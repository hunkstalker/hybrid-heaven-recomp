#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801f731c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F731C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F7320: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F7324: jr          $ra
    // 0x801F7328: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F7328: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f732c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f732c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F732C: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F7330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7334: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F7338: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F733C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F7340: jal         0x801BF628
    // 0x801F7344: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F7344: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801F7348: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F734C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F7354: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F7358: bne         $at, $zero, L_801F7368
    if (ctx->r1 != 0) {
        // 0x801F735C: nop
    
            goto L_801F7368;
    }
    // 0x801F735C: nop

    // 0x801F7360: b           L_801F7368
    // 0x801F7364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F7368;
    // 0x801F7364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F7368:
    // 0x801F7368: jr          $ra
    // 0x801F736C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F736C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7370(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7374: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F737C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7380: lui         $a1, 0x208
    ctx->r5 = S32(0X208 << 16);
    // 0x801F7384: ori         $a1, $a1, 0x531F
    ctx->r5 = ctx->r5 | 0X531F;
    // 0x801F7388: jal         0x801C0B8C
    // 0x801F738C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F738C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7390: beq         $v0, $zero, L_801F7518
    if (ctx->r2 == 0) {
        // 0x801F7394: lui         $at, 0xC3D2
        ctx->r1 = S32(0XC3D2 << 16);
            goto L_801F7518;
    }
    // 0x801F7394: lui         $at, 0xC3D2
    ctx->r1 = S32(0XC3D2 << 16);
    // 0x801F7398: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801F739C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801F73A0: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x801F73A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F73A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F73AC: addiu       $v0, $v0, -0x2730
    ctx->r2 = ADD32(ctx->r2, -0X2730);
    // 0x801F73B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801F73B4: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
L_801F73B8:
    // 0x801F73B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F73BC: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x801F73C0: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x801F73C4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F73C8: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x801F73CC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F73D0: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x801F73D4: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x801F73D8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F73DC: swc1        $f2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f2.u32l;
    // 0x801F73E0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F73E4: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F73E8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x801F73EC: lw          $t6, 0x20($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20);
    // 0x801F73F0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F73F4: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801F73F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F73FC: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801F7400: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x801F7404: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F7408: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801F740C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F7410: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x801F7414: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F7418: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F741C: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801F7420: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F7424: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x801F7428: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F742C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F7430: swc1        $f2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f2.u32l;
    // 0x801F7434: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F7438: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F743C: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x801F7440: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F7444: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F7448: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x801F744C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F7450: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x801F7454: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F7458: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F745C: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801F7460: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F7464: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801F7468: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x801F746C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F7470: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x801F7474: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F7478: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x801F747C: lw          $t4, 0x28($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X28);
    // 0x801F7480: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F7484: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    // 0x801F7488: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F748C: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F7490: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x801F7494: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x801F7498: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F749C: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801F74A0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F74A4: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x801F74A8: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x801F74AC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F74B0: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801F74B4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F74B8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x801F74BC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F74C0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F74C4: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801F74C8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F74CC: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801F74D0: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F74D4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F74D8: swc1        $f2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f2.u32l;
    // 0x801F74DC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F74E0: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F74E4: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x801F74E8: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F74EC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F74F0: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x801F74F4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F74F8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x801F74FC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F7500: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801F7504: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F7508: bne         $v1, $a0, L_801F73B8
    if (ctx->r3 != ctx->r4) {
        // 0x801F750C: sh          $zero, 0x12($t9)
        MEM_H(0X12, ctx->r25) = 0;
            goto L_801F73B8;
    }
    // 0x801F750C: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801F7510: b           L_801F751C
    // 0x801F7514: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F751C;
    // 0x801F7514: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F7518:
    // 0x801F7518: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F751C:
    // 0x801F751C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F7524: jr          $ra
    // 0x801F7528: nop

    return;
    // 0x801F7528: nop

