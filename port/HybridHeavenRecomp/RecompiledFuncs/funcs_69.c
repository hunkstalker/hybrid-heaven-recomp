#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801f57d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F57D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F57DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F57E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F57E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F57E8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F57EC: addiu       $a1, $a1, -0x2270
    ctx->r5 = ADD32(ctx->r5, -0X2270);
    // 0x801F57F0: jal         0x801C2420
    // 0x801F57F4: addiu       $a0, $zero, 0x263
    ctx->r4 = ADD32(0, 0X263);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801F57F4: addiu       $a0, $zero, 0x263
    ctx->r4 = ADD32(0, 0X263);
    after_0:
    // 0x801F57F8: jal         0x8038BA70
    // 0x801F57FC: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_1;
    // 0x801F57FC: nop

    after_1:
    // 0x801F5800: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F5804: addiu       $a1, $a1, -0x2258
    ctx->r5 = ADD32(ctx->r5, -0X2258);
    // 0x801F5808: jal         0x801C2420
    // 0x801F580C: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_2;
    // 0x801F580C: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    after_2:
    // 0x801F5810: jal         0x8038BA70
    // 0x801F5814: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_3;
    // 0x801F5814: nop

    after_3:
    // 0x801F5818: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F581C: addiu       $a1, $a1, -0x2240
    ctx->r5 = ADD32(ctx->r5, -0X2240);
    // 0x801F5820: jal         0x801C2420
    // 0x801F5824: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_4;
    // 0x801F5824: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    after_4:
    // 0x801F5828: jal         0x8038BA70
    // 0x801F582C: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_5;
    // 0x801F582C: nop

    after_5:
    // 0x801F5830: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F5834: addiu       $a1, $a1, -0x2228
    ctx->r5 = ADD32(ctx->r5, -0X2228);
    // 0x801F5838: jal         0x801C2420
    // 0x801F583C: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_6;
    // 0x801F583C: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    after_6:
    // 0x801F5840: jal         0x8038BA70
    // 0x801F5844: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_7;
    // 0x801F5844: nop

    after_7:
    // 0x801F5848: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F584C: addiu       $a1, $a1, -0x2210
    ctx->r5 = ADD32(ctx->r5, -0X2210);
    // 0x801F5850: jal         0x801C2420
    // 0x801F5854: addiu       $a0, $zero, 0x268
    ctx->r4 = ADD32(0, 0X268);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_8;
    // 0x801F5854: addiu       $a0, $zero, 0x268
    ctx->r4 = ADD32(0, 0X268);
    after_8:
    // 0x801F5858: jal         0x8038BA70
    // 0x801F585C: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_9;
    // 0x801F585C: nop

    after_9:
    // 0x801F5860: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F5864: addiu       $a1, $a1, -0x21F8
    ctx->r5 = ADD32(ctx->r5, -0X21F8);
    // 0x801F5868: jal         0x801C2420
    // 0x801F586C: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_10;
    // 0x801F586C: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    after_10:
    // 0x801F5870: jal         0x8038BA70
    // 0x801F5874: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_11;
    // 0x801F5874: nop

    after_11:
    // 0x801F5878: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F587C: addiu       $a1, $a1, -0x21E0
    ctx->r5 = ADD32(ctx->r5, -0X21E0);
    // 0x801F5880: jal         0x801C2420
    // 0x801F5884: addiu       $a0, $zero, 0x265
    ctx->r4 = ADD32(0, 0X265);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_12;
    // 0x801F5884: addiu       $a0, $zero, 0x265
    ctx->r4 = ADD32(0, 0X265);
    after_12:
    // 0x801F5888: jal         0x8038BA70
    // 0x801F588C: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_13;
    // 0x801F588C: nop

    after_13:
    // 0x801F5890: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F5894: addiu       $a1, $a1, -0x21C8
    ctx->r5 = ADD32(ctx->r5, -0X21C8);
    // 0x801F5898: jal         0x801C2420
    // 0x801F589C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_14;
    // 0x801F589C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_14:
    // 0x801F58A0: jal         0x8038BA70
    // 0x801F58A4: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_15;
    // 0x801F58A4: nop

    after_15:
    // 0x801F58A8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F58AC: addiu       $a1, $a1, -0x21B0
    ctx->r5 = ADD32(ctx->r5, -0X21B0);
    // 0x801F58B0: jal         0x801C2420
    // 0x801F58B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_16;
    // 0x801F58B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x801F58B8: jal         0x8038BA70
    // 0x801F58BC: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_17;
    // 0x801F58BC: nop

    after_17:
    // 0x801F58C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F58C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F58C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F58CC: jr          $ra
    // 0x801F58D0: nop

    return;
    // 0x801F58D0: nop

