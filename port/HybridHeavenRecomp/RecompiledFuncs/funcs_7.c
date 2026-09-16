#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_8001d2e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D2E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001D2E8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8001D2EC: sra         $a1, $a0, 8
    ctx->r5 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8001D2F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D2F4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001D2F8: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x8001D2FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D300: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001D304: bne         $a1, $at, L_8001D324
    if (ctx->r5 != ctx->r1) {
        // 0x8001D308: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8001D324;
    }
    // 0x8001D308: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001D30C: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001D310: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001D314: jal         0x8001C670
    // 0x8001D318: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001C670)(rdram, ctx);
        goto after_0;
    // 0x8001D318: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001D31C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D320: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001D324:
    // 0x8001D324: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x8001D328: bne         $a1, $at, L_8001D348
    if (ctx->r5 != ctx->r1) {
        // 0x8001D32C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001D348;
    }
    // 0x8001D32C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D330: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001D334: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001D338: jal         0x8001C6E8
    // 0x8001D33C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001C6E8)(rdram, ctx);
        goto after_1;
    // 0x8001D33C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001D340: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D344: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001D348:
    // 0x8001D348: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x8001D34C: bne         $a1, $at, L_8001D364
    if (ctx->r5 != ctx->r1) {
        // 0x8001D350: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001D364;
    }
    // 0x8001D350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D354: addiu       $a0, $a0, -0xB0
    ctx->r4 = ADD32(ctx->r4, -0XB0);
    // 0x8001D358: jal         0x8001C734
    // 0x8001D35C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x8001C734)(rdram, ctx);
        goto after_2;
    // 0x8001D35C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_2:
    // 0x8001D360: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001D364:
    // 0x8001D364: ori         $at, $zero, 0xA2A7
    ctx->r1 = 0 | 0XA2A7;
    // 0x8001D368: bne         $s0, $at, L_8001D374
    if (ctx->r16 != ctx->r1) {
        // 0x8001D36C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001D374;
    }
    // 0x8001D36C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D370: addiu       $v1, $zero, 0x55
    ctx->r3 = ADD32(0, 0X55);
L_8001D374:
    // 0x8001D374: ori         $at, $zero, 0xA1FC
    ctx->r1 = 0 | 0XA1FC;
    // 0x8001D378: bnel        $s0, $at, L_8001D388
    if (ctx->r16 != ctx->r1) {
        // 0x8001D37C: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_8001D388;
    }
    goto skip_0;
    // 0x8001D37C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8001D380: addiu       $v1, $zero, 0x56
    ctx->r3 = ADD32(0, 0X56);
    // 0x8001D384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
L_8001D388:
    // 0x8001D388: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D38C: jr          $ra
    // 0x8001D390: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001D390: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001d394(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001d394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D394: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D398: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D39C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001D3A0: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x8001D3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D3A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001D3AC: bne         $a3, $zero, L_8001D3C4
    if (ctx->r7 != 0) {
        // 0x8001D3B0: andi        $a2, $a1, 0xFFFF
        ctx->r6 = ctx->r5 & 0XFFFF;
            goto L_8001D3C4;
    }
    // 0x8001D3B0: andi        $a2, $a1, 0xFFFF
    ctx->r6 = ctx->r5 & 0XFFFF;
    // 0x8001D3B4: ori         $v0, $zero, 0xA1B8
    ctx->r2 = 0 | 0XA1B8;
    // 0x8001D3B8: bnel        $v0, $a1, L_8001D3C8
    if (ctx->r2 != ctx->r5) {
        // 0x8001D3BC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001D3C8;
    }
    goto skip_0;
    // 0x8001D3BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8001D3C0: ori         $a2, $zero, 0xA1A1
    ctx->r6 = 0 | 0XA1A1;
L_8001D3C4:
    // 0x8001D3C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8001D3C8:
    // 0x8001D3C8: bne         $a3, $at, L_8001D3DC
    if (ctx->r7 != ctx->r1) {
        // 0x8001D3CC: ori         $v0, $zero, 0xA1B8
        ctx->r2 = 0 | 0XA1B8;
            goto L_8001D3DC;
    }
    // 0x8001D3CC: ori         $v0, $zero, 0xA1B8
    ctx->r2 = 0 | 0XA1B8;
    // 0x8001D3D0: bnel        $v0, $a2, L_8001D3E0
    if (ctx->r2 != ctx->r6) {
        // 0x8001D3D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001D3E0;
    }
    goto skip_1;
    // 0x8001D3D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8001D3D8: ori         $a2, $zero, 0xA1A1
    ctx->r6 = 0 | 0XA1A1;
L_8001D3DC:
    // 0x8001D3DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8001D3E0:
    // 0x8001D3E0: bne         $a3, $at, L_8001D3F8
    if (ctx->r7 != ctx->r1) {
        // 0x8001D3E4: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8001D3F8;
    }
    // 0x8001D3E4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8001D3E8: bne         $v0, $v1, L_8001D3F8
    if (ctx->r2 != ctx->r3) {
        // 0x8001D3EC: nop
    
            goto L_8001D3F8;
    }
    // 0x8001D3EC: nop

    // 0x8001D3F0: ori         $a2, $zero, 0xA1A1
    ctx->r6 = 0 | 0XA1A1;
    // 0x8001D3F4: ori         $v1, $zero, 0xA1A1
    ctx->r3 = 0 | 0XA1A1;
L_8001D3F8:
    // 0x8001D3F8: bne         $a3, $zero, L_8001D420
    if (ctx->r7 != 0) {
        // 0x8001D3FC: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_8001D420;
    }
    // 0x8001D3FC: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x8001D400: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8001D404: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    // 0x8001D408: jal         0x8001C88C
    // 0x8001D40C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8001C88C)(rdram, ctx);
        goto after_0;
    // 0x8001D40C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001D410: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D414: lhu         $a2, 0x24($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X24);
    // 0x8001D418: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001D41C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
L_8001D420:
    // 0x8001D420: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001D424: bne         $a3, $at, L_8001D450
    if (ctx->r7 != ctx->r1) {
        // 0x8001D428: lhu         $a0, 0x26($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0X26);
            goto L_8001D450;
    }
    // 0x8001D428: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x8001D42C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x8001D430: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8001D434: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    // 0x8001D438: jal         0x8001C96C
    // 0x8001D43C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8001C96C)(rdram, ctx);
        goto after_1;
    // 0x8001D43C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x8001D440: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D444: lhu         $a2, 0x24($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X24);
    // 0x8001D448: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001D44C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_8001D450:
    // 0x8001D450: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001D454: bnel        $a3, $at, L_8001D484
    if (ctx->r7 != ctx->r1) {
        // 0x8001D458: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8001D484;
    }
    goto skip_2;
    // 0x8001D458: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_2:
    // 0x8001D45C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x8001D460: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8001D464: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    // 0x8001D468: jal         0x8001CE9C
    // 0x8001D46C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8001CE9C)(rdram, ctx);
        goto after_2;
    // 0x8001D46C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x8001D470: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D474: lhu         $a2, 0x24($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X24);
    // 0x8001D478: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001D47C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8001D480: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8001D484:
    // 0x8001D484: bnel        $a3, $at, L_8001D4B4
    if (ctx->r7 != ctx->r1) {
        // 0x8001D488: ori         $at, $zero, 0xD4A2
        ctx->r1 = 0 | 0XD4A2;
            goto L_8001D4B4;
    }
    goto skip_3;
    // 0x8001D488: ori         $at, $zero, 0xD4A2
    ctx->r1 = 0 | 0XD4A2;
    skip_3:
    // 0x8001D48C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x8001D490: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8001D494: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    // 0x8001D498: jal         0x8001D2E0
    // 0x8001D49C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8001D2E0)(rdram, ctx);
        goto after_3;
    // 0x8001D49C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x8001D4A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D4A4: lhu         $a2, 0x24($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X24);
    // 0x8001D4A8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001D4AC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8001D4B0: ori         $at, $zero, 0xD4A2
    ctx->r1 = 0 | 0XD4A2;
L_8001D4B4:
    // 0x8001D4B4: bnel        $v1, $at, L_8001D4C8
    if (ctx->r3 != ctx->r1) {
        // 0x8001D4B8: ori         $at, $zero, 0xE7A7
        ctx->r1 = 0 | 0XE7A7;
            goto L_8001D4C8;
    }
    goto skip_4;
    // 0x8001D4B8: ori         $at, $zero, 0xE7A7
    ctx->r1 = 0 | 0XE7A7;
    skip_4:
    // 0x8001D4BC: ori         $a2, $zero, 0xA6A0
    ctx->r6 = 0 | 0XA6A0;
    // 0x8001D4C0: ori         $v1, $zero, 0xA6A0
    ctx->r3 = 0 | 0XA6A0;
    // 0x8001D4C4: ori         $at, $zero, 0xE7A7
    ctx->r1 = 0 | 0XE7A7;
L_8001D4C8:
    // 0x8001D4C8: bnel        $v1, $at, L_8001D4DC
    if (ctx->r3 != ctx->r1) {
        // 0x8001D4CC: ori         $at, $zero, 0xD1DB
        ctx->r1 = 0 | 0XD1DB;
            goto L_8001D4DC;
    }
    goto skip_5;
    // 0x8001D4CC: ori         $at, $zero, 0xD1DB
    ctx->r1 = 0 | 0XD1DB;
    skip_5:
    // 0x8001D4D0: ori         $a2, $zero, 0xA6A1
    ctx->r6 = 0 | 0XA6A1;
    // 0x8001D4D4: ori         $v1, $zero, 0xA6A1
    ctx->r3 = 0 | 0XA6A1;
    // 0x8001D4D8: ori         $at, $zero, 0xD1DB
    ctx->r1 = 0 | 0XD1DB;
L_8001D4DC:
    // 0x8001D4DC: bnel        $v1, $at, L_8001D4F0
    if (ctx->r3 != ctx->r1) {
        // 0x8001D4E0: ori         $at, $zero, 0xD9C7
        ctx->r1 = 0 | 0XD9C7;
            goto L_8001D4F0;
    }
    goto skip_6;
    // 0x8001D4E0: ori         $at, $zero, 0xD9C7
    ctx->r1 = 0 | 0XD9C7;
    skip_6:
    // 0x8001D4E4: ori         $a2, $zero, 0xA6A2
    ctx->r6 = 0 | 0XA6A2;
    // 0x8001D4E8: ori         $v1, $zero, 0xA6A2
    ctx->r3 = 0 | 0XA6A2;
    // 0x8001D4EC: ori         $at, $zero, 0xD9C7
    ctx->r1 = 0 | 0XD9C7;
L_8001D4F0:
    // 0x8001D4F0: bnel        $v1, $at, L_8001D504
    if (ctx->r3 != ctx->r1) {
        // 0x8001D4F4: ori         $at, $zero, 0xE6AB
        ctx->r1 = 0 | 0XE6AB;
            goto L_8001D504;
    }
    goto skip_7;
    // 0x8001D4F4: ori         $at, $zero, 0xE6AB
    ctx->r1 = 0 | 0XE6AB;
    skip_7:
    // 0x8001D4F8: ori         $a2, $zero, 0xA6A3
    ctx->r6 = 0 | 0XA6A3;
    // 0x8001D4FC: ori         $v1, $zero, 0xA6A3
    ctx->r3 = 0 | 0XA6A3;
    // 0x8001D500: ori         $at, $zero, 0xE6AB
    ctx->r1 = 0 | 0XE6AB;
L_8001D504:
    // 0x8001D504: bnel        $v1, $at, L_8001D518
    if (ctx->r3 != ctx->r1) {
        // 0x8001D508: ori         $at, $zero, 0xE0FA
        ctx->r1 = 0 | 0XE0FA;
            goto L_8001D518;
    }
    goto skip_8;
    // 0x8001D508: ori         $at, $zero, 0xE0FA
    ctx->r1 = 0 | 0XE0FA;
    skip_8:
    // 0x8001D50C: ori         $a2, $zero, 0xA6A4
    ctx->r6 = 0 | 0XA6A4;
    // 0x8001D510: ori         $v1, $zero, 0xA6A4
    ctx->r3 = 0 | 0XA6A4;
    // 0x8001D514: ori         $at, $zero, 0xE0FA
    ctx->r1 = 0 | 0XE0FA;
L_8001D518:
    // 0x8001D518: bnel        $v1, $at, L_8001D528
    if (ctx->r3 != ctx->r1) {
        // 0x8001D51C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001D528;
    }
    goto skip_9;
    // 0x8001D51C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_9:
    // 0x8001D520: ori         $a2, $zero, 0xA6A5
    ctx->r6 = 0 | 0XA6A5;
    // 0x8001D524: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8001D528:
    // 0x8001D528: bnel        $a3, $at, L_8001D550
    if (ctx->r7 != ctx->r1) {
        // 0x8001D52C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001D550;
    }
    goto skip_10;
    // 0x8001D52C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_10:
    // 0x8001D530: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x8001D534: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    // 0x8001D538: jal         0x8001CF40
    // 0x8001D53C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8001CF40)(rdram, ctx);
        goto after_4;
    // 0x8001D53C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x8001D540: lhu         $a2, 0x24($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X24);
    // 0x8001D544: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001D548: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8001D54C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8001D550:
    // 0x8001D550: bne         $a3, $at, L_8001D57C
    if (ctx->r7 != ctx->r1) {
        // 0x8001D554: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001D57C;
    }
    // 0x8001D554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D558: ori         $at, $zero, 0xA1A1
    ctx->r1 = 0 | 0XA1A1;
    // 0x8001D55C: bne         $a2, $at, L_8001D56C
    if (ctx->r6 != ctx->r1) {
        // 0x8001D560: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8001D56C;
    }
    // 0x8001D560: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8001D564: b           L_8001D57C
    // 0x8001D568: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8001D57C;
    // 0x8001D568: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001D56C:
    // 0x8001D56C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001D570: ori         $at, $at, 0x5C40
    ctx->r1 = ctx->r1 | 0X5C40;
    // 0x8001D574: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x8001D578: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_8001D57C:
    // 0x8001D57C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001D580: jr          $ra
    // 0x8001D584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001D584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001d588(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001d588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D588: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001D58C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001D590: bne         $v0, $zero, L_8001D5A0
    if (ctx->r2 != 0) {
        // 0x8001D594: sw          $a0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r4;
            goto L_8001D5A0;
    }
    // 0x8001D594: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8001D598: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x8001D59C: sb          $v1, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r3;
L_8001D5A0:
    // 0x8001D5A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001D5A4: bne         $v0, $at, L_8001D5B0
    if (ctx->r2 != ctx->r1) {
        // 0x8001D5A8: lbu         $v1, 0x7($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X7);
            goto L_8001D5B0;
    }
    // 0x8001D5A8: lbu         $v1, 0x7($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X7);
    // 0x8001D5AC: addiu       $v1, $zero, 0x31
    ctx->r3 = ADD32(0, 0X31);
L_8001D5B0:
    // 0x8001D5B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001D5B4: bnel        $v0, $at, L_8001D5C4
    if (ctx->r2 != ctx->r1) {
        // 0x8001D5B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001D5C4;
    }
    goto skip_0;
    // 0x8001D5B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x8001D5BC: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x8001D5C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8001D5C4:
    // 0x8001D5C4: bnel        $v0, $at, L_8001D5D4
    if (ctx->r2 != ctx->r1) {
        // 0x8001D5C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8001D5D4;
    }
    goto skip_1;
    // 0x8001D5C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_1:
    // 0x8001D5CC: addiu       $v1, $zero, 0x33
    ctx->r3 = ADD32(0, 0X33);
    // 0x8001D5D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8001D5D4:
    // 0x8001D5D4: bnel        $v0, $at, L_8001D5E4
    if (ctx->r2 != ctx->r1) {
        // 0x8001D5D8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001D5E4;
    }
    goto skip_2;
    // 0x8001D5D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_2:
    // 0x8001D5DC: addiu       $v1, $zero, 0x34
    ctx->r3 = ADD32(0, 0X34);
    // 0x8001D5E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8001D5E4:
    // 0x8001D5E4: bnel        $v0, $at, L_8001D5F4
    if (ctx->r2 != ctx->r1) {
        // 0x8001D5E8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8001D5F4;
    }
    goto skip_3;
    // 0x8001D5E8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_3:
    // 0x8001D5EC: addiu       $v1, $zero, 0x35
    ctx->r3 = ADD32(0, 0X35);
    // 0x8001D5F0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_8001D5F4:
    // 0x8001D5F4: bnel        $v0, $at, L_8001D604
    if (ctx->r2 != ctx->r1) {
        // 0x8001D5F8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8001D604;
    }
    goto skip_4;
    // 0x8001D5F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_4:
    // 0x8001D5FC: addiu       $v1, $zero, 0x36
    ctx->r3 = ADD32(0, 0X36);
    // 0x8001D600: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_8001D604:
    // 0x8001D604: bnel        $v0, $at, L_8001D614
    if (ctx->r2 != ctx->r1) {
        // 0x8001D608: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8001D614;
    }
    goto skip_5;
    // 0x8001D608: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_5:
    // 0x8001D60C: addiu       $v1, $zero, 0x37
    ctx->r3 = ADD32(0, 0X37);
    // 0x8001D610: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8001D614:
    // 0x8001D614: bnel        $v0, $at, L_8001D624
    if (ctx->r2 != ctx->r1) {
        // 0x8001D618: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8001D624;
    }
    goto skip_6;
    // 0x8001D618: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_6:
    // 0x8001D61C: addiu       $v1, $zero, 0x38
    ctx->r3 = ADD32(0, 0X38);
    // 0x8001D620: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_8001D624:
    // 0x8001D624: bnel        $v0, $at, L_8001D634
    if (ctx->r2 != ctx->r1) {
        // 0x8001D628: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8001D634;
    }
    goto skip_7;
    // 0x8001D628: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_7:
    // 0x8001D62C: addiu       $v1, $zero, 0x39
    ctx->r3 = ADD32(0, 0X39);
    // 0x8001D630: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_8001D634:
    // 0x8001D634: bnel        $v0, $at, L_8001D644
    if (ctx->r2 != ctx->r1) {
        // 0x8001D638: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8001D644;
    }
    goto skip_8;
    // 0x8001D638: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_8:
    // 0x8001D63C: addiu       $v1, $zero, 0x41
    ctx->r3 = ADD32(0, 0X41);
    // 0x8001D640: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_8001D644:
    // 0x8001D644: bnel        $v0, $at, L_8001D654
    if (ctx->r2 != ctx->r1) {
        // 0x8001D648: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8001D654;
    }
    goto skip_9;
    // 0x8001D648: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_9:
    // 0x8001D64C: addiu       $v1, $zero, 0x42
    ctx->r3 = ADD32(0, 0X42);
    // 0x8001D650: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8001D654:
    // 0x8001D654: bnel        $v0, $at, L_8001D664
    if (ctx->r2 != ctx->r1) {
        // 0x8001D658: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8001D664;
    }
    goto skip_10;
    // 0x8001D658: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_10:
    // 0x8001D65C: addiu       $v1, $zero, 0x43
    ctx->r3 = ADD32(0, 0X43);
    // 0x8001D660: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
L_8001D664:
    // 0x8001D664: bnel        $v0, $at, L_8001D674
    if (ctx->r2 != ctx->r1) {
        // 0x8001D668: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8001D674;
    }
    goto skip_11;
    // 0x8001D668: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_11:
    // 0x8001D66C: addiu       $v1, $zero, 0x44
    ctx->r3 = ADD32(0, 0X44);
    // 0x8001D670: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_8001D674:
    // 0x8001D674: bnel        $v0, $at, L_8001D684
    if (ctx->r2 != ctx->r1) {
        // 0x8001D678: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8001D684;
    }
    goto skip_12;
    // 0x8001D678: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    skip_12:
    // 0x8001D67C: addiu       $v1, $zero, 0x45
    ctx->r3 = ADD32(0, 0X45);
    // 0x8001D680: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
L_8001D684:
    // 0x8001D684: bnel        $v0, $at, L_8001D694
    if (ctx->r2 != ctx->r1) {
        // 0x8001D688: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8001D694;
    }
    goto skip_13;
    // 0x8001D688: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_13:
    // 0x8001D68C: addiu       $v1, $zero, 0x46
    ctx->r3 = ADD32(0, 0X46);
    // 0x8001D690: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001D694:
    // 0x8001D694: jr          $ra
    // 0x8001D698: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001D698: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001d69c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001d69c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D69C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D6A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D6A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D6A8: bgez        $a0, L_8001D6C4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001D6AC: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_8001D6C4;
    }
    // 0x8001D6AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D6B0: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x8001D6B4: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8001D6B8: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
    // 0x8001D6BC: b           L_8001D6C8
    // 0x8001D6C0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001D6C8;
    // 0x8001D6C0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001D6C4:
    // 0x8001D6C4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8001D6C8:
    // 0x8001D6C8: lui         $a3, 0x3B9A
    ctx->r7 = S32(0X3B9A << 16);
    // 0x8001D6CC: ori         $a3, $a3, 0xCA00
    ctx->r7 = ctx->r7 | 0XCA00;
    // 0x8001D6D0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001D6D4: bne         $at, $zero, L_8001D738
    if (ctx->r1 != 0) {
        // 0x8001D6D8: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8001D738;
    }
    // 0x8001D6D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001D6DC: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x8001D6E0: mflo        $v1
    ctx->r3 = lo;
    // 0x8001D6E4: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001D6E8: bne         $a3, $zero, L_8001D6F4
    if (ctx->r7 != 0) {
        // 0x8001D6EC: nop
    
            goto L_8001D6F4;
    }
    // 0x8001D6EC: nop

    // 0x8001D6F0: break       7
    do_break(2147604208);
L_8001D6F4:
    // 0x8001D6F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001D6F8: bne         $a3, $at, L_8001D70C
    if (ctx->r7 != ctx->r1) {
        // 0x8001D6FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001D70C;
    }
    // 0x8001D6FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D700: bne         $a1, $at, L_8001D70C
    if (ctx->r5 != ctx->r1) {
        // 0x8001D704: nop
    
            goto L_8001D70C;
    }
    // 0x8001D704: nop

    // 0x8001D708: break       6
    do_break(2147604232);
L_8001D70C:
    // 0x8001D70C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D710: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D714: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D718: mflo        $t7
    ctx->r15 = lo;
    // 0x8001D71C: subu        $s0, $a1, $t7
    ctx->r16 = SUB32(ctx->r5, ctx->r15);
    // 0x8001D720: jal         0x8001D588
    // 0x8001D724: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_0;
    // 0x8001D724: nop

    after_0:
    // 0x8001D728: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D72C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D730: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001D734: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001D738:
    // 0x8001D738: lui         $a3, 0x5F5
    ctx->r7 = S32(0X5F5 << 16);
    // 0x8001D73C: ori         $a3, $a3, 0xE100
    ctx->r7 = ctx->r7 | 0XE100;
    // 0x8001D740: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001D744: bnel        $at, $zero, L_8001D7B0
    if (ctx->r1 != 0) {
        // 0x8001D748: lbu         $t9, 0x2F($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X2F);
            goto L_8001D7B0;
    }
    goto skip_0;
    // 0x8001D748: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    skip_0:
    // 0x8001D74C: div         $zero, $s0, $a3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r7)));
    // 0x8001D750: mflo        $v1
    ctx->r3 = lo;
    // 0x8001D754: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001D758: bne         $a3, $zero, L_8001D764
    if (ctx->r7 != 0) {
        // 0x8001D75C: nop
    
            goto L_8001D764;
    }
    // 0x8001D75C: nop

    // 0x8001D760: break       7
    do_break(2147604320);
