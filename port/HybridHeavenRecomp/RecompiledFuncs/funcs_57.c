#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801d72cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D72CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D72D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D72D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D72D8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D72DC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D72E0: beq         $t6, $zero, L_801D72FC
    if (ctx->r14 == 0) {
        // 0x801D72E4: nop
    
            goto L_801D72FC;
    }
    // 0x801D72E4: nop

    // 0x801D72E8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D72EC: jal         0x800058DC
    // 0x801D72F0: addiu       $a1, $a1, 0x7314
    ctx->r5 = ADD32(ctx->r5, 0X7314);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801D72F0: addiu       $a1, $a1, 0x7314
    ctx->r5 = ADD32(ctx->r5, 0X7314);
    after_0:
    // 0x801D72F4: b           L_801D7308
    // 0x801D72F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7308;
    // 0x801D72F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D72FC:
    // 0x801D72FC: jal         0x800058DC
    // 0x801D7300: addiu       $a1, $a1, 0x72CC
    ctx->r5 = ADD32(ctx->r5, 0X72CC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D7300: addiu       $a1, $a1, 0x72CC
    ctx->r5 = ADD32(ctx->r5, 0X72CC);
    after_1:
    // 0x801D7304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7308:
    // 0x801D7308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D730C: jr          $ra
    // 0x801D7310: nop

    return;
    // 0x801D7310: nop

;}
RECOMP_FUNC void M24_FUN_801d7314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7314: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D7318: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d731c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d731c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D731C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D7320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D7324: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D7328: bne         $t6, $zero, L_801D7520
    if (ctx->r14 != 0) {
        // 0x801D732C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801D7520;
    }
    // 0x801D732C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D7330: jal         0x801CC540
    // 0x801D7334: nop

    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D7334: nop

    after_0:
    // 0x801D7338: beq         $v0, $zero, L_801D7358
    if (ctx->r2 == 0) {
        // 0x801D733C: lui         $t7, 0x801E
        ctx->r15 = S32(0X801E << 16);
            goto L_801D7358;
    }
    // 0x801D733C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D7340: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D7344: addiu       $a1, $a1, 0x7314
    ctx->r5 = ADD32(ctx->r5, 0X7314);
    // 0x801D7348: jal         0x800058DC
    // 0x801D734C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D734C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D7350: b           L_801D7524
    // 0x801D7354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D7524;
    // 0x801D7354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D7358:
    // 0x801D7358: lw          $t7, -0x452C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X452C);
    // 0x801D735C: beq         $t7, $zero, L_801D73B4
    if (ctx->r15 == 0) {
        // 0x801D7360: nop
    
            goto L_801D73B4;
    }
    // 0x801D7360: nop

    // 0x801D7364: jal         0x80006214
    // 0x801D7368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D7368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D736C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D7370: lw          $t8, -0x452C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X452C);
    // 0x801D7374: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D7378: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D737C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801D7380: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801D7384: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801D7388: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D738C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D7390: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801D7394: jal         0x8013A2E0
    // 0x801D7398: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_3;
    // 0x801D7398: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D739C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D73A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801D73A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D73A8: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D73AC: sb          $t1, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r9;
    // 0x801D73B0: sw          $zero, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = 0;
L_801D73B4:
    // 0x801D73B4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D73B8: lw          $v0, -0x4528($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4528);
    // 0x801D73BC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D73C0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D73C4: beq         $v0, $zero, L_801D7490
    if (ctx->r2 == 0) {
        // 0x801D73C8: nop
    
            goto L_801D7490;
    }
    // 0x801D73C8: nop

    // 0x801D73CC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801D73D0: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D73D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D73D8: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x801D73DC: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x801D73E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D73E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801D73E8: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x801D73EC: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x801D73F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D73F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D73F8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801D73FC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D7400: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D7404: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801D7408: nop

    // 0x801D740C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801D7410: beql        $t5, $zero, L_801D7460
    if (ctx->r13 == 0) {
        // 0x801D7414: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_801D7460;
    }
    goto skip_0;
    // 0x801D7414: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D7418: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D741C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D7420: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D7424: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801D7428: nop

    // 0x801D742C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D7430: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801D7434: nop

    // 0x801D7438: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801D743C: bne         $t5, $zero, L_801D7454
    if (ctx->r13 != 0) {
        // 0x801D7440: nop
    
            goto L_801D7454;
    }
    // 0x801D7440: nop

    // 0x801D7444: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x801D7448: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D744C: b           L_801D746C
    // 0x801D7450: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801D746C;
    // 0x801D7450: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801D7454:
    // 0x801D7454: b           L_801D746C
    // 0x801D7458: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801D746C;
    // 0x801D7458: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801D745C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_801D7460:
    // 0x801D7460: nop

    // 0x801D7464: bltz        $t5, L_801D7454
    if (SIGNED(ctx->r13) < 0) {
        // 0x801D7468: nop
    
            goto L_801D7454;
    }
    // 0x801D7468: nop

L_801D746C:
    // 0x801D746C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D7470: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801D7474: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D7478: jal         0x80011140
    // 0x801D747C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D747C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D7480: beq         $v0, $zero, L_801D7508
    if (ctx->r2 == 0) {
        // 0x801D7484: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D7508;
    }
    // 0x801D7484: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7488: b           L_801D7508
    // 0x801D748C: sw          $zero, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = 0;
        goto L_801D7508;
    // 0x801D748C: sw          $zero, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = 0;
L_801D7490:
    // 0x801D7490: jal         0x80010550
    // 0x801D7494: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D7494: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D7498: beq         $v0, $zero, L_801D74B0
    if (ctx->r2 == 0) {
        // 0x801D749C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D74B0;
    }
    // 0x801D749C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D74A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D74A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D74A8: b           L_801D74B4
    // 0x801D74AC: sw          $t6, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->r14;
        goto L_801D74B4;
    // 0x801D74AC: sw          $t6, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->r14;
L_801D74B0:
    // 0x801D74B0: sw          $zero, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = 0;
L_801D74B4:
    // 0x801D74B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801D74B8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D74BC: addiu       $t7, $t7, 0x17C8
    ctx->r15 = ADD32(ctx->r15, 0X17C8);
    // 0x801D74C0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801D74C4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801D74C8: addiu       $t4, $t4, -0x3FD8
    ctx->r12 = ADD32(ctx->r12, -0X3FD8);
    // 0x801D74CC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801D74D0: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801D74D4: addiu       $t3, $t3, 0x17B8
    ctx->r11 = ADD32(ctx->r11, 0X17B8);
    // 0x801D74D8: lw          $t2, 0x5C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X5C);
    // 0x801D74DC: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x801D74E0: lw          $t1, 0x60($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X60);
    // 0x801D74E4: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x801D74E8: lw          $t2, 0x64($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X64);
    // 0x801D74EC: sw          $t2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r10;
    // 0x801D74F0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801D74F4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801D74F8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801D74FC: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801D7500: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801D7504: sw          $t6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r14;
L_801D7508:
    // 0x801D7508: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D750C: lw          $t8, -0x4520($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4520);
    // 0x801D7510: beql        $t8, $zero, L_801D7524
    if (ctx->r24 == 0) {
        // 0x801D7514: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D7524;
    }
    goto skip_1;
    // 0x801D7514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D7518: jal         0x801D83AC
    // 0x801D751C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D83AC)(rdram, ctx);
        goto after_6;
    // 0x801D751C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_801D7520:
    // 0x801D7520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D7524:
    // 0x801D7524: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D7528: jr          $ra
    // 0x801D752C: nop

    return;
    // 0x801D752C: nop

;}
RECOMP_FUNC void M24_FUN_801d7530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7530: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7534: lw          $v0, -0x4528($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4528);
    // 0x801D7538: jr          $ra
    // 0x801D753C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D753C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d7540(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d7540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7540: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D7544: lw          $t6, -0x4528($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4528);
    // 0x801D7548: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D754C: beq         $t6, $zero, L_801D755C
    if (ctx->r14 == 0) {
            // 0x801D7550: nop

    LOOKUP_FUNC(0x801D755C)(rdram, ctx);
    return;
    }
    // 0x801D7550: nop

    // 0x801D7554: jr          $ra
    // 0x801D7558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D7558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d755c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d755c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D755C: lw          $t7, -0x452C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X452C);
    // 0x801D7560: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7564: beq         $t7, $zero, L_801D7574
    if (ctx->r15 == 0) {
            // 0x801D7568: nop

    LOOKUP_FUNC(0x801D7574)(rdram, ctx);
    return;
    }
    // 0x801D7568: nop

    // 0x801D756C: jr          $ra
    // 0x801D7570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D7570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d7574(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d7574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7574: lw          $v0, -0x4524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4524);
    // 0x801D7578: jr          $ra
    // 0x801D757C: nop

    return;
    // 0x801D757C: nop

