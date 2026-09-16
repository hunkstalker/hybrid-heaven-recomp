#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_80228328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8022832C: addiu       $v0, $a1, -0x44C
    ctx->r2 = ADD32(ctx->r5, -0X44C);
    // 0x80228330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80228334: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80228338: bne         $v0, $t1, L_80228350
    if (ctx->r2 != ctx->r9) {
        // 0x8022833C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80228350;
    }
    // 0x8022833C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80228340: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80228344: addiu       $v1, $v1, -0x1398
    ctx->r3 = ADD32(ctx->r3, -0X1398);
    // 0x80228348: b           L_8022835C
    // 0x8022834C: lbu         $a2, 0x1A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1A);
        goto L_8022835C;
    // 0x8022834C: lbu         $a2, 0x1A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1A);
L_80228350:
    // 0x80228350: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80228354: addiu       $v1, $v1, -0x1398
    ctx->r3 = ADD32(ctx->r3, -0X1398);
    // 0x80228358: lbu         $a2, 0x1B($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1B);
L_8022835C:
    // 0x8022835C: bnel        $v0, $t1, L_80228370
    if (ctx->r2 != ctx->r9) {
        // 0x80228360: lbu         $t0, 0x1D($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X1D);
            goto L_80228370;
    }
    goto skip_0;
    // 0x80228360: lbu         $t0, 0x1D($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1D);
    skip_0:
    // 0x80228364: b           L_80228370
    // 0x80228368: lbu         $t0, 0x1C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1C);
        goto L_80228370;
    // 0x80228368: lbu         $t0, 0x1C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1C);
    // 0x8022836C: lbu         $t0, 0x1D($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1D);
L_80228370:
    // 0x80228370: bnel        $v0, $t1, L_80228384
    if (ctx->r2 != ctx->r9) {
        // 0x80228374: sh          $a2, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r6;
            goto L_80228384;
    }
    goto skip_1;
    // 0x80228374: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    skip_1:
    // 0x80228378: b           L_802283A0
    // 0x8022837C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_802283A0;
    // 0x8022837C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80228380: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
L_80228384:
    // 0x80228384: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80228388: jal         0x802269CC
    // 0x8022838C: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_0;
    // 0x8022838C: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80228390: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    // 0x80228394: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80228398: lhu         $t0, 0x1C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X1C);
    // 0x8022839C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
L_802283A0:
    // 0x802283A0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x802283A4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x802283A8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x802283AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x802283B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802283B4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_802283B8:
    // 0x802283B8: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802283BC: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x802283C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x802283C4: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x802283C8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x802283CC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x802283D0: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x802283D4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x802283D8: mflo        $t9
    ctx->r25 = lo;
    // 0x802283DC: addiu       $t2, $t9, 0x64
    ctx->r10 = ADD32(ctx->r25, 0X64);
    // 0x802283E0: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x802283E4: beql        $at, $zero, L_802283FC
    if (ctx->r1 == 0) {
        // 0x802283E8: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_802283FC;
    }
    goto skip_2;
    // 0x802283E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_2:
    // 0x802283EC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x802283F0: b           L_80228400
    // 0x802283F4: sb          $a1, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r5;
        goto L_80228400;
    // 0x802283F4: sb          $a1, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r5;
    // 0x802283F8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_802283FC:
    // 0x802283FC: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
L_80228400:
    // 0x80228400: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80228404: bne         $at, $zero, L_802283B8
    if (ctx->r1 != 0) {
        // 0x80228408: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_802283B8;
    }
    // 0x80228408: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8022840C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80228410: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80228414: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80228418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022841C: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
L_80228420:
    // 0x80228420: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80228424: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80228428: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8022842C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80228430: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80228434: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80228438: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8022843C: addu        $t2, $a0, $t8
    ctx->r10 = ADD32(ctx->r4, ctx->r24);
    // 0x80228440: mflo        $t4
    ctx->r12 = lo;
    // 0x80228444: addiu       $t5, $t4, 0x64
    ctx->r13 = ADD32(ctx->r12, 0X64);
    // 0x80228448: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8022844C: beql        $at, $zero, L_80228464
    if (ctx->r1 == 0) {
        // 0x80228450: lw          $t4, 0x0($t2)
        ctx->r12 = MEM_W(ctx->r10, 0X0);
            goto L_80228464;
    }
    goto skip_3;
    // 0x80228450: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    skip_3:
    // 0x80228454: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80228458: b           L_80228468
    // 0x8022845C: sb          $a1, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r5;
        goto L_80228468;
    // 0x8022845C: sb          $a1, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r5;
    // 0x80228460: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
L_80228464:
    // 0x80228464: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
L_80228468:
    // 0x80228468: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8022846C: bne         $at, $zero, L_80228420
    if (ctx->r1 != 0) {
        // 0x80228470: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80228420;
    }
    // 0x80228470: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80228474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80228478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8022847C: jr          $ra
    // 0x80228480: nop

    return;
    // 0x80228480: nop

;}
RECOMP_FUNC void M10_FUN_80228484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228484: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80228488: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8022848C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80228490: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80228494: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80228498: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8022849C: sb          $zero, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = 0;
    // 0x802284A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x802284A4: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x802284A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x802284AC: jal         0x80002364
    // 0x802284B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_0;
    // 0x802284B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x802284B4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802284B8: sh          $zero, 0x96($s1)
    MEM_H(0X96, ctx->r17) = 0;
    // 0x802284BC: sh          $zero, 0x94($s1)
    MEM_H(0X94, ctx->r17) = 0;
    // 0x802284C0: sb          $zero, 0x99($s1)
    MEM_B(0X99, ctx->r17) = 0;
    // 0x802284C4: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x802284C8: sb          $zero, 0x9B($s1)
    MEM_B(0X9B, ctx->r17) = 0;
    // 0x802284CC: sb          $zero, 0x9A($s1)
    MEM_B(0X9A, ctx->r17) = 0;
    // 0x802284D0: jal         0x80228298
    // 0x802284D4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x80228298)(rdram, ctx);
        goto after_1;
    // 0x802284D4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_1:
    // 0x802284D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802284DC: jal         0x80228298
    // 0x802284E0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x80228298)(rdram, ctx);
        goto after_2;
    // 0x802284E0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_2:
    // 0x802284E4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x802284E8: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x802284EC: sb          $zero, 0x90($s1)
    MEM_B(0X90, ctx->r17) = 0;
    // 0x802284F0: lh          $t9, 0x492($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X492);
    // 0x802284F4: lh          $t0, 0x82E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X82E);
    // 0x802284F8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802284FC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80228500: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80228504: addiu       $v0, $v0, -0x13A0
    ctx->r2 = ADD32(ctx->r2, -0X13A0);
    // 0x80228508: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022850C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80228510: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80228514: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80228518: jal         0x802269B0
    // 0x8022851C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    LOOKUP_FUNC(0x802269B0)(rdram, ctx);
        goto after_3;
    // 0x8022851C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    after_3:
    // 0x80228520: jal         0x802269D8
    // 0x80228524: nop

    LOOKUP_FUNC(0x802269D8)(rdram, ctx);
        goto after_4;
    // 0x80228524: nop

    after_4:
    // 0x80228528: jal         0x80146AF4
    // 0x8022852C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80146AF4)(rdram, ctx);
        goto after_5;
    // 0x8022852C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80228530: jal         0x80146AE4
    // 0x80228534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80146AE4)(rdram, ctx);
        goto after_6;
    // 0x80228534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80228538: jal         0x80116E80
    // 0x8022853C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_7;
    // 0x8022853C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_7:
    // 0x80228540: jal         0x80116E80
    // 0x80228544: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_8;
    // 0x80228544: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_8:
    // 0x80228548: jal         0x80116E80
    // 0x8022854C: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_9;
    // 0x8022854C: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_9:
    // 0x80228550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80228554: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80228558: jal         0x80226AA4
    // 0x8022855C: addiu       $a2, $sp, 0x2E
    ctx->r6 = ADD32(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x80226AA4)(rdram, ctx);
        goto after_10;
    // 0x8022855C: addiu       $a2, $sp, 0x2E
    ctx->r6 = ADD32(ctx->r29, 0X2E);
    after_10:
    // 0x80228560: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
    // 0x80228564: jal         0x80226A2C
    // 0x80228568: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80226A2C)(rdram, ctx);
        goto after_11;
    // 0x80228568: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x8022856C: jal         0x80147598
    // 0x80228570: nop

    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_12;
    // 0x80228570: nop

    after_12:
    // 0x80228574: beq         $v0, $zero, L_802285E4
    if (ctx->r2 == 0) {
        // 0x80228578: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_802285E4;
    }
    // 0x80228578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8022857C: lh          $v0, 0x44C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X44C);
    // 0x80228580: beq         $v0, $zero, L_802285BC
    if (ctx->r2 == 0) {
        // 0x80228584: nop
    
            goto L_802285BC;
    }
    // 0x80228584: nop

    // 0x80228588: lh          $t1, 0x44E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X44E);
    // 0x8022858C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80228590: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80228594: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80228598: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022859C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802285A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x802285A4: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x802285A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x802285AC: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x802285B0: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x802285B4: nop

    // 0x802285B8: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
L_802285BC:
    // 0x802285BC: jal         0x80146CD4
    // 0x802285C0: lh          $a0, 0x2C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80146CD4)(rdram, ctx);
        goto after_13;
    // 0x802285C0: lh          $a0, 0x2C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2C);
    after_13:
    // 0x802285C4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x802285C8: lbu         $t5, -0x138D($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X138D);
    // 0x802285CC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x802285D0: lh          $a0, 0x2C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2C);
    // 0x802285D4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x802285D8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x802285DC: jal         0x80146BE0
    // 0x802285E0: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    LOOKUP_FUNC(0x80146BE0)(rdram, ctx);
        goto after_14;
    // 0x802285E0: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_14:
L_802285E4:
    // 0x802285E4: lh          $v0, 0x7E8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X7E8);
    // 0x802285E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802285EC: beq         $v0, $zero, L_80228628
    if (ctx->r2 == 0) {
        // 0x802285F0: nop
    
            goto L_80228628;
    }
    // 0x802285F0: nop

    // 0x802285F4: lh          $t8, 0x7EA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X7EA);
    // 0x802285F8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x802285FC: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80228600: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80228604: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80228608: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8022860C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80228610: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80228614: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80228618: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8022861C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80228620: nop

    // 0x80228624: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
L_80228628:
    // 0x80228628: jal         0x80146CD4
    // 0x8022862C: lh          $a0, 0x2C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80146CD4)(rdram, ctx);
        goto after_15;
    // 0x8022862C: lh          $a0, 0x2C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2C);
    after_15:
    // 0x80228630: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80228634: lbu         $t2, -0x1380($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X1380);
    // 0x80228638: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8022863C: lh          $a0, 0x2C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2C);
    // 0x80228640: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80228644: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80228648: jal         0x80146BE0
    // 0x8022864C: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    LOOKUP_FUNC(0x80146BE0)(rdram, ctx);
        goto after_16;
    // 0x8022864C: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    after_16:
    // 0x80228650: lh          $t4, 0x456($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X456);
    // 0x80228654: lh          $t7, 0x7F2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X7F2);
    // 0x80228658: lbu         $t2, 0x2F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2F);
    // 0x8022865C: sh          $t4, 0x494($s0)
    MEM_H(0X494, ctx->r16) = ctx->r12;
    // 0x80228660: sh          $t7, 0x830($s0)
    MEM_H(0X830, ctx->r16) = ctx->r15;
    // 0x80228664: lh          $t6, 0x494($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X494);
    // 0x80228668: lh          $t8, 0x830($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X830);
    // 0x8022866C: lh          $t9, 0x452($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X452);
    // 0x80228670: lh          $t0, 0x7EE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X7EE);
    // 0x80228674: sh          $t6, 0x496($s0)
    MEM_H(0X496, ctx->r16) = ctx->r14;
    // 0x80228678: sh          $t8, 0x832($s0)
    MEM_H(0X832, ctx->r16) = ctx->r24;
    // 0x8022867C: sh          $t9, 0x498($s0)
    MEM_H(0X498, ctx->r16) = ctx->r25;
    // 0x80228680: beq         $t2, $zero, L_802286A8
    if (ctx->r10 == 0) {
        // 0x80228684: sh          $t0, 0x834($s0)
        MEM_H(0X834, ctx->r16) = ctx->r8;
            goto L_802286A8;
    }
    // 0x80228684: sh          $t0, 0x834($s0)
    MEM_H(0X834, ctx->r16) = ctx->r8;
    // 0x80228688: jal         0x80005700
    // 0x8022868C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_17;
    // 0x8022868C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80228690: jal         0x801170DC
    // 0x80228694: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_18;
    // 0x80228694: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_18:
    // 0x80228698: jal         0x801170DC
    // 0x8022869C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_19;
    // 0x8022869C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_19:
    // 0x802286A0: b           L_802286C0
    // 0x802286A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_802286C0;
    // 0x802286A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802286A8:
    // 0x802286A8: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x802286AC: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x802286B0: addiu       $a1, $a1, -0x7930
    ctx->r5 = ADD32(ctx->r5, -0X7930);
    // 0x802286B4: jal         0x800058DC
    // 0x802286B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_20;
    // 0x802286B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x802286BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802286C0:
    // 0x802286C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802286C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802286C8: jr          $ra
    // 0x802286CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x802286CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802286d0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802286d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802286D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802286D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802286D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x802286DC: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x802286E0: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x802286E4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x802286E8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x802286EC: slti        $at, $t8, 0x12
    ctx->r1 = SIGNED(ctx->r24) < 0X12 ? 1 : 0;
    // 0x802286F0: bne         $at, $zero, L_80228700
    if (ctx->r1 != 0) {
        // 0x802286F4: sh          $t7, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r15;
            goto L_80228700;
    }
    // 0x802286F4: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x802286F8: jal         0x800058DC
    // 0x802286FC: addiu       $a1, $a1, -0x78F0
    ctx->r5 = ADD32(ctx->r5, -0X78F0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802286FC: addiu       $a1, $a1, -0x78F0
    ctx->r5 = ADD32(ctx->r5, -0X78F0);
    after_0:
L_80228700:
    // 0x80228700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80228704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80228708: jr          $ra
    // 0x8022870C: nop

    return;
    // 0x8022870C: nop

;}
RECOMP_FUNC void M10_FUN_80228710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228710: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80228714: addiu       $t1, $t1, -0x1398
    ctx->r9 = ADD32(ctx->r9, -0X1398);
    // 0x80228718: lbu         $t0, 0x1E($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X1E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022871c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022871c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022871C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80228720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80228724: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80228728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8022872C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80228730: blez        $t0, L_802287C0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80228734: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_802287C0;
    }
    // 0x80228734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80228738: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8022873C: addiu       $a0, $a0, 0x760
    ctx->r4 = ADD32(ctx->r4, 0X760);
    // 0x80228740: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80228744: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80228748: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
L_8022874C:
    // 0x8022874C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80228750: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80228754: lhu         $v0, 0x2A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2A);
    // 0x80228758: bne         $a1, $v0, L_80228788
    if (ctx->r5 != ctx->r2) {
        // 0x8022875C: nop
    
            goto L_80228788;
    }
    // 0x8022875C: nop

    // 0x80228760: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80228764: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80228768: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8022876C: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80228770: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80228774: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80228778: nop

    // 0x8022877C: addiu       $t5, $t4, -0x12C
    ctx->r13 = ADD32(ctx->r12, -0X12C);
    // 0x80228780: b           L_802287A8
    // 0x80228784: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
        goto L_802287A8;
    // 0x80228784: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
L_80228788:
    // 0x80228788: bnel        $a3, $v0, L_802287AC
    if (ctx->r7 != ctx->r2) {
        // 0x8022878C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_802287AC;
    }
    goto skip_0;
    // 0x8022878C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80228790: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80228794: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x80228798: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8022879C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x802287A0: addiu       $t2, $t9, -0x12C
    ctx->r10 = ADD32(ctx->r25, -0X12C);
    // 0x802287A4: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
L_802287A8:
    // 0x802287A8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_802287AC:
    // 0x802287AC: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x802287B0: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x802287B4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x802287B8: bnel        $at, $zero, L_8022874C
    if (ctx->r1 != 0) {
        // 0x802287BC: sll         $t6, $a2, 2
        ctx->r14 = S32(ctx->r6 << 2);
            goto L_8022874C;
    }
    goto skip_1;
    // 0x802287BC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    skip_1:
L_802287C0:
    // 0x802287C0: lbu         $t0, 0x1F($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X1F);
    // 0x802287C4: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x802287C8: addiu       $a0, $a0, 0x760
    ctx->r4 = ADD32(ctx->r4, 0X760);
    // 0x802287CC: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x802287D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x802287D4: beq         $at, $zero, L_80228854
    if (ctx->r1 == 0) {
        // 0x802287D8: addiu       $a3, $zero, 0xD
        ctx->r7 = ADD32(0, 0XD);
            goto L_80228854;
    }
    // 0x802287D8: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x802287DC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
L_802287E0:
    // 0x802287E0: addu        $t5, $s0, $t6
    ctx->r13 = ADD32(ctx->r16, ctx->r14);
    // 0x802287E4: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x802287E8: lhu         $v0, 0x2A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2A);
    // 0x802287EC: bne         $a1, $v0, L_8022881C
    if (ctx->r5 != ctx->r2) {
        // 0x802287F0: nop
    
            goto L_8022881C;
    }
    // 0x802287F0: nop

    // 0x802287F4: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x802287F8: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x802287FC: addu        $t5, $a0, $t6
    ctx->r13 = ADD32(ctx->r4, ctx->r14);
    // 0x80228800: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80228804: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80228808: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8022880C: nop

    // 0x80228810: addiu       $t4, $t2, 0x12C
    ctx->r12 = ADD32(ctx->r10, 0X12C);
    // 0x80228814: b           L_8022883C
    // 0x80228818: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
        goto L_8022883C;
    // 0x80228818: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
L_8022881C:
    // 0x8022881C: bnel        $a3, $v0, L_80228840
    if (ctx->r7 != ctx->r2) {
        // 0x80228820: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80228840;
    }
    goto skip_2;
    // 0x80228820: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80228824: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x80228828: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x8022882C: addu        $t2, $a0, $t3
    ctx->r10 = ADD32(ctx->r4, ctx->r11);
    // 0x80228830: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80228834: addiu       $t9, $t8, 0x12C
    ctx->r25 = ADD32(ctx->r24, 0X12C);
    // 0x80228838: sh          $t9, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r25;
L_8022883C:
    // 0x8022883C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80228840:
    // 0x80228840: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80228844: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80228848: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8022884C: bnel        $at, $zero, L_802287E0
    if (ctx->r1 != 0) {
        // 0x80228850: sll         $t6, $a2, 2
        ctx->r14 = S32(ctx->r6 << 2);
            goto L_802287E0;
    }
    goto skip_3;
    // 0x80228850: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    skip_3:
L_80228854:
    // 0x80228854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80228858: jal         0x802281BC
    // 0x8022885C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x802281BC)(rdram, ctx);
        goto after_0;
    // 0x8022885C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80228860: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80228864: addiu       $a1, $a1, -0x777C
    ctx->r5 = ADD32(ctx->r5, -0X777C);
    // 0x80228868: jal         0x800058DC
    // 0x8022886C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8022886C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80228870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80228874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80228878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8022887C: jr          $ra
    // 0x80228880: nop

    return;
    // 0x80228880: nop

;}
RECOMP_FUNC void M10_FUN_80228884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228884: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80228888: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8022888C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80228890: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80228894: lhu         $t7, 0x94($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X94);
    // 0x80228898: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022889C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x802288A0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x802288A4: sh          $t8, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r24;
    // 0x802288A8: lbu         $a2, -0x1379($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1379);
    // 0x802288AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x802288B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x802288B4: blez        $a2, L_80228A78
    if (SIGNED(ctx->r6) <= 0) {
        // 0x802288B8: addiu       $t1, $zero, 0xD
        ctx->r9 = ADD32(0, 0XD);
            goto L_80228A78;
    }
    // 0x802288B8: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x802288BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x802288C0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x802288C4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802288C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x802288CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x802288D0: addiu       $a1, $a1, 0x760
    ctx->r5 = ADD32(ctx->r5, 0X760);
    // 0x802288D4: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x802288D8: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
L_802288DC:
    // 0x802288DC: addu        $t2, $s0, $t9
    ctx->r10 = ADD32(ctx->r16, ctx->r25);
    // 0x802288E0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x802288E4: lhu         $v1, 0x2A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2A);
    // 0x802288E8: bne         $t0, $v1, L_802289BC
    if (ctx->r8 != ctx->r3) {
        // 0x802288EC: nop
    
            goto L_802289BC;
    }
    // 0x802288EC: nop

    // 0x802288F0: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x802288F4: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
    // 0x802288F8: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x802288FC: lwc1        $f14, 0x4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80228900: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80228904: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80228908: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8022890C: nop

    // 0x80228910: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80228914: sra         $t9, $t6, 16
    ctx->r25 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80228918: subu        $t2, $t5, $t9
    ctx->r10 = SUB32(ctx->r13, ctx->r25);
    // 0x8022891C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80228920: nop

    // 0x80228924: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80228928: div.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8022892C: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80228930: nop

    // 0x80228934: bc1tl       L_8022898C
    if (c1cs) {
        // 0x80228938: trunc.w.s   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8022898C;
    }
    goto skip_0;
    // 0x80228938: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_0:
    // 0x8022893C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80228940: nop

    // 0x80228944: bc1fl       L_80228958
    if (!c1cs) {
        // 0x80228948: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80228958;
    }
    goto skip_1;
    // 0x80228948: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x8022894C: b           L_80228958
    // 0x80228950: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80228958;
    // 0x80228950: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80228954: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80228958:
    // 0x80228958: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8022895C: nop

    // 0x80228960: bc1fl       L_8022898C
    if (!c1cs) {
        // 0x80228964: trunc.w.s   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8022898C;
    }
    goto skip_2;
    // 0x80228964: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_2:
    // 0x80228968: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8022896C: nop

    // 0x80228970: bc1fl       L_80228984
    if (!c1cs) {
        // 0x80228974: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80228984;
    }
    goto skip_3;
    // 0x80228974: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_3:
    // 0x80228978: b           L_80228984
    // 0x8022897C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80228984;
    // 0x8022897C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80228980: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80228984:
    // 0x80228984: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80228988: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
L_8022898C:
    // 0x8022898C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80228990: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80228994: nop

    // 0x80228998: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x8022899C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x802289A0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x802289A4: nop

    // 0x802289A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802289AC: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x802289B0: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x802289B4: b           L_80228A60
    // 0x802289B8: lbu         $a2, -0x1379($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1379);
        goto L_80228A60;
    // 0x802289B8: lbu         $a2, -0x1379($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1379);
L_802289BC:
    // 0x802289BC: bne         $t1, $v1, L_80228A60
    if (ctx->r9 != ctx->r3) {
        // 0x802289C0: sll         $t6, $a3, 1
        ctx->r14 = S32(ctx->r7 << 1);
            goto L_80228A60;
    }
    // 0x802289C0: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x802289C4: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x802289C8: addu        $t5, $a1, $t6
    ctx->r13 = ADD32(ctx->r5, ctx->r14);
    // 0x802289CC: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x802289D0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x802289D4: subu        $t2, $t9, $a0
    ctx->r10 = SUB32(ctx->r25, ctx->r4);
    // 0x802289D8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x802289DC: nop

    // 0x802289E0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802289E4: div.s       $f0, $f4, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x802289E8: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x802289EC: nop

    // 0x802289F0: bc1tl       L_80228A48
    if (c1cs) {
        // 0x802289F4: trunc.w.s   $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_80228A48;
    }
    goto skip_4;
    // 0x802289F4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_4:
    // 0x802289F8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x802289FC: nop

    // 0x80228A00: bc1fl       L_80228A14
    if (!c1cs) {
        // 0x80228A04: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80228A14;
    }
    goto skip_5;
    // 0x80228A04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_5:
    // 0x80228A08: b           L_80228A14
    // 0x80228A0C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80228A14;
    // 0x80228A0C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80228A10: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80228A14:
    // 0x80228A14: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80228A18: nop

    // 0x80228A1C: bc1fl       L_80228A48
    if (!c1cs) {
        // 0x80228A20: trunc.w.s   $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_80228A48;
    }
    goto skip_6;
    // 0x80228A20: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_6:
    // 0x80228A24: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80228A28: nop

    // 0x80228A2C: bc1fl       L_80228A40
    if (!c1cs) {
        // 0x80228A30: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80228A40;
    }
    goto skip_7;
    // 0x80228A30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_7:
    // 0x80228A34: b           L_80228A40
    // 0x80228A38: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80228A40;
    // 0x80228A38: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80228A3C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80228A40:
    // 0x80228A40: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80228A44: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
L_80228A48:
    // 0x80228A48: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80228A4C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80228A50: nop

    // 0x80228A54: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x80228A58: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x80228A5C: lbu         $a2, -0x1379($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1379);
L_80228A60:
    // 0x80228A60: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80228A64: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x80228A68: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80228A6C: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80228A70: bnel        $at, $zero, L_802288DC
    if (ctx->r1 != 0) {
        // 0x80228A74: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_802288DC;
    }
    goto skip_8;
    // 0x80228A74: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    skip_8:
L_80228A78:
    // 0x80228A78: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80228A7C: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80228A80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80228A84: lhu         $t9, 0x94($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X94);
    // 0x80228A88: addiu       $a1, $a1, -0x7544
    ctx->r5 = ADD32(ctx->r5, -0X7544);
    // 0x80228A8C: slti        $at, $t9, 0x3D
    ctx->r1 = SIGNED(ctx->r25) < 0X3D ? 1 : 0;
    // 0x80228A90: bnel        $at, $zero, L_80228AA8
    if (ctx->r1 != 0) {
        // 0x80228A94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80228AA8;
    }
    goto skip_9;
    // 0x80228A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80228A98: sb          $t2, 0x90($t5)
    MEM_B(0X90, ctx->r13) = ctx->r10;
    // 0x80228A9C: jal         0x800058DC
    // 0x80228AA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80228AA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80228AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80228AA8:
    // 0x80228AA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80228AAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80228AB0: sb          $zero, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = 0;
    // 0x80228AB4: jr          $ra
    // 0x80228AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80228AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80228abc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80228abc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228ABC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80228AC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80228AC4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80228AC8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80228ACC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80228AD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80228AD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80228AD8: lhu         $t6, 0x94($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X94);
    // 0x80228ADC: lhu         $t8, 0x96($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X96);
    // 0x80228AE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80228AE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80228AE8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80228AEC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80228AF0: sh          $t7, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r15;
    // 0x80228AF4: jal         0x8022811C
    // 0x80228AF8: sh          $t9, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r25;
    LOOKUP_FUNC(0x8022811C)(rdram, ctx);
        goto after_0;
    // 0x80228AF8: sh          $t9, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r25;
    after_0:
    // 0x80228AFC: jal         0x80236BA4
    // 0x80228B00: nop

    LOOKUP_FUNC(0x80236BA4)(rdram, ctx);
        goto after_1;
    // 0x80228B00: nop

    after_1:
    // 0x80228B04: bne         $v0, $zero, L_80228B24
    if (ctx->r2 != 0) {
        // 0x80228B08: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80228B24;
    }
    // 0x80228B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80228B0C: jal         0x80147148
    // 0x80228B10: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_2;
    // 0x80228B10: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x80228B14: jal         0x802269B0
    // 0x80228B18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x802269B0)(rdram, ctx);
        goto after_3;
    // 0x80228B18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80228B1C: b           L_80228BF8
    // 0x80228B20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80228BF8;
    // 0x80228B20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80228B24:
    // 0x80228B24: jal         0x802269C0
    // 0x80228B28: nop

    LOOKUP_FUNC(0x802269C0)(rdram, ctx);
        goto after_4;
    // 0x80228B28: nop

    after_4:
    // 0x80228B2C: bne         $v0, $zero, L_80228BF4
    if (ctx->r2 != 0) {
        // 0x80228B30: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80228BF4;
    }
    // 0x80228B30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80228B34: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80228B38: jal         0x80228320
    // 0x80228B3C: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
    LOOKUP_FUNC(0x80228320)(rdram, ctx);
        goto after_5;
    // 0x80228B3C: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
    after_5:
    // 0x80228B40: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80228B44: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
    // 0x80228B48: jal         0x80228320
    // 0x80228B4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80228320)(rdram, ctx);
        goto after_6;
    // 0x80228B4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x80228B50: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80228B54: addiu       $s1, $s1, -0x1398
    ctx->r17 = ADD32(ctx->r17, -0X1398);
    // 0x80228B58: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80228B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80228B60: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80228B64:
    // 0x80228B64: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x80228B68: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80228B6C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80228B70: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80228B74: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80228B78: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80228B7C: jal         0x802269CC
    // 0x80228B80: sb          $s4, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r20;
    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_7;
    // 0x80228B80: sb          $s4, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r20;
    after_7:
    // 0x80228B84: lbu         $t5, 0xD($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XD);
    // 0x80228B88: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80228B8C: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80228B90: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80228B94: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80228B98: jal         0x802269CC
    // 0x80228B9C: sb          $v0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r2;
    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_8;
    // 0x80228B9C: sb          $v0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r2;
    after_8:
    // 0x80228BA0: lbu         $t0, 0x17($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X17);
    // 0x80228BA4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80228BA8: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80228BAC: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80228BB0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80228BB4: jal         0x80147598
    // 0x80228BB8: sb          $v0, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r2;
    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_9;
    // 0x80228BB8: sb          $v0, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r2;
    after_9:
    // 0x80228BBC: beq         $v0, $zero, L_80228BDC
    if (ctx->r2 == 0) {
        // 0x80228BC0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80228BDC;
    }
    // 0x80228BC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80228BC4: lbu         $t5, 0xA($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XA);
    // 0x80228BC8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80228BCC: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80228BD0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80228BD4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80228BD8: sb          $s4, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r20;
L_80228BDC:
    // 0x80228BDC: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80228BE0: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x80228BE4: bne         $at, $zero, L_80228B64
    if (ctx->r1 != 0) {
        // 0x80228BE8: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_80228B64;
    }
    // 0x80228BE8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80228BEC: jal         0x802269B0
    // 0x80228BF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802269B0)(rdram, ctx);
        goto after_10;
    // 0x80228BF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
L_80228BF4:
    // 0x80228BF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80228BF8:
    // 0x80228BF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80228BFC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80228C00: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80228C04: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80228C08: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80228C0C: jr          $ra
    // 0x80228C10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80228C10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80228c14(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80228c14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228C14: nop

    // 0x80228C18: nop

    // 0x80228C1C: nop

