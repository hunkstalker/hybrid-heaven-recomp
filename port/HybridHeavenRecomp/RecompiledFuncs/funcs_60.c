#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801e3610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E3610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E3614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E3618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E361C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E3620: jal         0x801CCE0C
    // 0x801E3624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801E3624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801E3628: lui         $a1, 0x2C2
    ctx->r5 = S32(0X2C2 << 16);
    // 0x801E362C: ori         $a1, $a1, 0x7B60
    ctx->r5 = ctx->r5 | 0X7B60;
    // 0x801E3630: jal         0x801C0B8C
    // 0x801E3634: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E3634: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_1:
    // 0x801E3638: beq         $v0, $zero, L_801E3680
    if (ctx->r2 == 0) {
        // 0x801E363C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E3680;
    }
    // 0x801E363C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E3640: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801E3644: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801E3648: jal         0x801CCE50
    // 0x801E364C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_2;
    // 0x801E364C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_2:
    // 0x801E3650: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3654: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801E3658: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801E365C: jal         0x801CCE88
    // 0x801E3660: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801E3660: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x801E3664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E366C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E3670: jal         0x801CCEC8
    // 0x801E3674: addiu       $a3, $zero, -0x7F
    ctx->r7 = ADD32(0, -0X7F);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801E3674: addiu       $a3, $zero, -0x7F
    ctx->r7 = ADD32(0, -0X7F);
    after_4:
    // 0x801E3678: b           L_801E36FC
    // 0x801E367C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E36FC;
    // 0x801E367C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E3680:
    // 0x801E3680: lui         $a1, 0x294
    ctx->r5 = S32(0X294 << 16);
    // 0x801E3684: jal         0x801C0B8C
    // 0x801E3688: ori         $a1, $a1, 0xB4A0
    ctx->r5 = ctx->r5 | 0XB4A0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_5;
    // 0x801E3688: ori         $a1, $a1, 0xB4A0
    ctx->r5 = ctx->r5 | 0XB4A0;
    after_5:
    // 0x801E368C: beq         $v0, $zero, L_801E36F8
    if (ctx->r2 == 0) {
        // 0x801E3690: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_801E36F8;
    }
    // 0x801E3690: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801E3694: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801E3698: jal         0x801CCE50
    // 0x801E369C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_6;
    // 0x801E369C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_6:
    // 0x801E36A0: jal         0x801C0AE4
    // 0x801E36A4: nop

    LOOKUP_FUNC(0x801C0AE4)(rdram, ctx);
        goto after_7;
    // 0x801E36A4: nop

    after_7:
    // 0x801E36A8: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x801E36AC: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x801E36B0: beq         $t7, $zero, L_801E36D4
    if (ctx->r15 == 0) {
        // 0x801E36B4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801E36D4;
    }
    // 0x801E36B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E36B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E36BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E36C0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801E36C4: jal         0x801CCE88
    // 0x801E36C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_8;
    // 0x801E36C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x801E36CC: b           L_801E36E8
    // 0x801E36D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_801E36E8;
    // 0x801E36D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801E36D4:
    // 0x801E36D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E36D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E36DC: jal         0x801CCE88
    // 0x801E36E0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_9;
    // 0x801E36E0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_9:
    // 0x801E36E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801E36E8:
    // 0x801E36E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E36EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E36F0: jal         0x801CCEC8
    // 0x801E36F4: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_10;
    // 0x801E36F4: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_10:
L_801E36F8:
    // 0x801E36F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E36FC:
    // 0x801E36FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E3700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E3704: jr          $ra
    // 0x801E3708: nop

    return;
    // 0x801E3708: nop

;}
RECOMP_FUNC void M25_FUN_801e370c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E370C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E3710: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E3714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E3718: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E371C: lui         $a1, 0x307
    ctx->r5 = S32(0X307 << 16);
    // 0x801E3720: ori         $a1, $a1, 0x2580
    ctx->r5 = ctx->r5 | 0X2580;
    // 0x801E3724: jal         0x801C0B8C
    // 0x801E3728: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E3728: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E372C: beq         $v0, $zero, L_801E3788
    if (ctx->r2 == 0) {
        // 0x801E3730: addiu       $a0, $zero, 0x32
        ctx->r4 = ADD32(0, 0X32);
            goto L_801E3788;
    }
    // 0x801E3730: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801E3734: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801E3738: jal         0x801CCE50
    // 0x801E373C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801E373C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_1:
    // 0x801E3740: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3744: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801E3748: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801E374C: jal         0x801CCE88
    // 0x801E3750: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801E3750: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x801E3754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E375C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E3760: jal         0x801CCEC8
    // 0x801E3764: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_3;
    // 0x801E3764: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    after_3:
    // 0x801E3768: lui         $a1, 0x3B6
    ctx->r5 = S32(0X3B6 << 16);
    // 0x801E376C: ori         $a1, $a1, 0x9F60
    ctx->r5 = ctx->r5 | 0X9F60;
    // 0x801E3770: jal         0x801C0B8C
    // 0x801E3774: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_4;
    // 0x801E3774: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_4:
    // 0x801E3778: beql        $v0, $zero, L_801E378C
    if (ctx->r2 == 0) {
        // 0x801E377C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801E378C;
    }
    goto skip_0;
    // 0x801E377C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x801E3780: b           L_801E378C
    // 0x801E3784: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E378C;
    // 0x801E3784: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E3788:
    // 0x801E3788: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E378C:
    // 0x801E378C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E3790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E3794: jr          $ra
    // 0x801E3798: nop

    return;
    // 0x801E3798: nop

