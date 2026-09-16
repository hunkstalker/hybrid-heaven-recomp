#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801f053c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F053C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0540: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F054C: lui         $a1, 0x5F4
    ctx->r5 = S32(0X5F4 << 16);
    // 0x801F0550: ori         $a1, $a1, 0x9B7A
    ctx->r5 = ctx->r5 | 0X9B7A;
    // 0x801F0554: jal         0x801C0B8C
    // 0x801F0558: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0558: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F055C: beql        $v0, $zero, L_801F0580
    if (ctx->r2 == 0) {
        // 0x801F0560: addiu       $v0, $zero, 0x1A
        ctx->r2 = ADD32(0, 0X1A);
            goto L_801F0580;
    }
    goto skip_0;
    // 0x801F0560: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    skip_0:
    // 0x801F0564: jal         0x8038D28C
    // 0x801F0568: addiu       $a0, $zero, 0x5C7
    ctx->r4 = ADD32(0, 0X5C7);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F0568: addiu       $a0, $zero, 0x5C7
    ctx->r4 = ADD32(0, 0X5C7);
    after_1:
    // 0x801F056C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0570: sw          $zero, -0x48B8($at)
    MEM_W(-0X48B8, ctx->r1) = 0;
    // 0x801F0574: b           L_801F0580
    // 0x801F0578: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
        goto L_801F0580;
    // 0x801F0578: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x801F057C: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_801F0580:
    // 0x801F0580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0588: jr          $ra
    // 0x801F058C: nop

    return;
    // 0x801F058C: nop

;}
RECOMP_FUNC void M25_FUN_801f0590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0590: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F0594: lw          $v0, -0x48B8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48B8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f0598(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f0598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F05A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F05A4: beq         $v0, $zero, L_801F05C0
    if (ctx->r2 == 0) {
        // 0x801F05A8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801F05C0;
    }
    // 0x801F05A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F05AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F05B0: beq         $v0, $at, L_801F05F0
    if (ctx->r2 == ctx->r1) {
        // 0x801F05B4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F05F0;
    }
    // 0x801F05B4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F05B8: b           L_801F0618
    // 0x801F05BC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
        goto L_801F0618;
    // 0x801F05BC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_801F05C0:
    // 0x801F05C0: lui         $a1, 0x6BA
    ctx->r5 = S32(0X6BA << 16);
    // 0x801F05C4: ori         $a1, $a1, 0xF8BA
    ctx->r5 = ctx->r5 | 0XF8BA;
    // 0x801F05C8: jal         0x801C0B8C
    // 0x801F05CC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F05CC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F05D0: beql        $v0, $zero, L_801F0618
    if (ctx->r2 == 0) {
        // 0x801F05D4: addiu       $v0, $zero, 0x1B
        ctx->r2 = ADD32(0, 0X1B);
            goto L_801F0618;
    }
    goto skip_0;
    // 0x801F05D4: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    skip_0:
    // 0x801F05D8: jal         0x8038D28C
    // 0x801F05DC: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F05DC: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    after_1:
    // 0x801F05E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F05E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F05E8: b           L_801F0614
    // 0x801F05EC: sw          $t6, -0x48B8($at)
    MEM_W(-0X48B8, ctx->r1) = ctx->r14;
        goto L_801F0614;
    // 0x801F05EC: sw          $t6, -0x48B8($at)
    MEM_W(-0X48B8, ctx->r1) = ctx->r14;
L_801F05F0:
    // 0x801F05F0: lui         $a1, 0x6D9
    ctx->r5 = S32(0X6D9 << 16);
    // 0x801F05F4: jal         0x801C0B8C
    // 0x801F05F8: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801F05F8: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    after_2:
    // 0x801F05FC: beql        $v0, $zero, L_801F0618
    if (ctx->r2 == 0) {
        // 0x801F0600: addiu       $v0, $zero, 0x1B
        ctx->r2 = ADD32(0, 0X1B);
            goto L_801F0618;
    }
    goto skip_1;
    // 0x801F0600: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    skip_1:
    // 0x801F0604: jal         0x8038D28C
    // 0x801F0608: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_3;
    // 0x801F0608: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    after_3:
    // 0x801F060C: b           L_801F0618
    // 0x801F0610: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801F0618;
    // 0x801F0610: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801F0614:
    // 0x801F0614: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_801F0618:
    // 0x801F0618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F061C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0620: jr          $ra
    // 0x801F0624: nop

    return;
    // 0x801F0624: nop

;}
RECOMP_FUNC void M25_FUN_801f0628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F062C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0634: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0638: lui         $a1, 0x6FF
    ctx->r5 = S32(0X6FF << 16);
    // 0x801F063C: ori         $a1, $a1, 0xA2DA
    ctx->r5 = ctx->r5 | 0XA2DA;
    // 0x801F0640: jal         0x801C0B8C
    // 0x801F0644: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0644: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0648: beql        $v0, $zero, L_801F0664
    if (ctx->r2 == 0) {
        // 0x801F064C: addiu       $v0, $zero, 0x1C
        ctx->r2 = ADD32(0, 0X1C);
            goto L_801F0664;
    }
    goto skip_0;
    // 0x801F064C: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    skip_0:
    // 0x801F0650: jal         0x8038D28C
    // 0x801F0654: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F0654: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    after_1:
    // 0x801F0658: b           L_801F0664
    // 0x801F065C: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
        goto L_801F0664;
    // 0x801F065C: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    // 0x801F0660: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801F0664:
    // 0x801F0664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F066C: jr          $ra
    // 0x801F0670: nop

    return;
    // 0x801F0670: nop

;}
RECOMP_FUNC void M25_FUN_801f0674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0678: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F067C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0684: lui         $a1, 0x739
    ctx->r5 = S32(0X739 << 16);
    // 0x801F0688: ori         $a1, $a1, 0x9E9A
    ctx->r5 = ctx->r5 | 0X9E9A;
    // 0x801F068C: jal         0x801C0B8C
    // 0x801F0690: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0690: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0694: beql        $v0, $zero, L_801F06B0
    if (ctx->r2 == 0) {
        // 0x801F0698: addiu       $v0, $zero, 0x1D
        ctx->r2 = ADD32(0, 0X1D);
            goto L_801F06B0;
    }
    goto skip_0;
    // 0x801F0698: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    skip_0:
    // 0x801F069C: jal         0x8038D28C
    // 0x801F06A0: addiu       $a0, $zero, 0x1DD
    ctx->r4 = ADD32(0, 0X1DD);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F06A0: addiu       $a0, $zero, 0x1DD
    ctx->r4 = ADD32(0, 0X1DD);
    after_1:
    // 0x801F06A4: b           L_801F06B0
    // 0x801F06A8: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
        goto L_801F06B0;
    // 0x801F06A8: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x801F06AC: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_801F06B0:
    // 0x801F06B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F06B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F06B8: jr          $ra
    // 0x801F06BC: nop

    return;
    // 0x801F06BC: nop

;}
RECOMP_FUNC void M25_FUN_801f06c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F06C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F06C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F06C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F06CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F06D0: lui         $a1, 0x750
    ctx->r5 = S32(0X750 << 16);
    // 0x801F06D4: ori         $a1, $a1, 0x81FA
    ctx->r5 = ctx->r5 | 0X81FA;
    // 0x801F06D8: jal         0x801C0B8C
    // 0x801F06DC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F06DC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F06E0: beql        $v0, $zero, L_801F06FC
    if (ctx->r2 == 0) {
        // 0x801F06E4: addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
            goto L_801F06FC;
    }
    goto skip_0;
    // 0x801F06E4: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    skip_0:
    // 0x801F06E8: jal         0x8038D28C
    // 0x801F06EC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F06EC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x801F06F0: b           L_801F06FC
    // 0x801F06F4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_801F06FC;
    // 0x801F06F4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x801F06F8: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_801F06FC:
    // 0x801F06FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0704: jr          $ra
    // 0x801F0708: nop

    return;
    // 0x801F0708: nop

;}
RECOMP_FUNC void M25_FUN_801f070c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F070C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F0710: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F0714: jr          $ra
    // 0x801F0718: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    return;
    // 0x801F0718: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f071c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f071c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F071C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0720: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F0724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0728: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F072C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0730: jal         0x8038BEC8
    // 0x801F0734: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8038BEC8)(rdram, ctx);
        goto after_0;
    // 0x801F0734: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F0738: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F073C: jal         0x8038BE98
    // 0x801F0740: lwc1        $f12, -0x36E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36E0);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_1;
    // 0x801F0740: lwc1        $f12, -0x36E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36E0);
    after_1:
    // 0x801F0744: lui         $a1, 0x5D
    ctx->r5 = S32(0X5D << 16);
    // 0x801F0748: ori         $a1, $a1, 0x1420
    ctx->r5 = ctx->r5 | 0X1420;
    // 0x801F074C: jal         0x801C0B8C
    // 0x801F0750: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801F0750: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_2:
    // 0x801F0754: beq         $v0, $zero, L_801F0764
    if (ctx->r2 == 0) {
        // 0x801F0758: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F0764;
    }
    // 0x801F0758: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F075C: b           L_801F0930
    // 0x801F0760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F0930;
    // 0x801F0760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F0764:
    // 0x801F0764: lui         $a1, 0x2F
    ctx->r5 = S32(0X2F << 16);
    // 0x801F0768: jal         0x801C0B8C
    // 0x801F076C: ori         $a1, $a1, 0x4D60
    ctx->r5 = ctx->r5 | 0X4D60;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801F076C: ori         $a1, $a1, 0x4D60
    ctx->r5 = ctx->r5 | 0X4D60;
    after_3:
    // 0x801F0770: beql        $v0, $zero, L_801F08A4
    if (ctx->r2 == 0) {
        // 0x801F0774: lui         $a1, 0x2D
        ctx->r5 = S32(0X2D << 16);
            goto L_801F08A4;
    }
    goto skip_0;
    // 0x801F0774: lui         $a1, 0x2D
    ctx->r5 = S32(0X2D << 16);
    skip_0:
    // 0x801F0778: jal         0x801C0B2C
    // 0x801F077C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_4;
    // 0x801F077C: nop

    after_4:
    // 0x801F0780: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F0784: jal         0x80034C24
    // 0x801F0788: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_5;
    // 0x801F0788: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x801F078C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0790: ldc1        $f4, -0x36D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X36D8);
    // 0x801F0794: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0798: ldc1        $f8, -0x36D0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X36D0);
    // 0x801F079C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F07A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F07A4: ldc1        $f4, -0x36C8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X36C8);
    // 0x801F07A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F07AC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F07B0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F07B4: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F07B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F07BC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F07C0: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F07C4: ldc1        $f6, -0x36C0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X36C0);
    // 0x801F07C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F07CC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F07D0: ldc1        $f10, -0x36B8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X36B8);
    // 0x801F07D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F07D8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F07DC: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F07E0: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F07E4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F07E8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F07EC: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F07F0: ldc1        $f4, -0x36B0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X36B0);
    // 0x801F07F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F07F8: ldc1        $f8, -0x36A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X36A8);
    // 0x801F07FC: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F0800: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0804: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0808: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F080C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F0810: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0814: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801F0818: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F081C: ldc1        $f18, -0x36A0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X36A0);
    // 0x801F0820: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0824: ldc1        $f6, -0x3698($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3698);
    // 0x801F0828: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F082C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F0830: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0834: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0838: mul.d       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F083C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F0840: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F0844: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F0848: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F084C: ldc1        $f18, -0x3690($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3690);
    // 0x801F0850: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0854: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0858: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801F085C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F0860: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0864: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801F0868: ldc1        $f8, -0x3688($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3688);
    // 0x801F086C: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0870: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0874: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x801F0878: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F087C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0880: swc1        $f16, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f16.u32l;
    // 0x801F0884: ldc1        $f18, -0x3680($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3680);
    // 0x801F0888: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F088C: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801F0890: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F0894: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0898: b           L_801F0930
    // 0x801F089C: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
        goto L_801F0930;
    // 0x801F089C: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
    // 0x801F08A0: lui         $a1, 0x2D
    ctx->r5 = S32(0X2D << 16);
L_801F08A4:
    // 0x801F08A4: ori         $a1, $a1, 0xC6C0
    ctx->r5 = ctx->r5 | 0XC6C0;
    // 0x801F08A8: jal         0x801C0B8C
    // 0x801F08AC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_6;
    // 0x801F08AC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_6:
    // 0x801F08B0: beq         $v0, $zero, L_801F08F4
    if (ctx->r2 == 0) {
        // 0x801F08B4: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801F08F4;
    }
    // 0x801F08B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F08B8: lwc1        $f12, -0x3678($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3678);
    // 0x801F08BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F08C0: lui         $a2, 0x4103
    ctx->r6 = S32(0X4103 << 16);
    // 0x801F08C4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801F08C8: jal         0x8038BD50
    // 0x801F08CC: lwc1        $f14, -0x3674($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3674);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_7;
    // 0x801F08CC: lwc1        $f14, -0x3674($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3674);
    after_7:
    // 0x801F08D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F08D4: lwc1        $f12, -0x3670($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3670);
    // 0x801F08D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F08DC: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x801F08E0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801F08E4: jal         0x8038BD88
    // 0x801F08E8: lwc1        $f14, -0x366C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X366C);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_8;
    // 0x801F08E8: lwc1        $f14, -0x366C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X366C);
    after_8:
    // 0x801F08EC: b           L_801F0930
    // 0x801F08F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801F0930;
    // 0x801F08F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F08F4:
    // 0x801F08F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F08F8: lwc1        $f12, -0x3668($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3668);
    // 0x801F08FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0900: lui         $a2, 0x4124
    ctx->r6 = S32(0X4124 << 16);
    // 0x801F0904: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801F0908: jal         0x8038BD50
    // 0x801F090C: lwc1        $f14, -0x3664($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3664);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_9;
    // 0x801F090C: lwc1        $f14, -0x3664($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3664);
    after_9:
    // 0x801F0910: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0914: lwc1        $f12, -0x3660($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3660);
    // 0x801F0918: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F091C: lui         $a2, 0xC019
    ctx->r6 = S32(0XC019 << 16);
    // 0x801F0920: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801F0924: jal         0x8038BD88
    // 0x801F0928: lwc1        $f14, -0x365C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X365C);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_10;
    // 0x801F0928: lwc1        $f14, -0x365C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X365C);
    after_10:
    // 0x801F092C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F0930:
    // 0x801F0930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0938: jr          $ra
    // 0x801F093C: nop

    return;
    // 0x801F093C: nop

;}
RECOMP_FUNC void M25_FUN_801f0940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0944: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F094C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0950: lui         $a1, 0x8A
    ctx->r5 = S32(0X8A << 16);
    // 0x801F0954: ori         $a1, $a1, 0xDAE0
    ctx->r5 = ctx->r5 | 0XDAE0;
    // 0x801F0958: jal         0x801C0B8C
    // 0x801F095C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F095C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0960: beq         $v0, $zero, L_801F0970
    if (ctx->r2 == 0) {
        // 0x801F0964: nop
    
            goto L_801F0970;
    }
    // 0x801F0964: nop

    // 0x801F0968: b           L_801F0AB8
    // 0x801F096C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F0AB8;
    // 0x801F096C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F0970:
    // 0x801F0970: jal         0x801C0B2C
    // 0x801F0974: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F0974: nop

    after_1:
    // 0x801F0978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F097C: jal         0x80034C24
    // 0x801F0980: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F0980: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F0984: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0988: ldc1        $f4, -0x3658($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3658);
    // 0x801F098C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0990: ldc1        $f8, -0x3650($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3650);
    // 0x801F0994: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F0998: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801F099C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F09A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F09A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F09A8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F09AC: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F09B0: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F09B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F09B8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F09BC: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F09C0: ldc1        $f6, -0x3648($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3648);
    // 0x801F09C4: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801F09C8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F09CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F09D0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F09D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F09D8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F09DC: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F09E0: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F09E4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F09E8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F09EC: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F09F0: ldc1        $f4, -0x3640($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3640);
    // 0x801F09F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F09F8: ldc1        $f8, -0x3638($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3638);
    // 0x801F09FC: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F0A00: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0A04: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0A08: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F0A0C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F0A10: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0A14: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F0A18: ldc1        $f18, -0x3630($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3630);
    // 0x801F0A1C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0A20: ldc1        $f6, -0x3628($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3628);
    // 0x801F0A24: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F0A28: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0A2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0A30: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F0A34: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F0A38: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F0A3C: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F0A40: ldc1        $f16, -0x3620($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3620);
    // 0x801F0A44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0A48: ldc1        $f4, -0x3618($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3618);
    // 0x801F0A4C: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F0A50: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0A54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0A58: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F0A5C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F0A60: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F0A64: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F0A68: ldc1        $f10, -0x3610($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3610);
    // 0x801F0A6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0A70: ldc1        $f18, -0x3608($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3608);
    // 0x801F0A74: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F0A78: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0A7C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0A80: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F0A84: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F0A88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F0A8C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0A90: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F0A94: ldc1        $f8, -0x3600($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3600);
    // 0x801F0A98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F0A9C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F0AA0: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F0AA4: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0AA8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F0AAC: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F0AB0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F0AB4: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801F0AB8:
    // 0x801F0AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0AC0: jr          $ra
    // 0x801F0AC4: nop

    return;
    // 0x801F0AC4: nop

;}
RECOMP_FUNC void M25_FUN_801f0ac8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0AC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0ACC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0AD8: lui         $a1, 0xC7
    ctx->r5 = S32(0XC7 << 16);
    // 0x801F0ADC: ori         $a1, $a1, 0xE3DF
    ctx->r5 = ctx->r5 | 0XE3DF;
    // 0x801F0AE0: jal         0x801C0B8C
    // 0x801F0AE4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0AE4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0AE8: beq         $v0, $zero, L_801F0B30
    if (ctx->r2 == 0) {
        // 0x801F0AEC: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F0B30;
    }
    // 0x801F0AEC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F0AF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0AF4: lwc1        $f12, -0x35F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X35F8);
    // 0x801F0AF8: lui         $at, 0x423C
    ctx->r1 = S32(0X423C << 16);
    // 0x801F0AFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F0B00: lui         $a2, 0xC133
    ctx->r6 = S32(0XC133 << 16);
    // 0x801F0B04: jal         0x8038BD50
    // 0x801F0B08: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F0B08: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_1:
    // 0x801F0B0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0B10: lwc1        $f12, -0x35F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X35F4);
    // 0x801F0B14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0B18: lui         $a2, 0x408C
    ctx->r6 = S32(0X408C << 16);
    // 0x801F0B1C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801F0B20: jal         0x8038BD88
    // 0x801F0B24: lwc1        $f14, -0x35F0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X35F0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F0B24: lwc1        $f14, -0x35F0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X35F0);
    after_2:
    // 0x801F0B28: b           L_801F1390
    // 0x801F0B2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F1390;
    // 0x801F0B2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F0B30:
    // 0x801F0B30: lui         $a1, 0xC4
    ctx->r5 = S32(0XC4 << 16);
    // 0x801F0B34: jal         0x801C0B8C
    // 0x801F0B38: ori         $a1, $a1, 0xD69F
    ctx->r5 = ctx->r5 | 0XD69F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801F0B38: ori         $a1, $a1, 0xD69F
    ctx->r5 = ctx->r5 | 0XD69F;
    after_3:
    // 0x801F0B3C: beq         $v0, $zero, L_801F0C44
    if (ctx->r2 == 0) {
        // 0x801F0B40: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F0C44;
    }
    // 0x801F0B40: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F0B44: jal         0x801C0B2C
    // 0x801F0B48: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_4;
    // 0x801F0B48: nop

    after_4:
    // 0x801F0B4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F0B50: jal         0x80034C24
    // 0x801F0B54: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_5;
    // 0x801F0B54: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x801F0B58: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0B5C: ldc1        $f4, -0x35E8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X35E8);
    // 0x801F0B60: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0B64: ldc1        $f8, -0x35E0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X35E0);
    // 0x801F0B68: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F0B6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0B70: ldc1        $f4, -0x35D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X35D8);
    // 0x801F0B74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0B78: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F0B7C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F0B80: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0B84: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F0B88: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F0B8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F0B90: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x801F0B94: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0B98: ldc1        $f10, -0x35D0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X35D0);
    // 0x801F0B9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0BA0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F0BA4: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F0BA8: mul.d       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801F0BAC: add.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f2.d + ctx->f10.d;
    // 0x801F0BB0: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x801F0BB4: swc1        $f14, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f14.u32l;
    // 0x801F0BB8: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0BBC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F0BC0: swc1        $f14, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f14.u32l;
    // 0x801F0BC4: ldc1        $f18, -0x35C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X35C8);
    // 0x801F0BC8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0BCC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0BD0: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0BD4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F0BD8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0BDC: swc1        $f6, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f6.u32l;
    // 0x801F0BE0: ldc1        $f8, -0x35C0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X35C0);
    // 0x801F0BE4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0BE8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0BEC: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0BF0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F0BF4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0BF8: swc1        $f16, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f16.u32l;
    // 0x801F0BFC: ldc1        $f18, -0x35B8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X35B8);
    // 0x801F0C00: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0C04: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0C08: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0C0C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F0C10: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0C14: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F0C18: ldc1        $f8, -0x35B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X35B0);
    // 0x801F0C1C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0C20: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0C24: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0C28: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F0C2C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0C30: swc1        $f16, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f16.u32l;
    // 0x801F0C34: jal         0x8038BE98
    // 0x801F0C38: lwc1        $f12, -0x35A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X35A8);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_6;
    // 0x801F0C38: lwc1        $f12, -0x35A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X35A8);
    after_6:
    // 0x801F0C3C: b           L_801F1390
    // 0x801F0C40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F1390;
    // 0x801F0C40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F0C44:
    // 0x801F0C44: lui         $a1, 0xC1
    ctx->r5 = S32(0XC1 << 16);
    // 0x801F0C48: jal         0x801C0B8C
    // 0x801F0C4C: ori         $a1, $a1, 0xC960
    ctx->r5 = ctx->r5 | 0XC960;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_7;
    // 0x801F0C4C: ori         $a1, $a1, 0xC960
    ctx->r5 = ctx->r5 | 0XC960;
    after_7:
    // 0x801F0C50: beq         $v0, $zero, L_801F0D74
    if (ctx->r2 == 0) {
        // 0x801F0C54: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F0D74;
    }
    // 0x801F0C54: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F0C58: jal         0x801C0B2C
    // 0x801F0C5C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_8;
    // 0x801F0C5C: nop

    after_8:
    // 0x801F0C60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F0C64: jal         0x80034C24
    // 0x801F0C68: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_9;
    // 0x801F0C68: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_9:
    // 0x801F0C6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0C70: ldc1        $f18, -0x35A0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X35A0);
    // 0x801F0C74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0C78: ldc1        $f6, -0x3598($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3598);
    // 0x801F0C7C: div.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x801F0C80: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0C84: ldc1        $f18, -0x3590($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3590);
    // 0x801F0C88: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0C8C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F0C90: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F0C94: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0C98: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F0C9C: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x801F0CA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F0CA4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F0CA8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F0CAC: ldc1        $f8, -0x3588($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3588);
    // 0x801F0CB0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F0CB4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801F0CB8: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x801F0CBC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F0CC0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F0CC4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0CC8: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801F0CCC: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0CD0: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0CD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F0CD8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0CDC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0CE0: swc1        $f16, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f16.u32l;
    // 0x801F0CE4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0CE8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F0CEC: swc1        $f6, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f6.u32l;
    // 0x801F0CF0: ldc1        $f8, -0x3580($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3580);
    // 0x801F0CF4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0CF8: lui         $at, 0xC012
    ctx->r1 = S32(0XC012 << 16);
    // 0x801F0CFC: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0D00: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F0D04: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F0D08: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0D0C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0D10: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0D14: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x801F0D18: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0D1C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F0D20: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0D24: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F0D28: swc1        $f6, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f6.u32l;
    // 0x801F0D2C: ldc1        $f8, -0x3578($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3578);
    // 0x801F0D30: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0D34: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x801F0D38: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0D3C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F0D40: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F0D44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0D48: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0D4C: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0D50: swc1        $f16, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f16.u32l;
    // 0x801F0D54: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0D58: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0D5C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F0D60: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
    // 0x801F0D64: jal         0x8038BE98
    // 0x801F0D68: lwc1        $f12, -0x3570($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3570);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_10;
    // 0x801F0D68: lwc1        $f12, -0x3570($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3570);
    after_10:
    // 0x801F0D6C: b           L_801F1390
    // 0x801F0D70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F1390;
    // 0x801F0D70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F0D74:
    // 0x801F0D74: lui         $a1, 0xBE
    ctx->r5 = S32(0XBE << 16);
    // 0x801F0D78: jal         0x801C0B8C
    // 0x801F0D7C: ori         $a1, $a1, 0xBC20
    ctx->r5 = ctx->r5 | 0XBC20;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_11;
    // 0x801F0D7C: ori         $a1, $a1, 0xBC20
    ctx->r5 = ctx->r5 | 0XBC20;
    after_11:
    // 0x801F0D80: beql        $v0, $zero, L_801F0E98
    if (ctx->r2 == 0) {
        // 0x801F0D84: lui         $a1, 0xBA
        ctx->r5 = S32(0XBA << 16);
            goto L_801F0E98;
    }
    goto skip_0;
    // 0x801F0D84: lui         $a1, 0xBA
    ctx->r5 = S32(0XBA << 16);
    skip_0:
    // 0x801F0D88: jal         0x801C0B2C
    // 0x801F0D8C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_12;
    // 0x801F0D8C: nop

    after_12:
    // 0x801F0D90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F0D94: jal         0x80034C24
    // 0x801F0D98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_13;
    // 0x801F0D98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_13:
    // 0x801F0D9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0DA0: ldc1        $f8, -0x3568($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3568);
    // 0x801F0DA4: lui         $at, 0x4029
    ctx->r1 = S32(0X4029 << 16);
    // 0x801F0DA8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F0DAC: div.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f0.d, ctx->f8.d);
    // 0x801F0DB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F0DB4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0DB8: ldc1        $f8, -0x3560($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3560);
    // 0x801F0DBC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0DC0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F0DC4: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F0DC8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0DCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F0DD0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F0DD4: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x801F0DD8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F0DDC: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801F0DE0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F0DE4: ldc1        $f18, -0x3558($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3558);
    // 0x801F0DE8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0DEC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F0DF0: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801F0DF4: mul.d       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f2.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x801F0DF8: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0DFC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0E00: swc1        $f6, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f6.u32l;
    // 0x801F0E04: ldc1        $f8, -0x3550($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3550);
    // 0x801F0E08: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0E0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0E10: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0E14: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F0E18: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0E1C: swc1        $f16, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f16.u32l;
    // 0x801F0E20: ldc1        $f18, -0x3548($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3548);
    // 0x801F0E24: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0E28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0E2C: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0E30: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F0E34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F0E38: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0E3C: swc1        $f6, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f6.u32l;
    // 0x801F0E40: ldc1        $f8, -0x3540($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3540);
    // 0x801F0E44: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0E48: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x801F0E4C: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0E50: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F0E54: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F0E58: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0E5C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0E60: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F0E64: swc1        $f16, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f16.u32l;
    // 0x801F0E68: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0E6C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F0E70: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F0E74: swc1        $f6, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f6.u32l;
    // 0x801F0E78: ldc1        $f8, -0x3538($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3538);
    // 0x801F0E7C: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0E80: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F0E84: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F0E88: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0E8C: b           L_801F1390
    // 0x801F0E90: swc1        $f16, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f16.u32l;
        goto L_801F1390;
    // 0x801F0E90: swc1        $f16, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f16.u32l;
    // 0x801F0E94: lui         $a1, 0xBA
    ctx->r5 = S32(0XBA << 16);
