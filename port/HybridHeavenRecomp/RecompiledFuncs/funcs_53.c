#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801d24d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D24D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D24DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D24E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D24E4: jal         0x801CC540
    // 0x801D24E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D24E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D24EC: beq         $v0, $zero, L_801D250C
    if (ctx->r2 == 0) {
        // 0x801D24F0: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D250C;
    }
    // 0x801D24F0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D24F4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D24F8: addiu       $a1, $a1, 0x24D8
    ctx->r5 = ADD32(ctx->r5, 0X24D8);
    // 0x801D24FC: jal         0x800058DC
    // 0x801D2500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D2504: b           L_801D26F8
    // 0x801D2508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D26F8;
    // 0x801D2508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D250C:
    // 0x801D250C: lw          $t6, -0x4DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4DA8);
    // 0x801D2510: beq         $t6, $zero, L_801D2568
    if (ctx->r14 == 0) {
        // 0x801D2514: nop
    
            goto L_801D2568;
    }
    // 0x801D2514: nop

    // 0x801D2518: jal         0x80006214
    // 0x801D251C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D251C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D2520: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2524: lw          $t7, -0x4DA8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4DA8);
    // 0x801D2528: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D252C: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D2530: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D2534: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D2538: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D253C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D2540: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D2544: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D2548: jal         0x8013A28C
    // 0x801D254C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D254C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D2550: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D2554: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D2558: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D255C: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D2560: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D2564: sw          $zero, -0x4DA8($at)
    MEM_W(-0X4DA8, ctx->r1) = 0;
L_801D2568:
    // 0x801D2568: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D256C: lw          $v0, -0x4DA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4DA4);
    // 0x801D2570: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D2574: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D2578: beq         $v0, $zero, L_801D2644
    if (ctx->r2 == 0) {
        // 0x801D257C: nop
    
            goto L_801D2644;
    }
    // 0x801D257C: nop

    // 0x801D2580: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D2584: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D2588: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D258C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D2590: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D2594: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D2598: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D259C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D25A0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D25A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D25A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D25AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D25B0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D25B4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D25B8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D25BC: nop

    // 0x801D25C0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D25C4: beql        $t4, $zero, L_801D2614
    if (ctx->r12 == 0) {
        // 0x801D25C8: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D2614;
    }
    goto skip_0;
    // 0x801D25C8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D25CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D25D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D25D4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D25D8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D25DC: nop

    // 0x801D25E0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D25E4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D25E8: nop

    // 0x801D25EC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D25F0: bne         $t4, $zero, L_801D2608
    if (ctx->r12 != 0) {
        // 0x801D25F4: nop
    
            goto L_801D2608;
    }
    // 0x801D25F4: nop

    // 0x801D25F8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D25FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D2600: b           L_801D2620
    // 0x801D2604: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D2620;
    // 0x801D2604: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D2608:
    // 0x801D2608: b           L_801D2620
    // 0x801D260C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D2620;
    // 0x801D260C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D2610: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D2614:
    // 0x801D2614: nop

    // 0x801D2618: bltz        $t4, L_801D2608
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D261C: nop
    
            goto L_801D2608;
    }
    // 0x801D261C: nop

L_801D2620:
    // 0x801D2620: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D2624: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D2628: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D262C: jal         0x80011140
    // 0x801D2630: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D2630: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D2634: beq         $v0, $zero, L_801D26BC
    if (ctx->r2 == 0) {
        // 0x801D2638: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D26BC;
    }
    // 0x801D2638: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D263C: b           L_801D26BC
    // 0x801D2640: sw          $zero, -0x4DA4($at)
    MEM_W(-0X4DA4, ctx->r1) = 0;
        goto L_801D26BC;
    // 0x801D2640: sw          $zero, -0x4DA4($at)
    MEM_W(-0X4DA4, ctx->r1) = 0;
L_801D2644:
    // 0x801D2644: jal         0x80010550
    // 0x801D2648: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D2648: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D264C: beq         $v0, $zero, L_801D2664
    if (ctx->r2 == 0) {
        // 0x801D2650: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D2664;
    }
    // 0x801D2650: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2654: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D2658: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D265C: b           L_801D2668
    // 0x801D2660: sw          $t5, -0x4D80($at)
    MEM_W(-0X4D80, ctx->r1) = ctx->r13;
        goto L_801D2668;
    // 0x801D2660: sw          $t5, -0x4D80($at)
    MEM_W(-0X4D80, ctx->r1) = ctx->r13;
L_801D2664:
    // 0x801D2664: sw          $zero, -0x4D80($at)
    MEM_W(-0X4D80, ctx->r1) = 0;
L_801D2668:
    // 0x801D2668: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D266C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2670: addiu       $t6, $t6, 0x1418
    ctx->r14 = ADD32(ctx->r14, 0X1418);
    // 0x801D2674: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D2678: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D267C: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D2680: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D2684: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D2688: addiu       $t2, $t2, 0x1408
    ctx->r10 = ADD32(ctx->r10, 0X1408);
    // 0x801D268C: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D2690: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D2694: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D2698: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D269C: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D26A0: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D26A4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D26A8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D26AC: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D26B0: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D26B4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D26B8: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D26BC:
    // 0x801D26BC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D26C0: lw          $t7, -0x4D88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D88);
    // 0x801D26C4: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D26C8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D26CC: beq         $t7, $zero, L_801D26E0
    if (ctx->r15 == 0) {
        // 0x801D26D0: lui         $t9, 0x801E
        ctx->r25 = S32(0X801E << 16);
            goto L_801D26E0;
    }
    // 0x801D26D0: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801D26D4: lw          $t8, -0x4D84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4D84);
    // 0x801D26D8: lw          $t6, -0x4D8C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D8C);
    // 0x801D26DC: sb          $t8, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r24;
L_801D26E0:
    // 0x801D26E0: lw          $t9, -0x4DC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4DC0);
    // 0x801D26E4: beql        $t9, $zero, L_801D26F8
    if (ctx->r25 == 0) {
        // 0x801D26E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D26F8;
    }
    goto skip_1;
    // 0x801D26E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D26EC: jal         0x801D2810
    // 0x801D26F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D2810)(rdram, ctx);
        goto after_6;
    // 0x801D26F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x801D26F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D26F8:
    // 0x801D26F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D26FC: jr          $ra
    // 0x801D2700: nop

    return;
    // 0x801D2700: nop

