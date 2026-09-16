#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_802016d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802016D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802016D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802016D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802016DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802016E0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802016E4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802016E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802016EC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x802016F0: bne         $t7, $zero, L_802017AC
    if (ctx->r15 != 0) {
        // 0x802016F4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802017AC;
    }
    // 0x802016F4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802016F8: jal         0x80005E44
    // 0x802016FC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802016FC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201700: jal         0x80006214
    // 0x80201704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020170C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201710: addiu       $a2, $zero, 0x216
    ctx->r6 = ADD32(0, 0X216);
    // 0x80201714: jal         0x8012C89C
    // 0x80201718: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201718: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x8020171C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201720: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201724: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201728: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020172C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201730: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201734: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201738: lwc1        $f4, -0x6A28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A28);
    // 0x8020173C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201740: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201744: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201748: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020174C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201750: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201754: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201758: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020175C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201760: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201764: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201768: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020176C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201770: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201774: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201778: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020177C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201780: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201784: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201788: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020178C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201790: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201794: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201798: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020179C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802017A0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802017A4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802017A8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802017AC:
    // 0x802017AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802017B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802017B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802017B8: jr          $ra
    // 0x802017BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802017BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802017c0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802017c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802017C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802017C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802017C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802017CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802017D0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802017D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802017D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802017DC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x802017E0: bne         $t7, $zero, L_8020189C
    if (ctx->r15 != 0) {
        // 0x802017E4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020189C;
    }
    // 0x802017E4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802017E8: jal         0x80005E44
    // 0x802017EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802017EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x802017F0: jal         0x80006214
    // 0x802017F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x802017F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802017F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802017FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201800: addiu       $a2, $zero, 0x217
    ctx->r6 = ADD32(0, 0X217);
    // 0x80201804: jal         0x8012C89C
    // 0x80201808: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201808: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8020180C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201810: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201814: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201818: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020181C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201820: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201824: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201828: lwc1        $f4, -0x6A24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A24);
    // 0x8020182C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201830: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201834: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201838: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020183C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201840: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201844: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201848: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020184C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201850: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201854: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201858: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020185C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201860: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201864: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201868: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020186C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201870: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201874: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201878: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020187C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201880: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201884: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201888: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020188C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201890: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201894: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201898: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020189C:
    // 0x8020189C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802018A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802018A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802018A8: jr          $ra
    // 0x802018AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802018AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802018b0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802018b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802018B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802018B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802018B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802018BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802018C0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802018C4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802018C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802018CC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x802018D0: bne         $t7, $zero, L_8020198C
    if (ctx->r15 != 0) {
        // 0x802018D4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020198C;
    }
    // 0x802018D4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802018D8: jal         0x80005E44
    // 0x802018DC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802018DC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x802018E0: jal         0x80006214
    // 0x802018E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x802018E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802018E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802018EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802018F0: addiu       $a2, $zero, 0x217
    ctx->r6 = ADD32(0, 0X217);
    // 0x802018F4: jal         0x8012C89C
    // 0x802018F8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x802018F8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x802018FC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201900: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201904: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201908: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020190C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201910: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201914: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201918: lwc1        $f4, -0x6A20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A20);
    // 0x8020191C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201920: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201924: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201928: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020192C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201930: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201934: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201938: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020193C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201940: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201944: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201948: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020194C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201950: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201954: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201958: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020195C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201960: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201964: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201968: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020196C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201970: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201974: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201978: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020197C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201980: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201984: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201988: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020198C:
    // 0x8020198C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201990: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201994: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201998: jr          $ra
    // 0x8020199C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020199C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802019a0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802019a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802019A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802019A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802019A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802019AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802019B0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802019B4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802019B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802019BC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x802019C0: bne         $t7, $zero, L_80201A7C
    if (ctx->r15 != 0) {
        // 0x802019C4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80201A7C;
    }
    // 0x802019C4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802019C8: jal         0x80005E44
    // 0x802019CC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802019CC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x802019D0: jal         0x80006214
    // 0x802019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x802019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802019D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802019DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802019E0: addiu       $a2, $zero, 0x218
    ctx->r6 = ADD32(0, 0X218);
    // 0x802019E4: jal         0x8012C89C
    // 0x802019E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x802019E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x802019EC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802019F0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x802019F4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x802019F8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x802019FC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201A00: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201A04: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201A08: lwc1        $f4, -0x6A1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A1C);
    // 0x80201A0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201A10: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201A14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201A18: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80201A1C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201A20: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201A24: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201A28: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80201A2C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201A30: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201A34: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201A38: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80201A3C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201A40: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201A44: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201A48: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80201A4C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201A50: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201A54: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201A58: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80201A5C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201A60: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201A64: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201A68: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80201A6C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201A70: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201A74: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201A78: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80201A7C:
    // 0x80201A7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201A80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201A84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201A88: jr          $ra
    // 0x80201A8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80201A8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201a90(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201a90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201A90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201A98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80201A9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201AA0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201AA4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201AA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80201AAC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201AB0: bne         $t7, $zero, L_80201B6C
    if (ctx->r15 != 0) {
        // 0x80201AB4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80201B6C;
    }
    // 0x80201AB4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201AB8: jal         0x80005E44
    // 0x80201ABC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80201ABC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201AC0: jal         0x80006214
    // 0x80201AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80201ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201AD0: addiu       $a2, $zero, 0x218
    ctx->r6 = ADD32(0, 0X218);
    // 0x80201AD4: jal         0x8012C89C
    // 0x80201AD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201AD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80201ADC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201AE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201AE4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201AE8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80201AEC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201AF0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201AF4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201AF8: lwc1        $f4, -0x6A18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A18);
    // 0x80201AFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201B00: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201B08: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80201B0C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201B10: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201B14: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201B18: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80201B1C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201B20: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201B24: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201B28: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80201B2C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201B30: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201B34: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201B38: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80201B3C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201B40: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201B44: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201B48: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80201B4C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201B50: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201B54: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201B58: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80201B5C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201B60: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201B64: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201B68: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80201B6C:
    // 0x80201B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201B70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201B74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201B78: jr          $ra
    // 0x80201B7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80201B7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201b80(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201b80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201B84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201B88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80201B8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201B90: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201B94: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201B98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80201B9C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201BA0: bne         $t7, $zero, L_80201C5C
    if (ctx->r15 != 0) {
        // 0x80201BA4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80201C5C;
    }
    // 0x80201BA4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201BA8: jal         0x80005E44
    // 0x80201BAC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80201BAC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201BB0: jal         0x80006214
    // 0x80201BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80201BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201BC0: addiu       $a2, $zero, 0x218
    ctx->r6 = ADD32(0, 0X218);
    // 0x80201BC4: jal         0x8012C89C
    // 0x80201BC8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201BC8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80201BCC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201BD0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201BD4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201BD8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80201BDC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201BE0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201BE4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201BE8: lwc1        $f4, -0x6A14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A14);
    // 0x80201BEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201BF0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201BF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201BF8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80201BFC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201C00: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201C04: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201C08: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80201C0C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201C10: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201C14: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201C18: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80201C1C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201C20: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201C24: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201C28: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80201C2C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201C30: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201C34: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201C38: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80201C3C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201C40: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201C44: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201C48: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80201C4C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201C50: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201C54: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201C58: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80201C5C:
    // 0x80201C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201C60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201C64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201C68: jr          $ra
    // 0x80201C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80201C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201c70(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201c70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201C70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201C74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201C78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80201C7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201C80: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201C84: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201C88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80201C8C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201C90: bne         $t7, $zero, L_80201D4C
    if (ctx->r15 != 0) {
        // 0x80201C94: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80201D4C;
    }
    // 0x80201C94: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201C98: jal         0x80005E44
    // 0x80201C9C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80201C9C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201CA0: jal         0x80006214
    // 0x80201CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80201CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201CB0: addiu       $a2, $zero, 0x21B
    ctx->r6 = ADD32(0, 0X21B);
    // 0x80201CB4: jal         0x8012C89C
    // 0x80201CB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201CB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80201CBC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201CC0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201CC4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201CC8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80201CCC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201CD0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201CD4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201CD8: lwc1        $f4, -0x6A10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A10);
    // 0x80201CDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201CE0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201CE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201CE8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80201CEC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201CF0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201CF4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201CF8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80201CFC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201D00: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201D04: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201D08: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80201D0C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201D10: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201D14: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201D18: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80201D1C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201D20: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201D24: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201D28: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80201D2C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201D30: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201D34: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201D38: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80201D3C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201D40: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201D44: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201D48: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80201D4C:
    // 0x80201D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201D50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201D54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201D58: jr          $ra
    // 0x80201D5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80201D5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201d60(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201d60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201D60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201D64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201D68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80201D6C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80201D70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80201D74: lwc1        $f14, 0x94($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80201D78: lwc1        $f0, 0x98($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80201D7C: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80201D80: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80201D84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80201D88: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80201D8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80201D90: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80201D94: jal         0x8010843C
    // 0x80201D98: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_0;
    // 0x80201D98: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80201D9C: beq         $v0, $zero, L_80201DB0
    if (ctx->r2 == 0) {
        // 0x80201DA0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80201DB0;
    }
    // 0x80201DA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80201DA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80201DA8: lwc1        $f8, -0x408C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X408C);
    // 0x80201DAC: swc1        $f8, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f8.u32l;
L_80201DB0:
    // 0x80201DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80201DB8: jr          $ra
    // 0x80201DBC: nop

    return;
    // 0x80201DBC: nop

;}
RECOMP_FUNC void M9_FUN_80201dc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201DC0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80201DC4: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201DC8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80201DCC: jr          $ra
    // 0x80201DD0: sh          $t7, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r15;
    return;
    // 0x80201DD0: sh          $t7, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201dd4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201dd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201DD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80201DD8: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201DDC: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80201DE0: jr          $ra
    // 0x80201DE4: sh          $t7, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r15;
    return;
    // 0x80201DE4: sh          $t7, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201de8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201de8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201DE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80201DEC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80201DF0: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80201DF4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80201DF8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201DFC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80201E00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80201E04: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x80201E08: lwc1        $f6, 0x94($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80201E0C: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80201E10: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80201E14: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80201E18: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80201E1C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80201E20: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x80201E24: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80201E28: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80201E2C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201E30: jr          $ra
    // 0x80201E34: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    return;
    // 0x80201E34: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201e38(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201e38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201E38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80201E3C: jr          $ra
    // 0x80201E40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80201E40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201e44(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201e44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201E44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80201E48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80201E4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80201E50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80201E54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80201E58: lw          $a2, 0x98($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X98);
    // 0x80201E5C: lwc1        $f14, 0x94($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80201E60: jal         0x801FD5BC
    // 0x80201E64: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    LOOKUP_FUNC(0x801FD5BC)(rdram, ctx);
        goto after_0;
    // 0x80201E64: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    after_0:
    // 0x80201E68: beql        $v0, $zero, L_80201E8C
    if (ctx->r2 == 0) {
        // 0x80201E6C: lhu         $t6, 0xA8($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0XA8);
            goto L_80201E8C;
    }
    goto skip_0;
    // 0x80201E6C: lhu         $t6, 0xA8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XA8);
    skip_0:
    // 0x80201E70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80201E74: nop

    // 0x80201E78: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80201E7C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80201E80: b           L_80201F60
    // 0x80201E84: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_80201F60;
    // 0x80201E84: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80201E88: lhu         $t6, 0xA8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XA8);
L_80201E8C:
    // 0x80201E8C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80201E90: beql        $t7, $zero, L_80201F38
    if (ctx->r15 == 0) {
        // 0x80201E94: lwc1        $f12, 0x90($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
            goto L_80201F38;
    }
    goto skip_1;
    // 0x80201E94: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    skip_1:
    // 0x80201E98: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80201E9C: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80201EA0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201EA4: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80201EA8: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80201EAC: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201EB0: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201EB4: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    // 0x80201EB8: ldc1        $f10, -0x6A08($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6A08);
    // 0x80201EBC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201EC0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80201EC4: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x80201EC8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80201ECC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80201ED0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80201ED4: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x80201ED8: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80201EDC: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80201EE0: ldc1        $f8, -0x6A00($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6A00);
    // 0x80201EE4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80201EE8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80201EEC: sub.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d - ctx->f8.d;
    // 0x80201EF0: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80201EF4: sub.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d - ctx->f4.d;
    // 0x80201EF8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80201EFC: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80201F00: jal         0x8010843C
    // 0x80201F04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_1;
    // 0x80201F04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80201F08: beq         $v0, $zero, L_80201F34
    if (ctx->r2 == 0) {
        // 0x80201F0C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80201F34;
    }
    // 0x80201F0C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80201F10: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80201F14: lbu         $t8, 0x35A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X35A);
    // 0x80201F18: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80201F1C: beql        $t8, $at, L_80201F38
    if (ctx->r24 == ctx->r1) {
        // 0x80201F20: lwc1        $f12, 0x90($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
            goto L_80201F38;
    }
    goto skip_2;
    // 0x80201F20: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    skip_2:
    // 0x80201F24: lwc1        $f6, 0x384($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X384);
    // 0x80201F28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80201F2C: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    // 0x80201F30: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
L_80201F34:
    // 0x80201F34: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
L_80201F38:
    // 0x80201F38: lwc1        $f14, 0x94($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80201F3C: jal         0x801FD5BC
    // 0x80201F40: lw          $a2, 0x98($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X98);
    LOOKUP_FUNC(0x801FD5BC)(rdram, ctx);
        goto after_2;
    // 0x80201F40: lw          $a2, 0x98($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X98);
    after_2:
    // 0x80201F44: beql        $v0, $zero, L_80201F64
    if (ctx->r2 == 0) {
        // 0x80201F48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80201F64;
    }
    goto skip_3;
    // 0x80201F48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80201F4C: lhu         $t9, 0xA8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XA8);
    // 0x80201F50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80201F54: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80201F58: sh          $t0, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r8;
    // 0x80201F5C: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_80201F60:
    // 0x80201F60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80201F64:
    // 0x80201F64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80201F68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80201F6C: jr          $ra
    // 0x80201F70: nop

    return;
    // 0x80201F70: nop

;}
RECOMP_FUNC void M9_FUN_80201f74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201F74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80201F78: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80201F7C: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x80201F80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80201F84: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80201F88: addiu       $s2, $s2, 0x4F40
    ctx->r18 = ADD32(ctx->r18, 0X4F40);
    // 0x80201F8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80201F90: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80201F94: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80201F98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80201F9C: jal         0x80005E44
    // 0x80201FA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80201FA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80201FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80201FA8: jal         0x80005E44
    // 0x80201FAC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80201FAC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80201FB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80201FB4: jal         0x80005E44
    // 0x80201FB8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x80201FB8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80201FBC: jal         0x80006214
    // 0x80201FC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80201FC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80201FC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80201FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201FCC: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x80201FD0: jal         0x8012C89C
    // 0x80201FD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x80201FD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80201FD8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80201FDC: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x80201FE0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80201FE4: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x80201FE8: jal         0x8000C3B0
    // 0x80201FEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_5;
    // 0x80201FEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80201FF0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80201FF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80201FF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80201FFC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80202000: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80202004: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x80202008: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x8020200C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80202010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80202018: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8020201C: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x80202020: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80202024: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80202028: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8020202C: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x80202030: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80202034: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80202038: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8020203C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80202040: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80202044: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80202048: lwc1        $f6, 0x90($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X90);
    // 0x8020204C: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80202050: swc1        $f6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f6.u32l;
    // 0x80202054: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80202058: lwc1        $f8, 0x94($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X94);
    // 0x8020205C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80202060: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
    // 0x80202064: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80202068: lwc1        $f10, 0x98($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X98);
    // 0x8020206C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80202070: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x80202074: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80202078: lh          $t2, 0x9C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X9C);
    // 0x8020207C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80202080: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    // 0x80202084: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80202088: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x8020208C: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80202090: ori         $t6, $t7, 0x400
    ctx->r14 = ctx->r15 | 0X400;
    // 0x80202094: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x80202098: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8020209C: lbu         $t8, 0xF32($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XF32);
    // 0x802020A0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x802020A4: sb          $t8, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r24;
    // 0x802020A8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x802020AC: lbu         $t1, 0xF33($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XF33);
    // 0x802020B0: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x802020B4: sb          $t1, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = ctx->r9;
    // 0x802020B8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802020BC: lbu         $t4, 0xF34($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XF34);
    // 0x802020C0: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x802020C4: sb          $t4, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r12;
    // 0x802020C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802020CC: lbu         $t6, 0xF35($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XF35);
    // 0x802020D0: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802020D4: jal         0x8012C89C
    // 0x802020D8: sb          $t6, 0x4F($t8)
    MEM_B(0X4F, ctx->r24) = ctx->r14;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x802020D8: sb          $t6, 0x4F($t8)
    MEM_B(0X4F, ctx->r24) = ctx->r14;
    after_6:
    // 0x802020DC: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x802020E0: addiu       $t0, $zero, 0x13
    ctx->r8 = ADD32(0, 0X13);
    // 0x802020E4: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x802020E8: sw          $t0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r8;
    // 0x802020EC: jal         0x8000C3B0
    // 0x802020F0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_7;
    // 0x802020F0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x802020F4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x802020F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x802020FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80202100: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x80202104: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x80202108: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8020210C: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80202110: swc1        $f16, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f16.u32l;
    // 0x80202114: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80202118: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x8020211C: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80202120: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80202124: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80202128: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x8020212C: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x80202130: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    // 0x80202134: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x80202138: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8020213C: jal         0x8001EAD0
    // 0x80202140: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x80202140: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_8:
    // 0x80202144: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80202148: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8020214C: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x80202150: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80202154: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80202158: lw          $t0, 0x30($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X30);
    // 0x8020215C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80202160: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x80202164: lwc1        $f8, 0x94($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80202168: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8020216C: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80202170: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80202174: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x80202178: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    // 0x8020217C: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x80202180: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80202184: jal         0x8001EB64
    // 0x80202188: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x80202188: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_9:
    // 0x8020218C: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80202190: lwc1        $f18, 0x98($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80202194: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80202198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8020219C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x802021A0: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x802021A4: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x802021A8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x802021AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x802021B0: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x802021B4: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x802021B8: lh          $t7, 0x9C($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X9C);
    // 0x802021BC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802021C0: addiu       $t8, $t7, 0x800
    ctx->r24 = ADD32(ctx->r15, 0X800);
    // 0x802021C4: andi        $t3, $t8, 0x1FFF
    ctx->r11 = ctx->r24 & 0X1FFF;
    // 0x802021C8: sh          $t3, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r11;
    // 0x802021CC: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x802021D0: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x802021D4: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    // 0x802021D8: ori         $t4, $t5, 0x400
    ctx->r12 = ctx->r13 | 0X400;
    // 0x802021DC: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x802021E0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x802021E4: lbu         $t7, 0xF32($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XF32);
    // 0x802021E8: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x802021EC: sb          $t7, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r15;
    // 0x802021F0: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x802021F4: lbu         $t8, 0xF33($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XF33);
    // 0x802021F8: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x802021FC: sb          $t8, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r24;
    // 0x80202200: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80202204: lbu         $t1, 0xF34($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XF34);
    // 0x80202208: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x8020220C: sb          $t1, 0x4E($t5)
    MEM_B(0X4E, ctx->r13) = ctx->r9;
    // 0x80202210: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80202214: lbu         $t4, 0xF35($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XF35);
    // 0x80202218: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x8020221C: jal         0x8012C89C
    // 0x80202220: sb          $t4, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r12;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_10;
    // 0x80202220: sb          $t4, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r12;
    after_10:
    // 0x80202224: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80202228: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x8020222C: lw          $t8, 0x30($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X30);
    // 0x80202230: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x80202234: jal         0x8000C3B0
    // 0x80202238: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_11;
    // 0x80202238: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_11:
    // 0x8020223C: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x80202240: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80202244: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80202248: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x8020224C: sw          $v0, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r2;
    // 0x80202250: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80202254: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x80202258: swc1        $f6, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f6.u32l;
    // 0x8020225C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80202260: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80202264: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80202268: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x8020226C: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80202270: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80202274: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x80202278: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    // 0x8020227C: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x80202280: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80202284: jal         0x8001EAD0
    // 0x80202288: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x80202288: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_12:
    // 0x8020228C: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80202290: lwc1        $f10, 0x90($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X90);
    // 0x80202294: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80202298: lw          $t6, 0x30($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X30);
    // 0x8020229C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802022A0: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x802022A4: lwc1        $f18, 0x94($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X94);
    // 0x802022A8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x802022AC: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x802022B0: lw          $t3, 0x30($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X30);
    // 0x802022B4: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x802022B8: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    // 0x802022BC: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x802022C0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802022C4: jal         0x8001EB64
    // 0x802022C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_13;
    // 0x802022C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_13:
    // 0x802022CC: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x802022D0: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x802022D4: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x802022D8: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    // 0x802022DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x802022E0: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x802022E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x802022E8: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x802022EC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x802022F0: lh          $t5, 0x9C($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X9C);
    // 0x802022F4: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x802022F8: addiu       $t7, $t5, -0x800
    ctx->r15 = ADD32(ctx->r13, -0X800);
    // 0x802022FC: andi        $t0, $t7, 0x1FFF
    ctx->r8 = ctx->r15 & 0X1FFF;
    // 0x80202300: sh          $t0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r8;
    // 0x80202304: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x80202308: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x8020230C: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    // 0x80202310: ori         $t1, $t2, 0x400
    ctx->r9 = ctx->r10 | 0X400;
    // 0x80202314: sw          $t1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r9;
    // 0x80202318: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8020231C: lbu         $t5, 0xF32($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XF32);
    // 0x80202320: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x80202324: sb          $t5, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r13;
    // 0x80202328: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8020232C: lbu         $t7, 0xF33($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XF33);
    // 0x80202330: lw          $t0, 0x30($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X30);
    // 0x80202334: sb          $t7, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r15;
    // 0x80202338: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x8020233C: lbu         $t8, 0xF34($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XF34);
    // 0x80202340: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x80202344: sb          $t8, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r24;
    // 0x80202348: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8020234C: lbu         $t1, 0xF35($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XF35);
    // 0x80202350: lw          $t5, 0x30($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X30);
    // 0x80202354: sb          $t1, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r9;
    // 0x80202358: lw          $t4, 0x2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2C);
    // 0x8020235C: ori         $t6, $t4, 0x800
    ctx->r14 = ctx->r12 | 0X800;
    // 0x80202360: jal         0x8012C97C
    // 0x80202364: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_14;
    // 0x80202364: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    after_14:
    // 0x80202368: lw          $t7, 0xA4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XA4);
    // 0x8020236C: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x80202370: lbu         $t0, 0x0($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X0);
    // 0x80202374: andi        $t3, $t0, 0x8
    ctx->r11 = ctx->r8 & 0X8;
    // 0x80202378: beql        $t3, $zero, L_802023F0
    if (ctx->r11 == 0) {
        // 0x8020237C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_802023F0;
    }
    goto skip_0;
    // 0x8020237C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80202380: lwc1        $f16, 0x94($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80202384: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80202388: ldc1        $f0, -0x69F8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X69F8);
    // 0x8020238C: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80202390: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80202394: sb          $t8, 0x9E($s1)
    MEM_B(0X9E, ctx->r17) = ctx->r24;
    // 0x80202398: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8020239C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802023A0: addiu       $v0, $zero, 0xE38
    ctx->r2 = ADD32(0, 0XE38);
    // 0x802023A4: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x802023A8: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x802023AC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x802023B0: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
    // 0x802023B4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x802023B8: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x802023BC: sh          $v0, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r2;
    // 0x802023C0: lwc1        $f10, 0x94($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X94);
    // 0x802023C4: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x802023C8: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x802023CC: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x802023D0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802023D4: add.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d + ctx->f0.d;
    // 0x802023D8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x802023DC: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x802023E0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x802023E4: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x802023E8: sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // 0x802023EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_802023F0:
    // 0x802023F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x802023F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x802023F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x802023FC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80202400: jr          $ra
    // 0x80202404: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80202404: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80202408(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80202408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80202408: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8020240C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80202410: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80202414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80202418: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020241C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80202420: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80202424: jal         0x80005E44
    // 0x80202428: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80202428: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x8020242C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80202430: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80202434: jal         0x80005E44
    // 0x80202438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80202438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8020243C: jal         0x80006214
    // 0x80202440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80202440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80202444: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8020244C: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x80202450: jal         0x8012C89C
    // 0x80202454: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80202454: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80202458: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8020245C: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x80202460: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80202464: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x80202468: jal         0x8000C3B0
    // 0x8020246C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_4;
    // 0x8020246C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80202470: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80202474: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80202478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8020247C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80202480: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80202484: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80202488: sw          $v0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r2;
    // 0x8020248C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80202490: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80202498: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8020249C: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x802024A0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x802024A4: swc1        $f4, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f4.u32l;
    // 0x802024A8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x802024AC: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x802024B0: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x802024B4: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x802024B8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802024BC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x802024C0: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x802024C4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x802024C8: lwc1        $f6, 0x90($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X90);
    // 0x802024CC: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x802024D0: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x802024D4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802024D8: lwc1        $f8, 0x94($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X94);
    // 0x802024DC: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x802024E0: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x802024E4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802024E8: lwc1        $f10, 0x98($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X98);
    // 0x802024EC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802024F0: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
    // 0x802024F4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802024F8: lh          $t4, 0x9C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X9C);
    // 0x802024FC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80202500: sh          $t4, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r12;
    // 0x80202504: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80202508: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x8020250C: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80202510: ori         $t9, $t8, 0x400
    ctx->r25 = ctx->r24 | 0X400;
    // 0x80202514: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x80202518: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8020251C: lbu         $t1, 0xF32($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XF32);
    // 0x80202520: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80202524: sb          $t1, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r9;
    // 0x80202528: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8020252C: lbu         $t5, 0xF33($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XF33);
    // 0x80202530: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80202534: sb          $t5, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r13;
    // 0x80202538: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8020253C: lbu         $t6, 0xF34($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XF34);
    // 0x80202540: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80202544: sb          $t6, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r14;
    // 0x80202548: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8020254C: lbu         $t2, 0xF35($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XF35);
    // 0x80202550: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80202554: jal         0x8012C89C
    // 0x80202558: sb          $t2, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x80202558: sb          $t2, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r10;
    after_5:
    // 0x8020255C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80202560: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
    // 0x80202564: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80202568: sw          $t4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r12;
    // 0x8020256C: jal         0x8000C3B0
    // 0x80202570: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_6;
    // 0x80202570: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x80202574: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80202578: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8020257C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80202580: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x80202584: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80202588: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x8020258C: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x80202590: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80202594: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    // 0x80202598: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8020259C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x802025A0: swc1        $f16, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f16.u32l;
    // 0x802025A4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x802025A8: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x802025AC: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x802025B0: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x802025B4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x802025B8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x802025BC: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802025C0: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x802025C4: lwc1        $f18, 0x90($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X90);
    // 0x802025C8: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x802025CC: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x802025D0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x802025D4: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x802025D8: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x802025DC: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x802025E0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x802025E4: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x802025E8: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x802025EC: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x802025F0: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x802025F4: lh          $t2, 0x9C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X9C);
    // 0x802025F8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x802025FC: sh          $t2, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r10;
    // 0x80202600: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80202604: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x80202608: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x8020260C: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x80202610: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x80202614: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80202618: lbu         $t6, 0xF32($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XF32);
    // 0x8020261C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80202620: sb          $t6, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r14;
    // 0x80202624: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80202628: lbu         $t3, 0xF33($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XF33);
    // 0x8020262C: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x80202630: sb          $t3, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r11;
    // 0x80202634: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80202638: lbu         $t4, 0xF34($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XF34);
    // 0x8020263C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80202640: sb          $t4, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r12;
    // 0x80202644: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80202648: lbu         $t9, 0xF35($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XF35);
    // 0x8020264C: lw          $t1, 0x30($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X30);
    // 0x80202650: sb          $t9, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r25;
    // 0x80202654: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x80202658: ori         $t3, $t2, 0x800
    ctx->r11 = ctx->r10 | 0X800;
    // 0x8020265C: jal         0x8012C97C
    // 0x80202660: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_7;
    // 0x80202660: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    after_7:
    // 0x80202664: lw          $t5, 0xA4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XA4);
    // 0x80202668: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x8020266C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80202670: lbu         $t7, 0x0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X0);
    // 0x80202674: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80202678: andi        $t4, $t7, 0x8
    ctx->r12 = ctx->r15 & 0X8;
    // 0x8020267C: beql        $t4, $zero, L_802026B4
    if (ctx->r12 == 0) {
        // 0x80202680: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_802026B4;
    }
    goto skip_0;
    // 0x80202680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80202684: lwc1        $f8, 0x94($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80202688: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8020268C: sb          $t8, 0x9E($s1)
    MEM_B(0X9E, ctx->r17) = ctx->r24;
    // 0x80202690: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80202694: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80202698: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    // 0x8020269C: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x802026A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x802026A4: jal         0x8012C97C
    // 0x802026A8: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_8;
    // 0x802026A8: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    after_8:
    // 0x802026AC: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x802026B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802026B4:
    // 0x802026B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802026B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802026BC: jr          $ra
    // 0x802026C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802026C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802026c4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802026c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802026C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x802026C8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x802026CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x802026D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x802026D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x802026D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802026DC: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x802026E0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x802026E4: addiu       $s2, $sp, 0x30
    ctx->r18 = ADD32(ctx->r29, 0X30);
    // 0x802026E8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x802026EC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x802026F0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x802026F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x802026F8: ori         $t9, $t9, 0xC00
    ctx->r25 = ctx->r25 | 0XC00;
    // 0x802026FC: sw          $t7, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r15;
    // 0x80202700: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80202704: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80202708: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8020270C: sw          $t8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r24;
    // 0x80202710: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80202714: sw          $t7, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r15;
    // 0x80202718: jal         0x80005E44
    // 0x8020271C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020271C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_0:
    // 0x80202720: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202724: jal         0x80005E44
    // 0x80202728: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80202728: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8020272C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202730: jal         0x80005E44
    // 0x80202734: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x80202734: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80202738: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8020273C: jal         0x80005E44
    // 0x80202740: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_3;
    // 0x80202740: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80202744: jal         0x80006214
    // 0x80202748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x80202748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8020274C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80202754: addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // 0x80202758: jal         0x8012C89C
    // 0x8020275C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x8020275C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_5:
    // 0x80202760: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80202764: addiu       $t0, $zero, 0x13
    ctx->r8 = ADD32(0, 0X13);
    // 0x80202768: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8020276C: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80202770: jal         0x8000C3B0
    // 0x80202774: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_6;
    // 0x80202774: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80202778: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8020277C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80202780: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80202784: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80202788: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8020278C: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x80202790: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
    // 0x80202794: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80202798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8020279C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802027A0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x802027A4: addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // 0x802027A8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x802027AC: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    // 0x802027B0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802027B4: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x802027B8: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x802027BC: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x802027C0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802027C4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x802027C8: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x802027CC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802027D0: lwc1        $f6, 0x90($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X90);
    // 0x802027D4: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x802027D8: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x802027DC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802027E0: lwc1        $f8, 0x94($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X94);
    // 0x802027E4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802027E8: swc1        $f8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
    // 0x802027EC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x802027F0: lwc1        $f10, 0x98($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X98);
    // 0x802027F4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802027F8: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    // 0x802027FC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80202800: lh          $t6, 0x9C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X9C);
    // 0x80202804: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80202808: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x8020280C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80202810: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80202814: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x80202818: ori         $t0, $t1, 0x400
    ctx->r8 = ctx->r9 | 0X400;
    // 0x8020281C: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x80202820: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80202824: lbu         $t2, 0xF32($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XF32);
    // 0x80202828: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8020282C: sb          $t2, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r10;
    // 0x80202830: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80202834: lbu         $t5, 0xF33($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XF33);
    // 0x80202838: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x8020283C: sb          $t5, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r13;
    // 0x80202840: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80202844: lbu         $t8, 0xF34($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XF34);
    // 0x80202848: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x8020284C: sb          $t8, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r24;
    // 0x80202850: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80202854: lbu         $t0, 0xF35($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XF35);
    // 0x80202858: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x8020285C: jal         0x8012C89C
    // 0x80202860: sb          $t0, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r8;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_7;
    // 0x80202860: sb          $t0, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r8;
    after_7:
    // 0x80202864: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80202868: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
    // 0x8020286C: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x80202870: sw          $t4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r12;
    // 0x80202874: jal         0x8000C3B0
    // 0x80202878: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_8;
    // 0x80202878: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x8020287C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80202880: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80202884: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80202888: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x8020288C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202890: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80202894: sw          $v0, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r2;
    // 0x80202898: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8020289C: addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // 0x802028A0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x802028A4: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x802028A8: swc1        $f16, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f16.u32l;
    // 0x802028AC: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x802028B0: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x802028B4: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x802028B8: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x802028BC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x802028C0: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x802028C4: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x802028C8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x802028CC: lwc1        $f18, 0x90($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X90);
    // 0x802028D0: lw          $t4, 0x30($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X30);
    // 0x802028D4: swc1        $f18, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f18.u32l;
    // 0x802028D8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x802028DC: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x802028E0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x802028E4: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x802028E8: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x802028EC: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x802028F0: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802028F4: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x802028F8: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x802028FC: lh          $t1, 0x9C($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X9C);
    // 0x80202900: lw          $t0, 0x30($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X30);
    // 0x80202904: sh          $t1, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r9;
    // 0x80202908: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8020290C: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80202910: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80202914: ori         $t4, $t7, 0x400
    ctx->r12 = ctx->r15 | 0X400;
    // 0x80202918: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x8020291C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80202920: lbu         $t5, 0xF32($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XF32);
    // 0x80202924: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x80202928: sb          $t5, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r13;
    // 0x8020292C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80202930: lbu         $t8, 0xF33($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XF33);
    // 0x80202934: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x80202938: sb          $t8, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r24;
    // 0x8020293C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80202940: lbu         $t0, 0xF34($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XF34);
    // 0x80202944: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    // 0x80202948: sb          $t0, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r8;
    // 0x8020294C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80202950: lbu         $t4, 0xF35($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XF35);
    // 0x80202954: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80202958: jal         0x8012C89C
    // 0x8020295C: sb          $t4, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r12;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_9;
    // 0x8020295C: sb          $t4, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r12;
    after_9:
    // 0x80202960: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80202964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202968: addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // 0x8020296C: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    // 0x80202970: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80202974: jal         0x8012CF8C
    // 0x80202978: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_10;
    // 0x80202978: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_10:
    // 0x8020297C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80202980: addiu       $t3, $zero, 0x13
    ctx->r11 = ADD32(0, 0X13);
    // 0x80202984: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80202988: sw          $t3, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r11;
    // 0x8020298C: jal         0x8000C3B0
    // 0x80202990: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_11;
    // 0x80202990: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_11:
    // 0x80202994: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80202998: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8020299C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x802029A0: lw          $t0, 0x30($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X30);
    // 0x802029A4: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x802029A8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x802029AC: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x802029B0: swc1        $f8, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f8.u32l;
    // 0x802029B4: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x802029B8: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x802029BC: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x802029C0: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x802029C4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x802029C8: lw          $t9, 0x30($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X30);
    // 0x802029CC: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x802029D0: jal         0x8001EAD0
    // 0x802029D4: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x802029D4: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    after_12:
    // 0x802029D8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x802029DC: lwc1        $f10, 0x90($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X90);
    // 0x802029E0: add.d       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f2.d + ctx->f2.d;
    // 0x802029E4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x802029E8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x802029EC: lw          $t3, 0x30($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X30);
    // 0x802029F0: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x802029F4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x802029F8: swc1        $f6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f6.u32l;
    // 0x802029FC: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80202A00: lwc1        $f8, 0x94($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80202A04: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80202A08: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    // 0x80202A0C: jal         0x8001EB64
    // 0x80202A10: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_13;
    // 0x80202A10: lh          $a0, 0x9C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X9C);
    after_13:
    // 0x80202A14: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80202A18: lwc1        $f10, 0x98($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80202A1C: add.d       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f2.d + ctx->f2.d;
    // 0x80202A20: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80202A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80202A28: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80202A2C: lw          $t7, 0x30($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X30);
    // 0x80202A30: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x80202A34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80202A38: addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // 0x80202A3C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80202A40: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80202A44: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x80202A48: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80202A4C: lh          $t6, 0x9C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X9C);
    // 0x80202A50: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80202A54: sh          $t6, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r14;
    // 0x80202A58: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80202A5C: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80202A60: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80202A64: ori         $t3, $t8, 0x400
    ctx->r11 = ctx->r24 | 0X400;
    // 0x80202A68: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x80202A6C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80202A70: lbu         $t1, 0xF32($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XF32);
    // 0x80202A74: lw          $t0, 0x30($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X30);
    // 0x80202A78: sb          $t1, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r9;
    // 0x80202A7C: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80202A80: lbu         $t7, 0xF33($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XF33);
    // 0x80202A84: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80202A88: sb          $t7, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r15;
    // 0x80202A8C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80202A90: lbu         $t5, 0xF34($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XF34);
    // 0x80202A94: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80202A98: sb          $t5, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r13;
    // 0x80202A9C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80202AA0: lbu         $t3, 0xF35($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XF35);
    // 0x80202AA4: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80202AA8: jal         0x8012C89C
    // 0x80202AAC: sb          $t3, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r11;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_14;
    // 0x80202AAC: sb          $t3, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r11;
    after_14:
    // 0x80202AB0: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80202AB4: addiu       $t0, $zero, 0x13
    ctx->r8 = ADD32(0, 0X13);
    // 0x80202AB8: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80202ABC: sw          $t0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r8;
    // 0x80202AC0: jal         0x8000C3B0
    // 0x80202AC4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_15;
    // 0x80202AC4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_15:
    // 0x80202AC8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80202ACC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80202AD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80202AD4: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x80202AD8: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    // 0x80202ADC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80202AE0: sw          $v0, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r2;
    // 0x80202AE4: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80202AE8: lw          $t8, 0x30($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X30);
    // 0x80202AEC: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
    // 0x80202AF0: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80202AF4: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80202AF8: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80202AFC: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80202B00: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x80202B04: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x80202B08: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x80202B0C: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80202B10: lwc1        $f10, 0x90($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X90);
    // 0x80202B14: lw          $t0, 0x30($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X30);
    // 0x80202B18: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x80202B1C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80202B20: lwc1        $f16, 0x94($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80202B24: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80202B28: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x80202B2C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80202B30: lwc1        $f18, 0x98($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80202B34: lw          $t5, 0x30($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X30);
    // 0x80202B38: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    // 0x80202B3C: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80202B40: lh          $t8, 0x9C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X9C);
    // 0x80202B44: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80202B48: sh          $t8, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r24;
    // 0x80202B4C: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80202B50: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x80202B54: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
    // 0x80202B58: ori         $t0, $t4, 0x400
    ctx->r8 = ctx->r12 | 0X400;
    // 0x80202B5C: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x80202B60: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80202B64: lbu         $t7, 0xF32($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XF32);
    // 0x80202B68: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x80202B6C: sb          $t7, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r15;
    // 0x80202B70: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80202B74: lbu         $t5, 0xF33($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XF33);
    // 0x80202B78: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x80202B7C: sb          $t5, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r13;
    // 0x80202B80: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80202B84: lbu         $t3, 0xF34($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XF34);
    // 0x80202B88: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x80202B8C: sb          $t3, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r11;
    // 0x80202B90: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80202B94: lbu         $t0, 0xF35($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XF35);
    // 0x80202B98: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80202B9C: sb          $t0, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r8;
    // 0x80202BA0: lw          $t9, 0x2C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X2C);
    // 0x80202BA4: ori         $t2, $t9, 0x800
    ctx->r10 = ctx->r25 | 0X800;
    // 0x80202BA8: jal         0x8012C97C
    // 0x80202BAC: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_16;
    // 0x80202BAC: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    after_16:
    // 0x80202BB0: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x80202BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80202BB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80202BBC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80202BC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80202BC4: jr          $ra
    // 0x80202BC8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80202BC8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80202bcc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80202bcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80202BCC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80202BD0: lwc1        $f4, -0x69F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X69F0);
    // 0x80202BD4: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    // 0x80202BD8: jr          $ra
    // 0x80202BDC: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80202BDC: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80202be0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80202be0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80202BE0: jr          $ra
    // 0x80202BE4: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    return;
    // 0x80202BE4: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80202be8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80202be8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80202BE8: jr          $ra
    // 0x80202BEC: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    return;
    // 0x80202BEC: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80202bf0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80202bf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80202BF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80202BF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80202BF8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80202BFC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80202C00: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x80202C04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80202C08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80202C0C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80202C10: lbu         $v0, 0x9E($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9E);
    // 0x80202C14: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80202C18: beq         $v0, $at, L_80202C40
    if (ctx->r2 == ctx->r1) {
        // 0x80202C1C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80202C40;
    }
    // 0x80202C1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80202C20: beq         $v0, $at, L_80202DE8
    if (ctx->r2 == ctx->r1) {
        // 0x80202C24: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80202DE8;
    }
    // 0x80202C24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80202C28: beq         $v0, $at, L_80202D1C
    if (ctx->r2 == ctx->r1) {
        // 0x80202C2C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80202D1C;
    }
    // 0x80202C2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80202C30: beql        $v0, $at, L_80202EA4
    if (ctx->r2 == ctx->r1) {
        // 0x80202C34: lw          $t0, 0x4($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X4);
            goto L_80202EA4;
    }
    goto skip_0;
    // 0x80202C34: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x80202C38: b           L_80202F3C
    // 0x80202C3C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
        goto L_80202F3C;
    // 0x80202C3C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_80202C40:
    // 0x80202C40: lh          $a0, 0xA2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA2);
    // 0x80202C44: sltiu       $v0, $a0, 0x1
    ctx->r2 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x80202C48: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x80202C4C: beq         $v0, $zero, L_80202C5C
    if (ctx->r2 == 0) {
        // 0x80202C50: sh          $t7, 0xA2($s0)
        MEM_H(0XA2, ctx->r16) = ctx->r15;
            goto L_80202C5C;
    }
    // 0x80202C50: sh          $t7, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r15;
    // 0x80202C54: jal         0x80020718
    // 0x80202C58: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x80202C58: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    after_0:
L_80202C5C:
    // 0x80202C5C: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80202C60: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80202C64: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80202C68: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x80202C6C: ldc1        $f2, -0x69E8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X69E8);
    // 0x80202C70: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80202C74: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80202C78: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80202C7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80202C80: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80202C84: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80202C88: lwc1        $f18, 0xAC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80202C8C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80202C90: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80202C94: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80202C98: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80202C9C: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80202CA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80202CA4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80202CA8: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80202CAC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80202CB0: swc1        $f18, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f18.u32l;
    // 0x80202CB4: lwc1        $f0, 0xAC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80202CB8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80202CBC: nop

    // 0x80202CC0: bc1fl       L_80202CE8
    if (!c1cs) {
        // 0x80202CC4: cvt.d.s     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
            goto L_80202CE8;
    }
    goto skip_1;
    // 0x80202CC4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    skip_1:
    // 0x80202CC8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80202CCC: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x80202CD0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80202CD4: swc1        $f10, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f10.u32l;
    // 0x80202CD8: lwc1        $f12, 0xAC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80202CDC: b           L_80202CF8
    // 0x80202CE0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80202CF8;
    // 0x80202CE0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80202CE4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
L_80202CE8:
    // 0x80202CE8: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80202CEC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80202CF0: swc1        $f6, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f6.u32l;
    // 0x80202CF4: lwc1        $f12, 0xAC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XAC);
L_80202CF8:
    // 0x80202CF8: ldc1        $f10, -0x69E0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X69E0);
    // 0x80202CFC: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80202D00: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80202D04: nop

    // 0x80202D08: bc1fl       L_80202F3C
    if (!c1cs) {
        // 0x80202D0C: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80202F3C;
    }
    goto skip_2;
    // 0x80202D0C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80202D10: sb          $t0, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = ctx->r8;
    // 0x80202D14: b           L_80202F38
    // 0x80202D18: sh          $zero, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = 0;
        goto L_80202F38;
    // 0x80202D18: sh          $zero, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = 0;
L_80202D1C:
    // 0x80202D1C: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x80202D20: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x80202D24: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80202D28: slti        $at, $a1, 0x471
    ctx->r1 = SIGNED(ctx->r5) < 0X471 ? 1 : 0;
    // 0x80202D2C: beql        $at, $zero, L_80202D50
    if (ctx->r1 == 0) {
        // 0x80202D30: slti        $at, $a1, 0x9C8
        ctx->r1 = SIGNED(ctx->r5) < 0X9C8 ? 1 : 0;
            goto L_80202D50;
    }
    goto skip_3;
    // 0x80202D30: slti        $at, $a1, 0x9C8
    ctx->r1 = SIGNED(ctx->r5) < 0X9C8 ? 1 : 0;
    skip_3:
    // 0x80202D34: lh          $t2, 0xA2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA2);
    // 0x80202D38: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x80202D3C: sh          $t3, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r11;
    // 0x80202D40: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x80202D44: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x80202D48: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80202D4C: slti        $at, $a1, 0x9C8
    ctx->r1 = SIGNED(ctx->r5) < 0X9C8 ? 1 : 0;
L_80202D50:
    // 0x80202D50: bnel        $at, $zero, L_80202D74
    if (ctx->r1 != 0) {
        // 0x80202D54: lh          $t8, 0xA2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0XA2);
            goto L_80202D74;
    }
    goto skip_4;
    // 0x80202D54: lh          $t8, 0xA2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA2);
    skip_4:
    // 0x80202D58: lh          $t5, 0xA2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA2);
    // 0x80202D5C: addiu       $t6, $t5, -0x10
    ctx->r14 = ADD32(ctx->r13, -0X10);
    // 0x80202D60: sh          $t6, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r14;
    // 0x80202D64: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80202D68: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x80202D6C: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80202D70: lh          $t8, 0xA2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA2);
L_80202D74:
    // 0x80202D74: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80202D78: sh          $t9, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r25;
    // 0x80202D7C: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x80202D80: lh          $t2, 0xA2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA2);
    // 0x80202D84: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80202D88: lh          $t1, 0x10($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X10);
    // 0x80202D8C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80202D90: sh          $t3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r11;
    // 0x80202D94: lh          $t4, 0xA2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XA2);
    // 0x80202D98: bnel        $t4, $zero, L_80202F3C
    if (ctx->r12 != 0) {
        // 0x80202D9C: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80202F3C;
    }
    goto skip_5;
    // 0x80202D9C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x80202DA0: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80202DA4: addiu       $v1, $zero, 0xE38
    ctx->r3 = ADD32(0, 0XE38);
    // 0x80202DA8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80202DAC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80202DB0: sh          $v1, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r3;
    // 0x80202DB4: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80202DB8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80202DBC: sh          $v1, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r3;
    // 0x80202DC0: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x80202DC4: sb          $t9, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = ctx->r25;
    // 0x80202DC8: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80202DCC: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80202DD0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80202DD4: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x80202DD8: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80202DDC: andi        $t3, $t2, 0xFFFB
    ctx->r11 = ctx->r10 & 0XFFFB;
    // 0x80202DE0: b           L_80202F38
    // 0x80202DE4: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
        goto L_80202F38;
    // 0x80202DE4: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80202DE8:
    // 0x80202DE8: lh          $a0, 0xA2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA2);
    // 0x80202DEC: bnel        $a0, $zero, L_80202E04
    if (ctx->r4 != 0) {
        // 0x80202DF0: lw          $t4, 0x4($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X4);
            goto L_80202E04;
    }
    goto skip_6;
    // 0x80202DF0: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    skip_6:
    // 0x80202DF4: jal         0x80020718
    // 0x80202DF8: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x80202DF8: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    after_1:
    // 0x80202DFC: lh          $a0, 0xA2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA2);
    // 0x80202E00: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
L_80202E04:
    // 0x80202E04: addiu       $t5, $a0, 0x10
    ctx->r13 = ADD32(ctx->r4, 0X10);
    // 0x80202E08: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x80202E0C: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80202E10: slti        $at, $a1, 0x471
    ctx->r1 = SIGNED(ctx->r5) < 0X471 ? 1 : 0;
    // 0x80202E14: beql        $at, $zero, L_80202E34
    if (ctx->r1 == 0) {
        // 0x80202E18: slti        $at, $a1, 0x9C8
        ctx->r1 = SIGNED(ctx->r5) < 0X9C8 ? 1 : 0;
            goto L_80202E34;
    }
    goto skip_7;
    // 0x80202E18: slti        $at, $a1, 0x9C8
    ctx->r1 = SIGNED(ctx->r5) < 0X9C8 ? 1 : 0;
    skip_7:
    // 0x80202E1C: sh          $t5, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r13;
    // 0x80202E20: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80202E24: lh          $a0, 0xA2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA2);
    // 0x80202E28: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x80202E2C: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80202E30: slti        $at, $a1, 0x9C8
    ctx->r1 = SIGNED(ctx->r5) < 0X9C8 ? 1 : 0;
L_80202E34:
    // 0x80202E34: bne         $at, $zero, L_80202E50
    if (ctx->r1 != 0) {
        // 0x80202E38: addiu       $t7, $a0, -0x10
        ctx->r15 = ADD32(ctx->r4, -0X10);
            goto L_80202E50;
    }
    // 0x80202E38: addiu       $t7, $a0, -0x10
    ctx->r15 = ADD32(ctx->r4, -0X10);
    // 0x80202E3C: sh          $t7, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r15;
    // 0x80202E40: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80202E44: lh          $a0, 0xA2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA2);
    // 0x80202E48: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x80202E4C: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
L_80202E50:
    // 0x80202E50: addu        $t9, $a1, $a0
    ctx->r25 = ADD32(ctx->r5, ctx->r4);
    // 0x80202E54: sh          $t9, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r25;
    // 0x80202E58: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x80202E5C: lh          $t2, 0xA2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA2);
    // 0x80202E60: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80202E64: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80202E68: lh          $t1, 0x10($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X10);
    // 0x80202E6C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80202E70: sh          $t3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r11;
    // 0x80202E74: lh          $t4, 0xA2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XA2);
    // 0x80202E78: bnel        $t4, $zero, L_80202F3C
    if (ctx->r12 != 0) {
        // 0x80202E7C: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80202F3C;
    }
    goto skip_8;
    // 0x80202E7C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_8:
    // 0x80202E80: sb          $t5, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = ctx->r13;
    // 0x80202E84: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80202E88: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80202E8C: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x80202E90: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80202E94: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80202E98: b           L_80202F38
    // 0x80202E9C: sh          $zero, 0x10($t9)
    MEM_H(0X10, ctx->r25) = 0;
        goto L_80202F38;
    // 0x80202E9C: sh          $zero, 0x10($t9)
    MEM_H(0X10, ctx->r25) = 0;
    // 0x80202EA0: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
L_80202EA4:
    // 0x80202EA4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80202EA8: ldc1        $f0, -0x69D8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X69D8);
    // 0x80202EAC: lw          $v1, 0x30($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X30);
    // 0x80202EB0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80202EB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80202EB8: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80202EBC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80202EC0: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x80202EC4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80202EC8: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80202ECC: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x80202ED0: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80202ED4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80202ED8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80202EDC: sub.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d - ctx->f0.d;
    // 0x80202EE0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80202EE4: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80202EE8: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80202EEC: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80202EF0: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80202EF4: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80202EF8: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80202EFC: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80202F00: nop

    // 0x80202F04: bc1fl       L_80202F3C
    if (!c1cs) {
        // 0x80202F08: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80202F3C;
    }
    goto skip_9;
    // 0x80202F08: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_9:
    // 0x80202F0C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x80202F10: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80202F14: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x80202F18: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x80202F1C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80202F20: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
    // 0x80202F24: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x80202F28: sb          $zero, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = 0;
    // 0x80202F2C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80202F30: andi        $t6, $t5, 0xFFF3
    ctx->r14 = ctx->r13 & 0XFFF3;
    // 0x80202F34: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_80202F38:
    // 0x80202F38: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_80202F3C:
    // 0x80202F3C: beql        $t7, $zero, L_80203118
    if (ctx->r15 == 0) {
        // 0x80202F40: lwc1        $f0, 0x40($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
            goto L_80203118;
    }
    goto skip_10;
    // 0x80202F40: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    skip_10:
    // 0x80202F44: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80202F48: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x80202F4C: beql        $t9, $zero, L_80203118
    if (ctx->r25 == 0) {
        // 0x80202F50: lwc1        $f0, 0x40($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
            goto L_80203118;
    }
    goto skip_11;
    // 0x80202F50: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    skip_11:
    // 0x80202F54: jal         0x80126944
    // 0x80202F58: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_2;
    // 0x80202F58: nop

    after_2:
    // 0x80202F5C: bne         $v0, $zero, L_80203114
    if (ctx->r2 != 0) {
        // 0x80202F60: lui         $at, 0x8022
        ctx->r1 = S32(0X8022 << 16);
            goto L_80203114;
    }
    // 0x80202F60: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80202F64: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80202F68: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80202F6C: ldc1        $f4, -0x69D0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X69D0);
    // 0x80202F70: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80202F74: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x80202F78: sub.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d - ctx->f4.d;
    // 0x80202F7C: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80202F80: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80202F84: add.d       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f2.d + ctx->f2.d;
    // 0x80202F88: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80202F8C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80202F90: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80202F94: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80202F98: sub.d       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f0.d - ctx->f10.d;
    // 0x80202F9C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80202FA0: jal         0x8010843C
    // 0x80202FA4: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_3;
    // 0x80202FA4: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    after_3:
    // 0x80202FA8: beq         $v0, $zero, L_802030B0
    if (ctx->r2 == 0) {
        // 0x80202FAC: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_802030B0;
    }
    // 0x80202FAC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80202FB0: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x80202FB4: lbu         $t0, 0x35A($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X35A);
    // 0x80202FB8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80202FBC: beql        $t0, $at, L_802030B4
    if (ctx->r8 == ctx->r1) {
        // 0x80202FC0: lwc1        $f6, 0x44($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
            goto L_802030B4;
    }
    goto skip_12;
    // 0x80202FC0: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    skip_12:
    // 0x80202FC4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80202FC8: lwc1        $f10, 0x384($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X384);
    // 0x80202FCC: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80202FD0: lw          $a0, 0x30($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X30);
    // 0x80202FD4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80202FD8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80202FDC: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80202FE0: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    // 0x80202FE4: addiu       $t4, $zero, 0x1FE
    ctx->r12 = ADD32(0, 0X1FE);
    // 0x80202FE8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80202FEC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80202FF0: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80202FF4: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80202FF8: lwc1        $f10, 0x384($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X384);
    // 0x80202FFC: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80203000: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80203004: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80203008: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8020300C: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80203010: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x80203014: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80203018: lwc1        $f10, 0x384($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X384);
    // 0x8020301C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80203020: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80203024: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80203028: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8020302C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80203030: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80203034: ldc1        $f10, -0x69C8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X69C8);
    // 0x80203038: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8020303C: c.le.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d <= ctx->f10.d;
    // 0x80203040: nop

    // 0x80203044: bc1fl       L_80203094
    if (!c1cs) {
        // 0x80203048: lwc1        $f0, 0x94($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
            goto L_80203094;
    }
    goto skip_13;
    // 0x80203048: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    skip_13:
    // 0x8020304C: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80203050: lwc1        $f14, 0x94($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80203054: lw          $a2, 0x98($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X98);
    // 0x80203058: jal         0x801FC830
    // 0x8020305C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_4;
    // 0x8020305C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x80203060: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80203064: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80203068: lwc1        $f14, 0x94($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020306C: lw          $a2, 0x98($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X98);
    // 0x80203070: addiu       $t5, $zero, 0x1F
    ctx->r13 = ADD32(0, 0X1F);
    // 0x80203074: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80203078: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8020307C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80203080: jal         0x80380F94
    // 0x80203084: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_5;
    // 0x80203084: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80203088: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8020308C: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x80203090: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
L_80203094:
    // 0x80203094: lwc1        $f4, 0x384($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X384);
    // 0x80203098: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8020309C: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x802030A0: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x802030A4: add.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x802030A8: b           L_80203114
    // 0x802030AC: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
        goto L_80203114;
    // 0x802030AC: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
L_802030B0:
    // 0x802030B0: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
L_802030B4:
    // 0x802030B4: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x802030B8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x802030BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x802030C0: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x802030C4: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x802030C8: nop

    // 0x802030CC: bc1f        L_802030E4
    if (!c1cs) {
        // 0x802030D0: lui         $at, 0x8022
        ctx->r1 = S32(0X8022 << 16);
            goto L_802030E4;
    }
    // 0x802030D0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802030D4: ldc1        $f8, -0x69C0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X69C0);
    // 0x802030D8: sub.d       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f2.d - ctx->f8.d;
    // 0x802030DC: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x802030E0: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_802030E4:
    // 0x802030E4: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802030E8: lwc1        $f14, 0x94($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802030EC: jal         0x801FD5BC
    // 0x802030F0: lw          $a2, 0x98($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X98);
    LOOKUP_FUNC(0x801FD5BC)(rdram, ctx);
        goto after_6;
    // 0x802030F0: lw          $a2, 0x98($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X98);
    after_6:
    // 0x802030F4: beql        $v0, $zero, L_80203118
    if (ctx->r2 == 0) {
        // 0x802030F8: lwc1        $f0, 0x40($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
            goto L_80203118;
    }
    goto skip_14;
    // 0x802030F8: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    skip_14:
    // 0x802030FC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80203100: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80203104: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80203108: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x8020310C: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x80203110: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
L_80203114:
    // 0x80203114: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
L_80203118:
    // 0x80203118: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8020311C: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80203120: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80203124: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80203128: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8020312C: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80203130: swc1        $f8, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f8.u32l;
    // 0x80203134: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80203138: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    // 0x8020313C: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80203140: swc1        $f18, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f18.u32l;
    // 0x80203144: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80203148: lw          $a0, 0x30($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X30);
    // 0x8020314C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80203150: add.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80203154: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80203158: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8020315C: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80203160: lw          $a0, 0x30($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X30);
    // 0x80203164: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80203168: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8020316C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80203170: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80203174: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80203178: lw          $a0, 0x30($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X30);
    // 0x8020317C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80203180: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80203184: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80203188: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8020318C: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80203190: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80203194: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80203198: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8020319C: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x802031A0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x802031A4: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x802031A8: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x802031AC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x802031B0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x802031B4: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x802031B8: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x802031BC: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x802031C0: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x802031C4: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x802031C8: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x802031CC: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x802031D0: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x802031D4: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x802031D8: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x802031DC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x802031E0: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x802031E4: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x802031E8: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x802031EC: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x802031F0: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x802031F4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x802031F8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x802031FC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80203200: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80203204: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80203208: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8020320C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80203210: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80203214: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80203218: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8020321C: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80203220: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80203224: lh          $t6, 0x9C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X9C);
    // 0x80203228: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x8020322C: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80203230: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x80203234: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    // 0x80203238: swc1        $f8, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f8.u32l;
    // 0x8020323C: sh          $t6, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r14;
    // 0x80203240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80203244: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80203248: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8020324C: jr          $ra
    // 0x80203250: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80203250: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80203254(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80203254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80203254: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80203258: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8020325C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80203260: lbu         $v1, 0x9E($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X9E);
    // 0x80203264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80203268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020326C: beq         $v1, $at, L_80203288
    if (ctx->r3 == ctx->r1) {
        // 0x80203270: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80203288;
    }
    // 0x80203270: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80203274: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80203278: beql        $v1, $at, L_80203334
    if (ctx->r3 == ctx->r1) {
        // 0x8020327C: lh          $v0, 0xA2($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XA2);
            goto L_80203334;
    }
    goto skip_0;
    // 0x8020327C: lh          $v0, 0xA2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA2);
    skip_0:
    // 0x80203280: b           L_802033C0
    // 0x80203284: lwc1        $f2, 0x94($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X94);
        goto L_802033C0;
    // 0x80203284: lwc1        $f2, 0x94($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X94);
L_80203288:
    // 0x80203288: lh          $v0, 0xA2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA2);
    // 0x8020328C: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x80203290: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80203294: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80203298: beq         $v1, $zero, L_802032AC
    if (ctx->r3 == 0) {
        // 0x8020329C: sh          $t6, 0xA2($s0)
        MEM_H(0XA2, ctx->r16) = ctx->r14;
            goto L_802032AC;
    }
    // 0x8020329C: sh          $t6, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r14;
    // 0x802032A0: jal         0x80020718
    // 0x802032A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x802032A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x802032A8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_802032AC:
    // 0x802032AC: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x802032B0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802032B4: ldc1        $f8, -0x69B8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X69B8);
    // 0x802032B8: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x802032BC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x802032C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x802032C4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x802032C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x802032CC: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    // 0x802032D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x802032D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x802032D8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x802032DC: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x802032E0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x802032E4: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802032E8: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x802032EC: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x802032F0: nop

    // 0x802032F4: bc1fl       L_802033C4
    if (!c1cs) {
        // 0x802032F8: lwc1        $f16, 0x90($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X90);
            goto L_802033C4;
    }
    goto skip_1;
    // 0x802032F8: lwc1        $f16, 0x90($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X90);
    skip_1:
    // 0x802032FC: jal         0x8012C97C
    // 0x80203300: sb          $t8, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = ctx->r24;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_1;
    // 0x80203300: sb          $t8, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = ctx->r24;
    after_1:
    // 0x80203304: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x80203308: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x8020330C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80203310: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80203314: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80203318: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x8020331C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80203320: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x80203324: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80203328: b           L_802033C0
    // 0x8020332C: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
        goto L_802033C0;
    // 0x8020332C: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80203330: lh          $v0, 0xA2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA2);
L_80203334:
    // 0x80203334: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    // 0x80203338: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8020333C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80203340: beq         $v1, $zero, L_80203354
    if (ctx->r3 == 0) {
        // 0x80203344: sh          $t3, 0xA2($s0)
        MEM_H(0XA2, ctx->r16) = ctx->r11;
            goto L_80203354;
    }
    // 0x80203344: sh          $t3, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r11;
    // 0x80203348: jal         0x80020718
    // 0x8020334C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x8020334C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x80203350: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_80203354:
    // 0x80203354: lw          $t4, 0x4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4);
    // 0x80203358: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020335C: ldc1        $f8, -0x69B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X69B0);
    // 0x80203360: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80203364: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80203368: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8020336C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80203370: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80203374: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80203378: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020337C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80203380: nop

    // 0x80203384: bc1fl       L_802033C4
    if (!c1cs) {
        // 0x80203388: lwc1        $f16, 0x90($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X90);
            goto L_802033C4;
    }
    goto skip_2;
    // 0x80203388: lwc1        $f16, 0x90($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X90);
    skip_2:
    // 0x8020338C: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    // 0x80203390: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    // 0x80203394: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80203398: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8020339C: swc1        $f2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f2.u32l;
    // 0x802033A0: jal         0x8012C97C
    // 0x802033A4: sb          $zero, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = 0;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_3;
    // 0x802033A4: sb          $zero, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = 0;
    after_3:
    // 0x802033A8: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x802033AC: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x802033B0: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x802033B4: andi        $t8, $t7, 0xFFF3
    ctx->r24 = ctx->r15 & 0XFFF3;
    // 0x802033B8: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x802033BC: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
L_802033C0:
    // 0x802033C0: lwc1        $f16, 0x90($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X90);
L_802033C4:
    // 0x802033C4: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802033C8: lh          $t9, 0x9C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X9C);
    // 0x802033CC: swc1        $f2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f2.u32l;
    // 0x802033D0: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x802033D4: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x802033D8: swc1        $f16, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f16.u32l;
    // 0x802033DC: swc1        $f18, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f18.u32l;
    // 0x802033E0: sh          $t9, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r25;
    // 0x802033E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802033E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x802033EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802033F0: jr          $ra
    // 0x802033F4: nop

    return;
    // 0x802033F4: nop

;}
RECOMP_FUNC void M9_FUN_802033f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802033F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802033FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80203400: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80203404: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80203408: lbu         $v0, 0x9E($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9E);
    // 0x8020340C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80203410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80203414: beq         $v0, $at, L_80203430
    if (ctx->r2 == ctx->r1) {
        // 0x80203418: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80203430;
    }
    // 0x80203418: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8020341C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80203420: beql        $v0, $at, L_802035BC
    if (ctx->r2 == ctx->r1) {
        // 0x80203424: lh          $v0, 0xA2($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XA2);
            goto L_802035BC;
    }
    goto skip_0;
    // 0x80203424: lh          $v0, 0xA2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA2);
    skip_0:
    // 0x80203428: b           L_802037F4
    // 0x8020342C: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
        goto L_802037F4;
    // 0x8020342C: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