;}
RECOMP_FUNC void M24_FUN_801d7580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7580: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7584: jr          $ra
    // 0x801D7588: addiu       $v0, $v0, 0x17B8
    ctx->r2 = ADD32(ctx->r2, 0X17B8);
    return;
    // 0x801D7588: addiu       $v0, $v0, 0x17B8
    ctx->r2 = ADD32(ctx->r2, 0X17B8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d758c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d758c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D758C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7590: jr          $ra
    // 0x801D7594: sw          $a0, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->r4;
    return;
    // 0x801D7594: sw          $a0, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d7598(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d7598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7598: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D759C: jr          $ra
    // 0x801D75A0: sw          $a0, -0x4518($at)
    MEM_W(-0X4518, ctx->r1) = ctx->r4;
    return;
    // 0x801D75A0: sw          $a0, -0x4518($at)
    MEM_W(-0X4518, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d75a4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d75a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D75A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D75A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D75AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D75B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D75B4: beq         $a0, $zero, L_801D760C
    if (ctx->r4 == 0) {
        // 0x801D75B8: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801D760C;
    }
    // 0x801D75B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D75BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D75C0: jal         0x80006214
    // 0x801D75C4: lw          $a0, 0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17B0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D75C4: lw          $a0, 0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17B0);
    after_0:
    // 0x801D75C8: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801D75CC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801D75D0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801D75D4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D75D8: lw          $a0, 0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17B0);
    // 0x801D75DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D75E0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801D75E4: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801D75E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801D75EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D75F0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801D75F4: jal         0x801C3370
    // 0x801D75F8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801D75F8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_1:
    // 0x801D75FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D7600: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7604: b           L_801D7614
    // 0x801D7608: sw          $t9, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->r25;
        goto L_801D7614;
    // 0x801D7608: sw          $t9, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->r25;
L_801D760C:
    // 0x801D760C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7610: sw          $zero, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = 0;
L_801D7614:
    // 0x801D7614: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D7618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D761C: jr          $ra
    // 0x801D7620: nop

    return;
    // 0x801D7620: nop

;}
RECOMP_FUNC void M24_FUN_801d7624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7624: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7628: lw          $v0, -0x4520($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4520);
    // 0x801D762C: jr          $ra
    // 0x801D7630: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801D7630: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d7634(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d7634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7634: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D7638: addiu       $v1, $v1, 0x17C8
    ctx->r3 = ADD32(ctx->r3, 0X17C8);
    // 0x801D763C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D7640: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D7644: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D7648: beql        $a0, $t6, L_801D765C
    if (ctx->r4 == ctx->r14) {
        // 0x801D764C: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D765C;
    }
    goto skip_0;
    // 0x801D764C: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D7650: jr          $ra
    // 0x801D7654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D7654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D7658: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D765C:
    // 0x801D765C: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D7660: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D7664: jr          $ra
    // 0x801D7668: nop

    return;
    // 0x801D7668: nop

;}
RECOMP_FUNC void M24_FUN_801d766c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D766C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7670: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801D7674: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7678: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801D767C: addiu       $v0, $v0, 0x17D8
    ctx->r2 = ADD32(ctx->r2, 0X17D8);
    // 0x801D7680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7684: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x801D7688: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x801D768C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D7690: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801D7694: jal         0x80006214
    // 0x801D7698: lw          $a0, 0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17B0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D7698: lw          $a0, 0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17B0);
    after_0:
    // 0x801D769C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D76A0: lw          $t6, 0x17B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X17B0);
    // 0x801D76A4: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801D76A8: addiu       $t5, $t5, -0x6C48
    ctx->r13 = ADD32(ctx->r13, -0X6C48);
    // 0x801D76AC: lw          $t0, 0x5C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X5C);
    // 0x801D76B0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801D76B4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801D76B8: lhu         $a1, 0xC($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0XC);
    // 0x801D76BC: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x801D76C0: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801D76C4: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x801D76C8: bne         $at, $zero, L_801D7784
    if (ctx->r1 != 0) {
        // 0x801D76CC: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_801D7784;
    }
    // 0x801D76CC: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x801D76D0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801D76D4: addiu       $t1, $t1, -0x2578
    ctx->r9 = ADD32(ctx->r9, -0X2578);
    // 0x801D76D8: addiu       $t3, $t3, -0x6CA0
    ctx->r11 = ADD32(ctx->r11, -0X6CA0);
    // 0x801D76DC: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
    // 0x801D76E0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
L_801D76E4:
    // 0x801D76E4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801D76E8: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
    // 0x801D76EC: bgezl       $t7, L_801D7700
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D76F0: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801D7700;
    }
    goto skip_0;
    // 0x801D76F0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801D76F4: b           L_801D7774
    // 0x801D76F8: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
        goto L_801D7774;
    // 0x801D76F8: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801D76FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801D7700:
    // 0x801D7700: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801D7704: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801D7708: ori         $t6, $t9, 0x100
    ctx->r14 = ctx->r25 | 0X100;
    // 0x801D770C: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x801D7710: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D7714: or          $t6, $t3, $a3
    ctx->r14 = ctx->r11 | ctx->r7;
    // 0x801D7718: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801D771C: or          $t7, $t5, $a3
    ctx->r15 = ctx->r13 | ctx->r7;
    // 0x801D7720: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x801D7724: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801D7728: bnel        $t2, $t9, L_801D773C
    if (ctx->r10 != ctx->r25) {
        // 0x801D772C: sw          $t7, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->r15;
            goto L_801D773C;
    }
    goto skip_1;
    // 0x801D772C: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
    skip_1:
    // 0x801D7730: b           L_801D773C
    // 0x801D7734: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
        goto L_801D773C;
    // 0x801D7734: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x801D7738: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
L_801D773C:
    // 0x801D773C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D7740: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D7744: sb          $zero, 0x48($t9)
    MEM_B(0X48, ctx->r25) = 0;
    // 0x801D7748: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D774C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D7750: sb          $zero, 0x49($t7)
    MEM_B(0X49, ctx->r15) = 0;
    // 0x801D7754: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D7758: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D775C: sb          $zero, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = 0;
    // 0x801D7760: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D7764: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D7768: sb          $t4, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r12;
    // 0x801D776C: lhu         $a1, 0xC($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0XC);
    // 0x801D7770: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_801D7774:
    // 0x801D7774: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801D7778: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D777C: bne         $at, $zero, L_801D76E4
    if (ctx->r1 != 0) {
        // 0x801D7780: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_801D76E4;
    }
    // 0x801D7780: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_801D7784:
    // 0x801D7784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7788: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D778C: sw          $zero, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = 0;
    // 0x801D7790: jr          $ra
    // 0x801D7794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D7794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d7798(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d7798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7798: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x801D779C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801D77A0: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801D77A4: addiu       $s1, $s1, -0x4510
    ctx->r17 = ADD32(ctx->r17, -0X4510);
    // 0x801D77A8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801D77AC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801D77B0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801D77B4: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x801D77B8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801D77BC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801D77C0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801D77C4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801D77C8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801D77CC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801D77D0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801D77D4: beq         $at, $zero, L_801D8280
    if (ctx->r1 == 0) {
        // 0x801D77D8: sdc1        $f20, 0x30($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
            goto L_801D8280;
    }
    // 0x801D77D8: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801D77DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801D77E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D77E4: addu        $at, $at, $t6
    gpr jr_addend_801D77EC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801D77E8: lw          $t6, -0x29C0($at)
    ctx->r14 = ADD32(ctx->r1, -0X29C0);
    // 0x801D77EC: jr          $t6
    // 0x801D77F0: nop

    switch (jr_addend_801D77EC >> 2) {
        case 0: goto L_801D77F4; break;
        case 1: goto L_801D7964; break;
        case 2: goto L_801D7C04; break;
        case 3: goto L_801D7DE8; break;
        case 4: goto L_801D7F34; break;
        case 5: goto L_801D8090; break;
        case 6: goto L_801D8278; break;
        default: switch_error(__func__, 0x801D77EC, 0x801DD640);
    }
    // 0x801D77F0: nop

L_801D77F4:
    // 0x801D77F4: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D77F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D77FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7800: addiu       $s0, $s0, 0x17B0
    ctx->r16 = ADD32(ctx->r16, 0X17B0);
    // 0x801D7804: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801D7808: jal         0x80006214
    // 0x801D780C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D780C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x801D7810: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801D7814: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D7818: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801D781C: lw          $a3, 0x5C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X5C);
    // 0x801D7820: addiu       $t5, $t5, -0x6C48
    ctx->r13 = ADD32(ctx->r13, -0X6C48);
    // 0x801D7824: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D7828: lhu         $a1, 0xC($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0XC);
    // 0x801D782C: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x801D7830: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801D7834: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x801D7838: bne         $at, $zero, L_801D78F8
    if (ctx->r1 != 0) {
        // 0x801D783C: addiu       $a2, $v1, 0x4
        ctx->r6 = ADD32(ctx->r3, 0X4);
            goto L_801D78F8;
    }
    // 0x801D783C: addiu       $a2, $v1, 0x4
    ctx->r6 = ADD32(ctx->r3, 0X4);
    // 0x801D7840: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801D7844: addiu       $t4, $t4, -0x6CA0
    ctx->r12 = ADD32(ctx->r12, -0X6CA0);
    // 0x801D7848: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x801D784C: lui         $t1, 0x4000
    ctx->r9 = S32(0X4000 << 16);
    // 0x801D7850: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_801D7854:
    // 0x801D7854: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x801D7858: addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // 0x801D785C: bgezl       $t8, L_801D7870
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801D7860: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_801D7870;
    }
    goto skip_0;
    // 0x801D7860: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801D7864: b           L_801D78E4
    // 0x801D7868: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
        goto L_801D78E4;
    // 0x801D7868: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801D786C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_801D7870:
    // 0x801D7870: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801D7874: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x801D7878: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x801D787C: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x801D7880: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D7884: or          $t7, $t4, $t1
    ctx->r15 = ctx->r12 | ctx->r9;
    // 0x801D7888: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801D788C: or          $t8, $t5, $t1
    ctx->r24 = ctx->r13 | ctx->r9;
    // 0x801D7890: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801D7894: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x801D7898: bnel        $t3, $t6, L_801D78AC
    if (ctx->r11 != ctx->r14) {
        // 0x801D789C: sw          $t8, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->r24;
            goto L_801D78AC;
    }
    goto skip_1;
    // 0x801D789C: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
    skip_1:
    // 0x801D78A0: b           L_801D78AC
    // 0x801D78A4: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
        goto L_801D78AC;
    // 0x801D78A4: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
    // 0x801D78A8: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