;}
RECOMP_FUNC void M25_FUN_801e379c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E379C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E37A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E37A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E37A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E37AC: lui         $a1, 0x3F3
    ctx->r5 = S32(0X3F3 << 16);
    // 0x801E37B0: ori         $a1, $a1, 0xA860
    ctx->r5 = ctx->r5 | 0XA860;
    // 0x801E37B4: jal         0x801C0B8C
    // 0x801E37B8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E37B8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E37BC: beq         $v0, $zero, L_801E3800
    if (ctx->r2 == 0) {
        // 0x801E37C0: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_801E3800;
    }
    // 0x801E37C0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801E37C4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801E37C8: jal         0x801CCE50
    // 0x801E37CC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801E37CC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x801E37D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E37D4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801E37D8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801E37DC: jal         0x801CCE88
    // 0x801E37E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801E37E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x801E37E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E37E8: addiu       $a1, $zero, -0x7F
    ctx->r5 = ADD32(0, -0X7F);
    // 0x801E37EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E37F0: jal         0x801CCEC8
    // 0x801E37F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_3;
    // 0x801E37F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801E37F8: b           L_801E3804
    // 0x801E37FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801E3804;
    // 0x801E37FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801E3800:
    // 0x801E3800: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E3804:
    // 0x801E3804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E3808: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E380C: jr          $ra
    // 0x801E3810: nop

    return;
    // 0x801E3810: nop

;}
RECOMP_FUNC void M25_FUN_801e3814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E3814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E3818: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E381C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E3820: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E3824: lui         $a1, 0x6F5
    ctx->r5 = S32(0X6F5 << 16);
    // 0x801E3828: ori         $a1, $a1, 0xC4D0
    ctx->r5 = ctx->r5 | 0XC4D0;
    // 0x801E382C: jal         0x801C0B8C
    // 0x801E3830: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E3830: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E3834: beq         $v0, $zero, L_801E3878
    if (ctx->r2 == 0) {
        // 0x801E3838: addiu       $a0, $zero, 0x32
        ctx->r4 = ADD32(0, 0X32);
            goto L_801E3878;
    }
    // 0x801E3838: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801E383C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801E3840: jal         0x801CCE50
    // 0x801E3844: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801E3844: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_1:
    // 0x801E3848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E384C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801E3850: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801E3854: jal         0x801CCE88
    // 0x801E3858: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801E3858: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x801E385C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E3864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E3868: jal         0x801CCEC8
    // 0x801E386C: addiu       $a3, $zero, -0x7F
    ctx->r7 = ADD32(0, -0X7F);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_3;
    // 0x801E386C: addiu       $a3, $zero, -0x7F
    ctx->r7 = ADD32(0, -0X7F);
    after_3:
    // 0x801E3870: b           L_801E387C
    // 0x801E3874: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801E387C;
    // 0x801E3874: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E3878:
    // 0x801E3878: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801E387C:
    // 0x801E387C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E3880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E3884: jr          $ra
    // 0x801E3888: nop

    return;
    // 0x801E3888: nop

;}
RECOMP_FUNC void M25_FUN_801e388c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E388C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E3890: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E3894: jr          $ra
    // 0x801E3898: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x801E3898: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e389c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e389c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E389C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E38A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E38A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E38A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E38AC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E38B0: addiu       $a1, $a1, -0x2298
    ctx->r5 = ADD32(ctx->r5, -0X2298);
    // 0x801E38B4: jal         0x801C2420
    // 0x801E38B8: addiu       $a0, $zero, 0x259
    ctx->r4 = ADD32(0, 0X259);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801E38B8: addiu       $a0, $zero, 0x259
    ctx->r4 = ADD32(0, 0X259);
    after_0:
    // 0x801E38BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E38C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E38C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E38C8: jr          $ra
    // 0x801E38CC: nop

    return;
    // 0x801E38CC: nop