L_801F0E98:
    // 0x801F0E98: ori         $a1, $a1, 0x2840
    ctx->r5 = ctx->r5 | 0X2840;
    // 0x801F0E9C: jal         0x801C0B8C
    // 0x801F0EA0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_14;
    // 0x801F0EA0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_14:
    // 0x801F0EA4: beql        $v0, $zero, L_801F0FE0
    if (ctx->r2 == 0) {
        // 0x801F0EA8: lui         $a1, 0xB1
        ctx->r5 = S32(0XB1 << 16);
            goto L_801F0FE0;
    }
    goto skip_1;
    // 0x801F0EA8: lui         $a1, 0xB1
    ctx->r5 = S32(0XB1 << 16);
    skip_1:
    // 0x801F0EAC: jal         0x801C0B2C
    // 0x801F0EB0: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_15;
    // 0x801F0EB0: nop

    after_15:
    // 0x801F0EB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F0EB8: jal         0x80034C24
    // 0x801F0EBC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_16;
    // 0x801F0EBC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_16:
    // 0x801F0EC0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0EC4: ldc1        $f18, -0x3530($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3530);
    // 0x801F0EC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0ECC: ldc1        $f6, -0x3528($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3528);
    // 0x801F0ED0: div.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x801F0ED4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0ED8: ldc1        $f18, -0x3520($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3520);
    // 0x801F0EDC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0EE0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F0EE4: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F0EE8: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0EEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F0EF0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F0EF4: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x801F0EF8: ldc1        $f4, -0x3518($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3518);
    // 0x801F0EFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0F00: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F0F04: ldc1        $f8, -0x3510($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3510);
    // 0x801F0F08: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0F0C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801F0F10: div.d       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x801F0F14: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F0F18: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F0F1C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F0F20: swc1        $f16, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f16.u32l;
    // 0x801F0F24: ldc1        $f18, -0x3508($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3508);
    // 0x801F0F28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0F2C: ldc1        $f6, -0x3500($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3500);
    // 0x801F0F30: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F0F34: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0F38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0F3C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F0F40: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F0F44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F0F48: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F0F4C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x801F0F50: swc1        $f10, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f10.u32l;
    // 0x801F0F54: ldc1        $f16, -0x34F8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X34F8);
    // 0x801F0F58: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x801F0F5C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F0F60: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F0F64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F0F68: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0F6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0F70: mul.d       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F0F74: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F0F78: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F0F7C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F0F80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F0F84: swc1        $f8, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f8.u32l;
    // 0x801F0F88: ldc1        $f16, -0x34F0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X34F0);
    // 0x801F0F8C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0F90: lui         $at, 0x402F
    ctx->r1 = S32(0X402F << 16);
    // 0x801F0F94: add.d       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f12.d + ctx->f16.d;
    // 0x801F0F98: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F0F9C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F0FA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F0FA4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F0FA8: add.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d + ctx->f6.d;
    // 0x801F0FAC: swc1        $f4, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f4.u32l;
    // 0x801F0FB0: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0FB4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F0FB8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F0FBC: swc1        $f10, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
    // 0x801F0FC0: ldc1        $f16, -0x34E8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X34E8);
    // 0x801F0FC4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F0FC8: add.d       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f12.d + ctx->f16.d;
    // 0x801F0FCC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F0FD0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F0FD4: b           L_801F1390
    // 0x801F0FD8: swc1        $f4, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f4.u32l;
        goto L_801F1390;
    // 0x801F0FD8: swc1        $f4, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f4.u32l;
    // 0x801F0FDC: lui         $a1, 0xB1
    ctx->r5 = S32(0XB1 << 16);
L_801F0FE0:
    // 0x801F0FE0: ori         $a1, $a1, 0x80
    ctx->r5 = ctx->r5 | 0X80;
    // 0x801F0FE4: jal         0x801C0B8C
    // 0x801F0FE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_17;
    // 0x801F0FE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_17:
    // 0x801F0FEC: beql        $v0, $zero, L_801F111C
    if (ctx->r2 == 0) {
        // 0x801F0FF0: lui         $a1, 0xA1
        ctx->r5 = S32(0XA1 << 16);
            goto L_801F111C;
    }
    goto skip_2;
    // 0x801F0FF0: lui         $a1, 0xA1
    ctx->r5 = S32(0XA1 << 16);
    skip_2:
    // 0x801F0FF4: jal         0x801C0B2C
    // 0x801F0FF8: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_18;
    // 0x801F0FF8: nop

    after_18:
    // 0x801F0FFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F1000: jal         0x80034C24
    // 0x801F1004: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_19;
    // 0x801F1004: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_19:
    // 0x801F1008: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F100C: ldc1        $f6, -0x34E0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X34E0);
    // 0x801F1010: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1014: ldc1        $f10, -0x34D8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X34D8);
    // 0x801F1018: div.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x801F101C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1020: ldc1        $f6, -0x34D0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X34D0);
    // 0x801F1024: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1028: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F102C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1030: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1034: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F1038: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F103C: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x801F1040: ldc1        $f8, -0x34C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X34C8);
    // 0x801F1044: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1048: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F104C: ldc1        $f16, -0x34C0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X34C0);
    // 0x801F1050: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F1054: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F1058: div.d       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801F105C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F1060: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F1064: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x801F1068: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F106C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F1070: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1074: mul.d       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x801F1078: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F107C: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F1080: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1084: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1088: swc1        $f4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f4.u32l;
    // 0x801F108C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1090: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1094: swc1        $f16, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f16.u32l;
    // 0x801F1098: ldc1        $f18, -0x34B8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X34B8);
    // 0x801F109C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F10A0: ldc1        $f6, -0x34B0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X34B0);
    // 0x801F10A4: mul.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f12.d, ctx->f18.d);
    // 0x801F10A8: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F10AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F10B0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F10B4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F10B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F10BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F10C0: swc1        $f10, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f10.u32l;
    // 0x801F10C4: ldc1        $f16, -0x34A8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X34A8);
    // 0x801F10C8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F10CC: lui         $at, 0x402F
    ctx->r1 = S32(0X402F << 16);
    // 0x801F10D0: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x801F10D4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F10D8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F10DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F10E0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F10E4: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801F10E8: swc1        $f4, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f4.u32l;
    // 0x801F10EC: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F10F0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F10F4: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F10F8: swc1        $f10, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f10.u32l;
    // 0x801F10FC: ldc1        $f16, -0x34A0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X34A0);
    // 0x801F1100: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1104: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x801F1108: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F110C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1110: b           L_801F1390
    // 0x801F1114: swc1        $f4, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f4.u32l;
        goto L_801F1390;
    // 0x801F1114: swc1        $f4, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f4.u32l;
    // 0x801F1118: lui         $a1, 0xA1
    ctx->r5 = S32(0XA1 << 16);
L_801F111C:
    // 0x801F111C: ori         $a1, $a1, 0xBE40
    ctx->r5 = ctx->r5 | 0XBE40;
    // 0x801F1120: jal         0x801C0B8C
    // 0x801F1124: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_20;
    // 0x801F1124: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_20:
    // 0x801F1128: beq         $v0, $zero, L_801F1260
    if (ctx->r2 == 0) {
        // 0x801F112C: nop
    
            goto L_801F1260;
    }
    // 0x801F112C: nop

    // 0x801F1130: jal         0x801C0B2C
    // 0x801F1134: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_21;
    // 0x801F1134: nop

    after_21:
    // 0x801F1138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F113C: jal         0x80034C24
    // 0x801F1140: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_22;
    // 0x801F1140: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_22:
    // 0x801F1144: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1148: ldc1        $f6, -0x3498($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3498);
    // 0x801F114C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1150: ldc1        $f10, -0x3490($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3490);
    // 0x801F1154: div.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x801F1158: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801F115C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F1160: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F1164: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1168: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F116C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1170: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1174: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F1178: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F117C: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x801F1180: ldc1        $f8, -0x3488($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3488);
    // 0x801F1184: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1188: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F118C: ldc1        $f16, -0x3480($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3480);
    // 0x801F1190: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1194: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F1198: div.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801F119C: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F11A0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F11A4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F11A8: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x801F11AC: ldc1        $f6, -0x3478($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3478);
    // 0x801F11B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F11B4: ldc1        $f10, -0x3470($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3470);
    // 0x801F11B8: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F11BC: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F11C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F11C4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F11C8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F11CC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F11D0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x801F11D4: swc1        $f18, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f18.u32l;
    // 0x801F11D8: ldc1        $f4, -0x3468($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3468);
    // 0x801F11DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F11E0: ldc1        $f8, -0x3460($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3460);
    // 0x801F11E4: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F11E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F11EC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F11F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F11F4: mul.d       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F11F8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F11FC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F1200: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1204: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F1208: swc1        $f16, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f16.u32l;
    // 0x801F120C: ldc1        $f4, -0x3458($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3458);
    // 0x801F1210: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1214: lui         $at, 0x402F
    ctx->r1 = S32(0X402F << 16);
    // 0x801F1218: add.d       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f12.d + ctx->f4.d;
    // 0x801F121C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F1220: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F1224: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1228: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F122C: add.d       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f12.d + ctx->f10.d;
    // 0x801F1230: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F1234: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1238: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F123C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1240: swc1        $f18, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f18.u32l;
    // 0x801F1244: ldc1        $f4, -0x3450($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3450);
    // 0x801F1248: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F124C: add.d       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f12.d + ctx->f4.d;
    // 0x801F1250: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1254: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F1258: b           L_801F1390
    // 0x801F125C: swc1        $f8, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f8.u32l;
        goto L_801F1390;
    // 0x801F125C: swc1        $f8, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f8.u32l;
L_801F1260:
    // 0x801F1260: jal         0x801C0B2C
    // 0x801F1264: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_23;
    // 0x801F1264: nop

    after_23:
    // 0x801F1268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F126C: jal         0x80034C24
    // 0x801F1270: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_24;
    // 0x801F1270: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_24:
    // 0x801F1274: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1278: ldc1        $f10, -0x3448($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3448);
    // 0x801F127C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1280: ldc1        $f18, -0x3440($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3440);
    // 0x801F1284: div.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x801F1288: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801F128C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F1290: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F1294: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1298: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F129C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F12A0: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F12A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F12A8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F12AC: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x801F12B0: ldc1        $f16, -0x3438($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3438);
    // 0x801F12B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F12B8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F12BC: ldc1        $f4, -0x3430($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3430);
    // 0x801F12C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F12C4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F12C8: div.d       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x801F12CC: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F12D0: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F12D4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F12D8: swc1        $f8, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f8.u32l;
    // 0x801F12DC: ldc1        $f10, -0x3428($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3428);
    // 0x801F12E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F12E4: ldc1        $f18, -0x3420($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3420);
    // 0x801F12E8: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F12EC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F12F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F12F4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F12F8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F12FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F1300: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1304: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F1308: swc1        $f6, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f6.u32l;
    // 0x801F130C: ldc1        $f8, -0x3418($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3418);
    // 0x801F1310: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x801F1314: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F1318: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F131C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F1320: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1324: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1328: mul.d       $f12, $f2, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F132C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F1330: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F1334: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1338: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F133C: swc1        $f4, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f4.u32l;
    // 0x801F1340: ldc1        $f8, -0x3410($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3410);
    // 0x801F1344: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1348: lui         $at, 0x402F
    ctx->r1 = S32(0X402F << 16);
    // 0x801F134C: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x801F1350: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F1354: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1358: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F135C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1360: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801F1364: swc1        $f16, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f16.u32l;
    // 0x801F1368: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F136C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1370: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1374: swc1        $f6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f6.u32l;
    // 0x801F1378: ldc1        $f8, -0x3408($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3408);
    // 0x801F137C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1380: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x801F1384: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F1388: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F138C: swc1        $f16, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f16.u32l;
L_801F1390:
    // 0x801F1390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F1394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F1398: jr          $ra
    // 0x801F139C: nop

    return;
    // 0x801F139C: nop

;}
RECOMP_FUNC void M25_FUN_801f13a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F13A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F13A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F13A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F13AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F13B0: lui         $a1, 0xF5
    ctx->r5 = S32(0XF5 << 16);
    // 0x801F13B4: ori         $a1, $a1, 0xAA9F
    ctx->r5 = ctx->r5 | 0XAA9F;
    // 0x801F13B8: jal         0x801C0B8C
    // 0x801F13BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F13BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F13C0: beq         $v0, $zero, L_801F13D0
    if (ctx->r2 == 0) {
        // 0x801F13C4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F13D0;
    }
    // 0x801F13C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F13C8: b           L_801F17F4
    // 0x801F13CC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F17F4;
    // 0x801F13CC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F13D0:
    // 0x801F13D0: lui         $a1, 0xE9
    ctx->r5 = S32(0XE9 << 16);
    // 0x801F13D4: jal         0x801C0B8C
    // 0x801F13D8: ori         $a1, $a1, 0x759F
    ctx->r5 = ctx->r5 | 0X759F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F13D8: ori         $a1, $a1, 0x759F
    ctx->r5 = ctx->r5 | 0X759F;
    after_1:
    // 0x801F13DC: beql        $v0, $zero, L_801F1534
    if (ctx->r2 == 0) {
        // 0x801F13E0: lui         $a1, 0xD7
        ctx->r5 = S32(0XD7 << 16);
            goto L_801F1534;
    }
    goto skip_0;
    // 0x801F13E0: lui         $a1, 0xD7
    ctx->r5 = S32(0XD7 << 16);
    skip_0:
    // 0x801F13E4: jal         0x801C0B2C
    // 0x801F13E8: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801F13E8: nop

    after_2:
    // 0x801F13EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F13F0: jal         0x80034C24
    // 0x801F13F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801F13F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801F13F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F13FC: ldc1        $f4, -0x3400($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3400);
    // 0x801F1400: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1404: ldc1        $f8, -0x33F8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X33F8);
    // 0x801F1408: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F140C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1410: ldc1        $f4, -0x33F0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X33F0);
    // 0x801F1414: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x801F1418: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F141C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1420: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1424: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801F1428: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F142C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F1430: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F1434: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F1438: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F143C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1440: ldc1        $f10, -0x33E8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X33E8);
    // 0x801F1444: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1448: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F144C: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F1450: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F1454: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F1458: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F145C: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F1460: ldc1        $f4, -0x33E0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X33E0);
    // 0x801F1464: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1468: ldc1        $f8, -0x33D8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X33D8);
    // 0x801F146C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F1470: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1474: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1478: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F147C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F1480: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1484: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F1488: ldc1        $f18, -0x33D0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X33D0);
    // 0x801F148C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1490: ldc1        $f6, -0x33C8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X33C8);
    // 0x801F1494: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F1498: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F149C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F14A0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F14A4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F14A8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F14AC: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F14B0: ldc1        $f16, -0x33C0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X33C0);
    // 0x801F14B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F14B8: ldc1        $f4, -0x33B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X33B8);
    // 0x801F14BC: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F14C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F14C4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F14C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F14CC: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F14D0: lui         $at, 0x4026
    ctx->r1 = S32(0X4026 << 16);
    // 0x801F14D4: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F14D8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F14DC: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F14E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F14E4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F14E8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F14EC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F14F0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F14F4: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F14F8: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F14FC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1500: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1504: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F1508: ldc1        $f8, -0x33B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X33B0);
    // 0x801F150C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1510: ldc1        $f16, -0x33A8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X33A8);
    // 0x801F1514: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F1518: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F151C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1520: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F1524: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1528: b           L_801F17F4
    // 0x801F152C: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
        goto L_801F17F4;
    // 0x801F152C: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
    // 0x801F1530: lui         $a1, 0xD7
    ctx->r5 = S32(0XD7 << 16);
L_801F1534:
    // 0x801F1534: ori         $a1, $a1, 0x261F
    ctx->r5 = ctx->r5 | 0X261F;
    // 0x801F1538: jal         0x801C0B8C
    // 0x801F153C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_4;
    // 0x801F153C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_4:
    // 0x801F1540: beq         $v0, $zero, L_801F16A4
    if (ctx->r2 == 0) {
        // 0x801F1544: nop
    
            goto L_801F16A4;
    }
    // 0x801F1544: nop

    // 0x801F1548: jal         0x801C0B2C
    // 0x801F154C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801F154C: nop

    after_5:
    // 0x801F1550: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F1554: jal         0x80034C24
    // 0x801F1558: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_6;
    // 0x801F1558: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_6:
    // 0x801F155C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1560: ldc1        $f6, -0x33A0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X33A0);
    // 0x801F1564: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1568: ldc1        $f10, -0x3398($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3398);
    // 0x801F156C: div.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x801F1570: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1574: ldc1        $f6, -0x3390($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3390);
    // 0x801F1578: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801F157C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F1580: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1584: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1588: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801F158C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F1590: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x801F1594: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F1598: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F159C: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x801F15A0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F15A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F15A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F15AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F15B0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F15B4: div.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801F15B8: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F15BC: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F15C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F15C4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F15C8: swc1        $f4, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f4.u32l;
    // 0x801F15CC: ldc1        $f6, -0x3388($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3388);
    // 0x801F15D0: lui         $at, 0x4012
    ctx->r1 = S32(0X4012 << 16);
    // 0x801F15D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F15D8: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F15DC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F15E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F15E4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F15E8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F15EC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F15F0: swc1        $f18, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f18.u32l;
    // 0x801F15F4: ldc1        $f4, -0x3380($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3380);
    // 0x801F15F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F15FC: ldc1        $f8, -0x3378($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3378);
    // 0x801F1600: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F1604: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1608: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F160C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F1610: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F1614: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F1618: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F161C: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x801F1620: ldc1        $f18, -0x3370($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3370);
    // 0x801F1624: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x801F1628: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F162C: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F1630: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801F1634: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F1638: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F163C: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1640: lui         $at, 0x402A
    ctx->r1 = S32(0X402A << 16);
    // 0x801F1644: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F1648: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F164C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F1650: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F1654: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F1658: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F165C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F1660: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F1664: swc1        $f10, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f10.u32l;
    // 0x801F1668: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F166C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F1670: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F1674: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1678: swc1        $f8, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f8.u32l;
    // 0x801F167C: ldc1        $f10, -0x3368($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3368);
    // 0x801F1680: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x801F1684: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F1688: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F168C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1690: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F1694: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F1698: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F169C: b           L_801F17F4
    // 0x801F16A0: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
        goto L_801F17F4;
    // 0x801F16A0: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
L_801F16A4:
    // 0x801F16A4: jal         0x801C0B2C
    // 0x801F16A8: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_7;
    // 0x801F16A8: nop

    after_7:
    // 0x801F16AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F16B0: jal         0x80034C24
    // 0x801F16B4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_8;
    // 0x801F16B4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_8:
    // 0x801F16B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F16BC: ldc1        $f8, -0x3360($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3360);
    // 0x801F16C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F16C4: ldc1        $f16, -0x3358($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3358);
    // 0x801F16C8: div.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f0.d, ctx->f8.d);
    // 0x801F16CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801F16D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F16D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F16D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F16DC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F16E0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F16E4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F16E8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F16EC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x801F16F0: ldc1        $f10, -0x3350($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3350);
    // 0x801F16F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F16F8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F16FC: ldc1        $f18, -0x3348($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3348);
    // 0x801F1700: lui         $at, 0xC030
    ctx->r1 = S32(0XC030 << 16);
    // 0x801F1704: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F1708: div.d       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801F170C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F1710: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F1714: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1718: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F171C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F1720: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F1724: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1728: swc1        $f6, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f6.u32l;
    // 0x801F172C: ldc1        $f16, -0x3340($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3340);
    // 0x801F1730: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1734: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1738: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F173C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F1740: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1744: swc1        $f4, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f4.u32l;
    // 0x801F1748: ldc1        $f6, -0x3338($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3338);
    // 0x801F174C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1750: ldc1        $f10, -0x3330($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3330);
    // 0x801F1754: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F1758: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F175C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1760: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1764: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F1768: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F176C: swc1        $f18, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f18.u32l;
    // 0x801F1770: ldc1        $f4, -0x3328($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3328);
    // 0x801F1774: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1778: ldc1        $f8, -0x3320($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3320);
    // 0x801F177C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F1780: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1784: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1788: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F178C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F1790: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1794: swc1        $f16, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f16.u32l;
    // 0x801F1798: ldc1        $f18, -0x3318($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3318);
    // 0x801F179C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F17A0: ldc1        $f6, -0x3310($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3310);
    // 0x801F17A4: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F17A8: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F17AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F17B0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F17B4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F17B8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F17BC: swc1        $f10, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f10.u32l;
    // 0x801F17C0: ldc1        $f16, -0x3308($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3308);
    // 0x801F17C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F17C8: ldc1        $f4, -0x3300($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3300);
    // 0x801F17CC: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F17D0: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F17D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F17D8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F17DC: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F17E0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F17E4: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
    // 0x801F17E8: jal         0x8038BE98
    // 0x801F17EC: lwc1        $f12, -0x32F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X32F8);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_9;
    // 0x801F17EC: lwc1        $f12, -0x32F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X32F8);
    after_9:
    // 0x801F17F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F17F4:
    // 0x801F17F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F17F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F17FC: jr          $ra
    // 0x801F1800: nop

    return;
    // 0x801F1800: nop

;}
RECOMP_FUNC void M25_FUN_801f1804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F1804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F1808: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F180C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F1810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F1814: lui         $a1, 0x104
    ctx->r5 = S32(0X104 << 16);
    // 0x801F1818: ori         $a1, $a1, 0xECDF
    ctx->r5 = ctx->r5 | 0XECDF;
    // 0x801F181C: jal         0x801C0B8C
    // 0x801F1820: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F1820: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F1824: beq         $v0, $zero, L_801F1834
    if (ctx->r2 == 0) {
        // 0x801F1828: nop
    
            goto L_801F1834;
    }
    // 0x801F1828: nop

    // 0x801F182C: b           L_801F1984
    // 0x801F1830: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F1984;
    // 0x801F1830: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F1834:
    // 0x801F1834: jal         0x801C0B2C
    // 0x801F1838: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F1838: nop

    after_1:
    // 0x801F183C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F1840: jal         0x80034C24
    // 0x801F1844: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F1844: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F1848: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F184C: ldc1        $f4, -0x32F0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X32F0);
    // 0x801F1850: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1854: ldc1        $f8, -0x32E8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X32E8);
    // 0x801F1858: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F185C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801F1860: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F1864: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F1868: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F186C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F1870: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1874: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1878: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801F187C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1880: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F1884: ldc1        $f6, -0x32E0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X32E0);
    // 0x801F1888: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F188C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1890: ldc1        $f10, -0x32D8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X32D8);
    // 0x801F1894: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1898: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F189C: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F18A0: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F18A4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F18A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F18AC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F18B0: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F18B4: ldc1        $f4, -0x32D0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X32D0);
    // 0x801F18B8: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x801F18BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F18C0: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F18C4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801F18C8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F18CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F18D0: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F18D4: lui         $at, 0xC016
    ctx->r1 = S32(0XC016 << 16);
    // 0x801F18D8: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F18DC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F18E0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F18E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F18E8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F18EC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F18F0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F18F4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F18F8: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F18FC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1900: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F1904: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F1908: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F190C: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F1910: ldc1        $f16, -0x32C8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X32C8);
    // 0x801F1914: lui         $at, 0xC034
    ctx->r1 = S32(0XC034 << 16);
    // 0x801F1918: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F191C: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F1920: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1924: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1928: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F192C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F1930: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F1934: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F1938: ldc1        $f10, -0x32C0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X32C0);
    // 0x801F193C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1940: ldc1        $f18, -0x32B8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X32B8);
    // 0x801F1944: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F1948: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F194C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1950: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1954: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F1958: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F195C: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F1960: ldc1        $f8, -0x32B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X32B0);
    // 0x801F1964: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1968: ldc1        $f16, -0x32A8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X32A8);
    // 0x801F196C: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F1970: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1974: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1978: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F197C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1980: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801F1984:
    // 0x801F1984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F1988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F198C: jr          $ra
    // 0x801F1990: nop

    return;
    // 0x801F1990: nop