L_801D78AC:
    // 0x801D78AC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D78B0: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D78B4: sb          $t0, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r8;
    // 0x801D78B8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D78BC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D78C0: sb          $t0, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r8;
    // 0x801D78C4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D78C8: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D78CC: sb          $t0, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r8;
    // 0x801D78D0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D78D4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D78D8: sb          $zero, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = 0;
    // 0x801D78DC: lhu         $a1, 0xC($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0XC);
    // 0x801D78E0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_801D78E4:
    // 0x801D78E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801D78E8: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D78EC: bne         $at, $zero, L_801D7854
    if (ctx->r1 != 0) {
        // 0x801D78F0: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_801D7854;
    }
    // 0x801D78F0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801D78F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801D78F8:
    // 0x801D78F8: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x801D78FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D7900: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x801D7904: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D7908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D790C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D7910: swc1        $f20, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f20.u32l;
    // 0x801D7914: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D7918: addiu       $v1, $v1, -0x4510
    ctx->r3 = ADD32(ctx->r3, -0X4510);
    // 0x801D791C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7920: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801D7924: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D7928: swc1        $f20, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f20.u32l;
    // 0x801D792C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801D7930: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x801D7934: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801D7938: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D793C: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x801D7940: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801D7944: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801D7948: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D794C: sh          $t9, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r25;
    // 0x801D7950: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D7954: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801D7958: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801D795C: b           L_801D8280
    // 0x801D7960: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
        goto L_801D8280;
    // 0x801D7960: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
L_801D7964:
    // 0x801D7964: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D7968: addiu       $s0, $s0, 0x17B0
    ctx->r16 = ADD32(ctx->r16, 0X17B0);
    // 0x801D796C: jal         0x80006214
    // 0x801D7970: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801D7970: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x801D7974: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D7978: lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // 0x801D797C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D7980: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D7984: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D7988: addiu       $s4, $s4, 0x17D8
    ctx->r20 = ADD32(ctx->r20, 0X17D8);
    // 0x801D798C: addiu       $s0, $s0, -0x450C
    ctx->r16 = ADD32(ctx->r16, -0X450C);
    // 0x801D7990: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x801D7994: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x801D7998: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
L_801D799C:
    // 0x801D799C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D79A0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D79A4: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D79A8: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x801D79AC: beql        $v0, $zero, L_801D7BCC
    if (ctx->r2 == 0) {
        // 0x801D79B0: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_801D7BCC;
    }
    goto skip_2;
    // 0x801D79B0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_2:
    // 0x801D79B4: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x801D79B8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D79BC: addiu       $t7, $t7, 0x1A28
    ctx->r15 = ADD32(ctx->r15, 0X1A28);
    // 0x801D79C0: beq         $a1, $zero, L_801D7BC8
    if (ctx->r5 == 0) {
        // 0x801D79C4: addiu       $a0, $sp, 0xCC
        ctx->r4 = ADD32(ctx->r29, 0XCC);
            goto L_801D7BC8;
    }
    // 0x801D79C4: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x801D79C8: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x801D79CC: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x801D79D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x801D79D4: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801D79D8: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D79DC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D79E0: addiu       $t6, $t6, 0x1A90
    ctx->r14 = ADD32(ctx->r14, 0X1A90);
    // 0x801D79E4: addiu       $t8, $t8, 0x1908
    ctx->r24 = ADD32(ctx->r24, 0X1908);
    // 0x801D79E8: addiu       $t9, $t9, 0x17E8
    ctx->r25 = ADD32(ctx->r25, 0X17E8);
    // 0x801D79EC: addu        $s2, $v0, $t9
    ctx->r18 = ADD32(ctx->r2, ctx->r25);
    // 0x801D79F0: addu        $s3, $v0, $t8
    ctx->r19 = ADD32(ctx->r2, ctx->r24);
    // 0x801D79F4: addu        $fp, $v0, $t6
    ctx->r30 = ADD32(ctx->r2, ctx->r14);
    // 0x801D79F8: jal         0x80029EE8
    // 0x801D79FC: addu        $s7, $s6, $t7
    ctx->r23 = ADD32(ctx->r22, ctx->r15);
    LOOKUP_FUNC(0x80029EE8)(rdram, ctx);
        goto after_2;
    // 0x801D79FC: addu        $s7, $s6, $t7
    ctx->r23 = ADD32(ctx->r22, ctx->r15);
    after_2:
    // 0x801D7A00: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D7A04: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x801D7A08: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x801D7A0C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801D7A10: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x801D7A14: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x801D7A18: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    // 0x801D7A1C: addiu       $a3, $sp, 0xB2
    ctx->r7 = ADD32(ctx->r29, 0XB2);
    // 0x801D7A20: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x801D7A24: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801D7A28: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x801D7A2C: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x801D7A30: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801D7A34: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x801D7A38: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x801D7A3C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801D7A40: lwc1        $f16, 0xFC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x801D7A44: lwc1        $f18, 0x100($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X100);
    // 0x801D7A48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D7A4C: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x801D7A50: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x801D7A54: addiu       $t9, $sp, 0xB0
    ctx->r25 = ADD32(ctx->r29, 0XB0);
    // 0x801D7A58: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x801D7A5C: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x801D7A60: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801D7A64: addiu       $t8, $sp, 0xAE
    ctx->r24 = ADD32(ctx->r29, 0XAE);
    // 0x801D7A68: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x801D7A6C: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x801D7A70: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801D7A74: addiu       $t6, $sp, 0xBC
    ctx->r14 = ADD32(ctx->r29, 0XBC);
    // 0x801D7A78: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    // 0x801D7A7C: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x801D7A80: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801D7A84: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801D7A88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801D7A8C: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x801D7A90: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
    // 0x801D7A94: addiu       $t7, $sp, 0xB8
    ctx->r15 = ADD32(ctx->r29, 0XB8);
    // 0x801D7A98: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801D7A9C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x801D7AA0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801D7AA4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801D7AA8: swc1        $f16, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f16.u32l;
    // 0x801D7AAC: swc1        $f18, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f18.u32l;
    // 0x801D7AB0: swc1        $f4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f4.u32l;
    // 0x801D7AB4: jal         0x801D83DC
    // 0x801D7AB8: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801D83DC)(rdram, ctx);
        goto after_3;
    // 0x801D7AB8: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
    after_3:
    // 0x801D7ABC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D7AC0: lhu         $t6, 0xB2($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XB2);
    // 0x801D7AC4: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x801D7AC8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801D7ACC: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x801D7AD0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x801D7AD4: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x801D7AD8: sh          $t6, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r14;
    // 0x801D7ADC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D7AE0: lhu         $t8, 0xB0($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XB0);
    // 0x801D7AE4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x801D7AE8: addu        $t9, $s1, $t6
    ctx->r25 = ADD32(ctx->r17, ctx->r14);
    // 0x801D7AEC: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x801D7AF0: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D7AF4: sh          $t8, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r24;
    // 0x801D7AF8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D7AFC: lhu         $t9, 0xAE($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XAE);
    // 0x801D7B00: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801D7B04: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D7B08: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D7B0C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D7B10: sh          $t9, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r25;
    // 0x801D7B14: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x801D7B18: lw          $t6, 0x4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X4);
    // 0x801D7B1C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D7B20: sw          $t7, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r15;
    // 0x801D7B24: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
    // 0x801D7B28: sw          $t6, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r14;
    // 0x801D7B2C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D7B30: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D7B34: sw          $t7, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r15;
    // 0x801D7B38: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D7B3C: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x801D7B40: swc1        $f20, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f20.u32l;
    // 0x801D7B44: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801D7B48: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801D7B4C: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D7B50: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D7B54: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801D7B58: swc1        $f20, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f20.u32l;
    // 0x801D7B5C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801D7B60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D7B64: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x801D7B68: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x801D7B6C: lw          $t6, 0x2C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X2C);
    // 0x801D7B70: swc1        $f20, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f20.u32l;
    // 0x801D7B74: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D7B78: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x801D7B7C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801D7B80: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x801D7B84: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801D7B88: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D7B8C: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801D7B90: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D7B94: lwc1        $f8, 0x4($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X4);
    // 0x801D7B98: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D7B9C: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D7BA0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D7BA4: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x801D7BA8: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
    // 0x801D7BAC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801D7BB0: lwc1        $f10, 0x8($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X8);
    // 0x801D7BB4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801D7BB8: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D7BBC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D7BC0: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801D7BC4: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
