#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8013d374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D374: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8013D378: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8013D37C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8013D380: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8013D384: lbu         $t0, -0x20FB($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X20FB);
    // 0x8013D388: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013D38C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8013D390: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8013D394: jr          $ra
    // 0x8013D398: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    return;
    // 0x8013D398: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d39c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d39c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D39C: jr          $ra
    // 0x8013D3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013D3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d3a4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d3a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D3A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8013D3A8: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x8013D3AC: addiu       $a1, $a1, -0x20EC
    ctx->r5 = ADD32(ctx->r5, -0X20EC);
    // 0x8013D3B0: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x8013D3B4: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8013D3B8: lbu         $t4, -0xE($t3)
    ctx->r12 = MEM_BU(ctx->r11, -0XE);
    // 0x8013D3BC: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x8013D3C0: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8013D3C4: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8013D3C8: bne         $at, $zero, L_8013D3D8
    if (ctx->r1 != 0) {
            // 0x8013D3CC: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    LOOKUP_FUNC(0x8013D3D8)(rdram, ctx);
    return;
    }
    // 0x8013D3CC: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8013D3D0: jr          $ra
    // 0x8013D3D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013D3D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d3d8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d3d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D3D8: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8013D3DC: lbu         $t8, -0xD($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0XD);
    // 0x8013D3E0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013D3E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8013D3E8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8013D3EC: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    // 0x8013D3F0: jr          $ra
    // 0x8013D3F4: nop

    return;
    // 0x8013D3F4: nop

;}
RECOMP_FUNC void M7_FUN_8013d3f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D3F8: lbu         $v0, 0x2D8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2D8);
    // 0x8013D3FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013D400: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8013D404: bne         $at, $zero, L_8013D420
    if (ctx->r1 != 0) {
        // 0x8013D408: slti        $at, $v0, 0xB
        ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
            goto L_8013D420;
    }
    // 0x8013D408: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8013D40C: beq         $at, $zero, L_8013D420
    if (ctx->r1 == 0) {
        // 0x8013D410: nop
    
            goto L_8013D420;
    }
    // 0x8013D410: nop

    // 0x8013D414: lbu         $v0, 0x375($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X375);
    // 0x8013D418: bgtz        $v0, L_8013D428
    if (SIGNED(ctx->r2) > 0) {
            // 0x8013D41C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8013D428)(rdram, ctx);
    return;
    }
    // 0x8013D41C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8013D420:
    // 0x8013D420: jr          $ra
    // 0x8013D424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013D424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d428(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D428: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x8013D42C: lbu         $t7, 0x377($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X377);
    // 0x8013D430: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x8013D434: addu        $t9, $a0, $v0
    ctx->r25 = ADD32(ctx->r4, ctx->r2);
    // 0x8013D438: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D43C: lbu         $t2, 0x378($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X378);
    // 0x8013D440: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8013D444: addiu       $t0, $t0, 0x42A0
    ctx->r8 = ADD32(ctx->r8, 0X42A0);
    // 0x8013D448: mflo        $t8
    ctx->r24 = lo;
    // 0x8013D44C: addu        $a2, $t0, $t8
    ctx->r6 = ADD32(ctx->r8, ctx->r24);
    // 0x8013D450: lbu         $t4, 0x1A($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1A);
    // 0x8013D454: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D458: mflo        $t3
    ctx->r11 = lo;
    // 0x8013D45C: addu        $a3, $t0, $t3
    ctx->r7 = ADD32(ctx->r8, ctx->r11);
    // 0x8013D460: lbu         $t5, 0x1A($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X1A);
    // 0x8013D464: bnel        $t4, $t5, L_8013D474
    if (ctx->r12 != ctx->r13) {
        // 0x8013D468: lbu         $t6, 0x9($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X9);
            goto L_8013D474;
    }
    goto skip_0;
    // 0x8013D468: lbu         $t6, 0x9($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X9);
    skip_0:
    // 0x8013D46C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8013D470: lbu         $t6, 0x9($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X9);
L_8013D474:
    // 0x8013D474: lbu         $t7, 0x9($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X9);
    // 0x8013D478: bnel        $t6, $t7, L_8013D48C
    if (ctx->r14 != ctx->r15) {
        // 0x8013D47C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8013D48C;
    }
    goto skip_1;
    // 0x8013D47C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x8013D480: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // 0x8013D484: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8013D488: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013D48C:
    // 0x8013D48C: jr          $ra
    // 0x8013D490: nop

    return;
    // 0x8013D490: nop

;}
RECOMP_FUNC void M7_FUN_8013d494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D494: nop

    // 0x8013D498: nop

    // 0x8013D49C: nop

;}
RECOMP_FUNC void M7_FUN_8013d4a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D4A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013D4A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013D4A8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013D4AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013D4B0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013D4B4: bne         $a1, $zero, L_8013D4C8
    if (ctx->r5 != 0) {
        // 0x8013D4B8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8013D4C8;
    }
    // 0x8013D4B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013D4BC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013D4C0: b           L_8013D4D0
    // 0x8013D4C4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8013D4D0;
    // 0x8013D4C4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8013D4C8:
    // 0x8013D4C8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013D4CC: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8013D4D0:
    // 0x8013D4D0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8013D4D4: jal         0x80126944
    // 0x8013D4D8: sb          $a0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8013D4D8: sb          $a0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013D4DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013D4E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D4E4: bne         $v0, $at, L_8013D500
    if (ctx->r2 != ctx->r1) {
        // 0x8013D4E8: lbu         $a0, 0x23($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X23);
            goto L_8013D500;
    }
    // 0x8013D4E8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8013D4EC: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x8013D4F0: lbu         $v0, 0x337($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X337);
    // 0x8013D4F4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8013D4F8: b           L_8013D510
    // 0x8013D4FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8013D510;
    // 0x8013D4FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8013D500:
    // 0x8013D500: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8013D504: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013D508: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8013D50C: lbu         $v0, -0x2000($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2000);
L_8013D510:
    // 0x8013D510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013D514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013D518: jr          $ra
    // 0x8013D51C: nop

    return;
    // 0x8013D51C: nop

;}
RECOMP_FUNC void M7_FUN_8013d520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013D524: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8013D528: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013D52C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013D530: sll         $a3, $a1, 24
    ctx->r7 = S32(ctx->r5 << 24);
    // 0x8013D534: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x8013D538: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013D53C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013D540: bne         $a2, $zero, L_8013D554
    if (ctx->r6 != 0) {
        // 0x8013D544: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8013D554;
    }
    // 0x8013D544: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013D548: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013D54C: b           L_8013D55C
    // 0x8013D550: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8013D55C;
    // 0x8013D550: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8013D554:
    // 0x8013D554: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013D558: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8013D55C:
    // 0x8013D55C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8013D560: sb          $a0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r4;
    // 0x8013D564: sb          $a2, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r6;
    // 0x8013D568: jal         0x80126944
    // 0x8013D56C: sb          $a3, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8013D56C: sb          $a3, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013D570: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013D574: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D578: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8013D57C: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x8013D580: bne         $v0, $at, L_8013D59C
    if (ctx->r2 != ctx->r1) {
        // 0x8013D584: lb          $a3, 0x27($sp)
        ctx->r7 = MEM_B(ctx->r29, 0X27);
            goto L_8013D59C;
    }
    // 0x8013D584: lb          $a3, 0x27($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X27);
    // 0x8013D588: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8013D58C: lbu         $t6, 0x337($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X337);
    // 0x8013D590: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8013D594: b           L_8013D5E0
    // 0x8013D598: sb          $t7, 0x337($v0)
    MEM_B(0X337, ctx->r2) = ctx->r15;
        goto L_8013D5E0;
    // 0x8013D598: sb          $t7, 0x337($v0)
    MEM_B(0X337, ctx->r2) = ctx->r15;
L_8013D59C:
    // 0x8013D59C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013D5A0: addiu       $t9, $t9, -0x1FFC
    ctx->r25 = ADD32(ctx->r25, -0X1FFC);
    // 0x8013D5A4: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8013D5A8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8013D5AC: lbu         $t0, -0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, -0X4);
    // 0x8013D5B0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8013D5B4: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x8013D5B8: addu        $t1, $t0, $a3
    ctx->r9 = ADD32(ctx->r8, ctx->r7);
    // 0x8013D5BC: jal         0x8013D4A0
    // 0x8013D5C0: sb          $t1, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r9;
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_1;
    // 0x8013D5C0: sb          $t1, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r9;
    after_1:
    // 0x8013D5C4: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8013D5C8: bne         $at, $zero, L_8013D5E0
    if (ctx->r1 != 0) {
        // 0x8013D5CC: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8013D5E0;
    }
    // 0x8013D5CC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013D5D0: addiu       $t2, $zero, 0x63
    ctx->r10 = ADD32(0, 0X63);
    // 0x8013D5D4: sb          $t2, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r10;
    // 0x8013D5D8: b           L_8013D5E4
    // 0x8013D5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013D5E4;
    // 0x8013D5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013D5E0:
    // 0x8013D5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013D5E4:
    // 0x8013D5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013D5E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013D5EC: jr          $ra
    // 0x8013D5F0: nop

    return;
    // 0x8013D5F0: nop

;}
RECOMP_FUNC void M7_FUN_8013d5f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D5F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013D5F8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013D5FC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8013D600: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8013D604: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8013D608: lw          $t7, -0x2004($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2004);
    // 0x8013D60C: jr          $ra
    // 0x8013D610: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    return;
    // 0x8013D610: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d614(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D614: nop

    // 0x8013D618: nop

    // 0x8013D61C: nop

;}
RECOMP_FUNC void M7_FUN_8013d620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D620: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8013D624: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013D628: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8013D62C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8013D630: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8013D634: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8013D638: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8013D63C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8013D640: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8013D644: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8013D648: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8013D64C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013D650: addiu       $t6, $t6, -0x1B6C
    ctx->r14 = ADD32(ctx->r14, -0X1B6C);
    // 0x8013D654: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013D658: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x8013D65C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8013D660: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8013D664: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013D668: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8013D66C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8013D670: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x8013D674: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013D678: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8013D67C: addiu       $s2, $s2, -0x1B7C
    ctx->r18 = ADD32(ctx->r18, -0X1B7C);
    // 0x8013D680: sw          $t8, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r24;
    // 0x8013D684: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013D688: sw          $t7, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r15;
    // 0x8013D68C: lw          $t9, -0x4334($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4334);
    // 0x8013D690: lbu         $t0, 0x63($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X63);
    // 0x8013D694: beql        $t0, $zero, L_8013D9E4
    if (ctx->r8 == 0) {
        // 0x8013D698: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8013D9E4;
    }
    goto skip_0;
    // 0x8013D698: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8013D69C: jal         0x80005E44
    // 0x8013D6A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8013D6A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8013D6A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8013D6A8: jal         0x80005E44
    // 0x8013D6AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x8013D6AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8013D6B0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8013D6B4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8013D6B8: addiu       $s1, $s1, -0x1480
    ctx->r17 = ADD32(ctx->r17, -0X1480);
    // 0x8013D6BC: addiu       $s0, $s0, -0x14B0
    ctx->r16 = ADD32(ctx->r16, -0X14B0);
    // 0x8013D6C0: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
L_8013D6C4:
    // 0x8013D6C4: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
    // 0x8013D6C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8013D6CC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8013D6D0: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x8013D6D4: lw          $t1, 0xC($s4)
    ctx->r9 = MEM_W(ctx->r20, 0XC);
    // 0x8013D6D8: lw          $t2, 0x8($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X8);
    // 0x8013D6DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8013D6E0: sw          $t1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r9;
    // 0x8013D6E4: jal         0x80005E44
    // 0x8013D6E8: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x8013D6E8: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    after_2:
    // 0x8013D6EC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8013D6F0: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8013D6F4: bnel        $at, $zero, L_8013D6C4
    if (ctx->r1 != 0) {
        // 0x8013D6F8: lw          $t2, 0x0($s4)
        ctx->r10 = MEM_W(ctx->r20, 0X0);
            goto L_8013D6C4;
    }
    goto skip_1;
    // 0x8013D6F8: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    skip_1:
    // 0x8013D6FC: jal         0x80006214
    // 0x8013D700: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x8013D700: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x8013D704: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8013D708: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x8013D70C: addiu       $s6, $s6, -0x4C20
    ctx->r22 = ADD32(ctx->r22, -0X4C20);
    // 0x8013D710: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
    // 0x8013D714: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8013D718: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8013D71C: or          $s6, $s6, $at
    ctx->r22 = ctx->r22 | ctx->r1;
    // 0x8013D720: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8013D724: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8013D728: sw          $s6, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r22;
    // 0x8013D72C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8013D730: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x8013D734: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x8013D738: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x8013D73C: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x8013D740: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8013D744: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8013D748: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8013D74C: sb          $zero, 0x48($t0)
    MEM_B(0X48, ctx->r8) = 0;
    // 0x8013D750: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x8013D754: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8013D758: sb          $s2, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r18;
    // 0x8013D75C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8013D760: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8013D764: sb          $zero, 0x4A($t4)
    MEM_B(0X4A, ctx->r12) = 0;
    // 0x8013D768: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8013D76C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8013D770: jal         0x801302CC
    // 0x8013D774: sb          $t5, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r13;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_4;
    // 0x8013D774: sb          $t5, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r13;
    after_4:
    // 0x8013D778: bne         $v0, $zero, L_8013D7B8
    if (ctx->r2 != 0) {
        // 0x8013D77C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8013D7B8;
    }
    // 0x8013D77C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8013D780: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8013D784: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013D788: lwc1        $f0, -0x1970($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1970);
    // 0x8013D78C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D790: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013D794: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013D798: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x8013D79C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8013D7A0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013D7A4: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    // 0x8013D7A8: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8013D7AC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8013D7B0: b           L_8013D7EC
    // 0x8013D7B4: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
        goto L_8013D7EC;
    // 0x8013D7B4: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
L_8013D7B8:
    // 0x8013D7B8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8013D7BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013D7C0: lwc1        $f0, -0x196C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X196C);
    // 0x8013D7C4: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8013D7C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013D7CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013D7D0: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x8013D7D4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8013D7D8: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8013D7DC: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
    // 0x8013D7E0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8013D7E4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D7E8: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
L_8013D7EC:
    // 0x8013D7EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013D7F0: jal         0x8012C784
    // 0x8013D7F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_5;
    // 0x8013D7F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8013D7F8: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x8013D7FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013D800: lwc1        $f22, -0x1968($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X1968);
    // 0x8013D804: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x8013D808: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x8013D80C: addiu       $s4, $zero, 0xC0
    ctx->r20 = ADD32(0, 0XC0);
    // 0x8013D810: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8013D814: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8013D818: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8013D81C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013D820: sw          $s6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r22;
    // 0x8013D824: lw          $t3, 0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X4);
    // 0x8013D828: addiu       $a2, $zero, 0x3F2
    ctx->r6 = ADD32(0, 0X3F2);
    // 0x8013D82C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013D830: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x8013D834: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x8013D838: ori         $t6, $t4, 0x100
    ctx->r14 = ctx->r12 | 0X100;
    // 0x8013D83C: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x8013D840: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x8013D844: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8013D848: sb          $s2, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r18;
    // 0x8013D84C: lw          $t8, 0x4($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4);
    // 0x8013D850: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D854: sb          $zero, 0x49($t9)
    MEM_B(0X49, ctx->r25) = 0;
    // 0x8013D858: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x8013D85C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013D860: sb          $zero, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = 0;
    // 0x8013D864: lw          $t2, 0x4($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4);
    // 0x8013D868: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8013D86C: sb          $s4, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r20;
    // 0x8013D870: lw          $t4, 0x4($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X4);
    // 0x8013D874: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8013D878: swc1        $f20, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f20.u32l;
    // 0x8013D87C: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x8013D880: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8013D884: swc1        $f20, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f20.u32l;
    // 0x8013D888: lw          $t8, 0x4($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4);
    // 0x8013D88C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D890: swc1        $f20, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f20.u32l;
    // 0x8013D894: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x8013D898: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013D89C: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x8013D8A0: lw          $t2, 0x4($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4);
    // 0x8013D8A4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8013D8A8: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x8013D8AC: lw          $t4, 0x4($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X4);
    // 0x8013D8B0: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8013D8B4: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    // 0x8013D8B8: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x8013D8BC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8013D8C0: swc1        $f22, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f22.u32l;
    // 0x8013D8C4: lw          $t8, 0x4($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4);
    // 0x8013D8C8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D8CC: swc1        $f22, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f22.u32l;
    // 0x8013D8D0: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x8013D8D4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013D8D8: jal         0x8012C89C
    // 0x8013D8DC: swc1        $f22, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f22.u32l;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x8013D8DC: swc1        $f22, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f22.u32l;
    after_6:
    // 0x8013D8E0: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8013D8E4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8013D8E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8013D8EC:
    // 0x8013D8EC: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8013D8F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8013D8F4: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // 0x8013D8F8: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
    // 0x8013D8FC: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x8013D900: addiu       $a2, $zero, 0x3F3
    ctx->r6 = ADD32(0, 0X3F3);
    // 0x8013D904: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013D908: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8013D90C: sw          $s6, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r22;
    // 0x8013D910: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8013D914: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8013D918: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x8013D91C: ori         $t7, $t5, 0x100
    ctx->r15 = ctx->r13 | 0X100;
    // 0x8013D920: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8013D924: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8013D928: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D92C: sb          $s2, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r18;
    // 0x8013D930: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8013D934: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013D938: sb          $s2, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r18;
    // 0x8013D93C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8013D940: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8013D944: sb          $s2, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = ctx->r18;
    // 0x8013D948: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x8013D94C: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8013D950: sb          $s4, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r20;
    // 0x8013D954: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8013D958: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8013D95C: swc1        $f20, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f20.u32l;
    // 0x8013D960: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8013D964: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D968: swc1        $f20, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f20.u32l;
    // 0x8013D96C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8013D970: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013D974: swc1        $f20, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f20.u32l;
    // 0x8013D978: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8013D97C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8013D980: sh          $zero, 0x10($t3)
    MEM_H(0X10, ctx->r11) = 0;
    // 0x8013D984: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x8013D988: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8013D98C: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    // 0x8013D990: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8013D994: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8013D998: sh          $zero, 0x14($t7)
    MEM_H(0X14, ctx->r15) = 0;
    // 0x8013D99C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8013D9A0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013D9A4: swc1        $f22, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f22.u32l;
    // 0x8013D9A8: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8013D9AC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013D9B0: swc1        $f22, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f22.u32l;
    // 0x8013D9B4: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8013D9B8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8013D9BC: jal         0x8012C89C
    // 0x8013D9C0: swc1        $f22, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f22.u32l;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_7;
    // 0x8013D9C0: swc1        $f22, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f22.u32l;
    after_7:
    // 0x8013D9C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8013D9C8: bne         $s1, $s3, L_8013D8EC
    if (ctx->r17 != ctx->r19) {
        // 0x8013D9CC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8013D8EC;
    }
    // 0x8013D9CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8013D9D0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013D9D4: addiu       $a1, $a1, -0x25F0
    ctx->r5 = ADD32(ctx->r5, -0X25F0);
    // 0x8013D9D8: jal         0x800058DC
    // 0x8013D9DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8013D9DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x8013D9E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8013D9E4:
    // 0x8013D9E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013D9E8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013D9EC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8013D9F0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8013D9F4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8013D9F8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8013D9FC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8013DA00: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8013DA04: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8013DA08: jr          $ra
    // 0x8013DA0C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8013DA0C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013da10(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013da10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DA10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013DA14: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013da18(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013da18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DA18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013DA1C: swc1        $f0, -0x14C0($at)
    MEM_W(-0X14C0, ctx->r1) = ctx->f0.u32l;
    // 0x8013DA20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DA24: swc1        $f0, -0x14BC($at)
    MEM_W(-0X14BC, ctx->r1) = ctx->f0.u32l;
    // 0x8013DA28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DA2C: swc1        $f0, -0x14B8($at)
    MEM_W(-0X14B8, ctx->r1) = ctx->f0.u32l;
    // 0x8013DA30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DA34: sh          $zero, -0x14B4($at)
    MEM_H(-0X14B4, ctx->r1) = 0;
    // 0x8013DA38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DA3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013DA40: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DA44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013DA48: sh          $zero, -0x14B2($at)
    MEM_H(-0X14B2, ctx->r1) = 0;
    // 0x8013DA4C: jal         0x80116E80
    // 0x8013DA50: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x8013DA50: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x8013DA54: jal         0x80001060
    // 0x8013DA58: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_1;
    // 0x8013DA58: nop

    after_1:
    // 0x8013DA5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013DA60: bne         $v0, $zero, L_8013DAB0
    if (ctx->r2 != 0) {
        // 0x8013DA64: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8013DAB0;
    }
    // 0x8013DA64: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013DA68: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013DA6C: lw          $t7, 0x26C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DA70: addiu       $t6, $zero, 0xC5
    ctx->r14 = ADD32(0, 0XC5);
    // 0x8013DA74: addiu       $t9, $zero, 0x8F
    ctx->r25 = ADD32(0, 0X8F);
    // 0x8013DA78: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8013DA7C: addiu       $t2, $zero, 0x115
    ctx->r10 = ADD32(0, 0X115);
    // 0x8013DA80: addiu       $t5, $zero, 0xDF
    ctx->r13 = ADD32(0, 0XDF);
    // 0x8013DA84: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8013DA88: lw          $t0, 0x26C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DA8C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8013DA90: sh          $t9, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r25;
    // 0x8013DA94: lw          $t3, 0x26C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DA98: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8013DA9C: sh          $t2, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r10;
    // 0x8013DAA0: lw          $t7, 0x26C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DAA4: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x8013DAA8: b           L_8013DB54
    // 0x8013DAAC: sh          $t5, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r13;
        goto L_8013DB54;
    // 0x8013DAAC: sh          $t5, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r13;
L_8013DAB0:
    // 0x8013DAB0: jal         0x801302CC
    // 0x8013DAB4: nop

    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_2;
    // 0x8013DAB4: nop

    after_2:
    // 0x8013DAB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013DABC: bne         $v0, $zero, L_8013DB0C
    if (ctx->r2 != 0) {
        // 0x8013DAC0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8013DB0C;
    }
    // 0x8013DAC0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013DAC4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013DAC8: lw          $t0, 0x26C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DACC: addiu       $t8, $zero, 0x18A
    ctx->r24 = ADD32(0, 0X18A);
    // 0x8013DAD0: addiu       $t1, $zero, 0x11E
    ctx->r9 = ADD32(0, 0X11E);
    // 0x8013DAD4: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x8013DAD8: addiu       $t4, $zero, 0x22A
    ctx->r12 = ADD32(0, 0X22A);
    // 0x8013DADC: addiu       $t6, $zero, 0x1BE
    ctx->r14 = ADD32(0, 0X1BE);
    // 0x8013DAE0: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8013DAE4: lw          $t3, 0x26C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DAE8: lw          $t2, 0x2C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X2C);
    // 0x8013DAEC: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x8013DAF0: lw          $t7, 0x26C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DAF4: lw          $t5, 0x2C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X2C);
    // 0x8013DAF8: sh          $t4, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r12;
    // 0x8013DAFC: lw          $t0, 0x26C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB00: lw          $t8, 0x2C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X2C);
    // 0x8013DB04: b           L_8013DB54
    // 0x8013DB08: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
        goto L_8013DB54;
    // 0x8013DB08: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
L_8013DB0C:
    // 0x8013DB0C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013DB10: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013DB14: lw          $t3, 0x26C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB18: addiu       $t9, $zero, 0x1E2
    ctx->r25 = ADD32(0, 0X1E2);
    // 0x8013DB1C: addiu       $t2, $zero, 0x110
    ctx->r10 = ADD32(0, 0X110);
    // 0x8013DB20: lw          $t1, 0x2C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X2C);
    // 0x8013DB24: addiu       $t5, $zero, 0x25A
    ctx->r13 = ADD32(0, 0X25A);
    // 0x8013DB28: addiu       $t8, $zero, 0x188
    ctx->r24 = ADD32(0, 0X188);
    // 0x8013DB2C: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x8013DB30: lw          $t7, 0x26C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB34: lw          $t4, 0x2C($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X2C);
    // 0x8013DB38: sh          $t2, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r10;
    // 0x8013DB3C: lw          $t0, 0x26C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB40: lw          $t6, 0x2C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X2C);
    // 0x8013DB44: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x8013DB48: lw          $t3, 0x26C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB4C: lw          $t9, 0x2C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X2C);
    // 0x8013DB50: sh          $t8, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r24;
L_8013DB54:
    // 0x8013DB54: lw          $t1, 0x26C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB58: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013DB5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013DB60: lw          $t7, 0x2C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X2C);
    // 0x8013DB64: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8013DB68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013DB6C: swc1        $f4, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f4.u32l;
    // 0x8013DB70: lw          $t2, 0x26C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB74: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8013DB78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013DB7C: lw          $t4, 0x2C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X2C);
    // 0x8013DB80: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8013DB84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013DB88: swc1        $f6, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f6.u32l;
    // 0x8013DB8C: lw          $t0, 0x26C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DB90: addiu       $a0, $zero, -0x800
    ctx->r4 = ADD32(0, -0X800);
    // 0x8013DB94: lw          $t5, 0x2C($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X2C);
    // 0x8013DB98: swc1        $f0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f0.u32l;
    // 0x8013DB9C: lw          $t6, 0x26C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DBA0: lw          $t3, 0x2C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X2C);
    // 0x8013DBA4: swc1        $f8, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f8.u32l;
    // 0x8013DBA8: lw          $t8, 0x26C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DBAC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8013DBB0: swc1        $f10, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f10.u32l;
    // 0x8013DBB4: lw          $t1, 0x26C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DBB8: lw          $t7, 0x2C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X2C);
    // 0x8013DBBC: swc1        $f0, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f0.u32l;
    // 0x8013DBC0: lw          $t2, 0x26C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DBC4: lw          $t4, 0x2C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X2C);
    // 0x8013DBC8: swc1        $f0, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f0.u32l;
    // 0x8013DBCC: lw          $t0, 0x26C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DBD0: lw          $t5, 0x2C($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X2C);
    // 0x8013DBD4: swc1        $f0, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f0.u32l;
    // 0x8013DBD8: lw          $t6, 0x26C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DBDC: lw          $t3, 0x2C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X2C);
    // 0x8013DBE0: jal         0x8001EAD0
    // 0x8013DBE4: swc1        $f0, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x8013DBE4: swc1        $f0, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f0.u32l;
    after_3:
    // 0x8013DBE8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013DBEC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013DBF0: lw          $t8, 0x26C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DBF4: addiu       $a0, $zero, -0x800
    ctx->r4 = ADD32(0, -0X800);
    // 0x8013DBF8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8013DBFC: jal         0x8001EB64
    // 0x8013DC00: swc1        $f0, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x8013DC00: swc1        $f0, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f0.u32l;
    after_4:
    // 0x8013DC04: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013DC08: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013DC0C: lw          $t1, 0x26C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X26C);
    // 0x8013DC10: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013DC14: addiu       $a1, $a1, -0x23C8
    ctx->r5 = ADD32(ctx->r5, -0X23C8);
    // 0x8013DC18: lw          $t7, 0x2C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X2C);
    // 0x8013DC1C: swc1        $f0, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f0.u32l;
    // 0x8013DC20: jal         0x800058DC
    // 0x8013DC24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8013DC24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8013DC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013DC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013DC30: jr          $ra
    // 0x8013DC34: nop

    return;
    // 0x8013DC34: nop

;}
RECOMP_FUNC void M7_FUN_8013dc38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DC38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013DC3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013DC40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DC44: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013DC48: jal         0x800058DC
    // 0x8013DC4C: addiu       $a1, $a1, -0x23A0
    ctx->r5 = ADD32(ctx->r5, -0X23A0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8013DC4C: addiu       $a1, $a1, -0x23A0
    ctx->r5 = ADD32(ctx->r5, -0X23A0);
    after_0:
    // 0x8013DC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013DC54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013DC58: jr          $ra
    // 0x8013DC5C: nop

    return;
    // 0x8013DC5C: nop

;}
RECOMP_FUNC void M7_FUN_8013dc60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DC60: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8013DC64: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8013DC68: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x8013DC6C: addiu       $s6, $s6, -0x4410
    ctx->r22 = ADD32(ctx->r22, -0X4410);
    // 0x8013DC70: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8013DC74: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8013DC78: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8013DC7C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8013DC80: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8013DC84: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8013DC88: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8013DC8C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8013DC90: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8013DC94: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8013DC98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013DC9C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8013DCA0: sb          $zero, 0x39E($s6)
    MEM_B(0X39E, ctx->r22) = 0;
    // 0x8013DCA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8013DCA8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8013DCAC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8013DCB0: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x8013DCB4: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8013DCB8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8013DCBC: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
