#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801c7424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7424: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C7428: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C742C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C7430: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C7434: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C7438: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C743C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C7440: jal         0x80005E44
    // 0x801C7444: addiu       $a1, $a1, -0x5A28
    ctx->r5 = ADD32(ctx->r5, -0X5A28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C7444: addiu       $a1, $a1, -0x5A28
    ctx->r5 = ADD32(ctx->r5, -0X5A28);
    after_0:
    // 0x801C7448: jal         0x80006214
    // 0x801C744C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C744C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C7450: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C7454: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C7458: addiu       $t8, $t8, -0x64A0
    ctx->r24 = ADD32(ctx->r24, -0X64A0);
    // 0x801C745C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C7460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C7464: addiu       $a2, $zero, 0x475
    ctx->r6 = ADD32(0, 0X475);
    // 0x801C7468: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801C746C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C7470: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C7474: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C7478: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801C747C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C7480: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C7484: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801C7488: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C748C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C7490: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801C7494: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C7498: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801C749C: jal         0x8012CF8C
    // 0x801C74A0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801C74A0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801C74A4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C74A8: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C74AC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801C74B0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C74B4: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801C74B8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C74BC: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C74C0: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801C74C4: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801C74C8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C74CC: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C74D0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C74D4: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801C74D8: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801C74DC: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801C74E0: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C74E4: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C74E8: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C74EC: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C74F0: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C74F4: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C74F8: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C74FC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801C7500: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C7504: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C7508: jal         0x8002FC20
    // 0x801C750C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x801C750C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_3:
    // 0x801C7510: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801C7514: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x801C7518: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801C751C: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C7520: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C7524: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C7528: jal         0x8001EF38
    // 0x801C752C: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x801C752C: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_4:
    // 0x801C7530: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C7534: andi        $t4, $v0, 0x1FFF
    ctx->r12 = ctx->r2 & 0X1FFF;
    // 0x801C7538: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C753C: sh          $t4, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r12;
    // 0x801C7540: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C7544: jal         0x8001EF38
    // 0x801C7548: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x801C7548: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x801C754C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C7550: addiu       $t8, $v0, 0x1000
    ctx->r24 = ADD32(ctx->r2, 0X1000);
    // 0x801C7554: andi        $t0, $t8, 0x1FFF
    ctx->r8 = ctx->r24 & 0X1FFF;
    // 0x801C7558: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C755C: addiu       $t8, $zero, 0x300
    ctx->r24 = ADD32(0, 0X300);
    // 0x801C7560: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C7564: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    // 0x801C7568: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C756C: lwc1        $f18, 0x9C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801C7570: addiu       $a2, $zero, 0xF0
    ctx->r6 = ADD32(0, 0XF0);
    // 0x801C7574: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C7578: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C757C: addiu       $a1, $a1, 0x7634
    ctx->r5 = ADD32(ctx->r5, 0X7634);
    // 0x801C7580: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    // 0x801C7584: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C7588: lwc1        $f4, 0xA0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801C758C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C7590: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C7594: swc1        $f4, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f4.u32l;
    // 0x801C7598: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C759C: lwc1        $f6, 0xA4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801C75A0: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C75A4: swc1        $f6, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f6.u32l;
    // 0x801C75A8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C75AC: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x801C75B0: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
    // 0x801C75B4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C75B8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C75BC: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x801C75C0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C75C4: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801C75C8: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x801C75CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C75D0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C75D4: sb          $v1, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r3;
    // 0x801C75D8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C75DC: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C75E0: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    // 0x801C75E4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C75E8: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801C75EC: sb          $a2, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r6;
    // 0x801C75F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C75F4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C75F8: sb          $a2, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r6;
    // 0x801C75FC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C7600: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801C7604: sb          $zero, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = 0;
    // 0x801C7608: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C760C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C7610: sb          $v1, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r3;
    // 0x801C7614: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C7618: jal         0x800058DC
    // 0x801C761C: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C761C: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    after_6:
    // 0x801C7620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C7624: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C7628: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C762C: jr          $ra
    // 0x801C7630: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C7630: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7634(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7634: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C7638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C763C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C7640: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C7644: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C7648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C764C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C7650: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C7654: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7658: bgez        $t6, L_801C766C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C765C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C766C;
    }
    // 0x801C765C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C7660: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C7664: nop

    // 0x801C7668: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C766C:
    // 0x801C766C: lhu         $t7, 0xB2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB2);
    // 0x801C7670: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C7678: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C767C: addiu       $a2, $zero, 0x475
    ctx->r6 = ADD32(0, 0X475);
    // 0x801C7680: bgez        $t7, L_801C7694
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C7684: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C7694;
    }
    // 0x801C7684: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C7688: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C768C: nop

    // 0x801C7690: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C7694:
    // 0x801C7694: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801C7698: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801C769C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C76A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C76A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C76A8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C76AC: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C76B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C76B4: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x801C76B8: nop

    // 0x801C76BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C76C0: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x801C76C4: nop

    // 0x801C76C8: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801C76CC: beql        $v1, $zero, L_801C771C
    if (ctx->r3 == 0) {
        // 0x801C76D0: mfc1        $v1, $f10
        ctx->r3 = (int32_t)ctx->f10.u32l;
            goto L_801C771C;
    }
    goto skip_0;
    // 0x801C76D0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801C76D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C76D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C76DC: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C76E0: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x801C76E4: nop

    // 0x801C76E8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C76EC: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x801C76F0: nop

    // 0x801C76F4: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801C76F8: bne         $v1, $zero, L_801C7710
    if (ctx->r3 != 0) {
        // 0x801C76FC: nop
    
            goto L_801C7710;
    }
    // 0x801C76FC: nop

    // 0x801C7700: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x801C7704: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C7708: b           L_801C7728
    // 0x801C770C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_801C7728;
    // 0x801C770C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_801C7710:
    // 0x801C7710: b           L_801C7728
    // 0x801C7714: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_801C7728;
    // 0x801C7714: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801C7718: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
L_801C771C:
    // 0x801C771C: nop

    // 0x801C7720: bltz        $v1, L_801C7710
    if (SIGNED(ctx->r3) < 0) {
        // 0x801C7724: nop
    
            goto L_801C7710;
    }
    // 0x801C7724: nop