;}
RECOMP_FUNC void M24_FUN_801d2704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2704: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2708: jr          $ra
    // 0x801D270C: sw          $a0, -0x4D88($at)
    MEM_W(-0X4D88, ctx->r1) = ctx->r4;
    return;
    // 0x801D270C: sw          $a0, -0x4D88($at)
    MEM_W(-0X4D88, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2710(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2710: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2714: jr          $ra
    // 0x801D2718: sw          $a0, -0x4D84($at)
    MEM_W(-0X4D84, ctx->r1) = ctx->r4;
    return;
    // 0x801D2718: sw          $a0, -0x4D84($at)
    MEM_W(-0X4D84, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d271c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d271c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D271C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2720: addiu       $v0, $v0, -0x4DC0
    ctx->r2 = ADD32(ctx->r2, -0X4DC0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2724(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D2728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D272C: beq         $a0, $zero, L_801D2758
    if (ctx->r4 == 0) {
        // 0x801D2730: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D2758;
    }
    // 0x801D2730: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D2734: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2738: jal         0x801C0B2C
    // 0x801D273C: sw          $zero, -0x4D90($at)
    MEM_W(-0X4D90, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D273C: sw          $zero, -0x4D90($at)
    MEM_W(-0X4D90, ctx->r1) = 0;
    after_0:
    // 0x801D2740: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2744: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
    // 0x801D2748: sw          $v1, 0x142C($at)
    MEM_W(0X142C, ctx->r1) = ctx->r3;
    // 0x801D274C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2750: b           L_801D276C
    // 0x801D2754: sw          $zero, 0x1430($at)
    MEM_W(0X1430, ctx->r1) = 0;
        goto L_801D276C;
    // 0x801D2754: sw          $zero, 0x1430($at)
    MEM_W(0X1430, ctx->r1) = 0;
L_801D2758:
    // 0x801D2758: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D275C: lw          $a0, 0x1400($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1400);
    // 0x801D2760: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801D2764: jal         0x8012D844
    // 0x801D2768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D2768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D276C:
    // 0x801D276C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D2770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2774: jr          $ra
    // 0x801D2778: nop

    return;
    // 0x801D2778: nop

;}
RECOMP_FUNC void M24_FUN_801d277c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D277C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2780: lw          $v0, -0x4DA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4DA4);
    // 0x801D2784: jr          $ra
    // 0x801D2788: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D2788: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d278c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d278c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D278C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2790: lw          $t6, -0x4DA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4DA4);
    // 0x801D2794: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2798: beq         $t6, $zero, L_801D27A8
    if (ctx->r14 == 0) {
            // 0x801D279C: nop

    LOOKUP_FUNC(0x801D27A8)(rdram, ctx);
    return;
    }
    // 0x801D279C: nop

    // 0x801D27A0: jr          $ra
    // 0x801D27A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D27A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d27a8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d27a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D27A8: lw          $t7, -0x4DA8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4DA8);
    // 0x801D27AC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D27B0: beq         $t7, $zero, L_801D27C0
    if (ctx->r15 == 0) {
            // 0x801D27B4: nop

    LOOKUP_FUNC(0x801D27C0)(rdram, ctx);
    return;
    }
    // 0x801D27B4: nop

    // 0x801D27B8: jr          $ra
    // 0x801D27BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D27BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d27c0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d27c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D27C0: lw          $v0, -0x4D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D80);
    // 0x801D27C4: jr          $ra
    // 0x801D27C8: nop

    return;
    // 0x801D27C8: nop

;}
RECOMP_FUNC void M24_FUN_801d27cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D27CC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D27D0: jr          $ra
    // 0x801D27D4: addiu       $v0, $v0, 0x1408
    ctx->r2 = ADD32(ctx->r2, 0X1408);
    return;
    // 0x801D27D4: addiu       $v0, $v0, 0x1408
    ctx->r2 = ADD32(ctx->r2, 0X1408);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d27d8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d27d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D27D8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D27DC: addiu       $v1, $v1, 0x1418
    ctx->r3 = ADD32(ctx->r3, 0X1418);
    // 0x801D27E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D27E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D27E8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D27EC: beql        $a0, $t6, L_801D2800
    if (ctx->r4 == ctx->r14) {
        // 0x801D27F0: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D2800;
    }
    goto skip_0;
    // 0x801D27F0: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D27F4: jr          $ra
    // 0x801D27F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D27F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D27FC: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D2800:
    // 0x801D2800: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D2804: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D2808: jr          $ra
    // 0x801D280C: nop

    return;
    // 0x801D280C: nop

;}
RECOMP_FUNC void M24_FUN_801d2810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2810: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2818: jal         0x801C0B2C
    // 0x801D281C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D281C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D2820: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2824: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2828: lw          $t7, 0x142C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X142C);
    // 0x801D282C: lw          $t6, 0x1428($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1428);
    // 0x801D2830: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D2834: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D2838: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D283C: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D2840: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D2844: jal         0x80034C24
    // 0x801D2848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D2848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D284C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2850: ldc1        $f4, -0x2B40($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2B40);
    // 0x801D2854: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D2858: addiu       $a3, $a3, 0x1430
    ctx->r7 = ADD32(ctx->r7, 0X1430);
    // 0x801D285C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D2860: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D2864: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D2868: addiu       $t1, $t1, -0x4D7C
    ctx->r9 = ADD32(ctx->r9, -0X4D7C);
    // 0x801D286C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D2870: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D2874: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D2878: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D287C: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D2880: nop

    // 0x801D2884: bc1fl       L_801D2964
    if (!c1cs) {
        // 0x801D2888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D2964;
    }
    goto skip_0;
    // 0x801D2888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D288C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D2890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D2894: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801D2898: beq         $v0, $zero, L_801D28BC
    if (ctx->r2 == 0) {
        // 0x801D289C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D28BC;
    }
    // 0x801D289C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D28A0: beq         $v0, $at, L_801D28D8
    if (ctx->r2 == ctx->r1) {
        // 0x801D28A4: addiu       $a1, $zero, 0x32
        ctx->r5 = ADD32(0, 0X32);
            goto L_801D28D8;
    }
    // 0x801D28A4: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801D28A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D28AC: beq         $v0, $at, L_801D28F8
    if (ctx->r2 == ctx->r1) {
        // 0x801D28B0: addiu       $a1, $zero, 0x32
        ctx->r5 = ADD32(0, 0X32);
            goto L_801D28F8;
    }
    // 0x801D28B0: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801D28B4: b           L_801D2918
    // 0x801D28B8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D2918;
    // 0x801D28B8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D28BC:
    // 0x801D28BC: jal         0x8012D844
    // 0x801D28C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D28C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D28C4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D28C8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D28CC: addiu       $a3, $a3, 0x1430
    ctx->r7 = ADD32(ctx->r7, 0X1430);
    // 0x801D28D0: b           L_801D2914
    // 0x801D28D4: lw          $a0, 0x1430($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1430);
        goto L_801D2914;
    // 0x801D28D4: lw          $a0, 0x1430($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1430);
L_801D28D8:
    // 0x801D28D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D28DC: jal         0x8012D844
    // 0x801D28E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D28E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D28E4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D28E8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D28EC: addiu       $a3, $a3, 0x1430
    ctx->r7 = ADD32(ctx->r7, 0X1430);
    // 0x801D28F0: b           L_801D2914
    // 0x801D28F4: lw          $a0, 0x1430($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1430);
        goto L_801D2914;
    // 0x801D28F4: lw          $a0, 0x1430($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1430);
L_801D28F8:
    // 0x801D28F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D28FC: jal         0x8012D844
    // 0x801D2900: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D2900: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D2904: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2908: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D290C: addiu       $a3, $a3, 0x1430
    ctx->r7 = ADD32(ctx->r7, 0X1430);
    // 0x801D2910: lw          $a0, 0x1430($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1430);
L_801D2914:
    // 0x801D2914: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D2918:
    // 0x801D2918: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D291C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D2920: bne         $at, $zero, L_801D294C
    if (ctx->r1 != 0) {
        // 0x801D2924: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D294C;
    }
    // 0x801D2924: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D2928: jal         0x801C0B2C
    // 0x801D292C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D292C: nop

    after_5:
    // 0x801D2930: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2934: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2938: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D293C: addiu       $a3, $a3, 0x1430
    ctx->r7 = ADD32(ctx->r7, 0X1430);
    // 0x801D2940: lw          $a0, 0x1430($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1430);
    // 0x801D2944: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
    // 0x801D2948: sw          $v1, 0x142C($at)
    MEM_W(0X142C, ctx->r1) = ctx->r3;
L_801D294C:
    // 0x801D294C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D2950: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D2954: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D2958: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D295C: nop

    // 0x801D2960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2964:
    // 0x801D2964: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D2968: jr          $ra
    // 0x801D296C: nop

    return;
    // 0x801D296C: nop

;}
RECOMP_FUNC void M24_FUN_801d2970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2970: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2974: sw          $zero, -0x4CEC($at)
    MEM_W(-0X4CEC, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2978(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2978: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D297C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2980: sw          $zero, -0x4CE8($at)
    MEM_W(-0X4CE8, ctx->r1) = 0;
    // 0x801D2984: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D2988: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D298C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D2990: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2994: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D2998: addiu       $t7, $t7, 0x29C4
    ctx->r15 = ADD32(ctx->r15, 0X29C4);
    // 0x801D299C: sw          $t6, -0x4CE4($at)
    MEM_W(-0X4CE4, ctx->r1) = ctx->r14;
    // 0x801D29A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D29A4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x801D29A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D29AC: jal         0x8013B570
    // 0x801D29B0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D29B0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D29B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D29B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D29BC: jr          $ra
    // 0x801D29C0: nop

    return;
    // 0x801D29C0: nop

;}
RECOMP_FUNC void M24_FUN_801d29c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D29C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D29C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D29CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D29D0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D29D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D29D8: beq         $t6, $zero, L_801D29F4
    if (ctx->r14 == 0) {
        // 0x801D29DC: nop
    
            goto L_801D29F4;
    }
    // 0x801D29DC: nop

    // 0x801D29E0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D29E4: jal         0x800058DC
    // 0x801D29E8: addiu       $a1, $a1, 0x2A0C
    ctx->r5 = ADD32(ctx->r5, 0X2A0C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801D29E8: addiu       $a1, $a1, 0x2A0C
    ctx->r5 = ADD32(ctx->r5, 0X2A0C);
    after_0:
    // 0x801D29EC: b           L_801D2A00
    // 0x801D29F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D2A00;
    // 0x801D29F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D29F4:
    // 0x801D29F4: jal         0x800058DC
    // 0x801D29F8: addiu       $a1, $a1, 0x29C4
    ctx->r5 = ADD32(ctx->r5, 0X29C4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D29F8: addiu       $a1, $a1, 0x29C4
    ctx->r5 = ADD32(ctx->r5, 0X29C4);
    after_1:
    // 0x801D29FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2A00:
    // 0x801D2A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2A04: jr          $ra
    // 0x801D2A08: nop

    return;
    // 0x801D2A08: nop

;}
RECOMP_FUNC void M24_FUN_801d2a0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2A0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2A10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D2A14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D2A18: jal         0x801CC540
    // 0x801D2A1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D2A1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D2A20: beq         $v0, $zero, L_801D2A40
    if (ctx->r2 == 0) {
        // 0x801D2A24: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D2A40;
    }
    // 0x801D2A24: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2A28: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2A2C: addiu       $a1, $a1, 0x2A0C
    ctx->r5 = ADD32(ctx->r5, 0X2A0C);
    // 0x801D2A30: jal         0x800058DC
    // 0x801D2A34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2A34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D2A38: b           L_801D2BF4
    // 0x801D2A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D2BF4;
    // 0x801D2A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D2A40:
    // 0x801D2A40: lw          $t6, -0x4CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CEC);
    // 0x801D2A44: beq         $t6, $zero, L_801D2A9C
    if (ctx->r14 == 0) {
        // 0x801D2A48: nop
    
            goto L_801D2A9C;
    }
    // 0x801D2A48: nop

    // 0x801D2A4C: jal         0x80006214
    // 0x801D2A50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D2A50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D2A54: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2A58: lw          $t7, -0x4CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CEC);
    // 0x801D2A5C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D2A60: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D2A64: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D2A68: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D2A6C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D2A70: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D2A74: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D2A78: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D2A7C: jal         0x8013A28C
    // 0x801D2A80: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D2A80: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D2A84: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D2A88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D2A8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2A90: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D2A94: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D2A98: sw          $zero, -0x4CEC($at)
    MEM_W(-0X4CEC, ctx->r1) = 0;
L_801D2A9C:
    // 0x801D2A9C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2AA0: lw          $v0, -0x4CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CE8);
    // 0x801D2AA4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D2AA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D2AAC: beq         $v0, $zero, L_801D2B78
    if (ctx->r2 == 0) {
        // 0x801D2AB0: nop
    
            goto L_801D2B78;
    }
    // 0x801D2AB0: nop

    // 0x801D2AB4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D2AB8: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D2ABC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D2AC0: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D2AC4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D2AC8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D2ACC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D2AD0: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D2AD4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D2AD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D2ADC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D2AE0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D2AE4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D2AE8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D2AEC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D2AF0: nop

    // 0x801D2AF4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D2AF8: beql        $t4, $zero, L_801D2B48
    if (ctx->r12 == 0) {
        // 0x801D2AFC: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D2B48;
    }
    goto skip_0;
    // 0x801D2AFC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D2B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D2B04: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D2B08: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D2B0C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D2B10: nop

    // 0x801D2B14: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D2B18: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D2B1C: nop

    // 0x801D2B20: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D2B24: bne         $t4, $zero, L_801D2B3C
    if (ctx->r12 != 0) {
        // 0x801D2B28: nop
    
            goto L_801D2B3C;
    }
    // 0x801D2B28: nop

    // 0x801D2B2C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D2B30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D2B34: b           L_801D2B54
    // 0x801D2B38: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D2B54;
    // 0x801D2B38: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D2B3C:
    // 0x801D2B3C: b           L_801D2B54
    // 0x801D2B40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D2B54;
    // 0x801D2B40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D2B44: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D2B48:
    // 0x801D2B48: nop

    // 0x801D2B4C: bltz        $t4, L_801D2B3C
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D2B50: nop
    
            goto L_801D2B3C;
    }
    // 0x801D2B50: nop

L_801D2B54:
    // 0x801D2B54: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D2B58: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D2B5C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D2B60: jal         0x80011140
    // 0x801D2B64: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D2B64: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D2B68: beq         $v0, $zero, L_801D2BF0
    if (ctx->r2 == 0) {
        // 0x801D2B6C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D2BF0;
    }
    // 0x801D2B6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2B70: b           L_801D2BF0
    // 0x801D2B74: sw          $zero, -0x4CE8($at)
    MEM_W(-0X4CE8, ctx->r1) = 0;
        goto L_801D2BF0;
    // 0x801D2B74: sw          $zero, -0x4CE8($at)
    MEM_W(-0X4CE8, ctx->r1) = 0;
L_801D2B78:
    // 0x801D2B78: jal         0x80010550
    // 0x801D2B7C: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D2B7C: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D2B80: beq         $v0, $zero, L_801D2B98
    if (ctx->r2 == 0) {
        // 0x801D2B84: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D2B98;
    }
    // 0x801D2B84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2B88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D2B8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2B90: b           L_801D2B9C
    // 0x801D2B94: sw          $t5, -0x4CE4($at)
    MEM_W(-0X4CE4, ctx->r1) = ctx->r13;
        goto L_801D2B9C;
    // 0x801D2B94: sw          $t5, -0x4CE4($at)
    MEM_W(-0X4CE4, ctx->r1) = ctx->r13;
L_801D2B98:
    // 0x801D2B98: sw          $zero, -0x4CE4($at)
    MEM_W(-0X4CE4, ctx->r1) = 0;
L_801D2B9C:
    // 0x801D2B9C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D2BA0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2BA4: addiu       $t6, $t6, 0x1450
    ctx->r14 = ADD32(ctx->r14, 0X1450);
    // 0x801D2BA8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D2BAC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D2BB0: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D2BB4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D2BB8: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D2BBC: addiu       $t2, $t2, 0x1440
    ctx->r10 = ADD32(ctx->r10, 0X1440);
    // 0x801D2BC0: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D2BC4: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D2BC8: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D2BCC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D2BD0: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D2BD4: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D2BD8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D2BDC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D2BE0: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D2BE4: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D2BE8: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D2BEC: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D2BF0:
    // 0x801D2BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D2BF4:
    // 0x801D2BF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D2BF8: jr          $ra
    // 0x801D2BFC: nop

    return;
    // 0x801D2BFC: nop

;}
RECOMP_FUNC void M24_FUN_801d2c00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C00: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2C04: lw          $v0, -0x4CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CE8);
    // 0x801D2C08: jr          $ra
    // 0x801D2C0C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D2C0C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2c10(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2c10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C10: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2C14: lw          $t6, -0x4CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CE8);
    // 0x801D2C18: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2C1C: beq         $t6, $zero, L_801D2C2C
    if (ctx->r14 == 0) {
            // 0x801D2C20: nop

    LOOKUP_FUNC(0x801D2C2C)(rdram, ctx);
    return;
    }
    // 0x801D2C20: nop

    // 0x801D2C24: jr          $ra
    // 0x801D2C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D2C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2c2c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2c2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C2C: lw          $t7, -0x4CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CEC);
    // 0x801D2C30: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2C34: beq         $t7, $zero, L_801D2C44
    if (ctx->r15 == 0) {
            // 0x801D2C38: nop

    LOOKUP_FUNC(0x801D2C44)(rdram, ctx);
    return;
    }
    // 0x801D2C38: nop

    // 0x801D2C3C: jr          $ra
    // 0x801D2C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D2C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2c44(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2c44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C44: lw          $v0, -0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CE4);
    // 0x801D2C48: jr          $ra
    // 0x801D2C4C: nop

    return;
    // 0x801D2C4C: nop