L_8013DCC0:
    // 0x8013DCC0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8013DCC4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8013DCC8: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x8013DCCC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8013DCD0: bne         $at, $zero, L_8013DCC0
    if (ctx->r1 != 0) {
        // 0x8013DCD4: sb          $zero, 0x22($t8)
        MEM_B(0X22, ctx->r24) = 0;
            goto L_8013DCC0;
    }
    // 0x8013DCD4: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x8013DCD8: jal         0x80126944
    // 0x8013DCDC: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8013DCDC: nop

    after_0:
    // 0x8013DCE0: bnel        $v0, $zero, L_8013E53C
    if (ctx->r2 != 0) {
        // 0x8013DCE4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_0;
    // 0x8013DCE4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8013DCE8: jal         0x8001F718
    // 0x8013DCEC: nop

    LOOKUP_FUNC(0x8001F718)(rdram, ctx);
        goto after_1;
    // 0x8013DCEC: nop

    after_1:
    // 0x8013DCF0: bnel        $v0, $zero, L_8013E53C
    if (ctx->r2 != 0) {
        // 0x8013DCF4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_1;
    // 0x8013DCF4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x8013DCF8: lhu         $t9, 0xEF0($s6)
    ctx->r25 = MEM_HU(ctx->r22, 0XEF0);
    // 0x8013DCFC: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x8013DD00: bnel        $t0, $zero, L_8013E53C
    if (ctx->r8 != 0) {
        // 0x8013DD04: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_2;
    // 0x8013DD04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x8013DD08: lhu         $t1, 0x18E($s6)
    ctx->r9 = MEM_HU(ctx->r22, 0X18E);
    // 0x8013DD0C: bnel        $t1, $zero, L_8013E53C
    if (ctx->r9 != 0) {
        // 0x8013DD10: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_3;
    // 0x8013DD10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x8013DD14: lw          $t2, 0x58($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X58);
    // 0x8013DD18: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8013DD1C: bnel        $t3, $zero, L_8013E53C
    if (ctx->r11 != 0) {
        // 0x8013DD20: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_4;
    // 0x8013DD20: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_4:
    // 0x8013DD24: lhu         $t4, 0xA0($s6)
    ctx->r12 = MEM_HU(ctx->r22, 0XA0);
    // 0x8013DD28: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x8013DD2C: beq         $t5, $zero, L_8013DD54
    if (ctx->r13 == 0) {
        // 0x8013DD30: nop
    
            goto L_8013DD54;
    }
    // 0x8013DD30: nop

    // 0x8013DD34: lbu         $t6, 0x39F($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X39F);
    // 0x8013DD38: bne         $t6, $zero, L_8013DD54
    if (ctx->r14 != 0) {
        // 0x8013DD3C: nop
    
            goto L_8013DD54;
    }
    // 0x8013DD3C: nop

    // 0x8013DD40: lbu         $t7, 0x39C($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X39C);
    // 0x8013DD44: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8013DD48: sb          $t9, 0x39C($s6)
    MEM_B(0X39C, ctx->r22) = ctx->r25;
    // 0x8013DD4C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8013DD50: sb          $t0, 0x39C($s6)
    MEM_B(0X39C, ctx->r22) = ctx->r8;
L_8013DD54:
    // 0x8013DD54: jal         0x80108280
    // 0x8013DD58: nop

    LOOKUP_FUNC(0x80108280)(rdram, ctx);
        goto after_2;
    // 0x8013DD58: nop

    after_2:
    // 0x8013DD5C: sra         $a0, $v0, 8
    ctx->r4 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8013DD60: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8013DD64: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8013DD68: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x8013DD6C: beq         $t1, $zero, L_8013E538
    if (ctx->r9 == 0) {
        // 0x8013DD70: andi        $s1, $a0, 0xFFFF
        ctx->r17 = ctx->r4 & 0XFFFF;
            goto L_8013E538;
    }
    // 0x8013DD70: andi        $s1, $a0, 0xFFFF
    ctx->r17 = ctx->r4 & 0XFFFF;
    // 0x8013DD74: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x8013DD78: beql        $t2, $zero, L_8013E53C
    if (ctx->r10 == 0) {
        // 0x8013DD7C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_5;
    // 0x8013DD7C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x8013DD80: lbu         $t3, 0x39C($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X39C);
    // 0x8013DD84: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8013DD88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013DD8C: bnel        $s2, $t3, L_8013E53C
    if (ctx->r18 != ctx->r11) {
        // 0x8013DD90: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_6;
    // 0x8013DD90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x8013DD94: sb          $v0, 0x39E($s6)
    MEM_B(0X39E, ctx->r22) = ctx->r2;
    // 0x8013DD98: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8013DD9C: sb          $v0, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r2;
    // 0x8013DDA0: lw          $t5, 0x4($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X4);
    // 0x8013DDA4: jal         0x801302CC
    // 0x8013DDA8: sb          $v0, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r2;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_3;
    // 0x8013DDA8: sb          $v0, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r2;
    after_3:
    // 0x8013DDAC: bne         $v0, $zero, L_8013DEA0
    if (ctx->r2 != 0) {
        // 0x8013DDB0: sll         $t7, $s1, 4
        ctx->r15 = S32(ctx->r17 << 4);
            goto L_8013DEA0;
    }
    // 0x8013DDB0: sll         $t7, $s1, 4
    ctx->r15 = S32(ctx->r17 << 4);
    // 0x8013DDB4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8013DDB8: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x8013DDBC: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x8013DDC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8013DDC4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8013DDC8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013DDCC: addiu       $t1, $t1, -0x1E90
    ctx->r9 = ADD32(ctx->r9, -0X1E90);
    // 0x8013DDD0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8013DDD4: addu        $s3, $t0, $t1
    ctx->r19 = ADD32(ctx->r8, ctx->r9);
    // 0x8013DDD8: lh          $t2, -0x42($s3)
    ctx->r10 = MEM_H(ctx->r19, -0X42);
    // 0x8013DDDC: lw          $v0, 0xE0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XE0);
    // 0x8013DDE0: sw          $s1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r17;
    // 0x8013DDE4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8013DDE8: sw          $s0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r16;
    // 0x8013DDEC: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DDF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013DDF4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013DDF8: lwc1        $f8, 0x4($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8013DDFC: ldc1        $f22, -0x1960($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, -0X1960);
    // 0x8013DE00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DE04: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013DE08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8013DE0C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8013DE10: mul.d       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f22.d);
    // 0x8013DE14: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8013DE18: swc1        $f4, -0x14C0($at)
    MEM_W(-0X14C0, ctx->r1) = ctx->f4.u32l;
    // 0x8013DE1C: lw          $t4, 0xDC($s6)
    ctx->r12 = MEM_W(ctx->r22, 0XDC);
    // 0x8013DE20: lwc1        $f8, 0x44($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8013DE24: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8013DE28: nop

    // 0x8013DE2C: bc1fl       L_8013DE58
    if (!c1cs) {
        // 0x8013DE30: lh          $t8, -0x3E($s3)
        ctx->r24 = MEM_H(ctx->r19, -0X3E);
            goto L_8013DE58;
    }
    goto skip_7;
    // 0x8013DE30: lh          $t8, -0x3E($s3)
    ctx->r24 = MEM_H(ctx->r19, -0X3E);
    skip_7:
    // 0x8013DE34: lh          $t5, -0x40($s3)
    ctx->r13 = MEM_H(ctx->r19, -0X40);
    // 0x8013DE38: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DE3C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DE40: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8013DE44: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8013DE48: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013DE4C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8013DE50: swc1        $f4, -0x14BC($at)
    MEM_W(-0X14BC, ctx->r1) = ctx->f4.u32l;
    // 0x8013DE54: lh          $t8, -0x3E($s3)
    ctx->r24 = MEM_H(ctx->r19, -0X3E);
L_8013DE58:
    // 0x8013DE58: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DE5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DE60: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8013DE64: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8013DE68: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8013DE6C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013DE70: addiu       $s0, $s0, -0x14B4
    ctx->r16 = ADD32(ctx->r16, -0X14B4);
    // 0x8013DE74: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8013DE78: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8013DE7C: mul.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f22.d);
    // 0x8013DE80: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8013DE84: swc1        $f6, -0x14B8($at)
    MEM_W(-0X14B8, ctx->r1) = ctx->f6.u32l;
    // 0x8013DE88: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DE8C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013DE90: lh          $t0, 0x12($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X12);
    // 0x8013DE94: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x8013DE98: b           L_8013DF94
    // 0x8013DE9C: ldc1        $f24, -0x1958($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, -0X1958);
        goto L_8013DF94;
    // 0x8013DE9C: ldc1        $f24, -0x1958($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, -0X1958);
L_8013DEA0:
    // 0x8013DEA0: sll         $t1, $s1, 4
    ctx->r9 = S32(ctx->r17 << 4);
    // 0x8013DEA4: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8013DEA8: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x8013DEAC: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8013DEB0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8013DEB4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8013DEB8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8013DEBC: addiu       $t4, $t4, -0x1E90
    ctx->r12 = ADD32(ctx->r12, -0X1E90);
    // 0x8013DEC0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8013DEC4: addu        $s3, $t3, $t4
    ctx->r19 = ADD32(ctx->r11, ctx->r12);
    // 0x8013DEC8: lh          $t5, -0x42($s3)
    ctx->r13 = MEM_H(ctx->r19, -0X42);
    // 0x8013DECC: lw          $v0, 0xE0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XE0);
    // 0x8013DED0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013DED4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8013DED8: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DEDC: ldc1        $f24, -0x1950($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, -0X1950);
    // 0x8013DEE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013DEE4: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8013DEE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DEEC: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8013DEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013DEF4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8013DEF8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8013DEFC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8013DF00: mul.d       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f24.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f24.d);
    // 0x8013DF04: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8013DF08: swc1        $f8, -0x14C0($at)
    MEM_W(-0X14C0, ctx->r1) = ctx->f8.u32l;
    // 0x8013DF0C: lw          $t8, 0xDC($s6)
    ctx->r24 = MEM_W(ctx->r22, 0XDC);
    // 0x8013DF10: lwc1        $f16, 0x44($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8013DF14: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8013DF18: nop

    // 0x8013DF1C: bc1fl       L_8013DF48
    if (!c1cs) {
        // 0x8013DF20: lh          $t0, -0x3E($s3)
        ctx->r8 = MEM_H(ctx->r19, -0X3E);
            goto L_8013DF48;
    }
    goto skip_8;
    // 0x8013DF20: lh          $t0, -0x3E($s3)
    ctx->r8 = MEM_H(ctx->r19, -0X3E);
    skip_8:
    // 0x8013DF24: lh          $t7, -0x40($s3)
    ctx->r15 = MEM_H(ctx->r19, -0X40);
    // 0x8013DF28: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DF2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DF30: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8013DF34: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8013DF38: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013DF3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013DF40: swc1        $f8, -0x14BC($at)
    MEM_W(-0X14BC, ctx->r1) = ctx->f8.u32l;
    // 0x8013DF44: lh          $t0, -0x3E($s3)
    ctx->r8 = MEM_H(ctx->r19, -0X3E);
L_8013DF48:
    // 0x8013DF48: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DF4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013DF50: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8013DF54: lwc1        $f18, 0xC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8013DF58: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8013DF5C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013DF60: addiu       $s0, $s0, -0x14B4
    ctx->r16 = ADD32(ctx->r16, -0X14B4);
    // 0x8013DF64: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8013DF68: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8013DF6C: mul.d       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f24.d);
    // 0x8013DF70: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8013DF74: swc1        $f10, -0x14B8($at)
    MEM_W(-0X14B8, ctx->r1) = ctx->f10.u32l;
    // 0x8013DF78: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x8013DF7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013DF80: lh          $t3, 0x12($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X12);
    // 0x8013DF84: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    // 0x8013DF88: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8013DF8C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x8013DF90: ldc1        $f22, -0x1948($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, -0X1948);
L_8013DF94:
    // 0x8013DF94: lbu         $t4, 0x17($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X17);
    // 0x8013DF98: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8013DF9C: addiu       $s4, $s4, -0x14B2
    ctx->r20 = ADD32(ctx->r20, -0X14B2);
    // 0x8013DFA0: bne         $s2, $t4, L_8013DFBC
    if (ctx->r18 != ctx->r12) {
        // 0x8013DFA4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8013DFBC;
    }
    // 0x8013DFA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8013DFA8: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8013DFAC: addiu       $s4, $s4, -0x14B2
    ctx->r20 = ADD32(ctx->r20, -0X14B2);
    // 0x8013DFB0: addiu       $t5, $zero, 0x1800
    ctx->r13 = ADD32(0, 0X1800);
    // 0x8013DFB4: b           L_8013DFC4
    // 0x8013DFB8: sh          $t5, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r13;
        goto L_8013DFC4;
    // 0x8013DFB8: sh          $t5, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r13;
L_8013DFBC:
    // 0x8013DFBC: jal         0x80119F9C
    // 0x8013DFC0: addiu       $a1, $sp, 0x6E
    ctx->r5 = ADD32(ctx->r29, 0X6E);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_4;
    // 0x8013DFC0: addiu       $a1, $sp, 0x6E
    ctx->r5 = ADD32(ctx->r29, 0X6E);
    after_4:
L_8013DFC4:
    // 0x8013DFC4: jal         0x801302CC
    // 0x8013DFC8: nop

    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_5;
    // 0x8013DFC8: nop

    after_5:
    // 0x8013DFCC: bnel        $v0, $zero, L_8013E0C8
    if (ctx->r2 != 0) {
        // 0x8013DFD0: lh          $a0, 0x0($s4)
        ctx->r4 = MEM_H(ctx->r20, 0X0);
            goto L_8013E0C8;
    }
    goto skip_9;
    // 0x8013DFD0: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    skip_9:
    // 0x8013DFD4: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013DFD8: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8013DFDC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013DFE0: jal         0x8001EB64
    // 0x8013DFE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x8013DFE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_6:
    // 0x8013DFE8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8013DFEC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013DFF0: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8013DFF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8013DFF8: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8013DFFC: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x8013E000: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x8013E004: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8013E008: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x8013E00C: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x8013E010: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E014: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8013E018: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E01C: jal         0x8001EAD0
    // 0x8013E020: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x8013E020: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
    // 0x8013E024: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8013E028: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x8013E02C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013E030: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x8013E034: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E038: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8013E03C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E040: jal         0x8001EB64
    // 0x8013E044: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x8013E044: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_8:
    // 0x8013E048: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8013E04C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E050: lwc1        $f8, -0x14C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X14C0);
    // 0x8013E054: lw          $t2, 0x4($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X4);
    // 0x8013E058: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E05C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8013E060: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013E064: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x8013E068: lw          $t4, 0x4($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X4);
    // 0x8013E06C: lwc1        $f16, -0x14BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X14BC);
    // 0x8013E070: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8013E074: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x8013E078: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E07C: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8013E080: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E084: jal         0x8001EAD0
    // 0x8013E088: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_9;
    // 0x8013E088: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_9:
    // 0x8013E08C: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8013E090: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E094: lwc1        $f4, -0x14B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14B8);
    // 0x8013E098: lw          $t6, 0x4($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X4);
    // 0x8013E09C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8013E0A0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8013E0A4: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x8013E0A8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013E0AC: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x8013E0B0: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x8013E0B4: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8013E0B8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8013E0BC: b           L_8013E1B0
    // 0x8013E0C0: sh          $t7, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r15;
        goto L_8013E1B0;
    // 0x8013E0C0: sh          $t7, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r15;
    // 0x8013E0C4: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
L_8013E0C8:
    // 0x8013E0C8: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x8013E0CC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E0D0: jal         0x8001EB64
    // 0x8013E0D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_10;
    // 0x8013E0D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_10:
    // 0x8013E0D8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8013E0DC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8013E0E0: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x8013E0E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8013E0E8: mul.s       $f8, $f0, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8013E0EC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8013E0F0: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x8013E0F4: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8013E0F8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8013E0FC: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x8013E100: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E104: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x8013E108: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E10C: jal         0x8001EAD0
    // 0x8013E110: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_11;
    // 0x8013E110: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_11:
    // 0x8013E114: mul.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8013E118: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8013E11C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8013E120: swc1        $f16, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f16.u32l;
    // 0x8013E124: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E128: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x8013E12C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E130: jal         0x8001EB64
    // 0x8013E134: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_12;
    // 0x8013E134: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_12:
    // 0x8013E138: mul.s       $f18, $f0, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8013E13C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E140: lwc1        $f4, -0x14C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14C0);
    // 0x8013E144: lw          $t8, 0x4($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X4);
    // 0x8013E148: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E14C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013E150: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013E154: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x8013E158: lw          $t7, 0x4($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X4);
    // 0x8013E15C: lwc1        $f8, -0x14BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X14BC);
    // 0x8013E160: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x8013E164: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x8013E168: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E16C: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x8013E170: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E174: jal         0x8001EAD0
    // 0x8013E178: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_13;
    // 0x8013E178: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_13:
    // 0x8013E17C: mul.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8013E180: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E184: lwc1        $f16, -0x14B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X14B8);
    // 0x8013E188: lw          $t1, 0x4($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X4);
    // 0x8013E18C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8013E190: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013E194: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8013E198: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8013E19C: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x8013E1A0: lw          $t4, 0x4($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X4);
    // 0x8013E1A4: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x8013E1A8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8013E1AC: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
L_8013E1B0:
    // 0x8013E1B0: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8013E1B4: addiu       $s1, $s1, -0x14B0
    ctx->r17 = ADD32(ctx->r17, -0X14B0);
    // 0x8013E1B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8013E1BC:
    // 0x8013E1BC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8013E1C0: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x8013E1C4: addu        $s0, $s5, $t8
    ctx->r16 = ADD32(ctx->r21, ctx->r24);
    // 0x8013E1C8: beql        $t6, $zero, L_8013E388
    if (ctx->r14 == 0) {
        // 0x8013E1CC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8013E388;
    }
    goto skip_10;
    // 0x8013E1CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
    // 0x8013E1D0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8013E1D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013E1D8: jal         0x801302CC
    // 0x8013E1DC: sb          $t9, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r25;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_14;
    // 0x8013E1DC: sb          $t9, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r25;
    after_14:
    // 0x8013E1E0: bnel        $v0, $zero, L_8013E2BC
    if (ctx->r2 != 0) {
        // 0x8013E1E4: lh          $a0, 0x0($s4)
        ctx->r4 = MEM_H(ctx->r20, 0X0);
            goto L_8013E2BC;
    }
    goto skip_11;
    // 0x8013E1E4: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    skip_11:
    // 0x8013E1E8: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E1EC: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8013E1F0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E1F4: jal         0x8001EB64
    // 0x8013E1F8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_15;
    // 0x8013E1F8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_15:
    // 0x8013E1FC: lh          $t1, -0x42($s3)
    ctx->r9 = MEM_H(ctx->r19, -0X42);
    // 0x8013E200: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x8013E204: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8013E208: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8013E20C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8013E210: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x8013E214: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013E218: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8013E21C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8013E220: mul.d       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f22.d);
    // 0x8013E224: nop

    // 0x8013E228: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8013E22C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8013E230: add.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d + ctx->f18.d;
    // 0x8013E234: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8013E238: swc1        $f10, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f10.u32l;
    // 0x8013E23C: lh          $t3, -0x40($s3)
    ctx->r11 = MEM_H(ctx->r19, -0X40);
    // 0x8013E240: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x8013E244: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8013E248: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8013E24C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8013E250: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x8013E254: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013E258: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8013E25C: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x8013E260: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E264: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8013E268: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E26C: jal         0x8001EAD0
    // 0x8013E270: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_16;
    // 0x8013E270: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_16:
    // 0x8013E274: lh          $t7, -0x3E($s3)
    ctx->r15 = MEM_H(ctx->r19, -0X3E);
    // 0x8013E278: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8013E27C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8013E280: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8013E284: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8013E288: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013E28C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013E290: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8013E294: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8013E298: mul.d       $f18, $f4, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f22.d);
    // 0x8013E29C: nop

    // 0x8013E2A0: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8013E2A4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8013E2A8: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x8013E2AC: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8013E2B0: b           L_8013E384
    // 0x8013E2B4: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
        goto L_8013E384;
    // 0x8013E2B4: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x8013E2B8: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
L_8013E2BC:
    // 0x8013E2BC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x8013E2C0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E2C4: jal         0x8001EB64
    // 0x8013E2C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_17;
    // 0x8013E2C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_17:
    // 0x8013E2CC: lh          $t4, -0x42($s3)
    ctx->r12 = MEM_H(ctx->r19, -0X42);
    // 0x8013E2D0: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8013E2D4: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x8013E2D8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8013E2DC: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8013E2E0: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x8013E2E4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013E2E8: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8013E2EC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8013E2F0: mul.d       $f6, $f16, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f24.d);
    // 0x8013E2F4: nop

    // 0x8013E2F8: mul.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8013E2FC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8013E300: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8013E304: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8013E308: swc1        $f18, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f18.u32l;
    // 0x8013E30C: lh          $t6, -0x40($s3)
    ctx->r14 = MEM_H(ctx->r19, -0X40);
    // 0x8013E310: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x8013E314: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8013E318: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8013E31C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8013E320: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x8013E324: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013E328: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8013E32C: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x8013E330: lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X0);
    // 0x8013E334: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x8013E338: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E33C: jal         0x8001EAD0
    // 0x8013E340: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_18;
    // 0x8013E340: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_18:
    // 0x8013E344: lh          $t1, -0x3E($s3)
    ctx->r9 = MEM_H(ctx->r19, -0X3E);
    // 0x8013E348: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x8013E34C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8013E350: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8013E354: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8013E358: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x8013E35C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013E360: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8013E364: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8013E368: mul.d       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f24.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f24.d);
    // 0x8013E36C: nop

    // 0x8013E370: mul.s       $f18, $f0, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8013E374: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8013E378: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    // 0x8013E37C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8013E380: swc1        $f10, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f10.u32l;
L_8013E384:
    // 0x8013E384: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8013E388:
    // 0x8013E388: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013E38C: bne         $s2, $at, L_8013E1BC
    if (ctx->r18 != ctx->r1) {
        // 0x8013E390: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_8013E1BC;
    }
    // 0x8013E390: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8013E394: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8013E398: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013E39C: addiu       $t6, $t6, -0x1BFC
    ctx->r14 = ADD32(ctx->r14, -0X1BFC);
    // 0x8013E3A0: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8013E3A4: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8013E3A8: lh          $t8, -0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X4);
    // 0x8013E3AC: lw          $t9, 0x26C($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E3B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E3B4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8013E3B8: lw          $t7, 0x2C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X2C);
    // 0x8013E3BC: addiu       $s0, $zero, -0x800
    ctx->r16 = ADD32(0, -0X800);
    // 0x8013E3C0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013E3C4: swc1        $f18, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f18.u32l;
    // 0x8013E3C8: lh          $t0, -0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X2);
    // 0x8013E3CC: lw          $t1, 0x26C($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E3D0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8013E3D4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8013E3D8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013E3DC: swc1        $f6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f6.u32l;
    // 0x8013E3E0: lwc1        $f16, -0x14C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X14C0);
    // 0x8013E3E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013E3E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013E3EC: lw          $t4, 0x26C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E3F0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E3F4: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8013E3F8: lw          $t3, 0x2C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X2C);
    // 0x8013E3FC: swc1        $f4, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f4.u32l;
    // 0x8013E400: lwc1        $f18, -0x14BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X14BC);
    // 0x8013E404: lw          $t5, 0x26C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E408: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E40C: sub.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x8013E410: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8013E414: swc1        $f8, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f8.u32l;
    // 0x8013E418: lw          $t8, 0x26C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E41C: lwc1        $f6, -0x14B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X14B8);
    // 0x8013E420: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E424: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8013E428: swc1        $f6, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f6.u32l;
    // 0x8013E42C: lw          $t7, 0x26C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E430: lwc1        $f16, -0x14C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X14C0);
    // 0x8013E434: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E438: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x8013E43C: swc1        $f16, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f16.u32l;
    // 0x8013E440: lw          $t1, 0x26C($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E444: lwc1        $f10, -0x14BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X14BC);
    // 0x8013E448: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E44C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8013E450: swc1        $f10, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f10.u32l;
    // 0x8013E454: lw          $t4, 0x26C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E458: lwc1        $f4, -0x14B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14B8);
    // 0x8013E45C: lw          $t3, 0x2C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X2C);
    // 0x8013E460: swc1        $f4, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f4.u32l;
    // 0x8013E464: lh          $t5, 0x0($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X0);
    // 0x8013E468: subu        $a0, $s0, $t5
    ctx->r4 = SUB32(ctx->r16, ctx->r13);
    // 0x8013E46C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8013E470: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E474: jal         0x8001EAD0
    // 0x8013E478: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_19;
    // 0x8013E478: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_19:
    // 0x8013E47C: lw          $t6, 0x26C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E480: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x8013E484: swc1        $f0, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->f0.u32l;
    // 0x8013E488: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8013E48C: subu        $a0, $s0, $t9
    ctx->r4 = SUB32(ctx->r16, ctx->r25);
    // 0x8013E490: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8013E494: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013E498: jal         0x8001EB64
    // 0x8013E49C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_20;
    // 0x8013E49C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_20:
    // 0x8013E4A0: lw          $t7, 0x26C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E4A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8013E4A8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013E4AC: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x8013E4B0: swc1        $f0, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->f0.u32l;
    // 0x8013E4B4: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8013E4B8: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8013E4BC: bnel        $v0, $t1, L_8013E4F8
    if (ctx->r2 != ctx->r9) {
        // 0x8013E4C0: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8013E4F8;
    }
    goto skip_12;
    // 0x8013E4C0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_12:
    // 0x8013E4C4: bnel        $t2, $at, L_8013E4F8
    if (ctx->r10 != ctx->r1) {
        // 0x8013E4C8: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8013E4F8;
    }
    goto skip_13;
    // 0x8013E4C8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_13:
    // 0x8013E4CC: lw          $t4, 0x26C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E4D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8013E4D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013E4D8: lw          $t3, 0x2C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X2C);
    // 0x8013E4DC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8013E4E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013E4E4: swc1        $f18, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f18.u32l;
    // 0x8013E4E8: lw          $t5, 0x26C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E4EC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8013E4F0: swc1        $f8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f8.u32l;
    // 0x8013E4F4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8013E4F8:
    // 0x8013E4F8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8013E4FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8013E500: bnel        $v0, $t8, L_8013E53C
    if (ctx->r2 != ctx->r24) {
        // 0x8013E504: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_14;
    // 0x8013E504: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_14:
    // 0x8013E508: bnel        $t9, $at, L_8013E53C
    if (ctx->r25 != ctx->r1) {
        // 0x8013E50C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8013E53C;
    }
    goto skip_15;
    // 0x8013E50C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_15:
    // 0x8013E510: lw          $t7, 0x26C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E514: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8013E518: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013E51C: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x8013E520: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x8013E524: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013E528: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x8013E52C: lw          $t1, 0x26C($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X26C);
    // 0x8013E530: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8013E534: swc1        $f16, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f16.u32l;
L_8013E538:
    // 0x8013E538: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8013E53C:
    // 0x8013E53C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013E540: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013E544: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8013E548: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8013E54C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8013E550: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8013E554: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8013E558: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8013E55C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8013E560: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8013E564: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8013E568: jr          $ra
    // 0x8013E56C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8013E56C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013e570(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013e570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E570: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013E574: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013E578: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013E57C: addiu       $v0, $v0, -0x1480
    ctx->r2 = ADD32(ctx->r2, -0X1480);
    // 0x8013E580: addiu       $v1, $v1, -0x14B0
    ctx->r3 = ADD32(ctx->r3, -0X14B0);
    // 0x8013E584: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8013E588:
    // 0x8013E588: bnel        $t6, $zero, L_8013E5B0
    if (ctx->r14 != 0) {
        // 0x8013E58C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8013E5B0;
    }
    goto skip_0;
    // 0x8013E58C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_0:
    // 0x8013E590: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x8013E594: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8013E598: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x8013E59C: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x8013E5A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013E5A4: jr          $ra
    // 0x8013E5A8: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    return;
    // 0x8013E5A8: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x8013E5AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8013E5B0:
    // 0x8013E5B0: bnel        $v1, $v0, L_8013E588
    if (ctx->r3 != ctx->r2) {
        // 0x8013E5B4: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8013E588;
    }
    goto skip_1;
    // 0x8013E5B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8013E5B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013E5BC: jr          $ra
    // 0x8013E5C0: nop

    return;
    // 0x8013E5C0: nop

;}
RECOMP_FUNC void M7_FUN_8013e5c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E5C4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013E5C8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013E5CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013E5D0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013E5D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8013E5D8: addiu       $v0, $v0, -0x1480
    ctx->r2 = ADD32(ctx->r2, -0X1480);
    // 0x8013E5DC: addiu       $v1, $v1, -0x14B0
    ctx->r3 = ADD32(ctx->r3, -0X14B0);
    // 0x8013E5E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8013E5E4:
    // 0x8013E5E4: bnel        $a0, $t6, L_8013E608
    if (ctx->r4 != ctx->r14) {
        // 0x8013E5E8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8013E608;
    }
    goto skip_0;
    // 0x8013E5E8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_0:
    // 0x8013E5EC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8013E5F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8013E5F4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8013E5F8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8013E5FC: jr          $ra
    // 0x8013E600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013E600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013E604: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8013E608:
    // 0x8013E608: bnel        $v1, $v0, L_8013E5E4
    if (ctx->r3 != ctx->r2) {
        // 0x8013E60C: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8013E5E4;
    }
    goto skip_1;
    // 0x8013E60C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8013E610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013E614: jr          $ra
    // 0x8013E618: nop

    return;
    // 0x8013E618: nop

;}
RECOMP_FUNC void M7_FUN_8013e61c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E61C: nop

;}
RECOMP_FUNC void M7_FUN_8013e620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013E624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E628: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013E62C: addiu       $a1, $a1, -0x1424
    ctx->r5 = ADD32(ctx->r5, -0X1424);
    // 0x8013E630: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8013E634: jal         0x8014150C
    // 0x8013E638: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_0;
    // 0x8013E638: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8013E63C: bne         $v0, $zero, L_8013E6EC
    if (ctx->r2 != 0) {
        // 0x8013E640: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8013E6EC;
    }
    // 0x8013E640: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013E644: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8013E648: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8013E64C: addiu       $t0, $t0, -0x1408
    ctx->r8 = ADD32(ctx->r8, -0X1408);
    // 0x8013E650: addiu       $a0, $a0, -0x1428
    ctx->r4 = ADD32(ctx->r4, -0X1428);
    // 0x8013E654: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8013E658: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8013E65C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013E660: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
L_8013E664:
    // 0x8013E664: bnel        $a1, $t6, L_8013E6A4
    if (ctx->r5 != ctx->r14) {
        // 0x8013E668: lbu         $t8, 0xC($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0XC);
            goto L_8013E6A4;
    }
    goto skip_0;
    // 0x8013E668: lbu         $t8, 0xC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XC);
    skip_0:
    // 0x8013E66C: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x8013E670: bnel        $a2, $t7, L_8013E6A4
    if (ctx->r6 != ctx->r15) {
        // 0x8013E674: lbu         $t8, 0xC($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0XC);
            goto L_8013E6A4;
    }
    goto skip_1;
    // 0x8013E674: lbu         $t8, 0xC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XC);
    skip_1:
    // 0x8013E678: lbu         $v0, 0xB($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XB);
    // 0x8013E67C: bne         $v0, $zero, L_8013E688
    if (ctx->r2 != 0) {
        // 0x8013E680: nop
    
            goto L_8013E688;
    }
    // 0x8013E680: nop

    // 0x8013E684: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
L_8013E688:
    // 0x8013E688: bne         $a1, $v0, L_8013E694
    if (ctx->r5 != ctx->r2) {
        // 0x8013E68C: nop
    
            goto L_8013E694;
    }
    // 0x8013E68C: nop

    // 0x8013E690: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
L_8013E694:
    // 0x8013E694: bnel        $a3, $v0, L_8013E6A4
    if (ctx->r7 != ctx->r2) {
        // 0x8013E698: lbu         $t8, 0xC($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0XC);
            goto L_8013E6A4;
    }
    goto skip_2;
    // 0x8013E698: lbu         $t8, 0xC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XC);
    skip_2:
    // 0x8013E69C: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x8013E6A0: lbu         $t8, 0xC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XC);
L_8013E6A4:
    // 0x8013E6A4: bnel        $a1, $t8, L_8013E6E4
    if (ctx->r5 != ctx->r24) {
        // 0x8013E6A8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8013E6E4;
    }
    goto skip_3;
    // 0x8013E6A8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    skip_3:
    // 0x8013E6AC: lbu         $t9, 0xE($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XE);
    // 0x8013E6B0: bnel        $a2, $t9, L_8013E6E4
    if (ctx->r6 != ctx->r25) {
        // 0x8013E6B4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8013E6E4;
    }
    goto skip_4;
    // 0x8013E6B4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    skip_4:
    // 0x8013E6B8: lbu         $v0, 0x13($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X13);
    // 0x8013E6BC: bne         $v0, $zero, L_8013E6C8
    if (ctx->r2 != 0) {
        // 0x8013E6C0: nop
    
            goto L_8013E6C8;
    }
    // 0x8013E6C0: nop

    // 0x8013E6C4: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
L_8013E6C8:
    // 0x8013E6C8: bne         $a1, $v0, L_8013E6D4
    if (ctx->r5 != ctx->r2) {
        // 0x8013E6CC: nop
    
            goto L_8013E6D4;
    }
    // 0x8013E6CC: nop

    // 0x8013E6D0: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
L_8013E6D4:
    // 0x8013E6D4: bnel        $a3, $v0, L_8013E6E4
    if (ctx->r7 != ctx->r2) {
        // 0x8013E6D8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8013E6E4;
    }
    goto skip_5;
    // 0x8013E6D8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    skip_5:
    // 0x8013E6DC: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x8013E6E0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_8013E6E4:
    // 0x8013E6E4: bnel        $a0, $t0, L_8013E664
    if (ctx->r4 != ctx->r8) {
        // 0x8013E6E8: lbu         $t6, 0x4($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X4);
            goto L_8013E664;
    }
    goto skip_6;
    // 0x8013E6E8: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    skip_6:
L_8013E6EC:
    // 0x8013E6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E6F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013E6F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013E6F8: jr          $ra
    // 0x8013E6FC: nop

    return;
    // 0x8013E6FC: nop

;}
RECOMP_FUNC void M7_FUN_8013e700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E700: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8013E704: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x8013E708: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x8013E70C: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x8013E710: sb          $zero, 0xD($a0)
    MEM_B(0XD, ctx->r4) = 0;
    // 0x8013E714: sb          $zero, 0xE($a0)
    MEM_B(0XE, ctx->r4) = 0;
    // 0x8013E718: sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // 0x8013E71C: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x8013E720: sb          $zero, 0x12($a0)
    MEM_B(0X12, ctx->r4) = 0;
    // 0x8013E724: sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    // 0x8013E728: sb          $zero, 0x15($a0)
    MEM_B(0X15, ctx->r4) = 0;
    // 0x8013E72C: sb          $zero, 0x16($a0)
    MEM_B(0X16, ctx->r4) = 0;
    // 0x8013E730: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x8013E734: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x8013E738: sb          $zero, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = 0;
    // 0x8013E73C: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
    // 0x8013E740: sb          $zero, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = 0;
    // 0x8013E744: sb          $zero, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = 0;
    // 0x8013E748: sb          $zero, 0x1F($a0)
    MEM_B(0X1F, ctx->r4) = 0;
    // 0x8013E74C: sh          $zero, 0x20($a0)
    MEM_H(0X20, ctx->r4) = 0;
    // 0x8013E750: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    // 0x8013E754: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x8013E758: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x8013E75C: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x8013E760: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x8013E764: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x8013E768: jr          $ra
    // 0x8013E76C: sb          $zero, 0xA($a0)
    MEM_B(0XA, ctx->r4) = 0;
    return;
    // 0x8013E76C: sb          $zero, 0xA($a0)
    MEM_B(0XA, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013e770(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013e770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E778: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013E77C: jal         0x800179B0
    // 0x8013E780: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x8013E780: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
    after_0:
    // 0x8013E784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E78C: jr          $ra
    // 0x8013E790: nop

    return;
    // 0x8013E790: nop

;}
RECOMP_FUNC void M7_FUN_8013e794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E79C: jal         0x800178E8
    // 0x8013E7A0: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x8013E7A0: nop

    after_0:
    // 0x8013E7A4: beq         $v0, $zero, L_8013E7B4
    if (ctx->r2 == 0) {
        // 0x8013E7A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013E7B4;
    }
    // 0x8013E7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E7AC: b           L_8013E7B8
    // 0x8013E7B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013E7B8;
    // 0x8013E7B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013E7B4:
    // 0x8013E7B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013E7B8:
    // 0x8013E7B8: jr          $ra
    // 0x8013E7BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8013E7BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013e7c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013e7c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E7C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E7C4: sb          $zero, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = 0;
    // 0x8013E7C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E7CC: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
    // 0x8013E7D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E7D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013E7D8: sb          $t6, -0x13FE($at)
    MEM_B(-0X13FE, ctx->r1) = ctx->r14;
    // 0x8013E7DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013e7e0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013e7e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E7E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E7E4: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x8013E7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E7EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E7F0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8013E7F4: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
    // 0x8013E7F8: jal         0x8013E700
    // 0x8013E7FC: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    LOOKUP_FUNC(0x8013E700)(rdram, ctx);
        goto after_0;
    // 0x8013E7FC: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    after_0:
    // 0x8013E800: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x8013E804: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x8013E808: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8013E80C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013E810: jal         0x80002364
    // 0x8013E814: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x8013E814: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8013E818: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013E81C: jal         0x800179B0
    // 0x8013E820: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x8013E820: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    after_2:
    // 0x8013E824: jal         0x801426B0
    // 0x8013E828: nop

    LOOKUP_FUNC(0x801426B0)(rdram, ctx);
        goto after_3;
    // 0x8013E828: nop

    after_3:
    // 0x8013E82C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8013E830: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8013E834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013E838: jal         0x8014307C
    // 0x8013E83C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_4;
    // 0x8013E83C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x8013E840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E848: jr          $ra
    // 0x8013E84C: nop

    return;
    // 0x8013E84C: nop

;}
RECOMP_FUNC void M7_FUN_8013e850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E858: jal         0x800178E8
    // 0x8013E85C: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x8013E85C: nop

    after_0:
    // 0x8013E860: bne         $v0, $zero, L_8013E870
    if (ctx->r2 != 0) {
        // 0x8013E864: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_8013E870;
    }
    // 0x8013E864: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013E868: b           L_8013EA44
    // 0x8013E86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013EA44;
    // 0x8013E86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013E870:
    // 0x8013E870: lbu         $t6, -0x13FD($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FD);
    // 0x8013E874: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013E878: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013E87C: bne         $t6, $at, L_8013E8A8
    if (ctx->r14 != ctx->r1) {
        // 0x8013E880: addiu       $v1, $v1, -0x1434
        ctx->r3 = ADD32(ctx->r3, -0X1434);
            goto L_8013E8A8;
    }
    // 0x8013E880: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x8013E884: jal         0x80142FC4
    // 0x8013E888: nop

    LOOKUP_FUNC(0x80142FC4)(rdram, ctx);
        goto after_1;
    // 0x8013E888: nop

    after_1:
    // 0x8013E88C: jal         0x80143B5C
    // 0x8013E890: nop

    LOOKUP_FUNC(0x80143B5C)(rdram, ctx);
        goto after_2;
    // 0x8013E890: nop

    after_2:
    // 0x8013E894: beq         $v0, $zero, L_8013E8A0
    if (ctx->r2 == 0) {
        // 0x8013E898: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8013E8A0;
    }
    // 0x8013E898: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013E89C: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
L_8013E8A0:
    // 0x8013E8A0: b           L_8013EA44
    // 0x8013E8A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013EA44;
    // 0x8013E8A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013E8A8:
    // 0x8013E8A8: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8013E8AC: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x8013E8B0: beq         $at, $zero, L_8013EA40
    if (ctx->r1 == 0) {
        // 0x8013E8B4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8013EA40;
    }
    // 0x8013E8B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8013E8B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013E8BC: addu        $at, $at, $t7
    gpr jr_addend_8013E8C4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8013E8C0: lw          $t7, -0x10F4($at)
    ctx->r15 = ADD32(ctx->r1, -0X10F4);
    // 0x8013E8C4: jr          $t7
    // 0x8013E8C8: nop

    switch (jr_addend_8013E8C4 >> 2) {
        case 0: goto L_8013E8CC; break;
        case 1: goto L_8013E92C; break;
        case 2: goto L_8013E93C; break;
        case 3: goto L_8013E9B8; break;
        case 4: goto L_8013E9E4; break;
        case 5: goto L_8013EA30; break;
        default: switch_error(__func__, 0x8013E8C4, 0x8018EF0C);
    }
    // 0x8013E8C8: nop

L_8013E8CC:
    // 0x8013E8CC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013E8D0: lhu         $v0, -0x40BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40BE);
    // 0x8013E8D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013E8D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013E8DC: bnel        $v0, $zero, L_8013E91C
    if (ctx->r2 != 0) {
        // 0x8013E8E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013E91C;
    }
    goto skip_0;
    // 0x8013E8E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8013E8E4: jal         0x8014150C
    // 0x8013E8E8: addiu       $a1, $a1, -0x147C
    ctx->r5 = ADD32(ctx->r5, -0X147C);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_3;
    // 0x8013E8E8: addiu       $a1, $a1, -0x147C
    ctx->r5 = ADD32(ctx->r5, -0X147C);
    after_3:
    // 0x8013E8EC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8013E8F0: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8013E8F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013E8F8: jal         0x8014307C
    // 0x8013E8FC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_4;
    // 0x8013E8FC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_4:
    // 0x8013E900: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013E904: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x8013E908: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8013E90C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8013E910: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013E914: lhu         $v0, -0x40BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40BE);
    // 0x8013E918: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8013E91C:
    // 0x8013E91C: bne         $v0, $at, L_8013EA40
    if (ctx->r2 != ctx->r1) {
        // 0x8013E920: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8013EA40;
    }
    // 0x8013E920: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013E924: b           L_8013EA40
    // 0x8013E928: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
        goto L_8013EA40;
    // 0x8013E928: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_8013E92C:
    // 0x8013E92C: jal         0x800023A8
    // 0x8013E930: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_5;
    // 0x8013E930: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8013E934: b           L_8013EA44
    // 0x8013E938: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8013EA44;
    // 0x8013E938: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8013E93C:
    // 0x8013E93C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8013E940: lhu         $t0, -0x6B88($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X6B88);
    // 0x8013E944: andi        $t1, $t0, 0xB000
    ctx->r9 = ctx->r8 & 0XB000;
    // 0x8013E948: beq         $t1, $zero, L_8013E98C
    if (ctx->r9 == 0) {
        // 0x8013E94C: nop
    
            goto L_8013E98C;
    }
    // 0x8013E94C: nop

    // 0x8013E950: jal         0x8014115C
    // 0x8013E954: nop

    LOOKUP_FUNC(0x8014115C)(rdram, ctx);
        goto after_6;
    // 0x8013E954: nop

    after_6:
    // 0x8013E958: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013E95C: beq         $v0, $zero, L_8013E978
    if (ctx->r2 == 0) {
        // 0x8013E960: addiu       $v1, $v1, -0x1434
        ctx->r3 = ADD32(ctx->r3, -0X1434);
            goto L_8013E978;
    }
    // 0x8013E960: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x8013E964: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013E968: jal         0x80017990
    // 0x8013E96C: addiu       $a0, $a0, 0x668
    ctx->r4 = ADD32(ctx->r4, 0X668);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_7;
    // 0x8013E96C: addiu       $a0, $a0, 0x668
    ctx->r4 = ADD32(ctx->r4, 0X668);
    after_7:
    // 0x8013E970: b           L_8013E98C
    // 0x8013E974: nop

        goto L_8013E98C;
    // 0x8013E974: nop

L_8013E978:
    // 0x8013E978: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8013E97C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013E980: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x8013E984: jal         0x80017990
    // 0x8013E988: addiu       $a0, $a0, 0x598
    ctx->r4 = ADD32(ctx->r4, 0X598);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_8;
    // 0x8013E988: addiu       $a0, $a0, 0x598
    ctx->r4 = ADD32(ctx->r4, 0X598);
    after_8:
L_8013E98C:
    // 0x8013E98C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8013E990: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8013E994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013E998: jal         0x80140E88
    // 0x8013E99C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80140E88)(rdram, ctx);
        goto after_9;
    // 0x8013E99C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x8013E9A0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013E9A4: lbu         $a1, -0x13FC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FC);
    // 0x8013E9A8: jal         0x80142B28
    // 0x8013E9AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_10;
    // 0x8013E9AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8013E9B0: b           L_8013EA44
    // 0x8013E9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013EA44;
    // 0x8013E9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013E9B8:
    // 0x8013E9B8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013E9BC: lhu         $v0, -0x40BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40BE);
    // 0x8013E9C0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8013E9C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013E9C8: bne         $v0, $zero, L_8013E9D4
    if (ctx->r2 != 0) {
        // 0x8013E9CC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8013E9D4;
    }
    // 0x8013E9CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013E9D0: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_8013E9D4:
    // 0x8013E9D4: bnel        $v0, $at, L_8013EA44
    if (ctx->r2 != ctx->r1) {
        // 0x8013E9D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013EA44;
    }
    goto skip_1;
    // 0x8013E9D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8013E9DC: b           L_8013EA40
    // 0x8013E9E0: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
        goto L_8013EA40;
    // 0x8013E9E0: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_8013E9E4:
    // 0x8013E9E4: jal         0x801411D0
    // 0x8013E9E8: nop

    LOOKUP_FUNC(0x801411D0)(rdram, ctx);
        goto after_11;
    // 0x8013E9E8: nop

    after_11:
    // 0x8013E9EC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013E9F0: bne         $v0, $zero, L_8013EA14
    if (ctx->r2 != 0) {
        // 0x8013E9F4: addiu       $v1, $v1, -0x1434
        ctx->r3 = ADD32(ctx->r3, -0X1434);
            goto L_8013EA14;
    }
    // 0x8013E9F4: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x8013E9F8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8013E9FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013EA00: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8013EA04: jal         0x80017990
    // 0x8013EA08: addiu       $a0, $a0, 0x6E4
    ctx->r4 = ADD32(ctx->r4, 0X6E4);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_12;
    // 0x8013EA08: addiu       $a0, $a0, 0x6E4
    ctx->r4 = ADD32(ctx->r4, 0X6E4);
    after_12:
    // 0x8013EA0C: b           L_8013EA44
    // 0x8013EA10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013EA44;
    // 0x8013EA10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EA14:
    // 0x8013EA14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013EA18: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013EA1C: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8013EA20: jal         0x80017990
    // 0x8013EA24: addiu       $a0, $a0, 0x71C
    ctx->r4 = ADD32(ctx->r4, 0X71C);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_13;
    // 0x8013EA24: addiu       $a0, $a0, 0x71C
    ctx->r4 = ADD32(ctx->r4, 0X71C);
    after_13:
    // 0x8013EA28: b           L_8013EA44
    // 0x8013EA2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013EA44;
    // 0x8013EA2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EA30:
    // 0x8013EA30: jal         0x800023A8
    // 0x8013EA34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_14;
    // 0x8013EA34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8013EA38: b           L_8013EA44
    // 0x8013EA3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013EA44;
    // 0x8013EA3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013EA40:
    // 0x8013EA40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EA44:
    // 0x8013EA44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013EA48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EA4C: jr          $ra
    // 0x8013EA50: nop

    return;
    // 0x8013EA50: nop

;}
RECOMP_FUNC void M7_FUN_8013ea54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EA54: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013EA58: lbu         $t6, -0x13FB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FB);
    // 0x8013EA5C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8013EA60: addiu       $t8, $t8, -0x1480
    ctx->r24 = ADD32(ctx->r24, -0X1480);
    // 0x8013EA64: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8013EA68: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8013EA6C: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x8013EA70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013ea74(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013ea74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EA74: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8013EA78: bnel        $t9, $at, L_8013EA8C
    if (ctx->r25 != ctx->r1) {
        // 0x8013EA7C: lw          $v0, 0x4($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4);
            goto L_8013EA8C;
    }
    goto skip_0;
    // 0x8013EA7C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    skip_0:
    // 0x8013EA80: lbu         $t0, 0x6($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X6);
    // 0x8013EA84: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8013EA88: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
L_8013EA8C:
    // 0x8013EA8C: jr          $ra
    // 0x8013EA90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8013EA90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013ea94(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013ea94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EA94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EA98: sb          $zero, -0x4410($at)
    MEM_B(-0X4410, ctx->r1) = 0;
    // 0x8013EA9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EAA0: sb          $zero, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = 0;
    // 0x8013EAA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EAA8: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
    // 0x8013EAAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EAB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013EAB4: sb          $t6, -0x13FE($at)
    MEM_B(-0X13FE, ctx->r1) = ctx->r14;
    // 0x8013EAB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013eabc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013eabc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EAC0: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x8013EAC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EAC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EACC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8013EAD0: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
    // 0x8013EAD4: jal         0x8013E700
    // 0x8013EAD8: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    LOOKUP_FUNC(0x8013E700)(rdram, ctx);
        goto after_0;
    // 0x8013EAD8: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    after_0:
    // 0x8013EADC: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x8013EAE0: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x8013EAE4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8013EAE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013EAEC: jal         0x80002364
    // 0x8013EAF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x8013EAF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8013EAF4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013EAF8: jal         0x800179B0
    // 0x8013EAFC: addiu       $a0, $a0, 0x79C
    ctx->r4 = ADD32(ctx->r4, 0X79C);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x8013EAFC: addiu       $a0, $a0, 0x79C
    ctx->r4 = ADD32(ctx->r4, 0X79C);
    after_2:
    // 0x8013EB00: jal         0x80142778
    // 0x8013EB04: nop

    LOOKUP_FUNC(0x80142778)(rdram, ctx);
        goto after_3;
    // 0x8013EB04: nop

    after_3:
    // 0x8013EB08: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8013EB0C: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8013EB10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013EB14: jal         0x8014307C
    // 0x8013EB18: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_4;
    // 0x8013EB18: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x8013EB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013EB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EB24: jr          $ra
    // 0x8013EB28: nop

    return;
    // 0x8013EB28: nop

;}
RECOMP_FUNC void M7_FUN_8013eb2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EB2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EB34: jal         0x800178E8
    // 0x8013EB38: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x8013EB38: nop

    after_0:
    // 0x8013EB3C: bne         $v0, $zero, L_8013EB4C
    if (ctx->r2 != 0) {
        // 0x8013EB40: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_8013EB4C;
    }
    // 0x8013EB40: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013EB44: b           L_8013ECD0
    // 0x8013EB48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013ECD0;
    // 0x8013EB48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EB4C:
    // 0x8013EB4C: lbu         $t6, -0x13FD($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FD);
    // 0x8013EB50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8013EB54: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013EB58: bne         $v1, $t6, L_8013EB84
    if (ctx->r3 != ctx->r14) {
        // 0x8013EB5C: nop
    
            goto L_8013EB84;
    }
    // 0x8013EB5C: nop

    // 0x8013EB60: jal         0x80142FC4
    // 0x8013EB64: nop

    LOOKUP_FUNC(0x80142FC4)(rdram, ctx);
        goto after_1;
    // 0x8013EB64: nop

    after_1:
    // 0x8013EB68: jal         0x80143B5C
    // 0x8013EB6C: nop

    LOOKUP_FUNC(0x80143B5C)(rdram, ctx);
        goto after_2;
    // 0x8013EB6C: nop

    after_2:
    // 0x8013EB70: beq         $v0, $zero, L_8013EB7C
    if (ctx->r2 == 0) {
        // 0x8013EB74: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8013EB7C;
    }
    // 0x8013EB74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EB78: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
L_8013EB7C:
    // 0x8013EB7C: b           L_8013ECD0
    // 0x8013EB80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013ECD0;
    // 0x8013EB80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EB84:
    // 0x8013EB84: lbu         $v0, -0x1434($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1434);
    // 0x8013EB88: beq         $v0, $zero, L_8013EBB8
    if (ctx->r2 == 0) {
        // 0x8013EB8C: nop
    
            goto L_8013EBB8;
    }
    // 0x8013EB8C: nop

    // 0x8013EB90: beq         $v0, $v1, L_8013EC18
    if (ctx->r2 == ctx->r3) {
        // 0x8013EB94: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_8013EC18;
    }
    // 0x8013EB94: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8013EB98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013EB9C: beq         $v0, $at, L_8013EC6C
    if (ctx->r2 == ctx->r1) {
        // 0x8013EBA0: lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
            goto L_8013EC6C;
    }
    // 0x8013EBA0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8013EBA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013EBA8: beq         $v0, $at, L_8013ECB4
    if (ctx->r2 == ctx->r1) {
        // 0x8013EBAC: nop
    
            goto L_8013ECB4;
    }
    // 0x8013EBAC: nop

    // 0x8013EBB0: b           L_8013ECD0
    // 0x8013EBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013ECD0;
    // 0x8013EBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EBB8:
    // 0x8013EBB8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013EBBC: lhu         $v0, -0x40BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40BE);
    // 0x8013EBC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013EBC4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013EBC8: bnel        $v0, $zero, L_8013EC04
    if (ctx->r2 != 0) {
        // 0x8013EBCC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013EC04;
    }
    goto skip_0;
    // 0x8013EBCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8013EBD0: jal         0x8014150C
    // 0x8013EBD4: addiu       $a1, $a1, -0x147C
    ctx->r5 = ADD32(ctx->r5, -0X147C);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_3;
    // 0x8013EBD4: addiu       $a1, $a1, -0x147C
    ctx->r5 = ADD32(ctx->r5, -0X147C);
    after_3:
    // 0x8013EBD8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8013EBDC: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8013EBE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013EBE4: jal         0x8014307C
    // 0x8013EBE8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_4;
    // 0x8013EBE8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_4:
    // 0x8013EBEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013EBF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EBF4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013EBF8: lhu         $v0, -0x40BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40BE);
    // 0x8013EBFC: sb          $t7, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r15;
    // 0x8013EC00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8013EC04:
    // 0x8013EC04: bne         $v0, $at, L_8013ECCC
    if (ctx->r2 != ctx->r1) {
        // 0x8013EC08: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_8013ECCC;
    }
    // 0x8013EC08: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8013EC0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EC10: b           L_8013ECCC
    // 0x8013EC14: sb          $t8, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r24;
        goto L_8013ECCC;
    // 0x8013EC14: sb          $t8, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r24;
L_8013EC18:
    // 0x8013EC18: lhu         $t9, -0x6B88($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X6B88);
    // 0x8013EC1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013EC20: andi        $t0, $t9, 0xB000
    ctx->r8 = ctx->r25 & 0XB000;
    // 0x8013EC24: beq         $t0, $zero, L_8013EC40
    if (ctx->r8 == 0) {
        // 0x8013EC28: nop
    
            goto L_8013EC40;
    }
    // 0x8013EC28: nop

    // 0x8013EC2C: jal         0x80017990
    // 0x8013EC30: addiu       $a0, $a0, 0x8E8
    ctx->r4 = ADD32(ctx->r4, 0X8E8);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_5;
    // 0x8013EC30: addiu       $a0, $a0, 0x8E8
    ctx->r4 = ADD32(ctx->r4, 0X8E8);
    after_5:
    // 0x8013EC34: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8013EC38: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EC3C: sb          $t1, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r9;
L_8013EC40:
    // 0x8013EC40: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8013EC44: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8013EC48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013EC4C: jal         0x80140E88
    // 0x8013EC50: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80140E88)(rdram, ctx);
        goto after_6;
    // 0x8013EC50: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x8013EC54: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013EC58: lbu         $a1, -0x13FC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FC);
    // 0x8013EC5C: jal         0x80142B28
    // 0x8013EC60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_7;
    // 0x8013EC60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8013EC64: b           L_8013ECD0
    // 0x8013EC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013ECD0;
    // 0x8013EC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EC6C:
    // 0x8013EC6C: lhu         $t2, -0x40BE($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X40BE);
    // 0x8013EC70: bnel        $t2, $zero, L_8013ECA8
    if (ctx->r10 != 0) {
        // 0x8013EC74: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8013ECA8;
    }
    goto skip_1;
    // 0x8013EC74: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    skip_1:
    // 0x8013EC78: jal         0x80141268
    // 0x8013EC7C: nop

    LOOKUP_FUNC(0x80141268)(rdram, ctx);
        goto after_8;
    // 0x8013EC7C: nop

    after_8:
    // 0x8013EC80: bne         $v0, $zero, L_8013EC9C
    if (ctx->r2 != 0) {
        // 0x8013EC84: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8013EC9C;
    }
    // 0x8013EC84: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013EC88: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013EC8C: jal         0x80017990
    // 0x8013EC90: addiu       $a0, $a0, 0x9CC
    ctx->r4 = ADD32(ctx->r4, 0X9CC);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_9;
    // 0x8013EC90: addiu       $a0, $a0, 0x9CC
    ctx->r4 = ADD32(ctx->r4, 0X9CC);
    after_9:
    // 0x8013EC94: b           L_8013ECA8
    // 0x8013EC98: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
        goto L_8013ECA8;
    // 0x8013EC98: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_8013EC9C:
    // 0x8013EC9C: jal         0x80017990
    // 0x8013ECA0: addiu       $a0, $a0, 0xA04
    ctx->r4 = ADD32(ctx->r4, 0XA04);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_10;
    // 0x8013ECA0: addiu       $a0, $a0, 0xA04
    ctx->r4 = ADD32(ctx->r4, 0XA04);
    after_10:
    // 0x8013ECA4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_8013ECA8:
    // 0x8013ECA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013ECAC: b           L_8013ECCC
    // 0x8013ECB0: sb          $t3, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r11;
        goto L_8013ECCC;
    // 0x8013ECB0: sb          $t3, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r11;
L_8013ECB4:
    // 0x8013ECB4: jal         0x80002A94
    // 0x8013ECB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80002A94)(rdram, ctx);
        goto after_11;
    // 0x8013ECB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8013ECBC: jal         0x800023A8
    // 0x8013ECC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_12;
    // 0x8013ECC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8013ECC4: b           L_8013ECD0
    // 0x8013ECC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013ECD0;
    // 0x8013ECC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013ECCC:
    // 0x8013ECCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013ECD0:
    // 0x8013ECD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013ECD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013ECD8: jr          $ra
    // 0x8013ECDC: nop

    return;
    // 0x8013ECDC: nop

;}
RECOMP_FUNC void M7_FUN_8013ece0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013ECE0: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x8013ECE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013ECE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013ECEC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013ECF0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013ECF4: sw          $a0, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r4;
    // 0x8013ECF8: sw          $a1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r5;
    // 0x8013ECFC: addiu       $t6, $t6, 0x12F0
    ctx->r14 = ADD32(ctx->r14, 0X12F0);
    // 0x8013ED00: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013ED04: addiu       $v0, $sp, 0x190
    ctx->r2 = ADD32(ctx->r29, 0X190);
    // 0x8013ED08: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013ED0C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013ED10: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013ED14: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x8013ED18: addiu       $t9, $t9, 0x1308
    ctx->r25 = ADD32(ctx->r25, 0X1308);
    // 0x8013ED1C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013ED20: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013ED24: addiu       $t3, $t9, 0x15C
    ctx->r11 = ADD32(ctx->r25, 0X15C);
    // 0x8013ED28: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x8013ED2C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8013ED30: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013ED34: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8013ED38: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8013ED3C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8013ED40: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8013ED44: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