L_801D7BC8:
    // 0x801D7BC8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_801D7BCC:
    // 0x801D7BCC: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x801D7BD0: bne         $s5, $t0, L_801D799C
    if (ctx->r21 != ctx->r8) {
        // 0x801D7BD4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_801D799C;
    }
    // 0x801D7BD4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801D7BD8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7BDC: addiu       $v0, $v0, -0x4510
    ctx->r2 = ADD32(ctx->r2, -0X4510);
    // 0x801D7BE0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D7BE4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801D7BE8: addiu       $a1, $a1, -0x44AC
    ctx->r5 = ADD32(ctx->r5, -0X44AC);
    // 0x801D7BEC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801D7BF0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801D7BF4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801D7BF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7BFC: b           L_801D8280
    // 0x801D7C00: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
        goto L_801D8280;
    // 0x801D7C00: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
L_801D7C04:
    // 0x801D7C04: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D7C08: addiu       $s0, $s0, 0x17B0
    ctx->r16 = ADD32(ctx->r16, 0X17B0);
    // 0x801D7C0C: jal         0x80006214
    // 0x801D7C10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x801D7C10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x801D7C14: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801D7C18: addiu       $a1, $a1, -0x44AC
    ctx->r5 = ADD32(ctx->r5, -0X44AC);
    // 0x801D7C1C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801D7C20: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D7C24: addiu       $t6, $t6, -0x2A10
    ctx->r14 = ADD32(ctx->r14, -0X2A10);
    // 0x801D7C28: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x801D7C2C: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801D7C30: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
    // 0x801D7C34: lw          $ra, 0x1A88($ra)
    ctx->r31 = MEM_W(ctx->r31, 0X1A88);
    // 0x801D7C38: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D7C3C: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801D7C40: mtc1        $ra, $f16
    ctx->f16.u32l = ctx->r31;
    // 0x801D7C44: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801D7C48: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801D7C4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D7C50: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7C54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7C58: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D7C5C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D7C60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D7C64: addiu       $a0, $a0, -0x44AC
    ctx->r4 = ADD32(ctx->r4, -0X44AC);
    // 0x801D7C68: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D7C6C: addiu       $v0, $v0, -0x450C
    ctx->r2 = ADD32(ctx->r2, -0X450C);
    // 0x801D7C70: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801D7C74: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801D7C78: div.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801D7C7C: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801D7C80: lwc1        $f12, -0x29A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x801D7C84: add.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801D7C88: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_801D7C8C:
    // 0x801D7C8C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D7C90: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D7C94: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x801D7C98: beql        $v1, $zero, L_801D7D04
    if (ctx->r3 == 0) {
        // 0x801D7C9C: lw          $t9, 0x4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X4);
            goto L_801D7D04;
    }
    goto skip_3;
    // 0x801D7C9C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    skip_3:
    // 0x801D7CA0: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x801D7CA4: beql        $t7, $zero, L_801D7D04
    if (ctx->r15 == 0) {
        // 0x801D7CA8: lw          $t9, 0x4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X4);
            goto L_801D7D04;
    }
    goto skip_4;
    // 0x801D7CA8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    skip_4:
    // 0x801D7CAC: mul.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x801D7CB0: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x801D7CB4: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x801D7CB8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D7CBC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801D7CC0: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D7CC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D7CC8: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801D7CCC: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x801D7CD0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D7CD4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D7CD8: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x801D7CDC: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x801D7CE0: lw          $t6, 0x2C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X2C);
    // 0x801D7CE4: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x801D7CE8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D7CEC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801D7CF0: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x801D7CF4: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801D7CF8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D7CFC: sb          $t0, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r8;
    // 0x801D7D00: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
L_801D7D04:
    // 0x801D7D04: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D7D08: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D7D0C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x801D7D10: beql        $v1, $zero, L_801D7D7C
    if (ctx->r3 == 0) {
        // 0x801D7D14: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_801D7D7C;
    }
    goto skip_5;
    // 0x801D7D14: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_5:
    // 0x801D7D18: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x801D7D1C: beql        $t7, $zero, L_801D7D7C
    if (ctx->r15 == 0) {
        // 0x801D7D20: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_801D7D7C;
    }
    goto skip_6;
    // 0x801D7D20: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_6:
    // 0x801D7D24: mul.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x801D7D28: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x801D7D2C: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x801D7D30: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x801D7D34: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801D7D38: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D7D3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D7D40: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801D7D44: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x801D7D48: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x801D7D4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D7D50: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x801D7D54: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x801D7D58: lw          $t6, 0x2C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X2C);
    // 0x801D7D5C: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x801D7D60: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x801D7D64: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801D7D68: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x801D7D6C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801D7D70: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D7D74: sb          $t0, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r8;
    // 0x801D7D78: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_801D7D7C:
    // 0x801D7D7C: bnel        $v0, $a0, L_801D7C8C
    if (ctx->r2 != ctx->r4) {
        // 0x801D7D80: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_801D7C8C;
    }
    goto skip_7;
    // 0x801D7D80: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_7:
    // 0x801D7D84: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801D7D88: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D7D8C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x801D7D90: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x801D7D94: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x801D7D98: lw          $v1, -0x2A10($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2A10);
    // 0x801D7D9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7DA0: sw          $ra, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = ctx->r31;
    // 0x801D7DA4: slt         $at, $v1, $ra
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x801D7DA8: beq         $at, $zero, L_801D7DC0
    if (ctx->r1 == 0) {
        // 0x801D7DAC: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_801D7DC0;
    }
    // 0x801D7DAC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x801D7DB0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801D7DB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7DB8: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
    // 0x801D7DBC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_801D7DC0:
    // 0x801D7DC0: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801D7DC4: bne         $at, $zero, L_801D8280
    if (ctx->r1 != 0) {
        // 0x801D7DC8: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801D8280;
    }
    // 0x801D7DC8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7DCC: addiu       $v0, $v0, -0x4510
    ctx->r2 = ADD32(ctx->r2, -0X4510);
    // 0x801D7DD0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D7DD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7DD8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801D7DDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801D7DE0: b           L_801D8280
    // 0x801D7DE4: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
        goto L_801D8280;
    // 0x801D7DE4: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
L_801D7DE8:
    // 0x801D7DE8: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801D7DEC: lw          $ra, 0x1A88($ra)
    ctx->r31 = MEM_W(ctx->r31, 0X1A88);
    // 0x801D7DF0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801D7DF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D7DF8: mtc1        $ra, $f4
    ctx->f4.u32l = ctx->r31;
    // 0x801D7DFC: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D7E00: addiu       $s0, $s0, 0x17B0
    ctx->r16 = ADD32(ctx->r16, 0X17B0);
    // 0x801D7E04: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D7E08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801D7E0C: div.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801D7E10: jal         0x80006214
    // 0x801D7E14: swc1        $f14, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801D7E14: swc1        $f14, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x801D7E18: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D7E1C: lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // 0x801D7E20: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D7E24: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D7E28: lwc1        $f14, 0x98($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801D7E2C: addiu       $a2, $a2, 0x1908
    ctx->r6 = ADD32(ctx->r6, 0X1908);
    // 0x801D7E30: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D7E34: addiu       $s4, $s4, 0x17D8
    ctx->r20 = ADD32(ctx->r20, 0X17D8);
    // 0x801D7E38: addiu       $v1, $v1, -0x450C
    ctx->r3 = ADD32(ctx->r3, -0X450C);
    // 0x801D7E3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801D7E40: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x801D7E44: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_801D7E48:
    // 0x801D7E48: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801D7E4C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D7E50: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D7E54: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x801D7E58: beql        $a1, $zero, L_801D7EF0
    if (ctx->r5 == 0) {
        // 0x801D7E5C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801D7EF0;
    }
    goto skip_8;
    // 0x801D7E5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_8:
    // 0x801D7E60: lw          $t7, 0x1C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1C);
    // 0x801D7E64: beql        $t7, $zero, L_801D7EF0
    if (ctx->r15 == 0) {
        // 0x801D7E68: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801D7EF0;
    }
    goto skip_9;
    // 0x801D7E68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_9:
    // 0x801D7E6C: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D7E70: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x801D7E74: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
    // 0x801D7E78: mflo        $t9
    ctx->r25 = lo;
    // 0x801D7E7C: addu        $v0, $a2, $t9
    ctx->r2 = ADD32(ctx->r6, ctx->r25);
    // 0x801D7E80: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D7E84: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801D7E88: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x801D7E8C: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801D7E90: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801D7E94: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D7E98: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x801D7E9C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D7EA0: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x801D7EA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D7EA8: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x801D7EAC: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x801D7EB0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x801D7EB4: lw          $t6, 0x2C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X2C);
    // 0x801D7EB8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x801D7EBC: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x801D7EC0: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D7EC4: lwc1        $f12, 0x8($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X8);
    // 0x801D7EC8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D7ECC: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x801D7ED0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801D7ED4: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x801D7ED8: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801D7EDC: mul.s       $f18, $f4, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x801D7EE0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D7EE4: add.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x801D7EE8: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x801D7EEC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_801D7EF0:
    // 0x801D7EF0: bne         $a0, $t0, L_801D7E48
    if (ctx->r4 != ctx->r8) {
        // 0x801D7EF4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801D7E48;
    }
    // 0x801D7EF4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801D7EF8: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801D7EFC: lw          $ra, 0x1A88($ra)
    ctx->r31 = MEM_W(ctx->r31, 0X1A88);
    // 0x801D7F00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7F04: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x801D7F08: sw          $ra, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = ctx->r31;
    // 0x801D7F0C: slti        $at, $ra, 0x100
    ctx->r1 = SIGNED(ctx->r31) < 0X100 ? 1 : 0;
    // 0x801D7F10: bne         $at, $zero, L_801D8280
    if (ctx->r1 != 0) {
        // 0x801D7F14: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801D8280;
    }
    // 0x801D7F14: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7F18: addiu       $v0, $v0, -0x4510
    ctx->r2 = ADD32(ctx->r2, -0X4510);
    // 0x801D7F1C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D7F20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7F24: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x801D7F28: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801D7F2C: b           L_801D8280
    // 0x801D7F30: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
        goto L_801D8280;
    // 0x801D7F30: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