;}
RECOMP_FUNC void M24_FUN_801d2c50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C50: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2C54: jr          $ra
    // 0x801D2C58: addiu       $v0, $v0, 0x1440
    ctx->r2 = ADD32(ctx->r2, 0X1440);
    return;
    // 0x801D2C58: addiu       $v0, $v0, 0x1440
    ctx->r2 = ADD32(ctx->r2, 0X1440);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2c5c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2c5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C5C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D2C60: addiu       $v1, $v1, 0x1450
    ctx->r3 = ADD32(ctx->r3, 0X1450);
    // 0x801D2C64: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D2C68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D2C6C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D2C70: beql        $a0, $t6, L_801D2C84
    if (ctx->r4 == ctx->r14) {
        // 0x801D2C74: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D2C84;
    }
    goto skip_0;
    // 0x801D2C74: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D2C78: jr          $ra
    // 0x801D2C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D2C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D2C80: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D2C84:
    // 0x801D2C84: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D2C88: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D2C8C: jr          $ra
    // 0x801D2C90: nop

    return;
    // 0x801D2C90: nop

;}
RECOMP_FUNC void M24_FUN_801d2c94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C94: nop

    // 0x801D2C98: nop

    // 0x801D2C9C: nop

;}
RECOMP_FUNC void M24_FUN_801d2ca0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2CA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2CA4: sw          $zero, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2ca8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2ca8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2CA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2CAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2CB0: sw          $zero, -0x4CC8($at)
    MEM_W(-0X4CC8, ctx->r1) = 0;
    // 0x801D2CB4: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D2CB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D2CBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D2CC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2CC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D2CC8: addiu       $t7, $t7, 0x2CF4
    ctx->r15 = ADD32(ctx->r15, 0X2CF4);
    // 0x801D2CCC: sw          $t6, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r14;
    // 0x801D2CD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D2CD4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x801D2CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D2CDC: jal         0x8013B570
    // 0x801D2CE0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D2CE0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D2CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D2CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D2CEC: jr          $ra
    // 0x801D2CF0: nop

    return;
    // 0x801D2CF0: nop