;}
RECOMP_FUNC void M25_FUN_801f58d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F58D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F58D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801F58DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801F58E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801F58E4: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x801F58E8: lui         $s2, 0x8039
    ctx->r18 = S32(0X8039 << 16);
    // 0x801F58EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F58F0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801F58F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801F58F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F58FC: addiu       $s2, $s2, -0x2734
    ctx->r18 = ADD32(ctx->r18, -0X2734);
    // 0x801F5900: addiu       $s1, $s1, -0x2774
    ctx->r17 = ADD32(ctx->r17, -0X2774);
    // 0x801F5904: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801F5908: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_801F590C:
    // 0x801F590C: jal         0x80005E44
    // 0x801F5910: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801F5910: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x801F5914: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801F5918: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x801F591C: bnel        $at, $zero, L_801F590C
    if (ctx->r1 != 0) {
        // 0x801F5920: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_801F590C;
    }
    goto skip_0;
    // 0x801F5920: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x801F5924: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801F5928: addiu       $a1, $a1, -0x2754
    ctx->r5 = ADD32(ctx->r5, -0X2754);
    // 0x801F592C: jal         0x80005E44
    // 0x801F5930: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x801F5930: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x801F5934: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F5938: jal         0x80005E44
    // 0x801F593C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801F593C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x801F5940: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F5944: jal         0x80005E44
    // 0x801F5948: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_3;
    // 0x801F5948: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x801F594C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801F5950: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x801F5954: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_801F5958:
    // 0x801F5958: jal         0x80005E44
    // 0x801F595C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_4;
    // 0x801F595C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x801F5960: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801F5964: bnel        $s0, $s3, L_801F5958
    if (ctx->r16 != ctx->r19) {
        // 0x801F5968: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_801F5958;
    }
    goto skip_1;
    // 0x801F5968: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x801F596C: jal         0x80006214
    // 0x801F5970: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801F5970: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_5:
    // 0x801F5974: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F5978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F597C: addiu       $a2, $zero, 0x263
    ctx->r6 = ADD32(0, 0X263);
    // 0x801F5980: jal         0x8012C89C
    // 0x801F5984: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x801F5984: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x801F5988: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F598C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F5990: addiu       $a2, $zero, 0x264
    ctx->r6 = ADD32(0, 0X264);
    // 0x801F5994: jal         0x8012C89C
    // 0x801F5998: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_7;
    // 0x801F5998: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x801F599C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F59A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801F59A4: addiu       $a2, $zero, 0x266
    ctx->r6 = ADD32(0, 0X266);
    // 0x801F59A8: jal         0x8012C89C
    // 0x801F59AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_8;
    // 0x801F59AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x801F59B0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F59B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801F59B8: addiu       $a2, $zero, 0x267
    ctx->r6 = ADD32(0, 0X267);
    // 0x801F59BC: jal         0x8012C89C
    // 0x801F59C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_9;
    // 0x801F59C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x801F59C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F59C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801F59CC: addiu       $a2, $zero, 0x268
    ctx->r6 = ADD32(0, 0X268);
    // 0x801F59D0: jal         0x8012C89C
    // 0x801F59D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_10;
    // 0x801F59D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x801F59D8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F59DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x801F59E0: addiu       $a2, $zero, 0x269
    ctx->r6 = ADD32(0, 0X269);
    // 0x801F59E4: jal         0x8012C89C
    // 0x801F59E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_11;
    // 0x801F59E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x801F59EC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F59F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801F59F4: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x801F59F8: jal         0x8012C89C
    // 0x801F59FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_12;
    // 0x801F59FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x801F5A00: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801F5A04: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x801F5A08: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x801F5A0C: jal         0x8012C89C
    // 0x801F5A10: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_13;
    // 0x801F5A10: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_13:
    // 0x801F5A14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801F5A18: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_801F5A1C:
    // 0x801F5A1C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x801F5A20: addiu       $a2, $zero, 0x265
    ctx->r6 = ADD32(0, 0X265);
    // 0x801F5A24: jal         0x8012C89C
    // 0x801F5A28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_14;
    // 0x801F5A28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x801F5A2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801F5A30: bnel        $s0, $s3, L_801F5A1C
    if (ctx->r16 != ctx->r19) {
        // 0x801F5A34: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_801F5A1C;
    }
    goto skip_2;
    // 0x801F5A34: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_2:
    // 0x801F5A38: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x801F5A3C: addiu       $v0, $v0, -0x2730
    ctx->r2 = ADD32(ctx->r2, -0X2730);
    // 0x801F5A40: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5A44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F5A48: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F5A4C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801F5A50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801F5A54: lui         $a0, 0x4000
    ctx->r4 = S32(0X4000 << 16);
    // 0x801F5A58: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F5A5C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801F5A60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801F5A64: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801F5A68: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F5A6C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801F5A70: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F5A74: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801F5A78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801F5A7C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F5A80: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801F5A84: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F5A88: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801F5A8C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F5A90: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801F5A94: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F5A98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801F5A9C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F5AA0: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801F5AA4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F5AA8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801F5AAC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F5AB0: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x801F5AB4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5AB8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801F5ABC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F5AC0: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x801F5AC4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5AC8: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801F5ACC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801F5AD0: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x801F5AD4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5AD8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801F5ADC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F5AE0: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801F5AE4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5AE8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F5AEC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F5AF0: swc1        $f2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f2.u32l;
    // 0x801F5AF4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801F5AF8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F5AFC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F5B00: swc1        $f0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f0.u32l;
    // 0x801F5B04: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B08: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F5B0C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F5B10: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x801F5B14: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B18: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F5B1C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F5B20: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801F5B24: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B28: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801F5B2C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F5B30: swc1        $f0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f0.u32l;
    // 0x801F5B34: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B38: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801F5B3C: addiu       $t4, $t4, -0x6FC0
    ctx->r12 = ADD32(ctx->r12, -0X6FC0);
    // 0x801F5B40: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801F5B44: or          $t5, $t4, $a0
    ctx->r13 = ctx->r12 | ctx->r4;
    // 0x801F5B48: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F5B4C: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x801F5B50: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B54: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x801F5B58: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F5B5C: swc1        $f0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f0.u32l;
    // 0x801F5B60: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B64: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801F5B68: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F5B6C: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801F5B70: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B74: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801F5B78: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F5B7C: sw          $t5, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r13;
    // 0x801F5B80: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B84: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801F5B88: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F5B8C: sw          $a1, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r5;
    // 0x801F5B90: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F5B94: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801F5B98: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F5B9C: sb          $zero, 0x48($t4)
    MEM_B(0X48, ctx->r12) = 0;
    // 0x801F5BA0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5BA4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801F5BA8: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x801F5BAC: sb          $zero, 0x49($t5)
    MEM_B(0X49, ctx->r13) = 0;
    // 0x801F5BB0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F5BB4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x801F5BB8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F5BBC: sb          $zero, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = 0;
    // 0x801F5BC0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5BC4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801F5BC8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F5BCC: sb          $a3, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r7;
    // 0x801F5BD0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5BD4: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x801F5BD8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F5BDC: swc1        $f2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f2.u32l;
    // 0x801F5BE0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F5BE4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801F5BE8: addiu       $t7, $t7, -0x6F80
    ctx->r15 = ADD32(ctx->r15, -0X6F80);
    // 0x801F5BEC: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x801F5BF0: or          $t5, $t7, $a0
    ctx->r13 = ctx->r15 | ctx->r4;
    // 0x801F5BF4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F5BF8: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x801F5BFC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C00: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x801F5C04: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F5C08: swc1        $f0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f0.u32l;
    // 0x801F5C0C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C10: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x801F5C14: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801F5C18: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    // 0x801F5C1C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C20: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801F5C24: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F5C28: sw          $t5, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r13;
    // 0x801F5C2C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C30: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x801F5C34: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F5C38: sw          $a1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r5;
    // 0x801F5C3C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C40: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x801F5C44: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F5C48: sb          $zero, 0x48($t7)
    MEM_B(0X48, ctx->r15) = 0;
    // 0x801F5C4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C50: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801F5C54: lw          $t5, 0x30($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X30);
    // 0x801F5C58: sb          $zero, 0x49($t5)
    MEM_B(0X49, ctx->r13) = 0;
    // 0x801F5C5C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C60: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x801F5C64: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F5C68: sb          $zero, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = 0;
    // 0x801F5C6C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C70: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x801F5C74: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801F5C78: sb          $a3, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r7;
    // 0x801F5C7C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C80: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801F5C84: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F5C88: swc1        $f2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f2.u32l;
    // 0x801F5C8C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F5C90: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801F5C94: addiu       $t9, $t9, -0x6F48
    ctx->r25 = ADD32(ctx->r25, -0X6F48);
    // 0x801F5C98: lw          $t0, 0x14($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X14);
    // 0x801F5C9C: or          $t5, $t9, $a0
    ctx->r13 = ctx->r25 | ctx->r4;
    // 0x801F5CA0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x801F5CA4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F5CA8: swc1        $f12, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f12.u32l;
    // 0x801F5CAC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F5CB0: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x801F5CB4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F5CB8: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801F5CBC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5CC0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801F5CC4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F5CC8: addiu       $t7, $zero, 0x42
    ctx->r15 = ADD32(0, 0X42);
    // 0x801F5CCC: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x801F5CD0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5CD4: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x801F5CD8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F5CDC: addiu       $t1, $zero, 0xDE
    ctx->r9 = ADD32(0, 0XDE);
    // 0x801F5CE0: sw          $t5, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r13;
    // 0x801F5CE4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801F5CE8: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x801F5CEC: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801F5CF0: addiu       $t4, $zero, 0xF8
    ctx->r12 = ADD32(0, 0XF8);
    // 0x801F5CF4: sw          $a1, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r5;
    // 0x801F5CF8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F5CFC: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x801F5D00: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F5D04: sb          $t7, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r15;
    // 0x801F5D08: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D0C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801F5D10: lw          $t2, 0x14($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X14);
    // 0x801F5D14: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F5D18: sb          $t1, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r9;
    // 0x801F5D1C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D20: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x801F5D24: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F5D28: sb          $t4, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r12;
    // 0x801F5D2C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D30: lw          $t5, 0x14($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X14);
    // 0x801F5D34: lw          $t2, 0x30($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X30);
    // 0x801F5D38: sb          $t7, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r15;
    // 0x801F5D3C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D40: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x801F5D44: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x801F5D48: swc1        $f2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f2.u32l;
    // 0x801F5D4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D50: lw          $t4, 0x18($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X18);
    // 0x801F5D54: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801F5D58: swc1        $f12, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f12.u32l;
    // 0x801F5D5C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D60: lw          $t5, 0x18($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X18);
    // 0x801F5D64: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801F5D68: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801F5D6C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D70: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x801F5D74: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801F5D78: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801F5D7C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D80: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x801F5D84: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x801F5D88: swc1        $f2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f2.u32l;
    // 0x801F5D8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F5D90: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x801F5D94: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801F5D98: swc1        $f12, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f12.u32l;
    // 0x801F5D9C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5DA0: lw          $t2, 0x1C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X1C);
    // 0x801F5DA4: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x801F5DA8: swc1        $f0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f0.u32l;
    // 0x801F5DAC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801F5DB0: lw          $t6, 0x1C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1C);
    // 0x801F5DB4: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801F5DB8: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x801F5DBC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5DC0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x801F5DC4: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F5DC8: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x801F5DCC: beq         $v1, $a0, L_801F5F1C
    if (ctx->r3 == ctx->r4) {
        // 0x801F5DD0: lw          $t5, 0x30($t0)
        ctx->r13 = MEM_W(ctx->r8, 0X30);
            goto L_801F5F1C;
    }
    // 0x801F5DD0: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