;}
RECOMP_FUNC void M10_FUN_80228c20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80228C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80228C28: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80228C2C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80228C30: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x80228C34: lw          $t6, 0xDC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XDC);
    // 0x80228C38: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80228C3C: bnel        $t6, $t8, L_80228C84
    if (ctx->r14 != ctx->r24) {
        // 0x80228C40: lw          $t4, 0x448($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X448);
            goto L_80228C84;
    }
    goto skip_0;
    // 0x80228C40: lw          $t4, 0x448($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X448);
    skip_0:
    // 0x80228C44: lw          $t9, 0x448($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X448);
    // 0x80228C48: lw          $t2, 0xE0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XE0);
    // 0x80228C4C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80228C50: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x80228C54: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x80228C58: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80228C5C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80228C60: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x80228C64: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80228C68: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80228C6C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80228C70: jal         0x8001EF38
    // 0x80228C74: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x80228C74: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x80228C78: b           L_80228CB8
    // 0x80228C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80228CB8;
    // 0x80228C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80228C80: lw          $t4, 0x448($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X448);
L_80228C84:
    // 0x80228C84: lw          $t3, 0xE0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XE0);
    // 0x80228C88: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80228C8C: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x80228C90: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x80228C94: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80228C98: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80228C9C: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80228CA0: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80228CA4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80228CA8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80228CAC: jal         0x8001EF38
    // 0x80228CB0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x80228CB0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80228CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80228CB8:
    // 0x80228CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80228CBC: jr          $ra
    // 0x80228CC0: nop

    return;
    // 0x80228CC0: nop

;}
RECOMP_FUNC void M10_FUN_80228cc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80228CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80228CCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80228CD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80228CD4: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80228CD8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80228CDC: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x80228CE0: lw          $t6, 0xDC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XDC);
    // 0x80228CE4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80228CE8: bnel        $t6, $t8, L_80228D40
    if (ctx->r14 != ctx->r24) {
        // 0x80228CEC: lw          $t4, 0x448($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X448);
            goto L_80228D40;
    }
    goto skip_0;
    // 0x80228CEC: lw          $t4, 0x448($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X448);
    skip_0:
    // 0x80228CF0: lw          $t9, 0x448($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X448);
    // 0x80228CF4: lw          $t2, 0xE0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XE0);
    // 0x80228CF8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80228CFC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80228D00: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x80228D04: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x80228D08: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80228D0C: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80228D10: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x80228D14: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80228D18: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80228D1C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80228D20: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80228D24: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80228D28: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80228D2C: jal         0x8001EF38
    // 0x80228D30: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x80228D30: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80228D34: b           L_80228D84
    // 0x80228D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80228D84;
    // 0x80228D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80228D3C: lw          $t4, 0x448($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X448);
L_80228D40:
    // 0x80228D40: lw          $t3, 0xE0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XE0);
    // 0x80228D44: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80228D48: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80228D4C: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x80228D50: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x80228D54: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80228D58: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80228D5C: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80228D60: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80228D64: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80228D68: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80228D6C: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80228D70: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80228D74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80228D78: jal         0x8001EF38
    // 0x80228D7C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x80228D7C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80228D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80228D84:
    // 0x80228D84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80228D88: jr          $ra
    // 0x80228D8C: nop

    return;
    // 0x80228D8C: nop

;}
RECOMP_FUNC void M10_FUN_80228d90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228D90: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80228D94: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80228D98: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80228D9C: lw          $v1, 0xC($t6)
    ctx->r3 = MEM_W(ctx->r14, 0XC);
    // 0x80228DA0: lw          $a1, 0xDC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XDC);
    // 0x80228DA4: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80228DA8: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80228DAC: bne         $a1, $v1, L_80228DBC
    if (ctx->r5 != ctx->r3) {
        // 0x80228DB0: lh          $v0, 0x12($t8)
        ctx->r2 = MEM_H(ctx->r24, 0X12);
            goto L_80228DBC;
    }
    // 0x80228DB0: lh          $v0, 0x12($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X12);
    // 0x80228DB4: b           L_80228DC0
    // 0x80228DB8: lh          $a0, 0x75C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X75C);
        goto L_80228DC0;
    // 0x80228DB8: lh          $a0, 0x75C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X75C);
L_80228DBC:
    // 0x80228DBC: lh          $a0, 0xAF8($a2)
    ctx->r4 = MEM_H(ctx->r6, 0XAF8);
L_80228DC0:
    // 0x80228DC0: bnel        $a1, $v1, L_80228DD4
    if (ctx->r5 != ctx->r3) {
        // 0x80228DC4: lh          $v1, 0xB98($a2)
        ctx->r3 = MEM_H(ctx->r6, 0XB98);
            goto L_80228DD4;
    }
    goto skip_0;
    // 0x80228DC4: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
    skip_0:
    // 0x80228DC8: b           L_80228DE0
    // 0x80228DCC: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
        goto L_80228DE0;
    // 0x80228DCC: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
    // 0x80228DD0: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
L_80228DD4:
    // 0x80228DD4: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    // 0x80228DD8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80228DDC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80228DE0:
    // 0x80228DE0: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x80228DE4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80228DE8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80228DEC: andi        $a2, $a1, 0x1000
    ctx->r6 = ctx->r5 & 0X1000;
    // 0x80228DF0: beq         $a2, $zero, L_80228E04
    if (ctx->r6 == 0) {
        // 0x80228DF4: andi        $v1, $a1, 0x1FFF
        ctx->r3 = ctx->r5 & 0X1FFF;
            goto L_80228E04;
    }
    // 0x80228DF4: andi        $v1, $a1, 0x1FFF
    ctx->r3 = ctx->r5 & 0X1FFF;
    // 0x80228DF8: andi        $v1, $a1, 0x1FFF
    ctx->r3 = ctx->r5 & 0X1FFF;
    // 0x80228DFC: b           L_80228E08
    // 0x80228E00: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
        goto L_80228E08;
    // 0x80228E00: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
L_80228E04:
    // 0x80228E04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80228E08:
    // 0x80228E08: bgez        $v0, L_80228E2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80228E0C: nop
    
            goto L_80228E2C;
    }
    // 0x80228E0C: nop

    // 0x80228E10: beq         $a2, $zero, L_80228E24
    if (ctx->r6 == 0) {
        // 0x80228E14: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80228E24;
    }
    // 0x80228E14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80228E18: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
    // 0x80228E1C: b           L_80228E40
    // 0x80228E20: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80228E40;
    // 0x80228E20: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80228E24:
    // 0x80228E24: b           L_80228E40
    // 0x80228E28: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80228E40;
    // 0x80228E28: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80228E2C:
    // 0x80228E2C: beq         $a2, $zero, L_80228E3C
    if (ctx->r6 == 0) {
        // 0x80228E30: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80228E3C;
    }
    // 0x80228E30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80228E34: b           L_80228E3C
    // 0x80228E38: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
        goto L_80228E3C;
    // 0x80228E38: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
L_80228E3C:
    // 0x80228E3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80228E40:
    // 0x80228E40: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80228E44: beq         $at, $zero, L_80228E54
    if (ctx->r1 == 0) {
            // 0x80228E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x80228E54)(rdram, ctx);
    return;
    }
    // 0x80228E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80228E4C: jr          $ra
    // 0x80228E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80228E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80228e54(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80228e54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228E54: jr          $ra
    // 0x80228E58: nop

    return;
    // 0x80228E58: nop

;}
RECOMP_FUNC void M10_FUN_80228e5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228E5C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80228E60: lh          $t6, -0x41DE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X41DE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80228e64(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80228e64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228E64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80228E68: addiu       $t7, $zero, 0x2800
    ctx->r15 = ADD32(0, 0X2800);
    // 0x80228E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80228E70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80228E74: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80228E78: subu        $a3, $t7, $t6
    ctx->r7 = SUB32(ctx->r15, ctx->r14);
    // 0x80228E7C: lbu         $v0, 0xA4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA4);
    // 0x80228E80: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80228E84: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80228E88: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80228E8C: andi        $a3, $a3, 0x1FFF
    ctx->r7 = ctx->r7 & 0X1FFF;
    // 0x80228E90: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80228E94: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80228E98: beq         $at, $zero, L_80228F1C
    if (ctx->r1 == 0) {
        // 0x80228E9C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_80228F1C;
    }
    // 0x80228E9C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80228EA0: jal         0x80228C20
    // 0x80228EA4: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80228C20)(rdram, ctx);
        goto after_0;
    // 0x80228EA4: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80228EA8: lh          $a3, 0x1C($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1C);
    // 0x80228EAC: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x80228EB0: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    // 0x80228EB4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80228EB8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80228EBC: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80228EC0: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80228EC4: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    // 0x80228EC8: jal         0x8001EB64
    // 0x80228ECC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80228ECC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80228ED0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80228ED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80228ED8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80228EDC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80228EE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80228EE4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80228EE8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80228EEC: nop

    // 0x80228EF0: sh          $t9, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r25;
    // 0x80228EF4: jal         0x8001EAD0
    // 0x80228EF8: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80228EF8: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_2:
    // 0x80228EFC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80228F00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80228F04: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80228F08: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80228F0C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80228F10: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80228F14: b           L_80228FC0
    // 0x80228F18: sh          $t2, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r10;
        goto L_80228FC0;
    // 0x80228F18: sh          $t2, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r10;
L_80228F1C:
    // 0x80228F1C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80228F20: bne         $at, $zero, L_80228F34
    if (ctx->r1 != 0) {
        // 0x80228F24: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_80228F34;
    }
    // 0x80228F24: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80228F28: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80228F2C: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80228F30: bne         $at, $zero, L_80228FC0
    if (ctx->r1 != 0) {
        // 0x80228F34: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_80228FC0;
    }
L_80228F34:
    // 0x80228F34: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80228F38: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80228F3C: beql        $at, $zero, L_80228FC0
    if (ctx->r1 == 0) {
        // 0x80228F40: sb          $zero, 0xA4($a0)
        MEM_B(0XA4, ctx->r4) = 0;
            goto L_80228FC0;
    }
    goto skip_0;
    // 0x80228F40: sb          $zero, 0xA4($a0)
    MEM_B(0XA4, ctx->r4) = 0;
    skip_0:
    // 0x80228F44: jal         0x80228C20
    // 0x80228F48: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80228C20)(rdram, ctx);
        goto after_3;
    // 0x80228F48: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80228F4C: lh          $a3, 0x1C($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1C);
    // 0x80228F50: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x80228F54: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80228F58: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80228F5C: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80228F60: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80228F64: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    // 0x80228F68: jal         0x8001EB64
    // 0x80228F6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x80228F6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x80228F70: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80228F74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80228F78: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80228F7C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80228F80: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80228F84: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80228F88: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80228F8C: nop

    // 0x80228F90: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x80228F94: jal         0x8001EAD0
    // 0x80228F98: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x80228F98: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_5:
    // 0x80228F9C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80228FA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80228FA4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80228FA8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80228FAC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80228FB0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80228FB4: b           L_80228FC0
    // 0x80228FB8: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
        goto L_80228FC0;
    // 0x80228FB8: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
    // 0x80228FBC: sb          $zero, 0xA4($a0)
    MEM_B(0XA4, ctx->r4) = 0;
L_80228FC0:
    // 0x80228FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80228FC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80228FC8: jr          $ra
    // 0x80228FCC: nop

    return;
    // 0x80228FCC: nop

;}
RECOMP_FUNC void M10_FUN_80228fd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228FD0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80228FD4: lh          $t6, -0x41DE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X41DE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80228fd8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80228fd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228FD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80228FDC: addiu       $t7, $zero, 0x2800
    ctx->r15 = ADD32(0, 0X2800);
    // 0x80228FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80228FE4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80228FE8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80228FEC: subu        $v1, $t7, $t6
    ctx->r3 = SUB32(ctx->r15, ctx->r14);
    // 0x80228FF0: lw          $t8, 0x9C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C);
    // 0x80228FF4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80228FF8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80228FFC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80229000: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80229004: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80229008: and         $t9, $t8, $a2
    ctx->r25 = ctx->r24 & ctx->r6;
    // 0x8022900C: beq         $t9, $zero, L_80229040
    if (ctx->r25 == 0) {
        // 0x80229010: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_80229040;
    }
    // 0x80229010: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80229014: jal         0x80228C20
    // 0x80229018: sh          $v1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80228C20)(rdram, ctx);
        goto after_0;
    // 0x80229018: sh          $v1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8022901C: lh          $v1, 0x1C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1C);
    // 0x80229020: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80229024: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x80229028: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022902C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80229030: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80229034: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80229038: b           L_80229068
    // 0x8022903C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_80229068;
    // 0x8022903C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_80229040:
    // 0x80229040: jal         0x80228C20
    // 0x80229044: sh          $v1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80228C20)(rdram, ctx);
        goto after_1;
    // 0x80229044: sh          $v1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80229048: lh          $v1, 0x1C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1C);
    // 0x8022904C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80229050: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x80229054: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80229058: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022905C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80229060: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80229064: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_80229068:
    // 0x80229068: jal         0x8001EB64
    // 0x8022906C: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x8022906C: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    after_2:
    // 0x80229070: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80229074: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80229078: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8022907C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80229080: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80229084: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x80229088: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8022908C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80229090: jal         0x8001EAD0
    // 0x80229094: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x80229094: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    after_3:
    // 0x80229098: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8022909C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x802290A0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x802290A4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x802290A8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x802290AC: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x802290B0: nop

    // 0x802290B4: sh          $t4, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r12;
    // 0x802290B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802290BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802290C0: jr          $ra
    // 0x802290C4: nop

    return;
    // 0x802290C4: nop

;}
RECOMP_FUNC void M10_FUN_802290c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802290C8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802290CC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x802290D0: lh          $t6, 0x232($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X232);
    // 0x802290D4: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x802290D8: lwc1        $f4, 0xB94($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB94);
    // 0x802290DC: addiu       $t7, $zero, 0x2800
    ctx->r15 = ADD32(0, 0X2800);
    // 0x802290E0: subu        $a3, $t7, $t6
    ctx->r7 = SUB32(ctx->r15, ctx->r14);
    // 0x802290E4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x802290E8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x802290EC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802290f0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802290f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802290F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802290F4: andi        $a3, $a3, 0x1FFF
    ctx->r7 = ctx->r7 & 0X1FFF;
    // 0x802290F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x802290FC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80229100: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80229104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80229108: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8022910C: bc1f        L_8022911C
    if (!c1cs) {
        // 0x80229110: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_8022911C;
    }
    // 0x80229110: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80229114: b           L_80229120
    // 0x80229118: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
        goto L_80229120;
    // 0x80229118: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
L_8022911C:
    // 0x8022911C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80229120:
    // 0x80229120: lw          $t8, 0x9C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C);
    // 0x80229124: and         $t9, $t8, $a2
    ctx->r25 = ctx->r24 & ctx->r6;
    // 0x80229128: beql        $t9, $zero, L_8022916C
    if (ctx->r25 == 0) {
        // 0x8022912C: sh          $v1, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r3;
            goto L_8022916C;
    }
    goto skip_0;
    // 0x8022912C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    skip_0:
    // 0x80229130: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // 0x80229134: jal         0x80228C20
    // 0x80229138: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80228C20)(rdram, ctx);
        goto after_0;
    // 0x80229138: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8022913C: lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1A);
    // 0x80229140: lh          $a3, 0x1C($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1C);
    // 0x80229144: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x80229148: addu        $a0, $t0, $a3
    ctx->r4 = ADD32(ctx->r8, ctx->r7);
    // 0x8022914C: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x80229150: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80229154: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80229158: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8022915C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80229160: b           L_8022919C
    // 0x80229164: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8022919C;
    // 0x80229164: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80229168: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
L_8022916C:
    // 0x8022916C: jal         0x80228C20
    // 0x80229170: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80228C20)(rdram, ctx);
        goto after_1;
    // 0x80229170: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80229174: lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1A);
    // 0x80229178: lh          $a3, 0x1C($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1C);
    // 0x8022917C: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // 0x80229180: addu        $a0, $t1, $a3
    ctx->r4 = ADD32(ctx->r9, ctx->r7);
    // 0x80229184: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x80229188: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022918C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80229190: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80229194: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80229198: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8022919C:
    // 0x8022919C: jal         0x8001EB64
    // 0x802291A0: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x802291A0: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    after_2:
    // 0x802291A4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x802291A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x802291AC: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x802291B0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x802291B4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x802291B8: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x802291BC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x802291C0: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x802291C4: jal         0x8001EAD0
    // 0x802291C8: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x802291C8: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    after_3:
    // 0x802291CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x802291D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x802291D4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x802291D8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x802291DC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x802291E0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x802291E4: nop

    // 0x802291E8: sh          $t7, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r15;
    // 0x802291EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802291F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802291F4: jr          $ra
    // 0x802291F8: nop

    return;
    // 0x802291F8: nop

;}
RECOMP_FUNC void M10_FUN_802291fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802291FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80229200: lw          $v0, 0x38($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X38);
    // 0x80229204: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80229208: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x8022920C: beq         $t6, $zero, L_80229250
    if (ctx->r14 == 0) {
        // 0x80229210: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_80229250;
    }
    // 0x80229210: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80229214: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80229218: bnel        $t8, $zero, L_80229254
    if (ctx->r24 != 0) {
        // 0x8022921C: sb          $zero, 0x94($a0)
        MEM_B(0X94, ctx->r4) = 0;
            goto L_80229254;
    }
    goto skip_0;
    // 0x8022921C: sb          $zero, 0x94($a0)
    MEM_B(0X94, ctx->r4) = 0;
    skip_0:
    // 0x80229220: lbu         $v1, 0x94($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X94);
    // 0x80229224: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80229228: slt         $v0, $a3, $v1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8022922C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80229230: beq         $v0, $zero, L_80229248
    if (ctx->r2 == 0) {
        // 0x80229234: sb          $t9, 0x94($a0)
        MEM_B(0X94, ctx->r4) = ctx->r25;
            goto L_80229248;
    }
    // 0x80229234: sb          $t9, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r25;
    // 0x80229238: sh          $t0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r8;
    // 0x8022923C: sb          $zero, 0x94($a0)
    MEM_B(0X94, ctx->r4) = 0;
    // 0x80229240: jr          $ra
    // 0x80229244: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80229244: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80229248:
    // 0x80229248: jr          $ra
    // 0x8022924C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8022924C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80229250:
    // 0x80229250: sb          $zero, 0x94($a0)
    MEM_B(0X94, ctx->r4) = 0;
L_80229254:
    // 0x80229254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80229258: jr          $ra
    // 0x8022925C: nop

    return;
    // 0x8022925C: nop

;}
RECOMP_FUNC void M10_FUN_80229260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80229260: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80229264: lw          $v0, 0x38($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X38);
    // 0x80229268: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8022926C: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x80229270: beq         $t6, $zero, L_802292C0
    if (ctx->r14 == 0) {
        // 0x80229274: sll         $t8, $v0, 3
        ctx->r24 = S32(ctx->r2 << 3);
            goto L_802292C0;
    }
    // 0x80229274: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80229278: bgez        $t8, L_802292C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8022927C: sll         $t9, $v0, 4
        ctx->r25 = S32(ctx->r2 << 4);
            goto L_802292C0;
    }
    // 0x8022927C: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80229280: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x80229284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80229288: bnel        $t0, $at, L_802292C4
    if (ctx->r8 != ctx->r1) {
        // 0x8022928C: sb          $zero, 0xA8($a0)
        MEM_B(0XA8, ctx->r4) = 0;
            goto L_802292C4;
    }
    goto skip_0;
    // 0x8022928C: sb          $zero, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = 0;
    skip_0:
    // 0x80229290: lbu         $v0, 0xA8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA8);
    // 0x80229294: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80229298: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8022929C: beq         $at, $zero, L_802292B4
    if (ctx->r1 == 0) {
        // 0x802292A0: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_802292B4;
    }
    // 0x802292A0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x802292A4: sh          $t1, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r9;
    // 0x802292A8: sb          $zero, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = 0;
    // 0x802292AC: jr          $ra
    // 0x802292B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x802292B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_802292B4:
    // 0x802292B4: sb          $t2, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = ctx->r10;
    // 0x802292B8: jr          $ra
    // 0x802292BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x802292BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_802292C0:
    // 0x802292C0: sb          $zero, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = 0;
L_802292C4:
    // 0x802292C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802292C8: jr          $ra
    // 0x802292CC: nop

    return;
    // 0x802292CC: nop

;}
RECOMP_FUNC void M10_FUN_802292d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802292D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x802292D4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x802292D8: lbu         $a2, 0x2D9($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X2D9);
    // 0x802292DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802292E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802292E4: slti        $at, $a2, 0x25
    ctx->r1 = SIGNED(ctx->r6) < 0X25 ? 1 : 0;
    // 0x802292E8: beq         $at, $zero, L_802293F8
    if (ctx->r1 == 0) {
        // 0x802292EC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_802293F8;
    }
    // 0x802292EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x802292F0: slti        $at, $a2, 0xE
    ctx->r1 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // 0x802292F4: bne         $at, $zero, L_80229300
    if (ctx->r1 != 0) {
        // 0x802292F8: sll         $t6, $a2, 3
        ctx->r14 = S32(ctx->r6 << 3);
            goto L_80229300;
    }
    // 0x802292F8: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x802292FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80229300:
    // 0x80229300: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80229304: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80229308: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8022930C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80229310: lbu         $a0, 0x42A9($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X42A9);
    // 0x80229314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80229318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022931C: beq         $a3, $a0, L_8022932C
    if (ctx->r7 == ctx->r4) {
        // 0x80229320: addiu       $t7, $zero, 0x20
        ctx->r15 = ADD32(0, 0X20);
            goto L_8022932C;
    }
    // 0x80229320: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80229324: bnel        $a0, $at, L_80229334
    if (ctx->r4 != ctx->r1) {
        // 0x80229328: lbu         $a0, 0x332($a1)
        ctx->r4 = MEM_BU(ctx->r5, 0X332);
            goto L_80229334;
    }
    goto skip_0;
    // 0x80229328: lbu         $a0, 0x332($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X332);
    skip_0:
L_8022932C:
    // 0x8022932C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80229330: lbu         $a0, 0x332($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X332);
L_80229334:
    // 0x80229334: beq         $a0, $zero, L_80229384
    if (ctx->r4 == 0) {
        // 0x80229338: nop
    
            goto L_80229384;
    }
    // 0x80229338: nop

    // 0x8022933C: beq         $a0, $a3, L_8022935C
    if (ctx->r4 == ctx->r7) {
        // 0x80229340: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8022935C;
    }
    // 0x80229340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80229344: beq         $a0, $at, L_80229368
    if (ctx->r4 == ctx->r1) {
        // 0x80229348: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80229368;
    }
    // 0x80229348: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022934C: beql        $a0, $at, L_80229378
    if (ctx->r4 == ctx->r1) {
        // 0x80229350: xori        $v0, $v0, 0x1
        ctx->r2 = ctx->r2 ^ 0X1;
            goto L_80229378;
    }
    goto skip_1;
    // 0x80229350: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    skip_1:
    // 0x80229354: b           L_80229384
    // 0x80229358: nop

        goto L_80229384;
    // 0x80229358: nop

L_8022935C:
    // 0x8022935C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80229360: b           L_80229384
    // 0x80229364: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80229384;
    // 0x80229364: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80229368:
    // 0x80229368: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8022936C: b           L_80229384
    // 0x80229370: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80229384;
    // 0x80229370: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80229374: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80229378:
    // 0x80229378: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8022937C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80229380: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80229384:
    // 0x80229384: beq         $v0, $zero, L_8022939C
    if (ctx->r2 == 0) {
        // 0x80229388: sh          $t7, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r15;
            goto L_8022939C;
    }
    // 0x80229388: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8022938C: bne         $v1, $zero, L_8022939C
    if (ctx->r3 != 0) {
        // 0x80229390: ori         $t9, $t7, 0x8
        ctx->r25 = ctx->r15 | 0X8;
            goto L_8022939C;
    }
    // 0x80229390: ori         $t9, $t7, 0x8
    ctx->r25 = ctx->r15 | 0X8;
    // 0x80229394: b           L_802293F8
    // 0x80229398: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
        goto L_802293F8;
    // 0x80229398: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
L_8022939C:
    // 0x8022939C: bne         $v0, $zero, L_802293BC
    if (ctx->r2 != 0) {
        // 0x802293A0: nop
    
            goto L_802293BC;
    }
    // 0x802293A0: nop

    // 0x802293A4: bne         $v1, $zero, L_802293BC
    if (ctx->r3 != 0) {
        // 0x802293A8: nop
    
            goto L_802293BC;
    }
    // 0x802293A8: nop

    // 0x802293AC: lhu         $t0, 0x2($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X2);
    // 0x802293B0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x802293B4: b           L_802293F8
    // 0x802293B8: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
        goto L_802293F8;
    // 0x802293B8: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
L_802293BC:
    // 0x802293BC: beq         $v0, $zero, L_802293DC
    if (ctx->r2 == 0) {
        // 0x802293C0: nop
    
            goto L_802293DC;
    }
    // 0x802293C0: nop

    // 0x802293C4: beq         $v1, $zero, L_802293DC
    if (ctx->r3 == 0) {
        // 0x802293C8: nop
    
            goto L_802293DC;
    }
    // 0x802293C8: nop

    // 0x802293CC: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x802293D0: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x802293D4: b           L_802293F8
    // 0x802293D8: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
        goto L_802293F8;
    // 0x802293D8: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_802293DC:
    // 0x802293DC: bnel        $v0, $zero, L_802293FC
    if (ctx->r2 != 0) {
        // 0x802293E0: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_802293FC;
    }
    goto skip_2;
    // 0x802293E0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_2:
    // 0x802293E4: beql        $v1, $zero, L_802293FC
    if (ctx->r3 == 0) {
        // 0x802293E8: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_802293FC;
    }
    goto skip_3;
    // 0x802293E8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_3:
    // 0x802293EC: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x802293F0: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x802293F4: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
L_802293F8:
    // 0x802293F8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_802293FC:
    // 0x802293FC: jr          $ra
    // 0x80229400: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80229400: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80229404(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80229404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80229404: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80229408: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022940c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022940c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022940C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80229410: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x80229414: bne         $a0, $t7, L_80229428
    if (ctx->r4 != ctx->r15) {
        // 0x80229418: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80229428;
    }
    // 0x80229418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022941C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80229420: b           L_80229430
    // 0x80229424: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
        goto L_80229430;
    // 0x80229424: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80229428:
    // 0x80229428: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022942C: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80229430:
    // 0x80229430: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80229434: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80229438: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x8022943C: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x80229440: bne         $t0, $at, L_80229478
    if (ctx->r8 != ctx->r1) {
        // 0x80229444: nop
    
            goto L_80229478;
    }
    // 0x80229444: nop

    // 0x80229448: jal         0x80376300
    // 0x8022944C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80376300)(rdram, ctx);
        goto after_0;
    // 0x8022944C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80229450: beq         $v0, $zero, L_80229468
    if (ctx->r2 == 0) {
        // 0x80229454: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80229468;
    }
    // 0x80229454: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80229458: lw          $t1, 0x334($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X334);
    // 0x8022945C: lbu         $t2, 0x81($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X81);
    // 0x80229460: b           L_802294A4
    // 0x80229464: sb          $t2, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r10;
        goto L_802294A4;
    // 0x80229464: sb          $t2, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r10;
L_80229468:
    // 0x80229468: lw          $t3, 0x334($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X334);
    // 0x8022946C: lbu         $t4, 0x7F($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X7F);
    // 0x80229470: b           L_802294A4
    // 0x80229474: sb          $t4, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r12;
        goto L_802294A4;
    // 0x80229474: sb          $t4, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r12;
L_80229478:
    // 0x80229478: jal         0x80376300
    // 0x8022947C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80376300)(rdram, ctx);
        goto after_1;
    // 0x8022947C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80229480: beq         $v0, $zero, L_80229498
    if (ctx->r2 == 0) {
        // 0x80229484: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80229498;
    }
    // 0x80229484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80229488: lw          $t5, 0x334($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X334);
    // 0x8022948C: lbu         $t6, 0x80($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X80);
    // 0x80229490: b           L_802294A4
    // 0x80229494: sb          $t6, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r14;
        goto L_802294A4;
    // 0x80229494: sb          $t6, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r14;
L_80229498:
    // 0x80229498: lw          $t7, 0x334($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X334);
    // 0x8022949C: lbu         $t8, 0x82($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X82);
    // 0x802294A0: sb          $t8, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r24;
L_802294A4:
    // 0x802294A4: jal         0x80376BE4
    // 0x802294A8: nop

    LOOKUP_FUNC(0x80376BE4)(rdram, ctx);
        goto after_2;
    // 0x802294A8: nop

    after_2:
    // 0x802294AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802294B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802294B4: jr          $ra
    // 0x802294B8: nop

    return;
    // 0x802294B8: nop

;}
RECOMP_FUNC void M10_FUN_802294bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802294BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802294C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802294C4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x802294C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x802294CC: sb          $t6, 0x2D8($a0)
    MEM_B(0X2D8, ctx->r4) = ctx->r14;
    // 0x802294D0: lbu         $a0, 0x38F($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X38F);
    // 0x802294D4: jal         0x8022B640
    // 0x802294D8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_0;
    // 0x802294D8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x802294DC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x802294E0: lw          $t7, 0x334($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X334);
    // 0x802294E4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x802294E8: lbu         $t9, 0x7F($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7F);
    // 0x802294EC: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x802294F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802294F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802294F8: jr          $ra
    // 0x802294FC: nop

    return;
    // 0x802294FC: nop