;}
RECOMP_FUNC void M25_FUN_801e38d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E38D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E38D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E38D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E38DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E38E0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E38E4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E38E8: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    // 0x801E38EC: jal         0x80005E44
    // 0x801E38F0: addiu       $a1, $a1, -0x27D0
    ctx->r5 = ADD32(ctx->r5, -0X27D0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801E38F0: addiu       $a1, $a1, -0x27D0
    ctx->r5 = ADD32(ctx->r5, -0X27D0);
    after_0:
    // 0x801E38F4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E38F8: jal         0x80006214
    // 0x801E38FC: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801E38FC: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    after_1:
    // 0x801E3900: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E3904: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    // 0x801E3908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E390C: addiu       $a2, $zero, 0x259
    ctx->r6 = ADD32(0, 0X259);
    // 0x801E3910: jal         0x8012C89C
    // 0x801E3914: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801E3914: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801E3918: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801E391C: addiu       $v1, $v1, -0x27AC
    ctx->r3 = ADD32(ctx->r3, -0X27AC);
    // 0x801E3920: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E3924: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801E3928: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E392C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801E3930: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801E3934: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E3938: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801E393C: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801E3940: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E3944: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801E3948: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E394C: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801E3950: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E3954: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801E3958: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801E395C: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801E3960: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3964: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801E3968: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E396C: swc1        $f2, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f2.u32l;
    // 0x801E3970: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3974: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801E3978: addiu       $t7, $t7, -0x5168
    ctx->r15 = ADD32(ctx->r15, -0X5168);
    // 0x801E397C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801E3980: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801E3984: swc1        $f2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f2.u32l;
    // 0x801E3988: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E398C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801E3990: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E3994: swc1        $f2, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f2.u32l;
    // 0x801E3998: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E399C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801E39A0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801E39A4: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    // 0x801E39A8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E39AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801E39B0: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801E39B4: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
    // 0x801E39B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E39BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E39C0: jr          $ra
    // 0x801E39C4: nop

    return;
    // 0x801E39C4: nop

;}
RECOMP_FUNC void M25_FUN_801e39c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E39C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E39CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E39D0: jr          $ra
    // 0x801E39D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E39D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e39d8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e39d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E39D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E39DC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E39E0: jr          $ra
    // 0x801E39E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E39E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e39e8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e39e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E39E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E39EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E39F0: jr          $ra
    // 0x801E39F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801E39F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e39f8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e39f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E39F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E39FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E3A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E3A04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E3A08: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3A0C: addiu       $a1, $a1, -0x2270
    ctx->r5 = ADD32(ctx->r5, -0X2270);
    // 0x801E3A10: jal         0x801C2420
    // 0x801E3A14: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801E3A14: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_0:
    // 0x801E3A18: jal         0x8038BA70
    // 0x801E3A1C: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_1;
    // 0x801E3A1C: nop

    after_1:
    // 0x801E3A20: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3A24: addiu       $a1, $a1, -0x2258
    ctx->r5 = ADD32(ctx->r5, -0X2258);
    // 0x801E3A28: jal         0x801C2420
    // 0x801E3A2C: addiu       $a0, $zero, 0x25A
    ctx->r4 = ADD32(0, 0X25A);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_2;
    // 0x801E3A2C: addiu       $a0, $zero, 0x25A
    ctx->r4 = ADD32(0, 0X25A);
    after_2:
    // 0x801E3A30: jal         0x8038BA70
    // 0x801E3A34: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_3;
    // 0x801E3A34: nop

    after_3:
    // 0x801E3A38: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3A3C: addiu       $a1, $a1, -0x2240
    ctx->r5 = ADD32(ctx->r5, -0X2240);
    // 0x801E3A40: jal         0x801C2420
    // 0x801E3A44: addiu       $a0, $zero, 0x25C
    ctx->r4 = ADD32(0, 0X25C);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_4;
    // 0x801E3A44: addiu       $a0, $zero, 0x25C
    ctx->r4 = ADD32(0, 0X25C);
    after_4:
    // 0x801E3A48: jal         0x8038BA70
    // 0x801E3A4C: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_5;
    // 0x801E3A4C: nop

    after_5:
    // 0x801E3A50: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3A54: addiu       $a1, $a1, -0x2228
    ctx->r5 = ADD32(ctx->r5, -0X2228);
    // 0x801E3A58: jal         0x801C2420
    // 0x801E3A5C: addiu       $a0, $zero, 0x25D
    ctx->r4 = ADD32(0, 0X25D);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_6;
    // 0x801E3A5C: addiu       $a0, $zero, 0x25D
    ctx->r4 = ADD32(0, 0X25D);
    after_6:
    // 0x801E3A60: jal         0x8038BA70
    // 0x801E3A64: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_7;
    // 0x801E3A64: nop

    after_7:
    // 0x801E3A68: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3A6C: addiu       $a1, $a1, -0x2210
    ctx->r5 = ADD32(ctx->r5, -0X2210);
    // 0x801E3A70: jal         0x801C2420
    // 0x801E3A74: addiu       $a0, $zero, 0x25E
    ctx->r4 = ADD32(0, 0X25E);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_8;
    // 0x801E3A74: addiu       $a0, $zero, 0x25E
    ctx->r4 = ADD32(0, 0X25E);
    after_8:
    // 0x801E3A78: jal         0x8038BA70
    // 0x801E3A7C: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_9;
    // 0x801E3A7C: nop

    after_9:
    // 0x801E3A80: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3A84: addiu       $a1, $a1, -0x21F8
    ctx->r5 = ADD32(ctx->r5, -0X21F8);
    // 0x801E3A88: jal         0x801C2420
    // 0x801E3A8C: addiu       $a0, $zero, 0x25F
    ctx->r4 = ADD32(0, 0X25F);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_10;
    // 0x801E3A8C: addiu       $a0, $zero, 0x25F
    ctx->r4 = ADD32(0, 0X25F);
    after_10:
    // 0x801E3A90: jal         0x8038BA70
    // 0x801E3A94: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_11;
    // 0x801E3A94: nop

    after_11:
    // 0x801E3A98: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3A9C: addiu       $a1, $a1, -0x21E0
    ctx->r5 = ADD32(ctx->r5, -0X21E0);
    // 0x801E3AA0: jal         0x801C2420
    // 0x801E3AA4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_12;
    // 0x801E3AA4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_12:
    // 0x801E3AA8: jal         0x8038BA70
    // 0x801E3AAC: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_13;
    // 0x801E3AAC: nop

    after_13:
    // 0x801E3AB0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3AB4: addiu       $a1, $a1, -0x21C8
    ctx->r5 = ADD32(ctx->r5, -0X21C8);
    // 0x801E3AB8: jal         0x801C2420
    // 0x801E3ABC: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_14;
    // 0x801E3ABC: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_14:
    // 0x801E3AC0: jal         0x8038BA70
    // 0x801E3AC4: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_15;
    // 0x801E3AC4: nop

    after_15:
    // 0x801E3AC8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3ACC: addiu       $a1, $a1, -0x2090
    ctx->r5 = ADD32(ctx->r5, -0X2090);
    // 0x801E3AD0: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x801E3AD4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801E3AD8: jal         0x801C2570
    // 0x801E3ADC: addiu       $a0, $zero, 0x25B
    ctx->r4 = ADD32(0, 0X25B);
    LOOKUP_FUNC(0x801C2570)(rdram, ctx);
        goto after_16;
    // 0x801E3ADC: addiu       $a0, $zero, 0x25B
    ctx->r4 = ADD32(0, 0X25B);
    after_16:
    // 0x801E3AE0: beql        $v0, $zero, L_801E3AF4
    if (ctx->r2 == 0) {
        // 0x801E3AE4: addiu       $t7, $zero, 0x4000
        ctx->r15 = ADD32(0, 0X4000);
            goto L_801E3AF4;
    }
    goto skip_0;
    // 0x801E3AE4: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
    skip_0:
    // 0x801E3AE8: jal         0x8038BA8C
    // 0x801E3AEC: nop

    LOOKUP_FUNC(0x8038BA8C)(rdram, ctx);
        goto after_17;
    // 0x801E3AEC: nop

    after_17:
    // 0x801E3AF0: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
L_801E3AF4:
    // 0x801E3AF4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x801E3AF8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3AFC: sw          $t7, -0x2080($at)
    MEM_W(-0X2080, ctx->r1) = ctx->r15;
    // 0x801E3B00: addiu       $a1, $a1, -0x2084
    ctx->r5 = ADD32(ctx->r5, -0X2084);
    // 0x801E3B04: jal         0x801C2570
    // 0x801E3B08: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    LOOKUP_FUNC(0x801C2570)(rdram, ctx);
        goto after_18;
    // 0x801E3B08: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_18:
    // 0x801E3B0C: beql        $v0, $zero, L_801E3B20
    if (ctx->r2 == 0) {
        // 0x801E3B10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E3B20;
    }
    goto skip_1;
    // 0x801E3B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801E3B14: jal         0x8038BA8C
    // 0x801E3B18: nop

    LOOKUP_FUNC(0x8038BA8C)(rdram, ctx);
        goto after_19;
    // 0x801E3B18: nop

    after_19:
    // 0x801E3B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801E3B20:
    // 0x801E3B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E3B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E3B28: jr          $ra
    // 0x801E3B2C: nop

    return;
    // 0x801E3B2C: nop