L_80203430:
    // 0x80203430: lh          $v0, 0xA2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA2);
    // 0x80203434: addiu       $a0, $zero, 0x1C2
    ctx->r4 = ADD32(0, 0X1C2);
    // 0x80203438: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8020343C: sh          $t6, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r14;
    // 0x80203440: bne         $v0, $zero, L_80203454
    if (ctx->r2 != 0) {
        // 0x80203444: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80203454;
    }
    // 0x80203444: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80203448: jal         0x80020718
    // 0x8020344C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x8020344C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80203450: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80203454:
    // 0x80203454: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80203458: beql        $at, $zero, L_802034B8
    if (ctx->r1 == 0) {
        // 0x8020345C: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_802034B8;
    }
    goto skip_1;
    // 0x8020345C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    skip_1:
    // 0x80203460: jal         0x8001EAD0
    // 0x80203464: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80203464: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    after_1:
    // 0x80203468: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8020346C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80203470: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80203474: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80203478: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8020347C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80203480: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80203484: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80203488: jal         0x8001EB64
    // 0x8020348C: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x8020348C: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    after_2:
    // 0x80203490: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80203494: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80203498: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8020349C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x802034A0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802034A4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x802034A8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x802034AC: b           L_802037F0
    // 0x802034B0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
        goto L_802037F0;
    // 0x802034B0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x802034B4: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_802034B8:
    // 0x802034B8: bne         $at, $zero, L_802037F0
    if (ctx->r1 != 0) {
        // 0x802034BC: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_802037F0;
    }
    // 0x802034BC: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x802034C0: beql        $at, $zero, L_80203530
    if (ctx->r1 == 0) {
        // 0x802034C4: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_80203530;
    }
    goto skip_2;
    // 0x802034C4: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    skip_2:
    // 0x802034C8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x802034CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x802034D0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x802034D4: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x802034D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x802034DC: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x802034E0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802034E4: add.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d + ctx->f0.d;
    // 0x802034E8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x802034EC: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x802034F0: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x802034F4: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x802034F8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x802034FC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80203500: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x80203504: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80203508: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8020350C: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x80203510: lw          $a0, 0x30($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X30);
    // 0x80203514: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80203518: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8020351C: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x80203520: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80203524: b           L_802037F0
    // 0x80203528: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
        goto L_802037F0;
    // 0x80203528: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x8020352C: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
L_80203530:
    // 0x80203530: bne         $at, $zero, L_802037F0
    if (ctx->r1 != 0) {
        // 0x80203534: slti        $at, $v1, 0x1E
        ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
            goto L_802037F0;
    }
    // 0x80203534: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x80203538: beql        $at, $zero, L_80203584
    if (ctx->r1 == 0) {
        // 0x8020353C: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80203584;
    }
    goto skip_3;
    // 0x8020353C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    skip_3:
    // 0x80203540: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80203544: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80203548: lh          $t3, 0x12($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X12);
    // 0x8020354C: addiu       $t4, $t3, -0xCC
    ctx->r12 = ADD32(ctx->r11, -0XCC);
    // 0x80203550: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
    // 0x80203554: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x80203558: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8020355C: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x80203560: addiu       $t7, $t6, -0xCC
    ctx->r15 = ADD32(ctx->r14, -0XCC);
    // 0x80203564: sh          $t7, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r15;
    // 0x80203568: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x8020356C: lw          $a0, 0x30($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X30);
    // 0x80203570: lh          $t9, 0x12($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X12);
    // 0x80203574: addiu       $t0, $t9, 0xCC
    ctx->r8 = ADD32(ctx->r25, 0XCC);
    // 0x80203578: b           L_802037F0
    // 0x8020357C: sh          $t0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r8;
        goto L_802037F0;
    // 0x8020357C: sh          $t0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r8;
    // 0x80203580: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_80203584:
    // 0x80203584: bne         $v1, $at, L_802037F0
    if (ctx->r3 != ctx->r1) {
        // 0x80203588: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_802037F0;
    }
    // 0x80203588: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8020358C: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x80203590: sb          $t1, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = ctx->r9;
    // 0x80203594: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x80203598: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8020359C: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x802035A0: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x802035A4: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x802035A8: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x802035AC: andi        $t5, $t4, 0xFFFB
    ctx->r13 = ctx->r12 & 0XFFFB;
    // 0x802035B0: b           L_802037F0
    // 0x802035B4: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
        goto L_802037F0;
    // 0x802035B4: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x802035B8: lh          $v0, 0xA2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA2);
L_802035BC:
    // 0x802035BC: addiu       $a0, $zero, 0x1C1
    ctx->r4 = ADD32(0, 0X1C1);
    // 0x802035C0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x802035C4: sh          $t6, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r14;
    // 0x802035C8: bne         $v0, $zero, L_802035EC
    if (ctx->r2 != 0) {
        // 0x802035CC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_802035EC;
    }
    // 0x802035CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x802035D0: jal         0x80020718
    // 0x802035D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_3;
    // 0x802035D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x802035D8: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    // 0x802035DC: jal         0x8012C97C
    // 0x802035E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_4;
    // 0x802035E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x802035E4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x802035E8: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
L_802035EC:
    // 0x802035EC: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x802035F0: beql        $at, $zero, L_8020363C
    if (ctx->r1 == 0) {
        // 0x802035F4: slti        $at, $v1, 0x16
        ctx->r1 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
            goto L_8020363C;
    }
    goto skip_4;
    // 0x802035F4: slti        $at, $v1, 0x16
    ctx->r1 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    skip_4:
    // 0x802035F8: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x802035FC: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x80203600: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x80203604: addiu       $t9, $t8, 0xCC
    ctx->r25 = ADD32(ctx->r24, 0XCC);
    // 0x80203608: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
    // 0x8020360C: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x80203610: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80203614: lh          $t1, 0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X12);
    // 0x80203618: addiu       $t2, $t1, 0xCC
    ctx->r10 = ADD32(ctx->r9, 0XCC);
    // 0x8020361C: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x80203620: lw          $t3, 0xC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC);
    // 0x80203624: lw          $a0, 0x30($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X30);
    // 0x80203628: lh          $t4, 0x12($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X12);
    // 0x8020362C: addiu       $t5, $t4, -0xCC
    ctx->r13 = ADD32(ctx->r12, -0XCC);
    // 0x80203630: b           L_802037F0
    // 0x80203634: sh          $t5, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r13;
        goto L_802037F0;
    // 0x80203634: sh          $t5, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r13;
    // 0x80203638: slti        $at, $v1, 0x16
    ctx->r1 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
L_8020363C:
    // 0x8020363C: bne         $at, $zero, L_802037F0
    if (ctx->r1 != 0) {
        // 0x80203640: slti        $at, $v1, 0x1A
        ctx->r1 = SIGNED(ctx->r3) < 0X1A ? 1 : 0;
            goto L_802037F0;
    }
    // 0x80203640: slti        $at, $v1, 0x1A
    ctx->r1 = SIGNED(ctx->r3) < 0X1A ? 1 : 0;
    // 0x80203644: beql        $at, $zero, L_802036B4
    if (ctx->r1 == 0) {
        // 0x80203648: slti        $at, $v1, 0x1C
        ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
            goto L_802036B4;
    }
    goto skip_5;
    // 0x80203648: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    skip_5:
    // 0x8020364C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80203650: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80203654: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80203658: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x8020365C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80203660: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80203664: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80203668: sub.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d - ctx->f0.d;
    // 0x8020366C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80203670: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x80203674: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80203678: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8020367C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80203680: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80203684: sub.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d - ctx->f0.d;
    // 0x80203688: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8020368C: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80203690: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x80203694: lw          $a0, 0x30($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X30);
    // 0x80203698: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8020369C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x802036A0: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x802036A4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x802036A8: b           L_802037F0
    // 0x802036AC: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
        goto L_802037F0;
    // 0x802036AC: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x802036B0: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
L_802036B4:
    // 0x802036B4: bne         $at, $zero, L_802037F0
    if (ctx->r1 != 0) {
        // 0x802036B8: slti        $at, $v1, 0x1E
        ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
            goto L_802037F0;
    }
    // 0x802036B8: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x802036BC: beql        $at, $zero, L_8020371C
    if (ctx->r1 == 0) {
        // 0x802036C0: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_8020371C;
    }
    goto skip_6;
    // 0x802036C0: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    skip_6:
    // 0x802036C4: jal         0x8001EAD0
    // 0x802036C8: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x802036C8: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    after_5:
    // 0x802036CC: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x802036D0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x802036D4: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802036D8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x802036DC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802036E0: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x802036E4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x802036E8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x802036EC: jal         0x8001EB64
    // 0x802036F0: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x802036F0: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    after_6:
    // 0x802036F4: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x802036F8: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x802036FC: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80203700: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80203704: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80203708: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x8020370C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80203710: b           L_802037F0
    // 0x80203714: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
        goto L_802037F0;
    // 0x80203714: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x80203718: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_8020371C:
    // 0x8020371C: bnel        $v1, $at, L_802037F4
    if (ctx->r3 != ctx->r1) {
        // 0x80203720: lwc1        $f10, 0x90($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
            goto L_802037F4;
    }
    goto skip_7;
    // 0x80203720: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
    skip_7:
    // 0x80203724: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80203728: lh          $t1, 0x9C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X9C);
    // 0x8020372C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80203730: sh          $t1, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r9;
    // 0x80203734: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x80203738: lh          $t4, 0x9C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X9C);
    // 0x8020373C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80203740: sh          $t4, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r12;
    // 0x80203744: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x80203748: lh          $t7, 0x9C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X9C);
    // 0x8020374C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80203750: sh          $t7, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r15;
    // 0x80203754: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x80203758: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020375C: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80203760: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    // 0x80203764: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x80203768: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020376C: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80203770: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
    // 0x80203774: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x80203778: lwc1        $f16, 0x94($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020377C: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80203780: swc1        $f16, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f16.u32l;
    // 0x80203784: jal         0x8001EAD0
    // 0x80203788: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x80203788: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    after_7:
    // 0x8020378C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80203790: lwc1        $f18, 0x90($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80203794: add.d       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f2.d + ctx->f2.d;
    // 0x80203798: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x8020379C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802037A0: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x802037A4: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x802037A8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x802037AC: swc1        $f10, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f10.u32l;
    // 0x802037B0: jal         0x8001EB64
    // 0x802037B4: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x802037B4: lh          $a0, 0x9C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X9C);
    after_8:
    // 0x802037B8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x802037BC: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802037C0: add.d       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f2.d + ctx->f2.d;
    // 0x802037C4: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x802037C8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802037CC: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x802037D0: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x802037D4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x802037D8: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x802037DC: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x802037E0: sb          $zero, 0x9E($s0)
    MEM_B(0X9E, ctx->r16) = 0;
    // 0x802037E4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x802037E8: andi        $t2, $t0, 0xFFF3
    ctx->r10 = ctx->r8 & 0XFFF3;
    // 0x802037EC: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_802037F0:
    // 0x802037F0: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
L_802037F4:
    // 0x802037F4: lwc1        $f16, 0x94($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802037F8: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802037FC: lh          $t1, 0x9C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X9C);
    // 0x80203800: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80203804: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80203808: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x8020380C: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x80203810: swc1        $f18, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f18.u32l;
    // 0x80203814: sh          $t1, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r9;
    // 0x80203818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8020381C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80203820: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80203824: jr          $ra
    // 0x80203828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80203828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_8020382c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_8020382c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8020382C: nop

;}
RECOMP_FUNC void M9_FUN_80203830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80203830: sw          $a1, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r5;
    // 0x80203834: sb          $zero, 0x98($a0)
    MEM_B(0X98, ctx->r4) = 0;
    // 0x80203838: sh          $zero, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = 0;
    // 0x8020383C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203840: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
    // 0x80203844: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80203848: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020384C: sb          $zero, -0x4F0F($at)
    MEM_B(-0X4F0F, ctx->r1) = 0;
    // 0x80203850: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203854: swc1        $f0, -0x4F0C($at)
    MEM_W(-0X4F0C, ctx->r1) = ctx->f0.u32l;
    // 0x80203858: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020385C: sh          $zero, -0x4F08($at)
    MEM_H(-0X4F08, ctx->r1) = 0;
    // 0x80203860: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203864: sw          $zero, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = 0;
    // 0x80203868: lui         $a2, 0x8022
    ctx->r6 = S32(0X8022 << 16);
    // 0x8020386C: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x80203870: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80203874: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x80203878: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x8020387C: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80203880: addiu       $t3, $t3, -0x4EFC
    ctx->r11 = ADD32(ctx->r11, -0X4EFC);
    // 0x80203884: addiu       $t2, $t2, -0x4EF8
    ctx->r10 = ADD32(ctx->r10, -0X4EF8);
    // 0x80203888: addiu       $t1, $t1, -0x4EF4
    ctx->r9 = ADD32(ctx->r9, -0X4EF4);
    // 0x8020388C: addiu       $t0, $t0, -0x4EF0
    ctx->r8 = ADD32(ctx->r8, -0X4EF0);
    // 0x80203890: addiu       $a3, $a3, -0x4EEC
    ctx->r7 = ADD32(ctx->r7, -0X4EEC);
    // 0x80203894: addiu       $a2, $a2, -0x4EE8
    ctx->r6 = ADD32(ctx->r6, -0X4EE8);
    // 0x80203898: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8020389C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x802038A0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x802038A4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x802038A8: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x802038AC: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x802038B0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038B4: sw          $zero, -0x4F00($at)
    MEM_W(-0X4F00, ctx->r1) = 0;
    // 0x802038B8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038BC: sh          $zero, -0x4EE0($at)
    MEM_H(-0X4EE0, ctx->r1) = 0;
    // 0x802038C0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038C4: sh          $zero, -0x4EDE($at)
    MEM_H(-0X4EDE, ctx->r1) = 0;
    // 0x802038C8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038CC: sh          $zero, -0x4ED0($at)
    MEM_H(-0X4ED0, ctx->r1) = 0;
    // 0x802038D0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038D4: sh          $zero, -0x4ECE($at)
    MEM_H(-0X4ECE, ctx->r1) = 0;
    // 0x802038D8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038DC: swc1        $f0, -0x4EDC($at)
    MEM_W(-0X4EDC, ctx->r1) = ctx->f0.u32l;
    // 0x802038E0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038E4: swc1        $f0, -0x4ED8($at)
    MEM_W(-0X4ED8, ctx->r1) = ctx->f0.u32l;
    // 0x802038E8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038EC: swc1        $f0, -0x4ED4($at)
    MEM_W(-0X4ED4, ctx->r1) = ctx->f0.u32l;
    // 0x802038F0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038F4: swc1        $f0, -0x4EC8($at)
    MEM_W(-0X4EC8, ctx->r1) = ctx->f0.u32l;
    // 0x802038F8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802038FC: swc1        $f0, -0x4ECC($at)
    MEM_W(-0X4ECC, ctx->r1) = ctx->f0.u32l;
    // 0x80203900: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80203904: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80203908: sw          $zero, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = 0;
    // 0x8020390C: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
    // 0x80203910: sh          $zero, 0x354($v1)
    MEM_H(0X354, ctx->r3) = 0;
    // 0x80203914: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80203918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8020391C:
    // 0x8020391C: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80203920: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80203924: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80203928: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8020392C: mflo        $t6
    ctx->r14 = lo;
    // 0x80203930: addu        $a0, $v1, $t6
    ctx->r4 = ADD32(ctx->r3, ctx->r14);
    // 0x80203934: sb          $zero, 0x1090($a0)
    MEM_B(0X1090, ctx->r4) = 0;
    // 0x80203938: sw          $zero, 0x1088($a0)
    MEM_W(0X1088, ctx->r4) = 0;
    // 0x8020393C: bne         $at, $zero, L_8020391C
    if (ctx->r1 != 0) {
        // 0x80203940: sw          $zero, 0x108C($a0)
        MEM_W(0X108C, ctx->r4) = 0;
            goto L_8020391C;
    }
    // 0x80203940: sw          $zero, 0x108C($a0)
    MEM_W(0X108C, ctx->r4) = 0;
    // 0x80203944: jr          $ra
    // 0x80203948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80203948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_8020394c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_8020394c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8020394C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80203950: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x80203954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80203958: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
L_8020395C:
    // 0x8020395C: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80203960: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80203964: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80203968: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8020396C: mflo        $t6
    ctx->r14 = lo;
    // 0x80203970: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x80203974: lw          $a0, 0x1088($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1088);
    // 0x80203978: beq         $a0, $zero, L_8020399C
    if (ctx->r4 == 0) {
        // 0x8020397C: nop
    
            goto L_8020399C;
    }
    // 0x8020397C: nop

    // 0x80203980: lbu         $t7, 0x63($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X63);
    // 0x80203984: bnel        $t7, $zero, L_80203998
    if (ctx->r15 != 0) {
        // 0x80203988: lw          $t8, 0x5C($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X5C);
            goto L_80203998;
    }
    goto skip_0;
    // 0x80203988: lw          $t8, 0x5C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X5C);
    skip_0:
    // 0x8020398C: jr          $ra
    // 0x80203990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80203990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80203994: lw          $t8, 0x5C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X5C);
L_80203998:
    // 0x80203998: sw          $t8, 0x108C($v1)
    MEM_W(0X108C, ctx->r3) = ctx->r24;
L_8020399C:
    // 0x8020399C: bne         $at, $zero, L_8020395C
    if (ctx->r1 != 0) {
        // 0x802039A0: nop
    
            goto L_8020395C;
    }
    // 0x802039A0: nop

    // 0x802039A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x802039A8: jr          $ra
    // 0x802039AC: nop

    return;
    // 0x802039AC: nop

;}
RECOMP_FUNC void M9_FUN_802039b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802039B0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x802039B4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x802039B8: sw          $s5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r21;
    // 0x802039BC: sw          $s4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r20;
    // 0x802039C0: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x802039C4: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x802039C8: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x802039CC: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x802039D0: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x802039D4: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x802039D8: lw          $t7, 0x94($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X94);
    // 0x802039DC: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x802039E0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x802039E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x802039E8: bne         $t6, $t7, L_802039FC
    if (ctx->r14 != ctx->r15) {
        // 0x802039EC: lui         $at, 0x8022
        ctx->r1 = S32(0X8022 << 16);
            goto L_802039FC;
    }
    // 0x802039EC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802039F0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802039F4: b           L_80203A0C
    // 0x802039F8: sb          $zero, -0x4F0E($at)
    MEM_B(-0X4F0E, ctx->r1) = 0;
        goto L_80203A0C;
    // 0x802039F8: sb          $zero, -0x4F0E($at)
    MEM_B(-0X4F0E, ctx->r1) = 0;
L_802039FC:
    // 0x802039FC: sb          $t8, -0x4F0E($at)
    MEM_B(-0X4F0E, ctx->r1) = ctx->r24;
    // 0x80203A00: lbu         $t9, 0x9B($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X9B);
    // 0x80203A04: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80203A08: sb          $t1, 0x9B($s2)
    MEM_B(0X9B, ctx->r18) = ctx->r9;
L_80203A0C:
    // 0x80203A0C: lw          $s0, 0x94($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X94);
    // 0x80203A10: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80203A14: addiu       $s3, $s3, -0x4410
    ctx->r19 = ADD32(ctx->r19, -0X4410);
    // 0x80203A18: sw          $s0, 0xA0($s2)
    MEM_W(0XA0, ctx->r18) = ctx->r16;
    // 0x80203A1C: lw          $v0, 0xE8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XE8);
    // 0x80203A20: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80203A24: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80203A28: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x80203A2C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203A30: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80203A34: lwc1        $f4, 0x30($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X30);
    // 0x80203A38: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x80203A3C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80203A40: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80203A44: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80203A48: nop

    // 0x80203A4C: sw          $t4, -0x4EC4($at)
    MEM_W(-0X4EC4, ctx->r1) = ctx->r12;
    // 0x80203A50: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x80203A54: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203A58: lwc1        $f10, 0x30($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80203A5C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80203A60: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80203A64: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80203A68: nop

    // 0x80203A6C: sw          $t7, -0x4EC0($at)
    MEM_W(-0X4EC0, ctx->r1) = ctx->r15;
    // 0x80203A70: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80203A74: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203A78: lwc1        $f4, 0x30($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X30);
    // 0x80203A7C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80203A80: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80203A84: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80203A88: nop

    // 0x80203A8C: sw          $t1, -0x4EBC($at)
    MEM_W(-0X4EBC, ctx->r1) = ctx->r9;
L_80203A90:
    // 0x80203A90: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80203A94: mflo        $t2
    ctx->r10 = lo;
    // 0x80203A98: addu        $s1, $s3, $t2
    ctx->r17 = ADD32(ctx->r19, ctx->r10);
    // 0x80203A9C: lw          $a0, 0x1088($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1088);
    // 0x80203AA0: beql        $a0, $zero, L_80203C3C
    if (ctx->r4 == 0) {
        // 0x80203AA4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80203C3C;
    }
    goto skip_0;
    // 0x80203AA4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x80203AA8: jal         0x80006214
    // 0x80203AAC: sb          $t0, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x80203AAC: sb          $t0, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r8;
    after_0:
    // 0x80203AB0: lbu         $v1, 0x1090($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1090);
    // 0x80203AB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80203AB8: lbu         $t0, 0x75($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X75);
    // 0x80203ABC: bne         $v1, $at, L_80203BF8
    if (ctx->r3 != ctx->r1) {
        // 0x80203AC0: lw          $s4, 0x94($sp)
        ctx->r20 = MEM_W(ctx->r29, 0X94);
            goto L_80203BF8;
    }
    // 0x80203AC0: lw          $s4, 0x94($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X94);
    // 0x80203AC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80203AC8: lwc1        $f0, 0x1098($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1098);
    // 0x80203ACC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80203AD0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80203AD4: nop

    // 0x80203AD8: bc1tl       L_80203BAC
    if (c1cs) {
        // 0x80203ADC: swc1        $f2, 0x440($s3)
        MEM_W(0X440, ctx->r19) = ctx->f2.u32l;
            goto L_80203BAC;
    }
    goto skip_1;
    // 0x80203ADC: swc1        $f2, 0x440($s3)
    MEM_W(0X440, ctx->r19) = ctx->f2.u32l;
    skip_1:
    // 0x80203AE0: lw          $t3, 0x1094($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1094);
    // 0x80203AE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80203AE8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80203AEC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80203AF0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80203AF4: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80203AF8: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x80203AFC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80203B00: lw          $a1, 0x108C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X108C);
    // 0x80203B04: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80203B08: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x80203B0C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80203B10: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80203B14: beq         $t7, $zero, L_80203B64
    if (ctx->r15 == 0) {
        // 0x80203B18: sw          $t5, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r13;
            goto L_80203B64;
    }
    // 0x80203B18: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80203B1C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80203B20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80203B24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80203B28: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80203B2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80203B30: nop

    // 0x80203B34: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80203B38: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80203B3C: nop

    // 0x80203B40: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80203B44: bne         $t7, $zero, L_80203B5C
    if (ctx->r15 != 0) {
        // 0x80203B48: nop
    
            goto L_80203B5C;
    }
    // 0x80203B48: nop

    // 0x80203B4C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80203B50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80203B54: b           L_80203B74
    // 0x80203B58: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80203B74;
    // 0x80203B58: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80203B5C:
    // 0x80203B5C: b           L_80203B74
    // 0x80203B60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80203B74;
    // 0x80203B60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80203B64:
    // 0x80203B64: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80203B68: nop

    // 0x80203B6C: bltz        $t7, L_80203B5C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80203B70: nop
    
            goto L_80203B5C;
    }
    // 0x80203B70: nop

L_80203B74:
    // 0x80203B74: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80203B78: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80203B7C: sb          $t0, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r8;
    // 0x80203B80: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80203B84: jal         0x8012CE9C
    // 0x80203B88: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_1;
    // 0x80203B88: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_1:
    // 0x80203B8C: lbu         $t0, 0x75($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X75);
    // 0x80203B90: bne         $v0, $zero, L_80203BA0
    if (ctx->r2 != 0) {
        // 0x80203B94: lw          $s4, 0x94($sp)
        ctx->r20 = MEM_W(ctx->r29, 0X94);
            goto L_80203BA0;
    }
    // 0x80203B94: lw          $s4, 0x94($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X94);
    // 0x80203B98: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80203B9C: sb          $t8, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = ctx->r24;
L_80203BA0:
    // 0x80203BA0: b           L_80203BF8
    // 0x80203BA4: lbu         $v1, 0x1090($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1090);
        goto L_80203BF8;
    // 0x80203BA4: lbu         $v1, 0x1090($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1090);
    // 0x80203BA8: swc1        $f2, 0x440($s3)
    MEM_W(0X440, ctx->r19) = ctx->f2.u32l;
L_80203BAC:
    // 0x80203BAC: lwc1        $f16, 0x440($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X440);
    // 0x80203BB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80203BB4: swc1        $f16, 0x43C($s3)
    MEM_W(0X43C, ctx->r19) = ctx->f16.u32l;
    // 0x80203BB8: lwc1        $f18, 0x43C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X43C);
    // 0x80203BBC: swc1        $f18, 0x438($s3)
    MEM_W(0X438, ctx->r19) = ctx->f18.u32l;
    // 0x80203BC0: lw          $t9, 0x1094($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1094);
    // 0x80203BC4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80203BC8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80203BCC: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80203BD0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80203BD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80203BD8: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x80203BDC: sb          $t0, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r8;
    // 0x80203BE0: jal         0x8013A2E0
    // 0x80203BE4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_2;
    // 0x80203BE4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x80203BE8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80203BEC: lbu         $t0, 0x75($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X75);
    // 0x80203BF0: sb          $t3, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = ctx->r11;
    // 0x80203BF4: andi        $v1, $t3, 0xFF
    ctx->r3 = ctx->r11 & 0XFF;
L_80203BF8:
    // 0x80203BF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80203BFC: bne         $v1, $at, L_80203C38
    if (ctx->r3 != ctx->r1) {
        // 0x80203C00: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80203C38;
    }
    // 0x80203C00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80203C04: lw          $a1, 0x108C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X108C);
    // 0x80203C08: jal         0x80010550
    // 0x80203C0C: sb          $t0, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_3;
    // 0x80203C0C: sb          $t0, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r8;
    after_3:
    // 0x80203C10: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x80203C14: lbu         $t0, 0x75($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X75);
    // 0x80203C18: bne         $t4, $zero, L_80203C38
    if (ctx->r12 != 0) {
        // 0x80203C1C: sb          $v0, 0x1091($s1)
        MEM_B(0X1091, ctx->r17) = ctx->r2;
            goto L_80203C38;
    }
    // 0x80203C1C: sb          $v0, 0x1091($s1)
    MEM_B(0X1091, ctx->r17) = ctx->r2;
    // 0x80203C20: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80203C24: lw          $t7, 0x109C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X109C);
    // 0x80203C28: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x80203C2C: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x80203C30: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80203C34: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
L_80203C38:
    // 0x80203C38: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80203C3C:
    // 0x80203C3C: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x80203C40: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80203C44: bne         $at, $zero, L_80203A90
    if (ctx->r1 != 0) {
        // 0x80203C48: nop
    
            goto L_80203A90;
    }
    // 0x80203C48: nop

    // 0x80203C4C: jal         0x80006214
    // 0x80203C50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x80203C50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80203C54: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80203C58: lbu         $t9, -0x4F10($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4F10);
    // 0x80203C5C: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x80203C60: beql        $t9, $zero, L_80203DC4
    if (ctx->r25 == 0) {
        // 0x80203C64: lbu         $v0, 0x90($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X90);
            goto L_80203DC4;
    }
    goto skip_2;
    // 0x80203C64: lbu         $v0, 0x90($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X90);
    skip_2:
    // 0x80203C68: lw          $t2, -0x4EE8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4EE8);
    // 0x80203C6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80203C70: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80203C74: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80203C78: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x80203C7C: lw          $t4, -0x4F00($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F00);
    // 0x80203C80: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80203C84: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80203C88: lw          $t6, -0x4EFC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4EFC);
    // 0x80203C8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80203C90: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80203C94: lw          $t8, -0x4EF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4EF8);
    // 0x80203C98: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80203C9C: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x80203CA0: lw          $t1, -0x4EF4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4EF4);
    // 0x80203CA4: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80203CA8: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80203CAC: lw          $t3, -0x4EF0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4EF0);
    // 0x80203CB0: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80203CB4: addiu       $a0, $a0, -0x6904
    ctx->r4 = ADD32(ctx->r4, -0X6904);
    // 0x80203CB8: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // 0x80203CBC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80203CC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80203CC4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80203CC8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80203CCC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80203CD0: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80203CD4: lw          $t5, -0x4EEC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4EEC);
    // 0x80203CD8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80203CDC: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80203CE0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80203CE4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80203CE8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80203CEC: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80203CF0: lw          $t7, -0x4EE4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4EE4);
    // 0x80203CF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80203CF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80203CFC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203D00: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80203D04: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80203D08: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80203D0C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80203D10: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80203D14: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80203D18: lh          $t9, -0x4F08($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4F08);
    // 0x80203D1C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80203D20: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80203D24: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80203D28: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80203D2C: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x80203D30: lw          $t1, -0x4F04($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4F04);
    // 0x80203D34: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80203D38: nop

    // 0x80203D3C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80203D40: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80203D44: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80203D48: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80203D4C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80203D50: nop

    // 0x80203D54: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80203D58: lwc1        $f16, -0x4F0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4F0C);
    // 0x80203D5C: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80203D60: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80203D64: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80203D68: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80203D6C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80203D70: nop

    // 0x80203D74: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80203D78: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80203D7C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80203D80: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80203D84: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80203D88: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80203D8C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80203D90: nop

    // 0x80203D94: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80203D98: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80203D9C: jal         0x8011AAF4
    // 0x80203DA0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_5;
    // 0x80203DA0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80203DA4: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80203DA8: addiu       $v1, $v1, -0x4F0F
    ctx->r3 = ADD32(ctx->r3, -0X4F0F);
    // 0x80203DAC: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80203DB0: bne         $t2, $zero, L_80203DC0
    if (ctx->r10 != 0) {
        // 0x80203DB4: sb          $v0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r2;
            goto L_80203DC0;
    }
    // 0x80203DB4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80203DB8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203DBC: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
L_80203DC0:
    // 0x80203DC0: lbu         $v0, 0x90($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X90);
L_80203DC4:
    // 0x80203DC4: beq         $v0, $zero, L_80203DE0
    if (ctx->r2 == 0) {
        // 0x80203DC8: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80203DE0;
    }
    // 0x80203DC8: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80203DCC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80203DD0: bne         $t4, $zero, L_80203DE0
    if (ctx->r12 != 0) {
        // 0x80203DD4: sb          $t3, 0x90($s2)
        MEM_B(0X90, ctx->r18) = ctx->r11;
            goto L_80203DE0;
    }
    // 0x80203DD4: sb          $t3, 0x90($s2)
    MEM_B(0X90, ctx->r18) = ctx->r11;
    // 0x80203DD8: jal         0x80133980
    // 0x80203DDC: lhu         $a0, 0x92($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X92);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_6;
    // 0x80203DDC: lhu         $a0, 0x92($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X92);
    after_6:
L_80203DE0:
    // 0x80203DE0: lbu         $v0, 0x91($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X91);
    // 0x80203DE4: beq         $v0, $zero, L_80203E00
    if (ctx->r2 == 0) {
        // 0x80203DE8: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80203E00;
    }
    // 0x80203DE8: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80203DEC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80203DF0: bne         $t6, $zero, L_80203E00
    if (ctx->r14 != 0) {
        // 0x80203DF4: sb          $t5, 0x91($s2)
        MEM_B(0X91, ctx->r18) = ctx->r13;
            goto L_80203E00;
    }
    // 0x80203DF4: sb          $t5, 0x91($s2)
    MEM_B(0X91, ctx->r18) = ctx->r13;
    // 0x80203DF8: jal         0x801339D0
    // 0x80203DFC: lhu         $a0, 0x92($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X92);
    LOOKUP_FUNC(0x801339D0)(rdram, ctx);
        goto after_7;
    // 0x80203DFC: lhu         $a0, 0x92($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X92);
    after_7:
L_80203E00:
    // 0x80203E00: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80203E04: addiu       $a1, $a1, -0x4EE0
    ctx->r5 = ADD32(ctx->r5, -0X4EE0);
    // 0x80203E08: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80203E0C: beq         $v1, $zero, L_80203E30
    if (ctx->r3 == 0) {
        // 0x80203E10: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80203E30;
    }
    // 0x80203E10: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80203E14: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x80203E18: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80203E1C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80203E20: bne         $t8, $zero, L_80203E30
    if (ctx->r24 != 0) {
        // 0x80203E24: nop
    
            goto L_80203E30;
    }
    // 0x80203E24: nop

    // 0x80203E28: jal         0x80020744
    // 0x80203E2C: lhu         $a0, -0x4ED0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4ED0);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_8;
    // 0x80203E2C: lhu         $a0, -0x4ED0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4ED0);
    after_8:
L_80203E30:
    // 0x80203E30: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80203E34: addiu       $a0, $a0, -0x4EDE
    ctx->r4 = ADD32(ctx->r4, -0X4EDE);
    // 0x80203E38: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80203E3C: beq         $v0, $zero, L_80203E8C
    if (ctx->r2 == 0) {
        // 0x80203E40: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80203E8C;
    }
    // 0x80203E40: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80203E44: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80203E48: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x80203E4C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203E50: lui         $a2, 0x8022
    ctx->r6 = S32(0X8022 << 16);
    // 0x80203E54: bne         $t1, $zero, L_80203E8C
    if (ctx->r9 != 0) {
        // 0x80203E58: lui         $a3, 0x8022
        ctx->r7 = S32(0X8022 << 16);
            goto L_80203E8C;
    }
    // 0x80203E58: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x80203E5C: lwc1        $f12, -0x4EDC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4EDC);
    // 0x80203E60: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203E64: lwc1        $f14, -0x4ED8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4ED8);
    // 0x80203E68: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203E6C: lwc1        $f8, -0x4EC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4EC8);
    // 0x80203E70: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203E74: lwc1        $f10, -0x4ECC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4ECC);
    // 0x80203E78: lw          $a2, -0x4ED4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4ED4);
    // 0x80203E7C: lhu         $a3, -0x4ECE($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X4ECE);
    // 0x80203E80: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80203E84: jal         0x80127430
    // 0x80203E88: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80127430)(rdram, ctx);
        goto after_9;
    // 0x80203E88: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