;}
RECOMP_FUNC void M10_FUN_80229500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80229500: sb          $zero, 0x95($a0)
    MEM_B(0X95, ctx->r4) = 0;
    // 0x80229504: sb          $zero, 0x92($a0)
    MEM_B(0X92, ctx->r4) = 0;
    // 0x80229508: sh          $zero, 0x96($a0)
    MEM_H(0X96, ctx->r4) = 0;
    // 0x8022950C: sw          $zero, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = 0;
    // 0x80229510: sh          $zero, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = 0;
    // 0x80229514: sh          $zero, 0x98($a0)
    MEM_H(0X98, ctx->r4) = 0;
    // 0x80229518: sb          $zero, 0x94($a0)
    MEM_B(0X94, ctx->r4) = 0;
    // 0x8022951C: jr          $ra
    // 0x80229520: sb          $zero, 0x93($a0)
    MEM_B(0X93, ctx->r4) = 0;
    return;
    // 0x80229520: sb          $zero, 0x93($a0)
    MEM_B(0X93, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80229524(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80229524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80229524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80229528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022952C: lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X36);
    // 0x80229530: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80229534: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80229538: bne         $at, $zero, L_802295E4
    if (ctx->r1 != 0) {
        // 0x8022953C: slti        $at, $v0, 0xFE
        ctx->r1 = SIGNED(ctx->r2) < 0XFE ? 1 : 0;
            goto L_802295E4;
    }
    // 0x8022953C: slti        $at, $v0, 0xFE
    ctx->r1 = SIGNED(ctx->r2) < 0XFE ? 1 : 0;
    // 0x80229540: bne         $at, $zero, L_80229594
    if (ctx->r1 != 0) {
        // 0x80229544: slti        $at, $v0, 0x11F
        ctx->r1 = SIGNED(ctx->r2) < 0X11F ? 1 : 0;
            goto L_80229594;
    }
    // 0x80229544: slti        $at, $v0, 0x11F
    ctx->r1 = SIGNED(ctx->r2) < 0X11F ? 1 : 0;
    // 0x80229548: bne         $at, $zero, L_80229574
    if (ctx->r1 != 0) {
        // 0x8022954C: addiu       $t7, $v0, -0x119
        ctx->r15 = ADD32(ctx->r2, -0X119);
            goto L_80229574;
    }
    // 0x8022954C: addiu       $t7, $v0, -0x119
    ctx->r15 = ADD32(ctx->r2, -0X119);
    // 0x80229550: addiu       $t6, $v0, -0x143
    ctx->r14 = ADD32(ctx->r2, -0X143);
    // 0x80229554: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x80229558: beq         $at, $zero, L_80229CB0
    if (ctx->r1 == 0) {
        // 0x8022955C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80229CB0;
    }
    // 0x8022955C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80229560: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80229564: addu        $at, $at, $t6
    gpr jr_addend_8022956C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80229568: lw          $t6, -0xEA4($at)
    ctx->r14 = ADD32(ctx->r1, -0XEA4);
    // 0x8022956C: jr          $t6
    // 0x80229570: nop

    switch (jr_addend_8022956C >> 2) {
        case 0: goto L_802296D0; break;
        case 1: goto L_80229748; break;
        case 2: goto L_80229810; break;
        case 3: goto L_80229860; break;
        case 4: goto L_80229A40; break;
        case 5: goto L_80229C10; break;
        case 6: goto L_80229888; break;
        default: switch_error(__func__, 0x8022956C, 0x8023F15C);
    }
    // 0x80229570: nop

L_80229574:
    // 0x80229574: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80229578: beq         $at, $zero, L_80229CB0
    if (ctx->r1 == 0) {
        // 0x8022957C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80229CB0;
    }
    // 0x8022957C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80229580: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80229584: addu        $at, $at, $t7
    gpr jr_addend_8022958C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80229588: lw          $t7, -0xE88($at)
    ctx->r15 = ADD32(ctx->r1, -0XE88);
    // 0x8022958C: jr          $t7
    // 0x80229590: nop

    switch (jr_addend_8022958C >> 2) {
        case 0: goto L_80229770; break;
        case 1: goto L_80229720; break;
        case 2: goto L_80229C38; break;
        case 3: goto L_80229CB0; break;
        case 4: goto L_80229C60; break;
        case 5: goto L_80229C88; break;
        default: switch_error(__func__, 0x8022958C, 0x8023F178);
    }
    // 0x80229590: nop

L_80229594:
    // 0x80229594: slti        $at, $v0, 0x5E
    ctx->r1 = SIGNED(ctx->r2) < 0X5E ? 1 : 0;
    // 0x80229598: bne         $at, $zero, L_802295C4
    if (ctx->r1 != 0) {
        // 0x8022959C: addiu       $t9, $v0, -0x50
        ctx->r25 = ADD32(ctx->r2, -0X50);
            goto L_802295C4;
    }
    // 0x8022959C: addiu       $t9, $v0, -0x50
    ctx->r25 = ADD32(ctx->r2, -0X50);
    // 0x802295A0: addiu       $t8, $v0, -0xF0
    ctx->r24 = ADD32(ctx->r2, -0XF0);
    // 0x802295A4: sltiu       $at, $t8, 0xE
    ctx->r1 = ctx->r24 < 0XE ? 1 : 0;
    // 0x802295A8: beq         $at, $zero, L_80229CB0
    if (ctx->r1 == 0) {
        // 0x802295AC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80229CB0;
    }
    // 0x802295AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x802295B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802295B4: addu        $at, $at, $t8
    gpr jr_addend_802295BC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x802295B8: lw          $t8, -0xE70($at)
    ctx->r24 = ADD32(ctx->r1, -0XE70);
    // 0x802295BC: jr          $t8
    // 0x802295C0: nop

    switch (jr_addend_802295BC >> 2) {
        case 0: goto L_80229A68; break;
        case 1: goto L_80229A90; break;
        case 2: goto L_80229B08; break;
        case 3: goto L_802299C8; break;
        case 4: goto L_802298D8; break;
        case 5: goto L_80229900; break;
        case 6: goto L_80229928; break;
        case 7: goto L_80229CB0; break;
        case 8: goto L_80229CB0; break;
        case 9: goto L_802298B0; break;
        case 10: goto L_802299F0; break;
        case 11: goto L_80229A18; break;
        case 12: goto L_80229B30; break;
        case 13: goto L_80229B58; break;
        default: switch_error(__func__, 0x802295BC, 0x8023F190);
    }
    // 0x802295C0: nop

L_802295C4:
    // 0x802295C4: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x802295C8: beq         $at, $zero, L_80229CB0
    if (ctx->r1 == 0) {
        // 0x802295CC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80229CB0;
    }
    // 0x802295CC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x802295D0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802295D4: addu        $at, $at, $t9
    gpr jr_addend_802295DC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x802295D8: lw          $t9, -0xE38($at)
    ctx->r25 = ADD32(ctx->r1, -0XE38);
    // 0x802295DC: jr          $t9
    // 0x802295E0: nop

    switch (jr_addend_802295DC >> 2) {
        case 0: goto L_8022961C; break;
        case 1: goto L_80229658; break;
        case 2: goto L_80229680; break;
        case 3: goto L_802296A8; break;
        case 4: goto L_802297E8; break;
        case 5: goto L_80229798; break;
        case 6: goto L_80229AB8; break;
        case 7: goto L_80229838; break;
        case 8: goto L_802296F8; break;
        case 9: goto L_802297C0; break;
        case 10: goto L_80229950; break;
        case 11: goto L_80229978; break;
        case 12: goto L_80229AE0; break;
        case 13: goto L_802299A0; break;
        default: switch_error(__func__, 0x802295DC, 0x8023F1C8);
    }
    // 0x802295E0: nop

L_802295E4:
    // 0x802295E4: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x802295E8: beq         $v0, $at, L_80229BA4
    if (ctx->r2 == ctx->r1) {
        // 0x802295EC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80229BA4;
    }
    // 0x802295EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x802295F0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x802295F4: beq         $v0, $at, L_80229B80
    if (ctx->r2 == ctx->r1) {
        // 0x802295F8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80229B80;
    }
    // 0x802295F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x802295FC: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80229600: beq         $v0, $at, L_80229BEC
    if (ctx->r2 == ctx->r1) {
        // 0x80229604: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80229BEC;
    }
    // 0x80229604: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80229608: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8022960C: beq         $v0, $at, L_80229BC8
    if (ctx->r2 == ctx->r1) {
        // 0x80229610: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80229BC8;
    }
    // 0x80229610: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80229614: b           L_80229CB0
    // 0x80229618: nop

        goto L_80229CB0;
    // 0x80229618: nop

L_8022961C:
    // 0x8022961C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229620: addiu       $a1, $a1, -0x23BC
    ctx->r5 = ADD32(ctx->r5, -0X23BC);
    // 0x80229624: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80229628: jal         0x80005670
    // 0x8022962C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x8022962C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80229630: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229634: addiu       $a1, $a1, -0x23D0
    ctx->r5 = ADD32(ctx->r5, -0X23D0);
    // 0x80229638: jal         0x80005670
    // 0x8022963C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8022963C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80229640: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80229644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80229648: jal         0x80005670
    // 0x8022964C: addiu       $a1, $a1, -0x1D20
    ctx->r5 = ADD32(ctx->r5, -0X1D20);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x8022964C: addiu       $a1, $a1, -0x1D20
    ctx->r5 = ADD32(ctx->r5, -0X1D20);
    after_2:
    // 0x80229650: b           L_80229CD4
    // 0x80229654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229658:
    // 0x80229658: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022965C: addiu       $a1, $a1, -0x268C
    ctx->r5 = ADD32(ctx->r5, -0X268C);
    // 0x80229660: jal         0x80005670
    // 0x80229664: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x80229664: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80229668: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022966C: addiu       $a1, $a1, -0x26A0
    ctx->r5 = ADD32(ctx->r5, -0X26A0);
    // 0x80229670: jal         0x80005670
    // 0x80229674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_4;
    // 0x80229674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80229678: b           L_80229CD4
    // 0x8022967C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x8022967C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229680:
    // 0x80229680: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229684: addiu       $a1, $a1, -0x27EC
    ctx->r5 = ADD32(ctx->r5, -0X27EC);
    // 0x80229688: jal         0x80005670
    // 0x8022968C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x8022968C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x80229690: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229694: addiu       $a1, $a1, -0x2800
    ctx->r5 = ADD32(ctx->r5, -0X2800);
    // 0x80229698: jal         0x80005670
    // 0x8022969C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x8022969C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x802296A0: b           L_80229CD4
    // 0x802296A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802296A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802296A8:
    // 0x802296A8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802296AC: addiu       $a1, $a1, -0x263C
    ctx->r5 = ADD32(ctx->r5, -0X263C);
    // 0x802296B0: jal         0x80005670
    // 0x802296B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_7;
    // 0x802296B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x802296B8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802296BC: addiu       $a1, $a1, -0x2650
    ctx->r5 = ADD32(ctx->r5, -0X2650);
    // 0x802296C0: jal         0x80005670
    // 0x802296C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_8;
    // 0x802296C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x802296C8: b           L_80229CD4
    // 0x802296CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802296CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802296D0:
    // 0x802296D0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802296D4: addiu       $a1, $a1, -0x21CC
    ctx->r5 = ADD32(ctx->r5, -0X21CC);
    // 0x802296D8: jal         0x80005670
    // 0x802296DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_9;
    // 0x802296DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_9:
    // 0x802296E0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802296E4: addiu       $a1, $a1, -0x21E0
    ctx->r5 = ADD32(ctx->r5, -0X21E0);
    // 0x802296E8: jal         0x80005670
    // 0x802296EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_10;
    // 0x802296EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x802296F0: b           L_80229CD4
    // 0x802296F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802296F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802296F8:
    // 0x802296F8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802296FC: addiu       $a1, $a1, -0x233C
    ctx->r5 = ADD32(ctx->r5, -0X233C);
    // 0x80229700: jal         0x80005670
    // 0x80229704: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_11;
    // 0x80229704: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_11:
    // 0x80229708: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022970C: addiu       $a1, $a1, -0x2350
    ctx->r5 = ADD32(ctx->r5, -0X2350);
    // 0x80229710: jal         0x80005670
    // 0x80229714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_12;
    // 0x80229714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80229718: b           L_80229CD4
    // 0x8022971C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x8022971C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229720:
    // 0x80229720: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229724: addiu       $a1, $a1, -0x24AC
    ctx->r5 = ADD32(ctx->r5, -0X24AC);
    // 0x80229728: jal         0x80005670
    // 0x8022972C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_13;
    // 0x8022972C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_13:
    // 0x80229730: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229734: addiu       $a1, $a1, -0x24C0
    ctx->r5 = ADD32(ctx->r5, -0X24C0);
    // 0x80229738: jal         0x80005670
    // 0x8022973C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_14;
    // 0x8022973C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80229740: b           L_80229CD4
    // 0x80229744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229748:
    // 0x80229748: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022974C: addiu       $a1, $a1, -0x266C
    ctx->r5 = ADD32(ctx->r5, -0X266C);
    // 0x80229750: jal         0x80005670
    // 0x80229754: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_15;
    // 0x80229754: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_15:
    // 0x80229758: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022975C: addiu       $a1, $a1, -0x2680
    ctx->r5 = ADD32(ctx->r5, -0X2680);
    // 0x80229760: jal         0x80005670
    // 0x80229764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_16;
    // 0x80229764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80229768: b           L_80229CD4
    // 0x8022976C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x8022976C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229770:
    // 0x80229770: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229774: addiu       $a1, $a1, -0x23DC
    ctx->r5 = ADD32(ctx->r5, -0X23DC);
    // 0x80229778: jal         0x80005670
    // 0x8022977C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_17;
    // 0x8022977C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_17:
    // 0x80229780: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229784: addiu       $a1, $a1, -0x23F0
    ctx->r5 = ADD32(ctx->r5, -0X23F0);
    // 0x80229788: jal         0x80005670
    // 0x8022978C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_18;
    // 0x8022978C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x80229790: b           L_80229CD4
    // 0x80229794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229798:
    // 0x80229798: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022979C: addiu       $a1, $a1, -0x261C
    ctx->r5 = ADD32(ctx->r5, -0X261C);
    // 0x802297A0: jal         0x80005670
    // 0x802297A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_19;
    // 0x802297A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_19:
    // 0x802297A8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802297AC: addiu       $a1, $a1, -0x2630
    ctx->r5 = ADD32(ctx->r5, -0X2630);
    // 0x802297B0: jal         0x80005670
    // 0x802297B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_20;
    // 0x802297B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x802297B8: b           L_80229CD4
    // 0x802297BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802297BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802297C0:
    // 0x802297C0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802297C4: addiu       $a1, $a1, -0x232C
    ctx->r5 = ADD32(ctx->r5, -0X232C);
    // 0x802297C8: jal         0x80005670
    // 0x802297CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_21;
    // 0x802297CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_21:
    // 0x802297D0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802297D4: addiu       $a1, $a1, -0x2340
    ctx->r5 = ADD32(ctx->r5, -0X2340);
    // 0x802297D8: jal         0x80005670
    // 0x802297DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_22;
    // 0x802297DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x802297E0: b           L_80229CD4
    // 0x802297E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802297E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802297E8:
    // 0x802297E8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802297EC: addiu       $a1, $a1, -0x251C
    ctx->r5 = ADD32(ctx->r5, -0X251C);
    // 0x802297F0: jal         0x80005670
    // 0x802297F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_23;
    // 0x802297F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_23:
    // 0x802297F8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802297FC: addiu       $a1, $a1, -0x2530
    ctx->r5 = ADD32(ctx->r5, -0X2530);
    // 0x80229800: jal         0x80005670
    // 0x80229804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_24;
    // 0x80229804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x80229808: b           L_80229CD4
    // 0x8022980C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x8022980C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229810:
    // 0x80229810: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229814: addiu       $a1, $a1, -0x22BC
    ctx->r5 = ADD32(ctx->r5, -0X22BC);
    // 0x80229818: jal         0x80005670
    // 0x8022981C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_25;
    // 0x8022981C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_25:
    // 0x80229820: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229824: addiu       $a1, $a1, -0x22D0
    ctx->r5 = ADD32(ctx->r5, -0X22D0);
    // 0x80229828: jal         0x80005670
    // 0x8022982C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_26;
    // 0x8022982C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x80229830: b           L_80229CD4
    // 0x80229834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229838:
    // 0x80229838: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022983C: addiu       $a1, $a1, -0x24CC
    ctx->r5 = ADD32(ctx->r5, -0X24CC);
    // 0x80229840: jal         0x80005670
    // 0x80229844: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_27;
    // 0x80229844: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_27:
    // 0x80229848: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022984C: addiu       $a1, $a1, -0x24E0
    ctx->r5 = ADD32(ctx->r5, -0X24E0);
    // 0x80229850: jal         0x80005670
    // 0x80229854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_28;
    // 0x80229854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_28:
    // 0x80229858: b           L_80229CD4
    // 0x8022985C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x8022985C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229860:
    // 0x80229860: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229864: addiu       $a1, $a1, -0x267C
    ctx->r5 = ADD32(ctx->r5, -0X267C);
    // 0x80229868: jal         0x80005670
    // 0x8022986C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_29;
    // 0x8022986C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_29:
    // 0x80229870: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229874: addiu       $a1, $a1, -0x2690
    ctx->r5 = ADD32(ctx->r5, -0X2690);
    // 0x80229878: jal         0x80005670
    // 0x8022987C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_30;
    // 0x8022987C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x80229880: b           L_80229CD4
    // 0x80229884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229888:
    // 0x80229888: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022988C: addiu       $a1, $a1, -0x1FBC
    ctx->r5 = ADD32(ctx->r5, -0X1FBC);
    // 0x80229890: jal         0x80005670
    // 0x80229894: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_31;
    // 0x80229894: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_31:
    // 0x80229898: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022989C: addiu       $a1, $a1, -0x1FD0
    ctx->r5 = ADD32(ctx->r5, -0X1FD0);
    // 0x802298A0: jal         0x80005670
    // 0x802298A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_32;
    // 0x802298A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_32:
    // 0x802298A8: b           L_80229CD4
    // 0x802298AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802298AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802298B0:
    // 0x802298B0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802298B4: addiu       $a1, $a1, -0x257C
    ctx->r5 = ADD32(ctx->r5, -0X257C);
    // 0x802298B8: jal         0x80005670
    // 0x802298BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_33;
    // 0x802298BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_33:
    // 0x802298C0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802298C4: addiu       $a1, $a1, -0x2590
    ctx->r5 = ADD32(ctx->r5, -0X2590);
    // 0x802298C8: jal         0x80005670
    // 0x802298CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_34;
    // 0x802298CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_34:
    // 0x802298D0: b           L_80229CD4
    // 0x802298D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802298D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802298D8:
    // 0x802298D8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802298DC: addiu       $a1, $a1, -0x255C
    ctx->r5 = ADD32(ctx->r5, -0X255C);
    // 0x802298E0: jal         0x80005670
    // 0x802298E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_35;
    // 0x802298E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_35:
    // 0x802298E8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802298EC: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x802298F0: jal         0x80005670
    // 0x802298F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_36;
    // 0x802298F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
    // 0x802298F8: b           L_80229CD4
    // 0x802298FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802298FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229900:
    // 0x80229900: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229904: addiu       $a1, $a1, -0x27EC
    ctx->r5 = ADD32(ctx->r5, -0X27EC);
    // 0x80229908: jal         0x80005670
    // 0x8022990C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_37;
    // 0x8022990C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_37:
    // 0x80229910: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229914: addiu       $a1, $a1, -0x2800
    ctx->r5 = ADD32(ctx->r5, -0X2800);
    // 0x80229918: jal         0x80005670
    // 0x8022991C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_38;
    // 0x8022991C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_38:
    // 0x80229920: b           L_80229CD4
    // 0x80229924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229928:
    // 0x80229928: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022992C: addiu       $a1, $a1, -0x28CC
    ctx->r5 = ADD32(ctx->r5, -0X28CC);
    // 0x80229930: jal         0x80005670
    // 0x80229934: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_39;
    // 0x80229934: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_39:
    // 0x80229938: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022993C: addiu       $a1, $a1, -0x28E0
    ctx->r5 = ADD32(ctx->r5, -0X28E0);
    // 0x80229940: jal         0x80005670
    // 0x80229944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_40;
    // 0x80229944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_40:
    // 0x80229948: b           L_80229CD4
    // 0x8022994C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x8022994C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229950:
    // 0x80229950: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229954: addiu       $a1, $a1, -0x25BC
    ctx->r5 = ADD32(ctx->r5, -0X25BC);
    // 0x80229958: jal         0x80005670
    // 0x8022995C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_41;
    // 0x8022995C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_41:
    // 0x80229960: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229964: addiu       $a1, $a1, -0x25D0
    ctx->r5 = ADD32(ctx->r5, -0X25D0);
    // 0x80229968: jal         0x80005670
    // 0x8022996C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_42;
    // 0x8022996C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_42:
    // 0x80229970: b           L_80229CD4
    // 0x80229974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229978:
    // 0x80229978: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022997C: addiu       $a1, $a1, -0x237C
    ctx->r5 = ADD32(ctx->r5, -0X237C);
    // 0x80229980: jal         0x80005670
    // 0x80229984: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_43;
    // 0x80229984: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_43:
    // 0x80229988: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022998C: addiu       $a1, $a1, -0x2390
    ctx->r5 = ADD32(ctx->r5, -0X2390);
    // 0x80229990: jal         0x80005670
    // 0x80229994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_44;
    // 0x80229994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_44:
    // 0x80229998: b           L_80229CD4
    // 0x8022999C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x8022999C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802299A0:
    // 0x802299A0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802299A4: addiu       $a1, $a1, -0x25BC
    ctx->r5 = ADD32(ctx->r5, -0X25BC);
    // 0x802299A8: jal         0x80005670
    // 0x802299AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_45;
    // 0x802299AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_45:
    // 0x802299B0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802299B4: addiu       $a1, $a1, -0x25D0
    ctx->r5 = ADD32(ctx->r5, -0X25D0);
    // 0x802299B8: jal         0x80005670
    // 0x802299BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_46;
    // 0x802299BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_46:
    // 0x802299C0: b           L_80229CD4
    // 0x802299C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802299C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802299C8:
    // 0x802299C8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802299CC: addiu       $a1, $a1, -0x25CC
    ctx->r5 = ADD32(ctx->r5, -0X25CC);
    // 0x802299D0: jal         0x80005670
    // 0x802299D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_47;
    // 0x802299D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_47:
    // 0x802299D8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802299DC: addiu       $a1, $a1, -0x25E0
    ctx->r5 = ADD32(ctx->r5, -0X25E0);
    // 0x802299E0: jal         0x80005670
    // 0x802299E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_48;
    // 0x802299E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_48:
    // 0x802299E8: b           L_80229CD4
    // 0x802299EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x802299EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802299F0:
    // 0x802299F0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x802299F4: addiu       $a1, $a1, -0x281C
    ctx->r5 = ADD32(ctx->r5, -0X281C);
    // 0x802299F8: jal         0x80005670
    // 0x802299FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_49;
    // 0x802299FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_49:
    // 0x80229A00: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A04: addiu       $a1, $a1, -0x2830
    ctx->r5 = ADD32(ctx->r5, -0X2830);
    // 0x80229A08: jal         0x80005670
    // 0x80229A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_50;
    // 0x80229A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_50:
    // 0x80229A10: b           L_80229CD4
    // 0x80229A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229A18:
    // 0x80229A18: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A1C: addiu       $a1, $a1, -0x27FC
    ctx->r5 = ADD32(ctx->r5, -0X27FC);
    // 0x80229A20: jal         0x80005670
    // 0x80229A24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_51;
    // 0x80229A24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_51:
    // 0x80229A28: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A2C: addiu       $a1, $a1, -0x2810
    ctx->r5 = ADD32(ctx->r5, -0X2810);
    // 0x80229A30: jal         0x80005670
    // 0x80229A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_52;
    // 0x80229A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_52:
    // 0x80229A38: b           L_80229CD4
    // 0x80229A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229A40:
    // 0x80229A40: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A44: addiu       $a1, $a1, -0x252C
    ctx->r5 = ADD32(ctx->r5, -0X252C);
    // 0x80229A48: jal         0x80005670
    // 0x80229A4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_53;
    // 0x80229A4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_53:
    // 0x80229A50: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A54: addiu       $a1, $a1, -0x2540
    ctx->r5 = ADD32(ctx->r5, -0X2540);
    // 0x80229A58: jal         0x80005670
    // 0x80229A5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_54;
    // 0x80229A5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_54:
    // 0x80229A60: b           L_80229CD4
    // 0x80229A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229A68:
    // 0x80229A68: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A6C: addiu       $a1, $a1, -0x23BC
    ctx->r5 = ADD32(ctx->r5, -0X23BC);
    // 0x80229A70: jal         0x80005670
    // 0x80229A74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_55;
    // 0x80229A74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_55:
    // 0x80229A78: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A7C: addiu       $a1, $a1, -0x23D0
    ctx->r5 = ADD32(ctx->r5, -0X23D0);
    // 0x80229A80: jal         0x80005670
    // 0x80229A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_56;
    // 0x80229A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_56:
    // 0x80229A88: b           L_80229CD4
    // 0x80229A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229A90:
    // 0x80229A90: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229A94: addiu       $a1, $a1, -0x242C
    ctx->r5 = ADD32(ctx->r5, -0X242C);
    // 0x80229A98: jal         0x80005670
    // 0x80229A9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_57;
    // 0x80229A9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_57:
    // 0x80229AA0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229AA4: addiu       $a1, $a1, -0x2440
    ctx->r5 = ADD32(ctx->r5, -0X2440);
    // 0x80229AA8: jal         0x80005670
    // 0x80229AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_58;
    // 0x80229AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_58:
    // 0x80229AB0: b           L_80229CD4
    // 0x80229AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229AB8:
    // 0x80229AB8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229ABC: addiu       $a1, $a1, -0x23FC
    ctx->r5 = ADD32(ctx->r5, -0X23FC);
    // 0x80229AC0: jal         0x80005670
    // 0x80229AC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_59;
    // 0x80229AC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_59:
    // 0x80229AC8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229ACC: addiu       $a1, $a1, -0x2410
    ctx->r5 = ADD32(ctx->r5, -0X2410);
    // 0x80229AD0: jal         0x80005670
    // 0x80229AD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_60;
    // 0x80229AD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_60:
    // 0x80229AD8: b           L_80229CD4
    // 0x80229ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229AE0:
    // 0x80229AE0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229AE4: addiu       $a1, $a1, -0x25CC
    ctx->r5 = ADD32(ctx->r5, -0X25CC);
    // 0x80229AE8: jal         0x80005670
    // 0x80229AEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_61;
    // 0x80229AEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_61:
    // 0x80229AF0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229AF4: addiu       $a1, $a1, -0x25E0
    ctx->r5 = ADD32(ctx->r5, -0X25E0);
    // 0x80229AF8: jal         0x80005670
    // 0x80229AFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_62;
    // 0x80229AFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_62:
    // 0x80229B00: b           L_80229CD4
    // 0x80229B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229B08:
    // 0x80229B08: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B0C: addiu       $a1, $a1, -0x25FC
    ctx->r5 = ADD32(ctx->r5, -0X25FC);
    // 0x80229B10: jal         0x80005670
    // 0x80229B14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_63;
    // 0x80229B14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_63:
    // 0x80229B18: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B1C: addiu       $a1, $a1, -0x2610
    ctx->r5 = ADD32(ctx->r5, -0X2610);
    // 0x80229B20: jal         0x80005670
    // 0x80229B24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_64;
    // 0x80229B24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_64:
    // 0x80229B28: b           L_80229CD4
    // 0x80229B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229B30:
    // 0x80229B30: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B34: addiu       $a1, $a1, -0x267C
    ctx->r5 = ADD32(ctx->r5, -0X267C);
    // 0x80229B38: jal         0x80005670
    // 0x80229B3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_65;
    // 0x80229B3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_65:
    // 0x80229B40: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B44: addiu       $a1, $a1, -0x2690
    ctx->r5 = ADD32(ctx->r5, -0X2690);
    // 0x80229B48: jal         0x80005670
    // 0x80229B4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_66;
    // 0x80229B4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_66:
    // 0x80229B50: b           L_80229CD4
    // 0x80229B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229B58:
    // 0x80229B58: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B5C: addiu       $a1, $a1, -0x270C
    ctx->r5 = ADD32(ctx->r5, -0X270C);
    // 0x80229B60: jal         0x80005670
    // 0x80229B64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_67;
    // 0x80229B64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_67:
    // 0x80229B68: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B6C: addiu       $a1, $a1, -0x2720
    ctx->r5 = ADD32(ctx->r5, -0X2720);
    // 0x80229B70: jal         0x80005670
    // 0x80229B74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_68;
    // 0x80229B74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_68:
    // 0x80229B78: b           L_80229CD4
    // 0x80229B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229B80:
    // 0x80229B80: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B84: jal         0x80005670
    // 0x80229B88: addiu       $a1, $a1, -0x1F5C
    ctx->r5 = ADD32(ctx->r5, -0X1F5C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_69;
    // 0x80229B88: addiu       $a1, $a1, -0x1F5C
    ctx->r5 = ADD32(ctx->r5, -0X1F5C);
    after_69:
    // 0x80229B8C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229B90: addiu       $a1, $a1, -0x1F70
    ctx->r5 = ADD32(ctx->r5, -0X1F70);
    // 0x80229B94: jal         0x80005670
    // 0x80229B98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_70;
    // 0x80229B98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_70:
    // 0x80229B9C: b           L_80229CD4
    // 0x80229BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229BA4:
    // 0x80229BA4: lui         $a1, 0x8025
    ctx->r5 = S32(0X8025 << 16);
    // 0x80229BA8: jal         0x80005670
    // 0x80229BAC: addiu       $a1, $a1, -0x710C
    ctx->r5 = ADD32(ctx->r5, -0X710C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_71;
    // 0x80229BAC: addiu       $a1, $a1, -0x710C
    ctx->r5 = ADD32(ctx->r5, -0X710C);
    after_71:
    // 0x80229BB0: lui         $a1, 0x8025
    ctx->r5 = S32(0X8025 << 16);
    // 0x80229BB4: addiu       $a1, $a1, -0x7120
    ctx->r5 = ADD32(ctx->r5, -0X7120);
    // 0x80229BB8: jal         0x80005670
    // 0x80229BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_72;
    // 0x80229BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_72:
    // 0x80229BC0: b           L_80229CD4
    // 0x80229BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229BC8:
    // 0x80229BC8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229BCC: jal         0x80005670
    // 0x80229BD0: addiu       $a1, $a1, -0x242C
    ctx->r5 = ADD32(ctx->r5, -0X242C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_73;
    // 0x80229BD0: addiu       $a1, $a1, -0x242C
    ctx->r5 = ADD32(ctx->r5, -0X242C);
    after_73:
    // 0x80229BD4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229BD8: addiu       $a1, $a1, -0x2440
    ctx->r5 = ADD32(ctx->r5, -0X2440);
    // 0x80229BDC: jal         0x80005670
    // 0x80229BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_74;
    // 0x80229BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_74:
    // 0x80229BE4: b           L_80229CD4
    // 0x80229BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229BEC:
    // 0x80229BEC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229BF0: jal         0x80005670
    // 0x80229BF4: addiu       $a1, $a1, -0x1ECC
    ctx->r5 = ADD32(ctx->r5, -0X1ECC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_75;
    // 0x80229BF4: addiu       $a1, $a1, -0x1ECC
    ctx->r5 = ADD32(ctx->r5, -0X1ECC);
    after_75:
    // 0x80229BF8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229BFC: addiu       $a1, $a1, -0x1EE0
    ctx->r5 = ADD32(ctx->r5, -0X1EE0);
    // 0x80229C00: jal         0x80005670
    // 0x80229C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_76;
    // 0x80229C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_76:
    // 0x80229C08: b           L_80229CD4
    // 0x80229C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229C10:
    // 0x80229C10: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C14: addiu       $a1, $a1, -0x269C
    ctx->r5 = ADD32(ctx->r5, -0X269C);
    // 0x80229C18: jal         0x80005670
    // 0x80229C1C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_77;
    // 0x80229C1C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_77:
    // 0x80229C20: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C24: addiu       $a1, $a1, -0x26B0
    ctx->r5 = ADD32(ctx->r5, -0X26B0);
    // 0x80229C28: jal         0x80005670
    // 0x80229C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_78;
    // 0x80229C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_78:
    // 0x80229C30: b           L_80229CD4
    // 0x80229C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229C38:
    // 0x80229C38: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C3C: addiu       $a1, $a1, -0x23CC
    ctx->r5 = ADD32(ctx->r5, -0X23CC);
    // 0x80229C40: jal         0x80005670
    // 0x80229C44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_79;
    // 0x80229C44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_79:
    // 0x80229C48: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C4C: addiu       $a1, $a1, -0x23E0
    ctx->r5 = ADD32(ctx->r5, -0X23E0);
    // 0x80229C50: jal         0x80005670
    // 0x80229C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_80;
    // 0x80229C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_80:
    // 0x80229C58: b           L_80229CD4
    // 0x80229C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229C60:
    // 0x80229C60: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C64: addiu       $a1, $a1, -0x297C
    ctx->r5 = ADD32(ctx->r5, -0X297C);
    // 0x80229C68: jal         0x80005670
    // 0x80229C6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_81;
    // 0x80229C6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_81:
    // 0x80229C70: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C74: addiu       $a1, $a1, -0x2990
    ctx->r5 = ADD32(ctx->r5, -0X2990);
    // 0x80229C78: jal         0x80005670
    // 0x80229C7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_82;
    // 0x80229C7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_82:
    // 0x80229C80: b           L_80229CD4
    // 0x80229C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229C88:
    // 0x80229C88: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C8C: addiu       $a1, $a1, -0x237C
    ctx->r5 = ADD32(ctx->r5, -0X237C);
    // 0x80229C90: jal         0x80005670
    // 0x80229C94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_83;
    // 0x80229C94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_83:
    // 0x80229C98: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229C9C: addiu       $a1, $a1, -0x2390
    ctx->r5 = ADD32(ctx->r5, -0X2390);
    // 0x80229CA0: jal         0x80005670
    // 0x80229CA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_84;
    // 0x80229CA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_84:
    // 0x80229CA8: b           L_80229CD4
    // 0x80229CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80229CD4;
    // 0x80229CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229CB0:
    // 0x80229CB0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229CB4: addiu       $a1, $a1, -0x24AC
    ctx->r5 = ADD32(ctx->r5, -0X24AC);
    // 0x80229CB8: jal         0x80005670
    // 0x80229CBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_85;
    // 0x80229CBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_85:
    // 0x80229CC0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80229CC4: addiu       $a1, $a1, -0x24C0
    ctx->r5 = ADD32(ctx->r5, -0X24C0);
    // 0x80229CC8: jal         0x80005670
    // 0x80229CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_86;
    // 0x80229CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_86:
    // 0x80229CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80229CD4:
    // 0x80229CD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80229CD8: jr          $ra
    // 0x80229CDC: nop

    return;
    // 0x80229CDC: nop

;}
RECOMP_FUNC void M10_FUN_80229ce0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80229CE0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80229CE4: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80229ce8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80229ce8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80229CE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80229CEC: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x80229CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80229CF4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80229CF8: bne         $a1, $t7, L_80229D0C
    if (ctx->r5 != ctx->r15) {
        // 0x80229CFC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80229D0C;
    }
    // 0x80229CFC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80229D00: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80229D04: b           L_80229D14
    // 0x80229D08: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
        goto L_80229D14;
    // 0x80229D08: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_80229D0C:
    // 0x80229D0C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80229D10: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80229D14:
    // 0x80229D14: lbu         $v0, 0x2D8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
    // 0x80229D18: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80229D1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80229D20: bne         $t0, $v0, L_80229D78
    if (ctx->r8 != ctx->r2) {
        // 0x80229D24: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80229D78;
    }
    // 0x80229D24: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80229D28: lw          $a2, 0x38($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X38);
    // 0x80229D2C: srl         $t8, $a2, 31
    ctx->r24 = S32(U32(ctx->r6) >> 31);
    // 0x80229D30: beq         $t8, $zero, L_80229D78
    if (ctx->r24 == 0) {
        // 0x80229D34: sll         $t2, $a2, 3
        ctx->r10 = S32(ctx->r6 << 3);
            goto L_80229D78;
    }
    // 0x80229D34: sll         $t2, $a2, 3
    ctx->r10 = S32(ctx->r6 << 3);
    // 0x80229D38: bgez        $t2, L_80229D78
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80229D3C: nop
    
            goto L_80229D78;
    }
    // 0x80229D3C: nop

    // 0x80229D40: lbu         $a0, 0x38E($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X38E);
    // 0x80229D44: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80229D48: jal         0x8022B640
    // 0x80229D4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_0;
    // 0x80229D4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80229D50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80229D54: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80229D58: lw          $t3, 0x334($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X334);
    // 0x80229D5C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80229D60: lbu         $t5, 0x7D($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X7D);
    // 0x80229D64: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
    // 0x80229D68: lh          $t6, 0x9A($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X9A);
    // 0x80229D6C: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80229D70: b           L_8022A814
    // 0x80229D74: sh          $t7, 0x9A($a3)
    MEM_H(0X9A, ctx->r7) = ctx->r15;
        goto L_8022A814;
    // 0x80229D74: sh          $t7, 0x9A($a3)
    MEM_H(0X9A, ctx->r7) = ctx->r15;
L_80229D78:
    // 0x80229D78: beql        $t0, $v0, L_80229FB0
    if (ctx->r8 == ctx->r2) {
        // 0x80229D7C: lh          $t5, 0x0($a0)
        ctx->r13 = MEM_H(ctx->r4, 0X0);
            goto L_80229FB0;
    }
    goto skip_0;
    // 0x80229D7C: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    skip_0:
    // 0x80229D80: lh          $t8, 0x2BC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2BC);
    // 0x80229D84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80229D88: bgezl       $t8, L_80229DA8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80229D8C: lh          $t3, 0x2C0($a1)
        ctx->r11 = MEM_H(ctx->r5, 0X2C0);
            goto L_80229DA8;
    }
    goto skip_1;
    // 0x80229D8C: lh          $t3, 0x2C0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2C0);
    skip_1:
    // 0x80229D90: lh          $t9, 0x2BE($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2BE);
    // 0x80229D94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80229D98: bgezl       $t9, L_80229DA8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80229D9C: lh          $t3, 0x2C0($a1)
        ctx->r11 = MEM_H(ctx->r5, 0X2C0);
            goto L_80229DA8;
    }
    goto skip_2;
    // 0x80229D9C: lh          $t3, 0x2C0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2C0);
    skip_2:
    // 0x80229DA0: sb          $t2, 0x2D8($a1)
    MEM_B(0X2D8, ctx->r5) = ctx->r10;
    // 0x80229DA4: lh          $t3, 0x2C0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2C0);
L_80229DA8:
    // 0x80229DA8: bgezl       $t3, L_80229DC4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80229DAC: lbu         $v0, 0x2D8($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
            goto L_80229DC4;
    }
    goto skip_3;
    // 0x80229DAC: lbu         $v0, 0x2D8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
    skip_3:
    // 0x80229DB0: lh          $t4, 0x2C2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2C2);
    // 0x80229DB4: bgezl       $t4, L_80229DC4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80229DB8: lbu         $v0, 0x2D8($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
            goto L_80229DC4;
    }
    goto skip_4;
    // 0x80229DB8: lbu         $v0, 0x2D8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
    skip_4:
    // 0x80229DBC: sb          $zero, 0x2D8($a1)
    MEM_B(0X2D8, ctx->r5) = 0;
    // 0x80229DC0: lbu         $v0, 0x2D8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