;}
RECOMP_FUNC void M24_FUN_801d2cf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2CF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D2CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2CFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D2D00: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D2D04: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2D08: beq         $t6, $zero, L_801D2D24
    if (ctx->r14 == 0) {
        // 0x801D2D0C: nop
    
            goto L_801D2D24;
    }
    // 0x801D2D0C: nop

    // 0x801D2D10: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2D14: jal         0x800058DC
    // 0x801D2D18: addiu       $a1, $a1, 0x2D3C
    ctx->r5 = ADD32(ctx->r5, 0X2D3C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801D2D18: addiu       $a1, $a1, 0x2D3C
    ctx->r5 = ADD32(ctx->r5, 0X2D3C);
    after_0:
    // 0x801D2D1C: b           L_801D2D30
    // 0x801D2D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D2D30;
    // 0x801D2D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2D24:
    // 0x801D2D24: jal         0x800058DC
    // 0x801D2D28: addiu       $a1, $a1, 0x2CF4
    ctx->r5 = ADD32(ctx->r5, 0X2CF4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2D28: addiu       $a1, $a1, 0x2CF4
    ctx->r5 = ADD32(ctx->r5, 0X2CF4);
    after_1:
    // 0x801D2D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2D30:
    // 0x801D2D30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2D34: jr          $ra
    // 0x801D2D38: nop

    return;
    // 0x801D2D38: nop

;}
RECOMP_FUNC void M24_FUN_801d2d3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D2D44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D2D48: jal         0x801CC540
    // 0x801D2D4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D2D4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D2D50: beq         $v0, $zero, L_801D2D70
    if (ctx->r2 == 0) {
        // 0x801D2D54: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D2D70;
    }
    // 0x801D2D54: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2D58: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2D5C: addiu       $a1, $a1, 0x2D3C
    ctx->r5 = ADD32(ctx->r5, 0X2D3C);
    // 0x801D2D60: jal         0x800058DC
    // 0x801D2D64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2D64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D2D68: b           L_801D2F24
    // 0x801D2D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D2F24;
    // 0x801D2D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D2D70:
    // 0x801D2D70: lw          $t6, -0x4CCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CCC);
    // 0x801D2D74: beq         $t6, $zero, L_801D2DCC
    if (ctx->r14 == 0) {
        // 0x801D2D78: nop
    
            goto L_801D2DCC;
    }
    // 0x801D2D78: nop

    // 0x801D2D7C: jal         0x80006214
    // 0x801D2D80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D2D80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D2D84: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2D88: lw          $t7, -0x4CCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CCC);
    // 0x801D2D8C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D2D90: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D2D94: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D2D98: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D2D9C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D2DA0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D2DA4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D2DA8: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D2DAC: jal         0x8013A28C
    // 0x801D2DB0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D2DB0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D2DB4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D2DB8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D2DBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2DC0: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D2DC4: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D2DC8: sw          $zero, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = 0;
L_801D2DCC:
    // 0x801D2DCC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2DD0: lw          $v0, -0x4CC8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC8);
    // 0x801D2DD4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D2DD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D2DDC: beq         $v0, $zero, L_801D2EA8
    if (ctx->r2 == 0) {
        // 0x801D2DE0: nop
    
            goto L_801D2EA8;
    }
    // 0x801D2DE0: nop

    // 0x801D2DE4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D2DE8: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D2DEC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D2DF0: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D2DF4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D2DF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D2DFC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D2E00: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D2E04: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D2E08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D2E0C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D2E10: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D2E14: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D2E18: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D2E1C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D2E20: nop

    // 0x801D2E24: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D2E28: beql        $t4, $zero, L_801D2E78
    if (ctx->r12 == 0) {
        // 0x801D2E2C: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D2E78;
    }
    goto skip_0;
    // 0x801D2E2C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D2E30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D2E34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D2E38: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D2E3C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D2E40: nop

    // 0x801D2E44: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D2E48: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D2E4C: nop

    // 0x801D2E50: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D2E54: bne         $t4, $zero, L_801D2E6C
    if (ctx->r12 != 0) {
        // 0x801D2E58: nop
    
            goto L_801D2E6C;
    }
    // 0x801D2E58: nop

    // 0x801D2E5C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D2E60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D2E64: b           L_801D2E84
    // 0x801D2E68: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D2E84;
    // 0x801D2E68: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D2E6C:
    // 0x801D2E6C: b           L_801D2E84
    // 0x801D2E70: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D2E84;
    // 0x801D2E70: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D2E74: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D2E78:
    // 0x801D2E78: nop

    // 0x801D2E7C: bltz        $t4, L_801D2E6C
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D2E80: nop
    
            goto L_801D2E6C;
    }
    // 0x801D2E80: nop