;}
RECOMP_FUNC void M25_FUN_801e3b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E3B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E3B34: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801E3B38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801E3B3C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801E3B40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801E3B44: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x801E3B48: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x801E3B4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E3B50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E3B54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E3B58: addiu       $s3, $s3, -0x2734
    ctx->r19 = ADD32(ctx->r19, -0X2734);
    // 0x801E3B5C: addiu       $s1, $s1, -0x2774
    ctx->r17 = ADD32(ctx->r17, -0X2774);
    // 0x801E3B60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801E3B64: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x801E3B68: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_801E3B6C:
    // 0x801E3B6C: jal         0x80005E44
    // 0x801E3B70: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801E3B70: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x801E3B74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801E3B78: bnel        $s0, $s2, L_801E3B6C
    if (ctx->r16 != ctx->r18) {
        // 0x801E3B7C: lw          $a0, 0x0($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X0);
            goto L_801E3B6C;
    }
    goto skip_0;
    // 0x801E3B7C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x801E3B80: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E3B84: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    // 0x801E3B88: jal         0x80005E44
    // 0x801E3B8C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x801E3B8C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_1:
    // 0x801E3B90: jal         0x80006214
    // 0x801E3B94: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801E3B94: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x801E3B98: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E3BA0: addiu       $a2, $zero, 0xA3
    ctx->r6 = ADD32(0, 0XA3);
    // 0x801E3BA4: jal         0x8012C89C
    // 0x801E3BA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x801E3BA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801E3BAC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801E3BB4: addiu       $a2, $zero, 0x25A
    ctx->r6 = ADD32(0, 0X25A);
    // 0x801E3BB8: jal         0x8012C89C
    // 0x801E3BBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x801E3BBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801E3BC0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801E3BC8: addiu       $a2, $zero, 0x25C
    ctx->r6 = ADD32(0, 0X25C);
    // 0x801E3BCC: jal         0x8012C89C
    // 0x801E3BD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x801E3BD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x801E3BD4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3BD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801E3BDC: addiu       $a2, $zero, 0x25D
    ctx->r6 = ADD32(0, 0X25D);
    // 0x801E3BE0: jal         0x8012C89C
    // 0x801E3BE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x801E3BE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x801E3BE8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3BEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801E3BF0: addiu       $a2, $zero, 0x25E
    ctx->r6 = ADD32(0, 0X25E);
    // 0x801E3BF4: jal         0x8012C89C
    // 0x801E3BF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_7;
    // 0x801E3BF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x801E3BFC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3C00: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x801E3C04: addiu       $a2, $zero, 0x25F
    ctx->r6 = ADD32(0, 0X25F);
    // 0x801E3C08: jal         0x8012C89C
    // 0x801E3C0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_8;
    // 0x801E3C0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x801E3C10: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3C14: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801E3C18: addiu       $a2, $zero, 0xA4
    ctx->r6 = ADD32(0, 0XA4);
    // 0x801E3C1C: jal         0x8012C89C
    // 0x801E3C20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_9;
    // 0x801E3C20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x801E3C24: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801E3C28: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801E3C2C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E3C30: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801E3C34: addiu       $a2, $zero, 0x25B
    ctx->r6 = ADD32(0, 0X25B);
    // 0x801E3C38: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801E3C3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801E3C40: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    // 0x801E3C44: jal         0x8012CF8C
    // 0x801E3C48: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_10;
    // 0x801E3C48: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_10:
    // 0x801E3C4C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3C50: lwc1        $f2, -0x4060($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4060);
    // 0x801E3C54: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801E3C58: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801E3C5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E3C60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E3C64: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3C68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3C6C: lwc1        $f14, -0x405C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X405C);
    // 0x801E3C70: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801E3C74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3C78: lwc1        $f16, -0x4058($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4058);
    // 0x801E3C7C: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x801E3C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E3C84: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801E3C88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801E3C8C: lui         $a0, 0x4000
    ctx->r4 = S32(0X4000 << 16);
    // 0x801E3C90: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801E3C94: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E3C98: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801E3C9C: addiu       $t0, $t0, -0x4F98
    ctx->r8 = ADD32(ctx->r8, -0X4F98);
    // 0x801E3CA0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801E3CA4: or          $t1, $t0, $a0
    ctx->r9 = ctx->r8 | ctx->r4;
    // 0x801E3CA8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801E3CAC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801E3CB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E3CB4: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x801E3CB8: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x801E3CBC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E3CC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E3CC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E3CC8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801E3CCC: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801E3CD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E3CD4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E3CD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3CDC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E3CE0: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x801E3CE4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801E3CE8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801E3CEC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801E3CF0: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801E3CF4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E3CF8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801E3CFC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801E3D00: sw          $t1, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r9;
    // 0x801E3D04: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D08: addiu       $t4, $zero, 0x49F
    ctx->r12 = ADD32(0, 0X49F);
    // 0x801E3D0C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801E3D10: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E3D14: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801E3D18: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D1C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801E3D20: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801E3D24: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x801E3D28: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D2C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801E3D30: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x801E3D34: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x801E3D38: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D3C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801E3D40: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E3D44: sh          $t4, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r12;
    // 0x801E3D48: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D4C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801E3D50: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801E3D54: swc1        $f2, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f2.u32l;
    // 0x801E3D58: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D5C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801E3D60: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x801E3D64: swc1        $f2, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f2.u32l;
    // 0x801E3D68: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D6C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801E3D70: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x801E3D74: swc1        $f2, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f2.u32l;
    // 0x801E3D78: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D7C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E3D80: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801E3D84: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
    // 0x801E3D88: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E3D8C: lwc1        $f4, -0x4054($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4054);
    // 0x801E3D90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801E3D94: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801E3D98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E3D9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3DA0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801E3DA4: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x801E3DA8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E3DAC: lw          $t5, 0x8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X8);
    // 0x801E3DB0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E3DB4: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x801E3DB8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E3DBC: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x801E3DC0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E3DC4: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x801E3DC8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E3DCC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E3DD0: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801E3DD4: swc1        $f2, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f2.u32l;
    // 0x801E3DD8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801E3DDC: lw          $t1, 0x8($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X8);
    // 0x801E3DE0: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x801E3DE4: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801E3DE8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E3DEC: lw          $t4, 0x8($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X8);
    // 0x801E3DF0: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x801E3DF4: swc1        $f2, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f2.u32l;
    // 0x801E3DF8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3DFC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x801E3E00: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801E3E04: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x801E3E08: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E0C: lwc1        $f8, -0x4050($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4050);
    // 0x801E3E10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3E14: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801E3E18: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x801E3E1C: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x801E3E20: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E24: lwc1        $f10, -0x404C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X404C);
    // 0x801E3E28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3E2C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801E3E30: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x801E3E34: swc1        $f10, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f10.u32l;
    // 0x801E3E38: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E3C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801E3E40: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801E3E44: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801E3E48: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E4C: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x801E3E50: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801E3E54: swc1        $f14, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f14.u32l;
    // 0x801E3E58: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E5C: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x801E3E60: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E3E64: swc1        $f14, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f14.u32l;
    // 0x801E3E68: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E6C: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x801E3E70: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E3E74: swc1        $f14, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f14.u32l;
    // 0x801E3E78: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E7C: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x801E3E80: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801E3E84: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
    // 0x801E3E88: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E8C: lw          $t1, 0x10($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X10);
    // 0x801E3E90: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x801E3E94: swc1        $f0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f0.u32l;
    // 0x801E3E98: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E3E9C: lw          $t4, 0x10($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X10);
    // 0x801E3EA0: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x801E3EA4: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801E3EA8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3EAC: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801E3EB0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801E3EB4: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x801E3EB8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E3EBC: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x801E3EC0: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x801E3EC4: swc1        $f12, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f12.u32l;
    // 0x801E3EC8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3ECC: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x801E3ED0: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x801E3ED4: swc1        $f12, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f12.u32l;
    // 0x801E3ED8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801E3EDC: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801E3EE0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801E3EE4: swc1        $f12, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f12.u32l;
    // 0x801E3EE8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E3EEC: lwc1        $f18, -0x4048($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4048);
    // 0x801E3EF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3EF4: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
    // 0x801E3EF8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801E3EFC: swc1        $f18, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f18.u32l;
    // 0x801E3F00: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F04: lwc1        $f4, -0x4044($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4044);
    // 0x801E3F08: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3F0C: lw          $t5, 0x14($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X14);
    // 0x801E3F10: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E3F14: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x801E3F18: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F1C: lwc1        $f6, -0x4040($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4040);
    // 0x801E3F20: lw          $t7, 0x14($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X14);
    // 0x801E3F24: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E3F28: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x801E3F2C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F30: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x801E3F34: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801E3F38: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    // 0x801E3F3C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F40: lw          $t1, 0x14($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X14);
    // 0x801E3F44: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x801E3F48: swc1        $f16, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f16.u32l;
    // 0x801E3F4C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F50: lw          $t4, 0x14($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X14);
    // 0x801E3F54: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x801E3F58: swc1        $f16, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f16.u32l;
    // 0x801E3F5C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F60: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x801E3F64: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801E3F68: swc1        $f16, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f16.u32l;
    // 0x801E3F6C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F70: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x801E3F74: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x801E3F78: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x801E3F7C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F80: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x801E3F84: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x801E3F88: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
    // 0x801E3F8C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801E3F90: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x801E3F94: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801E3F98: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801E3F9C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E3FA0: lw          $t2, 0x18($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X18);
    // 0x801E3FA4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801E3FA8: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801E3FAC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E3FB0: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801E3FB4: addiu       $t3, $t3, -0x4F40
    ctx->r11 = ADD32(ctx->r11, -0X4F40);
    // 0x801E3FB8: lw          $t5, 0x18($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X18);
    // 0x801E3FBC: or          $t1, $t3, $a0
    ctx->r9 = ctx->r11 | ctx->r4;
    // 0x801E3FC0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E3FC4: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
    // 0x801E3FC8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E3FCC: lw          $t7, 0x18($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X18);
    // 0x801E3FD0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E3FD4: swc1        $f12, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f12.u32l;
    // 0x801E3FD8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E3FDC: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x801E3FE0: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801E3FE4: swc1        $f12, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f12.u32l;
    // 0x801E3FE8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E3FEC: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x801E3FF0: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x801E3FF4: sw          $t1, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r9;
    // 0x801E3FF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E3FFC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801E4000: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4004: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801E4008: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801E400C: jr          $ra
    // 0x801E4010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801E4010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4014(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4014: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4018: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E401C: jr          $ra
    // 0x801E4020: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E4020: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4024(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4024: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4028: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E402C: jr          $ra
    // 0x801E4030: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E4030: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4034(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4034: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4038: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E403C: jr          $ra
    // 0x801E4040: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E4040: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4044(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4044: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E4048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E404C: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E4050: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E4054: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E4058: jal         0x801BF628
    // 0x801E405C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E405C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801E4060: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E4064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E406C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E4070: bne         $at, $zero, L_801E4080
    if (ctx->r1 != 0) {
        // 0x801E4074: nop
    
            goto L_801E4080;
    }
    // 0x801E4074: nop

    // 0x801E4078: b           L_801E4080
    // 0x801E407C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E4080;
    // 0x801E407C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E4080:
    // 0x801E4080: jr          $ra
    // 0x801E4084: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E4084: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4088(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E408C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E4090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E4098: lui         $a1, 0x8EC
    ctx->r5 = S32(0X8EC << 16);
    // 0x801E409C: ori         $a1, $a1, 0x8BBF
    ctx->r5 = ctx->r5 | 0X8BBF;
    // 0x801E40A0: jal         0x801C0B8C
    // 0x801E40A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E40A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E40A8: beq         $v0, $zero, L_801E40B8
    if (ctx->r2 == 0) {
        // 0x801E40AC: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_801E40B8;
    }
    // 0x801E40AC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801E40B0: b           L_801E40E0
    // 0x801E40B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E40E0;
    // 0x801E40B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E40B8:
    // 0x801E40B8: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801E40BC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E40C0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801E40C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801E40C8: addiu       $a2, $zero, 0x25B
    ctx->r6 = ADD32(0, 0X25B);
    // 0x801E40CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801E40D0: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    // 0x801E40D4: jal         0x8012CF8C
    // 0x801E40D8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_1;
    // 0x801E40D8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_1:
    // 0x801E40DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E40E0:
    // 0x801E40E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E40E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E40E8: jr          $ra
    // 0x801E40EC: nop

    return;
    // 0x801E40EC: nop

