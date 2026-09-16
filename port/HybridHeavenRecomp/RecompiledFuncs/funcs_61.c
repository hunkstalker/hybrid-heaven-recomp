#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801e48a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E48A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E48AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E48B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E48B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E48B8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E48BC: addiu       $a1, $a1, 0xA48
    ctx->r5 = ADD32(ctx->r5, 0XA48);
    // 0x801E48C0: jal         0x801C2420
    // 0x801E48C4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801E48C4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
    // 0x801E48C8: jal         0x801CC318
    // 0x801E48CC: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_1;
    // 0x801E48CC: nop

    after_1:
    // 0x801E48D0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E48D4: addiu       $a1, $a1, -0x4EBC
    ctx->r5 = ADD32(ctx->r5, -0X4EBC);
    // 0x801E48D8: jal         0x801CC458
    // 0x801E48DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_2;
    // 0x801E48DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801E48E0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E48E4: addiu       $a1, $a1, 0xA60
    ctx->r5 = ADD32(ctx->r5, 0XA60);
    // 0x801E48E8: jal         0x801C2420
    // 0x801E48EC: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_3;
    // 0x801E48EC: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_3:
    // 0x801E48F0: jal         0x801CC318
    // 0x801E48F4: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_4;
    // 0x801E48F4: nop

    after_4:
    // 0x801E48F8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E48FC: addiu       $a1, $a1, -0x52D8
    ctx->r5 = ADD32(ctx->r5, -0X52D8);
    // 0x801E4900: jal         0x801CC458
    // 0x801E4904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_5;
    // 0x801E4904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x801E4908: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E490C: addiu       $a1, $a1, 0xA78
    ctx->r5 = ADD32(ctx->r5, 0XA78);
    // 0x801E4910: jal         0x801C2420
    // 0x801E4914: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_6;
    // 0x801E4914: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_6:
    // 0x801E4918: jal         0x801CC318
    // 0x801E491C: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_7;
    // 0x801E491C: nop

    after_7:
    // 0x801E4920: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E4924: addiu       $a1, $a1, -0x5204
    ctx->r5 = ADD32(ctx->r5, -0X5204);
    // 0x801E4928: jal         0x801CC458
    // 0x801E492C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_8;
    // 0x801E492C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x801E4930: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E4934: addiu       $a1, $a1, -0x5200
    ctx->r5 = ADD32(ctx->r5, -0X5200);
    // 0x801E4938: jal         0x801CC4C0
    // 0x801E493C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CC4C0)(rdram, ctx);
        goto after_9;
    // 0x801E493C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x801E4940: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E4944: addiu       $a1, $a1, 0xA90
    ctx->r5 = ADD32(ctx->r5, 0XA90);
    // 0x801E4948: jal         0x801C2420
    // 0x801E494C: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_10;
    // 0x801E494C: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_10:
    // 0x801E4950: jal         0x801CC318
    // 0x801E4954: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_11;
    // 0x801E4954: nop

    after_11:
    // 0x801E4958: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E495C: addiu       $a1, $a1, -0x50E8
    ctx->r5 = ADD32(ctx->r5, -0X50E8);
    // 0x801E4960: jal         0x801CC458
    // 0x801E4964: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_12;
    // 0x801E4964: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x801E4968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E496C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E4970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E4974: jr          $ra
    // 0x801E4978: nop

    return;
    // 0x801E4978: nop

;}
RECOMP_FUNC void M25_FUN_801e497c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E497C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E4980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E4984: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E4988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E498C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E4990: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E4994: lw          $a0, -0x54EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54EC);
    // 0x801E4998: jal         0x80005670
    // 0x801E499C: addiu       $a1, $a1, -0x4ED0
    ctx->r5 = ADD32(ctx->r5, -0X4ED0);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801E499C: addiu       $a1, $a1, -0x4ED0
    ctx->r5 = ADD32(ctx->r5, -0X4ED0);
    after_0:
    // 0x801E49A0: jal         0x801CEDBC
    // 0x801E49A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CEDBC)(rdram, ctx);
        goto after_1;
    // 0x801E49A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801E49A8: jal         0x801CEDC8
    // 0x801E49AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CEDC8)(rdram, ctx);
        goto after_2;
    // 0x801E49AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801E49B0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801E49B4: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801E49B8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E49BC: addiu       $a1, $a1, -0x52EC
    ctx->r5 = ADD32(ctx->r5, -0X52EC);
    // 0x801E49C0: jal         0x80005670
    // 0x801E49C4: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x801E49C4: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    after_3:
    // 0x801E49C8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801E49CC: lw          $t7, -0x54EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X54EC);
    // 0x801E49D0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E49D4: addiu       $a1, $a1, -0x5218
    ctx->r5 = ADD32(ctx->r5, -0X5218);
    // 0x801E49D8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E49DC: jal         0x80005670
    // 0x801E49E0: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_4;
    // 0x801E49E0: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_4:
    // 0x801E49E4: jal         0x801D048C
    // 0x801E49E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D048C)(rdram, ctx);
        goto after_5;
    // 0x801E49E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801E49EC: jal         0x801D03E0
    // 0x801E49F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D03E0)(rdram, ctx);
        goto after_6;
    // 0x801E49F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x801E49F4: jal         0x801D03EC
    // 0x801E49F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D03EC)(rdram, ctx);
        goto after_7;
    // 0x801E49F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x801E49FC: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801E4A00: lw          $t9, -0x54EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X54EC);
    // 0x801E4A04: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E4A08: addiu       $a1, $a1, -0x50FC
    ctx->r5 = ADD32(ctx->r5, -0X50FC);
    // 0x801E4A0C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E4A10: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E4A14: jal         0x80005670
    // 0x801E4A18: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_8;
    // 0x801E4A18: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    after_8:
    // 0x801E4A1C: jal         0x801CC530
    // 0x801E4A20: nop

    LOOKUP_FUNC(0x801CC530)(rdram, ctx);
        goto after_9;
    // 0x801E4A20: nop

    after_9:
    // 0x801E4A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E4A2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E4A30: jr          $ra
    // 0x801E4A34: nop

    return;
    // 0x801E4A34: nop

;}
RECOMP_FUNC void M25_FUN_801e4a38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E4A3C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801E4A40: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801E4A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4A48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E4A4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E4A50: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E4A54: lui         $a1, 0x35
    ctx->r5 = S32(0X35 << 16);
    // 0x801E4A58: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E4A5C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E4A60: beql        $t8, $zero, L_801E4AA4
    if (ctx->r24 == 0) {
        // 0x801E4A64: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801E4AA4;
    }
    goto skip_0;
    // 0x801E4A64: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801E4A68: jal         0x801C0B8C
    // 0x801E4A6C: ori         $a1, $a1, 0x67E0
    ctx->r5 = ctx->r5 | 0X67E0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4A6C: ori         $a1, $a1, 0x67E0
    ctx->r5 = ctx->r5 | 0X67E0;
    after_0:
    // 0x801E4A70: beq         $v0, $zero, L_801E4AA0
    if (ctx->r2 == 0) {
        // 0x801E4A74: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801E4AA0;
    }
    // 0x801E4A74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E4A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E4A7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E4A80: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E4A84: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x801E4A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E4A8C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801E4A90: jal         0x801CC470
    // 0x801E4A94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801E4A94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801E4A98: b           L_801E4AA4
    // 0x801E4A9C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E4AA4;
    // 0x801E4A9C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E4AA0:
    // 0x801E4AA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E4AA4:
    // 0x801E4AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4AA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E4AAC: jr          $ra
    // 0x801E4AB0: nop

    return;
    // 0x801E4AB0: nop

;}
RECOMP_FUNC void M25_FUN_801e4ab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4AB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E4AB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E4ABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4AC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E4AC4: lui         $a1, 0x2CD
    ctx->r5 = S32(0X2CD << 16);
    // 0x801E4AC8: ori         $a1, $a1, 0x29C0
    ctx->r5 = ctx->r5 | 0X29C0;
    // 0x801E4ACC: jal         0x801C0B8C
    // 0x801E4AD0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4AD0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4AD4: beq         $v0, $zero, L_801E4B80
    if (ctx->r2 == 0) {
        // 0x801E4AD8: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801E4B80;
    }
    // 0x801E4AD8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E4ADC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E4AE0: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801E4AE4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E4AE8: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x801E4AEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E4AF0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E4AF4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801E4AF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E4AFC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E4B00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E4B04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E4B08: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E4B0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E4B10: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x801E4B14: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801E4B18: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E4B1C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E4B20: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x801E4B24: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E4B28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E4B2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E4B30: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801E4B34: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801E4B38: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E4B3C: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801E4B40: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E4B44: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E4B48: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801E4B4C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E4B50: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801E4B54: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E4B58: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E4B5C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801E4B60: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801E4B64: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801E4B68: jal         0x801CC470
    // 0x801E4B6C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801E4B6C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801E4B70: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4B74: sw          $zero, -0x4E24($at)
    MEM_W(-0X4E24, ctx->r1) = 0;
    // 0x801E4B78: b           L_801E4BEC
    // 0x801E4B7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E4BEC;
    // 0x801E4B7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E4B80:
    // 0x801E4B80: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801E4B84: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801E4B88: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4B8C: lwc1        $f16, -0x4034($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4034);
    // 0x801E4B90: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801E4B94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E4B98: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4B9C: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801E4BA0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801E4BA4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801E4BA8: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x801E4BAC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801E4BB0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801E4BB4: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801E4BB8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E4BBC: swc1        $f18, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f18.u32l;
    // 0x801E4BC0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E4BC4: lwc1        $f4, -0x4030($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4030);
    // 0x801E4BC8: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x801E4BCC: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801E4BD0: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801E4BD4: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x801E4BD8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E4BDC: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801E4BE0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801E4BE4: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x801E4BE8: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