L_801D2E84:
    // 0x801D2E84: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D2E88: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D2E8C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D2E90: jal         0x80011140
    // 0x801D2E94: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D2E94: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D2E98: beq         $v0, $zero, L_801D2F20
    if (ctx->r2 == 0) {
        // 0x801D2E9C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D2F20;
    }
    // 0x801D2E9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2EA0: b           L_801D2F20
    // 0x801D2EA4: sw          $zero, -0x4CC8($at)
    MEM_W(-0X4CC8, ctx->r1) = 0;
        goto L_801D2F20;
    // 0x801D2EA4: sw          $zero, -0x4CC8($at)
    MEM_W(-0X4CC8, ctx->r1) = 0;
L_801D2EA8:
    // 0x801D2EA8: jal         0x80010550
    // 0x801D2EAC: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D2EAC: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D2EB0: beq         $v0, $zero, L_801D2EC8
    if (ctx->r2 == 0) {
        // 0x801D2EB4: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D2EC8;
    }
    // 0x801D2EB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2EB8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D2EBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2EC0: b           L_801D2ECC
    // 0x801D2EC4: sw          $t5, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r13;
        goto L_801D2ECC;
    // 0x801D2EC4: sw          $t5, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r13;
L_801D2EC8:
    // 0x801D2EC8: sw          $zero, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = 0;
L_801D2ECC:
    // 0x801D2ECC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D2ED0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2ED4: addiu       $t6, $t6, 0x1470
    ctx->r14 = ADD32(ctx->r14, 0X1470);
    // 0x801D2ED8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D2EDC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D2EE0: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D2EE4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D2EE8: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D2EEC: addiu       $t2, $t2, 0x1460
    ctx->r10 = ADD32(ctx->r10, 0X1460);
    // 0x801D2EF0: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D2EF4: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D2EF8: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D2EFC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D2F00: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D2F04: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D2F08: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D2F0C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D2F10: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D2F14: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D2F18: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D2F1C: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D2F20:
    // 0x801D2F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D2F24:
    // 0x801D2F24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D2F28: jr          $ra
    // 0x801D2F2C: nop

    return;
    // 0x801D2F2C: nop

;}
RECOMP_FUNC void M24_FUN_801d2f30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2F30: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2F34: lw          $v0, -0x4CC8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC8);
    // 0x801D2F38: jr          $ra
    // 0x801D2F3C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D2F3C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2f40(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2f40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2F40: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2F44: lw          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CC8);
    // 0x801D2F48: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2F4C: beq         $t6, $zero, L_801D2F5C
    if (ctx->r14 == 0) {
            // 0x801D2F50: nop

    LOOKUP_FUNC(0x801D2F5C)(rdram, ctx);
    return;
    }
    // 0x801D2F50: nop

    // 0x801D2F54: jr          $ra
    // 0x801D2F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D2F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2f5c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2f5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2F5C: lw          $t7, -0x4CCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CCC);
    // 0x801D2F60: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2F64: beq         $t7, $zero, L_801D2F74
    if (ctx->r15 == 0) {
            // 0x801D2F68: nop

    LOOKUP_FUNC(0x801D2F74)(rdram, ctx);
    return;
    }
    // 0x801D2F68: nop

    // 0x801D2F6C: jr          $ra
    // 0x801D2F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D2F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2f74(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2f74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2F74: lw          $v0, -0x4CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC4);
    // 0x801D2F78: jr          $ra
    // 0x801D2F7C: nop

    return;
    // 0x801D2F7C: nop

;}
RECOMP_FUNC void M24_FUN_801d2f80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2F80: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2F84: jr          $ra
    // 0x801D2F88: addiu       $v0, $v0, 0x1460
    ctx->r2 = ADD32(ctx->r2, 0X1460);
    return;
    // 0x801D2F88: addiu       $v0, $v0, 0x1460
    ctx->r2 = ADD32(ctx->r2, 0X1460);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2f8c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2f8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2F8C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D2F90: addiu       $v1, $v1, 0x1470
    ctx->r3 = ADD32(ctx->r3, 0X1470);
    // 0x801D2F94: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D2F98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D2F9C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D2FA0: beql        $a0, $t6, L_801D2FB4
    if (ctx->r4 == ctx->r14) {
        // 0x801D2FA4: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D2FB4;
    }
    goto skip_0;
    // 0x801D2FA4: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D2FA8: jr          $ra
    // 0x801D2FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D2FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D2FB0: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D2FB4:
    // 0x801D2FB4: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D2FB8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D2FBC: jr          $ra
    // 0x801D2FC0: nop

    return;
    // 0x801D2FC0: nop