;}
RECOMP_FUNC void M25_FUN_801f1994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F1994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F1998: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F199C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f19a0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f19a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F19A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F19A4: lui         $a1, 0x132
    ctx->r5 = S32(0X132 << 16);
    // 0x801F19A8: ori         $a1, $a1, 0xB39F
    ctx->r5 = ctx->r5 | 0XB39F;
    // 0x801F19AC: jal         0x801C0B8C
    // 0x801F19B0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F19B0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F19B4: beq         $v0, $zero, L_801F19C4
    if (ctx->r2 == 0) {
        // 0x801F19B8: nop
    
            goto L_801F19C4;
    }
    // 0x801F19B8: nop

    // 0x801F19BC: b           L_801F1AF4
    // 0x801F19C0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F1AF4;
    // 0x801F19C0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F19C4:
    // 0x801F19C4: jal         0x801C0B2C
    // 0x801F19C8: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F19C8: nop

    after_1:
    // 0x801F19CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F19D0: jal         0x80034C24
    // 0x801F19D4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F19D4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F19D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F19DC: ldc1        $f4, -0x32A0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X32A0);
    // 0x801F19E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F19E4: ldc1        $f8, -0x3298($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3298);
    // 0x801F19E8: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F19EC: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801F19F0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F19F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F19F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F19FC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F1A00: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1A04: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1A08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801F1A0C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1A10: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F1A14: ldc1        $f6, -0x3290($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3290);
    // 0x801F1A18: lui         $at, 0xC031
    ctx->r1 = S32(0XC031 << 16);
    // 0x801F1A1C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1A20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F1A24: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F1A28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1A2C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F1A30: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F1A34: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F1A38: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F1A3C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F1A40: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F1A44: ldc1        $f4, -0x3288($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3288);
    // 0x801F1A48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1A4C: ldc1        $f8, -0x3280($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3280);
    // 0x801F1A50: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F1A54: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1A58: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1A5C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F1A60: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F1A64: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1A68: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801F1A6C: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F1A70: ldc1        $f18, -0x3278($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3278);
    // 0x801F1A74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F1A78: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1A7C: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F1A80: ldc1        $f6, -0x3270($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3270);
    // 0x801F1A84: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1A88: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801F1A8C: mul.d       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F1A90: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F1A94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F1A98: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F1A9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1AA0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F1AA4: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801F1AA8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F1AAC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1AB0: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F1AB4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1AB8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F1ABC: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801F1AC0: ldc1        $f8, -0x3268($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3268);
    // 0x801F1AC4: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1AC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1ACC: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x801F1AD0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1AD4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1AD8: swc1        $f16, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f16.u32l;
    // 0x801F1ADC: ldc1        $f18, -0x3260($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3260);
    // 0x801F1AE0: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1AE4: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801F1AE8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1AEC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1AF0: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
L_801F1AF4:
    // 0x801F1AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F1AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F1AFC: jr          $ra
    // 0x801F1B00: nop

    return;
    // 0x801F1B00: nop

;}
RECOMP_FUNC void M25_FUN_801f1b04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F1B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F1B08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F1B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F1B10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F1B14: lui         $a1, 0x160
    ctx->r5 = S32(0X160 << 16);
    // 0x801F1B18: ori         $a1, $a1, 0x7A5F
    ctx->r5 = ctx->r5 | 0X7A5F;
    // 0x801F1B1C: jal         0x801C0B8C
    // 0x801F1B20: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F1B20: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F1B24: beq         $v0, $zero, L_801F1B34
    if (ctx->r2 == 0) {
        // 0x801F1B28: nop
    
            goto L_801F1B34;
    }
    // 0x801F1B28: nop

    // 0x801F1B2C: b           L_801F1C80
    // 0x801F1B30: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801F1C80;
    // 0x801F1B30: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F1B34:
    // 0x801F1B34: jal         0x801C0B2C
    // 0x801F1B38: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F1B38: nop

    after_1:
    // 0x801F1B3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F1B40: jal         0x80034C24
    // 0x801F1B44: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F1B44: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F1B48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1B4C: ldc1        $f4, -0x3258($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3258);
    // 0x801F1B50: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1B54: ldc1        $f8, -0x3250($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3250);
    // 0x801F1B58: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F1B5C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801F1B60: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F1B64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F1B68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1B6C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F1B70: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1B74: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1B78: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801F1B7C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1B80: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F1B84: ldc1        $f6, -0x3248($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3248);
    // 0x801F1B88: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1B8C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1B90: ldc1        $f10, -0x3240($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3240);
    // 0x801F1B94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1B98: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F1B9C: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F1BA0: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F1BA4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F1BA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F1BAC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F1BB0: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F1BB4: ldc1        $f4, -0x3238($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3238);
    // 0x801F1BB8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801F1BBC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F1BC0: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F1BC4: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1BC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1BCC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F1BD0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F1BD4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1BD8: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F1BDC: ldc1        $f18, -0x3230($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3230);
    // 0x801F1BE0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1BE4: ldc1        $f6, -0x3228($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3228);
    // 0x801F1BE8: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F1BEC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1BF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1BF4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F1BF8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F1BFC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F1C00: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F1C04: ldc1        $f16, -0x3220($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3220);
    // 0x801F1C08: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1C0C: ldc1        $f4, -0x3218($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3218);
    // 0x801F1C10: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F1C14: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801F1C18: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F1C1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F1C20: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1C24: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1C28: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F1C2C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F1C30: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F1C34: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F1C38: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F1C3C: ldc1        $f18, -0x3210($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3210);
    // 0x801F1C40: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1C44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1C48: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F1C4C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1C50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F1C54: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1C58: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F1C5C: ldc1        $f8, -0x3208($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3208);
    // 0x801F1C60: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801F1C64: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F1C68: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F1C6C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1C70: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1C74: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F1C78: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1C7C: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801F1C80:
    // 0x801F1C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F1C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F1C88: jr          $ra
    // 0x801F1C8C: nop

    return;
    // 0x801F1C8C: nop

;}
RECOMP_FUNC void M25_FUN_801f1c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F1C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F1C94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F1C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F1C9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F1CA0: lui         $a1, 0x17E
    ctx->r5 = S32(0X17E << 16);
    // 0x801F1CA4: ori         $a1, $a1, 0xFEDF
    ctx->r5 = ctx->r5 | 0XFEDF;
    // 0x801F1CA8: jal         0x801C0B8C
    // 0x801F1CAC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F1CAC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F1CB0: beq         $v0, $zero, L_801F1CF0
    if (ctx->r2 == 0) {
        // 0x801F1CB4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F1CF0;
    }
    // 0x801F1CB4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F1CB8: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x801F1CBC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F1CC0: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x801F1CC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F1CC8: jal         0x8038BD50
    // 0x801F1CCC: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F1CCC: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    after_1:
    // 0x801F1CD0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1CD4: lwc1        $f12, -0x3200($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3200);
    // 0x801F1CD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1CDC: lwc1        $f14, -0x31FC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X31FC);
    // 0x801F1CE0: jal         0x8038BD88
    // 0x801F1CE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F1CE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x801F1CE8: b           L_801F1E90
    // 0x801F1CEC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801F1E90;
    // 0x801F1CEC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F1CF0:
    // 0x801F1CF0: lui         $a1, 0x168
    ctx->r5 = S32(0X168 << 16);
    // 0x801F1CF4: jal         0x801C0B8C
    // 0x801F1CF8: ori         $a1, $a1, 0x1B7F
    ctx->r5 = ctx->r5 | 0X1B7F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801F1CF8: ori         $a1, $a1, 0x1B7F
    ctx->r5 = ctx->r5 | 0X1B7F;
    after_3:
    // 0x801F1CFC: beq         $v0, $zero, L_801F1E54
    if (ctx->r2 == 0) {
        // 0x801F1D00: nop
    
            goto L_801F1E54;
    }
    // 0x801F1D00: nop

    // 0x801F1D04: jal         0x801C0B2C
    // 0x801F1D08: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_4;
    // 0x801F1D08: nop

    after_4:
    // 0x801F1D0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F1D10: jal         0x80034C24
    // 0x801F1D14: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_5;
    // 0x801F1D14: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x801F1D18: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1D1C: ldc1        $f4, -0x31F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X31F8);
    // 0x801F1D20: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1D24: ldc1        $f8, -0x31F0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X31F0);
    // 0x801F1D28: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F1D2C: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801F1D30: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F1D34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F1D38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1D3C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F1D40: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1D44: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1D48: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801F1D4C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1D50: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F1D54: ldc1        $f6, -0x31E8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X31E8);
    // 0x801F1D58: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1D5C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1D60: ldc1        $f10, -0x31E0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X31E0);
    // 0x801F1D64: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1D68: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F1D6C: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F1D70: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F1D74: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F1D78: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F1D7C: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F1D80: ldc1        $f4, -0x31D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X31D8);
    // 0x801F1D84: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1D88: ldc1        $f8, -0x31D0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X31D0);
    // 0x801F1D8C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F1D90: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1D94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1D98: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F1D9C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F1DA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F1DA4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F1DA8: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F1DAC: ldc1        $f18, -0x31C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X31C8);
    // 0x801F1DB0: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801F1DB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F1DB8: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F1DBC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1DC0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1DC4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F1DC8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F1DCC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F1DD0: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F1DD4: ldc1        $f16, -0x31C0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X31C0);
    // 0x801F1DD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1DDC: ldc1        $f4, -0x31B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X31B8);
    // 0x801F1DE0: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F1DE4: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x801F1DE8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F1DEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F1DF0: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1DF4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1DF8: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F1DFC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F1E00: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F1E04: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F1E08: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F1E0C: ldc1        $f18, -0x31B0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X31B0);
    // 0x801F1E10: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1E14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1E18: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F1E1C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F1E20: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F1E24: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F1E28: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F1E2C: ldc1        $f8, -0x31A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X31A8);
    // 0x801F1E30: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x801F1E34: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F1E38: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F1E3C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1E40: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1E44: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F1E48: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F1E4C: b           L_801F1E90
    // 0x801F1E50: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
        goto L_801F1E90;
    // 0x801F1E50: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801F1E54:
    // 0x801F1E54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1E58: lwc1        $f12, -0x31A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X31A0);
    // 0x801F1E5C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F1E60: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F1E64: lui         $a2, 0xC0C6
    ctx->r6 = S32(0XC0C6 << 16);
    // 0x801F1E68: jal         0x8038BD50
    // 0x801F1E6C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_6;
    // 0x801F1E6C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    after_6:
    // 0x801F1E70: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801F1E74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F1E78: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1E7C: lui         $a2, 0xBF33
    ctx->r6 = S32(0XBF33 << 16);
    // 0x801F1E80: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801F1E84: jal         0x8038BD88
    // 0x801F1E88: lwc1        $f14, -0x319C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X319C);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_7;
    // 0x801F1E88: lwc1        $f14, -0x319C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X319C);
    after_7:
    // 0x801F1E8C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F1E90:
    // 0x801F1E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F1E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F1E98: jr          $ra
    // 0x801F1E9C: nop

    return;
    // 0x801F1E9C: nop

;}
RECOMP_FUNC void M25_FUN_801f1ea0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F1EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F1EA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F1EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F1EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F1EB0: lui         $a1, 0x1BC
    ctx->r5 = S32(0X1BC << 16);
    // 0x801F1EB4: ori         $a1, $a1, 0x7DF
    ctx->r5 = ctx->r5 | 0X7DF;
    // 0x801F1EB8: jal         0x801C0B8C
    // 0x801F1EBC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F1EBC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F1EC0: beq         $v0, $zero, L_801F1F08
    if (ctx->r2 == 0) {
        // 0x801F1EC4: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F1F08;
    }
    // 0x801F1EC4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F1EC8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F1ECC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F1ED0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1ED4: lui         $a2, 0xC1A5
    ctx->r6 = S32(0XC1A5 << 16);
    // 0x801F1ED8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801F1EDC: jal         0x8038BD50
    // 0x801F1EE0: lwc1        $f14, -0x3198($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3198);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F1EE0: lwc1        $f14, -0x3198($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3198);
    after_1:
    // 0x801F1EE4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801F1EE8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F1EEC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1EF0: lui         $a2, 0xBF99
    ctx->r6 = S32(0XBF99 << 16);
    // 0x801F1EF4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801F1EF8: jal         0x8038BD88
    // 0x801F1EFC: lwc1        $f14, -0x3194($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3194);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F1EFC: lwc1        $f14, -0x3194($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3194);
    after_2:
    // 0x801F1F00: b           L_801F1FAC
    // 0x801F1F04: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801F1FAC;
    // 0x801F1F04: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801F1F08:
    // 0x801F1F08: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F1F0C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1F10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1F14: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801F1F18: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F1F1C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F1F20: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x801F1F24: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1F28: lwc1        $f8, -0x3190($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3190);
    // 0x801F1F2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1F30: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F1F34: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F1F38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F1F3C: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    // 0x801F1F40: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1F44: lwc1        $f18, -0x318C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X318C);
    // 0x801F1F48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1F4C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F1F50: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F1F54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F1F58: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
    // 0x801F1F5C: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1F60: lwc1        $f8, -0x3188($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3188);
    // 0x801F1F64: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1F68: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F1F6C: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F1F70: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F1F74: swc1        $f10, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f10.u32l;
    // 0x801F1F78: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1F7C: lwc1        $f18, -0x3184($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3184);
    // 0x801F1F80: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1F84: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801F1F88: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F1F8C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F1F90: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x801F1F94: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801F1F98: lwc1        $f8, -0x3180($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3180);
    // 0x801F1F9C: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801F1FA0: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F1FA4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F1FA8: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
L_801F1FAC:
    // 0x801F1FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F1FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F1FB4: jr          $ra
    // 0x801F1FB8: nop

    return;
    // 0x801F1FB8: nop

;}
RECOMP_FUNC void M25_FUN_801f1fbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F1FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F1FC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F1FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F1FC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F1FCC: lui         $a1, 0x1DA
    ctx->r5 = S32(0X1DA << 16);
    // 0x801F1FD0: ori         $a1, $a1, 0x8C5F
    ctx->r5 = ctx->r5 | 0X8C5F;
    // 0x801F1FD4: jal         0x801C0B8C
    // 0x801F1FD8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F1FD8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F1FDC: beq         $v0, $zero, L_801F201C
    if (ctx->r2 == 0) {
        // 0x801F1FE0: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F201C;
    }
    // 0x801F1FE0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F1FE4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1FE8: lwc1        $f12, -0x317C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X317C);
    // 0x801F1FEC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F1FF0: lwc1        $f14, -0x3178($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3178);
    // 0x801F1FF4: jal         0x8038BD50
    // 0x801F1FF8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F1FF8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_1:
    // 0x801F1FFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2000: lwc1        $f12, -0x3174($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3174);
    // 0x801F2004: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2008: lwc1        $f14, -0x3170($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3170);
    // 0x801F200C: jal         0x8038BD88
    // 0x801F2010: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F2010: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x801F2014: b           L_801F20CC
    // 0x801F2018: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F20CC;
    // 0x801F2018: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F201C:
    // 0x801F201C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F2020: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2024: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2028: lwc1        $f6, -0x316C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X316C);
    // 0x801F202C: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2030: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2034: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801F2038: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F203C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2040: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F2044: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2048: lwc1        $f16, -0x3168($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3168);
    // 0x801F204C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2050: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F2054: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F2058: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F205C: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F2060: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2064: lwc1        $f6, -0x3164($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3164);
    // 0x801F2068: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F206C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2070: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F2074: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2078: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801F207C: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2080: lwc1        $f16, -0x3160($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3160);
    // 0x801F2084: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2088: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F208C: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F2090: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F2094: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801F2098: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F209C: lwc1        $f6, -0x315C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X315C);
    // 0x801F20A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F20A4: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801F20A8: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F20AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F20B0: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x801F20B4: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801F20B8: lwc1        $f16, -0x3158($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3158);
    // 0x801F20BC: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801F20C0: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F20C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F20C8: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
L_801F20CC:
    // 0x801F20CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F20D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F20D4: jr          $ra
    // 0x801F20D8: nop

    return;
    // 0x801F20D8: nop

;}
RECOMP_FUNC void M25_FUN_801f20dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F20DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F20E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F20E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F20E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F20EC: lui         $a1, 0x208
    ctx->r5 = S32(0X208 << 16);
    // 0x801F20F0: ori         $a1, $a1, 0x531F
    ctx->r5 = ctx->r5 | 0X531F;
    // 0x801F20F4: jal         0x801C0B8C
    // 0x801F20F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F20F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F20FC: beq         $v0, $zero, L_801F2144
    if (ctx->r2 == 0) {
        // 0x801F2100: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F2144;
    }
    // 0x801F2100: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F2104: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2108: lwc1        $f12, -0x3154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3154);
    // 0x801F210C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2110: lui         $a2, 0x41EC
    ctx->r6 = S32(0X41EC << 16);
    // 0x801F2114: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801F2118: jal         0x8038BD50
    // 0x801F211C: lwc1        $f14, -0x3150($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3150);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F211C: lwc1        $f14, -0x3150($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3150);
    after_1:
    // 0x801F2120: lui         $at, 0x422A
    ctx->r1 = S32(0X422A << 16);
    // 0x801F2124: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F2128: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F212C: lui         $a2, 0xC1C2
    ctx->r6 = S32(0XC1C2 << 16);
    // 0x801F2130: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801F2134: jal         0x8038BD88
    // 0x801F2138: lwc1        $f14, -0x314C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X314C);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F2138: lwc1        $f14, -0x314C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X314C);
    after_2:
    // 0x801F213C: b           L_801F21E8
    // 0x801F2140: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801F21E8;
    // 0x801F2140: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F2144:
    // 0x801F2144: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F2148: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F214C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2150: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801F2154: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2158: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F215C: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x801F2160: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2164: lwc1        $f8, -0x3148($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3148);
    // 0x801F2168: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F216C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F2170: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F2174: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F2178: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    // 0x801F217C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2180: lwc1        $f18, -0x3144($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3144);
    // 0x801F2184: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2188: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F218C: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F2190: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F2194: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
    // 0x801F2198: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801F219C: lwc1        $f8, -0x3140($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3140);
    // 0x801F21A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F21A4: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F21A8: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F21AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F21B0: swc1        $f10, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f10.u32l;
    // 0x801F21B4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F21B8: lwc1        $f18, -0x313C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X313C);
    // 0x801F21BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F21C0: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801F21C4: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F21C8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F21CC: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x801F21D0: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801F21D4: lwc1        $f8, -0x3138($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3138);
    // 0x801F21D8: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801F21DC: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F21E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F21E4: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
L_801F21E8:
    // 0x801F21E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F21EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F21F0: jr          $ra
    // 0x801F21F4: nop

    return;
    // 0x801F21F4: nop

;}
RECOMP_FUNC void M25_FUN_801f21f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F21F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F21FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F2200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F2204: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F2208: lui         $a1, 0x282
    ctx->r5 = S32(0X282 << 16);
    // 0x801F220C: ori         $a1, $a1, 0x651F
    ctx->r5 = ctx->r5 | 0X651F;
    // 0x801F2210: jal         0x801C0B8C
    // 0x801F2214: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F2214: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F2218: beq         $v0, $zero, L_801F2398
    if (ctx->r2 == 0) {
        // 0x801F221C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F2398;
    }
    // 0x801F221C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F2220: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2224: lwc1        $f12, -0x3134($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3134);
    // 0x801F2228: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F222C: lwc1        $f14, -0x3130($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3130);
    // 0x801F2230: jal         0x8038BD50
    // 0x801F2234: lui         $a2, 0xC1A4
    ctx->r6 = S32(0XC1A4 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F2234: lui         $a2, 0xC1A4
    ctx->r6 = S32(0XC1A4 << 16);
    after_1:
    // 0x801F2238: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F223C: lwc1        $f12, -0x312C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X312C);
    // 0x801F2240: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2244: lwc1        $f14, -0x3128($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3128);
    // 0x801F2248: jal         0x8038BD88
    // 0x801F224C: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F224C: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    after_2:
    // 0x801F2250: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801F2254: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801F2258: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F225C: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x801F2260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F2264: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F2268: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F226C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F2270: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F2274: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F2278: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F227C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2280: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F2284: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x801F2288: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801F228C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F2290: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F2294: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x801F2298: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F229C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F22A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F22A4: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F22A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F22AC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F22B0: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801F22B4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F22B8: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F22BC: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F22C0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F22C4: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801F22C8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F22CC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F22D0: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F22D4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F22D8: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801F22DC: jal         0x801CC470
    // 0x801F22E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_3;
    // 0x801F22E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x801F22E4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801F22E8: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801F22EC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801F22F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F22F4: lwc1        $f16, -0x3124($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3124);
    // 0x801F22F8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F22FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F2300: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801F2304: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F2308: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F230C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F2310: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F2314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F2318: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F231C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2320: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    // 0x801F2324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F2328: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x801F232C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F2330: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F2334: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F2338: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F233C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F2340: lw          $t8, 0x24($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X24);
    // 0x801F2344: lw          $t2, 0x2C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2348: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x801F234C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801F2350: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F2354: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F2358: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F235C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2360: swc1        $f4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f4.u32l;
    // 0x801F2364: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F2368: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F236C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F2370: lw          $t8, 0x24($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X24);
    // 0x801F2374: lw          $t2, 0x2C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2378: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    // 0x801F237C: jal         0x801CC470
    // 0x801F2380: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_4;
    // 0x801F2380: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801F2384: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2388: jal         0x8038C158
    // 0x801F238C: sw          $zero, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = 0;
    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_5;
    // 0x801F238C: sw          $zero, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = 0;
    after_5:
    // 0x801F2390: b           L_801F2448
    // 0x801F2394: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801F2448;
    // 0x801F2394: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F2398:
    // 0x801F2398: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F239C: lw          $t3, 0xE8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XE8);
    // 0x801F23A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F23A4: lwc1        $f10, -0x3120($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3120);
    // 0x801F23A8: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801F23AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F23B0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801F23B4: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F23B8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F23BC: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    // 0x801F23C0: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F23C4: lwc1        $f4, -0x311C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X311C);
    // 0x801F23C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F23CC: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801F23D0: lwc1        $f18, 0x34($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F23D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F23D8: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x801F23DC: lw          $t5, 0xE8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XE8);
    // 0x801F23E0: lwc1        $f10, -0x3118($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3118);
    // 0x801F23E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F23E8: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x801F23EC: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F23F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F23F4: swc1        $f16, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f16.u32l;
    // 0x801F23F8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F23FC: lwc1        $f4, -0x3114($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3114);
    // 0x801F2400: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2404: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2408: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F240C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F2410: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x801F2414: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2418: lwc1        $f10, -0x3110($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3110);
    // 0x801F241C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2420: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F2424: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F2428: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F242C: swc1        $f16, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f16.u32l;
    // 0x801F2430: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2434: lwc1        $f4, -0x310C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X310C);
    // 0x801F2438: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F243C: lwc1        $f18, 0x44($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F2440: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F2444: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
L_801F2448:
    // 0x801F2448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F244C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F2450: jr          $ra
    // 0x801F2454: nop

    return;
    // 0x801F2454: nop

;}
RECOMP_FUNC void M25_FUN_801f2458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2458: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F245C: lw          $v0, -0x4808($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4808);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f2460(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f2460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2460: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801F2464: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801F2468: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801F246C: beq         $v0, $zero, L_801F2494
    if (ctx->r2 == 0) {
        // 0x801F2470: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_801F2494;
    }
    // 0x801F2470: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801F2474: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F2478: beq         $v0, $at, L_801F255C
    if (ctx->r2 == ctx->r1) {
        // 0x801F247C: lui         $a2, 0x4176
        ctx->r6 = S32(0X4176 << 16);
            goto L_801F255C;
    }
    // 0x801F247C: lui         $a2, 0x4176
    ctx->r6 = S32(0X4176 << 16);
    // 0x801F2480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F2484: beq         $v0, $at, L_801F2608
    if (ctx->r2 == ctx->r1) {
        // 0x801F2488: lui         $a2, 0xC271
        ctx->r6 = S32(0XC271 << 16);
            goto L_801F2608;
    }
    // 0x801F2488: lui         $a2, 0xC271
    ctx->r6 = S32(0XC271 << 16);
    // 0x801F248C: b           L_801F26B0
    // 0x801F2490: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801F26B0;
    // 0x801F2490: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F2494:
    // 0x801F2494: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    // 0x801F2498: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F249C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24A0: lwc1        $f18, -0x3108($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3108);
    // 0x801F24A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24A8: lwc1        $f14, -0x3104($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3104);
    // 0x801F24AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24B0: lwc1        $f4, -0x3100($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3100);
    // 0x801F24B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24B8: lwc1        $f6, -0x30FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X30FC);
    // 0x801F24BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24C0: lwc1        $f8, -0x30F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X30F8);
    // 0x801F24C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24C8: lwc1        $f10, -0x30F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30F4);
    // 0x801F24CC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x801F24D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801F24D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F24D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801F24E0: lwc1        $f6, -0x30F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X30F0);
    // 0x801F24E4: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x801F24E8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801F24EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F24F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F24F4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F24F8: lwc1        $f10, -0x30EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30EC);
    // 0x801F24FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2500: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801F2504: lwc1        $f4, -0x30E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30E8);
    // 0x801F2508: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F250C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801F2510: lwc1        $f6, -0x30E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X30E4);
    // 0x801F2514: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F2518: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801F251C: lui         $a2, 0xC158
    ctx->r6 = S32(0XC158 << 16);
    // 0x801F2520: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801F2524: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801F2528: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801F252C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801F2530: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801F2534: jal         0x8038C17C
    // 0x801F2538: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801F2538: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801F253C: beql        $v0, $zero, L_801F26B0
    if (ctx->r2 == 0) {
        // 0x801F2540: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_801F26B0;
    }
    goto skip_0;
    // 0x801F2540: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    skip_0:
    // 0x801F2544: jal         0x8038C158
    // 0x801F2548: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801F2548: nop

    after_1:
    // 0x801F254C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F2550: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2554: b           L_801F26AC
    // 0x801F2558: sw          $t6, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r14;
        goto L_801F26AC;
    // 0x801F2558: sw          $t6, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r14;
L_801F255C:
    // 0x801F255C: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    // 0x801F2560: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F2564: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2568: lwc1        $f2, -0x30E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X30E0);
    // 0x801F256C: lui         $at, 0x4148
    ctx->r1 = S32(0X4148 << 16);
    // 0x801F2570: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F2574: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2578: lwc1        $f18, -0x30DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X30DC);
    // 0x801F257C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2580: lwc1        $f14, -0x30D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X30D8);
    // 0x801F2584: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2588: lwc1        $f8, -0x30D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X30D4);
    // 0x801F258C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2590: lwc1        $f10, -0x30D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30D0);
    // 0x801F2594: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2598: lwc1        $f4, -0x30CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30CC);
    // 0x801F259C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F25A0: lwc1        $f6, -0x30C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X30C8);
    // 0x801F25A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F25A8: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x801F25AC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x801F25B0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801F25B4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801F25B8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801F25BC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x801F25C0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801F25C4: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x801F25C8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x801F25CC: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801F25D0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x801F25D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F25D8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F25DC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F25E0: jal         0x8038C17C
    // 0x801F25E4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_2;
    // 0x801F25E4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801F25E8: beql        $v0, $zero, L_801F26B0
    if (ctx->r2 == 0) {
        // 0x801F25EC: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_801F26B0;
    }
    goto skip_1;
    // 0x801F25EC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    skip_1:
    // 0x801F25F0: jal         0x8038C158
    // 0x801F25F4: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_3;
    // 0x801F25F4: nop

    after_3:
    // 0x801F25F8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801F25FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2600: b           L_801F26AC
    // 0x801F2604: sw          $t7, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r15;
        goto L_801F26AC;
    // 0x801F2604: sw          $t7, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r15;
L_801F2608:
    // 0x801F2608: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    // 0x801F260C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F2610: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2614: lwc1        $f2, -0x30C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X30C4);
    // 0x801F2618: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F261C: lwc1        $f16, -0x30C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X30C0);
    // 0x801F2620: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2624: lwc1        $f18, -0x30BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X30BC);
    // 0x801F2628: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F262C: lwc1        $f14, -0x30B8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X30B8);
    // 0x801F2630: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2634: lwc1        $f8, -0x30B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X30B4);
    // 0x801F2638: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F263C: lwc1        $f10, -0x30B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30B0);
    // 0x801F2640: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2644: lwc1        $f4, -0x30AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30AC);
    // 0x801F2648: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x801F264C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F2650: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F2654: lui         $a3, 0x4260
    ctx->r7 = S32(0X4260 << 16);
    // 0x801F2658: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801F265C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801F2660: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801F2664: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801F2668: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x801F266C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801F2670: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x801F2674: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x801F2678: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801F267C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x801F2680: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F2684: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F2688: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F268C: jal         0x8038C17C
    // 0x801F2690: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_4;
    // 0x801F2690: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801F2694: beq         $v0, $zero, L_801F26AC
    if (ctx->r2 == 0) {
        // 0x801F2698: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801F26AC;
    }
    // 0x801F2698: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F269C: jal         0x8038C158
    // 0x801F26A0: sw          $zero, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = 0;
    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_5;
    // 0x801F26A0: sw          $zero, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = 0;
    after_5:
    // 0x801F26A4: b           L_801F26B0
    // 0x801F26A8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801F26B0;
    // 0x801F26A8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801F26AC:
    // 0x801F26AC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F26B0:
    // 0x801F26B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801F26B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801F26B8: jr          $ra
    // 0x801F26BC: nop

    return;
    // 0x801F26BC: nop

;}
RECOMP_FUNC void M25_FUN_801f26c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F26C0: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x801F26C4: lw          $t6, -0x4808($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4808);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f26c8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f26c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F26C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801F26CC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801F26D0: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x801F26D4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801F26D8: beq         $at, $zero, L_801F2C48
    if (ctx->r1 == 0) {
        // 0x801F26DC: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_801F2C48;
    }
    // 0x801F26DC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801F26E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801F26E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F26E8: addu        $at, $at, $t6
    gpr jr_addend_801F26F0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801F26EC: lw          $t6, -0x30A8($at)
    ctx->r14 = ADD32(ctx->r1, -0X30A8);
    // 0x801F26F0: jr          $t6
    // 0x801F26F4: nop

    switch (jr_addend_801F26F0 >> 2) {
        case 0: goto L_801F26F8; break;
        case 1: goto L_801F27C0; break;
        case 2: goto L_801F2888; break;
        case 3: goto L_801F2950; break;
        case 4: goto L_801F2A14; break;
        case 5: goto L_801F2AB0; break;
        default: switch_error(__func__, 0x801F26F0, 0x801FCF58);
    }
    // 0x801F26F4: nop