;}
RECOMP_FUNC void M25_FUN_801f752c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F752C: lui         $at, 0xC3D2
    ctx->r1 = S32(0XC3D2 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7530(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7534: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F7538: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F753C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7540: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7544: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F7548: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801F754C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7550: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F7554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F7558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F755C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
L_801F7560:
    // 0x801F7560: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7564: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x801F7568: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x801F756C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801F7570: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F7574: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801F7578: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801F757C: nop

    // 0x801F7580: slti        $at, $t0, 0x1A4
    ctx->r1 = SIGNED(ctx->r8) < 0X1A4 ? 1 : 0;
    // 0x801F7584: bnel        $at, $zero, L_801F75A8
    if (ctx->r1 != 0) {
        // 0x801F7588: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_801F75A8;
    }
    goto skip_0;
    // 0x801F7588: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    skip_0:
    // 0x801F758C: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x801F7590: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801F7594: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x801F7598: lw          $t3, 0x20($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20);
    // 0x801F759C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801F75A0: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F75A4: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
L_801F75A8:
    // 0x801F75A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801F75AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801F75B0: bne         $a1, $a2, L_801F7560
    if (ctx->r5 != ctx->r6) {
        // 0x801F75B4: swc1        $f6, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
            goto L_801F7560;
    }
    // 0x801F75B4: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801F75B8: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801F75BC: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    // 0x801F75C0: jal         0x801C0B8C
    // 0x801F75C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F75C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F75C8: lui         $at, 0xC3D2
    ctx->r1 = S32(0XC3D2 << 16);
    // 0x801F75CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F75D0: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F75D4: beq         $v0, $zero, L_801F7754
    if (ctx->r2 == 0) {
        // 0x801F75D8: addiu       $v1, $v1, -0x2730
        ctx->r3 = ADD32(ctx->r3, -0X2730);
            goto L_801F7754;
    }
    // 0x801F75D8: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F75DC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x801F75E0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801F75E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F75E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F75EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F75F0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
L_801F75F4:
    // 0x801F75F4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F75F8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801F75FC: lw          $t6, 0x20($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20);
    // 0x801F7600: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F7604: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801F7608: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F760C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801F7610: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x801F7614: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F7618: swc1        $f2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f2.u32l;
    // 0x801F761C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F7620: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F7624: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801F7628: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x801F762C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F7630: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x801F7634: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7638: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801F763C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x801F7640: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F7644: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801F7648: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F764C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801F7650: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F7654: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F7658: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    // 0x801F765C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F7660: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801F7664: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F7668: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F766C: swc1        $f2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f2.u32l;
    // 0x801F7670: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F7674: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F7678: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801F767C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F7680: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F7684: swc1        $f0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f0.u32l;
    // 0x801F7688: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F768C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801F7690: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F7694: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F7698: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x801F769C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F76A0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801F76A4: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x801F76A8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F76AC: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x801F76B0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F76B4: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801F76B8: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x801F76BC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F76C0: swc1        $f2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f2.u32l;
    // 0x801F76C4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F76C8: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F76CC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801F76D0: lw          $t6, 0x28($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28);
    // 0x801F76D4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F76D8: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801F76DC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F76E0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801F76E4: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x801F76E8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F76EC: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801F76F0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F76F4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801F76F8: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F76FC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F7700: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801F7704: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7708: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801F770C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F7710: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F7714: swc1        $f2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f2.u32l;
    // 0x801F7718: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F771C: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F7720: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801F7724: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F7728: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F772C: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x801F7730: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F7734: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801F7738: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F773C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801F7740: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F7744: bne         $v0, $a0, L_801F75F4
    if (ctx->r2 != ctx->r4) {
        // 0x801F7748: sh          $zero, 0x12($t7)
        MEM_H(0X12, ctx->r15) = 0;
            goto L_801F75F4;
    }
    // 0x801F7748: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801F774C: b           L_801F7758
    // 0x801F7750: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F7758;
    // 0x801F7750: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F7754:
    // 0x801F7754: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F7758:
    // 0x801F7758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F775C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F7760: jr          $ra
    // 0x801F7764: nop

    return;
    // 0x801F7764: nop

;}
RECOMP_FUNC void M25_FUN_801f7768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F776C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7778: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F777C: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    // 0x801F7780: jal         0x801C0B8C
    // 0x801F7784: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F7784: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7788: beq         $v0, $zero, L_801F7914
    if (ctx->r2 == 0) {
        // 0x801F778C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801F7914;
    }
    // 0x801F778C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7790: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x801F7794: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801F7798: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801F779C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F77A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F77A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F77A8: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F77AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F77B0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
L_801F77B4:
    // 0x801F77B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F77B8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801F77BC: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x801F77C0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F77C4: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x801F77C8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F77CC: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801F77D0: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x801F77D4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F77D8: swc1        $f2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f2.u32l;
    // 0x801F77DC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F77E0: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F77E4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801F77E8: lw          $t6, 0x20($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20);
    // 0x801F77EC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F77F0: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801F77F4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F77F8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801F77FC: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x801F7800: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F7804: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801F7808: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F780C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801F7810: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F7814: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F7818: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801F781C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7820: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801F7824: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F7828: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F782C: swc1        $f2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f2.u32l;
    // 0x801F7830: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F7834: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F7838: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801F783C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F7840: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F7844: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x801F7848: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F784C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801F7850: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F7854: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F7858: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801F785C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F7860: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801F7864: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x801F7868: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F786C: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x801F7870: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F7874: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801F7878: lw          $t4, 0x28($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X28);
    // 0x801F787C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F7880: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    // 0x801F7884: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7888: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F788C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801F7890: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x801F7894: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F7898: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801F789C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F78A0: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801F78A4: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x801F78A8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F78AC: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801F78B0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F78B4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801F78B8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F78BC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801F78C0: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801F78C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F78C8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801F78CC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F78D0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801F78D4: swc1        $f2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f2.u32l;
    // 0x801F78D8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801F78DC: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801F78E0: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801F78E4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F78E8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F78EC: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x801F78F0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F78F4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801F78F8: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F78FC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801F7900: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F7904: bne         $v0, $a0, L_801F77B4
    if (ctx->r2 != ctx->r4) {
        // 0x801F7908: sh          $zero, 0x12($t9)
        MEM_H(0X12, ctx->r25) = 0;
            goto L_801F77B4;
    }
    // 0x801F7908: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801F790C: b           L_801F79DC
    // 0x801F7910: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F79DC;
    // 0x801F7910: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F7914:
    // 0x801F7914: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F7918: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F791C: lui         $at, 0xC3D2
    ctx->r1 = S32(0XC3D2 << 16);
    // 0x801F7920: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801F7924: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801F7928: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801F792C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F7930: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_801F7934:
    // 0x801F7934: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F7938: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x801F793C: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x801F7940: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801F7944: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F7948: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801F794C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801F7950: nop

    // 0x801F7954: slti        $at, $t4, 0x1A4
    ctx->r1 = SIGNED(ctx->r12) < 0X1A4 ? 1 : 0;
    // 0x801F7958: bnel        $at, $zero, L_801F797C
    if (ctx->r1 != 0) {
        // 0x801F795C: add.s       $f6, $f0, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_801F797C;
    }
    goto skip_0;
    // 0x801F795C: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    skip_0:
    // 0x801F7960: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x801F7964: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F7968: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x801F796C: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x801F7970: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801F7974: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F7978: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
L_801F797C:
    // 0x801F797C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801F7980: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F7984: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x801F7988: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F798C: lw          $a0, 0x30($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X30);
    // 0x801F7990: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801F7994: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801F7998: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801F799C: nop

    // 0x801F79A0: slti        $at, $t2, 0x1A4
    ctx->r1 = SIGNED(ctx->r10) < 0X1A4 ? 1 : 0;
    // 0x801F79A4: bnel        $at, $zero, L_801F79C8
    if (ctx->r1 != 0) {
        // 0x801F79A8: add.s       $f10, $f2, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_801F79C8;
    }
    goto skip_1;
    // 0x801F79A8: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    skip_1:
    // 0x801F79AC: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x801F79B0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801F79B4: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x801F79B8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F79BC: lw          $a0, 0x30($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X30);
    // 0x801F79C0: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801F79C4: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
L_801F79C8:
    // 0x801F79C8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x801F79CC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x801F79D0: bne         $a2, $a3, L_801F7934
    if (ctx->r6 != ctx->r7) {
        // 0x801F79D4: swc1        $f10, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
            goto L_801F7934;
    }
    // 0x801F79D4: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x801F79D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F79DC:
    // 0x801F79DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F79E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F79E4: jr          $ra
    // 0x801F79E8: nop

    return;
    // 0x801F79E8: nop

;}
RECOMP_FUNC void M25_FUN_801f79ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F79EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F79F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F79F4: jr          $ra
    // 0x801F79F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801F79F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f79fc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f79fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F79FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F7A00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F7A04: jr          $ra
    // 0x801F7A08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F7A08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7a0c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7a0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7A10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7A18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7A1C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7A20: addiu       $a1, $a1, 0xA48
    ctx->r5 = ADD32(ctx->r5, 0XA48);
    // 0x801F7A24: jal         0x801C2420
    // 0x801F7A28: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801F7A28: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    after_0:
    // 0x801F7A2C: jal         0x801CC318
    // 0x801F7A30: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_1;
    // 0x801F7A30: nop

    after_1:
    // 0x801F7A34: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7A38: addiu       $a1, $a1, -0x5134
    ctx->r5 = ADD32(ctx->r5, -0X5134);
    // 0x801F7A3C: jal         0x801CC458
    // 0x801F7A40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_2;
    // 0x801F7A40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801F7A44: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7A48: addiu       $a1, $a1, -0x5130
    ctx->r5 = ADD32(ctx->r5, -0X5130);
    // 0x801F7A4C: jal         0x801CC4C0
    // 0x801F7A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CC4C0)(rdram, ctx);
        goto after_3;
    // 0x801F7A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801F7A54: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7A58: addiu       $a1, $a1, 0xA60
    ctx->r5 = ADD32(ctx->r5, 0XA60);
    // 0x801F7A5C: jal         0x801C2420
    // 0x801F7A60: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_4;
    // 0x801F7A60: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_4:
    // 0x801F7A64: jal         0x801CC318
    // 0x801F7A68: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_5;
    // 0x801F7A68: nop

    after_5:
    // 0x801F7A6C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7A70: addiu       $a1, $a1, -0x50E8
    ctx->r5 = ADD32(ctx->r5, -0X50E8);
    // 0x801F7A74: jal         0x801CC458
    // 0x801F7A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_6;
    // 0x801F7A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x801F7A7C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7A80: addiu       $a1, $a1, -0x50E4
    ctx->r5 = ADD32(ctx->r5, -0X50E4);
    // 0x801F7A84: jal         0x801CC4C0
    // 0x801F7A88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CC4C0)(rdram, ctx);
        goto after_7;
    // 0x801F7A88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x801F7A8C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7A90: addiu       $a1, $a1, -0x5028
    ctx->r5 = ADD32(ctx->r5, -0X5028);
    // 0x801F7A94: jal         0x801CC458
    // 0x801F7A98: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_8;
    // 0x801F7A98: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x801F7A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F7AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F7AA8: jr          $ra
    // 0x801F7AAC: nop

    return;
    // 0x801F7AAC: nop

;}
RECOMP_FUNC void M25_FUN_801f7ab0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7ABC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7AC0: jal         0x801CFD28
    // 0x801F7AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CFD28)(rdram, ctx);
        goto after_0;
    // 0x801F7AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801F7AC8: jal         0x801CFD34
    // 0x801F7ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CFD34)(rdram, ctx);
        goto after_1;
    // 0x801F7ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801F7AD0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801F7AD4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7AD8: addiu       $a1, $a1, -0x5148
    ctx->r5 = ADD32(ctx->r5, -0X5148);
    // 0x801F7ADC: jal         0x80005670
    // 0x801F7AE0: lw          $a0, -0x54EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54EC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x801F7AE0: lw          $a0, -0x54EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54EC);
    after_2:
    // 0x801F7AE4: jal         0x801D048C
    // 0x801F7AE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D048C)(rdram, ctx);
        goto after_3;
    // 0x801F7AE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x801F7AEC: jal         0x801D03E0
    // 0x801F7AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D03E0)(rdram, ctx);
        goto after_4;
    // 0x801F7AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x801F7AF4: jal         0x801D03EC
    // 0x801F7AF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D03EC)(rdram, ctx);
        goto after_5;
    // 0x801F7AF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801F7AFC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801F7B00: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801F7B04: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7B08: addiu       $a1, $a1, -0x50FC
    ctx->r5 = ADD32(ctx->r5, -0X50FC);
    // 0x801F7B0C: jal         0x80005670
    // 0x801F7B10: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x801F7B10: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    after_6:
    // 0x801F7B14: jal         0x801D0A68
    // 0x801F7B18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0A68)(rdram, ctx);
        goto after_7;
    // 0x801F7B18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x801F7B1C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801F7B20: lw          $t7, -0x54EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X54EC);
    // 0x801F7B24: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801F7B28: addiu       $a1, $a1, -0x503C
    ctx->r5 = ADD32(ctx->r5, -0X503C);
    // 0x801F7B2C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F7B30: jal         0x80005670
    // 0x801F7B34: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_8;
    // 0x801F7B34: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_8:
    // 0x801F7B38: jal         0x801CC530
    // 0x801F7B3C: nop

    LOOKUP_FUNC(0x801CC530)(rdram, ctx);
        goto after_9;
    // 0x801F7B3C: nop

    after_9:
    // 0x801F7B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F7B48: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F7B4C: jr          $ra
    // 0x801F7B50: nop

    return;
    // 0x801F7B50: nop