L_8001D764:
    // 0x8001D764: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001D768: bne         $a3, $at, L_8001D77C
    if (ctx->r7 != ctx->r1) {
        // 0x8001D76C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001D77C;
    }
    // 0x8001D76C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D770: bne         $s0, $at, L_8001D77C
    if (ctx->r16 != ctx->r1) {
        // 0x8001D774: nop
    
            goto L_8001D77C;
    }
    // 0x8001D774: nop

    // 0x8001D778: break       6
    do_break(2147604344);
L_8001D77C:
    // 0x8001D77C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D780: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D784: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D788: mflo        $t8
    ctx->r24 = lo;
    // 0x8001D78C: subu        $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x8001D790: jal         0x8001D588
    // 0x8001D794: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_1;
    // 0x8001D794: nop

    after_1:
    // 0x8001D798: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D79C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D7A0: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001D7A4: b           L_8001D7C8
    // 0x8001D7A8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001D7C8;
    // 0x8001D7A8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001D7AC: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
L_8001D7B0:
    // 0x8001D7B0: slti        $at, $t9, 0x9
    ctx->r1 = SIGNED(ctx->r25) < 0X9 ? 1 : 0;
    // 0x8001D7B4: bnel        $at, $zero, L_8001D7CC
    if (ctx->r1 != 0) {
        // 0x8001D7B8: lui         $a3, 0x98
        ctx->r7 = S32(0X98 << 16);
            goto L_8001D7CC;
    }
    goto skip_1;
    // 0x8001D7B8: lui         $a3, 0x98
    ctx->r7 = S32(0X98 << 16);
    skip_1:
    // 0x8001D7BC: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8001D7C0: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x8001D7C4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001D7C8:
    // 0x8001D7C8: lui         $a3, 0x98
    ctx->r7 = S32(0X98 << 16);
L_8001D7CC:
    // 0x8001D7CC: ori         $a3, $a3, 0x9680
    ctx->r7 = ctx->r7 | 0X9680;
    // 0x8001D7D0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001D7D4: bnel        $at, $zero, L_8001D840
    if (ctx->r1 != 0) {
        // 0x8001D7D8: lbu         $t2, 0x2F($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X2F);
            goto L_8001D840;
    }
    goto skip_2;
    // 0x8001D7D8: lbu         $t2, 0x2F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2F);
    skip_2:
    // 0x8001D7DC: div         $zero, $s0, $a3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r7)));
    // 0x8001D7E0: mflo        $v1
    ctx->r3 = lo;
    // 0x8001D7E4: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001D7E8: bne         $a3, $zero, L_8001D7F4
    if (ctx->r7 != 0) {
        // 0x8001D7EC: nop
    
            goto L_8001D7F4;
    }
    // 0x8001D7EC: nop

    // 0x8001D7F0: break       7
    do_break(2147604464);
L_8001D7F4:
    // 0x8001D7F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001D7F8: bne         $a3, $at, L_8001D80C
    if (ctx->r7 != ctx->r1) {
        // 0x8001D7FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001D80C;
    }
    // 0x8001D7FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D800: bne         $s0, $at, L_8001D80C
    if (ctx->r16 != ctx->r1) {
        // 0x8001D804: nop
    
            goto L_8001D80C;
    }
    // 0x8001D804: nop

    // 0x8001D808: break       6
    do_break(2147604488);
L_8001D80C:
    // 0x8001D80C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D810: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D814: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D818: mflo        $t1
    ctx->r9 = lo;
    // 0x8001D81C: subu        $s0, $s0, $t1
    ctx->r16 = SUB32(ctx->r16, ctx->r9);
    // 0x8001D820: jal         0x8001D588
    // 0x8001D824: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_2;
    // 0x8001D824: nop

    after_2:
    // 0x8001D828: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D82C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D830: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001D834: b           L_8001D858
    // 0x8001D838: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001D858;
    // 0x8001D838: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001D83C: lbu         $t2, 0x2F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2F);
L_8001D840:
    // 0x8001D840: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8001D844: bnel        $at, $zero, L_8001D85C
    if (ctx->r1 != 0) {
        // 0x8001D848: lui         $a3, 0xF
        ctx->r7 = S32(0XF << 16);
            goto L_8001D85C;
    }
    goto skip_3;
    // 0x8001D848: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    skip_3:
    // 0x8001D84C: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8001D850: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x8001D854: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001D858:
    // 0x8001D858: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
L_8001D85C:
    // 0x8001D85C: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x8001D860: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001D864: bnel        $at, $zero, L_8001D8D0
    if (ctx->r1 != 0) {
        // 0x8001D868: lbu         $t5, 0x2F($sp)
        ctx->r13 = MEM_BU(ctx->r29, 0X2F);
            goto L_8001D8D0;
    }
    goto skip_4;
    // 0x8001D868: lbu         $t5, 0x2F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2F);
    skip_4:
    // 0x8001D86C: div         $zero, $s0, $a3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r7)));
    // 0x8001D870: mflo        $v1
    ctx->r3 = lo;
    // 0x8001D874: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001D878: bne         $a3, $zero, L_8001D884
    if (ctx->r7 != 0) {
        // 0x8001D87C: nop
    
            goto L_8001D884;
    }
    // 0x8001D87C: nop

    // 0x8001D880: break       7
    do_break(2147604608);
L_8001D884:
    // 0x8001D884: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001D888: bne         $a3, $at, L_8001D89C
    if (ctx->r7 != ctx->r1) {
        // 0x8001D88C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001D89C;
    }
    // 0x8001D88C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D890: bne         $s0, $at, L_8001D89C
    if (ctx->r16 != ctx->r1) {
        // 0x8001D894: nop
    
            goto L_8001D89C;
    }
    // 0x8001D894: nop

    // 0x8001D898: break       6
    do_break(2147604632);
L_8001D89C:
    // 0x8001D89C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D8A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D8A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D8A8: mflo        $t4
    ctx->r12 = lo;
    // 0x8001D8AC: subu        $s0, $s0, $t4
    ctx->r16 = SUB32(ctx->r16, ctx->r12);
    // 0x8001D8B0: jal         0x8001D588
    // 0x8001D8B4: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_3;
    // 0x8001D8B4: nop

    after_3:
    // 0x8001D8B8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D8BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D8C0: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001D8C4: b           L_8001D8E8
    // 0x8001D8C8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001D8E8;
    // 0x8001D8C8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001D8CC: lbu         $t5, 0x2F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2F);
L_8001D8D0:
    // 0x8001D8D0: slti        $at, $t5, 0x7
    ctx->r1 = SIGNED(ctx->r13) < 0X7 ? 1 : 0;
    // 0x8001D8D4: bnel        $at, $zero, L_8001D8EC
    if (ctx->r1 != 0) {
        // 0x8001D8D8: lui         $a3, 0x1
        ctx->r7 = S32(0X1 << 16);
            goto L_8001D8EC;
    }
    goto skip_5;
    // 0x8001D8D8: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    skip_5:
    // 0x8001D8DC: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8001D8E0: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8001D8E4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001D8E8:
    // 0x8001D8E8: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
L_8001D8EC:
    // 0x8001D8EC: ori         $a3, $a3, 0x86A0
    ctx->r7 = ctx->r7 | 0X86A0;
    // 0x8001D8F0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001D8F4: bnel        $at, $zero, L_8001D960
    if (ctx->r1 != 0) {
        // 0x8001D8F8: lbu         $t8, 0x2F($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X2F);
            goto L_8001D960;
    }
    goto skip_6;
    // 0x8001D8F8: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    skip_6:
    // 0x8001D8FC: div         $zero, $s0, $a3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r7)));
    // 0x8001D900: mflo        $v1
    ctx->r3 = lo;
    // 0x8001D904: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001D908: bne         $a3, $zero, L_8001D914
    if (ctx->r7 != 0) {
        // 0x8001D90C: nop
    
            goto L_8001D914;
    }
    // 0x8001D90C: nop

    // 0x8001D910: break       7
    do_break(2147604752);
L_8001D914:
    // 0x8001D914: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001D918: bne         $a3, $at, L_8001D92C
    if (ctx->r7 != ctx->r1) {
        // 0x8001D91C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001D92C;
    }
    // 0x8001D91C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D920: bne         $s0, $at, L_8001D92C
    if (ctx->r16 != ctx->r1) {
        // 0x8001D924: nop
    
            goto L_8001D92C;
    }
    // 0x8001D924: nop

    // 0x8001D928: break       6
    do_break(2147604776);
L_8001D92C:
    // 0x8001D92C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D930: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D934: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D938: mflo        $t7
    ctx->r15 = lo;
    // 0x8001D93C: subu        $s0, $s0, $t7
    ctx->r16 = SUB32(ctx->r16, ctx->r15);
    // 0x8001D940: jal         0x8001D588
    // 0x8001D944: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_4;
    // 0x8001D944: nop

    after_4:
    // 0x8001D948: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D94C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D950: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001D954: b           L_8001D978
    // 0x8001D958: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001D978;
    // 0x8001D958: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001D95C: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
L_8001D960:
    // 0x8001D960: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8001D964: bnel        $at, $zero, L_8001D97C
    if (ctx->r1 != 0) {
        // 0x8001D968: slti        $at, $a1, 0x2710
        ctx->r1 = SIGNED(ctx->r5) < 0X2710 ? 1 : 0;
            goto L_8001D97C;
    }
    goto skip_7;
    // 0x8001D968: slti        $at, $a1, 0x2710
    ctx->r1 = SIGNED(ctx->r5) < 0X2710 ? 1 : 0;
    skip_7:
    // 0x8001D96C: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8001D970: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x8001D974: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001D978:
    // 0x8001D978: slti        $at, $a1, 0x2710
    ctx->r1 = SIGNED(ctx->r5) < 0X2710 ? 1 : 0;
L_8001D97C:
    // 0x8001D97C: bnel        $at, $zero, L_8001D9EC
    if (ctx->r1 != 0) {
        // 0x8001D980: lbu         $t1, 0x2F($sp)
        ctx->r9 = MEM_BU(ctx->r29, 0X2F);
            goto L_8001D9EC;
    }
    goto skip_8;
    // 0x8001D980: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    skip_8:
    // 0x8001D984: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    // 0x8001D988: div         $zero, $s0, $a3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r7)));
    // 0x8001D98C: mflo        $v1
    ctx->r3 = lo;
    // 0x8001D990: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001D994: bne         $a3, $zero, L_8001D9A0
    if (ctx->r7 != 0) {
        // 0x8001D998: nop
    
            goto L_8001D9A0;
    }
    // 0x8001D998: nop

    // 0x8001D99C: break       7
    do_break(2147604892);
L_8001D9A0:
    // 0x8001D9A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001D9A4: bne         $a3, $at, L_8001D9B8
    if (ctx->r7 != ctx->r1) {
        // 0x8001D9A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001D9B8;
    }
    // 0x8001D9A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D9AC: bne         $s0, $at, L_8001D9B8
    if (ctx->r16 != ctx->r1) {
        // 0x8001D9B0: nop
    
            goto L_8001D9B8;
    }
    // 0x8001D9B0: nop

    // 0x8001D9B4: break       6
    do_break(2147604916);
L_8001D9B8:
    // 0x8001D9B8: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D9BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D9C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D9C4: mflo        $t0
    ctx->r8 = lo;
    // 0x8001D9C8: subu        $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // 0x8001D9CC: jal         0x8001D588
    // 0x8001D9D0: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_5;
    // 0x8001D9D0: nop

    after_5:
    // 0x8001D9D4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D9D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001D9DC: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001D9E0: b           L_8001DA04
    // 0x8001D9E4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DA04;
    // 0x8001D9E4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001D9E8: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
L_8001D9EC:
    // 0x8001D9EC: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8001D9F0: bnel        $at, $zero, L_8001DA08
    if (ctx->r1 != 0) {
        // 0x8001D9F4: slti        $at, $a1, 0x3E8
        ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
            goto L_8001DA08;
    }
    goto skip_9;
    // 0x8001D9F4: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
    skip_9:
    // 0x8001D9F8: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8001D9FC: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8001DA00: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DA04:
    // 0x8001DA04: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
L_8001DA08:
    // 0x8001DA08: bnel        $at, $zero, L_8001DA78
    if (ctx->r1 != 0) {
        // 0x8001DA0C: lbu         $t4, 0x2F($sp)
        ctx->r12 = MEM_BU(ctx->r29, 0X2F);
            goto L_8001DA78;
    }
    goto skip_10;
    // 0x8001DA0C: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    skip_10:
    // 0x8001DA10: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x8001DA14: div         $zero, $s0, $a3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r7)));
    // 0x8001DA18: mflo        $v1
    ctx->r3 = lo;
    // 0x8001DA1C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001DA20: bne         $a3, $zero, L_8001DA2C
    if (ctx->r7 != 0) {
        // 0x8001DA24: nop
    
            goto L_8001DA2C;
    }
    // 0x8001DA24: nop

    // 0x8001DA28: break       7
    do_break(2147605032);
L_8001DA2C:
    // 0x8001DA2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DA30: bne         $a3, $at, L_8001DA44
    if (ctx->r7 != ctx->r1) {
        // 0x8001DA34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001DA44;
    }
    // 0x8001DA34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DA38: bne         $s0, $at, L_8001DA44
    if (ctx->r16 != ctx->r1) {
        // 0x8001DA3C: nop
    
            goto L_8001DA44;
    }
    // 0x8001DA3C: nop

    // 0x8001DA40: break       6
    do_break(2147605056);
L_8001DA44:
    // 0x8001DA44: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DA48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001DA4C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DA50: mflo        $t3
    ctx->r11 = lo;
    // 0x8001DA54: subu        $s0, $s0, $t3
    ctx->r16 = SUB32(ctx->r16, ctx->r11);
    // 0x8001DA58: jal         0x8001D588
    // 0x8001DA5C: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_6;
    // 0x8001DA5C: nop

    after_6:
    // 0x8001DA60: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001DA64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001DA68: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DA6C: b           L_8001DA90
    // 0x8001DA70: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DA90;
    // 0x8001DA70: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001DA74: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
L_8001DA78:
    // 0x8001DA78: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8001DA7C: bnel        $at, $zero, L_8001DA94
    if (ctx->r1 != 0) {
        // 0x8001DA80: slti        $at, $a1, 0x64
        ctx->r1 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
            goto L_8001DA94;
    }
    goto skip_11;
    // 0x8001DA80: slti        $at, $a1, 0x64
    ctx->r1 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
    skip_11:
    // 0x8001DA84: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8001DA88: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x8001DA8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DA90:
    // 0x8001DA90: slti        $at, $a1, 0x64
    ctx->r1 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
L_8001DA94:
    // 0x8001DA94: bnel        $at, $zero, L_8001DB04
    if (ctx->r1 != 0) {
        // 0x8001DA98: lbu         $t7, 0x2F($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X2F);
            goto L_8001DB04;
    }
    goto skip_12;
    // 0x8001DA98: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    skip_12:
    // 0x8001DA9C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x8001DAA0: div         $zero, $s0, $a3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r7)));
    // 0x8001DAA4: mflo        $v1
    ctx->r3 = lo;
    // 0x8001DAA8: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001DAAC: bne         $a3, $zero, L_8001DAB8
    if (ctx->r7 != 0) {
        // 0x8001DAB0: nop
    
            goto L_8001DAB8;
    }
    // 0x8001DAB0: nop

    // 0x8001DAB4: break       7
    do_break(2147605172);
L_8001DAB8:
    // 0x8001DAB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DABC: bne         $a3, $at, L_8001DAD0
    if (ctx->r7 != ctx->r1) {
        // 0x8001DAC0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001DAD0;
    }
    // 0x8001DAC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DAC4: bne         $s0, $at, L_8001DAD0
    if (ctx->r16 != ctx->r1) {
        // 0x8001DAC8: nop
    
            goto L_8001DAD0;
    }
    // 0x8001DAC8: nop

    // 0x8001DACC: break       6
    do_break(2147605196);
L_8001DAD0:
    // 0x8001DAD0: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DAD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001DAD8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DADC: mflo        $t6
    ctx->r14 = lo;
    // 0x8001DAE0: subu        $s0, $s0, $t6
    ctx->r16 = SUB32(ctx->r16, ctx->r14);
    // 0x8001DAE4: jal         0x8001D588
    // 0x8001DAE8: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_7;
    // 0x8001DAE8: nop

    after_7:
    // 0x8001DAEC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001DAF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001DAF4: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DAF8: b           L_8001DB1C
    // 0x8001DAFC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DB1C;
    // 0x8001DAFC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001DB00: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
L_8001DB04:
    // 0x8001DB04: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8001DB08: bnel        $at, $zero, L_8001DB20
    if (ctx->r1 != 0) {
        // 0x8001DB0C: slti        $at, $a1, 0xA
        ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
            goto L_8001DB20;
    }
    goto skip_13;
    // 0x8001DB0C: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    skip_13:
    // 0x8001DB10: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8001DB14: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x8001DB18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DB1C:
    // 0x8001DB1C: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
L_8001DB20:
    // 0x8001DB20: bne         $at, $zero, L_8001DB80
    if (ctx->r1 != 0) {
        // 0x8001DB24: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8001DB80;
    }
    // 0x8001DB24: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8001DB28: div         $zero, $s0, $a1
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r5)));
    // 0x8001DB2C: mflo        $v1
    ctx->r3 = lo;
    // 0x8001DB30: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8001DB34: bne         $a1, $zero, L_8001DB40
    if (ctx->r5 != 0) {
        // 0x8001DB38: nop
    
            goto L_8001DB40;
    }
    // 0x8001DB38: nop

    // 0x8001DB3C: break       7
    do_break(2147605308);
L_8001DB40:
    // 0x8001DB40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DB44: bne         $a1, $at, L_8001DB58
    if (ctx->r5 != ctx->r1) {
        // 0x8001DB48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001DB58;
    }
    // 0x8001DB48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DB4C: bne         $s0, $at, L_8001DB58
    if (ctx->r16 != ctx->r1) {
        // 0x8001DB50: nop
    
            goto L_8001DB58;
    }
    // 0x8001DB50: nop

    // 0x8001DB54: break       6
    do_break(2147605332);