;}
RECOMP_FUNC void M25_FUN_801e40f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E40F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E40F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E40F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E40FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E4100: lui         $a1, 0x94B
    ctx->r5 = S32(0X94B << 16);
    // 0x801E4104: ori         $a1, $a1, 0x267F
    ctx->r5 = ctx->r5 | 0X267F;
    // 0x801E4108: jal         0x801C0B8C
    // 0x801E410C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E410C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4110: beq         $v0, $zero, L_801E4120
    if (ctx->r2 == 0) {
        // 0x801E4114: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_801E4120;
    }
    // 0x801E4114: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801E4118: b           L_801E4148
    // 0x801E411C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E4148;
    // 0x801E411C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E4120:
    // 0x801E4120: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801E4124: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E4128: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801E412C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801E4130: addiu       $a2, $zero, 0x25B
    ctx->r6 = ADD32(0, 0X25B);
    // 0x801E4134: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E4138: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    // 0x801E413C: jal         0x8012CF8C
    // 0x801E4140: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_1;
    // 0x801E4140: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_1:
    // 0x801E4144: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E4148:
    // 0x801E4148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E414C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E4150: jr          $ra
    // 0x801E4154: nop

    return;
    // 0x801E4154: nop

;}
RECOMP_FUNC void M25_FUN_801e4158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4158: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E415C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4160: jr          $ra
    // 0x801E4164: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E4164: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4168(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4168: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E416C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4170: jr          $ra
    // 0x801E4174: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E4174: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4178(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4178: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E417C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4180: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E4184: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E4188: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E418C: jal         0x801BF628
    // 0x801E4190: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E4190: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801E4194: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E4198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E419C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E41A0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E41A4: bne         $at, $zero, L_801E41B4
    if (ctx->r1 != 0) {
        // 0x801E41A8: nop
    
            goto L_801E41B4;
    }
    // 0x801E41A8: nop

    // 0x801E41AC: b           L_801E41B4
    // 0x801E41B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E41B4;
    // 0x801E41B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E41B4:
    // 0x801E41B4: jr          $ra
    // 0x801E41B8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E41B8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e41bc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e41bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E41BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E41C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E41C4: jr          $ra
    // 0x801E41C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E41C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e41cc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e41cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E41CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E41D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E41D4: jr          $ra
    // 0x801E41D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E41D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e41dc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e41dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E41DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E41E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E41E4: jr          $ra
    // 0x801E41E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E41E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e41ec(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e41ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E41EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E41F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E41F4: jr          $ra
    // 0x801E41F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E41F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e41fc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e41fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E41FC: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E4200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4204: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E4208: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E420C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E4210: jal         0x801BF628
    // 0x801E4214: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E4214: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801E4218: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E421C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E4224: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E4228: bne         $at, $zero, L_801E4238
    if (ctx->r1 != 0) {
        // 0x801E422C: nop
    
            goto L_801E4238;
    }
    // 0x801E422C: nop

    // 0x801E4230: b           L_801E4238
    // 0x801E4234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E4238;
    // 0x801E4234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E4238:
    // 0x801E4238: jr          $ra
    // 0x801E423C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E423C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4240(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4240: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4244: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4248: jr          $ra
    // 0x801E424C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E424C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4250(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4250: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4254: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4258: jr          $ra
    // 0x801E425C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E425C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4260(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4260: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4264: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4268: jr          $ra
    // 0x801E426C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E426C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4270(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4270: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4274: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4278: jr          $ra
    // 0x801E427C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E427C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4280(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4280: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E4284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4288: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E428C: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E4290: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E4294: jal         0x801BF628
    // 0x801E4298: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E4298: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801E429C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E42A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E42A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E42A8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E42AC: bne         $at, $zero, L_801E42BC
    if (ctx->r1 != 0) {
        // 0x801E42B0: nop
    
            goto L_801E42BC;
    }
    // 0x801E42B0: nop

    // 0x801E42B4: b           L_801E42BC
    // 0x801E42B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E42BC;
    // 0x801E42B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E42BC:
    // 0x801E42BC: jr          $ra
    // 0x801E42C0: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E42C0: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e42c4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e42c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E42C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E42C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E42CC: jr          $ra
    // 0x801E42D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E42D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e42d4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e42d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E42D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E42D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E42DC: jr          $ra
    // 0x801E42E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E42E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e42e4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e42e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E42E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E42E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E42EC: jr          $ra
    // 0x801E42F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E42F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e42f4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e42f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E42F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E42F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E42FC: jr          $ra
    // 0x801E4300: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E4300: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4304(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4304: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E4308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E430C: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E4310: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E4314: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E4318: jal         0x801BF628
    // 0x801E431C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E431C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801E4320: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E4324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E432C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E4330: bne         $at, $zero, L_801E4340
    if (ctx->r1 != 0) {
        // 0x801E4334: nop
    
            goto L_801E4340;
    }
    // 0x801E4334: nop

    // 0x801E4338: b           L_801E4340
    // 0x801E433C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E4340;
    // 0x801E433C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E4340:
    // 0x801E4340: jr          $ra
    // 0x801E4344: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E4344: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4348(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E434C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E4350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E4358: lui         $a1, 0x3F3
    ctx->r5 = S32(0X3F3 << 16);
    // 0x801E435C: ori         $a1, $a1, 0xA860
    ctx->r5 = ctx->r5 | 0XA860;
    // 0x801E4360: jal         0x801C0B8C
    // 0x801E4364: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4364: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4368: beq         $v0, $zero, L_801E43B8
    if (ctx->r2 == 0) {
        // 0x801E436C: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_801E43B8;
    }
    // 0x801E436C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801E4370: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801E4374: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4378: lwc1        $f4, -0x403C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X403C);
    // 0x801E437C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801E4380: lui         $a1, 0x46D
    ctx->r5 = S32(0X46D << 16);
    // 0x801E4384: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801E4388: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801E438C: ori         $a1, $a1, 0xBA60
    ctx->r5 = ctx->r5 | 0XBA60;
    // 0x801E4390: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E4394: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x801E4398: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x801E439C: subu        $t3, $t8, $t2
    ctx->r11 = SUB32(ctx->r24, ctx->r10);
    // 0x801E43A0: jal         0x801C0B8C
    // 0x801E43A4: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E43A4: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    after_1:
    // 0x801E43A8: beql        $v0, $zero, L_801E43BC
    if (ctx->r2 == 0) {
        // 0x801E43AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801E43BC;
    }
    goto skip_0;
    // 0x801E43AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801E43B0: b           L_801E43BC
    // 0x801E43B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E43BC;
    // 0x801E43B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E43B8:
    // 0x801E43B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E43BC:
    // 0x801E43BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E43C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E43C4: jr          $ra
    // 0x801E43C8: nop

    return;
    // 0x801E43C8: nop