L_801D7F34:
    // 0x801D7F34: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D7F38: addiu       $s0, $s0, 0x17B0
    ctx->r16 = ADD32(ctx->r16, 0X17B0);
    // 0x801D7F3C: jal         0x80006214
    // 0x801D7F40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x801D7F40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x801D7F44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D7F48: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7F4C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D7F50: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D7F54: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D7F58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801D7F5C: addiu       $t1, $t1, 0x17E8
    ctx->r9 = ADD32(ctx->r9, 0X17E8);
    // 0x801D7F60: addiu       $t2, $t2, 0x1A28
    ctx->r10 = ADD32(ctx->r10, 0X1A28);
    // 0x801D7F64: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D7F68: addiu       $v0, $v0, -0x450C
    ctx->r2 = ADD32(ctx->r2, -0X450C);
    // 0x801D7F6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801D7F70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D7F74: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x801D7F78: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_801D7F7C:
    // 0x801D7F7C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D7F80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D7F84: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x801D7F88: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x801D7F8C: beql        $a1, $zero, L_801D805C
    if (ctx->r5 == 0) {
        // 0x801D7F90: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801D805C;
    }
    goto skip_10;
    // 0x801D7F90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_10:
    // 0x801D7F94: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    // 0x801D7F98: beql        $t8, $zero, L_801D805C
    if (ctx->r24 == 0) {
        // 0x801D7F9C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801D805C;
    }
    goto skip_11;
    // 0x801D7F9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_11:
    // 0x801D7FA0: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D7FA4: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
    // 0x801D7FA8: mflo        $t6
    ctx->r14 = lo;
    // 0x801D7FAC: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x801D7FB0: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D7FB4: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
    // 0x801D7FB8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D7FBC: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801D7FC0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D7FC4: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D7FC8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D7FCC: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x801D7FD0: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    // 0x801D7FD4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D7FD8: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D7FDC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801D7FE0: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D7FE4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D7FE8: addu        $t6, $t2, $a2
    ctx->r14 = ADD32(ctx->r10, ctx->r6);
    // 0x801D7FEC: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801D7FF0: swc1        $f16, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f16.u32l;
    // 0x801D7FF4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D7FF8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D7FFC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D8000: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D8004: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x801D8008: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801D800C: sw          $t7, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r15;
    // 0x801D8010: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D8014: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x801D8018: addu        $t7, $s1, $t9
    ctx->r15 = ADD32(ctx->r17, ctx->r25);
    // 0x801D801C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D8020: lw          $t6, 0x2C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X2C);
    // 0x801D8024: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x801D8028: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D802C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x801D8030: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801D8034: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801D8038: lw          $t9, 0x2C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X2C);
    // 0x801D803C: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x801D8040: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D8044: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801D8048: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D804C: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x801D8050: lw          $t7, 0x2C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X2C);
    // 0x801D8054: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801D8058: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_801D805C:
    // 0x801D805C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801D8060: bne         $a0, $t0, L_801D7F7C
    if (ctx->r4 != ctx->r8) {
        // 0x801D8064: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_801D7F7C;
    }
    // 0x801D8064: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801D8068: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D806C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8070: addiu       $v0, $v0, -0x4510
    ctx->r2 = ADD32(ctx->r2, -0X4510);
    // 0x801D8074: sw          $zero, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = 0;
    // 0x801D8078: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D807C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8080: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x801D8084: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801D8088: b           L_801D8280
    // 0x801D808C: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
        goto L_801D8280;
    // 0x801D808C: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
L_801D8090:
    // 0x801D8090: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D8094: addiu       $s0, $s0, 0x17B0
    ctx->r16 = ADD32(ctx->r16, 0X17B0);
    // 0x801D8098: jal         0x80006214
    // 0x801D809C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_7;
    // 0x801D809C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x801D80A0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D80A4: lw          $t2, 0x5C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X5C);
    // 0x801D80A8: lhu         $a2, 0xC($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0XC);
    // 0x801D80AC: lw          $v0, 0x4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X4);
    // 0x801D80B0: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x801D80B4: bne         $at, $zero, L_801D8248
    if (ctx->r1 != 0) {
        // 0x801D80B8: nop
    
            goto L_801D8248;
    }
    // 0x801D80B8: nop

    // 0x801D80BC: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D80C0: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801D80C4: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801D80C8: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801D80CC: addiu       $t4, $t4, -0x6CA0
    ctx->r12 = ADD32(ctx->r12, -0X6CA0);
    // 0x801D80D0: addiu       $t5, $t5, -0x6C48
    ctx->r13 = ADD32(ctx->r13, -0X6C48);
    // 0x801D80D4: lw          $ra, 0x1A88($ra)
    ctx->r31 = MEM_W(ctx->r31, 0X1A88);
    // 0x801D80D8: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D80DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801D80E0: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x801D80E4: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x801D80E8: lui         $t1, 0x4000
    ctx->r9 = S32(0X4000 << 16);
    // 0x801D80EC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_801D80F0:
    // 0x801D80F0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x801D80F4: bgezl       $t7, L_801D8108
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D80F8: mtc1        $ra, $f4
        ctx->f4.u32l = ctx->r31;
            goto L_801D8108;
    }
    goto skip_12;
    // 0x801D80F8: mtc1        $ra, $f4
    ctx->f4.u32l = ctx->r31;
    skip_12:
    // 0x801D80FC: b           L_801D8230
    // 0x801D8100: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
        goto L_801D8230;
    // 0x801D8100: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x801D8104: mtc1        $ra, $f4
    ctx->f4.u32l = ctx->r31;
L_801D8108:
    // 0x801D8108: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801D810C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D8110: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D8114: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x801D8118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D811C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801D8120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D8124: addu        $v0, $s1, $a1
    ctx->r2 = ADD32(ctx->r17, ctx->r5);
    // 0x801D8128: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801D812C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D8130: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D8134: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D8138: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801D813C: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x801D8140: ori         $t9, $t6, 0x100
    ctx->r25 = ctx->r14 | 0X100;
    // 0x801D8144: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x801D8148: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D814C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801D8150: or          $t7, $t4, $t1
    ctx->r15 = ctx->r12 | ctx->r9;
    // 0x801D8154: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801D8158: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801D815C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801D8160: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801D8164: nop

    // 0x801D8168: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801D816C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801D8170: nop

    // 0x801D8174: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801D8178: beql        $a0, $zero, L_801D81C8
    if (ctx->r4 == 0) {
        // 0x801D817C: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801D81C8;
    }
    goto skip_13;
    // 0x801D817C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_13:
    // 0x801D8180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D8184: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D8188: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801D818C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801D8190: nop

    // 0x801D8194: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D8198: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801D819C: nop

    // 0x801D81A0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801D81A4: bne         $a0, $zero, L_801D81BC
    if (ctx->r4 != 0) {
        // 0x801D81A8: nop
    
            goto L_801D81BC;
    }
    // 0x801D81A8: nop

    // 0x801D81AC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801D81B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D81B4: b           L_801D81D4
    // 0x801D81B8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801D81D4;
    // 0x801D81B8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801D81BC:
    // 0x801D81BC: b           L_801D81D4
    // 0x801D81C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801D81D4;
    // 0x801D81C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801D81C4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801D81C8:
    // 0x801D81C8: nop

    // 0x801D81CC: bltz        $a0, L_801D81BC
    if (SIGNED(ctx->r4) < 0) {
        // 0x801D81D0: nop
    
            goto L_801D81BC;
    }
    // 0x801D81D0: nop

L_801D81D4:
    // 0x801D81D4: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x801D81D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801D81DC: or          $t8, $t5, $t1
    ctx->r24 = ctx->r13 | ctx->r9;
    // 0x801D81E0: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x801D81E4: bnel        $t3, $t9, L_801D81F8
    if (ctx->r11 != ctx->r25) {
        // 0x801D81E8: sw          $t8, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->r24;
            goto L_801D81F8;
    }
    goto skip_14;
    // 0x801D81E8: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
    skip_14:
    // 0x801D81EC: b           L_801D81F8
    // 0x801D81F0: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
        goto L_801D81F8;
    // 0x801D81F0: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
    // 0x801D81F4: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
L_801D81F8:
    // 0x801D81F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D81FC: lw          $t9, 0x2C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X2C);
    // 0x801D8200: sb          $a0, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r4;
    // 0x801D8204: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D8208: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D820C: sb          $a0, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r4;
    // 0x801D8210: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D8214: lw          $t9, 0x2C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X2C);
    // 0x801D8218: sb          $a0, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r4;
    // 0x801D821C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D8220: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D8224: sb          $t0, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r8;
    // 0x801D8228: lhu         $a2, 0xC($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0XC);
    // 0x801D822C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
L_801D8230:
    // 0x801D8230: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801D8234: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D8238: bne         $at, $zero, L_801D80F0
    if (ctx->r1 != 0) {
        // 0x801D823C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_801D80F0;
    }
    // 0x801D823C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x801D8240: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801D8244: addiu       $s1, $s1, -0x4510
    ctx->r17 = ADD32(ctx->r17, -0X4510);