L_801F26F8:
    // 0x801F26F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F26FC: lwc1        $f2, -0x3090($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3090);
    // 0x801F2700: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2704: lwc1        $f14, -0x308C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X308C);
    // 0x801F2708: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F270C: lwc1        $f4, -0x3088($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3088);
    // 0x801F2710: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2714: lwc1        $f6, -0x3084($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3084);
    // 0x801F2718: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F271C: lwc1        $f8, -0x3080($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3080);
    // 0x801F2720: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2724: lwc1        $f10, -0x307C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X307C);
    // 0x801F2728: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F272C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801F2730: lwc1        $f4, -0x3078($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3078);
    // 0x801F2734: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2738: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801F273C: lwc1        $f6, -0x3074($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3074);
    // 0x801F2740: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2744: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801F2748: lwc1        $f8, -0x3070($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3070);
    // 0x801F274C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2750: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801F2754: lwc1        $f10, -0x306C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X306C);
    // 0x801F2758: lui         $at, 0x4158
    ctx->r1 = S32(0X4158 << 16);
    // 0x801F275C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801F2760: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F2764: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2768: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F276C: lwc1        $f6, -0x3068($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3068);
    // 0x801F2770: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F2774: lui         $a2, 0xC256
    ctx->r6 = S32(0XC256 << 16);
    // 0x801F2778: lui         $a3, 0xC141
    ctx->r7 = S32(0XC141 << 16);
    // 0x801F277C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x801F2780: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801F2784: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x801F2788: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x801F278C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801F2790: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x801F2794: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801F2798: jal         0x8038C17C
    // 0x801F279C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801F279C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801F27A0: beql        $v0, $zero, L_801F2C4C
    if (ctx->r2 == 0) {
        // 0x801F27A4: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_801F2C4C;
    }
    goto skip_0;
    // 0x801F27A4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_0:
    // 0x801F27A8: jal         0x8038C158
    // 0x801F27AC: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801F27AC: nop

    after_1:
    // 0x801F27B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F27B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F27B8: b           L_801F2C48
    // 0x801F27BC: sw          $t7, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r15;
        goto L_801F2C48;
    // 0x801F27BC: sw          $t7, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r15;
L_801F27C0:
    // 0x801F27C0: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    // 0x801F27C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F27C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F27CC: lwc1        $f14, -0x3064($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3064);
    // 0x801F27D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F27D4: lwc1        $f8, -0x3060($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3060);
    // 0x801F27D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F27DC: lwc1        $f10, -0x305C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X305C);
    // 0x801F27E0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801F27E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F27E8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F27EC: lwc1        $f6, -0x3058($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3058);
    // 0x801F27F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F27F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F27F8: lwc1        $f8, -0x3054($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3054);
    // 0x801F27FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2800: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F2804: lwc1        $f10, -0x3050($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3050);
    // 0x801F2808: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F280C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F2810: lwc1        $f4, -0x304C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X304C);
    // 0x801F2814: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2818: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801F281C: lwc1        $f6, -0x3048($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3048);
    // 0x801F2820: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x801F2824: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801F2828: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F282C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2830: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801F2834: lwc1        $f10, -0x3044($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3044);
    // 0x801F2838: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F283C: lui         $a2, 0xC124
    ctx->r6 = S32(0XC124 << 16);
    // 0x801F2840: lui         $a3, 0x4209
    ctx->r7 = S32(0X4209 << 16);
    // 0x801F2844: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x801F2848: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801F284C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801F2850: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801F2854: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801F2858: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F285C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801F2860: jal         0x8038C17C
    // 0x801F2864: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_2;
    // 0x801F2864: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801F2868: beql        $v0, $zero, L_801F2C4C
    if (ctx->r2 == 0) {
        // 0x801F286C: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_801F2C4C;
    }
    goto skip_1;
    // 0x801F286C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_1:
    // 0x801F2870: jal         0x8038C158
    // 0x801F2874: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_3;
    // 0x801F2874: nop

    after_3:
    // 0x801F2878: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801F287C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2880: b           L_801F2C48
    // 0x801F2884: sw          $t8, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r24;
        goto L_801F2C48;
    // 0x801F2884: sw          $t8, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r24;
L_801F2888:
    // 0x801F2888: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x801F288C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F2890: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2894: lwc1        $f14, -0x3040($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3040);
    // 0x801F2898: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F289C: lwc1        $f4, -0x303C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X303C);
    // 0x801F28A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F28A4: lwc1        $f6, -0x3038($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3038);
    // 0x801F28A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F28AC: lwc1        $f8, -0x3034($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3034);
    // 0x801F28B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F28B4: lwc1        $f10, -0x3030($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3030);
    // 0x801F28B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F28BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801F28C0: lwc1        $f4, -0x302C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X302C);
    // 0x801F28C4: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x801F28C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801F28CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F28D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F28D4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801F28D8: lwc1        $f8, -0x3028($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3028);
    // 0x801F28DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F28E0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F28E4: lwc1        $f10, -0x3024($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3024);
    // 0x801F28E8: lui         $at, 0x4168
    ctx->r1 = S32(0X4168 << 16);
    // 0x801F28EC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801F28F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F28F4: lui         $at, 0xC168
    ctx->r1 = S32(0XC168 << 16);
    // 0x801F28F8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801F28FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F2900: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F2904: lui         $a2, 0xC0F6
    ctx->r6 = S32(0XC0F6 << 16);
    // 0x801F2908: lui         $a3, 0xC053
    ctx->r7 = S32(0XC053 << 16);
    // 0x801F290C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x801F2910: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801F2914: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801F2918: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801F291C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801F2920: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801F2924: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801F2928: jal         0x8038C17C
    // 0x801F292C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_4;
    // 0x801F292C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801F2930: beql        $v0, $zero, L_801F2C4C
    if (ctx->r2 == 0) {
        // 0x801F2934: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_801F2C4C;
    }
    goto skip_2;
    // 0x801F2934: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_2:
    // 0x801F2938: jal         0x8038C158
    // 0x801F293C: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_5;
    // 0x801F293C: nop

    after_5:
    // 0x801F2940: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801F2944: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2948: b           L_801F2C48
    // 0x801F294C: sw          $t9, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r25;
        goto L_801F2C48;
    // 0x801F294C: sw          $t9, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r25;
L_801F2950:
    // 0x801F2950: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2954: lwc1        $f0, -0x3020($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3020);
    // 0x801F2958: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F295C: lwc1        $f2, -0x301C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X301C);
    // 0x801F2960: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2964: lwc1        $f14, -0x3018($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3018);
    // 0x801F2968: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F296C: lwc1        $f8, -0x3014($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3014);
    // 0x801F2970: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2974: lwc1        $f10, -0x3010($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3010);
    // 0x801F2978: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F297C: lwc1        $f4, -0x300C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X300C);
    // 0x801F2980: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x801F2984: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F2988: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F298C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F2990: lwc1        $f8, -0x3008($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3008);
    // 0x801F2994: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x801F2998: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F299C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F29A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F29A4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F29A8: lwc1        $f4, -0x3004($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3004);
    // 0x801F29AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F29B0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801F29B4: lwc1        $f6, -0x3000($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3000);
    // 0x801F29B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F29BC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x801F29C0: lwc1        $f8, -0x2FFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2FFC);
    // 0x801F29C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F29C8: lui         $a2, 0x412B
    ctx->r6 = S32(0X412B << 16);
    // 0x801F29CC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801F29D0: lui         $a3, 0x41FC
    ctx->r7 = S32(0X41FC << 16);
    // 0x801F29D4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801F29D8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801F29DC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x801F29E0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801F29E4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801F29E8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801F29EC: jal         0x8038C17C
    // 0x801F29F0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_6;
    // 0x801F29F0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x801F29F4: beql        $v0, $zero, L_801F2C4C
    if (ctx->r2 == 0) {
        // 0x801F29F8: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_801F2C4C;
    }
    goto skip_3;
    // 0x801F29F8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_3:
    // 0x801F29FC: jal         0x8038C158
    // 0x801F2A00: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_7;
    // 0x801F2A00: nop

    after_7:
    // 0x801F2A04: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801F2A08: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2A0C: b           L_801F2C48
    // 0x801F2A10: sw          $t0, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r8;
        goto L_801F2C48;
    // 0x801F2A10: sw          $t0, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r8;
L_801F2A14:
    // 0x801F2A14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2A18: lwc1        $f0, -0x2FF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FF8);
    // 0x801F2A1C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2A20: lwc1        $f2, -0x2FF4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FF4);
    // 0x801F2A24: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2A28: lwc1        $f16, -0x2FF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2FF0);
    // 0x801F2A2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2A30: lwc1        $f18, -0x2FEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2FEC);
    // 0x801F2A34: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2A38: lwc1        $f14, -0x2FE8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FE8);
    // 0x801F2A3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2A40: lwc1        $f10, -0x2FE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2FE4);
    // 0x801F2A44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F2A48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F2A4C: lui         $at, 0x41F4
    ctx->r1 = S32(0X41F4 << 16);
    // 0x801F2A50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F2A54: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x801F2A58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F2A5C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F2A60: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x801F2A64: lui         $a3, 0x42CF
    ctx->r7 = S32(0X42CF << 16);
    // 0x801F2A68: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801F2A6C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801F2A70: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801F2A74: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x801F2A78: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801F2A7C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x801F2A80: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x801F2A84: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x801F2A88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801F2A8C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801F2A90: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801F2A94: jal         0x8038C17C
    // 0x801F2A98: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_8;
    // 0x801F2A98: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x801F2A9C: beq         $v0, $zero, L_801F2C48
    if (ctx->r2 == 0) {
        // 0x801F2AA0: addiu       $t1, $zero, 0x5
        ctx->r9 = ADD32(0, 0X5);
            goto L_801F2C48;
    }
    // 0x801F2AA0: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801F2AA4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2AA8: b           L_801F2C48
    // 0x801F2AAC: sw          $t1, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r9;
        goto L_801F2C48;
    // 0x801F2AAC: sw          $t1, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = ctx->r9;
L_801F2AB0:
    // 0x801F2AB0: lui         $a1, 0x367
    ctx->r5 = S32(0X367 << 16);
    // 0x801F2AB4: ori         $a1, $a1, 0x46DF
    ctx->r5 = ctx->r5 | 0X46DF;
    // 0x801F2AB8: jal         0x801C0B8C
    // 0x801F2ABC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_9;
    // 0x801F2ABC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_9:
    // 0x801F2AC0: beq         $v0, $zero, L_801F2C48
    if (ctx->r2 == 0) {
        // 0x801F2AC4: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801F2C48;
    }
    // 0x801F2AC4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2AC8: jal         0x8038BE98
    // 0x801F2ACC: lwc1        $f12, -0x2FE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2FE0);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_10;
    // 0x801F2ACC: lwc1        $f12, -0x2FE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2FE0);
    after_10:
    // 0x801F2AD0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2AD4: lwc1        $f12, -0x2FDC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2FDC);
    // 0x801F2AD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2ADC: lui         $a2, 0xC0B6
    ctx->r6 = S32(0XC0B6 << 16);
    // 0x801F2AE0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801F2AE4: jal         0x8038BD50
    // 0x801F2AE8: lwc1        $f14, -0x2FD8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FD8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_11;
    // 0x801F2AE8: lwc1        $f14, -0x2FD8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FD8);
    after_11:
    // 0x801F2AEC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2AF0: lwc1        $f12, -0x2FD4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2FD4);
    // 0x801F2AF4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2AF8: lui         $a2, 0x40D9
    ctx->r6 = S32(0X40D9 << 16);
    // 0x801F2AFC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801F2B00: jal         0x8038BD88
    // 0x801F2B04: lwc1        $f14, -0x2FD0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FD0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_12;
    // 0x801F2B04: lwc1        $f14, -0x2FD0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FD0);
    after_12:
    // 0x801F2B08: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801F2B0C: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801F2B10: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F2B14: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801F2B18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F2B1C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F2B20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F2B24: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2B28: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F2B2C: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F2B30: ori         $a1, $a1, 0x18
    ctx->r5 = ctx->r5 | 0X18;
    // 0x801F2B34: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F2B38: addiu       $t4, $zero, 0x999
    ctx->r12 = ADD32(0, 0X999);
    // 0x801F2B3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F2B40: swc1        $f10, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f10.u32l;
    // 0x801F2B44: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F2B48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F2B4C: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801F2B50: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F2B54: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F2B58: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2B5C: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x801F2B60: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F2B64: lwc1        $f6, -0x2FCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2FCC);
    // 0x801F2B68: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F2B6C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F2B70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F2B74: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F2B78: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F2B7C: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x801F2B80: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F2B84: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F2B88: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F2B8C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F2B90: sh          $t4, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r12;
    // 0x801F2B94: jal         0x801CC470
    // 0x801F2B98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_13;
    // 0x801F2B98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x801F2B9C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801F2BA0: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801F2BA4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F2BA8: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F2BAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F2BB0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F2BB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F2BB8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2BBC: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F2BC0: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F2BC4: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x801F2BC8: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F2BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F2BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F2BD4: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F2BD8: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801F2BDC: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x801F2BE0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F2BE4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F2BE8: addiu       $t5, $zero, 0x1800
    ctx->r13 = ADD32(0, 0X1800);
    // 0x801F2BEC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F2BF0: lw          $t4, 0x24($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X24);
    // 0x801F2BF4: lw          $t8, 0x2C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X2C);
    // 0x801F2BF8: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x801F2BFC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F2C00: lwc1        $f6, -0x2FC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2FC8);
    // 0x801F2C04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F2C08: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F2C0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F2C10: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F2C14: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F2C18: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F2C1C: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x801F2C20: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F2C24: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F2C28: lw          $t4, 0x8($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X8);
    // 0x801F2C2C: lw          $t8, 0x24($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X24);
    // 0x801F2C30: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2C34: sh          $t5, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r13;
    // 0x801F2C38: jal         0x801CC470
    // 0x801F2C3C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_14;
    // 0x801F2C3C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x801F2C40: b           L_801F2C4C
    // 0x801F2C44: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801F2C4C;
    // 0x801F2C44: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801F2C48:
    // 0x801F2C48: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801F2C4C:
    // 0x801F2C4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801F2C50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801F2C54: jr          $ra
    // 0x801F2C58: nop

    return;
    // 0x801F2C58: nop

;}
RECOMP_FUNC void M25_FUN_801f2c5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F2C60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F2C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F2C68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F2C6C: lui         $a1, 0x3CA
    ctx->r5 = S32(0X3CA << 16);
    // 0x801F2C70: ori         $a1, $a1, 0x757F
    ctx->r5 = ctx->r5 | 0X757F;
    // 0x801F2C74: jal         0x801C0B8C
    // 0x801F2C78: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F2C78: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F2C7C: beq         $v0, $zero, L_801F2CC0
    if (ctx->r2 == 0) {
        // 0x801F2C80: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F2CC0;
    }
    // 0x801F2C80: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F2C84: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2C88: lwc1        $f12, -0x2FC4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2FC4);
    // 0x801F2C8C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2C90: lwc1        $f14, -0x2FC0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FC0);
    // 0x801F2C94: jal         0x8038BD50
    // 0x801F2C98: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F2C98: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_1:
    // 0x801F2C9C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x801F2CA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F2CA4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2CA8: lui         $a2, 0x4006
    ctx->r6 = S32(0X4006 << 16);
    // 0x801F2CAC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801F2CB0: jal         0x8038BD88
    // 0x801F2CB4: lwc1        $f14, -0x2FBC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FBC);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F2CB4: lwc1        $f14, -0x2FBC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FBC);
    after_2:
    // 0x801F2CB8: b           L_801F2D58
    // 0x801F2CBC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_801F2D58;
    // 0x801F2CBC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801F2CC0:
    // 0x801F2CC0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F2CC4: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2CC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2CCC: lwc1        $f6, -0x2FB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2FB8);
    // 0x801F2CD0: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2CD4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2CD8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x801F2CDC: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F2CE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2CE4: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F2CE8: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2CEC: lwc1        $f16, -0x2FB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2FB4);
    // 0x801F2CF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2CF4: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F2CF8: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F2CFC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F2D00: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F2D04: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2D08: lwc1        $f6, -0x2FB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2FB0);
    // 0x801F2D0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2D10: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2D14: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F2D18: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2D1C: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801F2D20: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2D24: lwc1        $f16, -0x2FAC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2FAC);
    // 0x801F2D28: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F2D2C: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F2D30: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F2D34: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801F2D38: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2D3C: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801F2D40: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F2D44: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x801F2D48: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2D4C: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801F2D50: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F2D54: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
L_801F2D58:
    // 0x801F2D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F2D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F2D60: jr          $ra
    // 0x801F2D64: nop

    return;
    // 0x801F2D64: nop

;}
RECOMP_FUNC void M25_FUN_801f2d68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F2D6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F2D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F2D74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F2D78: lui         $a1, 0x40F
    ctx->r5 = S32(0X40F << 16);
    // 0x801F2D7C: ori         $a1, $a1, 0x1FA0
    ctx->r5 = ctx->r5 | 0X1FA0;
    // 0x801F2D80: jal         0x801C0B8C
    // 0x801F2D84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F2D84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F2D88: beq         $v0, $zero, L_801F2DD0
    if (ctx->r2 == 0) {
        // 0x801F2D8C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F2DD0;
    }
    // 0x801F2D8C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F2D90: lui         $at, 0xC210
    ctx->r1 = S32(0XC210 << 16);
    // 0x801F2D94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F2D98: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2D9C: lui         $a2, 0x4241
    ctx->r6 = S32(0X4241 << 16);
    // 0x801F2DA0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801F2DA4: jal         0x8038BD50
    // 0x801F2DA8: lwc1        $f14, -0x2FA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FA8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F2DA8: lwc1        $f14, -0x2FA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FA8);
    after_1:
    // 0x801F2DAC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2DB0: lwc1        $f12, -0x2FA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2FA4);
    // 0x801F2DB4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2DB8: lui         $a2, 0x40F3
    ctx->r6 = S32(0X40F3 << 16);
    // 0x801F2DBC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801F2DC0: jal         0x8038BD88
    // 0x801F2DC4: lwc1        $f14, -0x2FA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FA0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F2DC4: lwc1        $f14, -0x2FA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2FA0);
    after_2:
    // 0x801F2DC8: b           L_801F2E2C
    // 0x801F2DCC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_801F2E2C;
    // 0x801F2DCC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801F2DD0:
    // 0x801F2DD0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F2DD4: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2DD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2DDC: lwc1        $f6, -0x2F9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F9C);
    // 0x801F2DE0: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2DE4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2DE8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x801F2DEC: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F2DF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2DF4: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F2DF8: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2DFC: lwc1        $f16, -0x2F98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F98);
    // 0x801F2E00: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2E04: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F2E08: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F2E0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F2E10: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F2E14: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2E18: lwc1        $f6, -0x2F94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F94);
    // 0x801F2E1C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2E20: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F2E24: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2E28: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_801F2E2C:
    // 0x801F2E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F2E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F2E34: jr          $ra
    // 0x801F2E38: nop

    return;
    // 0x801F2E38: nop

;}
RECOMP_FUNC void M25_FUN_801f2e3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2E3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F2E40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F2E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F2E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F2E4C: lui         $a1, 0x422
    ctx->r5 = S32(0X422 << 16);
    // 0x801F2E50: ori         $a1, $a1, 0x738A
    ctx->r5 = ctx->r5 | 0X738A;
    // 0x801F2E54: jal         0x801C0B8C
    // 0x801F2E58: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F2E58: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F2E5C: beq         $v0, $zero, L_801F2EA4
    if (ctx->r2 == 0) {
        // 0x801F2E60: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F2EA4;
    }
    // 0x801F2E60: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F2E64: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2E68: lwc1        $f12, -0x2F90($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F90);
    // 0x801F2E6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2E70: lui         $a2, 0xC156
    ctx->r6 = S32(0XC156 << 16);
    // 0x801F2E74: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801F2E78: jal         0x8038BD50
    // 0x801F2E7C: lwc1        $f14, -0x2F8C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F8C);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F2E7C: lwc1        $f14, -0x2F8C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F8C);
    after_1:
    // 0x801F2E80: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2E84: lwc1        $f12, -0x2F88($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F88);
    // 0x801F2E88: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2E8C: lui         $a2, 0x40F9
    ctx->r6 = S32(0X40F9 << 16);
    // 0x801F2E90: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801F2E94: jal         0x8038BD88
    // 0x801F2E98: lwc1        $f14, -0x2F84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F84);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F2E98: lwc1        $f14, -0x2F84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F84);
    after_2:
    // 0x801F2E9C: b           L_801F2F54
    // 0x801F2EA0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801F2F54;
    // 0x801F2EA0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801F2EA4:
    // 0x801F2EA4: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F2EA8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2EAC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2EB0: lwc1        $f6, -0x2F80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F80);
    // 0x801F2EB4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2EB8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2EBC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x801F2EC0: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F2EC4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2EC8: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F2ECC: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2ED0: lwc1        $f16, -0x2F7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F7C);
    // 0x801F2ED4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2ED8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F2EDC: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F2EE0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F2EE4: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F2EE8: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2EEC: lwc1        $f6, -0x2F78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F78);
    // 0x801F2EF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2EF4: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F2EF8: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F2EFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2F00: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801F2F04: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2F08: lwc1        $f16, -0x2F74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F74);
    // 0x801F2F0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2F10: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F2F14: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F2F18: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F2F1C: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801F2F20: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2F24: lwc1        $f6, -0x2F70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F70);
    // 0x801F2F28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2F2C: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801F2F30: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F2F34: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2F38: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x801F2F3C: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2F40: lwc1        $f16, -0x2F6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F6C);
    // 0x801F2F44: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801F2F48: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F2F4C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F2F50: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
L_801F2F54:
    // 0x801F2F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F2F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F2F5C: jr          $ra
    // 0x801F2F60: nop

    return;
    // 0x801F2F60: nop