;}
RECOMP_FUNC void M25_FUN_801e43cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E43CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E43D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E43D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E43D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E43DC: lui         $a1, 0x69D
    ctx->r5 = S32(0X69D << 16);
    // 0x801E43E0: ori         $a1, $a1, 0x4490
    ctx->r5 = ctx->r5 | 0X4490;
    // 0x801E43E4: jal         0x801C0B8C
    // 0x801E43E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E43E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E43EC: beq         $v0, $zero, L_801E443C
    if (ctx->r2 == 0) {
        // 0x801E43F0: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_801E443C;
    }
    // 0x801E43F0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801E43F4: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801E43F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E43FC: lwc1        $f4, -0x4038($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4038);
    // 0x801E4400: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801E4404: lui         $a1, 0x6CB
    ctx->r5 = S32(0X6CB << 16);
    // 0x801E4408: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801E440C: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801E4410: ori         $a1, $a1, 0xB50
    ctx->r5 = ctx->r5 | 0XB50;
    // 0x801E4414: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E4418: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x801E441C: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x801E4420: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x801E4424: jal         0x801C0B8C
    // 0x801E4428: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E4428: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    after_1:
    // 0x801E442C: beql        $v0, $zero, L_801E4440
    if (ctx->r2 == 0) {
        // 0x801E4430: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801E4440;
    }
    goto skip_0;
    // 0x801E4430: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801E4434: b           L_801E4440
    // 0x801E4438: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E4440;
    // 0x801E4438: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E443C:
    // 0x801E443C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E4440:
    // 0x801E4440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E4448: jr          $ra
    // 0x801E444C: nop

    return;
    // 0x801E444C: nop