L_80203E8C:
    // 0x80203E8C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80203E90: lui         $at, 0x1234
    ctx->r1 = S32(0X1234 << 16);
    // 0x80203E94: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x80203E98: beq         $v1, $at, L_802056F0
    if (ctx->r3 == ctx->r1) {
        // 0x80203E9C: addiu       $s4, $zero, 0xC
        ctx->r20 = ADD32(0, 0XC);
            goto L_802056F0;
    }
    // 0x80203E9C: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80203EA0: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
L_80203EA4:
    // 0x80203EA4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80203EA8: addu        $t2, $v1, $at
    ctx->r10 = ADD32(ctx->r3, ctx->r1);
    // 0x80203EAC: sltiu       $at, $t2, 0x3D
    ctx->r1 = ctx->r10 < 0X3D ? 1 : 0;
    // 0x80203EB0: beq         $at, $zero, L_802056E0
    if (ctx->r1 == 0) {
        // 0x80203EB4: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_802056E0;
    }
    // 0x80203EB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80203EB8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80203EBC: addu        $at, $at, $t2
    gpr jr_addend_80203EC4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80203EC0: lw          $t2, -0x5B58($at)
    ctx->r10 = ADD32(ctx->r1, -0X5B58);
    // 0x80203EC4: jr          $t2
    // 0x80203EC8: nop

    switch (jr_addend_80203EC4 >> 2) {
        case 0: goto L_80203ECC; break;
        case 1: goto L_80203EF8; break;
        case 2: goto L_80203F10; break;
        case 3: goto L_80203F24; break;
        case 4: goto L_80203F48; break;
        case 5: goto L_8020425C; break;
        case 6: goto L_80204290; break;
        case 7: goto L_802042C8; break;
        case 8: goto L_802041C0; break;
        case 9: goto L_80204220; break;
        case 10: goto L_802042F4; break;
        case 11: goto L_80204040; break;
        case 12: goto L_802040EC; break;
        case 13: goto L_80203F60; break;
        case 14: goto L_80203FD8; break;
        case 15: goto L_80204188; break;
        case 16: goto L_802041D8; break;
        case 17: goto L_802043C4; break;
        case 18: goto L_80204454; break;
        case 19: goto L_802045B0; break;
        case 20: goto L_802056E0; break;
        case 21: goto L_802045C0; break;
        case 22: goto L_80204388; break;
        case 23: goto L_802055AC; break;
        case 24: goto L_8020447C; break;
        case 25: goto L_802044A0; break;
        case 26: goto L_80204550; break;
        case 27: goto L_80204594; break;
        case 28: goto L_80204568; break;
        case 29: goto L_802045C8; break;
        case 30: goto L_80204624; break;
        case 31: goto L_802046B4; break;
        case 32: goto L_802046D8; break;
        case 33: goto L_80204708; break;
        case 34: goto L_80204A1C; break;
        case 35: goto L_80204814; break;
        case 36: goto L_80204918; break;
        case 37: goto L_802043EC; break;
        case 38: goto L_80204440; break;
        case 39: goto L_8020477C; break;
        case 40: goto L_80204738; break;
        case 41: goto L_80204B24; break;
        case 42: goto L_80204CAC; break;
        case 43: goto L_80204D8C; break;
        case 44: goto L_80204EF8; break;
        case 45: goto L_80204F50; break;
        case 46: goto L_80205068; break;
        case 47: goto L_80205260; break;
        case 48: goto L_80205304; break;
        case 49: goto L_8020532C; break;
        case 50: goto L_80205344; break;
        case 51: goto L_80205388; break;
        case 52: goto L_8020546C; break;
        case 53: goto L_802054A0; break;
        case 54: goto L_802054C8; break;
        case 55: goto L_80205538; break;
        case 56: goto L_80205554; break;
        case 57: goto L_8020557C; break;
        case 58: goto L_80205594; break;
        case 59: goto L_802055C8; break;
        case 60: goto L_802056D0; break;
        default: switch_error(__func__, 0x80203EC4, 0x8021A4A8);
    }
    // 0x80203EC8: nop

L_80203ECC:
    // 0x80203ECC: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80203ED0: lhu         $t3, -0x6B88($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X6B88);
    // 0x80203ED4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80203ED8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80203EDC: beql        $t3, $at, L_80203EF0
    if (ctx->r11 == ctx->r1) {
        // 0x80203EE0: sw          $s0, 0x94($s2)
        MEM_W(0X94, ctx->r18) = ctx->r16;
            goto L_80203EF0;
    }
    goto skip_3;
    // 0x80203EE0: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    skip_3:
    // 0x80203EE4: b           L_802056F4
    // 0x80203EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80203EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80203EEC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
L_80203EF0:
    // 0x80203EF0: b           L_802056E0
    // 0x80203EF4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80203EF4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80203EF8:
    // 0x80203EF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80203EFC: sh          $t4, 0x356($s3)
    MEM_H(0X356, ctx->r19) = ctx->r12;
    // 0x80203F00: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80203F04: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80203F08: b           L_802056E0
    // 0x80203F0C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80203F0C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80203F10:
    // 0x80203F10: sh          $zero, 0x356($s3)
    MEM_H(0X356, ctx->r19) = 0;
    // 0x80203F14: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80203F18: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80203F1C: b           L_802056E0
    // 0x80203F20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80203F20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80203F24:
    // 0x80203F24: lhu         $t5, 0x358($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X358);
    // 0x80203F28: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80203F2C: bnel        $t5, $zero, L_80203F40
    if (ctx->r13 != 0) {
        // 0x80203F30: sw          $s0, 0x94($s2)
        MEM_W(0X94, ctx->r18) = ctx->r16;
            goto L_80203F40;
    }
    goto skip_4;
    // 0x80203F30: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    skip_4:
    // 0x80203F34: b           L_802056F4
    // 0x80203F38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80203F38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80203F3C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
L_80203F40:
    // 0x80203F40: b           L_802056E0
    // 0x80203F44: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80203F44: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80203F48:
    // 0x80203F48: jal         0x800179B0
    // 0x80203F4C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_10;
    // 0x80203F4C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    after_10:
    // 0x80203F50: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80203F54: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80203F58: b           L_802056E0
    // 0x80203F5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80203F5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80203F60:
    // 0x80203F60: lbu         $t0, 0x3F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3F);
    // 0x80203F64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80203F68: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80203F6C: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80203F70: mflo        $t6
    ctx->r14 = lo;
    // 0x80203F74: addu        $s1, $s3, $t6
    ctx->r17 = ADD32(ctx->r19, ctx->r14);
    // 0x80203F78: lbu         $t7, 0x1090($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1090);
    // 0x80203F7C: bnel        $t7, $at, L_80203F90
    if (ctx->r15 != ctx->r1) {
        // 0x80203F80: sb          $zero, 0x1090($s1)
        MEM_B(0X1090, ctx->r17) = 0;
            goto L_80203F90;
    }
    goto skip_5;
    // 0x80203F80: sb          $zero, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = 0;
    skip_5:
    // 0x80203F84: b           L_802056F4
    // 0x80203F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80203F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80203F8C: sb          $zero, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = 0;
L_80203F90:
    // 0x80203F90: sh          $v1, 0x354($s3)
    MEM_H(0X354, ctx->r19) = ctx->r3;
    // 0x80203F94: lw          $t8, 0x108C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X108C);
    // 0x80203F98: sb          $v1, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = ctx->r3;
    // 0x80203F9C: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x80203FA0: sh          $v1, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r3;
    // 0x80203FA4: lw          $t9, -0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, -0X3C);
    // 0x80203FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80203FAC: sw          $t9, 0x1094($s1)
    MEM_W(0X1094, ctx->r17) = ctx->r25;
    // 0x80203FB0: lw          $t1, -0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X28);
    // 0x80203FB4: sw          $zero, 0x109C($s1)
    MEM_W(0X109C, ctx->r17) = 0;
    // 0x80203FB8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80203FBC: nop

    // 0x80203FC0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80203FC4: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80203FC8: swc1        $f4, 0x1098($s1)
    MEM_W(0X1098, ctx->r17) = ctx->f4.u32l;
    // 0x80203FCC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80203FD0: b           L_802056F4
    // 0x80203FD4: sb          $zero, 0x1091($s1)
    MEM_B(0X1091, ctx->r17) = 0;
        goto L_802056F4;
    // 0x80203FD4: sb          $zero, 0x1091($s1)
    MEM_B(0X1091, ctx->r17) = 0;
L_80203FD8:
    // 0x80203FD8: lbu         $t0, 0x3F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3F);
    // 0x80203FDC: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80203FE0: mflo        $t2
    ctx->r10 = lo;
    // 0x80203FE4: addu        $s1, $s3, $t2
    ctx->r17 = ADD32(ctx->r19, ctx->r10);
    // 0x80203FE8: lbu         $t3, 0x1091($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1091);
    // 0x80203FEC: beq         $t3, $zero, L_80204038
    if (ctx->r11 == 0) {
        // 0x80203FF0: nop
    
            goto L_80204038;
    }
    // 0x80203FF0: nop

    // 0x80203FF4: lw          $t4, 0x108C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X108C);
    // 0x80203FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80203FFC: sb          $v0, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = ctx->r2;
    // 0x80204000: sh          $v0, 0x78($t4)
    MEM_H(0X78, ctx->r12) = ctx->r2;
    // 0x80204004: sh          $zero, 0x354($s3)
    MEM_H(0X354, ctx->r19) = 0;
    // 0x80204008: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x8020400C: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x80204010: sw          $t5, 0x1094($s1)
    MEM_W(0X1094, ctx->r17) = ctx->r13;
    // 0x80204014: lw          $t6, -0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, -0X28);
    // 0x80204018: sw          $zero, 0x109C($s1)
    MEM_W(0X109C, ctx->r17) = 0;
    // 0x8020401C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80204020: nop

    // 0x80204024: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80204028: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8020402C: swc1        $f10, 0x1098($s1)
    MEM_W(0X1098, ctx->r17) = ctx->f10.u32l;
    // 0x80204030: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204034: sb          $zero, 0x1091($s1)
    MEM_B(0X1091, ctx->r17) = 0;
L_80204038:
    // 0x80204038: b           L_802056F4
    // 0x8020403C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x8020403C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204040:
    // 0x80204040: lbu         $t0, 0x53($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X53);
    // 0x80204044: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80204048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8020404C: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204050: mflo        $t7
    ctx->r15 = lo;
    // 0x80204054: addu        $s1, $s3, $t7
    ctx->r17 = ADD32(ctx->r19, ctx->r15);
    // 0x80204058: lbu         $t8, 0x1090($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1090);
    // 0x8020405C: bnel        $t8, $at, L_80204070
    if (ctx->r24 != ctx->r1) {
        // 0x80204060: sb          $zero, 0x1090($s1)
        MEM_B(0X1090, ctx->r17) = 0;
            goto L_80204070;
    }
    goto skip_6;
    // 0x80204060: sb          $zero, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = 0;
    skip_6:
    // 0x80204064: b           L_802056F4
    // 0x80204068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8020406C: sb          $zero, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = 0;
L_80204070:
    // 0x80204070: sh          $v0, 0x354($s3)
    MEM_H(0X354, ctx->r19) = ctx->r2;
    // 0x80204074: lw          $t9, 0x108C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X108C);
    // 0x80204078: sb          $v0, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = ctx->r2;
    // 0x8020407C: sh          $v0, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r2;
    // 0x80204080: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80204084: sw          $a0, 0x1094($s1)
    MEM_W(0X1094, ctx->r17) = ctx->r4;
    // 0x80204088: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x8020408C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80204090: nop

    // 0x80204094: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80204098: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8020409C: jal         0x8000E634
    // 0x802040A0: swc1        $f4, 0x1098($s1)
    MEM_W(0X1098, ctx->r17) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8000E634)(rdram, ctx);
        goto after_11;
    // 0x802040A0: swc1        $f4, 0x1098($s1)
    MEM_W(0X1098, ctx->r17) = ctx->f4.u32l;
    after_11:
    // 0x802040A4: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
    // 0x802040A8: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x802040AC: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x802040B0: mflo        $t4
    ctx->r12 = lo;
    // 0x802040B4: sw          $t4, 0x109C($s1)
    MEM_W(0X109C, ctx->r17) = ctx->r12;
    // 0x802040B8: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802040BC: bne         $v0, $zero, L_802040C8
    if (ctx->r2 != 0) {
        // 0x802040C0: nop
    
            goto L_802040C8;
    }
    // 0x802040C0: nop

    // 0x802040C4: break       7
    do_break(2149597380);
L_802040C8:
    // 0x802040C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x802040CC: bne         $v0, $at, L_802040E0
    if (ctx->r2 != ctx->r1) {
        // 0x802040D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_802040E0;
    }
    // 0x802040D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802040D4: bne         $t3, $at, L_802040E0
    if (ctx->r11 != ctx->r1) {
        // 0x802040D8: nop
    
            goto L_802040E0;
    }
    // 0x802040D8: nop

    // 0x802040DC: break       6
    do_break(2149597404);
L_802040E0:
    // 0x802040E0: sb          $zero, 0x1091($s1)
    MEM_B(0X1091, ctx->r17) = 0;
    // 0x802040E4: b           L_802056F4
    // 0x802040E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802040E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802040EC:
    // 0x802040EC: lbu         $t0, 0x53($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X53);
    // 0x802040F0: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802040F4: mflo        $t5
    ctx->r13 = lo;
    // 0x802040F8: addu        $s1, $s3, $t5
    ctx->r17 = ADD32(ctx->r19, ctx->r13);
    // 0x802040FC: lbu         $t6, 0x1091($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1091);
    // 0x80204100: beq         $t6, $zero, L_80204180
    if (ctx->r14 == 0) {
        // 0x80204104: nop
    
            goto L_80204180;
    }
    // 0x80204104: nop

    // 0x80204108: lw          $t7, 0x108C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X108C);
    // 0x8020410C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80204110: sb          $v0, 0x1090($s1)
    MEM_B(0X1090, ctx->r17) = ctx->r2;
    // 0x80204114: sh          $v0, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r2;
    // 0x80204118: sh          $zero, 0x354($s3)
    MEM_H(0X354, ctx->r19) = 0;
    // 0x8020411C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80204120: sw          $a0, 0x1094($s1)
    MEM_W(0X1094, ctx->r17) = ctx->r4;
    // 0x80204124: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80204128: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8020412C: nop

    // 0x80204130: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80204134: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80204138: jal         0x8000E634
    // 0x8020413C: swc1        $f10, 0x1098($s1)
    MEM_W(0X1098, ctx->r17) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8000E634)(rdram, ctx);
        goto after_12;
    // 0x8020413C: swc1        $f10, 0x1098($s1)
    MEM_W(0X1098, ctx->r17) = ctx->f10.u32l;
    after_12:
    // 0x80204140: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80204144: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x80204148: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x8020414C: mflo        $t2
    ctx->r10 = lo;
    // 0x80204150: sw          $t2, 0x109C($s1)
    MEM_W(0X109C, ctx->r17) = ctx->r10;
    // 0x80204154: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204158: sb          $zero, 0x1091($s1)
    MEM_B(0X1091, ctx->r17) = 0;
    // 0x8020415C: bne         $v0, $zero, L_80204168
    if (ctx->r2 != 0) {
        // 0x80204160: nop
    
            goto L_80204168;
    }
    // 0x80204160: nop

    // 0x80204164: break       7
    do_break(2149597540);
L_80204168:
    // 0x80204168: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8020416C: bne         $v0, $at, L_80204180
    if (ctx->r2 != ctx->r1) {
        // 0x80204170: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80204180;
    }
    // 0x80204170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80204174: bne         $t1, $at, L_80204180
    if (ctx->r9 != ctx->r1) {
        // 0x80204178: nop
    
            goto L_80204180;
    }
    // 0x80204178: nop

    // 0x8020417C: break       6
    do_break(2149597564);
L_80204180:
    // 0x80204180: b           L_802056F4
    // 0x80204184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204188:
    // 0x80204188: lbu         $t0, 0x17($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X17);
    // 0x8020418C: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80204190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80204194: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204198: mflo        $t3
    ctx->r11 = lo;
    // 0x8020419C: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x802041A0: lbu         $t5, 0x1091($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1091);
    // 0x802041A4: bnel        $t5, $zero, L_802041B8
    if (ctx->r13 != 0) {
        // 0x802041A8: sh          $zero, 0x354($s3)
        MEM_H(0X354, ctx->r19) = 0;
            goto L_802041B8;
    }
    goto skip_7;
    // 0x802041A8: sh          $zero, 0x354($s3)
    MEM_H(0X354, ctx->r19) = 0;
    skip_7:
    // 0x802041AC: b           L_802056F4
    // 0x802041B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802041B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802041B4: sh          $zero, 0x354($s3)
    MEM_H(0X354, ctx->r19) = 0;
L_802041B8:
    // 0x802041B8: b           L_802056F4
    // 0x802041BC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
        goto L_802056F4;
    // 0x802041BC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
L_802041C0:
    // 0x802041C0: jal         0x801FA2E0
    // 0x802041C4: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_13;
    // 0x802041C4: nop

    after_13:
    // 0x802041C8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x802041CC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802041D0: b           L_802056F4
    // 0x802041D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802041D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802041D8:
    // 0x802041D8: lbu         $t0, 0x17($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X17);
    // 0x802041DC: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802041E0: mflo        $t6
    ctx->r14 = lo;
    // 0x802041E4: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x802041E8: jal         0x801270C0
    // 0x802041EC: lw          $a0, 0x1088($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1088);
    LOOKUP_FUNC(0x801270C0)(rdram, ctx);
        goto after_14;
    // 0x802041EC: lw          $a0, 0x1088($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1088);
    after_14:
    // 0x802041F0: bne         $v0, $zero, L_80204200
    if (ctx->r2 != 0) {
        // 0x802041F4: nop
    
            goto L_80204200;
    }
    // 0x802041F4: nop

    // 0x802041F8: b           L_802056F4
    // 0x802041FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802041FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204200:
    // 0x80204200: jal         0x801268CC
    // 0x80204204: lhu         $a0, 0x2A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2A);
    LOOKUP_FUNC(0x801268CC)(rdram, ctx);
        goto after_15;
    // 0x80204204: lhu         $a0, 0x2A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2A);
    after_15:
    // 0x80204208: jal         0x80020744
    // 0x8020420C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_16;
    // 0x8020420C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_16:
    // 0x80204210: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80204214: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204218: b           L_802056F4
    // 0x8020421C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x8020421C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204220:
    // 0x80204220: lbu         $t0, 0x17($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X17);
    // 0x80204224: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80204228: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x8020422C: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204230: mflo        $t8
    ctx->r24 = lo;
    // 0x80204234: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80204238: lw          $t1, 0x1088($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1088);
    // 0x8020423C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80204240: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x80204244: lh          $t3, 0x12($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X12);
    // 0x80204248: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8020424C: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    // 0x80204250: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204254: b           L_802056E0
    // 0x80204258: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204258: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8020425C:
    // 0x8020425C: lbu         $t0, 0x17($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X17);
    // 0x80204260: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80204264: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80204268: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8020426C: mflo        $t6
    ctx->r14 = lo;
    // 0x80204270: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80204274: lw          $a0, 0x1088($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1088);
    // 0x80204278: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8020427C: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x80204280: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80204284: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204288: b           L_802056E0
    // 0x8020428C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x8020428C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204290:
    // 0x80204290: lbu         $t0, 0x17($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X17);
    // 0x80204294: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x80204298: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x8020429C: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802042A0: nor         $t6, $t5, $zero
    ctx->r14 = ~(ctx->r13 | 0);
    // 0x802042A4: mflo        $t2
    ctx->r10 = lo;
    // 0x802042A8: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x802042AC: lw          $a0, 0x1088($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X1088);
    // 0x802042B0: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x802042B4: and         $t7, $t4, $t6
    ctx->r15 = ctx->r12 & ctx->r14;
    // 0x802042B8: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x802042BC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802042C0: b           L_802056E0
    // 0x802042C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802042C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802042C8:
    // 0x802042C8: lbu         $t0, 0x17($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X17);
    // 0x802042CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802042D0: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802042D4: mflo        $t8
    ctx->r24 = lo;
    // 0x802042D8: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x802042DC: jal         0x801C4A5C
    // 0x802042E0: lw          $a0, 0x1088($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1088);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_17;
    // 0x802042E0: lw          $a0, 0x1088($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1088);
    after_17:
    // 0x802042E4: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x802042E8: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802042EC: b           L_802056E0
    // 0x802042F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802042F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802042F4:
    // 0x802042F4: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x802042F8: lbu         $t0, 0x67($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X67);
    // 0x802042FC: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x80204300: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80204304: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204308: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8020430C: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204310: mflo        $t1
    ctx->r9 = lo;
    // 0x80204314: addu        $s1, $s3, $t1
    ctx->r17 = ADD32(ctx->r19, ctx->r9);
    // 0x80204318: lw          $t3, 0x1088($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1088);
    // 0x8020431C: lw          $t5, 0x24($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X24);
    // 0x80204320: lw          $t4, 0x2C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X2C);
    // 0x80204324: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x80204328: lw          $t6, -0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, -0X50);
    // 0x8020432C: lw          $t7, 0x1088($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1088);
    // 0x80204330: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80204334: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80204338: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8020433C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80204340: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80204344: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    // 0x80204348: lw          $t1, -0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X3C);
    // 0x8020434C: lw          $t2, 0x1088($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1088);
    // 0x80204350: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80204354: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x80204358: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8020435C: lw          $t5, 0x2C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X2C);
    // 0x80204360: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204364: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    // 0x80204368: lw          $t6, 0x1088($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1088);
    // 0x8020436C: lw          $t4, -0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X28);
    // 0x80204370: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80204374: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80204378: sh          $t4, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r12;
    // 0x8020437C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204380: b           L_802056E0
    // 0x80204384: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204384: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204388:
    // 0x80204388: lbu         $t0, 0x2B($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X2B);
    // 0x8020438C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80204390: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80204394: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204398: mflo        $t9
    ctx->r25 = lo;
    // 0x8020439C: addu        $t1, $s3, $t9
    ctx->r9 = ADD32(ctx->r19, ctx->r25);
    // 0x802043A0: lw          $t2, 0x1088($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1088);
    // 0x802043A4: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x802043A8: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x802043AC: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    // 0x802043B0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x802043B4: sh          $t7, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r15;
    // 0x802043B8: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802043BC: b           L_802056E0
    // 0x802043C0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802043C0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802043C4:
    // 0x802043C4: jal         0x80017910
    // 0x802043C8: nop

    LOOKUP_FUNC(0x80017910)(rdram, ctx);
        goto after_18;
    // 0x802043C8: nop

    after_18:
    // 0x802043CC: bnel        $v0, $zero, L_802043E0
    if (ctx->r2 != 0) {
        // 0x802043D0: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_802043E0;
    }
    goto skip_8;
    // 0x802043D0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_8:
    // 0x802043D4: b           L_802056F4
    // 0x802043D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802043D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802043DC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_802043E0:
    // 0x802043E0: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802043E4: b           L_802056F4
    // 0x802043E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802043E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802043EC:
    // 0x802043EC: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x802043F0: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x802043F4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x802043F8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x802043FC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80204400: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80204404: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80204408: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x8020440C: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x80204410: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80204414: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80204418: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8020441C: div.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80204420: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80204424: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204428: jal         0x801300B0
    // 0x8020442C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801300B0)(rdram, ctx);
        goto after_19;
    // 0x8020442C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_19:
    // 0x80204430: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x80204434: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204438: b           L_802056F4
    // 0x8020443C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x8020443C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204440:
    // 0x80204440: sw          $zero, 0x112C($s3)
    MEM_W(0X112C, ctx->r19) = 0;
    // 0x80204444: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80204448: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x8020444C: b           L_802056F4
    // 0x80204450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204454:
    // 0x80204454: jal         0x800178E8
    // 0x80204458: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_20;
    // 0x80204458: nop

    after_20:
    // 0x8020445C: bnel        $v0, $zero, L_80204470
    if (ctx->r2 != 0) {
        // 0x80204460: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_80204470;
    }
    goto skip_9;
    // 0x80204460: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_9:
    // 0x80204464: b           L_802056F4
    // 0x80204468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8020446C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80204470:
    // 0x80204470: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204474: b           L_802056F4
    // 0x80204478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8020447C:
    // 0x8020447C: jal         0x801268F4
    // 0x80204480: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801268F4)(rdram, ctx);
        goto after_21;
    // 0x80204480: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x80204484: bne         $v0, $zero, L_80204494
    if (ctx->r2 != 0) {
        // 0x80204488: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_80204494;
    }
    // 0x80204488: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8020448C: b           L_802056F4
    // 0x80204490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204494:
    // 0x80204494: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204498: b           L_802056E0
    // 0x8020449C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x8020449C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802044A0:
    // 0x802044A0: lbu         $v0, 0x98($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X98);
    // 0x802044A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802044A8: bne         $v0, $zero, L_80204504
    if (ctx->r2 != 0) {
        // 0x802044AC: nop
    
            goto L_80204504;
    }
    // 0x802044AC: nop

    // 0x802044B0: lhu         $v0, 0x190($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X190);
    // 0x802044B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802044B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x802044BC: beq         $v0, $at, L_802044E4
    if (ctx->r2 == ctx->r1) {
        // 0x802044C0: addiu       $t2, $zero, 0x6
        ctx->r10 = ADD32(0, 0X6);
            goto L_802044E4;
    }
    // 0x802044C0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x802044C4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x802044C8: beql        $v0, $at, L_802044E8
    if (ctx->r2 == ctx->r1) {
        // 0x802044CC: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_802044E8;
    }
    goto skip_10;
    // 0x802044CC: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    skip_10:
    // 0x802044D0: lhu         $t1, 0x18E($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X18E);
    // 0x802044D4: beql        $t1, $zero, L_802044E8
    if (ctx->r9 == 0) {
        // 0x802044D8: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_802044E8;
    }
    goto skip_11;
    // 0x802044D8: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    skip_11:
    // 0x802044DC: b           L_802056F4
    // 0x802044E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802044E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802044E4:
    // 0x802044E4: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
L_802044E8:
    // 0x802044E8: sh          $v1, 0x18E($s3)
    MEM_H(0X18E, ctx->r19) = ctx->r3;
    // 0x802044EC: sh          $t2, 0x190($s3)
    MEM_H(0X190, ctx->r19) = ctx->r10;
    // 0x802044F0: sh          $t3, 0x192($s3)
    MEM_H(0X192, ctx->r19) = ctx->r11;
    // 0x802044F4: sh          $zero, 0x196($s3)
    MEM_H(0X196, ctx->r19) = 0;
    // 0x802044F8: sb          $v1, 0x98($s2)
    MEM_B(0X98, ctx->r18) = ctx->r3;
    // 0x802044FC: b           L_802056F4
    // 0x80204500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204504:
    // 0x80204504: bne         $v0, $at, L_80204548
    if (ctx->r2 != ctx->r1) {
        // 0x80204508: nop
    
            goto L_80204548;
    }
    // 0x80204508: nop

    // 0x8020450C: lhu         $t5, 0x196($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X196);
    // 0x80204510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80204514: bne         $t5, $at, L_80204548
    if (ctx->r13 != ctx->r1) {
        // 0x80204518: nop
    
            goto L_80204548;
    }
    // 0x80204518: nop

    // 0x8020451C: lbu         $t0, 0x17($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X17);
    // 0x80204520: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80204524: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80204528: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8020452C: mflo        $t7
    ctx->r15 = lo;
    // 0x80204530: addu        $t4, $s3, $t7
    ctx->r12 = ADD32(ctx->r19, ctx->r15);
    // 0x80204534: sb          $t6, 0x1090($t4)
    MEM_B(0X1090, ctx->r12) = ctx->r14;
    // 0x80204538: sb          $zero, 0x98($s2)
    MEM_B(0X98, ctx->r18) = 0;
    // 0x8020453C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204540: b           L_802056E0
    // 0x80204544: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204544: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204548:
    // 0x80204548: b           L_802056F4
    // 0x8020454C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x8020454C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204550:
    // 0x80204550: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80204554: sh          $t8, 0x194($s3)
    MEM_H(0X194, ctx->r19) = ctx->r24;
    // 0x80204558: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8020455C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204560: b           L_802056E0
    // 0x80204564: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204564: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204568:
    // 0x80204568: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x8020456C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80204570: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80204574: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80204578: nop

    // 0x8020457C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80204580: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80204584: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80204588: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x8020458C: b           L_802056E0
    // 0x80204590: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204590: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204594:
    // 0x80204594: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80204598: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x8020459C: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x802045A0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x802045A4: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802045A8: b           L_802056E0
    // 0x802045AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802045AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802045B0:
    // 0x802045B0: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x802045B4: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802045B8: b           L_802056E0
    // 0x802045BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802045BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802045C0:
    // 0x802045C0: b           L_802056F4
    // 0x802045C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802045C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802045C8:
    // 0x802045C8: lbu         $v0, 0x98($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X98);
    // 0x802045CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x802045D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802045D4: bne         $v0, $zero, L_802045F0
    if (ctx->r2 != 0) {
        // 0x802045D8: nop
    
            goto L_802045F0;
    }
    // 0x802045D8: nop

    // 0x802045DC: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x802045E0: sb          $t3, 0x98($s2)
    MEM_B(0X98, ctx->r18) = ctx->r11;
    // 0x802045E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802045E8: b           L_802056F4
    // 0x802045EC: sh          $t2, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r10;
        goto L_802056F4;
    // 0x802045EC: sh          $t2, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r10;
L_802045F0:
    // 0x802045F0: bnel        $v0, $at, L_802056E4
    if (ctx->r2 != ctx->r1) {
        // 0x802045F4: lui         $at, 0x1234
        ctx->r1 = S32(0X1234 << 16);
            goto L_802056E4;
    }
    goto skip_12;
    // 0x802045F4: lui         $at, 0x1234
    ctx->r1 = S32(0X1234 << 16);
    skip_12:
    // 0x802045F8: lh          $v0, 0x9C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X9C);
    // 0x802045FC: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80204600: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80204604: beq         $v0, $zero, L_80204614
    if (ctx->r2 == 0) {
        // 0x80204608: sh          $t5, 0x9C($s2)
        MEM_H(0X9C, ctx->r18) = ctx->r13;
            goto L_80204614;
    }
    // 0x80204608: sh          $t5, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r13;
    // 0x8020460C: b           L_802056F4
    // 0x80204610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204614:
    // 0x80204614: sb          $zero, 0x98($s2)
    MEM_B(0X98, ctx->r18) = 0;
    // 0x80204618: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x8020461C: b           L_802056E0
    // 0x80204620: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204620: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204624:
    // 0x80204624: lbu         $v0, 0x98($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X98);
    // 0x80204628: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8020462C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80204630: bne         $v0, $zero, L_8020464C
    if (ctx->r2 != 0) {
        // 0x80204634: nop
    
            goto L_8020464C;
    }
    // 0x80204634: nop

    // 0x80204638: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8020463C: sb          $t6, 0x98($s2)
    MEM_B(0X98, ctx->r18) = ctx->r14;
    // 0x80204640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80204644: b           L_802056F4
    // 0x80204648: sh          $t7, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r15;
        goto L_802056F4;
    // 0x80204648: sh          $t7, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r15;