;}
RECOMP_FUNC void M25_FUN_801f7b54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7B54: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801F7B58: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7b5c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7b5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7B5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7B60: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F7B64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7B68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F7B6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F7B70: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F7B74: lui         $at, 0xC060
    ctx->r1 = S32(0XC060 << 16);
    // 0x801F7B78: lw          $v0, 0x24($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X24);
    // 0x801F7B7C: beql        $v0, $zero, L_801F7C0C
    if (ctx->r2 == 0) {
        // 0x801F7B80: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801F7C0C;
    }
    goto skip_0;
    // 0x801F7B80: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801F7B84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7B88: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x801F7B8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7B90: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7B94: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801F7B98: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801F7B9C: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x801F7BA0: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F7BA4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F7BA8: ori         $a1, $a1, 0x17
    ctx->r5 = ctx->r5 | 0X17;
    // 0x801F7BAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7BB0: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F7BB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7BB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F7BBC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F7BC0: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x801F7BC4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801F7BC8: lwc1        $f8, -0x2C58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C58);
    // 0x801F7BCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F7BD0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F7BD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F7BD8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F7BDC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F7BE0: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801F7BE4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801F7BE8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801F7BEC: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F7BF0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F7BF4: sh          $t7, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r15;
    // 0x801F7BF8: jal         0x801CC470
    // 0x801F7BFC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801F7BFC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801F7C00: b           L_801F7C0C
    // 0x801F7C04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F7C0C;
    // 0x801F7C04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801F7C08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F7C0C:
    // 0x801F7C0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F7C10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F7C14: jr          $ra
    // 0x801F7C18: nop

    return;
    // 0x801F7C18: nop

;}
RECOMP_FUNC void M25_FUN_801f7c1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7C1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7C20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F7C24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7C28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F7C2C: lui         $a1, 0x2F
    ctx->r5 = S32(0X2F << 16);
    // 0x801F7C30: ori         $a1, $a1, 0x4D60
    ctx->r5 = ctx->r5 | 0X4D60;
    // 0x801F7C34: jal         0x801C0B8C
    // 0x801F7C38: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F7C38: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7C3C: beq         $v0, $zero, L_801F7C6C
    if (ctx->r2 == 0) {
        // 0x801F7C40: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F7C6C;
    }
    // 0x801F7C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7C44: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801F7C48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7C4C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F7C50: ori         $a1, $a1, 0x17
    ctx->r5 = ctx->r5 | 0X17;
    // 0x801F7C54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7C58: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801F7C5C: jal         0x801CC470
    // 0x801F7C60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F7C60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F7C64: b           L_801F7C70
    // 0x801F7C68: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F7C70;
    // 0x801F7C68: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F7C6C:
    // 0x801F7C6C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F7C70:
    // 0x801F7C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F7C74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F7C78: jr          $ra
    // 0x801F7C7C: nop

    return;
    // 0x801F7C7C: nop

;}
RECOMP_FUNC void M25_FUN_801f7c80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7C80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7C88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F7C8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F7C90: jal         0x801BF6B0
    // 0x801F7C94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801F7C94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801F7C98: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801F7C9C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801F7CA0: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x801F7CA4: bne         $at, $zero, L_801F7D48
    if (ctx->r1 != 0) {
        // 0x801F7CA8: nop
    
            goto L_801F7D48;
    }
    // 0x801F7CA8: nop

    // 0x801F7CAC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F7CB0: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F7CB4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F7CB8: lui         $at, 0xC060
    ctx->r1 = S32(0XC060 << 16);
    // 0x801F7CBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7CC0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F7CC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7CC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7CCC: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F7CD0: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F7CD4: ori         $a1, $a1, 0x19
    ctx->r5 = ctx->r5 | 0X19;
    // 0x801F7CD8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F7CDC: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x801F7CE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7CE4: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F7CE8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F7CEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7CF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F7CF4: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F7CF8: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F7CFC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F7D00: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
    // 0x801F7D04: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F7D08: lwc1        $f8, -0x2C54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C54);
    // 0x801F7D0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F7D10: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F7D14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F7D18: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F7D1C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F7D20: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x801F7D24: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F7D28: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F7D2C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F7D30: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F7D34: sh          $t9, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r25;
    // 0x801F7D38: jal         0x801CC470
    // 0x801F7D3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F7D3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F7D40: b           L_801F7D48
    // 0x801F7D44: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F7D48;
    // 0x801F7D44: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F7D48:
    // 0x801F7D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F7D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F7D50: jr          $ra
    // 0x801F7D54: nop

    return;
    // 0x801F7D54: nop

;}
RECOMP_FUNC void M25_FUN_801f7d58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7D58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F7D5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F7D60: jr          $ra
    // 0x801F7D64: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801F7D64: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7d68(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7d68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7D68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F7D6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F7D70: jr          $ra
    // 0x801F7D74: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801F7D74: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7d78(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7d78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7D7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F7D80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7D84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F7D88: lui         $a1, 0x104
    ctx->r5 = S32(0X104 << 16);
    // 0x801F7D8C: ori         $a1, $a1, 0xECDF
    ctx->r5 = ctx->r5 | 0XECDF;
    // 0x801F7D90: jal         0x801C0B8C
    // 0x801F7D94: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F7D94: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7D98: beq         $v0, $zero, L_801F7E38
    if (ctx->r2 == 0) {
        // 0x801F7D9C: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F7E38;
    }
    // 0x801F7D9C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F7DA0: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F7DA4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F7DA8: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x801F7DAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7DB0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F7DB4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7DB8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7DBC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F7DC0: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F7DC4: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x801F7DC8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F7DCC: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801F7DD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7DD4: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801F7DD8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F7DDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7DE0: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801F7DE4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F7DE8: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F7DEC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F7DF0: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801F7DF4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F7DF8: lwc1        $f8, -0x2C50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C50);
    // 0x801F7DFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F7E00: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F7E04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F7E08: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F7E0C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F7E10: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801F7E14: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F7E18: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F7E1C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F7E20: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F7E24: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801F7E28: jal         0x801CC470
    // 0x801F7E2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F7E2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F7E30: b           L_801F7E3C
    // 0x801F7E34: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801F7E3C;
    // 0x801F7E34: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F7E38:
    // 0x801F7E38: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F7E3C:
    // 0x801F7E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F7E40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F7E44: jr          $ra
    // 0x801F7E48: nop

    return;
    // 0x801F7E48: nop