;}
RECOMP_FUNC void M25_FUN_801f2f64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F2F68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F2F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F2F70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F2F74: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801F2F78: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    // 0x801F2F7C: jal         0x801C0B8C
    // 0x801F2F80: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F2F80: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F2F84: beq         $v0, $zero, L_801F2FC8
    if (ctx->r2 == 0) {
        // 0x801F2F88: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F2FC8;
    }
    // 0x801F2F88: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F2F8C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2F90: lwc1        $f12, -0x2F68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F68);
    // 0x801F2F94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2F98: lwc1        $f14, -0x2F64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F64);
    // 0x801F2F9C: jal         0x8038BD50
    // 0x801F2FA0: lui         $a2, 0x4258
    ctx->r6 = S32(0X4258 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801F2FA0: lui         $a2, 0x4258
    ctx->r6 = S32(0X4258 << 16);
    after_1:
    // 0x801F2FA4: lui         $at, 0x41AC
    ctx->r1 = S32(0X41AC << 16);
    // 0x801F2FA8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F2FAC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2FB0: lui         $a2, 0xC186
    ctx->r6 = S32(0XC186 << 16);
    // 0x801F2FB4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801F2FB8: jal         0x8038BD88
    // 0x801F2FBC: lwc1        $f14, -0x2F60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F60);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801F2FBC: lwc1        $f14, -0x2F60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F60);
    after_2:
    // 0x801F2FC0: b           L_801F3024
    // 0x801F2FC4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_801F3024;
    // 0x801F2FC4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801F2FC8:
    // 0x801F2FC8: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F2FCC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2FD0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2FD4: lwc1        $f6, -0x2F5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F5C);
    // 0x801F2FD8: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F2FDC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2FE0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x801F2FE4: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F2FE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F2FEC: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F2FF0: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F2FF4: lwc1        $f16, -0x2F58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F58);
    // 0x801F2FF8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F2FFC: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F3000: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F3004: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F3008: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F300C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3010: lwc1        $f6, -0x2F54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F54);
    // 0x801F3014: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F3018: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F301C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F3020: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_801F3024:
    // 0x801F3024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F302C: jr          $ra
    // 0x801F3030: nop

    return;
    // 0x801F3030: nop

;}
RECOMP_FUNC void M25_FUN_801f3034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3038: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F303C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F3044: lui         $a1, 0x452
    ctx->r5 = S32(0X452 << 16);
    // 0x801F3048: ori         $a1, $a1, 0xC555
    ctx->r5 = ctx->r5 | 0XC555;
    // 0x801F304C: jal         0x801C0B8C
    // 0x801F3050: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F3050: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F3054: beq         $v0, $zero, L_801F315C
    if (ctx->r2 == 0) {
        // 0x801F3058: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F315C;
    }
    // 0x801F3058: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F305C: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F3060: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    // 0x801F3064: jal         0x801C0B8C
    // 0x801F3068: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F3068: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_1:
    // 0x801F306C: beq         $v0, $zero, L_801F30A8
    if (ctx->r2 == 0) {
        // 0x801F3070: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F30A8;
    }
    // 0x801F3070: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F3074: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3078: lwc1        $f12, -0x2F50($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F50);
    // 0x801F307C: lui         $at, 0x446D
    ctx->r1 = S32(0X446D << 16);
    // 0x801F3080: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F3084: jal         0x8038BD50
    // 0x801F3088: lui         $a2, 0x41BC
    ctx->r6 = S32(0X41BC << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_2;
    // 0x801F3088: lui         $a2, 0x41BC
    ctx->r6 = S32(0X41BC << 16);
    after_2:
    // 0x801F308C: lui         $at, 0xC178
    ctx->r1 = S32(0XC178 << 16);
    // 0x801F3090: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F3094: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801F3098: jal         0x8038BD88
    // 0x801F309C: lui         $a2, 0x4178
    ctx->r6 = S32(0X4178 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_3;
    // 0x801F309C: lui         $a2, 0x4178
    ctx->r6 = S32(0X4178 << 16);
    after_3:
    // 0x801F30A0: b           L_801F320C
    // 0x801F30A4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_801F320C;
    // 0x801F30A4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801F30A8:
    // 0x801F30A8: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F30AC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F30B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F30B4: lwc1        $f6, -0x2F4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F4C);
    // 0x801F30B8: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F30BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F30C0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x801F30C4: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F30C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F30CC: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F30D0: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F30D4: lwc1        $f16, -0x2F48($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F48);
    // 0x801F30D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F30DC: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F30E0: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F30E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F30E8: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F30EC: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F30F0: lwc1        $f6, -0x2F44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F44);
    // 0x801F30F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F30F8: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F30FC: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F3100: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F3104: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801F3108: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801F310C: lwc1        $f16, -0x2F40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F40);
    // 0x801F3110: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3114: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F3118: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F311C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F3120: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801F3124: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3128: lwc1        $f6, -0x2F3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F3C);
    // 0x801F312C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3130: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801F3134: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F3138: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F313C: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x801F3140: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3144: lwc1        $f16, -0x2F38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F38);
    // 0x801F3148: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801F314C: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F3150: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F3154: b           L_801F320C
    // 0x801F3158: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
        goto L_801F320C;
    // 0x801F3158: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
L_801F315C:
    // 0x801F315C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F3160: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3164: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3168: lwc1        $f6, -0x2F34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F34);
    // 0x801F316C: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801F3170: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3174: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x801F3178: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F317C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F3180: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F3184: lw          $t3, 0xE8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3188: lwc1        $f16, -0x2F30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F30);
    // 0x801F318C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3190: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801F3194: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F3198: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F319C: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F31A0: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F31A4: lwc1        $f6, -0x2F2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F2C);
    // 0x801F31A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F31AC: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801F31B0: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F31B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F31B8: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801F31BC: lw          $t5, 0xE8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XE8);
    // 0x801F31C0: lwc1        $f16, -0x2F28($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F28);
    // 0x801F31C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F31C8: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x801F31CC: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801F31D0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F31D4: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801F31D8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F31DC: lwc1        $f6, -0x2F24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x801F31E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F31E4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F31E8: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801F31EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F31F0: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x801F31F4: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F31F8: lwc1        $f16, -0x2F20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F20);
    // 0x801F31FC: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F3200: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801F3204: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F3208: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
L_801F320C:
    // 0x801F320C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F3214: jr          $ra
    // 0x801F3218: nop

    return;
    // 0x801F3218: nop

;}
RECOMP_FUNC void M25_FUN_801f321c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F321C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3220: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F3224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F322C: lui         $a1, 0x49F
    ctx->r5 = S32(0X49F << 16);
    // 0x801F3230: ori         $a1, $a1, 0x1095
    ctx->r5 = ctx->r5 | 0X1095;
    // 0x801F3234: jal         0x801C0B8C
    // 0x801F3238: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F3238: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F323C: beq         $v0, $zero, L_801F324C
    if (ctx->r2 == 0) {
        // 0x801F3240: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801F324C;
    }
    // 0x801F3240: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F3244: b           L_801F32A8
    // 0x801F3248: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_801F32A8;
    // 0x801F3248: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801F324C:
    // 0x801F324C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F3250: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3254: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3258: lwc1        $f6, -0x2F1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F1C);
    // 0x801F325C: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3260: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3264: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x801F3268: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F326C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F3270: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801F3274: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3278: lwc1        $f16, -0x2F18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2F18);
    // 0x801F327C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3280: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F3284: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F3288: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F328C: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801F3290: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3294: lwc1        $f6, -0x2F14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F14);
    // 0x801F3298: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F329C: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801F32A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F32A4: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_801F32A8:
    // 0x801F32A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F32AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F32B0: jr          $ra
    // 0x801F32B4: nop

    return;
    // 0x801F32B4: nop

;}
RECOMP_FUNC void M25_FUN_801f32b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F32B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F32BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F32C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F32C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F32C8: lui         $a1, 0x4E5
    ctx->r5 = S32(0X4E5 << 16);
    // 0x801F32CC: ori         $a1, $a1, 0x4155
    ctx->r5 = ctx->r5 | 0X4155;
    // 0x801F32D0: jal         0x801C0B8C
    // 0x801F32D4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F32D4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F32D8: beq         $v0, $zero, L_801F32E8
    if (ctx->r2 == 0) {
        // 0x801F32DC: nop
    
            goto L_801F32E8;
    }
    // 0x801F32DC: nop

    // 0x801F32E0: b           L_801F3410
    // 0x801F32E4: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_801F3410;
    // 0x801F32E4: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801F32E8:
    // 0x801F32E8: jal         0x801C0B2C
    // 0x801F32EC: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F32EC: nop

    after_1:
    // 0x801F32F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F32F4: jal         0x80034C24
    // 0x801F32F8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F32F8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F32FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3300: ldc1        $f4, -0x2F10($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2F10);
    // 0x801F3304: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3308: ldc1        $f8, -0x2F08($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2F08);
    // 0x801F330C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F3310: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3314: ldc1        $f4, -0x2F00($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2F00);
    // 0x801F3318: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F331C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F3320: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F3324: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3328: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x801F332C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3330: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F3334: ldc1        $f6, -0x2EF8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2EF8);
    // 0x801F3338: lui         $at, 0xC03F
    ctx->r1 = S32(0XC03F << 16);
    // 0x801F333C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F3340: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F3344: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F3348: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F334C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F3350: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F3354: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F3358: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F335C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F3360: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F3364: ldc1        $f4, -0x2EF0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EF0);
    // 0x801F3368: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F336C: ldc1        $f8, -0x2EE8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2EE8);
    // 0x801F3370: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F3374: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3378: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F337C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F3380: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F3384: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F3388: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F338C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x801F3390: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F3394: ldc1        $f18, -0x2EE0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2EE0);
    // 0x801F3398: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F339C: ldc1        $f6, -0x2ED8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2ED8);
    // 0x801F33A0: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F33A4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F33A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F33AC: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F33B0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F33B4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F33B8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801F33BC: swc1        $f12, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f12.u32l;
    // 0x801F33C0: ldc1        $f18, -0x2ED0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2ED0);
    // 0x801F33C4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F33C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F33CC: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F33D0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F33D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F33D8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F33DC: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801F33E0: ldc1        $f8, -0x2EC8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2EC8);
    // 0x801F33E4: lui         $at, 0x4033
    ctx->r1 = S32(0X4033 << 16);
    // 0x801F33E8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F33EC: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F33F0: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F33F4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F33F8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F33FC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F3400: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x801F3404: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3408: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F340C: swc1        $f12, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f12.u32l;
L_801F3410:
    // 0x801F3410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F3418: jr          $ra
    // 0x801F341C: nop

    return;
    // 0x801F341C: nop

;}
RECOMP_FUNC void M25_FUN_801f3420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3424: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F3428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F342C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F3430: lui         $a1, 0x539
    ctx->r5 = S32(0X539 << 16);
    // 0x801F3434: ori         $a1, $a1, 0x2DB5
    ctx->r5 = ctx->r5 | 0X2DB5;
    // 0x801F3438: jal         0x801C0B8C
    // 0x801F343C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F343C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F3440: beq         $v0, $zero, L_801F3450
    if (ctx->r2 == 0) {
        // 0x801F3444: nop
    
            goto L_801F3450;
    }
    // 0x801F3444: nop

    // 0x801F3448: b           L_801F3598
    // 0x801F344C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_801F3598;
    // 0x801F344C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_801F3450:
    // 0x801F3450: jal         0x801C0B2C
    // 0x801F3454: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F3454: nop

    after_1:
    // 0x801F3458: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F345C: jal         0x80034C24
    // 0x801F3460: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F3460: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F3464: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3468: ldc1        $f4, -0x2EC0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EC0);
    // 0x801F346C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3470: ldc1        $f8, -0x2EB8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2EB8);
    // 0x801F3474: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F3478: lui         $at, 0x4016
    ctx->r1 = S32(0X4016 << 16);
    // 0x801F347C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F3480: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F3484: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3488: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F348C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F3490: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3494: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x801F3498: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F349C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F34A0: ldc1        $f6, -0x2EB0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2EB0);
    // 0x801F34A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F34A8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F34AC: ldc1        $f10, -0x2EA8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2EA8);
    // 0x801F34B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F34B4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F34B8: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F34BC: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F34C0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F34C4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F34C8: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F34CC: ldc1        $f4, -0x2EA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EA0);
    // 0x801F34D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F34D4: ldc1        $f8, -0x2E98($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E98);
    // 0x801F34D8: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F34DC: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F34E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F34E4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F34E8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F34EC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F34F0: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F34F4: ldc1        $f18, -0x2E90($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2E90);
    // 0x801F34F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F34FC: ldc1        $f6, -0x2E88($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2E88);
    // 0x801F3500: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F3504: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x801F3508: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F350C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F3510: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3514: lui         $at, 0xC02D
    ctx->r1 = S32(0XC02D << 16);
    // 0x801F3518: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F351C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F3520: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F3524: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F3528: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F352C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3530: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F3534: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F3538: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F353C: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3540: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F3544: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F3548: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F354C: ldc1        $f10, -0x2E80($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2E80);
    // 0x801F3550: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3554: ldc1        $f18, -0x2E78($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2E78);
    // 0x801F3558: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F355C: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3560: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3564: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F3568: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F356C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F3570: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F3574: ldc1        $f8, -0x2E70($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E70);
    // 0x801F3578: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F357C: ldc1        $f16, -0x2E68($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2E68);
    // 0x801F3580: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F3584: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3588: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F358C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F3590: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F3594: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801F3598:
    // 0x801F3598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F359C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F35A0: jr          $ra
    // 0x801F35A4: nop

    return;
    // 0x801F35A4: nop

;}
RECOMP_FUNC void M25_FUN_801f35a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F35A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F35AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F35B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F35B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F35B8: lui         $a1, 0x5F0
    ctx->r5 = S32(0X5F0 << 16);
    // 0x801F35BC: ori         $a1, $a1, 0x48B5
    ctx->r5 = ctx->r5 | 0X48B5;
    // 0x801F35C0: jal         0x801C0B8C
    // 0x801F35C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F35C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F35C8: beq         $v0, $zero, L_801F35D8
    if (ctx->r2 == 0) {
        // 0x801F35CC: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F35D8;
    }
    // 0x801F35CC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F35D0: b           L_801F38B4
    // 0x801F35D4: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_801F38B4;
    // 0x801F35D4: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_801F35D8:
    // 0x801F35D8: lui         $a1, 0x594
    ctx->r5 = S32(0X594 << 16);
    // 0x801F35DC: jal         0x801C0B8C
    // 0x801F35E0: ori         $a1, $a1, 0xBB35
    ctx->r5 = ctx->r5 | 0XBB35;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F35E0: ori         $a1, $a1, 0xBB35
    ctx->r5 = ctx->r5 | 0XBB35;
    after_1:
    // 0x801F35E4: beq         $v0, $zero, L_801F3744
    if (ctx->r2 == 0) {
        // 0x801F35E8: nop
    
            goto L_801F3744;
    }
    // 0x801F35E8: nop

    // 0x801F35EC: jal         0x801C0B2C
    // 0x801F35F0: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801F35F0: nop

    after_2:
    // 0x801F35F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F35F8: jal         0x80034C24
    // 0x801F35FC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801F35FC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801F3600: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3604: ldc1        $f4, -0x2E60($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2E60);
    // 0x801F3608: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F360C: ldc1        $f8, -0x2E58($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E58);
    // 0x801F3610: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F3614: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801F3618: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F361C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F3620: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3624: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801F3628: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801F362C: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x801F3630: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3634: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F3638: ldc1        $f6, -0x2E50($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2E50);
    // 0x801F363C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3640: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F3644: ldc1        $f10, -0x2E48($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2E48);
    // 0x801F3648: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F364C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F3650: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F3654: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F3658: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F365C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F3660: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801F3664: ldc1        $f4, -0x2E40($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2E40);
    // 0x801F3668: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F366C: ldc1        $f8, -0x2E38($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E38);
    // 0x801F3670: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F3674: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x801F3678: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F367C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F3680: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F3684: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F3688: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801F368C: ldc1        $f18, -0x2E30($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2E30);
    // 0x801F3690: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3694: ldc1        $f6, -0x2E28($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2E28);
    // 0x801F3698: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F369C: lw          $t0, 0xE8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE8);
    // 0x801F36A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F36A4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F36A8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F36AC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F36B0: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801F36B4: ldc1        $f16, -0x2E20($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2E20);
    // 0x801F36B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F36BC: ldc1        $f4, -0x2E18($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2E18);
    // 0x801F36C0: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F36C4: lw          $t2, 0xE8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE8);
    // 0x801F36C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F36CC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F36D0: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F36D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F36D8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F36DC: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801F36E0: ldc1        $f10, -0x2E10($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2E10);
    // 0x801F36E4: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801F36E8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F36EC: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F36F0: lw          $t4, 0xE8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XE8);
    // 0x801F36F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F36F8: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F36FC: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F3700: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F3704: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F3708: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801F370C: ldc1        $f8, -0x2E08($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E08);
    // 0x801F3710: lui         $at, 0x402F
    ctx->r1 = S32(0X402F << 16);
    // 0x801F3714: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F3718: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F371C: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x801F3720: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3724: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3728: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F372C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F3730: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
    // 0x801F3734: jal         0x8038BE98
    // 0x801F3738: lwc1        $f12, -0x2E00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2E00);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_4;
    // 0x801F3738: lwc1        $f12, -0x2E00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2E00);
    after_4:
    // 0x801F373C: b           L_801F38B4
    // 0x801F3740: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_801F38B4;
    // 0x801F3740: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_801F3744:
    // 0x801F3744: jal         0x801C0B2C
    // 0x801F3748: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801F3748: nop

    after_5:
    // 0x801F374C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F3750: jal         0x80034C24
    // 0x801F3754: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_6;
    // 0x801F3754: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_6:
    // 0x801F3758: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F375C: ldc1        $f6, -0x2DF8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2DF8);
    // 0x801F3760: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3764: ldc1        $f10, -0x2DF0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2DF0);
    // 0x801F3768: div.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x801F376C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801F3770: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F3774: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3778: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F377C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801F3780: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801F3784: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x801F3788: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F378C: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x801F3790: ldc1        $f8, -0x2DE8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2DE8);
    // 0x801F3794: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x801F3798: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F379C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F37A0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F37A4: lui         $at, 0xC01A
    ctx->r1 = S32(0XC01A << 16);
    // 0x801F37A8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F37AC: div.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801F37B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F37B4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F37B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F37BC: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F37C0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F37C4: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F37C8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F37CC: swc1        $f4, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f4.u32l;
    // 0x801F37D0: ldc1        $f10, -0x2DE0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2DE0);
    // 0x801F37D4: lw          $t0, 0xE8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE8);
    // 0x801F37D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F37DC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F37E0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F37E4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F37E8: swc1        $f18, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f18.u32l;
    // 0x801F37EC: ldc1        $f4, -0x2DD8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2DD8);
    // 0x801F37F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F37F4: ldc1        $f8, -0x2DD0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2DD0);
    // 0x801F37F8: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801F37FC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801F3800: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F3804: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F3808: lw          $t2, 0xE8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE8);
    // 0x801F380C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3810: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F3814: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F3818: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801F381C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F3820: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x801F3824: ldc1        $f6, -0x2DC8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2DC8);
    // 0x801F3828: lw          $t4, 0xE8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XE8);
    // 0x801F382C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3830: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F3834: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F3838: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F383C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F3840: swc1        $f10, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f10.u32l;
    // 0x801F3844: ldc1        $f16, -0x2DC0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2DC0);
    // 0x801F3848: lui         $at, 0x400C
    ctx->r1 = S32(0X400C << 16);
    // 0x801F384C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F3850: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801F3854: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x801F3858: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F385C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3860: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F3864: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F3868: swc1        $f8, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f8.u32l;
    // 0x801F386C: ldc1        $f10, -0x2DB8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2DB8);
    // 0x801F3870: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3874: ldc1        $f18, -0x2DB0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2DB0);
    // 0x801F3878: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801F387C: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x801F3880: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3884: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F3888: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F388C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F3890: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
    // 0x801F3894: ldc1        $f8, -0x2DA8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2DA8);
    // 0x801F3898: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F389C: ldc1        $f16, -0x2DA0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2DA0);
    // 0x801F38A0: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801F38A4: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F38A8: jal         0x8038BE98
    // 0x801F38AC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_7;
    // 0x801F38AC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_7:
    // 0x801F38B0: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_801F38B4:
    // 0x801F38B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F38B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F38BC: jr          $ra
    // 0x801F38C0: nop

    return;
    // 0x801F38C0: nop

;}
RECOMP_FUNC void M25_FUN_801f38c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F38C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F38C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F38CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F38D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F38D4: lui         $a1, 0x61E
    ctx->r5 = S32(0X61E << 16);
    // 0x801F38D8: ori         $a1, $a1, 0xF75
    ctx->r5 = ctx->r5 | 0XF75;
    // 0x801F38DC: jal         0x801C0B8C
    // 0x801F38E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F38E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F38E4: beq         $v0, $zero, L_801F38F4
    if (ctx->r2 == 0) {
        // 0x801F38E8: nop
    
            goto L_801F38F4;
    }
    // 0x801F38E8: nop

    // 0x801F38EC: b           L_801F3A0C
    // 0x801F38F0: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_801F3A0C;
    // 0x801F38F0: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_801F38F4:
    // 0x801F38F4: jal         0x801C0B2C
    // 0x801F38F8: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F38F8: nop

    after_1:
    // 0x801F38FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F3900: jal         0x80034C24
    // 0x801F3904: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F3904: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F3908: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F390C: ldc1        $f4, -0x2D98($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D98);
    // 0x801F3910: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3914: ldc1        $f8, -0x2D90($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2D90);
    // 0x801F3918: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F391C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801F3920: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F3924: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F3928: lui         $at, 0xC02F
    ctx->r1 = S32(0XC02F << 16);
    // 0x801F392C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F3930: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F3934: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F3938: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // 0x801F393C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3940: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F3944: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3948: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F394C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F3950: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F3954: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F3958: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801F395C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F3960: div.d       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F3964: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F3968: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F396C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3970: mul.d       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x801F3974: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F3978: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F397C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F3980: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F3984: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x801F3988: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F398C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F3990: swc1        $f6, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f6.u32l;
    // 0x801F3994: ldc1        $f8, -0x2D88($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2D88);
    // 0x801F3998: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801F399C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F39A0: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801F39A4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F39A8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F39AC: swc1        $f16, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f16.u32l;
    // 0x801F39B0: ldc1        $f18, -0x2D80($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2D80);
    // 0x801F39B4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801F39B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F39BC: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801F39C0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F39C4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F39C8: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801F39CC: ldc1        $f8, -0x2D78($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2D78);
    // 0x801F39D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F39D4: ldc1        $f16, -0x2D70($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2D70);
    // 0x801F39D8: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x801F39DC: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801F39E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F39E4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F39E8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F39EC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801F39F0: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x801F39F4: ldc1        $f6, -0x2D68($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2D68);
    // 0x801F39F8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801F39FC: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801F3A00: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3A04: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F3A08: swc1        $f10, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f10.u32l;
L_801F3A0C:
    // 0x801F3A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F3A14: jr          $ra
    // 0x801F3A18: nop

    return;
    // 0x801F3A18: nop

;}
RECOMP_FUNC void M25_FUN_801f3a1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3A1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F3A20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F3A24: jr          $ra
    // 0x801F3A28: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x801F3A28: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f3a2c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f3a2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3A2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F3A30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F3A34: jr          $ra
    // 0x801F3A38: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x801F3A38: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f3a3c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f3a3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3A3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F3A40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F3A44: jr          $ra
    // 0x801F3A48: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    return;
    // 0x801F3A48: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f3a4c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f3a4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3A4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3A54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F3A58: jal         0x801CD044
    // 0x801F3A5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD044)(rdram, ctx);
        goto after_0;
    // 0x801F3A5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F3A60: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801F3A64: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F3A68: lw          $a1, -0x5444($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5444);
    // 0x801F3A6C: jal         0x801CCF48
    // 0x801F3A70: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    LOOKUP_FUNC(0x801CCF48)(rdram, ctx);
        goto after_1;
    // 0x801F3A70: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    after_1:
    // 0x801F3A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F3A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F3A80: jr          $ra
    // 0x801F3A84: nop

    return;
    // 0x801F3A84: nop

;}
RECOMP_FUNC void M25_FUN_801f3a88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3A90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F3A94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F3A98: jal         0x801CCE0C
    // 0x801F3A9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801F3A9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801F3AA0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801F3AA4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801F3AA8: jal         0x801CCE50
    // 0x801F3AAC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801F3AAC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x801F3AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F3AB4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801F3AB8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801F3ABC: jal         0x801CCE88
    // 0x801F3AC0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801F3AC0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_2:
    // 0x801F3AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F3AC8: addiu       $a1, $zero, -0x7F
    ctx->r5 = ADD32(0, -0X7F);
    // 0x801F3ACC: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x801F3AD0: jal         0x801CCEC8
    // 0x801F3AD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_3;
    // 0x801F3AD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801F3AD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3ADC: lwc1        $f4, -0x2D60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D60);
    // 0x801F3AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3AE4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F3AEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F3AF0: jr          $ra
    // 0x801F3AF4: swc1        $f4, -0x4790($at)
    MEM_W(-0X4790, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x801F3AF4: swc1        $f4, -0x4790($at)
    MEM_W(-0X4790, ctx->r1) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f3af8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f3af8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3B00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F3B04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F3B08: jal         0x801CCE0C
    // 0x801F3B0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801F3B0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F3B10: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F3B14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F3B18: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801F3B1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F3B20: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F3B24: addiu       $v1, $v1, -0x2BC4
    ctx->r3 = ADD32(ctx->r3, -0X2BC4);
    // 0x801F3B28: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F3B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F3B30: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x801F3B34: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F3B38: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F3B3C: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F3B40: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801F3B44: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F3B48: addiu       $t1, $t1, -0x2BBC
    ctx->r9 = ADD32(ctx->r9, -0X2BBC);
    // 0x801F3B4C: addiu       $t0, $t0, -0x2BC0
    ctx->r8 = ADD32(ctx->r8, -0X2BC0);
    // 0x801F3B50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F3B54: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F3B58: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x801F3B5C: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x801F3B60: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F3B64: beq         $a1, $zero, L_801F3BB0
    if (ctx->r5 == 0) {
        // 0x801F3B68: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801F3BB0;
    }
    // 0x801F3B68: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F3B6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F3B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F3B74: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F3B78: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F3B7C: nop

    // 0x801F3B80: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F3B84: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F3B88: nop

    // 0x801F3B8C: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F3B90: bne         $a1, $zero, L_801F3BA8
    if (ctx->r5 != 0) {
        // 0x801F3B94: nop
    
            goto L_801F3BA8;
    }
    // 0x801F3B94: nop

    // 0x801F3B98: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F3B9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F3BA0: b           L_801F3BC0
    // 0x801F3BA4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F3BC0;
    // 0x801F3BA4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F3BA8:
    // 0x801F3BA8: b           L_801F3BC0
    // 0x801F3BAC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F3BC0;
    // 0x801F3BAC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801F3BB0:
    // 0x801F3BB0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F3BB4: nop

    // 0x801F3BB8: bltz        $a1, L_801F3BA8
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F3BBC: nop
    
            goto L_801F3BA8;
    }
    // 0x801F3BBC: nop