L_8013ED48:
    // 0x8013ED48: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8013ED4C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013ED50: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8013ED54: sw          $t1, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r9;
    // 0x8013ED58: lw          $t0, -0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X8);
    // 0x8013ED5C: sw          $t0, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r8;
    // 0x8013ED60: lw          $t1, -0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, -0X4);
    // 0x8013ED64: bne         $t9, $t3, L_8013ED48
    if (ctx->r25 != ctx->r11) {
        // 0x8013ED68: sw          $t1, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r9;
            goto L_8013ED48;
    }
    // 0x8013ED68: sw          $t1, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r9;
    // 0x8013ED6C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8013ED70: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8013ED74: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013ED78: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8013ED7C: lbu         $t4, 0x1AB($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1AB);
    // 0x8013ED80: lbu         $t7, 0x1AF($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1AF);
    // 0x8013ED84: addiu       $a3, $a3, -0x12E4
    ctx->r7 = ADD32(ctx->r7, -0X12E4);
    // 0x8013ED88: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8013ED8C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8013ED90: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8013ED94: addu        $s0, $v0, $t5
    ctx->r16 = ADD32(ctx->r2, ctx->r13);
    // 0x8013ED98: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8013ED9C: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x8013EDA0: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x8013EDA4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8013EDA8: addu        $s1, $v1, $t8
    ctx->r17 = ADD32(ctx->r3, ctx->r24);
    // 0x8013EDAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013EDB0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8013EDB4: jal         0x8001B204
    // 0x8013EDB8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x8013EDB8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_0:
    // 0x8013EDBC: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x8013EDC0: lbu         $a1, 0x4($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4);
    // 0x8013EDC4: lbu         $a2, 0x5($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X5);
    // 0x8013EDC8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8013EDCC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013EDD0: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8013EDD4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013EDD8: addiu       $a3, $a3, -0x12DC
    ctx->r7 = ADD32(ctx->r7, -0X12DC);
    // 0x8013EDDC: jal         0x8001B204
    // 0x8013EDE0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8013EDE0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
    // 0x8013EDE4: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
    // 0x8013EDE8: lbu         $a1, 0x7($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7);
    // 0x8013EDEC: lbu         $a2, 0x8($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X8);
    // 0x8013EDF0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8013EDF4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8013EDF8: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x8013EDFC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013EE00: addiu       $a3, $a3, -0x12D4
    ctx->r7 = ADD32(ctx->r7, -0X12D4);
    // 0x8013EE04: jal         0x8001B204
    // 0x8013EE08: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x8013EE08: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_2:
    // 0x8013EE0C: lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9);
    // 0x8013EE10: lbu         $a1, 0xA($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XA);
    // 0x8013EE14: lbu         $a2, 0xB($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XB);
    // 0x8013EE18: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8013EE1C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8013EE20: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x8013EE24: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013EE28: addiu       $a3, $a3, -0x12CC
    ctx->r7 = ADD32(ctx->r7, -0X12CC);
    // 0x8013EE2C: jal         0x8001B204
    // 0x8013EE30: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x8013EE30: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x8013EE34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013EE38: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013EE3C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8013EE40: jr          $ra
    // 0x8013EE44: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x8013EE44: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013ee48(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013ee48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EE48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013EE4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013EE50: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013EE54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013EE58: bne         $a0, $zero, L_8013EEA8
    if (ctx->r4 != 0) {
        // 0x8013EE5C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8013EEA8;
    }
    // 0x8013EE5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013EE60: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x8013EE64: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013EE68: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8013EE6C: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x8013EE70: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8013EE74: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x8013EE78: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8013EE7C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8013EE80: addiu       $a2, $a2, 0xA7
    ctx->r6 = ADD32(ctx->r6, 0XA7);
    // 0x8013EE84: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8013EE88: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8013EE8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013EE90: addiu       $a3, $a3, -0x12C4
    ctx->r7 = ADD32(ctx->r7, -0X12C4);
    // 0x8013EE94: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8013EE98: jal         0x8001B204
    // 0x8013EE9C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x8013EE9C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_0:
    // 0x8013EEA0: b           L_8013EEEC
    // 0x8013EEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013EEEC;
    // 0x8013EEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013EEA8:
    // 0x8013EEA8: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x8013EEAC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013EEB0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8013EEB4: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x8013EEB8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8013EEBC: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x8013EEC0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8013EEC4: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8013EEC8: addiu       $a2, $a2, 0xA7
    ctx->r6 = ADD32(ctx->r6, 0XA7);
    // 0x8013EECC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8013EED0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8013EED4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8013EED8: addiu       $a3, $a3, -0x12BC
    ctx->r7 = ADD32(ctx->r7, -0X12BC);
    // 0x8013EEDC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8013EEE0: jal         0x8001B204
    // 0x8013EEE4: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8013EEE4: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    after_1:
    // 0x8013EEE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013EEEC:
    // 0x8013EEEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013EEF0: jr          $ra
    // 0x8013EEF4: nop

    return;
    // 0x8013EEF4: nop