L_801F5DD4:
    // 0x801F5DD4: swc1        $f2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f2.u32l;
    // 0x801F5DD8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5DDC: addu        $t2, $t7, $v1
    ctx->r10 = ADD32(ctx->r15, ctx->r3);
    // 0x801F5DE0: lw          $t1, 0x20($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X20);
    // 0x801F5DE4: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801F5DE8: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x801F5DEC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5DF0: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x801F5DF4: lw          $t4, 0x20($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X20);
    // 0x801F5DF8: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801F5DFC: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801F5E00: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E04: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x801F5E08: lw          $t7, 0x20($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X20);
    // 0x801F5E0C: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x801F5E10: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    // 0x801F5E14: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E18: addu        $t3, $t1, $v1
    ctx->r11 = ADD32(ctx->r9, ctx->r3);
    // 0x801F5E1C: lw          $t6, 0x24($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X24);
    // 0x801F5E20: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801F5E24: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
    // 0x801F5E28: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E2C: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F5E30: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F5E34: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801F5E38: swc1        $f0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f0.u32l;
    // 0x801F5E3C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E40: addu        $t2, $t7, $v1
    ctx->r10 = ADD32(ctx->r15, ctx->r3);
    // 0x801F5E44: lw          $t1, 0x24($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X24);
    // 0x801F5E48: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801F5E4C: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x801F5E50: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E54: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x801F5E58: lw          $t4, 0x24($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X24);
    // 0x801F5E5C: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801F5E60: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801F5E64: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E68: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x801F5E6C: lw          $t7, 0x28($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X28);
    // 0x801F5E70: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x801F5E74: swc1        $f2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f2.u32l;
    // 0x801F5E78: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E7C: addu        $t3, $t1, $v1
    ctx->r11 = ADD32(ctx->r9, ctx->r3);
    // 0x801F5E80: lw          $t6, 0x28($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X28);
    // 0x801F5E84: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801F5E88: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x801F5E8C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5E90: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F5E94: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x801F5E98: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801F5E9C: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x801F5EA0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5EA4: addu        $t2, $t7, $v1
    ctx->r10 = ADD32(ctx->r15, ctx->r3);
    // 0x801F5EA8: lw          $t1, 0x28($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X28);
    // 0x801F5EAC: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801F5EB0: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801F5EB4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5EB8: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x801F5EBC: lw          $t4, 0x2C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X2C);
    // 0x801F5EC0: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801F5EC4: swc1        $f2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f2.u32l;
    // 0x801F5EC8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5ECC: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x801F5ED0: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801F5ED4: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x801F5ED8: swc1        $f0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f0.u32l;
    // 0x801F5EDC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5EE0: addu        $t3, $t1, $v1
    ctx->r11 = ADD32(ctx->r9, ctx->r3);
    // 0x801F5EE4: lw          $t6, 0x2C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X2C);
    // 0x801F5EE8: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801F5EEC: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x801F5EF0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5EF4: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F5EF8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F5EFC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801F5F00: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801F5F04: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x801F5F08: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5F0C: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F5F10: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x801F5F14: bne         $v1, $a0, L_801F5DD4
    if (ctx->r3 != ctx->r4) {
        // 0x801F5F18: lw          $t5, 0x30($t0)
        ctx->r13 = MEM_W(ctx->r8, 0X30);
            goto L_801F5DD4;
    }
    // 0x801F5F18: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
L_801F5F1C:
    // 0x801F5F1C: swc1        $f2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f2.u32l;
    // 0x801F5F20: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5F24: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801F5F28: addu        $t2, $t7, $v1
    ctx->r10 = ADD32(ctx->r15, ctx->r3);
    // 0x801F5F2C: lw          $t1, 0x20($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X20);
    // 0x801F5F30: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801F5F34: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x801F5F38: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5F3C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x801F5F40: lw          $t4, 0x20($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X20);
    // 0x801F5F44: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801F5F48: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801F5F4C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5F50: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x801F5F54: lw          $t7, 0x20($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X20);
    // 0x801F5F58: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x801F5F5C: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    // 0x801F5F60: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5F64: addu        $t3, $t1, $v1
    ctx->r11 = ADD32(ctx->r9, ctx->r3);
    // 0x801F5F68: lw          $t6, 0x24($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X24);
    // 0x801F5F6C: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801F5F70: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
    // 0x801F5F74: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5F78: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F5F7C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F5F80: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801F5F84: swc1        $f0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f0.u32l;
    // 0x801F5F88: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5F8C: addu        $t2, $t7, $v1
    ctx->r10 = ADD32(ctx->r15, ctx->r3);
    // 0x801F5F90: lw          $t1, 0x24($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X24);
    // 0x801F5F94: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801F5F98: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x801F5F9C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F5FA0: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x801F5FA4: lw          $t4, 0x24($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X24);
    // 0x801F5FA8: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801F5FAC: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801F5FB0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F5FB4: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x801F5FB8: lw          $t7, 0x28($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X28);
    // 0x801F5FBC: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x801F5FC0: swc1        $f2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f2.u32l;
    // 0x801F5FC4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F5FC8: addu        $t3, $t1, $v1
    ctx->r11 = ADD32(ctx->r9, ctx->r3);
    // 0x801F5FCC: lw          $t6, 0x28($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X28);
    // 0x801F5FD0: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801F5FD4: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x801F5FD8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F5FDC: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F5FE0: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x801F5FE4: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801F5FE8: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x801F5FEC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F5FF0: addu        $t2, $t7, $v1
    ctx->r10 = ADD32(ctx->r15, ctx->r3);
    // 0x801F5FF4: lw          $t1, 0x28($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X28);
    // 0x801F5FF8: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801F5FFC: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801F6000: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F6004: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x801F6008: lw          $t4, 0x2C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X2C);
    // 0x801F600C: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801F6010: swc1        $f2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f2.u32l;
    // 0x801F6014: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F6018: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x801F601C: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801F6020: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x801F6024: swc1        $f0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f0.u32l;
    // 0x801F6028: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F602C: addu        $t3, $t1, $v1
    ctx->r11 = ADD32(ctx->r9, ctx->r3);
    // 0x801F6030: lw          $t6, 0x2C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X2C);
    // 0x801F6034: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801F6038: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x801F603C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F6040: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x801F6044: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F6048: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801F604C: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801F6050: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x801F6054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F6058: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801F605C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801F6060: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801F6064: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801F6068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F606C: jr          $ra
    // 0x801F6070: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801F6070: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6074(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6078: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F607C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6084: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801F6088: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    // 0x801F608C: jal         0x801C0B8C
    // 0x801F6090: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6090: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F6094: beq         $v0, $zero, L_801F60BC
    if (ctx->r2 == 0) {
        // 0x801F6098: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_801F60BC;
    }
    // 0x801F6098: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801F609C: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801F60A0: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F60A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F60A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801F60AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801F60B0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F60B4: b           L_801F60C0
    // 0x801F60B8: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
        goto L_801F60C0;
    // 0x801F60B8: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
L_801F60BC:
    // 0x801F60BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F60C0:
    // 0x801F60C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F60C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F60C8: jr          $ra
    // 0x801F60CC: nop

    return;
    // 0x801F60CC: nop

;}
RECOMP_FUNC void M25_FUN_801f60d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F60D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F60D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F60D8: jr          $ra
    // 0x801F60DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801F60DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f60e0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f60e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F60E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F60E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F60E8: jr          $ra
    // 0x801F60EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F60EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f60f0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f60f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F60F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F60F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F60F8: jr          $ra
    // 0x801F60FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F60FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6100(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6100: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F6104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6108: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F610C: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F6110: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F6114: jal         0x801BF628
    // 0x801F6118: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F6118: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F611C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F6120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F6124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F6128: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F612C: bne         $at, $zero, L_801F613C
    if (ctx->r1 != 0) {
        // 0x801F6130: nop
    
            goto L_801F613C;
    }
    // 0x801F6130: nop

    // 0x801F6134: b           L_801F613C
    // 0x801F6138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F613C;
    // 0x801F6138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F613C:
    // 0x801F613C: jr          $ra
    // 0x801F6140: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F6140: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6144(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6144: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6148: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F614C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F6150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F6154: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6158: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801F615C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F6160: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F6164: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F6168: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801F616C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F6170: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801F6174: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F6178: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801F617C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F6180: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801F6184: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F6188: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801F618C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F6190: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801F6194: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F6198: jr          $ra
    // 0x801F619C: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    return;
    // 0x801F619C: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f61a0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f61a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F61A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F61A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F61A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F61AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F61B0: lui         $a1, 0x17E
    ctx->r5 = S32(0X17E << 16);
    // 0x801F61B4: ori         $a1, $a1, 0xFEDF
    ctx->r5 = ctx->r5 | 0XFEDF;
    // 0x801F61B8: jal         0x801C0B8C
    // 0x801F61BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F61BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F61C0: beq         $v0, $zero, L_801F621C
    if (ctx->r2 == 0) {
        // 0x801F61C4: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_801F621C;
    }
    // 0x801F61C4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801F61C8: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801F61CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F61D0: lwc1        $f6, -0x2CF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2CF8);
    // 0x801F61D4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801F61D8: lui         $a1, 0x1BC
    ctx->r5 = S32(0X1BC << 16);
    // 0x801F61DC: ori         $a1, $a1, 0x7DF
    ctx->r5 = ctx->r5 | 0X7DF;
    // 0x801F61E0: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801F61E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F61E8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F61EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F61F0: jal         0x801C0B8C
    // 0x801F61F4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F61F4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    after_1:
    // 0x801F61F8: beq         $v0, $zero, L_801F621C
    if (ctx->r2 == 0) {
        // 0x801F61FC: lui         $t8, 0x8039
        ctx->r24 = S32(0X8039 << 16);
            goto L_801F621C;
    }
    // 0x801F61FC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801F6200: lw          $t8, -0x2730($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2730);
    // 0x801F6204: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F6208: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801F620C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801F6210: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F6214: b           L_801F6220
    // 0x801F6218: swc1        $f10, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f10.u32l;
        goto L_801F6220;
    // 0x801F6218: swc1        $f10, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f10.u32l;