L_801C7728:
    // 0x801C7728: lhu         $t9, 0xA8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XA8);
    // 0x801C772C: lhu         $t1, 0xAA($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XAA);
    // 0x801C7730: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C7734: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801C7738: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x801C773C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801C7740: beq         $at, $zero, L_801C78A8
    if (ctx->r1 == 0) {
        // 0x801C7744: sh          $t0, 0xA8($s0)
        MEM_H(0XA8, ctx->r16) = ctx->r8;
            goto L_801C78A8;
    }
    // 0x801C7744: sh          $t0, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r8;
    // 0x801C7748: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C774C: andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // 0x801C7750: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x801C7754: lw          $a1, 0x30($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X30);
    // 0x801C7758: addu        $a3, $a3, $t4
    ctx->r7 = ADD32(ctx->r7, ctx->r12);
    // 0x801C775C: lw          $a3, -0x5A18($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5A18);
    // 0x801C7760: jal         0x8012CF8C
    // 0x801C7764: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C7764: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C7768: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C776C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C7770: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801C7774: sb          $t5, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r13;
    // 0x801C7778: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801C777C: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C7780: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C7784: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C7788: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C778C: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C7790: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801C7794: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801C7798: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x801C779C: jal         0x8001EF38
    // 0x801C77A0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801C77A0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801C77A4: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C77A8: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C77AC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801C77B0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C77B4: addiu       $t0, $v0, 0x1000
    ctx->r8 = ADD32(ctx->r2, 0X1000);
    // 0x801C77B8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C77BC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C77C0: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x801C77C4: sh          $t1, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r9;
    // 0x801C77C8: jal         0x8002FC20
    // 0x801C77CC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801C77CC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x801C77D0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801C77D4: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x801C77D8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801C77DC: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801C77E0: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C77E4: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C77E8: jal         0x8001EF38
    // 0x801C77EC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801C77EC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    after_3:
    // 0x801C77F0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C77F4: andi        $t5, $v0, 0x1FFF
    ctx->r13 = ctx->r2 & 0X1FFF;
    // 0x801C77F8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C77FC: sh          $t5, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r13;
    // 0x801C7800: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C7804: lwc1        $f4, 0xAC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x801C7808: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x801C780C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C7810: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801C7814: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801C7818: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C781C: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x801C7820: lbu         $t0, 0x4C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4C);
    // 0x801C7824: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x801C7828: sb          $t2, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r10;
    // 0x801C782C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C7830: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801C7834: lbu         $t3, 0x4D($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4D);
    // 0x801C7838: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801C783C: sb          $t4, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r12;
    // 0x801C7840: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C7844: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x801C7848: lbu         $t5, 0x4E($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4E);
    // 0x801C784C: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x801C7850: sb          $t7, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r15;
    // 0x801C7854: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C7858: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x801C785C: lbu         $t0, 0x4C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4C);
    // 0x801C7860: sb          $t0, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r8;
    // 0x801C7864: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801C7868: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x801C786C: lbu         $t3, 0x4D($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4D);
    // 0x801C7870: sb          $t3, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r11;
    // 0x801C7874: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801C7878: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x801C787C: lbu         $t5, 0x4E($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4E);
    // 0x801C7880: sb          $t5, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r13;
    // 0x801C7884: lhu         $t7, 0xB0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB0);
    // 0x801C7888: lhu         $t9, 0xB2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XB2);
    // 0x801C788C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801C7890: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x801C7894: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801C7898: beq         $at, $zero, L_801C78A8
    if (ctx->r1 == 0) {
        // 0x801C789C: sh          $t8, 0xB0($s0)
        MEM_H(0XB0, ctx->r16) = ctx->r24;
            goto L_801C78A8;
    }
    // 0x801C789C: sh          $t8, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r24;
    // 0x801C78A0: jal         0x80005700
    // 0x801C78A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801C78A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801C78A8:
    // 0x801C78A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C78AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C78B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C78B4: jr          $ra
    // 0x801C78B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C78B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c78bc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c78bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C78BC: nop

;}
RECOMP_FUNC void M24_FUN_801c78c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C78C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C78C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C78C8: jr          $ra
    // 0x801C78CC: sw          $t6, -0x59F0($at)
    MEM_W(-0X59F0, ctx->r1) = ctx->r14;
    return;
    // 0x801C78CC: sw          $t6, -0x59F0($at)
    MEM_W(-0X59F0, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c78d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c78d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C78D0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C78D4: addiu       $v1, $v1, -0x59F0
    ctx->r3 = ADD32(ctx->r3, -0X59F0);
    // 0x801C78D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801C78DC: lui         $at, 0x5D58
    ctx->r1 = S32(0X5D58 << 16);
    // 0x801C78E0: ori         $at, $at, 0x8B65
    ctx->r1 = ctx->r1 | 0X8B65;
    // 0x801C78E4: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C78E8: mflo        $t7
    ctx->r15 = lo;
    // 0x801C78EC: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x801C78F0: jr          $ra
    // 0x801C78F4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x801C78F4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c78f8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c78f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C78F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C78FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7900: jal         0x801C78D0
    // 0x801C7904: nop

    LOOKUP_FUNC(0x801C78D0)(rdram, ctx);
        goto after_0;
    // 0x801C7904: nop

    after_0:
    // 0x801C7908: srl         $t6, $v0, 24
    ctx->r14 = S32(U32(ctx->r2) >> 24);
    // 0x801C790C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801C7910: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C7914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7918: bgez        $t7, L_801C7930
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C791C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C7930;
    }
    // 0x801C791C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C7920: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7924: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C7928: nop

    // 0x801C792C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C7930:
    // 0x801C7930: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C7934: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C7938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C793C: jr          $ra
    // 0x801C7940: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    return;
    // 0x801C7940: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7944(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C794C: jal         0x801C78C0
    // 0x801C7950: nop

    LOOKUP_FUNC(0x801C78C0)(rdram, ctx);
        goto after_0;
    // 0x801C7950: nop

    after_0:
    // 0x801C7954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C795C: jr          $ra
    // 0x801C7960: nop

    return;
    // 0x801C7960: nop