;}
RECOMP_FUNC void M25_FUN_801f7e4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7E4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7E50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7E58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7E5C: lui         $a1, 0x132
    ctx->r5 = S32(0X132 << 16);
    // 0x801F7E60: ori         $a1, $a1, 0xB39F
    ctx->r5 = ctx->r5 | 0XB39F;
    // 0x801F7E64: jal         0x801C0B8C
    // 0x801F7E68: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F7E68: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7E6C: beq         $v0, $zero, L_801F7E7C
    if (ctx->r2 == 0) {
        // 0x801F7E70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F7E7C;
    }
    // 0x801F7E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7E74: b           L_801F7E80
    // 0x801F7E78: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801F7E80;
    // 0x801F7E78: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801F7E7C:
    // 0x801F7E7C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F7E80:
    // 0x801F7E80: jr          $ra
    // 0x801F7E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F7E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f7e88(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f7e88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7E8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F7E90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7E94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F7E98: lui         $a1, 0x160
    ctx->r5 = S32(0X160 << 16);
    // 0x801F7E9C: ori         $a1, $a1, 0x7A5F
    ctx->r5 = ctx->r5 | 0X7A5F;
    // 0x801F7EA0: jal         0x801C0B8C
    // 0x801F7EA4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F7EA4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7EA8: beq         $v0, $zero, L_801F7F48
    if (ctx->r2 == 0) {
        // 0x801F7EAC: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F7F48;
    }
    // 0x801F7EAC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F7EB0: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F7EB4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F7EB8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7EBC: lwc1        $f4, -0x2C4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C4C);
    // 0x801F7EC0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F7EC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7EC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7ECC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F7ED0: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F7ED4: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    // 0x801F7ED8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F7EDC: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801F7EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7EE4: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801F7EE8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F7EEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7EF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F7EF4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F7EF8: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F7EFC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F7F00: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801F7F04: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F7F08: lwc1        $f8, -0x2C48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C48);
    // 0x801F7F0C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F7F10: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F7F14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F7F18: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F7F1C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F7F20: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801F7F24: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F7F28: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F7F2C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F7F30: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F7F34: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801F7F38: jal         0x801CC470
    // 0x801F7F3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F7F3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F7F40: b           L_801F7F4C
    // 0x801F7F44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F7F4C;
    // 0x801F7F44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F7F48:
    // 0x801F7F48: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801F7F4C:
    // 0x801F7F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F7F50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F7F54: jr          $ra
    // 0x801F7F58: nop

    return;
    // 0x801F7F58: nop

;}
RECOMP_FUNC void M25_FUN_801f7f5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7F5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7F60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F7F64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7F68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F7F6C: lui         $a1, 0x17E
    ctx->r5 = S32(0X17E << 16);
    // 0x801F7F70: ori         $a1, $a1, 0xFEDF
    ctx->r5 = ctx->r5 | 0XFEDF;
    // 0x801F7F74: jal         0x801C0B8C
    // 0x801F7F78: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F7F78: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F7F7C: beq         $v0, $zero, L_801F801C
    if (ctx->r2 == 0) {
        // 0x801F7F80: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F801C;
    }
    // 0x801F7F80: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F7F84: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F7F88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F7F8C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801F7F90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7F94: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F7F98: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7F9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F7FA0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F7FA4: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F7FA8: ori         $a1, $a1, 0x22
    ctx->r5 = ctx->r5 | 0X22;
    // 0x801F7FAC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F7FB0: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801F7FB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7FB8: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801F7FBC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F7FC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7FC4: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801F7FC8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F7FCC: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F7FD0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F7FD4: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801F7FD8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F7FDC: lwc1        $f8, -0x2C44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C44);
    // 0x801F7FE0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F7FE4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F7FE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F7FEC: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F7FF0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F7FF4: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801F7FF8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F7FFC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F8000: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F8004: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F8008: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801F800C: jal         0x801CC470
    // 0x801F8010: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8010: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F8014: b           L_801F8020
    // 0x801F8018: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801F8020;
    // 0x801F8018: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F801C:
    // 0x801F801C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F8020:
    // 0x801F8020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8028: jr          $ra
    // 0x801F802C: nop

    return;
    // 0x801F802C: nop

;}
RECOMP_FUNC void M25_FUN_801f8030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F8034: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F8038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F803C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F8040: lui         $a1, 0x1BC
    ctx->r5 = S32(0X1BC << 16);
    // 0x801F8044: ori         $a1, $a1, 0x7DF
    ctx->r5 = ctx->r5 | 0X7DF;
    // 0x801F8048: jal         0x801C0B8C
    // 0x801F804C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F804C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8050: beq         $v0, $zero, L_801F8064
    if (ctx->r2 == 0) {
        // 0x801F8054: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801F8064;
    }
    // 0x801F8054: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8058: sw          $zero, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = 0;
    // 0x801F805C: b           L_801F8068
    // 0x801F8060: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801F8068;
    // 0x801F8060: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F8064:
    // 0x801F8064: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F8068:
    // 0x801F8068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F806C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F8070: jr          $ra
    // 0x801F8074: nop

    return;
    // 0x801F8074: nop

;}
RECOMP_FUNC void M25_FUN_801f8078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8078: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F807C: lw          $v0, -0x4638($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4638);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8080(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8088: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F808C: beq         $v0, $zero, L_801F80A8
    if (ctx->r2 == 0) {
        // 0x801F8090: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801F80A8;
    }
    // 0x801F8090: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8094: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F8098: beq         $v0, $at, L_801F80F0
    if (ctx->r2 == ctx->r1) {
        // 0x801F809C: nop
    
            goto L_801F80F0;
    }
    // 0x801F809C: nop

    // 0x801F80A0: b           L_801F8134
    // 0x801F80A4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801F8134;
    // 0x801F80A4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F80A8:
    // 0x801F80A8: lui         $a1, 0x1F1
    ctx->r5 = S32(0X1F1 << 16);
    // 0x801F80AC: ori         $a1, $a1, 0x6FBF
    ctx->r5 = ctx->r5 | 0X6FBF;
    // 0x801F80B0: jal         0x801C0B8C
    // 0x801F80B4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F80B4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F80B8: beq         $v0, $zero, L_801F8130
    if (ctx->r2 == 0) {
        // 0x801F80BC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F8130;
    }
    // 0x801F80BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F80C0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801F80C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F80C8: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F80CC: ori         $a1, $a1, 0x19
    ctx->r5 = ctx->r5 | 0X19;
    // 0x801F80D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F80D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F80D8: jal         0x801CC4D8
    // 0x801F80DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC4D8)(rdram, ctx);
        goto after_1;
    // 0x801F80DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F80E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F80E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F80E8: b           L_801F8130
    // 0x801F80EC: sw          $t6, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = ctx->r14;
        goto L_801F8130;
    // 0x801F80EC: sw          $t6, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = ctx->r14;
L_801F80F0:
    // 0x801F80F0: jal         0x801CFD40
    // 0x801F80F4: nop

    LOOKUP_FUNC(0x801CFD40)(rdram, ctx);
        goto after_2;
    // 0x801F80F4: nop

    after_2:
    // 0x801F80F8: bne         $v0, $zero, L_801F8130
    if (ctx->r2 != 0) {
        // 0x801F80FC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F8130;
    }
    // 0x801F80FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8100: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801F8104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8108: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F810C: ori         $a1, $a1, 0x19
    ctx->r5 = ctx->r5 | 0X19;
    // 0x801F8110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8114: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8118: jal         0x801CC470
    // 0x801F811C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_3;
    // 0x801F811C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801F8120: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8124: sw          $zero, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = 0;
    // 0x801F8128: b           L_801F8134
    // 0x801F812C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801F8134;
    // 0x801F812C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801F8130:
    // 0x801F8130: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F8134:
    // 0x801F8134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F813C: jr          $ra
    // 0x801F8140: nop

    return;
    // 0x801F8140: nop

;}
RECOMP_FUNC void M25_FUN_801f8144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8144: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F8148: lw          $v0, -0x4638($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4638);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f814c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f814c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F814C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8154: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8158: beq         $v0, $zero, L_801F817C
    if (ctx->r2 == 0) {
        // 0x801F815C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801F817C;
    }
    // 0x801F815C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F8164: beq         $v0, $at, L_801F8234
    if (ctx->r2 == ctx->r1) {
        // 0x801F8168: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801F8234;
    }
    // 0x801F8168: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F816C: beq         $v0, $at, L_801F8274
    if (ctx->r2 == ctx->r1) {
        // 0x801F8170: nop
    
            goto L_801F8274;
    }
    // 0x801F8170: nop

    // 0x801F8174: b           L_801F82B0
    // 0x801F8178: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801F82B0;
    // 0x801F8178: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801F817C:
    // 0x801F817C: lui         $a1, 0x226
    ctx->r5 = S32(0X226 << 16);
    // 0x801F8180: ori         $a1, $a1, 0xD79F
    ctx->r5 = ctx->r5 | 0XD79F;
    // 0x801F8184: jal         0x801C0B8C
    // 0x801F8188: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8188: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F818C: beq         $v0, $zero, L_801F82AC
    if (ctx->r2 == 0) {
        // 0x801F8190: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F82AC;
    }
    // 0x801F8190: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F8194: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F8198: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F819C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F81A0: lwc1        $f4, -0x2C40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C40);
    // 0x801F81A4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F81A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F81AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F81B0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F81B4: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F81B8: ori         $a1, $a1, 0x2F
    ctx->r5 = ctx->r5 | 0X2F;
    // 0x801F81BC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F81C0: addiu       $t8, $zero, 0xC71
    ctx->r24 = ADD32(0, 0XC71);
    // 0x801F81C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F81C8: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801F81CC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F81D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F81D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F81D8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F81DC: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F81E0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F81E4: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801F81E8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801F81EC: lwc1        $f8, -0x2C3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C3C);
    // 0x801F81F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F81F4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F81F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F81FC: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F8200: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F8204: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801F8208: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801F820C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F8210: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F8214: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F8218: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801F821C: jal         0x801CC470
    // 0x801F8220: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8220: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F8224: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801F8228: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F822C: b           L_801F82AC
    // 0x801F8230: sw          $t3, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = ctx->r11;
        goto L_801F82AC;
    // 0x801F8230: sw          $t3, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = ctx->r11;