L_801F621C:
    // 0x801F621C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F6220:
    // 0x801F6220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F6224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F6228: jr          $ra
    // 0x801F622C: nop

    return;
    // 0x801F622C: nop

;}
RECOMP_FUNC void M25_FUN_801f6230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6234: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801F6238: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801F623C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6244: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F6248: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801F624C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6250: lwc1        $f6, -0x2CF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2CF4);
    // 0x801F6254: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801F6258: lui         $a1, 0x1DA
    ctx->r5 = S32(0X1DA << 16);
    // 0x801F625C: ori         $a1, $a1, 0x8C5F
    ctx->r5 = ctx->r5 | 0X8C5F;
    // 0x801F6260: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F6264: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F6268: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F626C: jal         0x801C0B8C
    // 0x801F6270: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6270: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x801F6274: beq         $v0, $zero, L_801F629C
    if (ctx->r2 == 0) {
        // 0x801F6278: lui         $t8, 0x8039
        ctx->r24 = S32(0X8039 << 16);
            goto L_801F629C;
    }
    // 0x801F6278: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801F627C: lw          $t8, -0x2730($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2730);
    // 0x801F6280: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801F6284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F6288: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801F628C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801F6290: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F6294: b           L_801F62A0
    // 0x801F6298: swc1        $f10, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f10.u32l;
        goto L_801F62A0;
    // 0x801F6298: swc1        $f10, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f10.u32l;
L_801F629C:
    // 0x801F629C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F62A0:
    // 0x801F62A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F62A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F62A8: jr          $ra
    // 0x801F62AC: nop

    return;
    // 0x801F62AC: nop

;}
RECOMP_FUNC void M25_FUN_801f62b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F62B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F62B4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801F62B8: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801F62BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F62C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F62C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F62C8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801F62CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F62D0: lwc1        $f6, -0x2CF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2CF0);
    // 0x801F62D4: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801F62D8: lui         $a1, 0x208
    ctx->r5 = S32(0X208 << 16);
    // 0x801F62DC: ori         $a1, $a1, 0x531F
    ctx->r5 = ctx->r5 | 0X531F;
    // 0x801F62E0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F62E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F62E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F62EC: jal         0x801C0B8C
    // 0x801F62F0: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F62F0: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x801F62F4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F62F8: beq         $v0, $zero, L_801F6334
    if (ctx->r2 == 0) {
        // 0x801F62FC: addiu       $v1, $v1, -0x2730
        ctx->r3 = ADD32(ctx->r3, -0X2730);
            goto L_801F6334;
    }
    // 0x801F62FC: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F6300: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F6304: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F6308: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F630C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801F6310: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F6314: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801F6318: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F631C: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x801F6320: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801F6324: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801F6328: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F632C: b           L_801F6338
    // 0x801F6330: swc1        $f16, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f16.u32l;
        goto L_801F6338;
    // 0x801F6330: swc1        $f16, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f16.u32l;
L_801F6334:
    // 0x801F6334: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F6338:
    // 0x801F6338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F633C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F6340: jr          $ra
    // 0x801F6344: nop

    return;
    // 0x801F6344: nop

;}
RECOMP_FUNC void M25_FUN_801f6348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6348: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F634C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6350: jr          $ra
    // 0x801F6354: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F6354: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6358(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6358: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F635C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6360: jr          $ra
    // 0x801F6364: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x801F6364: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6368(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F636C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6370: jr          $ra
    // 0x801F6374: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801F6374: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6378(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6378: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F637C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6380: jr          $ra
    // 0x801F6384: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801F6384: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6388(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6388: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F638C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6390: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F6394: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F6398: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F639C: jal         0x801BF628
    // 0x801F63A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F63A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F63A4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F63A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F63AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F63B0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F63B4: bne         $at, $zero, L_801F63C4
    if (ctx->r1 != 0) {
        // 0x801F63B8: nop
    
            goto L_801F63C4;
    }
    // 0x801F63B8: nop

    // 0x801F63BC: b           L_801F63C4
    // 0x801F63C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F63C4;
    // 0x801F63C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F63C4:
    // 0x801F63C4: jr          $ra
    // 0x801F63C8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F63C8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f63cc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f63cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F63CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F63D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F63D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F63D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F63DC: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F63E0: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    // 0x801F63E4: jal         0x801C0B8C
    // 0x801F63E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F63E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F63EC: beq         $v0, $zero, L_801F6444
    if (ctx->r2 == 0) {
        // 0x801F63F0: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_801F6444;
    }
    // 0x801F63F0: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F63F4: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F63F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F63FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F6400: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F6404: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F6408: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F640C: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801F6410: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F6414: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F6418: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F641C: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801F6420: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F6424: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F6428: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F642C: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801F6430: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F6434: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F6438: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F643C: b           L_801F6448
    // 0x801F6440: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
        goto L_801F6448;
    // 0x801F6440: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
L_801F6444:
    // 0x801F6444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F6448:
    // 0x801F6448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F644C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F6450: jr          $ra
    // 0x801F6454: nop

    return;
    // 0x801F6454: nop