;}
RECOMP_FUNC void M24_FUN_801c7964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7964: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801C7968: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801C796C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801C7970: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C7974: lwc1        $f22, 0x68($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C7978: mtc1        $a3, $f30
    ctx->f30.u32l = ctx->r7;
    // 0x801C797C: addiu       $v0, $v0, 0x4C0
    ctx->r2 = ADD32(ctx->r2, 0X4C0);
    // 0x801C7980: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801C7984: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801C7988: lwc1        $f26, 0x6C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C798C: mul.s       $f28, $f30, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f28.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x801C7990: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801C7994: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x801C7998: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C799C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801C79A0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801C79A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C79A8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801C79AC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801C79B0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801C79B4: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801C79B8: mul.s       $f24, $f14, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x801C79BC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801C79C0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801C79C4: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x801C79C8: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x801C79CC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x801C79D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C79D4: addiu       $s3, $zero, 0x1E
    ctx->r19 = ADD32(0, 0X1E);
    // 0x801C79D8: swc1        $f22, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f22.u32l;
    // 0x801C79DC: swc1        $f26, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f26.u32l;
    // 0x801C79E0: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x801C79E4: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x801C79E8: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
L_801C79EC:
    // 0x801C79EC: jal         0x801C78F8
    // 0x801C79F0: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_0;
    // 0x801C79F0: nop

    after_0:
    // 0x801C79F4: jal         0x801C78F8
    // 0x801C79F8: sub.s       $f26, $f0, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f30.fl;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_1;
    // 0x801C79F8: sub.s       $f26, $f0, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f30.fl;
    after_1:
    // 0x801C79FC: sub.s       $f2, $f0, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x801C7A00: mul.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f28.fl, ctx->f26.fl);
    // 0x801C7A04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C7A08: mul.s       $f22, $f28, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x801C7A0C: nop

L_801C7A10:
    // 0x801C7A10: jal         0x801C78F8
    // 0x801C7A14: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_2;
    // 0x801C7A14: nop

    after_2:
    // 0x801C7A18: mul.s       $f14, $f24, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x801C7A1C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801C7A20: jal         0x801C8828
    // 0x801C7A24: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    LOOKUP_FUNC(0x801C8828)(rdram, ctx);
        goto after_3;
    // 0x801C7A24: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x801C7A28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C7A2C: bne         $s0, $s1, L_801C7A10
    if (ctx->r16 != ctx->r17) {
        // 0x801C7A30: nop
    
            goto L_801C7A10;
    }
    // 0x801C7A30: nop

    // 0x801C7A34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C7A38: bne         $s2, $s3, L_801C79EC
    if (ctx->r18 != ctx->r19) {
        // 0x801C7A3C: nop
    
            goto L_801C79EC;
    }
    // 0x801C7A3C: nop

    // 0x801C7A40: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801C7A44: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801C7A48: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801C7A4C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801C7A50: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801C7A54: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801C7A58: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801C7A5C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801C7A60: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801C7A64: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801C7A68: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801C7A6C: jr          $ra
    // 0x801C7A70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801C7A70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7a74(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7a74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7A74: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801C7A78: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C7A7C: addiu       $t6, $t6, 0x4C0
    ctx->r14 = ADD32(ctx->r14, 0X4C0);
    // 0x801C7A80: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x801C7A84: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x801C7A88: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x801C7A8C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x801C7A90: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x801C7A94: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x801C7A98: sw          $t7, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r15;
    // 0x801C7A9C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x801C7AA0: sw          $t8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r24;
    // 0x801C7AA4: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x801C7AA8: sw          $t7, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r15;
    // 0x801C7AAC: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x801C7AB0: jr          $ra
    // 0x801C7AB4: sw          $t8, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r24;
    return;
    // 0x801C7AB4: sw          $t8, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7ab8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7ab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7AC0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C7AC4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C7AC8: addiu       $a1, $a1, -0x59E4
    ctx->r5 = ADD32(ctx->r5, -0X59E4);
    // 0x801C7ACC: jal         0x80005670
    // 0x801C7AD0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C7AD0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C7AD4: bne         $v0, $zero, L_801C7AE4
    if (ctx->r2 != 0) {
        // 0x801C7AD8: lui         $a0, 0x8039
        ctx->r4 = S32(0X8039 << 16);
            goto L_801C7AE4;
    }
    // 0x801C7AD8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C7ADC: b           L_801C7B14
    // 0x801C7AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7B14;
    // 0x801C7AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7AE4:
    // 0x801C7AE4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C7AE8: addiu       $a1, $a1, -0x59D0
    ctx->r5 = ADD32(ctx->r5, -0X59D0);
    // 0x801C7AEC: jal         0x80005670
    // 0x801C7AF0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801C7AF0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_1:
    // 0x801C7AF4: bne         $v0, $zero, L_801C7B04
    if (ctx->r2 != 0) {
        // 0x801C7AF8: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801C7B04;
    }
    // 0x801C7AF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7AFC: b           L_801C7B14
    // 0x801C7B00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7B14;
    // 0x801C7B00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7B04:
    // 0x801C7B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C7B08: sw          $v0, -0x59EC($at)
    MEM_W(-0X59EC, ctx->r1) = ctx->r2;
    // 0x801C7B0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7B10: sw          $v0, -0x59E8($at)
    MEM_W(-0X59E8, ctx->r1) = ctx->r2;
L_801C7B14:
    // 0x801C7B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C7B1C: jr          $ra
    // 0x801C7B20: nop

    return;
    // 0x801C7B20: nop

;}
RECOMP_FUNC void M24_FUN_801c7b24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7B24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7B28: jr          $ra
    // 0x801C7B2C: sw          $zero, -0x59EC($at)
    MEM_W(-0X59EC, ctx->r1) = 0;
    return;
    // 0x801C7B2C: sw          $zero, -0x59EC($at)
    MEM_W(-0X59EC, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7b30(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7B30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7B34: jr          $ra
    // 0x801C7B38: sw          $a0, -0x59E8($at)
    MEM_W(-0X59E8, ctx->r1) = ctx->r4;
    return;
    // 0x801C7B38: sw          $a0, -0x59E8($at)
    MEM_W(-0X59E8, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7b3c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7b3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7B44: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C7B48: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C7B4C: addiu       $a1, $a1, -0x59B4
    ctx->r5 = ADD32(ctx->r5, -0X59B4);
    // 0x801C7B50: jal         0x80005670
    // 0x801C7B54: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C7B54: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C7B58: bne         $v0, $zero, L_801C7B68
    if (ctx->r2 != 0) {
        // 0x801C7B5C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801C7B68;
    }
    // 0x801C7B5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7B60: b           L_801C7B78
    // 0x801C7B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7B78;
    // 0x801C7B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7B68:
    // 0x801C7B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C7B6C: sw          $v0, -0x59BC($at)
    MEM_W(-0X59BC, ctx->r1) = ctx->r2;
    // 0x801C7B70: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7B74: sw          $v0, -0x59B8($at)
    MEM_W(-0X59B8, ctx->r1) = ctx->r2;
L_801C7B78:
    // 0x801C7B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C7B80: jr          $ra
    // 0x801C7B84: nop

    return;
    // 0x801C7B84: nop

;}
RECOMP_FUNC void M24_FUN_801c7b88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7B88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7B8C: sw          $zero, -0x59BC($at)
    MEM_W(-0X59BC, ctx->r1) = 0;
    // 0x801C7B90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7B94: jr          $ra
    // 0x801C7B98: sw          $zero, -0x59B8($at)
    MEM_W(-0X59B8, ctx->r1) = 0;
    return;
    // 0x801C7B98: sw          $zero, -0x59B8($at)
    MEM_W(-0X59B8, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7b9c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7b9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7B9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7BA0: jr          $ra
    // 0x801C7BA4: sw          $a0, -0x59B8($at)
    MEM_W(-0X59B8, ctx->r1) = ctx->r4;
    return;
    // 0x801C7BA4: sw          $a0, -0x59B8($at)
    MEM_W(-0X59B8, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7ba8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7ba8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7BA8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C7BAC: addiu       $t6, $t6, 0x4E0
    ctx->r14 = ADD32(ctx->r14, 0X4E0);
    // 0x801C7BB0: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x801C7BB4: addiu       $t0, $a0, 0x6C
    ctx->r8 = ADD32(ctx->r4, 0X6C);
L_801C7BB8:
    // 0x801C7BB8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x801C7BBC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801C7BC0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801C7BC4: sw          $t8, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r24;
    // 0x801C7BC8: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x801C7BCC: sw          $t7, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r15;
    // 0x801C7BD0: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x801C7BD4: bne         $t9, $t0, L_801C7BB8
    if (ctx->r25 != ctx->r8) {
        // 0x801C7BD8: sw          $t8, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r24;
            goto L_801C7BB8;
    }
    // 0x801C7BD8: sw          $t8, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r24;
    // 0x801C7BDC: jr          $ra
    // 0x801C7BE0: nop

    return;
    // 0x801C7BE0: nop

;}
RECOMP_FUNC void M24_FUN_801c7be4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7BEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C7BF0: jal         0x801C0D04
    // 0x801C7BF4: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x801C7BF4: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    after_0:
    // 0x801C7BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C7C00: jr          $ra
    // 0x801C7C04: nop

    return;
    // 0x801C7C04: nop

;}
RECOMP_FUNC void M24_FUN_801c7c08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7C08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C7C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7C10: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x801C7C14: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801C7C18: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801C7C1C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801C7C20: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801C7C24: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C7C28: jal         0x801C0DE4
    // 0x801C7C2C: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x801C7C2C: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    after_0:
    // 0x801C7C30: beq         $v0, $zero, L_801C7C4C
    if (ctx->r2 == 0) {
        // 0x801C7C34: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_801C7C4C;
    }
    // 0x801C7C34: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C7C38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C7C3C: jal         0x801C0EB0
    // 0x801C7C40: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x801C7C40: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    after_1:
    // 0x801C7C44: b           L_801C7CFC
    // 0x801C7C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C7CFC;
    // 0x801C7C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C7C4C:
    // 0x801C7C4C: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    // 0x801C7C50: jal         0x801C0DE4
    // 0x801C7C54: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_2;
    // 0x801C7C54: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801C7C58: beq         $v0, $zero, L_801C7CF8
    if (ctx->r2 == 0) {
        // 0x801C7C5C: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_801C7CF8;
    }
    // 0x801C7C5C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C7C60: jal         0x801C0F18
    // 0x801C7C64: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_3;
    // 0x801C7C64: addiu       $a1, $zero, 0x20F1
    ctx->r5 = ADD32(0, 0X20F1);
    after_3:
    // 0x801C7C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C7C6C: jal         0x80034C24
    // 0x801C7C70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_4;
    // 0x801C7C70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x801C7C74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7C78: ldc1        $f4, -0x2D40($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D40);
    // 0x801C7C7C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C7C80: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C7C84: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801C7C88: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C7C8C: addiu       $a0, $a0, 0x4E0
    ctx->r4 = ADD32(ctx->r4, 0X4E0);
    // 0x801C7C90: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801C7C94: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C7C98: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801C7C9C: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x801C7CA0: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801C7CA4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801C7CA8: div.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801C7CAC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801C7CB0: jal         0x801C8AB8
    // 0x801C7CB4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x801C8AB8)(rdram, ctx);
        goto after_5;
    // 0x801C7CB4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x801C7CB8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801C7CBC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801C7CC0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C7CC4: addiu       $a0, $a0, 0x504
    ctx->r4 = ADD32(ctx->r4, 0X504);
    // 0x801C7CC8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801C7CCC: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x801C7CD0: jal         0x801C8AB8
    // 0x801C7CD4: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    LOOKUP_FUNC(0x801C8AB8)(rdram, ctx);
        goto after_6;
    // 0x801C7CD4: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    after_6:
    // 0x801C7CD8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801C7CDC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801C7CE0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C7CE4: addiu       $a0, $a0, 0x528
    ctx->r4 = ADD32(ctx->r4, 0X528);
    // 0x801C7CE8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801C7CEC: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    // 0x801C7CF0: jal         0x801C8AB8
    // 0x801C7CF4: addiu       $a2, $a2, 0x48
    ctx->r6 = ADD32(ctx->r6, 0X48);
    LOOKUP_FUNC(0x801C8AB8)(rdram, ctx);
        goto after_7;
    // 0x801C7CF4: addiu       $a2, $a2, 0x48
    ctx->r6 = ADD32(ctx->r6, 0X48);
    after_7:
L_801C7CF8:
    // 0x801C7CF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7CFC:
    // 0x801C7CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7D00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C7D04: jr          $ra
    // 0x801C7D08: nop

    return;
    // 0x801C7D08: nop

;}
RECOMP_FUNC void M24_FUN_801c7d0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7D14: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C7D18: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C7D1C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C7D20: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C7D24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C7D28: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C7D2C: addiu       $a1, $a1, -0x59A0
    ctx->r5 = ADD32(ctx->r5, -0X59A0);
    // 0x801C7D30: jal         0x80005670
    // 0x801C7D34: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C7D34: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C7D38: bne         $v0, $zero, L_801C7D48
    if (ctx->r2 != 0) {
        // 0x801C7D3C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C7D48;
    }
    // 0x801C7D3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C7D40: b           L_801C7DA4
    // 0x801C7D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7DA4;
    // 0x801C7D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7D48:
    // 0x801C7D48: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C7D4C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C7D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C7D54: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C7D58: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C7D5C: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C7D60: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C7D64: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C7D68: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C7D6C: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C7D70: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C7D74: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C7D78: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C7D7C: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C7D80: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C7D84: swc1        $f4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f4.u32l;
    // 0x801C7D88: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C7D8C: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C7D90: swc1        $f6, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f6.u32l;
    // 0x801C7D94: lhu         $t6, 0x3A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3A);
    // 0x801C7D98: jal         0x8038C4D8
    // 0x801C7D9C: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
    LOOKUP_FUNC(0x8038C4D8)(rdram, ctx);
        goto after_1;
    // 0x801C7D9C: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
    after_1:
    // 0x801C7DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C7DA4:
    // 0x801C7DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C7DAC: jr          $ra
    // 0x801C7DB0: nop

    return;
    // 0x801C7DB0: nop

;}
RECOMP_FUNC void M24_FUN_801c7db4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7DB4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C7DB8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C7DBC: addiu       $v0, $v0, 0x5D0
    ctx->r2 = ADD32(ctx->r2, 0X5D0);
    // 0x801C7DC0: addiu       $v1, $v1, 0x550
    ctx->r3 = ADD32(ctx->r3, 0X550);