L_801F3BC0:
    // 0x801F3BC0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F3BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F3BC8: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F3BCC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F3BD0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F3BD4: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F3BD8: nop

    // 0x801F3BDC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F3BE0: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F3BE4: nop

    // 0x801F3BE8: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F3BEC: beq         $a2, $zero, L_801F3C38
    if (ctx->r6 == 0) {
        // 0x801F3BF0: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801F3C38;
    }
    // 0x801F3BF0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F3BF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F3BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F3BFC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F3C00: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F3C04: nop

    // 0x801F3C08: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F3C0C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F3C10: nop

    // 0x801F3C14: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F3C18: bne         $a2, $zero, L_801F3C30
    if (ctx->r6 != 0) {
        // 0x801F3C1C: nop
    
            goto L_801F3C30;
    }
    // 0x801F3C1C: nop

    // 0x801F3C20: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F3C24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F3C28: b           L_801F3C48
    // 0x801F3C2C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F3C48;
    // 0x801F3C2C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F3C30:
    // 0x801F3C30: b           L_801F3C48
    // 0x801F3C34: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F3C48;
    // 0x801F3C34: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_801F3C38:
    // 0x801F3C38: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F3C3C: nop

    // 0x801F3C40: bltz        $a2, L_801F3C30
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F3C44: nop
    
            goto L_801F3C30;
    }
    // 0x801F3C44: nop

L_801F3C48:
    // 0x801F3C48: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F3C4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F3C50: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801F3C54: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F3C58: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F3C5C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F3C60: nop

    // 0x801F3C64: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F3C68: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F3C6C: nop

    // 0x801F3C70: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F3C74: beq         $a3, $zero, L_801F3CC0
    if (ctx->r7 == 0) {
        // 0x801F3C78: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801F3CC0;
    }
    // 0x801F3C78: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F3C7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F3C80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F3C84: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F3C88: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F3C8C: nop

    // 0x801F3C90: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F3C94: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F3C98: nop

    // 0x801F3C9C: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F3CA0: bne         $a3, $zero, L_801F3CB8
    if (ctx->r7 != 0) {
        // 0x801F3CA4: nop
    
            goto L_801F3CB8;
    }
    // 0x801F3CA4: nop

    // 0x801F3CA8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801F3CAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F3CB0: b           L_801F3CD0
    // 0x801F3CB4: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F3CD0;
    // 0x801F3CB4: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F3CB8:
    // 0x801F3CB8: b           L_801F3CD0
    // 0x801F3CBC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F3CD0;
    // 0x801F3CBC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_801F3CC0:
    // 0x801F3CC0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801F3CC4: nop

    // 0x801F3CC8: bltz        $a3, L_801F3CB8
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F3CCC: nop
    
            goto L_801F3CB8;
    }
    // 0x801F3CCC: nop

L_801F3CD0:
    // 0x801F3CD0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F3CD4: jal         0x801CCE88
    // 0x801F3CD8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_1;
    // 0x801F3CD8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801F3CDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F3CE0: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x801F3CE4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801F3CE8: jal         0x801CCEC8
    // 0x801F3CEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_2;
    // 0x801F3CEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801F3CF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F3CF4: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F3CF8: addiu       $v0, $v0, -0x2BB8
    ctx->r2 = ADD32(ctx->r2, -0X2BB8);
    // 0x801F3CFC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F3D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F3D04: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801F3D08: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F3D0C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F3D10: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F3D14: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F3D18: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F3D1C: addiu       $t0, $t0, -0x2BB0
    ctx->r8 = ADD32(ctx->r8, -0X2BB0);
    // 0x801F3D20: addiu       $v1, $v1, -0x2BB4
    ctx->r3 = ADD32(ctx->r3, -0X2BB4);
    // 0x801F3D24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F3D28: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F3D2C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F3D30: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801F3D34: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F3D38: beq         $a1, $zero, L_801F3D84
    if (ctx->r5 == 0) {
        // 0x801F3D3C: swc1        $f0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
            goto L_801F3D84;
    }
    // 0x801F3D3C: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x801F3D40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F3D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F3D48: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F3D4C: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F3D50: nop

    // 0x801F3D54: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F3D58: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F3D5C: nop

    // 0x801F3D60: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F3D64: bne         $a1, $zero, L_801F3D7C
    if (ctx->r5 != 0) {
        // 0x801F3D68: nop
    
            goto L_801F3D7C;
    }
    // 0x801F3D68: nop

    // 0x801F3D6C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F3D70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F3D74: b           L_801F3D94
    // 0x801F3D78: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F3D94;
    // 0x801F3D78: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F3D7C:
    // 0x801F3D7C: b           L_801F3D94
    // 0x801F3D80: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F3D94;
    // 0x801F3D80: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801F3D84:
    // 0x801F3D84: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F3D88: nop

    // 0x801F3D8C: bltz        $a1, L_801F3D7C
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F3D90: nop
    
            goto L_801F3D7C;
    }
    // 0x801F3D90: nop

L_801F3D94:
    // 0x801F3D94: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F3D98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F3D9C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F3DA0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F3DA4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F3DA8: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F3DAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F3DB0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F3DB4: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F3DB8: nop

    // 0x801F3DBC: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F3DC0: beql        $a2, $zero, L_801F3E10
    if (ctx->r6 == 0) {
        // 0x801F3DC4: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801F3E10;
    }
    goto skip_0;
    // 0x801F3DC4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801F3DC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F3DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F3DD0: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F3DD4: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F3DD8: nop

    // 0x801F3DDC: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F3DE0: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F3DE4: nop

    // 0x801F3DE8: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F3DEC: bne         $a2, $zero, L_801F3E04
    if (ctx->r6 != 0) {
        // 0x801F3DF0: nop
    
            goto L_801F3E04;
    }
    // 0x801F3DF0: nop

    // 0x801F3DF4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F3DF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F3DFC: b           L_801F3E1C
    // 0x801F3E00: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F3E1C;
    // 0x801F3E00: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F3E04:
    // 0x801F3E04: b           L_801F3E1C
    // 0x801F3E08: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F3E1C;
    // 0x801F3E08: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F3E0C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801F3E10:
    // 0x801F3E10: nop

    // 0x801F3E14: bltz        $a2, L_801F3E04
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F3E18: nop
    
            goto L_801F3E04;
    }
    // 0x801F3E18: nop

L_801F3E1C:
    // 0x801F3E1C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F3E20: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F3E24: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F3E28: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F3E2C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801F3E30: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F3E34: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F3E38: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F3E3C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F3E40: nop

    // 0x801F3E44: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F3E48: beql        $a3, $zero, L_801F3E98
    if (ctx->r7 == 0) {
        // 0x801F3E4C: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801F3E98;
    }
    goto skip_1;
    // 0x801F3E4C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801F3E50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F3E54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F3E58: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F3E5C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F3E60: nop

    // 0x801F3E64: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F3E68: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F3E6C: nop

    // 0x801F3E70: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F3E74: bne         $a3, $zero, L_801F3E8C
    if (ctx->r7 != 0) {
        // 0x801F3E78: nop
    
            goto L_801F3E8C;
    }
    // 0x801F3E78: nop

    // 0x801F3E7C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801F3E80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F3E84: b           L_801F3EA4
    // 0x801F3E88: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F3EA4;
    // 0x801F3E88: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F3E8C:
    // 0x801F3E8C: b           L_801F3EA4
    // 0x801F3E90: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F3EA4;
    // 0x801F3E90: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F3E94: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801F3E98:
    // 0x801F3E98: nop

    // 0x801F3E9C: bltz        $a3, L_801F3E8C
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F3EA0: nop
    
            goto L_801F3E8C;
    }
    // 0x801F3EA0: nop

L_801F3EA4:
    // 0x801F3EA4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801F3EA8: jal         0x801CCE88
    // 0x801F3EAC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801F3EAC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_3:
    // 0x801F3EB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F3EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F3EB8: addiu       $a2, $zero, -0x50
    ctx->r6 = ADD32(0, -0X50);
    // 0x801F3EBC: jal         0x801CCEC8
    // 0x801F3EC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801F3EC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801F3EC4: lui         $a1, 0x5D
    ctx->r5 = S32(0X5D << 16);
    // 0x801F3EC8: ori         $a1, $a1, 0x1420
    ctx->r5 = ctx->r5 | 0X1420;
    // 0x801F3ECC: jal         0x801C0B8C
    // 0x801F3ED0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_5;
    // 0x801F3ED0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_5:
    // 0x801F3ED4: beq         $v0, $zero, L_801F3EE4
    if (ctx->r2 == 0) {
        // 0x801F3ED8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F3EE4;
    }
    // 0x801F3ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3EDC: b           L_801F3EE8
    // 0x801F3EE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F3EE8;
    // 0x801F3EE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F3EE4:
    // 0x801F3EE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F3EE8:
    // 0x801F3EE8: jr          $ra
    // 0x801F3EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F3EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f3ef0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f3ef0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3EF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F3EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F3F00: lui         $a1, 0xF5
    ctx->r5 = S32(0XF5 << 16);
    // 0x801F3F04: ori         $a1, $a1, 0xAA9F
    ctx->r5 = ctx->r5 | 0XAA9F;
    // 0x801F3F08: jal         0x801C0B8C
    // 0x801F3F0C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F3F0C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F3F10: beq         $v0, $zero, L_801F3F34
    if (ctx->r2 == 0) {
        // 0x801F3F14: lui         $v1, 0x8020
        ctx->r3 = S32(0X8020 << 16);
            goto L_801F3F34;
    }
    // 0x801F3F14: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F3F18: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3F1C: sw          $zero, -0x478C($at)
    MEM_W(-0X478C, ctx->r1) = 0;
    // 0x801F3F20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F3F24: jal         0x801C0D04
    // 0x801F3F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_1;
    // 0x801F3F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x801F3F2C: b           L_801F4124
    // 0x801F3F30: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F4124;
    // 0x801F3F30: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F3F34:
    // 0x801F3F34: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F3F38: addiu       $v0, $v0, -0x2BB8
    ctx->r2 = ADD32(ctx->r2, -0X2BB8);
    // 0x801F3F3C: addiu       $v1, $v1, -0x2BB4
    ctx->r3 = ADD32(ctx->r3, -0X2BB4);
    // 0x801F3F40: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F3F44: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F3F48: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F3F4C: addiu       $t0, $t0, -0x2BB0
    ctx->r8 = ADD32(ctx->r8, -0X2BB0);
    // 0x801F3F50: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F3F54: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x801F3F58: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x801F3F5C: lwc1        $f10, -0x2D5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2D5C);
    // 0x801F3F60: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F3F64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F3F68: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F3F6C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F3F70: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F3F74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F3F78: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F3F7C: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F3F80: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x801F3F84: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F3F88: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F3F8C: nop

    // 0x801F3F90: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F3F94: beql        $a1, $zero, L_801F3FE4
    if (ctx->r5 == 0) {
        // 0x801F3F98: mfc1        $a1, $f4
        ctx->r5 = (int32_t)ctx->f4.u32l;
            goto L_801F3FE4;
    }
    goto skip_0;
    // 0x801F3F98: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801F3F9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F3FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F3FA4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F3FA8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F3FAC: nop

    // 0x801F3FB0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F3FB4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F3FB8: nop

    // 0x801F3FBC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F3FC0: bne         $a1, $zero, L_801F3FD8
    if (ctx->r5 != 0) {
        // 0x801F3FC4: nop
    
            goto L_801F3FD8;
    }
    // 0x801F3FC4: nop

    // 0x801F3FC8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F3FCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F3FD0: b           L_801F3FF0
    // 0x801F3FD4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F3FF0;
    // 0x801F3FD4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F3FD8:
    // 0x801F3FD8: b           L_801F3FF0
    // 0x801F3FDC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F3FF0;
    // 0x801F3FDC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F3FE0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
L_801F3FE4:
    // 0x801F3FE4: nop

    // 0x801F3FE8: bltz        $a1, L_801F3FD8
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F3FEC: nop
    
            goto L_801F3FD8;
    }
    // 0x801F3FEC: nop

L_801F3FF0:
    // 0x801F3FF0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F3FF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F3FF8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F3FFC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F4000: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F4004: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F4008: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F400C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F4010: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4014: nop

    // 0x801F4018: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F401C: beql        $a2, $zero, L_801F406C
    if (ctx->r6 == 0) {
        // 0x801F4020: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_801F406C;
    }
    goto skip_1;
    // 0x801F4020: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801F4024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F4028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F402C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F4030: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F4034: nop

    // 0x801F4038: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F403C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4040: nop

    // 0x801F4044: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4048: bne         $a2, $zero, L_801F4060
    if (ctx->r6 != 0) {
        // 0x801F404C: nop
    
            goto L_801F4060;
    }
    // 0x801F404C: nop

    // 0x801F4050: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F4054: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4058: b           L_801F4078
    // 0x801F405C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F4078;
    // 0x801F405C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F4060:
    // 0x801F4060: b           L_801F4078
    // 0x801F4064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F4078;
    // 0x801F4064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F4068: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_801F406C:
    // 0x801F406C: nop

    // 0x801F4070: bltz        $a2, L_801F4060
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F4074: nop
    
            goto L_801F4060;
    }
    // 0x801F4074: nop

L_801F4078:
    // 0x801F4078: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F407C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4080: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F4084: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F4088: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F408C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4090: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4094: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F4098: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F409C: nop

    // 0x801F40A0: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F40A4: beql        $a3, $zero, L_801F40F4
    if (ctx->r7 == 0) {
        // 0x801F40A8: mfc1        $a3, $f16
        ctx->r7 = (int32_t)ctx->f16.u32l;
            goto L_801F40F4;
    }
    goto skip_2;
    // 0x801F40A8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801F40AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F40B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F40B4: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F40B8: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F40BC: nop

    // 0x801F40C0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F40C4: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F40C8: nop

    // 0x801F40CC: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F40D0: bne         $a3, $zero, L_801F40E8
    if (ctx->r7 != 0) {
        // 0x801F40D4: nop
    
            goto L_801F40E8;
    }
    // 0x801F40D4: nop

    // 0x801F40D8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801F40DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F40E0: b           L_801F4100
    // 0x801F40E4: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F4100;
    // 0x801F40E4: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F40E8:
    // 0x801F40E8: b           L_801F4100
    // 0x801F40EC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F4100;
    // 0x801F40EC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F40F0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
L_801F40F4:
    // 0x801F40F4: nop

    // 0x801F40F8: bltz        $a3, L_801F40E8
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F40FC: nop
    
            goto L_801F40E8;
    }
    // 0x801F40FC: nop

L_801F4100:
    // 0x801F4100: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F4104: jal         0x801CCE88
    // 0x801F4108: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801F4108: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_2:
    // 0x801F410C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F4110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4114: addiu       $a2, $zero, -0x50
    ctx->r6 = ADD32(0, -0X50);
    // 0x801F4118: jal         0x801CCEC8
    // 0x801F411C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_3;
    // 0x801F411C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801F4120: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F4124:
    // 0x801F4124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F412C: jr          $ra
    // 0x801F4130: nop

    return;
    // 0x801F4130: nop

;}
RECOMP_FUNC void M25_FUN_801f4134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4134: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801F4138: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x801F413C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4140: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x801F4144: lui         $a1, 0x160
    ctx->r5 = S32(0X160 << 16);
    // 0x801F4148: ori         $a1, $a1, 0x7A5F
    ctx->r5 = ctx->r5 | 0X7A5F;
    // 0x801F414C: jal         0x801C0B8C
    // 0x801F4150: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F4150: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F4154: beq         $v0, $zero, L_801F41AC
    if (ctx->r2 == 0) {
        // 0x801F4158: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F41AC;
    }
    // 0x801F4158: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F415C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F4160: jal         0x801C0EB0
    // 0x801F4164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x801F4164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x801F4168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F416C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F4174: jal         0x801CCE88
    // 0x801F4178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801F4178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801F417C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F4180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4184: addiu       $a2, $zero, -0x50
    ctx->r6 = ADD32(0, -0X50);
    // 0x801F4188: jal         0x801CCEC8
    // 0x801F418C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_3;
    // 0x801F418C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801F4190: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801F4194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4198: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F419C: jal         0x801CCE88
    // 0x801F41A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_4;
    // 0x801F41A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801F41A4: b           L_801F45B8
    // 0x801F41A8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F45B8;
    // 0x801F41A8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F41AC:
    // 0x801F41AC: lui         $a1, 0x132
    ctx->r5 = S32(0X132 << 16);
    // 0x801F41B0: jal         0x801C0B8C
    // 0x801F41B4: ori         $a1, $a1, 0xB39F
    ctx->r5 = ctx->r5 | 0XB39F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_5;
    // 0x801F41B4: ori         $a1, $a1, 0xB39F
    ctx->r5 = ctx->r5 | 0XB39F;
    after_5:
    // 0x801F41B8: beq         $v0, $zero, L_801F43CC
    if (ctx->r2 == 0) {
        // 0x801F41BC: lui         $v1, 0x8020
        ctx->r3 = S32(0X8020 << 16);
            goto L_801F43CC;
    }
    // 0x801F41BC: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F41C0: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F41C4: addiu       $t0, $t0, -0x2BB4
    ctx->r8 = ADD32(ctx->r8, -0X2BB4);
    // 0x801F41C8: addiu       $v1, $v1, -0x2BB8
    ctx->r3 = ADD32(ctx->r3, -0X2BB8);
    // 0x801F41CC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F41D0: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F41D4: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F41D8: addiu       $v0, $v0, -0x2BB0
    ctx->r2 = ADD32(ctx->r2, -0X2BB0);
    // 0x801F41DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F41E0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x801F41E4: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x801F41E8: lwc1        $f10, -0x2D58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2D58);
    // 0x801F41EC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F41F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801F41F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F41F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F41FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4200: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x801F4204: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F4208: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801F420C: nop

    // 0x801F4210: bc1fl       L_801F4224
    if (!c1cs) {
        // 0x801F4214: cfc1        $t6, $FpcCsr
        ctx->r14 = get_cop1_cs();
            goto L_801F4224;
    }
    goto skip_0;
    // 0x801F4214: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    skip_0:
    // 0x801F4218: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x801F421C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F4220: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_801F4224:
    // 0x801F4224: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4228: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F422C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F4230: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F4234: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4238: nop

    // 0x801F423C: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F4240: beql        $a1, $zero, L_801F4290
    if (ctx->r5 == 0) {
        // 0x801F4244: mfc1        $a1, $f4
        ctx->r5 = (int32_t)ctx->f4.u32l;
            goto L_801F4290;
    }
    goto skip_1;
    // 0x801F4244: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801F4248: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F424C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4250: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F4254: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4258: nop

    // 0x801F425C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F4260: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4264: nop

    // 0x801F4268: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F426C: bne         $a1, $zero, L_801F4284
    if (ctx->r5 != 0) {
        // 0x801F4270: nop
    
            goto L_801F4284;
    }
    // 0x801F4270: nop

    // 0x801F4274: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F4278: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F427C: b           L_801F429C
    // 0x801F4280: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F429C;
    // 0x801F4280: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F4284:
    // 0x801F4284: b           L_801F429C
    // 0x801F4288: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F429C;
    // 0x801F4288: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F428C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
L_801F4290:
    // 0x801F4290: nop

    // 0x801F4294: bltz        $a1, L_801F4284
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F4298: nop
    
            goto L_801F4284;
    }
    // 0x801F4298: nop

L_801F429C:
    // 0x801F429C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F42A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F42A4: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F42A8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F42AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F42B0: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F42B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F42B8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F42BC: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F42C0: nop

    // 0x801F42C4: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F42C8: beql        $a2, $zero, L_801F4318
    if (ctx->r6 == 0) {
        // 0x801F42CC: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_801F4318;
    }
    goto skip_2;
    // 0x801F42CC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x801F42D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F42D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F42D8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F42DC: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F42E0: nop

    // 0x801F42E4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F42E8: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F42EC: nop

    // 0x801F42F0: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F42F4: bne         $a2, $zero, L_801F430C
    if (ctx->r6 != 0) {
        // 0x801F42F8: nop
    
            goto L_801F430C;
    }
    // 0x801F42F8: nop

    // 0x801F42FC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F4300: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4304: b           L_801F4324
    // 0x801F4308: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F4324;
    // 0x801F4308: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F430C:
    // 0x801F430C: b           L_801F4324
    // 0x801F4310: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F4324;
    // 0x801F4310: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F4314: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_801F4318:
    // 0x801F4318: nop

    // 0x801F431C: bltz        $a2, L_801F430C
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F4320: nop
    
            goto L_801F430C;
    }
    // 0x801F4320: nop

L_801F4324:
    // 0x801F4324: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F4328: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F432C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F4330: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4334: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F4338: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F433C: nop

    // 0x801F4340: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801F4344: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4348: nop

    // 0x801F434C: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F4350: beql        $a3, $zero, L_801F43A0
    if (ctx->r7 == 0) {
        // 0x801F4354: mfc1        $a3, $f10
        ctx->r7 = (int32_t)ctx->f10.u32l;
            goto L_801F43A0;
    }
    goto skip_3;
    // 0x801F4354: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x801F4358: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F435C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4360: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801F4364: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4368: nop

    // 0x801F436C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F4370: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4374: nop

    // 0x801F4378: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F437C: bne         $a3, $zero, L_801F4394
    if (ctx->r7 != 0) {
        // 0x801F4380: nop
    
            goto L_801F4394;
    }
    // 0x801F4380: nop

    // 0x801F4384: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801F4388: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F438C: b           L_801F43AC
    // 0x801F4390: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F43AC;
    // 0x801F4390: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F4394:
    // 0x801F4394: b           L_801F43AC
    // 0x801F4398: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F43AC;
    // 0x801F4398: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F439C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
L_801F43A0:
    // 0x801F43A0: nop

    // 0x801F43A4: bltz        $a3, L_801F4394
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F43A8: nop
    
            goto L_801F4394;
    }
    // 0x801F43A8: nop

L_801F43AC:
    // 0x801F43AC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F43B0: jal         0x801CCE88
    // 0x801F43B4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_6;
    // 0x801F43B4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_6:
    // 0x801F43B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F43BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F43C0: addiu       $a2, $zero, -0x50
    ctx->r6 = ADD32(0, -0X50);
    // 0x801F43C4: jal         0x801CCEC8
    // 0x801F43C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_7;
    // 0x801F43C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_801F43CC:
    // 0x801F43CC: lui         $a1, 0x104
    ctx->r5 = S32(0X104 << 16);
    // 0x801F43D0: ori         $a1, $a1, 0xECDF
    ctx->r5 = ctx->r5 | 0XECDF;
    // 0x801F43D4: jal         0x801C0B8C
    // 0x801F43D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_8;
    // 0x801F43D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_8:
    // 0x801F43DC: beq         $v0, $zero, L_801F45B4
    if (ctx->r2 == 0) {
        // 0x801F43E0: addiu       $t9, $sp, 0x5C
        ctx->r25 = ADD32(ctx->r29, 0X5C);
            goto L_801F45B4;
    }
    // 0x801F43E0: addiu       $t9, $sp, 0x5C
    ctx->r25 = ADD32(ctx->r29, 0X5C);
    // 0x801F43E4: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801F43E8: addiu       $t1, $t1, -0x43A0
    ctx->r9 = ADD32(ctx->r9, -0X43A0);
    // 0x801F43EC: addiu       $t4, $t1, 0x24
    ctx->r12 = ADD32(ctx->r9, 0X24);
L_801F43F0:
    // 0x801F43F0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801F43F4: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x801F43F8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801F43FC: sw          $t3, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r11;
    // 0x801F4400: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x801F4404: sw          $t2, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r10;
    // 0x801F4408: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x801F440C: bne         $t1, $t4, L_801F43F0
    if (ctx->r9 != ctx->r12) {
        // 0x801F4410: sw          $t3, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r11;
            goto L_801F43F0;
    }
    // 0x801F4410: sw          $t3, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r11;
    // 0x801F4414: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801F4418: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x801F441C: addiu       $t6, $t6, -0x4378
    ctx->r14 = ADD32(ctx->r14, -0X4378);
    // 0x801F4420: addiu       $t4, $t6, 0x24
    ctx->r12 = ADD32(ctx->r14, 0X24);
    // 0x801F4424: addiu       $t5, $sp, 0x34
    ctx->r13 = ADD32(ctx->r29, 0X34);
    // 0x801F4428: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