L_801E4BEC:
    // 0x801E4BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4BF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E4BF4: jr          $ra
    // 0x801E4BF8: nop

    return;
    // 0x801E4BF8: nop

;}
RECOMP_FUNC void M25_FUN_801e4bfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4BFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4C00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4C04: jr          $ra
    // 0x801E4C08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801E4C08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4c0c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4c0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4C0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E4C10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E4C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4C18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E4C1C: lui         $a1, 0x2E8
    ctx->r5 = S32(0X2E8 << 16);
    // 0x801E4C20: ori         $a1, $a1, 0xA100
    ctx->r5 = ctx->r5 | 0XA100;
    // 0x801E4C24: jal         0x801C0B8C
    // 0x801E4C28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4C28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4C2C: beq         $v0, $zero, L_801E4CDC
    if (ctx->r2 == 0) {
        // 0x801E4C30: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E4CDC;
    }
    // 0x801E4C30: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E4C34: lui         $a1, 0x307
    ctx->r5 = S32(0X307 << 16);
    // 0x801E4C38: jal         0x801C0B8C
    // 0x801E4C3C: ori         $a1, $a1, 0x2580
    ctx->r5 = ctx->r5 | 0X2580;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E4C3C: ori         $a1, $a1, 0x2580
    ctx->r5 = ctx->r5 | 0X2580;
    after_1:
    // 0x801E4C40: beq         $v0, $zero, L_801E4CDC
    if (ctx->r2 == 0) {
        // 0x801E4C44: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801E4CDC;
    }
    // 0x801E4C44: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E4C48: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801E4C4C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801E4C50: lui         $at, 0x428F
    ctx->r1 = S32(0X428F << 16);
    // 0x801E4C54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E4C58: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E4C5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E4C60: lui         $at, 0x4297
    ctx->r1 = S32(0X4297 << 16);
    // 0x801E4C64: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E4C68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E4C6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E4C70: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E4C74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E4C78: addiu       $t8, $zero, 0x1100
    ctx->r24 = ADD32(0, 0X1100);
    // 0x801E4C7C: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801E4C80: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801E4C84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E4C88: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E4C8C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E4C90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E4C94: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E4C98: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801E4C9C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E4CA0: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801E4CA4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801E4CA8: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E4CAC: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801E4CB0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E4CB4: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801E4CB8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801E4CBC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E4CC0: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801E4CC4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801E4CC8: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801E4CCC: jal         0x801CC470
    // 0x801E4CD0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801E4CD0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801E4CD4: b           L_801E4D14
    // 0x801E4CD8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801E4D14;
    // 0x801E4CD8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E4CDC:
    // 0x801E4CDC: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
    // 0x801E4CE0: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x801E4CE4: jal         0x801D1720
    // 0x801E4CE8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801D1720)(rdram, ctx);
        goto after_3;
    // 0x801E4CE8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x801E4CEC: bne         $v0, $zero, L_801E4D08
    if (ctx->r2 != 0) {
        // 0x801E4CF0: lui         $a0, 0x1B8
        ctx->r4 = S32(0X1B8 << 16);
            goto L_801E4D08;
    }
    // 0x801E4CF0: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
    // 0x801E4CF4: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x801E4CF8: jal         0x801D1720
    // 0x801E4CFC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    LOOKUP_FUNC(0x801D1720)(rdram, ctx);
        goto after_4;
    // 0x801E4CFC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_4:
    // 0x801E4D00: beql        $v0, $zero, L_801E4D14
    if (ctx->r2 == 0) {
        // 0x801E4D04: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_801E4D14;
    }
    goto skip_0;
    // 0x801E4D04: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_0:
L_801E4D08:
    // 0x801E4D08: jal         0x8038D28C
    // 0x801E4D0C: addiu       $a0, $zero, 0x68F
    ctx->r4 = ADD32(0, 0X68F);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_5;
    // 0x801E4D0C: addiu       $a0, $zero, 0x68F
    ctx->r4 = ADD32(0, 0X68F);
    after_5:
    // 0x801E4D10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801E4D14:
    // 0x801E4D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4D18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E4D1C: jr          $ra
    // 0x801E4D20: nop

    return;
    // 0x801E4D20: nop

;}
RECOMP_FUNC void M25_FUN_801e4d24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4D24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E4D28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E4D2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4D30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E4D34: lui         $a1, 0x3F3
    ctx->r5 = S32(0X3F3 << 16);
    // 0x801E4D38: ori         $a1, $a1, 0xA860
    ctx->r5 = ctx->r5 | 0XA860;
    // 0x801E4D3C: jal         0x801C0B8C
    // 0x801E4D40: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4D40: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4D44: beq         $v0, $zero, L_801E4DE4
    if (ctx->r2 == 0) {
        // 0x801E4D48: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801E4DE4;
    }
    // 0x801E4D48: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E4D4C: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801E4D50: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801E4D54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4D58: lwc1        $f4, -0x402C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X402C);
    // 0x801E4D5C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E4D60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E4D64: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4D68: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E4D6C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E4D70: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x801E4D74: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E4D78: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801E4D7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E4D80: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801E4D84: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801E4D88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E4D8C: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801E4D90: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E4D94: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801E4D98: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E4D9C: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801E4DA0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801E4DA4: lwc1        $f8, -0x4028($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4028);
    // 0x801E4DA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E4DAC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E4DB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E4DB4: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801E4DB8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E4DBC: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801E4DC0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801E4DC4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E4DC8: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801E4DCC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801E4DD0: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801E4DD4: jal         0x801CC470
    // 0x801E4DD8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801E4DD8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801E4DDC: b           L_801E4DE8
    // 0x801E4DE0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801E4DE8;
    // 0x801E4DE0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801E4DE4:
    // 0x801E4DE4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E4DE8:
    // 0x801E4DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4DEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E4DF0: jr          $ra
    // 0x801E4DF4: nop

    return;
    // 0x801E4DF4: nop

;}
RECOMP_FUNC void M25_FUN_801e4df8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4DF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E4DFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4E00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E4E04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E4E08: jal         0x801BF6B0
    // 0x801E4E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801E4E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801E4E10: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801E4E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E4E18: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E4E1C: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x801E4E20: bne         $at, $zero, L_801E4E54
    if (ctx->r1 != 0) {
        // 0x801E4E24: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_801E4E54;
    }
    // 0x801E4E24: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801E4E28: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801E4E2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E4E30: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x801E4E34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E4E38: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801E4E3C: jal         0x801CC470
    // 0x801E4E40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801E4E40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801E4E44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4E48: sw          $zero, -0x4E24($at)
    MEM_W(-0X4E24, ctx->r1) = 0;
    // 0x801E4E4C: b           L_801E4E54
    // 0x801E4E50: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801E4E54;
    // 0x801E4E50: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E4E54:
    // 0x801E4E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E4E5C: jr          $ra
    // 0x801E4E60: nop

    return;
    // 0x801E4E60: nop