L_801C7DC4:
    // 0x801C7DC4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801C7DC8: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x801C7DCC: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801C7DD0: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C7DD4: bne         $v1, $v0, L_801C7DC4
    if (ctx->r3 != ctx->r2) {
        // 0x801C7DD8: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_801C7DC4;
    }
    // 0x801C7DD8: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C7DDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7DE0: jr          $ra
    // 0x801C7DE4: sw          $zero, -0x5980($at)
    MEM_W(-0X5980, ctx->r1) = 0;
    return;
    // 0x801C7DE4: sw          $zero, -0x5980($at)
    MEM_W(-0X5980, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7de8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7de8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7DEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C7DF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C7DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7DF8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C7DFC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C7E00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C7E04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C7E08: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C7E0C: jal         0x80005670
    // 0x801C7E10: addiu       $a1, $a1, -0x597C
    ctx->r5 = ADD32(ctx->r5, -0X597C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C7E10: addiu       $a1, $a1, -0x597C
    ctx->r5 = ADD32(ctx->r5, -0X597C);
    after_0:
    // 0x801C7E14: bne         $v0, $zero, L_801C7E24
    if (ctx->r2 != 0) {
        // 0x801C7E18: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_801C7E24;
    }
    // 0x801C7E18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801C7E1C: b           L_801C7EB8
    // 0x801C7E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7EB8;
    // 0x801C7E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7E24:
    // 0x801C7E24: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C7E28: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C7E2C: addiu       $a0, $a0, -0x5980
    ctx->r4 = ADD32(ctx->r4, -0X5980);
    // 0x801C7E30: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x801C7E34: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C7E38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7E3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C7E40: swc1        $f6, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f6.u32l;
    // 0x801C7E44: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C7E48: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801C7E4C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C7E50: swc1        $f10, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f10.u32l;
    // 0x801C7E54: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C7E58: swc1        $f16, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->f16.u32l;
    // 0x801C7E5C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C7E60: swc1        $f18, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->f18.u32l;
    // 0x801C7E64: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C7E68: swc1        $f4, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f4.u32l;
    // 0x801C7E6C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801C7E70: swc1        $f6, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f6.u32l;
    // 0x801C7E74: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801C7E78: sb          $t6, 0xB0($v0)
    MEM_B(0XB0, ctx->r2) = ctx->r14;
    // 0x801C7E7C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801C7E80: sb          $t7, 0xB1($v0)
    MEM_B(0XB1, ctx->r2) = ctx->r15;
    // 0x801C7E84: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801C7E88: sb          $t8, 0xB2($v0)
    MEM_B(0XB2, ctx->r2) = ctx->r24;
    // 0x801C7E8C: sb          $zero, 0xB3($a1)
    MEM_B(0XB3, ctx->r5) = 0;
    // 0x801C7E90: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801C7E94: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x801C7E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C7E9C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801C7EA0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801C7EA4: sw          $t9, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r25;
    // 0x801C7EA8: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x801C7EAC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x801C7EB0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801C7EB4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_801C7EB8:
    // 0x801C7EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C7EC0: jr          $ra
    // 0x801C7EC4: nop

    return;
    // 0x801C7EC4: nop

;}
RECOMP_FUNC void M24_FUN_801c7ec8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7EC8: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x801C7ECC: bne         $at, $zero, L_801C7EDC
    if (ctx->r1 != 0) {
            // 0x801C7ED0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    LOOKUP_FUNC(0x801C7EDC)(rdram, ctx);
    return;
    }
    // 0x801C7ED0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C7ED4: jr          $ra
    // 0x801C7ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801C7ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7edc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7edc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7EDC: lw          $t6, -0x5980($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5980);
    // 0x801C7EE0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801C7EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C7EE8: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801C7EEC: bne         $at, $zero, L_801C7EFC
    if (ctx->r1 != 0) {
            // 0x801C7EF0: nop

    LOOKUP_FUNC(0x801C7EFC)(rdram, ctx);
    return;
    }
    // 0x801C7EF0: nop

    // 0x801C7EF4: jr          $ra
    // 0x801C7EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801C7EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7efc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7efc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7EFC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7F00: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801C7F04: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
    // 0x801C7F08: jr          $ra
    // 0x801C7F0C: nop

    return;
    // 0x801C7F0C: nop

;}
RECOMP_FUNC void M24_FUN_801c7f10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7F10: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C7F14: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C7F18: addiu       $v0, $v0, 0x5D0
    ctx->r2 = ADD32(ctx->r2, 0X5D0);
    // 0x801C7F1C: addiu       $v1, $v1, 0x550
    ctx->r3 = ADD32(ctx->r3, 0X550);