;}
RECOMP_FUNC void M7_FUN_8013eef8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EEFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013EF00: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013EF04: bne         $a0, $zero, L_8013EF2C
    if (ctx->r4 != 0) {
        // 0x8013EF08: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8013EF2C;
    }
    // 0x8013EF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EF0C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013EF10: addiu       $a3, $a3, -0x12B4
    ctx->r7 = ADD32(ctx->r7, -0X12B4);
    // 0x8013EF14: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8013EF18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013EF1C: jal         0x8001B204
    // 0x8013EF20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x8013EF20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8013EF24: b           L_8013EF48
    // 0x8013EF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013EF48;
    // 0x8013EF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013EF2C:
    // 0x8013EF2C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013EF30: addiu       $a3, $a3, -0x12B0
    ctx->r7 = ADD32(ctx->r7, -0X12B0);
    // 0x8013EF34: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8013EF38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013EF3C: jal         0x8001B204
    // 0x8013EF40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8013EF40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8013EF44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013EF48:
    // 0x8013EF48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EF4C: jr          $ra
    // 0x8013EF50: nop

    return;
    // 0x8013EF50: nop

;}
RECOMP_FUNC void M7_FUN_8013ef54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EF54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EF58: sb          $zero, -0x1433($at)
    MEM_B(-0X1433, ctx->r1) = 0;
    // 0x8013EF5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EF60: sb          $zero, -0x1401($at)
    MEM_B(-0X1401, ctx->r1) = 0;
    // 0x8013EF64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EF68: sb          $zero, -0x1400($at)
    MEM_B(-0X1400, ctx->r1) = 0;
    // 0x8013EF6C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EF70: sb          $zero, -0x13FF($at)
    MEM_B(-0X13FF, ctx->r1) = 0;
    // 0x8013EF74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EF78: sb          $zero, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = 0;
    // 0x8013EF7C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EF80: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
    // 0x8013EF84: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013ef88(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013ef88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EF8C: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x8013EF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EF94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013EF98: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x8013EF9C: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
    // 0x8013EFA0: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x8013EFA4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8013EFA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013EFAC: jal         0x80002364
    // 0x8013EFB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_0;
    // 0x8013EFB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8013EFB4: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x8013EFB8: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x8013EFBC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8013EFC0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013EFC4: jal         0x80002364
    // 0x8013EFC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x8013EFC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8013EFCC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013EFD0: jal         0x800179B0
    // 0x8013EFD4: addiu       $a0, $a0, 0x12A0
    ctx->r4 = ADD32(ctx->r4, 0X12A0);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x8013EFD4: addiu       $a0, $a0, 0x12A0
    ctx->r4 = ADD32(ctx->r4, 0X12A0);
    after_2:
    // 0x8013EFD8: jal         0x80142840
    // 0x8013EFDC: nop

    LOOKUP_FUNC(0x80142840)(rdram, ctx);
        goto after_3;
    // 0x8013EFDC: nop

    after_3:
    // 0x8013EFE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013EFE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EFE8: jr          $ra
    // 0x8013EFEC: nop

    return;
    // 0x8013EFEC: nop

;}
RECOMP_FUNC void M7_FUN_8013eff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EFF0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8013EFF4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8013EFF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8013EFFC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8013F000: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8013F004: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8013F008: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8013F00C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8013F010: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013F014: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013F018: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013F01C: addiu       $t7, $t7, 0x1468
    ctx->r15 = ADD32(ctx->r15, 0X1468);
    // 0x8013F020: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013F024: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013F028: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x8013F02C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013F030: addiu       $t1, $t1, 0x1470
    ctx->r9 = ADD32(ctx->r9, 0X1470);
    // 0x8013F034: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013F038: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013F03C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8013F040: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8013F044: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x8013F048: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8013F04C: addiu       $t4, $t4, 0x1478
    ctx->r12 = ADD32(ctx->r12, 0X1478);
    // 0x8013F050: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8013F054: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8013F058: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8013F05C: addiu       $s7, $sp, 0x50
    ctx->r23 = ADD32(ctx->r29, 0X50);
    // 0x8013F060: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x8013F064: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8013F068: jal         0x800178E8
    // 0x8013F06C: sw          $t5, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r13;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x8013F06C: sw          $t5, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r13;
    after_0:
    // 0x8013F070: bne         $v0, $zero, L_8013F080
    if (ctx->r2 != 0) {
        // 0x8013F074: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8013F080;
    }
    // 0x8013F074: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8013F078: b           L_80140248
    // 0x8013F07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140248;
    // 0x8013F07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F080:
    // 0x8013F080: lbu         $t7, -0x13FD($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X13FD);
    // 0x8013F084: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013F088: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8013F08C: bne         $t7, $at, L_8013F0B8
    if (ctx->r15 != ctx->r1) {
        // 0x8013F090: nop
    
            goto L_8013F0B8;
    }
    // 0x8013F090: nop

    // 0x8013F094: jal         0x80142F2C
    // 0x8013F098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142F2C)(rdram, ctx);
        goto after_1;
    // 0x8013F098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8013F09C: jal         0x80143B5C
    // 0x8013F0A0: nop

    LOOKUP_FUNC(0x80143B5C)(rdram, ctx);
        goto after_2;
    // 0x8013F0A0: nop

    after_2:
    // 0x8013F0A4: beq         $v0, $zero, L_8013F0B0
    if (ctx->r2 == 0) {
        // 0x8013F0A8: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8013F0B0;
    }
    // 0x8013F0A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013F0AC: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
L_8013F0B0:
    // 0x8013F0B0: b           L_80140248
    // 0x8013F0B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140248;
    // 0x8013F0B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F0B8:
    // 0x8013F0B8: lbu         $t8, -0x1401($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X1401);
    // 0x8013F0BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013F0C0: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8013F0C4: bne         $t8, $at, L_8013F0F0
    if (ctx->r24 != ctx->r1) {
        // 0x8013F0C8: nop
    
            goto L_8013F0F0;
    }
    // 0x8013F0C8: nop

    // 0x8013F0CC: jal         0x80142F2C
    // 0x8013F0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142F2C)(rdram, ctx);
        goto after_3;
    // 0x8013F0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8013F0D4: jal         0x80143B5C
    // 0x8013F0D8: nop

    LOOKUP_FUNC(0x80143B5C)(rdram, ctx);
        goto after_4;
    // 0x8013F0D8: nop

    after_4:
    // 0x8013F0DC: beq         $v0, $zero, L_8013F0E8
    if (ctx->r2 == 0) {
        // 0x8013F0E0: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8013F0E8;
    }
    // 0x8013F0E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013F0E4: sb          $zero, -0x1401($at)
    MEM_B(-0X1401, ctx->r1) = 0;
L_8013F0E8:
    // 0x8013F0E8: b           L_80140248
    // 0x8013F0EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140248;
    // 0x8013F0EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F0F0:
    // 0x8013F0F0: lhu         $t9, -0x6B6C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X6B6C);
    // 0x8013F0F4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8013F0F8: bne         $t9, $zero, L_8013F130
    if (ctx->r25 != 0) {
        // 0x8013F0FC: nop
    
            goto L_8013F130;
    }
    // 0x8013F0FC: nop

    // 0x8013F100: lbu         $t0, -0x1433($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1433);
    // 0x8013F104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013F108: bne         $t0, $zero, L_8013F130
    if (ctx->r8 != 0) {
        // 0x8013F10C: nop
    
            goto L_8013F130;
    }
    // 0x8013F10C: nop

    // 0x8013F110: jal         0x8013ECE0
    // 0x8013F114: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_5;
    // 0x8013F114: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_5:
    // 0x8013F118: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013F11C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013F120: sb          $t1, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r9;
    // 0x8013F124: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013F128: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8013F12C: sb          $t2, -0x1433($at)
    MEM_B(-0X1433, ctx->r1) = ctx->r10;
L_8013F130:
    // 0x8013F130: lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // 0x8013F134: addiu       $s5, $s5, -0x6D50
    ctx->r21 = ADD32(ctx->r21, -0X6D50);
    // 0x8013F138: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8013F13C: lui         $s6, 0x2
    ctx->r22 = S32(0X2 << 16);
L_8013F140:
    // 0x8013F140: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8013F144: lbu         $t3, -0x13FD($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X13FD);
    // 0x8013F148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013F14C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8013F150: beq         $t3, $at, L_8013F16C
    if (ctx->r11 == ctx->r1) {
        // 0x8013F154: nop
    
            goto L_8013F16C;
    }
    // 0x8013F154: nop

    // 0x8013F158: lbu         $t4, -0x1401($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X1401);
    // 0x8013F15C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013F160: sll         $s2, $s3, 2
    ctx->r18 = S32(ctx->r19 << 2);
    // 0x8013F164: bne         $t4, $at, L_8013F174
    if (ctx->r12 != ctx->r1) {
        // 0x8013F168: addiu       $t5, $sp, 0x60
        ctx->r13 = ADD32(ctx->r29, 0X60);
            goto L_8013F174;
    }
    // 0x8013F168: addiu       $t5, $sp, 0x60
    ctx->r13 = ADD32(ctx->r29, 0X60);