;}
RECOMP_FUNC void M25_FUN_801e4e64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4E64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E4E68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E4E6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4E70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E4E74: lui         $a1, 0x71B
    ctx->r5 = S32(0X71B << 16);
    // 0x801E4E78: ori         $a1, $a1, 0xEA70
    ctx->r5 = ctx->r5 | 0XEA70;
    // 0x801E4E7C: jal         0x801C0B8C
    // 0x801E4E80: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4E80: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4E84: beq         $v0, $zero, L_801E4EC8
    if (ctx->r2 == 0) {
        // 0x801E4E88: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E4EC8;
    }
    // 0x801E4E88: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E4E8C: lui         $a1, 0x8DA
    ctx->r5 = S32(0X8DA << 16);
    // 0x801E4E90: jal         0x801C0B8C
    // 0x801E4E94: ori         $a1, $a1, 0xFF90
    ctx->r5 = ctx->r5 | 0XFF90;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E4E94: ori         $a1, $a1, 0xFF90
    ctx->r5 = ctx->r5 | 0XFF90;
    after_1:
    // 0x801E4E98: beq         $v0, $zero, L_801E4EC8
    if (ctx->r2 == 0) {
        // 0x801E4E9C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801E4EC8;
    }
    // 0x801E4E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E4EA0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801E4EA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E4EA8: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E4EAC: ori         $a1, $a1, 0x15
    ctx->r5 = ctx->r5 | 0X15;
    // 0x801E4EB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E4EB4: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E4EB8: jal         0x801CC470
    // 0x801E4EBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801E4EBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801E4EC0: b           L_801E4ECC
    // 0x801E4EC4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801E4ECC;
    // 0x801E4EC4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801E4EC8:
    // 0x801E4EC8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E4ECC:
    // 0x801E4ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E4ED4: jr          $ra
    // 0x801E4ED8: nop

    return;
    // 0x801E4ED8: nop

;}
RECOMP_FUNC void M25_FUN_801e4edc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4EDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E4EE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E4EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E4EEC: lui         $a1, 0x90B
    ctx->r5 = S32(0X90B << 16);
    // 0x801E4EF0: ori         $a1, $a1, 0x103F
    ctx->r5 = ctx->r5 | 0X103F;
    // 0x801E4EF4: jal         0x801C0B8C
    // 0x801E4EF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4EF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4EFC: beq         $v0, $zero, L_801E4F0C
    if (ctx->r2 == 0) {
        // 0x801E4F00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E4F0C;
    }
    // 0x801E4F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4F04: b           L_801E4F10
    // 0x801E4F08: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801E4F10;
    // 0x801E4F08: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801E4F0C:
    // 0x801E4F0C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801E4F10:
    // 0x801E4F10: jr          $ra
    // 0x801E4F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801E4F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4f18(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4F18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E4F1C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E4F20: jr          $ra
    // 0x801E4F24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x801E4F24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4f28(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4f28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E4F2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E4F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E4F38: lui         $a1, 0x943
    ctx->r5 = S32(0X943 << 16);
    // 0x801E4F3C: ori         $a1, $a1, 0x855F
    ctx->r5 = ctx->r5 | 0X855F;
    // 0x801E4F40: jal         0x801C0B8C
    // 0x801E4F44: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E4F44: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E4F48: beql        $v0, $zero, L_801E4F5C
    if (ctx->r2 == 0) {
        // 0x801E4F4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E4F5C;
    }
    goto skip_0;
    // 0x801E4F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801E4F50: jal         0x801CC528
    // 0x801E4F54: nop

    LOOKUP_FUNC(0x801CC528)(rdram, ctx);
        goto after_1;
    // 0x801E4F54: nop

    after_1:
    // 0x801E4F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801E4F5C:
    // 0x801E4F5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E4F60: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801E4F64: jr          $ra
    // 0x801E4F68: nop

    return;
    // 0x801E4F68: nop

;}
RECOMP_FUNC void M25_FUN_801e4f6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4F6C: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E4F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E4F74: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E4F78: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E4F7C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E4F80: jal         0x801BF628
    // 0x801E4F84: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E4F84: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801E4F88: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E4F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E4F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E4F94: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E4F98: bne         $at, $zero, L_801E4FA8
    if (ctx->r1 != 0) {
        // 0x801E4F9C: nop
    
            goto L_801E4FA8;
    }
    // 0x801E4F9C: nop

    // 0x801E4FA0: b           L_801E4FA8
    // 0x801E4FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E4FA8;
    // 0x801E4FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E4FA8:
    // 0x801E4FA8: jr          $ra
    // 0x801E4FAC: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E4FAC: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4fb0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4fb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4FB0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E4FB4: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e4fb8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e4fb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4FB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E4FBC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E4FC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4FC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E4FC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E4FCC: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x801E4FD0: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801E4FD4: beql        $t7, $zero, L_801E5090
    if (ctx->r15 == 0) {
        // 0x801E4FD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801E5090;
    }
    goto skip_0;
    // 0x801E4FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801E4FDC: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x801E4FE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801E4FE4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E4FE8: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801E4FEC: lui         $a1, 0x139
    ctx->r5 = S32(0X139 << 16);
    // 0x801E4FF0: ori         $a1, $a1, 0x9170
    ctx->r5 = ctx->r5 | 0X9170;
    // 0x801E4FF4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801E4FF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E4FFC: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x801E5000: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E5004: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E5008: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E500C: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801E5010: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E5014: swc1        $f0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f0.u32l;
    // 0x801E5018: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E501C: lwc1        $f4, -0x4024($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4024);
    // 0x801E5020: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E5024: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E5028: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801E502C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801E5030: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    // 0x801E5034: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E5038: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E503C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E5040: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801E5044: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E5048: jal         0x801C0B8C
    // 0x801E504C: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E504C: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    after_0:
    // 0x801E5050: beql        $v0, $zero, L_801E5090
    if (ctx->r2 == 0) {
        // 0x801E5054: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801E5090;
    }
    goto skip_1;
    // 0x801E5054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801E5058: jal         0x801CED5C
    // 0x801E505C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CED5C)(rdram, ctx);
        goto after_1;
    // 0x801E505C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801E5060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E5064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E5068: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E506C: ori         $a1, $a1, 0x16
    ctx->r5 = ctx->r5 | 0X16;
    // 0x801E5070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801E5074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5078: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E507C: jal         0x801CC470
    // 0x801E5080: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801E5080: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801E5084: b           L_801E5090
    // 0x801E5088: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E5090;
    // 0x801E5088: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E508C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E5090:
    // 0x801E5090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E5094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E5098: jr          $ra
    // 0x801E509C: nop

    return;
    // 0x801E509C: nop

;}
RECOMP_FUNC void M25_FUN_801e50a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E50A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E50A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E50A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E50AC: jal         0x801CEDE4
    // 0x801E50B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CEDE4)(rdram, ctx);
        goto after_0;
    // 0x801E50B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801E50B4: beq         $v0, $zero, L_801E50E4
    if (ctx->r2 == 0) {
        // 0x801E50B8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801E50E4;
    }
    // 0x801E50B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801E50BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E50C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E50C4: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E50C8: ori         $a1, $a1, 0x16
    ctx->r5 = ctx->r5 | 0X16;
    // 0x801E50CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E50D0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801E50D4: jal         0x801CC470
    // 0x801E50D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801E50D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801E50DC: b           L_801E50E8
    // 0x801E50E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E50E8;
    // 0x801E50E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E50E4:
    // 0x801E50E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E50E8:
    // 0x801E50E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E50EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E50F0: jr          $ra
    // 0x801E50F4: nop

    return;
    // 0x801E50F4: nop

;}
RECOMP_FUNC void M25_FUN_801e50f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E50F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E50FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E5100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E5104: jal         0x801CEDE4
    // 0x801E5108: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CEDE4)(rdram, ctx);
        goto after_0;
    // 0x801E5108: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801E510C: beq         $v0, $zero, L_801E513C
    if (ctx->r2 == 0) {
        // 0x801E5110: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801E513C;
    }
    // 0x801E5110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801E5114: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E5118: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E511C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E5120: ori         $a1, $a1, 0x16
    ctx->r5 = ctx->r5 | 0X16;
    // 0x801E5124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5128: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E512C: jal         0x801CC470
    // 0x801E5130: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801E5130: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801E5134: b           L_801E5140
    // 0x801E5138: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E5140;
    // 0x801E5138: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E513C:
    // 0x801E513C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E5140:
    // 0x801E5140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E5144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E5148: jr          $ra
    // 0x801E514C: nop

    return;
    // 0x801E514C: nop