;}
RECOMP_FUNC void M25_FUN_801e4450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4450: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4454: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4458: jr          $ra
    // 0x801E445C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E445C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4460(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4460: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4464: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4468: jr          $ra
    // 0x801E446C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E446C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4470(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4470: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E4474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4478: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E447C: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E4480: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E4484: jal         0x801BF628
    // 0x801E4488: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E4488: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801E448C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E4490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E4498: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E449C: bne         $at, $zero, L_801E44AC
    if (ctx->r1 != 0) {
        // 0x801E44A0: nop
    
            goto L_801E44AC;
    }
    // 0x801E44A0: nop

    // 0x801E44A4: b           L_801E44AC
    // 0x801E44A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E44AC;
    // 0x801E44A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E44AC:
    // 0x801E44AC: jr          $ra
    // 0x801E44B0: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E44B0: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e44b4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e44b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E44B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E44B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E44BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E44C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E44C4: lui         $a1, 0x2C2
    ctx->r5 = S32(0X2C2 << 16);
    // 0x801E44C8: ori         $a1, $a1, 0x7B60
    ctx->r5 = ctx->r5 | 0X7B60;
    // 0x801E44CC: jal         0x801C0B8C
    // 0x801E44D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E44D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E44D4: beq         $v0, $zero, L_801E44E4
    if (ctx->r2 == 0) {
        // 0x801E44D8: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_801E44E4;
    }
    // 0x801E44D8: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801E44DC: b           L_801E453C
    // 0x801E44E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E453C;
    // 0x801E44E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E44E4:
    // 0x801E44E4: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801E44E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E44EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801E44F0: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x801E44F4: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x801E44F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E44FC: addiu       $t5, $zero, 0x118
    ctx->r13 = ADD32(0, 0X118);
    // 0x801E4500: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E4504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E4508: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801E450C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E4510: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x801E4514: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801E4518: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801E451C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E4520: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x801E4524: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801E4528: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x801E452C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E4530: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x801E4534: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E4538: sh          $t5, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r13;
L_801E453C:
    // 0x801E453C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E4544: jr          $ra
    // 0x801E4548: nop

    return;
    // 0x801E4548: nop