L_801F8234:
    // 0x801F8234: jal         0x801CFD50
    // 0x801F8238: nop

    LOOKUP_FUNC(0x801CFD50)(rdram, ctx);
        goto after_2;
    // 0x801F8238: nop

    after_2:
    // 0x801F823C: beq         $v0, $zero, L_801F82AC
    if (ctx->r2 == 0) {
        // 0x801F8240: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F82AC;
    }
    // 0x801F8240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8244: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F824C: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F8250: ori         $a1, $a1, 0x26
    ctx->r5 = ctx->r5 | 0X26;
    // 0x801F8254: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F825C: jal         0x801CC470
    // 0x801F8260: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_3;
    // 0x801F8260: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801F8264: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801F8268: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F826C: b           L_801F82AC
    // 0x801F8270: sw          $t4, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = ctx->r12;
        goto L_801F82AC;
    // 0x801F8270: sw          $t4, -0x4638($at)
    MEM_W(-0X4638, ctx->r1) = ctx->r12;
L_801F8274:
    // 0x801F8274: jal         0x801CFD50
    // 0x801F8278: nop

    LOOKUP_FUNC(0x801CFD50)(rdram, ctx);
        goto after_4;
    // 0x801F8278: nop

    after_4:
    // 0x801F827C: beq         $v0, $zero, L_801F82AC
    if (ctx->r2 == 0) {
        // 0x801F8280: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F82AC;
    }
    // 0x801F8280: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8284: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F8288: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F828C: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F8290: ori         $a1, $a1, 0x26
    ctx->r5 = ctx->r5 | 0X26;
    // 0x801F8294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F829C: jal         0x801CC470
    // 0x801F82A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_5;
    // 0x801F82A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801F82A4: b           L_801F82B0
    // 0x801F82A8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801F82B0;
    // 0x801F82A8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801F82AC:
    // 0x801F82AC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801F82B0:
    // 0x801F82B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F82B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F82B8: jr          $ra
    // 0x801F82BC: nop

    return;
    // 0x801F82BC: nop

;}
RECOMP_FUNC void M25_FUN_801f82c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F82C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F82C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F82C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F82CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F82D0: jal         0x801BF6B0
    // 0x801F82D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801F82D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801F82D8: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801F82DC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x801F82E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F82E4: slti        $at, $t6, 0xC
    ctx->r1 = SIGNED(ctx->r14) < 0XC ? 1 : 0;
    // 0x801F82E8: bne         $at, $zero, L_801F82F8
    if (ctx->r1 != 0) {
        // 0x801F82EC: nop
    
            goto L_801F82F8;
    }
    // 0x801F82EC: nop

    // 0x801F82F0: b           L_801F82F8
    // 0x801F82F4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_801F82F8;
    // 0x801F82F4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801F82F8:
    // 0x801F82F8: jr          $ra
    // 0x801F82FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F82FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8300(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F8304: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F8308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F830C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F8310: lui         $a1, 0x31A
    ctx->r5 = S32(0X31A << 16);
    // 0x801F8314: ori         $a1, $a1, 0xFB9F
    ctx->r5 = ctx->r5 | 0XFB9F;
    // 0x801F8318: jal         0x801C0B8C
    // 0x801F831C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F831C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8320: beq         $v0, $zero, L_801F8330
    if (ctx->r2 == 0) {
        // 0x801F8324: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F8330;
    }
    // 0x801F8324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8328: b           L_801F8334
    // 0x801F832C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_801F8334;
    // 0x801F832C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801F8330:
    // 0x801F8330: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801F8334:
    // 0x801F8334: jr          $ra
    // 0x801F8338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F8338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f833c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f833c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F833C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F8340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F8344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F8348: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F834C: jal         0x801BF6B0
    // 0x801F8350: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801F8350: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801F8354: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801F8358: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x801F835C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8360: slti        $at, $t6, 0xE
    ctx->r1 = SIGNED(ctx->r14) < 0XE ? 1 : 0;
    // 0x801F8364: bne         $at, $zero, L_801F8374
    if (ctx->r1 != 0) {
        // 0x801F8368: nop
    
            goto L_801F8374;
    }
    // 0x801F8368: nop

    // 0x801F836C: b           L_801F8374
    // 0x801F8370: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801F8374;
    // 0x801F8370: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801F8374:
    // 0x801F8374: jr          $ra
    // 0x801F8378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F8378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f837c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f837c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F837C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F8380: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F8384: jr          $ra
    // 0x801F8388: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x801F8388: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f838c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f838c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F838C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8390: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8398: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F839C: lui         $a1, 0x40F
    ctx->r5 = S32(0X40F << 16);
    // 0x801F83A0: ori         $a1, $a1, 0x1FA0
    ctx->r5 = ctx->r5 | 0X1FA0;
    // 0x801F83A4: jal         0x801C0B8C
    // 0x801F83A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F83A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F83AC: beq         $v0, $zero, L_801F844C
    if (ctx->r2 == 0) {
        // 0x801F83B0: lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
            goto L_801F844C;
    }
    // 0x801F83B0: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801F83B4: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801F83B8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801F83BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F83C0: lwc1        $f4, -0x2C38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C38);
    // 0x801F83C4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F83C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801F83CC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801F83D0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F83D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F83D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F83DC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F83E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F83E4: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F83E8: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801F83EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801F83F0: addiu       $t9, $zero, 0x844
    ctx->r25 = ADD32(0, 0X844);
    // 0x801F83F4: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    // 0x801F83F8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F83FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8404: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F8408: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F840C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F8410: swc1        $f14, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f14.u32l;
    // 0x801F8414: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x801F8418: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F841C: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F8420: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F8424: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x801F8428: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801F842C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F8430: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F8434: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F8438: sh          $t9, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r25;
    // 0x801F843C: jal         0x801CC470
    // 0x801F8440: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8440: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801F8444: b           L_801F8534
    // 0x801F8448: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_801F8534;
    // 0x801F8448: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801F844C:
    // 0x801F844C: jal         0x801CFD90
    // 0x801F8450: nop

    LOOKUP_FUNC(0x801CFD90)(rdram, ctx);
        goto after_2;
    // 0x801F8450: nop

    after_2:
    // 0x801F8454: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801F8458: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F845C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801F8460: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801F8464: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F8468: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F846C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801F8470: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801F8474: bc1fl       L_801F8488
    if (!c1cs) {
        // 0x801F8478: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801F8488;
    }
    goto skip_0;
    // 0x801F8478: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x801F847C: b           L_801F8488
    // 0x801F8480: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801F8488;
    // 0x801F8480: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801F8484: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801F8488:
    // 0x801F8488: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x801F848C: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x801F8490: nop

    // 0x801F8494: bc1f        L_801F84B8
    if (!c1cs) {
        // 0x801F8498: nop
    
            goto L_801F84B8;
    }
    // 0x801F8498: nop

    // 0x801F849C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x801F84A0: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F84A4: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F84A8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F84AC: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F84B0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801F84B4: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