;}
RECOMP_FUNC void M25_FUN_801e5150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E5154: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E5158: jr          $ra
    // 0x801E515C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801E515C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5160(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5160: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E5164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E5168: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E516C: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E5170: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E5174: jal         0x801BF628
    // 0x801E5178: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E5178: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801E517C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E5180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E5184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E5188: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E518C: bne         $at, $zero, L_801E519C
    if (ctx->r1 != 0) {
        // 0x801E5190: nop
    
            goto L_801E519C;
    }
    // 0x801E5190: nop

    // 0x801E5194: b           L_801E519C
    // 0x801E5198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E519C;
    // 0x801E5198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E519C:
    // 0x801E519C: jr          $ra
    // 0x801E51A0: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E51A0: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e51a4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e51a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E51A4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E51A8: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e51ac(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e51ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E51AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E51B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E51B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E51B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E51BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E51C0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E51C4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E51C8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801E51CC: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801E51D0: beql        $t0, $zero, L_801E535C
    if (ctx->r8 == 0) {
        // 0x801E51D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801E535C;
    }
    goto skip_0;
    // 0x801E51D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801E51D8: jal         0x801CF450
    // 0x801E51DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CF450)(rdram, ctx);
        goto after_0;
    // 0x801E51DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801E51E0: lui         $a1, 0x294
    ctx->r5 = S32(0X294 << 16);
    // 0x801E51E4: ori         $a1, $a1, 0xB4A0
    ctx->r5 = ctx->r5 | 0XB4A0;
    // 0x801E51E8: jal         0x801C0B8C
    // 0x801E51EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E51EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_1:
    // 0x801E51F0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E51F4: beq         $v0, $zero, L_801E52B0
    if (ctx->r2 == 0) {
        // 0x801E51F8: addiu       $v1, $v1, -0x54EC
        ctx->r3 = ADD32(ctx->r3, -0X54EC);
            goto L_801E52B0;
    }
    // 0x801E51F8: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801E51FC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801E5200: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801E5204: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E5208: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E520C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E5210: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801E5214: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E5218: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E521C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E5220: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801E5224: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E5228: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E522C: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801E5230: ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    // 0x801E5234: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E5238: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801E523C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5240: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801E5244: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x801E5248: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801E524C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E5250: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801E5254: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E5258: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x801E525C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801E5260: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801E5264: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x801E5268: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801E526C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801E5270: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E5274: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801E5278: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801E527C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801E5280: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x801E5284: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E5288: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E528C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E5290: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E5294: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801E5298: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E529C: sh          $t9, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r25;
    // 0x801E52A0: jal         0x801CC470
    // 0x801E52A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801E52A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801E52A8: b           L_801E535C
    // 0x801E52AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E535C;
    // 0x801E52AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E52B0:
    // 0x801E52B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E52B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E52B8: lwc1        $f16, -0x4020($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4020);
    // 0x801E52BC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E52C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E52C4: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x801E52C8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E52CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E52D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E52D4: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801E52D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E52DC: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E52E0: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801E52E4: ori         $a1, $a1, 0x13
    ctx->r5 = ctx->r5 | 0X13;
    // 0x801E52E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E52EC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801E52F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E52F4: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801E52F8: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x801E52FC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801E5300: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801E5304: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x801E5308: lw          $t5, 0x8($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X8);
    // 0x801E530C: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801E5310: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E5314: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
    // 0x801E5318: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E531C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801E5320: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E5324: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E5328: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801E532C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801E5330: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x801E5334: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E5338: lw          $t5, 0x8($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X8);
    // 0x801E533C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801E5340: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E5344: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E5348: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801E534C: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x801E5350: jal         0x801CC470
    // 0x801E5354: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_3;
    // 0x801E5354: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801E5358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E535C:
    // 0x801E535C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E5360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E5364: jr          $ra
    // 0x801E5368: nop

    return;
    // 0x801E5368: nop

;}
RECOMP_FUNC void M25_FUN_801e536c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E536C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E5370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E5374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E5378: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E537C: lui         $a1, 0x46D
    ctx->r5 = S32(0X46D << 16);
    // 0x801E5380: ori         $a1, $a1, 0xBA60
    ctx->r5 = ctx->r5 | 0XBA60;
    // 0x801E5384: jal         0x801C0B8C
    // 0x801E5388: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E5388: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E538C: beql        $v0, $zero, L_801E53B0
    if (ctx->r2 == 0) {
        // 0x801E5390: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801E53B0;
    }
    goto skip_0;
    // 0x801E5390: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801E5394: jal         0x801CF450
    // 0x801E5398: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CF450)(rdram, ctx);
        goto after_1;
    // 0x801E5398: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801E539C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E53A0: sw          $zero, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = 0;
    // 0x801E53A4: b           L_801E53B0
    // 0x801E53A8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E53B0;
    // 0x801E53A8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801E53AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E53B0:
    // 0x801E53B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E53B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E53B8: jr          $ra
    // 0x801E53BC: nop

    return;
    // 0x801E53BC: nop

;}
RECOMP_FUNC void M25_FUN_801e53c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E53C0: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x801E53C4: lw          $t6, -0x4DDC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4DDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e53c8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e53c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E53C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E53CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E53D0: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x801E53D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E53D8: beq         $at, $zero, L_801E5594
    if (ctx->r1 == 0) {
        // 0x801E53DC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801E5594;
    }
    // 0x801E53DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E53E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E53E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E53E8: addu        $at, $at, $t6
    gpr jr_addend_801E53F0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801E53EC: lw          $t6, -0x401C($at)
    ctx->r14 = ADD32(ctx->r1, -0X401C);
    // 0x801E53F0: jr          $t6
    // 0x801E53F4: nop

    switch (jr_addend_801E53F0 >> 2) {
        case 0: goto L_801E53F8; break;
        case 1: goto L_801E542C; break;
        case 2: goto L_801E546C; break;
        case 3: goto L_801E54AC; break;
        case 4: goto L_801E54EC; break;
        case 5: goto L_801E553C; break;
        case 6: goto L_801E557C; break;
        default: switch_error(__func__, 0x801E53F0, 0x801FBFE4);
    }
    // 0x801E53F4: nop

L_801E53F8:
    // 0x801E53F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801E53FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E5400: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E5404: ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    // 0x801E5408: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E540C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5410: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E5414: jal         0x801CC470
    // 0x801E5418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801E5418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801E541C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801E5420: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E5424: b           L_801E5594
    // 0x801E5428: sw          $t7, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r15;
        goto L_801E5594;
    // 0x801E5428: sw          $t7, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r15;
L_801E542C:
    // 0x801E542C: jal         0x801CF3CC
    // 0x801E5430: nop

    LOOKUP_FUNC(0x801CF3CC)(rdram, ctx);
        goto after_1;
    // 0x801E5430: nop

    after_1:
    // 0x801E5434: beq         $v0, $zero, L_801E5594
    if (ctx->r2 == 0) {
        // 0x801E5438: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801E5594;
    }
    // 0x801E5438: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E543C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801E5440: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E5444: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E5448: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x801E544C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5450: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E5454: jal         0x801CC470
    // 0x801E5458: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801E5458: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801E545C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E5460: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E5464: b           L_801E5594
    // 0x801E5468: sw          $t8, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r24;
        goto L_801E5594;
    // 0x801E5468: sw          $t8, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r24;
L_801E546C:
    // 0x801E546C: jal         0x801CF3CC
    // 0x801E5470: nop

    LOOKUP_FUNC(0x801CF3CC)(rdram, ctx);
        goto after_3;
    // 0x801E5470: nop

    after_3:
    // 0x801E5474: beq         $v0, $zero, L_801E5594
    if (ctx->r2 == 0) {
        // 0x801E5478: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801E5594;
    }
    // 0x801E5478: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E547C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801E5480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E5484: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E5488: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x801E548C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5490: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E5494: jal         0x801CC470
    // 0x801E5498: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_4;
    // 0x801E5498: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x801E549C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801E54A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E54A4: b           L_801E5594
    // 0x801E54A8: sw          $t9, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r25;
        goto L_801E5594;
    // 0x801E54A8: sw          $t9, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r25;
L_801E54AC:
    // 0x801E54AC: jal         0x801CF3CC
    // 0x801E54B0: nop

    LOOKUP_FUNC(0x801CF3CC)(rdram, ctx);
        goto after_5;
    // 0x801E54B0: nop

    after_5:
    // 0x801E54B4: beq         $v0, $zero, L_801E5594
    if (ctx->r2 == 0) {
        // 0x801E54B8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801E5594;
    }
    // 0x801E54B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E54BC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801E54C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E54C4: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E54C8: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x801E54CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E54D0: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E54D4: jal         0x801CC470
    // 0x801E54D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_6;
    // 0x801E54D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x801E54DC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801E54E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E54E4: b           L_801E5594
    // 0x801E54E8: sw          $t0, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r8;
        goto L_801E5594;
    // 0x801E54E8: sw          $t0, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r8;
L_801E54EC:
    // 0x801E54EC: lui         $a1, 0x69D
    ctx->r5 = S32(0X69D << 16);
    // 0x801E54F0: ori         $a1, $a1, 0x4490
    ctx->r5 = ctx->r5 | 0X4490;
    // 0x801E54F4: jal         0x801C0B8C
    // 0x801E54F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_7;
    // 0x801E54F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_7:
    // 0x801E54FC: beq         $v0, $zero, L_801E5594
    if (ctx->r2 == 0) {
        // 0x801E5500: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801E5594;
    }
    // 0x801E5500: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E5504: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801E5508: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E550C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E5510: ori         $a1, $a1, 0x5
    ctx->r5 = ctx->r5 | 0X5;
    // 0x801E5514: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5518: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E551C: jal         0x801CC4D8
    // 0x801E5520: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801CC4D8)(rdram, ctx);
        goto after_8;
    // 0x801E5520: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x801E5524: jal         0x801CF450
    // 0x801E5528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CF450)(rdram, ctx);
        goto after_9;
    // 0x801E5528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x801E552C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801E5530: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E5534: b           L_801E5594
    // 0x801E5538: sw          $t1, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r9;
        goto L_801E5594;
    // 0x801E5538: sw          $t1, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r9;