L_8001DB58:
    // 0x8001DB58: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DB5C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DB60: mflo        $t9
    ctx->r25 = lo;
    // 0x8001DB64: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
    // 0x8001DB68: jal         0x8001D588
    // 0x8001DB6C: nop

    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_8;
    // 0x8001DB6C: nop

    after_8:
    // 0x8001DB70: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001DB74: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DB78: b           L_8001DB9C
    // 0x8001DB7C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DB9C;
    // 0x8001DB7C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DB80:
    // 0x8001DB80: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001DB84: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8001DB88: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x8001DB8C: bnel        $at, $zero, L_8001DBA0
    if (ctx->r1 != 0) {
        // 0x8001DB90: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_8001DBA0;
    }
    goto skip_14;
    // 0x8001DB90: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_14:
    // 0x8001DB94: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x8001DB98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DB9C:
    // 0x8001DB9C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8001DBA0:
    // 0x8001DBA0: jal         0x8001D588
    // 0x8001DBA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_9;
    // 0x8001DBA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_9:
    // 0x8001DBA8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001DBAC: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DBB0: sb          $zero, 0x1($a2)
    MEM_B(0X1, ctx->r6) = 0;
    // 0x8001DBB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DBB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DBBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DBC0: jr          $ra
    // 0x8001DBC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    return;
    // 0x8001DBC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001dbc8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001dbc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DBC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001DBCC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001DBD0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001DBD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DBD8: bgez        $a0, L_8001DBF4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001DBDC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001DBF4;
    }
    // 0x8001DBDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DBE0: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x8001DBE4: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8001DBE8: negu        $s0, $a0
    ctx->r16 = SUB32(0, ctx->r4);
    // 0x8001DBEC: b           L_8001DBF8
    // 0x8001DBF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DBF8;
    // 0x8001DBF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DBF4:
    // 0x8001DBF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_8001DBF8:
    // 0x8001DBF8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8001DBFC: slt         $at, $s0, $at
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001DC00: bne         $at, $zero, L_8001DC34
    if (ctx->r1 != 0) {
        // 0x8001DC04: lui         $at, 0xF000
        ctx->r1 = S32(0XF000 << 16);
            goto L_8001DC34;
    }
    // 0x8001DC04: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8001DC08: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x8001DC0C: srl         $a0, $a0, 28
    ctx->r4 = S32(U32(ctx->r4) >> 28);
    // 0x8001DC10: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001DC14: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8001DC18: jal         0x8001D588
    // 0x8001DC1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_0;
    // 0x8001DC1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001DC20: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DC24: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8001DC28: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DC2C: b           L_8001DC48
    // 0x8001DC30: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DC48;
    // 0x8001DC30: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DC34:
    // 0x8001DC34: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x8001DC38: bne         $at, $zero, L_8001DC48
    if (ctx->r1 != 0) {
        // 0x8001DC3C: addiu       $t7, $zero, 0x20
        ctx->r15 = ADD32(0, 0X20);
            goto L_8001DC48;
    }
    // 0x8001DC3C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8001DC40: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x8001DC44: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DC48:
    // 0x8001DC48: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8001DC4C: slt         $at, $s0, $at
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001DC50: bne         $at, $zero, L_8001DC84
    if (ctx->r1 != 0) {
        // 0x8001DC54: lui         $at, 0xF00
        ctx->r1 = S32(0XF00 << 16);
            goto L_8001DC84;
    }
    // 0x8001DC54: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8001DC58: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x8001DC5C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001DC60: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001DC64: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8001DC68: jal         0x8001D588
    // 0x8001DC6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_1;
    // 0x8001DC6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x8001DC70: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DC74: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8001DC78: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DC7C: b           L_8001DC98
    // 0x8001DC80: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DC98;
    // 0x8001DC80: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DC84:
    // 0x8001DC84: slti        $at, $a1, 0x7
    ctx->r1 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x8001DC88: bne         $at, $zero, L_8001DC98
    if (ctx->r1 != 0) {
        // 0x8001DC8C: addiu       $t8, $zero, 0x20
        ctx->r24 = ADD32(0, 0X20);
            goto L_8001DC98;
    }
    // 0x8001DC8C: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8001DC90: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x8001DC94: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DC98:
    // 0x8001DC98: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8001DC9C: slt         $at, $s0, $at
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001DCA0: bne         $at, $zero, L_8001DCD4
    if (ctx->r1 != 0) {
        // 0x8001DCA4: lui         $at, 0xF0
        ctx->r1 = S32(0XF0 << 16);
            goto L_8001DCD4;
    }
    // 0x8001DCA4: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8001DCA8: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x8001DCAC: sra         $a0, $a0, 20
    ctx->r4 = S32(SIGNED(ctx->r4) >> 20);
    // 0x8001DCB0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001DCB4: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8001DCB8: jal         0x8001D588
    // 0x8001DCBC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_2;
    // 0x8001DCBC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x8001DCC0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DCC4: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8001DCC8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DCCC: b           L_8001DCE8
    // 0x8001DCD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DCE8;
    // 0x8001DCD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DCD4:
    // 0x8001DCD4: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8001DCD8: bne         $at, $zero, L_8001DCE8
    if (ctx->r1 != 0) {
        // 0x8001DCDC: addiu       $t9, $zero, 0x20
        ctx->r25 = ADD32(0, 0X20);
            goto L_8001DCE8;
    }
    // 0x8001DCDC: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8001DCE0: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x8001DCE4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DCE8:
    // 0x8001DCE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8001DCEC: slt         $at, $s0, $at
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001DCF0: bne         $at, $zero, L_8001DD24
    if (ctx->r1 != 0) {
        // 0x8001DCF4: lui         $at, 0xF
        ctx->r1 = S32(0XF << 16);
            goto L_8001DD24;
    }
    // 0x8001DCF4: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8001DCF8: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x8001DCFC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001DD00: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001DD04: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8001DD08: jal         0x8001D588
    // 0x8001DD0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_3;
    // 0x8001DD0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x8001DD10: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DD14: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8001DD18: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DD1C: b           L_8001DD38
    // 0x8001DD20: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DD38;
    // 0x8001DD20: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DD24:
    // 0x8001DD24: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8001DD28: bne         $at, $zero, L_8001DD38
    if (ctx->r1 != 0) {
        // 0x8001DD2C: addiu       $t0, $zero, 0x20
        ctx->r8 = ADD32(0, 0X20);
            goto L_8001DD38;
    }
    // 0x8001DD2C: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8001DD30: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x8001DD34: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DD38:
    // 0x8001DD38: slti        $at, $s0, 0x1000
    ctx->r1 = SIGNED(ctx->r16) < 0X1000 ? 1 : 0;
    // 0x8001DD3C: bne         $at, $zero, L_8001DD6C
    if (ctx->r1 != 0) {
        // 0x8001DD40: andi        $a0, $s0, 0xF000
        ctx->r4 = ctx->r16 & 0XF000;
            goto L_8001DD6C;
    }
    // 0x8001DD40: andi        $a0, $s0, 0xF000
    ctx->r4 = ctx->r16 & 0XF000;
    // 0x8001DD44: sra         $a0, $a0, 12
    ctx->r4 = S32(SIGNED(ctx->r4) >> 12);
    // 0x8001DD48: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001DD4C: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8001DD50: jal         0x8001D588
    // 0x8001DD54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_4;
    // 0x8001DD54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_4:
    // 0x8001DD58: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DD5C: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8001DD60: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DD64: b           L_8001DD80
    // 0x8001DD68: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DD80;
    // 0x8001DD68: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DD6C:
    // 0x8001DD6C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8001DD70: bne         $at, $zero, L_8001DD80
    if (ctx->r1 != 0) {
        // 0x8001DD74: addiu       $t1, $zero, 0x20
        ctx->r9 = ADD32(0, 0X20);
            goto L_8001DD80;
    }
    // 0x8001DD74: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8001DD78: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x8001DD7C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DD80:
    // 0x8001DD80: slti        $at, $s0, 0x100
    ctx->r1 = SIGNED(ctx->r16) < 0X100 ? 1 : 0;
    // 0x8001DD84: bne         $at, $zero, L_8001DDB4
    if (ctx->r1 != 0) {
        // 0x8001DD88: andi        $a0, $s0, 0xF00
        ctx->r4 = ctx->r16 & 0XF00;
            goto L_8001DDB4;
    }
    // 0x8001DD88: andi        $a0, $s0, 0xF00
    ctx->r4 = ctx->r16 & 0XF00;
    // 0x8001DD8C: sra         $a0, $a0, 8
    ctx->r4 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8001DD90: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001DD94: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8001DD98: jal         0x8001D588
    // 0x8001DD9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_5;
    // 0x8001DD9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x8001DDA0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DDA4: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8001DDA8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DDAC: b           L_8001DDC8
    // 0x8001DDB0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DDC8;
    // 0x8001DDB0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DDB4:
    // 0x8001DDB4: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x8001DDB8: bne         $at, $zero, L_8001DDC8
    if (ctx->r1 != 0) {
        // 0x8001DDBC: addiu       $t2, $zero, 0x20
        ctx->r10 = ADD32(0, 0X20);
            goto L_8001DDC8;
    }
    // 0x8001DDBC: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8001DDC0: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8001DDC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DDC8:
    // 0x8001DDC8: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8001DDCC: bne         $at, $zero, L_8001DDF4
    if (ctx->r1 != 0) {
        // 0x8001DDD0: andi        $a0, $s0, 0xF0
        ctx->r4 = ctx->r16 & 0XF0;
            goto L_8001DDF4;
    }
    // 0x8001DDD0: andi        $a0, $s0, 0xF0
    ctx->r4 = ctx->r16 & 0XF0;
    // 0x8001DDD4: sra         $a0, $a0, 4
    ctx->r4 = S32(SIGNED(ctx->r4) >> 4);
    // 0x8001DDD8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001DDDC: jal         0x8001D588
    // 0x8001DDE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_6;
    // 0x8001DDE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_6:
    // 0x8001DDE4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DDE8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DDEC: b           L_8001DE08
    // 0x8001DDF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001DE08;
    // 0x8001DDF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DDF4:
    // 0x8001DDF4: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8001DDF8: bne         $at, $zero, L_8001DE08
    if (ctx->r1 != 0) {
        // 0x8001DDFC: addiu       $t3, $zero, 0x20
        ctx->r11 = ADD32(0, 0X20);
            goto L_8001DE08;
    }
    // 0x8001DDFC: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8001DE00: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x8001DE04: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001DE08:
    // 0x8001DE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001DE0C: andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // 0x8001DE10: jal         0x8001D588
    // 0x8001DE14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001D588)(rdram, ctx);
        goto after_7;
    // 0x8001DE14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_7:
    // 0x8001DE18: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DE1C: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8001DE20: sb          $zero, 0x1($a2)
    MEM_B(0X1, ctx->r6) = 0;
    // 0x8001DE24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DE28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DE2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001DE30: jr          $ra
    // 0x8001DE34: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    return;
    // 0x8001DE34: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001de38(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001de38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DE38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DE3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001DE40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DE44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DE48: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8001DE4C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001DE50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001DE54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001DE58: addiu       $s1, $s1, 0x480C
    ctx->r17 = ADD32(ctx->r17, 0X480C);
    // 0x8001DE5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001DE60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8001DE64:
    // 0x8001DE64: jal         0x80005E44
    // 0x8001DE68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8001DE68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8001DE6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001DE70: slti        $at, $s0, 0x28
    ctx->r1 = SIGNED(ctx->r16) < 0X28 ? 1 : 0;
    // 0x8001DE74: bnel        $at, $zero, L_8001DE64
    if (ctx->r1 != 0) {
        // 0x8001DE78: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8001DE64;
    }
    goto skip_0;
    // 0x8001DE78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8001DE7C: jal         0x80006214
    // 0x8001DE80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8001DE80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8001DE84: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001DE88: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001DE8C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001DE90: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8001DE94: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001DE98: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001DE9C: addiu       $t0, $t0, 0x1CC8
    ctx->r8 = ADD32(ctx->r8, 0X1CC8);
    // 0x8001DEA0: addiu       $a0, $a0, 0xF58
    ctx->r4 = ADD32(ctx->r4, 0XF58);
    // 0x8001DEA4: addiu       $a3, $a3, 0xF02
    ctx->r7 = ADD32(ctx->r7, 0XF02);
    // 0x8001DEA8: addiu       $a2, $a2, 0xEAC
    ctx->r6 = ADD32(ctx->r6, 0XEAC);
    // 0x8001DEAC: addiu       $a1, $a1, 0xE56
    ctx->r5 = ADD32(ctx->r5, 0XE56);
    // 0x8001DEB0: addiu       $v0, $v0, 0xE50
    ctx->r2 = ADD32(ctx->r2, 0XE50);
    // 0x8001DEB4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DEB8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8001DEBC:
    // 0x8001DEBC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001DEC0: addiu       $v0, $v0, 0x158
    ctx->r2 = ADD32(ctx->r2, 0X158);
    // 0x8001DEC4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001DEC8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8001DECC: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x8001DED0: sb          $zero, -0x102($v0)
    MEM_B(-0X102, ctx->r2) = 0;
    // 0x8001DED4: lw          $t8, -0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XC);
    // 0x8001DED8: addiu       $a1, $a1, 0x158
    ctx->r5 = ADD32(ctx->r5, 0X158);
    // 0x8001DEDC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8001DEE0: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
    // 0x8001DEE4: sb          $zero, -0xAC($v0)
    MEM_B(-0XAC, ctx->r2) = 0;
    // 0x8001DEE8: lw          $t1, -0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, -0X8);
    // 0x8001DEEC: addiu       $a2, $a2, 0x158
    ctx->r6 = ADD32(ctx->r6, 0X158);
    // 0x8001DEF0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8001DEF4: sw          $a3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r7;
    // 0x8001DEF8: sb          $zero, -0x56($v0)
    MEM_B(-0X56, ctx->r2) = 0;
    // 0x8001DEFC: lw          $t3, -0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X4);
    // 0x8001DF00: addiu       $a3, $a3, 0x158
    ctx->r7 = ADD32(ctx->r7, 0X158);
    // 0x8001DF04: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8001DF08: sw          $a0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r4;
    // 0x8001DF0C: addiu       $a0, $a0, 0x158
    ctx->r4 = ADD32(ctx->r4, 0X158);
    // 0x8001DF10: bnel        $a0, $t0, L_8001DEBC
    if (ctx->r4 != ctx->r8) {
        // 0x8001DF14: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_8001DEBC;
    }
    goto skip_1;
    // 0x8001DF14: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    skip_1:
    // 0x8001DF18: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001DF1C: addiu       $a1, $a1, -0x20C0
    ctx->r5 = ADD32(ctx->r5, -0X20C0);
    // 0x8001DF20: jal         0x800058DC
    // 0x8001DF24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8001DF24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8001DF28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001DF2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DF30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DF34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001DF38: jr          $ra
    // 0x8001DF3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001DF3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001df40(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001df40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DF40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001DF44: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8001DF48: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001DF4C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001DF50: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8001DF54: addiu       $v0, $v0, 0x7744
    ctx->r2 = ADD32(ctx->r2, 0X7744);
    // 0x8001DF58: addiu       $a0, $a0, 0xE50
    ctx->r4 = ADD32(ctx->r4, 0XE50);
    // 0x8001DF5C: addiu       $a1, $a1, 0x1BC0
    ctx->r5 = ADD32(ctx->r5, 0X1BC0);
L_8001DF60:
    // 0x8001DF60: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8001DF64: beql        $t6, $zero, L_8001DF80
    if (ctx->r14 == 0) {
        // 0x8001DF68: lw          $t9, 0x0($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X0);
            goto L_8001DF80;
    }
    goto skip_0;
    // 0x8001DF68: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8001DF6C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8001DF70: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001DF74: b           L_8001DF84
    // 0x8001DF78: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
        goto L_8001DF84;
    // 0x8001DF78: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
    // 0x8001DF7C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
L_8001DF80:
    // 0x8001DF80: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
L_8001DF84:
    // 0x8001DF84: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8001DF88: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x8001DF8C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8001DF90: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x8001DF94: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001DF98: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x8001DF9C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8001DFA0: sh          $t3, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r11;
    // 0x8001DFA4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8001DFA8: beql        $t6, $zero, L_8001DFC4
    if (ctx->r14 == 0) {
        // 0x8001DFAC: lw          $t9, 0x4($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X4);
            goto L_8001DFC4;
    }
    goto skip_1;
    // 0x8001DFAC: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8001DFB0: lbu         $t7, 0x56($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X56);
    // 0x8001DFB4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8001DFB8: b           L_8001DFC8
    // 0x8001DFBC: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
        goto L_8001DFC8;
    // 0x8001DFBC: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
    // 0x8001DFC0: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
L_8001DFC4:
    // 0x8001DFC4: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
L_8001DFC8:
    // 0x8001DFC8: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8001DFCC: lh          $t1, 0x58($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X58);
    // 0x8001DFD0: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    // 0x8001DFD4: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x8001DFD8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001DFDC: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x8001DFE0: lw          $t3, -0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X4);
    // 0x8001DFE4: lh          $t4, -0x52($a0)
    ctx->r12 = MEM_H(ctx->r4, -0X52);
    // 0x8001DFE8: lw          $t5, 0x2C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X2C);
    // 0x8001DFEC: bne         $a0, $a1, L_8001DF60
    if (ctx->r4 != ctx->r5) {
        // 0x8001DFF0: sh          $t4, 0x2($t5)
        MEM_H(0X2, ctx->r13) = ctx->r12;
            goto L_8001DF60;
    }
    // 0x8001DFF0: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x8001DFF4: jr          $ra
    // 0x8001DFF8: nop

    return;
    // 0x8001DFF8: nop

;}
RECOMP_FUNC void FUN_8001dffc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DFFC: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8001E000: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001E004: sw          $a1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r5;
    // 0x8001E008: sw          $a2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r6;
    // 0x8001E00C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001E010: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001E014: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001E018: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x8001E01C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001E020: addiu       $t6, $t6, 0x481C
    ctx->r14 = ADD32(ctx->r14, 0X481C);
    // 0x8001E024: andi        $s5, $a0, 0xFF
    ctx->r21 = ctx->r4 & 0XFF;
    // 0x8001E028: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001E02C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001E030: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001E034: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001E038: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001E03C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001E040: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001E044: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001E048: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001E04C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E050: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x8001E054: sw          $a3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r7;
    // 0x8001E058: addiu       $t0, $t6, 0xC0
    ctx->r8 = ADD32(ctx->r14, 0XC0);
    // 0x8001E05C: or          $t9, $s1, $zero
    ctx->r25 = ctx->r17 | 0;
L_8001E060:
    // 0x8001E060: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001E064: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001E068: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8001E06C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8001E070: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8001E074: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8001E078: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8001E07C: bne         $t6, $t0, L_8001E060
    if (ctx->r14 != ctx->r8) {
        // 0x8001E080: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8001E060;
    }
    // 0x8001E080: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8001E084: lw          $t1, 0x13C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X13C);
    // 0x8001E088: sll         $t0, $s5, 2
    ctx->r8 = S32(ctx->r21 << 2);
    // 0x8001E08C: subu        $t0, $t0, $s5
    ctx->r8 = SUB32(ctx->r8, ctx->r21);
    // 0x8001E090: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8001E094: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001E098: subu        $t0, $t0, $s5
    ctx->r8 = SUB32(ctx->r8, ctx->r21);
    // 0x8001E09C: bne         $t2, $zero, L_8001E0DC
    if (ctx->r10 != 0) {
        // 0x8001E0A0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8001E0DC;
    }
    // 0x8001E0A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001E0A4: sll         $t3, $s5, 2
    ctx->r11 = S32(ctx->r21 << 2);
    // 0x8001E0A8: subu        $t3, $t3, $s5
    ctx->r11 = SUB32(ctx->r11, ctx->r21);
    // 0x8001E0AC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001E0B0: subu        $t3, $t3, $s5
    ctx->r11 = SUB32(ctx->r11, ctx->r21);
    // 0x8001E0B4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001E0B8: subu        $t3, $t3, $s5
    ctx->r11 = SUB32(ctx->r11, ctx->r21);
    // 0x8001E0BC: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8001E0C0: addiu       $t4, $t4, 0xE50
    ctx->r12 = ADD32(ctx->r12, 0XE50);
    // 0x8001E0C4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8001E0C8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8001E0CC: ori         $t5, $zero, 0xFFFF
    ctx->r13 = 0 | 0XFFFF;
    // 0x8001E0D0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001E0D4: b           L_8001E490
    // 0x8001E0D8: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
        goto L_8001E490;
    // 0x8001E0D8: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
L_8001E0DC:
    // 0x8001E0DC: subu        $t0, $t0, $s5
    ctx->r8 = SUB32(ctx->r8, ctx->r21);
    // 0x8001E0E0: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001E0E4: addiu       $t6, $t6, 0xE50
    ctx->r14 = ADD32(ctx->r14, 0XE50);
    // 0x8001E0E8: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8001E0EC: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x8001E0F0: lw          $t7, 0x13C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X13C);
    // 0x8001E0F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001E0F8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001E0FC: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x8001E100: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    // 0x8001E104: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8001E108: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x8001E10C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001E110: beq         $a0, $zero, L_8001E45C
    if (ctx->r4 == 0) {
        // 0x8001E114: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001E45C;
    }
    // 0x8001E114: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001E118: addiu       $fp, $sp, 0x118
    ctx->r30 = ADD32(ctx->r29, 0X118);
    // 0x8001E11C: addiu       $s7, $zero, 0x30
    ctx->r23 = ADD32(0, 0X30);
    // 0x8001E120: addiu       $s6, $zero, -0x4
    ctx->r22 = ADD32(0, -0X4);
    // 0x8001E124: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
L_8001E128:
    // 0x8001E128: beq         $a0, $at, L_8001E1C0
    if (ctx->r4 == ctx->r1) {
        // 0x8001E12C: lw          $t3, 0x13C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X13C);
            goto L_8001E1C0;
    }
    // 0x8001E12C: lw          $t3, 0x13C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X13C);
    // 0x8001E130: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8001E134: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E138: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E13C: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E140: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E144: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E148: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001E14C: addiu       $t1, $t1, 0xE50
    ctx->r9 = ADD32(ctx->r9, 0XE50);
    // 0x8001E150: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001E154: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x8001E158: bne         $at, $zero, L_8001E18C
    if (ctx->r1 != 0) {
        // 0x8001E15C: addu        $a1, $t8, $t1
        ctx->r5 = ADD32(ctx->r24, ctx->r9);
            goto L_8001E18C;
    }
    // 0x8001E15C: addu        $a1, $t8, $t1
    ctx->r5 = ADD32(ctx->r24, ctx->r9);
    // 0x8001E160: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001E164: beq         $at, $zero, L_8001E18C
    if (ctx->r1 == 0) {
        // 0x8001E168: sll         $t2, $a0, 1
        ctx->r10 = S32(ctx->r4 << 1);
            goto L_8001E18C;
    }
    // 0x8001E168: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x8001E16C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x8001E170: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x8001E174: lhu         $t4, -0x40($t3)
    ctx->r12 = MEM_HU(ctx->r11, -0X40);
    // 0x8001E178: addu        $t0, $a1, $t5
    ctx->r8 = ADD32(ctx->r5, ctx->r13);
    // 0x8001E17C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E180: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8001E184: b           L_8001E440
    // 0x8001E188: sh          $t4, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r12;
        goto L_8001E440;
    // 0x8001E188: sh          $t4, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r12;
L_8001E18C:
    // 0x8001E18C: lw          $t6, 0x13C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X13C);
    // 0x8001E190: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001E194: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x8001E198: addu        $t9, $s3, $t6
    ctx->r25 = ADD32(ctx->r19, ctx->r14);
    // 0x8001E19C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x8001E1A0: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x8001E1A4: sll         $t7, $a0, 8
    ctx->r15 = S32(ctx->r4 << 8);
    // 0x8001E1A8: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x8001E1AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E1B0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8001E1B4: sh          $t8, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r24;
    // 0x8001E1B8: b           L_8001E440
    // 0x8001E1BC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
        goto L_8001E440;
    // 0x8001E1BC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
L_8001E1C0:
    // 0x8001E1C0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001E1C4: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x8001E1C8: addu        $t5, $s3, $t3
    ctx->r13 = ADD32(ctx->r19, ctx->r11);
    // 0x8001E1CC: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x8001E1D0: addiu       $at, $zero, 0x73
    ctx->r1 = ADD32(0, 0X73);
    // 0x8001E1D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001E1D8: bne         $a0, $at, L_8001E288
    if (ctx->r4 != ctx->r1) {
        // 0x8001E1DC: addiu       $t4, $s4, 0x3
        ctx->r12 = ADD32(ctx->r20, 0X3);
            goto L_8001E288;
    }
    // 0x8001E1DC: addiu       $t4, $s4, 0x3
    ctx->r12 = ADD32(ctx->r20, 0X3);
    // 0x8001E1E0: and         $s4, $t4, $s6
    ctx->r20 = ctx->r12 & ctx->r22;
    // 0x8001E1E4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8001E1E8: sll         $t0, $s5, 2
    ctx->r8 = S32(ctx->r21 << 2);
    // 0x8001E1EC: subu        $t0, $t0, $s5
    ctx->r8 = SUB32(ctx->r8, ctx->r21);
    // 0x8001E1F0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E1F4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8001E1F8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001E1FC: beq         $a0, $zero, L_8001E288
    if (ctx->r4 == 0) {
        // 0x8001E200: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001E288;
    }
    // 0x8001E200: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E204: subu        $t0, $t0, $s5
    ctx->r8 = SUB32(ctx->r8, ctx->r21);
    // 0x8001E208: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001E20C: subu        $t0, $t0, $s5
    ctx->r8 = SUB32(ctx->r8, ctx->r21);
    // 0x8001E210: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001E214: addiu       $t6, $t6, 0xE50
    ctx->r14 = ADD32(ctx->r14, 0XE50);
    // 0x8001E218: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8001E21C: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    // 0x8001E220: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
L_8001E224:
    // 0x8001E224: bne         $at, $zero, L_8001E258
    if (ctx->r1 != 0) {
        // 0x8001E228: sll         $t3, $a0, 8
        ctx->r11 = S32(ctx->r4 << 8);
            goto L_8001E258;
    }
    // 0x8001E228: sll         $t3, $a0, 8
    ctx->r11 = S32(ctx->r4 << 8);
    // 0x8001E22C: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001E230: beq         $at, $zero, L_8001E258
    if (ctx->r1 == 0) {
        // 0x8001E234: sll         $t9, $a0, 1
        ctx->r25 = S32(ctx->r4 << 1);
            goto L_8001E258;
    }
    // 0x8001E234: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8001E238: addu        $t7, $s1, $t9
    ctx->r15 = ADD32(ctx->r17, ctx->r25);
    // 0x8001E23C: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x8001E240: lhu         $t1, -0x40($t7)
    ctx->r9 = MEM_HU(ctx->r15, -0X40);
    // 0x8001E244: addu        $t2, $a1, $t8
    ctx->r10 = ADD32(ctx->r5, ctx->r24);
    // 0x8001E248: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E24C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8001E250: b           L_8001E278
    // 0x8001E254: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
        goto L_8001E278;
    // 0x8001E254: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