L_801F84B8:
    // 0x801F84B8: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801F84BC: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801F84C0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801F84C4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F84C8: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x801F84CC: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F84D0: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801F84D4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F84D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F84DC: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801F84E0: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F84E4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x801F84E8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F84EC: nop

    // 0x801F84F0: bc1fl       L_801F8504
    if (!c1cs) {
        // 0x801F84F4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801F8504;
    }
    goto skip_1;
    // 0x801F84F4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x801F84F8: b           L_801F8504
    // 0x801F84FC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801F8504;
    // 0x801F84FC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801F8500: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801F8504:
    // 0x801F8504: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x801F8508: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x801F850C: nop

    // 0x801F8510: bc1f        L_801F8534
    if (!c1cs) {
        // 0x801F8514: nop
    
            goto L_801F8534;
    }
    // 0x801F8514: nop

    // 0x801F8518: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x801F851C: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x801F8520: lw          $t4, 0x24($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X24);
    // 0x801F8524: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801F8528: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F852C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801F8530: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
L_801F8534:
    // 0x801F8534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F853C: jr          $ra
    // 0x801F8540: nop

    return;
    // 0x801F8540: nop

;}
RECOMP_FUNC void M25_FUN_801f8544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8544: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F8548: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F854C: jr          $ra
    // 0x801F8550: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801F8550: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8554(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8554: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8558: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F855C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8564: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801F8568: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    // 0x801F856C: jal         0x801C0B8C
    // 0x801F8570: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8570: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8574: beq         $v0, $zero, L_801F8600
    if (ctx->r2 == 0) {
        // 0x801F8578: lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
            goto L_801F8600;
    }
    // 0x801F8578: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801F857C: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801F8580: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801F8584: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801F8588: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F858C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8590: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8594: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F8598: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F859C: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x801F85A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F85A4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F85A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F85AC: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801F85B0: swc1        $f2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f2.u32l;
    // 0x801F85B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801F85B8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F85BC: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F85C0: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F85C4: swc1        $f2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f2.u32l;
    // 0x801F85C8: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x801F85CC: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F85D0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F85D4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F85D8: swc1        $f2, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f2.u32l;
    // 0x801F85DC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x801F85E0: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801F85E4: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F85E8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F85EC: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801F85F0: jal         0x801CC470
    // 0x801F85F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F85F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F85F8: b           L_801F86D4
    // 0x801F85FC: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_801F86D4;
    // 0x801F85FC: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801F8600:
    // 0x801F8600: jal         0x801CFD90
    // 0x801F8604: nop

    LOOKUP_FUNC(0x801CFD90)(rdram, ctx);
        goto after_2;
    // 0x801F8604: nop

    after_2:
    // 0x801F8608: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801F860C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801F8610: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F8614: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F8618: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801F861C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F8620: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801F8624: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801F8628: bc1fl       L_801F863C
    if (!c1cs) {
        // 0x801F862C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801F863C;
    }
    goto skip_0;
    // 0x801F862C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x801F8630: b           L_801F863C
    // 0x801F8634: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801F863C;
    // 0x801F8634: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801F8638: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801F863C:
    // 0x801F863C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x801F8640: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x801F8644: nop

    // 0x801F8648: bc1f        L_801F866C
    if (!c1cs) {
        // 0x801F864C: nop
    
            goto L_801F866C;
    }
    // 0x801F864C: nop

    // 0x801F8650: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x801F8654: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F8658: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F865C: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F8660: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F8664: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801F8668: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
L_801F866C:
    // 0x801F866C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801F8670: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801F8674: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801F8678: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F867C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x801F8680: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8684: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F8688: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F868C: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8690: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F8694: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F8698: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x801F869C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F86A0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x801F86A4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801F86A8: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x801F86AC: nop

    // 0x801F86B0: bc1f        L_801F86D4
    if (!c1cs) {
        // 0x801F86B4: nop
    
            goto L_801F86D4;
    }
    // 0x801F86B4: nop

    // 0x801F86B8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801F86BC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F86C0: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F86C4: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801F86C8: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F86CC: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801F86D0: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
L_801F86D4:
    // 0x801F86D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F86D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F86DC: jr          $ra
    // 0x801F86E0: nop

    return;
    // 0x801F86E0: nop

;}
RECOMP_FUNC void M25_FUN_801f86e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F86E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F86E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F86EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F86F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F86F4: lui         $a1, 0x471
    ctx->r5 = S32(0X471 << 16);
    // 0x801F86F8: ori         $a1, $a1, 0x49D5
    ctx->r5 = ctx->r5 | 0X49D5;
    // 0x801F86FC: jal         0x801C0B8C
    // 0x801F8700: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8700: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8704: beq         $v0, $zero, L_801F8730
    if (ctx->r2 == 0) {
        // 0x801F8708: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801F8730;
    }
    // 0x801F8708: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801F870C: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801F8710: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F8714: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8718: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F871C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x801F8720: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F8724: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F8728: b           L_801F8734
    // 0x801F872C: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
        goto L_801F8734;
    // 0x801F872C: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
L_801F8730:
    // 0x801F8730: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801F8734:
    // 0x801F8734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F873C: jr          $ra
    // 0x801F8740: nop

    return;
    // 0x801F8740: nop

;}
RECOMP_FUNC void M25_FUN_801f8744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8744: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F874C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8750: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8754: jal         0x801BF6B0
    // 0x801F8758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801F8758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801F875C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801F8760: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x801F8764: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x801F8768: bne         $at, $zero, L_801F8810
    if (ctx->r1 != 0) {
        // 0x801F876C: nop
    
            goto L_801F8810;
    }
    // 0x801F876C: nop

    // 0x801F8770: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F8774: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F8778: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F877C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8780: lwc1        $f4, -0x2C34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C34);
    // 0x801F8784: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8788: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x801F878C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8790: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F8794: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8798: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F879C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F87A0: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x801F87A4: ori         $a1, $a1, 0x12
    ctx->r5 = ctx->r5 | 0X12;
    // 0x801F87A8: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F87AC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F87B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F87B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F87B8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F87BC: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801F87C0: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F87C4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F87C8: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
    // 0x801F87CC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F87D0: lwc1        $f8, -0x2C30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C30);
    // 0x801F87D4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801F87D8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F87DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F87E0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F87E4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F87E8: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x801F87EC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F87F0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F87F4: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F87F8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F87FC: sh          $t9, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r25;
    // 0x801F8800: jal         0x801CC470
    // 0x801F8804: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8804: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F8808: b           L_801F8810
    // 0x801F880C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_801F8810;
    // 0x801F880C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_801F8810:
    // 0x801F8810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8818: jr          $ra
    // 0x801F881C: nop

    return;
    // 0x801F881C: nop

;}
RECOMP_FUNC void M25_FUN_801f8820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8824: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8828: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F882C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8830: lui         $a1, 0x4EC
    ctx->r5 = S32(0X4EC << 16);
    // 0x801F8834: ori         $a1, $a1, 0xE275
    ctx->r5 = ctx->r5 | 0XE275;
    // 0x801F8838: jal         0x801C0B8C
    // 0x801F883C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F883C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8840: beq         $v0, $zero, L_801F88B4
    if (ctx->r2 == 0) {
        // 0x801F8844: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F88B4;
    }
    // 0x801F8844: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8848: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F884C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8850: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F8854: ori         $a1, $a1, 0x12
    ctx->r5 = ctx->r5 | 0X12;
    // 0x801F8858: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x801F885C: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801F8860: jal         0x801CC470
    // 0x801F8864: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8864: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F8868: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801F886C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8870: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F8874: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x801F8878: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F887C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8884: jal         0x801CC4D8
    // 0x801F8888: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC4D8)(rdram, ctx);
        goto after_2;
    // 0x801F8888: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801F888C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801F8890: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801F8894: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8898: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x801F889C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F88A0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F88A4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F88A8: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F88AC: b           L_801F88B8
    // 0x801F88B0: swc1        $f8, -0x4634($at)
    MEM_W(-0X4634, ctx->r1) = ctx->f8.u32l;
        goto L_801F88B8;
    // 0x801F88B0: swc1        $f8, -0x4634($at)
    MEM_W(-0X4634, ctx->r1) = ctx->f8.u32l;
L_801F88B4:
    // 0x801F88B4: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_801F88B8:
    // 0x801F88B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F88BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F88C0: jr          $ra
    // 0x801F88C4: nop

    return;
    // 0x801F88C4: nop