L_8020464C:
    // 0x8020464C: bnel        $v0, $at, L_8020467C
    if (ctx->r2 != ctx->r1) {
        // 0x80204650: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8020467C;
    }
    goto skip_13;
    // 0x80204650: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_13:
    // 0x80204654: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80204658: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8020465C: sb          $t9, 0x98($s2)
    MEM_B(0X98, ctx->r18) = ctx->r25;
    // 0x80204660: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80204664: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x80204668: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8020466C: subu        $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x80204670: b           L_802056E0
    // 0x80204674: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204674: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80204678: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8020467C:
    // 0x8020467C: bne         $v0, $at, L_802046A4
    if (ctx->r2 != ctx->r1) {
        // 0x80204680: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_802046A4;
    }
    // 0x80204680: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80204684: lh          $v0, 0x9C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X9C);
    // 0x80204688: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8020468C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80204690: beq         $v0, $zero, L_802046A4
    if (ctx->r2 == 0) {
        // 0x80204694: sh          $t1, 0x9C($s2)
        MEM_H(0X9C, ctx->r18) = ctx->r9;
            goto L_802046A4;
    }
    // 0x80204694: sh          $t1, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r9;
    // 0x80204698: sb          $t2, 0x98($s2)
    MEM_B(0X98, ctx->r18) = ctx->r10;
    // 0x8020469C: b           L_802056F4
    // 0x802046A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802046A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802046A4:
    // 0x802046A4: sb          $zero, 0x98($s2)
    MEM_B(0X98, ctx->r18) = 0;
    // 0x802046A8: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802046AC: b           L_802056E0
    // 0x802046B0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802046B0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802046B4:
    // 0x802046B4: jal         0x80133A24
    // 0x802046B8: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_22;
    // 0x802046B8: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    after_22:
    // 0x802046BC: bne         $v0, $zero, L_802046CC
    if (ctx->r2 != 0) {
        // 0x802046C0: addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
            goto L_802046CC;
    }
    // 0x802046C0: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x802046C4: b           L_802056F4
    // 0x802046C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802046C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802046CC:
    // 0x802046CC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802046D0: b           L_802056E0
    // 0x802046D4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802046D4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802046D8:
    // 0x802046D8: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x802046DC: sb          $t3, 0x90($s2)
    MEM_B(0X90, ctx->r18) = ctx->r11;
    // 0x802046E0: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x802046E4: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x802046E8: bne         $t7, $zero, L_802046F8
    if (ctx->r15 != 0) {
        // 0x802046EC: sh          $t5, 0x92($s2)
        MEM_H(0X92, ctx->r18) = ctx->r13;
            goto L_802046F8;
    }
    // 0x802046EC: sh          $t5, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r13;
    // 0x802046F0: jal         0x80133980
    // 0x802046F4: andi        $a0, $t5, 0xFFFF
    ctx->r4 = ctx->r13 & 0XFFFF;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_23;
    // 0x802046F4: andi        $a0, $t5, 0xFFFF
    ctx->r4 = ctx->r13 & 0XFFFF;
    after_23:
L_802046F8:
    // 0x802046F8: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x802046FC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204700: b           L_802056E0
    // 0x80204704: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204704: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204708:
    // 0x80204708: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8020470C: sb          $t6, 0x91($s2)
    MEM_B(0X91, ctx->r18) = ctx->r14;
    // 0x80204710: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80204714: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80204718: bne         $t8, $zero, L_80204728
    if (ctx->r24 != 0) {
        // 0x8020471C: sh          $t4, 0x92($s2)
        MEM_H(0X92, ctx->r18) = ctx->r12;
            goto L_80204728;
    }
    // 0x8020471C: sh          $t4, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r12;
    // 0x80204720: jal         0x801339D0
    // 0x80204724: andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    LOOKUP_FUNC(0x801339D0)(rdram, ctx);
        goto after_24;
    // 0x80204724: andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    after_24:
L_80204728:
    // 0x80204728: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x8020472C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204730: b           L_802056E0
    // 0x80204734: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204734: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204738:
    // 0x80204738: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8020473C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204740: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x80204744: sw          $t9, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = ctx->r25;
    // 0x80204748: lw          $t1, -0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X28);
    // 0x8020474C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204750: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80204754: nop

    // 0x80204758: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8020475C: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204760: swc1        $f8, -0x4F0C($at)
    MEM_W(-0X4F0C, ctx->r1) = ctx->f8.u32l;
    // 0x80204764: lw          $t2, -0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X14);
    // 0x80204768: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020476C: sh          $t2, -0x4F08($at)
    MEM_H(-0X4F08, ctx->r1) = ctx->r10;
    // 0x80204770: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204774: b           L_802056E0
    // 0x80204778: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204778: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8020477C:
    // 0x8020477C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80204780: lw          $t5, 0xE8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XE8);
    // 0x80204784: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80204788: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8020478C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80204790: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x80204794: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80204798: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8020479C: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x802047A0: lw          $t7, -0x4F04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F04);
    // 0x802047A4: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x802047A8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x802047AC: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x802047B0: addiu       $a0, $a0, -0x6194
    ctx->r4 = ADD32(ctx->r4, -0X6194);
    // 0x802047B4: addiu       $a1, $zero, 0x2AF
    ctx->r5 = ADD32(0, 0X2AF);
    // 0x802047B8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x802047BC: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x802047C0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x802047C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x802047C8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x802047CC: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x802047D0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x802047D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x802047D8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x802047DC: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x802047E0: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x802047E4: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x802047E8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x802047EC: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x802047F0: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x802047F4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x802047F8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x802047FC: jal         0x8011AAF4
    // 0x80204800: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_25;
    // 0x80204800: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_25:
    // 0x80204804: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80204808: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x8020480C: b           L_802056F4
    // 0x80204810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204814:
    // 0x80204814: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204818: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
    // 0x8020481C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80204820: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80204824: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80204828: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8020482C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80204830: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80204834: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80204838: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8020483C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80204840: addiu       $a0, $a0, -0x6128
    ctx->r4 = ADD32(ctx->r4, -0X6128);
    // 0x80204844: addiu       $a1, $zero, 0x2BF
    ctx->r5 = ADD32(0, 0X2BF);
    // 0x80204848: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8020484C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80204850: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80204854: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204858: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8020485C: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x80204860: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80204864: nop

    // 0x80204868: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8020486C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80204870: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80204874: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80204878: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x8020487C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80204880: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80204884: nop

    // 0x80204888: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8020488C: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204890: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80204894: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x80204898: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8020489C: nop

    // 0x802048A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802048A4: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x802048A8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x802048AC: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x802048B0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x802048B4: nop

    // 0x802048B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802048BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x802048C0: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x802048C4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x802048C8: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x802048CC: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x802048D0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x802048D4: nop

    // 0x802048D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802048DC: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x802048E0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x802048E4: lw          $t5, 0x8C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8C);
    // 0x802048E8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x802048EC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x802048F0: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x802048F4: nop

    // 0x802048F8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x802048FC: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204900: jal         0x8011AAF4
    // 0x80204904: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_26;
    // 0x80204904: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_26:
    // 0x80204908: addiu       $s0, $s0, 0xA0
    ctx->r16 = ADD32(ctx->r16, 0XA0);
    // 0x8020490C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204910: b           L_802056F4
    // 0x80204914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204918:
    // 0x80204918: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020491C: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
    // 0x80204920: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80204924: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80204928: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8020492C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80204930: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80204934: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80204938: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8020493C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80204940: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80204944: addiu       $a0, $a0, -0x60BC
    ctx->r4 = ADD32(ctx->r4, -0X60BC);
    // 0x80204948: addiu       $a1, $zero, 0x2CD
    ctx->r5 = ADD32(0, 0X2CD);
    // 0x8020494C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204950: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80204954: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80204958: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8020495C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80204960: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80204964: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80204968: nop

    // 0x8020496C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80204970: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80204974: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80204978: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8020497C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80204980: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80204984: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80204988: nop

    // 0x8020498C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204990: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204994: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80204998: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x8020499C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x802049A0: nop

    // 0x802049A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802049A8: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x802049AC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x802049B0: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x802049B4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x802049B8: nop

    // 0x802049BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802049C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x802049C4: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x802049C8: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x802049CC: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x802049D0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x802049D4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x802049D8: nop

    // 0x802049DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802049E0: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x802049E4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x802049E8: lw          $t3, 0x8C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8C);
    // 0x802049EC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x802049F0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x802049F4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x802049F8: nop

    // 0x802049FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80204A00: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204A04: jal         0x8011AAF4
    // 0x80204A08: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_27;
    // 0x80204A08: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_27:
    // 0x80204A0C: addiu       $s0, $s0, 0xA0
    ctx->r16 = ADD32(ctx->r16, 0XA0);
    // 0x80204A10: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204A14: b           L_802056E0
    // 0x80204A18: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204A18: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204A1C:
    // 0x80204A1C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204A20: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
    // 0x80204A24: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80204A28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80204A2C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80204A30: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80204A34: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80204A38: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80204A3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80204A40: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80204A44: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80204A48: addiu       $a0, $a0, -0x604C
    ctx->r4 = ADD32(ctx->r4, -0X604C);
    // 0x80204A4C: addiu       $a1, $zero, 0x2DD
    ctx->r5 = ADD32(0, 0X2DD);
    // 0x80204A50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204A54: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80204A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80204A5C: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204A60: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80204A64: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80204A68: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80204A6C: nop

    // 0x80204A70: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80204A74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80204A78: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80204A7C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80204A80: lw          $t4, 0x3C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X3C);
    // 0x80204A84: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80204A88: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80204A8C: nop

    // 0x80204A90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204A94: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204A98: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80204A9C: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80204AA0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80204AA4: nop

    // 0x80204AA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80204AAC: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204AB0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80204AB4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80204AB8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80204ABC: nop

    // 0x80204AC0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80204AC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80204AC8: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80204ACC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80204AD0: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x80204AD4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80204AD8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80204ADC: nop

    // 0x80204AE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80204AE4: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204AE8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80204AEC: lw          $t2, 0x8C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8C);
    // 0x80204AF0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80204AF4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80204AF8: nop

    // 0x80204AFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80204B00: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204B04: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80204B08: lw          $t3, 0xA0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XA0);
    // 0x80204B0C: jal         0x8011AAF4
    // 0x80204B10: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_28;
    // 0x80204B10: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    after_28:
    // 0x80204B14: addiu       $s0, $s0, 0xB4
    ctx->r16 = ADD32(ctx->r16, 0XB4);
    // 0x80204B18: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204B1C: b           L_802056F4
    // 0x80204B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204B24:
    // 0x80204B24: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80204B28: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B2C: sb          $t5, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = ctx->r13;
    // 0x80204B30: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B34: addiu       $t7, $s0, 0x14
    ctx->r15 = ADD32(ctx->r16, 0X14);
    // 0x80204B38: sw          $t7, -0x4F00($at)
    MEM_W(-0X4F00, ctx->r1) = ctx->r15;
    // 0x80204B3C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B40: addiu       $t6, $s0, 0x28
    ctx->r14 = ADD32(ctx->r16, 0X28);
    // 0x80204B44: sw          $t6, -0x4EFC($at)
    MEM_W(-0X4EFC, ctx->r1) = ctx->r14;
    // 0x80204B48: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B4C: addiu       $t4, $s0, 0x3C
    ctx->r12 = ADD32(ctx->r16, 0X3C);
    // 0x80204B50: sw          $t4, -0x4EF8($at)
    MEM_W(-0X4EF8, ctx->r1) = ctx->r12;
    // 0x80204B54: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B58: addiu       $t8, $s0, 0x50
    ctx->r24 = ADD32(ctx->r16, 0X50);
    // 0x80204B5C: sw          $t8, -0x4EF4($at)
    MEM_W(-0X4EF4, ctx->r1) = ctx->r24;
    // 0x80204B60: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B64: addiu       $t9, $s0, 0x64
    ctx->r25 = ADD32(ctx->r16, 0X64);
    // 0x80204B68: sw          $t9, -0x4EF0($at)
    MEM_W(-0X4EF0, ctx->r1) = ctx->r25;
    // 0x80204B6C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B70: addiu       $t1, $s0, 0x78
    ctx->r9 = ADD32(ctx->r16, 0X78);
    // 0x80204B74: sw          $t1, -0x4EEC($at)
    MEM_W(-0X4EEC, ctx->r1) = ctx->r9;
    // 0x80204B78: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B7C: addiu       $t2, $s0, 0x8C
    ctx->r10 = ADD32(ctx->r16, 0X8C);
    // 0x80204B80: sw          $t2, -0x4EE8($at)
    MEM_W(-0X4EE8, ctx->r1) = ctx->r10;
    // 0x80204B84: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204B88: addiu       $t3, $s0, 0xA0
    ctx->r11 = ADD32(ctx->r16, 0XA0);
    // 0x80204B8C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80204B90: sw          $t3, -0x4EE4($at)
    MEM_W(-0X4EE4, ctx->r1) = ctx->r11;
    // 0x80204B94: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80204B98: lw          $t7, 0x8C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8C);
    // 0x80204B9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80204BA0: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80204BA4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80204BA8: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80204BAC: lw          $t7, -0x4F04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F04);
    // 0x80204BB0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80204BB4: lh          $t5, -0x4F08($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4F08);
    // 0x80204BB8: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80204BBC: addiu       $a0, $a0, -0x5FD0
    ctx->r4 = ADD32(ctx->r4, -0X5FD0);
    // 0x80204BC0: addiu       $a1, $zero, 0x2F8
    ctx->r5 = ADD32(0, 0X2F8);
    // 0x80204BC4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80204BC8: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80204BCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80204BD0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80204BD4: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80204BD8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80204BDC: nop

    // 0x80204BE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80204BE4: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204BE8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80204BEC: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80204BF0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80204BF4: nop

    // 0x80204BF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80204BFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80204C00: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204C04: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80204C08: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80204C0C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80204C10: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80204C14: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80204C18: nop

    // 0x80204C1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80204C20: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204C24: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80204C28: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80204C2C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80204C30: nop

    // 0x80204C34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204C38: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204C3C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80204C40: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80204C44: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80204C48: nop

    // 0x80204C4C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80204C50: lwc1        $f18, -0x4F0C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4F0C);
    // 0x80204C54: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80204C58: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80204C5C: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x80204C60: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80204C64: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80204C68: nop

    // 0x80204C6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204C70: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204C74: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80204C78: lw          $t3, 0xA0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XA0);
    // 0x80204C7C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80204C80: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80204C84: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80204C88: nop

    // 0x80204C8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80204C90: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204C94: jal         0x8011AAF4
    // 0x80204C98: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_29;
    // 0x80204C98: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_29:
    // 0x80204C9C: addiu       $s0, $s0, 0xB4
    ctx->r16 = ADD32(ctx->r16, 0XB4);
    // 0x80204CA0: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204CA4: b           L_802056F4
    // 0x80204CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204CAC:
    // 0x80204CAC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204CB0: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
    // 0x80204CB4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80204CB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80204CBC: lw          $t4, 0xE8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE8);
    // 0x80204CC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80204CC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80204CC8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80204CCC: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x80204CD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80204CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80204CD8: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80204CDC: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80204CE0: addiu       $a0, $a0, -0x5F58
    ctx->r4 = ADD32(ctx->r4, -0X5F58);
    // 0x80204CE4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80204CE8: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80204CEC: addiu       $a1, $zero, 0x307
    ctx->r5 = ADD32(0, 0X307);
    // 0x80204CF0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80204CF4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80204CF8: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80204CFC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80204D00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80204D04: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80204D08: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80204D0C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80204D10: nop

    // 0x80204D14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204D18: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204D1C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80204D20: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80204D24: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80204D28: nop

    // 0x80204D2C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80204D30: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80204D34: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80204D38: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80204D3C: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80204D40: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80204D44: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80204D48: nop

    // 0x80204D4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204D50: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204D54: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80204D58: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x80204D5C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80204D60: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80204D64: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80204D68: nop

    // 0x80204D6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80204D70: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204D74: jal         0x8011AAF4
    // 0x80204D78: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_30;
    // 0x80204D78: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_30:
    // 0x80204D7C: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x80204D80: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204D84: b           L_802056F4
    // 0x80204D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204D8C:
    // 0x80204D8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80204D90: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204D94: sb          $t3, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = ctx->r11;
    // 0x80204D98: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80204D9C: addiu       $t5, $t5, -0x4EC4
    ctx->r13 = ADD32(ctx->r13, -0X4EC4);
    // 0x80204DA0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DA4: sw          $t5, -0x4F00($at)
    MEM_W(-0X4F00, ctx->r1) = ctx->r13;
    // 0x80204DA8: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80204DAC: addiu       $t7, $t7, -0x4EC0
    ctx->r15 = ADD32(ctx->r15, -0X4EC0);
    // 0x80204DB0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DB4: sw          $t7, -0x4EFC($at)
    MEM_W(-0X4EFC, ctx->r1) = ctx->r15;
    // 0x80204DB8: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80204DBC: addiu       $t6, $t6, -0x4EBC
    ctx->r14 = ADD32(ctx->r14, -0X4EBC);
    // 0x80204DC0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DC4: sw          $t6, -0x4EF8($at)
    MEM_W(-0X4EF8, ctx->r1) = ctx->r14;
    // 0x80204DC8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DCC: addiu       $t4, $s0, 0x14
    ctx->r12 = ADD32(ctx->r16, 0X14);
    // 0x80204DD0: sw          $t4, -0x4EF4($at)
    MEM_W(-0X4EF4, ctx->r1) = ctx->r12;
    // 0x80204DD4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DD8: addiu       $t8, $s0, 0x28
    ctx->r24 = ADD32(ctx->r16, 0X28);
    // 0x80204DDC: sw          $t8, -0x4EF0($at)
    MEM_W(-0X4EF0, ctx->r1) = ctx->r24;
    // 0x80204DE0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DE4: addiu       $t9, $s0, 0x3C
    ctx->r25 = ADD32(ctx->r16, 0X3C);
    // 0x80204DE8: sw          $t9, -0x4EEC($at)
    MEM_W(-0X4EEC, ctx->r1) = ctx->r25;
    // 0x80204DEC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DF0: addiu       $t1, $s0, 0x50
    ctx->r9 = ADD32(ctx->r16, 0X50);
    // 0x80204DF4: sw          $t1, -0x4EE8($at)
    MEM_W(-0X4EE8, ctx->r1) = ctx->r9;
    // 0x80204DF8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204DFC: addiu       $t2, $s0, 0x64
    ctx->r10 = ADD32(ctx->r16, 0X64);
    // 0x80204E00: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80204E04: sw          $t2, -0x4EE4($at)
    MEM_W(-0X4EE4, ctx->r1) = ctx->r10;
    // 0x80204E08: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80204E0C: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x80204E10: lw          $t7, 0xE8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XE8);
    // 0x80204E14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80204E18: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80204E1C: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x80204E20: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x80204E24: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80204E28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80204E2C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204E30: lh          $t1, -0x4F08($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4F08);
    // 0x80204E34: lw          $t2, -0x4F04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4F04);
    // 0x80204E38: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80204E3C: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80204E40: addiu       $a0, $a0, -0x5EE4
    ctx->r4 = ADD32(ctx->r4, -0X5EE4);
    // 0x80204E44: addiu       $a1, $zero, 0x31F
    ctx->r5 = ADD32(0, 0X31F);
    // 0x80204E48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80204E4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80204E50: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80204E54: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80204E58: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80204E5C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80204E60: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80204E64: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80204E68: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80204E6C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80204E70: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80204E74: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80204E78: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80204E7C: nop

    // 0x80204E80: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80204E84: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204E88: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80204E8C: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80204E90: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80204E94: nop

    // 0x80204E98: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80204E9C: lwc1        $f6, -0x4F0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F0C);
    // 0x80204EA0: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80204EA4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80204EA8: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80204EAC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80204EB0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80204EB4: nop

    // 0x80204EB8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80204EBC: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80204EC0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80204EC4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80204EC8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80204ECC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80204ED0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80204ED4: nop

    // 0x80204ED8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80204EDC: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80204EE0: jal         0x8011AAF4
    // 0x80204EE4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_31;
    // 0x80204EE4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_31:
    // 0x80204EE8: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x80204EEC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204EF0: b           L_802056F4
    // 0x80204EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80204EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80204EF8:
    // 0x80204EF8: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x80204EFC: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80204F00: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x80204F04: multu       $t5, $s4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204F08: mflo        $t7
    ctx->r15 = lo;
    // 0x80204F0C: addu        $t6, $s3, $t7
    ctx->r14 = ADD32(ctx->r19, ctx->r15);
    // 0x80204F10: sw          $t3, 0x104C($t6)
    MEM_W(0X104C, ctx->r14) = ctx->r11;
    // 0x80204F14: lw          $t8, -0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X14);
    // 0x80204F18: lw          $t4, -0x3C($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X3C);
    // 0x80204F1C: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204F20: mflo        $t9
    ctx->r25 = lo;
    // 0x80204F24: addu        $t1, $s3, $t9
    ctx->r9 = ADD32(ctx->r19, ctx->r25);
    // 0x80204F28: sw          $t4, 0x1050($t1)
    MEM_W(0X1050, ctx->r9) = ctx->r12;
    // 0x80204F2C: lw          $t5, -0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X14);
    // 0x80204F30: lw          $t2, -0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X28);
    // 0x80204F34: multu       $t5, $s4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204F38: mflo        $t7
    ctx->r15 = lo;
    // 0x80204F3C: addu        $t3, $s3, $t7
    ctx->r11 = ADD32(ctx->r19, ctx->r15);
    // 0x80204F40: sw          $t2, 0x1054($t3)
    MEM_W(0X1054, ctx->r11) = ctx->r10;
    // 0x80204F44: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80204F48: b           L_802056E0
    // 0x80204F4C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80204F4C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80204F50:
    // 0x80204F50: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80204F54: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
    // 0x80204F58: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80204F5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80204F60: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80204F64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80204F68: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80204F6C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80204F70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80204F74: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80204F78: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204F7C: addiu       $a0, $a0, -0x5E50
    ctx->r4 = ADD32(ctx->r4, -0X5E50);
    // 0x80204F80: addiu       $a1, $zero, 0x33B
    ctx->r5 = ADD32(0, 0X33B);
    // 0x80204F84: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80204F88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80204F8C: mflo        $t9
    ctx->r25 = lo;
    // 0x80204F90: addu        $v0, $s3, $t9
    ctx->r2 = ADD32(ctx->r19, ctx->r25);
    // 0x80204F94: lw          $t4, 0x104C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X104C);
    // 0x80204F98: lw          $t1, 0x1050($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1050);
    // 0x80204F9C: lw          $t5, 0x1054($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1054);
    // 0x80204FA0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80204FA4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80204FA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80204FAC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80204FB0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80204FB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80204FB8: nop

    // 0x80204FBC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80204FC0: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204FC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80204FC8: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80204FCC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80204FD0: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80204FD4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80204FD8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80204FDC: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80204FE0: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80204FE4: mflo        $t2
    ctx->r10 = lo;
    // 0x80204FE8: addu        $v1, $s3, $t2
    ctx->r3 = ADD32(ctx->r19, ctx->r10);
    // 0x80204FEC: lw          $t3, 0x104C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X104C);
    // 0x80204FF0: lw          $t6, 0x1050($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1050);
    // 0x80204FF4: lw          $t8, 0x1054($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1054);
    // 0x80204FF8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80204FFC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80205000: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80205004: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80205008: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8020500C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80205010: nop

    // 0x80205014: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80205018: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8020501C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80205020: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80205024: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80205028: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8020502C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80205030: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80205034: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x80205038: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8020503C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80205040: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80205044: nop

    // 0x80205048: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8020504C: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80205050: jal         0x8011AAF4
    // 0x80205054: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_32;
    // 0x80205054: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_32:
    // 0x80205058: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x8020505C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80205060: b           L_802056E0
    // 0x80205064: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205064: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80205068:
    // 0x80205068: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8020506C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205070: sb          $t4, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = ctx->r12;
    // 0x80205074: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80205078: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020507C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80205080: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80205084: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80205088: addiu       $a0, $a0, -0x5DE4
    ctx->r4 = ADD32(ctx->r4, -0X5DE4);
    // 0x8020508C: addiu       $a1, $zero, 0x35A
    ctx->r5 = ADD32(0, 0X35A);
    // 0x80205090: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80205094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80205098: mflo        $t5
    ctx->r13 = lo;
    // 0x8020509C: addu        $t7, $s3, $t5
    ctx->r15 = ADD32(ctx->r19, ctx->r13);
    // 0x802050A0: addiu       $t2, $t7, 0x104C
    ctx->r10 = ADD32(ctx->r15, 0X104C);
    // 0x802050A4: sw          $t2, -0x4F00($at)
    MEM_W(-0X4F00, ctx->r1) = ctx->r10;
    // 0x802050A8: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x802050AC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802050B0: multu       $t3, $s4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802050B4: mflo        $t6
    ctx->r14 = lo;
    // 0x802050B8: addu        $t8, $s3, $t6
    ctx->r24 = ADD32(ctx->r19, ctx->r14);
    // 0x802050BC: addiu       $t9, $t8, 0x1050
    ctx->r25 = ADD32(ctx->r24, 0X1050);
    // 0x802050C0: sw          $t9, -0x4EFC($at)
    MEM_W(-0X4EFC, ctx->r1) = ctx->r25;
    // 0x802050C4: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x802050C8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802050CC: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802050D0: mflo        $t1
    ctx->r9 = lo;
    // 0x802050D4: addu        $t5, $s3, $t1
    ctx->r13 = ADD32(ctx->r19, ctx->r9);
    // 0x802050D8: addiu       $t7, $t5, 0x1054
    ctx->r15 = ADD32(ctx->r13, 0X1054);
    // 0x802050DC: sw          $t7, -0x4EF8($at)
    MEM_W(-0X4EF8, ctx->r1) = ctx->r15;
    // 0x802050E0: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x802050E4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802050E8: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802050EC: mflo        $t3
    ctx->r11 = lo;
    // 0x802050F0: addu        $t6, $s3, $t3
    ctx->r14 = ADD32(ctx->r19, ctx->r11);
    // 0x802050F4: addiu       $t8, $t6, 0x104C
    ctx->r24 = ADD32(ctx->r14, 0X104C);
    // 0x802050F8: sw          $t8, -0x4EF4($at)
    MEM_W(-0X4EF4, ctx->r1) = ctx->r24;
    // 0x802050FC: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80205100: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205104: addiu       $t8, $s0, 0x3C
    ctx->r24 = ADD32(ctx->r16, 0X3C);
    // 0x80205108: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8020510C: addiu       $t9, $s0, 0x50
    ctx->r25 = ADD32(ctx->r16, 0X50);
    // 0x80205110: mflo        $t4
    ctx->r12 = lo;
    // 0x80205114: addu        $t1, $s3, $t4
    ctx->r9 = ADD32(ctx->r19, ctx->r12);
    // 0x80205118: addiu       $t5, $t1, 0x1050
    ctx->r13 = ADD32(ctx->r9, 0X1050);
    // 0x8020511C: sw          $t5, -0x4EF0($at)
    MEM_W(-0X4EF0, ctx->r1) = ctx->r13;
    // 0x80205120: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80205124: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205128: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8020512C: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80205130: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80205134: mflo        $t2
    ctx->r10 = lo;
    // 0x80205138: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x8020513C: addiu       $t6, $t3, 0x1054
    ctx->r14 = ADD32(ctx->r11, 0X1054);
    // 0x80205140: sw          $t6, -0x4EEC($at)
    MEM_W(-0X4EEC, ctx->r1) = ctx->r14;
    // 0x80205144: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205148: sw          $t8, -0x4EE8($at)
    MEM_W(-0X4EE8, ctx->r1) = ctx->r24;
    // 0x8020514C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205150: sw          $t9, -0x4EE4($at)
    MEM_W(-0X4EE4, ctx->r1) = ctx->r25;
    // 0x80205154: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80205158: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8020515C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80205160: nop

    // 0x80205164: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80205168: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8020516C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80205170: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x80205174: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80205178: mflo        $t7
    ctx->r15 = lo;
    // 0x8020517C: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
    // 0x80205180: lw          $t2, 0x104C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X104C);
    // 0x80205184: lw          $t3, 0x1050($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1050);
    // 0x80205188: lw          $t6, 0x1054($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1054);
    // 0x8020518C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80205190: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80205194: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80205198: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8020519C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x802051A0: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x802051A4: lh          $t2, -0x4F08($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4F08);
    // 0x802051A8: lw          $t3, -0x4F04($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4F04);
    // 0x802051AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802051B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x802051B4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802051B8: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x802051BC: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x802051C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x802051C4: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x802051C8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x802051CC: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x802051D0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x802051D4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x802051D8: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x802051DC: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802051E0: mflo        $t9
    ctx->r25 = lo;
    // 0x802051E4: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x802051E8: lw          $t4, 0x104C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X104C);
    // 0x802051EC: lw          $t1, 0x1050($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1050);
    // 0x802051F0: lw          $t5, 0x1054($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1054);
    // 0x802051F4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x802051F8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x802051FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80205200: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80205204: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80205208: lwc1        $f10, -0x4F0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4F0C);
    // 0x8020520C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80205210: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80205214: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80205218: div.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8020521C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80205220: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80205224: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80205228: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8020522C: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80205230: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80205234: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80205238: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8020523C: nop

    // 0x80205240: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80205244: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80205248: jal         0x8011AAF4
    // 0x8020524C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_33;
    // 0x8020524C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_33:
    // 0x80205250: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x80205254: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80205258: b           L_802056F4
    // 0x8020525C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x8020525C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80205260:
    // 0x80205260: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205264: sb          $zero, -0x4F10($at)
    MEM_B(-0X4F10, ctx->r1) = 0;
    // 0x80205268: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8020526C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80205270: lw          $t8, 0xE8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE8);
    // 0x80205274: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80205278: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8020527C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80205280: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x80205284: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80205288: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8020528C: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80205290: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80205294: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80205298: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8020529C: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x802052A0: addiu       $a0, $a0, -0x5D7C
    ctx->r4 = ADD32(ctx->r4, -0X5D7C);
    // 0x802052A4: addiu       $a1, $zero, 0x365
    ctx->r5 = ADD32(0, 0X365);
    // 0x802052A8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x802052AC: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x802052B0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x802052B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x802052B8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x802052BC: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x802052C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x802052C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x802052C8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x802052CC: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x802052D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x802052D4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x802052D8: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x802052DC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x802052E0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x802052E4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x802052E8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x802052EC: jal         0x8011AAF4
    // 0x802052F0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_34;
    // 0x802052F0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_34:
    // 0x802052F4: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x802052F8: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802052FC: b           L_802056F4
    // 0x80205300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80205300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80205304:
    // 0x80205304: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80205308: lbu         $v0, -0x4F0F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4F0F);
    // 0x8020530C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80205310: beql        $v0, $zero, L_80205324
    if (ctx->r2 == 0) {
        // 0x80205314: sw          $s0, 0x94($s2)
        MEM_W(0X94, ctx->r18) = ctx->r16;
            goto L_80205324;
    }
    goto skip_14;
    // 0x80205314: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    skip_14:
    // 0x80205318: b           L_802056F4
    // 0x8020531C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x8020531C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80205320: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
L_80205324:
    // 0x80205324: b           L_802056E0
    // 0x80205328: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205328: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8020532C:
    // 0x8020532C: jal         0x800208C4
    // 0x80205330: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_35;
    // 0x80205330: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    after_35:
    // 0x80205334: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80205338: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x8020533C: b           L_802056E0
    // 0x80205340: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205340: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80205344:
    // 0x80205344: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80205348: bnel        $t9, $zero, L_80205364
    if (ctx->r25 != 0) {
        // 0x8020534C: lw          $t4, 0x14($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X14);
            goto L_80205364;
    }
    goto skip_15;
    // 0x8020534C: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    skip_15:
    // 0x80205350: jal         0x80020744
    // 0x80205354: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_36;
    // 0x80205354: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    after_36:
    // 0x80205358: b           L_8020537C
    // 0x8020535C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
        goto L_8020537C;
    // 0x8020535C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80205360: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
L_80205364:
    // 0x80205364: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205368: sh          $t4, -0x4ED0($at)
    MEM_H(-0X4ED0, ctx->r1) = ctx->r12;
    // 0x8020536C: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x80205370: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205374: sh          $t1, -0x4EE0($at)
    MEM_H(-0X4EE0, ctx->r1) = ctx->r9;
    // 0x80205378: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_8020537C:
    // 0x8020537C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80205380: b           L_802056E0
    // 0x80205384: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205384: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80205388:
    // 0x80205388: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x8020538C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205390: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x80205394: sh          $t5, -0x4ECE($at)
    MEM_H(-0X4ECE, ctx->r1) = ctx->r13;
    // 0x80205398: lw          $t7, -0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X50);
    // 0x8020539C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802053A0: sh          $t7, -0x4EDE($at)
    MEM_H(-0X4EDE, ctx->r1) = ctx->r15;
    // 0x802053A4: lw          $t2, -0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X3C);
    // 0x802053A8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802053AC: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802053B0: mflo        $t3
    ctx->r11 = lo;
    // 0x802053B4: addu        $t6, $s3, $t3
    ctx->r14 = ADD32(ctx->r19, ctx->r11);
    // 0x802053B8: lw          $t8, 0x104C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X104C);
    // 0x802053BC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x802053C0: nop

    // 0x802053C4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802053C8: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x802053CC: swc1        $f6, -0x4EDC($at)
    MEM_W(-0X4EDC, ctx->r1) = ctx->f6.u32l;
    // 0x802053D0: lw          $t9, -0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, -0X3C);
    // 0x802053D4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802053D8: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802053DC: mflo        $t4
    ctx->r12 = lo;
    // 0x802053E0: addu        $t1, $s3, $t4
    ctx->r9 = ADD32(ctx->r19, ctx->r12);
    // 0x802053E4: lw          $t5, 0x1050($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X1050);
    // 0x802053E8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x802053EC: nop

    // 0x802053F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x802053F4: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x802053F8: swc1        $f16, -0x4ED8($at)
    MEM_W(-0X4ED8, ctx->r1) = ctx->f16.u32l;
    // 0x802053FC: lw          $t7, -0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X3C);
    // 0x80205400: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205404: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80205408: mflo        $t2
    ctx->r10 = lo;
    // 0x8020540C: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80205410: lw          $t6, 0x1054($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1054);
    // 0x80205414: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80205418: nop

    // 0x8020541C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80205420: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80205424: swc1        $f6, -0x4ED4($at)
    MEM_W(-0X4ED4, ctx->r1) = ctx->f6.u32l;
    // 0x80205428: lw          $t8, -0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X28);
    // 0x8020542C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205430: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80205434: nop

    // 0x80205438: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8020543C: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80205440: swc1        $f16, -0x4EC8($at)
    MEM_W(-0X4EC8, ctx->r1) = ctx->f16.u32l;
    // 0x80205444: lw          $t9, -0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, -0X14);
    // 0x80205448: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020544C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80205450: nop

    // 0x80205454: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80205458: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8020545C: swc1        $f6, -0x4ECC($at)
    MEM_W(-0X4ECC, ctx->r1) = ctx->f6.u32l;
    // 0x80205460: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80205464: b           L_802056E0
    // 0x80205468: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205468: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8020546C:
    // 0x8020546C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80205470: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80205474: lh          $v0, -0x4EDE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4EDE);
    // 0x80205478: lh          $v1, -0x4EE0($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4EE0);
    // 0x8020547C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80205480: or          $t4, $v1, $v0
    ctx->r12 = ctx->r3 | ctx->r2;
    // 0x80205484: beql        $t4, $zero, L_80205498
    if (ctx->r12 == 0) {
        // 0x80205488: sw          $s0, 0x94($s2)
        MEM_W(0X94, ctx->r18) = ctx->r16;
            goto L_80205498;
    }
    goto skip_16;
    // 0x80205488: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    skip_16:
    // 0x8020548C: b           L_802056F4
    // 0x80205490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x80205490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80205494: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