L_801E553C:
    // 0x801E553C: jal         0x801CF3BC
    // 0x801E5540: nop

    LOOKUP_FUNC(0x801CF3BC)(rdram, ctx);
        goto after_10;
    // 0x801E5540: nop

    after_10:
    // 0x801E5544: bne         $v0, $zero, L_801E5594
    if (ctx->r2 != 0) {
        // 0x801E5548: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801E5594;
    }
    // 0x801E5548: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E554C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801E5550: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E5554: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E5558: ori         $a1, $a1, 0x5
    ctx->r5 = ctx->r5 | 0X5;
    // 0x801E555C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5560: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801E5564: jal         0x801CC470
    // 0x801E5568: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_11;
    // 0x801E5568: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x801E556C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x801E5570: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E5574: b           L_801E5594
    // 0x801E5578: sw          $t2, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r10;
        goto L_801E5594;
    // 0x801E5578: sw          $t2, -0x4DDC($at)
    MEM_W(-0X4DDC, ctx->r1) = ctx->r10;
L_801E557C:
    // 0x801E557C: jal         0x801CF3CC
    // 0x801E5580: nop

    LOOKUP_FUNC(0x801CF3CC)(rdram, ctx);
        goto after_12;
    // 0x801E5580: nop

    after_12:
    // 0x801E5584: beql        $v0, $zero, L_801E5598
    if (ctx->r2 == 0) {
        // 0x801E5588: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801E5598;
    }
    goto skip_0;
    // 0x801E5588: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x801E558C: b           L_801E5598
    // 0x801E5590: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E5598;
    // 0x801E5590: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E5594:
    // 0x801E5594: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E5598:
    // 0x801E5598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E559C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E55A0: jr          $ra
    // 0x801E55A4: nop

    return;
    // 0x801E55A4: nop

;}
RECOMP_FUNC void M25_FUN_801e55a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E55A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E55AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E55B0: jr          $ra
    // 0x801E55B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E55B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e55b8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e55b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E55B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E55BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E55C0: jr          $ra
    // 0x801E55C4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801E55C4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e55c8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e55c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E55C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E55CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E55D0: jr          $ra
    // 0x801E55D4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x801E55D4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e55d8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e55d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E55D8: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801E55DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E55E0: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801E55E4: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801E55E8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801E55EC: jal         0x801BF628
    // 0x801E55F0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801E55F0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801E55F4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801E55F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E55FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801E5600: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E5604: bne         $at, $zero, L_801E5614
    if (ctx->r1 != 0) {
        // 0x801E5608: nop
    
            goto L_801E5614;
    }
    // 0x801E5608: nop

    // 0x801E560C: b           L_801E5614
    // 0x801E5610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E5614;
    // 0x801E5610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E5614:
    // 0x801E5614: jr          $ra
    // 0x801E5618: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801E5618: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e561c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e561c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E561C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E5620: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5624(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E5628: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E562C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E5630: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E5634: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E5638: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E563C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801E5640: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E5644: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801E5648: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E564C: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x801E5650: beql        $v0, $zero, L_801E5700
    if (ctx->r2 == 0) {
        // 0x801E5654: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801E5700;
    }
    goto skip_0;
    // 0x801E5654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801E5658: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E565C: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x801E5660: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E5664: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x801E5668: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801E566C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E5670: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E5674: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E5678: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E567C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E5680: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E5684: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801E5688: ori         $a1, $a1, 0x13
    ctx->r5 = ctx->r5 | 0X13;
    // 0x801E568C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801E5690: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E5694: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5698: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801E569C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801E56A0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801E56A4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801E56A8: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801E56AC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E56B0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E56B4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E56B8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E56BC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E56C0: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801E56C4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E56C8: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x801E56CC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E56D0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E56D4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E56D8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801E56DC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E56E0: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801E56E4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801E56E8: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    // 0x801E56EC: jal         0x801CC470
    // 0x801E56F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801E56F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801E56F4: b           L_801E5700
    // 0x801E56F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E5700;
    // 0x801E56F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E56FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E5700:
    // 0x801E5700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E5704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E5708: jr          $ra
    // 0x801E570C: nop

    return;
    // 0x801E570C: nop

;}
RECOMP_FUNC void M25_FUN_801e5710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5710: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E5714: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E5718: jr          $ra
    // 0x801E571C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E571C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5720(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5720: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E5724: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E5728: jr          $ra
    // 0x801E572C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E572C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5730(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5730: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E5734: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E5738: jr          $ra
    // 0x801E573C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E573C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5740(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E5744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E5748: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E574C: addiu       $a1, $a1, 0x1110
    ctx->r5 = ADD32(ctx->r5, 0X1110);
    // 0x801E5750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E5754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E5758: addiu       $t6, $zero, 0x1180
    ctx->r14 = ADD32(0, 0X1180);
    // 0x801E575C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801E5760: jal         0x801C2570
    // 0x801E5764: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    LOOKUP_FUNC(0x801C2570)(rdram, ctx);
        goto after_0;
    // 0x801E5764: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_0:
    // 0x801E5768: jal         0x801CDD20
    // 0x801E576C: nop

    LOOKUP_FUNC(0x801CDD20)(rdram, ctx);
        goto after_1;
    // 0x801E576C: nop

    after_1:
    // 0x801E5770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E5774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E5778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E577C: jr          $ra
    // 0x801E5780: nop

    return;
    // 0x801E5780: nop

;}
RECOMP_FUNC void M25_FUN_801e5784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E5788: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E578C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E5790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E5794: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E5798: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E579C: lw          $a0, -0x53B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B8);
    // 0x801E57A0: jal         0x80005E44
    // 0x801E57A4: addiu       $a1, $a1, -0x5410
    ctx->r5 = ADD32(ctx->r5, -0X5410);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801E57A4: addiu       $a1, $a1, -0x5410
    ctx->r5 = ADD32(ctx->r5, -0X5410);
    after_0:
    // 0x801E57A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E57AC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E57B0: addiu       $a1, $a1, -0x5400
    ctx->r5 = ADD32(ctx->r5, -0X5400);
    // 0x801E57B4: jal         0x80005E44
    // 0x801E57B8: lw          $a0, -0x53B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B8);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x801E57B8: lw          $a0, -0x53B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B8);
    after_1:
    // 0x801E57BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E57C0: jal         0x80006214
    // 0x801E57C4: lw          $a0, -0x53B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B8);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801E57C4: lw          $a0, -0x53B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B8);
    after_2:
    // 0x801E57C8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E57CC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801E57D0: addiu       $v1, $v1, -0x5418
    ctx->r3 = ADD32(ctx->r3, -0X5418);
    // 0x801E57D4: addiu       $t6, $t6, 0xD10
    ctx->r14 = ADD32(ctx->r14, 0XD10);
    // 0x801E57D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801E57DC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801E57E0: lui         $a3, 0xDF00
    ctx->r7 = S32(0XDF00 << 16);
    // 0x801E57E4: addiu       $t7, $t7, 0xF10
    ctx->r15 = ADD32(ctx->r15, 0XF10);
    // 0x801E57E8: sw          $a3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r7;
    // 0x801E57EC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801E57F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801E57F4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801E57F8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801E57FC: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801E5800: addiu       $t0, $t0, -0x53B4
    ctx->r8 = ADD32(ctx->r8, -0X53B4);
    // 0x801E5804: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x801E5808: sw          $a3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r7;
    // 0x801E580C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x801E5810: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E5814: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E5818: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x801E581C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801E5820: sw          $zero, 0x30($t2)
    MEM_W(0X30, ctx->r10) = 0;
    // 0x801E5824: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x801E5828: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801E582C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801E5830: sw          $zero, 0x28($t5)
    MEM_W(0X28, ctx->r13) = 0;
    // 0x801E5834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E5838: sw          $zero, -0x4D94($at)
    MEM_W(-0X4D94, ctx->r1) = 0;
    // 0x801E583C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E5840: jr          $ra
    // 0x801E5844: nop

    return;
    // 0x801E5844: nop