;}
RECOMP_FUNC void M25_FUN_801f6458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6458: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F645C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6460: jr          $ra
    // 0x801F6464: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801F6464: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6468(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6468: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F646C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6470: jr          $ra
    // 0x801F6474: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801F6474: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6478(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6478: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F647C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6480: jr          $ra
    // 0x801F6484: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F6484: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6488(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6488: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F648C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6490: jr          $ra
    // 0x801F6494: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F6494: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6498(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6498: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F649C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F64A0: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F64A4: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F64A8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F64AC: jal         0x801BF628
    // 0x801F64B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F64B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F64B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F64B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F64BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F64C0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F64C4: bne         $at, $zero, L_801F64D4
    if (ctx->r1 != 0) {
        // 0x801F64C8: nop
    
            goto L_801F64D4;
    }
    // 0x801F64C8: nop

    // 0x801F64CC: b           L_801F64D4
    // 0x801F64D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F64D4;
    // 0x801F64D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F64D4:
    // 0x801F64D4: jr          $ra
    // 0x801F64D8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F64D8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f64dc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f64dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F64DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F64E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F64E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F64E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F64EC: lui         $a1, 0xF5
    ctx->r5 = S32(0XF5 << 16);
    // 0x801F64F0: ori         $a1, $a1, 0xAA9F
    ctx->r5 = ctx->r5 | 0XAA9F;
    // 0x801F64F4: jal         0x801C0B8C
    // 0x801F64F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F64F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F64FC: beq         $v0, $zero, L_801F650C
    if (ctx->r2 == 0) {
        // 0x801F6500: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F650C;
    }
    // 0x801F6500: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F6504: b           L_801F66D8
    // 0x801F6508: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F66D8;
    // 0x801F6508: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F650C:
    // 0x801F650C: lui         $a1, 0x5D
    ctx->r5 = S32(0X5D << 16);
    // 0x801F6510: jal         0x801C0B8C
    // 0x801F6514: ori         $a1, $a1, 0x1420
    ctx->r5 = ctx->r5 | 0X1420;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F6514: ori         $a1, $a1, 0x1420
    ctx->r5 = ctx->r5 | 0X1420;
    after_1:
    // 0x801F6518: beql        $v0, $zero, L_801F66D8
    if (ctx->r2 == 0) {
        // 0x801F651C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801F66D8;
    }
    goto skip_0;
    // 0x801F651C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801F6520: jal         0x801C0B2C
    // 0x801F6524: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801F6524: nop

    after_2:
    // 0x801F6528: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F652C: jal         0x80034C24
    // 0x801F6530: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801F6530: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801F6534: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6538: ldc1        $f4, -0x2CE8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CE8);
    // 0x801F653C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6540: ldc1        $f8, -0x2CE0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2CE0);
    // 0x801F6544: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F6548: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F654C: ldc1        $f4, -0x2CD8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CD8);
    // 0x801F6550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F6554: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6558: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F655C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F6560: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F6564: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F6568: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F656C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F6570: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F6574: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F6578: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F657C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F6580: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F6584: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F6588: nop

    // 0x801F658C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F6590: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F6594: nop

    // 0x801F6598: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F659C: beql        $v0, $zero, L_801F65EC
    if (ctx->r2 == 0) {
        // 0x801F65A0: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_801F65EC;
    }
    goto skip_1;
    // 0x801F65A0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x801F65A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F65A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F65AC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F65B0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F65B4: nop

    // 0x801F65B8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F65BC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F65C0: nop

    // 0x801F65C4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F65C8: bne         $v0, $zero, L_801F65E0
    if (ctx->r2 != 0) {
        // 0x801F65CC: nop
    
            goto L_801F65E0;
    }
    // 0x801F65CC: nop

    // 0x801F65D0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x801F65D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F65D8: b           L_801F65F8
    // 0x801F65DC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801F65F8;
    // 0x801F65DC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801F65E0:
    // 0x801F65E0: b           L_801F65F8
    // 0x801F65E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801F65F8;
    // 0x801F65E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801F65E8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_801F65EC:
    // 0x801F65EC: nop

    // 0x801F65F0: bltz        $v0, L_801F65E0
    if (SIGNED(ctx->r2) < 0) {
        // 0x801F65F4: nop
    
            goto L_801F65E0;
    }
    // 0x801F65F4: nop

L_801F65F8:
    // 0x801F65F8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801F65FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6600: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F6604: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801F6608: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F660C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F6610: sb          $v0, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r2;
    // 0x801F6614: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F6618: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x801F661C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F6620: sb          $v0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r2;
    // 0x801F6624: ldc1        $f18, -0x2CD0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2CD0);
    // 0x801F6628: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F662C: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F6630: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F6634: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801F6638: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801F663C: nop

    // 0x801F6640: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F6644: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801F6648: nop

    // 0x801F664C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801F6650: beql        $t4, $zero, L_801F66A0
    if (ctx->r12 == 0) {
        // 0x801F6654: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_801F66A0;
    }
    goto skip_2;
    // 0x801F6654: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x801F6658: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F665C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F6660: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F6664: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801F6668: nop

    // 0x801F666C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F6670: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801F6674: nop

    // 0x801F6678: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801F667C: bne         $t4, $zero, L_801F6694
    if (ctx->r12 != 0) {
        // 0x801F6680: nop
    
            goto L_801F6694;
    }
    // 0x801F6680: nop

    // 0x801F6684: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x801F6688: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F668C: b           L_801F66AC
    // 0x801F6690: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801F66AC;
    // 0x801F6690: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801F6694:
    // 0x801F6694: b           L_801F66AC
    // 0x801F6698: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801F66AC;
    // 0x801F6698: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801F669C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_801F66A0:
    // 0x801F66A0: nop

    // 0x801F66A4: bltz        $t4, L_801F6694
    if (SIGNED(ctx->r12) < 0) {
        // 0x801F66A8: nop
    
            goto L_801F6694;
    }
    // 0x801F66A8: nop

L_801F66AC:
    // 0x801F66AC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F66B0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801F66B4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801F66B8: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801F66BC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F66C0: sb          $t4, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r12;
    // 0x801F66C4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F66C8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801F66CC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F66D0: sb          $t8, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r24;
    // 0x801F66D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F66D8:
    // 0x801F66D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F66DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F66E0: jr          $ra
    // 0x801F66E4: nop

    return;
    // 0x801F66E4: nop

;}
RECOMP_FUNC void M25_FUN_801f66e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F66E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F66EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F66F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F66F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F66F8: lui         $a1, 0x160
    ctx->r5 = S32(0X160 << 16);
    // 0x801F66FC: ori         $a1, $a1, 0x7A5F
    ctx->r5 = ctx->r5 | 0X7A5F;
    // 0x801F6700: jal         0x801C0B8C
    // 0x801F6704: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6704: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F6708: beq         $v0, $zero, L_801F6718
    if (ctx->r2 == 0) {
        // 0x801F670C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F6718;
    }
    // 0x801F670C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F6710: b           L_801F68F4
    // 0x801F6714: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F68F4;
    // 0x801F6714: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F6718:
    // 0x801F6718: lui         $a1, 0x132
    ctx->r5 = S32(0X132 << 16);
    // 0x801F671C: jal         0x801C0B8C
    // 0x801F6720: ori         $a1, $a1, 0xB39F
    ctx->r5 = ctx->r5 | 0XB39F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F6720: ori         $a1, $a1, 0xB39F
    ctx->r5 = ctx->r5 | 0XB39F;
    after_1:
    // 0x801F6724: beql        $v0, $zero, L_801F68F4
    if (ctx->r2 == 0) {
        // 0x801F6728: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801F68F4;
    }
    goto skip_0;
    // 0x801F6728: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801F672C: jal         0x801C0B2C
    // 0x801F6730: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801F6730: nop

    after_2:
    // 0x801F6734: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F6738: jal         0x80034C24
    // 0x801F673C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801F673C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801F6740: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6744: ldc1        $f4, -0x2CC8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CC8);
    // 0x801F6748: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F674C: ldc1        $f8, -0x2CC0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2CC0);
    // 0x801F6750: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F6754: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801F6758: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F675C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F6760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F6764: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6768: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F676C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F6770: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F6774: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F6778: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F677C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F6780: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F6784: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F6788: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F678C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F6790: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F6794: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F6798: nop

    // 0x801F679C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F67A0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F67A4: nop

    // 0x801F67A8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F67AC: beql        $v0, $zero, L_801F67FC
    if (ctx->r2 == 0) {
        // 0x801F67B0: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_801F67FC;
    }
    goto skip_1;
    // 0x801F67B0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x801F67B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F67B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F67BC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F67C0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F67C4: nop

    // 0x801F67C8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F67CC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F67D0: nop

    // 0x801F67D4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F67D8: bne         $v0, $zero, L_801F67F0
    if (ctx->r2 != 0) {
        // 0x801F67DC: nop
    
            goto L_801F67F0;
    }
    // 0x801F67DC: nop

    // 0x801F67E0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x801F67E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F67E8: b           L_801F6808
    // 0x801F67EC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801F6808;
    // 0x801F67EC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801F67F0:
    // 0x801F67F0: b           L_801F6808
    // 0x801F67F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801F6808;
    // 0x801F67F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801F67F8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_801F67FC:
    // 0x801F67FC: nop

    // 0x801F6800: bltz        $v0, L_801F67F0
    if (SIGNED(ctx->r2) < 0) {
        // 0x801F6804: nop
    
            goto L_801F67F0;
    }
    // 0x801F6804: nop

L_801F6808:
    // 0x801F6808: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801F680C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6810: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F6814: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801F6818: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F681C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F6820: sb          $v0, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r2;
    // 0x801F6824: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F6828: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x801F682C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F6830: sb          $v0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r2;
    // 0x801F6834: ldc1        $f18, -0x2CB8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2CB8);
    // 0x801F6838: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F683C: ldc1        $f6, -0x2CB0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2CB0);
    // 0x801F6840: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801F6844: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F6848: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F684C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F6850: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801F6854: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801F6858: nop

    // 0x801F685C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801F6860: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801F6864: nop

    // 0x801F6868: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801F686C: beql        $t4, $zero, L_801F68BC
    if (ctx->r12 == 0) {
        // 0x801F6870: mfc1        $t4, $f16
        ctx->r12 = (int32_t)ctx->f16.u32l;
            goto L_801F68BC;
    }
    goto skip_2;
    // 0x801F6870: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801F6874: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F6878: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F687C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F6880: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801F6884: nop

    // 0x801F6888: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F688C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801F6890: nop

    // 0x801F6894: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801F6898: bne         $t4, $zero, L_801F68B0
    if (ctx->r12 != 0) {
        // 0x801F689C: nop
    
            goto L_801F68B0;
    }
    // 0x801F689C: nop

    // 0x801F68A0: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x801F68A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F68A8: b           L_801F68C8
    // 0x801F68AC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801F68C8;
    // 0x801F68AC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801F68B0:
    // 0x801F68B0: b           L_801F68C8
    // 0x801F68B4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801F68C8;
    // 0x801F68B4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801F68B8: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