L_80205498:
    // 0x80205498: b           L_802056E0
    // 0x8020549C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x8020549C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802054A0:
    // 0x802054A0: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x802054A4: lh          $v0, -0x4EDE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4EDE);
    // 0x802054A8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x802054AC: beql        $v0, $zero, L_802054C0
    if (ctx->r2 == 0) {
        // 0x802054B0: sw          $s0, 0x94($s2)
        MEM_W(0X94, ctx->r18) = ctx->r16;
            goto L_802054C0;
    }
    goto skip_17;
    // 0x802054B0: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    skip_17:
    // 0x802054B4: b           L_802056F4
    // 0x802054B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802054B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802054BC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
L_802054C0:
    // 0x802054C0: b           L_802056E0
    // 0x802054C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802054C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802054C8:
    // 0x802054C8: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x802054CC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x802054D0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x802054D4: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x802054D8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x802054DC: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x802054E0: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x802054E4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x802054E8: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x802054EC: lw          $t1, 0x34($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X34);
    // 0x802054F0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x802054F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x802054F8: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x802054FC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80205500: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x80205504: jal         0x8012C4D0
    // 0x80205508: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_37;
    // 0x80205508: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_37:
    // 0x8020550C: beql        $v0, $zero, L_8020552C
    if (ctx->r2 == 0) {
        // 0x80205510: addiu       $s0, $s0, 0x64
        ctx->r16 = ADD32(ctx->r16, 0X64);
            goto L_8020552C;
    }
    goto skip_18;
    // 0x80205510: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    skip_18:
    // 0x80205514: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x80205518: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8020551C: nop

    // 0x80205520: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80205524: swc1        $f10, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f10.u32l;
    // 0x80205528: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
L_8020552C:
    // 0x8020552C: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80205530: b           L_802056E0
    // 0x80205534: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205534: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80205538:
    // 0x80205538: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8020553C: jalr        $v0
    // 0x80205540: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_38;
    // 0x80205540: nop

    after_38:
    // 0x80205544: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80205548: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x8020554C: b           L_802056E0
    // 0x80205550: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205550: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80205554:
    // 0x80205554: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80205558: jalr        $v0
    // 0x8020555C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_39;
    // 0x8020555C: nop

    after_39:
    // 0x80205560: bne         $v0, $zero, L_80205570
    if (ctx->r2 != 0) {
        // 0x80205564: addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
            goto L_80205570;
    }
    // 0x80205564: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80205568: b           L_802056F4
    // 0x8020556C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x8020556C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80205570:
    // 0x80205570: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x80205574: b           L_802056E0
    // 0x80205578: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205578: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8020557C:
    // 0x8020557C: jal         0x801FBB20
    // 0x80205580: nop

    LOOKUP_FUNC(0x801FBB20)(rdram, ctx);
        goto after_40;
    // 0x80205580: nop

    after_40:
    // 0x80205584: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80205588: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x8020558C: b           L_802056E0
    // 0x80205590: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x80205590: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80205594:
    // 0x80205594: jal         0x801FBB30
    // 0x80205598: nop

    LOOKUP_FUNC(0x801FBB30)(rdram, ctx);
        goto after_41;
    // 0x80205598: nop

    after_41:
    // 0x8020559C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x802055A0: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802055A4: b           L_802056E0
    // 0x802055A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802055A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802055AC:
    // 0x802055AC: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x802055B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x802055B4: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x802055B8: sh          $t3, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r11;
    // 0x802055BC: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802055C0: b           L_802056E0
    // 0x802055C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802055C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802055C8:
    // 0x802055C8: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x802055CC: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x802055D0: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x802055D4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x802055D8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x802055DC: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x802055E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x802055E4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x802055E8: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x802055EC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x802055F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x802055F4: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x802055F8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x802055FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80205600: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80205604: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80205608: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8020560C: nop

    // 0x80205610: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80205614: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80205618: div.s       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8020561C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80205620: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x80205624: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80205628: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8020562C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80205630: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80205634: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80205638: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8020563C: lw          $t7, 0x8C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8C);
    // 0x80205640: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80205644: nop

    // 0x80205648: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8020564C: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80205650: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80205654: lw          $t2, 0xA0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XA0);
    // 0x80205658: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8020565C: lw          $t3, 0xB4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XB4);
    // 0x80205660: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80205664: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x80205668: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8020566C: lw          $t8, 0xDC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDC);
    // 0x80205670: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80205674: lw          $t9, 0xF0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XF0);
    // 0x80205678: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8020567C: lw          $t4, 0x104($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X104);
    // 0x80205680: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80205684: lw          $t1, 0x118($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X118);
    // 0x80205688: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8020568C: lw          $t5, 0x12C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X12C);
    // 0x80205690: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80205694: lw          $t7, 0x140($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X140);
    // 0x80205698: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8020569C: nop

    // 0x802056A0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802056A4: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x802056A8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x802056AC: lw          $t2, 0x154($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X154);
    // 0x802056B0: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x802056B4: lw          $t3, 0x168($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X168);
    // 0x802056B8: jal         0x80129FB8
    // 0x802056BC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_42;
    // 0x802056BC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_42:
    // 0x802056C0: addiu       $s0, $s0, 0x17C
    ctx->r16 = ADD32(ctx->r16, 0X17C);
    // 0x802056C4: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802056C8: b           L_802056E0
    // 0x802056CC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_802056E0;
    // 0x802056CC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_802056D0:
    // 0x802056D0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x802056D4: sw          $s0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r16;
    // 0x802056D8: b           L_802056F4
    // 0x802056DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802056F4;
    // 0x802056DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802056E0:
    // 0x802056E0: lui         $at, 0x1234
    ctx->r1 = S32(0X1234 << 16);
L_802056E4:
    // 0x802056E4: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x802056E8: bnel        $v1, $at, L_80203EA4
    if (ctx->r3 != ctx->r1) {
        // 0x802056EC: lui         $at, 0xEDCB
        ctx->r1 = S32(0XEDCB << 16);
            goto L_80203EA4;
    }
    goto skip_19;
    // 0x802056EC: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
    skip_19:
L_802056F0:
    // 0x802056F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_802056F4:
    // 0x802056F4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x802056F8: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x802056FC: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x80205700: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x80205704: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x80205708: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x8020570C: lw          $s4, 0x64($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X64);
    // 0x80205710: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x80205714: jr          $ra
    // 0x80205718: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80205718: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_8020571c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_8020571c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8020571C: nop

;}
RECOMP_FUNC void M9_FUN_80205720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80205720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80205724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80205728: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8020572C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80205730: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80205734: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x80205738: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8020573C: jal         0x80133A24
    // 0x80205740: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80205740: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x80205744: beq         $v0, $zero, L_8020575C
    if (ctx->r2 == 0) {
        // 0x80205748: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8020575C;
    }
    // 0x80205748: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8020574C: jal         0x80005700
    // 0x80205750: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80205750: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80205754: b           L_80205770
    // 0x80205758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80205770;
    // 0x80205758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8020575C:
    // 0x8020575C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x80205760: addiu       $a1, $a1, 0x577C
    ctx->r5 = ADD32(ctx->r5, 0X577C);
    // 0x80205764: jal         0x800058DC
    // 0x80205768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80205768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8020576C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80205770:
    // 0x80205770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80205774: jr          $ra
    // 0x80205778: nop

    return;
    // 0x80205778: nop

;}
RECOMP_FUNC void M9_FUN_8020577c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8020577C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80205780: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80205784: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80205788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8020578C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80205790: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80205794: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80205798: jal         0x80126CC0
    // 0x8020579C: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x8020579C: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    after_0:
    // 0x802057A0: beq         $v0, $zero, L_80205A4C
    if (ctx->r2 == 0) {
        // 0x802057A4: lui         $t6, 0x8016
        ctx->r14 = S32(0X8016 << 16);
            goto L_80205A4C;
    }
    // 0x802057A4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x802057A8: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x802057AC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x802057B0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x802057B4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x802057B8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x802057BC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x802057C0: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x802057C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802057C8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x802057CC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x802057D0: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x802057D4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x802057D8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x802057DC: jal         0x80005E44
    // 0x802057E0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x802057E0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_1:
    // 0x802057E4: jal         0x80006214
    // 0x802057E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x802057E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x802057EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802057F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802057F4: addiu       $a2, $zero, 0x4DA
    ctx->r6 = ADD32(0, 0X4DA);
    // 0x802057F8: jal         0x8012C89C
    // 0x802057FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x802057FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80205800: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80205804: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80205808: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8020580C: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80205810: lui         $t3, 0x8021
    ctx->r11 = S32(0X8021 << 16);
    // 0x80205814: addiu       $t3, $t3, 0x7978
    ctx->r11 = ADD32(ctx->r11, 0X7978);
    // 0x80205818: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x8020581C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80205820: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80205824: ori         $t2, $t1, 0x300
    ctx->r10 = ctx->r9 | 0X300;
    // 0x80205828: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x8020582C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80205830: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80205834: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x80205838: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8020583C: addiu       $v1, $v1, 0x79D8
    ctx->r3 = ADD32(ctx->r3, 0X79D8);
    // 0x80205840: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    // 0x80205844: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80205848: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x8020584C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80205850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80205854: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80205858: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020585C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80205860: nop

    // 0x80205864: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80205868: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8020586C: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80205870: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80205874: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x80205878: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8020587C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80205880: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x80205884: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80205888: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8020588C: nop

    // 0x80205890: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80205894: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80205898: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8020589C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x802058A0: swc1        $f10, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f10.u32l;
    // 0x802058A4: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x802058A8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x802058AC: lh          $t6, 0xA($t4)
    ctx->r14 = MEM_H(ctx->r12, 0XA);
    // 0x802058B0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x802058B4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x802058B8: nop

    // 0x802058BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x802058C0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802058C4: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x802058C8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x802058CC: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x802058D0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802058D4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x802058D8: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x802058DC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802058E0: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x802058E4: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x802058E8: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x802058EC: sh          $t2, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r10;
    // 0x802058F0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802058F4: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x802058F8: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    // 0x802058FC: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80205900: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80205904: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80205908: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x8020590C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80205910: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80205914: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80205918: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8020591C: sb          $t3, 0x48($t5)
    MEM_B(0X48, ctx->r13) = ctx->r11;
    // 0x80205920: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80205924: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80205928: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8020592C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80205930: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80205934: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80205938: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8020593C: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x80205940: sb          $t0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r8;
    // 0x80205944: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80205948: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8020594C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80205950: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x80205954: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80205958: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
    // 0x8020595C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80205960: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80205964: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x80205968: sb          $t8, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r24;
    // 0x8020596C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80205970: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80205974: sb          $t0, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r8;
    // 0x80205978: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8020597C: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x80205980: lbu         $t4, 0x48($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X48);
    // 0x80205984: sb          $t4, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r12;
    // 0x80205988: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020598C: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80205990: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x80205994: sb          $t7, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r15;
    // 0x80205998: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8020599C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802059A0: lbu         $t8, 0x4A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4A);
    // 0x802059A4: sb          $t8, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r24;
    // 0x802059A8: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x802059AC: ori         $t2, $t1, 0x800
    ctx->r10 = ctx->r9 | 0X800;
    // 0x802059B0: jal         0x8012C97C
    // 0x802059B4: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_4;
    // 0x802059B4: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    after_4:
    // 0x802059B8: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x802059BC: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x802059C0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x802059C4: lh          $t0, 0x6($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X6);
    // 0x802059C8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x802059CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x802059D0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x802059D4: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x802059D8: addiu       $a1, $a1, 0x5A60
    ctx->r5 = ADD32(ctx->r5, 0X5A60);
    // 0x802059DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802059E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802059E4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802059E8: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x802059EC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x802059F0: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x802059F4: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x802059F8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x802059FC: nop

    // 0x80205A00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80205A04: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80205A08: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x80205A0C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80205A10: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    // 0x80205A14: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x80205A18: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80205A1C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80205A20: nop

    // 0x80205A24: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80205A28: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80205A2C: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80205A30: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80205A34: swc1        $f18, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f18.u32l;
    // 0x80205A38: lh          $t4, 0xC($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XC);
    // 0x80205A3C: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80205A40: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x80205A44: jal         0x800058DC
    // 0x80205A48: sh          $t4, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80205A48: sh          $t4, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r12;
    after_5:
L_80205A4C:
    // 0x80205A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80205A50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80205A54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80205A58: jr          $ra
    // 0x80205A5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80205A5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80205a60(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80205a60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80205A60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80205A64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80205A68: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80205A6C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80205A70: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80205A74: lui         $t8, 0x8021
    ctx->r24 = S32(0X8021 << 16);
    // 0x80205A78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80205A7C: lw          $v1, 0x10($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X10);
    // 0x80205A80: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80205A84: addiu       $t8, $t8, 0x79D8
    ctx->r24 = ADD32(ctx->r24, 0X79D8);
    // 0x80205A88: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80205A8C: beq         $v1, $zero, L_80205DF0
    if (ctx->r3 == 0) {
        // 0x80205A90: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_80205DF0;
    }
    // 0x80205A90: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80205A94: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80205A98: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x80205A9C: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x80205AA0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80205AA4: sb          $t9, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r25;
    // 0x80205AA8: sb          $t0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r8;
    // 0x80205AAC: lhu         $a0, 0x3C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3C);
    // 0x80205AB0: sb          $a1, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r5;
    // 0x80205AB4: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80205AB8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80205ABC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80205AC0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80205AC4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205AC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80205ACC: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80205AD0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205AD4: jal         0x8001EAD0
    // 0x80205AD8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80205AD8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80205ADC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205AE0: ldc1        $f2, -0x5A20($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X5A20);
    // 0x80205AE4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80205AE8: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80205AEC: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80205AF0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80205AF4: subu        $t2, $t1, $a1
    ctx->r10 = SUB32(ctx->r9, ctx->r5);
    // 0x80205AF8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80205AFC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80205B00: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80205B04: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80205B08: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x80205B0C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80205B10: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80205B14: bgezl       $a1, L_80205B30
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80205B18: add.d       $f8, $f18, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
            goto L_80205B30;
    }
    goto skip_0;
    // 0x80205B18: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    skip_0:
    // 0x80205B1C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80205B20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80205B24: nop

    // 0x80205B28: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
    // 0x80205B2C: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
L_80205B30:
    // 0x80205B30: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80205B34: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80205B38: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80205B3C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80205B40: nop

    // 0x80205B44: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80205B48: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80205B4C: nop

    // 0x80205B50: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80205B54: beql        $t4, $zero, L_80205BA8
    if (ctx->r12 == 0) {
        // 0x80205B58: mfc1        $t4, $f16
        ctx->r12 = (int32_t)ctx->f16.u32l;
            goto L_80205BA8;
    }
    goto skip_1;
    // 0x80205B58: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x80205B5C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80205B60: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80205B64: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80205B68: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x80205B6C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80205B70: nop

    // 0x80205B74: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x80205B78: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80205B7C: nop

    // 0x80205B80: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80205B84: bne         $t4, $zero, L_80205B9C
    if (ctx->r12 != 0) {
        // 0x80205B88: nop
    
            goto L_80205B9C;
    }
    // 0x80205B88: nop

    // 0x80205B8C: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80205B90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80205B94: b           L_80205BB4
    // 0x80205B98: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80205BB4;
    // 0x80205B98: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80205B9C:
    // 0x80205B9C: b           L_80205BB4
    // 0x80205BA0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80205BB4;
    // 0x80205BA0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80205BA4: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
L_80205BA8:
    // 0x80205BA8: nop

    // 0x80205BAC: bltz        $t4, L_80205B9C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80205BB0: nop
    
            goto L_80205B9C;
    }
    // 0x80205BB0: nop

L_80205BB4:
    // 0x80205BB4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80205BB8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80205BBC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80205BC0: sb          $t4, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r12;
    // 0x80205BC4: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80205BC8: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80205BCC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80205BD0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80205BD4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80205BD8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205BDC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80205BE0: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80205BE4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205BE8: jal         0x8001EAD0
    // 0x80205BEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80205BEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80205BF0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205BF4: ldc1        $f2, -0x5A18($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X5A18);
    // 0x80205BF8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80205BFC: lbu         $v0, 0x2E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2E);
    // 0x80205C00: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80205C04: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80205C08: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80205C0C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80205C10: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80205C14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80205C18: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80205C1C: add.d       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f10.d + ctx->f2.d;
    // 0x80205C20: cvt.d.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = CVT_D_W(ctx->f4.u32l);
    // 0x80205C24: mul.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80205C28: bgezl       $v0, L_80205C44
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80205C2C: add.d       $f18, $f16, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
            goto L_80205C44;
    }
    goto skip_2;
    // 0x80205C2C: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    skip_2:
    // 0x80205C30: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80205C34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80205C38: nop

    // 0x80205C3C: add.d       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f10.d + ctx->f6.d;
    // 0x80205C40: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
L_80205C44:
    // 0x80205C44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80205C48: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80205C4C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80205C50: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80205C54: nop

    // 0x80205C58: cvt.w.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_D(ctx->f18.d);
    // 0x80205C5C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80205C60: nop

    // 0x80205C64: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80205C68: beql        $t0, $zero, L_80205CBC
    if (ctx->r8 == 0) {
        // 0x80205C6C: mfc1        $t0, $f8
        ctx->r8 = (int32_t)ctx->f8.u32l;
            goto L_80205CBC;
    }
    goto skip_3;
    // 0x80205C6C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x80205C70: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80205C74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80205C78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80205C7C: sub.d       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f18.d - ctx->f8.d;
    // 0x80205C80: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80205C84: nop

    // 0x80205C88: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x80205C8C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80205C90: nop

    // 0x80205C94: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80205C98: bne         $t0, $zero, L_80205CB0
    if (ctx->r8 != 0) {
        // 0x80205C9C: nop
    
            goto L_80205CB0;
    }
    // 0x80205C9C: nop

    // 0x80205CA0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80205CA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80205CA8: b           L_80205CC8
    // 0x80205CAC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80205CC8;
    // 0x80205CAC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80205CB0:
    // 0x80205CB0: b           L_80205CC8
    // 0x80205CB4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80205CC8;
    // 0x80205CB4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80205CB8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
L_80205CBC:
    // 0x80205CBC: nop

    // 0x80205CC0: bltz        $t0, L_80205CB0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80205CC4: nop
    
            goto L_80205CB0;
    }
    // 0x80205CC4: nop

L_80205CC8:
    // 0x80205CC8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80205CCC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80205CD0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80205CD4: sb          $t0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r8;
    // 0x80205CD8: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80205CDC: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80205CE0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80205CE4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80205CE8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80205CEC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205CF0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80205CF4: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80205CF8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205CFC: jal         0x8001EAD0
    // 0x80205D00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80205D00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x80205D04: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80205D08: ldc1        $f2, -0x5A10($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X5A10);
    // 0x80205D0C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80205D10: lbu         $v0, 0x2D($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2D);
    // 0x80205D14: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80205D18: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80205D1C: subu        $t5, $t3, $v0
    ctx->r13 = SUB32(ctx->r11, ctx->r2);
    // 0x80205D20: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80205D24: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80205D28: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80205D2C: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80205D30: add.d       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f6.d + ctx->f2.d;
    // 0x80205D34: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80205D38: mul.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80205D3C: bgezl       $v0, L_80205D58
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80205D40: add.d       $f16, $f8, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
            goto L_80205D58;
    }
    goto skip_4;
    // 0x80205D40: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    skip_4:
    // 0x80205D44: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80205D48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80205D4C: nop

    // 0x80205D50: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
    // 0x80205D54: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
L_80205D58:
    // 0x80205D58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80205D5C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80205D60: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80205D64: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80205D68: nop

    // 0x80205D6C: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x80205D70: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80205D74: nop

    // 0x80205D78: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80205D7C: beql        $t6, $zero, L_80205DD0
    if (ctx->r14 == 0) {
        // 0x80205D80: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_80205DD0;
    }
    goto skip_5;
    // 0x80205D80: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x80205D84: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80205D88: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80205D8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80205D90: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x80205D94: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80205D98: nop

    // 0x80205D9C: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80205DA0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80205DA4: nop

    // 0x80205DA8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80205DAC: bne         $t6, $zero, L_80205DC4
    if (ctx->r14 != 0) {
        // 0x80205DB0: nop
    
            goto L_80205DC4;
    }
    // 0x80205DB0: nop

    // 0x80205DB4: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80205DB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80205DBC: b           L_80205DDC
    // 0x80205DC0: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80205DDC;
    // 0x80205DC0: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80205DC4:
    // 0x80205DC4: b           L_80205DDC
    // 0x80205DC8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80205DDC;
    // 0x80205DC8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80205DCC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_80205DD0:
    // 0x80205DD0: nop

    // 0x80205DD4: bltz        $t6, L_80205DC4
    if (SIGNED(ctx->r14) < 0) {
        // 0x80205DD8: nop
    
            goto L_80205DC4;
    }
    // 0x80205DD8: nop

L_80205DDC:
    // 0x80205DDC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80205DE0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80205DE4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80205DE8: b           L_8020607C
    // 0x80205DEC: sb          $t6, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r14;
        goto L_8020607C;
    // 0x80205DEC: sb          $t6, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r14;
L_80205DF0:
    // 0x80205DF0: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80205DF4: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80205DF8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80205DFC: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80205E00: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80205E04: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80205E08: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80205E0C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205E10: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80205E14: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80205E18: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205E1C: jal         0x8001EAD0
    // 0x80205E20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x80205E20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x80205E24: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80205E28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80205E2C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80205E30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80205E34: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80205E38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80205E3C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80205E40: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80205E44: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80205E48: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80205E4C: nop

    // 0x80205E50: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80205E54: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80205E58: nop

    // 0x80205E5C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80205E60: beql        $t1, $zero, L_80205EB0
    if (ctx->r9 == 0) {
        // 0x80205E64: mfc1        $t1, $f16
        ctx->r9 = (int32_t)ctx->f16.u32l;
            goto L_80205EB0;
    }
    goto skip_6;
    // 0x80205E64: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    skip_6:
    // 0x80205E68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80205E6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80205E70: sub.s       $f16, $f6, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80205E74: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80205E78: nop

    // 0x80205E7C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80205E80: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80205E84: nop

    // 0x80205E88: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80205E8C: bne         $t1, $zero, L_80205EA4
    if (ctx->r9 != 0) {
        // 0x80205E90: nop
    
            goto L_80205EA4;
    }
    // 0x80205E90: nop

    // 0x80205E94: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80205E98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80205E9C: b           L_80205EBC
    // 0x80205EA0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80205EBC;
    // 0x80205EA0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80205EA4:
    // 0x80205EA4: b           L_80205EBC
    // 0x80205EA8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80205EBC;
    // 0x80205EA8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80205EAC: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
L_80205EB0:
    // 0x80205EB0: nop

    // 0x80205EB4: bltz        $t1, L_80205EA4
    if (SIGNED(ctx->r9) < 0) {
        // 0x80205EB8: nop
    
            goto L_80205EA4;
    }
    // 0x80205EB8: nop

L_80205EBC:
    // 0x80205EBC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80205EC0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80205EC4: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80205EC8: sb          $t1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r9;
    // 0x80205ECC: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80205ED0: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80205ED4: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80205ED8: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80205EDC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80205EE0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205EE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80205EE8: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80205EEC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205EF0: jal         0x8001EAD0
    // 0x80205EF4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x80205EF4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x80205EF8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80205EFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80205F00: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80205F04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80205F08: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80205F0C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80205F10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80205F14: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80205F18: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80205F1C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80205F20: nop

    // 0x80205F24: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80205F28: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80205F2C: nop

    // 0x80205F30: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80205F34: beql        $t5, $zero, L_80205F84
    if (ctx->r13 == 0) {
        // 0x80205F38: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_80205F84;
    }
    goto skip_7;
    // 0x80205F38: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_7:
    // 0x80205F3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80205F40: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80205F44: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80205F48: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80205F4C: nop

    // 0x80205F50: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80205F54: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80205F58: nop

    // 0x80205F5C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80205F60: bne         $t5, $zero, L_80205F78
    if (ctx->r13 != 0) {
        // 0x80205F64: nop
    
            goto L_80205F78;
    }
    // 0x80205F64: nop

    // 0x80205F68: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80205F6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80205F70: b           L_80205F90
    // 0x80205F74: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80205F90;
    // 0x80205F74: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80205F78:
    // 0x80205F78: b           L_80205F90
    // 0x80205F7C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80205F90;
    // 0x80205F7C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80205F80: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_80205F84:
    // 0x80205F84: nop

    // 0x80205F88: bltz        $t5, L_80205F78
    if (SIGNED(ctx->r13) < 0) {
        // 0x80205F8C: nop
    
            goto L_80205F78;
    }
    // 0x80205F8C: nop

L_80205F90:
    // 0x80205F90: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80205F94: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80205F98: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80205F9C: sb          $t5, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r13;
    // 0x80205FA0: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x80205FA4: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80205FA8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80205FAC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80205FB0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80205FB4: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80205FB8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80205FBC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205FC0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80205FC4: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80205FC8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80205FCC: jal         0x8001EAD0
    // 0x80205FD0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x80205FD0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
    // 0x80205FD4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80205FD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80205FDC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80205FE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80205FE4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80205FE8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80205FEC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80205FF0: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80205FF4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80205FF8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80205FFC: nop

    // 0x80206000: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80206004: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80206008: nop

    // 0x8020600C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80206010: beql        $t8, $zero, L_80206060
    if (ctx->r24 == 0) {
        // 0x80206014: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_80206060;
    }
    goto skip_8;
    // 0x80206014: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_8:
    // 0x80206018: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8020601C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80206020: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80206024: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80206028: nop

    // 0x8020602C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80206030: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80206034: nop

    // 0x80206038: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8020603C: bne         $t8, $zero, L_80206054
    if (ctx->r24 != 0) {
        // 0x80206040: nop
    
            goto L_80206054;
    }
    // 0x80206040: nop

    // 0x80206044: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80206048: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8020604C: b           L_8020606C
    // 0x80206050: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8020606C;
    // 0x80206050: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80206054:
    // 0x80206054: b           L_8020606C
    // 0x80206058: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8020606C;
    // 0x80206058: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8020605C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_80206060:
    // 0x80206060: nop

    // 0x80206064: bltz        $t8, L_80206054
    if (SIGNED(ctx->r24) < 0) {
        // 0x80206068: nop
    
            goto L_80206054;
    }
    // 0x80206068: nop

L_8020606C:
    // 0x8020606C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80206070: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80206074: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80206078: sb          $t8, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r24;
L_8020607C:
    // 0x8020607C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80206080: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80206084: lbu         $t2, 0x48($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X48);
    // 0x80206088: sb          $t2, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r10;
    // 0x8020608C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80206090: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80206094: lbu         $t4, 0x49($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X49);
    // 0x80206098: sb          $t4, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r12;
    // 0x8020609C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x802060A0: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x802060A4: lbu         $t7, 0x4A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4A);
    // 0x802060A8: sb          $t7, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r15;
    // 0x802060AC: lhu         $t6, 0x3C($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X3C);
    // 0x802060B0: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x802060B4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x802060B8: sh          $t9, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r25;
    // 0x802060BC: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    // 0x802060C0: jal         0x80133A24
    // 0x802060C4: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_6;
    // 0x802060C4: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_6:
    // 0x802060C8: beql        $v0, $zero, L_80206108
    if (ctx->r2 == 0) {
        // 0x802060CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80206108;
    }
    goto skip_9;
    // 0x802060CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x802060D0: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802060D4: addiu       $t1, $zero, 0x154
    ctx->r9 = ADD32(0, 0X154);
    // 0x802060D8: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    // 0x802060DC: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x802060E0: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x802060E4: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x802060E8: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x802060EC: jal         0x801FC830
    // 0x802060F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_7;
    // 0x802060F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_7:
    // 0x802060F4: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x802060F8: addiu       $a1, $a1, 0x6118
    ctx->r5 = ADD32(ctx->r5, 0X6118);
    // 0x802060FC: jal         0x800058DC
    // 0x80206100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x80206100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80206104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80206108:
    // 0x80206108: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8020610C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80206110: jr          $ra
    // 0x80206114: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80206114: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80206118(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80206118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8020611C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80206120: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80206124: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80206128: lbu         $t7, 0x4B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4B);
    // 0x8020612C: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x80206130: sb          $t8, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r24;
    // 0x80206134: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80206138: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020613C: lbu         $t1, 0x4B($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4B);
    // 0x80206140: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80206144: beql        $at, $zero, L_80206174
    if (ctx->r1 == 0) {
        // 0x80206148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80206174;
    }
    goto skip_0;
    // 0x80206148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8020614C: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80206150: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80206154: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80206158: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x8020615C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80206160: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x80206164: addiu       $a1, $a1, 0x6180
    ctx->r5 = ADD32(ctx->r5, 0X6180);
    // 0x80206168: jal         0x800058DC
    // 0x8020616C: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8020616C: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
    after_0:
    // 0x80206170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80206174:
    // 0x80206174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80206178: jr          $ra
    // 0x8020617C: nop

    return;
    // 0x8020617C: nop

;}
RECOMP_FUNC void M9_FUN_80206180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206180: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80206184: jr          $ra
    // 0x80206188: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80206188: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_8020618c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_8020618c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8020618C: nop