L_80229DC4:
    // 0x80229DC4: bne         $v0, $zero, L_80229EAC
    if (ctx->r2 != 0) {
        // 0x80229DC8: nop
    
            goto L_80229EAC;
    }
    // 0x80229DC8: nop

    // 0x80229DCC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80229DD0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80229DD4: lh          $t5, 0x2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2);
    // 0x80229DD8: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x80229DDC: mflo        $t7
    ctx->r15 = lo;
    // 0x80229DE0: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80229DE4: beql        $at, $zero, L_80229DFC
    if (ctx->r1 == 0) {
        // 0x80229DE8: lbu         $v0, 0x33($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X33);
            goto L_80229DFC;
    }
    goto skip_5;
    // 0x80229DE8: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
    skip_5:
    // 0x80229DEC: lbu         $v0, 0x387($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X387);
    // 0x80229DF0: bnel        $v0, $zero, L_80229E10
    if (ctx->r2 != 0) {
        // 0x80229DF4: lw          $a2, 0x334($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X334);
            goto L_80229E10;
    }
    goto skip_6;
    // 0x80229DF4: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    skip_6:
    // 0x80229DF8: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
L_80229DFC:
    // 0x80229DFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80229E00: bne         $t0, $v0, L_80229E1C
    if (ctx->r8 != ctx->r2) {
        // 0x80229E04: nop
    
            goto L_80229E1C;
    }
    // 0x80229E04: nop

    // 0x80229E08: lbu         $v0, 0x387($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X387);
    // 0x80229E0C: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
L_80229E10:
    // 0x80229E10: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229E14: b           L_80229EA4
    // 0x80229E18: addiu       $a2, $a2, 0x6C
    ctx->r6 = ADD32(ctx->r6, 0X6C);
        goto L_80229EA4;
    // 0x80229E18: addiu       $a2, $a2, 0x6C
    ctx->r6 = ADD32(ctx->r6, 0X6C);
L_80229E1C:
    // 0x80229E1C: bne         $v0, $at, L_80229E40
    if (ctx->r2 != ctx->r1) {
        // 0x80229E20: lbu         $t8, 0x33($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X33);
            goto L_80229E40;
    }
    // 0x80229E20: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x80229E24: lbu         $v0, 0x386($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X386);
    // 0x80229E28: beq         $v0, $zero, L_80229E40
    if (ctx->r2 == 0) {
        // 0x80229E2C: nop
    
            goto L_80229E40;
    }
    // 0x80229E2C: nop

    // 0x80229E30: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229E34: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229E38: b           L_80229EA4
    // 0x80229E3C: addiu       $a2, $a2, 0x69
    ctx->r6 = ADD32(ctx->r6, 0X69);
        goto L_80229EA4;
    // 0x80229E3C: addiu       $a2, $a2, 0x69
    ctx->r6 = ADD32(ctx->r6, 0X69);
L_80229E40:
    // 0x80229E40: bnel        $t8, $zero, L_80229E68
    if (ctx->r24 != 0) {
        // 0x80229E44: lbu         $v0, 0x386($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X386);
            goto L_80229E68;
    }
    goto skip_7;
    // 0x80229E44: lbu         $v0, 0x386($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X386);
    skip_7:
    // 0x80229E48: lbu         $v0, 0x385($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X385);
    // 0x80229E4C: beql        $v0, $zero, L_80229E68
    if (ctx->r2 == 0) {
        // 0x80229E50: lbu         $v0, 0x386($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X386);
            goto L_80229E68;
    }
    goto skip_8;
    // 0x80229E50: lbu         $v0, 0x386($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X386);
    skip_8:
    // 0x80229E54: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229E58: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229E5C: b           L_80229EA4
    // 0x80229E60: addiu       $a2, $a2, 0x66
    ctx->r6 = ADD32(ctx->r6, 0X66);
        goto L_80229EA4;
    // 0x80229E60: addiu       $a2, $a2, 0x66
    ctx->r6 = ADD32(ctx->r6, 0X66);
    // 0x80229E64: lbu         $v0, 0x386($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X386);
L_80229E68:
    // 0x80229E68: beql        $v0, $zero, L_80229E84
    if (ctx->r2 == 0) {
        // 0x80229E6C: lbu         $v0, 0x385($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X385);
            goto L_80229E84;
    }
    goto skip_9;
    // 0x80229E6C: lbu         $v0, 0x385($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X385);
    skip_9:
    // 0x80229E70: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229E74: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229E78: b           L_80229EA4
    // 0x80229E7C: addiu       $a2, $a2, 0x69
    ctx->r6 = ADD32(ctx->r6, 0X69);
        goto L_80229EA4;
    // 0x80229E7C: addiu       $a2, $a2, 0x69
    ctx->r6 = ADD32(ctx->r6, 0X69);
    // 0x80229E80: lbu         $v0, 0x385($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X385);
L_80229E84:
    // 0x80229E84: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80229E88: addiu       $a2, $a2, 0x42AA
    ctx->r6 = ADD32(ctx->r6, 0X42AA);
    // 0x80229E8C: beq         $v0, $zero, L_80229EA4
    if (ctx->r2 == 0) {
        // 0x80229E90: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80229EA4;
    }
    // 0x80229E90: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80229E94: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229E98: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229E9C: b           L_80229EA4
    // 0x80229EA0: addiu       $a2, $a2, 0x66
    ctx->r6 = ADD32(ctx->r6, 0X66);
        goto L_80229EA4;
    // 0x80229EA0: addiu       $a2, $a2, 0x66
    ctx->r6 = ADD32(ctx->r6, 0X66);
L_80229EA4:
    // 0x80229EA4: b           L_80229FA4
    // 0x80229EA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
        goto L_80229FA4;
    // 0x80229EA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
L_80229EAC:
    // 0x80229EAC: bne         $v0, $at, L_80229FA4
    if (ctx->r2 != ctx->r1) {
        // 0x80229EB0: nop
    
            goto L_80229FA4;
    }
    // 0x80229EB0: nop

    // 0x80229EB4: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x80229EB8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80229EBC: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x80229EC0: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80229EC4: mflo        $t3
    ctx->r11 = lo;
    // 0x80229EC8: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80229ECC: beql        $at, $zero, L_80229EE4
    if (ctx->r1 == 0) {
        // 0x80229ED0: lbu         $v0, 0x33($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X33);
            goto L_80229EE4;
    }
    goto skip_10;
    // 0x80229ED0: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
    skip_10:
    // 0x80229ED4: lbu         $v0, 0x38A($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38A);
    // 0x80229ED8: bnel        $v0, $zero, L_80229EF8
    if (ctx->r2 != 0) {
        // 0x80229EDC: lw          $a2, 0x334($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X334);
            goto L_80229EF8;
    }
    goto skip_11;
    // 0x80229EDC: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    skip_11:
    // 0x80229EE0: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
L_80229EE4:
    // 0x80229EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80229EE8: bne         $t0, $v0, L_80229F08
    if (ctx->r8 != ctx->r2) {
        // 0x80229EEC: nop
    
            goto L_80229F08;
    }
    // 0x80229EEC: nop

    // 0x80229EF0: lbu         $v0, 0x38A($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38A);
    // 0x80229EF4: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
L_80229EF8:
    // 0x80229EF8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229EFC: addiu       $a2, $a2, 0x76
    ctx->r6 = ADD32(ctx->r6, 0X76);
    // 0x80229F00: b           L_80229FA4
    // 0x80229F04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
        goto L_80229FA4;
    // 0x80229F04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
L_80229F08:
    // 0x80229F08: bne         $v0, $at, L_80229F30
    if (ctx->r2 != ctx->r1) {
        // 0x80229F0C: lbu         $t4, 0x33($sp)
        ctx->r12 = MEM_BU(ctx->r29, 0X33);
            goto L_80229F30;
    }
    // 0x80229F0C: lbu         $t4, 0x33($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X33);
    // 0x80229F10: lbu         $v0, 0x389($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X389);
    // 0x80229F14: beq         $v0, $zero, L_80229F30
    if (ctx->r2 == 0) {
        // 0x80229F18: nop
    
            goto L_80229F30;
    }
    // 0x80229F18: nop

    // 0x80229F1C: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229F20: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229F24: addiu       $a2, $a2, 0x72
    ctx->r6 = ADD32(ctx->r6, 0X72);
    // 0x80229F28: b           L_80229FA4
    // 0x80229F2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
        goto L_80229FA4;
    // 0x80229F2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
L_80229F30:
    // 0x80229F30: bnel        $t4, $zero, L_80229F5C
    if (ctx->r12 != 0) {
        // 0x80229F34: lbu         $v0, 0x389($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X389);
            goto L_80229F5C;
    }
    goto skip_12;
    // 0x80229F34: lbu         $v0, 0x389($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X389);
    skip_12:
    // 0x80229F38: lbu         $v0, 0x388($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X388);
    // 0x80229F3C: beql        $v0, $zero, L_80229F5C
    if (ctx->r2 == 0) {
        // 0x80229F40: lbu         $v0, 0x389($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X389);
            goto L_80229F5C;
    }
    goto skip_13;
    // 0x80229F40: lbu         $v0, 0x389($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X389);
    skip_13:
    // 0x80229F44: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229F48: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229F4C: addiu       $a2, $a2, 0x6D
    ctx->r6 = ADD32(ctx->r6, 0X6D);
    // 0x80229F50: b           L_80229FA4
    // 0x80229F54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
        goto L_80229FA4;
    // 0x80229F54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80229F58: lbu         $v0, 0x389($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X389);
L_80229F5C:
    // 0x80229F5C: beql        $v0, $zero, L_80229F7C
    if (ctx->r2 == 0) {
        // 0x80229F60: lbu         $v0, 0x388($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X388);
            goto L_80229F7C;
    }
    goto skip_14;
    // 0x80229F60: lbu         $v0, 0x388($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X388);
    skip_14:
    // 0x80229F64: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229F68: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229F6C: addiu       $a2, $a2, 0x72
    ctx->r6 = ADD32(ctx->r6, 0X72);
    // 0x80229F70: b           L_80229FA4
    // 0x80229F74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
        goto L_80229FA4;
    // 0x80229F74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80229F78: lbu         $v0, 0x388($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X388);
L_80229F7C:
    // 0x80229F7C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80229F80: addiu       $a2, $a2, 0x4432
    ctx->r6 = ADD32(ctx->r6, 0X4432);
    // 0x80229F84: beq         $v0, $zero, L_80229FA0
    if (ctx->r2 == 0) {
        // 0x80229F88: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80229FA0;
    }
    // 0x80229F88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80229F8C: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x80229F90: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229F94: addiu       $a2, $a2, 0x6D
    ctx->r6 = ADD32(ctx->r6, 0X6D);
    // 0x80229F98: b           L_80229FA4
    // 0x80229F9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
        goto L_80229FA4;
    // 0x80229F9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
L_80229FA0:
    // 0x80229FA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
L_80229FA4:
    // 0x80229FA4: b           L_8022A084
    // 0x80229FA8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_8022A084;
    // 0x80229FA8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80229FAC: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
L_80229FB0:
    // 0x80229FB0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80229FB4: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80229FB8: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x80229FBC: mflo        $t7
    ctx->r15 = lo;
    // 0x80229FC0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80229FC4: beql        $at, $zero, L_80229FDC
    if (ctx->r1 == 0) {
        // 0x80229FC8: lbu         $v0, 0x33($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X33);
            goto L_80229FDC;
    }
    goto skip_15;
    // 0x80229FC8: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
    skip_15:
    // 0x80229FCC: lbu         $v0, 0x38D($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38D);
    // 0x80229FD0: bnel        $v0, $zero, L_80229FF0
    if (ctx->r2 != 0) {
        // 0x80229FD4: lw          $a2, 0x334($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X334);
            goto L_80229FF0;
    }
    goto skip_16;
    // 0x80229FD4: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    skip_16:
    // 0x80229FD8: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
L_80229FDC:
    // 0x80229FDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80229FE0: bne         $t0, $v0, L_80229FFC
    if (ctx->r8 != ctx->r2) {
        // 0x80229FE4: nop
    
            goto L_80229FFC;
    }
    // 0x80229FE4: nop

    // 0x80229FE8: lbu         $v0, 0x38D($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38D);
    // 0x80229FEC: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
L_80229FF0:
    // 0x80229FF0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80229FF4: b           L_8022A084
    // 0x80229FF8: addiu       $a2, $a2, 0x7C
    ctx->r6 = ADD32(ctx->r6, 0X7C);
        goto L_8022A084;
    // 0x80229FF8: addiu       $a2, $a2, 0x7C
    ctx->r6 = ADD32(ctx->r6, 0X7C);
L_80229FFC:
    // 0x80229FFC: bne         $v0, $at, L_8022A020
    if (ctx->r2 != ctx->r1) {
        // 0x8022A000: lbu         $t8, 0x33($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X33);
            goto L_8022A020;
    }
    // 0x8022A000: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x8022A004: lbu         $v0, 0x38C($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38C);
    // 0x8022A008: beq         $v0, $zero, L_8022A020
    if (ctx->r2 == 0) {
        // 0x8022A00C: nop
    
            goto L_8022A020;
    }
    // 0x8022A00C: nop

    // 0x8022A010: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x8022A014: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A018: b           L_8022A084
    // 0x8022A01C: addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
        goto L_8022A084;
    // 0x8022A01C: addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
L_8022A020:
    // 0x8022A020: bnel        $t8, $zero, L_8022A048
    if (ctx->r24 != 0) {
        // 0x8022A024: lbu         $v0, 0x38C($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X38C);
            goto L_8022A048;
    }
    goto skip_17;
    // 0x8022A024: lbu         $v0, 0x38C($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38C);
    skip_17:
    // 0x8022A028: lbu         $v0, 0x38B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38B);
    // 0x8022A02C: beql        $v0, $zero, L_8022A048
    if (ctx->r2 == 0) {
        // 0x8022A030: lbu         $v0, 0x38C($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X38C);
            goto L_8022A048;
    }
    goto skip_18;
    // 0x8022A030: lbu         $v0, 0x38C($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38C);
    skip_18:
    // 0x8022A034: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x8022A038: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A03C: b           L_8022A084
    // 0x8022A040: addiu       $a2, $a2, 0x77
    ctx->r6 = ADD32(ctx->r6, 0X77);
        goto L_8022A084;
    // 0x8022A040: addiu       $a2, $a2, 0x77
    ctx->r6 = ADD32(ctx->r6, 0X77);
    // 0x8022A044: lbu         $v0, 0x38C($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38C);
L_8022A048:
    // 0x8022A048: beql        $v0, $zero, L_8022A064
    if (ctx->r2 == 0) {
        // 0x8022A04C: lbu         $v0, 0x38B($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X38B);
            goto L_8022A064;
    }
    goto skip_19;
    // 0x8022A04C: lbu         $v0, 0x38B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38B);
    skip_19:
    // 0x8022A050: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x8022A054: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A058: b           L_8022A084
    // 0x8022A05C: addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
        goto L_8022A084;
    // 0x8022A05C: addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
    // 0x8022A060: lbu         $v0, 0x38B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X38B);
L_8022A064:
    // 0x8022A064: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8022A068: addiu       $a2, $a2, 0x46D2
    ctx->r6 = ADD32(ctx->r6, 0X46D2);
    // 0x8022A06C: beq         $v0, $zero, L_8022A084
    if (ctx->r2 == 0) {
        // 0x8022A070: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8022A084;
    }
    // 0x8022A070: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8022A074: lw          $a2, 0x334($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X334);
    // 0x8022A078: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A07C: b           L_8022A084
    // 0x8022A080: addiu       $a2, $a2, 0x77
    ctx->r6 = ADD32(ctx->r6, 0X77);
        goto L_8022A084;
    // 0x8022A080: addiu       $a2, $a2, 0x77
    ctx->r6 = ADD32(ctx->r6, 0X77);
L_8022A084:
    // 0x8022A084: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8022A088: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    // 0x8022A08C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8022A090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8022A094: jal         0x8022B640
    // 0x8022A098: sb          $t1, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_1;
    // 0x8022A098: sb          $t1, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r9;
    after_1:
    // 0x8022A09C: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x8022A0A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8022A0A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8022A0A8: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8022A0AC: sltiu       $at, $t2, 0xA
    ctx->r1 = ctx->r10 < 0XA ? 1 : 0;
    // 0x8022A0B0: beq         $at, $zero, L_8022A5A0
    if (ctx->r1 == 0) {
        // 0x8022A0B4: lbu         $t1, 0x1C($sp)
        ctx->r9 = MEM_BU(ctx->r29, 0X1C);
            goto L_8022A5A0;
    }
    // 0x8022A0B4: lbu         $t1, 0x1C($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1C);
    // 0x8022A0B8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8022A0BC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022A0C0: addu        $at, $at, $t2
    gpr jr_addend_8022A0C8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8022A0C4: lw          $t2, -0xE00($at)
    ctx->r10 = ADD32(ctx->r1, -0XE00);
    // 0x8022A0C8: jr          $t2
    // 0x8022A0CC: nop

    switch (jr_addend_8022A0C8 >> 2) {
        case 0: goto L_8022A0D0; break;
        case 1: goto L_8022A0DC; break;
        case 2: goto L_8022A104; break;
        case 3: goto L_8022A144; break;
        case 4: goto L_8022A19C; break;
        case 5: goto L_8022A20C; break;
        case 6: goto L_8022A294; break;
        case 7: goto L_8022A334; break;
        case 8: goto L_8022A3EC; break;
        case 9: goto L_8022A4BC; break;
        default: switch_error(__func__, 0x8022A0C8, 0x8023F200);
    }
    // 0x8022A0CC: nop

L_8022A0D0:
    // 0x8022A0D0: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A0D4: b           L_8022A5A0
    // 0x8022A0D8: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A5A0;
    // 0x8022A0D8: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
L_8022A0DC:
    // 0x8022A0DC: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8022A0E0: slti        $at, $t3, 0x43
    ctx->r1 = SIGNED(ctx->r11) < 0X43 ? 1 : 0;
    // 0x8022A0E4: beql        $at, $zero, L_8022A0FC
    if (ctx->r1 == 0) {
        // 0x8022A0E8: lbu         $t5, 0x1($a2)
        ctx->r13 = MEM_BU(ctx->r6, 0X1);
            goto L_8022A0FC;
    }
    goto skip_20;
    // 0x8022A0E8: lbu         $t5, 0x1($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1);
    skip_20:
    // 0x8022A0EC: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A0F0: b           L_8022A5A0
    // 0x8022A0F4: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A5A0;
    // 0x8022A0F4: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
    // 0x8022A0F8: lbu         $t5, 0x1($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1);
L_8022A0FC:
    // 0x8022A0FC: b           L_8022A5A0
    // 0x8022A100: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
        goto L_8022A5A0;
    // 0x8022A100: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
L_8022A104:
    // 0x8022A104: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A108: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x8022A10C: beql        $at, $zero, L_8022A124
    if (ctx->r1 == 0) {
        // 0x8022A110: slti        $at, $v1, 0x54
        ctx->r1 = SIGNED(ctx->r3) < 0X54 ? 1 : 0;
            goto L_8022A124;
    }
    goto skip_21;
    // 0x8022A110: slti        $at, $v1, 0x54
    ctx->r1 = SIGNED(ctx->r3) < 0X54 ? 1 : 0;
    skip_21:
    // 0x8022A114: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A118: b           L_8022A5A0
    // 0x8022A11C: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A5A0;
    // 0x8022A11C: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
    // 0x8022A120: slti        $at, $v1, 0x54
    ctx->r1 = SIGNED(ctx->r3) < 0X54 ? 1 : 0;
L_8022A124:
    // 0x8022A124: beql        $at, $zero, L_8022A13C
    if (ctx->r1 == 0) {
        // 0x8022A128: lbu         $t8, 0x2($a2)
        ctx->r24 = MEM_BU(ctx->r6, 0X2);
            goto L_8022A13C;
    }
    goto skip_22;
    // 0x8022A128: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
    skip_22:
    // 0x8022A12C: lbu         $t7, 0x1($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A130: b           L_8022A5A0
    // 0x8022A134: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A5A0;
    // 0x8022A134: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
    // 0x8022A138: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
L_8022A13C:
    // 0x8022A13C: b           L_8022A5A0
    // 0x8022A140: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
        goto L_8022A5A0;
    // 0x8022A140: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
L_8022A144:
    // 0x8022A144: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A148: slti        $at, $v1, 0x28
    ctx->r1 = SIGNED(ctx->r3) < 0X28 ? 1 : 0;
    // 0x8022A14C: beql        $at, $zero, L_8022A164
    if (ctx->r1 == 0) {
        // 0x8022A150: slti        $at, $v1, 0x46
        ctx->r1 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
            goto L_8022A164;
    }
    goto skip_23;
    // 0x8022A150: slti        $at, $v1, 0x46
    ctx->r1 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
    skip_23:
    // 0x8022A154: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A158: b           L_8022A5A0
    // 0x8022A15C: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A5A0;
    // 0x8022A15C: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
    // 0x8022A160: slti        $at, $v1, 0x46
    ctx->r1 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
L_8022A164:
    // 0x8022A164: beql        $at, $zero, L_8022A17C
    if (ctx->r1 == 0) {
        // 0x8022A168: slti        $at, $v1, 0x5A
        ctx->r1 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
            goto L_8022A17C;
    }
    goto skip_24;
    // 0x8022A168: slti        $at, $v1, 0x5A
    ctx->r1 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
    skip_24:
    // 0x8022A16C: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A170: b           L_8022A5A0
    // 0x8022A174: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A5A0;
    // 0x8022A174: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x8022A178: slti        $at, $v1, 0x5A
    ctx->r1 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
L_8022A17C:
    // 0x8022A17C: beql        $at, $zero, L_8022A194
    if (ctx->r1 == 0) {
        // 0x8022A180: lbu         $t4, 0x3($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0X3);
            goto L_8022A194;
    }
    goto skip_25;
    // 0x8022A180: lbu         $t4, 0x3($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X3);
    skip_25:
    // 0x8022A184: lbu         $t3, 0x2($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X2);
    // 0x8022A188: b           L_8022A5A0
    // 0x8022A18C: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A5A0;
    // 0x8022A18C: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
    // 0x8022A190: lbu         $t4, 0x3($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X3);
L_8022A194:
    // 0x8022A194: b           L_8022A5A0
    // 0x8022A198: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A5A0;
    // 0x8022A198: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
L_8022A19C:
    // 0x8022A19C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A1A0: slti        $at, $v1, 0x21
    ctx->r1 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x8022A1A4: beql        $at, $zero, L_8022A1BC
    if (ctx->r1 == 0) {
        // 0x8022A1A8: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8022A1BC;
    }
    goto skip_26;
    // 0x8022A1A8: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    skip_26:
    // 0x8022A1AC: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A1B0: b           L_8022A5A0
    // 0x8022A1B4: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
        goto L_8022A5A0;
    // 0x8022A1B4: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
    // 0x8022A1B8: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
L_8022A1BC:
    // 0x8022A1BC: beql        $at, $zero, L_8022A1D4
    if (ctx->r1 == 0) {
        // 0x8022A1C0: slti        $at, $v1, 0x50
        ctx->r1 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
            goto L_8022A1D4;
    }
    goto skip_27;
    // 0x8022A1C0: slti        $at, $v1, 0x50
    ctx->r1 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
    skip_27:
    // 0x8022A1C4: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A1C8: b           L_8022A5A0
    // 0x8022A1CC: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A5A0;
    // 0x8022A1CC: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
    // 0x8022A1D0: slti        $at, $v1, 0x50
    ctx->r1 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