;}
RECOMP_FUNC void M25_FUN_801e454c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E454C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4550: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4554: jr          $ra
    // 0x801E4558: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E4558: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e455c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e455c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E455C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4560: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4564: jr          $ra
    // 0x801E4568: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E4568: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e456c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e456c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E456C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4570: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4574: jr          $ra
    // 0x801E4578: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E4578: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e457c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e457c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E457C: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E4580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4584: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E4588: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E458C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E4590: jal         0x801BF628
    // 0x801E4594: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E4594: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801E4598: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E459C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E45A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E45A4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E45A8: bne         $at, $zero, L_801E45B8
    if (ctx->r1 != 0) {
        // 0x801E45AC: nop
    
            goto L_801E45B8;
    }
    // 0x801E45AC: nop

    // 0x801E45B0: b           L_801E45B8
    // 0x801E45B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E45B8;
    // 0x801E45B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E45B8:
    // 0x801E45B8: jr          $ra
    // 0x801E45BC: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E45BC: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e45c0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e45c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E45C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801E45C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801E45C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801E45CC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801E45D0: lui         $a1, 0x34B
    ctx->r5 = S32(0X34B << 16);
    // 0x801E45D4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801E45D8: ori         $a1, $a1, 0xCFA0
    ctx->r5 = ctx->r5 | 0XCFA0;
    // 0x801E45DC: jal         0x801C0B8C
    // 0x801E45E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E45E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E45E4: beq         $v0, $zero, L_801E4860
    if (ctx->r2 == 0) {
        // 0x801E45E8: lui         $s0, 0x801E
        ctx->r16 = S32(0X801E << 16);
            goto L_801E4860;
    }
    // 0x801E45E8: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801E45EC: addiu       $s0, $s0, -0x71A0
    ctx->r16 = ADD32(ctx->r16, -0X71A0);
    // 0x801E45F0: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801E45F4: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x801E45F8: addiu       $t8, $zero, 0x43
    ctx->r24 = ADD32(0, 0X43);
    // 0x801E45FC: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x801E4600: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801E4604: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E4608: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801E460C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E4610: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801E4614: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x801E4618: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x801E461C: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E4620: jal         0x801C2980
    // 0x801E4624: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_1;
    // 0x801E4624: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_1:
    // 0x801E4628: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x801E462C: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801E4630: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x801E4634: addiu       $t3, $zero, 0x168
    ctx->r11 = ADD32(0, 0X168);
    // 0x801E4638: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801E463C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801E4640: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801E4644: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801E4648: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x801E464C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801E4650: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E4654: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E4658: jal         0x801C2980
    // 0x801E465C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_2;
    // 0x801E465C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_2:
    // 0x801E4660: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x801E4664: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x801E4668: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x801E466C: addiu       $t7, $zero, 0x168
    ctx->r15 = ADD32(0, 0X168);
    // 0x801E4670: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801E4674: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801E4678: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801E467C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801E4680: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x801E4684: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x801E4688: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E468C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E4690: jal         0x801C2980
    // 0x801E4694: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_3;
    // 0x801E4694: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_3:
    // 0x801E4698: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x801E469C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x801E46A0: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x801E46A4: addiu       $t1, $zero, 0x168
    ctx->r9 = ADD32(0, 0X168);
    // 0x801E46A8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801E46AC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801E46B0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801E46B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801E46B8: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x801E46BC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x801E46C0: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E46C4: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E46C8: jal         0x801C2980
    // 0x801E46CC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_4;
    // 0x801E46CC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_4:
    // 0x801E46D0: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x801E46D4: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x801E46D8: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x801E46DC: addiu       $t5, $zero, 0x168
    ctx->r13 = ADD32(0, 0X168);
    // 0x801E46E0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x801E46E4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801E46E8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801E46EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801E46F0: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x801E46F4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x801E46F8: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E46FC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E4700: jal         0x801C2980
    // 0x801E4704: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_5;
    // 0x801E4704: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_5:
    // 0x801E4708: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801E470C: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x801E4710: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x801E4714: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x801E4718: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801E471C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E4720: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801E4724: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E4728: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x801E472C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x801E4730: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E4734: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E4738: jal         0x801C2980
    // 0x801E473C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_6;
    // 0x801E473C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_6:
    // 0x801E4740: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x801E4744: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801E4748: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x801E474C: addiu       $t3, $zero, 0x168
    ctx->r11 = ADD32(0, 0X168);
    // 0x801E4750: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801E4754: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801E4758: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801E475C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801E4760: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x801E4764: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x801E4768: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E476C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E4770: jal         0x801C2980
    // 0x801E4774: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_7;
    // 0x801E4774: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_7:
    // 0x801E4778: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x801E477C: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x801E4780: addiu       $t6, $zero, 0xDC
    ctx->r14 = ADD32(0, 0XDC);
    // 0x801E4784: addiu       $t7, $zero, 0x168
    ctx->r15 = ADD32(0, 0X168);
    // 0x801E4788: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801E478C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801E4790: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801E4794: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801E4798: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x801E479C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x801E47A0: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E47A4: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E47A8: jal         0x801C2980
    // 0x801E47AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_8;
    // 0x801E47AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_8:
    // 0x801E47B0: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x801E47B4: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x801E47B8: addiu       $t0, $zero, 0xFA
    ctx->r8 = ADD32(0, 0XFA);
    // 0x801E47BC: addiu       $t1, $zero, 0x168
    ctx->r9 = ADD32(0, 0X168);
    // 0x801E47C0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801E47C4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801E47C8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801E47CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801E47D0: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x801E47D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801E47D8: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E47DC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E47E0: jal         0x801C2980
    // 0x801E47E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_9;
    // 0x801E47E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_9:
    // 0x801E47E8: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x801E47EC: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x801E47F0: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x801E47F4: addiu       $t5, $zero, 0x168
    ctx->r13 = ADD32(0, 0X168);
    // 0x801E47F8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x801E47FC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801E4800: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801E4804: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801E4808: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x801E480C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x801E4810: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E4814: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E4818: jal         0x801C2980
    // 0x801E481C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_10;
    // 0x801E481C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_10:
    // 0x801E4820: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801E4824: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x801E4828: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x801E482C: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x801E4830: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801E4834: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E4838: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801E483C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E4840: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x801E4844: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x801E4848: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x801E484C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801E4850: jal         0x801C2980
    // 0x801E4854: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801C2980)(rdram, ctx);
        goto after_11;
    // 0x801E4854: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_11:
    // 0x801E4858: b           L_801E4864
    // 0x801E485C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E4864;
    // 0x801E485C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E4860:
    // 0x801E4860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E4864:
    // 0x801E4864: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801E4868: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801E486C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801E4870: jr          $ra
    // 0x801E4874: nop

    return;
    // 0x801E4874: nop

;}
RECOMP_FUNC void M25_FUN_801e4878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4878: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E487C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4880: jr          $ra
    // 0x801E4884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E4884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4888(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4888: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E488C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4890: jr          $ra
    // 0x801E4894: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E4894: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4898(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4898: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E489C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E48A0: jr          $ra
    // 0x801E48A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E48A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e48a8(rdram, ctx);
;}