L_8001E258:
    // 0x8001E258: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E25C: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x8001E260: addu        $t0, $a1, $t4
    ctx->r8 = ADD32(ctx->r5, ctx->r12);
    // 0x8001E264: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E268: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x8001E26C: sh          $t5, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r13;
    // 0x8001E270: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8001E274: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001E278:
    // 0x8001E278: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E27C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E280: bnel        $a0, $zero, L_8001E224
    if (ctx->r4 != 0) {
        // 0x8001E284: slti        $at, $a0, 0x20
        ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
            goto L_8001E224;
    }
    goto skip_0;
    // 0x8001E284: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    skip_0:
L_8001E288:
    // 0x8001E288: bne         $s7, $a0, L_8001E338
    if (ctx->r23 != ctx->r4) {
        // 0x8001E28C: lw          $t6, 0x13C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X13C);
            goto L_8001E338;
    }
    // 0x8001E28C: lw          $t6, 0x13C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X13C);
    // 0x8001E290: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001E294: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x8001E298: addu        $t9, $s3, $t6
    ctx->r25 = ADD32(ctx->r19, ctx->r14);
    // 0x8001E29C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8001E2A0: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8001E2A4: lw          $t7, 0x13C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X13C);
    // 0x8001E2A8: bnel        $a0, $at, L_8001E2B8
    if (ctx->r4 != ctx->r1) {
        // 0x8001E2AC: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_8001E2B8;
    }
    goto skip_1;
    // 0x8001E2AC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    skip_1:
    // 0x8001E2B0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001E2B4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
L_8001E2B8:
    // 0x8001E2B8: bne         $a0, $at, L_8001E2C4
    if (ctx->r4 != ctx->r1) {
        // 0x8001E2BC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8001E2C4;
    }
    // 0x8001E2BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001E2C0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8001E2C4:
    // 0x8001E2C4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8001E2C8: bne         $a0, $at, L_8001E2D4
    if (ctx->r4 != ctx->r1) {
        // 0x8001E2CC: andi        $s3, $s3, 0xFF
        ctx->r19 = ctx->r19 & 0XFF;
            goto L_8001E2D4;
    }
    // 0x8001E2CC: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x8001E2D0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8001E2D4:
    // 0x8001E2D4: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8001E2D8: bne         $a0, $at, L_8001E2E4
    if (ctx->r4 != ctx->r1) {
        // 0x8001E2DC: addu        $t8, $s3, $t7
        ctx->r24 = ADD32(ctx->r19, ctx->r15);
            goto L_8001E2E4;
    }
    // 0x8001E2DC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8001E2E0: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8001E2E4:
    // 0x8001E2E4: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x8001E2E8: bnel        $a0, $at, L_8001E2F8
    if (ctx->r4 != ctx->r1) {
        // 0x8001E2EC: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_8001E2F8;
    }
    goto skip_2;
    // 0x8001E2EC: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    skip_2:
    // 0x8001E2F0: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x8001E2F4: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
L_8001E2F8:
    // 0x8001E2F8: bnel        $a0, $at, L_8001E308
    if (ctx->r4 != ctx->r1) {
        // 0x8001E2FC: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_8001E308;
    }
    goto skip_3;
    // 0x8001E2FC: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    skip_3:
    // 0x8001E300: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8001E304: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
L_8001E308:
    // 0x8001E308: bnel        $a0, $at, L_8001E318
    if (ctx->r4 != ctx->r1) {
        // 0x8001E30C: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_8001E318;
    }
    goto skip_4;
    // 0x8001E30C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    skip_4:
    // 0x8001E310: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x8001E314: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
L_8001E318:
    // 0x8001E318: bnel        $a0, $at, L_8001E328
    if (ctx->r4 != ctx->r1) {
        // 0x8001E31C: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_8001E328;
    }
    goto skip_5;
    // 0x8001E31C: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    skip_5:
    // 0x8001E320: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x8001E324: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
L_8001E328:
    // 0x8001E328: bnel        $a0, $at, L_8001E338
    if (ctx->r4 != ctx->r1) {
        // 0x8001E32C: lbu         $a0, 0x0($t8)
        ctx->r4 = MEM_BU(ctx->r24, 0X0);
            goto L_8001E338;
    }
    goto skip_6;
    // 0x8001E32C: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    skip_6:
    // 0x8001E330: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
    // 0x8001E334: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
L_8001E338:
    // 0x8001E338: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8001E33C: bne         $a0, $at, L_8001E3BC
    if (ctx->r4 != ctx->r1) {
        // 0x8001E340: addiu       $t1, $s4, 0x3
        ctx->r9 = ADD32(ctx->r20, 0X3);
            goto L_8001E3BC;
    }
    // 0x8001E340: addiu       $t1, $s4, 0x3
    ctx->r9 = ADD32(ctx->r20, 0X3);
    // 0x8001E344: and         $s4, $t1, $s6
    ctx->r20 = ctx->r9 & ctx->r22;
    // 0x8001E348: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8001E34C: lw          $a0, -0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, -0X4);
    // 0x8001E350: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // 0x8001E354: jal         0x8001DBC8
    // 0x8001E358: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    LOOKUP_FUNC(0x8001DBC8)(rdram, ctx);
        goto after_0;
    // 0x8001E358: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_0:
    // 0x8001E35C: lbu         $a0, 0x118($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X118);
    // 0x8001E360: sll         $t2, $s5, 2
    ctx->r10 = S32(ctx->r21 << 2);
    // 0x8001E364: subu        $t2, $t2, $s5
    ctx->r10 = SUB32(ctx->r10, ctx->r21);
    // 0x8001E368: beq         $a0, $zero, L_8001E3BC
    if (ctx->r4 == 0) {
        // 0x8001E36C: addiu       $v0, $sp, 0x119
        ctx->r2 = ADD32(ctx->r29, 0X119);
            goto L_8001E3BC;
    }
    // 0x8001E36C: addiu       $v0, $sp, 0x119
    ctx->r2 = ADD32(ctx->r29, 0X119);
    // 0x8001E370: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001E374: subu        $t2, $t2, $s5
    ctx->r10 = SUB32(ctx->r10, ctx->r21);
    // 0x8001E378: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001E37C: subu        $t2, $t2, $s5
    ctx->r10 = SUB32(ctx->r10, ctx->r21);
    // 0x8001E380: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001E384: addiu       $t3, $t3, 0xE50
    ctx->r11 = ADD32(ctx->r11, 0XE50);
    // 0x8001E388: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8001E38C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
L_8001E390:
    // 0x8001E390: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8001E394: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x8001E398: lhu         $t0, -0x40($t5)
    ctx->r8 = MEM_HU(ctx->r13, -0X40);
    // 0x8001E39C: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x8001E3A0: addu        $t9, $a1, $t6
    ctx->r25 = ADD32(ctx->r5, ctx->r14);
    // 0x8001E3A4: sh          $t0, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r8;
    // 0x8001E3A8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E3AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E3B0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8001E3B4: bne         $a0, $zero, L_8001E390
    if (ctx->r4 != 0) {
        // 0x8001E3B8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001E390;
    }
    // 0x8001E3B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001E3BC:
    // 0x8001E3BC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8001E3C0: bne         $a0, $at, L_8001E440
    if (ctx->r4 != ctx->r1) {
        // 0x8001E3C4: addiu       $t7, $s4, 0x3
        ctx->r15 = ADD32(ctx->r20, 0X3);
            goto L_8001E440;
    }
    // 0x8001E3C4: addiu       $t7, $s4, 0x3
    ctx->r15 = ADD32(ctx->r20, 0X3);
    // 0x8001E3C8: and         $s4, $t7, $s6
    ctx->r20 = ctx->r15 & ctx->r22;
    // 0x8001E3CC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8001E3D0: lw          $a0, -0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, -0X4);
    // 0x8001E3D4: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // 0x8001E3D8: jal         0x8001D69C
    // 0x8001E3DC: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    LOOKUP_FUNC(0x8001D69C)(rdram, ctx);
        goto after_1;
    // 0x8001E3DC: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_1:
    // 0x8001E3E0: lbu         $a0, 0x118($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X118);
    // 0x8001E3E4: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8001E3E8: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E3EC: beq         $a0, $zero, L_8001E440
    if (ctx->r4 == 0) {
        // 0x8001E3F0: addiu       $v0, $sp, 0x119
        ctx->r2 = ADD32(ctx->r29, 0X119);
            goto L_8001E440;
    }
    // 0x8001E3F0: addiu       $v0, $sp, 0x119
    ctx->r2 = ADD32(ctx->r29, 0X119);
    // 0x8001E3F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E3F8: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E3FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E400: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E404: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001E408: addiu       $t1, $t1, 0xE50
    ctx->r9 = ADD32(ctx->r9, 0XE50);
    // 0x8001E40C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001E410: addu        $a1, $t8, $t1
    ctx->r5 = ADD32(ctx->r24, ctx->r9);
L_8001E414:
    // 0x8001E414: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x8001E418: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x8001E41C: lhu         $t4, -0x40($t3)
    ctx->r12 = MEM_HU(ctx->r11, -0X40);
    // 0x8001E420: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x8001E424: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8001E428: sh          $t4, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r12;
    // 0x8001E42C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E430: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E434: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8001E438: bne         $a0, $zero, L_8001E414
    if (ctx->r4 != 0) {
        // 0x8001E43C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001E414;
    }
    // 0x8001E43C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001E440:
    // 0x8001E440: lw          $t0, 0x13C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X13C);
    // 0x8001E444: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001E448: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x8001E44C: addu        $t9, $s3, $t0
    ctx->r25 = ADD32(ctx->r19, ctx->r8);
    // 0x8001E450: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8001E454: bnel        $a0, $zero, L_8001E128
    if (ctx->r4 != 0) {
        // 0x8001E458: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_8001E128;
    }
    goto skip_7;
    // 0x8001E458: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    skip_7:
L_8001E45C:
    // 0x8001E45C: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8001E460: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E464: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E468: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E46C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E470: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001E474: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001E478: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x8001E47C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8001E480: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E484: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8001E488: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8001E48C: sh          $t7, 0xE56($at)
    MEM_H(0XE56, ctx->r1) = ctx->r15;
L_8001E490:
    // 0x8001E490: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E494: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E498: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E49C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E4A0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E4A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E4A8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E4AC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001E4B0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001E4B4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001E4B8: jr          $ra
    // 0x8001E4BC: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8001E4BC: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001e4c0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001e4c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4C0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001E4C4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8001E4C8: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8001E4CC: lbu         $t8, 0x15A($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X15A);
    // 0x8001E4D0: lbu         $t9, 0x15B($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X15B);
    // 0x8001E4D4: lbu         $t0, 0x15C($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X15C);
    // 0x8001E4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E4DC: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8001E4E0: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x8001E4E4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001E4E8: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8001E4EC: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x8001E4F0: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x8001E4F4: sh          $t7, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r15;
    // 0x8001E4F8: sh          $t6, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r14;
    // 0x8001E4FC: sb          $t8, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r24;
    // 0x8001E500: sb          $t9, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r25;
    // 0x8001E504: jal         0x801302CC
    // 0x8001E508: sb          $t0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_0;
    // 0x8001E508: sb          $t0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r8;
    after_0:
    // 0x8001E50C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8001E510: beq         $v0, $zero, L_8001E544
    if (ctx->r2 == 0) {
        // 0x8001E514: addiu       $a2, $a2, -0x4410
        ctx->r6 = ADD32(ctx->r6, -0X4410);
            goto L_8001E544;
    }
    // 0x8001E514: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8001E518: lbu         $t1, 0x34($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X34);
    // 0x8001E51C: lbu         $t2, 0x35($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X35);
    // 0x8001E520: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x8001E524: bne         $t1, $zero, L_8001E53C
    if (ctx->r9 != 0) {
        // 0x8001E528: addiu       $t5, $zero, 0x96
        ctx->r13 = ADD32(0, 0X96);
            goto L_8001E53C;
    }
    // 0x8001E528: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x8001E52C: bne         $t2, $zero, L_8001E53C
    if (ctx->r10 != 0) {
        // 0x8001E530: lbu         $t3, 0x36($sp)
        ctx->r11 = MEM_BU(ctx->r29, 0X36);
            goto L_8001E53C;
    }
    // 0x8001E530: lbu         $t3, 0x36($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X36);
    // 0x8001E534: beql        $t3, $zero, L_8001E548
    if (ctx->r11 == 0) {
        // 0x8001E538: lbu         $v1, 0x15D($a2)
        ctx->r3 = MEM_BU(ctx->r6, 0X15D);
            goto L_8001E548;
    }
    goto skip_0;
    // 0x8001E538: lbu         $v1, 0x15D($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X15D);
    skip_0:
L_8001E53C:
    // 0x8001E53C: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x8001E540: sh          $t5, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r13;
L_8001E544:
    // 0x8001E544: lbu         $v1, 0x15D($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X15D);
L_8001E548:
    // 0x8001E548: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001E54C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8001E550: beq         $v1, $at, L_8001E560
    if (ctx->r3 == ctx->r1) {
        // 0x8001E554: addiu       $a1, $a1, 0x48F4
        ctx->r5 = ADD32(ctx->r5, 0X48F4);
            goto L_8001E560;
    }
    // 0x8001E554: addiu       $a1, $a1, 0x48F4
    ctx->r5 = ADD32(ctx->r5, 0X48F4);
    // 0x8001E558: bne         $v1, $zero, L_8001E570
    if (ctx->r3 != 0) {
        // 0x8001E55C: addiu       $t7, $zero, 0x1002
        ctx->r15 = ADD32(0, 0X1002);
            goto L_8001E570;
    }
    // 0x8001E55C: addiu       $t7, $zero, 0x1002
    ctx->r15 = ADD32(0, 0X1002);
L_8001E560:
    // 0x8001E560: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8001E564: sb          $t6, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r14;
    // 0x8001E568: b           L_8001E578
    // 0x8001E56C: sh          $zero, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = 0;
        goto L_8001E578;
    // 0x8001E56C: sh          $zero, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = 0;
L_8001E570:
    // 0x8001E570: sb          $zero, 0x37($sp)
    MEM_B(0X37, ctx->r29) = 0;
    // 0x8001E574: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
L_8001E578:
    // 0x8001E578: lbu         $v0, 0x15E($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X15E);
    // 0x8001E57C: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8001E580: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x8001E584: beq         $v0, $zero, L_8001E598
    if (ctx->r2 == 0) {
        // 0x8001E588: sw          $t8, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->r24;
            goto L_8001E598;
    }
    // 0x8001E588: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x8001E58C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8001E590: b           L_8001E5A0
    // 0x8001E594: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
        goto L_8001E5A0;
    // 0x8001E594: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
L_8001E598:
    // 0x8001E598: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8001E59C: sh          $t0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r8;
L_8001E5A0:
    // 0x8001E5A0: beql        $v0, $zero, L_8001E5B4
    if (ctx->r2 == 0) {
        // 0x8001E5A4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8001E5B4;
    }
    goto skip_1;
    // 0x8001E5A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_1:
    // 0x8001E5A8: b           L_8001E5B4
    // 0x8001E5AC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
        goto L_8001E5B4;
    // 0x8001E5AC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8001E5B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8001E5B4:
    // 0x8001E5B4: jal         0x80116E80
    // 0x8001E5B8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x8001E5B8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x8001E5BC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8001E5C0: addiu       $a1, $a1, 0x48F4
    ctx->r5 = ADD32(ctx->r5, 0X48F4);
    // 0x8001E5C4: jal         0x80005E44
    // 0x8001E5C8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x8001E5C8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_2:
    // 0x8001E5CC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8001E5D0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8001E5D4: lbu         $v1, 0x15D($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X15D);
    // 0x8001E5D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E5DC: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8001E5E0: bne         $a0, $v1, L_8001E5F4
    if (ctx->r4 != ctx->r3) {
        // 0x8001E5E4: sll         $t2, $v1, 4
        ctx->r10 = S32(ctx->r3 << 4);
            goto L_8001E5F4;
    }
    // 0x8001E5E4: sll         $t2, $v1, 4
    ctx->r10 = S32(ctx->r3 << 4);
    // 0x8001E5E8: lhu         $t1, 0x154($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X154);
    // 0x8001E5EC: b           L_8001E5F8
    // 0x8001E5F0: sh          $t1, 0x158($a2)
    MEM_H(0X158, ctx->r6) = ctx->r9;
        goto L_8001E5F8;
    // 0x8001E5F0: sh          $t1, 0x158($a2)
    MEM_H(0X158, ctx->r6) = ctx->r9;
L_8001E5F4:
    // 0x8001E5F4: sh          $zero, 0x158($a2)
    MEM_H(0X158, ctx->r6) = 0;
L_8001E5F8:
    // 0x8001E5F8: or          $t4, $v1, $t2
    ctx->r12 = ctx->r3 | ctx->r10;
    // 0x8001E5FC: sb          $t4, 0x15D($a2)
    MEM_B(0X15D, ctx->r6) = ctx->r12;
    // 0x8001E600: ori         $v0, $t4, 0x80
    ctx->r2 = ctx->r12 | 0X80;
    // 0x8001E604: sb          $v0, 0x15D($a2)
    MEM_B(0X15D, ctx->r6) = ctx->r2;
    // 0x8001E608: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001E60C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8001E610: bne         $v0, $zero, L_8001E630
    if (ctx->r2 != 0) {
        // 0x8001E614: sb          $t6, 0x164($a2)
        MEM_B(0X164, ctx->r6) = ctx->r14;
            goto L_8001E630;
    }
    // 0x8001E614: sb          $t6, 0x164($a2)
    MEM_B(0X164, ctx->r6) = ctx->r14;
    // 0x8001E618: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001E61C: addiu       $a1, $a1, -0x1898
    ctx->r5 = ADD32(ctx->r5, -0X1898);
    // 0x8001E620: jal         0x800058DC
    // 0x8001E624: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8001E624: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8001E628: b           L_8001E660
    // 0x8001E62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E660;
    // 0x8001E62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E630:
    // 0x8001E630: bne         $a0, $v0, L_8001E650
    if (ctx->r4 != ctx->r2) {
        // 0x8001E634: lui         $a1, 0x8002
        ctx->r5 = S32(0X8002 << 16);
            goto L_8001E650;
    }
    // 0x8001E634: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001E638: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001E63C: addiu       $a1, $a1, -0x1784
    ctx->r5 = ADD32(ctx->r5, -0X1784);
    // 0x8001E640: jal         0x800058DC
    // 0x8001E644: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8001E644: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x8001E648: b           L_8001E660
    // 0x8001E64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E660;
    // 0x8001E64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E650:
    // 0x8001E650: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001E654: jal         0x800058DC
    // 0x8001E658: addiu       $a1, $a1, -0x1994
    ctx->r5 = ADD32(ctx->r5, -0X1994);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8001E658: addiu       $a1, $a1, -0x1994
    ctx->r5 = ADD32(ctx->r5, -0X1994);
    after_5:
    // 0x8001E65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E660:
    // 0x8001E660: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001E664: jr          $ra
    // 0x8001E668: nop

    return;
    // 0x8001E668: nop

;}
RECOMP_FUNC void FUN_8001e66c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E66C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001E678: jal         0x80006214
    // 0x8001E67C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8001E67C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001E680: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001E684: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E688: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001E68C: lhu         $t8, 0x158($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X158);
    // 0x8001E690: lhu         $a1, 0x154($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X154);
    // 0x8001E694: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001E698: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8001E69C: andi        $a0, $t9, 0xFFFF
    ctx->r4 = ctx->r25 & 0XFFFF;
    // 0x8001E6A0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001E6A4: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x8001E6A8: beq         $at, $zero, L_8001E6F0
    if (ctx->r1 == 0) {
        // 0x8001E6AC: sh          $t9, 0x158($v0)
        MEM_H(0X158, ctx->r2) = ctx->r25;
            goto L_8001E6F0;
    }
    // 0x8001E6AC: sh          $t9, 0x158($v0)
    MEM_H(0X158, ctx->r2) = ctx->r25;
    // 0x8001E6B0: sll         $t0, $a0, 8
    ctx->r8 = S32(ctx->r4 << 8);
    // 0x8001E6B4: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8001E6B8: div         $zero, $t0, $a1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r5)));
    // 0x8001E6BC: mflo        $t1
    ctx->r9 = lo;
    // 0x8001E6C0: sb          $t1, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r9;
    // 0x8001E6C4: bne         $a1, $zero, L_8001E6D0
    if (ctx->r5 != 0) {
        // 0x8001E6C8: nop
    
            goto L_8001E6D0;
    }
    // 0x8001E6C8: nop

    // 0x8001E6CC: break       7
    do_break(2147608268);
L_8001E6D0:
    // 0x8001E6D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E6D4: bne         $a1, $at, L_8001E6E8
    if (ctx->r5 != ctx->r1) {
        // 0x8001E6D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E6E8;
    }
    // 0x8001E6D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E6DC: bne         $t0, $at, L_8001E6E8
    if (ctx->r8 != ctx->r1) {
        // 0x8001E6E0: nop
    
            goto L_8001E6E8;
    }
    // 0x8001E6E0: nop

    // 0x8001E6E4: break       6
    do_break(2147608292);
L_8001E6E8:
    // 0x8001E6E8: b           L_8001E75C
    // 0x8001E6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E75C;
    // 0x8001E6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E6F0:
    // 0x8001E6F0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8001E6F4: sb          $t2, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r10;
    // 0x8001E6F8: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x8001E6FC: lhu         $t4, 0x158($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X158);
    // 0x8001E700: lhu         $t3, 0x154($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X154);
    // 0x8001E704: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001E708: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001E70C: bne         $t3, $t4, L_8001E720
    if (ctx->r11 != ctx->r12) {
        // 0x8001E710: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_8001E720;
    }
    // 0x8001E710: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001E714: lh          $t5, -0x6CB4($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6CB4);
    // 0x8001E718: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001E71C: sb          $t5, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r13;
L_8001E720:
    // 0x8001E720: lh          $t6, -0x6CB4($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6CB4);
    // 0x8001E724: lbu         $t7, 0x4914($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4914);
    // 0x8001E728: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001E72C: addiu       $a1, $a1, -0x1898
    ctx->r5 = ADD32(ctx->r5, -0X1898);
    // 0x8001E730: beql        $t6, $t7, L_8001E75C
    if (ctx->r14 == ctx->r15) {
        // 0x8001E734: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E75C;
    }
    goto skip_0;
    // 0x8001E734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001E738: lbu         $t8, 0x15D($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X15D);
    // 0x8001E73C: sh          $zero, 0x158($v0)
    MEM_H(0X158, ctx->r2) = 0;
    // 0x8001E740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001E744: andi        $t0, $t8, 0xF
    ctx->r8 = ctx->r24 & 0XF;
    // 0x8001E748: sb          $t0, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = ctx->r8;
    // 0x8001E74C: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x8001E750: jal         0x800058DC
    // 0x8001E754: sb          $t1, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = ctx->r9;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8001E754: sb          $t1, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = ctx->r9;
    after_1:
    // 0x8001E758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E75C:
    // 0x8001E75C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E760: jr          $ra
    // 0x8001E764: nop

    return;
    // 0x8001E764: nop