L_8022A1D4:
    // 0x8022A1D4: beql        $at, $zero, L_8022A1EC
    if (ctx->r1 == 0) {
        // 0x8022A1D8: slti        $at, $v1, 0x5D
        ctx->r1 = SIGNED(ctx->r3) < 0X5D ? 1 : 0;
            goto L_8022A1EC;
    }
    goto skip_28;
    // 0x8022A1D8: slti        $at, $v1, 0x5D
    ctx->r1 = SIGNED(ctx->r3) < 0X5D ? 1 : 0;
    skip_28:
    // 0x8022A1DC: lbu         $t7, 0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2);
    // 0x8022A1E0: b           L_8022A5A0
    // 0x8022A1E4: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A5A0;
    // 0x8022A1E4: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
    // 0x8022A1E8: slti        $at, $v1, 0x5D
    ctx->r1 = SIGNED(ctx->r3) < 0X5D ? 1 : 0;
L_8022A1EC:
    // 0x8022A1EC: beql        $at, $zero, L_8022A204
    if (ctx->r1 == 0) {
        // 0x8022A1F0: lbu         $t2, 0x4($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X4);
            goto L_8022A204;
    }
    goto skip_29;
    // 0x8022A1F0: lbu         $t2, 0x4($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X4);
    skip_29:
    // 0x8022A1F4: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x8022A1F8: b           L_8022A5A0
    // 0x8022A1FC: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
        goto L_8022A5A0;
    // 0x8022A1FC: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
    // 0x8022A200: lbu         $t2, 0x4($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X4);
L_8022A204:
    // 0x8022A204: b           L_8022A5A0
    // 0x8022A208: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A5A0;
    // 0x8022A208: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
L_8022A20C:
    // 0x8022A20C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A210: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x8022A214: beql        $at, $zero, L_8022A22C
    if (ctx->r1 == 0) {
        // 0x8022A218: slti        $at, $v1, 0x46
        ctx->r1 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
            goto L_8022A22C;
    }
    goto skip_30;
    // 0x8022A218: slti        $at, $v1, 0x46
    ctx->r1 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
    skip_30:
    // 0x8022A21C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A220: b           L_8022A5A0
    // 0x8022A224: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A5A0;
    // 0x8022A224: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x8022A228: slti        $at, $v1, 0x46
    ctx->r1 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
L_8022A22C:
    // 0x8022A22C: beql        $at, $zero, L_8022A244
    if (ctx->r1 == 0) {
        // 0x8022A230: slti        $at, $v1, 0x50
        ctx->r1 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
            goto L_8022A244;
    }
    goto skip_31;
    // 0x8022A230: slti        $at, $v1, 0x50
    ctx->r1 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
    skip_31:
    // 0x8022A234: lbu         $t3, 0x1($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A238: b           L_8022A5A0
    // 0x8022A23C: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A5A0;
    // 0x8022A23C: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
    // 0x8022A240: slti        $at, $v1, 0x50
    ctx->r1 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
L_8022A244:
    // 0x8022A244: beql        $at, $zero, L_8022A25C
    if (ctx->r1 == 0) {
        // 0x8022A248: slti        $at, $v1, 0x58
        ctx->r1 = SIGNED(ctx->r3) < 0X58 ? 1 : 0;
            goto L_8022A25C;
    }
    goto skip_32;
    // 0x8022A248: slti        $at, $v1, 0x58
    ctx->r1 = SIGNED(ctx->r3) < 0X58 ? 1 : 0;
    skip_32:
    // 0x8022A24C: lbu         $t4, 0x2($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X2);
    // 0x8022A250: b           L_8022A5A0
    // 0x8022A254: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A5A0;
    // 0x8022A254: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
    // 0x8022A258: slti        $at, $v1, 0x58
    ctx->r1 = SIGNED(ctx->r3) < 0X58 ? 1 : 0;
L_8022A25C:
    // 0x8022A25C: beql        $at, $zero, L_8022A274
    if (ctx->r1 == 0) {
        // 0x8022A260: slti        $at, $v1, 0x5F
        ctx->r1 = SIGNED(ctx->r3) < 0X5F ? 1 : 0;
            goto L_8022A274;
    }
    goto skip_33;
    // 0x8022A260: slti        $at, $v1, 0x5F
    ctx->r1 = SIGNED(ctx->r3) < 0X5F ? 1 : 0;
    skip_33:
    // 0x8022A264: lbu         $t5, 0x3($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X3);
    // 0x8022A268: b           L_8022A5A0
    // 0x8022A26C: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
        goto L_8022A5A0;
    // 0x8022A26C: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
    // 0x8022A270: slti        $at, $v1, 0x5F
    ctx->r1 = SIGNED(ctx->r3) < 0X5F ? 1 : 0;
L_8022A274:
    // 0x8022A274: beql        $at, $zero, L_8022A28C
    if (ctx->r1 == 0) {
        // 0x8022A278: lbu         $t7, 0x5($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X5);
            goto L_8022A28C;
    }
    goto skip_34;
    // 0x8022A278: lbu         $t7, 0x5($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X5);
    skip_34:
    // 0x8022A27C: lbu         $t6, 0x4($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X4);
    // 0x8022A280: b           L_8022A5A0
    // 0x8022A284: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A5A0;
    // 0x8022A284: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
    // 0x8022A288: lbu         $t7, 0x5($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X5);
L_8022A28C:
    // 0x8022A28C: b           L_8022A5A0
    // 0x8022A290: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A5A0;
    // 0x8022A290: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
L_8022A294:
    // 0x8022A294: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A298: slti        $at, $v1, 0x19
    ctx->r1 = SIGNED(ctx->r3) < 0X19 ? 1 : 0;
    // 0x8022A29C: beql        $at, $zero, L_8022A2B4
    if (ctx->r1 == 0) {
        // 0x8022A2A0: slti        $at, $v1, 0x2E
        ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
            goto L_8022A2B4;
    }
    goto skip_35;
    // 0x8022A2A0: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    skip_35:
    // 0x8022A2A4: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A2A8: b           L_8022A5A0
    // 0x8022A2AC: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
        goto L_8022A5A0;
    // 0x8022A2AC: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
    // 0x8022A2B0: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
L_8022A2B4:
    // 0x8022A2B4: beql        $at, $zero, L_8022A2CC
    if (ctx->r1 == 0) {
        // 0x8022A2B8: slti        $at, $v1, 0x40
        ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
            goto L_8022A2CC;
    }
    goto skip_36;
    // 0x8022A2B8: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    skip_36:
    // 0x8022A2BC: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A2C0: b           L_8022A5A0
    // 0x8022A2C4: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A5A0;
    // 0x8022A2C4: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
    // 0x8022A2C8: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
L_8022A2CC:
    // 0x8022A2CC: beql        $at, $zero, L_8022A2E4
    if (ctx->r1 == 0) {
        // 0x8022A2D0: slti        $at, $v1, 0x4E
        ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
            goto L_8022A2E4;
    }
    goto skip_37;
    // 0x8022A2D0: slti        $at, $v1, 0x4E
    ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
    skip_37:
    // 0x8022A2D4: lbu         $t9, 0x2($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X2);
    // 0x8022A2D8: b           L_8022A5A0
    // 0x8022A2DC: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A5A0;
    // 0x8022A2DC: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x8022A2E0: slti        $at, $v1, 0x4E
    ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
L_8022A2E4:
    // 0x8022A2E4: beql        $at, $zero, L_8022A2FC
    if (ctx->r1 == 0) {
        // 0x8022A2E8: slti        $at, $v1, 0x59
        ctx->r1 = SIGNED(ctx->r3) < 0X59 ? 1 : 0;
            goto L_8022A2FC;
    }
    goto skip_38;
    // 0x8022A2E8: slti        $at, $v1, 0x59
    ctx->r1 = SIGNED(ctx->r3) < 0X59 ? 1 : 0;
    skip_38:
    // 0x8022A2EC: lbu         $t3, 0x3($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3);
    // 0x8022A2F0: b           L_8022A5A0
    // 0x8022A2F4: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A5A0;
    // 0x8022A2F4: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
    // 0x8022A2F8: slti        $at, $v1, 0x59
    ctx->r1 = SIGNED(ctx->r3) < 0X59 ? 1 : 0;
L_8022A2FC:
    // 0x8022A2FC: beql        $at, $zero, L_8022A314
    if (ctx->r1 == 0) {
        // 0x8022A300: slti        $at, $v1, 0x60
        ctx->r1 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
            goto L_8022A314;
    }
    goto skip_39;
    // 0x8022A300: slti        $at, $v1, 0x60
    ctx->r1 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
    skip_39:
    // 0x8022A304: lbu         $t4, 0x4($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X4);
    // 0x8022A308: b           L_8022A5A0
    // 0x8022A30C: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A5A0;
    // 0x8022A30C: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
    // 0x8022A310: slti        $at, $v1, 0x60
    ctx->r1 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
L_8022A314:
    // 0x8022A314: beql        $at, $zero, L_8022A32C
    if (ctx->r1 == 0) {
        // 0x8022A318: lbu         $t6, 0x6($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X6);
            goto L_8022A32C;
    }
    goto skip_40;
    // 0x8022A318: lbu         $t6, 0x6($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X6);
    skip_40:
    // 0x8022A31C: lbu         $t5, 0x5($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X5);
    // 0x8022A320: b           L_8022A5A0
    // 0x8022A324: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
        goto L_8022A5A0;
    // 0x8022A324: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
    // 0x8022A328: lbu         $t6, 0x6($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X6);
L_8022A32C:
    // 0x8022A32C: b           L_8022A5A0
    // 0x8022A330: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A5A0;
    // 0x8022A330: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
L_8022A334:
    // 0x8022A334: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A338: slti        $at, $v1, 0x16
    ctx->r1 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    // 0x8022A33C: beql        $at, $zero, L_8022A354
    if (ctx->r1 == 0) {
        // 0x8022A340: slti        $at, $v1, 0x29
        ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
            goto L_8022A354;
    }
    goto skip_41;
    // 0x8022A340: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    skip_41:
    // 0x8022A344: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A348: b           L_8022A5A0
    // 0x8022A34C: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A5A0;
    // 0x8022A34C: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
    // 0x8022A350: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
L_8022A354:
    // 0x8022A354: beql        $at, $zero, L_8022A36C
    if (ctx->r1 == 0) {
        // 0x8022A358: slti        $at, $v1, 0x3A
        ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
            goto L_8022A36C;
    }
    goto skip_42;
    // 0x8022A358: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    skip_42:
    // 0x8022A35C: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A360: b           L_8022A5A0
    // 0x8022A364: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
        goto L_8022A5A0;
    // 0x8022A364: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
    // 0x8022A368: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
L_8022A36C:
    // 0x8022A36C: beql        $at, $zero, L_8022A384
    if (ctx->r1 == 0) {
        // 0x8022A370: slti        $at, $v1, 0x48
        ctx->r1 = SIGNED(ctx->r3) < 0X48 ? 1 : 0;
            goto L_8022A384;
    }
    goto skip_43;
    // 0x8022A370: slti        $at, $v1, 0x48
    ctx->r1 = SIGNED(ctx->r3) < 0X48 ? 1 : 0;
    skip_43:
    // 0x8022A374: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x8022A378: b           L_8022A5A0
    // 0x8022A37C: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A5A0;
    // 0x8022A37C: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
    // 0x8022A380: slti        $at, $v1, 0x48
    ctx->r1 = SIGNED(ctx->r3) < 0X48 ? 1 : 0;
L_8022A384:
    // 0x8022A384: beql        $at, $zero, L_8022A39C
    if (ctx->r1 == 0) {
        // 0x8022A388: slti        $at, $v1, 0x53
        ctx->r1 = SIGNED(ctx->r3) < 0X53 ? 1 : 0;
            goto L_8022A39C;
    }
    goto skip_44;
    // 0x8022A388: slti        $at, $v1, 0x53
    ctx->r1 = SIGNED(ctx->r3) < 0X53 ? 1 : 0;
    skip_44:
    // 0x8022A38C: lbu         $t9, 0x3($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3);
    // 0x8022A390: b           L_8022A5A0
    // 0x8022A394: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A5A0;
    // 0x8022A394: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x8022A398: slti        $at, $v1, 0x53
    ctx->r1 = SIGNED(ctx->r3) < 0X53 ? 1 : 0;
L_8022A39C:
    // 0x8022A39C: beql        $at, $zero, L_8022A3B4
    if (ctx->r1 == 0) {
        // 0x8022A3A0: slti        $at, $v1, 0x5B
        ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
            goto L_8022A3B4;
    }
    goto skip_45;
    // 0x8022A3A0: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    skip_45:
    // 0x8022A3A4: lbu         $t3, 0x4($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X4);
    // 0x8022A3A8: b           L_8022A5A0
    // 0x8022A3AC: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A5A0;
    // 0x8022A3AC: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
    // 0x8022A3B0: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
L_8022A3B4:
    // 0x8022A3B4: beql        $at, $zero, L_8022A3CC
    if (ctx->r1 == 0) {
        // 0x8022A3B8: slti        $at, $v1, 0x61
        ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
            goto L_8022A3CC;
    }
    goto skip_46;
    // 0x8022A3B8: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    skip_46:
    // 0x8022A3BC: lbu         $t4, 0x5($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X5);
    // 0x8022A3C0: b           L_8022A5A0
    // 0x8022A3C4: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A5A0;
    // 0x8022A3C4: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
    // 0x8022A3C8: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
L_8022A3CC:
    // 0x8022A3CC: beql        $at, $zero, L_8022A3E4
    if (ctx->r1 == 0) {
        // 0x8022A3D0: lbu         $t6, 0x7($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X7);
            goto L_8022A3E4;
    }
    goto skip_47;
    // 0x8022A3D0: lbu         $t6, 0x7($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7);
    skip_47:
    // 0x8022A3D4: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x8022A3D8: b           L_8022A5A0
    // 0x8022A3DC: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
        goto L_8022A5A0;
    // 0x8022A3DC: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
    // 0x8022A3E0: lbu         $t6, 0x7($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7);
L_8022A3E4:
    // 0x8022A3E4: b           L_8022A5A0
    // 0x8022A3E8: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A5A0;
    // 0x8022A3E8: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
L_8022A3EC:
    // 0x8022A3EC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A3F0: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8022A3F4: beql        $at, $zero, L_8022A40C
    if (ctx->r1 == 0) {
        // 0x8022A3F8: slti        $at, $v1, 0x26
        ctx->r1 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
            goto L_8022A40C;
    }
    goto skip_48;
    // 0x8022A3F8: slti        $at, $v1, 0x26
    ctx->r1 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
    skip_48:
    // 0x8022A3FC: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A400: b           L_8022A5A0
    // 0x8022A404: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A5A0;
    // 0x8022A404: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
    // 0x8022A408: slti        $at, $v1, 0x26
    ctx->r1 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
L_8022A40C:
    // 0x8022A40C: beql        $at, $zero, L_8022A424
    if (ctx->r1 == 0) {
        // 0x8022A410: slti        $at, $v1, 0x36
        ctx->r1 = SIGNED(ctx->r3) < 0X36 ? 1 : 0;
            goto L_8022A424;
    }
    goto skip_49;
    // 0x8022A410: slti        $at, $v1, 0x36
    ctx->r1 = SIGNED(ctx->r3) < 0X36 ? 1 : 0;
    skip_49:
    // 0x8022A414: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A418: b           L_8022A5A0
    // 0x8022A41C: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
        goto L_8022A5A0;
    // 0x8022A41C: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
    // 0x8022A420: slti        $at, $v1, 0x36
    ctx->r1 = SIGNED(ctx->r3) < 0X36 ? 1 : 0;
L_8022A424:
    // 0x8022A424: beql        $at, $zero, L_8022A43C
    if (ctx->r1 == 0) {
        // 0x8022A428: slti        $at, $v1, 0x43
        ctx->r1 = SIGNED(ctx->r3) < 0X43 ? 1 : 0;
            goto L_8022A43C;
    }
    goto skip_50;
    // 0x8022A428: slti        $at, $v1, 0x43
    ctx->r1 = SIGNED(ctx->r3) < 0X43 ? 1 : 0;
    skip_50:
    // 0x8022A42C: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x8022A430: b           L_8022A5A0
    // 0x8022A434: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A5A0;
    // 0x8022A434: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
    // 0x8022A438: slti        $at, $v1, 0x43
    ctx->r1 = SIGNED(ctx->r3) < 0X43 ? 1 : 0;
L_8022A43C:
    // 0x8022A43C: beql        $at, $zero, L_8022A454
    if (ctx->r1 == 0) {
        // 0x8022A440: slti        $at, $v1, 0x4E
        ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
            goto L_8022A454;
    }
    goto skip_51;
    // 0x8022A440: slti        $at, $v1, 0x4E
    ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
    skip_51:
    // 0x8022A444: lbu         $t9, 0x3($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3);
    // 0x8022A448: b           L_8022A5A0
    // 0x8022A44C: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A5A0;
    // 0x8022A44C: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x8022A450: slti        $at, $v1, 0x4E
    ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
L_8022A454:
    // 0x8022A454: beql        $at, $zero, L_8022A46C
    if (ctx->r1 == 0) {
        // 0x8022A458: slti        $at, $v1, 0x57
        ctx->r1 = SIGNED(ctx->r3) < 0X57 ? 1 : 0;
            goto L_8022A46C;
    }
    goto skip_52;
    // 0x8022A458: slti        $at, $v1, 0x57
    ctx->r1 = SIGNED(ctx->r3) < 0X57 ? 1 : 0;
    skip_52:
    // 0x8022A45C: lbu         $t3, 0x4($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X4);
    // 0x8022A460: b           L_8022A5A0
    // 0x8022A464: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A5A0;
    // 0x8022A464: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
    // 0x8022A468: slti        $at, $v1, 0x57
    ctx->r1 = SIGNED(ctx->r3) < 0X57 ? 1 : 0;
L_8022A46C:
    // 0x8022A46C: beql        $at, $zero, L_8022A484
    if (ctx->r1 == 0) {
        // 0x8022A470: slti        $at, $v1, 0x5E
        ctx->r1 = SIGNED(ctx->r3) < 0X5E ? 1 : 0;
            goto L_8022A484;
    }
    goto skip_53;
    // 0x8022A470: slti        $at, $v1, 0x5E
    ctx->r1 = SIGNED(ctx->r3) < 0X5E ? 1 : 0;
    skip_53:
    // 0x8022A474: lbu         $t4, 0x5($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X5);
    // 0x8022A478: b           L_8022A5A0
    // 0x8022A47C: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A5A0;
    // 0x8022A47C: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
    // 0x8022A480: slti        $at, $v1, 0x5E
    ctx->r1 = SIGNED(ctx->r3) < 0X5E ? 1 : 0;
L_8022A484:
    // 0x8022A484: beql        $at, $zero, L_8022A49C
    if (ctx->r1 == 0) {
        // 0x8022A488: slti        $at, $v1, 0x62
        ctx->r1 = SIGNED(ctx->r3) < 0X62 ? 1 : 0;
            goto L_8022A49C;
    }
    goto skip_54;
    // 0x8022A488: slti        $at, $v1, 0x62
    ctx->r1 = SIGNED(ctx->r3) < 0X62 ? 1 : 0;
    skip_54:
    // 0x8022A48C: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x8022A490: b           L_8022A5A0
    // 0x8022A494: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
        goto L_8022A5A0;
    // 0x8022A494: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
    // 0x8022A498: slti        $at, $v1, 0x62
    ctx->r1 = SIGNED(ctx->r3) < 0X62 ? 1 : 0;
L_8022A49C:
    // 0x8022A49C: beql        $at, $zero, L_8022A4B4
    if (ctx->r1 == 0) {
        // 0x8022A4A0: lbu         $t7, 0x8($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X8);
            goto L_8022A4B4;
    }
    goto skip_55;
    // 0x8022A4A0: lbu         $t7, 0x8($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X8);
    skip_55:
    // 0x8022A4A4: lbu         $t6, 0x7($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7);
    // 0x8022A4A8: b           L_8022A5A0
    // 0x8022A4AC: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A5A0;
    // 0x8022A4AC: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
    // 0x8022A4B0: lbu         $t7, 0x8($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X8);
L_8022A4B4:
    // 0x8022A4B4: b           L_8022A5A0
    // 0x8022A4B8: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A5A0;
    // 0x8022A4B8: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
L_8022A4BC:
    // 0x8022A4BC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8022A4C0: slti        $at, $v1, 0x12
    ctx->r1 = SIGNED(ctx->r3) < 0X12 ? 1 : 0;
    // 0x8022A4C4: beql        $at, $zero, L_8022A4DC
    if (ctx->r1 == 0) {
        // 0x8022A4C8: slti        $at, $v1, 0x22
        ctx->r1 = SIGNED(ctx->r3) < 0X22 ? 1 : 0;
            goto L_8022A4DC;
    }
    goto skip_56;
    // 0x8022A4C8: slti        $at, $v1, 0x22
    ctx->r1 = SIGNED(ctx->r3) < 0X22 ? 1 : 0;
    skip_56:
    // 0x8022A4CC: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8022A4D0: b           L_8022A5A0
    // 0x8022A4D4: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
        goto L_8022A5A0;
    // 0x8022A4D4: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
    // 0x8022A4D8: slti        $at, $v1, 0x22
    ctx->r1 = SIGNED(ctx->r3) < 0X22 ? 1 : 0;
L_8022A4DC:
    // 0x8022A4DC: beql        $at, $zero, L_8022A4F4
    if (ctx->r1 == 0) {
        // 0x8022A4E0: slti        $at, $v1, 0x31
        ctx->r1 = SIGNED(ctx->r3) < 0X31 ? 1 : 0;
            goto L_8022A4F4;
    }
    goto skip_57;
    // 0x8022A4E0: slti        $at, $v1, 0x31
    ctx->r1 = SIGNED(ctx->r3) < 0X31 ? 1 : 0;
    skip_57:
    // 0x8022A4E4: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x8022A4E8: b           L_8022A5A0
    // 0x8022A4EC: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A5A0;
    // 0x8022A4EC: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
    // 0x8022A4F0: slti        $at, $v1, 0x31
    ctx->r1 = SIGNED(ctx->r3) < 0X31 ? 1 : 0;
L_8022A4F4:
    // 0x8022A4F4: beql        $at, $zero, L_8022A50C
    if (ctx->r1 == 0) {
        // 0x8022A4F8: slti        $at, $v1, 0x3E
        ctx->r1 = SIGNED(ctx->r3) < 0X3E ? 1 : 0;
            goto L_8022A50C;
    }
    goto skip_58;
    // 0x8022A4F8: slti        $at, $v1, 0x3E
    ctx->r1 = SIGNED(ctx->r3) < 0X3E ? 1 : 0;
    skip_58:
    // 0x8022A4FC: lbu         $t9, 0x2($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X2);
    // 0x8022A500: b           L_8022A5A0
    // 0x8022A504: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A5A0;
    // 0x8022A504: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x8022A508: slti        $at, $v1, 0x3E
    ctx->r1 = SIGNED(ctx->r3) < 0X3E ? 1 : 0;
L_8022A50C:
    // 0x8022A50C: beql        $at, $zero, L_8022A524
    if (ctx->r1 == 0) {
        // 0x8022A510: slti        $at, $v1, 0x49
        ctx->r1 = SIGNED(ctx->r3) < 0X49 ? 1 : 0;
            goto L_8022A524;
    }
    goto skip_59;
    // 0x8022A510: slti        $at, $v1, 0x49
    ctx->r1 = SIGNED(ctx->r3) < 0X49 ? 1 : 0;
    skip_59:
    // 0x8022A514: lbu         $t3, 0x3($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3);
    // 0x8022A518: b           L_8022A5A0
    // 0x8022A51C: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A5A0;
    // 0x8022A51C: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
    // 0x8022A520: slti        $at, $v1, 0x49
    ctx->r1 = SIGNED(ctx->r3) < 0X49 ? 1 : 0;
L_8022A524:
    // 0x8022A524: beql        $at, $zero, L_8022A53C
    if (ctx->r1 == 0) {
        // 0x8022A528: slti        $at, $v1, 0x52
        ctx->r1 = SIGNED(ctx->r3) < 0X52 ? 1 : 0;
            goto L_8022A53C;
    }
    goto skip_60;
    // 0x8022A528: slti        $at, $v1, 0x52
    ctx->r1 = SIGNED(ctx->r3) < 0X52 ? 1 : 0;
    skip_60:
    // 0x8022A52C: lbu         $t4, 0x4($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X4);
    // 0x8022A530: b           L_8022A5A0
    // 0x8022A534: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A5A0;
    // 0x8022A534: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
    // 0x8022A538: slti        $at, $v1, 0x52
    ctx->r1 = SIGNED(ctx->r3) < 0X52 ? 1 : 0;
L_8022A53C:
    // 0x8022A53C: beql        $at, $zero, L_8022A554
    if (ctx->r1 == 0) {
        // 0x8022A540: slti        $at, $v1, 0x59
        ctx->r1 = SIGNED(ctx->r3) < 0X59 ? 1 : 0;
            goto L_8022A554;
    }
    goto skip_61;
    // 0x8022A540: slti        $at, $v1, 0x59
    ctx->r1 = SIGNED(ctx->r3) < 0X59 ? 1 : 0;
    skip_61:
    // 0x8022A544: lbu         $t5, 0x5($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X5);
    // 0x8022A548: b           L_8022A5A0
    // 0x8022A54C: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
        goto L_8022A5A0;
    // 0x8022A54C: sb          $t5, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r13;
    // 0x8022A550: slti        $at, $v1, 0x59
    ctx->r1 = SIGNED(ctx->r3) < 0X59 ? 1 : 0;
L_8022A554:
    // 0x8022A554: beql        $at, $zero, L_8022A56C
    if (ctx->r1 == 0) {
        // 0x8022A558: slti        $at, $v1, 0x5E
        ctx->r1 = SIGNED(ctx->r3) < 0X5E ? 1 : 0;
            goto L_8022A56C;
    }
    goto skip_62;
    // 0x8022A558: slti        $at, $v1, 0x5E
    ctx->r1 = SIGNED(ctx->r3) < 0X5E ? 1 : 0;
    skip_62:
    // 0x8022A55C: lbu         $t6, 0x6($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X6);
    // 0x8022A560: b           L_8022A5A0
    // 0x8022A564: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A5A0;
    // 0x8022A564: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
    // 0x8022A568: slti        $at, $v1, 0x5E
    ctx->r1 = SIGNED(ctx->r3) < 0X5E ? 1 : 0;
L_8022A56C:
    // 0x8022A56C: beql        $at, $zero, L_8022A584
    if (ctx->r1 == 0) {
        // 0x8022A570: slti        $at, $v1, 0x62
        ctx->r1 = SIGNED(ctx->r3) < 0X62 ? 1 : 0;
            goto L_8022A584;
    }
    goto skip_63;
    // 0x8022A570: slti        $at, $v1, 0x62
    ctx->r1 = SIGNED(ctx->r3) < 0X62 ? 1 : 0;
    skip_63:
    // 0x8022A574: lbu         $t7, 0x7($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X7);
    // 0x8022A578: b           L_8022A5A0
    // 0x8022A57C: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A5A0;
    // 0x8022A57C: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
    // 0x8022A580: slti        $at, $v1, 0x62
    ctx->r1 = SIGNED(ctx->r3) < 0X62 ? 1 : 0;
L_8022A584:
    // 0x8022A584: beql        $at, $zero, L_8022A59C
    if (ctx->r1 == 0) {
        // 0x8022A588: lbu         $t2, 0x9($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X9);
            goto L_8022A59C;
    }
    goto skip_64;
    // 0x8022A588: lbu         $t2, 0x9($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X9);
    skip_64:
    // 0x8022A58C: lbu         $t8, 0x8($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X8);
    // 0x8022A590: b           L_8022A5A0
    // 0x8022A594: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
        goto L_8022A5A0;
    // 0x8022A594: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
    // 0x8022A598: lbu         $t2, 0x9($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X9);
L_8022A59C:
    // 0x8022A59C: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
L_8022A5A0:
    // 0x8022A5A0: lbu         $v0, 0x2D8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
    // 0x8022A5A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022A5A8: beq         $v0, $zero, L_8022A5B8
    if (ctx->r2 == 0) {
        // 0x8022A5AC: nop
    
            goto L_8022A5B8;
    }
    // 0x8022A5AC: nop

    // 0x8022A5B0: bnel        $v0, $at, L_8022A818
    if (ctx->r2 != ctx->r1) {
        // 0x8022A5B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022A818;
    }
    goto skip_65;
    // 0x8022A5B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_65:
L_8022A5B8:
    // 0x8022A5B8: bnel        $v0, $zero, L_8022A618
    if (ctx->r2 != 0) {
        // 0x8022A5BC: lh          $t6, 0x2C0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X2C0);
            goto L_8022A618;
    }
    goto skip_66;
    // 0x8022A5BC: lh          $t6, 0x2C0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2C0);
    skip_66:
    // 0x8022A5C0: lh          $t9, 0x2BC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2BC);
    // 0x8022A5C4: bgezl       $t9, L_8022A5D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8022A5C8: lh          $t3, 0x2BE($a1)
        ctx->r11 = MEM_H(ctx->r5, 0X2BE);
            goto L_8022A5D8;
    }
    goto skip_67;
    // 0x8022A5C8: lh          $t3, 0x2BE($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2BE);
    skip_67:
    // 0x8022A5CC: b           L_8022A60C
    // 0x8022A5D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8022A60C;
    // 0x8022A5D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8022A5D4: lh          $t3, 0x2BE($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2BE);
L_8022A5D8:
    // 0x8022A5D8: bgezl       $t3, L_8022A5EC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8022A5DC: lhu         $t4, 0x86($a1)
        ctx->r12 = MEM_HU(ctx->r5, 0X86);
            goto L_8022A5EC;
    }
    goto skip_68;
    // 0x8022A5DC: lhu         $t4, 0x86($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X86);
    skip_68:
    // 0x8022A5E0: b           L_8022A60C
    // 0x8022A5E4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
        goto L_8022A60C;
    // 0x8022A5E4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8022A5E8: lhu         $t4, 0x86($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X86);
L_8022A5EC:
    // 0x8022A5EC: lhu         $t5, 0x88($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X88);
    // 0x8022A5F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8022A5F4: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8022A5F8: bnel        $at, $zero, L_8022A60C
    if (ctx->r1 != 0) {
        // 0x8022A5FC: sb          $v1, 0x1D($sp)
        MEM_B(0X1D, ctx->r29) = ctx->r3;
            goto L_8022A60C;
    }
    goto skip_69;
    // 0x8022A5FC: sb          $v1, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r3;
    skip_69:
    // 0x8022A600: b           L_8022A60C
    // 0x8022A604: sb          $zero, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = 0;
        goto L_8022A60C;
    // 0x8022A604: sb          $zero, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = 0;
    // 0x8022A608: sb          $v1, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r3;