;}
RECOMP_FUNC void M24_FUN_801d2fc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2FC4: nop

    // 0x801D2FC8: nop

    // 0x801D2FCC: nop

;}
RECOMP_FUNC void M24_FUN_801d2fd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2FD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2FD4: sw          $zero, -0x4CAC($at)
    MEM_W(-0X4CAC, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2fd8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2fd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2FD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2FDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2FE0: sw          $zero, -0x4CA8($at)
    MEM_W(-0X4CA8, ctx->r1) = 0;
    // 0x801D2FE4: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D2FE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D2FEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D2FF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2FF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D2FF8: addiu       $t7, $t7, 0x3024
    ctx->r15 = ADD32(ctx->r15, 0X3024);
    // 0x801D2FFC: sw          $t6, -0x4CA4($at)
    MEM_W(-0X4CA4, ctx->r1) = ctx->r14;
    // 0x801D3000: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D3004: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x801D3008: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D300C: jal         0x8013B570
    // 0x801D3010: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D3010: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D3014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D301C: jr          $ra
    // 0x801D3020: nop

    return;
    // 0x801D3020: nop

;}
RECOMP_FUNC void M24_FUN_801d3024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D3028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D302C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D3030: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D3034: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3038: beq         $t6, $zero, L_801D3054
    if (ctx->r14 == 0) {
        // 0x801D303C: nop
    
            goto L_801D3054;
    }
    // 0x801D303C: nop

    // 0x801D3040: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3044: jal         0x800058DC
    // 0x801D3048: addiu       $a1, $a1, 0x306C
    ctx->r5 = ADD32(ctx->r5, 0X306C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801D3048: addiu       $a1, $a1, 0x306C
    ctx->r5 = ADD32(ctx->r5, 0X306C);
    after_0:
    // 0x801D304C: b           L_801D3060
    // 0x801D3050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D3060;
    // 0x801D3050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D3054:
    // 0x801D3054: jal         0x800058DC
    // 0x801D3058: addiu       $a1, $a1, 0x3024
    ctx->r5 = ADD32(ctx->r5, 0X3024);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D3058: addiu       $a1, $a1, 0x3024
    ctx->r5 = ADD32(ctx->r5, 0X3024);
    after_1:
    // 0x801D305C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D3060:
    // 0x801D3060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D3064: jr          $ra
    // 0x801D3068: nop

    return;
    // 0x801D3068: nop

;}
RECOMP_FUNC void M24_FUN_801d306c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D306C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D3070: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D3074: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D3078: jal         0x801CC540
    // 0x801D307C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D307C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D3080: beq         $v0, $zero, L_801D30A0
    if (ctx->r2 == 0) {
        // 0x801D3084: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D30A0;
    }
    // 0x801D3084: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D3088: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D308C: addiu       $a1, $a1, 0x306C
    ctx->r5 = ADD32(ctx->r5, 0X306C);
    // 0x801D3090: jal         0x800058DC
    // 0x801D3094: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D3094: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D3098: b           L_801D3254
    // 0x801D309C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D3254;
    // 0x801D309C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D30A0:
    // 0x801D30A0: lw          $t6, -0x4CAC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CAC);
    // 0x801D30A4: beq         $t6, $zero, L_801D30FC
    if (ctx->r14 == 0) {
        // 0x801D30A8: nop
    
            goto L_801D30FC;
    }
    // 0x801D30A8: nop

    // 0x801D30AC: jal         0x80006214
    // 0x801D30B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D30B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D30B4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D30B8: lw          $t7, -0x4CAC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CAC);
    // 0x801D30BC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D30C0: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D30C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D30C8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D30CC: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D30D0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D30D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D30D8: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D30DC: jal         0x8013A28C
    // 0x801D30E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D30E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D30E4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D30E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D30EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D30F0: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D30F4: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D30F8: sw          $zero, -0x4CAC($at)
    MEM_W(-0X4CAC, ctx->r1) = 0;
L_801D30FC:
    // 0x801D30FC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3100: lw          $v0, -0x4CA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CA8);
    // 0x801D3104: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D3108: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D310C: beq         $v0, $zero, L_801D31D8
    if (ctx->r2 == 0) {
        // 0x801D3110: nop
    
            goto L_801D31D8;
    }
    // 0x801D3110: nop

    // 0x801D3114: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D3118: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D311C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D3120: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D3124: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D3128: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D312C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D3130: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D3134: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D3138: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D313C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D3140: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D3144: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D3148: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D314C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D3150: nop

    // 0x801D3154: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D3158: beql        $t4, $zero, L_801D31A8
    if (ctx->r12 == 0) {
        // 0x801D315C: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D31A8;
    }
    goto skip_0;
    // 0x801D315C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D3160: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D3164: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D3168: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D316C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D3170: nop

    // 0x801D3174: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D3178: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D317C: nop

    // 0x801D3180: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D3184: bne         $t4, $zero, L_801D319C
    if (ctx->r12 != 0) {
        // 0x801D3188: nop
    
            goto L_801D319C;
    }
    // 0x801D3188: nop

    // 0x801D318C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D3190: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D3194: b           L_801D31B4
    // 0x801D3198: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D31B4;
    // 0x801D3198: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D319C:
    // 0x801D319C: b           L_801D31B4
    // 0x801D31A0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D31B4;
    // 0x801D31A0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D31A4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D31A8:
    // 0x801D31A8: nop

    // 0x801D31AC: bltz        $t4, L_801D319C
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D31B0: nop
    
            goto L_801D319C;
    }
    // 0x801D31B0: nop

L_801D31B4:
    // 0x801D31B4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D31B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D31BC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D31C0: jal         0x80011140
    // 0x801D31C4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D31C4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D31C8: beq         $v0, $zero, L_801D3250
    if (ctx->r2 == 0) {
        // 0x801D31CC: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D3250;
    }
    // 0x801D31CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D31D0: b           L_801D3250
    // 0x801D31D4: sw          $zero, -0x4CA8($at)
    MEM_W(-0X4CA8, ctx->r1) = 0;
        goto L_801D3250;
    // 0x801D31D4: sw          $zero, -0x4CA8($at)
    MEM_W(-0X4CA8, ctx->r1) = 0;
L_801D31D8:
    // 0x801D31D8: jal         0x80010550
    // 0x801D31DC: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D31DC: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D31E0: beq         $v0, $zero, L_801D31F8
    if (ctx->r2 == 0) {
        // 0x801D31E4: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D31F8;
    }
    // 0x801D31E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D31E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D31EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D31F0: b           L_801D31FC
    // 0x801D31F4: sw          $t5, -0x4CA4($at)
    MEM_W(-0X4CA4, ctx->r1) = ctx->r13;
        goto L_801D31FC;
    // 0x801D31F4: sw          $t5, -0x4CA4($at)
    MEM_W(-0X4CA4, ctx->r1) = ctx->r13;
L_801D31F8:
    // 0x801D31F8: sw          $zero, -0x4CA4($at)
    MEM_W(-0X4CA4, ctx->r1) = 0;