L_801F68BC:
    // 0x801F68BC: nop

    // 0x801F68C0: bltz        $t4, L_801F68B0
    if (SIGNED(ctx->r12) < 0) {
        // 0x801F68C4: nop
    
            goto L_801F68B0;
    }
    // 0x801F68C4: nop

L_801F68C8:
    // 0x801F68C8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F68CC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801F68D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801F68D4: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801F68D8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F68DC: sb          $t4, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r12;
    // 0x801F68E0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F68E4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801F68E8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F68EC: sb          $t8, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r24;
    // 0x801F68F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F68F4:
    // 0x801F68F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F68F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F68FC: jr          $ra
    // 0x801F6900: nop

    return;
    // 0x801F6900: nop

;}
RECOMP_FUNC void M25_FUN_801f6904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6904: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F6908: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F690C: jr          $ra
    // 0x801F6910: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F6910: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6914(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6918: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F691C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6924: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801F6928: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    // 0x801F692C: jal         0x801C0B8C
    // 0x801F6930: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6930: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F6934: beq         $v0, $zero, L_801F6964
    if (ctx->r2 == 0) {
        // 0x801F6938: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_801F6964;
    }
    // 0x801F6938: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F693C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6940: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F6944: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F6948: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F694C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F6950: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801F6954: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801F6958: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F695C: b           L_801F69B0
    // 0x801F6960: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
        goto L_801F69B0;
    // 0x801F6960: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
L_801F6964:
    // 0x801F6964: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F6968: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F696C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F6970: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801F6974: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801F6978: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F697C: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x801F6980: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F6984: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801F6988: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F698C: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
    // 0x801F6990: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F6994: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801F6998: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F699C: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801F69A0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F69A4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x801F69A8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F69AC: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
L_801F69B0:
    // 0x801F69B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F69B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F69B8: jr          $ra
    // 0x801F69BC: nop

    return;
    // 0x801F69BC: nop

;}
RECOMP_FUNC void M25_FUN_801f69c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F69C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F69C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F69C8: jr          $ra
    // 0x801F69CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F69CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f69d0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f69d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F69D0: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F69D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F69D8: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F69DC: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F69E0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F69E4: jal         0x801BF628
    // 0x801F69E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F69E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F69EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F69F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F69F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F69F8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F69FC: bne         $at, $zero, L_801F6A0C
    if (ctx->r1 != 0) {
        // 0x801F6A00: nop
    
            goto L_801F6A0C;
    }
    // 0x801F6A00: nop

    // 0x801F6A04: b           L_801F6A0C
    // 0x801F6A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F6A0C;
    // 0x801F6A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F6A0C:
    // 0x801F6A0C: jr          $ra
    // 0x801F6A10: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F6A10: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6a14(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6a14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6A18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F6A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6A24: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F6A28: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    // 0x801F6A2C: jal         0x801C0B8C
    // 0x801F6A30: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6A30: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F6A34: beq         $v0, $zero, L_801F6AD0
    if (ctx->r2 == 0) {
        // 0x801F6A38: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_801F6AD0;
    }
    // 0x801F6A38: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6A3C: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F6A40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F6A44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F6A48: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F6A4C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801F6A50: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F6A54: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801F6A58: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F6A5C: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x801F6A60: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F6A64: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801F6A68: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F6A6C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x801F6A70: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F6A74: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801F6A78: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F6A7C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x801F6A80: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F6A84: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801F6A88: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F6A8C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801F6A90: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801F6A94: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F6A98: sb          $zero, 0x48($t0)
    MEM_B(0X48, ctx->r8) = 0;
    // 0x801F6A9C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801F6AA0: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x801F6AA4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F6AA8: sb          $zero, 0x49($t3)
    MEM_B(0X49, ctx->r11) = 0;
    // 0x801F6AAC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F6AB0: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x801F6AB4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801F6AB8: sb          $zero, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = 0;
    // 0x801F6ABC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F6AC0: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801F6AC4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F6AC8: b           L_801F6AD4
    // 0x801F6ACC: sb          $t7, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r15;
        goto L_801F6AD4;
    // 0x801F6ACC: sb          $t7, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r15;
L_801F6AD0:
    // 0x801F6AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F6AD4:
    // 0x801F6AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F6AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F6ADC: jr          $ra
    // 0x801F6AE0: nop

    return;
    // 0x801F6AE0: nop

;}
RECOMP_FUNC void M25_FUN_801f6ae4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6AE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F6AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6AF4: lui         $a1, 0x49F
    ctx->r5 = S32(0X49F << 16);
    // 0x801F6AF8: ori         $a1, $a1, 0x1095
    ctx->r5 = ctx->r5 | 0X1095;
    // 0x801F6AFC: jal         0x801C0B8C
    // 0x801F6B00: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6B00: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F6B04: beq         $v0, $zero, L_801F6B14
    if (ctx->r2 == 0) {
        // 0x801F6B08: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F6B14;
    }
    // 0x801F6B08: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F6B0C: b           L_801F6CCC
    // 0x801F6B10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F6CCC;
    // 0x801F6B10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F6B14:
    // 0x801F6B14: lui         $a1, 0x497
    ctx->r5 = S32(0X497 << 16);
    // 0x801F6B18: jal         0x801C0B8C
    // 0x801F6B1C: ori         $a1, $a1, 0x6F75
    ctx->r5 = ctx->r5 | 0X6F75;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F6B1C: ori         $a1, $a1, 0x6F75
    ctx->r5 = ctx->r5 | 0X6F75;
    after_1:
    // 0x801F6B20: beql        $v0, $zero, L_801F6CCC
    if (ctx->r2 == 0) {
        // 0x801F6B24: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801F6CCC;
    }
    goto skip_0;
    // 0x801F6B24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801F6B28: jal         0x801C0B2C
    // 0x801F6B2C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801F6B2C: nop

    after_2:
    // 0x801F6B30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F6B34: jal         0x80034C24
    // 0x801F6B38: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801F6B38: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801F6B3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6B40: ldc1        $f4, -0x2CA8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CA8);
    // 0x801F6B44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6B48: ldc1        $f8, -0x2CA0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2CA0);
    // 0x801F6B4C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F6B50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801F6B54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F6B58: lui         $at, 0x4319
    ctx->r1 = S32(0X4319 << 16);
    // 0x801F6B5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F6B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F6B64: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6B68: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F6B6C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F6B70: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F6B74: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F6B78: div.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801F6B7C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x801F6B80: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F6B84: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F6B88: nop

    // 0x801F6B8C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F6B90: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F6B94: nop

    // 0x801F6B98: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F6B9C: beql        $v0, $zero, L_801F6BEC
    if (ctx->r2 == 0) {
        // 0x801F6BA0: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_801F6BEC;
    }
    goto skip_1;
    // 0x801F6BA0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801F6BA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F6BA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F6BAC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801F6BB0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F6BB4: nop

    // 0x801F6BB8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801F6BBC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F6BC0: nop

    // 0x801F6BC4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F6BC8: bne         $v0, $zero, L_801F6BE0
    if (ctx->r2 != 0) {
        // 0x801F6BCC: nop
    
            goto L_801F6BE0;
    }
    // 0x801F6BCC: nop

    // 0x801F6BD0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x801F6BD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F6BD8: b           L_801F6BF8
    // 0x801F6BDC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801F6BF8;
    // 0x801F6BDC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801F6BE0:
    // 0x801F6BE0: b           L_801F6BF8
    // 0x801F6BE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801F6BF8;
    // 0x801F6BE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801F6BE8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_801F6BEC:
    // 0x801F6BEC: nop

    // 0x801F6BF0: bltz        $v0, L_801F6BE0
    if (SIGNED(ctx->r2) < 0) {
        // 0x801F6BF4: nop
    
            goto L_801F6BE0;
    }
    // 0x801F6BF4: nop