;}
RECOMP_FUNC void M25_FUN_801e5848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5848: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801E584C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801E5850: lh          $t6, -0x6CB4($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6CB4);
    // 0x801E5854: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801E5858: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801E585C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801E5860: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801E5864: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801E5868: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801E586C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801E5870: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801E5874: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801E5878: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801E587C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801E5880: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801E5884: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801E5888: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801E588C: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x801E5890: bne         $t6, $zero, L_801E58A8
    if (ctx->r14 != 0) {
        // 0x801E5894: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_801E58A8;
    }
    // 0x801E5894: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x801E5898: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E589C: addiu       $v1, $a0, 0xD10
    ctx->r3 = ADD32(ctx->r4, 0XD10);
    // 0x801E58A0: b           L_801E58B4
    // 0x801E58A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_801E58B4;
    // 0x801E58A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801E58A8:
    // 0x801E58A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E58AC: addiu       $v1, $a0, 0xF10
    ctx->r3 = ADD32(ctx->r4, 0XF10);
    // 0x801E58B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801E58B4:
    // 0x801E58B4: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801E58B8: addiu       $a2, $a2, -0x53B4
    ctx->r6 = ADD32(ctx->r6, -0X53B4);
    // 0x801E58BC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x801E58C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E58C4: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x801E58C8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801E58CC: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801E58D0: addiu       $s1, $s1, -0x5418
    ctx->r17 = ADD32(ctx->r17, -0X5418);
    // 0x801E58D4: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x801E58D8: lui         $a1, 0x33
    ctx->r5 = S32(0X33 << 16);
    // 0x801E58DC: ori         $a1, $a1, 0xE140
    ctx->r5 = ctx->r5 | 0XE140;
    // 0x801E58E0: sw          $t7, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r15;
    // 0x801E58E4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x801E58E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E58EC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801E58F0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E58F4: sw          $zero, 0x28($t6)
    MEM_W(0X28, ctx->r14) = 0;
    // 0x801E58F8: jal         0x801C0B8C
    // 0x801E58FC: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E58FC: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    after_0:
    // 0x801E5900: beq         $v0, $zero, L_801E5928
    if (ctx->r2 == 0) {
        // 0x801E5904: nop
    
            goto L_801E5928;
    }
    // 0x801E5904: nop

    // 0x801E5908: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E590C: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x801E5910: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801E5914: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x801E5918: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x801E591C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5920: b           L_801E5ED0
    // 0x801E5924: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
        goto L_801E5ED0;
    // 0x801E5924: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_801E5928:
    // 0x801E5928: jal         0x801302CC
    // 0x801E592C: nop

    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_1;
    // 0x801E592C: nop

    after_1:
    // 0x801E5930: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x801E5934: addiu       $s4, $s4, 0x1CF0
    ctx->r20 = ADD32(ctx->r20, 0X1CF0);
    // 0x801E5938: lw          $t7, 0x290($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X290);
    // 0x801E593C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801E5940: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x801E5944: jal         0x80001060
    // 0x801E5948: lhu         $s3, 0x0($t3)
    ctx->r19 = MEM_HU(ctx->r11, 0X0);
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_2;
    // 0x801E5948: lhu         $s3, 0x0($t3)
    ctx->r19 = MEM_HU(ctx->r11, 0X0);
    after_2:
    // 0x801E594C: beq         $v0, $zero, L_801E596C
    if (ctx->r2 == 0) {
        // 0x801E5950: addiu       $s6, $zero, 0xA0
        ctx->r22 = ADD32(0, 0XA0);
            goto L_801E596C;
    }
    // 0x801E5950: addiu       $s6, $zero, 0xA0
    ctx->r22 = ADD32(0, 0XA0);
    // 0x801E5954: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E5958: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x801E595C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801E5960: addiu       $s6, $zero, 0x140
    ctx->r22 = ADD32(0, 0X140);
    // 0x801E5964: b           L_801E597C
    // 0x801E5968: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
        goto L_801E597C;
    // 0x801E5968: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
L_801E596C:
    // 0x801E596C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E5970: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x801E5974: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801E5978: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
L_801E597C:
    // 0x801E597C: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
    // 0x801E5980: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5984: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801E5988: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x801E598C: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x801E5990: addiu       $t5, $t5, -0x53F0
    ctx->r13 = ADD32(ctx->r13, -0X53F0);
    // 0x801E5994: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801E5998: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x801E599C: lui         $s5, 0xFD10
    ctx->r21 = S32(0XFD10 << 16);
    // 0x801E59A0: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x801E59A4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801E59A8: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801E59AC: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801E59B0: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x801E59B4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x801E59B8: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x801E59BC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x801E59C0: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x801E59C4: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x801E59C8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E59CC: ori         $t9, $t9, 0x7008
    ctx->r25 = ctx->r25 | 0X7008;
    // 0x801E59D0: lui         $t4, 0xFFFC
    ctx->r12 = S32(0XFFFC << 16);
    // 0x801E59D4: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801E59D8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801E59DC: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x801E59E0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801E59E4: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E59E8: lui         $t3, 0xFCFF
    ctx->r11 = S32(0XFCFF << 16);
    // 0x801E59EC: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x801E59F0: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x801E59F4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801E59F8: ori         $t4, $t4, 0xF279
    ctx->r12 = ctx->r12 | 0XF279;
    // 0x801E59FC: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x801E5A00: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x801E5A04: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801E5A08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801E5A0C: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x801E5A10: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x801E5A14: sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    // 0x801E5A18: jal         0x8000522C
    // 0x801E5A1C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_3;
    // 0x801E5A1C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x801E5A20: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x801E5A24: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5A28: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x801E5A2C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x801E5A30: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801E5A34: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801E5A38: lui         $s4, 0xF510
    ctx->r20 = S32(0XF510 << 16);
    // 0x801E5A3C: sw          $s4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r20;
    // 0x801E5A40: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x801E5A44: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5A48: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x801E5A4C: lui         $t5, 0x707
    ctx->r13 = S32(0X707 << 16);
    // 0x801E5A50: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x801E5A54: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801E5A58: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5A5C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801E5A60: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5A64: ori         $t5, $t5, 0xF200
    ctx->r13 = ctx->r13 | 0XF200;
    // 0x801E5A68: lui         $t4, 0xF300
    ctx->r12 = S32(0XF300 << 16);
    // 0x801E5A6C: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x801E5A70: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x801E5A74: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x801E5A78: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x801E5A7C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5A80: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801E5A84: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x801E5A88: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801E5A8C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801E5A90: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5A94: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801E5A98: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5A9C: lui         $t7, 0xF510
    ctx->r15 = S32(0XF510 << 16);
    // 0x801E5AA0: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x801E5AA4: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x801E5AA8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801E5AAC: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x801E5AB0: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x801E5AB4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801E5AB8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5ABC: lui         $t6, 0x3
    ctx->r14 = S32(0X3 << 16);
    // 0x801E5AC0: ori         $t6, $t6, 0xC01C
    ctx->r14 = ctx->r14 | 0XC01C;
    // 0x801E5AC4: addiu       $t4, $a2, 0x8
    ctx->r12 = ADD32(ctx->r6, 0X8);
    // 0x801E5AC8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801E5ACC: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x801E5AD0: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x801E5AD4: bne         $s2, $zero, L_801E5C4C
    if (ctx->r18 != 0) {
        // 0x801E5AD8: sw          $t6, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r14;
            goto L_801E5C4C;
    }
    // 0x801E5AD8: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x801E5ADC: jal         0x80001060
    // 0x801E5AE0: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_4;
    // 0x801E5AE0: nop

    after_4:
    // 0x801E5AE4: beq         $v0, $zero, L_801E5AF4
    if (ctx->r2 == 0) {
        // 0x801E5AE8: addiu       $a3, $zero, 0x200
        ctx->r7 = ADD32(0, 0X200);
            goto L_801E5AF4;
    }
    // 0x801E5AE8: addiu       $a3, $zero, 0x200
    ctx->r7 = ADD32(0, 0X200);
    // 0x801E5AEC: b           L_801E5AF4
    // 0x801E5AF0: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
        goto L_801E5AF4;
    // 0x801E5AF0: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