L_801C7F20:
    // 0x801C7F20: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801C7F24: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x801C7F28: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801C7F2C: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C7F30: bne         $v1, $v0, L_801C7F20
    if (ctx->r3 != ctx->r2) {
        // 0x801C7F34: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_801C7F20;
    }
    // 0x801C7F34: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C7F38: jr          $ra
    // 0x801C7F3C: nop

    return;
    // 0x801C7F3C: nop

;}
RECOMP_FUNC void M24_FUN_801c7f40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7F40: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C7F44: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C7F48: addiu       $v0, $v0, 0x650
    ctx->r2 = ADD32(ctx->r2, 0X650);
    // 0x801C7F4C: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
L_801C7F50:
    // 0x801C7F50: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801C7F54: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x801C7F58: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801C7F5C: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C7F60: bne         $v1, $v0, L_801C7F50
    if (ctx->r3 != ctx->r2) {
        // 0x801C7F64: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_801C7F50;
    }
    // 0x801C7F64: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C7F68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7F6C: jr          $ra
    // 0x801C7F70: sw          $zero, -0x5968($at)
    MEM_W(-0X5968, ctx->r1) = 0;
    return;
    // 0x801C7F70: sw          $zero, -0x5968($at)
    MEM_W(-0X5968, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7f74(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7f74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C7F7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C7F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7F84: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C7F88: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C7F8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C7F90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C7F94: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C7F98: jal         0x80005670
    // 0x801C7F9C: addiu       $a1, $a1, -0x5964
    ctx->r5 = ADD32(ctx->r5, -0X5964);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C7F9C: addiu       $a1, $a1, -0x5964
    ctx->r5 = ADD32(ctx->r5, -0X5964);
    after_0:
    // 0x801C7FA0: bne         $v0, $zero, L_801C7FB0
    if (ctx->r2 != 0) {
        // 0x801C7FA4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C7FB0;
    }
    // 0x801C7FA4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C7FA8: b           L_801C8040
    // 0x801C7FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C8040;
    // 0x801C7FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7FB0:
    // 0x801C7FB0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C7FB4: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801C7FB8: addiu       $a2, $a2, -0x5968
    ctx->r6 = ADD32(ctx->r6, -0X5968);
    // 0x801C7FBC: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C7FC0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C7FC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7FC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C7FCC: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C7FD0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C7FD4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C7FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C7FDC: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C7FE0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C7FE4: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C7FE8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C7FEC: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C7FF0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C7FF4: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C7FF8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C7FFC: swc1        $f4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f4.u32l;
    // 0x801C8000: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801C8004: swc1        $f6, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f6.u32l;
    // 0x801C8008: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801C800C: sb          $zero, 0xB3($v1)
    MEM_B(0XB3, ctx->r3) = 0;
    // 0x801C8010: sb          $t6, 0xB0($v1)
    MEM_B(0XB0, ctx->r3) = ctx->r14;
    // 0x801C8014: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801C8018: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801C801C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801C8020: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801C8024: sw          $t7, 0x5D0($at)
    MEM_W(0X5D0, ctx->r1) = ctx->r15;
    // 0x801C8028: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x801C802C: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801C8030: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801C8034: jal         0x8038C4D8
    // 0x801C8038: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    LOOKUP_FUNC(0x8038C4D8)(rdram, ctx);
        goto after_1;
    // 0x801C8038: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    after_1:
    // 0x801C803C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C8040:
    // 0x801C8040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C8048: jr          $ra
    // 0x801C804C: nop

    return;
    // 0x801C804C: nop

;}
RECOMP_FUNC void M24_FUN_801c8050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8050: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x801C8054: bne         $at, $zero, L_801C8064
    if (ctx->r1 != 0) {
            // 0x801C8058: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    LOOKUP_FUNC(0x801C8064)(rdram, ctx);
    return;
    }
    // 0x801C8058: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C805C: jr          $ra
    // 0x801C8060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801C8060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8064(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8064: lw          $t6, -0x5968($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5968);
    // 0x801C8068: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801C806C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C8070: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801C8074: bne         $at, $zero, L_801C8084
    if (ctx->r1 != 0) {
            // 0x801C8078: nop

    LOOKUP_FUNC(0x801C8084)(rdram, ctx);
    return;
    }
    // 0x801C8078: nop

    // 0x801C807C: jr          $ra
    // 0x801C8080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801C8080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8084(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8084: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8088: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801C808C: sw          $zero, 0x5D0($at)
    MEM_W(0X5D0, ctx->r1) = 0;
    // 0x801C8090: jr          $ra
    // 0x801C8094: nop

    return;
    // 0x801C8094: nop

;}
RECOMP_FUNC void M24_FUN_801c8098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8098: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C809C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C80A0: addiu       $v0, $v0, 0x650
    ctx->r2 = ADD32(ctx->r2, 0X650);
    // 0x801C80A4: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
L_801C80A8:
    // 0x801C80A8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801C80AC: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x801C80B0: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801C80B4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C80B8: bne         $v1, $v0, L_801C80A8
    if (ctx->r3 != ctx->r2) {
        // 0x801C80BC: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_801C80A8;
    }
    // 0x801C80BC: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C80C0: jr          $ra
    // 0x801C80C4: nop

    return;
    // 0x801C80C4: nop

;}
RECOMP_FUNC void M24_FUN_801c80c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C80C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C80CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C80D0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C80D4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C80D8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C80DC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C80E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C80E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C80E8: addiu       $a1, $a1, -0x5950
    ctx->r5 = ADD32(ctx->r5, -0X5950);
    // 0x801C80EC: jal         0x80005670
    // 0x801C80F0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C80F0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C80F4: bne         $v0, $zero, L_801C8104
    if (ctx->r2 != 0) {
        // 0x801C80F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C8104;
    }
    // 0x801C80F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C80FC: b           L_801C814C
    // 0x801C8100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C814C;
    // 0x801C8100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C8104:
    // 0x801C8104: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C8108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C810C: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C8110: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C8114: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C8118: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C811C: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C8120: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C8124: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C8128: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C812C: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C8130: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C8134: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C8138: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C813C: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C8140: swc1        $f4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f4.u32l;
    // 0x801C8144: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x801C8148: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
L_801C814C:
    // 0x801C814C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C8154: jr          $ra
    // 0x801C8158: nop

    return;
    // 0x801C8158: nop