;}
RECOMP_FUNC void FUN_8001e768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E768: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001E76C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001E770: lbu         $t6, 0x15D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X15D);
    // 0x8001E774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E778: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E77C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8001E780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E784: bne         $t7, $at, L_8001E7AC
    if (ctx->r15 != ctx->r1) {
        // 0x8001E788: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8001E7AC;
    }
    // 0x8001E788: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E78C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001E790: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E794: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001E798: sh          $t8, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r24;
    // 0x8001E79C: jal         0x800058DC
    // 0x8001E7A0: addiu       $a1, $a1, -0x17D0
    ctx->r5 = ADD32(ctx->r5, -0X17D0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8001E7A0: addiu       $a1, $a1, -0x17D0
    ctx->r5 = ADD32(ctx->r5, -0X17D0);
    after_0:
    // 0x8001E7A4: b           L_8001E824
    // 0x8001E7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E824;
    // 0x8001E7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E7AC:
    // 0x8001E7AC: lhu         $v1, 0x156($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X156);
    // 0x8001E7B0: beql        $v1, $zero, L_8001E824
    if (ctx->r3 == 0) {
        // 0x8001E7B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E824;
    }
    goto skip_0;
    // 0x8001E7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001E7B8: lhu         $t9, 0x158($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X158);
    // 0x8001E7BC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8001E7C0: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8001E7C4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E7C8: bne         $at, $zero, L_8001E820
    if (ctx->r1 != 0) {
        // 0x8001E7CC: sh          $t0, 0x158($v0)
        MEM_H(0X158, ctx->r2) = ctx->r8;
            goto L_8001E820;
    }
    // 0x8001E7CC: sh          $t0, 0x158($v0)
    MEM_H(0X158, ctx->r2) = ctx->r8;
    // 0x8001E7D0: jal         0x80006214
    // 0x8001E7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8001E7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8001E7D8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E7DC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001E7E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001E7E4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001E7E8: addiu       $t2, $zero, 0x1002
    ctx->r10 = ADD32(0, 0X1002);
    // 0x8001E7EC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001E7F0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8001E7F4: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001E7F8: addiu       $a1, $a1, -0x1784
    ctx->r5 = ADD32(ctx->r5, -0X1784);
    // 0x8001E7FC: sh          $t2, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r10;
    // 0x8001E800: lbu         $t7, 0x15D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X15D);
    // 0x8001E804: lhu         $t6, 0x154($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X154);
    // 0x8001E808: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x8001E80C: sb          $t9, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = ctx->r25;
    // 0x8001E810: ori         $t0, $t9, 0xA0
    ctx->r8 = ctx->r25 | 0XA0;
    // 0x8001E814: sb          $t0, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = ctx->r8;
    // 0x8001E818: jal         0x800058DC
    // 0x8001E81C: sh          $t6, 0x158($v0)
    MEM_H(0X158, ctx->r2) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8001E81C: sh          $t6, 0x158($v0)
    MEM_H(0X158, ctx->r2) = ctx->r14;
    after_2:
L_8001E820:
    // 0x8001E820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E824:
    // 0x8001E824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E828: jr          $ra
    // 0x8001E82C: nop

    return;
    // 0x8001E82C: nop

;}
RECOMP_FUNC void FUN_8001e830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E834: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001E838: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001E83C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E840: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001E844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E848: sh          $t6, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r14;
    // 0x8001E84C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E850: sb          $zero, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = 0;
    // 0x8001E854: jal         0x80005700
    // 0x8001E858: sb          $zero, 0x164($v0)
    MEM_B(0X164, ctx->r2) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x8001E858: sb          $zero, 0x164($v0)
    MEM_B(0X164, ctx->r2) = 0;
    after_0:
    // 0x8001E85C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8001E860: sw          $zero, -0x42B0($at)
    MEM_W(-0X42B0, ctx->r1) = 0;
    // 0x8001E864: jal         0x801170DC
    // 0x8001E868: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_1;
    // 0x8001E868: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x8001E86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E874: jr          $ra
    // 0x8001E878: nop

    return;
    // 0x8001E878: nop

;}
RECOMP_FUNC void FUN_8001e87c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E87C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001E880: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001E884: lhu         $t6, 0x158($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X158);
    // 0x8001E888: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E88C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E890: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001E894: sh          $t7, 0x158($v0)
    MEM_H(0X158, ctx->r2) = ctx->r15;
    // 0x8001E898: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8001E89C: lhu         $t8, 0x158($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X158);
    // 0x8001E8A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E8A4: beql        $t8, $zero, L_8001E924
    if (ctx->r24 == 0) {
        // 0x8001E8A8: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_8001E924;
    }
    goto skip_0;
    // 0x8001E8A8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8001E8AC: jal         0x80006214
    // 0x8001E8B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8001E8B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001E8B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E8B8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001E8BC: addiu       $t9, $zero, 0x1002
    ctx->r25 = ADD32(0, 0X1002);
    // 0x8001E8C0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8001E8C4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001E8C8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8001E8CC: sh          $t9, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r25;
    // 0x8001E8D0: lhu         $t2, 0x158($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X158);
    // 0x8001E8D4: lhu         $t4, 0x154($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X154);
    // 0x8001E8D8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8001E8DC: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8001E8E0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8001E8E4: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x8001E8E8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8001E8EC: mflo        $t5
    ctx->r13 = lo;
    // 0x8001E8F0: bne         $t4, $zero, L_8001E8FC
    if (ctx->r12 != 0) {
        // 0x8001E8F4: nop
    
            goto L_8001E8FC;
    }
    // 0x8001E8F4: nop

    // 0x8001E8F8: break       7
    do_break(2147608824);
L_8001E8FC:
    // 0x8001E8FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E900: bne         $t4, $at, L_8001E914
    if (ctx->r12 != ctx->r1) {
        // 0x8001E904: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E914;
    }
    // 0x8001E904: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E908: bne         $t3, $at, L_8001E914
    if (ctx->r11 != ctx->r1) {
        // 0x8001E90C: nop
    
            goto L_8001E914;
    }
    // 0x8001E90C: nop

    // 0x8001E910: break       6
    do_break(2147608848);
L_8001E914:
    // 0x8001E914: sb          $t5, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r13;
    // 0x8001E918: b           L_8001E96C
    // 0x8001E91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E96C;
    // 0x8001E91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E920: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_8001E924:
    // 0x8001E924: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x8001E928: lbu         $t0, 0x15D($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X15D);
    // 0x8001E92C: sb          $zero, 0x164($v0)
    MEM_B(0X164, ctx->r2) = 0;
    // 0x8001E930: andi        $t9, $t0, 0xF
    ctx->r25 = ctx->r8 & 0XF;
    // 0x8001E934: jal         0x80005700
    // 0x8001E938: sb          $t9, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x8001E938: sb          $t9, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = ctx->r25;
    after_1:
    // 0x8001E93C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001E940: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001E944: lbu         $t1, 0x15E($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X15E);
    // 0x8001E948: sw          $zero, 0x160($v0)
    MEM_W(0X160, ctx->r2) = 0;
    // 0x8001E94C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001E950: beq         $t1, $zero, L_8001E960
    if (ctx->r9 == 0) {
        // 0x8001E954: nop
    
            goto L_8001E960;
    }
    // 0x8001E954: nop

    // 0x8001E958: b           L_8001E960
    // 0x8001E95C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
        goto L_8001E960;
    // 0x8001E95C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_8001E960:
    // 0x8001E960: jal         0x801170DC
    // 0x8001E964: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_2;
    // 0x8001E964: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x8001E968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E96C:
    // 0x8001E96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E970: jr          $ra
    // 0x8001E974: nop

    return;
    // 0x8001E974: nop

;}
RECOMP_FUNC void FUN_8001e978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E978: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8001E97C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8001E980: lbu         $t6, 0x15D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X15D);
    // 0x8001E984: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001E988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E98C: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8001E990: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001E994: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001E998: beq         $t7, $zero, L_8001E9DC
    if (ctx->r15 == 0) {
        // 0x8001E99C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8001E9DC;
    }
    // 0x8001E99C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001E9A0: lw          $t8, 0x160($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X160);
    // 0x8001E9A4: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8001E9A8: addiu       $t0, $t0, 0x4918
    ctx->r8 = ADD32(ctx->r8, 0X4918);
    // 0x8001E9AC: beq         $t8, $zero, L_8001E9DC
    if (ctx->r24 == 0) {
        // 0x8001E9B0: nop
    
            goto L_8001E9DC;
    }
    // 0x8001E9B0: nop

    // 0x8001E9B4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8001E9B8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8001E9BC: addiu       $t9, $sp, 0x18
    ctx->r25 = ADD32(ctx->r29, 0X18);
    // 0x8001E9C0: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8001E9C4: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8001E9C8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8001E9CC: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8001E9D0: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
    // 0x8001E9D4: b           L_8001EA38
    // 0x8001E9D8: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
        goto L_8001EA38;
    // 0x8001E9D8: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
L_8001E9DC:
    // 0x8001E9DC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8001E9E0: jal         0x80005670
    // 0x8001E9E4: addiu       $a1, $a1, 0x48E0
    ctx->r5 = ADD32(ctx->r5, 0X48E0);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x8001E9E4: addiu       $a1, $a1, 0x48E0
    ctx->r5 = ADD32(ctx->r5, 0X48E0);
    after_0:
    // 0x8001E9E8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8001E9EC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8001E9F0: beq         $v0, $zero, L_8001EA38
    if (ctx->r2 == 0) {
        // 0x8001E9F4: sw          $v0, 0x160($v1)
        MEM_W(0X160, ctx->r3) = ctx->r2;
            goto L_8001EA38;
    }
    // 0x8001E9F4: sw          $v0, 0x160($v1)
    MEM_W(0X160, ctx->r3) = ctx->r2;
    // 0x8001E9F8: lhu         $t4, 0x3A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3A);
    // 0x8001E9FC: lhu         $t5, 0x3E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X3E);
    // 0x8001EA00: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001EA04: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x8001EA08: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x8001EA0C: lbu         $t9, 0x43($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X43);
    // 0x8001EA10: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x8001EA14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001EA18: sb          $t1, 0x164($v1)
    MEM_B(0X164, ctx->r3) = ctx->r9;
    // 0x8001EA1C: sh          $t4, 0x154($v1)
    MEM_H(0X154, ctx->r3) = ctx->r12;
    // 0x8001EA20: sh          $t5, 0x156($v1)
    MEM_H(0X156, ctx->r3) = ctx->r13;
    // 0x8001EA24: sb          $t6, 0x15A($v1)
    MEM_B(0X15A, ctx->r3) = ctx->r14;
    // 0x8001EA28: sb          $t7, 0x15B($v1)
    MEM_B(0X15B, ctx->r3) = ctx->r15;
    // 0x8001EA2C: sb          $t8, 0x15C($v1)
    MEM_B(0X15C, ctx->r3) = ctx->r24;
    // 0x8001EA30: sb          $t9, 0x15D($v1)
    MEM_B(0X15D, ctx->r3) = ctx->r25;
    // 0x8001EA34: sb          $t0, 0x15E($v1)
    MEM_B(0X15E, ctx->r3) = ctx->r8;
L_8001EA38:
    // 0x8001EA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EA3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001EA40: jr          $ra
    // 0x8001EA44: nop

    return;
    // 0x8001EA44: nop

    // 0x8001EA48: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001EA4C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001EA50: lbu         $t6, 0x15D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X15D);
    // 0x8001EA54: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001EA58: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001EA5C: andi        $t7, $t6, 0x70
    ctx->r15 = ctx->r14 & 0X70;
    // 0x8001EA60: bne         $t7, $at, L_8001EA6C
    if (ctx->r15 != ctx->r1) {
        // 0x8001EA64: nop
    
            goto L_8001EA6C;
    }
    // 0x8001EA64: nop

    // 0x8001EA68: sh          $t8, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r24;
L_8001EA6C:
    // 0x8001EA6C: jr          $ra
    // 0x8001EA70: nop

    return;
    // 0x8001EA70: nop

;}
RECOMP_FUNC void FUN_8001ea74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EA74: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001EA78: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001EA7C: lbu         $t6, 0x15D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X15D);
    // 0x8001EA80: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001EA84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001EA88: andi        $t7, $t6, 0x70
    ctx->r15 = ctx->r14 & 0X70;
    // 0x8001EA8C: bne         $t7, $at, L_8001EA9C
    if (ctx->r15 != ctx->r1) {
        // 0x8001EA90: nop
    
            goto L_8001EA9C;
    }
    // 0x8001EA90: nop

    // 0x8001EA94: sh          $v1, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r3;
    // 0x8001EA98: sh          $v1, 0x154($v0)
    MEM_H(0X154, ctx->r2) = ctx->r3;
L_8001EA9C:
    // 0x8001EA9C: jr          $ra
    // 0x8001EAA0: nop

    return;
    // 0x8001EAA0: nop

;}
RECOMP_FUNC void FUN_8001eaa4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EAA4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8001EAA8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8001EAAC: sw          $zero, 0x160($v0)
    MEM_W(0X160, ctx->r2) = 0;
    // 0x8001EAB0: sb          $zero, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = 0;
    // 0x8001EAB4: sh          $zero, 0x156($v0)
    MEM_H(0X156, ctx->r2) = 0;
    // 0x8001EAB8: sh          $zero, 0x154($v0)
    MEM_H(0X154, ctx->r2) = 0;
    // 0x8001EABC: jr          $ra
    // 0x8001EAC0: sh          $zero, 0x158($v0)
    MEM_H(0X158, ctx->r2) = 0;
    return;
    // 0x8001EAC0: sh          $zero, 0x158($v0)
    MEM_H(0X158, ctx->r2) = 0;
    // 0x8001EAC4: nop

    // 0x8001EAC8: nop

    // 0x8001EACC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001ead0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001ead0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EAD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001EAD4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001EAD8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001EADC: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8001EAE0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001EAE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001EAE8: slti        $at, $a0, 0x800
    ctx->r1 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x8001EAEC: beq         $at, $zero, L_8001EB04
    if (ctx->r1 == 0) {
        // 0x8001EAF0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8001EB04;
    }
    // 0x8001EAF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001EAF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EAF8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001EAFC: jr          $ra
    // 0x8001EB00: lwc1        $f0, 0x4930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4930);
    return;
    // 0x8001EB00: lwc1        $f0, 0x4930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4930);
L_8001EB04:
    // 0x8001EB04: slti        $at, $a0, 0x1000
    ctx->r1 = SIGNED(ctx->r4) < 0X1000 ? 1 : 0;
    // 0x8001EB08: beq         $at, $zero, L_8001EB24
    if (ctx->r1 == 0) {
        // 0x8001EB0C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8001EB24;
    }
    // 0x8001EB0C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001EB10: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8001EB14: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001EB18: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001EB1C: jr          $ra
    // 0x8001EB20: lwc1        $f0, -0x76D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76D0);
    return;
    // 0x8001EB20: lwc1        $f0, -0x76D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76D0);
L_8001EB24:
    // 0x8001EB24: slti        $at, $a0, 0x1800
    ctx->r1 = SIGNED(ctx->r4) < 0X1800 ? 1 : 0;
    // 0x8001EB28: beq         $at, $zero, L_8001EB48
    if (ctx->r1 == 0) {
        // 0x8001EB2C: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_8001EB48;
    }
    // 0x8001EB2C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8001EB30: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001EB34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EB38: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8001EB3C: lwc1        $f0, 0x930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X930);
    // 0x8001EB40: jr          $ra
    // 0x8001EB44: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8001EB44: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8001EB48:
    // 0x8001EB48: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8001EB4C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001EB50: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8001EB54: lwc1        $f0, -0x36D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X36D0);
    // 0x8001EB58: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001EB5C: jr          $ra
    // 0x8001EB60: nop

    return;
    // 0x8001EB60: nop

;}
RECOMP_FUNC void FUN_8001eb64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB64: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001EB68: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001EB6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001EB70: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8001EB74: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001EB78: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001EB7C: slti        $at, $a0, 0x800
    ctx->r1 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x8001EB80: beq         $at, $zero, L_8001EB9C
    if (ctx->r1 == 0) {
        // 0x8001EB84: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8001EB9C;
    }
    // 0x8001EB84: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001EB88: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8001EB8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EB90: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001EB94: jr          $ra
    // 0x8001EB98: lwc1        $f0, 0x6930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6930);
    return;
    // 0x8001EB98: lwc1        $f0, 0x6930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6930);
L_8001EB9C:
    // 0x8001EB9C: slti        $at, $a0, 0x1000
    ctx->r1 = SIGNED(ctx->r4) < 0X1000 ? 1 : 0;
    // 0x8001EBA0: beq         $at, $zero, L_8001EBBC
    if (ctx->r1 == 0) {
        // 0x8001EBA4: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8001EBBC;
    }
    // 0x8001EBA4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001EBA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EBAC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001EBB0: lwc1        $f0, 0x2930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2930);
    // 0x8001EBB4: jr          $ra
    // 0x8001EBB8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8001EBB8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8001EBBC:
    // 0x8001EBBC: slti        $at, $a0, 0x1800
    ctx->r1 = SIGNED(ctx->r4) < 0X1800 ? 1 : 0;
    // 0x8001EBC0: beq         $at, $zero, L_8001EBE4
    if (ctx->r1 == 0) {
        // 0x8001EBC4: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8001EBE4;
    }
    // 0x8001EBC4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8001EBC8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001EBCC: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8001EBD0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001EBD4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8001EBD8: lwc1        $f0, -0x56D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X56D0);
    // 0x8001EBDC: jr          $ra
    // 0x8001EBE0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8001EBE0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8001EBE4:
    // 0x8001EBE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EBE8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8001EBEC: lwc1        $f0, -0x16D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X16D0);
    // 0x8001EBF0: jr          $ra
    // 0x8001EBF4: nop

    return;
    // 0x8001EBF4: nop

;}
RECOMP_FUNC void FUN_8001ebf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EBF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001EBFC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8001EC00: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001EC04: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001EC08: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8001EC0C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001EC10: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8001EC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EC18: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001EC1C: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8001EC20: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
    // 0x8001EC24: nop

    // 0x8001EC28: bc1fl       L_8001EC40
    if (!c1cs) {
        // 0x8001EC2C: sub.d       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
            goto L_8001EC40;
    }
    goto skip_0;
    // 0x8001EC2C: sub.d       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
    skip_0:
    // 0x8001EC30: sub.d       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
    // 0x8001EC34: b           L_8001EC44
    // 0x8001EC38: neg.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = -ctx->f0.d;
        goto L_8001EC44;
    // 0x8001EC38: neg.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = -ctx->f0.d;
    // 0x8001EC3C: sub.d       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
L_8001EC40:
    // 0x8001EC40: mov.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.d = ctx->f0.d;
L_8001EC44:
    // 0x8001EC44: ldc1        $f2, -0x2FE0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2FE0);
    // 0x8001EC48: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x8001EC4C: nop

    // 0x8001EC50: bc1tl       L_8001EC74
    if (c1cs) {
        // 0x8001EC54: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8001EC74;
    }
    goto skip_1;
    // 0x8001EC54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_1:
    // 0x8001EC58: jal         0x8002FC20
    // 0x8001EC5C: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8001EC5C: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_0:
    // 0x8001EC60: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001EC64: ldc1        $f2, -0x2FD8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2FD8);
    // 0x8001EC68: b           L_8001EC78
    // 0x8001EC6C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8001EC78;
    // 0x8001EC6C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8001EC70: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8001EC74:
    // 0x8001EC74: nop

L_8001EC78:
    // 0x8001EC78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001EC7C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001EC80: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001EC84: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x8001EC88: nop

    // 0x8001EC8C: bc1fl       L_8001ECA0
    if (!c1cs) {
        // 0x8001EC90: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_8001ECA0;
    }
    goto skip_2;
    // 0x8001EC90: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_2:
    // 0x8001EC94: b           L_8001ECA0
    // 0x8001EC98: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
        goto L_8001ECA0;
    // 0x8001EC98: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x8001EC9C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_8001ECA0:
    // 0x8001ECA0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8001ECA4: c.lt.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d < ctx->f2.d;
    // 0x8001ECA8: nop

    // 0x8001ECAC: bc1tl       L_8001ED30
    if (c1cs) {
        // 0x8001ECB0: mtc1        $zero, $f17
        ctx->f_odd[(17 - 1) * 2] = 0;
            goto L_8001ED30;
    }
    goto skip_3;
    // 0x8001ECB0: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    skip_3:
    // 0x8001ECB4: jal         0x8001EF38
    // 0x8001ECB8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8001ECB8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8001ECBC: andi        $t6, $v0, 0x1000
    ctx->r14 = ctx->r2 & 0X1000;
    // 0x8001ECC0: beq         $t6, $zero, L_8001ECE4
    if (ctx->r14 == 0) {
        // 0x8001ECC4: lwc1        $f14, 0x1C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8001ECE4;
    }
    // 0x8001ECC4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001ECC8: jal         0x8001EF38
    // 0x8001ECCC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8001ECCC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8001ECD0: andi        $v1, $v0, 0x1FFF
    ctx->r3 = ctx->r2 & 0X1FFF;
    // 0x8001ECD4: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x8001ECD8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001ECDC: b           L_8001ECF8
    // 0x8001ECE0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8001ECF8;
    // 0x8001ECE0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8001ECE4:
    // 0x8001ECE4: jal         0x8001EF38
    // 0x8001ECE8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x8001ECE8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8001ECEC: andi        $v1, $v0, 0x1FFF
    ctx->r3 = ctx->r2 & 0X1FFF;
    // 0x8001ECF0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001ECF4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8001ECF8:
    // 0x8001ECF8: slti        $at, $v1, -0x800
    ctx->r1 = SIGNED(ctx->r3) < -0X800 ? 1 : 0;
    // 0x8001ECFC: bne         $at, $zero, L_8001ED0C
    if (ctx->r1 != 0) {
        // 0x8001ED00: slti        $at, $v1, -0x3FF
        ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
            goto L_8001ED0C;
    }
    // 0x8001ED00: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x8001ED04: bnel        $at, $zero, L_8001ED20
    if (ctx->r1 != 0) {
        // 0x8001ED08: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001ED20;
    }
    goto skip_4;
    // 0x8001ED08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
L_8001ED0C:
    // 0x8001ED0C: blez        $v1, L_8001ED54
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001ED10: slti        $at, $v1, 0x400
        ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
            goto L_8001ED54;
    }
    // 0x8001ED10: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x8001ED14: beql        $at, $zero, L_8001ED58
    if (ctx->r1 == 0) {
        // 0x8001ED18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001ED58;
    }
    goto skip_5;
    // 0x8001ED18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8001ED1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001ED20:
    // 0x8001ED20: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001ED24: b           L_8001ED54
    // 0x8001ED28: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8001ED54;
    // 0x8001ED28: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001ED2C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
L_8001ED30:
    // 0x8001ED30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001ED34: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8001ED38: addiu       $v1, $zero, -0x800
    ctx->r3 = ADD32(0, -0X800);
    // 0x8001ED3C: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x8001ED40: nop

    // 0x8001ED44: bc1f        L_8001ED54
    if (!c1cs) {
        // 0x8001ED48: nop
    
            goto L_8001ED54;
    }
    // 0x8001ED48: nop

    // 0x8001ED4C: b           L_8001ED54
    // 0x8001ED50: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
        goto L_8001ED54;
    // 0x8001ED50: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