L_8022A60C:
    // 0x8022A60C: b           L_8022A664
    // 0x8022A610: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
        goto L_8022A664;
    // 0x8022A610: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
    // 0x8022A614: lh          $t6, 0x2C0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2C0);
L_8022A618:
    // 0x8022A618: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
    // 0x8022A61C: bgezl       $t6, L_8022A630
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8022A620: lh          $t7, 0x2C2($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X2C2);
            goto L_8022A630;
    }
    goto skip_70;
    // 0x8022A620: lh          $t7, 0x2C2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2C2);
    skip_70:
    // 0x8022A624: b           L_8022A664
    // 0x8022A628: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8022A664;
    // 0x8022A628: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8022A62C: lh          $t7, 0x2C2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2C2);
L_8022A630:
    // 0x8022A630: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
    // 0x8022A634: bgezl       $t7, L_8022A648
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8022A638: lhu         $t8, 0x8A($a1)
        ctx->r24 = MEM_HU(ctx->r5, 0X8A);
            goto L_8022A648;
    }
    goto skip_71;
    // 0x8022A638: lhu         $t8, 0x8A($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X8A);
    skip_71:
    // 0x8022A63C: b           L_8022A664
    // 0x8022A640: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
        goto L_8022A664;
    // 0x8022A640: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8022A644: lhu         $t8, 0x8A($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X8A);
L_8022A648:
    // 0x8022A648: lhu         $t2, 0x8C($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X8C);
    // 0x8022A64C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8022A650: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8022A654: bne         $at, $zero, L_8022A664
    if (ctx->r1 != 0) {
        // 0x8022A658: nop
    
            goto L_8022A664;
    }
    // 0x8022A658: nop

    // 0x8022A65C: b           L_8022A664
    // 0x8022A660: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8022A664;
    // 0x8022A660: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8022A664:
    // 0x8022A664: beq         $t1, $zero, L_8022A684
    if (ctx->r9 == 0) {
        // 0x8022A668: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8022A684;
    }
    // 0x8022A668: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022A66C: bnel        $t1, $at, L_8022A818
    if (ctx->r9 != ctx->r1) {
        // 0x8022A670: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022A818;
    }
    goto skip_72;
    // 0x8022A670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_72:
    // 0x8022A674: lbu         $t9, 0x2D9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A678: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x8022A67C: b           L_8022A814
    // 0x8022A680: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A814;
    // 0x8022A680: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
L_8022A684:
    // 0x8022A684: lw          $t4, 0x334($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X334);
    // 0x8022A688: lbu         $t5, 0x4C($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4C);
    // 0x8022A68C: sltiu       $at, $t5, 0x7
    ctx->r1 = ctx->r13 < 0X7 ? 1 : 0;
    // 0x8022A690: beq         $at, $zero, L_8022A814
    if (ctx->r1 == 0) {
        // 0x8022A694: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8022A814;
    }
    // 0x8022A694: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8022A698: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022A69C: addu        $at, $at, $t5
    gpr jr_addend_8022A6A4 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8022A6A0: lw          $t5, -0xDD8($at)
    ctx->r13 = ADD32(ctx->r1, -0XDD8);
    // 0x8022A6A4: jr          $t5
    // 0x8022A6A8: nop

    switch (jr_addend_8022A6A4 >> 2) {
        case 0: goto L_8022A6AC; break;
        case 1: goto L_8022A6BC; break;
        case 2: goto L_8022A700; break;
        case 3: goto L_8022A744; break;
        case 4: goto L_8022A788; break;
        case 5: goto L_8022A7A8; break;
        case 6: goto L_8022A7CC; break;
        default: switch_error(__func__, 0x8022A6A4, 0x8023F228);
    }
    // 0x8022A6A8: nop

L_8022A6AC:
    // 0x8022A6AC: lbu         $t6, 0x2D9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A6B0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8022A6B4: b           L_8022A814
    // 0x8022A6B8: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
        goto L_8022A814;
    // 0x8022A6B8: sb          $t7, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r15;
L_8022A6BC:
    // 0x8022A6BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8022A6C0: sb          $v1, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r3;
    // 0x8022A6C4: jal         0x8022B640
    // 0x8022A6C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_2;
    // 0x8022A6C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x8022A6CC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8022A6D0: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
    // 0x8022A6D4: beq         $at, $zero, L_8022A6EC
    if (ctx->r1 == 0) {
        // 0x8022A6D8: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8022A6EC;
    }
    // 0x8022A6D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8022A6DC: lbu         $t8, 0x2D9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A6E0: addu        $t2, $t8, $v1
    ctx->r10 = ADD32(ctx->r24, ctx->r3);
    // 0x8022A6E4: b           L_8022A814
    // 0x8022A6E8: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A814;
    // 0x8022A6E8: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
L_8022A6EC:
    // 0x8022A6EC: lbu         $t9, 0x2D9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A6F0: xori        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 ^ 0X1;
    // 0x8022A6F4: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8022A6F8: b           L_8022A814
    // 0x8022A6FC: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A814;
    // 0x8022A6FC: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
L_8022A700:
    // 0x8022A700: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8022A704: sb          $v1, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r3;
    // 0x8022A708: jal         0x8022B640
    // 0x8022A70C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_3;
    // 0x8022A70C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8022A710: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8022A714: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
    // 0x8022A718: beq         $at, $zero, L_8022A730
    if (ctx->r1 == 0) {
        // 0x8022A71C: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8022A730;
    }
    // 0x8022A71C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8022A720: lbu         $t5, 0x2D9($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A724: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8022A728: b           L_8022A814
    // 0x8022A72C: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A814;
    // 0x8022A72C: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
L_8022A730:
    // 0x8022A730: lbu         $t7, 0x2D9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A734: xori        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 ^ 0X1;
    // 0x8022A738: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8022A73C: b           L_8022A814
    // 0x8022A740: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
        goto L_8022A814;
    // 0x8022A740: sb          $t2, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r10;
L_8022A744:
    // 0x8022A744: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8022A748: sb          $v1, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r3;
    // 0x8022A74C: jal         0x8022B640
    // 0x8022A750: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_4;
    // 0x8022A750: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_4:
    // 0x8022A754: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8022A758: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
    // 0x8022A75C: beq         $at, $zero, L_8022A774
    if (ctx->r1 == 0) {
        // 0x8022A760: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8022A774;
    }
    // 0x8022A760: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8022A764: lbu         $t9, 0x2D9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A768: addu        $t3, $t9, $v1
    ctx->r11 = ADD32(ctx->r25, ctx->r3);
    // 0x8022A76C: b           L_8022A814
    // 0x8022A770: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
        goto L_8022A814;
    // 0x8022A770: sb          $t3, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r11;
L_8022A774:
    // 0x8022A774: lbu         $t4, 0x2D9($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A778: xori        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 ^ 0X1;
    // 0x8022A77C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8022A780: b           L_8022A814
    // 0x8022A784: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
        goto L_8022A814;
    // 0x8022A784: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
L_8022A788:
    // 0x8022A788: lbu         $t7, 0x2FC($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2FC);
    // 0x8022A78C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8022A790: beql        $t8, $zero, L_8022A818
    if (ctx->r24 == 0) {
        // 0x8022A794: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022A818;
    }
    goto skip_73;
    // 0x8022A794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_73:
    // 0x8022A798: lbu         $t2, 0x2D9($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A79C: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8022A7A0: b           L_8022A814
    // 0x8022A7A4: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022A814;
    // 0x8022A7A4: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
L_8022A7A8:
    // 0x8022A7A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8022A7AC: jal         0x8022B640
    // 0x8022A7B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_5;
    // 0x8022A7B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_5:
    // 0x8022A7B4: beq         $v0, $zero, L_8022A814
    if (ctx->r2 == 0) {
        // 0x8022A7B8: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8022A814;
    }
    // 0x8022A7B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8022A7BC: lbu         $t3, 0x2D9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A7C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8022A7C4: b           L_8022A814
    // 0x8022A7C8: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
        goto L_8022A814;
    // 0x8022A7C8: sb          $t4, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r12;
L_8022A7CC:
    // 0x8022A7CC: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x8022A7D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022A7D4: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x8022A7D8: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x8022A7DC: bnel        $v0, $at, L_8022A800
    if (ctx->r2 != ctx->r1) {
        // 0x8022A7E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8022A800;
    }
    goto skip_74;
    // 0x8022A7E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_74:
    // 0x8022A7E4: lbu         $t5, 0x2D9($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A7E8: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x8022A7EC: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8022A7F0: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x8022A7F4: sb          $t6, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r14;
    // 0x8022A7F8: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x8022A7FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8022A800:
    // 0x8022A800: bnel        $v0, $at, L_8022A818
    if (ctx->r2 != ctx->r1) {
        // 0x8022A804: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022A818;
    }
    goto skip_75;
    // 0x8022A804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_75:
    // 0x8022A808: lbu         $t7, 0x2D9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8022A80C: andi        $t8, $t7, 0xFFE
    ctx->r24 = ctx->r15 & 0XFFE;
    // 0x8022A810: sb          $t8, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r24;
L_8022A814:
    // 0x8022A814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022A818:
    // 0x8022A818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8022A81C: jr          $ra
    // 0x8022A820: nop

    return;
    // 0x8022A820: nop

;}
RECOMP_FUNC void M10_FUN_8022a824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022A824: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8022A828: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022A82C: jr          $ra
    // 0x8022A830: sb          $t6, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r14;
    return;
    // 0x8022A830: sb          $t6, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022a834(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022a834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022A834: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8022A838: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8022A83C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8022A840: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8022A844: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8022A848: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8022A84C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8022A850: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8022A854: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8022A858: sb          $t6, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r14;
    // 0x8022A85C: lw          $t7, 0x448($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X448);
    // 0x8022A860: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8022A864: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x8022A868: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8022A86C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    // 0x8022A870: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8022A874: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A878: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022A87C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8022A880: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A884: jal         0x8001EB64
    // 0x8022A888: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8022A888: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x8022A88C: lw          $t1, 0x448($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X448);
    // 0x8022A890: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8022A894: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8022A898: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x8022A89C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8022A8A0: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    // 0x8022A8A4: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8022A8A8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A8AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022A8B0: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8022A8B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A8B8: jal         0x8001EAD0
    // 0x8022A8BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8022A8BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8022A8C0: lw          $t5, 0x448($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X448);
    // 0x8022A8C4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8022A8C8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8022A8CC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8022A8D0: mul.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8022A8D4: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8022A8D8: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8022A8DC: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8022A8E0: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8022A8E4: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8022A8E8: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8022A8EC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8022A8F0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8022A8F4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8022A8F8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8022A8FC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8022A900: jal         0x8010843C
    // 0x8022A904: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_2;
    // 0x8022A904: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8022A908: beq         $v0, $zero, L_8022AA80
    if (ctx->r2 == 0) {
        // 0x8022A90C: nop
    
            goto L_8022AA80;
    }
    // 0x8022A90C: nop

    // 0x8022A910: lw          $t8, 0x448($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X448);
    // 0x8022A914: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8022A918: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x8022A91C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8022A920: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x8022A924: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x8022A928: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A92C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022A930: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8022A934: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A938: jal         0x8001EB64
    // 0x8022A93C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8022A93C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x8022A940: lw          $t2, 0x448($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X448);
    // 0x8022A944: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8022A948: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8022A94C: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x8022A950: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8022A954: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    // 0x8022A958: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x8022A95C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A960: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022A964: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8022A968: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A96C: jal         0x8001EAD0
    // 0x8022A970: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8022A970: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x8022A974: lw          $t6, 0x448($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X448);
    // 0x8022A978: mul.s       $f16, $f20, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8022A97C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8022A980: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8022A984: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x8022A988: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8022A98C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8022A990: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8022A994: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8022A998: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8022A99C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8022A9A0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8022A9A4: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8022A9A8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8022A9AC: jal         0x8010843C
    // 0x8022A9B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_5;
    // 0x8022A9B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x8022A9B4: bne         $v0, $zero, L_8022A9C8
    if (ctx->r2 != 0) {
        // 0x8022A9B8: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_8022A9C8;
    }
    // 0x8022A9B8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8022A9BC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8022A9C0: b           L_8022AA90
    // 0x8022A9C4: sb          $t9, 0x2D9($t0)
    MEM_B(0X2D9, ctx->r8) = ctx->r25;
        goto L_8022AA90;
    // 0x8022A9C4: sb          $t9, 0x2D9($t0)
    MEM_B(0X2D9, ctx->r8) = ctx->r25;
L_8022A9C8:
    // 0x8022A9C8: lw          $t1, 0x448($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X448);
    // 0x8022A9CC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8022A9D0: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x8022A9D4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8022A9D8: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    // 0x8022A9DC: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x8022A9E0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A9E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022A9E8: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8022A9EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022A9F0: jal         0x8001EB64
    // 0x8022A9F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x8022A9F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_6:
    // 0x8022A9F8: lw          $t5, 0x448($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X448);
    // 0x8022A9FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8022AA00: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8022AA04: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8022AA08: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8022AA0C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    // 0x8022AA10: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x8022AA14: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022AA18: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022AA1C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8022AA20: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022AA24: jal         0x8001EAD0
    // 0x8022AA28: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x8022AA28: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
    // 0x8022AA2C: lw          $t9, 0x448($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X448);
    // 0x8022AA30: mul.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8022AA34: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8022AA38: mul.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8022AA3C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x8022AA40: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x8022AA44: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8022AA48: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8022AA4C: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8022AA50: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8022AA54: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8022AA58: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8022AA5C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8022AA60: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8022AA64: jal         0x8010843C
    // 0x8022AA68: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_8;
    // 0x8022AA68: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x8022AA6C: bne         $v0, $zero, L_8022AA90
    if (ctx->r2 != 0) {
        // 0x8022AA70: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_8022AA90;
    }
    // 0x8022AA70: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8022AA74: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8022AA78: b           L_8022AA90
    // 0x8022AA7C: sb          $t2, 0x2D9($t3)
    MEM_B(0X2D9, ctx->r11) = ctx->r10;
        goto L_8022AA90;
    // 0x8022AA7C: sb          $t2, 0x2D9($t3)
    MEM_B(0X2D9, ctx->r11) = ctx->r10;
L_8022AA80:
    // 0x8022AA80: jal         0x8022B640
    // 0x8022AA84: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_9;
    // 0x8022AA84: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_9:
    // 0x8022AA88: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8022AA8C: sb          $v0, 0x2D9($t4)
    MEM_B(0X2D9, ctx->r12) = ctx->r2;
L_8022AA90:
    // 0x8022AA90: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8022AA94: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8022AA98: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8022AA9C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8022AAA0: jr          $ra
    // 0x8022AAA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8022AAA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022aaa8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022aaa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022AAA8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022AAAC: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022aab0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022aab0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022AAB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022AAB4: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x8022AAB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022AABC: bne         $a1, $t7, L_8022AAD0
    if (ctx->r5 != ctx->r15) {
        // 0x8022AAC0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8022AAD0;
    }
    // 0x8022AAC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8022AAC4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022AAC8: b           L_8022AAD8
    // 0x8022AACC: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
        goto L_8022AAD8;
    // 0x8022AACC: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_8022AAD0:
    // 0x8022AAD0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022AAD4: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8022AAD8:
    // 0x8022AAD8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8022AADC: sb          $t8, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = ctx->r24;
    // 0x8022AAE0: lhu         $a0, 0x86($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X86);
    // 0x8022AAE4: lhu         $v1, 0x88($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X88);
    // 0x8022AAE8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8022AAEC: beql        $at, $zero, L_8022AB14
    if (ctx->r1 == 0) {
        // 0x8022AAF0: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8022AB14;
    }
    goto skip_0;
    // 0x8022AAF0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x8022AAF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8022AAF8: jal         0x8022B640
    // 0x8022AAFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_0;
    // 0x8022AAFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8022AB00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8022AB04: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8022AB08: b           L_8022AB48
    // 0x8022AB0C: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
        goto L_8022AB48;
    // 0x8022AB0C: sb          $t9, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r25;
    // 0x8022AB10: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8022AB14:
    // 0x8022AB14: beq         $at, $zero, L_8022AB38
    if (ctx->r1 == 0) {
        // 0x8022AB18: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8022AB38;
    }
    // 0x8022AB18: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8022AB1C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8022AB20: jal         0x8022B640
    // 0x8022AB24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_1;
    // 0x8022AB24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8022AB28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8022AB2C: addiu       $t0, $v0, 0x5
    ctx->r8 = ADD32(ctx->r2, 0X5);
    // 0x8022AB30: b           L_8022AB48
    // 0x8022AB34: sb          $t0, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r8;
        goto L_8022AB48;
    // 0x8022AB34: sb          $t0, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r8;
L_8022AB38:
    // 0x8022AB38: jal         0x8022B640
    // 0x8022AB3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_2;
    // 0x8022AB3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x8022AB40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8022AB44: sb          $v0, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r2;
L_8022AB48:
    // 0x8022AB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022AB4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022AB50: jr          $ra
    // 0x8022AB54: nop

    return;
    // 0x8022AB54: nop

;}
RECOMP_FUNC void M10_FUN_8022ab58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022AB58: lh          $t6, 0x2BC($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2BC);
    // 0x8022AB5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8022AB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022AB64: bgezl       $t6, L_8022AB74
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8022AB68: lh          $t7, 0x2BE($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X2BE);
            goto L_8022AB74;
    }
    goto skip_0;
    // 0x8022AB68: lh          $t7, 0x2BE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2BE);
    skip_0:
    // 0x8022AB6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8022AB70: lh          $t7, 0x2BE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2BE);
L_8022AB74:
    // 0x8022AB74: bgezl       $t7, L_8022AB88
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8022AB78: lh          $t8, 0x2C0($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X2C0);
            goto L_8022AB88;
    }
    goto skip_1;
    // 0x8022AB78: lh          $t8, 0x2C0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2C0);
    skip_1:
    // 0x8022AB7C: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x8022AB80: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8022AB84: lh          $t8, 0x2C0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2C0);
L_8022AB88:
    // 0x8022AB88: bgezl       $t8, L_8022AB9C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8022AB8C: lh          $t9, 0x2C2($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X2C2);
            goto L_8022AB9C;
    }
    goto skip_2;
    // 0x8022AB8C: lh          $t9, 0x2C2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2C2);
    skip_2:
    // 0x8022AB90: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x8022AB94: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8022AB98: lh          $t9, 0x2C2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2C2);
L_8022AB9C:
    // 0x8022AB9C: bgezl       $t9, L_8022ABB0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8022ABA0: lbu         $t0, 0xA3($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0XA3);
            goto L_8022ABB0;
    }
    goto skip_3;
    // 0x8022ABA0: lbu         $t0, 0xA3($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XA3);
    skip_3:
    // 0x8022ABA4: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x8022ABA8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8022ABAC: lbu         $t0, 0xA3($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XA3);
L_8022ABB0:
    // 0x8022ABB0: beq         $v1, $t0, L_8022ABC0
    if (ctx->r3 == ctx->r8) {
        // 0x8022ABB4: nop
    
            goto L_8022ABC0;
    }
    // 0x8022ABB4: nop

    // 0x8022ABB8: bnel        $v1, $zero, L_8022ABCC
    if (ctx->r3 != 0) {
        // 0x8022ABBC: sb          $v1, 0xA3($a0)
        MEM_B(0XA3, ctx->r4) = ctx->r3;
            goto L_8022ABCC;
    }
    goto skip_4;
    // 0x8022ABBC: sb          $v1, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r3;
    skip_4:
L_8022ABC0:
    // 0x8022ABC0: jr          $ra
    // 0x8022ABC4: sb          $v1, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r3;
    return;
    // 0x8022ABC4: sb          $v1, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r3;
    // 0x8022ABC8: sb          $v1, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r3;
L_8022ABCC:
    // 0x8022ABCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8022ABD0: jr          $ra
    // 0x8022ABD4: nop

    return;
    // 0x8022ABD4: nop

;}
RECOMP_FUNC void M10_FUN_8022abd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022ABD8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022ABDC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022abe0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022abe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022ABE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022ABE4: addiu       $t6, $v0, 0x44C
    ctx->r14 = ADD32(ctx->r2, 0X44C);
    // 0x8022ABE8: bne         $a1, $t6, L_8022ABF8
    if (ctx->r5 != ctx->r14) {
        // 0x8022ABEC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8022ABF8;
    }
    // 0x8022ABEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022ABF0: b           L_8022ABFC
    // 0x8022ABF4: lw          $v1, 0xDC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XDC);
        goto L_8022ABFC;
    // 0x8022ABF4: lw          $v1, 0xDC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XDC);
L_8022ABF8:
    // 0x8022ABF8: lw          $v1, 0xEC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XEC);
L_8022ABFC:
    // 0x8022ABFC: lhu         $v0, 0x36($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X36);
    // 0x8022AC00: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x8022AC04: bne         $at, $zero, L_8022ACB0
    if (ctx->r1 != 0) {
        // 0x8022AC08: slti        $at, $v0, 0xFE
        ctx->r1 = SIGNED(ctx->r2) < 0XFE ? 1 : 0;
            goto L_8022ACB0;
    }
    // 0x8022AC08: slti        $at, $v0, 0xFE
    ctx->r1 = SIGNED(ctx->r2) < 0XFE ? 1 : 0;
    // 0x8022AC0C: bne         $at, $zero, L_8022AC60
    if (ctx->r1 != 0) {
        // 0x8022AC10: slti        $at, $v0, 0x11F
        ctx->r1 = SIGNED(ctx->r2) < 0X11F ? 1 : 0;
            goto L_8022AC60;
    }
    // 0x8022AC10: slti        $at, $v0, 0x11F
    ctx->r1 = SIGNED(ctx->r2) < 0X11F ? 1 : 0;
    // 0x8022AC14: bne         $at, $zero, L_8022AC40
    if (ctx->r1 != 0) {
        // 0x8022AC18: addiu       $t8, $v0, -0x119
        ctx->r24 = ADD32(ctx->r2, -0X119);
            goto L_8022AC40;
    }
    // 0x8022AC18: addiu       $t8, $v0, -0x119
    ctx->r24 = ADD32(ctx->r2, -0X119);
    // 0x8022AC1C: addiu       $t7, $v0, -0x143
    ctx->r15 = ADD32(ctx->r2, -0X143);
    // 0x8022AC20: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8022AC24: beq         $at, $zero, L_8022AF7C
    if (ctx->r1 == 0) {
        // 0x8022AC28: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8022AF7C;
    }
    // 0x8022AC28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8022AC2C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022AC30: addu        $at, $at, $t7
    gpr jr_addend_8022AC38 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8022AC34: lw          $t7, -0xDBC($at)
    ctx->r15 = ADD32(ctx->r1, -0XDBC);
    // 0x8022AC38: jr          $t7
    // 0x8022AC3C: nop

    switch (jr_addend_8022AC38 >> 2) {
        case 0: goto L_8022AD1C; break;
        case 1: goto L_8022AD4C; break;
        case 2: goto L_8022AD9C; break;
        case 3: goto L_8022ADBC; break;
        case 4: goto L_8022AE7C; break;
        case 5: goto L_8022AF3C; break;
        case 6: goto L_8022ADCC; break;
        default: switch_error(__func__, 0x8022AC38, 0x8023F244);
    }
    // 0x8022AC3C: nop

L_8022AC40:
    // 0x8022AC40: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x8022AC44: beq         $at, $zero, L_8022AF7C
    if (ctx->r1 == 0) {
        // 0x8022AC48: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8022AF7C;
    }
    // 0x8022AC48: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8022AC4C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022AC50: addu        $at, $at, $t8
    gpr jr_addend_8022AC58 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8022AC54: lw          $t8, -0xDA0($at)
    ctx->r24 = ADD32(ctx->r1, -0XDA0);
    // 0x8022AC58: jr          $t8
    // 0x8022AC5C: nop

    switch (jr_addend_8022AC58 >> 2) {
        case 0: goto L_8022AD5C; break;
        case 1: goto L_8022AD3C; break;
        case 2: goto L_8022AF4C; break;
        case 3: goto L_8022AF7C; break;
        case 4: goto L_8022AF5C; break;
        case 5: goto L_8022AF6C; break;
        default: switch_error(__func__, 0x8022AC58, 0x8023F260);
    }
    // 0x8022AC5C: nop

L_8022AC60:
    // 0x8022AC60: slti        $at, $v0, 0x5E
    ctx->r1 = SIGNED(ctx->r2) < 0X5E ? 1 : 0;
    // 0x8022AC64: bne         $at, $zero, L_8022AC90
    if (ctx->r1 != 0) {
        // 0x8022AC68: addiu       $t0, $v0, -0x50
        ctx->r8 = ADD32(ctx->r2, -0X50);
            goto L_8022AC90;
    }
    // 0x8022AC68: addiu       $t0, $v0, -0x50
    ctx->r8 = ADD32(ctx->r2, -0X50);
    // 0x8022AC6C: addiu       $t9, $v0, -0xF0
    ctx->r25 = ADD32(ctx->r2, -0XF0);
    // 0x8022AC70: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x8022AC74: beq         $at, $zero, L_8022AF7C
    if (ctx->r1 == 0) {
        // 0x8022AC78: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8022AF7C;
    }
    // 0x8022AC78: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8022AC7C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022AC80: addu        $at, $at, $t9
    gpr jr_addend_8022AC88 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8022AC84: lw          $t9, -0xD88($at)
    ctx->r25 = ADD32(ctx->r1, -0XD88);
    // 0x8022AC88: jr          $t9
    // 0x8022AC8C: nop

    switch (jr_addend_8022AC88 >> 2) {
        case 0: goto L_8022AE8C; break;
        case 1: goto L_8022AE9C; break;
        case 2: goto L_8022AECC; break;
        case 3: goto L_8022AE4C; break;
        case 4: goto L_8022ADEC; break;
        case 5: goto L_8022ADFC; break;
        case 6: goto L_8022AE0C; break;
        case 7: goto L_8022AF7C; break;
        case 8: goto L_8022AF7C; break;
        case 9: goto L_8022ADDC; break;
        case 10: goto L_8022AE5C; break;
        case 11: goto L_8022AE6C; break;
        case 12: goto L_8022AEDC; break;
        case 13: goto L_8022AEEC; break;
        default: switch_error(__func__, 0x8022AC88, 0x8023F278);
    }
    // 0x8022AC8C: nop

L_8022AC90:
    // 0x8022AC90: sltiu       $at, $t0, 0xE
    ctx->r1 = ctx->r8 < 0XE ? 1 : 0;
    // 0x8022AC94: beq         $at, $zero, L_8022AF7C
    if (ctx->r1 == 0) {
        // 0x8022AC98: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8022AF7C;
    }
    // 0x8022AC98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8022AC9C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022ACA0: addu        $at, $at, $t0
    gpr jr_addend_8022ACA8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8022ACA4: lw          $t0, -0xD50($at)
    ctx->r8 = ADD32(ctx->r1, -0XD50);
    // 0x8022ACA8: jr          $t0
    // 0x8022ACAC: nop

    switch (jr_addend_8022ACA8 >> 2) {
        case 0: goto L_8022ACDC; break;
        case 1: goto L_8022ACEC; break;
        case 2: goto L_8022ACFC; break;
        case 3: goto L_8022AD0C; break;
        case 4: goto L_8022AD8C; break;
        case 5: goto L_8022AD6C; break;
        case 6: goto L_8022AEAC; break;
        case 7: goto L_8022ADAC; break;
        case 8: goto L_8022AD2C; break;
        case 9: goto L_8022AD7C; break;
        case 10: goto L_8022AE1C; break;
        case 11: goto L_8022AE2C; break;
        case 12: goto L_8022AEBC; break;
        case 13: goto L_8022AE3C; break;
        default: switch_error(__func__, 0x8022ACA8, 0x8023F2B0);
    }
    // 0x8022ACAC: nop

L_8022ACB0:
    // 0x8022ACB0: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8022ACB4: beq         $v0, $at, L_8022AF0C
    if (ctx->r2 == ctx->r1) {
        // 0x8022ACB8: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_8022AF0C;
    }
    // 0x8022ACB8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8022ACBC: beq         $v0, $at, L_8022AEFC
    if (ctx->r2 == ctx->r1) {
        // 0x8022ACC0: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_8022AEFC;
    }
    // 0x8022ACC0: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8022ACC4: beq         $v0, $at, L_8022AF2C
    if (ctx->r2 == ctx->r1) {
        // 0x8022ACC8: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_8022AF2C;
    }
    // 0x8022ACC8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8022ACCC: beq         $v0, $at, L_8022AF1C
    if (ctx->r2 == ctx->r1) {
        // 0x8022ACD0: nop
    
            goto L_8022AF1C;
    }
    // 0x8022ACD0: nop

    // 0x8022ACD4: b           L_8022AF7C
    // 0x8022ACD8: nop

        goto L_8022AF7C;
    // 0x8022ACD8: nop