;}
RECOMP_FUNC void M24_FUN_801c815c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C815C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C8160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8164: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C8168: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C816C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C8170: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C8174: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C8178: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C817C: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x801C8180: jal         0x80005670
    // 0x801C8184: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C8184: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C8188: bne         $v0, $zero, L_801C8198
    if (ctx->r2 != 0) {
        // 0x801C818C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C8198;
    }
    // 0x801C818C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C8190: b           L_801C81E0
    // 0x801C8194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C81E0;
    // 0x801C8194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C8198:
    // 0x801C8198: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C819C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C81A0: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C81A4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C81A8: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C81AC: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C81B0: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C81B4: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C81B8: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C81BC: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C81C0: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C81C4: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C81C8: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C81CC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C81D0: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C81D4: swc1        $f4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f4.u32l;
    // 0x801C81D8: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x801C81DC: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
L_801C81E0:
    // 0x801C81E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C81E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C81E8: jr          $ra
    // 0x801C81EC: nop

    return;
    // 0x801C81EC: nop

;}
RECOMP_FUNC void M24_FUN_801c81f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C81F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C81F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C81F8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C81FC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C8200: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C8204: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C8208: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C820C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C8210: addiu       $a1, $a1, -0x5928
    ctx->r5 = ADD32(ctx->r5, -0X5928);
    // 0x801C8214: jal         0x80005670
    // 0x801C8218: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C8218: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C821C: bne         $v0, $zero, L_801C822C
    if (ctx->r2 != 0) {
        // 0x801C8220: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C822C;
    }
    // 0x801C8220: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C8224: b           L_801C8274
    // 0x801C8228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C8274;
    // 0x801C8228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C822C:
    // 0x801C822C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C8230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C8234: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C8238: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C823C: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C8240: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C8244: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C8248: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C824C: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C8250: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C8254: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C8258: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C825C: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C8260: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C8264: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C8268: swc1        $f4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f4.u32l;
    // 0x801C826C: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x801C8270: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
L_801C8274:
    // 0x801C8274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C827C: jr          $ra
    // 0x801C8280: nop

    return;
    // 0x801C8280: nop

;}
RECOMP_FUNC void M24_FUN_801c8284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C8288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C828C: jal         0x801C78C0
    // 0x801C8290: nop

    LOOKUP_FUNC(0x801C78C0)(rdram, ctx);
        goto after_0;
    // 0x801C8290: nop

    after_0:
    // 0x801C8294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C829C: jr          $ra
    // 0x801C82A0: nop

    return;
    // 0x801C82A0: nop