L_801F442C:
    // 0x801F442C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801F4430: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801F4434: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x801F4438: sw          $t8, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r24;
    // 0x801F443C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801F4440: sw          $t7, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r15;
    // 0x801F4444: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801F4448: bne         $t6, $t4, L_801F442C
    if (ctx->r14 != ctx->r12) {
        // 0x801F444C: sw          $t8, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r24;
            goto L_801F442C;
    }
    // 0x801F444C: sw          $t8, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r24;
    // 0x801F4450: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801F4454: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F4458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F445C: jal         0x801C0F18
    // 0x801F4460: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_9;
    // 0x801F4460: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    after_9:
    // 0x801F4464: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F4468: jal         0x80034C24
    // 0x801F446C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_10;
    // 0x801F446C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_10:
    // 0x801F4470: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4474: lwc1        $f2, -0x4788($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4788);
    // 0x801F4478: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F447C: ldc1        $f16, -0x2D50($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2D50);
    // 0x801F4480: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801F4484: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F4488: div.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f0.d, ctx->f16.d);
    // 0x801F448C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F4490: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F4494: addiu       $v0, $v0, -0x478C
    ctx->r2 = ADD32(ctx->r2, -0X478C);
    // 0x801F4498: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x801F449C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F44A0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x801F44A4: nop

    // 0x801F44A8: bc1f        L_801F44E4
    if (!c1cs) {
        // 0x801F44AC: nop
    
            goto L_801F44E4;
    }
    // 0x801F44AC: nop

    // 0x801F44B0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F44B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801F44B8: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x801F44BC: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x801F44C0: mfhi        $t3
    ctx->r11 = hi;
    // 0x801F44C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801F44C8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x801F44CC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801F44D0: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x801F44D4: lwc1        $f10, 0x5C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X5C);
    // 0x801F44D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F44DC: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x801F44E0: swc1        $f2, -0x4788($at)
    MEM_W(-0X4788, ctx->r1) = ctx->f2.u32l;
L_801F44E4:
    // 0x801F44E4: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F44E8: addiu       $v0, $v0, -0x478C
    ctx->r2 = ADD32(ctx->r2, -0X478C);
    // 0x801F44EC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F44F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F44F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F44F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801F44FC: addu        $t1, $sp, $t8
    ctx->r9 = ADD32(ctx->r29, ctx->r24);
    // 0x801F4500: lwc1        $f16, 0x34($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X34);
    // 0x801F4504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4508: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F450C: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801F4510: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801F4514: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F4518: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F451C: nop

    // 0x801F4520: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801F4524: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4528: nop

    // 0x801F452C: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F4530: beql        $a1, $zero, L_801F4580
    if (ctx->r5 == 0) {
        // 0x801F4534: mfc1        $a1, $f4
        ctx->r5 = (int32_t)ctx->f4.u32l;
            goto L_801F4580;
    }
    goto skip_4;
    // 0x801F4534: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x801F4538: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F453C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4540: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801F4544: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4548: nop

    // 0x801F454C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F4550: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4554: nop

    // 0x801F4558: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F455C: bne         $a1, $zero, L_801F4574
    if (ctx->r5 != 0) {
        // 0x801F4560: nop
    
            goto L_801F4574;
    }
    // 0x801F4560: nop

    // 0x801F4564: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F4568: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F456C: b           L_801F458C
    // 0x801F4570: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F458C;
    // 0x801F4570: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F4574:
    // 0x801F4574: b           L_801F458C
    // 0x801F4578: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F458C;
    // 0x801F4578: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F457C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
L_801F4580:
    // 0x801F4580: nop

    // 0x801F4584: bltz        $a1, L_801F4574
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F4588: nop
    
            goto L_801F4574;
    }
    // 0x801F4588: nop

L_801F458C:
    // 0x801F458C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F4590: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F4594: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x801F4598: jal         0x801CCE88
    // 0x801F459C: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_11;
    // 0x801F459C: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    after_11:
    // 0x801F45A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801F45A4: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x801F45A8: addiu       $a2, $zero, -0x14
    ctx->r6 = ADD32(0, -0X14);
    // 0x801F45AC: jal         0x801CCEC8
    // 0x801F45B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_12;
    // 0x801F45B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
L_801F45B4:
    // 0x801F45B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F45B8:
    // 0x801F45B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F45BC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x801F45C0: jr          $ra
    // 0x801F45C4: nop

    return;
    // 0x801F45C4: nop

;}
RECOMP_FUNC void M25_FUN_801f45c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F45C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F45CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F45D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F45D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F45D8: jal         0x801CCE0C
    // 0x801F45DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801F45DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801F45E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801F45E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F45E8: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x801F45EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F45F0: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F45F4: addiu       $v1, $v1, -0x2BC4
    ctx->r3 = ADD32(ctx->r3, -0X2BC4);
    // 0x801F45F8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801F45FC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F4600: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4604: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F4608: addiu       $t0, $t0, -0x2BC0
    ctx->r8 = ADD32(ctx->r8, -0X2BC0);
    // 0x801F460C: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801F4610: addiu       $t1, $t1, -0x2BBC
    ctx->r9 = ADD32(ctx->r9, -0X2BBC);
    // 0x801F4614: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801F4618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F461C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4620: swc1        $f10, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f10.u32l;
    // 0x801F4624: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4628: lwc1        $f18, -0x2D48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2D48);
    // 0x801F462C: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F4630: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4634: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801F4638: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801F463C: swc1        $f4, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f4.u32l;
    // 0x801F4640: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4644: lwc1        $f10, -0x2D44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2D44);
    // 0x801F4648: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801F464C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4650: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801F4654: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801F4658: swc1        $f16, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f16.u32l;
    // 0x801F465C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F4660: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4664: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F4668: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F466C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F4670: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4674: nop

    // 0x801F4678: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F467C: beql        $a1, $zero, L_801F46CC
    if (ctx->r5 == 0) {
        // 0x801F4680: mfc1        $a1, $f4
        ctx->r5 = (int32_t)ctx->f4.u32l;
            goto L_801F46CC;
    }
    goto skip_0;
    // 0x801F4680: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801F4684: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F4688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F468C: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801F4690: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4694: nop

    // 0x801F4698: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F469C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F46A0: nop

    // 0x801F46A4: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F46A8: bne         $a1, $zero, L_801F46C0
    if (ctx->r5 != 0) {
        // 0x801F46AC: nop
    
            goto L_801F46C0;
    }
    // 0x801F46AC: nop

    // 0x801F46B0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F46B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F46B8: b           L_801F46D8
    // 0x801F46BC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F46D8;
    // 0x801F46BC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F46C0:
    // 0x801F46C0: b           L_801F46D8
    // 0x801F46C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F46D8;
    // 0x801F46C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F46C8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
L_801F46CC:
    // 0x801F46CC: nop

    // 0x801F46D0: bltz        $a1, L_801F46C0
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F46D4: nop
    
            goto L_801F46C0;
    }
    // 0x801F46D4: nop

L_801F46D8:
    // 0x801F46D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F46DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F46E0: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F46E4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F46E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F46EC: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F46F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F46F4: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F46F8: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F46FC: nop

    // 0x801F4700: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4704: beql        $a2, $zero, L_801F4754
    if (ctx->r6 == 0) {
        // 0x801F4708: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_801F4754;
    }
    goto skip_1;
    // 0x801F4708: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801F470C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F4710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F4714: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801F4718: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F471C: nop

    // 0x801F4720: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F4724: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4728: nop

    // 0x801F472C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4730: bne         $a2, $zero, L_801F4748
    if (ctx->r6 != 0) {
        // 0x801F4734: nop
    
            goto L_801F4748;
    }
    // 0x801F4734: nop

    // 0x801F4738: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F473C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4740: b           L_801F4760
    // 0x801F4744: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F4760;
    // 0x801F4744: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F4748:
    // 0x801F4748: b           L_801F4760
    // 0x801F474C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F4760;
    // 0x801F474C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F4750: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_801F4754:
    // 0x801F4754: nop

    // 0x801F4758: bltz        $a2, L_801F4748
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F475C: nop
    
            goto L_801F4748;
    }
    // 0x801F475C: nop

L_801F4760:
    // 0x801F4760: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F4764: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4768: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801F476C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F4770: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F4774: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4778: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F477C: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F4780: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4784: nop

    // 0x801F4788: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F478C: beql        $a3, $zero, L_801F47DC
    if (ctx->r7 == 0) {
        // 0x801F4790: mfc1        $a3, $f16
        ctx->r7 = (int32_t)ctx->f16.u32l;
            goto L_801F47DC;
    }
    goto skip_2;
    // 0x801F4790: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801F4794: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F4798: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F479C: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801F47A0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F47A4: nop

    // 0x801F47A8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F47AC: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F47B0: nop

    // 0x801F47B4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F47B8: bne         $a3, $zero, L_801F47D0
    if (ctx->r7 != 0) {
        // 0x801F47BC: nop
    
            goto L_801F47D0;
    }
    // 0x801F47BC: nop

    // 0x801F47C0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801F47C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F47C8: b           L_801F47E8
    // 0x801F47CC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F47E8;
    // 0x801F47CC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F47D0:
    // 0x801F47D0: b           L_801F47E8
    // 0x801F47D4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F47E8;
    // 0x801F47D4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F47D8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
L_801F47DC:
    // 0x801F47DC: nop

    // 0x801F47E0: bltz        $a3, L_801F47D0
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F47E4: nop
    
            goto L_801F47D0;
    }
    // 0x801F47E4: nop

L_801F47E8:
    // 0x801F47E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F47EC: jal         0x801CCE88
    // 0x801F47F0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_1;
    // 0x801F47F0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801F47F4: lui         $a1, 0x1BC
    ctx->r5 = S32(0X1BC << 16);
    // 0x801F47F8: ori         $a1, $a1, 0x7DF
    ctx->r5 = ctx->r5 | 0X7DF;
    // 0x801F47FC: jal         0x801C0B8C
    // 0x801F4800: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801F4800: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_2:
    // 0x801F4804: beq         $v0, $zero, L_801F4838
    if (ctx->r2 == 0) {
        // 0x801F4808: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_801F4838;
    }
    // 0x801F4808: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F480C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F4810: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801F4814: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F4818: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F481C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801F4820: swc1        $f6, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f6.u32l;
    // 0x801F4824: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4828: swc1        $f0, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f0.u32l;
    // 0x801F482C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4830: b           L_801F483C
    // 0x801F4834: swc1        $f0, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f0.u32l;
        goto L_801F483C;
    // 0x801F4834: swc1        $f0, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f0.u32l;
L_801F4838:
    // 0x801F4838: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F483C:
    // 0x801F483C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F4844: jr          $ra
    // 0x801F4848: nop

    return;
    // 0x801F4848: nop

;}
RECOMP_FUNC void M25_FUN_801f484c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F484C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F4850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F4858: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F485C: jal         0x801CCE0C
    // 0x801F4860: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801F4860: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801F4864: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801F4868: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F486C: lui         $at, 0xC088
    ctx->r1 = S32(0XC088 << 16);
    // 0x801F4870: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F4874: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F4878: addiu       $v1, $v1, -0x2BC4
    ctx->r3 = ADD32(ctx->r3, -0X2BC4);
    // 0x801F487C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801F4880: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F4884: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4888: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F488C: addiu       $t0, $t0, -0x2BC0
    ctx->r8 = ADD32(ctx->r8, -0X2BC0);
    // 0x801F4890: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801F4894: addiu       $t1, $t1, -0x2BBC
    ctx->r9 = ADD32(ctx->r9, -0X2BBC);
    // 0x801F4898: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801F489C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F48A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F48A4: swc1        $f10, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f10.u32l;
    // 0x801F48A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F48AC: lwc1        $f18, -0x2D40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2D40);
    // 0x801F48B0: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F48B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F48B8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801F48BC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801F48C0: swc1        $f4, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f4.u32l;
    // 0x801F48C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F48C8: lwc1        $f10, -0x2D3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2D3C);
    // 0x801F48CC: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801F48D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F48D4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801F48D8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801F48DC: swc1        $f16, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f16.u32l;
    // 0x801F48E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F48E4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F48E8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F48EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F48F0: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F48F4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F48F8: nop

    // 0x801F48FC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F4900: beql        $a1, $zero, L_801F4950
    if (ctx->r5 == 0) {
        // 0x801F4904: mfc1        $a1, $f4
        ctx->r5 = (int32_t)ctx->f4.u32l;
            goto L_801F4950;
    }
    goto skip_0;
    // 0x801F4904: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801F4908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F490C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4910: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801F4914: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4918: nop

    // 0x801F491C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F4920: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4924: nop

    // 0x801F4928: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F492C: bne         $a1, $zero, L_801F4944
    if (ctx->r5 != 0) {
        // 0x801F4930: nop
    
            goto L_801F4944;
    }
    // 0x801F4930: nop

    // 0x801F4934: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F4938: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F493C: b           L_801F495C
    // 0x801F4940: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F495C;
    // 0x801F4940: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F4944:
    // 0x801F4944: b           L_801F495C
    // 0x801F4948: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F495C;
    // 0x801F4948: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F494C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
L_801F4950:
    // 0x801F4950: nop

    // 0x801F4954: bltz        $a1, L_801F4944
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F4958: nop
    
            goto L_801F4944;
    }
    // 0x801F4958: nop

L_801F495C:
    // 0x801F495C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F4960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F4964: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F4968: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F496C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F4970: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F4974: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4978: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F497C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4980: nop

    // 0x801F4984: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4988: beql        $a2, $zero, L_801F49D8
    if (ctx->r6 == 0) {
        // 0x801F498C: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_801F49D8;
    }
    goto skip_1;
    // 0x801F498C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801F4990: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F4994: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F4998: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801F499C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F49A0: nop

    // 0x801F49A4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F49A8: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F49AC: nop

    // 0x801F49B0: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F49B4: bne         $a2, $zero, L_801F49CC
    if (ctx->r6 != 0) {
        // 0x801F49B8: nop
    
            goto L_801F49CC;
    }
    // 0x801F49B8: nop

    // 0x801F49BC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F49C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F49C4: b           L_801F49E4
    // 0x801F49C8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F49E4;
    // 0x801F49C8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F49CC:
    // 0x801F49CC: b           L_801F49E4
    // 0x801F49D0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F49E4;
    // 0x801F49D0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F49D4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_801F49D8:
    // 0x801F49D8: nop

    // 0x801F49DC: bltz        $a2, L_801F49CC
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F49E0: nop
    
            goto L_801F49CC;
    }
    // 0x801F49E0: nop

L_801F49E4:
    // 0x801F49E4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F49E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F49EC: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801F49F0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F49F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F49F8: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F49FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4A00: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F4A04: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4A08: nop

    // 0x801F4A0C: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F4A10: beql        $a3, $zero, L_801F4A60
    if (ctx->r7 == 0) {
        // 0x801F4A14: mfc1        $a3, $f16
        ctx->r7 = (int32_t)ctx->f16.u32l;
            goto L_801F4A60;
    }
    goto skip_2;
    // 0x801F4A14: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801F4A18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F4A1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4A20: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801F4A24: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4A28: nop

    // 0x801F4A2C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F4A30: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4A34: nop

    // 0x801F4A38: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F4A3C: bne         $a3, $zero, L_801F4A54
    if (ctx->r7 != 0) {
        // 0x801F4A40: nop
    
            goto L_801F4A54;
    }
    // 0x801F4A40: nop

    // 0x801F4A44: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801F4A48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4A4C: b           L_801F4A6C
    // 0x801F4A50: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F4A6C;
    // 0x801F4A50: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F4A54:
    // 0x801F4A54: b           L_801F4A6C
    // 0x801F4A58: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F4A6C;
    // 0x801F4A58: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F4A5C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
L_801F4A60:
    // 0x801F4A60: nop

    // 0x801F4A64: bltz        $a3, L_801F4A54
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F4A68: nop
    
            goto L_801F4A54;
    }
    // 0x801F4A68: nop

L_801F4A6C:
    // 0x801F4A6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F4A70: jal         0x801CCE88
    // 0x801F4A74: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_1;
    // 0x801F4A74: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801F4A78: lui         $a1, 0x1DA
    ctx->r5 = S32(0X1DA << 16);
    // 0x801F4A7C: ori         $a1, $a1, 0x8C5F
    ctx->r5 = ctx->r5 | 0X8C5F;
    // 0x801F4A80: jal         0x801C0B8C
    // 0x801F4A84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801F4A84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_2:
    // 0x801F4A88: beq         $v0, $zero, L_801F4AC4
    if (ctx->r2 == 0) {
        // 0x801F4A8C: lui         $at, 0x4299
        ctx->r1 = S32(0X4299 << 16);
            goto L_801F4AC4;
    }
    // 0x801F4A8C: lui         $at, 0x4299
    ctx->r1 = S32(0X4299 << 16);
    // 0x801F4A90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F4A94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4A98: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801F4A9C: swc1        $f6, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f6.u32l;
    // 0x801F4AA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4AA4: lwc1        $f4, -0x2D38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D38);
    // 0x801F4AA8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4AAC: swc1        $f4, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f4.u32l;
    // 0x801F4AB0: lui         $at, 0x431C
    ctx->r1 = S32(0X431C << 16);
    // 0x801F4AB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F4AB8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4ABC: b           L_801F4AC8
    // 0x801F4AC0: swc1        $f10, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f10.u32l;
        goto L_801F4AC8;
    // 0x801F4AC0: swc1        $f10, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f10.u32l;
L_801F4AC4:
    // 0x801F4AC4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F4AC8:
    // 0x801F4AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F4AD0: jr          $ra
    // 0x801F4AD4: nop

    return;
    // 0x801F4AD4: nop

;}
RECOMP_FUNC void M25_FUN_801f4ad8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F4ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4AE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F4AE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F4AE8: jal         0x801CCE0C
    // 0x801F4AEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801F4AEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801F4AF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4AF4: lwc1        $f0, -0x2D34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D34);
    // 0x801F4AF8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4AFC: lwc1        $f6, -0x2D30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2D30);
    // 0x801F4B00: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F4B04: addiu       $v1, $v1, -0x2BC4
    ctx->r3 = ADD32(ctx->r3, -0X2BC4);
    // 0x801F4B08: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801F4B0C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F4B10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4B14: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F4B18: addiu       $t0, $t0, -0x2BC0
    ctx->r8 = ADD32(ctx->r8, -0X2BC0);
    // 0x801F4B1C: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801F4B20: addiu       $t1, $t1, -0x2BBC
    ctx->r9 = ADD32(ctx->r9, -0X2BBC);
    // 0x801F4B24: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801F4B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4B2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4B30: swc1        $f10, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f10.u32l;
    // 0x801F4B34: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4B38: lwc1        $f18, -0x2D2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2D2C);
    // 0x801F4B3C: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F4B40: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4B44: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801F4B48: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801F4B4C: swc1        $f4, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f4.u32l;
    // 0x801F4B50: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4B54: lwc1        $f10, -0x2D28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2D28);
    // 0x801F4B58: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801F4B5C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4B60: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801F4B64: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801F4B68: swc1        $f16, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f16.u32l;
    // 0x801F4B6C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F4B70: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4B74: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F4B78: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4B7C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F4B80: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4B84: nop

    // 0x801F4B88: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F4B8C: beql        $a1, $zero, L_801F4BDC
    if (ctx->r5 == 0) {
        // 0x801F4B90: mfc1        $a1, $f4
        ctx->r5 = (int32_t)ctx->f4.u32l;
            goto L_801F4BDC;
    }
    goto skip_0;
    // 0x801F4B90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801F4B94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F4B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4B9C: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801F4BA0: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4BA4: nop

    // 0x801F4BA8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F4BAC: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4BB0: nop

    // 0x801F4BB4: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F4BB8: bne         $a1, $zero, L_801F4BD0
    if (ctx->r5 != 0) {
        // 0x801F4BBC: nop
    
            goto L_801F4BD0;
    }
    // 0x801F4BBC: nop

    // 0x801F4BC0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F4BC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4BC8: b           L_801F4BE8
    // 0x801F4BCC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F4BE8;
    // 0x801F4BCC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F4BD0:
    // 0x801F4BD0: b           L_801F4BE8
    // 0x801F4BD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F4BE8;
    // 0x801F4BD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F4BD8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
L_801F4BDC:
    // 0x801F4BDC: nop

    // 0x801F4BE0: bltz        $a1, L_801F4BD0
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F4BE4: nop
    
            goto L_801F4BD0;
    }
    // 0x801F4BE4: nop

L_801F4BE8:
    // 0x801F4BE8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F4BEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F4BF0: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F4BF4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F4BF8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F4BFC: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F4C00: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4C04: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F4C08: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4C0C: nop

    // 0x801F4C10: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4C14: beql        $a2, $zero, L_801F4C64
    if (ctx->r6 == 0) {
        // 0x801F4C18: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_801F4C64;
    }
    goto skip_1;
    // 0x801F4C18: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801F4C1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F4C20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F4C24: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801F4C28: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F4C2C: nop

    // 0x801F4C30: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F4C34: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4C38: nop

    // 0x801F4C3C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4C40: bne         $a2, $zero, L_801F4C58
    if (ctx->r6 != 0) {
        // 0x801F4C44: nop
    
            goto L_801F4C58;
    }
    // 0x801F4C44: nop

    // 0x801F4C48: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F4C4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4C50: b           L_801F4C70
    // 0x801F4C54: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F4C70;
    // 0x801F4C54: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F4C58:
    // 0x801F4C58: b           L_801F4C70
    // 0x801F4C5C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F4C70;
    // 0x801F4C5C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F4C60: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_801F4C64:
    // 0x801F4C64: nop

    // 0x801F4C68: bltz        $a2, L_801F4C58
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F4C6C: nop
    
            goto L_801F4C58;
    }
    // 0x801F4C6C: nop

L_801F4C70:
    // 0x801F4C70: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F4C74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4C78: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801F4C7C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F4C80: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F4C84: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4C88: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4C8C: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F4C90: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4C94: nop

    // 0x801F4C98: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F4C9C: beql        $a3, $zero, L_801F4CEC
    if (ctx->r7 == 0) {
        // 0x801F4CA0: mfc1        $a3, $f16
        ctx->r7 = (int32_t)ctx->f16.u32l;
            goto L_801F4CEC;
    }
    goto skip_2;
    // 0x801F4CA0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801F4CA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F4CA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4CAC: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801F4CB0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4CB4: nop

    // 0x801F4CB8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F4CBC: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4CC0: nop

    // 0x801F4CC4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F4CC8: bne         $a3, $zero, L_801F4CE0
    if (ctx->r7 != 0) {
        // 0x801F4CCC: nop
    
            goto L_801F4CE0;
    }
    // 0x801F4CCC: nop

    // 0x801F4CD0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801F4CD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4CD8: b           L_801F4CF8
    // 0x801F4CDC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F4CF8;
    // 0x801F4CDC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F4CE0:
    // 0x801F4CE0: b           L_801F4CF8
    // 0x801F4CE4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F4CF8;
    // 0x801F4CE4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F4CE8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
L_801F4CEC:
    // 0x801F4CEC: nop

    // 0x801F4CF0: bltz        $a3, L_801F4CE0
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F4CF4: nop
    
            goto L_801F4CE0;
    }
    // 0x801F4CF4: nop

L_801F4CF8:
    // 0x801F4CF8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F4CFC: jal         0x801CCE88
    // 0x801F4D00: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_1;
    // 0x801F4D00: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801F4D04: lui         $a1, 0x208
    ctx->r5 = S32(0X208 << 16);
    // 0x801F4D08: ori         $a1, $a1, 0x531F
    ctx->r5 = ctx->r5 | 0X531F;
    // 0x801F4D0C: jal         0x801C0B8C
    // 0x801F4D10: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801F4D10: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_2:
    // 0x801F4D14: beq         $v0, $zero, L_801F4EEC
    if (ctx->r2 == 0) {
        // 0x801F4D18: lui         $v1, 0x8020
        ctx->r3 = S32(0X8020 << 16);
            goto L_801F4EEC;
    }
    // 0x801F4D18: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F4D1C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F4D20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F4D24: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F4D28: addiu       $v0, $v0, -0x2BC4
    ctx->r2 = ADD32(ctx->r2, -0X2BC4);
    // 0x801F4D2C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F4D30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4D34: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801F4D38: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4D3C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F4D40: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801F4D44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F4D48: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F4D4C: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F4D50: addiu       $t0, $t0, -0x2BBC
    ctx->r8 = ADD32(ctx->r8, -0X2BBC);
    // 0x801F4D54: addiu       $v1, $v1, -0x2BC0
    ctx->r3 = ADD32(ctx->r3, -0X2BC0);
    // 0x801F4D58: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4D60: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801F4D64: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F4D68: beq         $a1, $zero, L_801F4DB8
    if (ctx->r5 == 0) {
        // 0x801F4D6C: swc1        $f6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
            goto L_801F4DB8;
    }
    // 0x801F4D6C: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x801F4D70: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4D74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F4D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F4D7C: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801F4D80: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F4D84: nop

    // 0x801F4D88: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F4D8C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F4D90: nop

    // 0x801F4D94: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F4D98: bne         $a1, $zero, L_801F4DB0
    if (ctx->r5 != 0) {
        // 0x801F4D9C: nop
    
            goto L_801F4DB0;
    }
    // 0x801F4D9C: nop

    // 0x801F4DA0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801F4DA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4DA8: b           L_801F4DC8
    // 0x801F4DAC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F4DC8;
    // 0x801F4DAC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F4DB0:
    // 0x801F4DB0: b           L_801F4DC8
    // 0x801F4DB4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F4DC8;
    // 0x801F4DB4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801F4DB8:
    // 0x801F4DB8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801F4DBC: nop

    // 0x801F4DC0: bltz        $a1, L_801F4DB0
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F4DC4: nop
    
            goto L_801F4DB0;
    }
    // 0x801F4DC4: nop

L_801F4DC8:
    // 0x801F4DC8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F4DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F4DD0: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F4DD4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F4DD8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F4DDC: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F4DE0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4DE4: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F4DE8: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4DEC: nop

    // 0x801F4DF0: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4DF4: beql        $a2, $zero, L_801F4E44
    if (ctx->r6 == 0) {
        // 0x801F4DF8: mfc1        $a2, $f18
        ctx->r6 = (int32_t)ctx->f18.u32l;
            goto L_801F4E44;
    }
    goto skip_3;
    // 0x801F4DF8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x801F4DFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F4E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F4E04: sub.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x801F4E08: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F4E0C: nop

    // 0x801F4E10: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F4E14: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F4E18: nop

    // 0x801F4E1C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F4E20: bne         $a2, $zero, L_801F4E38
    if (ctx->r6 != 0) {
        // 0x801F4E24: nop
    
            goto L_801F4E38;
    }
    // 0x801F4E24: nop

    // 0x801F4E28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801F4E2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4E30: b           L_801F4E50
    // 0x801F4E34: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F4E50;
    // 0x801F4E34: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F4E38:
    // 0x801F4E38: b           L_801F4E50
    // 0x801F4E3C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F4E50;
    // 0x801F4E3C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F4E40: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