;}
RECOMP_FUNC void M9_FUN_80206190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206190: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80206194: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80206198: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8020619C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x802061A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x802061A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802061A8: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x802061AC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x802061B0: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x802061B4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x802061B8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x802061BC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x802061C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x802061C4: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x802061C8: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x802061CC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x802061D0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x802061D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x802061D8: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x802061DC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x802061E0: sw          $t7, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r15;
    // 0x802061E4: jal         0x80005E44
    // 0x802061E8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802061E8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_0:
    // 0x802061EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x802061F0: jal         0x80005E44
    // 0x802061F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x802061F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x802061F8: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x802061FC: ori         $t0, $t0, 0x600
    ctx->r8 = ctx->r8 | 0X600;
    // 0x80206200: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80206204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80206208: jal         0x80005E44
    // 0x8020620C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x8020620C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80206210: lbu         $t1, 0xAC($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XAC);
    // 0x80206214: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80206218: ori         $t3, $t3, 0x900
    ctx->r11 = ctx->r11 | 0X900;
    // 0x8020621C: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x80206220: beq         $t2, $zero, L_80206234
    if (ctx->r10 == 0) {
        // 0x80206224: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80206234;
    }
    // 0x80206224: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80206228: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8020622C: jal         0x80005E44
    // 0x80206230: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_3;
    // 0x80206230: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80206234:
    // 0x80206234: jal         0x80006214
    // 0x80206238: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x80206238: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8020623C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80206240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80206244: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x80206248: jal         0x8012C89C
    // 0x8020624C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x8020624C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80206250: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80206254: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
    // 0x80206258: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8020625C: sw          $t4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r12;
    // 0x80206260: jal         0x8000C3B0
    // 0x80206264: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_6;
    // 0x80206264: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80206268: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8020626C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206270: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80206274: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80206278: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8020627C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80206280: sw          $v0, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r2;
    // 0x80206284: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80206288: lwc1        $f4, -0x584C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X584C);
    // 0x8020628C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80206290: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80206294: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x80206298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8020629C: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x802062A0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802062A4: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x802062A8: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x802062AC: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x802062B0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802062B4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802062B8: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x802062BC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802062C0: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x802062C4: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
    // 0x802062C8: ori         $t6, $t4, 0x400
    ctx->r14 = ctx->r12 | 0X400;
    // 0x802062CC: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x802062D0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802062D4: lbu         $t7, 0xF32($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XF32);
    // 0x802062D8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x802062DC: sb          $t7, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r15;
    // 0x802062E0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802062E4: lbu         $t0, 0xF33($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XF33);
    // 0x802062E8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802062EC: sb          $t0, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = ctx->r8;
    // 0x802062F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802062F4: lbu         $t3, 0xF34($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XF34);
    // 0x802062F8: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x802062FC: sb          $t3, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r11;
    // 0x80206300: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80206304: lbu         $t6, 0xF35($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XF35);
    // 0x80206308: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x8020630C: jal         0x8012C89C
    // 0x80206310: sb          $t6, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_7;
    // 0x80206310: sb          $t6, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r14;
    after_7:
    // 0x80206314: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80206318: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x8020631C: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x80206320: sw          $t9, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r25;
    // 0x80206324: jal         0x8000C3B0
    // 0x80206328: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_8;
    // 0x80206328: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x8020632C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80206330: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206334: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80206338: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x8020633C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80206340: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x80206344: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x80206348: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8020634C: lwc1        $f6, -0x5848($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5848);
    // 0x80206350: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80206354: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80206358: swc1        $f6, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f6.u32l;
    // 0x8020635C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80206360: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x80206364: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80206368: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x8020636C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80206370: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80206374: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x80206378: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8020637C: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x80206380: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x80206384: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x80206388: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x8020638C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80206390: lbu         $t2, 0xF32($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0XF32);
    // 0x80206394: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x80206398: sb          $t2, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r10;
    // 0x8020639C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x802063A0: lbu         $t4, 0xF33($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XF33);
    // 0x802063A4: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x802063A8: sb          $t4, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r12;
    // 0x802063AC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x802063B0: lbu         $t7, 0xF34($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XF34);
    // 0x802063B4: lw          $t9, 0x30($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X30);
    // 0x802063B8: sb          $t7, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r15;
    // 0x802063BC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x802063C0: lbu         $t0, 0xF35($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XF35);
    // 0x802063C4: lw          $t2, 0x30($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X30);
    // 0x802063C8: jal         0x8012C89C
    // 0x802063CC: sb          $t0, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r8;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_9;
    // 0x802063CC: sb          $t0, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r8;
    after_9:
    // 0x802063D0: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x802063D4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802063D8: lwc1        $f0, -0x5844($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5844);
    // 0x802063DC: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802063E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x802063E4: addiu       $t6, $t6, -0x4A58
    ctx->r14 = ADD32(ctx->r14, -0X4A58);
    // 0x802063E8: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x802063EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802063F0: or          $t1, $t6, $at
    ctx->r9 = ctx->r14 | ctx->r1;
    // 0x802063F4: ori         $t4, $t8, 0x100
    ctx->r12 = ctx->r24 | 0X100;
    // 0x802063F8: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x802063FC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80206400: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206404: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80206408: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x8020640C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80206410: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80206414: sw          $t1, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r9;
    // 0x80206418: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8020641C: addiu       $t9, $zero, 0x60
    ctx->r25 = ADD32(0, 0X60);
    // 0x80206420: addiu       $a2, $zero, 0xE2
    ctx->r6 = ADD32(0, 0XE2);
    // 0x80206424: lw          $t0, 0x30($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X30);
    // 0x80206428: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x8020642C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80206430: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206434: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80206438: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x8020643C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80206440: lwc1        $f8, -0x5840($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5840);
    // 0x80206444: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x80206448: swc1        $f8, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f8.u32l;
    // 0x8020644C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80206450: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80206454: lw          $t1, 0x30($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X30);
    // 0x80206458: sb          $t6, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r14;
    // 0x8020645C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80206460: lw          $t0, 0x30($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X30);
    // 0x80206464: sb          $t9, 0x49($t0)
    MEM_B(0X49, ctx->r8) = ctx->r25;
    // 0x80206468: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x8020646C: lw          $t8, 0x30($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X30);
    // 0x80206470: sb          $t2, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r10;
    // 0x80206474: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80206478: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x8020647C: sb          $t4, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r12;
    // 0x80206480: lbu         $v1, 0xAC($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XAC);
    // 0x80206484: andi        $t1, $v1, 0x40
    ctx->r9 = ctx->r3 & 0X40;
    // 0x80206488: beql        $t1, $zero, L_802064A0
    if (ctx->r9 == 0) {
        // 0x8020648C: andi        $t9, $v1, 0x20
        ctx->r25 = ctx->r3 & 0X20;
            goto L_802064A0;
    }
    goto skip_0;
    // 0x8020648C: andi        $t9, $v1, 0x20
    ctx->r25 = ctx->r3 & 0X20;
    skip_0:
    // 0x80206490: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80206494: sb          $zero, 0x22($t5)
    MEM_B(0X22, ctx->r13) = 0;
    // 0x80206498: lbu         $v1, 0xAC($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XAC);
    // 0x8020649C: andi        $t9, $v1, 0x20
    ctx->r25 = ctx->r3 & 0X20;
L_802064A0:
    // 0x802064A0: beq         $t9, $zero, L_80206550
    if (ctx->r25 == 0) {
        // 0x802064A4: nop
    
            goto L_80206550;
    }
    // 0x802064A4: nop

    // 0x802064A8: jal         0x8012C89C
    // 0x802064AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_10;
    // 0x802064AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x802064B0: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x802064B4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x802064B8: addiu       $t8, $t8, -0x5070
    ctx->r24 = ADD32(ctx->r24, -0X5070);
    // 0x802064BC: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x802064C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802064C4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x802064C8: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x802064CC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802064D0: ori         $t2, $t3, 0x400
    ctx->r10 = ctx->r11 | 0X400;
    // 0x802064D4: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x802064D8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x802064DC: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x802064E0: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
    // 0x802064E4: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x802064E8: lwc1        $f10, -0x583C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X583C);
    // 0x802064EC: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x802064F0: swc1        $f10, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f10.u32l;
    // 0x802064F4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x802064F8: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802064FC: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80206500: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80206504: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x80206508: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x8020650C: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x80206510: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80206514: lbu         $t2, 0xF32($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0XF32);
    // 0x80206518: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x8020651C: sb          $t2, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r10;
    // 0x80206520: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80206524: lbu         $t7, 0xF33($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XF33);
    // 0x80206528: lw          $t1, 0x30($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X30);
    // 0x8020652C: sb          $t7, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r15;
    // 0x80206530: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80206534: lbu         $t5, 0xF34($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XF34);
    // 0x80206538: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020653C: sb          $t5, 0x4E($t0)
    MEM_B(0X4E, ctx->r8) = ctx->r13;
    // 0x80206540: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80206544: lbu         $t3, 0xF35($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XF35);
    // 0x80206548: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x8020654C: sb          $t3, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r11;
L_80206550:
    // 0x80206550: jal         0x8012C6B4
    // 0x80206554: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80206554: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_11:
    // 0x80206558: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8020655C: addiu       $t4, $v0, 0x14
    ctx->r12 = ADD32(ctx->r2, 0X14);
    // 0x80206560: addiu       $t6, $zero, 0x1C7
    ctx->r14 = ADD32(0, 0X1C7);
    // 0x80206564: sh          $t4, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r12;
    // 0x80206568: sh          $zero, 0x92($s2)
    MEM_H(0X92, ctx->r18) = 0;
    // 0x8020656C: sh          $zero, 0xA6($s2)
    MEM_H(0XA6, ctx->r18) = 0;
    // 0x80206570: sh          $t6, 0xA0($s2)
    MEM_H(0XA0, ctx->r18) = ctx->r14;
    // 0x80206574: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
    // 0x80206578: swc1        $f0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f0.u32l;
    // 0x8020657C: swc1        $f0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f0.u32l;
    // 0x80206580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80206584: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80206588: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8020658C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80206590: jr          $ra
    // 0x80206594: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80206594: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80206598(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80206598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206598: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8020659C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x802065A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802065A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802065A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802065AC: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x802065B0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x802065B4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x802065B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x802065BC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x802065C0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x802065C4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x802065C8: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x802065CC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x802065D0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x802065D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x802065D8: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x802065DC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x802065E0: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x802065E4: jal         0x80005E44
    // 0x802065E8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802065E8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x802065EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802065F0: jal         0x80005E44
    // 0x802065F4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x802065F4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x802065F8: jal         0x80006214
    // 0x802065FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x802065FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80206600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80206604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80206608: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x8020660C: jal         0x8012C89C
    // 0x80206610: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80206610: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x80206614: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80206618: addiu       $t1, $zero, 0x13
    ctx->r9 = ADD32(0, 0X13);
    // 0x8020661C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206620: sw          $t1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r9;
    // 0x80206624: jal         0x8000C3B0
    // 0x80206628: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_4;
    // 0x80206628: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x8020662C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80206630: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206634: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80206638: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8020663C: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80206640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80206644: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x80206648: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8020664C: lwc1        $f4, -0x5838($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5838);
    // 0x80206650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80206654: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80206658: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x8020665C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80206660: swc1        $f4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f4.u32l;
    // 0x80206664: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80206668: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x8020666C: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80206670: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80206674: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80206678: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x8020667C: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x80206680: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80206684: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x80206688: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x8020668C: ori         $t4, $t3, 0x400
    ctx->r12 = ctx->r11 | 0X400;
    // 0x80206690: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x80206694: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80206698: lbu         $t5, 0xF32($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XF32);
    // 0x8020669C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802066A0: sb          $t5, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r13;
    // 0x802066A4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802066A8: lbu         $t8, 0xF33($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XF33);
    // 0x802066AC: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x802066B0: sb          $t8, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = ctx->r24;
    // 0x802066B4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x802066B8: lbu         $t1, 0xF34($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XF34);
    // 0x802066BC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802066C0: sb          $t1, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r9;
    // 0x802066C4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802066C8: lbu         $t6, 0xF35($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XF35);
    // 0x802066CC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x802066D0: jal         0x8012C89C
    // 0x802066D4: sb          $t6, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x802066D4: sb          $t6, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r14;
    after_5:
    // 0x802066D8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x802066DC: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x802066E0: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x802066E4: sw          $t9, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r25;
    // 0x802066E8: jal         0x8000C3B0
    // 0x802066EC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_6;
    // 0x802066EC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x802066F0: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x802066F4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802066F8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802066FC: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x80206700: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80206704: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80206708: sw          $v0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r2;
    // 0x8020670C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80206710: lwc1        $f6, -0x5834($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5834);
    // 0x80206714: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80206718: swc1        $f6, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f6.u32l;
    // 0x8020671C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80206720: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x80206724: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80206728: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x8020672C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80206730: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80206734: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x80206738: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8020673C: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80206740: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    // 0x80206744: ori         $t3, $t2, 0x400
    ctx->r11 = ctx->r10 | 0X400;
    // 0x80206748: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x8020674C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80206750: lbu         $t1, 0xF32($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XF32);
    // 0x80206754: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80206758: sb          $t1, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r9;
    // 0x8020675C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80206760: lbu         $t6, 0xF33($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XF33);
    // 0x80206764: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80206768: sb          $t6, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r14;
    // 0x8020676C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80206770: lbu         $t9, 0xF34($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XF34);
    // 0x80206774: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206778: sb          $t9, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r25;
    // 0x8020677C: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80206780: lbu         $t4, 0xF35($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XF35);
    // 0x80206784: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x80206788: jal         0x8012C6B4
    // 0x8020678C: sb          $t4, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r12;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x8020678C: sb          $t4, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r12;
    after_7:
    // 0x80206790: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80206794: addiu       $t7, $v0, 0xA
    ctx->r15 = ADD32(ctx->r2, 0XA);
    // 0x80206798: sh          $t7, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r15;
    // 0x8020679C: lh          $a0, 0xA2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XA2);
    // 0x802067A0: jal         0x8001EAD0
    // 0x802067A4: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x802067A4: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
    after_8:
    // 0x802067A8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802067AC: ldc1        $f16, -0x5830($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X5830);
    // 0x802067B0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x802067B4: lh          $a0, 0xA2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XA2);
    // 0x802067B8: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x802067BC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x802067C0: jal         0x8001EB64
    // 0x802067C4: swc1        $f4, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x802067C4: swc1        $f4, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f4.u32l;
    after_9:
    // 0x802067C8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802067CC: ldc1        $f8, -0x5828($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X5828);
    // 0x802067D0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x802067D4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x802067D8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x802067DC: swc1        $f16, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f16.u32l;
    // 0x802067E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802067E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802067E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802067EC: jr          $ra
    // 0x802067F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x802067F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802067f4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802067f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802067F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x802067F8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x802067FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80206800: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80206804: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80206808: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8020680C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80206810: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80206814: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80206818: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8020681C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80206820: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80206824: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80206828: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8020682C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80206830: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80206834: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80206838: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8020683C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80206840: jal         0x80005E44
    // 0x80206844: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80206844: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80206848: jal         0x80006214
    // 0x8020684C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8020684C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80206850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80206854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80206858: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x8020685C: jal         0x8012C89C
    // 0x80206860: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80206860: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x80206864: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80206868: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8020686C: addiu       $t3, $t3, -0x4A58
    ctx->r11 = ADD32(ctx->r11, -0X4A58);
    // 0x80206870: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80206874: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80206878: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8020687C: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x80206880: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206884: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80206888: ori         $t2, $t1, 0x100
    ctx->r10 = ctx->r9 | 0X100;
    // 0x8020688C: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80206890: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80206894: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80206898: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x8020689C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802068A0: lwc1        $f4, -0x5820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5820);
    // 0x802068A4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802068A8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x802068AC: swc1        $f4, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f4.u32l;
    // 0x802068B0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802068B4: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802068B8: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x802068BC: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x802068C0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802068C4: lwc1        $f8, -0x581C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X581C);
    // 0x802068C8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802068CC: swc1        $f8, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f8.u32l;
    // 0x802068D0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802068D4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802068D8: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x802068DC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802068E0: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x802068E4: sb          $zero, 0x49($t4)
    MEM_B(0X49, ctx->r12) = 0;
    // 0x802068E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x802068EC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802068F0: sb          $zero, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = 0;
    // 0x802068F4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802068F8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x802068FC: sb          $v1, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r3;
    // 0x80206900: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80206904: lhu         $t0, 0xA0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XA0);
    // 0x80206908: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8020690C: sh          $t0, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r8;
    // 0x80206910: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80206914: lhu         $t3, 0xA2($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XA2);
    // 0x80206918: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x8020691C: sh          $t3, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r11;
    // 0x80206920: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80206924: lhu         $t6, 0xA4($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XA4);
    // 0x80206928: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8020692C: sh          $t6, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r14;
    // 0x80206930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80206934: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80206938: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8020693C: jr          $ra
    // 0x80206940: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80206940: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80206944(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80206944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206944: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80206948: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8020694C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80206950: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80206954: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80206958: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8020695C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80206960: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80206964: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80206968: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8020696C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80206970: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80206974: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80206978: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8020697C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80206980: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80206984: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80206988: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8020698C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80206990: jal         0x80005E44
    // 0x80206994: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80206994: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80206998: jal         0x80006214
    // 0x8020699C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8020699C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x802069A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802069A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802069A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x802069AC: jal         0x8012C89C
    // 0x802069B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x802069B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x802069B4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802069B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802069BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x802069C0: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x802069C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x802069C8: jal         0x8012CF8C
    // 0x802069CC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x802069CC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x802069D0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802069D4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x802069D8: addiu       $t4, $t4, -0x4A58
    ctx->r12 = ADD32(ctx->r12, -0X4A58);
    // 0x802069DC: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x802069E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802069E4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x802069E8: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x802069EC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802069F0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x802069F4: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x802069F8: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x802069FC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80206A00: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80206A04: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x80206A08: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80206A0C: lwc1        $f4, -0x5818($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5818);
    // 0x80206A10: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206A14: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80206A18: swc1        $f4, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f4.u32l;
    // 0x80206A1C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80206A20: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80206A24: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80206A28: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80206A2C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80206A30: lwc1        $f8, -0x5814($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5814);
    // 0x80206A34: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80206A38: swc1        $f8, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f8.u32l;
    // 0x80206A3C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80206A40: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80206A44: sb          $v1, 0x48($t4)
    MEM_B(0X48, ctx->r12) = ctx->r3;
    // 0x80206A48: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80206A4C: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80206A50: sb          $zero, 0x49($t5)
    MEM_B(0X49, ctx->r13) = 0;
    // 0x80206A54: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80206A58: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80206A5C: sb          $zero, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = 0;
    // 0x80206A60: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80206A64: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80206A68: sb          $v1, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r3;
    // 0x80206A6C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80206A70: lhu         $t1, 0xA0($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XA0);
    // 0x80206A74: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206A78: sh          $t1, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r9;
    // 0x80206A7C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80206A80: lhu         $t4, 0xA2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XA2);
    // 0x80206A84: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80206A88: sh          $t4, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r12;
    // 0x80206A8C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80206A90: lhu         $t7, 0xA4($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XA4);
    // 0x80206A94: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80206A98: sh          $t7, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r15;
    // 0x80206A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80206AA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80206AA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80206AA8: jr          $ra
    // 0x80206AAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80206AAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80206ab0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80206ab0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206AB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80206AB4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80206AB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80206ABC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80206AC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80206AC4: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80206AC8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80206ACC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80206AD0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80206AD4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80206AD8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80206ADC: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80206AE0: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80206AE4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80206AE8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80206AEC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80206AF0: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80206AF4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80206AF8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80206AFC: jal         0x80005E44
    // 0x80206B00: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80206B00: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80206B04: jal         0x80006214
    // 0x80206B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80206B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80206B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80206B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80206B14: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80206B18: jal         0x8012C89C
    // 0x80206B1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80206B1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80206B20: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80206B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80206B28: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80206B2C: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x80206B30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80206B34: jal         0x8012CF8C
    // 0x80206B38: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x80206B38: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x80206B3C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80206B40: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80206B44: addiu       $t4, $t4, -0x4A58
    ctx->r12 = ADD32(ctx->r12, -0X4A58);
    // 0x80206B48: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80206B4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80206B50: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80206B54: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x80206B58: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206B5C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80206B60: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x80206B64: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80206B68: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80206B6C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80206B70: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80206B74: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x80206B78: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80206B7C: lwc1        $f4, -0x5810($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5810);
    // 0x80206B80: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206B84: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80206B88: swc1        $f4, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f4.u32l;
    // 0x80206B8C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80206B90: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80206B94: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80206B98: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80206B9C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80206BA0: lwc1        $f8, -0x580C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X580C);
    // 0x80206BA4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80206BA8: swc1        $f8, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f8.u32l;
    // 0x80206BAC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80206BB0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80206BB4: sb          $v1, 0x48($t4)
    MEM_B(0X48, ctx->r12) = ctx->r3;
    // 0x80206BB8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80206BBC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80206BC0: sb          $t6, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r14;
    // 0x80206BC4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80206BC8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80206BCC: sb          $zero, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = 0;
    // 0x80206BD0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80206BD4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80206BD8: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    // 0x80206BDC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80206BE0: lwc1        $f10, 0x94($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80206BE4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206BE8: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x80206BEC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80206BF0: lwc1        $f16, 0x98($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80206BF4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80206BF8: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x80206BFC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80206C00: lwc1        $f18, 0x9C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80206C04: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80206C08: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    // 0x80206C0C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80206C10: lhu         $t8, 0xA0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XA0);
    // 0x80206C14: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80206C18: sh          $t8, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r24;
    // 0x80206C1C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80206C20: lhu         $t1, 0xA2($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XA2);
    // 0x80206C24: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206C28: sh          $t1, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r9;
    // 0x80206C2C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80206C30: lhu         $t4, 0xA4($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XA4);
    // 0x80206C34: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80206C38: sh          $t4, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r12;
    // 0x80206C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80206C40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80206C44: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80206C48: jr          $ra
    // 0x80206C4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80206C4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80206c50(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80206c50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206C50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80206C54: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80206C58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80206C5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80206C60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80206C64: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80206C68: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80206C6C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80206C70: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80206C74: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80206C78: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80206C7C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80206C80: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80206C84: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80206C88: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80206C8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80206C90: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80206C94: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80206C98: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80206C9C: jal         0x80005E44
    // 0x80206CA0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80206CA0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80206CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80206CA8: jal         0x80005E44
    // 0x80206CAC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80206CAC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80206CB0: jal         0x80006214
    // 0x80206CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80206CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80206CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80206CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80206CC0: addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // 0x80206CC4: jal         0x8012C89C
    // 0x80206CC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80206CC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80206CCC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80206CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80206CD4: addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // 0x80206CD8: lw          $a1, 0x30($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X30);
    // 0x80206CDC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80206CE0: jal         0x8012CF8C
    // 0x80206CE4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_4;
    // 0x80206CE4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_4:
    // 0x80206CE8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80206CEC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206CF0: lwc1        $f0, -0x5808($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5808);
    // 0x80206CF4: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80206CF8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80206CFC: addiu       $t0, $t0, -0x5070
    ctx->r8 = ADD32(ctx->r8, -0X5070);
    // 0x80206D00: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x80206D04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80206D08: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x80206D0C: ori         $t4, $t3, 0x400
    ctx->r12 = ctx->r11 | 0X400;
    // 0x80206D10: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x80206D14: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80206D18: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80206D1C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80206D20: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80206D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80206D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80206D2C: sw          $t0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r8;
    // 0x80206D30: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80206D34: addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // 0x80206D38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80206D3C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80206D40: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x80206D44: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80206D48: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80206D4C: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x80206D50: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80206D54: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206D58: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x80206D5C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80206D60: lbu         $t4, 0xF32($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XF32);
    // 0x80206D64: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80206D68: sb          $t4, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r12;
    // 0x80206D6C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80206D70: lbu         $t7, 0xF33($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF33);
    // 0x80206D74: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80206D78: sb          $t7, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r15;
    // 0x80206D7C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80206D80: lbu         $t1, 0xF34($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XF34);
    // 0x80206D84: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80206D88: sb          $t1, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r9;
    // 0x80206D8C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80206D90: lbu         $t5, 0xF35($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XF35);
    // 0x80206D94: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80206D98: sb          $t5, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = ctx->r13;
    // 0x80206D9C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80206DA0: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80206DA4: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80206DA8: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x80206DAC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80206DB0: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80206DB4: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x80206DB8: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x80206DBC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80206DC0: lwc1        $f8, 0x9C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80206DC4: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80206DC8: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x80206DCC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80206DD0: lhu         $t4, 0xA2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XA2);
    // 0x80206DD4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80206DD8: sh          $t4, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r12;
    // 0x80206DDC: jal         0x8012C89C
    // 0x80206DE0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x80206DE0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_5:
    // 0x80206DE4: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80206DE8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206DEC: lwc1        $f0, -0x5804($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5804);
    // 0x80206DF0: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x80206DF4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80206DF8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80206DFC: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80206E00: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80206E04: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80206E08: ori         $t9, $t7, 0x400
    ctx->r25 = ctx->r15 | 0X400;
    // 0x80206E0C: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x80206E10: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80206E14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80206E18: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80206E1C: sw          $t0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r8;
    // 0x80206E20: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x80206E24: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80206E28: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80206E2C: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x80206E30: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80206E34: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80206E38: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80206E3C: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80206E40: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x80206E44: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80206E48: lbu         $t9, 0xF32($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF32);
    // 0x80206E4C: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80206E50: sb          $t9, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r25;
    // 0x80206E54: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80206E58: lbu         $t3, 0xF33($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XF33);
    // 0x80206E5C: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80206E60: sb          $t3, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r11;
    // 0x80206E64: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80206E68: lbu         $t6, 0xF34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF34);
    // 0x80206E6C: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80206E70: sb          $t6, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r14;
    // 0x80206E74: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80206E78: lbu         $t2, 0xF35($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XF35);
    // 0x80206E7C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80206E80: sb          $t2, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r10;
    // 0x80206E84: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80206E88: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80206E8C: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x80206E90: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x80206E94: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x80206E98: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80206E9C: lw          $t8, 0x30($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X30);
    // 0x80206EA0: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80206EA4: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80206EA8: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80206EAC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80206EB0: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    // 0x80206EB4: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80206EB8: lhu         $t9, 0xA2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XA2);
    // 0x80206EBC: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80206EC0: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x80206EC4: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x80206EC8: ori         $t3, $t5, 0x800
    ctx->r11 = ctx->r13 | 0X800;
    // 0x80206ECC: jal         0x8012C97C
    // 0x80206ED0: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_6;
    // 0x80206ED0: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    after_6:
    // 0x80206ED4: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80206ED8: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80206EDC: lwc1        $f8, 0x9C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80206EE0: lhu         $t4, 0xA2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XA2);
    // 0x80206EE4: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80206EE8: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80206EEC: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80206EF0: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x80206EF4: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x80206EF8: swc1        $f8, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f8.u32l;
    // 0x80206EFC: sh          $t4, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r12;
    // 0x80206F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80206F04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80206F08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80206F0C: jr          $ra
    // 0x80206F10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80206F10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80206f14(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80206f14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80206F14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80206F18: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80206F1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80206F20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80206F24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80206F28: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80206F2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80206F30: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80206F34: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80206F38: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80206F3C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80206F40: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80206F44: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x80206F48: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80206F4C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80206F50: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80206F54: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80206F58: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80206F5C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80206F60: jal         0x80005E44
    // 0x80206F64: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80206F64: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80206F68: jal         0x80006214
    // 0x80206F6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80206F6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80206F70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80206F74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80206F78: addiu       $a2, $zero, 0xD4
    ctx->r6 = ADD32(0, 0XD4);
    // 0x80206F7C: jal         0x8012C89C
    // 0x80206F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80206F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80206F84: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80206F88: lui         $t0, 0x8021
    ctx->r8 = S32(0X8021 << 16);
    // 0x80206F8C: addiu       $t0, $t0, 0x7A00
    ctx->r8 = ADD32(ctx->r8, 0X7A00);
    // 0x80206F90: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80206F94: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80206F98: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80206F9C: sw          $t0, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r8;
    // 0x80206FA0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80206FA4: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    // 0x80206FA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80206FAC: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80206FB0: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x80206FB4: ori         $t5, $t4, 0x300
    ctx->r13 = ctx->r12 | 0X300;
    // 0x80206FB8: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x80206FBC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80206FC0: lwc1        $f4, -0x5800($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5800);
    // 0x80206FC4: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x80206FC8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80206FCC: swc1        $f4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f4.u32l;
    // 0x80206FD0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80206FD4: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80206FD8: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80206FDC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80206FE0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80206FE4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80206FE8: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x80206FEC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80206FF0: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80206FF4: sb          $v1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r3;
    // 0x80206FF8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80206FFC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80207000: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x80207004: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207008: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8020700C: sb          $t5, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r13;
    // 0x80207010: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80207014: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80207018: sb          $zero, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = 0;
    // 0x8020701C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207020: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x80207024: sb          $v1, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r3;
    // 0x80207028: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8020702C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207030: sb          $v1, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r3;
    // 0x80207034: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207038: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8020703C: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x80207040: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80207044: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80207048: sb          $v1, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r3;
    // 0x8020704C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80207050: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207054: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80207058: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x8020705C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207060: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207064: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x80207068: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x8020706C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207070: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207074: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207078: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
    // 0x8020707C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207080: lhu         $t4, 0xA2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XA2);
    // 0x80207084: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80207088: sh          $t4, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r12;
    // 0x8020708C: lw          $t7, 0x2C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X2C);
    // 0x80207090: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x80207094: jal         0x8012C97C
    // 0x80207098: sw          $t8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r24;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_3;
    // 0x80207098: sw          $t8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r24;
    after_3:
    // 0x8020709C: lwc1        $f16, 0x94($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X94);
    // 0x802070A0: lwc1        $f18, 0x98($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X98);
    // 0x802070A4: lwc1        $f4, 0x9C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x802070A8: lhu         $t9, 0xA2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XA2);
    // 0x802070AC: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x802070B0: sh          $zero, 0x84($s1)
    MEM_H(0X84, ctx->r17) = 0;
    // 0x802070B4: sh          $zero, 0x88($s1)
    MEM_H(0X88, ctx->r17) = 0;
    // 0x802070B8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x802070BC: swc1        $f16, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f16.u32l;
    // 0x802070C0: swc1        $f18, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f18.u32l;
    // 0x802070C4: swc1        $f4, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f4.u32l;
    // 0x802070C8: jal         0x8012C6B4
    // 0x802070CC: sh          $t9, 0x86($s1)
    MEM_H(0X86, ctx->r17) = ctx->r25;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x802070CC: sh          $t9, 0x86($s1)
    MEM_H(0X86, ctx->r17) = ctx->r25;
    after_4:
    // 0x802070D0: addiu       $t1, $v0, 0x1E
    ctx->r9 = ADD32(ctx->r2, 0X1E);
    // 0x802070D4: sh          $t1, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r9;
    // 0x802070D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802070DC: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x802070E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802070E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802070E8: sh          $zero, 0x7CAC($at)
    MEM_H(0X7CAC, ctx->r1) = 0;
    // 0x802070EC: jr          $ra
    // 0x802070F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x802070F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802070f4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802070f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802070F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x802070F8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x802070FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80207100: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80207104: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80207108: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8020710C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80207110: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80207114: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80207118: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8020711C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80207120: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80207124: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x80207128: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8020712C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80207130: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80207134: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80207138: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8020713C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80207140: jal         0x80005E44
    // 0x80207144: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80207144: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80207148: jal         0x80006214
    // 0x8020714C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8020714C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80207150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80207158: addiu       $a2, $zero, 0xDA
    ctx->r6 = ADD32(0, 0XDA);
    // 0x8020715C: jal         0x8012C89C
    // 0x80207160: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80207160: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80207164: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207168: addiu       $t0, $zero, 0x13
    ctx->r8 = ADD32(0, 0X13);
    // 0x8020716C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80207170: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80207174: addiu       $t3, $t3, -0x5070
    ctx->r11 = ADD32(ctx->r11, -0X5070);
    // 0x80207178: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8020717C: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80207180: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80207184: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80207188: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020718C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80207190: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80207194: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80207198: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x8020719C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802071A0: lwc1        $f4, -0x57FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X57FC);
    // 0x802071A4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x802071A8: swc1        $f4, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f4.u32l;
    // 0x802071AC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802071B0: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802071B4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802071B8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802071BC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802071C0: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x802071C4: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x802071C8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802071CC: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x802071D0: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x802071D4: ori         $t5, $t3, 0x400
    ctx->r13 = ctx->r11 | 0X400;
    // 0x802071D8: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x802071DC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x802071E0: lbu         $t4, 0xF32($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF32);
    // 0x802071E4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802071E8: sb          $t4, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r12;
    // 0x802071EC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802071F0: lbu         $t8, 0xF33($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF33);
    // 0x802071F4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x802071F8: sb          $t8, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r24;
    // 0x802071FC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207200: lbu         $t0, 0xF34($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XF34);
    // 0x80207204: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207208: sb          $t0, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r8;
    // 0x8020720C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207210: lbu         $t5, 0xF35($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF35);
    // 0x80207214: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x80207218: sb          $t5, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r13;
    // 0x8020721C: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80207220: sh          $zero, 0x92($s1)
    MEM_H(0X92, ctx->r17) = 0;
    // 0x80207224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80207228: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8020722C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80207230: jr          $ra
    // 0x80207234: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80207234: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80207238(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80207238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80207238: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8020723C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80207240: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80207244: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80207248: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8020724C: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80207250: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80207254: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80207258: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8020725C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80207260: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80207264: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80207268: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x8020726C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80207270: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80207274: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80207278: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x8020727C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80207280: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80207284: jal         0x80005E44
    // 0x80207288: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80207288: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_0:
    // 0x8020728C: jal         0x80006214
    // 0x80207290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80207290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80207294: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8020729C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x802072A0: jal         0x8012C89C
    // 0x802072A4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x802072A4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x802072A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802072AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802072B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x802072B4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x802072B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x802072BC: jal         0x8012D8C8
    // 0x802072C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_3;
    // 0x802072C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x802072C4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802072C8: lui         $t0, 0x6
    ctx->r8 = S32(0X6 << 16);
    // 0x802072CC: ori         $t0, $t0, 0x300
    ctx->r8 = ctx->r8 | 0X300;
    // 0x802072D0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802072D4: lui         $t3, 0x8021
    ctx->r11 = S32(0X8021 << 16);
    // 0x802072D8: addiu       $t3, $t3, 0x7B00
    ctx->r11 = ADD32(ctx->r11, 0X7B00);
    // 0x802072DC: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x802072E0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802072E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802072E8: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x802072EC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x802072F0: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x802072F4: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x802072F8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802072FC: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207300: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207304: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80207308: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8020730C: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207310: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207314: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80207318: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8020731C: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207320: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80207324: jal         0x8012C6B4
    // 0x80207328: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80207328: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    after_4:
    // 0x8020732C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80207330: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207334: ldc1        $f18, -0x57F8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X57F8);
    // 0x80207338: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x8020733C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207340: ldc1        $f6, -0x57F0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X57F0);
    // 0x80207344: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80207348: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8020734C: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80207350: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80207354: addiu       $t1, $zero, 0xE6
    ctx->r9 = ADD32(0, 0XE6);
    // 0x80207358: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8020735C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80207360: swc1        $f10, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f10.u32l;
    // 0x80207364: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207368: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x8020736C: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80207370: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80207374: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207378: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8020737C: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x80207380: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80207384: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80207388: sb          $a0, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r4;
    // 0x8020738C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207390: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80207394: sb          $t1, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r9;
    // 0x80207398: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8020739C: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x802073A0: sb          $zero, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = 0;
    // 0x802073A4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x802073A8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x802073AC: sb          $zero, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = 0;
    // 0x802073B0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802073B4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x802073B8: sb          $a0, 0x4C($t8)
    MEM_B(0X4C, ctx->r24) = ctx->r4;
    // 0x802073BC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802073C0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x802073C4: sb          $zero, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = 0;
    // 0x802073C8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802073CC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802073D0: sb          $zero, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = 0;
    // 0x802073D4: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x802073D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x802073DC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x802073E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x802073E4: jr          $ra
    // 0x802073E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x802073E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802073ec(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802073ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802073EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x802073F0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x802073F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802073F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802073FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80207400: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80207404: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80207408: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8020740C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80207410: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80207414: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80207418: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8020741C: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x80207420: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80207424: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80207428: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8020742C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80207430: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80207434: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80207438: jal         0x80005E44
    // 0x8020743C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020743C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80207440: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80207444: ori         $t0, $t0, 0x600
    ctx->r8 = ctx->r8 | 0X600;
    // 0x80207448: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8020744C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207450: jal         0x80005E44
    // 0x80207454: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80207454: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80207458: jal         0x80006214
    // 0x8020745C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x8020745C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80207460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80207468: addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // 0x8020746C: jal         0x8012C89C
    // 0x80207470: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80207470: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80207474: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207478: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8020747C: lwc1        $f2, -0x57E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X57E8);
    // 0x80207480: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80207484: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80207488: addiu       $t4, $t4, -0x5070
    ctx->r12 = ADD32(ctx->r12, -0X5070);
    // 0x8020748C: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x80207490: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80207494: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80207498: ori         $t3, $t2, 0x400
    ctx->r11 = ctx->r10 | 0X400;
    // 0x8020749C: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x802074A0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x802074A4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802074A8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x802074AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802074B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802074B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802074B8: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x802074BC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802074C0: addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // 0x802074C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x802074C8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x802074CC: swc1        $f2, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f2.u32l;
    // 0x802074D0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802074D4: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x802074D8: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802074DC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802074E0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802074E4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802074E8: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x802074EC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x802074F0: lbu         $t3, 0xF32($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF32);
    // 0x802074F4: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x802074F8: sb          $t3, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r11;
    // 0x802074FC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207500: lbu         $t5, 0xF33($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF33);
    // 0x80207504: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207508: sb          $t5, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r13;
    // 0x8020750C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207510: lbu         $t9, 0xF34($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF34);
    // 0x80207514: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80207518: sb          $t9, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r25;
    // 0x8020751C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207520: lbu         $t2, 0xF35($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF35);
    // 0x80207524: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80207528: jal         0x8012C89C
    // 0x8020752C: sb          $t2, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x8020752C: sb          $t2, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r10;
    after_4:
    // 0x80207530: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80207534: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207538: lwc1        $f2, -0x57E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X57E4);
    // 0x8020753C: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80207540: lui         $t8, 0x8021
    ctx->r24 = S32(0X8021 << 16);
    // 0x80207544: addiu       $t8, $t8, 0x7B60
    ctx->r24 = ADD32(ctx->r24, 0X7B60);
    // 0x80207548: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x8020754C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80207550: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x80207554: ori         $t5, $t7, 0x100
    ctx->r13 = ctx->r15 | 0X100;
    // 0x80207558: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x8020755C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80207560: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80207564: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80207568: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x8020756C: sw          $t0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r8;
    // 0x80207570: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80207574: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x80207578: swc1        $f2, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f2.u32l;
    // 0x8020757C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80207580: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x80207584: swc1        $f2, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f2.u32l;
    // 0x80207588: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8020758C: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x80207590: swc1        $f2, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f2.u32l;
    // 0x80207594: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80207598: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8020759C: sb          $v1, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r3;
    // 0x802075A0: lbu         $t0, 0x91($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X91);
    // 0x802075A4: bnel        $t0, $at, L_80207610
    if (ctx->r8 != ctx->r1) {
        // 0x802075A8: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_80207610;
    }
    goto skip_0;
    // 0x802075A8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x802075AC: lbu         $t1, 0xAC($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XAC);
    // 0x802075B0: andi        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 & 0X1;
    // 0x802075B4: bnel        $t4, $zero, L_802075E8
    if (ctx->r12 != 0) {
        // 0x802075B8: lw          $t9, 0x4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X4);
            goto L_802075E8;
    }
    goto skip_1;
    // 0x802075B8: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x802075BC: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x802075C0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802075C4: sb          $zero, 0x48($t3)
    MEM_B(0X48, ctx->r11) = 0;
    // 0x802075C8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x802075CC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802075D0: sb          $v1, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r3;
    // 0x802075D4: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x802075D8: lw          $t8, 0x30($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X30);
    // 0x802075DC: b           L_80207634
    // 0x802075E0: sb          $zero, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = 0;
        goto L_80207634;
    // 0x802075E0: sb          $zero, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = 0;
    // 0x802075E4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_802075E8:
    // 0x802075E8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x802075EC: sb          $v1, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r3;
    // 0x802075F0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x802075F4: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x802075F8: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x802075FC: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80207600: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207604: b           L_80207634
    // 0x80207608: sb          $zero, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = 0;
        goto L_80207634;
    // 0x80207608: sb          $zero, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = 0;
    // 0x8020760C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_80207610:
    // 0x80207610: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80207614: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80207618: sb          $v0, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r2;
    // 0x8020761C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80207620: lw          $t8, 0x30($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X30);
    // 0x80207624: sb          $v0, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r2;
    // 0x80207628: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8020762C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80207630: sb          $v1, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r3;