L_8001ED54:
    // 0x8001ED54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001ED58:
    // 0x8001ED58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001ED5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001ED60: jr          $ra
    // 0x8001ED64: nop

    return;
    // 0x8001ED64: nop

;}
RECOMP_FUNC void FUN_8001ed68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ED68: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001ED6C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001ED70: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8001ED74: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8001ED78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001ED7C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001ED80: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8001ED84: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8001ED88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001ED8C: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
    // 0x8001ED90: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001ED94: bc1fl       L_8001EDAC
    if (!c1cs) {
        // 0x8001ED98: sub.d       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
            goto L_8001EDAC;
    }
    goto skip_0;
    // 0x8001ED98: sub.d       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
    skip_0:
    // 0x8001ED9C: sub.d       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
    // 0x8001EDA0: b           L_8001EDB0
    // 0x8001EDA4: neg.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = -ctx->f0.d;
        goto L_8001EDB0;
    // 0x8001EDA4: neg.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = -ctx->f0.d;
    // 0x8001EDA8: sub.d       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f14.d - ctx->f2.d;
L_8001EDAC:
    // 0x8001EDAC: mov.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.d = ctx->f0.d;
L_8001EDB0:
    // 0x8001EDB0: ldc1        $f2, -0x2FD0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2FD0);
    // 0x8001EDB4: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x8001EDB8: nop

    // 0x8001EDBC: bc1tl       L_8001EDE4
    if (c1cs) {
        // 0x8001EDC0: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8001EDE4;
    }
    goto skip_1;
    // 0x8001EDC0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_1:
    // 0x8001EDC4: jal         0x8002FC20
    // 0x8001EDC8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8001EDC8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_0:
    // 0x8001EDCC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001EDD0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8001EDD4: ldc1        $f2, -0x2FC8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2FC8);
    // 0x8001EDD8: b           L_8001EDEC
    // 0x8001EDDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8001EDEC;
    // 0x8001EDDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8001EDE0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8001EDE4:
    // 0x8001EDE4: nop

    // 0x8001EDE8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8001EDEC:
    // 0x8001EDEC: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
    // 0x8001EDF0: nop

    // 0x8001EDF4: bc1fl       L_8001EE08
    if (!c1cs) {
        // 0x8001EDF8: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_8001EE08;
    }
    goto skip_2;
    // 0x8001EDF8: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_2:
    // 0x8001EDFC: b           L_8001EE08
    // 0x8001EE00: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
        goto L_8001EE08;
    // 0x8001EE00: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x8001EE04: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8001EE08:
    // 0x8001EE08: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EE0C: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x8001EE10: nop

    // 0x8001EE14: bc1tl       L_8001EE9C
    if (c1cs) {
        // 0x8001EE18: c.lt.s      $f20, $f14
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
            goto L_8001EE9C;
    }
    goto skip_3;
    // 0x8001EE18: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
    skip_3:
    // 0x8001EE1C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8001EE20: nop

    // 0x8001EE24: bc1fl       L_8001EE38
    if (!c1cs) {
        // 0x8001EE28: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001EE38;
    }
    goto skip_4;
    // 0x8001EE28: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_4:
    // 0x8001EE2C: b           L_8001EE38
    // 0x8001EE30: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8001EE38;
    // 0x8001EE30: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8001EE34: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001EE38:
    // 0x8001EE38: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EE3C: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x8001EE40: nop

    // 0x8001EE44: bc1tl       L_8001EE9C
    if (c1cs) {
        // 0x8001EE48: c.lt.s      $f20, $f14
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
            goto L_8001EE9C;
    }
    goto skip_5;
    // 0x8001EE48: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
    skip_5:
    // 0x8001EE4C: jal         0x8001EF38
    // 0x8001EE50: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8001EE50: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x8001EE54: andi        $v1, $v0, 0x1FFF
    ctx->r3 = ctx->r2 & 0X1FFF;
    // 0x8001EE58: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x8001EE5C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x8001EE60: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001EE64: blez        $a0, L_8001EE74
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001EE68: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_8001EE74;
    }
    // 0x8001EE68: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001EE6C: slti        $at, $a0, 0x400
    ctx->r1 = SIGNED(ctx->r4) < 0X400 ? 1 : 0;
    // 0x8001EE70: bne         $at, $zero, L_8001EE88
    if (ctx->r1 != 0) {
        // 0x8001EE74: slti        $at, $a0, 0x801
        ctx->r1 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
            goto L_8001EE88;
    }
L_8001EE74:
    // 0x8001EE74: slti        $at, $a0, 0x801
    ctx->r1 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
    // 0x8001EE78: bne         $at, $zero, L_8001EF24
    if (ctx->r1 != 0) {
        // 0x8001EE7C: slti        $at, $a0, 0xC00
        ctx->r1 = SIGNED(ctx->r4) < 0XC00 ? 1 : 0;
            goto L_8001EF24;
    }
    // 0x8001EE7C: slti        $at, $a0, 0xC00
    ctx->r1 = SIGNED(ctx->r4) < 0XC00 ? 1 : 0;
    // 0x8001EE80: beql        $at, $zero, L_8001EF28
    if (ctx->r1 == 0) {
        // 0x8001EE84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001EF28;
    }
    goto skip_6;
    // 0x8001EE84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
L_8001EE88:
    // 0x8001EE88: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x8001EE8C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001EE90: b           L_8001EF24
    // 0x8001EE94: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_8001EF24;
    // 0x8001EE94: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001EE98: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
L_8001EE9C:
    // 0x8001EE9C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8001EEA0: bc1fl       L_8001EEB4
    if (!c1cs) {
        // 0x8001EEA4: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_8001EEB4;
    }
    goto skip_7;
    // 0x8001EEA4: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_7:
    // 0x8001EEA8: b           L_8001EEB4
    // 0x8001EEAC: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
        goto L_8001EEB4;
    // 0x8001EEAC: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x8001EEB0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8001EEB4:
    // 0x8001EEB4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EEB8: c.lt.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d < ctx->f2.d;
    // 0x8001EEBC: nop

    // 0x8001EEC0: bc1fl       L_8001EED0
    if (!c1cs) {
        // 0x8001EEC4: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_8001EED0;
    }
    goto skip_8;
    // 0x8001EEC4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_8:
    // 0x8001EEC8: sh          $a1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r5;
    // 0x8001EECC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_8001EED0:
    // 0x8001EED0: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x8001EED4: bc1fl       L_8001EEE8
    if (!c1cs) {
        // 0x8001EED8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001EEE8;
    }
    goto skip_9;
    // 0x8001EED8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_9:
    // 0x8001EEDC: b           L_8001EEE8
    // 0x8001EEE0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8001EEE8;
    // 0x8001EEE0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8001EEE4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001EEE8:
    // 0x8001EEE8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EEEC: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x8001EEF0: nop

    // 0x8001EEF4: bc1fl       L_8001EF28
    if (!c1cs) {
        // 0x8001EEF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001EF28;
    }
    goto skip_10;
    // 0x8001EEF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x8001EEFC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8001EF00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001EF04: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x8001EF08: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8001EF0C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8001EF10: nop

    // 0x8001EF14: bc1f        L_8001EF24
    if (!c1cs) {
        // 0x8001EF18: nop
    
            goto L_8001EF24;
    }
    // 0x8001EF18: nop

    // 0x8001EF1C: b           L_8001EF24
    // 0x8001EF20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8001EF24;
    // 0x8001EF20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001EF24:
    // 0x8001EF24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EF28:
    // 0x8001EF28: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001EF2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001EF30: jr          $ra
    // 0x8001EF34: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8001EF34: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001ef38(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001ef38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EF38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001EF3C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001EF40: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8001EF44: nop

    // 0x8001EF48: bc1fl       L_8001EF5C
    if (!c1cs) {
        // 0x8001EF4C: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_8001EF5C;
    }
    goto skip_0;
    // 0x8001EF4C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_0:
    // 0x8001EF50: b           L_8001EF5C
    // 0x8001EF54: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
        goto L_8001EF5C;
    // 0x8001EF54: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x8001EF58: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_8001EF5C:
    // 0x8001EF5C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8001EF60: nop

    // 0x8001EF64: bc1fl       L_8001EF78
    if (!c1cs) {
        // 0x8001EF68: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8001EF78;
    }
    goto skip_1;
    // 0x8001EF68: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_1:
    // 0x8001EF6C: b           L_8001EF78
    // 0x8001EF70: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_8001EF78;
    // 0x8001EF70: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x8001EF74: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8001EF78:
    // 0x8001EF78: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001EF7C: nop

    // 0x8001EF80: bc1fl       L_8001F00C
    if (!c1cs) {
        // 0x8001EF84: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8001F00C;
    }
    goto skip_2;
    // 0x8001EF84: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x8001EF88: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x8001EF8C: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x8001EF90: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001EF94: bc1fl       L_8001EFA8
    if (!c1cs) {
        // 0x8001EF98: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8001EFA8;
    }
    goto skip_3;
    // 0x8001EF98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x8001EF9C: b           L_8001F154
    // 0x8001EFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F154;
    // 0x8001EFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EFA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8001EFA8:
    // 0x8001EFA8: nop

    // 0x8001EFAC: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001EFB0: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001EFB4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001EFB8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8001EFBC: nop

    // 0x8001EFC0: sltiu       $at, $v0, 0x801
    ctx->r1 = ctx->r2 < 0X801 ? 1 : 0;
    // 0x8001EFC4: bnel        $at, $zero, L_8001EFD4
    if (ctx->r1 != 0) {
        // 0x8001EFC8: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_8001EFD4;
    }
    goto skip_4;
    // 0x8001EFC8: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    skip_4:
    // 0x8001EFCC: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x8001EFD0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
L_8001EFD4:
    // 0x8001EFD4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8001EFD8: beq         $v0, $zero, L_8001F000
    if (ctx->r2 == 0) {
        // 0x8001EFDC: lh          $v1, 0x6934($v1)
        ctx->r3 = MEM_H(ctx->r3, 0X6934);
            goto L_8001F000;
    }
    // 0x8001EFDC: lh          $v1, 0x6934($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6934);
    // 0x8001EFE0: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8001EFE4: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8001EFE8: nop

    // 0x8001EFEC: bc1f        L_8001F000
    if (!c1cs) {
        // 0x8001EFF0: nop
    
            goto L_8001F000;
    }
    // 0x8001EFF0: nop

    // 0x8001EFF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001EFF8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001EFFC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8001F000:
    // 0x8001F000: b           L_8001F0BC
    // 0x8001F004: sh          $v1, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r3;
        goto L_8001F0BC;
    // 0x8001F004: sh          $v1, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r3;
    // 0x8001F008: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8001F00C:
    // 0x8001F00C: nop

    // 0x8001F010: bc1fl       L_8001F0AC
    if (!c1cs) {
        // 0x8001F014: c.eq.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
            goto L_8001F0AC;
    }
    goto skip_5;
    // 0x8001F014: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    skip_5:
    // 0x8001F018: c.eq.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl == ctx->f16.fl;
    // 0x8001F01C: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x8001F020: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8001F024: bc1fl       L_8001F038
    if (!c1cs) {
        // 0x8001F028: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8001F038;
    }
    goto skip_6;
    // 0x8001F028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_6:
    // 0x8001F02C: b           L_8001F154
    // 0x8001F030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F154;
    // 0x8001F030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8001F038:
    // 0x8001F038: nop

    // 0x8001F03C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001F040: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001F044: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001F048: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8001F04C: nop

    // 0x8001F050: sltiu       $at, $v0, 0x801
    ctx->r1 = ctx->r2 < 0X801 ? 1 : 0;
    // 0x8001F054: bnel        $at, $zero, L_8001F064
    if (ctx->r1 != 0) {
        // 0x8001F058: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_8001F064;
    }
    goto skip_7;
    // 0x8001F058: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    skip_7:
    // 0x8001F05C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x8001F060: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
L_8001F064:
    // 0x8001F064: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8001F068: lh          $t0, 0x6934($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6934);
    // 0x8001F06C: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8001F070: subu        $v1, $t1, $t0
    ctx->r3 = SUB32(ctx->r9, ctx->r8);
    // 0x8001F074: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001F078: beq         $v0, $zero, L_8001F0A0
    if (ctx->r2 == 0) {
        // 0x8001F07C: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8001F0A0;
    }
    // 0x8001F07C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001F080: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8001F084: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8001F088: nop

    // 0x8001F08C: bc1f        L_8001F0A0
    if (!c1cs) {
        // 0x8001F090: nop
    
            goto L_8001F0A0;
    }
    // 0x8001F090: nop

    // 0x8001F094: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001F098: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001F09C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8001F0A0:
    // 0x8001F0A0: b           L_8001F0BC
    // 0x8001F0A4: sh          $v1, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r3;
        goto L_8001F0BC;
    // 0x8001F0A4: sh          $v1, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r3;
    // 0x8001F0A8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
L_8001F0AC:
    // 0x8001F0AC: addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
    // 0x8001F0B0: bc1fl       L_8001F0C0
    if (!c1cs) {
        // 0x8001F0B4: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_8001F0C0;
    }
    goto skip_8;
    // 0x8001F0B4: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_8:
    // 0x8001F0B8: sh          $v1, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r3;
L_8001F0BC:
    // 0x8001F0BC: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
L_8001F0C0:
    // 0x8001F0C0: lh          $v1, 0x2($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2);
    // 0x8001F0C4: bc1fl       L_8001F0F0
    if (!c1cs) {
        // 0x8001F0C8: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_8001F0F0;
    }
    goto skip_9;
    // 0x8001F0C8: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_9:
    // 0x8001F0CC: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x8001F0D0: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8001F0D4: bc1fl       L_8001F0F0
    if (!c1cs) {
        // 0x8001F0D8: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_8001F0F0;
    }
    goto skip_10;
    // 0x8001F0D8: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_10:
    // 0x8001F0DC: subu        $v1, $t2, $v1
    ctx->r3 = SUB32(ctx->r10, ctx->r3);
    // 0x8001F0E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001F0E4: b           L_8001F148
    // 0x8001F0E8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8001F148;
    // 0x8001F0E8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001F0EC: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
L_8001F0F0:
    // 0x8001F0F0: nop

    // 0x8001F0F4: bc1fl       L_8001F120
    if (!c1cs) {
        // 0x8001F0F8: c.le.s      $f16, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
            goto L_8001F120;
    }
    goto skip_11;
    // 0x8001F0F8: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    skip_11:
    // 0x8001F0FC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8001F100: nop

    // 0x8001F104: bc1fl       L_8001F120
    if (!c1cs) {
        // 0x8001F108: c.le.s      $f16, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
            goto L_8001F120;
    }
    goto skip_12;
    // 0x8001F108: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    skip_12:
    // 0x8001F10C: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    // 0x8001F110: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001F114: b           L_8001F148
    // 0x8001F118: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8001F148;
    // 0x8001F118: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001F11C: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
L_8001F120:
    // 0x8001F120: nop

    // 0x8001F124: bc1fl       L_8001F14C
    if (!c1cs) {
        // 0x8001F128: andi        $v0, $v1, 0x1FFF
        ctx->r2 = ctx->r3 & 0X1FFF;
            goto L_8001F14C;
    }
    goto skip_13;
    // 0x8001F128: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    skip_13:
    // 0x8001F12C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8001F130: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x8001F134: bc1fl       L_8001F14C
    if (!c1cs) {
        // 0x8001F138: andi        $v0, $v1, 0x1FFF
        ctx->r2 = ctx->r3 & 0X1FFF;
            goto L_8001F14C;
    }
    goto skip_14;
    // 0x8001F138: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    skip_14:
    // 0x8001F13C: subu        $v1, $t3, $v1
    ctx->r3 = SUB32(ctx->r11, ctx->r3);
    // 0x8001F140: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001F144: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8001F148:
    // 0x8001F148: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
L_8001F14C:
    // 0x8001F14C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001F150: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8001F154:
    // 0x8001F154: jr          $ra
    // 0x8001F158: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001F158: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8001F15C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f160(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F160: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x8001F164: blezl       $v0, L_8001F190
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F168: slti        $at, $a1, 0x8
        ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
            goto L_8001F190;
    }
    goto skip_0;
    // 0x8001F168: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    skip_0:
    // 0x8001F16C: blez        $a1, L_8001F18C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8001F170: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001F18C;
    }
    // 0x8001F170: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001F174:
    // 0x8001F174: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001F178: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8001F17C: blez        $v0, L_8001F18C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F180: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001F18C;
    }
    // 0x8001F180: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001F184: bgtzl       $a1, L_8001F174
    if (SIGNED(ctx->r5) > 0) {
        // 0x8001F188: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001F174;
    }
    goto skip_1;
    // 0x8001F188: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_1:
L_8001F18C:
    // 0x8001F18C: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
L_8001F190:
    // 0x8001F190: bne         $at, $zero, L_8001F1B8
    if (ctx->r1 != 0) {
        // 0x8001F194: nop
    
            goto L_8001F1B8;
    }
    // 0x8001F194: nop

L_8001F198:
    // 0x8001F198: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x8001F19C: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x8001F1A0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8001F1A4: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8001F1A8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8001F1AC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001F1B0: beq         $at, $zero, L_8001F198
    if (ctx->r1 == 0) {
        // 0x8001F1B4: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8001F198;
    }
    // 0x8001F1B4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8001F1B8:
    // 0x8001F1B8: blez        $a1, L_8001F1CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8001F1BC: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_8001F1CC;
    }
L_8001F1BC:
    // 0x8001F1BC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001F1C0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8001F1C4: bgtz        $a1, L_8001F1BC
    if (SIGNED(ctx->r5) > 0) {
        // 0x8001F1C8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001F1BC;
    }
    // 0x8001F1C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8001F1CC:
    // 0x8001F1CC: jr          $ra
    // 0x8001F1D0: nop

    return;
    // 0x8001F1D0: nop

    // 0x8001F1D4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001F1D8: beq         $a2, $zero, L_8001F1FC
    if (ctx->r6 == 0) {
        // 0x8001F1DC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001F1FC;
    }
    // 0x8001F1DC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001F1E0:
    // 0x8001F1E0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8001F1E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001F1E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001F1EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001F1F0: sb          $t6, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r14;
    // 0x8001F1F4: bne         $a2, $zero, L_8001F1E0
    if (ctx->r6 != 0) {
        // 0x8001F1F8: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001F1E0;
    }
    // 0x8001F1F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001F1FC:
    // 0x8001F1FC: jr          $ra
    // 0x8001F200: nop

    return;
    // 0x8001F200: nop

;}
RECOMP_FUNC void FUN_8001f204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F20C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001F210: jal         0x8001F160
    // 0x8001F214: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F160)(rdram, ctx);
        goto after_0;
    // 0x8001F214: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001F218: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001F21C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F220: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001F224: addiu       $v0, $v0, 0x1BC0
    ctx->r2 = ADD32(ctx->r2, 0X1BC0);
    // 0x8001F228: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001F22C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001F230: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8001F234: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x8001F238: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x8001F23C: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x8001F240: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001F244: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8001F248: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8001F24C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8001F250: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8001F254: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8001F258: sw          $a1, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->r5;
    // 0x8001F25C: sw          $t6, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->r14;
    // 0x8001F260: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8001F264: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8001F268: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8001F26C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001F270: addiu       $t4, $t3, -0x10
    ctx->r12 = ADD32(ctx->r11, -0X10);
    // 0x8001F274: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8001F278: sw          $a0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r4;
    // 0x8001F27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F280: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8001F284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F288: jr          $ra
    // 0x8001F28C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    return;
    // 0x8001F28C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f290(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F290: bgtz        $a0, L_8001F2A0
    if (SIGNED(ctx->r4) > 0) {
        // 0x8001F294: lui         $a1, 0x8009
        ctx->r5 = S32(0X8009 << 16);
            goto L_8001F2A0;
    }
    // 0x8001F294: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001F298: jr          $ra
    // 0x8001F29C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001F29C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F2A0:
    // 0x8001F2A0: lw          $a1, 0x1BC8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1BC8);
    // 0x8001F2A4: addiu       $v1, $a0, 0x17
    ctx->r3 = ADD32(ctx->r4, 0X17);
    // 0x8001F2A8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8001F2AC: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8001F2B0: beq         $v0, $zero, L_8001F2F8
    if (ctx->r2 == 0) {
        // 0x8001F2B4: nop
    
            goto L_8001F2F8;
    }
    // 0x8001F2B4: nop

    // 0x8001F2B8: lw          $a2, 0x7940($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7940);
    // 0x8001F2BC: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8001F2C0: and         $v1, $v1, $at
    ctx->r3 = ctx->r3 & ctx->r1;
    // 0x8001F2C4: nor         $a3, $a2, $zero
    ctx->r7 = ~(ctx->r6 | 0);
    // 0x8001F2C8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_8001F2CC:
    // 0x8001F2CC: addu        $t6, $a1, $a2
    ctx->r14 = ADD32(ctx->r5, ctx->r6);
    // 0x8001F2D0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x8001F2D4: and         $a0, $t7, $a3
    ctx->r4 = ctx->r15 & ctx->r7;
    // 0x8001F2D8: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // 0x8001F2DC: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F2E0: beql        $at, $zero, L_8001F304
    if (ctx->r1 == 0) {
        // 0x8001F2E4: addu        $a2, $a0, $v1
        ctx->r6 = ADD32(ctx->r4, ctx->r3);
            goto L_8001F304;
    }
    goto skip_0;
    // 0x8001F2E4: addu        $a2, $a0, $v1
    ctx->r6 = ADD32(ctx->r4, ctx->r3);
    skip_0:
    // 0x8001F2E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F2EC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8001F2F0: bnel        $v0, $zero, L_8001F2CC
    if (ctx->r2 != 0) {
        // 0x8001F2F4: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_8001F2CC;
    }
    goto skip_1;
    // 0x8001F2F4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_8001F2F8:
    // 0x8001F2F8: jr          $ra
    // 0x8001F2FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001F2FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F300: addu        $a2, $a0, $v1
    ctx->r6 = ADD32(ctx->r4, ctx->r3);
L_8001F304:
    // 0x8001F304: sw          $a1, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r5;
    // 0x8001F308: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x8001F30C: addiu       $a3, $a2, -0x10
    ctx->r7 = ADD32(ctx->r6, -0X10);
    // 0x8001F310: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001F314: sw          $t0, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r8;
    // 0x8001F318: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x8001F31C: sw          $a3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r7;
    // 0x8001F320: sw          $a3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r7;
    // 0x8001F324: sw          $a0, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->r4;
    // 0x8001F328: sw          $v1, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r3;
    // 0x8001F32C: jr          $ra
    // 0x8001F330: nop

    return;
    // 0x8001F330: nop