L_8022ACDC:
    // 0x8022ACDC: jal         0x8038DBA4
    // 0x8022ACE0: nop

    LOOKUP_FUNC(0x8038DBA4)(rdram, ctx);
        goto after_0;
    // 0x8022ACE0: nop

    after_0:
    // 0x8022ACE4: b           L_8022AF88
    // 0x8022ACE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ACE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ACEC:
    // 0x8022ACEC: jal         0x8038D93C
    // 0x8022ACF0: nop

    LOOKUP_FUNC(0x8038D93C)(rdram, ctx);
        goto after_1;
    // 0x8022ACF0: nop

    after_1:
    // 0x8022ACF4: b           L_8022AF88
    // 0x8022ACF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ACF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ACFC:
    // 0x8022ACFC: jal         0x8038D7B8
    // 0x8022AD00: nop

    LOOKUP_FUNC(0x8038D7B8)(rdram, ctx);
        goto after_2;
    // 0x8022AD00: nop

    after_2:
    // 0x8022AD04: b           L_8022AF88
    // 0x8022AD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD0C:
    // 0x8022AD0C: jal         0x8038D900
    // 0x8022AD10: nop

    LOOKUP_FUNC(0x8038D900)(rdram, ctx);
        goto after_3;
    // 0x8022AD10: nop

    after_3:
    // 0x8022AD14: b           L_8022AF88
    // 0x8022AD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD1C:
    // 0x8022AD1C: jal         0x8038DDD4
    // 0x8022AD20: nop

    LOOKUP_FUNC(0x8038DDD4)(rdram, ctx);
        goto after_4;
    // 0x8022AD20: nop

    after_4:
    // 0x8022AD24: b           L_8022AF88
    // 0x8022AD28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD2C:
    // 0x8022AD2C: jal         0x8038DC20
    // 0x8022AD30: nop

    LOOKUP_FUNC(0x8038DC20)(rdram, ctx);
        goto after_5;
    // 0x8022AD30: nop

    after_5:
    // 0x8022AD34: b           L_8022AF88
    // 0x8022AD38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD3C:
    // 0x8022AD3C: jal         0x8038DAAC
    // 0x8022AD40: nop

    LOOKUP_FUNC(0x8038DAAC)(rdram, ctx);
        goto after_6;
    // 0x8022AD40: nop

    after_6:
    // 0x8022AD44: b           L_8022AF88
    // 0x8022AD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD4C:
    // 0x8022AD4C: jal         0x8038D8EC
    // 0x8022AD50: nop

    LOOKUP_FUNC(0x8038D8EC)(rdram, ctx);
        goto after_7;
    // 0x8022AD50: nop

    after_7:
    // 0x8022AD54: b           L_8022AF88
    // 0x8022AD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD5C:
    // 0x8022AD5C: jal         0x8038DB74
    // 0x8022AD60: nop

    LOOKUP_FUNC(0x8038DB74)(rdram, ctx);
        goto after_8;
    // 0x8022AD60: nop

    after_8:
    // 0x8022AD64: b           L_8022AF88
    // 0x8022AD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD6C:
    // 0x8022AD6C: jal         0x8038D940
    // 0x8022AD70: nop

    LOOKUP_FUNC(0x8038D940)(rdram, ctx);
        goto after_9;
    // 0x8022AD70: nop

    after_9:
    // 0x8022AD74: b           L_8022AF88
    // 0x8022AD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD7C:
    // 0x8022AD7C: jal         0x8038DC28
    // 0x8022AD80: nop

    LOOKUP_FUNC(0x8038DC28)(rdram, ctx);
        goto after_10;
    // 0x8022AD80: nop

    after_10:
    // 0x8022AD84: b           L_8022AF88
    // 0x8022AD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD8C:
    // 0x8022AD8C: jal         0x8038DA40
    // 0x8022AD90: nop

    LOOKUP_FUNC(0x8038DA40)(rdram, ctx);
        goto after_11;
    // 0x8022AD90: nop

    after_11:
    // 0x8022AD94: b           L_8022AF88
    // 0x8022AD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AD9C:
    // 0x8022AD9C: jal         0x8038DC98
    // 0x8022ADA0: nop

    LOOKUP_FUNC(0x8038DC98)(rdram, ctx);
        goto after_12;
    // 0x8022ADA0: nop

    after_12:
    // 0x8022ADA4: b           L_8022AF88
    // 0x8022ADA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ADA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ADAC:
    // 0x8022ADAC: jal         0x8038DA84
    // 0x8022ADB0: nop

    LOOKUP_FUNC(0x8038DA84)(rdram, ctx);
        goto after_13;
    // 0x8022ADB0: nop

    after_13:
    // 0x8022ADB4: b           L_8022AF88
    // 0x8022ADB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ADB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ADBC:
    // 0x8022ADBC: jal         0x8038D8E0
    // 0x8022ADC0: nop

    LOOKUP_FUNC(0x8038D8E0)(rdram, ctx);
        goto after_14;
    // 0x8022ADC0: nop

    after_14:
    // 0x8022ADC4: b           L_8022AF88
    // 0x8022ADC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ADC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ADCC:
    // 0x8022ADCC: jal         0x8038DFA0
    // 0x8022ADD0: nop

    LOOKUP_FUNC(0x8038DFA0)(rdram, ctx);
        goto after_15;
    // 0x8022ADD0: nop

    after_15:
    // 0x8022ADD4: b           L_8022AF88
    // 0x8022ADD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ADD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ADDC:
    // 0x8022ADDC: jal         0x8038DA4C
    // 0x8022ADE0: nop

    LOOKUP_FUNC(0x8038DA4C)(rdram, ctx);
        goto after_16;
    // 0x8022ADE0: nop

    after_16:
    // 0x8022ADE4: b           L_8022AF88
    // 0x8022ADE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ADE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ADEC:
    // 0x8022ADEC: jal         0x8038DA6C
    // 0x8022ADF0: nop

    LOOKUP_FUNC(0x8038DA6C)(rdram, ctx);
        goto after_17;
    // 0x8022ADF0: nop

    after_17:
    // 0x8022ADF4: b           L_8022AF88
    // 0x8022ADF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022ADF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022ADFC:
    // 0x8022ADFC: jal         0x8038D7D4
    // 0x8022AE00: nop

    LOOKUP_FUNC(0x8038D7D4)(rdram, ctx);
        goto after_18;
    // 0x8022AE00: nop

    after_18:
    // 0x8022AE04: b           L_8022AF88
    // 0x8022AE08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE0C:
    // 0x8022AE0C: jal         0x8038D6F4
    // 0x8022AE10: nop

    LOOKUP_FUNC(0x8038D6F4)(rdram, ctx);
        goto after_19;
    // 0x8022AE10: nop

    after_19:
    // 0x8022AE14: b           L_8022AF88
    // 0x8022AE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE1C:
    // 0x8022AE1C: jal         0x8038D9D8
    // 0x8022AE20: nop

    LOOKUP_FUNC(0x8038D9D8)(rdram, ctx);
        goto after_20;
    // 0x8022AE20: nop

    after_20:
    // 0x8022AE24: b           L_8022AF88
    // 0x8022AE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE2C:
    // 0x8022AE2C: jal         0x8038DC2C
    // 0x8022AE30: nop

    LOOKUP_FUNC(0x8038DC2C)(rdram, ctx);
        goto after_21;
    // 0x8022AE30: nop

    after_21:
    // 0x8022AE34: b           L_8022AF88
    // 0x8022AE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE3C:
    // 0x8022AE3C: jal         0x8038D9F0
    // 0x8022AE40: nop

    LOOKUP_FUNC(0x8038D9F0)(rdram, ctx);
        goto after_22;
    // 0x8022AE40: nop

    after_22:
    // 0x8022AE44: b           L_8022AF88
    // 0x8022AE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE4C:
    // 0x8022AE4C: jal         0x8038D9FC
    // 0x8022AE50: nop

    LOOKUP_FUNC(0x8038D9FC)(rdram, ctx);
        goto after_23;
    // 0x8022AE50: nop

    after_23:
    // 0x8022AE54: b           L_8022AF88
    // 0x8022AE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE5C:
    // 0x8022AE5C: jal         0x8038D7A4
    // 0x8022AE60: nop

    LOOKUP_FUNC(0x8038D7A4)(rdram, ctx);
        goto after_24;
    // 0x8022AE60: nop

    after_24:
    // 0x8022AE64: b           L_8022AF88
    // 0x8022AE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE6C:
    // 0x8022AE6C: jal         0x8038D7B4
    // 0x8022AE70: nop

    LOOKUP_FUNC(0x8038D7B4)(rdram, ctx);
        goto after_25;
    // 0x8022AE70: nop

    after_25:
    // 0x8022AE74: b           L_8022AF88
    // 0x8022AE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE7C:
    // 0x8022AE7C: jal         0x8038DA80
    // 0x8022AE80: nop

    LOOKUP_FUNC(0x8038DA80)(rdram, ctx);
        goto after_26;
    // 0x8022AE80: nop

    after_26:
    // 0x8022AE84: b           L_8022AF88
    // 0x8022AE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE8C:
    // 0x8022AE8C: jal         0x8038DC0C
    // 0x8022AE90: nop

    LOOKUP_FUNC(0x8038DC0C)(rdram, ctx);
        goto after_27;
    // 0x8022AE90: nop

    after_27:
    // 0x8022AE94: b           L_8022AF88
    // 0x8022AE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AE9C:
    // 0x8022AE9C: jal         0x8038DBA0
    // 0x8022AEA0: nop

    LOOKUP_FUNC(0x8038DBA0)(rdram, ctx);
        goto after_28;
    // 0x8022AEA0: nop

    after_28:
    // 0x8022AEA4: b           L_8022AF88
    // 0x8022AEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AEAC:
    // 0x8022AEAC: jal         0x8038DBC4
    // 0x8022AEB0: nop

    LOOKUP_FUNC(0x8038DBC4)(rdram, ctx);
        goto after_29;
    // 0x8022AEB0: nop

    after_29:
    // 0x8022AEB4: b           L_8022AF88
    // 0x8022AEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AEBC:
    // 0x8022AEBC: jal         0x8038D9D8
    // 0x8022AEC0: nop

    LOOKUP_FUNC(0x8038D9D8)(rdram, ctx);
        goto after_30;
    // 0x8022AEC0: nop

    after_30:
    // 0x8022AEC4: b           L_8022AF88
    // 0x8022AEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AECC:
    // 0x8022AECC: jal         0x8038D9E4
    // 0x8022AED0: nop

    LOOKUP_FUNC(0x8038D9E4)(rdram, ctx);
        goto after_31;
    // 0x8022AED0: nop

    after_31:
    // 0x8022AED4: b           L_8022AF88
    // 0x8022AED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AEDC:
    // 0x8022AEDC: jal         0x8038D950
    // 0x8022AEE0: nop

    LOOKUP_FUNC(0x8038D950)(rdram, ctx);
        goto after_32;
    // 0x8022AEE0: nop

    after_32:
    // 0x8022AEE4: b           L_8022AF88
    // 0x8022AEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AEEC:
    // 0x8022AEEC: jal         0x8038D8BC
    // 0x8022AEF0: nop

    LOOKUP_FUNC(0x8038D8BC)(rdram, ctx);
        goto after_33;
    // 0x8022AEF0: nop

    after_33:
    // 0x8022AEF4: b           L_8022AF88
    // 0x8022AEF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AEF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AEFC:
    // 0x8022AEFC: jal         0x8038DFDC
    // 0x8022AF00: nop

    LOOKUP_FUNC(0x8038DFDC)(rdram, ctx);
        goto after_34;
    // 0x8022AF00: nop

    after_34:
    // 0x8022AF04: b           L_8022AF88
    // 0x8022AF08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF0C:
    // 0x8022AF0C: jal         0x80242B2C
    // 0x8022AF10: nop

    LOOKUP_FUNC(0x80242B2C)(rdram, ctx);
        goto after_35;
    // 0x8022AF10: nop

    after_35:
    // 0x8022AF14: b           L_8022AF88
    // 0x8022AF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF1C:
    // 0x8022AF1C: jal         0x8038DBA0
    // 0x8022AF20: nop

    LOOKUP_FUNC(0x8038DBA0)(rdram, ctx);
        goto after_36;
    // 0x8022AF20: nop

    after_36:
    // 0x8022AF24: b           L_8022AF88
    // 0x8022AF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF2C:
    // 0x8022AF2C: jal         0x8038E100
    // 0x8022AF30: nop

    LOOKUP_FUNC(0x8038E100)(rdram, ctx);
        goto after_37;
    // 0x8022AF30: nop

    after_37:
    // 0x8022AF34: b           L_8022AF88
    // 0x8022AF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF3C:
    // 0x8022AF3C: jal         0x8038D92C
    // 0x8022AF40: nop

    LOOKUP_FUNC(0x8038D92C)(rdram, ctx);
        goto after_38;
    // 0x8022AF40: nop

    after_38:
    // 0x8022AF44: b           L_8022AF88
    // 0x8022AF48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF4C:
    // 0x8022AF4C: jal         0x8038DBF4
    // 0x8022AF50: nop

    LOOKUP_FUNC(0x8038DBF4)(rdram, ctx);
        goto after_39;
    // 0x8022AF50: nop

    after_39:
    // 0x8022AF54: b           L_8022AF88
    // 0x8022AF58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF5C:
    // 0x8022AF5C: jal         0x8038D584
    // 0x8022AF60: nop

    LOOKUP_FUNC(0x8038D584)(rdram, ctx);
        goto after_40;
    // 0x8022AF60: nop

    after_40:
    // 0x8022AF64: b           L_8022AF88
    // 0x8022AF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF6C:
    // 0x8022AF6C: jal         0x8038DC3C
    // 0x8022AF70: nop

    LOOKUP_FUNC(0x8038DC3C)(rdram, ctx);
        goto after_41;
    // 0x8022AF70: nop

    after_41:
    // 0x8022AF74: b           L_8022AF88
    // 0x8022AF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022AF88;
    // 0x8022AF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF7C:
    // 0x8022AF7C: jal         0x8038D93C
    // 0x8022AF80: nop

    LOOKUP_FUNC(0x8038D93C)(rdram, ctx);
        goto after_42;
    // 0x8022AF80: nop

    after_42:
    // 0x8022AF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022AF88:
    // 0x8022AF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022AF8C: jr          $ra
    // 0x8022AF90: nop

    return;
    // 0x8022AF90: nop

;}
RECOMP_FUNC void M10_FUN_8022af94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022AF94: lui         $v1, 0x8003
    ctx->r3 = S32(0X8003 << 16);
    // 0x8022AF98: addiu       $v1, $v1, 0x7C5C
    ctx->r3 = ADD32(ctx->r3, 0X7C5C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022af9c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022af9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022AF9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022AFA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022AFA4: lw          $t6, 0x1C4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C4);
    // 0x8022AFA8: lw          $t7, 0x1C0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C0);
    // 0x8022AFAC: lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X36);
    // 0x8022AFB0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8022AFB4: lw          $t9, -0x43F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X43F0);
    // 0x8022AFB8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8022AFBC: slti        $at, $v0, 0x5E
    ctx->r1 = SIGNED(ctx->r2) < 0X5E ? 1 : 0;
    // 0x8022AFC0: bne         $at, $zero, L_8022B044
    if (ctx->r1 != 0) {
        // 0x8022AFC4: addu        $a1, $t8, $t9
        ctx->r5 = ADD32(ctx->r24, ctx->r25);
            goto L_8022B044;
    }
    // 0x8022AFC4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8022AFC8: slti        $at, $v0, 0x11F
    ctx->r1 = SIGNED(ctx->r2) < 0X11F ? 1 : 0;
    // 0x8022AFCC: bne         $at, $zero, L_8022AFF4
    if (ctx->r1 != 0) {
        // 0x8022AFD0: addiu       $t0, $v0, -0x143
        ctx->r8 = ADD32(ctx->r2, -0X143);
            goto L_8022AFF4;
    }
    // 0x8022AFD0: addiu       $t0, $v0, -0x143
    ctx->r8 = ADD32(ctx->r2, -0X143);
    // 0x8022AFD4: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x8022AFD8: beq         $at, $zero, L_8022B338
    if (ctx->r1 == 0) {
        // 0x8022AFDC: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8022B338;
    }
    // 0x8022AFDC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8022AFE0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022AFE4: addu        $at, $at, $t0
    gpr jr_addend_8022AFEC = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8022AFE8: lw          $t0, -0xD18($at)
    ctx->r8 = ADD32(ctx->r1, -0XD18);
    // 0x8022AFEC: jr          $t0
    // 0x8022AFF0: nop

    switch (jr_addend_8022AFEC >> 2) {
        case 0: goto L_8022B0E8; break;
        case 1: goto L_8022B118; break;
        case 2: goto L_8022B168; break;
        case 3: goto L_8022B188; break;
        case 4: goto L_8022B248; break;
        case 5: goto L_8022B2F8; break;
        case 6: goto L_8022B198; break;
        default: switch_error(__func__, 0x8022AFEC, 0x8023F2E8);
    }
    // 0x8022AFF0: nop

L_8022AFF4:
    // 0x8022AFF4: slti        $at, $v0, 0xFE
    ctx->r1 = SIGNED(ctx->r2) < 0XFE ? 1 : 0;
    // 0x8022AFF8: bne         $at, $zero, L_8022B024
    if (ctx->r1 != 0) {
        // 0x8022AFFC: addiu       $t2, $v0, -0xF0
        ctx->r10 = ADD32(ctx->r2, -0XF0);
            goto L_8022B024;
    }
    // 0x8022AFFC: addiu       $t2, $v0, -0xF0
    ctx->r10 = ADD32(ctx->r2, -0XF0);
    // 0x8022B000: addiu       $t1, $v0, -0x119
    ctx->r9 = ADD32(ctx->r2, -0X119);
    // 0x8022B004: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8022B008: beq         $at, $zero, L_8022B338
    if (ctx->r1 == 0) {
        // 0x8022B00C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8022B338;
    }
    // 0x8022B00C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8022B010: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022B014: addu        $at, $at, $t1
    gpr jr_addend_8022B01C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8022B018: lw          $t1, -0xCFC($at)
    ctx->r9 = ADD32(ctx->r1, -0XCFC);
    // 0x8022B01C: jr          $t1
    // 0x8022B020: nop

    switch (jr_addend_8022B01C >> 2) {
        case 0: goto L_8022B128; break;
        case 1: goto L_8022B108; break;
        case 2: goto L_8022B308; break;
        case 3: goto L_8022B338; break;
        case 4: goto L_8022B318; break;
        case 5: goto L_8022B328; break;
        default: switch_error(__func__, 0x8022B01C, 0x8023F304);
    }
    // 0x8022B020: nop

L_8022B024:
    // 0x8022B024: sltiu       $at, $t2, 0xE
    ctx->r1 = ctx->r10 < 0XE ? 1 : 0;
    // 0x8022B028: beq         $at, $zero, L_8022B338
    if (ctx->r1 == 0) {
        // 0x8022B02C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8022B338;
    }
    // 0x8022B02C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8022B030: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022B034: addu        $at, $at, $t2
    gpr jr_addend_8022B03C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8022B038: lw          $t2, -0xCE4($at)
    ctx->r10 = ADD32(ctx->r1, -0XCE4);
    // 0x8022B03C: jr          $t2
    // 0x8022B040: nop

    switch (jr_addend_8022B03C >> 2) {
        case 0: goto L_8022B258; break;
        case 1: goto L_8022B268; break;
        case 2: goto L_8022B298; break;
        case 3: goto L_8022B218; break;
        case 4: goto L_8022B1B8; break;
        case 5: goto L_8022B1C8; break;
        case 6: goto L_8022B1D8; break;
        case 7: goto L_8022B338; break;
        case 8: goto L_8022B338; break;
        case 9: goto L_8022B1A8; break;
        case 10: goto L_8022B228; break;
        case 11: goto L_8022B238; break;
        case 12: goto L_8022B2A8; break;
        case 13: goto L_8022B2B8; break;
        default: switch_error(__func__, 0x8022B03C, 0x8023F31C);
    }
    // 0x8022B040: nop

L_8022B044:
    // 0x8022B044: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8022B048: bne         $at, $zero, L_8022B08C
    if (ctx->r1 != 0) {
        // 0x8022B04C: slti        $at, $v0, 0x33
        ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
            goto L_8022B08C;
    }
    // 0x8022B04C: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x8022B050: bne         $at, $zero, L_8022B078
    if (ctx->r1 != 0) {
        // 0x8022B054: addiu       $t3, $v0, -0x50
        ctx->r11 = ADD32(ctx->r2, -0X50);
            goto L_8022B078;
    }
    // 0x8022B054: addiu       $t3, $v0, -0x50
    ctx->r11 = ADD32(ctx->r2, -0X50);
    // 0x8022B058: sltiu       $at, $t3, 0xE
    ctx->r1 = ctx->r11 < 0XE ? 1 : 0;
    // 0x8022B05C: beq         $at, $zero, L_8022B338
    if (ctx->r1 == 0) {
        // 0x8022B060: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8022B338;
    }
    // 0x8022B060: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8022B064: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022B068: addu        $at, $at, $t3
    gpr jr_addend_8022B070 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8022B06C: lw          $t3, -0xCAC($at)
    ctx->r11 = ADD32(ctx->r1, -0XCAC);
    // 0x8022B070: jr          $t3
    // 0x8022B074: nop

    switch (jr_addend_8022B070 >> 2) {
        case 0: goto L_8022B0A8; break;
        case 1: goto L_8022B0B8; break;
        case 2: goto L_8022B0C8; break;
        case 3: goto L_8022B0D8; break;
        case 4: goto L_8022B158; break;
        case 5: goto L_8022B138; break;
        case 6: goto L_8022B278; break;
        case 7: goto L_8022B178; break;
        case 8: goto L_8022B0F8; break;
        case 9: goto L_8022B148; break;
        case 10: goto L_8022B1E8; break;
        case 11: goto L_8022B1F8; break;
        case 12: goto L_8022B288; break;
        case 13: goto L_8022B208; break;
        default: switch_error(__func__, 0x8022B070, 0x8023F354);
    }
    // 0x8022B074: nop

L_8022B078:
    // 0x8022B078: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8022B07C: beq         $v0, $at, L_8022B2D8
    if (ctx->r2 == ctx->r1) {
        // 0x8022B080: nop
    
            goto L_8022B2D8;
    }
    // 0x8022B080: nop

    // 0x8022B084: b           L_8022B338
    // 0x8022B088: nop

        goto L_8022B338;
    // 0x8022B088: nop

L_8022B08C:
    // 0x8022B08C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8022B090: beq         $v0, $at, L_8022B2C8
    if (ctx->r2 == ctx->r1) {
        // 0x8022B094: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_8022B2C8;
    }
    // 0x8022B094: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8022B098: beq         $v0, $at, L_8022B2E8
    if (ctx->r2 == ctx->r1) {
        // 0x8022B09C: nop
    
            goto L_8022B2E8;
    }
    // 0x8022B09C: nop

    // 0x8022B0A0: b           L_8022B338
    // 0x8022B0A4: nop

        goto L_8022B338;
    // 0x8022B0A4: nop

L_8022B0A8:
    // 0x8022B0A8: jal         0x8000469C
    // 0x8022B0AC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_0;
    // 0x8022B0AC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_0:
    // 0x8022B0B0: b           L_8022B344
    // 0x8022B0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B0B8:
    // 0x8022B0B8: jal         0x8000469C
    // 0x8022B0BC: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_1;
    // 0x8022B0BC: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_1:
    // 0x8022B0C0: b           L_8022B344
    // 0x8022B0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B0C8:
    // 0x8022B0C8: jal         0x8000469C
    // 0x8022B0CC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_2;
    // 0x8022B0CC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_2:
    // 0x8022B0D0: b           L_8022B344
    // 0x8022B0D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B0D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B0D8:
    // 0x8022B0D8: jal         0x8000469C
    // 0x8022B0DC: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_3;
    // 0x8022B0DC: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_3:
    // 0x8022B0E0: b           L_8022B344
    // 0x8022B0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B0E8:
    // 0x8022B0E8: jal         0x8000469C
    // 0x8022B0EC: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_4;
    // 0x8022B0EC: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_4:
    // 0x8022B0F0: b           L_8022B344
    // 0x8022B0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B0F8:
    // 0x8022B0F8: jal         0x8000469C
    // 0x8022B0FC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_5;
    // 0x8022B0FC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_5:
    // 0x8022B100: b           L_8022B344
    // 0x8022B104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B108:
    // 0x8022B108: jal         0x8000469C
    // 0x8022B10C: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_6;
    // 0x8022B10C: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    after_6:
    // 0x8022B110: b           L_8022B344
    // 0x8022B114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B118:
    // 0x8022B118: jal         0x8000469C
    // 0x8022B11C: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_7;
    // 0x8022B11C: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    after_7:
    // 0x8022B120: b           L_8022B344
    // 0x8022B124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B128:
    // 0x8022B128: jal         0x8000469C
    // 0x8022B12C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_8;
    // 0x8022B12C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_8:
    // 0x8022B130: b           L_8022B344
    // 0x8022B134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B138:
    // 0x8022B138: jal         0x8000469C
    // 0x8022B13C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_9;
    // 0x8022B13C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_9:
    // 0x8022B140: b           L_8022B344
    // 0x8022B144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B148:
    // 0x8022B148: jal         0x8000469C
    // 0x8022B14C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_10;
    // 0x8022B14C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_10:
    // 0x8022B150: b           L_8022B344
    // 0x8022B154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B158:
    // 0x8022B158: jal         0x8000469C
    // 0x8022B15C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_11;
    // 0x8022B15C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    after_11:
    // 0x8022B160: b           L_8022B344
    // 0x8022B164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B168:
    // 0x8022B168: jal         0x8000469C
    // 0x8022B16C: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_12;
    // 0x8022B16C: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    after_12:
    // 0x8022B170: b           L_8022B344
    // 0x8022B174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B178:
    // 0x8022B178: jal         0x8000469C
    // 0x8022B17C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_13;
    // 0x8022B17C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_13:
    // 0x8022B180: b           L_8022B344
    // 0x8022B184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B188:
    // 0x8022B188: jal         0x8000469C
    // 0x8022B18C: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_14;
    // 0x8022B18C: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_14:
    // 0x8022B190: b           L_8022B344
    // 0x8022B194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B198:
    // 0x8022B198: jal         0x8000469C
    // 0x8022B19C: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_15;
    // 0x8022B19C: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_15:
    // 0x8022B1A0: b           L_8022B344
    // 0x8022B1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B1A8:
    // 0x8022B1A8: jal         0x8000469C
    // 0x8022B1AC: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_16;
    // 0x8022B1AC: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    after_16:
    // 0x8022B1B0: b           L_8022B344
    // 0x8022B1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B1B8:
    // 0x8022B1B8: jal         0x8000469C
    // 0x8022B1BC: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_17;
    // 0x8022B1BC: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_17:
    // 0x8022B1C0: b           L_8022B344
    // 0x8022B1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B1C8:
    // 0x8022B1C8: jal         0x8000469C
    // 0x8022B1CC: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_18;
    // 0x8022B1CC: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_18:
    // 0x8022B1D0: b           L_8022B344
    // 0x8022B1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B1D8:
    // 0x8022B1D8: jal         0x8000469C
    // 0x8022B1DC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_19;
    // 0x8022B1DC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_19:
    // 0x8022B1E0: b           L_8022B344
    // 0x8022B1E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B1E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B1E8:
    // 0x8022B1E8: jal         0x8000469C
    // 0x8022B1EC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_20;
    // 0x8022B1EC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_20:
    // 0x8022B1F0: b           L_8022B344
    // 0x8022B1F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B1F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B1F8:
    // 0x8022B1F8: jal         0x8000469C
    // 0x8022B1FC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_21;
    // 0x8022B1FC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_21:
    // 0x8022B200: b           L_8022B344
    // 0x8022B204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B208:
    // 0x8022B208: jal         0x8000469C
    // 0x8022B20C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_22;
    // 0x8022B20C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_22:
    // 0x8022B210: b           L_8022B344
    // 0x8022B214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B218:
    // 0x8022B218: jal         0x8000469C
    // 0x8022B21C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_23;
    // 0x8022B21C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_23:
    // 0x8022B220: b           L_8022B344
    // 0x8022B224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B228:
    // 0x8022B228: jal         0x8000469C
    // 0x8022B22C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_24;
    // 0x8022B22C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_24:
    // 0x8022B230: b           L_8022B344
    // 0x8022B234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B238:
    // 0x8022B238: jal         0x8000469C
    // 0x8022B23C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_25;
    // 0x8022B23C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_25:
    // 0x8022B240: b           L_8022B344
    // 0x8022B244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B248:
    // 0x8022B248: jal         0x8000469C
    // 0x8022B24C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_26;
    // 0x8022B24C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_26:
    // 0x8022B250: b           L_8022B344
    // 0x8022B254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B258:
    // 0x8022B258: jal         0x8000469C
    // 0x8022B25C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_27;
    // 0x8022B25C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_27:
    // 0x8022B260: b           L_8022B344
    // 0x8022B264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B268:
    // 0x8022B268: jal         0x8000469C
    // 0x8022B26C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_28;
    // 0x8022B26C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_28:
    // 0x8022B270: b           L_8022B344
    // 0x8022B274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B278:
    // 0x8022B278: jal         0x8000469C
    // 0x8022B27C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_29;
    // 0x8022B27C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_29:
    // 0x8022B280: b           L_8022B344
    // 0x8022B284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B288:
    // 0x8022B288: jal         0x8000469C
    // 0x8022B28C: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_30;
    // 0x8022B28C: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    after_30:
    // 0x8022B290: b           L_8022B344
    // 0x8022B294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B298:
    // 0x8022B298: jal         0x8000469C
    // 0x8022B29C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_31;
    // 0x8022B29C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_31:
    // 0x8022B2A0: b           L_8022B344
    // 0x8022B2A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B2A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B2A8:
    // 0x8022B2A8: jal         0x8000469C
    // 0x8022B2AC: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_32;
    // 0x8022B2AC: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_32:
    // 0x8022B2B0: b           L_8022B344
    // 0x8022B2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B2B8:
    // 0x8022B2B8: jal         0x8000469C
    // 0x8022B2BC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_33;
    // 0x8022B2BC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_33:
    // 0x8022B2C0: b           L_8022B344
    // 0x8022B2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B2C8:
    // 0x8022B2C8: jal         0x8000469C
    // 0x8022B2CC: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_34;
    // 0x8022B2CC: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_34:
    // 0x8022B2D0: b           L_8022B344
    // 0x8022B2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B2D8:
    // 0x8022B2D8: jal         0x8000469C
    // 0x8022B2DC: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_35;
    // 0x8022B2DC: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_35:
    // 0x8022B2E0: b           L_8022B344
    // 0x8022B2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B2E8:
    // 0x8022B2E8: jal         0x8000469C
    // 0x8022B2EC: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_36;
    // 0x8022B2EC: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_36:
    // 0x8022B2F0: b           L_8022B344
    // 0x8022B2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B2F8:
    // 0x8022B2F8: jal         0x8000469C
    // 0x8022B2FC: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_37;
    // 0x8022B2FC: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_37:
    // 0x8022B300: b           L_8022B344
    // 0x8022B304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B308:
    // 0x8022B308: jal         0x8000469C
    // 0x8022B30C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_38;
    // 0x8022B30C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_38:
    // 0x8022B310: b           L_8022B344
    // 0x8022B314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B318:
    // 0x8022B318: jal         0x8000469C
    // 0x8022B31C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_39;
    // 0x8022B31C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_39:
    // 0x8022B320: b           L_8022B344
    // 0x8022B324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B328:
    // 0x8022B328: jal         0x8000469C
    // 0x8022B32C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_40;
    // 0x8022B32C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_40:
    // 0x8022B330: b           L_8022B344
    // 0x8022B334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8022B344;
    // 0x8022B334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B338:
    // 0x8022B338: jal         0x8000469C
    // 0x8022B33C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_41;
    // 0x8022B33C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_41:
    // 0x8022B340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B344:
    // 0x8022B344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022B348: jr          $ra
    // 0x8022B34C: nop

    return;
    // 0x8022B34C: nop

;}
RECOMP_FUNC void M10_FUN_8022b350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B350: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8022B354: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8022B358: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022B35C: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // 0x8022B360: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8022B364: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022B368: addiu       $v0, $v0, -0x4354
    ctx->r2 = ADD32(ctx->r2, -0X4354);
    // 0x8022B36C: bne         $t6, $t8, L_8022B380
    if (ctx->r14 != ctx->r24) {
        // 0x8022B370: nop
    
            goto L_8022B380;
    }
    // 0x8022B370: nop

    // 0x8022B374: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022B378: b           L_8022B380
    // 0x8022B37C: addiu       $v0, $v0, -0x4374
    ctx->r2 = ADD32(ctx->r2, -0X4374);
        goto L_8022B380;
    // 0x8022B37C: addiu       $v0, $v0, -0x4374
    ctx->r2 = ADD32(ctx->r2, -0X4374);