L_80207634:
    // 0x80207634: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80207638: sh          $zero, 0x92($s1)
    MEM_H(0X92, ctx->r17) = 0;
    // 0x8020763C: sh          $zero, 0xA6($s1)
    MEM_H(0XA6, ctx->r17) = 0;
    // 0x80207640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80207644: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80207648: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8020764C: jr          $ra
    // 0x80207650: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80207650: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80207654(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80207654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80207654: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80207658: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8020765C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80207660: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80207664: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80207668: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8020766C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80207670: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80207674: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80207678: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8020767C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80207680: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80207684: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80207688: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8020768C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80207690: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80207694: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80207698: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8020769C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x802076A0: jal         0x80005E44
    // 0x802076A4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802076A4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x802076A8: jal         0x80006214
    // 0x802076AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x802076AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x802076B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802076B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802076B8: addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // 0x802076BC: jal         0x8012C89C
    // 0x802076C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x802076C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x802076C4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802076C8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802076CC: lwc1        $f0, -0x57E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57E0);
    // 0x802076D0: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x802076D4: lui         $t3, 0x8021
    ctx->r11 = S32(0X8021 << 16);
    // 0x802076D8: addiu       $t3, $t3, 0x7B60
    ctx->r11 = ADD32(ctx->r11, 0X7B60);
    // 0x802076DC: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x802076E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802076E4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x802076E8: ori         $t2, $t1, 0x100
    ctx->r10 = ctx->r9 | 0X100;
    // 0x802076EC: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x802076F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802076F4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x802076F8: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x802076FC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207700: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207704: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207708: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x8020770C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80207710: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207714: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80207718: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x8020771C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207720: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207724: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80207728: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x8020772C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80207730: lhu         $t3, 0xA0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XA0);
    // 0x80207734: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80207738: sh          $t3, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r11;
    // 0x8020773C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207740: lhu         $t6, 0xA2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XA2);
    // 0x80207744: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207748: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x8020774C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207750: lhu         $t9, 0xA4($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XA4);
    // 0x80207754: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80207758: sh          $t9, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r25;
    // 0x8020775C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207760: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x80207764: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80207768: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8020776C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80207770: swc1        $f0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f0.u32l;
    // 0x80207774: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207778: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x8020777C: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x80207780: lw          $t8, 0xA8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XA8);
    // 0x80207784: bnel        $t8, $zero, L_802077A0
    if (ctx->r24 != 0) {
        // 0x80207788: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_802077A0;
    }
    goto skip_0;
    // 0x80207788: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8020778C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207790: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x80207794: b           L_802077AC
    // 0x80207798: sb          $zero, 0x48($t9)
    MEM_B(0X48, ctx->r25) = 0;
        goto L_802077AC;
    // 0x80207798: sb          $zero, 0x48($t9)
    MEM_B(0X48, ctx->r25) = 0;
    // 0x8020779C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_802077A0:
    // 0x802077A0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x802077A4: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x802077A8: sb          $t1, 0x48($t5)
    MEM_B(0X48, ctx->r13) = ctx->r9;
L_802077AC:
    // 0x802077AC: lw          $t3, 0xA8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XA8);
    // 0x802077B0: bnel        $t3, $zero, L_802077D0
    if (ctx->r11 != 0) {
        // 0x802077B4: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_802077D0;
    }
    goto skip_1;
    // 0x802077B4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x802077B8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802077BC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x802077C0: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x802077C4: b           L_802077D8
    // 0x802077C8: sb          $t4, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r12;
        goto L_802077D8;
    // 0x802077C8: sb          $t4, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r12;
    // 0x802077CC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_802077D0:
    // 0x802077D0: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x802077D4: sb          $zero, 0x49($t0)
    MEM_B(0X49, ctx->r8) = 0;
L_802077D8:
    // 0x802077D8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802077DC: addiu       $t1, $zero, 0xC0
    ctx->r9 = ADD32(0, 0XC0);
    // 0x802077E0: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x802077E4: sb          $zero, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = 0;
    // 0x802077E8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802077EC: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x802077F0: sb          $t1, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r9;
    // 0x802077F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802077F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802077FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80207800: jr          $ra
    // 0x80207804: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80207804: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80207808(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80207808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80207808: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8020780C: jr          $ra
    // 0x80207810: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80207810: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80207814(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80207814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80207814: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80207818: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8020781C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80207820: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80207824: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80207828: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8020782C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80207830: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80207834: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80207838: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8020783C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80207840: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80207844: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80207848: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8020784C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80207850: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80207854: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80207858: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8020785C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80207860: jal         0x80005E44
    // 0x80207864: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80207864: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80207868: jal         0x80006214
    // 0x8020786C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8020786C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80207870: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80207878: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x8020787C: jal         0x8012C89C
    // 0x80207880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80207880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80207884: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207888: lui         $t3, 0x8021
    ctx->r11 = S32(0X8021 << 16);
    // 0x8020788C: addiu       $t3, $t3, 0x7B00
    ctx->r11 = ADD32(ctx->r11, 0X7B00);
    // 0x80207890: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80207894: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80207898: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8020789C: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x802078A0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802078A4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x802078A8: ori         $t2, $t1, 0x300
    ctx->r10 = ctx->r9 | 0X300;
    // 0x802078AC: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x802078B0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x802078B4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x802078B8: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x802078BC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802078C0: lwc1        $f4, -0x57DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X57DC);
    // 0x802078C4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802078C8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x802078CC: swc1        $f4, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f4.u32l;
    // 0x802078D0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802078D4: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x802078D8: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802078DC: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x802078E0: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x802078E4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802078E8: lwc1        $f8, -0x57D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X57D8);
    // 0x802078EC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802078F0: swc1        $f8, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f8.u32l;
    // 0x802078F4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802078F8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802078FC: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x80207900: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80207904: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80207908: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x8020790C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207910: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80207914: sb          $v1, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r3;
    // 0x80207918: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8020791C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80207920: sb          $t8, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r24;
    // 0x80207924: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207928: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8020792C: sb          $zero, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = 0;
    // 0x80207930: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80207934: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80207938: sb          $zero, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = 0;
    // 0x8020793C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207940: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80207944: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x80207948: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8020794C: lwc1        $f10, 0x94($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207950: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80207954: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x80207958: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8020795C: lwc1        $f16, 0x98($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207960: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x80207964: swc1        $f16, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f16.u32l;
    // 0x80207968: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8020796C: lwc1        $f18, 0x9C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207970: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80207974: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x80207978: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8020797C: lhu         $t3, 0xA0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XA0);
    // 0x80207980: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80207984: sh          $t3, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r11;
    // 0x80207988: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8020798C: lhu         $t6, 0xA2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XA2);
    // 0x80207990: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80207994: sh          $t6, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r14;
    // 0x80207998: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8020799C: lhu         $t8, 0xA4($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XA4);
    // 0x802079A0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802079A4: sh          $t8, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r24;
    // 0x802079A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802079AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802079B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802079B4: jr          $ra
    // 0x802079B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x802079B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802079bc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802079bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802079BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x802079C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x802079C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802079C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802079CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802079D0: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x802079D4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x802079D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x802079DC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x802079E0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x802079E4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x802079E8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x802079EC: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x802079F0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x802079F4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x802079F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x802079FC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80207A00: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80207A04: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80207A08: jal         0x80005E44
    // 0x80207A0C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80207A0C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80207A10: jal         0x80006214
    // 0x80207A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80207A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80207A18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207A1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80207A20: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80207A24: jal         0x8012C89C
    // 0x80207A28: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80207A28: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80207A2C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207A30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207A34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80207A38: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x80207A3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80207A40: jal         0x8012CF8C
    // 0x80207A44: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x80207A44: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x80207A48: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207A4C: lui         $t4, 0x8021
    ctx->r12 = S32(0X8021 << 16);
    // 0x80207A50: addiu       $t4, $t4, 0x7B00
    ctx->r12 = ADD32(ctx->r12, 0X7B00);
    // 0x80207A54: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80207A58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80207A5C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80207A60: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x80207A64: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207A68: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80207A6C: ori         $t3, $t2, 0x300
    ctx->r11 = ctx->r10 | 0X300;
    // 0x80207A70: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80207A74: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207A78: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80207A7C: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x80207A80: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80207A84: lwc1        $f4, -0x57D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X57D4);
    // 0x80207A88: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207A8C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80207A90: swc1        $f4, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f4.u32l;
    // 0x80207A94: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207A98: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x80207A9C: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80207AA0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80207AA4: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80207AA8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207AAC: lwc1        $f8, -0x57D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X57D0);
    // 0x80207AB0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80207AB4: swc1        $f8, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f8.u32l;
    // 0x80207AB8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80207ABC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80207AC0: sb          $v1, 0x48($t4)
    MEM_B(0X48, ctx->r12) = ctx->r3;
    // 0x80207AC4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207AC8: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80207ACC: sb          $v1, 0x49($t5)
    MEM_B(0X49, ctx->r13) = ctx->r3;
    // 0x80207AD0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207AD4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207AD8: sb          $v1, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r3;
    // 0x80207ADC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207AE0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80207AE4: sb          $t9, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r25;
    // 0x80207AE8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207AEC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207AF0: sb          $zero, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = 0;
    // 0x80207AF4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207AF8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80207AFC: sb          $zero, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = 0;
    // 0x80207B00: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80207B04: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80207B08: sb          $v1, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r3;
    // 0x80207B0C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80207B10: lwc1        $f10, 0x94($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207B14: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x80207B18: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x80207B1C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80207B20: lwc1        $f16, 0x98($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207B24: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207B28: swc1        $f16, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f16.u32l;
    // 0x80207B2C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207B30: lwc1        $f18, 0x9C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207B34: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207B38: swc1        $f18, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
    // 0x80207B3C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207B40: lhu         $t4, 0xA0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XA0);
    // 0x80207B44: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80207B48: sh          $t4, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r12;
    // 0x80207B4C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80207B50: lhu         $t7, 0xA2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XA2);
    // 0x80207B54: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x80207B58: sh          $t7, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r15;
    // 0x80207B5C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207B60: lhu         $t9, 0xA4($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XA4);
    // 0x80207B64: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80207B68: sh          $t9, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r25;
    // 0x80207B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80207B70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80207B74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80207B78: jr          $ra
    // 0x80207B7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80207B7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80207b80(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80207b80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80207B80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80207B84: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80207B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80207B8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80207B90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80207B94: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80207B98: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80207B9C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80207BA0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80207BA4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80207BA8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80207BAC: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80207BB0: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x80207BB4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80207BB8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80207BBC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80207BC0: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80207BC4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80207BC8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80207BCC: jal         0x80005E44
    // 0x80207BD0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80207BD0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80207BD4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80207BD8: ori         $t1, $t1, 0x900
    ctx->r9 = ctx->r9 | 0X900;
    // 0x80207BDC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80207BE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207BE4: jal         0x80005E44
    // 0x80207BE8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80207BE8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80207BEC: jal         0x80006214
    // 0x80207BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80207BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80207BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207BF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80207BFC: addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    // 0x80207C00: jal         0x8012C89C
    // 0x80207C04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80207C04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80207C08: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207C0C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207C10: lwc1        $f0, -0x57CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57CC);
    // 0x80207C14: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80207C18: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80207C1C: addiu       $t0, $t0, -0x5070
    ctx->r8 = ADD32(ctx->r8, -0X5070);
    // 0x80207C20: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x80207C24: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80207C28: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x80207C2C: ori         $t4, $t3, 0x400
    ctx->r12 = ctx->r11 | 0X400;
    // 0x80207C30: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x80207C34: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80207C38: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80207C3C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80207C40: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80207C44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80207C4C: sw          $t0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r8;
    // 0x80207C50: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207C54: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207C58: addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    // 0x80207C5C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207C60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80207C64: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80207C68: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80207C6C: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207C70: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207C74: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80207C78: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207C7C: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207C80: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207C84: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x80207C88: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207C8C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80207C90: sh          $zero, 0x10($t5)
    MEM_H(0X10, ctx->r13) = 0;
    // 0x80207C94: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207C98: lhu         $t6, 0xA2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XA2);
    // 0x80207C9C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207CA0: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x80207CA4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80207CA8: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207CAC: sh          $zero, 0x14($t1)
    MEM_H(0X14, ctx->r9) = 0;
    // 0x80207CB0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80207CB4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80207CB8: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x80207CBC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207CC0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80207CC4: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x80207CC8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207CCC: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80207CD0: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x80207CD4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80207CD8: lbu         $t8, 0xF32($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF32);
    // 0x80207CDC: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207CE0: sb          $t8, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r24;
    // 0x80207CE4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80207CE8: lbu         $t2, 0xF33($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XF33);
    // 0x80207CEC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80207CF0: sb          $t2, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r10;
    // 0x80207CF4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207CF8: lbu         $t5, 0xF34($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XF34);
    // 0x80207CFC: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80207D00: sb          $t5, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r13;
    // 0x80207D04: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80207D08: lbu         $t9, 0xF35($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF35);
    // 0x80207D0C: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80207D10: sb          $t9, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r25;
    // 0x80207D14: jal         0x8012C89C
    // 0x80207D18: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x80207D18: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_4:
    // 0x80207D1C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80207D20: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207D24: lwc1        $f0, -0x57C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57C8);
    // 0x80207D28: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x80207D2C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80207D30: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80207D34: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    // 0x80207D38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80207D3C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80207D40: ori         $t4, $t2, 0x400
    ctx->r12 = ctx->r10 | 0X400;
    // 0x80207D44: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x80207D48: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80207D4C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80207D50: addiu       $a0, $zero, 0xD8
    ctx->r4 = ADD32(0, 0XD8);
    // 0x80207D54: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x80207D58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80207D5C: sw          $t0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r8;
    // 0x80207D60: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80207D64: lwc1        $f10, 0x94($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207D68: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x80207D6C: swc1        $f10, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f10.u32l;
    // 0x80207D70: lwc1        $f16, 0x98($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207D74: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80207D78: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80207D7C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207D80: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x80207D84: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80207D88: lwc1        $f6, 0x9C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207D8C: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x80207D90: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    // 0x80207D94: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80207D98: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80207D9C: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x80207DA0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80207DA4: lhu         $t5, 0xA2($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XA2);
    // 0x80207DA8: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x80207DAC: sh          $t5, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r13;
    // 0x80207DB0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80207DB4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207DB8: sh          $zero, 0x14($t1)
    MEM_H(0X14, ctx->r9) = 0;
    // 0x80207DBC: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80207DC0: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x80207DC4: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x80207DC8: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80207DCC: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80207DD0: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x80207DD4: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80207DD8: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80207DDC: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x80207DE0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80207DE4: lbu         $t8, 0xF32($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF32);
    // 0x80207DE8: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80207DEC: sb          $t8, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r24;
    // 0x80207DF0: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80207DF4: lbu         $t3, 0xF33($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XF33);
    // 0x80207DF8: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80207DFC: sb          $t3, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r11;
    // 0x80207E00: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80207E04: lbu         $t7, 0xF34($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF34);
    // 0x80207E08: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80207E0C: sb          $t7, 0x4E($t5)
    MEM_B(0X4E, ctx->r13) = ctx->r15;
    // 0x80207E10: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80207E14: lbu         $t9, 0xF35($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF35);
    // 0x80207E18: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80207E1C: sb          $t9, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r25;
    // 0x80207E20: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x80207E24: ori         $t3, $t2, 0x800
    ctx->r11 = ctx->r10 | 0X800;
    // 0x80207E28: jal         0x8012C97C
    // 0x80207E2C: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_5;
    // 0x80207E2C: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    after_5:
    // 0x80207E30: lhu         $t4, 0xA2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XA2);
    // 0x80207E34: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x80207E38: sh          $zero, 0x84($s1)
    MEM_H(0X84, ctx->r17) = 0;
    // 0x80207E3C: sh          $zero, 0x88($s1)
    MEM_H(0X88, ctx->r17) = 0;
    // 0x80207E40: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80207E44: sh          $zero, 0x92($s1)
    MEM_H(0X92, ctx->r17) = 0;
    // 0x80207E48: sh          $t4, 0x86($s1)
    MEM_H(0X86, ctx->r17) = ctx->r12;
    // 0x80207E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80207E50: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80207E54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80207E58: jr          $ra
    // 0x80207E5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80207E5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80207e60(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80207e60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80207E60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80207E64: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80207E68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80207E6C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80207E70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80207E74: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80207E78: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80207E7C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80207E80: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80207E84: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80207E88: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80207E8C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80207E90: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x80207E94: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80207E98: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80207E9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80207EA0: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80207EA4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80207EA8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80207EAC: jal         0x80005E44
    // 0x80207EB0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80207EB0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80207EB4: jal         0x80006214
    // 0x80207EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80207EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80207EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80207EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80207EC4: addiu       $a2, $zero, 0xD1
    ctx->r6 = ADD32(0, 0XD1);
    // 0x80207EC8: jal         0x8012C89C
    // 0x80207ECC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80207ECC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80207ED0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207ED4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80207ED8: lwc1        $f0, -0x57C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57C4);
    // 0x80207EDC: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80207EE0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80207EE4: addiu       $t3, $t3, -0x5070
    ctx->r11 = ADD32(ctx->r11, -0X5070);
    // 0x80207EE8: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x80207EEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80207EF0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80207EF4: ori         $t2, $t1, 0x400
    ctx->r10 = ctx->r9 | 0X400;
    // 0x80207EF8: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80207EFC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80207F00: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80207F04: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80207F08: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80207F0C: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    // 0x80207F10: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80207F14: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207F18: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207F1C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207F20: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80207F24: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80207F28: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207F2C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80207F30: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x80207F34: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80207F38: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80207F3C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80207F40: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x80207F44: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80207F48: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80207F4C: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80207F50: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80207F54: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80207F58: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80207F5C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80207F60: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80207F64: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x80207F68: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207F6C: lbu         $t9, 0xF32($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF32);
    // 0x80207F70: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80207F74: sb          $t9, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r25;
    // 0x80207F78: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80207F7C: lbu         $t2, 0xF33($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF33);
    // 0x80207F80: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80207F84: sb          $t2, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r10;
    // 0x80207F88: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80207F8C: lbu         $t4, 0xF34($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF34);
    // 0x80207F90: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x80207F94: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80207F98: addiu       $t5, $zero, 0x316
    ctx->r13 = ADD32(0, 0X316);
    // 0x80207F9C: sb          $t4, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r12;
    // 0x80207FA0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80207FA4: lbu         $t8, 0xF35($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF35);
    // 0x80207FA8: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x80207FAC: sb          $t8, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r24;
    // 0x80207FB0: lbu         $t1, 0xAC($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XAC);
    // 0x80207FB4: andi        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 & 0X1;
    // 0x80207FB8: beql        $t3, $zero, L_80207FC8
    if (ctx->r11 == 0) {
        // 0x80207FBC: sh          $zero, 0x92($s1)
        MEM_H(0X92, ctx->r17) = 0;
            goto L_80207FC8;
    }
    goto skip_0;
    // 0x80207FBC: sh          $zero, 0x92($s1)
    MEM_H(0X92, ctx->r17) = 0;
    skip_0:
    // 0x80207FC0: sb          $t2, 0x90($s1)
    MEM_B(0X90, ctx->r17) = ctx->r10;
    // 0x80207FC4: sh          $zero, 0x92($s1)
    MEM_H(0X92, ctx->r17) = 0;
L_80207FC8:
    // 0x80207FC8: lwc1        $f12, 0x94($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80207FCC: lwc1        $f14, 0x98($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80207FD0: lw          $a2, 0x9C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X9C);
    // 0x80207FD4: jal         0x801FC830
    // 0x80207FD8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_3;
    // 0x80207FD8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x80207FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80207FE0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80207FE4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80207FE8: jr          $ra
    // 0x80207FEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80207FEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80207ff0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80207ff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80207FF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80207FF4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80207FF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80207FFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80208000: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80208004: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80208008: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8020800C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80208010: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80208014: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80208018: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8020801C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80208020: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x80208024: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80208028: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8020802C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80208030: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80208034: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80208038: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x8020803C: jal         0x80005E44
    // 0x80208040: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80208040: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80208044: lbu         $t0, 0xAC($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XAC);
    // 0x80208048: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8020804C: ori         $t2, $t2, 0x600
    ctx->r10 = ctx->r10 | 0X600;
    // 0x80208050: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80208054: bne         $t1, $zero, L_80208068
    if (ctx->r9 != 0) {
        // 0x80208058: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80208068;
    }
    // 0x80208058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8020805C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80208060: jal         0x80005E44
    // 0x80208064: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80208064: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
L_80208068:
    // 0x80208068: jal         0x80006214
    // 0x8020806C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x8020806C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80208070: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80208074: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80208078: lwc1        $f0, -0x57C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57C0);
    // 0x8020807C: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x80208080: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80208084: addiu       $t6, $t6, -0x5070
    ctx->r14 = ADD32(ctx->r14, -0X5070);
    // 0x80208088: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
    // 0x8020808C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80208090: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80208094: ori         $t5, $t4, 0x400
    ctx->r13 = ctx->r12 | 0X400;
    // 0x80208098: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x8020809C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802080A0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802080A4: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x802080A8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x802080AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x802080B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802080B4: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x802080B8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802080BC: lhu         $t0, 0xA0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XA0);
    // 0x802080C0: addiu       $a2, $zero, 0xDB
    ctx->r6 = ADD32(0, 0XDB);
    // 0x802080C4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802080C8: sh          $t0, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r8;
    // 0x802080CC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x802080D0: lhu         $t3, 0xA2($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XA2);
    // 0x802080D4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802080D8: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    // 0x802080DC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802080E0: lhu         $t6, 0xA4($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XA4);
    // 0x802080E4: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x802080E8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x802080EC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802080F0: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x802080F4: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x802080F8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802080FC: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80208100: swc1        $f0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f0.u32l;
    // 0x80208104: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80208108: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x8020810C: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x80208110: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80208114: lbu         $t5, 0xF32($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XF32);
    // 0x80208118: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x8020811C: sb          $t5, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r13;
    // 0x80208120: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80208124: lbu         $t7, 0xF33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XF33);
    // 0x80208128: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x8020812C: sb          $t7, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r15;
    // 0x80208130: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80208134: lbu         $t0, 0xF34($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XF34);
    // 0x80208138: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x8020813C: sb          $t0, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r8;
    // 0x80208140: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80208144: lbu         $t3, 0xF35($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XF35);
    // 0x80208148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8020814C: lw          $t5, 0x30($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X30);
    // 0x80208150: sb          $t3, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r11;
    // 0x80208154: lbu         $t6, 0xAC($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XAC);
    // 0x80208158: andi        $t9, $t6, 0x10
    ctx->r25 = ctx->r14 & 0X10;
    // 0x8020815C: bne         $t9, $zero, L_8020825C
    if (ctx->r25 != 0) {
        // 0x80208160: nop
    
            goto L_8020825C;
    }
    // 0x80208160: nop

    // 0x80208164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80208168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8020816C: jal         0x8012C89C
    // 0x80208170: addiu       $a2, $zero, 0xDE
    ctx->r6 = ADD32(0, 0XDE);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80208170: addiu       $a2, $zero, 0xDE
    ctx->r6 = ADD32(0, 0XDE);
    after_3:
    // 0x80208174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80208178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8020817C: addiu       $a2, $zero, 0xDE
    ctx->r6 = ADD32(0, 0XDE);
    // 0x80208180: jal         0x8012C89C
    // 0x80208184: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x80208184: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80208188: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8020818C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80208190: lwc1        $f0, -0x57B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X57B8);
    // 0x80208194: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80208198: lui         $t0, 0x8021
    ctx->r8 = S32(0X8021 << 16);
    // 0x8020819C: addiu       $t0, $t0, 0x7B60
    ctx->r8 = ADD32(ctx->r8, 0X7B60);
    // 0x802081A0: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x802081A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802081A8: or          $t4, $t0, $at
    ctx->r12 = ctx->r8 | ctx->r1;
    // 0x802081AC: ori         $t2, $t1, 0x100
    ctx->r10 = ctx->r9 | 0X100;
    // 0x802081B0: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x802081B4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x802081B8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x802081BC: addiu       $a0, $zero, 0xDE
    ctx->r4 = ADD32(0, 0XDE);
    // 0x802081C0: lw          $t3, 0x30($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X30);
    // 0x802081C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x802081C8: sw          $t4, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r12;
    // 0x802081CC: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x802081D0: lhu         $t5, 0xA0($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XA0);
    // 0x802081D4: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x802081D8: sh          $t5, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r13;
    // 0x802081DC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x802081E0: lhu         $t7, 0xA2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XA2);
    // 0x802081E4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802081E8: sh          $t7, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r15;
    // 0x802081EC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x802081F0: lhu         $t0, 0xA4($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XA4);
    // 0x802081F4: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x802081F8: sh          $t0, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r8;
    // 0x802081FC: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80208200: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x80208204: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x80208208: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8020820C: lw          $t9, 0x30($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X30);
    // 0x80208210: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80208214: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80208218: lw          $t7, 0x30($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X30);
    // 0x8020821C: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x80208220: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80208224: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x80208228: sb          $v1, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r3;
    // 0x8020822C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80208230: lw          $t4, 0x30($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X30);
    // 0x80208234: sb          $zero, 0x49($t4)
    MEM_B(0X49, ctx->r12) = 0;
    // 0x80208238: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8020823C: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x80208240: sb          $zero, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = 0;
    // 0x80208244: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80208248: lw          $t9, 0x30($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X30);
    // 0x8020824C: jal         0x8012C97C
    // 0x80208250: sb          $v1, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r3;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_5;
    // 0x80208250: sb          $v1, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r3;
    after_5:
    // 0x80208254: b           L_80208274
    // 0x80208258: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
        goto L_80208274;
    // 0x80208258: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
L_8020825C:
    // 0x8020825C: jal         0x8012C89C
    // 0x80208260: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x80208260: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80208264: addiu       $a0, $zero, 0xDB
    ctx->r4 = ADD32(0, 0XDB);
    // 0x80208268: jal         0x8012C97C
    // 0x8020826C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_7;
    // 0x8020826C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80208270: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
L_80208274:
    // 0x80208274: lw          $t1, 0x2C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X2C);
    // 0x80208278: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x8020827C: sh          $zero, 0x92($s1)
    MEM_H(0X92, ctx->r17) = 0;
    // 0x80208280: ori         $t7, $t1, 0x800
    ctx->r15 = ctx->r9 | 0X800;
    // 0x80208284: sw          $t7, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r15;
    // 0x80208288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8020828C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80208290: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80208294: jr          $ra
    // 0x80208298: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80208298: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_8020829c(rdram, ctx);
;}