L_801D31FC:
    // 0x801D31FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D3200: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D3204: addiu       $t6, $t6, 0x1490
    ctx->r14 = ADD32(ctx->r14, 0X1490);
    // 0x801D3208: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D320C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D3210: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D3214: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3218: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D321C: addiu       $t2, $t2, 0x1480
    ctx->r10 = ADD32(ctx->r10, 0X1480);
    // 0x801D3220: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D3224: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D3228: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D322C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D3230: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D3234: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D3238: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D323C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D3240: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D3244: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D3248: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D324C: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D3250:
    // 0x801D3250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D3254:
    // 0x801D3254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D3258: jr          $ra
    // 0x801D325C: nop

    return;
    // 0x801D325C: nop

;}
RECOMP_FUNC void M24_FUN_801d3260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3260: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3264: lw          $v0, -0x4CA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CA8);
    // 0x801D3268: jr          $ra
    // 0x801D326C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D326C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d3270(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d3270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3270: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D3274: lw          $t6, -0x4CA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CA8);
    // 0x801D3278: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D327C: beq         $t6, $zero, L_801D328C
    if (ctx->r14 == 0) {
            // 0x801D3280: nop

    LOOKUP_FUNC(0x801D328C)(rdram, ctx);
    return;
    }
    // 0x801D3280: nop

    // 0x801D3284: jr          $ra
    // 0x801D3288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D3288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d328c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d328c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D328C: lw          $t7, -0x4CAC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CAC);
    // 0x801D3290: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3294: beq         $t7, $zero, L_801D32A4
    if (ctx->r15 == 0) {
            // 0x801D3298: nop

    LOOKUP_FUNC(0x801D32A4)(rdram, ctx);
    return;
    }
    // 0x801D3298: nop

    // 0x801D329C: jr          $ra
    // 0x801D32A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D32A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d32a4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d32a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D32A4: lw          $v0, -0x4CA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CA4);
    // 0x801D32A8: jr          $ra
    // 0x801D32AC: nop

    return;
    // 0x801D32AC: nop

;}
RECOMP_FUNC void M24_FUN_801d32b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D32B0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D32B4: jr          $ra
    // 0x801D32B8: addiu       $v0, $v0, 0x1480
    ctx->r2 = ADD32(ctx->r2, 0X1480);
    return;
    // 0x801D32B8: addiu       $v0, $v0, 0x1480
    ctx->r2 = ADD32(ctx->r2, 0X1480);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d32bc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d32bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D32BC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D32C0: addiu       $v1, $v1, 0x1490
    ctx->r3 = ADD32(ctx->r3, 0X1490);
    // 0x801D32C4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D32C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D32CC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D32D0: beql        $a0, $t6, L_801D32E4
    if (ctx->r4 == ctx->r14) {
        // 0x801D32D4: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D32E4;
    }
    goto skip_0;
    // 0x801D32D4: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D32D8: jr          $ra
    // 0x801D32DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D32DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D32E0: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D32E4:
    // 0x801D32E4: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D32E8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D32EC: jr          $ra
    // 0x801D32F0: nop

    return;
    // 0x801D32F0: nop

;}
RECOMP_FUNC void M24_FUN_801d32f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D32F4: nop

    // 0x801D32F8: nop

    // 0x801D32FC: nop