L_8022B380:
    // 0x8022B380: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8022B384: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8022B388: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8022B38C: jr          $ra
    // 0x8022B390: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    return;
    // 0x8022B390: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022b394(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022b394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B394: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022B398: lbu         $t6, -0x33DF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DF);
    // 0x8022B39C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022B3A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8022B3A4: bne         $t6, $at, L_8022B3B8
    if (ctx->r14 != ctx->r1) {
        // 0x8022B3A8: nop
    
            goto L_8022B3B8;
    }
    // 0x8022B3A8: nop

    // 0x8022B3AC: lw          $t7, 0x9C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C);
    // 0x8022B3B0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8022B3B4: sw          $t8, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r24;
L_8022B3B8:
    // 0x8022B3B8: jr          $ra
    // 0x8022B3BC: nop

    return;
    // 0x8022B3BC: nop

;}
RECOMP_FUNC void M10_FUN_8022b3c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022B3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022B3C8: jal         0x80005700
    // 0x8022B3CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x8022B3CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8022B3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022B3D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022B3D8: jr          $ra
    // 0x8022B3DC: nop

    return;
    // 0x8022B3DC: nop

;}
RECOMP_FUNC void M10_FUN_8022b3e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022B3E4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022B3E8: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8022B3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022B3F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8022B3F4: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8022B3F8: lw          $v0, 0xDC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XDC);
    // 0x8022B3FC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022B400: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
    // 0x8022B404: bne         $v0, $v1, L_8022B418
    if (ctx->r2 != ctx->r3) {
        // 0x8022B408: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_8022B418;
    }
    // 0x8022B408: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022B40C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022B410: b           L_8022B418
    // 0x8022B414: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
        goto L_8022B418;
    // 0x8022B414: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_8022B418:
    // 0x8022B418: bne         $v0, $v1, L_8022B42C
    if (ctx->r2 != ctx->r3) {
        // 0x8022B41C: addiu       $a2, $a2, -0x3FC4
        ctx->r6 = ADD32(ctx->r6, -0X3FC4);
            goto L_8022B42C;
    }
    // 0x8022B41C: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
    // 0x8022B420: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022B424: b           L_8022B42C
    // 0x8022B428: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
        goto L_8022B42C;
    // 0x8022B428: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_8022B42C:
    // 0x8022B42C: bnel        $v0, $v1, L_8022B440
    if (ctx->r2 != ctx->r3) {
        // 0x8022B430: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8022B440;
    }
    goto skip_0;
    // 0x8022B430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8022B434: b           L_8022B440
    // 0x8022B438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8022B440;
    // 0x8022B438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022B43C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8022B440:
    // 0x8022B440: lbu         $t6, 0x1031($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1031);
    // 0x8022B444: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022B448: bnel        $t6, $at, L_8022B498
    if (ctx->r14 != ctx->r1) {
        // 0x8022B44C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022B498;
    }
    goto skip_1;
    // 0x8022B44C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8022B450: lbu         $t7, 0x1030($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1030);
    // 0x8022B454: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8022B458: beql        $v0, $t7, L_8022B488
    if (ctx->r2 == ctx->r15) {
        // 0x8022B45C: sb          $t1, 0xA8($a0)
        MEM_B(0XA8, ctx->r4) = ctx->r9;
            goto L_8022B488;
    }
    goto skip_2;
    // 0x8022B45C: sb          $t1, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = ctx->r9;
    skip_2:
    // 0x8022B460: lbu         $t8, 0x2DD($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2DD);
    // 0x8022B464: bnel        $t8, $zero, L_8022B488
    if (ctx->r24 != 0) {
        // 0x8022B468: sb          $t1, 0xA8($a0)
        MEM_B(0XA8, ctx->r4) = ctx->r9;
            goto L_8022B488;
    }
    goto skip_3;
    // 0x8022B468: sb          $t1, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = ctx->r9;
    skip_3:
    // 0x8022B46C: lbu         $t9, 0xA1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XA1);
    // 0x8022B470: sb          $t9, 0x2D8($a1)
    MEM_B(0X2D8, ctx->r5) = ctx->r25;
    // 0x8022B474: lbu         $t0, 0xA2($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XA2);
    // 0x8022B478: sb          $t0, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r8;
    // 0x8022B47C: b           L_8022B48C
    // 0x8022B480: sb          $zero, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = 0;
        goto L_8022B48C;
    // 0x8022B480: sb          $zero, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = 0;
    // 0x8022B484: sb          $t1, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = ctx->r9;
L_8022B488:
    // 0x8022B488: sh          $zero, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = 0;
L_8022B48C:
    // 0x8022B48C: jal         0x800058DC
    // 0x8022B490: lw          $a1, 0xB0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XB0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8022B490: lw          $a1, 0xB0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XB0);
    after_0:
    // 0x8022B494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B498:
    // 0x8022B498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022B49C: jr          $ra
    // 0x8022B4A0: nop

    return;
    // 0x8022B4A0: nop

;}
RECOMP_FUNC void M10_FUN_8022b4a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B4A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022B4A8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022B4AC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8022B4B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022B4B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8022B4B8: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8022B4BC: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x8022B4C0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022B4C4: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
    // 0x8022B4C8: bne         $t6, $t7, L_8022B4DC
    if (ctx->r14 != ctx->r15) {
        // 0x8022B4CC: nop
    
            goto L_8022B4DC;
    }
    // 0x8022B4CC: nop

    // 0x8022B4D0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022B4D4: b           L_8022B4DC
    // 0x8022B4D8: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_8022B4DC;
    // 0x8022B4D8: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8022B4DC:
    // 0x8022B4DC: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x8022B4E0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8022B4E4: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x8022B4E8: bne         $t0, $zero, L_8022B500
    if (ctx->r8 != 0) {
        // 0x8022B4EC: nop
    
            goto L_8022B500;
    }
    // 0x8022B4EC: nop

    // 0x8022B4F0: lbu         $t1, 0x1031($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1031);
    // 0x8022B4F4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8022B4F8: bnel        $t1, $at, L_8022B50C
    if (ctx->r9 != ctx->r1) {
        // 0x8022B4FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022B50C;
    }
    goto skip_0;
    // 0x8022B4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8022B500:
    // 0x8022B500: jal         0x80005700
    // 0x8022B504: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x8022B504: nop

    after_0:
    // 0x8022B508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022B50C:
    // 0x8022B50C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022B510: jr          $ra
    // 0x8022B514: nop

    return;
    // 0x8022B514: nop

;}
RECOMP_FUNC void M10_FUN_8022b518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022B51C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8022B520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022B524: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x8022B528: sb          $zero, 0x90($a0)
    MEM_B(0X90, ctx->r4) = 0;
    // 0x8022B52C: jal         0x800058DC
    // 0x8022B530: addiu       $a1, $a1, -0x4ABC
    ctx->r5 = ADD32(ctx->r5, -0X4ABC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8022B530: addiu       $a1, $a1, -0x4ABC
    ctx->r5 = ADD32(ctx->r5, -0X4ABC);
    after_0:
    // 0x8022B534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022B538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022B53C: jr          $ra
    // 0x8022B540: nop

    return;
    // 0x8022B540: nop

;}
RECOMP_FUNC void M10_FUN_8022b544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B544: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8022B548: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8022B54C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022B550: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8022B554: lbu         $t6, 0x1030($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1030);
    // 0x8022B558: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8022B55C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8022B560: bnel        $t6, $zero, L_8022B610
    if (ctx->r14 != 0) {
        // 0x8022B564: lw          $t9, 0x818($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X818);
            goto L_8022B610;
    }
    goto skip_0;
    // 0x8022B564: lw          $t9, 0x818($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X818);
    skip_0:
    // 0x8022B568: lbu         $t7, 0xAE0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XAE0);
    // 0x8022B56C: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8022B570: bnel        $at, $zero, L_8022B610
    if (ctx->r1 != 0) {
        // 0x8022B574: lw          $t9, 0x818($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X818);
            goto L_8022B610;
    }
    goto skip_1;
    // 0x8022B574: lw          $t9, 0x818($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X818);
    skip_1:
    // 0x8022B578: lbu         $t8, 0x1031($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1031);
    // 0x8022B57C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8022B580: bnel        $t8, $at, L_8022B610
    if (ctx->r24 != ctx->r1) {
        // 0x8022B584: lw          $t9, 0x818($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X818);
            goto L_8022B610;
    }
    goto skip_2;
    // 0x8022B584: lw          $t9, 0x818($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X818);
    skip_2:
    // 0x8022B588: lbu         $t0, 0x90($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X90);
    // 0x8022B58C: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x8022B590: beql        $at, $zero, L_8022B610
    if (ctx->r1 == 0) {
        // 0x8022B594: lw          $t9, 0x818($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X818);
            goto L_8022B610;
    }
    goto skip_3;
    // 0x8022B594: lw          $t9, 0x818($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X818);
    skip_3:
    // 0x8022B598: lh          $t1, 0x44C($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X44C);
    // 0x8022B59C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8022B5A0: slti        $t2, $t1, 0x259
    ctx->r10 = SIGNED(ctx->r9) < 0X259 ? 1 : 0;
    // 0x8022B5A4: xori        $t2, $t2, 0x1
    ctx->r10 = ctx->r10 ^ 0X1;
    // 0x8022B5A8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8022B5AC: beq         $t3, $zero, L_8022B5BC
    if (ctx->r11 == 0) {
        // 0x8022B5B0: nop
    
            goto L_8022B5BC;
    }
    // 0x8022B5B0: nop

    // 0x8022B5B4: b           L_8022B5BC
    // 0x8022B5B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8022B5BC;
    // 0x8022B5B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8022B5BC:
    // 0x8022B5BC: lw          $t4, 0x448($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X448);
    // 0x8022B5C0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8022B5C4: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x8022B5C8: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8022B5CC: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8022B5D0: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8022B5D4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8022B5D8: lh          $a3, 0x12($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X12);
    // 0x8022B5DC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8022B5E0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8022B5E4: jal         0x8014ADB4
    // 0x8022B5E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8014ADB4)(rdram, ctx);
        goto after_0;
    // 0x8022B5E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8022B5EC: jal         0x8014B36C
    // 0x8022B5F0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8014B36C)(rdram, ctx);
        goto after_1;
    // 0x8022B5F0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_1:
    // 0x8022B5F4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8022B5F8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022B5FC: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8022B600: lbu         $t7, 0x90($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X90);
    // 0x8022B604: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8022B608: sb          $t8, 0x90($v1)
    MEM_B(0X90, ctx->r3) = ctx->r24;
    // 0x8022B60C: lw          $t9, 0x818($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X818);
L_8022B610:
    // 0x8022B610: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8022B614: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x8022B618: beql        $t1, $zero, L_8022B62C
    if (ctx->r9 == 0) {
        // 0x8022B61C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8022B62C;
    }
    goto skip_4;
    // 0x8022B61C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8022B620: jal         0x80005700
    // 0x8022B624: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x8022B624: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8022B628: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8022B62C:
    // 0x8022B62C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8022B630: jr          $ra
    // 0x8022B634: nop

    return;
    // 0x8022B634: nop

;}
RECOMP_FUNC void M10_FUN_8022b638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B638: nop

    // 0x8022B63C: nop

;}
RECOMP_FUNC void M10_FUN_8022b640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022B644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022B648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8022B64C: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8022B650: jal         0x8012C6B4
    // 0x8022B654: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x8022B654: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8022B658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022B65C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022B660: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8022B664: jr          $ra
    // 0x8022B668: nop

    return;
    // 0x8022B668: nop

;}
RECOMP_FUNC void M10_FUN_8022b66c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B66C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8022B670: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x8022B674: lbu         $t6, 0x1030($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X1030);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022b678(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022b678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8022B67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022B680: bne         $t6, $zero, L_8022B694
    if (ctx->r14 != 0) {
        // 0x8022B684: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8022B694;
    }
    // 0x8022B684: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8022B688: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022B68C: b           L_8022B69C
    // 0x8022B690: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
        goto L_8022B69C;
    // 0x8022B690: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
L_8022B694:
    // 0x8022B694: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022B698: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
L_8022B69C:
    // 0x8022B69C: addiu       $a0, $a3, -0x44C
    ctx->r4 = ADD32(ctx->r7, -0X44C);
    // 0x8022B6A0: bne         $a0, $t0, L_8022B6B4
    if (ctx->r4 != ctx->r8) {
        // 0x8022B6A4: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_8022B6B4;
    }
    // 0x8022B6A4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8022B6A8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022B6AC: b           L_8022B6BC
    // 0x8022B6B0: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
        goto L_8022B6BC;
    // 0x8022B6B0: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_8022B6B4:
    // 0x8022B6B4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022B6B8: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_8022B6BC:
    // 0x8022B6BC: lw          $v0, 0xDC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XDC);
    // 0x8022B6C0: bnel        $t7, $v0, L_8022B6D8
    if (ctx->r15 != ctx->r2) {
        // 0x8022B6C4: lw          $v1, 0x5C($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X5C);
            goto L_8022B6D8;
    }
    goto skip_0;
    // 0x8022B6C4: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    skip_0:
    // 0x8022B6C8: lw          $t8, 0xEC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XEC);
    // 0x8022B6CC: b           L_8022B6D8
    // 0x8022B6D0: lw          $v1, 0x5C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X5C);
        goto L_8022B6D8;
    // 0x8022B6D0: lw          $v1, 0x5C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X5C);
    // 0x8022B6D4: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
L_8022B6D8:
    // 0x8022B6D8: lbu         $t9, 0x2E8($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2E8);
    // 0x8022B6DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022B6E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022B6E4: bnel        $t9, $at, L_8022B8B4
    if (ctx->r25 != ctx->r1) {
        // 0x8022B6E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022B8B4;
    }
    goto skip_1;
    // 0x8022B6E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8022B6EC: bnel        $a0, $t0, L_8022B700
    if (ctx->r4 != ctx->r8) {
        // 0x8022B6F0: lw          $a0, 0xEC($t0)
        ctx->r4 = MEM_W(ctx->r8, 0XEC);
            goto L_8022B700;
    }
    goto skip_2;
    // 0x8022B6F0: lw          $a0, 0xEC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XEC);
    skip_2:
    // 0x8022B6F4: b           L_8022B700
    // 0x8022B6F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8022B700;
    // 0x8022B6F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8022B6FC: lw          $a0, 0xEC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XEC);
L_8022B700:
    // 0x8022B700: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8022B704: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8022B708: sb          $a2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r6;
    // 0x8022B70C: jal         0x803618B0
    // 0x8022B710: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x803618B0)(rdram, ctx);
        goto after_0;
    // 0x8022B710: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8022B714: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8022B718: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8022B71C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8022B720: lbu         $a2, 0x1E($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1E);
    // 0x8022B724: swc1        $f0, 0x2F4($a3)
    MEM_W(0X2F4, ctx->r7) = ctx->f0.u32l;
    // 0x8022B728: lbu         $t2, 0x2F1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2F1);
    // 0x8022B72C: sb          $zero, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = 0;
    // 0x8022B730: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022B734: sb          $t2, 0x2DB($a1)
    MEM_B(0X2DB, ctx->r5) = ctx->r10;
    // 0x8022B738: lbu         $t3, 0x9C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X9C);
    // 0x8022B73C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8022B740: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8022B744: bne         $t3, $at, L_8022B750
    if (ctx->r11 != ctx->r1) {
        // 0x8022B748: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_8022B750;
    }
    // 0x8022B748: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8022B74C: sb          $t4, 0x9C($v1)
    MEM_B(0X9C, ctx->r3) = ctx->r12;
L_8022B750:
    // 0x8022B750: lbu         $t5, 0x2DF($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X2DF);
    // 0x8022B754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8022B758: blez        $t5, L_8022B834
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8022B75C: addu        $v1, $a3, $a0
        ctx->r3 = ADD32(ctx->r7, ctx->r4);
            goto L_8022B834;
    }
    // 0x8022B75C: addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
L_8022B760:
    // 0x8022B760: lbu         $v0, 0x2E0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2E0);
    // 0x8022B764: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8022B768: beql        $at, $zero, L_8022B78C
    if (ctx->r1 == 0) {
        // 0x8022B76C: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_8022B78C;
    }
    goto skip_3;
    // 0x8022B76C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    skip_3:
    // 0x8022B770: bnel        $a2, $zero, L_8022B78C
    if (ctx->r6 != 0) {
        // 0x8022B774: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_8022B78C;
    }
    goto skip_4;
    // 0x8022B774: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    skip_4:
    // 0x8022B778: sh          $t1, 0x42($a1)
    MEM_H(0X42, ctx->r5) = ctx->r9;
    // 0x8022B77C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8022B780: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8022B784: lbu         $v0, 0x2E0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2E0);
    // 0x8022B788: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
L_8022B78C:
    // 0x8022B78C: beq         $at, $zero, L_8022B7A4
    if (ctx->r1 == 0) {
        // 0x8022B790: nop
    
            goto L_8022B7A4;
    }
    // 0x8022B790: nop

    // 0x8022B794: lbu         $t6, 0x2F0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B798: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8022B79C: b           L_8022B818
    // 0x8022B7A0: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
        goto L_8022B818;
    // 0x8022B7A0: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
L_8022B7A4:
    // 0x8022B7A4: bne         $t0, $v0, L_8022B7BC
    if (ctx->r8 != ctx->r2) {
        // 0x8022B7A8: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8022B7BC;
    }
    // 0x8022B7A8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8022B7AC: lbu         $t8, 0x2F0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B7B0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8022B7B4: b           L_8022B818
    // 0x8022B7B8: sb          $t9, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r25;
        goto L_8022B818;
    // 0x8022B7B8: sb          $t9, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r25;
L_8022B7BC:
    // 0x8022B7BC: beql        $at, $zero, L_8022B7D8
    if (ctx->r1 == 0) {
        // 0x8022B7C0: slti        $at, $v0, 0xD
        ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
            goto L_8022B7D8;
    }
    goto skip_5;
    // 0x8022B7C0: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    skip_5:
    // 0x8022B7C4: lbu         $t2, 0x2F0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B7C8: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x8022B7CC: b           L_8022B818
    // 0x8022B7D0: sb          $t3, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r11;
        goto L_8022B818;
    // 0x8022B7D0: sb          $t3, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r11;
    // 0x8022B7D4: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
L_8022B7D8:
    // 0x8022B7D8: beql        $at, $zero, L_8022B7F4
    if (ctx->r1 == 0) {
        // 0x8022B7DC: slti        $at, $v0, 0x10
        ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
            goto L_8022B7F4;
    }
    goto skip_6;
    // 0x8022B7DC: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    skip_6:
    // 0x8022B7E0: lbu         $t4, 0x2F0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B7E4: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8022B7E8: b           L_8022B818
    // 0x8022B7EC: sb          $t5, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r13;
        goto L_8022B818;
    // 0x8022B7EC: sb          $t5, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r13;
    // 0x8022B7F0: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
L_8022B7F4:
    // 0x8022B7F4: beql        $at, $zero, L_8022B810
    if (ctx->r1 == 0) {
        // 0x8022B7F8: lbu         $t8, 0x2F0($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
            goto L_8022B810;
    }
    goto skip_7;
    // 0x8022B7F8: lbu         $t8, 0x2F0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
    skip_7:
    // 0x8022B7FC: lbu         $t6, 0x2F0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B800: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8022B804: b           L_8022B818
    // 0x8022B808: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
        goto L_8022B818;
    // 0x8022B808: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
    // 0x8022B80C: lbu         $t8, 0x2F0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
L_8022B810:
    // 0x8022B810: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8022B814: sb          $t9, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r25;
L_8022B818:
    // 0x8022B818: lbu         $t2, 0x2DF($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X2DF);
    // 0x8022B81C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8022B820: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8022B824: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8022B828: bnel        $at, $zero, L_8022B760
    if (ctx->r1 != 0) {
        // 0x8022B82C: addu        $v1, $a3, $a0
        ctx->r3 = ADD32(ctx->r7, ctx->r4);
            goto L_8022B760;
    }
    goto skip_8;
    // 0x8022B82C: addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
    skip_8:
    // 0x8022B830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8022B834:
    // 0x8022B834: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8022B838: sb          $zero, 0x2DF($a3)
    MEM_B(0X2DF, ctx->r7) = 0;
    // 0x8022B83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022B840:
    // 0x8022B840: lbu         $t3, 0x2F0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B844: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022B848: sllv        $t5, $t4, $v0
    ctx->r13 = S32(ctx->r12 << (ctx->r2 & 31));
    // 0x8022B84C: and         $t6, $t3, $t5
    ctx->r14 = ctx->r11 & ctx->r13;
    // 0x8022B850: beq         $t6, $zero, L_8022B864
    if (ctx->r14 == 0) {
        // 0x8022B854: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8022B864;
    }
    // 0x8022B854: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8022B858: lbu         $t7, 0x2DF($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2DF);
    // 0x8022B85C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8022B860: sb          $t8, 0x2DF($a3)
    MEM_B(0X2DF, ctx->r7) = ctx->r24;
L_8022B864:
    // 0x8022B864: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8022B868: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x8022B86C: bne         $at, $zero, L_8022B840
    if (ctx->r1 != 0) {
        // 0x8022B870: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8022B840;
    }
    // 0x8022B870: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8022B874: lbu         $t2, 0x2D8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2D8);
    // 0x8022B878: lbu         $t9, 0x2DF($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2DF);
    // 0x8022B87C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8022B880: bne         $t2, $at, L_8022B898
    if (ctx->r10 != ctx->r1) {
        // 0x8022B884: sb          $t9, 0x2DF($a1)
        MEM_B(0X2DF, ctx->r5) = ctx->r25;
            goto L_8022B898;
    }
    // 0x8022B884: sb          $t9, 0x2DF($a1)
    MEM_B(0X2DF, ctx->r5) = ctx->r25;
    // 0x8022B888: lbu         $t4, 0x2DB($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2DB);
    // 0x8022B88C: beql        $t4, $zero, L_8022B89C
    if (ctx->r12 == 0) {
        // 0x8022B890: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8022B89C;
    }
    goto skip_9;
    // 0x8022B890: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    skip_9:
    // 0x8022B894: sh          $t1, 0x42($a3)
    MEM_H(0X42, ctx->r7) = ctx->r9;
L_8022B898:
    // 0x8022B898: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_8022B89C:
    // 0x8022B89C: sb          $t3, 0x2E8($a3)
    MEM_B(0X2E8, ctx->r7) = ctx->r11;
    // 0x8022B8A0: jal         0x80232E94
    // 0x8022B8A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80232E94)(rdram, ctx);
        goto after_1;
    // 0x8022B8A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8022B8A8: b           L_8022B8B4
    // 0x8022B8AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022B8B4;
    // 0x8022B8AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8022B8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022B8B4:
    // 0x8022B8B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022B8B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8022B8BC: jr          $ra
    // 0x8022B8C0: nop

    return;
    // 0x8022B8C0: nop

;}
RECOMP_FUNC void M10_FUN_8022b8c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B8C4: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B8C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8022B8CC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8022B8D0: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
    // 0x8022B8D4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8022B8D8: bne         $v0, $zero, L_8022B8EC
    if (ctx->r2 != 0) {
        // 0x8022B8DC: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_8022B8EC;
    }
    // 0x8022B8DC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8022B8E0: sb          $t7, 0x2DF($a0)
    MEM_B(0X2DF, ctx->r4) = ctx->r15;
    // 0x8022B8E4: b           L_8022B9FC
    // 0x8022B8E8: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
        goto L_8022B9FC;
    // 0x8022B8E8: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
L_8022B8EC:
    // 0x8022B8EC: beq         $t9, $zero, L_8022B908
    if (ctx->r25 == 0) {
        // 0x8022B8F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8022B908;
    }
    // 0x8022B8F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8022B8F4: lbu         $t0, 0x2F0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B8F8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8022B8FC: sb          $t1, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r9;
    // 0x8022B900: lw          $t2, 0x2D4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B904: lbu         $v1, 0xC($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0XC);
L_8022B908:
    // 0x8022B908: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    // 0x8022B90C: beql        $t3, $zero, L_8022B92C
    if (ctx->r11 == 0) {
        // 0x8022B910: andi        $v0, $v1, 0xC
        ctx->r2 = ctx->r3 & 0XC;
            goto L_8022B92C;
    }
    goto skip_0;
    // 0x8022B910: andi        $v0, $v1, 0xC
    ctx->r2 = ctx->r3 & 0XC;
    skip_0:
    // 0x8022B914: lbu         $t4, 0x2F0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B918: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8022B91C: sb          $t5, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r13;
    // 0x8022B920: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B924: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
    // 0x8022B928: andi        $v0, $v1, 0xC
    ctx->r2 = ctx->r3 & 0XC;
L_8022B92C:
    // 0x8022B92C: bne         $v0, $at, L_8022B94C
    if (ctx->r2 != ctx->r1) {
        // 0x8022B930: nop
    
            goto L_8022B94C;
    }
    // 0x8022B930: nop

    // 0x8022B934: lbu         $t7, 0x2F0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B938: ori         $t8, $t7, 0xC
    ctx->r24 = ctx->r15 | 0XC;
    // 0x8022B93C: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
    // 0x8022B940: lw          $t9, 0x2D4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B944: b           L_8022B99C
    // 0x8022B948: lbu         $v1, 0xC($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0XC);
        goto L_8022B99C;
    // 0x8022B948: lbu         $v1, 0xC($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0XC);
L_8022B94C:
    // 0x8022B94C: beql        $v0, $zero, L_8022B9A0
    if (ctx->r2 == 0) {
        // 0x8022B950: andi        $v0, $v1, 0x30
        ctx->r2 = ctx->r3 & 0X30;
            goto L_8022B9A0;
    }
    goto skip_1;
    // 0x8022B950: andi        $v0, $v1, 0x30
    ctx->r2 = ctx->r3 & 0X30;
    skip_1:
    // 0x8022B954: lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X30);
    // 0x8022B958: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022B95C: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x8022B960: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x8022B964: bnel        $t2, $at, L_8022B98C
    if (ctx->r10 != ctx->r1) {
        // 0x8022B968: lbu         $t7, 0x2F0($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
            goto L_8022B98C;
    }
    goto skip_2;
    // 0x8022B968: lbu         $t7, 0x2F0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
    skip_2:
    // 0x8022B96C: lbu         $t3, 0x2F0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B970: xori        $t4, $v0, 0xC
    ctx->r12 = ctx->r2 ^ 0XC;
    // 0x8022B974: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8022B978: sb          $t5, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r13;
    // 0x8022B97C: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B980: b           L_8022B99C
    // 0x8022B984: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
        goto L_8022B99C;
    // 0x8022B984: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
    // 0x8022B988: lbu         $t7, 0x2F0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
L_8022B98C:
    // 0x8022B98C: or          $t8, $t7, $v0
    ctx->r24 = ctx->r15 | ctx->r2;
    // 0x8022B990: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
    // 0x8022B994: lw          $t9, 0x2D4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B998: lbu         $v1, 0xC($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0XC);
L_8022B99C:
    // 0x8022B99C: andi        $v0, $v1, 0x30
    ctx->r2 = ctx->r3 & 0X30;
L_8022B9A0:
    // 0x8022B9A0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8022B9A4: bne         $v0, $at, L_8022B9BC
    if (ctx->r2 != ctx->r1) {
        // 0x8022B9A8: nop
    
            goto L_8022B9BC;
    }
    // 0x8022B9A8: nop

    // 0x8022B9AC: lbu         $t0, 0x2F0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B9B0: ori         $t1, $t0, 0x30
    ctx->r9 = ctx->r8 | 0X30;
    // 0x8022B9B4: b           L_8022B9FC
    // 0x8022B9B8: sb          $t1, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r9;
        goto L_8022B9FC;
    // 0x8022B9B8: sb          $t1, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r9;
L_8022B9BC:
    // 0x8022B9BC: beql        $v0, $zero, L_8022BA00
    if (ctx->r2 == 0) {
        // 0x8022B9C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BA00;
    }
    goto skip_3;
    // 0x8022B9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8022B9C4: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x8022B9C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022B9CC: sll         $t3, $t2, 9
    ctx->r11 = S32(ctx->r10 << 9);
    // 0x8022B9D0: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x8022B9D4: bnel        $t4, $at, L_8022B9F4
    if (ctx->r12 != ctx->r1) {
        // 0x8022B9D8: lbu         $t8, 0x2F0($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
            goto L_8022B9F4;
    }
    goto skip_4;
    // 0x8022B9D8: lbu         $t8, 0x2F0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
    skip_4:
    // 0x8022B9DC: lbu         $t5, 0x2F0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B9E0: xori        $t6, $v0, 0x30
    ctx->r14 = ctx->r2 ^ 0X30;
    // 0x8022B9E4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8022B9E8: b           L_8022B9FC
    // 0x8022B9EC: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
        goto L_8022B9FC;
    // 0x8022B9EC: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
    // 0x8022B9F0: lbu         $t8, 0x2F0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
L_8022B9F4:
    // 0x8022B9F4: or          $t9, $t8, $v0
    ctx->r25 = ctx->r24 | ctx->r2;
    // 0x8022B9F8: sb          $t9, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r25;
L_8022B9FC:
    // 0x8022B9FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022BA00:
    // 0x8022BA00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8022BA04:
    // 0x8022BA04: lbu         $t0, 0x2F0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022BA08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8022BA0C: sllv        $t2, $t1, $v1
    ctx->r10 = S32(ctx->r9 << (ctx->r3 & 31));
    // 0x8022BA10: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x8022BA14: beq         $t3, $zero, L_8022BA28
    if (ctx->r11 == 0) {
        // 0x8022BA18: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8022BA28;
    }
    // 0x8022BA18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8022BA1C: lbu         $t4, 0x2DF($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X2DF);
    // 0x8022BA20: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8022BA24: sb          $t5, 0x2DF($a0)
    MEM_B(0X2DF, ctx->r4) = ctx->r13;
L_8022BA28:
    // 0x8022BA28: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8022BA2C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8022BA30: bne         $at, $zero, L_8022BA04
    if (ctx->r1 != 0) {
        // 0x8022BA34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8022BA04;
    }
    // 0x8022BA34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8022BA38: lbu         $t6, 0x2DF($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2DF);
    // 0x8022BA3C: jr          $ra
    // 0x8022BA40: sb          $t6, 0x2DF($a1)
    MEM_B(0X2DF, ctx->r5) = ctx->r14;
    return;
    // 0x8022BA40: sb          $t6, 0x2DF($a1)
    MEM_B(0X2DF, ctx->r5) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022ba44(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022ba44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BA44: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022BA48: lbu         $v0, -0x33E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022ba4c(rdram, ctx);
;}