L_8013F16C:
    // 0x8013F16C: b           L_80140248
    // 0x8013F170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140248;
    // 0x8013F170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F174:
    // 0x8013F174: addu        $s4, $s2, $t5
    ctx->r20 = ADD32(ctx->r18, ctx->r13);
    // 0x8013F178: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8013F17C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8013F180: slti        $at, $v0, 0xD1
    ctx->r1 = SIGNED(ctx->r2) < 0XD1 ? 1 : 0;
    // 0x8013F184: bne         $at, $zero, L_8013F1A4
    if (ctx->r1 != 0) {
        // 0x8013F188: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_8013F1A4;
    }
    // 0x8013F188: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8013F18C: beq         $v0, $at, L_801401A4
    if (ctx->r2 == ctx->r1) {
        // 0x8013F190: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_801401A4;
    }
    // 0x8013F190: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8013F194: beql        $v0, $at, L_801401A8
    if (ctx->r2 == ctx->r1) {
        // 0x8013F198: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_0;
    // 0x8013F198: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x8013F19C: b           L_801401A8
    // 0x8013F1A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_801401A8;
    // 0x8013F1A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8013F1A4:
    // 0x8013F1A4: slti        $at, $v0, 0x69
    ctx->r1 = SIGNED(ctx->r2) < 0X69 ? 1 : 0;
    // 0x8013F1A8: bne         $at, $zero, L_8013F1D0
    if (ctx->r1 != 0) {
        // 0x8013F1AC: addiu       $t6, $v0, -0xC8
        ctx->r14 = ADD32(ctx->r2, -0XC8);
            goto L_8013F1D0;
    }
    // 0x8013F1AC: addiu       $t6, $v0, -0xC8
    ctx->r14 = ADD32(ctx->r2, -0XC8);
    // 0x8013F1B0: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8013F1B4: beq         $at, $zero, L_801401A4
    if (ctx->r1 == 0) {
        // 0x8013F1B8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801401A4;
    }
    // 0x8013F1B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013F1BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013F1C0: addu        $at, $at, $t6
    gpr jr_addend_8013F1C8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013F1C4: lw          $t6, -0x10DC($at)
    ctx->r14 = ADD32(ctx->r1, -0X10DC);
    // 0x8013F1C8: jr          $t6
    // 0x8013F1CC: nop

    switch (jr_addend_8013F1C8 >> 2) {
        case 0: goto L_8013FD30; break;
        case 1: goto L_8013FDA4; break;
        case 2: goto L_8013FE4C; break;
        case 3: goto L_8013FF80; break;
        case 4: goto L_8013FFB8; break;
        case 5: goto L_80140038; break;
        case 6: goto L_8014008C; break;
        case 7: goto L_8014014C; break;
        case 8: goto L_80140184; break;
        default: switch_error(__func__, 0x8013F1C8, 0x8018EF24);
    }
    // 0x8013F1CC: nop

L_8013F1D0:
    // 0x8013F1D0: slti        $at, $v0, 0x2C
    ctx->r1 = SIGNED(ctx->r2) < 0X2C ? 1 : 0;
    // 0x8013F1D4: bne         $at, $zero, L_8013F1FC
    if (ctx->r1 != 0) {
        // 0x8013F1D8: addiu       $t7, $v0, -0x64
        ctx->r15 = ADD32(ctx->r2, -0X64);
            goto L_8013F1FC;
    }
    // 0x8013F1D8: addiu       $t7, $v0, -0x64
    ctx->r15 = ADD32(ctx->r2, -0X64);
    // 0x8013F1DC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8013F1E0: beq         $at, $zero, L_801401A4
    if (ctx->r1 == 0) {
        // 0x8013F1E4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_801401A4;
    }
    // 0x8013F1E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8013F1E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013F1EC: addu        $at, $at, $t7
    gpr jr_addend_8013F1F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8013F1F0: lw          $t7, -0x10B8($at)
    ctx->r15 = ADD32(ctx->r1, -0X10B8);
    // 0x8013F1F4: jr          $t7
    // 0x8013F1F8: nop

    switch (jr_addend_8013F1F4 >> 2) {
        case 0: goto L_8013FB3C; break;
        case 1: goto L_8013FBC0; break;
        case 2: goto L_8013FC14; break;
        case 3: goto L_8013FCD4; break;
        case 4: goto L_8013FD0C; break;
        default: switch_error(__func__, 0x8013F1F4, 0x8018EF48);
    }
    // 0x8013F1F8: nop

L_8013F1FC:
    // 0x8013F1FC: sltiu       $at, $v0, 0x2C
    ctx->r1 = ctx->r2 < 0X2C ? 1 : 0;
    // 0x8013F200: beq         $at, $zero, L_801401A4
    if (ctx->r1 == 0) {
        // 0x8013F204: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_801401A4;
    }
    // 0x8013F204: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8013F208: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013F20C: addu        $at, $at, $t8
    gpr jr_addend_8013F214 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8013F210: lw          $t8, -0x10A4($at)
    ctx->r24 = ADD32(ctx->r1, -0X10A4);
    // 0x8013F214: jr          $t8
    // 0x8013F218: nop

    switch (jr_addend_8013F214 >> 2) {
        case 0: goto L_8013F21C; break;
        case 1: goto L_8013F348; break;
        case 2: goto L_8013F374; break;
        case 3: goto L_8013F394; break;
        case 4: goto L_8013F3B0; break;
        case 5: goto L_801401A4; break;
        case 6: goto L_801401A4; break;
        case 7: goto L_801401A4; break;
        case 8: goto L_801401A4; break;
        case 9: goto L_801401A4; break;
        case 10: goto L_8013F3B8; break;
        case 11: goto L_8013F40C; break;
        case 12: goto L_8013F4CC; break;
        case 13: goto L_8013F504; break;
        case 14: goto L_801401A4; break;
        case 15: goto L_801401A4; break;
        case 16: goto L_801401A4; break;
        case 17: goto L_801401A4; break;
        case 18: goto L_801401A4; break;
        case 19: goto L_801401A4; break;
        case 20: goto L_8013F528; break;
        case 21: goto L_8013F57C; break;
        case 22: goto L_8013F63C; break;
        case 23: goto L_8013F674; break;
        case 24: goto L_801401A4; break;
        case 25: goto L_801401A4; break;
        case 26: goto L_801401A4; break;
        case 27: goto L_801401A4; break;
        case 28: goto L_801401A4; break;
        case 29: goto L_801401A4; break;
        case 30: goto L_8013F698; break;
        case 31: goto L_8013F6EC; break;
        case 32: goto L_8013F7C0; break;
        case 33: goto L_8013F7E4; break;
        case 34: goto L_8013F8B0; break;
        case 35: goto L_8013F970; break;
        case 36: goto L_8013F9A8; break;
        case 37: goto L_801401A4; break;
        case 38: goto L_801401A4; break;
        case 39: goto L_801401A4; break;
        case 40: goto L_8013F9CC; break;
        case 41: goto L_8013FA20; break;
        case 42: goto L_8013FAE0; break;
        case 43: goto L_8013FB18; break;
        default: switch_error(__func__, 0x8013F214, 0x8018EF5C);
    }
    // 0x8013F218: nop

L_8013F21C:
    // 0x8013F21C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8013F220: addiu       $t0, $t0, 0x12E8
    ctx->r8 = ADD32(ctx->r8, 0X12E8);
    // 0x8013F224: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x8013F228: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F22C: addiu       $t9, $sp, 0x58
    ctx->r25 = ADD32(ctx->r29, 0X58);
    // 0x8013F230: addu        $s0, $s2, $t9
    ctx->r16 = ADD32(ctx->r18, ctx->r25);
    // 0x8013F234: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F238: jal         0x80002BE0
    // 0x8013F23C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_6;
    // 0x8013F23C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    after_6:
    // 0x8013F240: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8013F244: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013F248: sb          $v0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r2;
    // 0x8013F24C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8013F250: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x8013F254: bnel        $v1, $at, L_8013F278
    if (ctx->r3 != ctx->r1) {
        // 0x8013F258: sltiu       $at, $v1, 0x10
        ctx->r1 = ctx->r3 < 0X10 ? 1 : 0;
            goto L_8013F278;
    }
    goto skip_1;
    // 0x8013F258: sltiu       $at, $v1, 0x10
    ctx->r1 = ctx->r3 < 0X10 ? 1 : 0;
    skip_1:
    // 0x8013F25C: jal         0x80002BE0
    // 0x8013F260: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_7;
    // 0x8013F260: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_7:
    // 0x8013F264: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8013F268: sb          $v0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r2;
    // 0x8013F26C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8013F270: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
    // 0x8013F274: sltiu       $at, $v1, 0x10
    ctx->r1 = ctx->r3 < 0X10 ? 1 : 0;
L_8013F278:
    // 0x8013F278: beq         $at, $zero, L_8013F32C
    if (ctx->r1 == 0) {
        // 0x8013F27C: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_8013F32C;
    }
    // 0x8013F27C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8013F280: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013F284: addu        $at, $at, $t6
    gpr jr_addend_8013F28C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013F288: lw          $t6, -0xFF4($at)
    ctx->r14 = ADD32(ctx->r1, -0XFF4);
    // 0x8013F28C: jr          $t6
    // 0x8013F290: nop

    switch (jr_addend_8013F28C >> 2) {
        case 0: goto L_8013F294; break;
        case 1: goto L_8013F2A4; break;
        case 2: goto L_8013F32C; break;
        case 3: goto L_8013F2C0; break;
        case 4: goto L_8013F2DC; break;
        case 5: goto L_8013F2DC; break;
        case 6: goto L_8013F32C; break;
        case 7: goto L_8013F2F8; break;
        case 8: goto L_8013F32C; break;
        case 9: goto L_8013F32C; break;
        case 10: goto L_8013F32C; break;
        case 11: goto L_8013F32C; break;
        case 12: goto L_8013F32C; break;
        case 13: goto L_8013F32C; break;
        case 14: goto L_8013F32C; break;
        case 15: goto L_8013F314; break;
        default: switch_error(__func__, 0x8013F28C, 0x8018F00C);
    }
    // 0x8013F290: nop

L_8013F294:
    // 0x8013F294: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8013F298: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8013F29C: b           L_8013F32C
    // 0x8013F2A0: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
        goto L_8013F32C;
    // 0x8013F2A0: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8013F2A4:
    // 0x8013F2A4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F2A8: jal         0x8013ECE0
    // 0x8013F2AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_8;
    // 0x8013F2AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8013F2B0: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8013F2B4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8013F2B8: b           L_8013F32C
    // 0x8013F2BC: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
        goto L_8013F32C;
    // 0x8013F2BC: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_8013F2C0:
    // 0x8013F2C0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F2C4: jal         0x8013ECE0
    // 0x8013F2C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_9;
    // 0x8013F2C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x8013F2CC: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8013F2D0: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8013F2D4: b           L_8013F32C
    // 0x8013F2D8: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
        goto L_8013F32C;
    // 0x8013F2D8: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
L_8013F2DC:
    // 0x8013F2DC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F2E0: jal         0x8013ECE0
    // 0x8013F2E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_10;
    // 0x8013F2E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x8013F2E8: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8013F2EC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8013F2F0: b           L_8013F32C
    // 0x8013F2F4: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_8013F32C;
    // 0x8013F2F4: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_8013F2F8:
    // 0x8013F2F8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F2FC: jal         0x8013ECE0
    // 0x8013F300: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_11;
    // 0x8013F300: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x8013F304: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8013F308: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8013F30C: b           L_8013F32C
    // 0x8013F310: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_8013F32C;
    // 0x8013F310: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_8013F314:
    // 0x8013F314: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F318: jal         0x8013ECE0
    // 0x8013F31C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_12;
    // 0x8013F31C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
    // 0x8013F320: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8013F324: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8013F328: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8013F32C:
    // 0x8013F32C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8013F330: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F334: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8013F338: jal         0x8014307C
    // 0x8013F33C: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_13;
    // 0x8013F33C: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    after_13:
    // 0x8013F340: b           L_801401A8
    // 0x8013F344: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_801401A8;
    // 0x8013F344: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8013F348:
    // 0x8013F348: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x8013F34C: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x8013F350: addu        $t2, $t1, $s6
    ctx->r10 = ADD32(ctx->r9, ctx->r22);
    // 0x8013F354: lhu         $t3, 0x1C8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X1C8);
    // 0x8013F358: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8013F35C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013F360: andi        $t4, $t3, 0xB000
    ctx->r12 = ctx->r11 & 0XB000;
    // 0x8013F364: beql        $t4, $zero, L_801401A8
    if (ctx->r12 == 0) {
        // 0x8013F368: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_2;
    // 0x8013F368: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x8013F36C: b           L_801401A4
    // 0x8013F370: sb          $t5, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r13;
        goto L_801401A4;
    // 0x8013F370: sb          $t5, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r13;
L_8013F374:
    // 0x8013F374: jal         0x800023A8
    // 0x8013F378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_14;
    // 0x8013F378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8013F37C: jal         0x800023A8
    // 0x8013F380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_15;
    // 0x8013F380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x8013F384: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8013F388: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013F38C: b           L_801401A4
    // 0x8013F390: sb          $t6, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r14;
        goto L_801401A4;
    // 0x8013F390: sb          $t6, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r14;
L_8013F394:
    // 0x8013F394: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013F398: jal         0x80017990
    // 0x8013F39C: addiu       $a0, $a0, 0x12D8
    ctx->r4 = ADD32(ctx->r4, 0X12D8);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_16;
    // 0x8013F39C: addiu       $a0, $a0, 0x12D8
    ctx->r4 = ADD32(ctx->r4, 0X12D8);
    after_16:
    // 0x8013F3A0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8013F3A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013F3A8: b           L_801401A4
    // 0x8013F3AC: sb          $t7, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r15;
        goto L_801401A4;
    // 0x8013F3AC: sb          $t7, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r15;
L_8013F3B0:
    // 0x8013F3B0: b           L_80140248
    // 0x8013F3B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80140248;
    // 0x8013F3B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8013F3B8:
    // 0x8013F3B8: sll         $t8, $s3, 5
    ctx->r24 = S32(ctx->r19 << 5);
    // 0x8013F3BC: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x8013F3C0: addu        $t0, $t9, $s6
    ctx->r8 = ADD32(ctx->r25, ctx->r22);
    // 0x8013F3C4: lhu         $t1, 0x1C8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X1C8);
    // 0x8013F3C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013F3CC: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F3D0: andi        $t2, $t1, 0xB000
    ctx->r10 = ctx->r9 & 0XB000;
    // 0x8013F3D4: beql        $t2, $zero, L_801401A8
    if (ctx->r10 == 0) {
        // 0x8013F3D8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_3;
    // 0x8013F3D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x8013F3DC: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F3E0: jal         0x8013ECE0
    // 0x8013F3E4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_17;
    // 0x8013F3E4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_17:
    // 0x8013F3E8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F3EC: jal         0x8013EE48
    // 0x8013F3F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_18;
    // 0x8013F3F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x8013F3F4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8013F3F8: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x8013F3FC: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x8013F400: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8013F404: b           L_801401A4
    // 0x8013F408: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
        goto L_801401A4;
    // 0x8013F408: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
L_8013F40C:
    // 0x8013F40C: sll         $t6, $s3, 5
    ctx->r14 = S32(ctx->r19 << 5);
    // 0x8013F410: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x8013F414: addu        $s1, $t7, $s6
    ctx->r17 = ADD32(ctx->r15, ctx->r22);
    // 0x8013F418: lhu         $t8, 0x1D0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013F41C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F420: andi        $t9, $t8, 0xC00
    ctx->r25 = ctx->r24 & 0XC00;
    // 0x8013F424: beql        $t9, $zero, L_8013F468
    if (ctx->r25 == 0) {
        // 0x8013F428: lhu         $t5, 0x1C8($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013F468;
    }
    goto skip_4;
    // 0x8013F428: lhu         $t5, 0x1C8($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X1C8);
    skip_4:
    // 0x8013F42C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F430: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F434: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F438: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8013F43C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8013F440: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F444: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F448: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8013F44C: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x8013F450: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8013F454: lbu         $a1, 0x0($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X0);
    // 0x8013F458: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013F45C: jal         0x8013EE48
    // 0x8013F460: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_19;
    // 0x8013F460: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_19:
    // 0x8013F464: lhu         $t5, 0x1C8($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X1C8);
L_8013F468:
    // 0x8013F468: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F46C: andi        $t6, $t5, 0xB000
    ctx->r14 = ctx->r13 & 0XB000;
    // 0x8013F470: beql        $t6, $zero, L_801401A8
    if (ctx->r14 == 0) {
        // 0x8013F474: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_5;
    // 0x8013F474: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_5:
    // 0x8013F478: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F47C: jal         0x8013EEF8
    // 0x8013F480: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_20;
    // 0x8013F480: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_20:
    // 0x8013F484: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8013F488: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013F48C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F490: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8013F494: bne         $t8, $zero, L_8013F4B4
    if (ctx->r24 != 0) {
        // 0x8013F498: nop
    
            goto L_8013F4B4;
    }
    // 0x8013F498: nop

    // 0x8013F49C: jal         0x8013ECE0
    // 0x8013F4A0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_21;
    // 0x8013F4A0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_21:
    // 0x8013F4A4: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8013F4A8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8013F4AC: b           L_801401A4
    // 0x8013F4B0: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
        goto L_801401A4;
    // 0x8013F4B0: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_8013F4B4:
    // 0x8013F4B4: jal         0x8013ECE0
    // 0x8013F4B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_22;
    // 0x8013F4B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_22:
    // 0x8013F4BC: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8013F4C0: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x8013F4C4: b           L_801401A4
    // 0x8013F4C8: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
        goto L_801401A4;
    // 0x8013F4C8: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
L_8013F4CC:
    // 0x8013F4CC: sll         $t3, $s3, 5
    ctx->r11 = S32(ctx->r19 << 5);
    // 0x8013F4D0: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x8013F4D4: addu        $t5, $t4, $s6
    ctx->r13 = ADD32(ctx->r12, ctx->r22);
    // 0x8013F4D8: lhu         $t6, 0x1C8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X1C8);
    // 0x8013F4DC: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F4E0: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x8013F4E4: beql        $t7, $zero, L_801401A8
    if (ctx->r15 == 0) {
        // 0x8013F4E8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_6;
    // 0x8013F4E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_6:
    // 0x8013F4EC: jal         0x8013ECE0
    // 0x8013F4F0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_23;
    // 0x8013F4F0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_23:
    // 0x8013F4F4: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8013F4F8: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x8013F4FC: b           L_801401A4
    // 0x8013F500: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_801401A4;
    // 0x8013F500: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_8013F504:
    // 0x8013F504: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x8013F508: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x8013F50C: addu        $t2, $t1, $s6
    ctx->r10 = ADD32(ctx->r9, ctx->r22);
    // 0x8013F510: lhu         $t3, 0x1C8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X1C8);
    // 0x8013F514: andi        $t4, $t3, 0xB000
    ctx->r12 = ctx->r11 & 0XB000;
    // 0x8013F518: beql        $t4, $zero, L_801401A8
    if (ctx->r12 == 0) {
        // 0x8013F51C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_7;
    // 0x8013F51C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_7:
    // 0x8013F520: b           L_801401A4
    // 0x8013F524: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801401A4;
    // 0x8013F524: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8013F528:
    // 0x8013F528: sll         $t5, $s3, 5
    ctx->r13 = S32(ctx->r19 << 5);
    // 0x8013F52C: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x8013F530: addu        $t7, $t6, $s6
    ctx->r15 = ADD32(ctx->r14, ctx->r22);
    // 0x8013F534: lhu         $t8, 0x1C8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X1C8);
    // 0x8013F538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013F53C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F540: andi        $t9, $t8, 0xB000
    ctx->r25 = ctx->r24 & 0XB000;
    // 0x8013F544: beql        $t9, $zero, L_801401A8
    if (ctx->r25 == 0) {
        // 0x8013F548: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_8;
    // 0x8013F548: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_8:
    // 0x8013F54C: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F550: jal         0x8013ECE0
    // 0x8013F554: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_24;
    // 0x8013F554: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_24:
    // 0x8013F558: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F55C: jal         0x8013EE48
    // 0x8013F560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_25;
    // 0x8013F560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x8013F564: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8013F568: addiu       $t1, $zero, 0x15
    ctx->r9 = ADD32(0, 0X15);
    // 0x8013F56C: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8013F570: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8013F574: b           L_801401A4
    // 0x8013F578: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
        goto L_801401A4;
    // 0x8013F578: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
L_8013F57C:
    // 0x8013F57C: sll         $t3, $s3, 5
    ctx->r11 = S32(ctx->r19 << 5);
    // 0x8013F580: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x8013F584: addu        $s1, $t4, $s6
    ctx->r17 = ADD32(ctx->r12, ctx->r22);
    // 0x8013F588: lhu         $t5, 0x1D0($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013F58C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F590: andi        $t6, $t5, 0xC00
    ctx->r14 = ctx->r13 & 0XC00;
    // 0x8013F594: beql        $t6, $zero, L_8013F5D8
    if (ctx->r14 == 0) {
        // 0x8013F598: lhu         $t2, 0x1C8($s1)
        ctx->r10 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013F5D8;
    }
    goto skip_9;
    // 0x8013F598: lhu         $t2, 0x1C8($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X1C8);
    skip_9:
    // 0x8013F59C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F5A0: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F5A4: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F5A8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8013F5AC: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8013F5B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F5B4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F5B8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8013F5BC: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x8013F5C0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8013F5C4: lbu         $a1, 0x0($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X0);
    // 0x8013F5C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013F5CC: jal         0x8013EE48
    // 0x8013F5D0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_26;
    // 0x8013F5D0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_26:
    // 0x8013F5D4: lhu         $t2, 0x1C8($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X1C8);
L_8013F5D8:
    // 0x8013F5D8: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F5DC: andi        $t3, $t2, 0xB000
    ctx->r11 = ctx->r10 & 0XB000;
    // 0x8013F5E0: beql        $t3, $zero, L_801401A8
    if (ctx->r11 == 0) {
        // 0x8013F5E4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_10;
    // 0x8013F5E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_10:
    // 0x8013F5E8: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F5EC: jal         0x8013EEF8
    // 0x8013F5F0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_27;
    // 0x8013F5F0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_27:
    // 0x8013F5F4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8013F5F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013F5FC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F600: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8013F604: bne         $t5, $zero, L_8013F624
    if (ctx->r13 != 0) {
        // 0x8013F608: nop
    
            goto L_8013F624;
    }
    // 0x8013F608: nop

    // 0x8013F60C: jal         0x8013ECE0
    // 0x8013F610: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_28;
    // 0x8013F610: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_28:
    // 0x8013F614: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8013F618: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x8013F61C: b           L_801401A4
    // 0x8013F620: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
        goto L_801401A4;
    // 0x8013F620: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
L_8013F624:
    // 0x8013F624: jal         0x8013ECE0
    // 0x8013F628: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_29;
    // 0x8013F628: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_29:
    // 0x8013F62C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8013F630: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x8013F634: b           L_801401A4
    // 0x8013F638: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_801401A4;
    // 0x8013F638: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_8013F63C:
    // 0x8013F63C: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x8013F640: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x8013F644: addu        $t2, $t1, $s6
    ctx->r10 = ADD32(ctx->r9, ctx->r22);
    // 0x8013F648: lhu         $t3, 0x1C8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X1C8);
    // 0x8013F64C: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F650: andi        $t4, $t3, 0xB000
    ctx->r12 = ctx->r11 & 0XB000;
    // 0x8013F654: beql        $t4, $zero, L_801401A8
    if (ctx->r12 == 0) {
        // 0x8013F658: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_11;
    // 0x8013F658: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_11:
    // 0x8013F65C: jal         0x8013ECE0
    // 0x8013F660: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_30;
    // 0x8013F660: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_30:
    // 0x8013F664: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8013F668: addiu       $t5, $zero, 0xFE
    ctx->r13 = ADD32(0, 0XFE);
    // 0x8013F66C: b           L_801401A4
    // 0x8013F670: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_801401A4;
    // 0x8013F670: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_8013F674:
    // 0x8013F674: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x8013F678: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8013F67C: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x8013F680: lhu         $t0, 0x1C8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X1C8);
    // 0x8013F684: andi        $t1, $t0, 0xB000
    ctx->r9 = ctx->r8 & 0XB000;
    // 0x8013F688: beql        $t1, $zero, L_801401A8
    if (ctx->r9 == 0) {
        // 0x8013F68C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_12;
    // 0x8013F68C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_12:
    // 0x8013F690: b           L_801401A4
    // 0x8013F694: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801401A4;
    // 0x8013F694: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8013F698:
    // 0x8013F698: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x8013F69C: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x8013F6A0: addu        $t4, $t3, $s6
    ctx->r12 = ADD32(ctx->r11, ctx->r22);
    // 0x8013F6A4: lhu         $t5, 0x1C8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X1C8);
    // 0x8013F6A8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8013F6AC: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F6B0: andi        $t6, $t5, 0xB000
    ctx->r14 = ctx->r13 & 0XB000;
    // 0x8013F6B4: beql        $t6, $zero, L_801401A8
    if (ctx->r14 == 0) {
        // 0x8013F6B8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_13;
    // 0x8013F6B8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_13:
    // 0x8013F6BC: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F6C0: jal         0x8013ECE0
    // 0x8013F6C4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_31;
    // 0x8013F6C4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_31:
    // 0x8013F6C8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F6CC: jal         0x8013EE48
    // 0x8013F6D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_32;
    // 0x8013F6D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x8013F6D4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8013F6D8: addiu       $t8, $zero, 0x1F
    ctx->r24 = ADD32(0, 0X1F);
    // 0x8013F6DC: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8013F6E0: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8013F6E4: b           L_801401A4
    // 0x8013F6E8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_801401A4;
    // 0x8013F6E8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_8013F6EC:
    // 0x8013F6EC: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x8013F6F0: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x8013F6F4: addu        $s1, $t1, $s6
    ctx->r17 = ADD32(ctx->r9, ctx->r22);
    // 0x8013F6F8: lhu         $t2, 0x1D0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013F6FC: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F700: andi        $t3, $t2, 0xC00
    ctx->r11 = ctx->r10 & 0XC00;
    // 0x8013F704: beql        $t3, $zero, L_8013F748
    if (ctx->r11 == 0) {
        // 0x8013F708: lhu         $t9, 0x1C8($s1)
        ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013F748;
    }
    goto skip_14;
    // 0x8013F708: lhu         $t9, 0x1C8($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
    skip_14:
    // 0x8013F70C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F710: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F714: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F718: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8013F71C: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x8013F720: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F724: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F728: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8013F72C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8013F730: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8013F734: lbu         $a1, 0x0($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X0);
    // 0x8013F738: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8013F73C: jal         0x8013EE48
    // 0x8013F740: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_33;
    // 0x8013F740: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_33:
    // 0x8013F744: lhu         $t9, 0x1C8($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
L_8013F748:
    // 0x8013F748: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F74C: andi        $t0, $t9, 0xB000
    ctx->r8 = ctx->r25 & 0XB000;
    // 0x8013F750: beql        $t0, $zero, L_801401A8
    if (ctx->r8 == 0) {
        // 0x8013F754: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_15;
    // 0x8013F754: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_15:
    // 0x8013F758: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F75C: jal         0x8013EEF8
    // 0x8013F760: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_34;
    // 0x8013F760: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_34:
    // 0x8013F764: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8013F768: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8013F76C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F770: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8013F774: bne         $t2, $zero, L_8013F794
    if (ctx->r10 != 0) {
        // 0x8013F778: nop
    
            goto L_8013F794;
    }
    // 0x8013F778: nop

    // 0x8013F77C: jal         0x8013ECE0
    // 0x8013F780: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_35;
    // 0x8013F780: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_35:
    // 0x8013F784: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8013F788: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8013F78C: b           L_801401A4
    // 0x8013F790: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_801401A4;
    // 0x8013F790: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_8013F794:
    // 0x8013F794: jal         0x8013ECE0
    // 0x8013F798: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_36;
    // 0x8013F798: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_36:
    // 0x8013F79C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F7A0: jal         0x8013EE48
    // 0x8013F7A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_37;
    // 0x8013F7A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_37:
    // 0x8013F7A8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8013F7AC: addiu       $t6, $zero, 0x21
    ctx->r14 = ADD32(0, 0X21);
    // 0x8013F7B0: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x8013F7B4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8013F7B8: b           L_801401A4
    // 0x8013F7BC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
        goto L_801401A4;
    // 0x8013F7BC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
L_8013F7C0:
    // 0x8013F7C0: sll         $t8, $s3, 5
    ctx->r24 = S32(ctx->r19 << 5);
    // 0x8013F7C4: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x8013F7C8: addu        $t0, $t9, $s6
    ctx->r8 = ADD32(ctx->r25, ctx->r22);
    // 0x8013F7CC: lhu         $t1, 0x1C8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X1C8);
    // 0x8013F7D0: andi        $t2, $t1, 0xB000
    ctx->r10 = ctx->r9 & 0XB000;
    // 0x8013F7D4: beql        $t2, $zero, L_801401A8
    if (ctx->r10 == 0) {
        // 0x8013F7D8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_16;
    // 0x8013F7D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_16:
    // 0x8013F7DC: b           L_801401A4
    // 0x8013F7E0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801401A4;
    // 0x8013F7E0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8013F7E4:
    // 0x8013F7E4: sll         $t3, $s3, 5
    ctx->r11 = S32(ctx->r19 << 5);
    // 0x8013F7E8: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x8013F7EC: addu        $s1, $t4, $s6
    ctx->r17 = ADD32(ctx->r12, ctx->r22);
    // 0x8013F7F0: lhu         $t5, 0x1D0($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013F7F4: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F7F8: andi        $t6, $t5, 0xC00
    ctx->r14 = ctx->r13 & 0XC00;
    // 0x8013F7FC: beql        $t6, $zero, L_8013F840
    if (ctx->r14 == 0) {
        // 0x8013F800: lhu         $t2, 0x1C8($s1)
        ctx->r10 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013F840;
    }
    goto skip_17;
    // 0x8013F800: lhu         $t2, 0x1C8($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X1C8);
    skip_17:
    // 0x8013F804: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F808: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F80C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F810: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8013F814: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8013F818: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F81C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F820: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8013F824: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x8013F828: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8013F82C: lbu         $a1, 0x0($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X0);
    // 0x8013F830: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8013F834: jal         0x8013EE48
    // 0x8013F838: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_38;
    // 0x8013F838: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_38:
    // 0x8013F83C: lhu         $t2, 0x1C8($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X1C8);
L_8013F840:
    // 0x8013F840: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F844: andi        $t3, $t2, 0xB000
    ctx->r11 = ctx->r10 & 0XB000;
    // 0x8013F848: beql        $t3, $zero, L_801401A8
    if (ctx->r11 == 0) {
        // 0x8013F84C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_18;
    // 0x8013F84C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_18:
    // 0x8013F850: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F854: jal         0x8013EEF8
    // 0x8013F858: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_39;
    // 0x8013F858: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_39:
    // 0x8013F85C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8013F860: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F864: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8013F868: bne         $t5, $zero, L_8013F89C
    if (ctx->r13 != 0) {
        // 0x8013F86C: nop
    
            goto L_8013F89C;
    }
    // 0x8013F86C: nop

    // 0x8013F870: jal         0x8013ECE0
    // 0x8013F874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_40;
    // 0x8013F874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x8013F878: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F87C: jal         0x8013EE48
    // 0x8013F880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_41;
    // 0x8013F880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x8013F884: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8013F888: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x8013F88C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8013F890: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8013F894: b           L_801401A4
    // 0x8013F898: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
        goto L_801401A4;
    // 0x8013F898: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8013F89C:
    // 0x8013F89C: jal         0x80002D00
    // 0x8013F8A0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x80002D00)(rdram, ctx);
        goto after_42;
    // 0x8013F8A0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_42:
    // 0x8013F8A4: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8013F8A8: b           L_801401A4
    // 0x8013F8AC: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
        goto L_801401A4;
    // 0x8013F8AC: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
L_8013F8B0:
    // 0x8013F8B0: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x8013F8B4: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x8013F8B8: addu        $s1, $t1, $s6
    ctx->r17 = ADD32(ctx->r9, ctx->r22);
    // 0x8013F8BC: lhu         $t2, 0x1D0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013F8C0: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F8C4: andi        $t3, $t2, 0xC00
    ctx->r11 = ctx->r10 & 0XC00;
    // 0x8013F8C8: beql        $t3, $zero, L_8013F90C
    if (ctx->r11 == 0) {
        // 0x8013F8CC: lhu         $t9, 0x1C8($s1)
        ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013F90C;
    }
    goto skip_19;
    // 0x8013F8CC: lhu         $t9, 0x1C8($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
    skip_19:
    // 0x8013F8D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F8D4: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F8D8: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F8DC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8013F8E0: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x8013F8E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013F8E8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8013F8EC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8013F8F0: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8013F8F4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8013F8F8: lbu         $a1, 0x0($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X0);
    // 0x8013F8FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013F900: jal         0x8013EE48
    // 0x8013F904: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_43;
    // 0x8013F904: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_43:
    // 0x8013F908: lhu         $t9, 0x1C8($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
L_8013F90C:
    // 0x8013F90C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F910: andi        $t0, $t9, 0xB000
    ctx->r8 = ctx->r25 & 0XB000;
    // 0x8013F914: beql        $t0, $zero, L_801401A8
    if (ctx->r8 == 0) {
        // 0x8013F918: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_20;
    // 0x8013F918: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_20:
    // 0x8013F91C: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F920: jal         0x8013EEF8
    // 0x8013F924: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_44;
    // 0x8013F924: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_44:
    // 0x8013F928: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8013F92C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013F930: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013F934: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8013F938: bne         $t2, $zero, L_8013F958
    if (ctx->r10 != 0) {
        // 0x8013F93C: nop
    
            goto L_8013F958;
    }
    // 0x8013F93C: nop

    // 0x8013F940: jal         0x8013ECE0
    // 0x8013F944: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_45;
    // 0x8013F944: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_45:
    // 0x8013F948: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8013F94C: addiu       $t3, $zero, 0x23
    ctx->r11 = ADD32(0, 0X23);
    // 0x8013F950: b           L_801401A4
    // 0x8013F954: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_801401A4;
    // 0x8013F954: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_8013F958:
    // 0x8013F958: jal         0x8013ECE0
    // 0x8013F95C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_46;
    // 0x8013F95C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_46:
    // 0x8013F960: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8013F964: addiu       $t5, $zero, 0x24
    ctx->r13 = ADD32(0, 0X24);
    // 0x8013F968: b           L_801401A4
    // 0x8013F96C: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_801401A4;
    // 0x8013F96C: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_8013F970:
    // 0x8013F970: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x8013F974: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8013F978: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x8013F97C: lhu         $t0, 0x1C8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X1C8);
    // 0x8013F980: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013F984: andi        $t1, $t0, 0xB000
    ctx->r9 = ctx->r8 & 0XB000;
    // 0x8013F988: beql        $t1, $zero, L_801401A8
    if (ctx->r9 == 0) {
        // 0x8013F98C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_21;
    // 0x8013F98C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_21:
    // 0x8013F990: jal         0x8013ECE0
    // 0x8013F994: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_47;
    // 0x8013F994: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_47:
    // 0x8013F998: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8013F99C: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x8013F9A0: b           L_801401A4
    // 0x8013F9A4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
        goto L_801401A4;
    // 0x8013F9A4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_8013F9A8:
    // 0x8013F9A8: sll         $t4, $s3, 5
    ctx->r12 = S32(ctx->r19 << 5);
    // 0x8013F9AC: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x8013F9B0: addu        $t6, $t5, $s6
    ctx->r14 = ADD32(ctx->r13, ctx->r22);
    // 0x8013F9B4: lhu         $t7, 0x1C8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1C8);
    // 0x8013F9B8: andi        $t8, $t7, 0xB000
    ctx->r24 = ctx->r15 & 0XB000;
    // 0x8013F9BC: beql        $t8, $zero, L_801401A8
    if (ctx->r24 == 0) {
        // 0x8013F9C0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_22;
    // 0x8013F9C0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_22:
    // 0x8013F9C4: b           L_801401A4
    // 0x8013F9C8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801401A4;
    // 0x8013F9C8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8013F9CC:
    // 0x8013F9CC: sll         $t9, $s3, 5
    ctx->r25 = S32(ctx->r19 << 5);
    // 0x8013F9D0: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x8013F9D4: addu        $t1, $t0, $s6
    ctx->r9 = ADD32(ctx->r8, ctx->r22);
    // 0x8013F9D8: lhu         $t2, 0x1C8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1C8);
    // 0x8013F9DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013F9E0: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013F9E4: andi        $t3, $t2, 0xB000
    ctx->r11 = ctx->r10 & 0XB000;
    // 0x8013F9E8: beql        $t3, $zero, L_801401A8
    if (ctx->r11 == 0) {
        // 0x8013F9EC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_23;
    // 0x8013F9EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_23:
    // 0x8013F9F0: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013F9F4: jal         0x8013ECE0
    // 0x8013F9F8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_48;
    // 0x8013F9F8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_48:
    // 0x8013F9FC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FA00: jal         0x8013EE48
    // 0x8013FA04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_49;
    // 0x8013FA04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x8013FA08: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8013FA0C: addiu       $t5, $zero, 0x29
    ctx->r13 = ADD32(0, 0X29);
    // 0x8013FA10: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x8013FA14: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8013FA18: b           L_801401A4
    // 0x8013FA1C: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_801401A4;
    // 0x8013FA1C: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_8013FA20:
    // 0x8013FA20: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x8013FA24: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8013FA28: addu        $s1, $t8, $s6
    ctx->r17 = ADD32(ctx->r24, ctx->r22);
    // 0x8013FA2C: lhu         $t9, 0x1D0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013FA30: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FA34: andi        $t0, $t9, 0xC00
    ctx->r8 = ctx->r25 & 0XC00;
    // 0x8013FA38: beql        $t0, $zero, L_8013FA7C
    if (ctx->r8 == 0) {
        // 0x8013FA3C: lhu         $t6, 0x1C8($s1)
        ctx->r14 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013FA7C;
    }
    goto skip_24;
    // 0x8013FA3C: lhu         $t6, 0x1C8($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X1C8);
    skip_24:
    // 0x8013FA40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013FA44: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013FA48: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8013FA4C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8013FA50: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x8013FA54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013FA58: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8013FA5C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8013FA60: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x8013FA64: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8013FA68: lbu         $a1, 0x0($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X0);
    // 0x8013FA6C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013FA70: jal         0x8013EE48
    // 0x8013FA74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_50;
    // 0x8013FA74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_50:
    // 0x8013FA78: lhu         $t6, 0x1C8($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X1C8);
L_8013FA7C:
    // 0x8013FA7C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FA80: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x8013FA84: beql        $t7, $zero, L_801401A8
    if (ctx->r15 == 0) {
        // 0x8013FA88: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_25;
    // 0x8013FA88: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_25:
    // 0x8013FA8C: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013FA90: jal         0x8013EEF8
    // 0x8013FA94: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_51;
    // 0x8013FA94: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_51:
    // 0x8013FA98: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8013FA9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013FAA0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FAA4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8013FAA8: bne         $t9, $zero, L_8013FAC8
    if (ctx->r25 != 0) {
        // 0x8013FAAC: nop
    
            goto L_8013FAC8;
    }
    // 0x8013FAAC: nop

    // 0x8013FAB0: jal         0x8013ECE0
    // 0x8013FAB4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_52;
    // 0x8013FAB4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_52:
    // 0x8013FAB8: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8013FABC: addiu       $t0, $zero, 0x2A
    ctx->r8 = ADD32(0, 0X2A);
    // 0x8013FAC0: b           L_801401A4
    // 0x8013FAC4: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
        goto L_801401A4;
    // 0x8013FAC4: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
L_8013FAC8:
    // 0x8013FAC8: jal         0x8013ECE0
    // 0x8013FACC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_53;
    // 0x8013FACC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_53:
    // 0x8013FAD0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8013FAD4: addiu       $t2, $zero, 0x2B
    ctx->r10 = ADD32(0, 0X2B);
    // 0x8013FAD8: b           L_801401A4
    // 0x8013FADC: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
        goto L_801401A4;
    // 0x8013FADC: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_8013FAE0:
    // 0x8013FAE0: sll         $t4, $s3, 5
    ctx->r12 = S32(ctx->r19 << 5);
    // 0x8013FAE4: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x8013FAE8: addu        $t6, $t5, $s6
    ctx->r14 = ADD32(ctx->r13, ctx->r22);
    // 0x8013FAEC: lhu         $t7, 0x1C8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1C8);
    // 0x8013FAF0: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013FAF4: andi        $t8, $t7, 0xB000
    ctx->r24 = ctx->r15 & 0XB000;
    // 0x8013FAF8: beql        $t8, $zero, L_801401A8
    if (ctx->r24 == 0) {
        // 0x8013FAFC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_26;
    // 0x8013FAFC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_26:
    // 0x8013FB00: jal         0x8013ECE0
    // 0x8013FB04: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_54;
    // 0x8013FB04: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_54:
    // 0x8013FB08: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8013FB0C: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x8013FB10: b           L_801401A4
    // 0x8013FB14: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
        goto L_801401A4;
    // 0x8013FB14: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_8013FB18:
    // 0x8013FB18: sll         $t1, $s3, 5
    ctx->r9 = S32(ctx->r19 << 5);
    // 0x8013FB1C: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x8013FB20: addu        $t3, $t2, $s6
    ctx->r11 = ADD32(ctx->r10, ctx->r22);
    // 0x8013FB24: lhu         $t4, 0x1C8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X1C8);
    // 0x8013FB28: andi        $t5, $t4, 0xB000
    ctx->r13 = ctx->r12 & 0XB000;
    // 0x8013FB2C: beql        $t5, $zero, L_801401A8
    if (ctx->r13 == 0) {
        // 0x8013FB30: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_27;
    // 0x8013FB30: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_27:
    // 0x8013FB34: b           L_801401A4
    // 0x8013FB38: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801401A4;
    // 0x8013FB38: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8013FB3C:
    // 0x8013FB3C: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013FB40: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FB44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013FB48: jal         0x80002DBC
    // 0x8013FB4C: addiu       $a2, $sp, 0x6B
    ctx->r6 = ADD32(ctx->r29, 0X6B);
    LOOKUP_FUNC(0x80002DBC)(rdram, ctx);
        goto after_55;
    // 0x8013FB4C: addiu       $a2, $sp, 0x6B
    ctx->r6 = ADD32(ctx->r29, 0X6B);
    after_55:
    // 0x8013FB50: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8013FB54: bne         $v0, $at, L_8013FB78
    if (ctx->r2 != ctx->r1) {
        // 0x8013FB58: addiu       $a0, $s3, 0x1
        ctx->r4 = ADD32(ctx->r19, 0X1);
            goto L_8013FB78;
    }
    // 0x8013FB58: addiu       $a0, $s3, 0x1
    ctx->r4 = ADD32(ctx->r19, 0X1);
    // 0x8013FB5C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FB60: jal         0x8013ECE0
    // 0x8013FB64: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_56;
    // 0x8013FB64: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_56:
    // 0x8013FB68: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8013FB6C: addiu       $t6, $zero, 0x65
    ctx->r14 = ADD32(0, 0X65);
    // 0x8013FB70: b           L_801401A4
    // 0x8013FB74: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
        goto L_801401A4;
    // 0x8013FB74: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
L_8013FB78:
    // 0x8013FB78: jal         0x80141934
    // 0x8013FB7C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x80141934)(rdram, ctx);
        goto after_57;
    // 0x8013FB7C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_57:
    // 0x8013FB80: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x8013FB84: bne         $v0, $at, L_8013FBA8
    if (ctx->r2 != ctx->r1) {
        // 0x8013FB88: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_8013FBA8;
    }
    // 0x8013FB88: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FB8C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FB90: jal         0x8013ECE0
    // 0x8013FB94: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_58;
    // 0x8013FB94: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_58:
    // 0x8013FB98: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8013FB9C: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x8013FBA0: b           L_801401A4
    // 0x8013FBA4: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_801401A4;
    // 0x8013FBA4: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_8013FBA8:
    // 0x8013FBA8: jal         0x8013ECE0
    // 0x8013FBAC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_59;
    // 0x8013FBAC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_59:
    // 0x8013FBB0: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8013FBB4: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x8013FBB8: b           L_801401A4
    // 0x8013FBBC: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
        goto L_801401A4;
    // 0x8013FBBC: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
L_8013FBC0:
    // 0x8013FBC0: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x8013FBC4: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x8013FBC8: addu        $t4, $t3, $s6
    ctx->r12 = ADD32(ctx->r11, ctx->r22);
    // 0x8013FBCC: lhu         $t5, 0x1C8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X1C8);
    // 0x8013FBD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013FBD4: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FBD8: andi        $t6, $t5, 0xB000
    ctx->r14 = ctx->r13 & 0XB000;
    // 0x8013FBDC: beql        $t6, $zero, L_801401A8
    if (ctx->r14 == 0) {
        // 0x8013FBE0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_28;
    // 0x8013FBE0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_28:
    // 0x8013FBE4: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013FBE8: jal         0x8013ECE0
    // 0x8013FBEC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_60;
    // 0x8013FBEC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_60:
    // 0x8013FBF0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FBF4: jal         0x8013EE48
    // 0x8013FBF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_61;
    // 0x8013FBF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_61:
    // 0x8013FBFC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8013FC00: addiu       $t8, $zero, 0x66
    ctx->r24 = ADD32(0, 0X66);
    // 0x8013FC04: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8013FC08: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8013FC0C: b           L_801401A4
    // 0x8013FC10: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_801401A4;
    // 0x8013FC10: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_8013FC14:
    // 0x8013FC14: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x8013FC18: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x8013FC1C: addu        $s1, $t1, $s6
    ctx->r17 = ADD32(ctx->r9, ctx->r22);
    // 0x8013FC20: lhu         $t2, 0x1D0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013FC24: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FC28: andi        $t3, $t2, 0xC00
    ctx->r11 = ctx->r10 & 0XC00;
    // 0x8013FC2C: beql        $t3, $zero, L_8013FC70
    if (ctx->r11 == 0) {
        // 0x8013FC30: lhu         $t9, 0x1C8($s1)
        ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013FC70;
    }
    goto skip_29;
    // 0x8013FC30: lhu         $t9, 0x1C8($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
    skip_29:
    // 0x8013FC34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013FC38: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013FC3C: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8013FC40: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8013FC44: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x8013FC48: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013FC4C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8013FC50: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8013FC54: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8013FC58: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8013FC5C: lbu         $a1, 0x0($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X0);
    // 0x8013FC60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013FC64: jal         0x8013EE48
    // 0x8013FC68: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_62;
    // 0x8013FC68: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_62:
    // 0x8013FC6C: lhu         $t9, 0x1C8($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X1C8);
L_8013FC70:
    // 0x8013FC70: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FC74: andi        $t0, $t9, 0xB000
    ctx->r8 = ctx->r25 & 0XB000;
    // 0x8013FC78: beql        $t0, $zero, L_801401A8
    if (ctx->r8 == 0) {
        // 0x8013FC7C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_30;
    // 0x8013FC7C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_30:
    // 0x8013FC80: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013FC84: jal         0x8013EEF8
    // 0x8013FC88: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_63;
    // 0x8013FC88: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_63:
    // 0x8013FC8C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8013FC90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013FC94: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FC98: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8013FC9C: bne         $t2, $zero, L_8013FCBC
    if (ctx->r10 != 0) {
        // 0x8013FCA0: nop
    
            goto L_8013FCBC;
    }
    // 0x8013FCA0: nop

    // 0x8013FCA4: jal         0x8013ECE0
    // 0x8013FCA8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_64;
    // 0x8013FCA8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_64:
    // 0x8013FCAC: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8013FCB0: addiu       $t3, $zero, 0x67
    ctx->r11 = ADD32(0, 0X67);
    // 0x8013FCB4: b           L_801401A4
    // 0x8013FCB8: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_801401A4;
    // 0x8013FCB8: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_8013FCBC:
    // 0x8013FCBC: jal         0x8013ECE0
    // 0x8013FCC0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_65;
    // 0x8013FCC0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_65:
    // 0x8013FCC4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8013FCC8: addiu       $t5, $zero, 0x68
    ctx->r13 = ADD32(0, 0X68);
    // 0x8013FCCC: b           L_801401A4
    // 0x8013FCD0: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_801401A4;
    // 0x8013FCD0: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_8013FCD4:
    // 0x8013FCD4: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x8013FCD8: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8013FCDC: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x8013FCE0: lhu         $t0, 0x1C8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X1C8);
    // 0x8013FCE4: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013FCE8: andi        $t1, $t0, 0xB000
    ctx->r9 = ctx->r8 & 0XB000;
    // 0x8013FCEC: beql        $t1, $zero, L_801401A8
    if (ctx->r9 == 0) {
        // 0x8013FCF0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_31;
    // 0x8013FCF0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_31:
    // 0x8013FCF4: jal         0x8013ECE0
    // 0x8013FCF8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_66;
    // 0x8013FCF8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_66:
    // 0x8013FCFC: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8013FD00: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x8013FD04: b           L_801401A4
    // 0x8013FD08: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
        goto L_801401A4;
    // 0x8013FD08: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_8013FD0C:
    // 0x8013FD0C: sll         $t4, $s3, 5
    ctx->r12 = S32(ctx->r19 << 5);
    // 0x8013FD10: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x8013FD14: addu        $t6, $t5, $s6
    ctx->r14 = ADD32(ctx->r13, ctx->r22);
    // 0x8013FD18: lhu         $t7, 0x1C8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1C8);
    // 0x8013FD1C: andi        $t8, $t7, 0xB000
    ctx->r24 = ctx->r15 & 0XB000;
    // 0x8013FD20: beql        $t8, $zero, L_801401A8
    if (ctx->r24 == 0) {
        // 0x8013FD24: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_32;
    // 0x8013FD24: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_32:
    // 0x8013FD28: b           L_801401A4
    // 0x8013FD2C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801401A4;
    // 0x8013FD2C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8013FD30:
    // 0x8013FD30: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013FD34: addiu       $t9, $t9, 0x12E8
    ctx->r25 = ADD32(ctx->r25, 0X12E8);
    // 0x8013FD38: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8013FD3C: bne         $s3, $zero, L_8013FD58
    if (ctx->r19 != 0) {
        // 0x8013FD40: sw          $t0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r8;
            goto L_8013FD58;
    }
    // 0x8013FD40: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8013FD44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013FD48: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x8013FD4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013FD50: b           L_8013FD68
    // 0x8013FD54: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
        goto L_8013FD68;
    // 0x8013FD54: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
L_8013FD58:
    // 0x8013FD58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013FD5C: sb          $zero, -0x1400($at)
    MEM_B(-0X1400, ctx->r1) = 0;
    // 0x8013FD60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013FD64: sb          $zero, -0x13FF($at)
    MEM_B(-0X13FF, ctx->r1) = 0;
L_8013FD68:
    // 0x8013FD68: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8013FD6C: addiu       $a0, $s3, 0x1
    ctx->r4 = ADD32(ctx->r19, 0X1);
    // 0x8013FD70: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013FD74: jal         0x8014150C
    // 0x8013FD78: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_67;
    // 0x8013FD78: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    after_67:
    // 0x8013FD7C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8013FD80: sb          $v0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r2;
    // 0x8013FD84: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013FD88: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8013FD8C: jal         0x8014307C
    // 0x8013FD90: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_68;
    // 0x8013FD90: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    after_68:
    // 0x8013FD94: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8013FD98: addiu       $t3, $zero, 0xC9
    ctx->r11 = ADD32(0, 0XC9);
    // 0x8013FD9C: b           L_801401A4
    // 0x8013FDA0: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_801401A4;
    // 0x8013FDA0: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_8013FDA4:
    // 0x8013FDA4: sll         $t5, $s3, 5
    ctx->r13 = S32(ctx->r19 << 5);
    // 0x8013FDA8: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x8013FDAC: bne         $s3, $zero, L_8013FDE0
    if (ctx->r19 != 0) {
        // 0x8013FDB0: addu        $s1, $t6, $s6
        ctx->r17 = ADD32(ctx->r14, ctx->r22);
            goto L_8013FDE0;
    }
    // 0x8013FDB0: addu        $s1, $t6, $s6
    ctx->r17 = ADD32(ctx->r14, ctx->r22);
    // 0x8013FDB4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8013FDB8: lw          $a2, 0x12E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X12E8);
    // 0x8013FDBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013FDC0: jal         0x80140E88
    // 0x8013FDC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80140E88)(rdram, ctx);
        goto after_69;
    // 0x8013FDC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_69:
    // 0x8013FDC8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013FDCC: lbu         $a1, -0x13FC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FC);
    // 0x8013FDD0: jal         0x80142B28
    // 0x8013FDD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_70;
    // 0x8013FDD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_70:
    // 0x8013FDD8: b           L_8013FE08
    // 0x8013FDDC: lhu         $t7, 0x1C8($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X1C8);
        goto L_8013FE08;
    // 0x8013FDDC: lhu         $t7, 0x1C8($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X1C8);
L_8013FDE0:
    // 0x8013FDE0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8013FDE4: lw          $a2, 0x12EC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X12EC);
    // 0x8013FDE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013FDEC: jal         0x80140FC8
    // 0x8013FDF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80140FC8)(rdram, ctx);
        goto after_71;
    // 0x8013FDF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_71:
    // 0x8013FDF4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013FDF8: lbu         $a1, -0x1400($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1400);
    // 0x8013FDFC: jal         0x80142B28
    // 0x8013FE00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_72;
    // 0x8013FE00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_72:
    // 0x8013FE04: lhu         $t7, 0x1C8($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X1C8);
L_8013FE08:
    // 0x8013FE08: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x8013FE0C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FE10: andi        $t8, $t7, 0xB000
    ctx->r24 = ctx->r15 & 0XB000;
    // 0x8013FE14: beql        $t8, $zero, L_801401A8
    if (ctx->r24 == 0) {
        // 0x8013FE18: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_33;
    // 0x8013FE18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_33:
    // 0x8013FE1C: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013FE20: jal         0x8013ECE0
    // 0x8013FE24: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_73;
    // 0x8013FE24: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_73:
    // 0x8013FE28: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FE2C: jal         0x8013EE48
    // 0x8013FE30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_74;
    // 0x8013FE30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_74:
    // 0x8013FE34: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8013FE38: addiu       $t0, $zero, 0xCA
    ctx->r8 = ADD32(0, 0XCA);
    // 0x8013FE3C: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8013FE40: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8013FE44: b           L_801401A4
    // 0x8013FE48: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
        goto L_801401A4;
    // 0x8013FE48: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
L_8013FE4C:
    // 0x8013FE4C: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x8013FE50: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x8013FE54: addu        $s1, $t3, $s6
    ctx->r17 = ADD32(ctx->r11, ctx->r22);
    // 0x8013FE58: lhu         $t4, 0x1D0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8013FE5C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FE60: andi        $t5, $t4, 0xC00
    ctx->r13 = ctx->r12 & 0XC00;
    // 0x8013FE64: beql        $t5, $zero, L_8013FEA8
    if (ctx->r13 == 0) {
        // 0x8013FE68: lhu         $t1, 0x1C8($s1)
        ctx->r9 = MEM_HU(ctx->r17, 0X1C8);
            goto L_8013FEA8;
    }
    goto skip_34;
    // 0x8013FE68: lhu         $t1, 0x1C8($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X1C8);
    skip_34:
    // 0x8013FE6C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013FE70: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013FE74: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8013FE78: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013FE7C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8013FE80: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013FE84: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8013FE88: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8013FE8C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8013FE90: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8013FE94: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x8013FE98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013FE9C: jal         0x8013EE48
    // 0x8013FEA0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_75;
    // 0x8013FEA0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_75:
    // 0x8013FEA4: lhu         $t1, 0x1C8($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X1C8);
L_8013FEA8:
    // 0x8013FEA8: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x8013FEAC: andi        $t2, $t1, 0xB000
    ctx->r10 = ctx->r9 & 0XB000;
    // 0x8013FEB0: beql        $t2, $zero, L_801401A8
    if (ctx->r10 == 0) {
        // 0x8013FEB4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_35;
    // 0x8013FEB4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_35:
    // 0x8013FEB8: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013FEBC: jal         0x8013EEF8
    // 0x8013FEC0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_76;
    // 0x8013FEC0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_76:
    // 0x8013FEC4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8013FEC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013FECC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FED0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8013FED4: bnel        $t4, $at, L_8013FEF8
    if (ctx->r12 != ctx->r1) {
        // 0x8013FED8: lw          $t8, 0x0($s4)
        ctx->r24 = MEM_W(ctx->r20, 0X0);
            goto L_8013FEF8;
    }
    goto skip_36;
    // 0x8013FED8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    skip_36:
    // 0x8013FEDC: jal         0x8013ECE0
    // 0x8013FEE0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_77;
    // 0x8013FEE0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_77:
    // 0x8013FEE4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8013FEE8: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x8013FEEC: b           L_801401A4
    // 0x8013FEF0: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_801401A4;
    // 0x8013FEF0: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8013FEF4: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
L_8013FEF8:
    // 0x8013FEF8: addiu       $t7, $zero, 0xCC
    ctx->r15 = ADD32(0, 0XCC);
    // 0x8013FEFC: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8013FF00: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8013FF04: lbu         $t9, -0x13FB($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X13FB);
    // 0x8013FF08: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8013FF0C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8013FF10: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8013FF14: lbu         $t1, -0x147C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X147C);
    // 0x8013FF18: bne         $t1, $zero, L_8013FF3C
    if (ctx->r9 != 0) {
        // 0x8013FF1C: nop
    
            goto L_8013FF3C;
    }
    // 0x8013FF1C: nop

    // 0x8013FF20: bne         $s3, $zero, L_8013FF3C
    if (ctx->r19 != 0) {
        // 0x8013FF24: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_8013FF3C;
    }
    // 0x8013FF24: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FF28: jal         0x8013ECE0
    // 0x8013FF2C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_78;
    // 0x8013FF2C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_78:
    // 0x8013FF30: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8013FF34: addiu       $t2, $zero, 0xCB
    ctx->r10 = ADD32(0, 0XCB);
    // 0x8013FF38: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_8013FF3C:
    // 0x8013FF3C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8013FF40: lbu         $t4, -0x13FF($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X13FF);
    // 0x8013FF44: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013FF48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013FF4C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8013FF50: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8013FF54: lbu         $t6, -0x1454($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1454);
    // 0x8013FF58: bnel        $t6, $zero, L_801401A8
    if (ctx->r14 != 0) {
        // 0x8013FF5C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_37;
    // 0x8013FF5C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_37:
    // 0x8013FF60: bne         $s3, $at, L_801401A4
    if (ctx->r19 != ctx->r1) {
        // 0x8013FF64: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_801401A4;
    }
    // 0x8013FF64: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FF68: jal         0x8013ECE0
    // 0x8013FF6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_79;
    // 0x8013FF6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_79:
    // 0x8013FF70: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8013FF74: addiu       $t7, $zero, 0xCB
    ctx->r15 = ADD32(0, 0XCB);
    // 0x8013FF78: b           L_801401A4
    // 0x8013FF7C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
        goto L_801401A4;
    // 0x8013FF7C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8013FF80:
    // 0x8013FF80: sll         $t9, $s3, 5
    ctx->r25 = S32(ctx->r19 << 5);
    // 0x8013FF84: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x8013FF88: addu        $t1, $t0, $s6
    ctx->r9 = ADD32(ctx->r8, ctx->r22);
    // 0x8013FF8C: lhu         $t2, 0x1C8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1C8);
    // 0x8013FF90: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8013FF94: andi        $t3, $t2, 0xB000
    ctx->r11 = ctx->r10 & 0XB000;
    // 0x8013FF98: beql        $t3, $zero, L_801401A8
    if (ctx->r11 == 0) {
        // 0x8013FF9C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_38;
    // 0x8013FF9C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_38:
    // 0x8013FFA0: jal         0x8013ECE0
    // 0x8013FFA4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_80;
    // 0x8013FFA4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_80:
    // 0x8013FFA8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8013FFAC: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x8013FFB0: b           L_801401A4
    // 0x8013FFB4: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
        goto L_801401A4;
    // 0x8013FFB4: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
L_8013FFB8:
    // 0x8013FFB8: bne         $s3, $zero, L_8013FFE0
    if (ctx->r19 != 0) {
        // 0x8013FFBC: andi        $s1, $s3, 0xFF
        ctx->r17 = ctx->r19 & 0XFF;
            goto L_8013FFE0;
    }
    // 0x8013FFBC: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x8013FFC0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013FFC4: lbu         $a1, -0x13FB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FB);
    // 0x8013FFC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013FFCC: jal         0x801424D0
    // 0x8013FFD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801424D0)(rdram, ctx);
        goto after_81;
    // 0x8013FFD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_81:
    // 0x8013FFD4: sb          $v0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r2;
    // 0x8013FFD8: b           L_8013FFF8
    // 0x8013FFDC: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
        goto L_8013FFF8;
    // 0x8013FFDC: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
L_8013FFE0:
    // 0x8013FFE0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013FFE4: lbu         $a1, -0x13FF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FF);
    // 0x8013FFE8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8013FFEC: jal         0x801424D0
    // 0x8013FFF0: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801424D0)(rdram, ctx);
        goto after_82;
    // 0x8013FFF0: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_82:
    // 0x8013FFF4: sb          $v0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r2;
L_8013FFF8:
    // 0x8013FFF8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8013FFFC: bne         $t6, $zero, L_80140020
    if (ctx->r14 != 0) {
        // 0x80140000: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_80140020;
    }
    // 0x80140000: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80140004: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80140008: jal         0x8013ECE0
    // 0x8014000C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_83;
    // 0x8014000C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_83:
    // 0x80140010: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80140014: addiu       $t7, $zero, 0xCF
    ctx->r15 = ADD32(0, 0XCF);
    // 0x80140018: b           L_801401A4
    // 0x8014001C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
        goto L_801401A4;
    // 0x8014001C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_80140020:
    // 0x80140020: jal         0x8013ECE0
    // 0x80140024: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_84;
    // 0x80140024: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_84:
    // 0x80140028: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8014002C: addiu       $t9, $zero, 0xCD
    ctx->r25 = ADD32(0, 0XCD);
    // 0x80140030: b           L_801401A4
    // 0x80140034: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
        goto L_801401A4;
    // 0x80140034: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_80140038:
    // 0x80140038: sll         $t1, $s3, 5
    ctx->r9 = S32(ctx->r19 << 5);
    // 0x8014003C: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x80140040: addu        $t3, $t2, $s6
    ctx->r11 = ADD32(ctx->r10, ctx->r22);
    // 0x80140044: lhu         $t4, 0x1C8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X1C8);
    // 0x80140048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014004C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x80140050: andi        $t5, $t4, 0xB000
    ctx->r13 = ctx->r12 & 0XB000;
    // 0x80140054: beql        $t5, $zero, L_801401A8
    if (ctx->r13 == 0) {
        // 0x80140058: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_39;
    // 0x80140058: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_39:
    // 0x8014005C: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x80140060: jal         0x8013ECE0
    // 0x80140064: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_85;
    // 0x80140064: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_85:
    // 0x80140068: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8014006C: jal         0x8013EE48
    // 0x80140070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_86;
    // 0x80140070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_86:
    // 0x80140074: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80140078: addiu       $t7, $zero, 0xCE
    ctx->r15 = ADD32(0, 0XCE);
    // 0x8014007C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80140080: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80140084: b           L_801401A4
    // 0x80140088: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
        goto L_801401A4;
    // 0x80140088: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8014008C:
    // 0x8014008C: sll         $t9, $s3, 5
    ctx->r25 = S32(ctx->r19 << 5);
    // 0x80140090: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x80140094: addu        $s1, $t0, $s6
    ctx->r17 = ADD32(ctx->r8, ctx->r22);
    // 0x80140098: lhu         $t1, 0x1D0($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X1D0);
    // 0x8014009C: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x801400A0: andi        $t2, $t1, 0xC00
    ctx->r10 = ctx->r9 & 0XC00;
    // 0x801400A4: beql        $t2, $zero, L_801400E8
    if (ctx->r10 == 0) {
        // 0x801400A8: lhu         $t8, 0x1C8($s1)
        ctx->r24 = MEM_HU(ctx->r17, 0X1C8);
            goto L_801400E8;
    }
    goto skip_40;
    // 0x801400A8: lhu         $t8, 0x1C8($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X1C8);
    skip_40:
    // 0x801400AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801400B0: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x801400B4: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x801400B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801400BC: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x801400C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801400C4: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x801400C8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x801400CC: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x801400D0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801400D4: lbu         $a1, 0x0($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X0);
    // 0x801400D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801400DC: jal         0x8013EE48
    // 0x801400E0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013EE48)(rdram, ctx);
        goto after_87;
    // 0x801400E0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_87:
    // 0x801400E4: lhu         $t8, 0x1C8($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X1C8);
L_801400E8:
    // 0x801400E8: addu        $s0, $s7, $s2
    ctx->r16 = ADD32(ctx->r23, ctx->r18);
    // 0x801400EC: andi        $t9, $t8, 0xB000
    ctx->r25 = ctx->r24 & 0XB000;
    // 0x801400F0: beql        $t9, $zero, L_801401A8
    if (ctx->r25 == 0) {
        // 0x801400F4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_41;
    // 0x801400F4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_41:
    // 0x801400F8: andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // 0x801400FC: jal         0x8013EEF8
    // 0x80140100: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013EEF8)(rdram, ctx);
        goto after_88;
    // 0x80140100: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_88:
    // 0x80140104: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80140108: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8014010C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80140110: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80140114: bne         $t1, $zero, L_80140134
    if (ctx->r9 != 0) {
        // 0x80140118: nop
    
            goto L_80140134;
    }
    // 0x80140118: nop

    // 0x8014011C: jal         0x8013ECE0
    // 0x80140120: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_89;
    // 0x80140120: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_89:
    // 0x80140124: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80140128: addiu       $t2, $zero, 0xCF
    ctx->r10 = ADD32(0, 0XCF);
    // 0x8014012C: b           L_801401A4
    // 0x80140130: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
        goto L_801401A4;
    // 0x80140130: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_80140134:
    // 0x80140134: jal         0x8013ECE0
    // 0x80140138: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_90;
    // 0x80140138: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_90:
    // 0x8014013C: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80140140: addiu       $t4, $zero, 0xD0
    ctx->r12 = ADD32(0, 0XD0);
    // 0x80140144: b           L_801401A4
    // 0x80140148: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
        goto L_801401A4;
    // 0x80140148: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
L_8014014C:
    // 0x8014014C: sll         $t6, $s3, 5
    ctx->r14 = S32(ctx->r19 << 5);
    // 0x80140150: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80140154: addu        $t8, $t7, $s6
    ctx->r24 = ADD32(ctx->r15, ctx->r22);
    // 0x80140158: lhu         $t9, 0x1C8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1C8);
    // 0x8014015C: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x80140160: andi        $t0, $t9, 0xB000
    ctx->r8 = ctx->r25 & 0XB000;
    // 0x80140164: beql        $t0, $zero, L_801401A8
    if (ctx->r8 == 0) {
        // 0x80140168: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_42;
    // 0x80140168: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_42:
    // 0x8014016C: jal         0x8013ECE0
    // 0x80140170: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_91;
    // 0x80140170: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_91:
    // 0x80140174: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80140178: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x8014017C: b           L_801401A4
    // 0x80140180: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
        goto L_801401A4;
    // 0x80140180: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
L_80140184:
    // 0x80140184: sll         $t3, $s3, 5
    ctx->r11 = S32(ctx->r19 << 5);
    // 0x80140188: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x8014018C: addu        $t5, $t4, $s6
    ctx->r13 = ADD32(ctx->r12, ctx->r22);
    // 0x80140190: lhu         $t6, 0x1C8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X1C8);
    // 0x80140194: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x80140198: beql        $t7, $zero, L_801401A8
    if (ctx->r15 == 0) {
        // 0x8014019C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801401A8;
    }
    goto skip_43;
    // 0x8014019C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_43:
    // 0x801401A0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801401A4:
    // 0x801401A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_801401A8:
    // 0x801401A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801401AC: bne         $s3, $at, L_8013F140
    if (ctx->r19 != ctx->r1) {
        // 0x801401B0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8013F140;
    }
    // 0x801401B0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801401B4: lbu         $v0, -0x1433($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1433);
    // 0x801401B8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801401BC: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801401C0: bnel        $v0, $at, L_801401F4
    if (ctx->r2 != ctx->r1) {
        // 0x801401C4: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_801401F4;
    }
    goto skip_44;
    // 0x801401C4: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    skip_44:
    // 0x801401C8: lbu         $t8, -0x1434($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X1434);
    // 0x801401CC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801401D0: bnel        $t8, $at, L_801401F4
    if (ctx->r24 != ctx->r1) {
        // 0x801401D4: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_801401F4;
    }
    goto skip_45;
    // 0x801401D4: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    skip_45:
    // 0x801401D8: jal         0x800023A8
    // 0x801401DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_92;
    // 0x801401DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_92:
    // 0x801401E0: jal         0x800023A8
    // 0x801401E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_93;
    // 0x801401E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_93:
    // 0x801401E8: b           L_80140248
    // 0x801401EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140248;
    // 0x801401EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801401F0: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
L_801401F4:
    // 0x801401F4: bne         $v0, $at, L_80140244
    if (ctx->r2 != ctx->r1) {
        // 0x801401F8: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_80140244;
    }
    // 0x801401F8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801401FC: lbu         $t9, -0x1434($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1434);
    // 0x80140200: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80140204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140208: bnel        $t9, $at, L_80140248
    if (ctx->r25 != ctx->r1) {
        // 0x8014020C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80140248;
    }
    goto skip_46;
    // 0x8014020C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_46:
    // 0x80140210: jal         0x8013ECE0
    // 0x80140214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_94;
    // 0x80140214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_94:
    // 0x80140218: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x8014021C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140220: sb          $s0, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r16;
    // 0x80140224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80140228: jal         0x8013ECE0
    // 0x8014022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013ECE0)(rdram, ctx);
        goto after_95;
    // 0x8014022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_95:
    // 0x80140230: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140234: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140238: sb          $s0, -0x1433($at)
    MEM_B(-0X1433, ctx->r1) = ctx->r16;
    // 0x8014023C: jal         0x80017990
    // 0x80140240: addiu       $a0, $a0, 0x12D8
    ctx->r4 = ADD32(ctx->r4, 0X12D8);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_96;
    // 0x80140240: addiu       $a0, $a0, 0x12D8
    ctx->r4 = ADD32(ctx->r4, 0X12D8);
    after_96:
L_80140244:
    // 0x80140244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140248:
    // 0x80140248: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8014024C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80140250: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80140254: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80140258: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8014025C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80140260: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80140264: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80140268: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8014026C: jr          $ra
    // 0x80140270: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80140270: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80140274(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80140274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140274: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80140278: lbu         $t6, -0x13FB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FB);
    // 0x8014027C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80140280: addiu       $t8, $t8, -0x1480
    ctx->r24 = ADD32(ctx->r24, -0X1480);
    // 0x80140284: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80140288: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8014028C: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80140290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80140298: bne         $t9, $at, L_801402A4
    if (ctx->r25 != ctx->r1) {
        // 0x8014029C: nop
    
            goto L_801402A4;
    }
    // 0x8014029C: nop

    // 0x801402A0: lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X6);
L_801402A4:
    // 0x801402A4: jr          $ra
    // 0x801402A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801402A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801402ac(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801402ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801402AC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801402B0: lbu         $t6, -0x13FF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FF);
    // 0x801402B4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801402B8: addiu       $t8, $t8, -0x1458
    ctx->r24 = ADD32(ctx->r24, -0X1458);
    // 0x801402BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801402C0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801402C4: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x801402C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801402CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801402D0: bne         $t9, $at, L_801402DC
    if (ctx->r25 != ctx->r1) {
        // 0x801402D4: nop
    
            goto L_801402DC;
    }
    // 0x801402D4: nop

    // 0x801402D8: lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X6);
L_801402DC:
    // 0x801402DC: jr          $ra
    // 0x801402E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801402E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801402e4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801402e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801402E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801402E8: sb          $zero, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = 0;
    // 0x801402EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801402F0: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
    // 0x801402F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801402f8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801402f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801402F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801402FC: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x80140300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140304: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140308: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014030C: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
    // 0x80140310: jal         0x8013E700
    // 0x80140314: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    LOOKUP_FUNC(0x8013E700)(rdram, ctx);
        goto after_0;
    // 0x80140314: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    after_0:
    // 0x80140318: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x8014031C: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x80140320: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80140324: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80140328: jal         0x80002364
    // 0x8014032C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x8014032C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80140330: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140334: jal         0x800179B0
    // 0x80140338: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x80140338: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    after_2:
    // 0x8014033C: jal         0x80142778
    // 0x80140340: nop

    LOOKUP_FUNC(0x80142778)(rdram, ctx);
        goto after_3;
    // 0x80140340: nop

    after_3:
    // 0x80140344: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80140348: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8014034C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140350: jal         0x8014307C
    // 0x80140354: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_4;
    // 0x80140354: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80140358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014035C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140360: jr          $ra
    // 0x80140364: nop

    return;
    // 0x80140364: nop

;}
RECOMP_FUNC void M7_FUN_80140368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140368: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014036C: sb          $zero, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = 0;
    // 0x80140370: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140374: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
    // 0x80140378: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014037C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80140380: sb          $t6, -0x13FE($at)
    MEM_B(-0X13FE, ctx->r1) = ctx->r14;
    // 0x80140384: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80140388(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80140388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014038C: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x80140390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140394: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140398: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014039C: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
    // 0x801403A0: jal         0x8013E700
    // 0x801403A4: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    LOOKUP_FUNC(0x8013E700)(rdram, ctx);
        goto after_0;
    // 0x801403A4: addiu       $a0, $a0, -0x1480
    ctx->r4 = ADD32(ctx->r4, -0X1480);
    after_0:
    // 0x801403A8: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x801403AC: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x801403B0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801403B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801403B8: jal         0x80002364
    // 0x801403BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x801403BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801403C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801403C4: jal         0x800179B0
    // 0x801403C8: addiu       $a0, $a0, 0x4F8
    ctx->r4 = ADD32(ctx->r4, 0X4F8);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x801403C8: addiu       $a0, $a0, 0x4F8
    ctx->r4 = ADD32(ctx->r4, 0X4F8);
    after_2:
    // 0x801403CC: jal         0x801426B0
    // 0x801403D0: nop

    LOOKUP_FUNC(0x801426B0)(rdram, ctx);
        goto after_3;
    // 0x801403D0: nop

    after_3:
    // 0x801403D4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801403D8: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x801403DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801403E0: jal         0x8014307C
    // 0x801403E4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_4;
    // 0x801403E4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x801403E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801403EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801403F0: jr          $ra
    // 0x801403F4: nop

    return;
    // 0x801403F4: nop

;}
RECOMP_FUNC void M7_FUN_801403f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801403F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801403FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140400: jal         0x800178E8
    // 0x80140404: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80140404: nop

    after_0:
    // 0x80140408: bne         $v0, $zero, L_80140418
    if (ctx->r2 != 0) {
        // 0x8014040C: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_80140418;
    }
    // 0x8014040C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80140410: b           L_801405F0
    // 0x80140414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801405F0;
    // 0x80140414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140418:
    // 0x80140418: lbu         $t6, -0x13FD($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FD);
    // 0x8014041C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140420: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80140424: bne         $t6, $at, L_80140450
    if (ctx->r14 != ctx->r1) {
        // 0x80140428: addiu       $v1, $v1, -0x1434
        ctx->r3 = ADD32(ctx->r3, -0X1434);
            goto L_80140450;
    }
    // 0x80140428: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x8014042C: jal         0x80142FC4
    // 0x80140430: nop

    LOOKUP_FUNC(0x80142FC4)(rdram, ctx);
        goto after_1;
    // 0x80140430: nop

    after_1:
    // 0x80140434: jal         0x80143B5C
    // 0x80140438: nop

    LOOKUP_FUNC(0x80143B5C)(rdram, ctx);
        goto after_2;
    // 0x80140438: nop

    after_2:
    // 0x8014043C: beq         $v0, $zero, L_80140448
    if (ctx->r2 == 0) {
        // 0x80140440: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80140448;
    }
    // 0x80140440: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140444: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
L_80140448:
    // 0x80140448: b           L_801405F0
    // 0x8014044C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801405F0;
    // 0x8014044C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140450:
    // 0x80140450: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80140454: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80140458: beq         $at, $zero, L_801405EC
    if (ctx->r1 == 0) {
        // 0x8014045C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_801405EC;
    }
    // 0x8014045C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80140460: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140464: addu        $at, $at, $t7
    gpr jr_addend_8014046C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80140468: lw          $t7, -0xFB4($at)
    ctx->r15 = ADD32(ctx->r1, -0XFB4);
    // 0x8014046C: jr          $t7
    // 0x80140470: nop

    switch (jr_addend_8014046C >> 2) {
        case 0: goto L_80140474; break;
        case 1: goto L_801404D8; break;
        case 2: goto L_801404E8; break;
        case 3: goto L_80140564; break;
        case 4: goto L_80140590; break;
        case 5: goto L_801405DC; break;
        default: switch_error(__func__, 0x8014046C, 0x8018F04C);
    }
    // 0x80140470: nop

L_80140474:
    // 0x80140474: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80140478: addiu       $a1, $a1, -0x147C
    ctx->r5 = ADD32(ctx->r5, -0X147C);
    // 0x8014047C: jal         0x8014150C
    // 0x80140480: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_3;
    // 0x80140480: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80140484: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80140488: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x8014048C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140490: jal         0x8014307C
    // 0x80140494: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_4;
    // 0x80140494: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_4:
    // 0x80140498: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014049C: lhu         $v0, -0x40BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40BE);
    // 0x801404A0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801404A4: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x801404A8: bne         $v0, $zero, L_801404B8
    if (ctx->r2 != 0) {
        // 0x801404AC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801404B8;
    }
    // 0x801404AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801404B0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801404B4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_801404B8:
    // 0x801404B8: bne         $v0, $at, L_801404C4
    if (ctx->r2 != ctx->r1) {
        // 0x801404BC: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_801404C4;
    }
    // 0x801404BC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x801404C0: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_801404C4:
    // 0x801404C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801404C8: bne         $v0, $at, L_801405EC
    if (ctx->r2 != ctx->r1) {
        // 0x801404CC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_801405EC;
    }
    // 0x801404CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801404D0: b           L_801405EC
    // 0x801404D4: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
        goto L_801405EC;
    // 0x801404D4: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_801404D8:
    // 0x801404D8: jal         0x800023A8
    // 0x801404DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_5;
    // 0x801404DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801404E0: b           L_801405F0
    // 0x801404E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801405F0;
    // 0x801404E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801404E8:
    // 0x801404E8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801404EC: lhu         $t1, -0x6B88($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X6B88);
    // 0x801404F0: andi        $t2, $t1, 0xB000
    ctx->r10 = ctx->r9 & 0XB000;
    // 0x801404F4: beq         $t2, $zero, L_80140538
    if (ctx->r10 == 0) {
        // 0x801404F8: nop
    
            goto L_80140538;
    }
    // 0x801404F8: nop

    // 0x801404FC: jal         0x8014115C
    // 0x80140500: nop

    LOOKUP_FUNC(0x8014115C)(rdram, ctx);
        goto after_6;
    // 0x80140500: nop

    after_6:
    // 0x80140504: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80140508: beq         $v0, $zero, L_80140524
    if (ctx->r2 == 0) {
        // 0x8014050C: addiu       $v1, $v1, -0x1434
        ctx->r3 = ADD32(ctx->r3, -0X1434);
            goto L_80140524;
    }
    // 0x8014050C: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x80140510: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140514: jal         0x80017990
    // 0x80140518: addiu       $a0, $a0, 0x668
    ctx->r4 = ADD32(ctx->r4, 0X668);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_7;
    // 0x80140518: addiu       $a0, $a0, 0x668
    ctx->r4 = ADD32(ctx->r4, 0X668);
    after_7:
    // 0x8014051C: b           L_80140538
    // 0x80140520: nop

        goto L_80140538;
    // 0x80140520: nop

L_80140524:
    // 0x80140524: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80140528: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014052C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80140530: jal         0x80017990
    // 0x80140534: addiu       $a0, $a0, 0x598
    ctx->r4 = ADD32(ctx->r4, 0X598);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_8;
    // 0x80140534: addiu       $a0, $a0, 0x598
    ctx->r4 = ADD32(ctx->r4, 0X598);
    after_8:
L_80140538:
    // 0x80140538: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8014053C: addiu       $a2, $a2, -0x147C
    ctx->r6 = ADD32(ctx->r6, -0X147C);
    // 0x80140540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140544: jal         0x80140E88
    // 0x80140548: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80140E88)(rdram, ctx);
        goto after_9;
    // 0x80140548: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x8014054C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80140550: lbu         $a1, -0x13FC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FC);
    // 0x80140554: jal         0x80142B28
    // 0x80140558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_10;
    // 0x80140558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8014055C: b           L_801405F0
    // 0x80140560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801405F0;
    // 0x80140560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140564:
    // 0x80140564: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80140568: lhu         $v0, -0x40BE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X40BE);
    // 0x8014056C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80140570: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80140574: bne         $v0, $zero, L_80140580
    if (ctx->r2 != 0) {
        // 0x80140578: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80140580;
    }
    // 0x80140578: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8014057C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_80140580:
    // 0x80140580: bnel        $v0, $at, L_801405F0
    if (ctx->r2 != ctx->r1) {
        // 0x80140584: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801405F0;
    }
    goto skip_0;
    // 0x80140584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80140588: b           L_801405EC
    // 0x8014058C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
        goto L_801405EC;
    // 0x8014058C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_80140590:
    // 0x80140590: jal         0x801411D0
    // 0x80140594: nop

    LOOKUP_FUNC(0x801411D0)(rdram, ctx);
        goto after_11;
    // 0x80140594: nop

    after_11:
    // 0x80140598: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014059C: bne         $v0, $zero, L_801405C0
    if (ctx->r2 != 0) {
        // 0x801405A0: addiu       $v1, $v1, -0x1434
        ctx->r3 = ADD32(ctx->r3, -0X1434);
            goto L_801405C0;
    }
    // 0x801405A0: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x801405A4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801405A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801405AC: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x801405B0: jal         0x80017990
    // 0x801405B4: addiu       $a0, $a0, 0x6E4
    ctx->r4 = ADD32(ctx->r4, 0X6E4);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_12;
    // 0x801405B4: addiu       $a0, $a0, 0x6E4
    ctx->r4 = ADD32(ctx->r4, 0X6E4);
    after_12:
    // 0x801405B8: b           L_801405F0
    // 0x801405BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801405F0;
    // 0x801405BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801405C0:
    // 0x801405C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801405C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801405C8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x801405CC: jal         0x80017990
    // 0x801405D0: addiu       $a0, $a0, 0x71C
    ctx->r4 = ADD32(ctx->r4, 0X71C);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_13;
    // 0x801405D0: addiu       $a0, $a0, 0x71C
    ctx->r4 = ADD32(ctx->r4, 0X71C);
    after_13:
    // 0x801405D4: b           L_801405F0
    // 0x801405D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801405F0;
    // 0x801405D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801405DC:
    // 0x801405DC: jal         0x800023A8
    // 0x801405E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_14;
    // 0x801405E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x801405E4: b           L_801405F0
    // 0x801405E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801405F0;
    // 0x801405E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801405EC:
    // 0x801405EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801405F0:
    // 0x801405F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801405F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801405F8: jr          $ra
    // 0x801405FC: nop

    return;
    // 0x801405FC: nop

;}
RECOMP_FUNC void M7_FUN_80140600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140600: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140604: sb          $zero, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = 0;
    // 0x80140608: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014060C: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
    // 0x80140610: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140614: sb          $zero, -0x1433($at)
    MEM_B(-0X1433, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80140618(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80140618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014061C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80140620: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140624: addiu       $v0, $v0, -0x1428
    ctx->r2 = ADD32(ctx->r2, -0X1428);
    // 0x80140628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014062C: sb          $zero, -0x1401($at)
    MEM_B(-0X1401, ctx->r1) = 0;
    // 0x80140630: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80140634: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80140638: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014063C: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80140640: sb          $t7, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r15;
    // 0x80140644: jal         0x800179B0
    // 0x80140648: addiu       $a0, $a0, 0xB38
    ctx->r4 = ADD32(ctx->r4, 0XB38);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x80140648: addiu       $a0, $a0, 0xB38
    ctx->r4 = ADD32(ctx->r4, 0XB38);
    after_0:
    // 0x8014064C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80140650: addiu       $a2, $a2, -0x1424
    ctx->r6 = ADD32(ctx->r6, -0X1424);
    // 0x80140654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140658: jal         0x8014307C
    // 0x8014065C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_1;
    // 0x8014065C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x80140660: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80140664: addiu       $a2, $a2, -0x1424
    ctx->r6 = ADD32(ctx->r6, -0X1424);
    // 0x80140668: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014066C: jal         0x8014307C
    // 0x80140670: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_2;
    // 0x80140670: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_2:
    // 0x80140674: jal         0x80142A58
    // 0x80140678: nop

    LOOKUP_FUNC(0x80142A58)(rdram, ctx);
        goto after_3;
    // 0x80140678: nop

    after_3:
    // 0x8014067C: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x80140680: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x80140684: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80140688: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8014068C: jal         0x80002364
    // 0x80140690: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_4;
    // 0x80140690: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80140694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014069C: jr          $ra
    // 0x801406A0: nop

    return;
    // 0x801406A0: nop

;}
RECOMP_FUNC void M7_FUN_801406a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801406A4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801406A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801406AC: jal         0x800178E8
    // 0x801406B0: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x801406B0: nop

    after_0:
    // 0x801406B4: bne         $v0, $zero, L_801406C4
    if (ctx->r2 != 0) {
        // 0x801406B8: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801406C4;
    }
    // 0x801406B8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801406BC: b           L_80140E78
    // 0x801406C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x801406C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801406C4:
    // 0x801406C4: lbu         $t6, -0x13FD($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FD);
    // 0x801406C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801406CC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801406D0: bne         $v0, $t6, L_801406FC
    if (ctx->r2 != ctx->r14) {
        // 0x801406D4: nop
    
            goto L_801406FC;
    }
    // 0x801406D4: nop

    // 0x801406D8: jal         0x80142F2C
    // 0x801406DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142F2C)(rdram, ctx);
        goto after_1;
    // 0x801406DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801406E0: jal         0x80143B5C
    // 0x801406E4: nop

    LOOKUP_FUNC(0x80143B5C)(rdram, ctx);
        goto after_2;
    // 0x801406E4: nop

    after_2:
    // 0x801406E8: beq         $v0, $zero, L_801406F4
    if (ctx->r2 == 0) {
        // 0x801406EC: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801406F4;
    }
    // 0x801406EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801406F0: sb          $zero, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = 0;
L_801406F4:
    // 0x801406F4: b           L_80140E78
    // 0x801406F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x801406F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801406FC:
    // 0x801406FC: lbu         $t7, -0x1401($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1401);
    // 0x80140700: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80140704: addiu       $v1, $v1, -0x1434
    ctx->r3 = ADD32(ctx->r3, -0X1434);
    // 0x80140708: bnel        $v0, $t7, L_80140738
    if (ctx->r2 != ctx->r15) {
        // 0x8014070C: lbu         $t8, 0x0($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X0);
            goto L_80140738;
    }
    goto skip_0;
    // 0x8014070C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    skip_0:
    // 0x80140710: jal         0x80142F2C
    // 0x80140714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142F2C)(rdram, ctx);
        goto after_3;
    // 0x80140714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80140718: jal         0x80143B5C
    // 0x8014071C: nop

    LOOKUP_FUNC(0x80143B5C)(rdram, ctx);
        goto after_4;
    // 0x8014071C: nop

    after_4:
    // 0x80140720: beq         $v0, $zero, L_8014072C
    if (ctx->r2 == 0) {
        // 0x80140724: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8014072C;
    }
    // 0x80140724: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140728: sb          $zero, -0x1401($at)
    MEM_B(-0X1401, ctx->r1) = 0;
L_8014072C:
    // 0x8014072C: b           L_80140E78
    // 0x80140730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x80140730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80140734: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
L_80140738:
    // 0x80140738: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x8014073C: beq         $at, $zero, L_80140E74
    if (ctx->r1 == 0) {
        // 0x80140740: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80140E74;
    }
    // 0x80140740: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80140744: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140748: addu        $at, $at, $t8
    gpr jr_addend_80140750 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8014074C: lw          $t8, -0xF9C($at)
    ctx->r24 = ADD32(ctx->r1, -0XF9C);
    // 0x80140750: jr          $t8
    // 0x80140754: nop

    switch (jr_addend_80140750 >> 2) {
        case 0: goto L_80140758; break;
        case 1: goto L_801407B4; break;
        case 2: goto L_801408F8; break;
        case 3: goto L_801409AC; break;
        case 4: goto L_80140A00; break;
        case 5: goto L_80140BF4; break;
        case 6: goto L_80140CAC; break;
        case 7: goto L_80140D58; break;
        case 8: goto L_80140E48; break;
        case 9: goto L_80140E6C; break;
        default: switch_error(__func__, 0x80140750, 0x8018F064);
    }
    // 0x80140754: nop

L_80140758:
    // 0x80140758: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014075C: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x80140760: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140764: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
    // 0x80140768: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8014076C: lhu         $t9, -0x6B6C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X6B6C);
    // 0x80140770: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140774: sb          $zero, -0x1400($at)
    MEM_B(-0X1400, ctx->r1) = 0;
    // 0x80140778: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014077C: bne         $v0, $t9, L_80140798
    if (ctx->r2 != ctx->r25) {
        // 0x80140780: sb          $zero, -0x13FF($at)
        MEM_B(-0X13FF, ctx->r1) = 0;
            goto L_80140798;
    }
    // 0x80140780: sb          $zero, -0x13FF($at)
    MEM_B(-0X13FF, ctx->r1) = 0;
    // 0x80140784: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140788: jal         0x80017990
    // 0x8014078C: addiu       $a0, $a0, 0xBA8
    ctx->r4 = ADD32(ctx->r4, 0XBA8);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_5;
    // 0x8014078C: addiu       $a0, $a0, 0xBA8
    ctx->r4 = ADD32(ctx->r4, 0XBA8);
    after_5:
    // 0x80140790: b           L_801407A8
    // 0x80140794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801407A8;
    // 0x80140794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140798:
    // 0x80140798: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014079C: jal         0x80017990
    // 0x801407A0: addiu       $a0, $a0, 0xB54
    ctx->r4 = ADD32(ctx->r4, 0XB54);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_6;
    // 0x801407A0: addiu       $a0, $a0, 0xB54
    ctx->r4 = ADD32(ctx->r4, 0XB54);
    after_6:
    // 0x801407A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801407A8:
    // 0x801407A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801407AC: b           L_80140E74
    // 0x801407B0: sb          $v0, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r2;
        goto L_80140E74;
    // 0x801407B0: sb          $v0, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r2;
L_801407B4:
    // 0x801407B4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801407B8: addiu       $a1, $a1, -0x147C
    ctx->r5 = ADD32(ctx->r5, -0X147C);
    // 0x801407BC: jal         0x8014150C
    // 0x801407C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_7;
    // 0x801407C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x801407C4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801407C8: addiu       $a1, $a1, -0x1454
    ctx->r5 = ADD32(ctx->r5, -0X1454);
    // 0x801407CC: jal         0x8014150C
    // 0x801407D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_8;
    // 0x801407D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x801407D4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801407D8: lhu         $v1, -0x40BE($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X40BE);
    // 0x801407DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801407E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801407E4: beq         $v1, $zero, L_80140814
    if (ctx->r3 == 0) {
        // 0x801407E8: nop
    
            goto L_80140814;
    }
    // 0x801407E8: nop

    // 0x801407EC: beq         $v1, $at, L_8014082C
    if (ctx->r3 == ctx->r1) {
        // 0x801407F0: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_8014082C;
    }
    // 0x801407F0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801407F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801407F8: beq         $v1, $at, L_80140848
    if (ctx->r3 == ctx->r1) {
        // 0x801407FC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80140848;
    }
    // 0x801407FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80140800: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80140804: beq         $v1, $at, L_80140868
    if (ctx->r3 == ctx->r1) {
        // 0x80140808: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80140868;
    }
    // 0x80140808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8014080C: b           L_80140E78
    // 0x80140810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x80140810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140814:
    // 0x80140814: jal         0x80017990
    // 0x80140818: addiu       $a0, $a0, 0x1214
    ctx->r4 = ADD32(ctx->r4, 0X1214);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_9;
    // 0x80140818: addiu       $a0, $a0, 0x1214
    ctx->r4 = ADD32(ctx->r4, 0X1214);
    after_9:
    // 0x8014081C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80140820: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140824: b           L_80140E74
    // 0x80140828: sb          $t0, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r8;
        goto L_80140E74;
    // 0x80140828: sb          $t0, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r8;
L_8014082C:
    // 0x8014082C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140830: sb          $zero, -0x13FE($at)
    MEM_B(-0X13FE, ctx->r1) = 0;
    // 0x80140834: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140838: sb          $zero, -0x1402($at)
    MEM_B(-0X1402, ctx->r1) = 0;
    // 0x8014083C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140840: b           L_80140E74
    // 0x80140844: sb          $t1, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r9;
        goto L_80140E74;
    // 0x80140844: sb          $t1, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r9;
L_80140848:
    // 0x80140848: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014084C: sb          $v0, -0x13FE($at)
    MEM_B(-0X13FE, ctx->r1) = ctx->r2;
    // 0x80140850: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140854: sb          $v0, -0x1402($at)
    MEM_B(-0X1402, ctx->r1) = ctx->r2;
    // 0x80140858: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014085C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80140860: b           L_80140E74
    // 0x80140864: sb          $t2, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r10;
        goto L_80140E74;
    // 0x80140864: sb          $t2, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r10;
L_80140868:
    // 0x80140868: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8014086C: addiu       $a2, $a2, -0x1424
    ctx->r6 = ADD32(ctx->r6, -0X1424);
    // 0x80140870: jal         0x8014307C
    // 0x80140874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_10;
    // 0x80140874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80140878: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8014087C: addiu       $a2, $a2, -0x1424
    ctx->r6 = ADD32(ctx->r6, -0X1424);
    // 0x80140880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80140884: jal         0x8014307C
    // 0x80140888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_11;
    // 0x80140888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8014088C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140890: jal         0x80017990
    // 0x80140894: addiu       $a0, $a0, 0xDD8
    ctx->r4 = ADD32(ctx->r4, 0XDD8);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_12;
    // 0x80140894: addiu       $a0, $a0, 0xDD8
    ctx->r4 = ADD32(ctx->r4, 0XDD8);
    after_12:
    // 0x80140898: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014089C: addiu       $t3, $zero, 0x7A
    ctx->r11 = ADD32(0, 0X7A);
    // 0x801408A0: addiu       $t4, $zero, 0x5C
    ctx->r12 = ADD32(0, 0X5C);
    // 0x801408A4: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801408A8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x801408AC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801408B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801408B4: addiu       $a1, $a1, -0x12AC
    ctx->r5 = ADD32(ctx->r5, -0X12AC);
    // 0x801408B8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x801408BC: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x801408C0: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    // 0x801408C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801408C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801408CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801408D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801408D4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801408D8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801408DC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801408E0: jal         0x8001A804
    // 0x801408E4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_13;
    // 0x801408E4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_13:
    // 0x801408E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801408EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801408F0: b           L_80140E74
    // 0x801408F4: sb          $t6, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r14;
        goto L_80140E74;
    // 0x801408F4: sb          $t6, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r14;
L_801408F8:
    // 0x801408F8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x801408FC: lhu         $t7, -0x6B88($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6B88);
    // 0x80140900: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80140904: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140908: andi        $t8, $t7, 0xB000
    ctx->r24 = ctx->r15 & 0XB000;
    // 0x8014090C: beq         $t8, $zero, L_80140980
    if (ctx->r24 == 0) {
        // 0x80140910: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80140980;
    }
    // 0x80140910: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140914: lbu         $t9, -0x13FB($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X13FB);
    // 0x80140918: addiu       $a0, $a0, 0xE80
    ctx->r4 = ADD32(ctx->r4, 0XE80);
    // 0x8014091C: jal         0x80017990
    // 0x80140920: sb          $t9, -0x13FE($at)
    MEM_B(-0X13FE, ctx->r1) = ctx->r25;
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_14;
    // 0x80140920: sb          $t9, -0x13FE($at)
    MEM_B(-0X13FE, ctx->r1) = ctx->r25;
    after_14:
    // 0x80140924: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80140928: addiu       $t0, $zero, 0x7A
    ctx->r8 = ADD32(0, 0X7A);
    // 0x8014092C: addiu       $t1, $zero, 0x5C
    ctx->r9 = ADD32(0, 0X5C);
    // 0x80140930: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80140934: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80140938: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8014093C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80140940: addiu       $a1, $a1, -0x1284
    ctx->r5 = ADD32(ctx->r5, -0X1284);
    // 0x80140944: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80140948: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8014094C: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    // 0x80140950: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80140954: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80140958: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8014095C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80140960: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80140964: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80140968: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8014096C: jal         0x8001A804
    // 0x80140970: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_15;
    // 0x80140970: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_15:
    // 0x80140974: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80140978: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014097C: sb          $t3, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r11;
L_80140980:
    // 0x80140980: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80140984: addiu       $a2, $a2, -0x1424
    ctx->r6 = ADD32(ctx->r6, -0X1424);
    // 0x80140988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8014098C: jal         0x80140E88
    // 0x80140990: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80140E88)(rdram, ctx);
        goto after_16;
    // 0x80140990: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
    // 0x80140994: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80140998: lbu         $a1, -0x13FC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FC);
    // 0x8014099C: jal         0x80142B28
    // 0x801409A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_17;
    // 0x801409A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x801409A4: b           L_80140E78
    // 0x801409A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x801409A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801409AC:
    // 0x801409AC: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x801409B0: lhu         $t4, -0x6B88($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6B88);
    // 0x801409B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801409B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801409BC: andi        $t5, $t4, 0xB000
    ctx->r13 = ctx->r12 & 0XB000;
    // 0x801409C0: beq         $t5, $zero, L_801409E0
    if (ctx->r13 == 0) {
        // 0x801409C4: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_801409E0;
    }
    // 0x801409C4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801409C8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801409CC: lbu         $t6, -0x13FF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FF);
    // 0x801409D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801409D4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801409D8: sb          $t6, -0x1402($at)
    MEM_B(-0X1402, ctx->r1) = ctx->r14;
    // 0x801409DC: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801409E0:
    // 0x801409E0: jal         0x80140FC8
    // 0x801409E4: addiu       $a2, $a2, -0x1424
    ctx->r6 = ADD32(ctx->r6, -0X1424);
    LOOKUP_FUNC(0x80140FC8)(rdram, ctx);
        goto after_18;
    // 0x801409E4: addiu       $a2, $a2, -0x1424
    ctx->r6 = ADD32(ctx->r6, -0X1424);
    after_18:
    // 0x801409E8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801409EC: lbu         $a1, -0x1400($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1400);
    // 0x801409F0: jal         0x80142B28
    // 0x801409F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_19;
    // 0x801409F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x801409F8: b           L_80140E78
    // 0x801409FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x801409FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140A00:
    // 0x80140A00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140A04: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x80140A08: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80140A0C: lbu         $t8, -0x13FE($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X13FE);
    // 0x80140A10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140A14: sb          $zero, -0x13FB($at)
    MEM_B(-0X13FB, ctx->r1) = 0;
    // 0x80140A18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140A1C: sb          $zero, -0x1400($at)
    MEM_B(-0X1400, ctx->r1) = 0;
    // 0x80140A20: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80140A24: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80140A28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140A2C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80140A30: sb          $zero, -0x13FF($at)
    MEM_B(-0X13FF, ctx->r1) = 0;
    // 0x80140A34: lw          $a2, 0x12E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X12E8);
    // 0x80140A38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140A3C: jal         0x8014307C
    // 0x80140A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_20;
    // 0x80140A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80140A44: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80140A48: lbu         $t0, -0x1402($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1402);
    // 0x80140A4C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80140A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80140A54: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80140A58: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80140A5C: lw          $a2, 0x12E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X12E8);
    // 0x80140A60: jal         0x8014307C
    // 0x80140A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_21;
    // 0x80140A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80140A68: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140A6C: jal         0x80017990
    // 0x80140A70: addiu       $a0, $a0, 0xF28
    ctx->r4 = ADD32(ctx->r4, 0XF28);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_22;
    // 0x80140A70: addiu       $a0, $a0, 0xF28
    ctx->r4 = ADD32(ctx->r4, 0XF28);
    after_22:
    // 0x80140A74: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80140A78: addiu       $t2, $zero, 0x7A
    ctx->r10 = ADD32(0, 0X7A);
    // 0x80140A7C: addiu       $t3, $zero, 0x5C
    ctx->r11 = ADD32(0, 0X5C);
    // 0x80140A80: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80140A84: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80140A88: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80140A8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80140A90: addiu       $a1, $a1, -0x125C
    ctx->r5 = ADD32(ctx->r5, -0X125C);
    // 0x80140A94: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80140A98: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x80140A9C: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    // 0x80140AA0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80140AA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80140AA8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80140AAC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80140AB0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80140AB4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80140AB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80140ABC: jal         0x8001A804
    // 0x80140AC0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_23;
    // 0x80140AC0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_23:
    // 0x80140AC4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80140AC8: lbu         $v1, -0x13FE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X13FE);
    // 0x80140ACC: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80140AD0: bne         $v1, $zero, L_80140B18
    if (ctx->r3 != 0) {
        // 0x80140AD4: nop
    
            goto L_80140B18;
    }
    // 0x80140AD4: nop

    // 0x80140AD8: lbu         $t5, -0x1402($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X1402);
    // 0x80140ADC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80140AE0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80140AE4: bne         $t5, $zero, L_80140B18
    if (ctx->r13 != 0) {
        // 0x80140AE8: addiu       $a2, $zero, 0x30
        ctx->r6 = ADD32(0, 0X30);
            goto L_80140B18;
    }
    // 0x80140AE8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80140AEC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80140AF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80140AF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80140AF8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80140AFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80140B00: addiu       $a3, $a3, -0x1234
    ctx->r7 = ADD32(ctx->r7, -0X1234);
    // 0x80140B04: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80140B08: jal         0x8001B204
    // 0x80140B0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_24;
    // 0x80140B0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_24:
    // 0x80140B10: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80140B14: lbu         $v1, -0x13FE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X13FE);
L_80140B18:
    // 0x80140B18: bne         $v1, $zero, L_80140B5C
    if (ctx->r3 != 0) {
        // 0x80140B1C: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_80140B5C;
    }
    // 0x80140B1C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80140B20: lbu         $t8, -0x1402($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X1402);
    // 0x80140B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80140B28: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80140B2C: bne         $v0, $t8, L_80140B5C
    if (ctx->r2 != ctx->r24) {
        // 0x80140B30: addiu       $a1, $zero, 0x26
        ctx->r5 = ADD32(0, 0X26);
            goto L_80140B5C;
    }
    // 0x80140B30: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80140B34: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80140B38: addiu       $a3, $a3, -0x11F8
    ctx->r7 = ADD32(ctx->r7, -0X11F8);
    // 0x80140B3C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80140B40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80140B44: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80140B48: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80140B4C: jal         0x8001B204
    // 0x80140B50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_25;
    // 0x80140B50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_25:
    // 0x80140B54: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80140B58: lbu         $v1, -0x13FE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X13FE);
L_80140B5C:
    // 0x80140B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80140B60: bne         $v0, $v1, L_80140BA4
    if (ctx->r2 != ctx->r3) {
        // 0x80140B64: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_80140BA4;
    }
    // 0x80140B64: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80140B68: lbu         $t9, -0x1402($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1402);
    // 0x80140B6C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80140B70: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80140B74: bne         $t9, $zero, L_80140BA4
    if (ctx->r25 != 0) {
        // 0x80140B78: addiu       $a2, $zero, 0x30
        ctx->r6 = ADD32(0, 0X30);
            goto L_80140BA4;
    }
    // 0x80140B78: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80140B7C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80140B80: addiu       $a3, $a3, -0x11BC
    ctx->r7 = ADD32(ctx->r7, -0X11BC);
    // 0x80140B84: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80140B88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80140B8C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80140B90: jal         0x8001B204
    // 0x80140B94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_26;
    // 0x80140B94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_26:
    // 0x80140B98: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80140B9C: lbu         $v1, -0x13FE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X13FE);
    // 0x80140BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140BA4:
    // 0x80140BA4: bne         $v0, $v1, L_80140BE4
    if (ctx->r2 != ctx->r3) {
        // 0x80140BA8: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_80140BE4;
    }
    // 0x80140BA8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80140BAC: lbu         $t0, -0x1402($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1402);
    // 0x80140BB0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80140BB4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80140BB8: bne         $v0, $t0, L_80140BE4
    if (ctx->r2 != ctx->r8) {
        // 0x80140BBC: addiu       $a2, $zero, 0x30
        ctx->r6 = ADD32(0, 0X30);
            goto L_80140BE4;
    }
    // 0x80140BBC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80140BC0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80140BC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80140BC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80140BCC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80140BD0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80140BD4: addiu       $a3, $a3, -0x1180
    ctx->r7 = ADD32(ctx->r7, -0X1180);
    // 0x80140BD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80140BDC: jal         0x8001B204
    // 0x80140BE0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_27;
    // 0x80140BE0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_27:
L_80140BE4:
    // 0x80140BE4: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80140BE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140BEC: b           L_80140E74
    // 0x80140BF0: sb          $t3, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r11;
        goto L_80140E74;
    // 0x80140BF0: sb          $t3, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r11;
L_80140BF4:
    // 0x80140BF4: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80140BF8: lhu         $t4, -0x6B88($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6B88);
    // 0x80140BFC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140C00: andi        $t5, $t4, 0xB000
    ctx->r13 = ctx->r12 & 0XB000;
    // 0x80140C04: beq         $t5, $zero, L_80140C70
    if (ctx->r13 == 0) {
        // 0x80140C08: nop
    
            goto L_80140C70;
    }
    // 0x80140C08: nop

    // 0x80140C0C: jal         0x80017990
    // 0x80140C10: addiu       $a0, $a0, 0xF94
    ctx->r4 = ADD32(ctx->r4, 0XF94);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_28;
    // 0x80140C10: addiu       $a0, $a0, 0xF94
    ctx->r4 = ADD32(ctx->r4, 0XF94);
    after_28:
    // 0x80140C14: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80140C18: addiu       $t6, $zero, 0x7A
    ctx->r14 = ADD32(0, 0X7A);
    // 0x80140C1C: addiu       $t7, $zero, 0x5C
    ctx->r15 = ADD32(0, 0X5C);
    // 0x80140C20: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80140C24: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80140C28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80140C2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80140C30: addiu       $a1, $a1, -0x1144
    ctx->r5 = ADD32(ctx->r5, -0X1144);
    // 0x80140C34: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80140C38: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80140C3C: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    // 0x80140C40: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80140C44: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80140C48: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80140C4C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80140C50: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80140C54: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80140C58: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80140C5C: jal         0x8001A804
    // 0x80140C60: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_29;
    // 0x80140C60: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_29:
    // 0x80140C64: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80140C68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140C6C: sb          $t9, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r25;
L_80140C70:
    // 0x80140C70: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80140C74: lbu         $t0, -0x13FE($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X13FE);
    // 0x80140C78: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80140C7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140C80: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80140C84: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80140C88: lw          $a2, 0x12E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X12E8);
    // 0x80140C8C: jal         0x80140E88
    // 0x80140C90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80140E88)(rdram, ctx);
        goto after_30;
    // 0x80140C90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_30:
    // 0x80140C94: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80140C98: lbu         $a1, -0x13FC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FC);
    // 0x80140C9C: jal         0x80142B28
    // 0x80140CA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_31;
    // 0x80140CA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x80140CA4: b           L_80140E78
    // 0x80140CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x80140CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140CAC:
    // 0x80140CAC: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80140CB0: lhu         $t2, -0x6B88($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X6B88);
    // 0x80140CB4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140CB8: andi        $t3, $t2, 0xB000
    ctx->r11 = ctx->r10 & 0XB000;
    // 0x80140CBC: beq         $t3, $zero, L_80140D1C
    if (ctx->r11 == 0) {
        // 0x80140CC0: nop
    
            goto L_80140D1C;
    }
    // 0x80140CC0: nop

    // 0x80140CC4: jal         0x80017990
    // 0x80140CC8: addiu       $a0, $a0, 0x1010
    ctx->r4 = ADD32(ctx->r4, 0X1010);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_32;
    // 0x80140CC8: addiu       $a0, $a0, 0x1010
    ctx->r4 = ADD32(ctx->r4, 0X1010);
    after_32:
    // 0x80140CCC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80140CD0: addiu       $a1, $a1, -0x111C
    ctx->r5 = ADD32(ctx->r5, -0X111C);
    // 0x80140CD4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80140CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80140CDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80140CE0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80140CE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80140CE8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80140CEC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80140CF0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80140CF4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80140CF8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80140CFC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80140D00: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80140D04: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80140D08: jal         0x8001A804
    // 0x80140D0C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_33;
    // 0x80140D0C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_33:
    // 0x80140D10: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80140D14: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140D18: sb          $t4, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r12;
L_80140D1C:
    // 0x80140D1C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80140D20: lbu         $t5, -0x1402($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X1402);
    // 0x80140D24: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80140D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140D2C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80140D30: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x80140D34: lw          $a2, 0x12E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X12E8);
    // 0x80140D38: jal         0x80140FC8
    // 0x80140D3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80140FC8)(rdram, ctx);
        goto after_34;
    // 0x80140D3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_34:
    // 0x80140D40: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80140D44: lbu         $a1, -0x1400($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1400);
    // 0x80140D48: jal         0x80142B28
    // 0x80140D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142B28)(rdram, ctx);
        goto after_35;
    // 0x80140D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x80140D50: b           L_80140E78
    // 0x80140D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E78;
    // 0x80140D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140D58:
    // 0x80140D58: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80140D5C: lhu         $t7, -0x40BC($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X40BC);
    // 0x80140D60: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80140D64: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80140D68: bne         $t7, $zero, L_80140E30
    if (ctx->r15 != 0) {
        // 0x80140D6C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80140E30;
    }
    // 0x80140D6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140D70: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80140D74: lbu         $a0, -0x13FE($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X13FE);
    // 0x80140D78: lbu         $a1, -0x1402($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1402);
    // 0x80140D7C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80140D80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80140D84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80140D88: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80140D8C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80140D90: lbu         $a3, -0x13FF($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X13FF);
    // 0x80140D94: jal         0x8014168C
    // 0x80140D98: lbu         $a2, -0x13FB($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X13FB);
    LOOKUP_FUNC(0x8014168C)(rdram, ctx);
        goto after_36;
    // 0x80140D98: lbu         $a2, -0x13FB($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X13FB);
    after_36:
    // 0x80140D9C: bne         $v0, $zero, L_80140E1C
    if (ctx->r2 != 0) {
        // 0x80140DA0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80140E1C;
    }
    // 0x80140DA0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80140DA4: lbu         $v0, -0x1402($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1402);
    // 0x80140DA8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80140DAC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80140DB0: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80140DB4: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80140DB8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80140DBC: jal         0x8014150C
    // 0x80140DC0: lw          $a1, 0x12E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X12E8);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_37;
    // 0x80140DC0: lw          $a1, 0x12E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X12E8);
    after_37:
    // 0x80140DC4: bne         $v0, $zero, L_80140E1C
    if (ctx->r2 != 0) {
        // 0x80140DC8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80140E1C;
    }
    // 0x80140DC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80140DCC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80140DD0: lbu         $t3, -0x1402($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X1402);
    // 0x80140DD4: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80140DD8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80140DDC: lbu         $t0, -0x1400($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1400);
    // 0x80140DE0: lbu         $t9, -0x13FF($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X13FF);
    // 0x80140DE4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80140DE8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80140DEC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80140DF0: lw          $t5, 0x12E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X12E8);
    // 0x80140DF4: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80140DF8: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80140DFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80140E00: jal         0x801439C0
    // 0x80140E04: addu        $a2, $t5, $t2
    ctx->r6 = ADD32(ctx->r13, ctx->r10);
    LOOKUP_FUNC(0x801439C0)(rdram, ctx);
        goto after_38;
    // 0x80140E04: addu        $a2, $t5, $t2
    ctx->r6 = ADD32(ctx->r13, ctx->r10);
    after_38:
    // 0x80140E08: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140E0C: jal         0x80017990
    // 0x80140E10: addiu       $a0, $a0, 0x10D4
    ctx->r4 = ADD32(ctx->r4, 0X10D4);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_39;
    // 0x80140E10: addiu       $a0, $a0, 0x10D4
    ctx->r4 = ADD32(ctx->r4, 0X10D4);
    after_39:
    // 0x80140E14: b           L_80140E3C
    // 0x80140E18: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
        goto L_80140E3C;
    // 0x80140E18: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
L_80140E1C:
    // 0x80140E1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80140E20: jal         0x80017990
    // 0x80140E24: addiu       $a0, $a0, 0x110C
    ctx->r4 = ADD32(ctx->r4, 0X110C);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_40;
    // 0x80140E24: addiu       $a0, $a0, 0x110C
    ctx->r4 = ADD32(ctx->r4, 0X110C);
    after_40:
    // 0x80140E28: b           L_80140E3C
    // 0x80140E2C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
        goto L_80140E3C;
    // 0x80140E2C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
L_80140E30:
    // 0x80140E30: jal         0x80017990
    // 0x80140E34: addiu       $a0, $a0, 0x1150
    ctx->r4 = ADD32(ctx->r4, 0X1150);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_41;
    // 0x80140E34: addiu       $a0, $a0, 0x1150
    ctx->r4 = ADD32(ctx->r4, 0X1150);
    after_41:
    // 0x80140E38: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
L_80140E3C:
    // 0x80140E3C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140E40: b           L_80140E74
    // 0x80140E44: sb          $t6, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r14;
        goto L_80140E74;
    // 0x80140E44: sb          $t6, -0x1434($at)
    MEM_B(-0X1434, ctx->r1) = ctx->r14;
L_80140E48:
    // 0x80140E48: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80140E4C: lhu         $t7, -0x40BC($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X40BC);
    // 0x80140E50: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80140E54: bne         $t7, $zero, L_80140E64
    if (ctx->r15 != 0) {
        // 0x80140E58: nop
    
            goto L_80140E64;
    }
    // 0x80140E58: nop

    // 0x80140E5C: b           L_80140E74
    // 0x80140E60: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_80140E74;
    // 0x80140E60: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80140E64:
    // 0x80140E64: b           L_80140E74
    // 0x80140E68: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_80140E74;
    // 0x80140E68: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80140E6C:
    // 0x80140E6C: b           L_80140E78
    // 0x80140E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140E78;
    // 0x80140E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140E74:
    // 0x80140E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140E78:
    // 0x80140E78: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80140E7C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80140E80: jr          $ra
    // 0x80140E84: nop

    return;
    // 0x80140E84: nop

;}
RECOMP_FUNC void M7_FUN_80140e88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80140E8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80140E90: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80140E94: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80140E98: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80140E9C: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80140EA0: addiu       $t8, $t8, -0x6D50
    ctx->r24 = ADD32(ctx->r24, -0X6D50);
    // 0x80140EA4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80140EA8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80140EAC: lhu         $t0, 0x1D0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1D0);
    // 0x80140EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140EB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80140EB8: andi        $t9, $t0, 0x800
    ctx->r25 = ctx->r8 & 0X800;
    // 0x80140EBC: beq         $t9, $zero, L_80140F38
    if (ctx->r25 == 0) {
        // 0x80140EC0: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80140F38;
    }
    // 0x80140EC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80140EC4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80140EC8: addiu       $a3, $a3, -0x13FB
    ctx->r7 = ADD32(ctx->r7, -0X13FB);
    // 0x80140ECC: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80140ED0: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80140ED4: addiu       $t1, $t1, -0x13FC
    ctx->r9 = ADD32(ctx->r9, -0X13FC);
    // 0x80140ED8: blez        $v0, L_80140F38
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80140EDC: nop
    
            goto L_80140F38;
    }
    // 0x80140EDC: nop

    // 0x80140EE0: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80140EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140EE8: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80140EEC: bne         $t2, $at, L_80140F04
    if (ctx->r10 != ctx->r1) {
        // 0x80140EF0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80140F04;
    }
    // 0x80140EF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140EF4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80140EF8: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
    // 0x80140EFC: b           L_80140F38
    // 0x80140F00: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
        goto L_80140F38;
    // 0x80140F00: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
L_80140F04:
    // 0x80140F04: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80140F08: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80140F0C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80140F10: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x80140F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80140F18: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80140F1C: jal         0x80143AC4
    // 0x80140F20: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x80143AC4)(rdram, ctx);
        goto after_0;
    // 0x80140F20: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80140F24: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80140F28: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80140F2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140F30: sb          $t8, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = ctx->r24;
    // 0x80140F34: lhu         $t0, 0x1D0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1D0);
L_80140F38:
    // 0x80140F38: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80140F3C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80140F40: andi        $t9, $t0, 0x400
    ctx->r25 = ctx->r8 & 0X400;
    // 0x80140F44: addiu       $t1, $t1, -0x13FC
    ctx->r9 = ADD32(ctx->r9, -0X13FC);
    // 0x80140F48: beq         $t9, $zero, L_80140FB8
    if (ctx->r25 == 0) {
        // 0x80140F4C: addiu       $a3, $a3, -0x13FB
        ctx->r7 = ADD32(ctx->r7, -0X13FB);
            goto L_80140FB8;
    }
    // 0x80140F4C: addiu       $a3, $a3, -0x13FB
    ctx->r7 = ADD32(ctx->r7, -0X13FB);
    // 0x80140F50: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x80140F54: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80140F58: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80140F5C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80140F60: beql        $at, $zero, L_80140FBC
    if (ctx->r1 == 0) {
        // 0x80140F64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140FBC;
    }
    goto skip_0;
    // 0x80140F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80140F68: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80140F6C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80140F70: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80140F74: bnel        $t4, $zero, L_80140F8C
    if (ctx->r12 != 0) {
        // 0x80140F78: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_80140F8C;
    }
    goto skip_1;
    // 0x80140F78: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80140F7C: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
    // 0x80140F80: b           L_80140FB8
    // 0x80140F84: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
        goto L_80140FB8;
    // 0x80140F84: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x80140F88: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
L_80140F8C:
    // 0x80140F8C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80140F90: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80140F94: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80140F98: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
    // 0x80140F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80140FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80140FA4: jal         0x80143AC4
    // 0x80140FA8: addu        $a2, $t9, $t2
    ctx->r6 = ADD32(ctx->r25, ctx->r10);
    LOOKUP_FUNC(0x80143AC4)(rdram, ctx);
        goto after_1;
    // 0x80140FA8: addu        $a2, $t9, $t2
    ctx->r6 = ADD32(ctx->r25, ctx->r10);
    after_1:
    // 0x80140FAC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80140FB0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80140FB4: sb          $t3, -0x13FD($at)
    MEM_B(-0X13FD, ctx->r1) = ctx->r11;
L_80140FB8:
    // 0x80140FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140FBC:
    // 0x80140FBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80140FC0: jr          $ra
    // 0x80140FC4: nop

    return;
    // 0x80140FC4: nop

;}
RECOMP_FUNC void M7_FUN_80140fc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140FC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80140FCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80140FD0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80140FD4: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80140FD8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80140FDC: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80140FE0: addiu       $t8, $t8, -0x6D50
    ctx->r24 = ADD32(ctx->r24, -0X6D50);
    // 0x80140FE4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80140FE8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80140FEC: lhu         $t0, 0x1D0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1D0);
    // 0x80140FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140FF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80140FF8: andi        $t9, $t0, 0x800
    ctx->r25 = ctx->r8 & 0X800;
    // 0x80140FFC: beq         $t9, $zero, L_80141078
    if (ctx->r25 == 0) {
        // 0x80141000: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
        LOOKUP_FUNC(0x80141078)(rdram, ctx);
        return;
    }
    // 0x80141000: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80141004: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80141008: addiu       $a3, $a3, -0x13FF
    ctx->r7 = ADD32(ctx->r7, -0X13FF);
    // 0x8014100C: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80141010: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141014(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141014: addiu       $t1, $t1, -0x1400
    ctx->r9 = ADD32(ctx->r9, -0X1400);
    // 0x80141018: blez        $v0, L_80141078
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8014101C: nop
    
            goto L_80141078;
    }
    // 0x8014101C: nop

    // 0x80141020: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80141024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80141028: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8014102C: bne         $t2, $at, L_80141044
    if (ctx->r10 != ctx->r1) {
        // 0x80141030: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80141044;
    }
    // 0x80141030: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80141034: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80141038: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
    // 0x8014103C: b           L_80141078
    // 0x80141040: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
        goto L_80141078;
    // 0x80141040: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
L_80141044:
    // 0x80141044: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80141048: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8014104C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80141050: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x80141054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80141058: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8014105C: jal         0x80143AC4
    // 0x80141060: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x80143AC4)(rdram, ctx);
        goto after_0;
    // 0x80141060: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80141064: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80141068: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014106C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80141070: sb          $t8, -0x1401($at)
    MEM_B(-0X1401, ctx->r1) = ctx->r24;
    // 0x80141074: lhu         $t0, 0x1D0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1D0);
L_80141078:
    // 0x80141078: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8014107C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80141080: andi        $t9, $t0, 0x400
    ctx->r25 = ctx->r8 & 0X400;
    // 0x80141084: addiu       $t1, $t1, -0x1400
    ctx->r9 = ADD32(ctx->r9, -0X1400);
    // 0x80141088: beq         $t9, $zero, L_801410F8
    if (ctx->r25 == 0) {
        // 0x8014108C: addiu       $a3, $a3, -0x13FF
        ctx->r7 = ADD32(ctx->r7, -0X13FF);
            goto L_801410F8;
    }
    // 0x8014108C: addiu       $a3, $a3, -0x13FF
    ctx->r7 = ADD32(ctx->r7, -0X13FF);
    // 0x80141090: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x80141094: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80141098: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8014109C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801410A0: beql        $at, $zero, L_801410FC
    if (ctx->r1 == 0) {
        // 0x801410A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801410FC;
    }
    goto skip_0;
    // 0x801410A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801410A8: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x801410AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801410B0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801410B4: bnel        $t4, $zero, L_801410CC
    if (ctx->r12 != 0) {
        // 0x801410B8: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_801410CC;
    }
    goto skip_1;
    // 0x801410B8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x801410BC: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
    // 0x801410C0: b           L_801410F8
    // 0x801410C4: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
        goto L_801410F8;
    // 0x801410C4: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x801410C8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
L_801410CC:
    // 0x801410CC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801410D0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801410D4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801410D8: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
    // 0x801410DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801410E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801410E4: jal         0x80143AC4
    // 0x801410E8: addu        $a2, $t9, $t2
    ctx->r6 = ADD32(ctx->r25, ctx->r10);
    LOOKUP_FUNC(0x80143AC4)(rdram, ctx);
        goto after_1;
    // 0x801410E8: addu        $a2, $t9, $t2
    ctx->r6 = ADD32(ctx->r25, ctx->r10);
    after_1:
    // 0x801410EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801410F0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801410F4: sb          $t3, -0x1401($at)
    MEM_B(-0X1401, ctx->r1) = ctx->r11;
L_801410F8:
    // 0x801410F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801410FC:
    // 0x801410FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80141100: jr          $ra
    // 0x80141104: nop

    return;
    // 0x80141104: nop

;}