L_801F4E44:
    // 0x801F4E44: nop

    // 0x801F4E48: bltz        $a2, L_801F4E38
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F4E4C: nop
    
            goto L_801F4E38;
    }
    // 0x801F4E4C: nop

L_801F4E50:
    // 0x801F4E50: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F4E54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4E58: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F4E5C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F4E60: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801F4E64: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4E68: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F4E6C: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F4E70: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4E74: nop

    // 0x801F4E78: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F4E7C: beql        $a3, $zero, L_801F4ECC
    if (ctx->r7 == 0) {
        // 0x801F4E80: mfc1        $a3, $f6
        ctx->r7 = (int32_t)ctx->f6.u32l;
            goto L_801F4ECC;
    }
    goto skip_4;
    // 0x801F4E80: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    skip_4:
    // 0x801F4E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F4E88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F4E8C: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801F4E90: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F4E94: nop

    // 0x801F4E98: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F4E9C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F4EA0: nop

    // 0x801F4EA4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F4EA8: bne         $a3, $zero, L_801F4EC0
    if (ctx->r7 != 0) {
        // 0x801F4EAC: nop
    
            goto L_801F4EC0;
    }
    // 0x801F4EAC: nop

    // 0x801F4EB0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801F4EB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F4EB8: b           L_801F4ED8
    // 0x801F4EBC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F4ED8;
    // 0x801F4EBC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F4EC0:
    // 0x801F4EC0: b           L_801F4ED8
    // 0x801F4EC4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F4ED8;
    // 0x801F4EC4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F4EC8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
L_801F4ECC:
    // 0x801F4ECC: nop

    // 0x801F4ED0: bltz        $a3, L_801F4EC0
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F4ED4: nop
    
            goto L_801F4EC0;
    }
    // 0x801F4ED4: nop

L_801F4ED8:
    // 0x801F4ED8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801F4EDC: jal         0x801CCE88
    // 0x801F4EE0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801F4EE0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_3:
    // 0x801F4EE4: b           L_801F4EF0
    // 0x801F4EE8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801F4EF0;
    // 0x801F4EE8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F4EEC:
    // 0x801F4EEC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F4EF0:
    // 0x801F4EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F4EF8: jr          $ra
    // 0x801F4EFC: nop

    return;
    // 0x801F4EFC: nop

;}
RECOMP_FUNC void M25_FUN_801f4f00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4F00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F4F04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F4F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4F0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F4F10: lui         $a1, 0x49F
    ctx->r5 = S32(0X49F << 16);
    // 0x801F4F14: ori         $a1, $a1, 0x1095
    ctx->r5 = ctx->r5 | 0X1095;
    // 0x801F4F18: jal         0x801C0B8C
    // 0x801F4F1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F4F1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F4F20: beq         $v0, $zero, L_801F4F30
    if (ctx->r2 == 0) {
        // 0x801F4F24: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F4F30;
    }
    // 0x801F4F24: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F4F28: b           L_801F5124
    // 0x801F4F2C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801F5124;
    // 0x801F4F2C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801F4F30:
    // 0x801F4F30: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F4F34: jal         0x801C0B8C
    // 0x801F4F38: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F4F38: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    after_1:
    // 0x801F4F3C: beq         $v0, $zero, L_801F4F8C
    if (ctx->r2 == 0) {
        // 0x801F4F40: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F4F8C;
    }
    // 0x801F4F40: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F4F44: jal         0x801CCE0C
    // 0x801F4F48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_2;
    // 0x801F4F48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801F4F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4F50: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801F4F54: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801F4F58: jal         0x801CCE88
    // 0x801F4F5C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801F4F5C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_3:
    // 0x801F4F60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4F68: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x801F4F6C: jal         0x801CCEC8
    // 0x801F4F70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801F4F70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801F4F74: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801F4F78: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801F4F7C: jal         0x801CCE50
    // 0x801F4F80: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_5;
    // 0x801F4F80: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_5:
    // 0x801F4F84: b           L_801F5124
    // 0x801F4F88: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801F5124;
    // 0x801F4F88: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F4F8C:
    // 0x801F4F8C: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801F4F90: jal         0x801C0B8C
    // 0x801F4F94: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_6;
    // 0x801F4F94: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    after_6:
    // 0x801F4F98: beq         $v0, $zero, L_801F4FBC
    if (ctx->r2 == 0) {
        // 0x801F4F9C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F4FBC;
    }
    // 0x801F4F9C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F4FA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4FA4: lwc1        $f4, -0x4790($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4790);
    // 0x801F4FA8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801F4FAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F4FB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4FB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801F4FB8: swc1        $f8, -0x4790($at)
    MEM_W(-0X4790, ctx->r1) = ctx->f8.u32l;
L_801F4FBC:
    // 0x801F4FBC: lui         $a1, 0x208
    ctx->r5 = S32(0X208 << 16);
    // 0x801F4FC0: jal         0x801C0B8C
    // 0x801F4FC4: ori         $a1, $a1, 0x531F
    ctx->r5 = ctx->r5 | 0X531F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_7;
    // 0x801F4FC4: ori         $a1, $a1, 0x531F
    ctx->r5 = ctx->r5 | 0X531F;
    after_7:
    // 0x801F4FC8: beq         $v0, $zero, L_801F5120
    if (ctx->r2 == 0) {
        // 0x801F4FCC: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801F5120;
    }
    // 0x801F4FCC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4FD0: lwc1        $f0, -0x4784($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4784);
    // 0x801F4FD4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4FD8: lwc1        $f10, -0x4790($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4790);
    // 0x801F4FDC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4FE0: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x801F4FE4: swc1        $f0, -0x4784($at)
    MEM_W(-0X4784, ctx->r1) = ctx->f0.u32l;
    // 0x801F4FE8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F4FEC: lwc1        $f16, -0x2D24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2D24);
    // 0x801F4FF0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x801F4FF4: nop

    // 0x801F4FF8: bc1f        L_801F500C
    if (!c1cs) {
        // 0x801F4FFC: nop
    
            goto L_801F500C;
    }
    // 0x801F4FFC: nop

    // 0x801F5000: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F5004: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F5008: swc1        $f18, -0x4784($at)
    MEM_W(-0X4784, ctx->r1) = ctx->f18.u32l;
L_801F500C:
    // 0x801F500C: jal         0x801CCE0C
    // 0x801F5010: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_8;
    // 0x801F5010: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x801F5014: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801F5018: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801F501C: jal         0x801CCE50
    // 0x801F5020: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_9;
    // 0x801F5020: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_9:
    // 0x801F5024: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F5028: jal         0x80032720
    // 0x801F502C: lwc1        $f12, -0x4784($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4784);
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_10;
    // 0x801F502C: lwc1        $f12, -0x4784($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4784);
    after_10:
    // 0x801F5030: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801F5034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F5038: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F503C: lwc1        $f12, -0x4784($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4784);
    // 0x801F5040: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801F5044: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801F5048: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801F504C: jal         0x80029280
    // 0x801F5050: sb          $t7, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_11;
    // 0x801F5050: sb          $t7, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r15;
    after_11:
    // 0x801F5054: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801F5058: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F505C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F5060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F5064: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801F5068: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F506C: addiu       $a3, $zero, 0xFE
    ctx->r7 = ADD32(0, 0XFE);
    // 0x801F5070: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801F5074: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x801F5078: jal         0x801CCE88
    // 0x801F507C: sb          $t9, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_12;
    // 0x801F507C: sb          $t9, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r25;
    after_12:
    // 0x801F5080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F5084: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801F5088: lb          $a2, 0x1C($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X1C);
    // 0x801F508C: jal         0x801CCEC8
    // 0x801F5090: lb          $a3, 0x1B($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X1B);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_13;
    // 0x801F5090: lb          $a3, 0x1B($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X1B);
    after_13:
    // 0x801F5094: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F5098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F509C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F50A0: jal         0x801CCE88
    // 0x801F50A4: addiu       $a3, $zero, 0xFE
    ctx->r7 = ADD32(0, 0XFE);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_14;
    // 0x801F50A4: addiu       $a3, $zero, 0xFE
    ctx->r7 = ADD32(0, 0XFE);
    after_14:
    // 0x801F50A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F50AC: lwc1        $f4, -0x4784($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4784);
    // 0x801F50B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F50B4: lwc1        $f6, -0x2D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2D20);
    // 0x801F50B8: jal         0x80032720
    // 0x801F50BC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_15;
    // 0x801F50BC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_15:
    // 0x801F50C0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801F50C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F50C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F50CC: lwc1        $f18, -0x4784($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4784);
    // 0x801F50D0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801F50D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F50D8: lwc1        $f4, -0x2D1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D1C);
    // 0x801F50DC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F50E0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801F50E4: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x801F50E8: jal         0x80029280
    // 0x801F50EC: sb          $t1, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_16;
    // 0x801F50EC: sb          $t1, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r9;
    after_16:
    // 0x801F50F0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801F50F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F50F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F50FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801F5100: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801F5104: lb          $a2, 0x1C($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X1C);
    // 0x801F5108: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801F510C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801F5110: nop

    // 0x801F5114: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801F5118: jal         0x801CCEC8
    // 0x801F511C: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_17;
    // 0x801F511C: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_17:
L_801F5120:
    // 0x801F5120: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F5124:
    // 0x801F5124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F5128: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F512C: jr          $ra
    // 0x801F5130: nop

    return;
    // 0x801F5130: nop

;}
RECOMP_FUNC void M25_FUN_801f5134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F5138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F513C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F5140: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F5144: jal         0x801CCE0C
    // 0x801F5148: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801F5148: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x801F514C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x801F5150: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x801F5154: jal         0x801CCE50
    // 0x801F5158: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801F5158: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    after_1:
    // 0x801F515C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F5160: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F5164: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F5168: addiu       $v0, $v0, -0x2BC4
    ctx->r2 = ADD32(ctx->r2, -0X2BC4);
    // 0x801F516C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F5170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F5174: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801F5178: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F517C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F5180: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801F5184: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F5188: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F518C: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F5190: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F5194: addiu       $t0, $t0, -0x2BBC
    ctx->r8 = ADD32(ctx->r8, -0X2BBC);
    // 0x801F5198: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F519C: addiu       $v1, $v1, -0x2BC0
    ctx->r3 = ADD32(ctx->r3, -0X2BC0);
    // 0x801F51A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F51A4: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F51A8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801F51AC: beq         $a1, $zero, L_801F51FC
    if (ctx->r5 == 0) {
        // 0x801F51B0: swc1        $f4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
            goto L_801F51FC;
    }
    // 0x801F51B0: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x801F51B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F51B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F51BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F51C0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F51C4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F51C8: nop

    // 0x801F51CC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F51D0: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F51D4: nop

    // 0x801F51D8: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F51DC: bne         $a1, $zero, L_801F51F4
    if (ctx->r5 != 0) {
        // 0x801F51E0: nop
    
            goto L_801F51F4;
    }
    // 0x801F51E0: nop

    // 0x801F51E4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F51E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F51EC: b           L_801F520C
    // 0x801F51F0: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F520C;
    // 0x801F51F0: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F51F4:
    // 0x801F51F4: b           L_801F520C
    // 0x801F51F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F520C;
    // 0x801F51F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801F51FC:
    // 0x801F51FC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F5200: nop

    // 0x801F5204: bltz        $a1, L_801F51F4
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F5208: nop
    
            goto L_801F51F4;
    }
    // 0x801F5208: nop

L_801F520C:
    // 0x801F520C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F5210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F5214: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F5218: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F521C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F5220: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F5224: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F5228: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F522C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F5230: nop

    // 0x801F5234: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F5238: beql        $a2, $zero, L_801F5288
    if (ctx->r6 == 0) {
        // 0x801F523C: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801F5288;
    }
    goto skip_0;
    // 0x801F523C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801F5240: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F5244: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F5248: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F524C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F5250: nop

    // 0x801F5254: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F5258: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F525C: nop

    // 0x801F5260: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F5264: bne         $a2, $zero, L_801F527C
    if (ctx->r6 != 0) {
        // 0x801F5268: nop
    
            goto L_801F527C;
    }
    // 0x801F5268: nop

    // 0x801F526C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F5270: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5274: b           L_801F5294
    // 0x801F5278: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F5294;
    // 0x801F5278: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F527C:
    // 0x801F527C: b           L_801F5294
    // 0x801F5280: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F5294;
    // 0x801F5280: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F5284: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801F5288:
    // 0x801F5288: nop

    // 0x801F528C: bltz        $a2, L_801F527C
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F5290: nop
    
            goto L_801F527C;
    }
    // 0x801F5290: nop

L_801F5294:
    // 0x801F5294: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F5298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F529C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F52A0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F52A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F52A8: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F52AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F52B0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F52B4: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F52B8: nop

    // 0x801F52BC: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F52C0: beql        $a3, $zero, L_801F5310
    if (ctx->r7 == 0) {
        // 0x801F52C4: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801F5310;
    }
    goto skip_1;
    // 0x801F52C4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801F52C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F52CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F52D0: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F52D4: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F52D8: nop

    // 0x801F52DC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F52E0: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F52E4: nop

    // 0x801F52E8: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F52EC: bne         $a3, $zero, L_801F5304
    if (ctx->r7 != 0) {
        // 0x801F52F0: nop
    
            goto L_801F5304;
    }
    // 0x801F52F0: nop

    // 0x801F52F4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801F52F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F52FC: b           L_801F531C
    // 0x801F5300: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F531C;
    // 0x801F5300: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F5304:
    // 0x801F5304: b           L_801F531C
    // 0x801F5308: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F531C;
    // 0x801F5308: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F530C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801F5310:
    // 0x801F5310: nop

    // 0x801F5314: bltz        $a3, L_801F5304
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F5318: nop
    
            goto L_801F5304;
    }
    // 0x801F5318: nop

L_801F531C:
    // 0x801F531C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F5320: jal         0x801CCE88
    // 0x801F5324: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801F5324: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_2:
    // 0x801F5328: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F532C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F5330: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x801F5334: jal         0x801CCEC8
    // 0x801F5338: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_3;
    // 0x801F5338: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801F533C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801F5340: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F5344: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F5348: addiu       $v0, $v0, -0x2BB8
    ctx->r2 = ADD32(ctx->r2, -0X2BB8);
    // 0x801F534C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F5350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F5354: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801F5358: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F535C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F5360: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F5364: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F5368: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F536C: addiu       $t0, $t0, -0x2BB0
    ctx->r8 = ADD32(ctx->r8, -0X2BB0);
    // 0x801F5370: addiu       $v1, $v1, -0x2BB4
    ctx->r3 = ADD32(ctx->r3, -0X2BB4);
    // 0x801F5374: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F5378: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F537C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F5380: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801F5384: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F5388: beq         $a1, $zero, L_801F53D4
    if (ctx->r5 == 0) {
        // 0x801F538C: swc1        $f0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
            goto L_801F53D4;
    }
    // 0x801F538C: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x801F5390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F5394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F5398: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F539C: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F53A0: nop

    // 0x801F53A4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F53A8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F53AC: nop

    // 0x801F53B0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F53B4: bne         $a1, $zero, L_801F53CC
    if (ctx->r5 != 0) {
        // 0x801F53B8: nop
    
            goto L_801F53CC;
    }
    // 0x801F53B8: nop

    // 0x801F53BC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F53C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F53C4: b           L_801F53E4
    // 0x801F53C8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F53E4;
    // 0x801F53C8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F53CC:
    // 0x801F53CC: b           L_801F53E4
    // 0x801F53D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F53E4;
    // 0x801F53D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801F53D4:
    // 0x801F53D4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F53D8: nop

    // 0x801F53DC: bltz        $a1, L_801F53CC
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F53E0: nop
    
            goto L_801F53CC;
    }
    // 0x801F53E0: nop

L_801F53E4:
    // 0x801F53E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F53E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F53EC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F53F0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F53F4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801F53F8: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F53FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F5400: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F5404: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F5408: nop

    // 0x801F540C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F5410: beql        $a2, $zero, L_801F5460
    if (ctx->r6 == 0) {
        // 0x801F5414: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801F5460;
    }
    goto skip_2;
    // 0x801F5414: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801F5418: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F541C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F5420: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F5424: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F5428: nop

    // 0x801F542C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F5430: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F5434: nop

    // 0x801F5438: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F543C: bne         $a2, $zero, L_801F5454
    if (ctx->r6 != 0) {
        // 0x801F5440: nop
    
            goto L_801F5454;
    }
    // 0x801F5440: nop

    // 0x801F5444: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F5448: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F544C: b           L_801F546C
    // 0x801F5450: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F546C;
    // 0x801F5450: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F5454:
    // 0x801F5454: b           L_801F546C
    // 0x801F5458: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F546C;
    // 0x801F5458: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F545C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801F5460:
    // 0x801F5460: nop

    // 0x801F5464: bltz        $a2, L_801F5454
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F5468: nop
    
            goto L_801F5454;
    }
    // 0x801F5468: nop

L_801F546C:
    // 0x801F546C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801F5470: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F5474: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F5478: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F547C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F5480: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F5484: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F5488: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F548C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F5490: nop

    // 0x801F5494: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F5498: beql        $a3, $zero, L_801F54E8
    if (ctx->r7 == 0) {
        // 0x801F549C: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801F54E8;
    }
    goto skip_3;
    // 0x801F549C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_3:
    // 0x801F54A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F54A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F54A8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F54AC: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F54B0: nop

    // 0x801F54B4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F54B8: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F54BC: nop

    // 0x801F54C0: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F54C4: bne         $a3, $zero, L_801F54DC
    if (ctx->r7 != 0) {
        // 0x801F54C8: nop
    
            goto L_801F54DC;
    }
    // 0x801F54C8: nop

    // 0x801F54CC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801F54D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F54D4: b           L_801F54F4
    // 0x801F54D8: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F54F4;
    // 0x801F54D8: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F54DC:
    // 0x801F54DC: b           L_801F54F4
    // 0x801F54E0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F54F4;
    // 0x801F54E0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F54E4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801F54E8:
    // 0x801F54E8: nop

    // 0x801F54EC: bltz        $a3, L_801F54DC
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F54F0: nop
    
            goto L_801F54DC;
    }
    // 0x801F54F0: nop

L_801F54F4:
    // 0x801F54F4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F54F8: jal         0x801CCE88
    // 0x801F54FC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_4;
    // 0x801F54FC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_4:
    // 0x801F5500: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F5504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F5508: addiu       $a2, $zero, -0x50
    ctx->r6 = ADD32(0, -0X50);
    // 0x801F550C: jal         0x801CCEC8
    // 0x801F5510: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_5;
    // 0x801F5510: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x801F5514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F5518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F551C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801F5520: jr          $ra
    // 0x801F5524: nop

    return;
    // 0x801F5524: nop

;}
RECOMP_FUNC void M25_FUN_801f5528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F552C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F5530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F5534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F5538: lui         $a1, 0x539
    ctx->r5 = S32(0X539 << 16);
    // 0x801F553C: ori         $a1, $a1, 0x2DB5
    ctx->r5 = ctx->r5 | 0X2DB5;
    // 0x801F5540: jal         0x801C0B8C
    // 0x801F5544: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F5544: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F5548: beq         $v0, $zero, L_801F5558
    if (ctx->r2 == 0) {
        // 0x801F554C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F5558;
    }
    // 0x801F554C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F5550: b           L_801F57A8
    // 0x801F5554: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801F57A8;
    // 0x801F5554: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F5558:
    // 0x801F5558: lui         $a1, 0x4EC
    ctx->r5 = S32(0X4EC << 16);
    // 0x801F555C: jal         0x801C0B8C
    // 0x801F5560: ori         $a1, $a1, 0xE275
    ctx->r5 = ctx->r5 | 0XE275;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F5560: ori         $a1, $a1, 0xE275
    ctx->r5 = ctx->r5 | 0XE275;
    after_1:
    // 0x801F5564: beql        $v0, $zero, L_801F57A8
    if (ctx->r2 == 0) {
        // 0x801F5568: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_801F57A8;
    }
    goto skip_0;
    // 0x801F5568: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_0:
    // 0x801F556C: jal         0x801C0B2C
    // 0x801F5570: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801F5570: nop

    after_2:
    // 0x801F5574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F5578: jal         0x80034C24
    // 0x801F557C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801F557C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801F5580: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F5584: ldc1        $f4, -0x2D18($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D18);
    // 0x801F5588: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F558C: ldc1        $f8, -0x2D10($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2D10);
    // 0x801F5590: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F5594: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801F5598: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F559C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F55A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F55A4: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F55A8: addiu       $v0, $v0, -0x2BB8
    ctx->r2 = ADD32(ctx->r2, -0X2BB8);
    // 0x801F55AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F55B0: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801F55B4: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801F55B8: addiu       $t0, $t0, -0x2BB0
    ctx->r8 = ADD32(ctx->r8, -0X2BB0);
    // 0x801F55BC: addiu       $v1, $v1, -0x2BB4
    ctx->r3 = ADD32(ctx->r3, -0X2BB4);
    // 0x801F55C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F55C4: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F55C8: ldc1        $f8, -0x2D08($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2D08);
    // 0x801F55CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F55D0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F55D4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F55D8: ldc1        $f16, -0x2D00($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2D00);
    // 0x801F55DC: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F55E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F55E4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801F55E8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F55EC: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x801F55F0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x801F55F4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F55F8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F55FC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F5600: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x801F5604: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
    // 0x801F5608: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F560C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F5610: nop

    // 0x801F5614: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F5618: beql        $a1, $zero, L_801F5668
    if (ctx->r5 == 0) {
        // 0x801F561C: mfc1        $a1, $f6
        ctx->r5 = (int32_t)ctx->f6.u32l;
            goto L_801F5668;
    }
    goto skip_1;
    // 0x801F561C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x801F5620: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F5624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F5628: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801F562C: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F5630: nop

    // 0x801F5634: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F5638: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F563C: nop

    // 0x801F5640: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F5644: bne         $a1, $zero, L_801F565C
    if (ctx->r5 != 0) {
        // 0x801F5648: nop
    
            goto L_801F565C;
    }
    // 0x801F5648: nop

    // 0x801F564C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801F5650: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5654: b           L_801F5674
    // 0x801F5658: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F5674;
    // 0x801F5658: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F565C:
    // 0x801F565C: b           L_801F5674
    // 0x801F5660: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F5674;
    // 0x801F5660: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F5664: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
L_801F5668:
    // 0x801F5668: nop

    // 0x801F566C: bltz        $a1, L_801F565C
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F5670: nop
    
            goto L_801F565C;
    }
    // 0x801F5670: nop

L_801F5674:
    // 0x801F5674: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F5678: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F567C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F5680: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F5684: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F5688: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F568C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F5690: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F5694: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F5698: nop

    // 0x801F569C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F56A0: beql        $a2, $zero, L_801F56F0
    if (ctx->r6 == 0) {
        // 0x801F56A4: mfc1        $a2, $f10
        ctx->r6 = (int32_t)ctx->f10.u32l;
            goto L_801F56F0;
    }
    goto skip_2;
    // 0x801F56A4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x801F56A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F56AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F56B0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801F56B4: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F56B8: nop

    // 0x801F56BC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F56C0: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F56C4: nop

    // 0x801F56C8: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F56CC: bne         $a2, $zero, L_801F56E4
    if (ctx->r6 != 0) {
        // 0x801F56D0: nop
    
            goto L_801F56E4;
    }
    // 0x801F56D0: nop

    // 0x801F56D4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801F56D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F56DC: b           L_801F56FC
    // 0x801F56E0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F56FC;
    // 0x801F56E0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F56E4:
    // 0x801F56E4: b           L_801F56FC
    // 0x801F56E8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F56FC;
    // 0x801F56E8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F56EC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
L_801F56F0:
    // 0x801F56F0: nop

    // 0x801F56F4: bltz        $a2, L_801F56E4
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F56F8: nop
    
            goto L_801F56E4;
    }
    // 0x801F56F8: nop

L_801F56FC:
    // 0x801F56FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F5700: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F5704: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801F5708: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F570C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F5710: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F5714: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F5718: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F571C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F5720: nop

    // 0x801F5724: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F5728: beql        $a3, $zero, L_801F5778
    if (ctx->r7 == 0) {
        // 0x801F572C: mfc1        $a3, $f18
        ctx->r7 = (int32_t)ctx->f18.u32l;
            goto L_801F5778;
    }
    goto skip_3;
    // 0x801F572C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x801F5730: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F5734: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F5738: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801F573C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F5740: nop

    // 0x801F5744: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F5748: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F574C: nop

    // 0x801F5750: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F5754: bne         $a3, $zero, L_801F576C
    if (ctx->r7 != 0) {
        // 0x801F5758: nop
    
            goto L_801F576C;
    }
    // 0x801F5758: nop

    // 0x801F575C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801F5760: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5764: b           L_801F5784
    // 0x801F5768: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F5784;
    // 0x801F5768: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F576C:
    // 0x801F576C: b           L_801F5784
    // 0x801F5770: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F5784;
    // 0x801F5770: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F5774: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
L_801F5778:
    // 0x801F5778: nop

    // 0x801F577C: bltz        $a3, L_801F576C
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F5780: nop
    
            goto L_801F576C;
    }
    // 0x801F5780: nop

L_801F5784:
    // 0x801F5784: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F5788: jal         0x801CCE88
    // 0x801F578C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_4;
    // 0x801F578C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_4:
    // 0x801F5790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F5794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F5798: addiu       $a2, $zero, -0x50
    ctx->r6 = ADD32(0, -0X50);
    // 0x801F579C: jal         0x801CCEC8
    // 0x801F57A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_5;
    // 0x801F57A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x801F57A4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F57A8:
    // 0x801F57A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F57AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F57B0: jr          $ra
    // 0x801F57B4: nop

    return;
    // 0x801F57B4: nop

;}
RECOMP_FUNC void M25_FUN_801f57b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F57B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F57BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F57C0: jr          $ra
    // 0x801F57C4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x801F57C4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f57c8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f57c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F57C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F57CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F57D0: jr          $ra
    // 0x801F57D4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x801F57D4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f57d8(rdram, ctx);
;}