L_801D8248:
    // 0x801D8248: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801D824C: lw          $ra, 0x1A88($ra)
    ctx->r31 = MEM_W(ctx->r31, 0X1A88);
    // 0x801D8250: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8254: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x801D8258: sw          $ra, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = ctx->r31;
    // 0x801D825C: slti        $at, $ra, 0x5B
    ctx->r1 = SIGNED(ctx->r31) < 0X5B ? 1 : 0;
    // 0x801D8260: bnel        $at, $zero, L_801D8284
    if (ctx->r1 != 0) {
        // 0x801D8264: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801D8284;
    }
    goto skip_15;
    // 0x801D8264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_15:
    // 0x801D8268: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801D826C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x801D8270: b           L_801D8280
    // 0x801D8274: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_801D8280;
    // 0x801D8274: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_801D8278:
    // 0x801D8278: b           L_801D8284
    // 0x801D827C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D8284;
    // 0x801D827C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D8280:
    // 0x801D8280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801D8284:
    // 0x801D8284: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801D8288: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801D828C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801D8290: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801D8294: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801D8298: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801D829C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801D82A0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801D82A4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801D82A8: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x801D82AC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x801D82B0: jr          $ra
    // 0x801D82B4: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x801D82B4: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d82b8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d82b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D82B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D82BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D82C0: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x801D82C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D82C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D82CC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D82D0: jal         0x80006214
    // 0x801D82D4: lw          $a0, 0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17B0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D82D4: lw          $a0, 0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17B0);
    after_0:
    // 0x801D82D8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D82DC: lw          $t6, 0x17B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X17B0);
    // 0x801D82E0: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D82E4: addiu       $t2, $t2, -0x5EC8
    ctx->r10 = ADD32(ctx->r10, -0X5EC8);
    // 0x801D82E8: lw          $t4, 0x5C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X5C);
    // 0x801D82EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801D82F0: lui         $t3, 0x4000
    ctx->r11 = S32(0X4000 << 16);
    // 0x801D82F4: lhu         $t0, 0xC($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0XC);
    // 0x801D82F8: lw          $v0, 0x4($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X4);
    // 0x801D82FC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801D8300: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x801D8304: bne         $at, $zero, L_801D8398
    if (ctx->r1 != 0) {
        // 0x801D8308: addiu       $a1, $v0, 0x4
        ctx->r5 = ADD32(ctx->r2, 0X4);
            goto L_801D8398;
    }
    // 0x801D8308: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x801D830C: addiu       $t1, $t1, -0x2578
    ctx->r9 = ADD32(ctx->r9, -0X2578);
    // 0x801D8310: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_801D8314:
    // 0x801D8314: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801D8318: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
    // 0x801D831C: bgezl       $t7, L_801D8330
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D8320: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801D8330;
    }
    goto skip_0;
    // 0x801D8320: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801D8324: b           L_801D8388
    // 0x801D8328: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
        goto L_801D8388;
    // 0x801D8328: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x801D832C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801D8330:
    // 0x801D8330: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x801D8334: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801D8338: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801D833C: ori         $t5, $t9, 0x100
    ctx->r13 = ctx->r25 | 0X100;
    // 0x801D8340: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x801D8344: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D8348: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D834C: sw          $t6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r14;
    // 0x801D8350: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D8354: lw          $t5, 0x2C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X2C);
    // 0x801D8358: sb          $a3, 0x48($t5)
    MEM_B(0X48, ctx->r13) = ctx->r7;
    // 0x801D835C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D8360: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D8364: sb          $a3, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r7;
    // 0x801D8368: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D836C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D8370: sb          $a3, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r7;
    // 0x801D8374: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801D8378: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801D837C: sb          $s0, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r16;
    // 0x801D8380: lhu         $t0, 0xC($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0XC);
    // 0x801D8384: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
L_801D8388:
    // 0x801D8388: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801D838C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801D8390: bne         $at, $zero, L_801D8314
    if (ctx->r1 != 0) {
        // 0x801D8394: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_801D8314;
    }
    // 0x801D8394: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_801D8398:
    // 0x801D8398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D839C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D83A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D83A4: jr          $ra
    // 0x801D83A8: nop

    return;
    // 0x801D83A8: nop

;}
RECOMP_FUNC void M24_FUN_801d83ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D83AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D83B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D83B4: jal         0x80006214
    // 0x801D83B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D83B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D83BC: jal         0x801C354C
    // 0x801D83C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801D83C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801D83C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D83C8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D83CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D83D0: sw          $t6, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->r14;
    // 0x801D83D4: jr          $ra
    // 0x801D83D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D83D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d83dc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d83dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D83DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801D83E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D83E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D83E8: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x801D83EC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x801D83F0: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x801D83F4: sh          $t6, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r14;
    // 0x801D83F8: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x801D83FC: lw          $s0, 0x7C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X7C);
    // 0x801D8400: addiu       $t1, $zero, 0x200
    ctx->r9 = ADD32(0, 0X200);
    // 0x801D8404: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    // 0x801D8408: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801D840C: sh          $t0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r8;
    // 0x801D8410: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x801D8414: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x801D8418: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x801D841C: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x801D8420: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x801D8424: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x801D8428: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x801D842C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801D8430: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D8434: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D8438: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D843C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x801D8440: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801D8444: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801D8448: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801D844C: jal         0x8002FC20
    // 0x801D8450: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801D8450: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_0:
    // 0x801D8454: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x801D8458: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x801D845C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801D8460: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801D8464: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801D8468: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801D846C: nop

    // 0x801D8470: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801D8474: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801D8478: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D847C: jal         0x8002FC20
    // 0x801D8480: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801D8480: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_1:
    // 0x801D8484: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x801D8488: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801D848C: lwc1        $f14, 0x20($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D8490: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801D8494: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801D8498: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801D849C: nop

    // 0x801D84A0: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801D84A4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801D84A8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D84AC: jal         0x8002FC20
    // 0x801D84B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801D84B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_2:
    // 0x801D84B4: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x801D84B8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x801D84BC: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x801D84C0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801D84C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801D84C8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801D84CC: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x801D84D0: nop

    // 0x801D84D4: bc1tl       L_801D850C
    if (c1cs) {
        // 0x801D84D8: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_801D850C;
    }
    goto skip_0;
    // 0x801D84D8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801D84DC: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801D84E0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D84E4: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801D84E8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D84EC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x801D84F0: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801D84F4: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801D84F8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801D84FC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801D8500: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801D8504: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801D8508: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_801D850C:
    // 0x801D850C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x801D8510: nop

    // 0x801D8514: bc1tl       L_801D854C
    if (c1cs) {
        // 0x801D8518: lwc1        $f0, 0x0($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
            goto L_801D854C;
    }
    goto skip_1;
    // 0x801D8518: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801D851C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801D8520: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801D8524: div.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D8528: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801D852C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x801D8530: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D8534: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801D8538: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x801D853C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D8540: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801D8544: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x801D8548: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_801D854C:
    // 0x801D854C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x801D8550: nop

    // 0x801D8554: bc1tl       L_801D858C
    if (c1cs) {
        // 0x801D8558: lwc1        $f14, 0x4($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
            goto L_801D858C;
    }
    goto skip_2;
    // 0x801D8558: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x801D855C: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D8560: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801D8564: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801D8568: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801D856C: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x801D8570: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D8574: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801D8578: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x801D857C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D8580: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801D8584: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x801D8588: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
L_801D858C:
    // 0x801D858C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801D8590: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801D8594: nop

    // 0x801D8598: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D859C: jal         0x8002FC20
    // 0x801D85A0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x801D85A0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_3:
    // 0x801D85A4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801D85A8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801D85AC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x801D85B0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x801D85B4: jal         0x801D85D0
    // 0x801D85B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x801D85D0)(rdram, ctx);
        goto after_4;
    // 0x801D85B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x801D85BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D85C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D85C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801D85C8: jr          $ra
    // 0x801D85CC: nop

    return;
    // 0x801D85CC: nop

;}
RECOMP_FUNC void M24_FUN_801d85d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D85D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D85D4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D85D8: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x801D85DC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801D85E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D85E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D85E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801D85EC: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801D85F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D85F4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x801D85F8: jal         0x8001EF38
    // 0x801D85FC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801D85FC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x801D8600: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801D8604: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D8608: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801D860C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8610: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // 0x801D8614: lwc1        $f4, -0x29A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x801D8618: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x801D861C: nop

    // 0x801D8620: bc1fl       L_801D86A4
    if (!c1cs) {
        // 0x801D8624: lwc1        $f6, 0x18($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0X18);
            goto L_801D86A4;
    }
    goto skip_0;
    // 0x801D8624: lwc1        $f6, 0x18($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X18);
    skip_0:
    // 0x801D8628: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D862C: nop

    // 0x801D8630: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x801D8634: nop

    // 0x801D8638: bc1tl       L_801D8664
    if (c1cs) {
        // 0x801D863C: sh          $zero, 0x0($a0)
        MEM_H(0X0, ctx->r4) = 0;
            goto L_801D8664;
    }
    goto skip_1;
    // 0x801D863C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    skip_1:
    // 0x801D8640: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x801D8644: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x801D8648: bc1fl       L_801D8684
    if (!c1cs) {
        // 0x801D864C: sh          $t0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r8;
            goto L_801D8684;
    }
    goto skip_2;
    // 0x801D864C: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    skip_2:
    // 0x801D8650: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x801D8654: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x801D8658: beql        $t8, $zero, L_801D8684
    if (ctx->r24 == 0) {
        // 0x801D865C: sh          $t0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r8;
            goto L_801D8684;
    }
    goto skip_3;
    // 0x801D865C: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    skip_3:
    // 0x801D8660: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_801D8664:
    // 0x801D8664: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x801D8668: lwc1        $f14, 0x14($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X14);
    // 0x801D866C: jal         0x8001EF38
    // 0x801D8670: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801D8670: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x801D8674: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801D8678: b           L_801D86E0
    // 0x801D867C: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
        goto L_801D86E0;
    // 0x801D867C: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x801D8680: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