;}
RECOMP_FUNC void M24_FUN_801c82a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C82A4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801C82A8: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x801C82AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C82B0: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x801C82B4: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x801C82B8: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x801C82BC: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x801C82C0: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x801C82C4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801C82C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801C82CC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x801C82D0: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801C82D4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801C82D8: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x801C82DC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x801C82E0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x801C82E4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x801C82E8: lwc1        $f22, 0x80($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C82EC: lwc1        $f28, 0x7C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C82F0: lwc1        $f30, 0x78($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801C82F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C82F8: addiu       $s1, $zero, 0x1E
    ctx->r17 = ADD32(0, 0X1E);
    // 0x801C82FC: lhu         $s2, 0x86($sp)
    ctx->r18 = MEM_HU(ctx->r29, 0X86);
L_801C8300:
    // 0x801C8300: jal         0x801C78F8
    // 0x801C8304: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_0;
    // 0x801C8304: nop

    after_0:
    // 0x801C8308: sub.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801C830C: mul.s       $f20, $f4, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x801C8310: jal         0x801C78F8
    // 0x801C8314: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_1;
    // 0x801C8314: nop

    after_1:
    // 0x801C8318: sub.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801C831C: mul.s       $f24, $f6, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x801C8320: jal         0x801C78F8
    // 0x801C8324: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_2;
    // 0x801C8324: nop

    after_2:
    // 0x801C8328: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C832C: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801C8330: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x801C8334: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x801C8338: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C833C: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C8340: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x801C8344: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x801C8348: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801C834C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801C8350: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x801C8354: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801C8358: jal         0x801C89DC
    // 0x801C835C: nop

    LOOKUP_FUNC(0x801C89DC)(rdram, ctx);
        goto after_3;
    // 0x801C835C: nop

    after_3:
    // 0x801C8360: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C8364: bne         $s0, $s1, L_801C8300
    if (ctx->r16 != ctx->r17) {
        // 0x801C8368: nop
    
            goto L_801C8300;
    }
    // 0x801C8368: nop

    // 0x801C836C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x801C8370: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801C8374: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801C8378: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801C837C: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801C8380: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x801C8384: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x801C8388: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801C838C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x801C8390: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x801C8394: jr          $ra
    // 0x801C8398: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801C8398: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c839c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c839c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C839C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C83A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C83A4: jal         0x801C78C0
    // 0x801C83A8: nop

    LOOKUP_FUNC(0x801C78C0)(rdram, ctx);
        goto after_0;
    // 0x801C83A8: nop

    after_0:
    // 0x801C83AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C83B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C83B4: jr          $ra
    // 0x801C83B8: nop

    return;
    // 0x801C83B8: nop

;}
RECOMP_FUNC void M24_FUN_801c83bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C83BC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c83c0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c83c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C83C0: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x801C83C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C83C8: lwc1        $f28, -0x2D38($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X2D38);
    // 0x801C83CC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801C83D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C83D4: sw          $s3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r19;
    // 0x801C83D8: sw          $s2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r18;
    // 0x801C83DC: sw          $s1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r17;
    // 0x801C83E0: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x801C83E4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801C83E8: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x801C83EC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801C83F0: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x801C83F4: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x801C83F8: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801C83FC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801C8400: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x801C8404: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801C8408: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x801C840C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x801C8410: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C8414: addiu       $s3, $zero, 0x1E
    ctx->r19 = ADD32(0, 0X1E);
L_801C8418:
    // 0x801C8418: jal         0x801C78F8
    // 0x801C841C: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_0;
    // 0x801C841C: nop

    after_0:
    // 0x801C8420: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C8424: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C8428: jal         0x801C78F8
    // 0x801C842C: sub.s       $f30, $f0, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f30.fl = ctx->f0.fl - ctx->f4.fl;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_1;
    // 0x801C842C: sub.s       $f30, $f0, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f30.fl = ctx->f0.fl - ctx->f4.fl;
    after_1:
    // 0x801C8430: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C8434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C8438: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C843C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C8440: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801C8444: mul.s       $f8, $f12, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f30.fl);
    // 0x801C8448: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801C844C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C8450: mul.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x801C8454: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C8458: add.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f16.fl + ctx->f18.fl;
L_801C845C:
    // 0x801C845C: jal         0x801C78F8
    // 0x801C8460: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_2;
    // 0x801C8460: nop

    after_2:
    // 0x801C8464: mul.s       $f4, $f28, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x801C8468: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801C846C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801C8470: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x801C8474: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801C8478: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C847C: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x801C8480: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801C8484: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801C8488: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801C848C: jal         0x801C88A4
    // 0x801C8490: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    LOOKUP_FUNC(0x801C88A4)(rdram, ctx);
        goto after_3;
    // 0x801C8490: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x801C8494: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C8498: bne         $s0, $s1, L_801C845C
    if (ctx->r16 != ctx->r17) {
        // 0x801C849C: nop
    
            goto L_801C845C;
    }
    // 0x801C849C: nop

    // 0x801C84A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C84A4: bne         $s2, $s3, L_801C8418
    if (ctx->r18 != ctx->r19) {
        // 0x801C84A8: nop
    
            goto L_801C8418;
    }
    // 0x801C84A8: nop

    // 0x801C84AC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801C84B0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801C84B4: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801C84B8: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801C84BC: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801C84C0: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x801C84C4: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x801C84C8: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x801C84CC: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x801C84D0: lw          $s2, 0x64($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X64);
    // 0x801C84D4: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x801C84D8: jr          $ra
    // 0x801C84DC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801C84DC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c84e0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c84e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C84E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C84E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C84E8: jal         0x801C78C0
    // 0x801C84EC: nop

    LOOKUP_FUNC(0x801C78C0)(rdram, ctx);
        goto after_0;
    // 0x801C84EC: nop

    after_0:
    // 0x801C84F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C84F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C84F8: addiu       $v0, $v0, 0x650
    ctx->r2 = ADD32(ctx->r2, 0X650);
    // 0x801C84FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8500: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8504: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801C8508: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x801C850C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x801C8510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C8514: jr          $ra
    // 0x801C8518: swc1        $f0, -0x5914($at)
    MEM_W(-0X5914, ctx->r1) = ctx->f0.u32l;
    return;
    // 0x801C8518: swc1        $f0, -0x5914($at)
    MEM_W(-0X5914, ctx->r1) = ctx->f0.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c851c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c851c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C851C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801C8520: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x801C8524: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801C8528: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C852C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C8530: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801C8534: addiu       $v0, $v0, 0x650
    ctx->r2 = ADD32(ctx->r2, 0X650);
    // 0x801C8538: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x801C853C: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C8540: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x801C8544: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x801C8548: swc1        $f26, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f26.u32l;
    // 0x801C854C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8550: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x801C8554: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801C8558: swc1        $f8, -0x5914($at)
    MEM_W(-0X5914, ctx->r1) = ctx->f8.u32l;
    // 0x801C855C: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x801C8560: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8564: lwc1        $f28, -0x2D34($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X2D34);
    // 0x801C8568: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801C856C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C8570: sw          $s3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r19;
    // 0x801C8574: sw          $s2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r18;
    // 0x801C8578: sw          $s1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r17;
    // 0x801C857C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801C8580: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801C8584: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x801C8588: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x801C858C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801C8590: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801C8594: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801C8598: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C859C: addiu       $s3, $zero, 0x32
    ctx->r19 = ADD32(0, 0X32);
L_801C85A0:
    // 0x801C85A0: jal         0x801C78F8
    // 0x801C85A4: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_0;
    // 0x801C85A4: nop

    after_0:
    // 0x801C85A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C85AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C85B0: jal         0x801C78F8
    // 0x801C85B4: sub.s       $f30, $f0, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f0.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_1;
    // 0x801C85B4: sub.s       $f30, $f0, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f0.fl - ctx->f10.fl;
    after_1:
    // 0x801C85B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C85BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C85C0: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C85C4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C85C8: sub.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801C85CC: mul.s       $f18, $f12, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f30.fl);
    // 0x801C85D0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801C85D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C85D8: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x801C85DC: add.s       $f22, $f18, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801C85E0: add.s       $f24, $f6, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f8.fl;
L_801C85E4:
    // 0x801C85E4: jal         0x801C78F8
    // 0x801C85E8: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_2;
    // 0x801C85E8: nop

    after_2:
    // 0x801C85EC: mul.s       $f10, $f28, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x801C85F0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801C85F4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801C85F8: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x801C85FC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801C8600: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C8604: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x801C8608: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801C860C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801C8610: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801C8614: jal         0x801C8940
    // 0x801C8618: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    LOOKUP_FUNC(0x801C8940)(rdram, ctx);
        goto after_3;
    // 0x801C8618: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x801C861C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C8620: bne         $s0, $s1, L_801C85E4
    if (ctx->r16 != ctx->r17) {
        // 0x801C8624: nop
    
            goto L_801C85E4;
    }
    // 0x801C8624: nop

    // 0x801C8628: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C862C: bne         $s2, $s3, L_801C85A0
    if (ctx->r18 != ctx->r19) {
        // 0x801C8630: nop
    
            goto L_801C85A0;
    }
    // 0x801C8630: nop

    // 0x801C8634: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801C8638: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801C863C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801C8640: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801C8644: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801C8648: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x801C864C: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x801C8650: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x801C8654: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x801C8658: lw          $s2, 0x64($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X64);
    // 0x801C865C: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x801C8660: jr          $ra
    // 0x801C8664: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801C8664: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8668(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C866C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8670: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C8674: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C8678: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C867C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C8680: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C8684: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C8688: addiu       $a1, $a1, -0x5910
    ctx->r5 = ADD32(ctx->r5, -0X5910);
    // 0x801C868C: jal         0x80005670
    // 0x801C8690: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C8690: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C8694: bne         $v0, $zero, L_801C86A4
    if (ctx->r2 != 0) {
        // 0x801C8698: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C86A4;
    }
    // 0x801C8698: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C869C: b           L_801C86EC
    // 0x801C86A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C86EC;
    // 0x801C86A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C86A4:
    // 0x801C86A4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C86A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C86AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C86B0: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C86B4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C86B8: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C86BC: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C86C0: swc1        $f0, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f0.u32l;
    // 0x801C86C4: swc1        $f0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f0.u32l;
    // 0x801C86C8: swc1        $f0, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f0.u32l;
    // 0x801C86CC: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C86D0: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C86D4: swc1        $f10, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f10.u32l;
    // 0x801C86D8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C86DC: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C86E0: swc1        $f16, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f16.u32l;
    // 0x801C86E4: lhu         $t6, 0x2E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2E);
    // 0x801C86E8: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
L_801C86EC:
    // 0x801C86EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C86F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C86F4: jr          $ra
    // 0x801C86F8: nop

    return;
    // 0x801C86F8: nop

;}
RECOMP_FUNC void M24_FUN_801c86fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C86FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C8700: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C8704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C8708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C870C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C8710: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C8714: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C8718: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C871C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C8720: jal         0x80005670
    // 0x801C8724: addiu       $a1, $a1, -0x58FC
    ctx->r5 = ADD32(ctx->r5, -0X58FC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C8724: addiu       $a1, $a1, -0x58FC
    ctx->r5 = ADD32(ctx->r5, -0X58FC);
    after_0:
    // 0x801C8728: bne         $v0, $zero, L_801C8738
    if (ctx->r2 != 0) {
        // 0x801C872C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C8738;
    }
    // 0x801C872C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C8730: b           L_801C8778
    // 0x801C8734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C8778;
    // 0x801C8734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C8738:
    // 0x801C8738: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801C873C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C8740: sh          $t6, 0x90($v1)
    MEM_H(0X90, ctx->r3) = ctx->r14;
    // 0x801C8744: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C8748: swc1        $f4, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f4.u32l;
    // 0x801C874C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C8750: swc1        $f6, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f6.u32l;
    // 0x801C8754: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C8758: swc1        $f8, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f8.u32l;
    // 0x801C875C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C8760: swc1        $f10, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f10.u32l;
    // 0x801C8764: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C8768: sh          $zero, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = 0;
    // 0x801C876C: swc1        $f16, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f16.u32l;
    // 0x801C8770: lhu         $t7, 0x32($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X32);
    // 0x801C8774: sh          $t7, 0xAA($v1)
    MEM_H(0XAA, ctx->r3) = ctx->r15;
L_801C8778:
    // 0x801C8778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C877C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C8780: jr          $ra
    // 0x801C8784: nop

    return;
    // 0x801C8784: nop

;}
RECOMP_FUNC void M24_FUN_801c8788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8788: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C878C: jr          $ra
    // 0x801C8790: sw          $a0, -0x58E8($at)
    MEM_W(-0X58E8, ctx->r1) = ctx->r4;
    return;
    // 0x801C8790: sw          $a0, -0x58E8($at)
    MEM_W(-0X58E8, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8794(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8794: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801C8798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C879C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x801C87A0: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C87A4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801C87A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C87AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C87B0: mflo        $t6
    ctx->r14 = lo;
    // 0x801C87B4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801C87B8: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801C87BC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C87C0: swc1        $f16, -0x58E4($at)
    MEM_W(-0X58E4, ctx->r1) = ctx->f16.u32l;
    // 0x801C87C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801C87C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C87CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C87D0: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801C87D4: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801C87D8: jr          $ra
    // 0x801C87DC: swc1        $f10, -0x58E0($at)
    MEM_W(-0X58E0, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x801C87DC: swc1        $f10, -0x58E0($at)
    MEM_W(-0X58E0, ctx->r1) = ctx->f10.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c87e0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c87e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C87E0: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C87E4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801C87E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C87EC: lwc1        $f8, -0x58E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X58E4);
    // 0x801C87F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C87F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C87F8: lwc1        $f16, -0x58E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X58E0);
    // 0x801C87FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C8800: mflo        $t6
    ctx->r14 = lo;
    // 0x801C8804: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801C8808: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801C880C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C8810: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801C8814: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801C8818: nop

    // 0x801C881C: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801C8820: jr          $ra
    // 0x801C8824: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    return;
    // 0x801C8824: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8828(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C882C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8830: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C8834: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C8838: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C883C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C8840: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C8844: addiu       $a1, $a1, -0x58DC
    ctx->r5 = ADD32(ctx->r5, -0X58DC);
    // 0x801C8848: jal         0x80005670
    // 0x801C884C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C884C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C8850: bne         $v0, $zero, L_801C8860
    if (ctx->r2 != 0) {
        // 0x801C8854: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C8860;
    }
    // 0x801C8854: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C8858: b           L_801C8894
    // 0x801C885C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C8894;
    // 0x801C885C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C8860:
    // 0x801C8860: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C8864: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C8868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C886C: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C8870: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C8874: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C8878: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C887C: sh          $zero, 0xA4($v1)
    MEM_H(0XA4, ctx->r3) = 0;
    // 0x801C8880: sh          $zero, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = 0;
    // 0x801C8884: sh          $zero, 0xAA($v1)
    MEM_H(0XAA, ctx->r3) = 0;
    // 0x801C8888: swc1        $f0, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f0.u32l;
    // 0x801C888C: swc1        $f0, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->f0.u32l;
    // 0x801C8890: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
L_801C8894:
    // 0x801C8894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C889C: jr          $ra
    // 0x801C88A0: nop

    return;
    // 0x801C88A0: nop

;}
RECOMP_FUNC void M24_FUN_801c88a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C88A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C88A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C88AC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C88B0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C88B4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C88B8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C88BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C88C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C88C4: addiu       $a1, $a1, -0x58C8
    ctx->r5 = ADD32(ctx->r5, -0X58C8);
    // 0x801C88C8: jal         0x80005670
    // 0x801C88CC: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C88CC: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C88D0: bne         $v0, $zero, L_801C88E0
    if (ctx->r2 != 0) {
        // 0x801C88D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C88E0;
    }
    // 0x801C88D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C88D8: b           L_801C8930
    // 0x801C88DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C8930;
    // 0x801C88DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C88E0:
    // 0x801C88E0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C88E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C88E8: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C88EC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C88F0: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C88F4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C88F8: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C88FC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C8900: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C8904: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C8908: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C890C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C8910: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C8914: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C8918: swc1        $f4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f4.u32l;
    // 0x801C891C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C8920: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C8924: swc1        $f6, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f6.u32l;
    // 0x801C8928: lhu         $t6, 0x3A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3A);
    // 0x801C892C: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
L_801C8930:
    // 0x801C8930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C8938: jr          $ra
    // 0x801C893C: nop

    return;
    // 0x801C893C: nop

;}
RECOMP_FUNC void M24_FUN_801c8940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C8944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8948: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C894C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C8950: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C8954: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C8958: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C895C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C8960: addiu       $a1, $a1, -0x58B4
    ctx->r5 = ADD32(ctx->r5, -0X58B4);
    // 0x801C8964: jal         0x80005670
    // 0x801C8968: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C8968: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C896C: bne         $v0, $zero, L_801C897C
    if (ctx->r2 != 0) {
        // 0x801C8970: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C897C;
    }
    // 0x801C8970: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C8974: b           L_801C89CC
    // 0x801C8978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C89CC;
    // 0x801C8978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C897C:
    // 0x801C897C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C8980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C8984: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C8988: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C898C: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C8990: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C8994: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C8998: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C899C: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C89A0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C89A4: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C89A8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C89AC: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C89B0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C89B4: swc1        $f4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f4.u32l;
    // 0x801C89B8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C89BC: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C89C0: swc1        $f6, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f6.u32l;
    // 0x801C89C4: lhu         $t6, 0x3A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3A);
    // 0x801C89C8: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