;}
RECOMP_FUNC void FUN_8001f334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F334: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F33C: addiu       $t6, $zero, 0xFFF
    ctx->r14 = ADD32(0, 0XFFF);
    // 0x8001F340: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F344: jal         0x8001F290
    // 0x8001F348: sw          $t6, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_0;
    // 0x8001F348: sw          $t6, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->r14;
    after_0:
    // 0x8001F34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F350: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8001F354: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F358: sw          $t7, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->r15;
    // 0x8001F35C: jr          $ra
    // 0x8001F360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001F360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f364(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F364: bgtz        $a0, L_8001F374
    if (SIGNED(ctx->r4) > 0) {
        // 0x8001F368: lui         $a1, 0x8009
        ctx->r5 = S32(0X8009 << 16);
            goto L_8001F374;
    }
    // 0x8001F368: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001F36C: jr          $ra
    // 0x8001F370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001F370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F374:
    // 0x8001F374: lw          $a1, 0x1BCC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1BCC);
    // 0x8001F378: addiu       $v1, $a0, 0x17
    ctx->r3 = ADD32(ctx->r4, 0X17);
    // 0x8001F37C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001F380: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x8001F384: beq         $a2, $zero, L_8001F3C8
    if (ctx->r6 == 0) {
        // 0x8001F388: nop
    
            goto L_8001F3C8;
    }
    // 0x8001F388: nop

    // 0x8001F38C: lw          $v0, 0x7940($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7940);
    // 0x8001F390: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8001F394: and         $v1, $v1, $at
    ctx->r3 = ctx->r3 & ctx->r1;
    // 0x8001F398: nor         $v0, $v0, $zero
    ctx->r2 = ~(ctx->r2 | 0);
    // 0x8001F39C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
L_8001F3A0:
    // 0x8001F3A0: addiu       $t8, $a2, 0x10
    ctx->r24 = ADD32(ctx->r6, 0X10);
    // 0x8001F3A4: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x8001F3A8: and         $a0, $t7, $v0
    ctx->r4 = ctx->r15 & ctx->r2;
    // 0x8001F3AC: sltu        $at, $a0, $t8
    ctx->r1 = ctx->r4 < ctx->r24 ? 1 : 0;
    // 0x8001F3B0: beql        $at, $zero, L_8001F3D4
    if (ctx->r1 == 0) {
        // 0x8001F3B4: addu        $a3, $a0, $v1
        ctx->r7 = ADD32(ctx->r4, ctx->r3);
            goto L_8001F3D4;
    }
    goto skip_0;
    // 0x8001F3B4: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
    skip_0:
    // 0x8001F3B8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8001F3BC: lw          $a2, 0x8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X8);
    // 0x8001F3C0: bnel        $a2, $zero, L_8001F3A0
    if (ctx->r6 != 0) {
        // 0x8001F3C4: lw          $t6, 0x0($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X0);
            goto L_8001F3A0;
    }
    goto skip_1;
    // 0x8001F3C4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    skip_1:
L_8001F3C8:
    // 0x8001F3C8: jr          $ra
    // 0x8001F3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001F3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F3D0: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
L_8001F3D4:
    // 0x8001F3D4: sw          $a2, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->r6;
    // 0x8001F3D8: sw          $a1, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r5;
    // 0x8001F3DC: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x8001F3E0: addiu       $t0, $a3, -0x10
    ctx->r8 = ADD32(ctx->r7, -0X10);
    // 0x8001F3E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001F3E8: sw          $t0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r8;
    // 0x8001F3EC: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x8001F3F0: sw          $a0, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->r4;
    // 0x8001F3F4: sw          $v1, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->r3;
    // 0x8001F3F8: jr          $ra
    // 0x8001F3FC: nop

    return;
    // 0x8001F3FC: nop

;}
RECOMP_FUNC void FUN_8001f400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F408: addiu       $t6, $zero, 0xFFF
    ctx->r14 = ADD32(0, 0XFFF);
    // 0x8001F40C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F410: jal         0x8001F364
    // 0x8001F414: sw          $t6, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x8001F364)(rdram, ctx);
        goto after_0;
    // 0x8001F414: sw          $t6, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->r14;
    after_0:
    // 0x8001F418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F41C: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8001F420: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F424: sw          $t7, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->r15;
    // 0x8001F428: jr          $ra
    // 0x8001F42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001F42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f430(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001F434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F438: jal         0x8001F290
    // 0x8001F43C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_0;
    // 0x8001F43C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001F440: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001F444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F448: jal         0x8001F160
    // 0x8001F44C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001F160)(rdram, ctx);
        goto after_1;
    // 0x8001F44C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8001F450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F454: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F45C: jr          $ra
    // 0x8001F460: nop

    return;
    // 0x8001F460: nop

;}
RECOMP_FUNC void FUN_8001f464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001F468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F46C: jal         0x8001F364
    // 0x8001F470: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F364)(rdram, ctx);
        goto after_0;
    // 0x8001F470: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001F474: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001F478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F47C: jal         0x8001F160
    // 0x8001F480: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001F160)(rdram, ctx);
        goto after_1;
    // 0x8001F480: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8001F484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F488: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F48C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F490: jr          $ra
    // 0x8001F494: nop

    return;
    // 0x8001F494: nop

;}
RECOMP_FUNC void FUN_8001f498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F498: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001F49C: addiu       $a1, $a1, 0x1BC0
    ctx->r5 = ADD32(ctx->r5, 0X1BC0);
    // 0x8001F4A0: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8001F4A4: lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
    // 0x8001F4A8: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8001F4AC: and         $t6, $v0, $a2
    ctx->r14 = ctx->r2 & ctx->r6;
    // 0x8001F4B0: bne         $v1, $t6, L_8001F538
    if (ctx->r3 != ctx->r14) {
        // 0x8001F4B4: nop
    
            goto L_8001F538;
    }
    // 0x8001F4B4: nop

    // 0x8001F4B8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8001F4BC: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x8001F4C0: beq         $v1, $t8, L_8001F4FC
    if (ctx->r3 == ctx->r24) {
        // 0x8001F4C4: nop
    
            goto L_8001F4FC;
    }
    // 0x8001F4C4: nop

    // 0x8001F4C8: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8001F4CC: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8001F4D0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8001F4D4: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x8001F4D8: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x8001F4DC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8001F4E0: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8001F4E4: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8001F4E8: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8001F4EC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001F4F0: addiu       $t5, $t4, -0x10
    ctx->r13 = ADD32(ctx->r12, -0X10);
    // 0x8001F4F4: jr          $ra
    // 0x8001F4F8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    return;
    // 0x8001F4F8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8001F4FC:
    // 0x8001F4FC: beq         $v0, $zero, L_8001F538
    if (ctx->r2 == 0) {
        // 0x8001F500: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001F538;
    }
    // 0x8001F500: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001F504:
    // 0x8001F504: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8001F508: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8001F50C: beq         $v1, $t7, L_8001F520
    if (ctx->r3 == ctx->r15) {
        // 0x8001F510: nop
    
            goto L_8001F520;
    }
    // 0x8001F510: nop

    // 0x8001F514: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8001F518: jr          $ra
    // 0x8001F51C: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    return;
    // 0x8001F51C: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_8001F520:
    // 0x8001F520: bne         $a0, $v0, L_8001F530
    if (ctx->r4 != ctx->r2) {
        // 0x8001F524: nop
    
            goto L_8001F530;
    }
    // 0x8001F524: nop

    // 0x8001F528: jr          $ra
    // 0x8001F52C: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    return;
    // 0x8001F52C: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_8001F530:
    // 0x8001F530: bne         $v0, $zero, L_8001F504
    if (ctx->r2 != 0) {
        // 0x8001F534: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001F504;
    }
    // 0x8001F534: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001F538:
    // 0x8001F538: jr          $ra
    // 0x8001F53C: nop

    return;
    // 0x8001F53C: nop

;}
RECOMP_FUNC void FUN_8001f540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F540: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001F544: lw          $a2, 0x1BC8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1BC8);
    // 0x8001F548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F54C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F550: beq         $a2, $zero, L_8001F594
    if (ctx->r6 == 0) {
        // 0x8001F554: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8001F594;
    }
    // 0x8001F554: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8001F558:
    // 0x8001F558: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x8001F55C: beql        $v0, $zero, L_8001F584
    if (ctx->r2 == 0) {
        // 0x8001F560: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_8001F584;
    }
    goto skip_0;
    // 0x8001F560: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x8001F564: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8001F568: beq         $a2, $t6, L_8001F580
    if (ctx->r6 == ctx->r14) {
        // 0x8001F56C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8001F580;
    }
    // 0x8001F56C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8001F570: jal         0x8001F498
    // 0x8001F574: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8001F498)(rdram, ctx);
        goto after_0;
    // 0x8001F574: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001F578: b           L_8001F5C0
    // 0x8001F57C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_8001F5C0;
    // 0x8001F57C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_8001F580:
    // 0x8001F580: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_8001F584:
    // 0x8001F584: beql        $a3, $t7, L_8001F5A0
    if (ctx->r7 == ctx->r15) {
        // 0x8001F588: lw          $t8, 0x8($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X8);
            goto L_8001F5A0;
    }
    goto skip_1;
    // 0x8001F588: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    skip_1:
    // 0x8001F58C: bne         $v0, $zero, L_8001F558
    if (ctx->r2 != 0) {
        // 0x8001F590: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8001F558;
    }
    // 0x8001F590: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8001F594:
    // 0x8001F594: b           L_8001F5C0
    // 0x8001F598: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_8001F5C0;
    // 0x8001F598: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8001F59C: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
L_8001F5A0:
    // 0x8001F5A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001F5A4: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
    // 0x8001F5A8: lw          $t0, 0xC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XC);
    // 0x8001F5AC: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x8001F5B0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8001F5B4: jal         0x8001F160
    // 0x8001F5B8: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    LOOKUP_FUNC(0x8001F160)(rdram, ctx);
        goto after_1;
    // 0x8001F5B8: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    after_1:
    // 0x8001F5BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F5C0:
    // 0x8001F5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F5C8: jr          $ra
    // 0x8001F5CC: nop

    return;
    // 0x8001F5CC: nop

;}
RECOMP_FUNC void FUN_8001f5d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F5D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001F5D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001F5D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001F5DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F5E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001F5E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001F5E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F5EC: addiu       $s2, $zero, 0x100
    ctx->r18 = ADD32(0, 0X100);
L_8001F5F0:
    // 0x8001F5F0: jal         0x8001703C
    // 0x8001F5F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001703C)(rdram, ctx);
        goto after_0;
    // 0x8001F5F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001F5F8: bnel        $v0, $s1, L_8001F60C
    if (ctx->r2 != ctx->r17) {
        // 0x8001F5FC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001F60C;
    }
    goto skip_0;
    // 0x8001F5FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001F600: b           L_8001F618
    // 0x8001F604: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8001F618;
    // 0x8001F604: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8001F608: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001F60C:
    // 0x8001F60C: bne         $s0, $s2, L_8001F5F0
    if (ctx->r16 != ctx->r18) {
        // 0x8001F610: nop
    
            goto L_8001F5F0;
    }
    // 0x8001F610: nop

    // 0x8001F614: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001F618:
    // 0x8001F618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001F61C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F620: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F624: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001F628: jr          $ra
    // 0x8001F62C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001F62C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f630(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001F634: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001F638: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8001F63C: addiu       $s1, $s1, 0x1BC0
    ctx->r17 = ADD32(ctx->r17, 0X1BC0);
    // 0x8001F640: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001F644: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x8001F648: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F64C: beql        $s0, $zero, L_8001F6B4
    if (ctx->r16 == 0) {
        // 0x8001F650: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F6B4;
    }
    goto skip_0;
    // 0x8001F650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001F654: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_8001F658:
    // 0x8001F658: beql        $v0, $zero, L_8001F678
    if (ctx->r2 == 0) {
        // 0x8001F65C: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_8001F678;
    }
    goto skip_1;
    // 0x8001F65C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x8001F660: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8001F664: beql        $s0, $t6, L_8001F678
    if (ctx->r16 == ctx->r14) {
        // 0x8001F668: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_8001F678;
    }
    goto skip_2;
    // 0x8001F668: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x8001F66C: jal         0x8001F498
    // 0x8001F670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F498)(rdram, ctx);
        goto after_0;
    // 0x8001F670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001F674: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8001F678:
    // 0x8001F678: beql        $v0, $zero, L_8001F6A8
    if (ctx->r2 == 0) {
        // 0x8001F67C: lw          $s0, 0xC($s0)
        ctx->r16 = MEM_W(ctx->r16, 0XC);
            goto L_8001F6A8;
    }
    goto skip_3;
    // 0x8001F67C: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    skip_3:
    // 0x8001F680: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x8001F684: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8001F688: beql        $s0, $a0, L_8001F6A8
    if (ctx->r16 == ctx->r4) {
        // 0x8001F68C: lw          $s0, 0xC($s0)
        ctx->r16 = MEM_W(ctx->r16, 0XC);
            goto L_8001F6A8;
    }
    goto skip_4;
    // 0x8001F68C: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    skip_4:
    // 0x8001F690: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x8001F694: beql        $s0, $t7, L_8001F6A8
    if (ctx->r16 == ctx->r15) {
        // 0x8001F698: lw          $s0, 0xC($s0)
        ctx->r16 = MEM_W(ctx->r16, 0XC);
            goto L_8001F6A8;
    }
    goto skip_5;
    // 0x8001F698: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x8001F69C: jal         0x8001F5D0
    // 0x8001F6A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x8001F5D0)(rdram, ctx);
        goto after_1;
    // 0x8001F6A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8001F6A4: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
L_8001F6A8:
    // 0x8001F6A8: bnel        $s0, $zero, L_8001F658
    if (ctx->r16 != 0) {
        // 0x8001F6AC: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_8001F658;
    }
    goto skip_6;
    // 0x8001F6AC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x8001F6B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001F6B4:
    // 0x8001F6B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001F6B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001F6BC: jr          $ra
    // 0x8001F6C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001F6C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F6C4: nop

    // 0x8001F6C8: nop

    // 0x8001F6CC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f6d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f6d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F6D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001F6D4: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x8001F6D8: lw          $t6, 0x429C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X429C);
    // 0x8001F6DC: jr          $ra
    // 0x8001F6E0: sw          $t6, 0x429C($v0)
    MEM_W(0X429C, ctx->r2) = ctx->r14;
    return;
    // 0x8001F6E0: sw          $t6, 0x429C($v0)
    MEM_W(0X429C, ctx->r2) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f6e4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f6e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F6E4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001F6E8: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x8001F6EC: lw          $t6, 0x429C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X429C);
    // 0x8001F6F0: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8001F6F4: jr          $ra
    // 0x8001F6F8: sw          $t7, 0x429C($v0)
    MEM_W(0X429C, ctx->r2) = ctx->r15;
    return;
    // 0x8001F6F8: sw          $t7, 0x429C($v0)
    MEM_W(0X429C, ctx->r2) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f6fc(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f6fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F6FC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001F700: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x8001F704: lw          $t6, 0x429C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X429C);
    // 0x8001F708: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001F70C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8001F710: jr          $ra
    // 0x8001F714: sw          $t7, 0x429C($v0)
    MEM_W(0X429C, ctx->r2) = ctx->r15;
    return;
    // 0x8001F714: sw          $t7, 0x429C($v0)
    MEM_W(0X429C, ctx->r2) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f718(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F718: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001F71C: lw          $t6, -0x2AB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AB4);
    // 0x8001F720: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F724: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8001F728: beq         $t7, $zero, L_8001F738
    if (ctx->r15 == 0) {
        // 0x8001F72C: nop
    
            goto L_8001F738;
    }
    // 0x8001F72C: nop

    // 0x8001F730: jr          $ra
    // 0x8001F734: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001F734: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F738:
    // 0x8001F738: jr          $ra
    // 0x8001F73C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001F73C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001F740: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F744: jr          $ra
    // 0x8001F748: sh          $t6, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r14;
    return;
    // 0x8001F748: sh          $t6, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f74c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f74c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F74C: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F750: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8001F754: jr          $ra
    // 0x8001F758: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    return;
    // 0x8001F758: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f75c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f75c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F75C: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F760: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8001F764: jr          $ra
    // 0x8001F768: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    return;
    // 0x8001F768: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f76c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f76c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F76C: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F770: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F774: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8001F778: beq         $t7, $zero, L_8001F788
    if (ctx->r15 == 0) {
        // 0x8001F77C: nop
    
            goto L_8001F788;
    }
    // 0x8001F77C: nop

    // 0x8001F780: jr          $ra
    // 0x8001F784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001F784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F788:
    // 0x8001F788: jr          $ra
    // 0x8001F78C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001F78C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f790(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F790: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F794: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8001F798: jr          $ra
    // 0x8001F79C: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    return;
    // 0x8001F79C: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    // 0x8001F7A0: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F7A4: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x8001F7A8: jr          $ra
    // 0x8001F7AC: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    return;
    // 0x8001F7AC: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f7b0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f7b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F7B0: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F7B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F7B8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8001F7BC: beq         $t7, $zero, L_8001F7CC
    if (ctx->r15 == 0) {
        // 0x8001F7C0: nop
    
            goto L_8001F7CC;
    }
    // 0x8001F7C0: nop

    // 0x8001F7C4: jr          $ra
    // 0x8001F7C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001F7C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F7CC:
    // 0x8001F7CC: jr          $ra
    // 0x8001F7D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001F7D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f7d4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f7d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F7D4: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F7D8: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8001F7DC: jr          $ra
    // 0x8001F7E0: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    return;
    // 0x8001F7E0: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    // 0x8001F7E4: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F7E8: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x8001F7EC: jr          $ra
    // 0x8001F7F0: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    return;
    // 0x8001F7F0: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    // 0x8001F7F4: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8001F7F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F7FC: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8001F800: beq         $t7, $zero, L_8001F810
    if (ctx->r15 == 0) {
        // 0x8001F804: nop
    
            goto L_8001F810;
    }
    // 0x8001F804: nop

    // 0x8001F808: jr          $ra
    // 0x8001F80C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001F80C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F810:
    // 0x8001F810: jr          $ra
    // 0x8001F814: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001F814: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001F818: nop

    // 0x8001F81C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001f820(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001f820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F820: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001F824: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001F828: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8001F82C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001F830: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001F834: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8001F838: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8001F83C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001F840: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8001F844: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8001F848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F84C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001F854: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8001F858: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8001F85C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8001F860: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8001F864: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8001F868: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8001F86C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8001F870: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8001F874: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8001F878: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8001F87C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8001F880: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8001F884: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8001F888: jal         0x80030388
    // 0x8001F88C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x80030388)(rdram, ctx);
        goto after_0;
    // 0x8001F88C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8001F890: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8001F894: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001F898: jr          $ra
    // 0x8001F89C: nop

    return;
    // 0x8001F89C: nop

;}
RECOMP_FUNC void FUN_8001f8a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F8A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001F8A4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8001F8A8: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8001F8AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001F8B0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8001F8B4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8001F8B8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8001F8BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001F8C0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001F8C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8001F8C8: addiu       $t6, $t6, 0x78
    ctx->r14 = ADD32(ctx->r14, 0X78);
    // 0x8001F8CC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001F8D0: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x8001F8D4: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001F8D8: jal         0x80031670
    // 0x8001F8DC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    LOOKUP_FUNC(0x80031670)(rdram, ctx);
        goto after_0;
    // 0x8001F8DC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_0:
    // 0x8001F8E0: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // 0x8001F8E4: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // 0x8001F8E8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8001F8EC:
    // 0x8001F8EC: bnel        $s1, $zero, L_8001F8EC
    if (ctx->r17 != 0) {
        // 0x8001F8F0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8001F8EC;
    }
    goto skip_0;
    // 0x8001F8F0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x8001F8F4: lw          $t7, 0x4($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4);
    // 0x8001F8F8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001F8FC: addiu       $v1, $v1, 0x6340
    ctx->r3 = ADD32(ctx->r3, 0X6340);
    // 0x8001F900: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001F904: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8001F908: bgez        $t7, L_8001F920
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001F90C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001F920;
    }
    // 0x8001F90C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F910: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F914: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F918: nop

    // 0x8001F91C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001F920:
    // 0x8001F920: lw          $t8, 0x18($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X18);
    // 0x8001F924: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8001F928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001F92C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8001F930: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001F934: addiu       $s5, $s5, 0x6344
    ctx->r21 = ADD32(ctx->r21, 0X6344);
    // 0x8001F938: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001F93C: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    // 0x8001F940: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8001F944: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001F948: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001F94C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001F950: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8001F954: nop

    // 0x8001F958: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8001F95C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001F960: bgez        $v0, L_8001F978
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001F964: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8001F978;
    }
    // 0x8001F964: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001F968: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F96C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001F970: nop

    // 0x8001F974: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8001F978:
    // 0x8001F978: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8001F97C: nop

    // 0x8001F980: bc1f        L_8001F990
    if (!c1cs) {
        // 0x8001F984: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_8001F990;
    }
    // 0x8001F984: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x8001F988: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8001F98C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8001F990:
    // 0x8001F990: andi        $t2, $v0, 0xF
    ctx->r10 = ctx->r2 & 0XF;
    // 0x8001F994: beq         $t2, $zero, L_8001F9A8
    if (ctx->r10 == 0) {
        // 0x8001F998: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_8001F9A8;
    }
    // 0x8001F998: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8001F99C: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x8001F9A0: addiu       $v0, $t3, 0x10
    ctx->r2 = ADD32(ctx->r11, 0X10);
    // 0x8001F9A4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8001F9A8:
    // 0x8001F9A8: addiu       $t5, $v0, -0x10
    ctx->r13 = ADD32(ctx->r2, -0X10);
    // 0x8001F9AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001F9B0: sw          $t5, 0x633C($at)
    MEM_W(0X633C, ctx->r1) = ctx->r13;
    // 0x8001F9B4: addiu       $t6, $v0, 0x100
    ctx->r14 = ADD32(ctx->r2, 0X100);
    // 0x8001F9B8: jal         0x8002691C
    // 0x8001F9BC: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    LOOKUP_FUNC(0x8002691C)(rdram, ctx);
        goto after_1;
    // 0x8001F9BC: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    after_1:
    // 0x8001F9C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001F9C4: addiu       $v0, $v0, 0x6030
    ctx->r2 = ADD32(ctx->r2, 0X6030);
    // 0x8001F9C8: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001F9CC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001F9D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F9D4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001F9D8: addiu       $s0, $s0, 0x6044
    ctx->r16 = ADD32(ctx->r16, 0X6044);
    // 0x8001F9DC: addiu       $s2, $s2, 0x6030
    ctx->r18 = ADD32(ctx->r18, 0X6030);
    // 0x8001F9E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001F9E4:
    // 0x8001F9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001F9E8: jal         0x800268C0
    // 0x8001F9EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_2;
    // 0x8001F9EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x8001F9F0: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8001F9F4: addiu       $t7, $zero, 0xA00
    ctx->r15 = ADD32(0, 0XA00);
    // 0x8001F9F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001F9FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FA00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FA04: jal         0x80034A10
    // 0x8001FA08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_3;
    // 0x8001FA08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8001FA0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001FA10: sltiu       $at, $s1, 0x26
    ctx->r1 = ctx->r17 < 0X26 ? 1 : 0;
    // 0x8001FA14: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x8001FA18: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8001FA1C: bne         $at, $zero, L_8001F9E4
    if (ctx->r1 != 0) {
        // 0x8001FA20: sw          $v0, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->r2;
            goto L_8001F9E4;
    }
    // 0x8001FA20: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x8001FA24: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8001FA28: addiu       $t8, $zero, 0xA00
    ctx->r24 = ADD32(0, 0XA00);
    // 0x8001FA2C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001FA30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FA34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FA38: jal         0x80034A10
    // 0x8001FA3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_4;
    // 0x8001FA3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8001FA40: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001FA44: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8001FA48: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x8001FA4C: addiu       $s1, $s1, 0x1BE0
    ctx->r17 = ADD32(ctx->r17, 0X1BE0);
    // 0x8001FA50: addiu       $s0, $s0, 0x1BD8
    ctx->r16 = ADD32(ctx->r16, 0X1BD8);