;}
RECOMP_FUNC void M25_FUN_801f88c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F88C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F88CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F88D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F88D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F88D8: lui         $a1, 0x539
    ctx->r5 = S32(0X539 << 16);
    // 0x801F88DC: ori         $a1, $a1, 0x2DB5
    ctx->r5 = ctx->r5 | 0X2DB5;
    // 0x801F88E0: jal         0x801C0B8C
    // 0x801F88E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F88E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F88E8: beq         $v0, $zero, L_801F8948
    if (ctx->r2 == 0) {
        // 0x801F88EC: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801F8948;
    }
    // 0x801F88EC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801F88F0: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801F88F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F88F8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F88FC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F8900: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F8904: jal         0x801CFD40
    // 0x801F8908: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CFD40)(rdram, ctx);
        goto after_1;
    // 0x801F8908: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    after_1:
    // 0x801F890C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F8910: bne         $v0, $at, L_801F8920
    if (ctx->r2 != ctx->r1) {
        // 0x801F8914: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F8920;
    }
    // 0x801F8914: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8918: b           L_801F89CC
    // 0x801F891C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_801F89CC;
    // 0x801F891C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_801F8920:
    // 0x801F8920: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8924: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8928: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F892C: ori         $a1, $a1, 0x15
    ctx->r5 = ctx->r5 | 0X15;
    // 0x801F8930: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8934: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8938: jal         0x801CC470
    // 0x801F893C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801F893C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801F8940: b           L_801F89CC
    // 0x801F8944: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_801F89CC;
    // 0x801F8944: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801F8948:
    // 0x801F8948: jal         0x801C0B2C
    // 0x801F894C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_3;
    // 0x801F894C: nop

    after_3:
    // 0x801F8950: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801F8954: jal         0x80034C24
    // 0x801F8958: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_4;
    // 0x801F8958: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x801F895C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8960: lwc1        $f8, -0x4634($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4634);
    // 0x801F8964: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8968: ldc1        $f10, -0x2C28($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2C28);
    // 0x801F896C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8970: ldc1        $f18, -0x2C20($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2C20);
    // 0x801F8974: div.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x801F8978: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801F897C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F8980: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F8984: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801F8988: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801F898C: lw          $t0, -0x54EC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X54EC);
    // 0x801F8990: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x801F8994: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F8998: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F899C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F89A0: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x801F89A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F89A8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x801F89AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801F89B0: sub.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d - ctx->f2.d;
    // 0x801F89B4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F89B8: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x801F89BC: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x801F89C0: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801F89C4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F89C8: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
L_801F89CC:
    // 0x801F89CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F89D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F89D4: jr          $ra
    // 0x801F89D8: nop

    return;
    // 0x801F89D8: nop

;}
RECOMP_FUNC void M25_FUN_801f89dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F89DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F89E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F89E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F89E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F89EC: lui         $a1, 0x5A3
    ctx->r5 = S32(0X5A3 << 16);
    // 0x801F89F0: ori         $a1, $a1, 0xFD75
    ctx->r5 = ctx->r5 | 0XFD75;
    // 0x801F89F4: jal         0x801C0B8C
    // 0x801F89F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F89F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F89FC: beq         $v0, $zero, L_801F8A34
    if (ctx->r2 == 0) {
        // 0x801F8A00: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F8A34;
    }
    // 0x801F8A00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8A04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8A08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8A0C: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F8A10: ori         $a1, $a1, 0x16
    ctx->r5 = ctx->r5 | 0X16;
    // 0x801F8A14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8A18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8A1C: jal         0x801CC470
    // 0x801F8A20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8A20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F8A24: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8A28: sw          $zero, -0x4630($at)
    MEM_W(-0X4630, ctx->r1) = 0;
    // 0x801F8A2C: b           L_801F8A38
    // 0x801F8A30: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
        goto L_801F8A38;
    // 0x801F8A30: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_801F8A34:
    // 0x801F8A34: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801F8A38:
    // 0x801F8A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8A3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8A40: jr          $ra
    // 0x801F8A44: nop

    return;
    // 0x801F8A44: nop

;}
RECOMP_FUNC void M25_FUN_801f8a48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8A48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F8A4C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F8A50: jr          $ra
    // 0x801F8A54: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x801F8A54: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8a58(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8a58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8A58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F8A5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F8A60: jr          $ra
    // 0x801F8A64: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x801F8A64: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8a68(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8a68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F8A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F8A70: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x801F8A74: addiu       $a0, $a0, -0x4630
    ctx->r4 = ADD32(ctx->r4, -0X4630);
    // 0x801F8A78: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801F8A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F8A80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F8A84: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x801F8A88: bne         $at, $zero, L_801F8AA0
    if (ctx->r1 != 0) {
        // 0x801F8A8C: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_801F8AA0;
    }
    // 0x801F8A8C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x801F8A90: jal         0x8038D28C
    // 0x801F8A94: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_0;
    // 0x801F8A94: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    after_0:
    // 0x801F8A98: b           L_801F8AA8
    // 0x801F8A9C: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
        goto L_801F8AA8;
    // 0x801F8A9C: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_801F8AA0:
    // 0x801F8AA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801F8AA4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801F8AA8:
    // 0x801F8AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F8AB0: jr          $ra
    // 0x801F8AB4: nop

    return;
    // 0x801F8AB4: nop

;}
RECOMP_FUNC void M25_FUN_801f8ab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F8ABC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F8AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F8AC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F8AC8: lui         $a1, 0x63C
    ctx->r5 = S32(0X63C << 16);
    // 0x801F8ACC: ori         $a1, $a1, 0x93F5
    ctx->r5 = ctx->r5 | 0X93F5;
    // 0x801F8AD0: jal         0x801C0B8C
    // 0x801F8AD4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8AD4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8AD8: beql        $v0, $zero, L_801F8AEC
    if (ctx->r2 == 0) {
        // 0x801F8ADC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F8AEC;
    }
    goto skip_0;
    // 0x801F8ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801F8AE0: jal         0x801CC528
    // 0x801F8AE4: nop

    LOOKUP_FUNC(0x801CC528)(rdram, ctx);
        goto after_1;
    // 0x801F8AE4: nop

    after_1:
    // 0x801F8AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F8AEC:
    // 0x801F8AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F8AF0: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    // 0x801F8AF4: jr          $ra
    // 0x801F8AF8: nop

    return;
    // 0x801F8AF8: nop

;}
RECOMP_FUNC void M25_FUN_801f8afc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8AFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F8B00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F8B04: jr          $ra
    // 0x801F8B08: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x801F8B08: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8b0c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8b0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8B0C: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F8B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F8B14: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F8B18: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F8B1C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F8B20: jal         0x801BF628
    // 0x801F8B24: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F8B24: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801F8B28: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F8B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F8B34: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F8B38: bne         $at, $zero, L_801F8B48
    if (ctx->r1 != 0) {
        // 0x801F8B3C: nop
    
            goto L_801F8B48;
    }
    // 0x801F8B3C: nop

    // 0x801F8B40: b           L_801F8B48
    // 0x801F8B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F8B48;
    // 0x801F8B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F8B48:
    // 0x801F8B48: jr          $ra
    // 0x801F8B4C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F8B4C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8b50(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8b50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8B50: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801F8B54: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8b58(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8b58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8B58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8B5C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F8B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8B64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8B68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8B6C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8B70: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8B74: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8B78: lw          $v0, 0x24($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X24);
    // 0x801F8B7C: beql        $v0, $zero, L_801F8C18
    if (ctx->r2 == 0) {
        // 0x801F8B80: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801F8C18;
    }
    goto skip_0;
    // 0x801F8B80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801F8B84: lwc1        $f4, -0x2C18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C18);
    // 0x801F8B88: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x801F8B8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F8B90: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8B94: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801F8B98: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801F8B9C: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F8BA0: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x801F8BA4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F8BA8: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x801F8BAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F8BB0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F8BB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8BB8: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801F8BBC: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F8BC0: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F8BC4: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
    // 0x801F8BC8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801F8BCC: lwc1        $f8, -0x2C14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C14);
    // 0x801F8BD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F8BD4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F8BD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F8BDC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8BE0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F8BE4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F8BE8: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x801F8BEC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801F8BF0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F8BF4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F8BF8: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F8BFC: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F8C00: sh          $t0, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r8;
    // 0x801F8C04: jal         0x801CC470
    // 0x801F8C08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801F8C08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801F8C0C: b           L_801F8C18
    // 0x801F8C10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F8C18;
    // 0x801F8C10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F8C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F8C18:
    // 0x801F8C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8C1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8C20: jr          $ra
    // 0x801F8C24: nop

    return;
    // 0x801F8C24: nop