;}
RECOMP_FUNC void M24_FUN_801d3300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3300: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3304: sw          $a0, 0x14A0($at)
    MEM_W(0X14A0, ctx->r1) = ctx->r4;
    // 0x801D3308: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D330C: sw          $zero, -0x4C8C($at)
    MEM_W(-0X4C8C, ctx->r1) = 0;
    // 0x801D3310: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3314: sw          $zero, -0x4C88($at)
    MEM_W(-0X4C88, ctx->r1) = 0;
    // 0x801D3318: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D331C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D3320: sw          $t6, -0x4C84($at)
    MEM_W(-0X4C84, ctx->r1) = ctx->r14;
    // 0x801D3324: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3328: sw          $zero, -0x4C7C($at)
    MEM_W(-0X4C7C, ctx->r1) = 0;
    // 0x801D332C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D3330: lw          $t7, -0x4C80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C80);
    // 0x801D3334: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3338: sw          $zero, -0x4C78($at)
    MEM_W(-0X4C78, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d333c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d333c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D333C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D3340: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3344: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D3348: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D334C: beq         $t7, $zero, L_801D3378
    if (ctx->r15 == 0) {
        // 0x801D3350: sw          $zero, -0x4C74($at)
        MEM_W(-0X4C74, ctx->r1) = 0;
            goto L_801D3378;
    }
    // 0x801D3350: sw          $zero, -0x4C74($at)
    MEM_W(-0X4C74, ctx->r1) = 0;
    // 0x801D3354: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801D3358: addiu       $t8, $t8, 0x33A4
    ctx->r24 = ADD32(ctx->r24, 0X33A4);
    // 0x801D335C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801D3360: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x801D3364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D3368: jal         0x8013B570
    // 0x801D336C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D336C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D3370: b           L_801D3398
    // 0x801D3374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D3398;
    // 0x801D3374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D3378:
    // 0x801D3378: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801D337C: addiu       $t9, $t9, 0x33A4
    ctx->r25 = ADD32(ctx->r25, 0X33A4);
    // 0x801D3380: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801D3384: addiu       $a1, $zero, 0x148
    ctx->r5 = ADD32(0, 0X148);
    // 0x801D3388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D338C: jal         0x8013B570
    // 0x801D3390: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_1;
    // 0x801D3390: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x801D3394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D3398:
    // 0x801D3398: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D339C: jr          $ra
    // 0x801D33A0: nop

    return;
    // 0x801D33A0: nop

;}
RECOMP_FUNC void M24_FUN_801d33a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D33A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D33A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D33AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D33B0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D33B4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D33B8: beq         $t6, $zero, L_801D33D4
    if (ctx->r14 == 0) {
        // 0x801D33BC: nop
    
            goto L_801D33D4;
    }
    // 0x801D33BC: nop

    // 0x801D33C0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D33C4: jal         0x800058DC
    // 0x801D33C8: addiu       $a1, $a1, 0x33EC
    ctx->r5 = ADD32(ctx->r5, 0X33EC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801D33C8: addiu       $a1, $a1, 0x33EC
    ctx->r5 = ADD32(ctx->r5, 0X33EC);
    after_0:
    // 0x801D33CC: b           L_801D33E0
    // 0x801D33D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D33E0;
    // 0x801D33D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D33D4:
    // 0x801D33D4: jal         0x800058DC
    // 0x801D33D8: addiu       $a1, $a1, 0x33A4
    ctx->r5 = ADD32(ctx->r5, 0X33A4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D33D8: addiu       $a1, $a1, 0x33A4
    ctx->r5 = ADD32(ctx->r5, 0X33A4);
    after_1:
    // 0x801D33DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D33E0:
    // 0x801D33E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D33E4: jr          $ra
    // 0x801D33E8: nop

    return;
    // 0x801D33E8: nop

;}
RECOMP_FUNC void M24_FUN_801d33ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D33EC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D33F0: lw          $t6, -0x4C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d33f4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d33f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D33F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D33F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D33FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D3400: bne         $t6, $zero, L_801D3610
    if (ctx->r14 != 0) {
        // 0x801D3404: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801D3610;
    }
    // 0x801D3404: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D3408: jal         0x801CC540
    // 0x801D340C: nop

    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D340C: nop

    after_0:
    // 0x801D3410: beq         $v0, $zero, L_801D3430
    if (ctx->r2 == 0) {
        // 0x801D3414: lui         $t7, 0x801E
        ctx->r15 = S32(0X801E << 16);
            goto L_801D3430;
    }
    // 0x801D3414: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D3418: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D341C: addiu       $a1, $a1, 0x33EC
    ctx->r5 = ADD32(ctx->r5, 0X33EC);
    // 0x801D3420: jal         0x800058DC
    // 0x801D3424: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D3424: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D3428: b           L_801D3614
    // 0x801D342C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D3614;
    // 0x801D342C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D3430:
    // 0x801D3430: lw          $t7, -0x4C8C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C8C);
    // 0x801D3434: beq         $t7, $zero, L_801D348C
    if (ctx->r15 == 0) {
        // 0x801D3438: nop
    
            goto L_801D348C;
    }
    // 0x801D3438: nop

    // 0x801D343C: jal         0x80006214
    // 0x801D3440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D3440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D3444: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D3448: lw          $t8, -0x4C8C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C8C);
    // 0x801D344C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D3450: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D3454: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801D3458: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801D345C: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801D3460: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D3464: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D3468: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801D346C: jal         0x8013A28C
    // 0x801D3470: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D3470: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D3474: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D3478: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801D347C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3480: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D3484: sb          $t1, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r9;
    // 0x801D3488: sw          $zero, -0x4C8C($at)
    MEM_W(-0X4C8C, ctx->r1) = 0;
L_801D348C:
    // 0x801D348C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3490: lw          $v0, -0x4C88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C88);
    // 0x801D3494: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D3498: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D349C: beq         $v0, $zero, L_801D3568
    if (ctx->r2 == 0) {
        // 0x801D34A0: nop
    
            goto L_801D3568;
    }
    // 0x801D34A0: nop

    // 0x801D34A4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801D34A8: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D34AC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D34B0: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x801D34B4: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x801D34B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D34BC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801D34C0: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x801D34C4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x801D34C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D34CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D34D0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801D34D4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D34D8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D34DC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801D34E0: nop

    // 0x801D34E4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801D34E8: beql        $t5, $zero, L_801D3538
    if (ctx->r13 == 0) {
        // 0x801D34EC: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_801D3538;
    }
    goto skip_0;
    // 0x801D34EC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D34F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D34F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D34F8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D34FC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801D3500: nop

    // 0x801D3504: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D3508: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801D350C: nop

    // 0x801D3510: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801D3514: bne         $t5, $zero, L_801D352C
    if (ctx->r13 != 0) {
        // 0x801D3518: nop
    
            goto L_801D352C;
    }
    // 0x801D3518: nop

    // 0x801D351C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x801D3520: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D3524: b           L_801D3544
    // 0x801D3528: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801D3544;
    // 0x801D3528: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801D352C:
    // 0x801D352C: b           L_801D3544
    // 0x801D3530: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801D3544;
    // 0x801D3530: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801D3534: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_801D3538:
    // 0x801D3538: nop

    // 0x801D353C: bltz        $t5, L_801D352C
    if (SIGNED(ctx->r13) < 0) {
        // 0x801D3540: nop
    
            goto L_801D352C;
    }
    // 0x801D3540: nop

L_801D3544:
    // 0x801D3544: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D3548: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801D354C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D3550: jal         0x80011140
    // 0x801D3554: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D3554: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D3558: beq         $v0, $zero, L_801D35E0
    if (ctx->r2 == 0) {
        // 0x801D355C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D35E0;
    }
    // 0x801D355C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3560: b           L_801D35E0
    // 0x801D3564: sw          $zero, -0x4C88($at)
    MEM_W(-0X4C88, ctx->r1) = 0;
        goto L_801D35E0;
    // 0x801D3564: sw          $zero, -0x4C88($at)
    MEM_W(-0X4C88, ctx->r1) = 0;
L_801D3568:
    // 0x801D3568: jal         0x80010550
    // 0x801D356C: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D356C: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D3570: beq         $v0, $zero, L_801D3588
    if (ctx->r2 == 0) {
        // 0x801D3574: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D3588;
    }
    // 0x801D3574: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3578: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D357C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3580: b           L_801D358C
    // 0x801D3584: sw          $t6, -0x4C84($at)
    MEM_W(-0X4C84, ctx->r1) = ctx->r14;
        goto L_801D358C;
    // 0x801D3584: sw          $t6, -0x4C84($at)
    MEM_W(-0X4C84, ctx->r1) = ctx->r14;
L_801D3588:
    // 0x801D3588: sw          $zero, -0x4C84($at)
    MEM_W(-0X4C84, ctx->r1) = 0;
L_801D358C:
    // 0x801D358C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801D3590: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D3594: addiu       $t7, $t7, 0x14B8
    ctx->r15 = ADD32(ctx->r15, 0X14B8);
    // 0x801D3598: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801D359C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801D35A0: addiu       $t4, $t4, -0x3FD8
    ctx->r12 = ADD32(ctx->r12, -0X3FD8);
    // 0x801D35A4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801D35A8: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801D35AC: addiu       $t3, $t3, 0x14A8
    ctx->r11 = ADD32(ctx->r11, 0X14A8);
    // 0x801D35B0: lw          $t2, 0x5C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X5C);
    // 0x801D35B4: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x801D35B8: lw          $t1, 0x60($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X60);
    // 0x801D35BC: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x801D35C0: lw          $t2, 0x64($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X64);
    // 0x801D35C4: sw          $t2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r10;
    // 0x801D35C8: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801D35CC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801D35D0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801D35D4: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801D35D8: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801D35DC: sw          $t6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r14;
L_801D35E0:
    // 0x801D35E0: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D35E4: lw          $t8, -0x4C7C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C7C);
    // 0x801D35E8: beq         $t8, $zero, L_801D35F8
    if (ctx->r24 == 0) {
        // 0x801D35EC: nop
    
            goto L_801D35F8;
    }
    // 0x801D35EC: nop

    // 0x801D35F0: jal         0x801D3FD8
    // 0x801D35F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D3FD8)(rdram, ctx);
        goto after_6;
    // 0x801D35F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_801D35F8:
    // 0x801D35F8: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801D35FC: lw          $t9, -0x4C74($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C74);
    // 0x801D3600: beql        $t9, $zero, L_801D3614
    if (ctx->r25 == 0) {
        // 0x801D3604: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D3614;
    }
    goto skip_1;
    // 0x801D3604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D3608: jal         0x801D4068
    // 0x801D360C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D4068)(rdram, ctx);
        goto after_7;
    // 0x801D360C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
L_801D3610:
    // 0x801D3610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D3614:
    // 0x801D3614: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D3618: jr          $ra
    // 0x801D361C: nop

    return;
    // 0x801D361C: nop

;}