L_801C89CC:
    // 0x801C89CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C89D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C89D4: jr          $ra
    // 0x801C89D8: nop

    return;
    // 0x801C89D8: nop

;}
RECOMP_FUNC void M24_FUN_801c89dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C89DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C89E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C89E4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C89E8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C89EC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C89F0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C89F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C89F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C89FC: addiu       $a1, $a1, -0x58A0
    ctx->r5 = ADD32(ctx->r5, -0X58A0);
    // 0x801C8A00: jal         0x80005670
    // 0x801C8A04: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C8A04: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C8A08: bne         $v0, $zero, L_801C8A18
    if (ctx->r2 != 0) {
        // 0x801C8A0C: lwc1        $f4, 0x18($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
            goto L_801C8A18;
    }
    // 0x801C8A0C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C8A10: b           L_801C8AA8
    // 0x801C8A14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C8AA8;
    // 0x801C8A14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C8A18:
    // 0x801C8A18: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    // 0x801C8A1C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C8A20: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x801C8A24: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C8A28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801C8A2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C8A30: swc1        $f6, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f6.u32l;
    // 0x801C8A34: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C8A38: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x801C8A3C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C8A40: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801C8A44: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C8A48: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C8A4C: swc1        $f10, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f10.u32l;
    // 0x801C8A50: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C8A54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C8A58: bgez        $a0, L_801C8A6C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801C8A5C: swc1        $f16, 0xA0($v0)
        MEM_W(0XA0, ctx->r2) = ctx->f16.u32l;
            goto L_801C8A6C;
    }
    // 0x801C8A5C: swc1        $f16, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->f16.u32l;
    // 0x801C8A60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C8A64: nop

    // 0x801C8A68: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C8A6C:
    // 0x801C8A6C: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C8A70: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801C8A74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C8A78: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801C8A7C: sh          $zero, 0xB0($v0)
    MEM_H(0XB0, ctx->r2) = 0;
    // 0x801C8A80: sh          $a0, 0xB2($v0)
    MEM_H(0XB2, ctx->r2) = ctx->r4;
    // 0x801C8A84: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C8A88: mflo        $t6
    ctx->r14 = lo;
    // 0x801C8A8C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801C8A90: nop

    // 0x801C8A94: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C8A98: swc1        $f16, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->f16.u32l;
    // 0x801C8A9C: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801C8AA0: swc1        $f8, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f8.u32l;
    // 0x801C8AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C8AA8:
    // 0x801C8AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C8AB0: jr          $ra
    // 0x801C8AB4: nop

    return;
    // 0x801C8AB4: nop

;}