;}
RECOMP_FUNC void M25_FUN_801f8c28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8C28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8C2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8C30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8C34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8C38: lui         $a1, 0x160
    ctx->r5 = S32(0X160 << 16);
    // 0x801F8C3C: ori         $a1, $a1, 0x7A5F
    ctx->r5 = ctx->r5 | 0X7A5F;
    // 0x801F8C40: jal         0x801C0B8C
    // 0x801F8C44: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8C44: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8C48: beq         $v0, $zero, L_801F8CF8
    if (ctx->r2 == 0) {
        // 0x801F8C4C: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F8CF8;
    }
    // 0x801F8C4C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F8C50: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F8C54: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F8C58: lui         $at, 0x4184
    ctx->r1 = S32(0X4184 << 16);
    // 0x801F8C5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8C60: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8C64: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F8C68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8C6C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8C70: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F8C74: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x801F8C78: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F8C7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F8C80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8C84: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8C88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8C8C: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F8C90: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F8C94: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F8C98: addiu       $t1, $zero, 0x1800
    ctx->r9 = ADD32(0, 0X1800);
    // 0x801F8C9C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F8CA0: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F8CA4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F8CA8: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801F8CAC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F8CB0: lwc1        $f8, -0x2C10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C10);
    // 0x801F8CB4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8CB8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8CBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F8CC0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8CC4: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F8CC8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8CCC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801F8CD0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F8CD4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F8CD8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F8CDC: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F8CE0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F8CE4: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801F8CE8: jal         0x801CC470
    // 0x801F8CEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8CEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F8CF0: b           L_801F8CFC
    // 0x801F8CF4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F8CFC;
    // 0x801F8CF4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F8CF8:
    // 0x801F8CF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F8CFC:
    // 0x801F8CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8D00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8D04: jr          $ra
    // 0x801F8D08: nop

    return;
    // 0x801F8D08: nop

;}
RECOMP_FUNC void M25_FUN_801f8d0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8D0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8D10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8D14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8D18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8D1C: lui         $a1, 0x17E
    ctx->r5 = S32(0X17E << 16);
    // 0x801F8D20: ori         $a1, $a1, 0xFEDF
    ctx->r5 = ctx->r5 | 0XFEDF;
    // 0x801F8D24: jal         0x801C0B8C
    // 0x801F8D28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8D28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8D2C: beq         $v0, $zero, L_801F8DD4
    if (ctx->r2 == 0) {
        // 0x801F8D30: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F8DD4;
    }
    // 0x801F8D30: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F8D34: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F8D38: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F8D3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F8D40: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8D44: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8D48: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F8D4C: ori         $a1, $a1, 0x23
    ctx->r5 = ctx->r5 | 0X23;
    // 0x801F8D50: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8D54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F8D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8D5C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F8D60: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801F8D64: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8D68: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x801F8D6C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F8D70: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F8D74: addiu       $t1, $zero, 0x1800
    ctx->r9 = ADD32(0, 0X1800);
    // 0x801F8D78: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F8D7C: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F8D80: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F8D84: swc1        $f0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f0.u32l;
    // 0x801F8D88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F8D8C: lwc1        $f4, -0x2C0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C0C);
    // 0x801F8D90: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8D94: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8D98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8D9C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8DA0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F8DA4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8DA8: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    // 0x801F8DAC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F8DB0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F8DB4: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F8DB8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F8DBC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F8DC0: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801F8DC4: jal         0x801CC470
    // 0x801F8DC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8DC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801F8DCC: b           L_801F8DD8
    // 0x801F8DD0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F8DD8;
    // 0x801F8DD0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F8DD4:
    // 0x801F8DD4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F8DD8:
    // 0x801F8DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8DDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8DE0: jr          $ra
    // 0x801F8DE4: nop

    return;
    // 0x801F8DE4: nop

;}
RECOMP_FUNC void M25_FUN_801f8de8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F8DEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F8DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F8DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F8DF8: lui         $a1, 0x1BC
    ctx->r5 = S32(0X1BC << 16);
    // 0x801F8DFC: ori         $a1, $a1, 0x7DF
    ctx->r5 = ctx->r5 | 0X7DF;
    // 0x801F8E00: jal         0x801C0B8C
    // 0x801F8E04: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8E04: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8E08: beq         $v0, $zero, L_801F8E1C
    if (ctx->r2 == 0) {
        // 0x801F8E0C: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801F8E1C;
    }
    // 0x801F8E0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8E10: sw          $zero, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = 0;
    // 0x801F8E14: b           L_801F8E20
    // 0x801F8E18: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F8E20;
    // 0x801F8E18: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F8E1C:
    // 0x801F8E1C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F8E20:
    // 0x801F8E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F8E28: jr          $ra
    // 0x801F8E2C: nop

    return;
    // 0x801F8E2C: nop

;}
RECOMP_FUNC void M25_FUN_801f8e30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8E30: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F8E34: lw          $v0, -0x45B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X45B0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8e38(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8e38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8E38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8E3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8E40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8E44: beq         $v0, $zero, L_801F8E60
    if (ctx->r2 == 0) {
        // 0x801F8E48: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801F8E60;
    }
    // 0x801F8E48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8E4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F8E50: beq         $v0, $at, L_801F8EA8
    if (ctx->r2 == ctx->r1) {
        // 0x801F8E54: nop
    
            goto L_801F8EA8;
    }
    // 0x801F8E54: nop

    // 0x801F8E58: b           L_801F8EEC
    // 0x801F8E5C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F8EEC;
    // 0x801F8E5C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F8E60:
    // 0x801F8E60: lui         $a1, 0x1F1
    ctx->r5 = S32(0X1F1 << 16);
    // 0x801F8E64: ori         $a1, $a1, 0x6FBF
    ctx->r5 = ctx->r5 | 0X6FBF;
    // 0x801F8E68: jal         0x801C0B8C
    // 0x801F8E6C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8E6C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8E70: beq         $v0, $zero, L_801F8EE8
    if (ctx->r2 == 0) {
        // 0x801F8E74: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801F8EE8;
    }
    // 0x801F8E74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F8E78: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801F8E7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8E80: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F8E84: ori         $a1, $a1, 0x1A
    ctx->r5 = ctx->r5 | 0X1A;
    // 0x801F8E88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8E8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8E90: jal         0x801CC4D8
    // 0x801F8E94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC4D8)(rdram, ctx);
        goto after_1;
    // 0x801F8E94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F8E98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F8E9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8EA0: b           L_801F8EE8
    // 0x801F8EA4: sw          $t6, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r14;
        goto L_801F8EE8;
    // 0x801F8EA4: sw          $t6, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r14;
L_801F8EA8:
    // 0x801F8EA8: jal         0x801D03F8
    // 0x801F8EAC: nop

    LOOKUP_FUNC(0x801D03F8)(rdram, ctx);
        goto after_2;
    // 0x801F8EAC: nop

    after_2:
    // 0x801F8EB0: bne         $v0, $zero, L_801F8EE8
    if (ctx->r2 != 0) {
        // 0x801F8EB4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801F8EE8;
    }
    // 0x801F8EB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F8EB8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801F8EBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8EC0: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F8EC4: ori         $a1, $a1, 0x1A
    ctx->r5 = ctx->r5 | 0X1A;
    // 0x801F8EC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8ECC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8ED0: jal         0x801CC470
    // 0x801F8ED4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_3;
    // 0x801F8ED4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801F8ED8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8EDC: sw          $zero, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = 0;
    // 0x801F8EE0: b           L_801F8EEC
    // 0x801F8EE4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F8EEC;
    // 0x801F8EE4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F8EE8:
    // 0x801F8EE8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F8EEC:
    // 0x801F8EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8EF4: jr          $ra
    // 0x801F8EF8: nop

    return;
    // 0x801F8EF8: nop

;}