L_801D8684:
    // 0x801D8684: lwc1        $f14, 0x14($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X14);
    // 0x801D8688: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x801D868C: jal         0x8001EF38
    // 0x801D8690: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x801D8690: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_2:
    // 0x801D8694: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801D8698: b           L_801D86E0
    // 0x801D869C: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
        goto L_801D86E0;
    // 0x801D869C: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x801D86A0: lwc1        $f6, 0x18($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X18);
L_801D86A4:
    // 0x801D86A4: lwc1        $f8, 0x28($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X28);
    // 0x801D86A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D86AC: div.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801D86B0: jal         0x8001EF38
    // 0x801D86B4: div.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801D86B4: div.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    after_3:
    // 0x801D86B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D86BC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801D86C0: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x801D86C4: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801D86C8: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801D86CC: div.s       $f14, $f16, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801D86D0: jal         0x8001EF38
    // 0x801D86D4: div.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x801D86D4: div.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    after_4:
    // 0x801D86D8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801D86DC: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_801D86E0:
    // 0x801D86E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D86E4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D86E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D86EC: jr          $ra
    // 0x801D86F0: nop

    return;
    // 0x801D86F0: nop

;}
RECOMP_FUNC void M24_FUN_801d86f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D86F4: nop

    // 0x801D86F8: nop

    // 0x801D86FC: nop

;}
RECOMP_FUNC void M24_FUN_801d8700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8700: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8704: sw          $a0, 0x1BB0($at)
    MEM_W(0X1BB0, ctx->r1) = ctx->r4;
    // 0x801D8708: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D870C: sw          $zero, -0x448C($at)
    MEM_W(-0X448C, ctx->r1) = 0;
    // 0x801D8710: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8714: sw          $zero, -0x4488($at)
    MEM_W(-0X4488, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d8718(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d8718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D871C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8720: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D8724: sw          $t6, -0x4484($at)
    MEM_W(-0X4484, ctx->r1) = ctx->r14;
    // 0x801D8728: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D872C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D8730: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D8734: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8738: addiu       $t7, $t7, -0x789C
    ctx->r15 = ADD32(ctx->r15, -0X789C);
    // 0x801D873C: sw          $zero, -0x4480($at)
    MEM_W(-0X4480, ctx->r1) = 0;
    // 0x801D8740: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D8744: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    // 0x801D8748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D874C: jal         0x8013B570
    // 0x801D8750: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D8750: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D8754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D8758: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D875C: jr          $ra
    // 0x801D8760: nop

    return;
    // 0x801D8760: nop

;}
RECOMP_FUNC void M24_FUN_801d8764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D8768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D876C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D8770: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D8774: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801D8778: beq         $t6, $zero, L_801D8794
    if (ctx->r14 == 0) {
        // 0x801D877C: nop
    
            goto L_801D8794;
    }
    // 0x801D877C: nop

    // 0x801D8780: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801D8784: jal         0x800058DC
    // 0x801D8788: addiu       $a1, $a1, -0x7854
    ctx->r5 = ADD32(ctx->r5, -0X7854);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801D8788: addiu       $a1, $a1, -0x7854
    ctx->r5 = ADD32(ctx->r5, -0X7854);
    after_0:
    // 0x801D878C: b           L_801D87A0
    // 0x801D8790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D87A0;
    // 0x801D8790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D8794:
    // 0x801D8794: jal         0x800058DC
    // 0x801D8798: addiu       $a1, $a1, -0x789C
    ctx->r5 = ADD32(ctx->r5, -0X789C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D8798: addiu       $a1, $a1, -0x789C
    ctx->r5 = ADD32(ctx->r5, -0X789C);
    after_1:
    // 0x801D879C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D87A0:
    // 0x801D87A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D87A4: jr          $ra
    // 0x801D87A8: nop

    return;
    // 0x801D87A8: nop

;}
RECOMP_FUNC void M24_FUN_801d87ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D87AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D87B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D87B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D87B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D87BC: jal         0x801CC540
    // 0x801D87C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D87C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D87C4: beq         $v0, $zero, L_801D87E4
    if (ctx->r2 == 0) {
        // 0x801D87C8: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D87E4;
    }
    // 0x801D87C8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D87CC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801D87D0: addiu       $a1, $a1, -0x7854
    ctx->r5 = ADD32(ctx->r5, -0X7854);
    // 0x801D87D4: jal         0x800058DC
    // 0x801D87D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D87D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D87DC: b           L_801D89A8
    // 0x801D87E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D89A8;
    // 0x801D87E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D87E4:
    // 0x801D87E4: lw          $t6, -0x448C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X448C);
    // 0x801D87E8: beq         $t6, $zero, L_801D883C
    if (ctx->r14 == 0) {
        // 0x801D87EC: nop
    
            goto L_801D883C;
    }
    // 0x801D87EC: nop

    // 0x801D87F0: jal         0x80006214
    // 0x801D87F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D87F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801D87F8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D87FC: lw          $t7, -0x448C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X448C);
    // 0x801D8800: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D8804: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D8808: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D880C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D8810: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D8814: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D8818: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D881C: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D8820: jal         0x8013A28C
    // 0x801D8824: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D8824: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D8828: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801D882C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D8830: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8834: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D8838: sw          $zero, -0x448C($at)
    MEM_W(-0X448C, ctx->r1) = 0;
L_801D883C:
    // 0x801D883C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D8840: lw          $v0, -0x4488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4488);
    // 0x801D8844: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D8848: beq         $v0, $zero, L_801D8914
    if (ctx->r2 == 0) {
        // 0x801D884C: nop
    
            goto L_801D8914;
    }
    // 0x801D884C: nop

    // 0x801D8850: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D8854: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801D8858: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D885C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D8860: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D8864: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D8868: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D886C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D8870: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D8874: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D8878: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D887C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D8880: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D8884: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D8888: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D888C: nop

    // 0x801D8890: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D8894: beql        $t4, $zero, L_801D88E4
    if (ctx->r12 == 0) {
        // 0x801D8898: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D88E4;
    }
    goto skip_0;
    // 0x801D8898: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D889C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D88A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D88A4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D88A8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D88AC: nop

    // 0x801D88B0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D88B4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D88B8: nop

    // 0x801D88BC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D88C0: bne         $t4, $zero, L_801D88D8
    if (ctx->r12 != 0) {
        // 0x801D88C4: nop
    
            goto L_801D88D8;
    }
    // 0x801D88C4: nop

    // 0x801D88C8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D88CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D88D0: b           L_801D88F0
    // 0x801D88D4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D88F0;
    // 0x801D88D4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D88D8:
    // 0x801D88D8: b           L_801D88F0
    // 0x801D88DC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D88F0;
    // 0x801D88DC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D88E0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D88E4:
    // 0x801D88E4: nop

    // 0x801D88E8: bltz        $t4, L_801D88D8
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D88EC: nop
    
            goto L_801D88D8;
    }
    // 0x801D88EC: nop

L_801D88F0:
    // 0x801D88F0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D88F4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D88F8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D88FC: jal         0x80011140
    // 0x801D8900: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D8900: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D8904: beq         $v0, $zero, L_801D898C
    if (ctx->r2 == 0) {
        // 0x801D8908: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D898C;
    }
    // 0x801D8908: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D890C: b           L_801D898C
    // 0x801D8910: sw          $zero, -0x4488($at)
    MEM_W(-0X4488, ctx->r1) = 0;
        goto L_801D898C;
    // 0x801D8910: sw          $zero, -0x4488($at)
    MEM_W(-0X4488, ctx->r1) = 0;
L_801D8914:
    // 0x801D8914: jal         0x80010550
    // 0x801D8918: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D8918: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801D891C: beq         $v0, $zero, L_801D8934
    if (ctx->r2 == 0) {
        // 0x801D8920: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D8934;
    }
    // 0x801D8920: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8924: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D8928: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D892C: b           L_801D8938
    // 0x801D8930: sw          $t5, -0x4484($at)
    MEM_W(-0X4484, ctx->r1) = ctx->r13;
        goto L_801D8938;
    // 0x801D8930: sw          $t5, -0x4484($at)
    MEM_W(-0X4484, ctx->r1) = ctx->r13;
L_801D8934:
    // 0x801D8934: sw          $zero, -0x4484($at)
    MEM_W(-0X4484, ctx->r1) = 0;