L_801F6BF8:
    // 0x801F6BF8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801F6BFC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F6C00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F6C04: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801F6C08: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801F6C0C: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x801F6C10: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F6C14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F6C18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6C1C: sb          $v0, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r2;
    // 0x801F6C20: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F6C24: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F6C28: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F6C2C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x801F6C30: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F6C34: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F6C38: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F6C3C: sb          $v0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r2;
    // 0x801F6C40: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801F6C44: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F6C48: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x801F6C4C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F6C50: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F6C54: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F6C58: beq         $t7, $zero, L_801F6CA4
    if (ctx->r15 == 0) {
        // 0x801F6C5C: sb          $v0, 0x4A($t5)
        MEM_B(0X4A, ctx->r13) = ctx->r2;
            goto L_801F6CA4;
    }
    // 0x801F6C5C: sb          $v0, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r2;
    // 0x801F6C60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6C64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6C68: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801F6C6C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F6C70: nop

    // 0x801F6C74: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801F6C78: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F6C7C: nop

    // 0x801F6C80: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F6C84: bne         $t7, $zero, L_801F6C9C
    if (ctx->r15 != 0) {
        // 0x801F6C88: nop
    
            goto L_801F6C9C;
    }
    // 0x801F6C88: nop

    // 0x801F6C8C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801F6C90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F6C94: b           L_801F6CB4
    // 0x801F6C98: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801F6CB4;
    // 0x801F6C98: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801F6C9C:
    // 0x801F6C9C: b           L_801F6CB4
    // 0x801F6CA0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801F6CB4;
    // 0x801F6CA0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_801F6CA4:
    // 0x801F6CA4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801F6CA8: nop

    // 0x801F6CAC: bltz        $t7, L_801F6C9C
    if (SIGNED(ctx->r15) < 0) {
        // 0x801F6CB0: nop
    
            goto L_801F6C9C;
    }
    // 0x801F6CB0: nop

L_801F6CB4:
    // 0x801F6CB4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F6CB8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F6CBC: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801F6CC0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F6CC4: sb          $t7, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r15;
    // 0x801F6CC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F6CCC:
    // 0x801F6CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F6CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F6CD4: jr          $ra
    // 0x801F6CD8: nop

    return;
    // 0x801F6CD8: nop

;}
RECOMP_FUNC void M25_FUN_801f6cdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6CE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F6CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6CE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6CEC: lui         $a1, 0x539
    ctx->r5 = S32(0X539 << 16);
    // 0x801F6CF0: ori         $a1, $a1, 0x2DB5
    ctx->r5 = ctx->r5 | 0X2DB5;
    // 0x801F6CF4: jal         0x801C0B8C
    // 0x801F6CF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6CF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F6CFC: beq         $v0, $zero, L_801F6D0C
    if (ctx->r2 == 0) {
        // 0x801F6D00: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F6D0C;
    }
    // 0x801F6D00: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F6D04: b           L_801F6EF0
    // 0x801F6D08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F6EF0;
    // 0x801F6D08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F6D0C:
    // 0x801F6D0C: lui         $a1, 0x4EC
    ctx->r5 = S32(0X4EC << 16);
    // 0x801F6D10: jal         0x801C0B8C
    // 0x801F6D14: ori         $a1, $a1, 0xE275
    ctx->r5 = ctx->r5 | 0XE275;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801F6D14: ori         $a1, $a1, 0xE275
    ctx->r5 = ctx->r5 | 0XE275;
    after_1:
    // 0x801F6D18: beql        $v0, $zero, L_801F6EF0
    if (ctx->r2 == 0) {
        // 0x801F6D1C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801F6EF0;
    }
    goto skip_0;
    // 0x801F6D1C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x801F6D20: jal         0x801C0B2C
    // 0x801F6D24: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801F6D24: nop

    after_2:
    // 0x801F6D28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F6D2C: jal         0x80034C24
    // 0x801F6D30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801F6D30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801F6D34: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6D38: ldc1        $f4, -0x2C98($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C98);
    // 0x801F6D3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6D40: ldc1        $f8, -0x2C90($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2C90);
    // 0x801F6D44: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801F6D48: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801F6D4C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F6D50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F6D54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6D58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F6D5C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6D60: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F6D64: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801F6D68: ldc1        $f6, -0x2C88($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2C88);
    // 0x801F6D6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6D70: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F6D74: ldc1        $f10, -0x2C80($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2C80);
    // 0x801F6D78: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F6D7C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F6D80: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801F6D84: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F6D88: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F6D8C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F6D90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F6D94: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F6D98: nop

    // 0x801F6D9C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F6DA0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F6DA4: nop

    // 0x801F6DA8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F6DAC: beql        $v0, $zero, L_801F6DFC
    if (ctx->r2 == 0) {
        // 0x801F6DB0: mfc1        $v0, $f4
        ctx->r2 = (int32_t)ctx->f4.u32l;
            goto L_801F6DFC;
    }
    goto skip_1;
    // 0x801F6DB0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801F6DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F6DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F6DBC: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F6DC0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F6DC4: nop

    // 0x801F6DC8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F6DCC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F6DD0: nop

    // 0x801F6DD4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F6DD8: bne         $v0, $zero, L_801F6DF0
    if (ctx->r2 != 0) {
        // 0x801F6DDC: nop
    
            goto L_801F6DF0;
    }
    // 0x801F6DDC: nop

    // 0x801F6DE0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x801F6DE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F6DE8: b           L_801F6E08
    // 0x801F6DEC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801F6E08;
    // 0x801F6DEC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801F6DF0:
    // 0x801F6DF0: b           L_801F6E08
    // 0x801F6DF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801F6E08;
    // 0x801F6DF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801F6DF8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
L_801F6DFC:
    // 0x801F6DFC: nop

    // 0x801F6E00: bltz        $v0, L_801F6DF0
    if (SIGNED(ctx->r2) < 0) {
        // 0x801F6E04: nop
    
            goto L_801F6DF0;
    }
    // 0x801F6E04: nop

L_801F6E08:
    // 0x801F6E08: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801F6E0C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F6E10: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F6E14: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801F6E18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F6E1C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F6E20: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F6E24: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801F6E28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6E2C: sb          $v0, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r2;
    // 0x801F6E30: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F6E34: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x801F6E38: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F6E3C: sb          $v0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r2;
    // 0x801F6E40: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801F6E44: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x801F6E48: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F6E4C: sb          $v0, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r2;
    // 0x801F6E50: ldc1        $f10, -0x2C78($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2C78);
    // 0x801F6E54: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F6E58: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801F6E5C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F6E60: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F6E64: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F6E68: nop

    // 0x801F6E6C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F6E70: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F6E74: nop

    // 0x801F6E78: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F6E7C: beql        $t7, $zero, L_801F6ECC
    if (ctx->r15 == 0) {
        // 0x801F6E80: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_801F6ECC;
    }
    goto skip_2;
    // 0x801F6E80: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x801F6E84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F6E88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6E8C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801F6E90: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F6E94: nop

    // 0x801F6E98: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801F6E9C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F6EA0: nop

    // 0x801F6EA4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F6EA8: bne         $t7, $zero, L_801F6EC0
    if (ctx->r15 != 0) {
        // 0x801F6EAC: nop
    
            goto L_801F6EC0;
    }
    // 0x801F6EAC: nop

    // 0x801F6EB0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801F6EB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F6EB8: b           L_801F6ED8
    // 0x801F6EBC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801F6ED8;
    // 0x801F6EBC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801F6EC0:
    // 0x801F6EC0: b           L_801F6ED8
    // 0x801F6EC4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801F6ED8;
    // 0x801F6EC4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801F6EC8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_801F6ECC:
    // 0x801F6ECC: nop

    // 0x801F6ED0: bltz        $t7, L_801F6EC0
    if (SIGNED(ctx->r15) < 0) {
        // 0x801F6ED4: nop
    
            goto L_801F6EC0;
    }
    // 0x801F6ED4: nop

L_801F6ED8:
    // 0x801F6ED8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F6EDC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F6EE0: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801F6EE4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F6EE8: sb          $t7, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r15;
    // 0x801F6EEC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F6EF0:
    // 0x801F6EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F6EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F6EF8: jr          $ra
    // 0x801F6EFC: nop

    return;
    // 0x801F6EFC: nop