L_801E5AF4:
    // 0x801E5AF4: mtc1        $s6, $f4
    ctx->f4.u32l = ctx->r22;
    // 0x801E5AF8: addiu       $t4, $zero, -0x69
    ctx->r12 = ADD32(0, -0X69);
    // 0x801E5AFC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x801E5B00: cvt.s.w     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801E5B04: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x801E5B08: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x801E5B0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E5B10: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801E5B14: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801E5B18: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x801E5B1C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5B20: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801E5B24: lui         $s7, 0xE400
    ctx->r23 = S32(0XE400 << 16);
    // 0x801E5B28: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x801E5B2C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x801E5B30: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801E5B34: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x801E5B38: lui         $fp, 0xE100
    ctx->r30 = S32(0XE100 << 16);
    // 0x801E5B3C: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x801E5B40: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801E5B44: add.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x801E5B48: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x801E5B4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E5B50: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801E5B54: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x801E5B58: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x801E5B5C: nop

    // 0x801E5B60: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x801E5B64: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x801E5B68: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x801E5B6C: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x801E5B70: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801E5B74: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801E5B78: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x801E5B7C: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x801E5B80: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801E5B84: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x801E5B88: or          $t3, $t5, $s7
    ctx->r11 = ctx->r13 | ctx->r23;
    // 0x801E5B8C: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x801E5B90: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x801E5B94: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801E5B98: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801E5B9C: nop

    // 0x801E5BA0: addu        $t5, $t8, $t4
    ctx->r13 = ADD32(ctx->r24, ctx->r12);
    // 0x801E5BA4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x801E5BA8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x801E5BAC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x801E5BB0: addiu       $t4, $zero, -0x69
    ctx->r12 = ADD32(0, -0X69);
    // 0x801E5BB4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801E5BB8: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x801E5BBC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801E5BC0: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x801E5BC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801E5BC8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801E5BCC: nop

    // 0x801E5BD0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801E5BD4: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x801E5BD8: nop

    // 0x801E5BDC: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x801E5BE0: add.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x801E5BE4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801E5BE8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801E5BEC: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x801E5BF0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801E5BF4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x801E5BF8: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x801E5BFC: sll         $t7, $t3, 12
    ctx->r15 = S32(ctx->r11 << 12);
    // 0x801E5C00: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801E5C04: nop

    // 0x801E5C08: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801E5C0C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x801E5C10: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x801E5C14: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x801E5C18: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5C1C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x801E5C20: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x801E5C24: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x801E5C28: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x801E5C2C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5C30: sw          $fp, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r30;
    // 0x801E5C34: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5C38: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x801E5C3C: addiu       $t4, $a2, 0x8
    ctx->r12 = ADD32(ctx->r6, 0X8);
    // 0x801E5C40: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801E5C44: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x801E5C48: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_801E5C4C:
    // 0x801E5C4C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801E5C50: lui         $s7, 0xE400
    ctx->r23 = S32(0XE400 << 16);
    // 0x801E5C54: lui         $fp, 0xE100
    ctx->r30 = S32(0XE100 << 16);
    // 0x801E5C58: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x801E5C5C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801E5C60: sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    // 0x801E5C64: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x801E5C68: jal         0x8000522C
    // 0x801E5C6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_5;
    // 0x801E5C6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x801E5C70: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x801E5C74: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5C78: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x801E5C7C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x801E5C80: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x801E5C84: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x801E5C88: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x801E5C8C: sw          $s4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r20;
    // 0x801E5C90: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5C94: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x801E5C98: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x801E5C9C: addiu       $t4, $a2, 0x8
    ctx->r12 = ADD32(ctx->r6, 0X8);
    // 0x801E5CA0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801E5CA4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5CA8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x801E5CAC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5CB0: ori         $t9, $t9, 0xF800
    ctx->r25 = ctx->r25 | 0XF800;
    // 0x801E5CB4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x801E5CB8: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801E5CBC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801E5CC0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x801E5CC4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801E5CC8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5CCC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801E5CD0: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x801E5CD4: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x801E5CD8: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x801E5CDC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5CE0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801E5CE4: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5CE8: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x801E5CEC: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x801E5CF0: addiu       $t4, $a2, 0x8
    ctx->r12 = ADD32(ctx->r6, 0X8);
    // 0x801E5CF4: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801E5CF8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x801E5CFC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x801E5D00: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x801E5D04: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5D08: ori         $t3, $zero, 0xC03C
    ctx->r11 = 0 | 0XC03C;
    // 0x801E5D0C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x801E5D10: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x801E5D14: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801E5D18: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x801E5D1C: bne         $s2, $zero, L_801E5EB4
    if (ctx->r18 != 0) {
        // 0x801E5D20: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_801E5EB4;
    }
    // 0x801E5D20: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801E5D24: jal         0x801C0B2C
    // 0x801E5D28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_6;
    // 0x801E5D28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_6:
    // 0x801E5D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E5D30: jal         0x80034C24
    // 0x801E5D34: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_7;
    // 0x801E5D34: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_7:
    // 0x801E5D38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E5D3C: ldc1        $f20, -0x4000($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X4000);
    // 0x801E5D40: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801E5D44: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801E5D48: div.d       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f0.d, ctx->f20.d);
    // 0x801E5D4C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801E5D50: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801E5D54: add.d       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = ctx->f16.d + ctx->f22.d;
    // 0x801E5D58: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x801E5D5C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801E5D60: nop

    // 0x801E5D64: blezl       $t4, L_801E5EB8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x801E5D68: lw          $a2, 0x0($s1)
        ctx->r6 = MEM_W(ctx->r17, 0X0);
            goto L_801E5EB8;
    }
    goto skip_0;
    // 0x801E5D68: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x801E5D6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E5D70: mtc1        $s6, $f6
    ctx->f6.u32l = ctx->r22;
    // 0x801E5D74: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x801E5D78: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x801E5D7C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x801E5D80: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801E5D84: sll         $s0, $s2, 3
    ctx->r16 = S32(ctx->r18 << 3);
    // 0x801E5D88: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801E5D8C: subu        $s0, $s0, $s2
    ctx->r16 = SUB32(ctx->r16, ctx->r18);
    // 0x801E5D90: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801E5D94: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801E5D98: lui         $s6, 0x400
    ctx->r22 = S32(0X400 << 16);
    // 0x801E5D9C: ori         $s6, $s6, 0x400
    ctx->r22 = ctx->r22 | 0X400;
    // 0x801E5DA0: addiu       $s0, $s0, -0x44
    ctx->r16 = ADD32(ctx->r16, -0X44);
    // 0x801E5DA4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801E5DA8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801E5DAC: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x801E5DB0: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x801E5DB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E5DB8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801E5DBC: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x801E5DC0: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801E5DC4: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801E5DC8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801E5DCC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801E5DD0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801E5DD4: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x801E5DD8: mfc1        $s5, $f4
    ctx->r21 = (int32_t)ctx->f4.u32l;
    // 0x801E5DDC: addu        $s4, $t3, $t4
    ctx->r20 = ADD32(ctx->r11, ctx->r12);
    // 0x801E5DE0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x801E5DE4: sll         $s4, $s4, 2
    ctx->r20 = S32(ctx->r20 << 2);
    // 0x801E5DE8: sll         $s5, $s5, 2
    ctx->r21 = S32(ctx->r21 << 2);
    // 0x801E5DEC: andi        $s5, $s5, 0xFFF
    ctx->r21 = ctx->r21 & 0XFFF;
    // 0x801E5DF0: andi        $s4, $s4, 0xFFF
    ctx->r20 = ctx->r20 & 0XFFF;
    // 0x801E5DF4: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
L_801E5DF8:
    // 0x801E5DF8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5DFC: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
    // 0x801E5E00: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801E5E04: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801E5E08: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801E5E0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801E5E10: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x801E5E14: add.s       $f6, $f24, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x801E5E18: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801E5E1C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801E5E20: nop

    // 0x801E5E24: addu        $t9, $s3, $a1
    ctx->r25 = ADD32(ctx->r19, ctx->r5);
    // 0x801E5E28: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x801E5E2C: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x801E5E30: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x801E5E34: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x801E5E38: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x801E5E3C: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x801E5E40: or          $t6, $t5, $s7
    ctx->r14 = ctx->r13 | ctx->r23;
    // 0x801E5E44: sll         $t3, $t8, 12
    ctx->r11 = S32(ctx->r24 << 12);
    // 0x801E5E48: or          $t4, $t3, $s5
    ctx->r12 = ctx->r11 | ctx->r21;
    // 0x801E5E4C: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x801E5E50: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801E5E54: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x801E5E58: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5E5C: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x801E5E60: addiu       $t5, $a2, 0x8
    ctx->r13 = ADD32(ctx->r6, 0X8);
    // 0x801E5E64: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x801E5E68: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5E6C: sw          $fp, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r30;
    // 0x801E5E70: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801E5E74: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801E5E78: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801E5E7C: sw          $s6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r22;
    // 0x801E5E80: jal         0x801C0B2C
    // 0x801E5E84: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_8;
    // 0x801E5E84: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    after_8:
    // 0x801E5E88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E5E8C: jal         0x80034C24
    // 0x801E5E90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_9;
    // 0x801E5E90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_9:
    // 0x801E5E94: div.d       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f20.d);
    // 0x801E5E98: add.d       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f4.d + ctx->f22.d;
    // 0x801E5E9C: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801E5EA0: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801E5EA4: nop

    // 0x801E5EA8: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801E5EAC: bnel        $at, $zero, L_801E5DF8
    if (ctx->r1 != 0) {
        // 0x801E5EB0: mtc1        $s0, $f10
        ctx->f10.u32l = ctx->r16;
            goto L_801E5DF8;
    }
    goto skip_1;
    // 0x801E5EB0: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    skip_1:
L_801E5EB4:
    // 0x801E5EB4: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
L_801E5EB8:
    // 0x801E5EB8: lui         $t4, 0xDF00
    ctx->r12 = S32(0XDF00 << 16);
    // 0x801E5EBC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E5EC0: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x801E5EC4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x801E5EC8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801E5ECC: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
L_801E5ED0:
    // 0x801E5ED0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801E5ED4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801E5ED8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801E5EDC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801E5EE0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801E5EE4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801E5EE8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801E5EEC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801E5EF0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801E5EF4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801E5EF8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801E5EFC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801E5F00: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x801E5F04: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x801E5F08: jr          $ra
    // 0x801E5F0C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801E5F0C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5f10(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5f10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5F10: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E5F14: addiu       $v0, $v0, -0x53B4
    ctx->r2 = ADD32(ctx->r2, -0X53B4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5f18(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E5F1C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801E5F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E5F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E5F28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E5F2C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801E5F30: lui         $a1, 0x294
    ctx->r5 = S32(0X294 << 16);
    // 0x801E5F34: ori         $a1, $a1, 0xB4A0
    ctx->r5 = ctx->r5 | 0XB4A0;
    // 0x801E5F38: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E5F3C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E5F40: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
    // 0x801E5F44: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801E5F48: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801E5F4C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801E5F50: jal         0x801C0B8C
    // 0x801E5F54: sw          $zero, 0x28($t1)
    MEM_W(0X28, ctx->r9) = 0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E5F54: sw          $zero, 0x28($t1)
    MEM_W(0X28, ctx->r9) = 0;
    after_0:
    // 0x801E5F58: beq         $v0, $zero, L_801E5F68
    if (ctx->r2 == 0) {
        // 0x801E5F5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E5F68;
    }
    // 0x801E5F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E5F60: b           L_801E5F6C
    // 0x801E5F64: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E5F6C;
    // 0x801E5F64: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E5F68:
    // 0x801E5F68: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E5F6C:
    // 0x801E5F6C: jr          $ra
    // 0x801E5F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801E5F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5f74(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5f74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5F74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E5F78: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E5F7C: jr          $ra
    // 0x801E5F80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E5F80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5f84(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5f84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5F84: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E5F88: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e5f8c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e5f8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5F8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E5F90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E5F94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E5F98: beq         $t6, $zero, L_801E5FA8
    if (ctx->r14 == 0) {
        // 0x801E5F9C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801E5FA8;
    }
    // 0x801E5F9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E5FA0: b           L_801E5FE0
    // 0x801E5FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801E5FE0;
    // 0x801E5FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E5FA8:
    // 0x801E5FA8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E5FAC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E5FB0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801E5FB4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E5FB8: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E5FBC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E5FC0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E5FC4: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E5FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E5FCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E5FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E5FD4: jal         0x8038C97C
    // 0x801E5FD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_0;
    // 0x801E5FD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x801E5FDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E5FE0:
    // 0x801E5FE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E5FE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E5FE8: jr          $ra
    // 0x801E5FEC: nop

    return;
    // 0x801E5FEC: nop

;}
RECOMP_FUNC void M25_FUN_801e5ff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E5FF0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E5FF4: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E5FF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E5FFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6000: beq         $t6, $zero, L_801E6010
    if (ctx->r14 == 0) {
            // 0x801E6004: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801E6010)(rdram, ctx);
    return;
    }
    // 0x801E6004: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E6008: jr          $ra
    // 0x801E600C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E600C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6010(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6010: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E6014: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E6018: jr          $ra
    // 0x801E601C: nop

    return;
    // 0x801E601C: nop

;}
RECOMP_FUNC void M25_FUN_801e6020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6020: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E6024: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E6028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E602C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E6030: lui         $a1, 0x2F7
    ctx->r5 = S32(0X2F7 << 16);
    // 0x801E6034: ori         $a1, $a1, 0xE340
    ctx->r5 = ctx->r5 | 0XE340;
    // 0x801E6038: jal         0x801C0B8C
    // 0x801E603C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E603C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6040: beq         $v0, $zero, L_801E608C
    if (ctx->r2 == 0) {
        // 0x801E6044: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801E608C;
    }
    // 0x801E6044: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E6048: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E604C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E6050: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E6054: bne         $t6, $zero, L_801E608C
    if (ctx->r14 != 0) {
        // 0x801E6058: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801E608C;
    }
    // 0x801E6058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E605C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801E6060: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801E6064: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E6068: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E606C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E6070: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E6074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E6078: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E607C: jal         0x8038C97C
    // 0x801E6080: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E6080: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E6084: b           L_801E6090
    // 0x801E6088: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E6090;
    // 0x801E6088: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E608C:
    // 0x801E608C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E6090:
    // 0x801E6090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E6094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E6098: jr          $ra
    // 0x801E609C: nop

    return;
    // 0x801E609C: nop

;}
RECOMP_FUNC void M25_FUN_801e60a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E60A0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E60A4: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E60A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E60AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E60B0: beq         $t6, $zero, L_801E60C0
    if (ctx->r14 == 0) {
            // 0x801E60B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801E60C0)(rdram, ctx);
    return;
    }
    // 0x801E60B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801E60B8: jr          $ra
    // 0x801E60BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E60BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e60c0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e60c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E60C0: jr          $ra
    // 0x801E60C4: nop

    return;
    // 0x801E60C4: nop

;}
RECOMP_FUNC void M25_FUN_801e60c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E60C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E60CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E60D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E60D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E60D8: lui         $a1, 0x36A
    ctx->r5 = S32(0X36A << 16);
    // 0x801E60DC: ori         $a1, $a1, 0x5420
    ctx->r5 = ctx->r5 | 0X5420;
    // 0x801E60E0: jal         0x801C0B8C
    // 0x801E60E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E60E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E60E8: beq         $v0, $zero, L_801E6134
    if (ctx->r2 == 0) {
        // 0x801E60EC: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801E6134;
    }
    // 0x801E60EC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E60F0: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E60F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E60F8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E60FC: bne         $t6, $zero, L_801E6134
    if (ctx->r14 != 0) {
        // 0x801E6100: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801E6134;
    }
    // 0x801E6100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E6104: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801E6108: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E610C: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E6110: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E6114: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E6118: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E611C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E6120: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E6124: jal         0x8038C97C
    // 0x801E6128: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E6128: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E612C: b           L_801E6138
    // 0x801E6130: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801E6138;
    // 0x801E6130: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801E6134:
    // 0x801E6134: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E6138:
    // 0x801E6138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E613C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E6140: jr          $ra
    // 0x801E6144: nop

    return;
    // 0x801E6144: nop

;}
RECOMP_FUNC void M25_FUN_801e6148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6148: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E614C: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E6150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6154: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6158: beq         $t6, $zero, L_801E6168
    if (ctx->r14 == 0) {
            // 0x801E615C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801E6168)(rdram, ctx);
    return;
    }
    // 0x801E615C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E6160: jr          $ra
    // 0x801E6164: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801E6164: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6168(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6168: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E616C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801E6170: jr          $ra
    // 0x801E6174: nop

    return;
    // 0x801E6174: nop

;}
RECOMP_FUNC void M25_FUN_801e6178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6178: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E617C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E6180: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E6184: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E6188: lui         $a1, 0x3B6
    ctx->r5 = S32(0X3B6 << 16);
    // 0x801E618C: ori         $a1, $a1, 0x9F60
    ctx->r5 = ctx->r5 | 0X9F60;
    // 0x801E6190: jal         0x801C0B8C
    // 0x801E6194: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6194: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6198: beq         $v0, $zero, L_801E61E4
    if (ctx->r2 == 0) {
        // 0x801E619C: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801E61E4;
    }
    // 0x801E619C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E61A0: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E61A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E61A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E61AC: bne         $t6, $zero, L_801E61E4
    if (ctx->r14 != 0) {
        // 0x801E61B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801E61E4;
    }
    // 0x801E61B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E61B4: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801E61B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801E61BC: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E61C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E61C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E61C8: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E61CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E61D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E61D4: jal         0x8038C97C
    // 0x801E61D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E61D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E61DC: b           L_801E61E8
    // 0x801E61E0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801E61E8;
    // 0x801E61E0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801E61E4:
    // 0x801E61E4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E61E8:
    // 0x801E61E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E61EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E61F0: jr          $ra
    // 0x801E61F4: nop

    return;
    // 0x801E61F4: nop

;}