L_801D8938:
    // 0x801D8938: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801D893C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D8940: addiu       $t6, $t6, 0x1BC8
    ctx->r14 = ADD32(ctx->r14, 0X1BC8);
    // 0x801D8944: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D8948: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D894C: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D8950: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D8954: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D8958: addiu       $t2, $t2, 0x1BB8
    ctx->r10 = ADD32(ctx->r10, 0X1BB8);
    // 0x801D895C: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D8960: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D8964: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D8968: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D896C: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D8970: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D8974: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D8978: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D897C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D8980: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D8984: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D8988: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D898C:
    // 0x801D898C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D8990: lw          $t7, -0x4480($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4480);
    // 0x801D8994: beql        $t7, $zero, L_801D89A8
    if (ctx->r15 == 0) {
        // 0x801D8998: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D89A8;
    }
    goto skip_1;
    // 0x801D8998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D899C: jal         0x801D8BD0
    // 0x801D89A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D8BD0)(rdram, ctx);
        goto after_6;
    // 0x801D89A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801D89A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D89A8:
    // 0x801D89A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D89AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D89B0: jr          $ra
    // 0x801D89B4: nop

    return;
    // 0x801D89B4: nop

;}
RECOMP_FUNC void M24_FUN_801d89b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D89B8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D89BC: lw          $v0, -0x4488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4488);
    // 0x801D89C0: jr          $ra
    // 0x801D89C4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D89C4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d89c8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d89c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D89C8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D89CC: lw          $t6, -0x4488($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4488);
    // 0x801D89D0: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D89D4: beq         $t6, $zero, L_801D89E4
    if (ctx->r14 == 0) {
            // 0x801D89D8: nop

    LOOKUP_FUNC(0x801D89E4)(rdram, ctx);
    return;
    }
    // 0x801D89D8: nop

    // 0x801D89DC: jr          $ra
    // 0x801D89E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D89E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d89e4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d89e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D89E4: lw          $t7, -0x448C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X448C);
    // 0x801D89E8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D89EC: beq         $t7, $zero, L_801D89FC
    if (ctx->r15 == 0) {
            // 0x801D89F0: nop

    LOOKUP_FUNC(0x801D89FC)(rdram, ctx);
    return;
    }
    // 0x801D89F0: nop

    // 0x801D89F4: jr          $ra
    // 0x801D89F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D89F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d89fc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d89fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D89FC: lw          $v0, -0x4484($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4484);
    // 0x801D8A00: jr          $ra
    // 0x801D8A04: nop

    return;
    // 0x801D8A04: nop

;}
RECOMP_FUNC void M24_FUN_801d8a08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8A08: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D8A0C: jr          $ra
    // 0x801D8A10: addiu       $v0, $v0, 0x1BB8
    ctx->r2 = ADD32(ctx->r2, 0X1BB8);
    return;
    // 0x801D8A10: addiu       $v0, $v0, 0x1BB8
    ctx->r2 = ADD32(ctx->r2, 0X1BB8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d8a14(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d8a14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8A14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D8A18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D8A1C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D8A20: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D8A24: beq         $a0, $zero, L_801D8A7C
    if (ctx->r4 == 0) {
        // 0x801D8A28: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801D8A7C;
    }
    // 0x801D8A28: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D8A2C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D8A30: jal         0x80006214
    // 0x801D8A34: lw          $a0, 0x1BB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BB0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D8A34: lw          $a0, 0x1BB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BB0);
    after_0:
    // 0x801D8A38: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801D8A3C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801D8A40: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801D8A44: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D8A48: lw          $a0, 0x1BB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BB0);
    // 0x801D8A4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D8A50: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801D8A54: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801D8A58: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801D8A5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D8A60: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801D8A64: jal         0x801C3370
    // 0x801D8A68: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801D8A68: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_1:
    // 0x801D8A6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D8A70: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8A74: b           L_801D8A84
    // 0x801D8A78: sw          $t9, -0x4480($at)
    MEM_W(-0X4480, ctx->r1) = ctx->r25;
        goto L_801D8A84;
    // 0x801D8A78: sw          $t9, -0x4480($at)
    MEM_W(-0X4480, ctx->r1) = ctx->r25;
L_801D8A7C:
    // 0x801D8A7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8A80: sw          $zero, -0x4480($at)
    MEM_W(-0X4480, ctx->r1) = 0;
L_801D8A84:
    // 0x801D8A84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D8A88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D8A8C: jr          $ra
    // 0x801D8A90: nop

    return;
    // 0x801D8A90: nop

;}
RECOMP_FUNC void M24_FUN_801d8a94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8A94: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D8A98: lw          $v0, -0x4480($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4480);
    // 0x801D8A9C: jr          $ra
    // 0x801D8AA0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801D8AA0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d8aa4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d8aa4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8AA4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D8AA8: addiu       $v1, $v1, 0x1BC8
    ctx->r3 = ADD32(ctx->r3, 0X1BC8);
    // 0x801D8AAC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D8AB0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D8AB4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D8AB8: beql        $a0, $t6, L_801D8ACC
    if (ctx->r4 == ctx->r14) {
        // 0x801D8ABC: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D8ACC;
    }
    goto skip_0;
    // 0x801D8ABC: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D8AC0: jr          $ra
    // 0x801D8AC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D8AC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D8AC8: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D8ACC:
    // 0x801D8ACC: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D8AD0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D8AD4: jr          $ra
    // 0x801D8AD8: nop

    return;
    // 0x801D8AD8: nop

;}
RECOMP_FUNC void M24_FUN_801d8adc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8ADC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D8AE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D8AE4: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x801D8AE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D8AEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D8AF0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D8AF4: jal         0x80006214
    // 0x801D8AF8: lw          $a0, 0x1BB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BB0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D8AF8: lw          $a0, 0x1BB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1BB0);
    after_0:
    // 0x801D8AFC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D8B00: lw          $t6, 0x1BB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1BB0);
    // 0x801D8B04: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D8B08: addiu       $t2, $t2, -0x5EC8
    ctx->r10 = ADD32(ctx->r10, -0X5EC8);
    // 0x801D8B0C: lw          $t4, 0x5C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X5C);
    // 0x801D8B10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801D8B14: lui         $t3, 0x4000
    ctx->r11 = S32(0X4000 << 16);
    // 0x801D8B18: lhu         $t0, 0xC($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0XC);
    // 0x801D8B1C: lw          $v0, 0x4($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X4);
    // 0x801D8B20: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801D8B24: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x801D8B28: bne         $at, $zero, L_801D8BBC
    if (ctx->r1 != 0) {
        // 0x801D8B2C: addiu       $a1, $v0, 0x4
        ctx->r5 = ADD32(ctx->r2, 0X4);
            goto L_801D8BBC;
    }
    // 0x801D8B2C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x801D8B30: addiu       $t1, $t1, -0x2578
    ctx->r9 = ADD32(ctx->r9, -0X2578);
    // 0x801D8B34: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_801D8B38:
    // 0x801D8B38: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801D8B3C: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
    // 0x801D8B40: bgezl       $t7, L_801D8B54
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D8B44: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801D8B54;
    }
    goto skip_0;
    // 0x801D8B44: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801D8B48: b           L_801D8BAC
    // 0x801D8B4C: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
        goto L_801D8BAC;
    // 0x801D8B4C: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x801D8B50: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801D8B54:
    // 0x801D8B54: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x801D8B58: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801D8B5C: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801D8B60: ori         $t5, $t9, 0x100
    ctx->r13 = ctx->r25 | 0X100;
    // 0x801D8B64: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x801D8B68: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D8B6C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D8B70: sw          $t6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r14;
    // 0x801D8B74: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D8B78: lw          $t5, 0x2C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X2C);
    // 0x801D8B7C: sb          $a3, 0x48($t5)
    MEM_B(0X48, ctx->r13) = ctx->r7;
    // 0x801D8B80: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D8B84: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D8B88: sb          $a3, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r7;
    // 0x801D8B8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D8B90: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D8B94: sb          $a3, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r7;
    // 0x801D8B98: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801D8B9C: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801D8BA0: sb          $s0, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r16;
    // 0x801D8BA4: lhu         $t0, 0xC($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0XC);
    // 0x801D8BA8: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
L_801D8BAC:
    // 0x801D8BAC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801D8BB0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801D8BB4: bne         $at, $zero, L_801D8B38
    if (ctx->r1 != 0) {
        // 0x801D8BB8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_801D8B38;
    }
    // 0x801D8BB8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_801D8BBC:
    // 0x801D8BBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D8BC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D8BC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D8BC8: jr          $ra
    // 0x801D8BCC: nop

    return;
    // 0x801D8BCC: nop

;}
RECOMP_FUNC void M24_FUN_801d8bd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D8BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D8BD8: jal         0x80006214
    // 0x801D8BDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D8BDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D8BE0: jal         0x801C354C
    // 0x801D8BE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801D8BE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801D8BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D8BEC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D8BF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D8BF4: sw          $t6, -0x4480($at)
    MEM_W(-0X4480, ctx->r1) = ctx->r14;
    // 0x801D8BF8: jr          $ra
    // 0x801D8BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D8BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d8c00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d8c00(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801D8C00u);
    return;
}
RECOMP_FUNC void M24_FUN_801d9818(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801D9818u);
    return;
}
RECOMP_FUNC void M24_FUN_801d9a70(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801D9A70u);
    return;
}
RECOMP_FUNC void M24_FUN_801d9cc0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801D9CC0u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbb90(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBB90u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbbd0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBBD0u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbc10(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBC10u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbc50(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBC50u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbc90(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBC90u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbcd0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBCD0u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbd10(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBD10u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbd50(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBD50u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbd90(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBD90u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbdbc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBDBCu);
    return;
}
RECOMP_FUNC void M24_FUN_801dbde8(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBDE8u);
    return;
}
RECOMP_FUNC void M24_FUN_801dbe14(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801DBE14u);
    return;
}