;}
RECOMP_FUNC void M25_FUN_801f6f00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6F00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F6F04: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6F08: jr          $ra
    // 0x801F6F0C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F6F0C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6f10(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6f10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6F10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F6F14: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F6F18: jr          $ra
    // 0x801F6F1C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F6F1C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6f20(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6f20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6F20: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F6F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6F28: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F6F2C: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F6F30: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F6F34: jal         0x801BF628
    // 0x801F6F38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F6F38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F6F3C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F6F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F6F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F6F48: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F6F4C: bne         $at, $zero, L_801F6F5C
    if (ctx->r1 != 0) {
        // 0x801F6F50: nop
    
            goto L_801F6F5C;
    }
    // 0x801F6F50: nop

    // 0x801F6F54: b           L_801F6F5C
    // 0x801F6F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F6F5C;
    // 0x801F6F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F6F5C:
    // 0x801F6F5C: jr          $ra
    // 0x801F6F60: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F6F60: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f6f64(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f6f64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6F68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F6F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6F70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6F74: lui         $a1, 0x8D
    ctx->r5 = S32(0X8D << 16);
    // 0x801F6F78: ori         $a1, $a1, 0xE81F
    ctx->r5 = ctx->r5 | 0XE81F;
    // 0x801F6F7C: jal         0x801C0B8C
    // 0x801F6F80: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F6F80: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F6F84: beq         $v0, $zero, L_801F6FD4
    if (ctx->r2 == 0) {
        // 0x801F6F88: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_801F6FD4;
    }
    // 0x801F6F88: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F6F8C: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F6F90: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F6F94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F6F98: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F6F9C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801F6FA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F6FA4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F6FA8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F6FAC: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801F6FB0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F6FB4: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x801F6FB8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F6FBC: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x801F6FC0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F6FC4: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x801F6FC8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F6FCC: b           L_801F6FD8
    // 0x801F6FD0: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
        goto L_801F6FD8;
    // 0x801F6FD0: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
L_801F6FD4:
    // 0x801F6FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F6FD8:
    // 0x801F6FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F6FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F6FE0: jr          $ra
    // 0x801F6FE4: nop

    return;
    // 0x801F6FE4: nop

;}
RECOMP_FUNC void M25_FUN_801f6fe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6FE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F6FEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F6FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F6FF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F6FF8: lui         $a1, 0xC7
    ctx->r5 = S32(0XC7 << 16);
    // 0x801F6FFC: ori         $a1, $a1, 0xE3DF
    ctx->r5 = ctx->r5 | 0XE3DF;
    // 0x801F7000: jal         0x801C0B8C
    // 0x801F7004: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F7004: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7008: beq         $v0, $zero, L_801F7030
    if (ctx->r2 == 0) {
        // 0x801F700C: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_801F7030;
    }
    // 0x801F700C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801F7010: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x801F7014: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F7018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F701C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801F7020: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801F7024: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F7028: b           L_801F70AC
    // 0x801F702C: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
        goto L_801F70AC;
    // 0x801F702C: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
L_801F7030:
    // 0x801F7030: jal         0x801C0B2C
    // 0x801F7034: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801F7034: nop

    after_1:
    // 0x801F7038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F703C: jal         0x80034C24
    // 0x801F7040: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801F7040: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801F7044: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7048: ldc1        $f6, -0x2C70($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2C70);
    // 0x801F704C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7050: ldc1        $f10, -0x2C68($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2C68);
    // 0x801F7054: div.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x801F7058: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F705C: ldc1        $f6, -0x2C60($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2C60);
    // 0x801F7060: lui         $at, 0x402A
    ctx->r1 = S32(0X402A << 16);
    // 0x801F7064: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x801F7068: lw          $t9, -0x2730($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2730);
    // 0x801F706C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F7070: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x801F7074: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F7078: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x801F707C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F7080: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F7084: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801F7088: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F708C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F7090: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F7094: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F7098: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801F709C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801F70A0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F70A4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F70A8: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
L_801F70AC:
    // 0x801F70AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F70B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F70B4: jr          $ra
    // 0x801F70B8: nop

    return;
    // 0x801F70B8: nop

;}
RECOMP_FUNC void M25_FUN_801f70bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F70BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F70C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F70C4: jr          $ra
    // 0x801F70C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801F70C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f70cc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f70cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F70CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F70D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F70D4: jr          $ra
    // 0x801F70D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F70D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f70dc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f70dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F70DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F70E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F70E4: jr          $ra
    // 0x801F70E8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F70E8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f70ec(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f70ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F70EC: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F70F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F70F4: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F70F8: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F70FC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F7100: jal         0x801BF628
    // 0x801F7104: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F7104: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F7108: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F710C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F7114: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F7118: bne         $at, $zero, L_801F7128
    if (ctx->r1 != 0) {
        // 0x801F711C: nop
    
            goto L_801F7128;
    }
    // 0x801F711C: nop

    // 0x801F7120: b           L_801F7128
    // 0x801F7124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F7128;
    // 0x801F7124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F7128:
    // 0x801F7128: jr          $ra
    // 0x801F712C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F712C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7130(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7134: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F713C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7140: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F7144: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    // 0x801F7148: jal         0x801C0B8C
    // 0x801F714C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F714C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7150: beq         $v0, $zero, L_801F71B8
    if (ctx->r2 == 0) {
        // 0x801F7154: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_801F71B8;
    }
    // 0x801F7154: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F7158: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F715C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7160: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x801F7164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7168: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x801F716C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7170: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x801F7174: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F7178: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F717C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F7180: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801F7184: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F7188: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x801F718C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F7190: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801F7194: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F7198: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x801F719C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F71A0: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
    // 0x801F71A4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F71A8: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x801F71AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F71B0: b           L_801F71BC
    // 0x801F71B4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
        goto L_801F71BC;
    // 0x801F71B4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
L_801F71B8:
    // 0x801F71B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F71BC:
    // 0x801F71BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F71C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F71C4: jr          $ra
    // 0x801F71C8: nop

    return;
    // 0x801F71C8: nop

;}
RECOMP_FUNC void M25_FUN_801f71cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F71CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F71D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F71D4: jr          $ra
    // 0x801F71D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801F71D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f71dc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f71dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F71DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F71E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F71E4: jr          $ra
    // 0x801F71E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801F71E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f71ec(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f71ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F71EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F71F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F71F4: jr          $ra
    // 0x801F71F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F71F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f71fc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f71fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F71FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F7200: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F7204: jr          $ra
    // 0x801F7208: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F7208: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f720c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f720c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F720C: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F7210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7214: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F7218: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F721C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F7220: jal         0x801BF628
    // 0x801F7224: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F7224: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F7228: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F7234: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F7238: bne         $at, $zero, L_801F7248
    if (ctx->r1 != 0) {
        // 0x801F723C: nop
    
            goto L_801F7248;
    }
    // 0x801F723C: nop

    // 0x801F7240: b           L_801F7248
    // 0x801F7244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F7248;
    // 0x801F7244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F7248:
    // 0x801F7248: jr          $ra
    // 0x801F724C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F724C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7250(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7254: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F725C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7260: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F7264: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    // 0x801F7268: jal         0x801C0B8C
    // 0x801F726C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F726C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7270: beq         $v0, $zero, L_801F72D8
    if (ctx->r2 == 0) {
        // 0x801F7274: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_801F72D8;
    }
    // 0x801F7274: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F7278: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F727C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7280: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x801F7284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7288: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x801F728C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7290: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x801F7294: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F7298: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F729C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F72A0: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801F72A4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F72A8: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x801F72AC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F72B0: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801F72B4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F72B8: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x801F72BC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F72C0: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
    // 0x801F72C4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F72C8: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x801F72CC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F72D0: b           L_801F72DC
    // 0x801F72D4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
        goto L_801F72DC;
    // 0x801F72D4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
L_801F72D8:
    // 0x801F72D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F72DC:
    // 0x801F72DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F72E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F72E4: jr          $ra
    // 0x801F72E8: nop

    return;
    // 0x801F72E8: nop

;}
RECOMP_FUNC void M25_FUN_801f72ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F72EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F72F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F72F4: jr          $ra
    // 0x801F72F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801F72F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f72fc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f72fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F72FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F7300: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F7304: jr          $ra
    // 0x801F7308: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801F7308: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f730c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f730c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F730C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F7310: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F7314: jr          $ra
    // 0x801F7318: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F7318: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f731c(rdram, ctx);
;}