L_8001FA54:
    // 0x8001FA54: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x8001FA58: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8001FA5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FA60: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8001FA64: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8001FA68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FA6C: jal         0x80034A10
    // 0x8001FA70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_5;
    // 0x8001FA70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8001FA74: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001FA78: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8001FA7C: bne         $at, $zero, L_8001FA54
    if (ctx->r1 != 0) {
        // 0x8001FA80: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8001FA54;
    }
    // 0x8001FA80: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x8001FA84: lw          $t1, 0x8($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X8);
    // 0x8001FA88: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001FA8C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001FA90: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001FA94: addiu       $s2, $s2, 0x1BE4
    ctx->r18 = ADD32(ctx->r18, 0X1BE4);
    // 0x8001FA98: addiu       $s0, $s0, 0x1BD8
    ctx->r16 = ADD32(ctx->r16, 0X1BD8);
    // 0x8001FA9C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8001FAA0: sw          $t1, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r9;
L_8001FAA4:
    // 0x8001FAA4: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8001FAA8: addiu       $t2, $zero, 0x68
    ctx->r10 = ADD32(0, 0X68);
    // 0x8001FAAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001FAB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FAB8: jal         0x80034A10
    // 0x8001FABC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_6;
    // 0x8001FABC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x8001FAC0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8001FAC4: sh          $s1, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r17;
    // 0x8001FAC8: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8001FACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FAD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FAD4: sw          $v1, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r3;
    // 0x8001FAD8: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8001FADC: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8001FAE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001FAE4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001FAE8: jal         0x80034A10
    // 0x8001FAEC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_7;
    // 0x8001FAEC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_7:
    // 0x8001FAF0: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8001FAF4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001FAF8: bne         $s0, $s2, L_8001FAA4
    if (ctx->r16 != ctx->r18) {
        // 0x8001FAFC: sw          $v0, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r2;
            goto L_8001FAA4;
    }
    // 0x8001FAFC: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8001FB00: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FB04: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001FB08: addiu       $a1, $a1, 0x1ED0
    ctx->r5 = ADD32(ctx->r5, 0X1ED0);
    // 0x8001FB0C: addiu       $a0, $a0, 0x1EB8
    ctx->r4 = ADD32(ctx->r4, 0X1EB8);
    // 0x8001FB10: jal         0x80030610
    // 0x8001FB14: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_8;
    // 0x8001FB14: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_8:
    // 0x8001FB18: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FB1C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001FB20: addiu       $a1, $a1, 0x1DB8
    ctx->r5 = ADD32(ctx->r5, 0X1DB8);
    // 0x8001FB24: addiu       $a0, $a0, 0x1DA0
    ctx->r4 = ADD32(ctx->r4, 0X1DA0);
    // 0x8001FB28: jal         0x80030610
    // 0x8001FB2C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_9;
    // 0x8001FB2C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_9:
    // 0x8001FB30: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FB34: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001FB38: addiu       $a1, $a1, 0x6968
    ctx->r5 = ADD32(ctx->r5, 0X6968);
    // 0x8001FB3C: addiu       $a0, $a0, 0x6950
    ctx->r4 = ADD32(ctx->r4, 0X6950);
    // 0x8001FB40: jal         0x80030610
    // 0x8001FB44: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_10;
    // 0x8001FB44: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_10:
    // 0x8001FB48: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8001FB4C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001FB50: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001FB54: addiu       $s0, $s0, 0x1BF0
    ctx->r16 = ADD32(ctx->r16, 0X1BF0);
    // 0x8001FB58: addiu       $t6, $t6, 0x6020
    ctx->r14 = ADD32(ctx->r14, 0X6020);
    // 0x8001FB5C: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x8001FB60: addiu       $a2, $a2, -0x458
    ctx->r6 = ADD32(ctx->r6, -0X458);
    // 0x8001FB64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001FB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001FB6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8001FB70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001FB74: jal         0x80028260
    // 0x8001FB78: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_11;
    // 0x8001FB78: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_11:
    // 0x8001FB7C: jal         0x80034C90
    // 0x8001FB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_12;
    // 0x8001FB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8001FB84: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001FB88: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FB8C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001FB90: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8001FB94: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8001FB98: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8001FB9C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8001FBA0: jr          $ra
    // 0x8001FBA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001FBA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001fba8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001fba8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FBA8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001FBAC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001FBB0: lui         $s1, 0x8006
    ctx->r17 = S32(0X8006 << 16);
    // 0x8001FBB4: addiu       $s1, $s1, -0x3B50
    ctx->r17 = ADD32(ctx->r17, -0X3B50);
    // 0x8001FBB8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001FBBC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001FBC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001FBC4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001FBC8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001FBCC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001FBD0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001FBD4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001FBD8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001FBDC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001FBE0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001FBE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001FBE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001FBEC: addiu       $a2, $a2, 0x1DA0
    ctx->r6 = ADD32(ctx->r6, 0X1DA0);
    // 0x8001FBF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001FBF4: jal         0x80000934
    // 0x8001FBF8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80000934)(rdram, ctx);
        goto after_0;
    // 0x8001FBF8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8001FBFC: jal         0x800006F4
    // 0x8001FC00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800006F4)(rdram, ctx);
        goto after_1;
    // 0x8001FC00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8001FC04: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001FC08: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x8001FC0C: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8001FC10: sw          $v0, 0x1BD0($at)
    MEM_W(0X1BD0, ctx->r1) = ctx->r2;
    // 0x8001FC14: addiu       $s6, $s6, 0x1BD8
    ctx->r22 = ADD32(ctx->r22, 0X1BD8);
    // 0x8001FC18: addiu       $s7, $s7, 0x7950
    ctx->r23 = ADD32(ctx->r23, 0X7950);
    // 0x8001FC1C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8001FC20: addiu       $s5, $zero, 0x20
    ctx->r21 = ADD32(0, 0X20);
    // 0x8001FC24: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x8001FC28: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8001FC2C: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
L_8001FC30:
    // 0x8001FC30: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FC34: addiu       $a0, $a0, 0x1DA0
    ctx->r4 = ADD32(ctx->r4, 0X1DA0);
    // 0x8001FC38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001FC3C: jal         0x800266B0
    // 0x8001FC40: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_2;
    // 0x8001FC40: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x8001FC44: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8001FC48: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x8001FC4C: beql        $v1, $s3, L_8001FC70
    if (ctx->r3 == ctx->r19) {
        // 0x8001FC50: lw          $t7, 0x0($s7)
        ctx->r15 = MEM_W(ctx->r23, 0X0);
            goto L_8001FC70;
    }
    goto skip_0;
    // 0x8001FC50: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    skip_0:
    // 0x8001FC54: beq         $v1, $s4, L_8001FCD0
    if (ctx->r3 == ctx->r20) {
        // 0x8001FC58: nop
    
            goto L_8001FCD0;
    }
    // 0x8001FC58: nop

    // 0x8001FC5C: beql        $v1, $s5, L_8001FCD0
    if (ctx->r3 == ctx->r21) {
        // 0x8001FC60: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_8001FCD0;
    }
    goto skip_1;
    // 0x8001FC60: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    skip_1:
    // 0x8001FC64: b           L_8001FCD0
    // 0x8001FC68: nop

        goto L_8001FCD0;
    // 0x8001FC68: nop

    // 0x8001FC6C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
L_8001FC70:
    // 0x8001FC70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001FC74: divu        $zero, $t7, $fp
    lo = S32(U32(ctx->r15) / U32(ctx->r30)); hi = S32(U32(ctx->r15) % U32(ctx->r30));
    // 0x8001FC78: mfhi        $t8
    ctx->r24 = hi;
    // 0x8001FC7C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001FC80: addu        $t0, $s6, $t9
    ctx->r8 = ADD32(ctx->r22, ctx->r25);
    // 0x8001FC84: bne         $fp, $zero, L_8001FC90
    if (ctx->r30 != 0) {
        // 0x8001FC88: nop
    
            goto L_8001FC90;
    }
    // 0x8001FC88: nop

    // 0x8001FC8C: break       7
    do_break(2147613836);
L_8001FC90:
    // 0x8001FC90: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x8001FC94: jal         0x8001FD14
    // 0x8001FC98: nop

    LOOKUP_FUNC(0x8001FD14)(rdram, ctx);
        goto after_3;
    // 0x8001FC98: nop

    after_3:
    // 0x8001FC9C: beq         $v0, $zero, L_8001FCD0
    if (ctx->r2 == 0) {
        // 0x8001FCA0: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_8001FCD0;
    }
    // 0x8001FCA0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FCA4: addiu       $a0, $a0, 0x1EB8
    ctx->r4 = ADD32(ctx->r4, 0X1EB8);
    // 0x8001FCA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001FCAC: jal         0x800266B0
    // 0x8001FCB0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_4;
    // 0x8001FCB0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x8001FCB4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8001FCB8: jal         0x8001FEBC
    // 0x8001FCBC: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    LOOKUP_FUNC(0x8001FEBC)(rdram, ctx);
        goto after_5;
    // 0x8001FCBC: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_5:
    // 0x8001FCC0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8001FCC4: b           L_8001FCD0
    // 0x8001FCC8: lw          $s0, 0x4($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X4);
        goto L_8001FCD0;
    // 0x8001FCC8: lw          $s0, 0x4($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X4);
    // 0x8001FCCC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001FCD0:
    // 0x8001FCD0: beq         $s2, $zero, L_8001FC30
    if (ctx->r18 == 0) {
        // 0x8001FCD4: nop
    
            goto L_8001FC30;
    }
    // 0x8001FCD4: nop

    // 0x8001FCD8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FCDC: jal         0x800268E4
    // 0x8001FCE0: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    LOOKUP_FUNC(0x800268E4)(rdram, ctx);
        goto after_6;
    // 0x8001FCE0: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    after_6:
    // 0x8001FCE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001FCE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001FCEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FCF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001FCF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001FCF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001FCFC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001FD00: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001FD04: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001FD08: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001FD0C: jr          $ra
    // 0x8001FD10: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8001FD10: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001fd14(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001fd14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FD14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001FD18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001FD1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001FD20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001FD24: jal         0x800200B0
    // 0x8001FD28: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800200B0)(rdram, ctx);
        goto after_0;
    // 0x8001FD28: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001FD2C: jal         0x80028A10
    // 0x8001FD30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_1;
    // 0x8001FD30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x8001FD34: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8001FD38: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8001FD3C: beq         $v1, $zero, L_8001FD54
    if (ctx->r3 == 0) {
        // 0x8001FD40: nop
    
            goto L_8001FD54;
    }
    // 0x8001FD40: nop

    // 0x8001FD44: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x8001FD48: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001FD4C: jal         0x80034F70
    // 0x8001FD50: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    LOOKUP_FUNC(0x80034F70)(rdram, ctx);
        goto after_2;
    // 0x8001FD50: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    after_2:
L_8001FD54:
    // 0x8001FD54: jal         0x80033C60
    // 0x8001FD58: nop

    LOOKUP_FUNC(0x80033C60)(rdram, ctx);
        goto after_3;
    // 0x8001FD58: nop

    after_3:
    // 0x8001FD5C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001FD60: lw          $t6, 0x6340($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6340);
    // 0x8001FD64: srl         $t7, $v0, 2
    ctx->r15 = S32(U32(ctx->r2) >> 2);
    // 0x8001FD68: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001FD6C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8001FD70: addiu       $t9, $t8, 0x100
    ctx->r25 = ADD32(ctx->r24, 0X100);
    // 0x8001FD74: andi        $t1, $t9, 0xFFF0
    ctx->r9 = ctx->r25 & 0XFFF0;
    // 0x8001FD78: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x8001FD7C: lw          $v1, 0x633C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X633C);
    // 0x8001FD80: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8001FD84: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001FD88: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FD8C: sltu        $at, $a3, $v1
    ctx->r1 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8001FD90: beq         $at, $zero, L_8001FDA0
    if (ctx->r1 == 0) {
        // 0x8001FD94: nop
    
            goto L_8001FDA0;
    }
    // 0x8001FD94: nop

    // 0x8001FD98: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x8001FD9C: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
L_8001FDA0:
    // 0x8001FDA0: lw          $t2, 0x7958($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7958);
    // 0x8001FDA4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8001FDA8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8001FDAC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001FDB0: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8001FDB4: jal         0x8002C4D0
    // 0x8001FDB8: lw          $a0, 0x1BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BD8);
    LOOKUP_FUNC(0x8002C4D0)(rdram, ctx);
        goto after_4;
    // 0x8001FDB8: lw          $a0, 0x1BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BD8);
    after_4:
    // 0x8001FDBC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8001FDC0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001FDC4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001FDC8: addiu       $t0, $t0, 0x1BD8
    ctx->r8 = ADD32(ctx->r8, 0X1BD8);
    // 0x8001FDCC: addiu       $v1, $v1, 0x7958
    ctx->r3 = ADD32(ctx->r3, 0X7958);
    // 0x8001FDD0: bne         $t4, $zero, L_8001FDE0
    if (ctx->r12 != 0) {
        // 0x8001FDD4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8001FDE0;
    }
    // 0x8001FDD4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8001FDD8: b           L_8001FEA8
    // 0x8001FDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FEA8;
    // 0x8001FDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FDE0:
    // 0x8001FDE0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001FDE4: addiu       $t5, $t5, 0x1EB8
    ctx->r13 = ADD32(ctx->r13, 0X1EB8);
    // 0x8001FDE8: addiu       $t6, $s0, 0x60
    ctx->r14 = ADD32(ctx->r16, 0X60);
    // 0x8001FDEC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8001FDF0: sw          $t5, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r13;
    // 0x8001FDF4: sw          $t6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r14;
    // 0x8001FDF8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001FDFC: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8001FE00: addiu       $v0, $v0, 0x50D0
    ctx->r2 = ADD32(ctx->r2, 0X50D0);
    // 0x8001FE04: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001FE08: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8001FE0C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8001FE10: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001FE14: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001FE18: sw          $t1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r9;
    // 0x8001FE1C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001FE20: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x8001FE24: addiu       $t1, $t1, 0x51A0
    ctx->r9 = ADD32(ctx->r9, 0X51A0);
    // 0x8001FE28: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001FE2C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8001FE30: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8001FE34: lui         $t3, 0x8003
    ctx->r11 = S32(0X8003 << 16);
    // 0x8001FE38: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x8001FE3C: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x8001FE40: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001FE44: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001FE48: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x8001FE4C: addiu       $t3, $t3, 0x6530
    ctx->r11 = ADD32(ctx->r11, 0X6530);
    // 0x8001FE50: addiu       $t4, $t4, -0x26F0
    ctx->r12 = ADD32(ctx->r12, -0X26F0);
    // 0x8001FE54: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x8001FE58: sw          $t8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r24;
    // 0x8001FE5C: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x8001FE60: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8001FE64: sw          $t2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r10;
    // 0x8001FE68: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8001FE6C: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x8001FE70: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x8001FE74: sw          $t5, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r13;
    // 0x8001FE78: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8001FE7C: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x8001FE80: lw          $a0, 0x1BD0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BD0);
    // 0x8001FE84: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x8001FE88: jal         0x80026300
    // 0x8001FE8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_5;
    // 0x8001FE8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8001FE90: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001FE94: addiu       $v1, $v1, 0x7958
    ctx->r3 = ADD32(ctx->r3, 0X7958);
    // 0x8001FE98: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001FE9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FEA0: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8001FEA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8001FEA8:
    // 0x8001FEA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FEAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001FEB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8001FEB4: jr          $ra
    // 0x8001FEB8: nop

    return;
    // 0x8001FEB8: nop

;}
RECOMP_FUNC void FUN_8001febc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FEC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FEC4: jal         0x80033C60
    // 0x8001FEC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80033C60)(rdram, ctx);
        goto after_0;
    // 0x8001FEC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001FECC: srl         $t6, $v0, 2
    ctx->r14 = S32(U32(ctx->r2) >> 2);
    // 0x8001FED0: bne         $t6, $zero, L_8001FEEC
    if (ctx->r14 != 0) {
        // 0x8001FED4: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_8001FEEC;
    }
    // 0x8001FED4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001FED8: lw          $t7, 0x795C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X795C);
    // 0x8001FEDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001FEE0: bnel        $t7, $zero, L_8001FEF0
    if (ctx->r15 != 0) {
        // 0x8001FEE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001FEF0;
    }
    goto skip_0;
    // 0x8001FEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001FEE8: sw          $zero, 0x795C($at)
    MEM_W(0X795C, ctx->r1) = 0;
L_8001FEEC:
    // 0x8001FEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001FEF0:
    // 0x8001FEF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FEF4: jr          $ra
    // 0x8001FEF8: nop

    return;
    // 0x8001FEF8: nop

;}
RECOMP_FUNC void FUN_8001fefc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001FF00: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8001FF04: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8001FF08: addiu       $s1, $s1, 0x6020
    ctx->r17 = ADD32(ctx->r17, 0X6020);
    // 0x8001FF0C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8001FF10: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8001FF14: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8001FF18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001FF1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001FF20: beq         $s0, $zero, L_8001FF78
    if (ctx->r16 == 0) {
        // 0x8001FF24: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001FF78;
    }
    // 0x8001FF24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001FF28: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8001FF2C:
    // 0x8001FF2C: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x8001FF30: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x8001FF34: bne         $at, $zero, L_8001FF78
    if (ctx->r1 != 0) {
        // 0x8001FF38: addiu       $v1, $v0, 0xA00
        ctx->r3 = ADD32(ctx->r2, 0XA00);
            goto L_8001FF78;
    }
    // 0x8001FF38: addiu       $v1, $v0, 0xA00
    ctx->r3 = ADD32(ctx->r2, 0XA00);
    // 0x8001FF3C: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001FF40: bne         $at, $zero, L_8001FF6C
    if (ctx->r1 != 0) {
        // 0x8001FF44: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_8001FF6C;
    }
    // 0x8001FF44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8001FF48: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8001FF4C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001FF50: lw          $t7, 0x7950($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7950);
    // 0x8001FF54: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x8001FF58: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x8001FF5C: jal         0x80028A10
    // 0x8001FF60: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_0;
    // 0x8001FF60: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_0:
    // 0x8001FF64: b           L_80020068
    // 0x8001FF68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80020068;
    // 0x8001FF68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001FF6C:
    // 0x8001FF6C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8001FF70: bnel        $s0, $zero, L_8001FF2C
    if (ctx->r16 != 0) {
        // 0x8001FF74: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_8001FF2C;
    }
    goto skip_0;
    // 0x8001FF74: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_0:
L_8001FF78:
    // 0x8001FF78: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x8001FF7C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8001FF80: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x8001FF84: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001FF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001FF8C: jal         0x80026890
    // 0x8001FF90: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    LOOKUP_FUNC(0x80026890)(rdram, ctx);
        goto after_1;
    // 0x8001FF90: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    after_1:
    // 0x8001FF94: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001FF98: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8001FF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001FFA0: beq         $a2, $zero, L_8001FFB8
    if (ctx->r6 == 0) {
        // 0x8001FFA4: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8001FFB8;
    }
    // 0x8001FFA4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8001FFA8: jal         0x800268C0
    // 0x8001FFAC: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_2;
    // 0x8001FFAC: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_2:
    // 0x8001FFB0: b           L_8001FFE4
    // 0x8001FFB4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
        goto L_8001FFE4;
    // 0x8001FFB4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
L_8001FFB8:
    // 0x8001FFB8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8001FFBC: beql        $v0, $zero, L_8001FFDC
    if (ctx->r2 == 0) {
        // 0x8001FFC0: sw          $s0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r16;
            goto L_8001FFDC;
    }
    goto skip_1;
    // 0x8001FFC0: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    skip_1:
    // 0x8001FFC4: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x8001FFC8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001FFCC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8001FFD0: b           L_8001FFE4
    // 0x8001FFD4: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
        goto L_8001FFE4;
    // 0x8001FFD4: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8001FFD8: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
L_8001FFDC:
    // 0x8001FFDC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8001FFE0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8001FFE4:
    // 0x8001FFE4: andi        $v0, $a3, 0x1
    ctx->r2 = ctx->r7 & 0X1;
    // 0x8001FFE8: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x8001FFEC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8001FFF0: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x8001FFF4: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x8001FFF8: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001FFFC: lw          $t2, 0x7950($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7950);
    // 0x80020000: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80020004: addiu       $t0, $t0, 0x7954
    ctx->r8 = ADD32(ctx->r8, 0X7954);
    // 0x80020008: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x8002000C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80020010: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80020014: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80020018: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8002001C: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80020020: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80020024: addiu       $t6, $t6, 0x6950
    ctx->r14 = ADD32(ctx->r14, 0X6950);
    // 0x80020028: addiu       $t4, $t4, 0x6350
    ctx->r12 = ADD32(ctx->r12, 0X6350);
    // 0x8002002C: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x80020030: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80020034: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80020038: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8002003C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80020040: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80020044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002004C: jal         0x8002BFA0
    // 0x80020050: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x8002BFA0)(rdram, ctx);
        goto after_3;
    // 0x80020050: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
    // 0x80020054: jal         0x80028A10
    // 0x80020058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_4;
    // 0x80020058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8002005C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020060: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80020064: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80020068:
    // 0x80020068: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8002006C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80020070: jr          $ra
    // 0x80020074: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80020074: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80020078(rdram, ctx);
;}
RECOMP_FUNC void FUN_80020078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020078: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002007C: addiu       $v1, $v1, 0x6020
    ctx->r3 = ADD32(ctx->r3, 0X6020);
    // 0x80020080: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80020084: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x80020088: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002008C: bne         $t6, $zero, L_800200A8
    if (ctx->r14 != 0) {
        // 0x80020090: addiu       $v0, $v0, -0x104
        ctx->r2 = ADD32(ctx->r2, -0X104);
            goto L_800200A8;
    }
    // 0x80020090: addiu       $v0, $v0, -0x104
    ctx->r2 = ADD32(ctx->r2, -0X104);
    // 0x80020094: addiu       $t7, $t7, 0x6030
    ctx->r15 = ADD32(ctx->r15, 0X6030);
    // 0x80020098: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002009C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800200A0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800200A4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_800200A8:
    // 0x800200A8: jr          $ra
    // 0x800200AC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x800200AC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800200b0(rdram, ctx);
;}
