#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8012b7c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012B7C0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012B7C4: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x8012B7C8: beq         $t7, $zero, L_8012B814
    if (ctx->r15 == 0) {
        // 0x8012B7CC: nop
    
            goto L_8012B814;
    }
    // 0x8012B7CC: nop

    // 0x8012B7D0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8012B7D4: beq         $v0, $zero, L_8012B814
    if (ctx->r2 == 0) {
        // 0x8012B7D8: nop
    
            goto L_8012B814;
    }
    // 0x8012B7D8: nop

    // 0x8012B7DC: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8012B7E0: beql        $v1, $zero, L_8012B7FC
    if (ctx->r3 == 0) {
        // 0x8012B7E4: lw          $v1, 0x30($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X30);
            goto L_8012B7FC;
    }
    goto skip_0;
    // 0x8012B7E4: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x8012B7E8: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012B7EC: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8012B7F0: b           L_8012B808
    // 0x8012B7F4: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
        goto L_8012B808;
    // 0x8012B7F4: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012B7F8: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
L_8012B7FC:
    // 0x8012B7FC: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012B800: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8012B804: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
L_8012B808:
    // 0x8012B808: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    // 0x8012B80C: swc1        $f2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f2.u32l;
    // 0x8012B810: swc1        $f12, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f12.u32l;
L_8012B814:
    // 0x8012B814: jr          $ra
    // 0x8012B818: nop

    return;
    // 0x8012B818: nop

;}
RECOMP_FUNC void M7_FUN_8012b81c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012B81C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012B820: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8012B824: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012B828: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012B82C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8012B830: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8012B834: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8012B838: jal         0x8010854C
    // 0x8012B83C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8010854C)(rdram, ctx);
        goto after_0;
    // 0x8012B83C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8012B840: beq         $v0, $zero, L_8012B850
    if (ctx->r2 == 0) {
        // 0x8012B844: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012B850;
    }
    // 0x8012B844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012B848: b           L_8012B854
    // 0x8012B84C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012B854;
    // 0x8012B84C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012B850:
    // 0x8012B850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012B854:
    // 0x8012B854: jr          $ra
    // 0x8012B858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8012B858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012b85c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012b85c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012B85C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8012B860: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8012B864: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8012B868: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8012B86C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8012B870: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8012B874: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8012B878: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8012B87C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8012B880: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8012B884: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8012B888: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8012B88C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8012B890: sw          $zero, 0xD2C($s0)
    MEM_W(0XD2C, ctx->r16) = 0;
    // 0x8012B894: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x8012B898: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8012B89C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8012B8A0: addiu       $s1, $s1, 0x6020
    ctx->r17 = ADD32(ctx->r17, 0X6020);
    // 0x8012B8A4: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x8012B8A8: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x8012B8AC: beq         $v1, $zero, L_8012BF28
    if (ctx->r3 == 0) {
        // 0x8012B8B0: mov.s       $f28, $f20
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    ctx->f28.fl = ctx->f20.fl;
            goto L_8012BF28;
    }
    // 0x8012B8B0: mov.s       $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    ctx->f28.fl = ctx->f20.fl;
    // 0x8012B8B4: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8012B8B8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8012B8BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8012B8C0: beq         $v0, $zero, L_8012B8E0
    if (ctx->r2 == 0) {
        // 0x8012B8C4: addiu       $t6, $v0, 0x4
        ctx->r14 = ADD32(ctx->r2, 0X4);
            goto L_8012B8E0;
    }
    // 0x8012B8C4: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x8012B8C8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8012B8CC: addiu       $t8, $v0, 0xC
    ctx->r24 = ADD32(ctx->r2, 0XC);
    // 0x8012B8D0: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8012B8D4: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x8012B8D8: b           L_8012B8FC
    // 0x8012B8DC: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
        goto L_8012B8FC;
    // 0x8012B8DC: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
L_8012B8E0:
    // 0x8012B8E0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8012B8E4: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    // 0x8012B8E8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8012B8EC: addiu       $t1, $v0, 0xC
    ctx->r9 = ADD32(ctx->r2, 0XC);
    // 0x8012B8F0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8012B8F4: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8012B8F8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
L_8012B8FC:
    // 0x8012B8FC: lhu         $t2, 0x6020($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X6020);
    // 0x8012B900: beql        $t2, $zero, L_8012BF2C
    if (ctx->r10 == 0) {
        // 0x8012B904: lw          $t9, 0x2C($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X2C);
            goto L_8012BF2C;
    }
    goto skip_0;
    // 0x8012B904: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    skip_0:
    // 0x8012B908: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x8012B90C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8012B910: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x8012B914: lw          $t3, 0xD28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XD28);
L_8012B918:
    // 0x8012B918: and         $t4, $v1, $t3
    ctx->r12 = ctx->r3 & ctx->r11;
    // 0x8012B91C: beql        $t4, $zero, L_8012BF1C
    if (ctx->r12 == 0) {
        // 0x8012B920: lhu         $v1, 0x4($s1)
        ctx->r3 = MEM_HU(ctx->r17, 0X4);
            goto L_8012BF1C;
    }
    goto skip_1;
    // 0x8012B920: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    skip_1:
    // 0x8012B924: lw          $t5, 0x2C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X2C);
    // 0x8012B928: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x8012B92C: beql        $t6, $zero, L_8012B9B4
    if (ctx->r14 == 0) {
        // 0x8012B930: slti        $at, $v1, 0x81
        ctx->r1 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
            goto L_8012B9B4;
    }
    goto skip_2;
    // 0x8012B930: slti        $at, $v1, 0x81
    ctx->r1 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
    skip_2:
    // 0x8012B934: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x8012B938: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8012B93C: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x8012B940: lwc1        $f4, 0xC68($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC68);
    // 0x8012B944: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x8012B948: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x8012B94C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8012B950: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8012B954: nop

    // 0x8012B958: sh          $t0, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r8;
    // 0x8012B95C: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x8012B960: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8012B964: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8012B968: lwc1        $f8, 0xCA8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XCA8);
    // 0x8012B96C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8012B970: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x8012B974: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8012B978: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8012B97C: nop

    // 0x8012B980: sh          $t6, 0x130($t8)
    MEM_H(0X130, ctx->r24) = ctx->r14;
    // 0x8012B984: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x8012B988: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8012B98C: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x8012B990: lwc1        $f16, 0xCE8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XCE8);
    // 0x8012B994: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8012B998: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8012B99C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8012B9A0: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8012B9A4: nop

    // 0x8012B9A8: sh          $t2, 0x142($t4)
    MEM_H(0X142, ctx->r12) = ctx->r10;
    // 0x8012B9AC: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x8012B9B0: slti        $at, $v1, 0x81
    ctx->r1 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
L_8012B9B4:
    // 0x8012B9B4: bne         $at, $zero, L_8012B9D8
    if (ctx->r1 != 0) {
        // 0x8012B9B8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8012B9D8;
    }
    // 0x8012B9B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8012B9BC: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x8012B9C0: beq         $v1, $at, L_8012BB98
    if (ctx->r3 == ctx->r1) {
        // 0x8012B9C4: addiu       $at, $zero, 0x200
        ctx->r1 = ADD32(0, 0X200);
            goto L_8012BB98;
    }
    // 0x8012B9C4: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8012B9C8: beql        $v1, $at, L_8012BEA8
    if (ctx->r3 == ctx->r1) {
        // 0x8012B9CC: lhu         $t4, 0x2($s1)
        ctx->r12 = MEM_HU(ctx->r17, 0X2);
            goto L_8012BEA8;
    }
    goto skip_3;
    // 0x8012B9CC: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
    skip_3:
    // 0x8012B9D0: b           L_8012BF1C
    // 0x8012B9D4: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
        goto L_8012BF1C;
    // 0x8012B9D4: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
L_8012B9D8:
    // 0x8012B9D8: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x8012B9DC: bne         $at, $zero, L_8012B9F4
    if (ctx->r1 != 0) {
        // 0x8012B9E0: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8012B9F4;
    }
    // 0x8012B9E0: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8012B9E4: beql        $v0, $at, L_8012BB9C
    if (ctx->r2 == ctx->r1) {
        // 0x8012B9E8: lbu         $t6, 0x4D($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X4D);
            goto L_8012BB9C;
    }
    goto skip_4;
    // 0x8012B9E8: lbu         $t6, 0x4D($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X4D);
    skip_4:
    // 0x8012B9EC: b           L_8012BF1C
    // 0x8012B9F0: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
        goto L_8012BF1C;
    // 0x8012B9F0: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
L_8012B9F4:
    // 0x8012B9F4: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x8012B9F8: bne         $at, $zero, L_8012BA14
    if (ctx->r1 != 0) {
        // 0x8012B9FC: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_8012BA14;
    }
    // 0x8012B9FC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8012BA00: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8012BA04: beql        $v0, $at, L_8012BB9C
    if (ctx->r2 == ctx->r1) {
        // 0x8012BA08: lbu         $t6, 0x4D($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X4D);
            goto L_8012BB9C;
    }
    goto skip_5;
    // 0x8012BA08: lbu         $t6, 0x4D($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X4D);
    skip_5:
    // 0x8012BA0C: b           L_8012BF1C
    // 0x8012BA10: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
        goto L_8012BF1C;
    // 0x8012BA10: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
L_8012BA14:
    // 0x8012BA14: sltiu       $at, $t5, 0x20
    ctx->r1 = ctx->r13 < 0X20 ? 1 : 0;
    // 0x8012BA18: beq         $at, $zero, L_8012BF18
    if (ctx->r1 == 0) {
        // 0x8012BA1C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8012BF18;
    }
    // 0x8012BA1C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8012BA20: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012BA24: addu        $at, $at, $t5
    gpr jr_addend_8012BA2C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8012BA28: lw          $t5, -0x30C8($at)
    ctx->r13 = ADD32(ctx->r1, -0X30C8);
    // 0x8012BA2C: jr          $t5
    // 0x8012BA30: nop

    switch (jr_addend_8012BA2C >> 2) {
        case 0: goto L_8012BA34; break;
        case 1: goto L_8012BA34; break;
        case 2: goto L_8012BF18; break;
        case 3: goto L_8012BA34; break;
        case 4: goto L_8012BF18; break;
        case 5: goto L_8012BF18; break;
        case 6: goto L_8012BF18; break;
        case 7: goto L_8012BA34; break;
        case 8: goto L_8012BF18; break;
        case 9: goto L_8012BF18; break;
        case 10: goto L_8012BF18; break;
        case 11: goto L_8012BF18; break;
        case 12: goto L_8012BF18; break;
        case 13: goto L_8012BF18; break;
        case 14: goto L_8012BF18; break;
        case 15: goto L_8012BA34; break;
        case 16: goto L_8012BF18; break;
        case 17: goto L_8012BF18; break;
        case 18: goto L_8012BF18; break;
        case 19: goto L_8012BF18; break;
        case 20: goto L_8012BF18; break;
        case 21: goto L_8012BF18; break;
        case 22: goto L_8012BF18; break;
        case 23: goto L_8012BF18; break;
        case 24: goto L_8012BF18; break;
        case 25: goto L_8012BF18; break;
        case 26: goto L_8012BF18; break;
        case 27: goto L_8012BF18; break;
        case 28: goto L_8012BF18; break;
        case 29: goto L_8012BF18; break;
        case 30: goto L_8012BF18; break;
        case 31: goto L_8012BB98; break;
        default: switch_error(__func__, 0x8012BA2C, 0x8018CF38);
    }
    // 0x8012BA30: nop

L_8012BA34:
    // 0x8012BA34: lbu         $t6, 0x4D($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X4D);
    // 0x8012BA38: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8012BA3C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8012BA40: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8012BA44: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8012BA48: bgez        $t6, L_8012BA60
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8012BA4C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8012BA60;
    }
    // 0x8012BA4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012BA50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012BA54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012BA58: nop

    // 0x8012BA5C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8012BA60:
    // 0x8012BA60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8012BA64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8012BA68: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
    // 0x8012BA6C: lb          $t9, 0x4F($s2)
    ctx->r25 = MEM_B(ctx->r18, 0X4F);
    // 0x8012BA70: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8012BA74: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8012BA78: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8012BA7C: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
    // 0x8012BA80: lwc1        $f10, 0xCA8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XCA8);
    // 0x8012BA84: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8012BA88: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8012BA8C: lw          $a3, 0xC68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC68);
    // 0x8012BA90: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012BA94: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8012BA98: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8012BA9C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8012BAA0: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8012BAA4: lwc1        $f6, 0xCE8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XCE8);
    // 0x8012BAA8: sub.d       $f16, $f18, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f26.d); 
    ctx->f16.d = ctx->f18.d - ctx->f26.d;
    // 0x8012BAAC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8012BAB0: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8012BAB4: jal         0x8012B81C
    // 0x8012BAB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012B81C)(rdram, ctx);
        goto after_0;
    // 0x8012BAB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8012BABC: lwc1        $f14, 0x368($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X368);
    // 0x8012BAC0: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8012BAC4: nop

    // 0x8012BAC8: bc1fl       L_8012BADC
    if (!c1cs) {
        // 0x8012BACC: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_8012BADC;
    }
    goto skip_6;
    // 0x8012BACC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_6:
    // 0x8012BAD0: b           L_8012BADC
    // 0x8012BAD4: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
        goto L_8012BADC;
    // 0x8012BAD4: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    // 0x8012BAD8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8012BADC:
    // 0x8012BADC: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x8012BAE0: nop

    // 0x8012BAE4: bc1fl       L_8012BAF8
    if (!c1cs) {
        // 0x8012BAE8: mov.s       $f0, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
            goto L_8012BAF8;
    }
    goto skip_7;
    // 0x8012BAE8: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
    skip_7:
    // 0x8012BAEC: b           L_8012BAF8
    // 0x8012BAF0: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
        goto L_8012BAF8;
    // 0x8012BAF0: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x8012BAF4: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
L_8012BAF8:
    // 0x8012BAF8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8012BAFC: nop

    // 0x8012BB00: bc1fl       L_8012BB10
    if (!c1cs) {
        // 0x8012BB04: lwc1        $f14, 0x36C($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X36C);
            goto L_8012BB10;
    }
    goto skip_8;
    // 0x8012BB04: lwc1        $f14, 0x36C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X36C);
    skip_8:
    // 0x8012BB08: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8012BB0C: lwc1        $f14, 0x36C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X36C);
L_8012BB10:
    // 0x8012BB10: c.lt.s      $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f28.fl < ctx->f14.fl;
    // 0x8012BB14: nop

    // 0x8012BB18: bc1fl       L_8012BB28
    if (!c1cs) {
        // 0x8012BB1C: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_8012BB28;
    }
    goto skip_9;
    // 0x8012BB1C: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_9:
    // 0x8012BB20: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x8012BB24: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_8012BB28:
    // 0x8012BB28: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8012BB2C: nop

    // 0x8012BB30: bc1fl       L_8012BB44
    if (!c1cs) {
        // 0x8012BB34: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_8012BB44;
    }
    goto skip_10;
    // 0x8012BB34: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_10:
    // 0x8012BB38: b           L_8012BB44
    // 0x8012BB3C: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
        goto L_8012BB44;
    // 0x8012BB3C: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x8012BB40: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8012BB44:
    // 0x8012BB44: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8012BB48: nop

    // 0x8012BB4C: bc1fl       L_8012BB60
    if (!c1cs) {
        // 0x8012BB50: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_8012BB60;
    }
    goto skip_11;
    // 0x8012BB50: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_11:
    // 0x8012BB54: b           L_8012BB60
    // 0x8012BB58: neg.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = -ctx->f22.fl;
        goto L_8012BB60;
    // 0x8012BB58: neg.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = -ctx->f22.fl;
    // 0x8012BB5C: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_8012BB60:
    // 0x8012BB60: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8012BB64: nop

    // 0x8012BB68: bc1fl       L_8012BB78
    if (!c1cs) {
        // 0x8012BB6C: c.eq.s      $f20, $f14
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
            goto L_8012BB78;
    }
    goto skip_12;
    // 0x8012BB6C: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    skip_12:
    // 0x8012BB70: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x8012BB74: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
L_8012BB78:
    // 0x8012BB78: nop

    // 0x8012BB7C: bc1tl       L_8012BF1C
    if (c1cs) {
        // 0x8012BB80: lhu         $v1, 0x4($s1)
        ctx->r3 = MEM_HU(ctx->r17, 0X4);
            goto L_8012BF1C;
    }
    goto skip_13;
    // 0x8012BB80: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    skip_13:
    // 0x8012BB84: lw          $t2, 0xD2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XD2C);
    // 0x8012BB88: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x8012BB8C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8012BB90: b           L_8012BF18
    // 0x8012BB94: sw          $t5, 0xD2C($s0)
    MEM_W(0XD2C, ctx->r16) = ctx->r13;
        goto L_8012BF18;
    // 0x8012BB94: sw          $t5, 0xD2C($s0)
    MEM_W(0XD2C, ctx->r16) = ctx->r13;
L_8012BB98:
    // 0x8012BB98: lbu         $t6, 0x4D($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X4D);
L_8012BB9C:
    // 0x8012BB9C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8012BBA0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8012BBA4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8012BBA8: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8012BBAC: bgez        $t6, L_8012BBC4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8012BBB0: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8012BBC4;
    }
    // 0x8012BBB0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012BBB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012BBB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8012BBBC: nop

    // 0x8012BBC0: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8012BBC4:
    // 0x8012BBC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8012BBC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012BBCC: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
    // 0x8012BBD0: lb          $t9, 0x4F($s2)
    ctx->r25 = MEM_B(ctx->r18, 0X4F);
    // 0x8012BBD4: div.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8012BBD8: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8012BBDC: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8012BBE0: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
    // 0x8012BBE4: lwc1        $f16, 0xCA8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XCA8);
    // 0x8012BBE8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8012BBEC: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8012BBF0: lw          $a3, 0xC68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC68);
    // 0x8012BBF4: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012BBF8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8012BBFC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8012BC00: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8012BC04: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8012BC08: lwc1        $f10, 0xCE8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XCE8);
    // 0x8012BC0C: sub.d       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f26.d); 
    ctx->f8.d = ctx->f6.d - ctx->f26.d;
    // 0x8012BC10: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8012BC14: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8012BC18: jal         0x8012B81C
    // 0x8012BC1C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012B81C)(rdram, ctx);
        goto after_1;
    // 0x8012BC1C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8012BC20: lwc1        $f14, 0x368($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X368);
    // 0x8012BC24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8012BC28: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8012BC2C: nop

    // 0x8012BC30: bc1fl       L_8012BC44
    if (!c1cs) {
        // 0x8012BC34: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_8012BC44;
    }
    goto skip_14;
    // 0x8012BC34: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_14:
    // 0x8012BC38: b           L_8012BC44
    // 0x8012BC3C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
        goto L_8012BC44;
    // 0x8012BC3C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    // 0x8012BC40: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8012BC44:
    // 0x8012BC44: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x8012BC48: nop

    // 0x8012BC4C: bc1fl       L_8012BC60
    if (!c1cs) {
        // 0x8012BC50: mov.s       $f0, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
            goto L_8012BC60;
    }
    goto skip_15;
    // 0x8012BC50: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
    skip_15:
    // 0x8012BC54: b           L_8012BC60
    // 0x8012BC58: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
        goto L_8012BC60;
    // 0x8012BC58: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x8012BC5C: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
L_8012BC60:
    // 0x8012BC60: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8012BC64: nop

    // 0x8012BC68: bc1fl       L_8012BC78
    if (!c1cs) {
        // 0x8012BC6C: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_8012BC78;
    }
    goto skip_16;
    // 0x8012BC6C: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_16:
    // 0x8012BC70: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8012BC74: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_8012BC78:
    // 0x8012BC78: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8012BC7C: nop

    // 0x8012BC80: bc1fl       L_8012BC94
    if (!c1cs) {
        // 0x8012BC84: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_8012BC94;
    }
    goto skip_17;
    // 0x8012BC84: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_17:
    // 0x8012BC88: b           L_8012BC94
    // 0x8012BC8C: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
        goto L_8012BC94;
    // 0x8012BC8C: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x8012BC90: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8012BC94:
    // 0x8012BC94: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8012BC98: nop

    // 0x8012BC9C: bc1fl       L_8012BCB0
    if (!c1cs) {
        // 0x8012BCA0: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_8012BCB0;
    }
    goto skip_18;
    // 0x8012BCA0: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_18:
    // 0x8012BCA4: b           L_8012BCB0
    // 0x8012BCA8: neg.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = -ctx->f22.fl;
        goto L_8012BCB0;
    // 0x8012BCA8: neg.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = -ctx->f22.fl;
    // 0x8012BCAC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_8012BCB0:
    // 0x8012BCB0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8012BCB4: nop

    // 0x8012BCB8: bc1fl       L_8012BCC8
    if (!c1cs) {
        // 0x8012BCBC: c.eq.s      $f20, $f14
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
            goto L_8012BCC8;
    }
    goto skip_19;
    // 0x8012BCBC: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    skip_19:
    // 0x8012BCC0: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x8012BCC4: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
L_8012BCC8:
    // 0x8012BCC8: nop

    // 0x8012BCCC: bc1fl       L_8012BCE8
    if (!c1cs) {
        // 0x8012BCD0: lw          $t2, 0xD2C($s0)
        ctx->r10 = MEM_W(ctx->r16, 0XD2C);
            goto L_8012BCE8;
    }
    goto skip_20;
    // 0x8012BCD0: lw          $t2, 0xD2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XD2C);
    skip_20:
    // 0x8012BCD4: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x8012BCD8: nop

    // 0x8012BCDC: bc1tl       L_8012BCF8
    if (c1cs) {
        // 0x8012BCE0: lhu         $t7, 0x0($s1)
        ctx->r15 = MEM_HU(ctx->r17, 0X0);
            goto L_8012BCF8;
    }
    goto skip_21;
    // 0x8012BCE0: lhu         $t7, 0x0($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X0);
    skip_21:
    // 0x8012BCE4: lw          $t2, 0xD2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XD2C);
L_8012BCE8:
    // 0x8012BCE8: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x8012BCEC: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8012BCF0: sw          $t5, 0xD2C($s0)
    MEM_W(0XD2C, ctx->r16) = ctx->r13;
    // 0x8012BCF4: lhu         $t7, 0x0($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X0);
L_8012BCF8:
    // 0x8012BCF8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8012BCFC: bnel        $t7, $at, L_8012BF1C
    if (ctx->r15 != ctx->r1) {
        // 0x8012BD00: lhu         $v1, 0x4($s1)
        ctx->r3 = MEM_HU(ctx->r17, 0X4);
            goto L_8012BF1C;
    }
    goto skip_22;
    // 0x8012BD00: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    skip_22:
    // 0x8012BD04: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8012BD08: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8012BD0C: lwc1        $f4, 0x35C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x8012BD10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8012BD14: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8012BD18: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8012BD1C: nop

    // 0x8012BD20: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8012BD24: beql        $t8, $zero, L_8012BD74
    if (ctx->r24 == 0) {
        // 0x8012BD28: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_8012BD74;
    }
    goto skip_23;
    // 0x8012BD28: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_23:
    // 0x8012BD2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012BD30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8012BD34: sub.s       $f16, $f4, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8012BD38: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8012BD3C: nop

    // 0x8012BD40: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8012BD44: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8012BD48: nop

    // 0x8012BD4C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8012BD50: bne         $t8, $zero, L_8012BD68
    if (ctx->r24 != 0) {
        // 0x8012BD54: nop
    
            goto L_8012BD68;
    }
    // 0x8012BD54: nop

    // 0x8012BD58: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8012BD5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012BD60: b           L_8012BD80
    // 0x8012BD64: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8012BD80;
    // 0x8012BD64: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8012BD68:
    // 0x8012BD68: b           L_8012BD80
    // 0x8012BD6C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8012BD80;
    // 0x8012BD6C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8012BD70: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_8012BD74:
    // 0x8012BD74: nop

    // 0x8012BD78: bltz        $t8, L_8012BD68
    if (SIGNED(ctx->r24) < 0) {
        // 0x8012BD7C: nop
    
            goto L_8012BD68;
    }
    // 0x8012BD7C: nop

L_8012BD80:
    // 0x8012BD80: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8012BD84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8012BD88: lwc1        $f6, 0x360($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X360);
    // 0x8012BD8C: sw          $t8, 0xD30($s0)
    MEM_W(0XD30, ctx->r16) = ctx->r24;
    // 0x8012BD90: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8012BD94: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8012BD98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8012BD9C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8012BDA0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8012BDA4: nop

    // 0x8012BDA8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8012BDAC: beql        $t1, $zero, L_8012BDFC
    if (ctx->r9 == 0) {
        // 0x8012BDB0: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_8012BDFC;
    }
    goto skip_24;
    // 0x8012BDB0: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_24:
    // 0x8012BDB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012BDB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8012BDBC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8012BDC0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8012BDC4: nop

    // 0x8012BDC8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8012BDCC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8012BDD0: nop

    // 0x8012BDD4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8012BDD8: bne         $t1, $zero, L_8012BDF0
    if (ctx->r9 != 0) {
        // 0x8012BDDC: nop
    
            goto L_8012BDF0;
    }
    // 0x8012BDDC: nop

    // 0x8012BDE0: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8012BDE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012BDE8: b           L_8012BE08
    // 0x8012BDEC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8012BE08;
    // 0x8012BDEC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8012BDF0:
    // 0x8012BDF0: b           L_8012BE08
    // 0x8012BDF4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8012BE08;
    // 0x8012BDF4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8012BDF8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_8012BDFC:
    // 0x8012BDFC: nop

    // 0x8012BE00: bltz        $t1, L_8012BDF0
    if (SIGNED(ctx->r9) < 0) {
        // 0x8012BE04: nop
    
            goto L_8012BDF0;
    }
    // 0x8012BE04: nop

L_8012BE08:
    // 0x8012BE08: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8012BE0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8012BE10: lwc1        $f18, 0x364($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X364);
    // 0x8012BE14: sw          $t1, 0xD34($s0)
    MEM_W(0XD34, ctx->r16) = ctx->r9;
    // 0x8012BE18: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8012BE1C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8012BE20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8012BE24: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8012BE28: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8012BE2C: nop

    // 0x8012BE30: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8012BE34: beql        $t3, $zero, L_8012BE84
    if (ctx->r11 == 0) {
        // 0x8012BE38: mfc1        $t3, $f10
        ctx->r11 = (int32_t)ctx->f10.u32l;
            goto L_8012BE84;
    }
    goto skip_25;
    // 0x8012BE38: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    skip_25:
    // 0x8012BE3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8012BE40: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8012BE44: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8012BE48: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8012BE4C: nop

    // 0x8012BE50: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8012BE54: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8012BE58: nop

    // 0x8012BE5C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8012BE60: bne         $t3, $zero, L_8012BE78
    if (ctx->r11 != 0) {
        // 0x8012BE64: nop
    
            goto L_8012BE78;
    }
    // 0x8012BE64: nop

    // 0x8012BE68: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8012BE6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012BE70: b           L_8012BE90
    // 0x8012BE74: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8012BE90;
    // 0x8012BE74: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8012BE78:
    // 0x8012BE78: b           L_8012BE90
    // 0x8012BE7C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8012BE90;
    // 0x8012BE7C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8012BE80: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
L_8012BE84:
    // 0x8012BE84: nop

    // 0x8012BE88: bltz        $t3, L_8012BE78
    if (SIGNED(ctx->r11) < 0) {
        // 0x8012BE8C: nop
    
            goto L_8012BE78;
    }
    // 0x8012BE8C: nop

L_8012BE90:
    // 0x8012BE90: lbu         $t2, 0x35A($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X35A);
    // 0x8012BE94: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8012BE98: sw          $t3, 0xD38($s0)
    MEM_W(0XD38, ctx->r16) = ctx->r11;
    // 0x8012BE9C: b           L_8012BF18
    // 0x8012BEA0: sw          $t2, 0xD3C($s0)
    MEM_W(0XD3C, ctx->r16) = ctx->r10;
        goto L_8012BF18;
    // 0x8012BEA0: sw          $t2, 0xD3C($s0)
    MEM_W(0XD3C, ctx->r16) = ctx->r10;
    // 0x8012BEA4: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
L_8012BEA8:
    // 0x8012BEA8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8012BEAC: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x8012BEB0: lwc1        $f4, 0xCA8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XCA8);
    // 0x8012BEB4: lwc1        $f18, 0xCE8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XCE8);
    // 0x8012BEB8: lwc1        $f12, 0xBA8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XBA8);
    // 0x8012BEBC: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8012BEC0: lwc1        $f14, 0xBE8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XBE8);
    // 0x8012BEC4: add.d       $f6, $f16, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f26.d); 
    ctx->f6.d = ctx->f16.d + ctx->f26.d;
    // 0x8012BEC8: lw          $a2, 0xC28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC28);
    // 0x8012BECC: lw          $a3, 0xC68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC68);
    // 0x8012BED0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8012BED4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8012BED8: jal         0x8012B81C
    // 0x8012BEDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012B81C)(rdram, ctx);
        goto after_2;
    // 0x8012BEDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8012BEE0: lwc1        $f14, 0x36C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X36C);
    // 0x8012BEE4: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    // 0x8012BEE8: nop

    // 0x8012BEEC: bc1tl       L_8012BF1C
    if (c1cs) {
        // 0x8012BEF0: lhu         $v1, 0x4($s1)
        ctx->r3 = MEM_HU(ctx->r17, 0X4);
            goto L_8012BF1C;
    }
    goto skip_26;
    // 0x8012BEF0: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    skip_26:
    // 0x8012BEF4: c.lt.s      $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f14.fl < ctx->f28.fl;
    // 0x8012BEF8: nop

    // 0x8012BEFC: bc1fl       L_8012BF0C
    if (!c1cs) {
        // 0x8012BF00: lw          $t7, 0xD2C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XD2C);
            goto L_8012BF0C;
    }
    goto skip_27;
    // 0x8012BF00: lw          $t7, 0xD2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XD2C);
    skip_27:
    // 0x8012BF04: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x8012BF08: lw          $t7, 0xD2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XD2C);
L_8012BF0C:
    // 0x8012BF0C: lhu         $t6, 0x0($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X0);
    // 0x8012BF10: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8012BF14: sw          $t8, 0xD2C($s0)
    MEM_W(0XD2C, ctx->r16) = ctx->r24;
L_8012BF18:
    // 0x8012BF18: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
L_8012BF1C:
    // 0x8012BF1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8012BF20: bnel        $v1, $zero, L_8012B918
    if (ctx->r3 != 0) {
        // 0x8012BF24: lw          $t3, 0xD28($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XD28);
            goto L_8012B918;
    }
    goto skip_28;
    // 0x8012BF24: lw          $t3, 0xD28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XD28);
    skip_28:
L_8012BF28:
    // 0x8012BF28: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
L_8012BF2C:
    // 0x8012BF2C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8012BF30: andi        $t1, $t9, 0x200
    ctx->r9 = ctx->r25 & 0X200;
    // 0x8012BF34: beql        $t1, $zero, L_8012BF74
    if (ctx->r9 == 0) {
        // 0x8012BF38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8012BF74;
    }
    goto skip_29;
    // 0x8012BF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_29:
    // 0x8012BF3C: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8012BF40: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8012BF44: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x8012BF48: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8012BF4C: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8012BF50: add.s       $f6, $f16, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f28.fl;
    // 0x8012BF54: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x8012BF58: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8012BF5C: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8012BF60: add.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8012BF64: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
    // 0x8012BF68: b           L_8012BF74
    // 0x8012BF6C: lhu         $v0, 0xD2E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD2E);
        goto L_8012BF74;
    // 0x8012BF6C: lhu         $v0, 0xD2E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD2E);
    // 0x8012BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012BF74:
    // 0x8012BF74: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8012BF78: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8012BF7C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8012BF80: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8012BF84: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8012BF88: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8012BF8C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8012BF90: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8012BF94: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8012BF98: jr          $ra
    // 0x8012BF9C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8012BF9C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012bfa0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012bfa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012BFA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012BFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012BFA8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012BFAC: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x8012BFB0: beql        $t7, $zero, L_8012C13C
    if (ctx->r15 == 0) {
        // 0x8012BFB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012C13C;
    }
    goto skip_0;
    // 0x8012BFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8012BFB8: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x8012BFBC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8012BFC0: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8012BFC4: beq         $t8, $zero, L_8012BFD8
    if (ctx->r24 == 0) {
        // 0x8012BFC8: and         $t0, $v0, $at
        ctx->r8 = ctx->r2 & ctx->r1;
            goto L_8012BFD8;
    }
    // 0x8012BFC8: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x8012BFCC: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
    // 0x8012BFD0: b           L_8012BFDC
    // 0x8012BFD4: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
        goto L_8012BFDC;
    // 0x8012BFD4: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
L_8012BFD8:
    // 0x8012BFD8: sw          $t0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r8;
L_8012BFDC:
    // 0x8012BFDC: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x8012BFE0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8012BFE4: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8012BFE8: addiu       $at, $zero, -0xD9
    ctx->r1 = ADD32(0, -0XD9);
    // 0x8012BFEC: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
    // 0x8012BFF0: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8012BFF4: sw          $t4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r12;
    // 0x8012BFF8: jal         0x8012B85C
    // 0x8012BFFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012B85C)(rdram, ctx);
        goto after_0;
    // 0x8012BFFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012C000: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8012C004: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8012C008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8012C00C: lw          $t5, 0xD2C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XD2C);
    // 0x8012C010: andi        $t6, $v0, 0x21F
    ctx->r14 = ctx->r2 & 0X21F;
    // 0x8012C014: beq         $v0, $zero, L_8012C138
    if (ctx->r2 == 0) {
        // 0x8012C018: sw          $t5, 0x58($a0)
        MEM_W(0X58, ctx->r4) = ctx->r13;
            goto L_8012C138;
    }
    // 0x8012C018: sw          $t5, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r13;
    // 0x8012C01C: beq         $t6, $zero, L_8012C038
    if (ctx->r14 == 0) {
        // 0x8012C020: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8012C038;
    }
    // 0x8012C020: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8012C024: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8012C028: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8012C02C: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8012C030: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x8012C034: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
L_8012C038:
    // 0x8012C038: andi        $t9, $v1, 0x1E0
    ctx->r25 = ctx->r3 & 0X1E0;
    // 0x8012C03C: beq         $t9, $zero, L_8012C070
    if (ctx->r25 == 0) {
        // 0x8012C040: andi        $t5, $v1, 0x20
        ctx->r13 = ctx->r3 & 0X20;
            goto L_8012C070;
    }
    // 0x8012C040: andi        $t5, $v1, 0x20
    ctx->r13 = ctx->r3 & 0X20;
    // 0x8012C044: lw          $t0, 0xD3C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XD3C);
    // 0x8012C048: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8012C04C: beql        $t0, $at, L_8012C068
    if (ctx->r8 == ctx->r1) {
        // 0x8012C050: lw          $t3, 0x30($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X30);
            goto L_8012C068;
    }
    goto skip_1;
    // 0x8012C050: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    skip_1:
    // 0x8012C054: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x8012C058: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8012C05C: b           L_8012C070
    // 0x8012C060: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
        goto L_8012C070;
    // 0x8012C060: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
    // 0x8012C064: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
L_8012C068:
    // 0x8012C068: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8012C06C: sw          $t4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r12;
L_8012C070:
    // 0x8012C070: beql        $t5, $zero, L_8012C13C
    if (ctx->r13 == 0) {
        // 0x8012C074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012C13C;
    }
    goto skip_2;
    // 0x8012C074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8012C078: lw          $t6, 0xD38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD38);
    // 0x8012C07C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012C080: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8012C084: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8012C088: bgez        $t7, L_8012C09C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8012C08C: cvt.s.w     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8012C09C;
    }
    // 0x8012C08C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8012C090: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012C094: nop

    // 0x8012C098: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_8012C09C:
    // 0x8012C09C: lw          $t8, 0xD30($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XD30);
    // 0x8012C0A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012C0A4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8012C0A8: bgez        $t8, L_8012C0BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8012C0AC: cvt.s.w     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8012C0BC;
    }
    // 0x8012C0AC: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012C0B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012C0B4: nop

    // 0x8012C0B8: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
L_8012C0BC:
    // 0x8012C0BC: jal         0x8001EF38
    // 0x8012C0C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8012C0C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8012C0C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8012C0C8: addiu       $t5, $v0, 0x1800
    ctx->r13 = ADD32(ctx->r2, 0X1800);
    // 0x8012C0CC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8012C0D0: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x8012C0D4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8012C0D8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8012C0DC: lh          $t1, 0x12($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X12);
    // 0x8012C0E0: subu        $v1, $t1, $t5
    ctx->r3 = SUB32(ctx->r9, ctx->r13);
    // 0x8012C0E4: addiu       $v1, $v1, -0x1000
    ctx->r3 = ADD32(ctx->r3, -0X1000);
    // 0x8012C0E8: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8012C0EC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8012C0F0: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x8012C0F4: bne         $at, $zero, L_8012C10C
    if (ctx->r1 != 0) {
        // 0x8012C0F8: slti        $at, $v1, 0x1C01
        ctx->r1 = SIGNED(ctx->r3) < 0X1C01 ? 1 : 0;
            goto L_8012C10C;
    }
    // 0x8012C0F8: slti        $at, $v1, 0x1C01
    ctx->r1 = SIGNED(ctx->r3) < 0X1C01 ? 1 : 0;
    // 0x8012C0FC: bne         $at, $zero, L_8012C138
    if (ctx->r1 != 0) {
        // 0x8012C100: slti        $at, $v1, 0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < 0X1FFF ? 1 : 0;
            goto L_8012C138;
    }
    // 0x8012C100: slti        $at, $v1, 0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < 0X1FFF ? 1 : 0;
    // 0x8012C104: beql        $at, $zero, L_8012C13C
    if (ctx->r1 == 0) {
        // 0x8012C108: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012C13C;
    }
    goto skip_3;
    // 0x8012C108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_8012C10C:
    // 0x8012C10C: lw          $t6, 0xD3C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD3C);
    // 0x8012C110: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8012C114: beql        $t6, $at, L_8012C130
    if (ctx->r14 == ctx->r1) {
        // 0x8012C118: lw          $t9, 0x30($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X30);
            goto L_8012C130;
    }
    goto skip_4;
    // 0x8012C118: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    skip_4:
    // 0x8012C11C: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8012C120: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8012C124: b           L_8012C138
    // 0x8012C128: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
        goto L_8012C138;
    // 0x8012C128: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x8012C12C: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
L_8012C130:
    // 0x8012C130: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x8012C134: sw          $t0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r8;
L_8012C138:
    // 0x8012C138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012C13C:
    // 0x8012C13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012C140: jr          $ra
    // 0x8012C144: nop

    return;
    // 0x8012C144: nop

;}
RECOMP_FUNC void M7_FUN_8012c148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012C14C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8012C150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012C154: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8012C158: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8012C15C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8012C160: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8012C164: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x8012C168: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8012C16C: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8012C170: jal         0x8010843C
    // 0x8012C174: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_0;
    // 0x8012C174: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8012C178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012C17C: bne         $v0, $at, L_8012C1AC
    if (ctx->r2 != ctx->r1) {
        // 0x8012C180: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_8012C1AC;
    }
    // 0x8012C180: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8012C184: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012C188: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8012C18C: lwc1        $f8, 0x374($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X374);
    // 0x8012C190: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
    // 0x8012C194: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8012C198: lwc1        $f10, 0x378($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X378);
    // 0x8012C19C: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x8012C1A0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8012C1A4: lwc1        $f16, 0x37C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X37C);
    // 0x8012C1A8: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
L_8012C1AC:
    // 0x8012C1AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012C1B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012C1B4: jr          $ra
    // 0x8012C1B8: nop

    return;
    // 0x8012C1B8: nop

;}
RECOMP_FUNC void M7_FUN_8012c1bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C1BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012C1C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012C1C4: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012C1C8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8012C1CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8012C1D0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8012C1D4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8012C1D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012C1DC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012C1E0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012C1E4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8012C1E8: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8012C1EC: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8012C1F0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012C1F4: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012C1F8: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8012C1FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8012C200: addiu       $t9, $v0, 0xC
    ctx->r25 = ADD32(ctx->r2, 0XC);
    // 0x8012C204: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8012C208: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8012C20C: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x8012C210: jal         0x8012C148
    // 0x8012C214: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8012C148)(rdram, ctx);
        goto after_0;
    // 0x8012C214: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x8012C218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012C21C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012C220: jr          $ra
    // 0x8012C224: nop

    return;
    // 0x8012C224: nop

;}
RECOMP_FUNC void M7_FUN_8012c228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012C22C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012C230: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012C234: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012C238: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8012C23C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8012C240: ori         $t7, $t6, 0x800
    ctx->r15 = ctx->r14 | 0X800;
    // 0x8012C244: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8012C248: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8012C24C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8012C250: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8012C254: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8012C258: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x8012C25C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8012C260: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8012C264: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8012C268: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x8012C26C: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x8012C270: jal         0x8000522C
    // 0x8012C274: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_0;
    // 0x8012C274: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8012C278: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8012C27C: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x8012C280: sw          $v0, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r2;
    // 0x8012C284: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x8012C288: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8012C28C: swc1        $f4, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->f4.u32l;
    // 0x8012C290: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
    // 0x8012C294: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8012C298: swc1        $f6, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->f6.u32l;
    // 0x8012C29C: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x8012C2A0: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8012C2A4: swc1        $f8, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->f8.u32l;
    // 0x8012C2A8: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x8012C2AC: lh          $t8, 0x10($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X10);
    // 0x8012C2B0: sh          $t8, 0x84($a3)
    MEM_H(0X84, ctx->r7) = ctx->r24;
    // 0x8012C2B4: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x8012C2B8: lh          $t0, 0x12($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X12);
    // 0x8012C2BC: sh          $t0, 0x86($a3)
    MEM_H(0X86, ctx->r7) = ctx->r8;
    // 0x8012C2C0: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x8012C2C4: lh          $t2, 0x14($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X14);
    // 0x8012C2C8: sh          $t2, 0x88($a3)
    MEM_H(0X88, ctx->r7) = ctx->r10;
    // 0x8012C2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012C2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012C2D4: jr          $ra
    // 0x8012C2D8: nop

    return;
    // 0x8012C2D8: nop

;}
RECOMP_FUNC void M7_FUN_8012c2dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C2DC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8012C2E0: addiu       $t7, $t7, -0x2578
    ctx->r15 = ADD32(ctx->r15, -0X2578);
    // 0x8012C2E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8012C2E8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8012C2EC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8012C2F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8012C2F4: addiu       $t1, $t1, -0x50C8
    ctx->r9 = ADD32(ctx->r9, -0X50C8);
    // 0x8012C2F8: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x8012C2FC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C300: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C304: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x8012C308: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x8012C30C: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x8012C310: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8012C314: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8012C318: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
    // 0x8012C31C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8012C320: lbu         $t4, 0xF32($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XF32);
    // 0x8012C324: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8012C328: sb          $t4, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r12;
    // 0x8012C32C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8012C330: lbu         $t7, 0xF33($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XF33);
    // 0x8012C334: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8012C338: sb          $t7, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r15;
    // 0x8012C33C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8012C340: lbu         $t0, 0xF34($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XF34);
    // 0x8012C344: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x8012C348: sb          $t0, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r8;
    // 0x8012C34C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8012C350: lbu         $t3, 0xF35($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XF35);
    // 0x8012C354: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x8012C358: jr          $ra
    // 0x8012C35C: sb          $t3, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r11;
    return;
    // 0x8012C35C: sb          $t3, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r11;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012c360(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012c360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C360: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012C364: jr          $ra
    // 0x8012C368: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8012C368: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012c36c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012c36c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C36C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012C370: jr          $ra
    // 0x8012C374: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8012C374: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012c378(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012c378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012C37C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012C380: jal         0x80005700
    // 0x8012C384: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x8012C384: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8012C388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012C38C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012C390: jr          $ra
    // 0x8012C394: nop

    return;
    // 0x8012C394: nop

;}
RECOMP_FUNC void M7_FUN_8012c398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C398: nop

    // 0x8012C39C: nop

;}
RECOMP_FUNC void M7_FUN_8012c3a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C3A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8012C3A4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8012C3A8: sltiu       $at, $a1, 0x9
    ctx->r1 = ctx->r5 < 0X9 ? 1 : 0;
    // 0x8012C3AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012C3B0: addiu       $v1, $zero, 0x3E7
    ctx->r3 = ADD32(0, 0X3E7);
    // 0x8012C3B4: beq         $at, $zero, L_8012C468
    if (ctx->r1 == 0) {
        // 0x8012C3B8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8012C468;
    }
    // 0x8012C3B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8012C3BC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8012C3C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012C3C4: addu        $at, $at, $t6
    gpr jr_addend_8012C3CC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8012C3C8: lw          $t6, -0x2AF4($at)
    ctx->r14 = ADD32(ctx->r1, -0X2AF4);
    // 0x8012C3CC: jr          $t6
    // 0x8012C3D0: nop

    switch (jr_addend_8012C3CC >> 2) {
        case 0: goto L_8012C3D4; break;
        case 1: goto L_8012C3F4; break;
        case 2: goto L_8012C404; break;
        case 3: goto L_8012C3E4; break;
        case 4: goto L_8012C414; break;
        case 5: goto L_8012C43C; break;
        case 6: goto L_8012C444; break;
        case 7: goto L_8012C428; break;
        case 8: goto L_8012C458; break;
        default: switch_error(__func__, 0x8012C3CC, 0x8018D50C);
    }
    // 0x8012C3D0: nop

L_8012C3D4:
    // 0x8012C3D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C3D8: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C3DC: b           L_8012C478
    // 0x8012C3E0: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C3E0: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
L_8012C3E4:
    // 0x8012C3E4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C3E8: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C3EC: b           L_8012C478
    // 0x8012C3F0: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C3F0: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
L_8012C3F4:
    // 0x8012C3F4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C3F8: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C3FC: b           L_8012C478
    // 0x8012C400: lw          $a0, 0x4C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4C);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C400: lw          $a0, 0x4C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4C);
L_8012C404:
    // 0x8012C404: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C408: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C40C: b           L_8012C478
    // 0x8012C410: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C410: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
L_8012C414:
    // 0x8012C414: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C418: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C41C: lw          $v1, 0x22C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X22C);
    // 0x8012C420: b           L_8012C478
    // 0x8012C424: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C424: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
L_8012C428:
    // 0x8012C428: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C42C: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C430: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x8012C434: b           L_8012C478
    // 0x8012C438: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C438: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
L_8012C43C:
    // 0x8012C43C: jr          $ra
    // 0x8012C440: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8012C440: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8012C444:
    // 0x8012C444: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C448: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C44C: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x8012C450: b           L_8012C478
    // 0x8012C454: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C454: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
L_8012C458:
    // 0x8012C458: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C45C: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C460: b           L_8012C478
    // 0x8012C464: lw          $a0, 0x3C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X3C);
    LOOKUP_FUNC(0x8012C478)(rdram, ctx);
    return;
    // 0x8012C464: lw          $a0, 0x3C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X3C);
L_8012C468:
    // 0x8012C468: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8012C46C: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8012C470: jr          $ra
    // 0x8012C474: lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X3C);
    return;
    // 0x8012C474: lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X3C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012c478(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012c478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C478: beql        $a0, $zero, L_8012C4B4
    if (ctx->r4 == 0) {
        // 0x8012C47C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8012C4B4;
    }
    goto skip_0;
    // 0x8012C47C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x8012C480: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x8012C484: beql        $a1, $zero, L_8012C4B4
    if (ctx->r5 == 0) {
        // 0x8012C488: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8012C4B4;
    }
    goto skip_1;
    // 0x8012C488: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_1:
    // 0x8012C48C: beql        $a1, $zero, L_8012C4B4
    if (ctx->r5 == 0) {
        // 0x8012C490: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8012C4B4;
    }
    goto skip_2;
    // 0x8012C490: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_2:
    // 0x8012C494: lbu         $t7, 0x34($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X34);
L_8012C498:
    // 0x8012C498: bnel        $a2, $t7, L_8012C4A8
    if (ctx->r6 != ctx->r15) {
        // 0x8012C49C: lw          $a1, 0x0($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X0);
            goto L_8012C4A8;
    }
    goto skip_3;
    // 0x8012C49C: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    skip_3:
    // 0x8012C4A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8012C4A4: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
L_8012C4A8:
    // 0x8012C4A8: bnel        $a1, $zero, L_8012C498
    if (ctx->r5 != 0) {
        // 0x8012C4AC: lbu         $t7, 0x34($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X34);
            goto L_8012C498;
    }
    goto skip_4;
    // 0x8012C4AC: lbu         $t7, 0x34($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X34);
    skip_4:
    // 0x8012C4B0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8012C4B4:
    // 0x8012C4B4: beql        $at, $zero, L_8012C4C8
    if (ctx->r1 == 0) {
        // 0x8012C4B8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8012C4C8;
    }
    goto skip_5;
    // 0x8012C4B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_5:
    // 0x8012C4BC: jr          $ra
    // 0x8012C4C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8012C4C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012C4C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8012C4C8:
    // 0x8012C4C8: jr          $ra
    // 0x8012C4CC: nop

    return;
    // 0x8012C4CC: nop

;}
RECOMP_FUNC void M7_FUN_8012c4d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C4D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012C4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012C4D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012C4DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8012C4E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8012C4E4: jal         0x8012C3A0
    // 0x8012C4E8: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    LOOKUP_FUNC(0x8012C3A0)(rdram, ctx);
        goto after_0;
    // 0x8012C4E8: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    after_0:
    // 0x8012C4EC: beq         $v0, $zero, L_8012C518
    if (ctx->r2 == 0) {
        // 0x8012C4F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8012C518;
    }
    // 0x8012C4F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8012C4F4: jal         0x80005670
    // 0x8012C4F8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8012C4F8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8012C4FC: beq         $v0, $zero, L_8012C518
    if (ctx->r2 == 0) {
        // 0x8012C500: lbu         $t6, 0x33($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X33);
            goto L_8012C518;
    }
    // 0x8012C500: lbu         $t6, 0x33($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X33);
    // 0x8012C504: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x8012C508: sb          $t6, 0x34($v0)
    MEM_B(0X34, ctx->r2) = ctx->r14;
    // 0x8012C50C: sb          $t7, 0x3E($v0)
    MEM_B(0X3E, ctx->r2) = ctx->r15;
    // 0x8012C510: b           L_8012C51C
    // 0x8012C514: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
        goto L_8012C51C;
    // 0x8012C514: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
L_8012C518:
    // 0x8012C518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012C51C:
    // 0x8012C51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012C520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012C524: jr          $ra
    // 0x8012C528: nop

    return;
    // 0x8012C528: nop

;}
RECOMP_FUNC void M7_FUN_8012c52c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C52C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012C530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012C534: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012C538: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8012C53C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8012C540: jal         0x8012C3A0
    // 0x8012C544: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    LOOKUP_FUNC(0x8012C3A0)(rdram, ctx);
        goto after_0;
    // 0x8012C544: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x8012C548: beq         $v0, $zero, L_8012C5DC
    if (ctx->r2 == 0) {
        // 0x8012C54C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8012C5DC;
    }
    // 0x8012C54C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8012C550: jal         0x80005670
    // 0x8012C554: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8012C554: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8012C558: beq         $v0, $zero, L_8012C5DC
    if (ctx->r2 == 0) {
        // 0x8012C55C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8012C5DC;
    }
    // 0x8012C55C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8012C560: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8012C564: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    // 0x8012C568: jal         0x80005F6C
    // 0x8012C56C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_2;
    // 0x8012C56C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8012C570: bne         $v0, $zero, L_8012C588
    if (ctx->r2 != 0) {
        // 0x8012C574: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8012C588;
    }
    // 0x8012C574: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8012C578: jal         0x80005700
    // 0x8012C57C: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x8012C57C: nop

    after_3:
    // 0x8012C580: b           L_8012C5E0
    // 0x8012C584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012C5E0;
    // 0x8012C584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012C588:
    // 0x8012C588: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012C58C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8012C590: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    // 0x8012C594: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8012C598: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8012C59C: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x8012C5A0: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8012C5A4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8012C5A8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012C5AC: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x8012C5B0: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x8012C5B4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012C5B8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8012C5BC: swc1        $f8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f8.u32l;
    // 0x8012C5C0: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x8012C5C4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8012C5C8: sw          $t3, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r11;
    // 0x8012C5CC: lbu         $t4, 0x3B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3B);
    // 0x8012C5D0: sb          $t5, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r13;
    // 0x8012C5D4: b           L_8012C5E0
    // 0x8012C5D8: sb          $t4, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r12;
        goto L_8012C5E0;
    // 0x8012C5D8: sb          $t4, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r12;
L_8012C5DC:
    // 0x8012C5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012C5E0:
    // 0x8012C5E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012C5E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012C5E8: jr          $ra
    // 0x8012C5EC: nop

    return;
    // 0x8012C5EC: nop

;}
RECOMP_FUNC void M7_FUN_8012c5f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C5F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012C5F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012C5F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012C5FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8012C600: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8012C604: jal         0x8012C3A0
    // 0x8012C608: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    LOOKUP_FUNC(0x8012C3A0)(rdram, ctx);
        goto after_0;
    // 0x8012C608: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x8012C60C: beq         $v0, $zero, L_8012C6A0
    if (ctx->r2 == 0) {
        // 0x8012C610: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8012C6A0;
    }
    // 0x8012C610: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8012C614: jal         0x80005670
    // 0x8012C618: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8012C618: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8012C61C: beq         $v0, $zero, L_8012C6A0
    if (ctx->r2 == 0) {
        // 0x8012C620: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8012C6A0;
    }
    // 0x8012C620: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8012C624: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8012C628: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x8012C62C: jal         0x80005F6C
    // 0x8012C630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_2;
    // 0x8012C630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8012C634: bne         $v0, $zero, L_8012C64C
    if (ctx->r2 != 0) {
        // 0x8012C638: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8012C64C;
    }
    // 0x8012C638: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8012C63C: jal         0x80005700
    // 0x8012C640: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x8012C640: nop

    after_3:
    // 0x8012C644: b           L_8012C6A4
    // 0x8012C648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012C6A4;
    // 0x8012C648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012C64C:
    // 0x8012C64C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012C650: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8012C654: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    // 0x8012C658: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8012C65C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8012C660: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x8012C664: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8012C668: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8012C66C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8012C670: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x8012C674: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x8012C678: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012C67C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8012C680: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x8012C684: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x8012C688: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8012C68C: sw          $t3, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r11;
    // 0x8012C690: lbu         $t4, 0x3B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3B);
    // 0x8012C694: sb          $t5, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r13;
    // 0x8012C698: b           L_8012C6A4
    // 0x8012C69C: sb          $t4, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r12;
        goto L_8012C6A4;
    // 0x8012C69C: sb          $t4, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r12;
L_8012C6A0:
    // 0x8012C6A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012C6A4:
    // 0x8012C6A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012C6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012C6AC: jr          $ra
    // 0x8012C6B0: nop

    return;
    // 0x8012C6B0: nop

;}
RECOMP_FUNC void M7_FUN_8012c6b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C6B4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012C6B8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012C6BC: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x8012C6C0: addiu       $at, $zero, 0x11B7
    ctx->r1 = ADD32(0, 0X11B7);
    // 0x8012C6C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8012C6C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8012C6CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8012C6D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8012C6D4: addiu       $t8, $t7, 0x929
    ctx->r24 = ADD32(ctx->r15, 0X929);
    // 0x8012C6D8: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8012C6DC: mfhi        $t9
    ctx->r25 = hi;
    // 0x8012C6E0: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8012C6E4: sh          $t9, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r25;
    // 0x8012C6E8: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8012C6EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012C6F0: ldc1        $f8, -0x2AD0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2AD0);
    // 0x8012C6F4: mflo        $t1
    ctx->r9 = lo;
    // 0x8012C6F8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8012C6FC: nop

    // 0x8012C700: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8012C704: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8012C708: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8012C70C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8012C710: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8012C714: jr          $ra
    // 0x8012C718: nop

    return;
    // 0x8012C718: nop

;}
RECOMP_FUNC void M7_FUN_8012c71c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C71C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8012C720: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8012C724: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8012C728: beql        $v1, $zero, L_8012C754
    if (ctx->r3 == 0) {
        // 0x8012C72C: lw          $t0, 0x30($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X30);
            goto L_8012C754;
    }
    goto skip_0;
    // 0x8012C72C: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x8012C730: swc1        $f12, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f12.u32l;
    // 0x8012C734: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012C738: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8012C73C: swc1        $f12, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f12.u32l;
    // 0x8012C740: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8012C744: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012C748: jr          $ra
    // 0x8012C74C: swc1        $f12, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f12.u32l;
    return;
    // 0x8012C74C: swc1        $f12, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f12.u32l;
    // 0x8012C750: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
L_8012C754:
    // 0x8012C754: swc1        $f12, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f12.u32l;
    // 0x8012C758: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x8012C75C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8012C760: swc1        $f12, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f12.u32l;
    // 0x8012C764: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8012C768: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8012C76C: swc1        $f12, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f12.u32l;
    // 0x8012C770: jr          $ra
    // 0x8012C774: nop

    return;
    // 0x8012C774: nop

;}
RECOMP_FUNC void M7_FUN_8012c778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C778: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012C77C: jr          $ra
    // 0x8012C780: sw          $zero, 0x0($zero)
    MEM_W(0X0, 0) = 0;
    return;
    // 0x8012C780: sw          $zero, 0x0($zero)
    MEM_W(0X0, 0) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012c784(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012c784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C784: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8012C788: addiu       $t7, $t7, -0x2578
    ctx->r15 = ADD32(ctx->r15, -0X2578);
    // 0x8012C78C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8012C790: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8012C794: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8012C798: lw          $a3, 0x2C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X2C);
    // 0x8012C79C: beql        $a3, $zero, L_8012C820
    if (ctx->r7 == 0) {
        // 0x8012C7A0: lhu         $t1, 0x36($a0)
        ctx->r9 = MEM_HU(ctx->r4, 0X36);
            goto L_8012C820;
    }
    goto skip_0;
    // 0x8012C7A0: lhu         $t1, 0x36($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X36);
    skip_0:
    // 0x8012C7A4: lhu         $t8, 0x36($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X36);
    // 0x8012C7A8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8012C7AC: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x8012C7B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8012C7B4: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8012C7B8: lw          $t1, -0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, -0X4);
    // 0x8012C7BC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8012C7C0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8012C7C4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8012C7C8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8012C7CC: sw          $t5, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r13;
    // 0x8012C7D0: lhu         $t6, 0x36($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X36);
    // 0x8012C7D4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8012C7D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8012C7DC: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8012C7E0: lw          $t9, -0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X4);
    // 0x8012C7E4: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8012C7E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8012C7EC: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8012C7F0: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
    // 0x8012C7F4: lhu         $t4, 0x36($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X36);
    // 0x8012C7F8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8012C7FC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8012C800: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8012C804: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x8012C808: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x8012C80C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8012C810: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x8012C814: jr          $ra
    // 0x8012C818: sh          $t9, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r25;
    return;
    // 0x8012C818: sh          $t9, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r25;
    // 0x8012C81C: lhu         $t1, 0x36($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X36);
L_8012C820:
    // 0x8012C820: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8012C824: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x8012C828: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8012C82C: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8012C830: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x8012C834: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8012C838: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x8012C83C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012C840: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8012C844: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8012C848: sw          $t0, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r8;
    // 0x8012C84C: lhu         $t2, 0x36($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X36);
    // 0x8012C850: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8012C854: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8012C858: addu        $t3, $a1, $t1
    ctx->r11 = ADD32(ctx->r5, ctx->r9);
    // 0x8012C85C: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x8012C860: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8012C864: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8012C868: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8012C86C: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8012C870: lhu         $t0, 0x36($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X36);
    // 0x8012C874: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8012C878: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8012C87C: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x8012C880: lw          $t1, -0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, -0X4);
    // 0x8012C884: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8012C888: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8012C88C: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x8012C890: sh          $t4, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r12;
    // 0x8012C894: jr          $ra
    // 0x8012C898: nop

    return;
    // 0x8012C898: nop

;}
RECOMP_FUNC void M7_FUN_8012c89c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C89C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8012C8A0: addiu       $t7, $t7, -0x2578
    ctx->r15 = ADD32(ctx->r15, -0X2578);
    // 0x8012C8A4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8012C8A8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8012C8AC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8012C8B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012C8B4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8012C8B8: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x8012C8BC: addiu       $t6, $t6, 0x1CF0
    ctx->r14 = ADD32(ctx->r14, 0X1CF0);
    // 0x8012C8C0: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8012C8C4: beq         $a0, $zero, L_8012C928
    if (ctx->r4 == 0) {
            // 0x8012C8C8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    LOOKUP_FUNC(0x8012C928)(rdram, ctx);
    return;
    }
    // 0x8012C8C8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8012C8CC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8012C8D0: addiu       $t9, $t9, 0x1CF0
    ctx->r25 = ADD32(ctx->r25, 0X1CF0);
    // 0x8012C8D4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8012C8D8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8012C8DC: lw          $t0, -0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, -0X4);
    // 0x8012C8E0: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x8012C8E4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8012C8E8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8012C8EC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8012C8F0: sw          $t4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r12;
    // 0x8012C8F4: lw          $t5, -0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, -0X4);
    // 0x8012C8F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8012C8FC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8012C900: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012C904: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8012C908: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x8012C90C: lw          $t0, -0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, -0X4);
    // 0x8012C910: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8012C914: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8012C918: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8012C91C: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x8012C920: jr          $ra
    // 0x8012C924: sh          $t2, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = ctx->r10;
    return;
    // 0x8012C924: sh          $t2, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = ctx->r10;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012c928(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012c928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C928: lw          $t8, -0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, -0X4);
    // 0x8012C92C: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8012C930: lw          $t3, 0x30($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X30);
    // 0x8012C934: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8012C938: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8012C93C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8012C940: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x8012C944: lw          $t2, -0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, -0X4);
    // 0x8012C948: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8012C94C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8012C950: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x8012C954: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8012C958: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x8012C95C: lw          $t7, -0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, -0X4);
    // 0x8012C960: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8012C964: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8012C968: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x8012C96C: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8012C970: sh          $t0, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r8;
    // 0x8012C974: jr          $ra
    // 0x8012C978: nop

    return;
    // 0x8012C978: nop

;}
RECOMP_FUNC void M7_FUN_8012c97c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C97C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8012C980: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8012C984: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8012C988: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012c98c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012c98c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C98C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012C990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012C994: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8012C998: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8012C99C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8012C9A0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8012C9A4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8012C9A8: jal         0x8000522C
    // 0x8012C9AC: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_0;
    // 0x8012C9AC: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    after_0:
    // 0x8012C9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012C9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012C9B8: jr          $ra
    // 0x8012C9BC: nop

    return;
    // 0x8012C9BC: nop

;}
RECOMP_FUNC void M7_FUN_8012c9c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012C9C0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012C9C4: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8012C9C8: beq         $t7, $zero, L_8012CAB0
    if (ctx->r15 == 0) {
        // 0x8012C9CC: nop
    
            goto L_8012CAB0;
    }
    // 0x8012C9CC: nop

    // 0x8012C9D0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8012C9D4: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8012C9D8: beql        $v1, $zero, L_8012CA4C
    if (ctx->r3 == 0) {
        // 0x8012C9DC: lw          $v1, 0x30($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X30);
            goto L_8012CA4C;
    }
    goto skip_0;
    // 0x8012C9DC: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x8012C9E0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012C9E4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8012C9E8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8012C9EC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012C9F0: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8012C9F4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012C9F8: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8012C9FC: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8012CA00: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8012CA04: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x8012CA08: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8012CA0C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8012CA10: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CA14: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8012CA18: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CA1C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8012CA20: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x8012CA24: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8012CA28: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8012CA2C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012CA30: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012CA34: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CA38: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8012CA3C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CA40: jr          $ra
    // 0x8012CA44: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x8012CA44: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
    // 0x8012CA48: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
L_8012CA4C:
    // 0x8012CA4C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8012CA50: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012CA54: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8012CA58: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CA5C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8012CA60: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CA64: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8012CA68: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x8012CA6C: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8012CA70: lw          $v1, 0x30($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X30);
    // 0x8012CA74: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012CA78: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8012CA7C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CA80: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8012CA84: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CA88: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8012CA8C: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x8012CA90: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8012CA94: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x8012CA98: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8012CA9C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012CAA0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CAA4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8012CAA8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CAAC: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
L_8012CAB0:
    // 0x8012CAB0: jr          $ra
    // 0x8012CAB4: nop

    return;
    // 0x8012CAB4: nop

;}
RECOMP_FUNC void M7_FUN_8012cab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CAB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012CABC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8012CAC0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8012CAC4: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CAC8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8012CB3C;
    }
    // 0x8012CAC8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8012CACC: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CAD0: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8012CB3C;
    }
    // 0x8012CAD0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8012CAD4: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CAD8: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8012CB3C;
    }
    // 0x8012CAD8: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8012CADC: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CAE0: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8012CB3C;
    }
    // 0x8012CAE0: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8012CAE4: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CAE8: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_8012CB3C;
    }
    // 0x8012CAE8: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8012CAEC: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CAF0: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_8012CB3C;
    }
    // 0x8012CAF0: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8012CAF4: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CAF8: addiu       $at, $zero, 0x28
        ctx->r1 = ADD32(0, 0X28);
            goto L_8012CB3C;
    }
    // 0x8012CAF8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8012CAFC: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CB00: addiu       $at, $zero, 0x46
        ctx->r1 = ADD32(0, 0X46);
            goto L_8012CB3C;
    }
    // 0x8012CB00: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x8012CB04: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CB08: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_8012CB3C;
    }
    // 0x8012CB08: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x8012CB0C: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CB10: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8012CB3C;
    }
    // 0x8012CB10: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x8012CB14: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CB18: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_8012CB3C;
    }
    // 0x8012CB18: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8012CB1C: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CB20: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8012CB3C;
    }
    // 0x8012CB20: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x8012CB24: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CB28: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_8012CB3C;
    }
    // 0x8012CB28: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x8012CB2C: beq         $a0, $at, L_8012CB3C
    if (ctx->r4 == ctx->r1) {
        // 0x8012CB30: addiu       $at, $zero, 0x5D
        ctx->r1 = ADD32(0, 0X5D);
            goto L_8012CB3C;
    }
    // 0x8012CB30: addiu       $at, $zero, 0x5D
    ctx->r1 = ADD32(0, 0X5D);
    // 0x8012CB34: bne         $a0, $at, L_8012CB44
    if (ctx->r4 != ctx->r1) {
            // 0x8012CB38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x8012CB44)(rdram, ctx);
    return;
    }
    // 0x8012CB38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012CB3C:
    // 0x8012CB3C: jr          $ra
    // 0x8012CB40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012CB40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012cb44(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012cb44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CB44: jr          $ra
    // 0x8012CB48: nop

    return;
    // 0x8012CB48: nop

;}
RECOMP_FUNC void M7_FUN_8012cb4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CB4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012CB50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012CB54: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012CB58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8012CB5C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8012CB60: beql        $t7, $zero, L_8012CD1C
    if (ctx->r15 == 0) {
        // 0x8012CB64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_0;
    // 0x8012CB64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8012CB68: lbu         $t8, 0x3E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X3E);
    // 0x8012CB6C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012CB70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012CB74: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8012CB78: bgez        $t8, L_8012CB8C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8012CB7C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8012CB8C;
    }
    // 0x8012CB7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012CB80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012CB84: nop

    // 0x8012CB88: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8012CB8C:
    // 0x8012CB8C: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8012CB90: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012CB94: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8012CB98: lwc1        $f4, 0x44($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
    // 0x8012CB9C: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8012CBA0: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x8012CBA4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CBA8: sub.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d - ctx->f18.d;
    // 0x8012CBAC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8012CBB0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8012CBB4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8012CBB8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8012CBBC: swc1        $f10, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f10.u32l;
    // 0x8012CBC0: lwc1        $f16, 0x44($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X44);
    // 0x8012CBC4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8012CBC8: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8012CBCC: nop

    // 0x8012CBD0: bc1fl       L_8012CBE8
    if (!c1cs) {
        // 0x8012CBD4: lw          $t9, 0x30($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X30);
            goto L_8012CBE8;
    }
    goto skip_1;
    // 0x8012CBD4: lw          $t9, 0x30($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X30);
    skip_1:
    // 0x8012CBD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8012CBDC: b           L_8012CD18
    // 0x8012CBE0: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
        goto L_8012CD18;
    // 0x8012CBE0: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
    // 0x8012CBE4: lw          $t9, 0x30($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X30);
L_8012CBE8:
    // 0x8012CBE8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8012CBEC: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8012CBF0: beql        $t0, $zero, L_8012CD1C
    if (ctx->r8 == 0) {
        // 0x8012CBF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_2;
    // 0x8012CBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8012CBF8: lbu         $a0, -0x440B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X440B);
    // 0x8012CBFC: jal         0x8012CAB8
    // 0x8012CC00: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8012CAB8)(rdram, ctx);
        goto after_0;
    // 0x8012CC00: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8012CC04: beq         $v0, $zero, L_8012CCCC
    if (ctx->r2 == 0) {
        // 0x8012CC08: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8012CCCC;
    }
    // 0x8012CC08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8012CC0C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8012CC10: lhu         $t1, -0x3520($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X3520);
    // 0x8012CC14: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8012CC18: bnel        $t2, $zero, L_8012CC38
    if (ctx->r10 != 0) {
        // 0x8012CC1C: lwc1        $f6, 0x44($a1)
        ctx->f6.u32l = MEM_W(ctx->r5, 0X44);
            goto L_8012CC38;
    }
    goto skip_3;
    // 0x8012CC1C: lwc1        $f6, 0x44($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X44);
    skip_3:
    // 0x8012CC20: jal         0x801F1114
    // 0x8012CC24: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801F1114)(rdram, ctx);
        goto after_1;
    // 0x8012CC24: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8012CC28: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8012CC2C: beq         $v0, $at, L_8012CC80
    if (ctx->r2 == ctx->r1) {
        // 0x8012CC30: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8012CC80;
    }
    // 0x8012CC30: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8012CC34: lwc1        $f6, 0x44($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X44);
L_8012CC38:
    // 0x8012CC38: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8012CC3C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8012CC40: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8012CC44: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8012CC48: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8012CC4C: nop

    // 0x8012CC50: bc1fl       L_8012CD1C
    if (!c1cs) {
        // 0x8012CC54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_4;
    // 0x8012CC54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8012CC58: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012CC5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012CC60: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8012CC64: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x8012CC68: nop

    // 0x8012CC6C: bc1fl       L_8012CD1C
    if (!c1cs) {
        // 0x8012CC70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_5;
    // 0x8012CC70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8012CC74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8012CC78: b           L_8012CD18
    // 0x8012CC7C: swc1        $f4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f4.u32l;
        goto L_8012CD18;
    // 0x8012CC7C: swc1        $f4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f4.u32l;
L_8012CC80:
    // 0x8012CC80: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x8012CC84: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8012CC88: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8012CC8C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8012CC90: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8012CC94: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8012CC98: nop

    // 0x8012CC9C: bc1fl       L_8012CD1C
    if (!c1cs) {
        // 0x8012CCA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_6;
    // 0x8012CCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8012CCA4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8012CCA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8012CCAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8012CCB0: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8012CCB4: nop

    // 0x8012CCB8: bc1fl       L_8012CD1C
    if (!c1cs) {
        // 0x8012CCBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_7;
    // 0x8012CCBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8012CCC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8012CCC4: b           L_8012CD18
    // 0x8012CCC8: swc1        $f10, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f10.u32l;
        goto L_8012CD18;
    // 0x8012CCC8: swc1        $f10, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f10.u32l;
L_8012CCCC:
    // 0x8012CCCC: lwc1        $f16, 0x44($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X44);
    // 0x8012CCD0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8012CCD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8012CCD8: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8012CCDC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8012CCE0: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8012CCE4: nop

    // 0x8012CCE8: bc1fl       L_8012CD1C
    if (!c1cs) {
        // 0x8012CCEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_8;
    // 0x8012CCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x8012CCF0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8012CCF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8012CCF8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8012CCFC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8012CD00: nop

    // 0x8012CD04: bc1fl       L_8012CD1C
    if (!c1cs) {
        // 0x8012CD08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012CD1C;
    }
    goto skip_9;
    // 0x8012CD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x8012CD0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8012CD10: nop

    // 0x8012CD14: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
L_8012CD18:
    // 0x8012CD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012CD1C:
    // 0x8012CD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012CD20: jr          $ra
    // 0x8012CD24: nop

    return;
    // 0x8012CD24: nop

;}
RECOMP_FUNC void M7_FUN_8012cd28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CD28: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012CD2C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8012CD30: beq         $t7, $zero, L_8012CE08
    if (ctx->r15 == 0) {
        // 0x8012CD34: nop
    
            goto L_8012CE08;
    }
    // 0x8012CD34: nop

    // 0x8012CD38: lbu         $t8, 0x3E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X3E);
    // 0x8012CD3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012CD40: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012CD44: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8012CD48: bgez        $t8, L_8012CD5C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8012CD4C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8012CD5C;
    }
    // 0x8012CD4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012CD50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012CD54: nop

    // 0x8012CD58: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8012CD5C:
    // 0x8012CD5C: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8012CD60: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012CD64: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8012CD68: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8012CD6C: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8012CD70: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x8012CD74: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8012CD78: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8012CD7C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CD80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8012CD84: sub.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d - ctx->f18.d;
    // 0x8012CD88: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8012CD8C: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x8012CD90: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8012CD94: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8012CD98: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8012CD9C: nop

    // 0x8012CDA0: bc1fl       L_8012CDB8
    if (!c1cs) {
        // 0x8012CDA4: lw          $t9, 0x30($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X30);
            goto L_8012CDB8;
    }
    goto skip_0;
    // 0x8012CDA4: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    skip_0:
    // 0x8012CDA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012CDAC: jr          $ra
    // 0x8012CDB0: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8012CDB0: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x8012CDB4: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
L_8012CDB8:
    // 0x8012CDB8: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8012CDBC: beq         $t0, $zero, L_8012CE08
    if (ctx->r8 == 0) {
        // 0x8012CDC0: nop
    
            goto L_8012CE08;
    }
    // 0x8012CDC0: nop

    // 0x8012CDC4: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8012CDC8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8012CDCC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8012CDD0: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8012CDD4: nop

    // 0x8012CDD8: bc1f        L_8012CE08
    if (!c1cs) {
        // 0x8012CDDC: nop
    
            goto L_8012CE08;
    }
    // 0x8012CDDC: nop

    // 0x8012CDE0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8012CDE4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8012CDE8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8012CDEC: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8012CDF0: nop

    // 0x8012CDF4: bc1f        L_8012CE08
    if (!c1cs) {
        // 0x8012CDF8: nop
    
            goto L_8012CE08;
    }
    // 0x8012CDF8: nop

    // 0x8012CDFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8012CE00: nop

    // 0x8012CE04: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
L_8012CE08:
    // 0x8012CE08: jr          $ra
    // 0x8012CE0C: nop

    return;
    // 0x8012CE0C: nop

;}
RECOMP_FUNC void M7_FUN_8012ce10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CE10: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012CE14: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8012CE18: beq         $t7, $zero, L_8012CE94
    if (ctx->r15 == 0) {
        // 0x8012CE1C: nop
    
            goto L_8012CE94;
    }
    // 0x8012CE1C: nop

    // 0x8012CE20: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8012CE24: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012CE28: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012CE2C: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8012CE30: lwc1        $f8, 0x438($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X438);
    // 0x8012CE34: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012CE38: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012CE3C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CE40: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8012CE44: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CE48: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8012CE4C: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x8012CE50: lwc1        $f6, 0x43C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X43C);
    // 0x8012CE54: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8012CE58: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8012CE5C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012CE60: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CE64: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8012CE68: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CE6C: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8012CE70: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x8012CE74: lwc1        $f8, 0x440($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X440);
    // 0x8012CE78: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x8012CE7C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012CE80: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012CE84: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8012CE88: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8012CE8C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012CE90: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
L_8012CE94:
    // 0x8012CE94: jr          $ra
    // 0x8012CE98: nop

    return;
    // 0x8012CE98: nop

;}
RECOMP_FUNC void M7_FUN_8012ce9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CE9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012CEA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012CEA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8012CEA8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8012CEAC: lhu         $t6, 0x78($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X78);
    // 0x8012CEB0: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x8012CEB4: beql        $t6, $zero, L_8012CF00
    if (ctx->r14 == 0) {
        // 0x8012CEB8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8012CF00;
    }
    goto skip_0;
    // 0x8012CEB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8012CEBC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8012CEC0: lhu         $t0, 0x36($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X36);
    // 0x8012CEC4: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8012CEC8: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x8012CECC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012CED0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8012CED4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8012CED8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012CEDC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8012CEE0: jal         0x80011140
    // 0x8012CEE4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x8012CEE4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8012CEE8: bne         $v0, $zero, L_8012CEF8
    if (ctx->r2 != 0) {
        // 0x8012CEEC: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8012CEF8;
    }
    // 0x8012CEEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8012CEF0: b           L_8012CF00
    // 0x8012CEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012CF00;
    // 0x8012CEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012CEF8:
    // 0x8012CEF8: sh          $zero, 0x78($a1)
    MEM_H(0X78, ctx->r5) = 0;
    // 0x8012CEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012CF00:
    // 0x8012CF00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012CF04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012CF08: jr          $ra
    // 0x8012CF0C: nop

    return;
    // 0x8012CF0C: nop

;}
RECOMP_FUNC void M7_FUN_8012cf10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CF10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012CF14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012CF18: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8012CF1C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8012CF20: lhu         $t6, 0x78($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X78);
    // 0x8012CF24: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x8012CF28: beql        $t6, $zero, L_8012CF7C
    if (ctx->r14 == 0) {
        // 0x8012CF2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8012CF7C;
    }
    goto skip_0;
    // 0x8012CF2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8012CF30: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8012CF34: lhu         $t0, 0x3E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3E);
    // 0x8012CF38: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8012CF3C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8012CF40: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x8012CF44: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012CF48: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8012CF4C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8012CF50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8012CF54: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8012CF58: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8012CF5C: jal         0x80010D08
    // 0x8012CF60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80010D08)(rdram, ctx);
        goto after_0;
    // 0x8012CF60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8012CF64: bne         $v0, $zero, L_8012CF74
    if (ctx->r2 != 0) {
        // 0x8012CF68: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8012CF74;
    }
    // 0x8012CF68: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8012CF6C: b           L_8012CF7C
    // 0x8012CF70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012CF7C;
    // 0x8012CF70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012CF74:
    // 0x8012CF74: sh          $zero, 0x78($a1)
    MEM_H(0X78, ctx->r5) = 0;
    // 0x8012CF78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012CF7C:
    // 0x8012CF7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8012CF80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012CF84: jr          $ra
    // 0x8012CF88: nop

    return;
    // 0x8012CF88: nop

;}
RECOMP_FUNC void M7_FUN_8012cf8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012CF8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012CF90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8012CF94: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8012CF98: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8012CF9C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8012CFA0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8012CFA4: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x8012CFA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012CFAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8012CFB0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8012CFB4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8012CFB8: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8012CFBC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8012CFC0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8012CFC4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8012CFC8: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8012CFCC: lui         $at, 0xD00
    ctx->r1 = S32(0XD00 << 16);
    // 0x8012CFD0: bne         $t2, $at, L_8012D018
    if (ctx->r10 != ctx->r1) {
        // 0x8012CFD4: sw          $t0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r8;
            goto L_8012D018;
    }
    // 0x8012CFD4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8012CFD8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8012CFDC: lhu         $a0, 0x2($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X2);
    // 0x8012CFE0: jal         0x80017064
    // 0x8012CFE4: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x8012CFE4: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012CFE8: jal         0x80005204
    // 0x8012CFEC: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x8012CFEC: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    after_1:
    // 0x8012CFF0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8012CFF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012CFF8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8012CFFC: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8012D000: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8012D004: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012D008: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012D00C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8012D010: b           L_8012D054
    // 0x8012D014: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_8012D054;
    // 0x8012D014: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_8012D018:
    // 0x8012D018: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8012D01C: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8012D020: jal         0x80017064
    // 0x8012D024: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_2;
    // 0x8012D024: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    after_2:
    // 0x8012D028: jal         0x80005204
    // 0x8012D02C: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_3;
    // 0x8012D02C: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    after_3:
    // 0x8012D030: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8012D034: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D038: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8012D03C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8012D040: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8012D044: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012D048: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012D04C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8012D050: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_8012D054:
    // 0x8012D054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012D058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012D05C: jr          $ra
    // 0x8012D060: nop

    return;
    // 0x8012D060: nop

;}
RECOMP_FUNC void M7_FUN_8012d064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D064: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8012D068: lbu         $t6, 0x47($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X47);
    // 0x8012D06C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8012D070: addiu       $t8, $t8, -0x2578
    ctx->r24 = ADD32(ctx->r24, -0X2578);
    // 0x8012D074: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8012D078: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8012D07C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8012D080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012D084: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8012D088: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8012D08C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8012D090: sb          $t3, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r11;
    // 0x8012D094: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x8012D098: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8012D09C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8012D0A0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8012D0A4: beql        $t5, $zero, L_8012D0EC
    if (ctx->r13 == 0) {
        // 0x8012D0A8: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_8012D0EC;
    }
    goto skip_0;
    // 0x8012D0A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8012D0AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8012D0B0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8012D0B4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8012D0B8: sh          $t6, 0x38($t8)
    MEM_H(0X38, ctx->r24) = ctx->r14;
    // 0x8012D0BC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8012D0C0: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8012D0C4: addiu       $t4, $v0, 0x40
    ctx->r12 = ADD32(ctx->r2, 0X40);
    // 0x8012D0C8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8012D0CC: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    // 0x8012D0D0: addiu       $a2, $v0, 0x3B
    ctx->r6 = ADD32(ctx->r2, 0X3B);
    // 0x8012D0D4: addiu       $t2, $v0, 0x3A
    ctx->r10 = ADD32(ctx->r2, 0X3A);
    // 0x8012D0D8: addiu       $t0, $v0, 0x38
    ctx->r8 = ADD32(ctx->r2, 0X38);
    // 0x8012D0DC: addiu       $a0, $v0, 0x3E
    ctx->r4 = ADD32(ctx->r2, 0X3E);
    // 0x8012D0E0: b           L_8012D120
    // 0x8012D0E4: addiu       $a3, $v0, 0x3D
    ctx->r7 = ADD32(ctx->r2, 0X3D);
        goto L_8012D120;
    // 0x8012D0E4: addiu       $a3, $v0, 0x3D
    ctx->r7 = ADD32(ctx->r2, 0X3D);
    // 0x8012D0E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_8012D0EC:
    // 0x8012D0EC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8012D0F0: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x8012D0F4: sh          $t5, 0x38($t6)
    MEM_H(0X38, ctx->r14) = ctx->r13;
    // 0x8012D0F8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8012D0FC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8012D100: addiu       $t9, $v0, 0x40
    ctx->r25 = ADD32(ctx->r2, 0X40);
    // 0x8012D104: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8012D108: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    // 0x8012D10C: addiu       $a2, $v0, 0x3B
    ctx->r6 = ADD32(ctx->r2, 0X3B);
    // 0x8012D110: addiu       $t2, $v0, 0x3A
    ctx->r10 = ADD32(ctx->r2, 0X3A);
    // 0x8012D114: addiu       $t0, $v0, 0x38
    ctx->r8 = ADD32(ctx->r2, 0X38);
    // 0x8012D118: addiu       $a0, $v0, 0x3E
    ctx->r4 = ADD32(ctx->r2, 0X3E);
    // 0x8012D11C: addiu       $a3, $v0, 0x3D
    ctx->r7 = ADD32(ctx->r2, 0X3D);
L_8012D120:
    // 0x8012D120: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8012D124: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012D128: bnel        $t4, $at, L_8012D144
    if (ctx->r12 != ctx->r1) {
        // 0x8012D12C: lhu         $t6, 0x0($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X0);
            goto L_8012D144;
    }
    goto skip_1;
    // 0x8012D12C: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    skip_1:
    // 0x8012D130: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x8012D134: ori         $t5, $t7, 0x1
    ctx->r13 = ctx->r15 | 0X1;
    // 0x8012D138: b           L_8012D14C
    // 0x8012D13C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
        goto L_8012D14C;
    // 0x8012D13C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x8012D140: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
L_8012D144:
    // 0x8012D144: andi        $t8, $t6, 0xFFFE
    ctx->r24 = ctx->r14 & 0XFFFE;
    // 0x8012D148: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
L_8012D14C:
    // 0x8012D14C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8012D150: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8012D154: bnel        $t9, $at, L_8012D16C
    if (ctx->r25 != ctx->r1) {
        // 0x8012D158: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_8012D16C;
    }
    goto skip_2;
    // 0x8012D158: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    skip_2:
    // 0x8012D15C: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x8012D160: ori         $t7, $t4, 0x4
    ctx->r15 = ctx->r12 | 0X4;
    // 0x8012D164: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8012D168: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
L_8012D16C:
    // 0x8012D16C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8012D170: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8012D174: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8012D178: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8012D17C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8012D180: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8012D184: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8012D188: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8012D18C: addiu       $t1, $t1, 0x1CF0
    ctx->r9 = ADD32(ctx->r9, 0X1CF0);
    // 0x8012D190: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8012D194: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8012D198: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8012D19C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8012D1A0: nop

    // 0x8012D1A4: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x8012D1A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8012D1AC: nop

    // 0x8012D1B0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8012D1B4: beql        $t6, $zero, L_8012D208
    if (ctx->r14 == 0) {
        // 0x8012D1B8: mfc1        $t6, $f16
        ctx->r14 = (int32_t)ctx->f16.u32l;
            goto L_8012D208;
    }
    goto skip_3;
    // 0x8012D1B8: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x8012D1BC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012D1C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012D1C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8012D1C8: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x8012D1CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8012D1D0: nop

    // 0x8012D1D4: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8012D1D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8012D1DC: nop

    // 0x8012D1E0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8012D1E4: bne         $t6, $zero, L_8012D1FC
    if (ctx->r14 != 0) {
        // 0x8012D1E8: nop
    
            goto L_8012D1FC;
    }
    // 0x8012D1E8: nop

    // 0x8012D1EC: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x8012D1F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D1F4: b           L_8012D214
    // 0x8012D1F8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8012D214;
    // 0x8012D1F8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8012D1FC:
    // 0x8012D1FC: b           L_8012D214
    // 0x8012D200: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8012D214;
    // 0x8012D200: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8012D204: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
L_8012D208:
    // 0x8012D208: nop

    // 0x8012D20C: bltz        $t6, L_8012D1FC
    if (SIGNED(ctx->r14) < 0) {
        // 0x8012D210: nop
    
            goto L_8012D1FC;
    }
    // 0x8012D210: nop

L_8012D214:
    // 0x8012D214: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x8012D218: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8012D21C: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x8012D220: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8012D224: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8012D228: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8012D22C: addu        $t4, $t1, $t9
    ctx->r12 = ADD32(ctx->r9, ctx->r25);
    // 0x8012D230: lw          $t7, -0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, -0X4);
    // 0x8012D234: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8012D238: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012D23C: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x8012D240: andi        $t7, $zero, 0xFF
    ctx->r15 = 0 & 0XFF;
    // 0x8012D244: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x8012D248: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8012D24C: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8012D250: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x8012D254: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8012D258: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8012D25C: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x8012D260: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    // 0x8012D264: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8012D268: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8012D26C: bgez        $t8, L_8012D280
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8012D270: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8012D280;
    }
    // 0x8012D270: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012D274: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8012D278: nop

    // 0x8012D27C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8012D280:
    // 0x8012D280: bgez        $v1, L_8012D298
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8012D284: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8012D298;
    }
    // 0x8012D284: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012D288: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012D28C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012D290: nop

    // 0x8012D294: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8012D298:
    // 0x8012D298: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8012D29C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8012D2A0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8012D2A4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8012D2A8: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8012D2AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8012D2B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8012D2B4: nop

    // 0x8012D2B8: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x8012D2BC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8012D2C0: nop

    // 0x8012D2C4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8012D2C8: beql        $t7, $zero, L_8012D31C
    if (ctx->r15 == 0) {
        // 0x8012D2CC: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_8012D31C;
    }
    goto skip_4;
    // 0x8012D2CC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_4:
    // 0x8012D2D0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012D2D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012D2D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8012D2DC: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x8012D2E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8012D2E4: nop

    // 0x8012D2E8: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8012D2EC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8012D2F0: nop

    // 0x8012D2F4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8012D2F8: bne         $t7, $zero, L_8012D310
    if (ctx->r15 != 0) {
        // 0x8012D2FC: nop
    
            goto L_8012D310;
    }
    // 0x8012D2FC: nop

    // 0x8012D300: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8012D304: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D308: b           L_8012D328
    // 0x8012D30C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8012D328;
    // 0x8012D30C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8012D310:
    // 0x8012D310: b           L_8012D328
    // 0x8012D314: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8012D328;
    // 0x8012D314: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8012D318: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_8012D31C:
    // 0x8012D31C: nop

    // 0x8012D320: bltz        $t7, L_8012D310
    if (SIGNED(ctx->r15) < 0) {
        // 0x8012D324: nop
    
            goto L_8012D310;
    }
    // 0x8012D324: nop

L_8012D328:
    // 0x8012D328: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8012D32C: andi        $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 & 0XFF;
    // 0x8012D330: bne         $t4, $zero, L_8012D33C
    if (ctx->r12 != 0) {
        // 0x8012D334: sb          $t7, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r15;
            goto L_8012D33C;
    }
    // 0x8012D334: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8012D338: sb          $t3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r11;
L_8012D33C:
    // 0x8012D33C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8012D340: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8012D344: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x8012D348: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8012D34C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8012D350: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8012D354: lui         $at, 0xD00
    ctx->r1 = S32(0XD00 << 16);
    // 0x8012D358: bnel        $t9, $at, L_8012D3B4
    if (ctx->r25 != ctx->r1) {
        // 0x8012D35C: lhu         $t8, 0x0($t0)
        ctx->r24 = MEM_HU(ctx->r8, 0X0);
            goto L_8012D3B4;
    }
    goto skip_5;
    // 0x8012D35C: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    skip_5:
    // 0x8012D360: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x8012D364: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8012D368: addu        $t6, $t1, $t4
    ctx->r14 = ADD32(ctx->r9, ctx->r12);
    // 0x8012D36C: lw          $t5, -0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, -0X4);
    // 0x8012D370: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8012D374: lhu         $a0, 0x2($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X2);
    // 0x8012D378: jal         0x80017064
    // 0x8012D37C: sh          $a0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x8012D37C: sh          $a0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012D380: jal         0x80005204
    // 0x8012D384: lhu         $a0, 0x28($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x8012D384: lhu         $a0, 0x28($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X28);
    after_1:
    // 0x8012D388: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8012D38C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D390: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8012D394: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x8012D398: addu        $t4, $t7, $at
    ctx->r12 = ADD32(ctx->r15, ctx->r1);
    // 0x8012D39C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012D3A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012D3A4: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8012D3A8: b           L_8012D3FC
    // 0x8012D3AC: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_8012D3FC;
    // 0x8012D3AC: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8012D3B0: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
L_8012D3B4:
    // 0x8012D3B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8012D3B8: addu        $t7, $t1, $t9
    ctx->r15 = ADD32(ctx->r9, ctx->r25);
    // 0x8012D3BC: lw          $t4, -0x4($t7)
    ctx->r12 = MEM_W(ctx->r15, -0X4);
    // 0x8012D3C0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8012D3C4: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x8012D3C8: jal         0x80017064
    // 0x8012D3CC: sh          $a0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_2;
    // 0x8012D3CC: sh          $a0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x8012D3D0: jal         0x80005204
    // 0x8012D3D4: lhu         $a0, 0x28($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_3;
    // 0x8012D3D4: lhu         $a0, 0x28($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X28);
    after_3:
    // 0x8012D3D8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8012D3DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D3E0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8012D3E4: addu        $t8, $v0, $t5
    ctx->r24 = ADD32(ctx->r2, ctx->r13);
    // 0x8012D3E8: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x8012D3EC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012D3F0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012D3F4: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8012D3F8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_8012D3FC:
    // 0x8012D3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012D400: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8012D404: jr          $ra
    // 0x8012D408: nop

    return;
    // 0x8012D408: nop

;}
RECOMP_FUNC void M7_FUN_8012d40c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D40C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8012D410: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8012D414: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8012D418: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8012D41C: addiu       $t7, $t7, -0x2578
    ctx->r15 = ADD32(ctx->r15, -0X2578);
    // 0x8012D420: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8012D424: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x8012D428: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8012D42C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012D430: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8012D434: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8012D438: beql        $v0, $zero, L_8012D470
    if (ctx->r2 == 0) {
        // 0x8012D43C: lw          $v0, 0x30($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X30);
            goto L_8012D470;
    }
    goto skip_0;
    // 0x8012D43C: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    skip_0:
    // 0x8012D440: lbu         $t8, 0x3A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3A);
    // 0x8012D444: addiu       $a3, $v0, 0x3A
    ctx->r7 = ADD32(ctx->r2, 0X3A);
    // 0x8012D448: addiu       $a1, $v0, 0x3B
    ctx->r5 = ADD32(ctx->r2, 0X3B);
    // 0x8012D44C: beq         $t8, $zero, L_8012D798
    if (ctx->r24 == 0) {
        // 0x8012D450: addiu       $v1, $v0, 0x3C
        ctx->r3 = ADD32(ctx->r2, 0X3C);
            goto L_8012D798;
    }
    // 0x8012D450: addiu       $v1, $v0, 0x3C
    ctx->r3 = ADD32(ctx->r2, 0X3C);
    // 0x8012D454: addiu       $t9, $v0, 0x40
    ctx->r25 = ADD32(ctx->r2, 0X40);
    // 0x8012D458: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8012D45C: addiu       $t0, $v0, 0x38
    ctx->r8 = ADD32(ctx->r2, 0X38);
    // 0x8012D460: addiu       $a0, $v0, 0x3E
    ctx->r4 = ADD32(ctx->r2, 0X3E);
    // 0x8012D464: b           L_8012D498
    // 0x8012D468: addiu       $t2, $v0, 0x3D
    ctx->r10 = ADD32(ctx->r2, 0X3D);
        goto L_8012D498;
    // 0x8012D468: addiu       $t2, $v0, 0x3D
    ctx->r10 = ADD32(ctx->r2, 0X3D);
    // 0x8012D46C: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
L_8012D470:
    // 0x8012D470: lbu         $t4, 0x3A($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3A);
    // 0x8012D474: addiu       $a3, $v0, 0x3A
    ctx->r7 = ADD32(ctx->r2, 0X3A);
    // 0x8012D478: addiu       $a1, $v0, 0x3B
    ctx->r5 = ADD32(ctx->r2, 0X3B);
    // 0x8012D47C: beq         $t4, $zero, L_8012D798
    if (ctx->r12 == 0) {
        // 0x8012D480: addiu       $v1, $v0, 0x3C
        ctx->r3 = ADD32(ctx->r2, 0X3C);
            goto L_8012D798;
    }
    // 0x8012D480: addiu       $v1, $v0, 0x3C
    ctx->r3 = ADD32(ctx->r2, 0X3C);
    // 0x8012D484: addiu       $t5, $v0, 0x40
    ctx->r13 = ADD32(ctx->r2, 0X40);
    // 0x8012D488: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8012D48C: addiu       $t0, $v0, 0x38
    ctx->r8 = ADD32(ctx->r2, 0X38);
    // 0x8012D490: addiu       $a0, $v0, 0x3E
    ctx->r4 = ADD32(ctx->r2, 0X3E);
    // 0x8012D494: addiu       $t2, $v0, 0x3D
    ctx->r10 = ADD32(ctx->r2, 0X3D);
L_8012D498:
    // 0x8012D498: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8012D49C: beql        $t6, $zero, L_8012D79C
    if (ctx->r14 == 0) {
        // 0x8012D4A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012D79C;
    }
    goto skip_1;
    // 0x8012D4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8012D4A4: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8012D4A8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8012D4AC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8012D4B0: bne         $t9, $zero, L_8012D798
    if (ctx->r25 != 0) {
        // 0x8012D4B4: sb          $t8, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r24;
            goto L_8012D798;
    }
    // 0x8012D4B4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8012D4B8: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x8012D4BC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8012D4C0: addiu       $t3, $t3, 0x1CF0
    ctx->r11 = ADD32(ctx->r11, 0X1CF0);
    // 0x8012D4C4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8012D4C8: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    // 0x8012D4CC: lhu         $a2, 0x0($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X0);
    // 0x8012D4D0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8012D4D4: sltiu       $at, $a2, 0x1001
    ctx->r1 = ctx->r6 < 0X1001 ? 1 : 0;
    // 0x8012D4D8: bne         $at, $zero, L_8012D524
    if (ctx->r1 != 0) {
        // 0x8012D4DC: sll         $t5, $a2, 2
        ctx->r13 = S32(ctx->r6 << 2);
            goto L_8012D524;
    }
    // 0x8012D4DC: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8012D4E0: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x8012D4E4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8012D4E8: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x8012D4EC: beql        $v0, $zero, L_8012D50C
    if (ctx->r2 == 0) {
        // 0x8012D4F0: lw          $t7, 0x0($t1)
        ctx->r15 = MEM_W(ctx->r9, 0X0);
            goto L_8012D50C;
    }
    goto skip_2;
    // 0x8012D4F0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    skip_2:
    // 0x8012D4F4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8012D4F8:
    // 0x8012D4F8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8012D4FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8012D500: bnel        $v0, $zero, L_8012D4F8
    if (ctx->r2 != 0) {
        // 0x8012D504: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8012D4F8;
    }
    goto skip_3;
    // 0x8012D504: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    skip_3:
    // 0x8012D508: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
L_8012D50C:
    // 0x8012D50C: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
    // 0x8012D510: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8012D514: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8012D518: ori         $t4, $t9, 0x20
    ctx->r12 = ctx->r25 | 0X20;
    // 0x8012D51C: b           L_8012D798
    // 0x8012D520: sw          $t4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r12;
        goto L_8012D798;
    // 0x8012D520: sw          $t4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r12;
L_8012D524:
    // 0x8012D524: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8012D528: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x8012D52C: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x8012D530: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8012D534: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8012D538: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8012D53C: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8012D540: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x8012D544: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x8012D548: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x8012D54C: lbu         $v0, 0x4($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X4);
    // 0x8012D550: bne         $v0, $zero, L_8012D59C
    if (ctx->r2 != 0) {
        // 0x8012D554: nop
    
            goto L_8012D59C;
    }
    // 0x8012D554: nop

    // 0x8012D558: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x8012D55C: andi        $t5, $t8, 0x1
    ctx->r13 = ctx->r24 & 0X1;
    // 0x8012D560: bne         $t5, $zero, L_8012D59C
    if (ctx->r13 != 0) {
        // 0x8012D564: nop
    
            goto L_8012D59C;
    }
    // 0x8012D564: nop

    // 0x8012D568: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x8012D56C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8012D570: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x8012D574: ori         $t4, $t6, 0x20
    ctx->r12 = ctx->r14 | 0X20;
    // 0x8012D578: sw          $t4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r12;
    // 0x8012D57C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x8012D580: ori         $t5, $t9, 0x2
    ctx->r13 = ctx->r25 | 0X2;
    // 0x8012D584: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8012D588: beq         $t6, $zero, L_8012D798
    if (ctx->r14 == 0) {
        // 0x8012D58C: sh          $t5, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r13;
            goto L_8012D798;
    }
    // 0x8012D58C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x8012D590: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8012D594: b           L_8012D798
    // 0x8012D598: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
        goto L_8012D798;
    // 0x8012D598: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
L_8012D59C:
    // 0x8012D59C: beq         $v0, $zero, L_8012D5AC
    if (ctx->r2 == 0) {
        // 0x8012D5A0: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8012D5AC;
    }
    // 0x8012D5A0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8012D5A4: bnel        $v0, $at, L_8012D5E8
    if (ctx->r2 != ctx->r1) {
        // 0x8012D5A8: lbu         $t7, 0x0($t2)
        ctx->r15 = MEM_BU(ctx->r10, 0X0);
            goto L_8012D5E8;
    }
    goto skip_4;
    // 0x8012D5A8: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    skip_4:
L_8012D5AC:
    // 0x8012D5AC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8012D5B0: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x8012D5B4: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x8012D5B8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8012D5BC: addu        $t8, $t3, $t9
    ctx->r24 = ADD32(ctx->r11, ctx->r25);
    // 0x8012D5C0: lw          $t5, -0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, -0X4);
    // 0x8012D5C4: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8012D5C8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012D5CC: andi        $t5, $zero, 0xFF
    ctx->r13 = 0 & 0XFF;
    // 0x8012D5D0: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x8012D5D4: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8012D5D8: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x8012D5DC: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x8012D5E0: lbu         $v0, 0x4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4);
    // 0x8012D5E4: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
L_8012D5E8:
    // 0x8012D5E8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8012D5EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012D5F0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8012D5F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8012D5F8: bgez        $t7, L_8012D60C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8012D5FC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8012D60C;
    }
    // 0x8012D5FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012D600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012D604: nop

    // 0x8012D608: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8012D60C:
    // 0x8012D60C: bgez        $v0, L_8012D624
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8012D610: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8012D624;
    }
    // 0x8012D610: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012D614: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012D618: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8012D61C: nop

    // 0x8012D620: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8012D624:
    // 0x8012D624: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8012D628: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8012D62C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8012D630: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8012D634: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8012D638: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8012D63C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012D640: div.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8012D644: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8012D648: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8012D64C: nop

    // 0x8012D650: cvt.w.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_D(ctx->f18.d);
    // 0x8012D654: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8012D658: nop

    // 0x8012D65C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8012D660: beql        $t5, $zero, L_8012D6B4
    if (ctx->r13 == 0) {
        // 0x8012D664: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_8012D6B4;
    }
    goto skip_5;
    // 0x8012D664: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_5:
    // 0x8012D668: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8012D66C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8012D670: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8012D674: sub.d       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f18.d - ctx->f6.d;
    // 0x8012D678: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8012D67C: nop

    // 0x8012D680: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8012D684: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8012D688: nop

    // 0x8012D68C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8012D690: bne         $t5, $zero, L_8012D6A8
    if (ctx->r13 != 0) {
        // 0x8012D694: nop
    
            goto L_8012D6A8;
    }
    // 0x8012D694: nop

    // 0x8012D698: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8012D69C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D6A0: b           L_8012D6C0
    // 0x8012D6A4: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8012D6C0;
    // 0x8012D6A4: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8012D6A8:
    // 0x8012D6A8: b           L_8012D6C0
    // 0x8012D6AC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8012D6C0;
    // 0x8012D6AC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8012D6B0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_8012D6B4:
    // 0x8012D6B4: nop

    // 0x8012D6B8: bltz        $t5, L_8012D6A8
    if (SIGNED(ctx->r13) < 0) {
        // 0x8012D6BC: nop
    
            goto L_8012D6A8;
    }
    // 0x8012D6BC: nop

L_8012D6C0:
    // 0x8012D6C0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8012D6C4: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x8012D6C8: bne         $t8, $zero, L_8012D6D4
    if (ctx->r24 != 0) {
        // 0x8012D6CC: sb          $t5, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r13;
            goto L_8012D6D4;
    }
    // 0x8012D6CC: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8012D6D0: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_8012D6D4:
    // 0x8012D6D4: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x8012D6D8: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x8012D6DC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8012D6E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8012D6E4: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x8012D6E8: lw          $v0, -0x4($t9)
    ctx->r2 = MEM_W(ctx->r25, -0X4);
    // 0x8012D6EC: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8012D6F0: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8012D6F4: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8012D6F8: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x8012D6FC: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x8012D700: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x8012D704: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x8012D708: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8012D70C: and         $t9, $t4, $at
    ctx->r25 = ctx->r12 & ctx->r1;
    // 0x8012D710: lui         $at, 0xD00
    ctx->r1 = S32(0XD00 << 16);
    // 0x8012D714: bne         $t9, $at, L_8012D75C
    if (ctx->r25 != ctx->r1) {
        // 0x8012D718: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_8012D75C;
    }
    // 0x8012D718: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8012D71C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8012D720: lhu         $a0, 0x2($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X2);
    // 0x8012D724: jal         0x80017064
    // 0x8012D728: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x8012D728: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012D72C: jal         0x80005204
    // 0x8012D730: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x8012D730: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    after_1:
    // 0x8012D734: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8012D738: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D73C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8012D740: addu        $t5, $v0, $t8
    ctx->r13 = ADD32(ctx->r2, ctx->r24);
    // 0x8012D744: addu        $t4, $t5, $at
    ctx->r12 = ADD32(ctx->r13, ctx->r1);
    // 0x8012D748: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012D74C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012D750: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8012D754: b           L_8012D798
    // 0x8012D758: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
        goto L_8012D798;
    // 0x8012D758: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
L_8012D75C:
    // 0x8012D75C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8012D760: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x8012D764: jal         0x80017064
    // 0x8012D768: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_2;
    // 0x8012D768: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    after_2:
    // 0x8012D76C: jal         0x80005204
    // 0x8012D770: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_3;
    // 0x8012D770: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    after_3:
    // 0x8012D774: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8012D778: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012D77C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8012D780: addu        $t5, $v0, $t8
    ctx->r13 = ADD32(ctx->r2, ctx->r24);
    // 0x8012D784: addu        $t4, $t5, $at
    ctx->r12 = ADD32(ctx->r13, ctx->r1);
    // 0x8012D788: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012D78C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012D790: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8012D794: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
L_8012D798:
    // 0x8012D798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012D79C:
    // 0x8012D79C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8012D7A0: jr          $ra
    // 0x8012D7A4: nop

    return;
    // 0x8012D7A4: nop

;}
RECOMP_FUNC void M7_FUN_8012d7a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D7A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012D7AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012D7B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8012D7B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8012D7B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8012D7BC: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012D7C0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8012D7C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8012D7C8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8012D7CC: beql        $t7, $zero, L_8012D800
    if (ctx->r15 == 0) {
        // 0x8012D7D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8012D800;
    }
    goto skip_0;
    // 0x8012D7D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8012D7D4: lw          $s0, 0x24($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X24);
    // 0x8012D7D8: beq         $s0, $zero, L_8012D7FC
    if (ctx->r16 == 0) {
        // 0x8012D7DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8012D7FC;
    }
    // 0x8012D7DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8012D7E0:
    // 0x8012D7E0: jal         0x8012D40C
    // 0x8012D7E4: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8012D40C)(rdram, ctx);
        goto after_0;
    // 0x8012D7E4: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_0:
    // 0x8012D7E8: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x8012D7EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8012D7F0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8012D7F4: bnel        $s0, $zero, L_8012D7E0
    if (ctx->r16 != 0) {
        // 0x8012D7F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8012D7E0;
    }
    goto skip_1;
    // 0x8012D7F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_8012D7FC:
    // 0x8012D7FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8012D800:
    // 0x8012D800: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8012D804: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8012D808: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8012D80C: jr          $ra
    // 0x8012D810: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8012D810: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012d814(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012d814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D814: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012d818(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012d818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012D81C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8012D820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012D824: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8012D828: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8012D82C: jal         0x8012D8C8
    // 0x8012D830: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_0;
    // 0x8012D830: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8012D834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012D838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012D83C: jr          $ra
    // 0x8012D840: nop

    return;
    // 0x8012D840: nop

;}
RECOMP_FUNC void M7_FUN_8012d844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012D848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012D84C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012D850: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8012D854: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8012D858: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8012D85C: beq         $v1, $zero, L_8012D874
    if (ctx->r3 == 0) {
        // 0x8012D860: addiu       $a1, $v1, 0x40
        ctx->r5 = ADD32(ctx->r3, 0X40);
            goto L_8012D874;
    }
    // 0x8012D860: addiu       $a1, $v1, 0x40
    ctx->r5 = ADD32(ctx->r3, 0X40);
    // 0x8012D864: jal         0x8012CF8C
    // 0x8012D868: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x8012D868: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    after_0:
    // 0x8012D86C: b           L_8012D888
    // 0x8012D870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8012D888;
    // 0x8012D870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012D874:
    // 0x8012D874: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    // 0x8012D878: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    // 0x8012D87C: jal         0x8012CF8C
    // 0x8012D880: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_1;
    // 0x8012D880: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_1:
    // 0x8012D884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012D888:
    // 0x8012D888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012D88C: jr          $ra
    // 0x8012D890: nop

    return;
    // 0x8012D890: nop

;}
RECOMP_FUNC void M7_FUN_8012d894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D894: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012D898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012D89C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012D8A0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012D8A4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8012D8A8: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    // 0x8012D8AC: lw          $a1, 0x2C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X2C);
    // 0x8012D8B0: jal         0x8012CF8C
    // 0x8012D8B4: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x8012D8B4: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_0:
    // 0x8012D8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012D8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012D8C0: jr          $ra
    // 0x8012D8C4: nop

    return;
    // 0x8012D8C4: nop

;}
RECOMP_FUNC void M7_FUN_8012d8c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D8C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012D8CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012D8D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012D8D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8012D8D8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012D8DC: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8012D8E0: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8012D8E4: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8012D8E8: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x8012D8EC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8012D8F0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8012D8F4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8012D8F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8012D8FC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8012D900: jal         0x8012D064
    // 0x8012D904: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012D064)(rdram, ctx);
        goto after_0;
    // 0x8012D904: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8012D908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012D90C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012D910: jr          $ra
    // 0x8012D914: nop

    return;
    // 0x8012D914: nop

;}
RECOMP_FUNC void M7_FUN_8012d918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012D918: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012D91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012D920: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8012D924: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8012D928: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012D92C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8012D930: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8012D934: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8012D938: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x8012D93C: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x8012D940: beq         $t7, $zero, L_8012D984
    if (ctx->r15 == 0) {
        // 0x8012D944: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8012D984;
    }
    // 0x8012D944: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8012D948: bne         $t8, $zero, L_8012D96C
    if (ctx->r24 != 0) {
        // 0x8012D94C: sll         $t1, $a3, 2
        ctx->r9 = S32(ctx->r7 << 2);
            goto L_8012D96C;
    }
    // 0x8012D94C: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8012D950: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8012D954: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8012D958: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8012D95C: lw          $t0, -0x2578($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2578);
    // 0x8012D960: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x8012D964: b           L_8012D9BC
    // 0x8012D968: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
        goto L_8012D9BC;
    // 0x8012D968: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_8012D96C:
    // 0x8012D96C: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8012D970: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8012D974: lw          $t2, -0x2578($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2578);
    // 0x8012D978: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8012D97C: b           L_8012D9BC
    // 0x8012D980: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
        goto L_8012D9BC;
    // 0x8012D980: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
L_8012D984:
    // 0x8012D984: bne         $t3, $zero, L_8012D9A8
    if (ctx->r11 != 0) {
        // 0x8012D988: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_8012D9A8;
    }
    // 0x8012D988: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8012D98C: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x8012D990: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8012D994: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8012D998: lw          $t5, -0x2578($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2578);
    // 0x8012D99C: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x8012D9A0: b           L_8012D9BC
    // 0x8012D9A4: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
        goto L_8012D9BC;
    // 0x8012D9A4: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_8012D9A8:
    // 0x8012D9A8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8012D9AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8012D9B0: lw          $t7, -0x2578($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2578);
    // 0x8012D9B4: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x8012D9B8: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
L_8012D9BC:
    // 0x8012D9BC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8012D9C0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8012D9C4: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x8012D9C8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8012D9CC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8012D9D0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8012D9D4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8012D9D8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8012D9DC: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8012D9E0: lui         $at, 0xD00
    ctx->r1 = S32(0XD00 << 16);
    // 0x8012D9E4: bne         $t4, $at, L_8012DA38
    if (ctx->r12 != ctx->r1) {
        // 0x8012D9E8: sw          $t2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r10;
            goto L_8012DA38;
    }
    // 0x8012D9E8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8012D9EC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8012D9F0: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x8012D9F4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8012D9F8: jal         0x80017064
    // 0x8012D9FC: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x8012D9FC: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012DA00: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8012DA04: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x8012DA08: jal         0x80005204
    // 0x8012DA0C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x8012DA0C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8012DA10: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8012DA14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012DA18: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8012DA1C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8012DA20: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8012DA24: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012DA28: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012DA2C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8012DA30: b           L_8012DA80
    // 0x8012DA34: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8012DA80;
    // 0x8012DA34: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8012DA38:
    // 0x8012DA38: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8012DA3C: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x8012DA40: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8012DA44: jal         0x80017064
    // 0x8012DA48: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_2;
    // 0x8012DA48: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    after_2:
    // 0x8012DA4C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8012DA50: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x8012DA54: jal         0x80005204
    // 0x8012DA58: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_3;
    // 0x8012DA58: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x8012DA5C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8012DA60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012DA64: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8012DA68: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8012DA6C: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8012DA70: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8012DA74: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8012DA78: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8012DA7C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_8012DA80:
    // 0x8012DA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012DA84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012DA88: jr          $ra
    // 0x8012DA8C: nop

    return;
    // 0x8012DA8C: nop

;}
RECOMP_FUNC void M7_FUN_8012da90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012DA90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012DA94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012DA98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8012DA9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8012DAA0: lbu         $t6, 0x3F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3F);
    // 0x8012DAA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8012DAA8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8012DAAC: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x8012DAB0: beq         $at, $zero, L_8012DE40
    if (ctx->r1 == 0) {
        // 0x8012DAB4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8012DE40;
    }
    // 0x8012DAB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8012DAB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DABC: addu        $at, $at, $t7
    gpr jr_addend_8012DAC4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8012DAC0: lw          $t7, -0x2AC8($at)
    ctx->r15 = ADD32(ctx->r1, -0X2AC8);
    // 0x8012DAC4: jr          $t7
    // 0x8012DAC8: nop

    switch (jr_addend_8012DAC4 >> 2) {
        case 0: goto L_8012DACC; break;
        case 1: goto L_8012DB1C; break;
        case 2: goto L_8012DB38; break;
        case 3: goto L_8012DB54; break;
        case 4: goto L_8012DBC4; break;
        case 5: goto L_8012DC20; break;
        case 6: goto L_8012DC64; break;
        case 7: goto L_8012DC88; break;
        case 8: goto L_8012DCE4; break;
        case 9: goto L_8012DD6C; break;
        case 10: goto L_8012DDD4; break;
        default: switch_error(__func__, 0x8012DAC4, 0x8018D538);
    }
    // 0x8012DAC8: nop

L_8012DACC:
    // 0x8012DACC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DAD0: lwc1        $f4, -0x2A9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A9C);
    // 0x8012DAD4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DAD8: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DADC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x8012DAE0: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DAE4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012DAE8: jal         0x8001EAD0
    // 0x8012DAEC: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8012DAEC: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_0:
    // 0x8012DAF0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DAF4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8012DAF8: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x8012DAFC: lw          $t0, 0xE0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DB00: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8012DB04: jal         0x8001EB64
    // 0x8012DB08: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8012DB08: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_1:
    // 0x8012DB0C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DB10: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8012DB14: b           L_8012DE40
    // 0x8012DB18: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_8012DE40;
    // 0x8012DB18: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_8012DB1C:
    // 0x8012DB1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8012DB20: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DB24: lwc1        $f18, -0x2A98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2A98);
    // 0x8012DB28: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8012DB2C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8012DB30: b           L_8012DE40
    // 0x8012DB34: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
        goto L_8012DE40;
    // 0x8012DB34: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
L_8012DB38:
    // 0x8012DB38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8012DB3C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8012DB40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8012DB44: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8012DB48: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8012DB4C: b           L_8012DE40
    // 0x8012DB50: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
        goto L_8012DE40;
    // 0x8012DB50: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
L_8012DB54:
    // 0x8012DB54: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8012DB58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8012DB5C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DB60: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DB64: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x8012DB68: lw          $t2, 0xE0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DB6C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8012DB70: jal         0x8001EAD0
    // 0x8012DB74: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x8012DB74: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_2:
    // 0x8012DB78: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x8012DB7C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8012DB80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8012DB84: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DB88: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8012DB8C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012DB90: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8012DB94: lw          $t4, 0xE0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DB98: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8012DB9C: jal         0x8001EB64
    // 0x8012DBA0: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8012DBA0: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_3:
    // 0x8012DBA4: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x8012DBA8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8012DBAC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8012DBB0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DBB4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8012DBB8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8012DBBC: b           L_8012DE40
    // 0x8012DBC0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
        goto L_8012DE40;
    // 0x8012DBC0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_8012DBC4:
    // 0x8012DBC4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DBC8: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DBCC: lw          $t6, 0xE0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DBD0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8012DBD4: jal         0x8001EAD0
    // 0x8012DBD8: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8012DBD8: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_4:
    // 0x8012DBDC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DBE0: ldc1        $f18, -0x2A90($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2A90);
    // 0x8012DBE4: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DBE8: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8012DBEC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8012DBF0: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8012DBF4: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DBF8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012DBFC: jal         0x8001EB64
    // 0x8012DC00: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x8012DC00: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_5:
    // 0x8012DC04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DC08: ldc1        $f10, -0x2A88($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2A88);
    // 0x8012DC0C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DC10: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8012DC14: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012DC18: b           L_8012DE40
    // 0x8012DC1C: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
        goto L_8012DE40;
    // 0x8012DC1C: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
L_8012DC20:
    // 0x8012DC20: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DC24: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DC28: lw          $t0, 0xE0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DC2C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8012DC30: jal         0x8001EAD0
    // 0x8012DC34: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x8012DC34: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_6:
    // 0x8012DC38: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DC3C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8012DC40: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8012DC44: lw          $t2, 0xE0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DC48: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8012DC4C: jal         0x8001EB64
    // 0x8012DC50: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x8012DC50: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_7:
    // 0x8012DC54: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DC58: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8012DC5C: b           L_8012DE40
    // 0x8012DC60: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
        goto L_8012DE40;
    // 0x8012DC60: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_8012DC64:
    // 0x8012DC64: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8012DC68: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8012DC6C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8012DC70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8012DC74: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8012DC78: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x8012DC7C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8012DC80: b           L_8012DE40
    // 0x8012DC84: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
        goto L_8012DE40;
    // 0x8012DC84: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
L_8012DC88:
    // 0x8012DC88: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DC8C: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DC90: lw          $t4, 0xE0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DC94: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8012DC98: jal         0x8001EAD0
    // 0x8012DC9C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x8012DC9C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_8:
    // 0x8012DCA0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DCA4: ldc1        $f16, -0x2A80($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2A80);
    // 0x8012DCA8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DCAC: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8012DCB0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8012DCB4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x8012DCB8: lw          $t6, 0xE0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DCBC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8012DCC0: jal         0x8001EB64
    // 0x8012DCC4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x8012DCC4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_9:
    // 0x8012DCC8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DCCC: ldc1        $f8, -0x2A78($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2A78);
    // 0x8012DCD0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DCD4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8012DCD8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8012DCDC: b           L_8012DE40
    // 0x8012DCE0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_8012DE40;
    // 0x8012DCE0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_8012DCE4:
    // 0x8012DCE4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8012DCE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8012DCEC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DCF0: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DCF4: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x8012DCF8: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DCFC: lhu         $v0, 0x190($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X190);
    // 0x8012DD00: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012DD04: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x8012DD08: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8012DD0C: lh          $t0, 0x12($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X12);
    // 0x8012DD10: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8012DD14: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8012DD18: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x8012DD1C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012DD20: jal         0x8001EAD0
    // 0x8012DD24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_10;
    // 0x8012DD24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_10:
    // 0x8012DD28: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DD2C: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x8012DD30: add.d       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f2.d + ctx->f2.d;
    // 0x8012DD34: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8012DD38: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8012DD3C: lw          $t1, 0xE0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DD40: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8012DD44: lh          $t3, 0x12($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X12);
    // 0x8012DD48: addu        $a0, $t3, $v0
    ctx->r4 = ADD32(ctx->r11, ctx->r2);
    // 0x8012DD4C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012DD50: jal         0x8001EB64
    // 0x8012DD54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_11;
    // 0x8012DD54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_11:
    // 0x8012DD58: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DD5C: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x8012DD60: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8012DD64: b           L_8012DE40
    // 0x8012DD68: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
        goto L_8012DE40;
    // 0x8012DD68: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_8012DD6C:
    // 0x8012DD6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DD70: lwc1        $f16, -0x2A70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2A70);
    // 0x8012DD74: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DD78: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DD7C: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x8012DD80: lw          $t4, 0xE0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DD84: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8012DD88: jal         0x8001EAD0
    // 0x8012DD8C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x8012DD8C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_12:
    // 0x8012DD90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DD94: ldc1        $f4, -0x2A68($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A68);
    // 0x8012DD98: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DD9C: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8012DDA0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8012DDA4: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x8012DDA8: lw          $t6, 0xE0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DDAC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8012DDB0: jal         0x8001EB64
    // 0x8012DDB4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_13;
    // 0x8012DDB4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_13:
    // 0x8012DDB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012DDBC: ldc1        $f16, -0x2A60($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2A60);
    // 0x8012DDC0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DDC4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8012DDC8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8012DDCC: b           L_8012DE40
    // 0x8012DDD0: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
        goto L_8012DE40;
    // 0x8012DDD0: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
L_8012DDD4:
    // 0x8012DDD4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8012DDD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8012DDDC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012DDE0: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012DDE4: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x8012DDE8: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DDEC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012DDF0: jal         0x8001EAD0
    // 0x8012DDF4: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_14;
    // 0x8012DDF4: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_14:
    // 0x8012DDF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8012DDFC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8012DE00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8012DE04: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DE08: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8012DE0C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012DE10: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8012DE14: lw          $t0, 0xE0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XE0);
    // 0x8012DE18: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8012DE1C: jal         0x8001EB64
    // 0x8012DE20: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_15;
    // 0x8012DE20: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_15:
    // 0x8012DE24: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8012DE28: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8012DE2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8012DE30: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8012DE34: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8012DE38: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8012DE3C: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_8012DE40:
    // 0x8012DE40: sb          $zero, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = 0;
    // 0x8012DE44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012DE48: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8012DE4C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8012DE50: jr          $ra
    // 0x8012DE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8012DE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012de58(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012de58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012DE58: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012DE5C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012DE60: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012de64(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012de64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012DE64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012DE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012DE6C: bnel        $a0, $t6, L_8012DF2C
    if (ctx->r4 != ctx->r14) {
        // 0x8012DE70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012DF2C;
    }
    goto skip_0;
    // 0x8012DE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8012DE74: jal         0x801F1114
    // 0x8012DE78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801F1114)(rdram, ctx);
        goto after_0;
    // 0x8012DE78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012DE7C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012DE80: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8012DE84: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012DE88: bne         $v0, $at, L_8012DF28
    if (ctx->r2 != ctx->r1) {
        // 0x8012DE8C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8012DF28;
    }
    // 0x8012DE8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8012DE90: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x8012DE94: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x8012DE98: beql        $v0, $zero, L_8012DEE8
    if (ctx->r2 == 0) {
        // 0x8012DE9C: lw          $v0, 0x30($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X30);
            goto L_8012DEE8;
    }
    goto skip_1;
    // 0x8012DE9C: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    skip_1:
    // 0x8012DEA0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012DEA4: lwc1        $f6, 0x390($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X390);
    // 0x8012DEA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012DEAC: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8012DEB0: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8012DEB4: lwc1        $f16, 0x394($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X394);
    // 0x8012DEB8: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8012DEBC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012DEC0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8012DEC4: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8012DEC8: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8012DECC: lwc1        $f6, 0x398($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X398);
    // 0x8012DED0: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8012DED4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012DED8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012DEDC: b           L_8012DF28
    // 0x8012DEE0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
        goto L_8012DF28;
    // 0x8012DEE0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8012DEE4: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
L_8012DEE8:
    // 0x8012DEE8: lwc1        $f16, 0x390($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X390);
    // 0x8012DEEC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012DEF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8012DEF4: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8012DEF8: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x8012DEFC: lwc1        $f6, 0x394($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X394);
    // 0x8012DF00: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x8012DF04: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012DF08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012DF0C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8012DF10: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x8012DF14: lwc1        $f16, 0x398($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X398);
    // 0x8012DF18: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x8012DF1C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012DF20: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8012DF24: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
L_8012DF28:
    // 0x8012DF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012DF2C:
    // 0x8012DF2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012DF30: jr          $ra
    // 0x8012DF34: nop

    return;
    // 0x8012DF34: nop

;}
RECOMP_FUNC void M7_FUN_8012df38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012DF38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012DF3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8012DF40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8012DF44: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8012DF48: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8012DF4C: beq         $a0, $zero, L_8012E100
    if (ctx->r4 == 0) {
        // 0x8012DF50: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8012E100;
    }
    // 0x8012DF50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012DF54: beql        $a1, $zero, L_8012E104
    if (ctx->r5 == 0) {
        // 0x8012DF58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E104;
    }
    goto skip_0;
    // 0x8012DF58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8012DF5C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8012DF60: beql        $v1, $zero, L_8012E104
    if (ctx->r3 == 0) {
        // 0x8012DF64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E104;
    }
    goto skip_1;
    // 0x8012DF64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8012DF68: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x8012DF6C: beql        $t6, $zero, L_8012E104
    if (ctx->r14 == 0) {
        // 0x8012DF70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E104;
    }
    goto skip_2;
    // 0x8012DF70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8012DF74: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x8012DF78: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012DF7C: lbu         $t8, 0x63($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X63);
    // 0x8012DF80: beql        $t8, $zero, L_8012E104
    if (ctx->r24 == 0) {
        // 0x8012DF84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E104;
    }
    goto skip_3;
    // 0x8012DF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8012DF88: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // 0x8012DF8C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8012DF90: beq         $v0, $at, L_8012DFB8
    if (ctx->r2 == ctx->r1) {
        // 0x8012DF94: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8012DFB8;
    }
    // 0x8012DF94: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8012DF98: beq         $v0, $at, L_8012DFB8
    if (ctx->r2 == ctx->r1) {
        // 0x8012DF9C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8012DFB8;
    }
    // 0x8012DF9C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8012DFA0: beq         $v0, $at, L_8012DFB8
    if (ctx->r2 == ctx->r1) {
        // 0x8012DFA4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8012DFB8;
    }
    // 0x8012DFA4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8012DFA8: beq         $v0, $at, L_8012DFB8
    if (ctx->r2 == ctx->r1) {
        // 0x8012DFAC: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8012DFB8;
    }
    // 0x8012DFAC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8012DFB0: bnel        $v0, $at, L_8012E104
    if (ctx->r2 != ctx->r1) {
        // 0x8012DFB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E104;
    }
    goto skip_4;
    // 0x8012DFB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_8012DFB8:
    // 0x8012DFB8: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8012DFBC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012DFC0: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
    // 0x8012DFC4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012DFC8: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
    // 0x8012DFCC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012DFD0: swc1        $f8, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f8.u32l;
    // 0x8012DFD4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8012DFD8: lbu         $t0, 0x22($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X22);
    // 0x8012DFDC: bnel        $t0, $zero, L_8012E024
    if (ctx->r8 != 0) {
        // 0x8012DFE0: lw          $t4, 0x24($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X24);
            goto L_8012E024;
    }
    goto skip_5;
    // 0x8012DFE0: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    skip_5:
    // 0x8012DFE4: lhu         $t1, 0xC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XC);
    // 0x8012DFE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012DFEC: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8012DFF0: blezl       $t1, L_8012E104
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8012DFF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E104;
    }
    goto skip_6;
    // 0x8012DFF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8012DFF8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
L_8012DFFC:
    // 0x8012DFFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8012E000: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8012E004: sw          $zero, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = 0;
    // 0x8012E008: lhu         $t3, 0xC($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XC);
    // 0x8012E00C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8012E010: bnel        $at, $zero, L_8012DFFC
    if (ctx->r1 != 0) {
        // 0x8012E014: lw          $t2, 0x0($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X0);
            goto L_8012DFFC;
    }
    goto skip_7;
    // 0x8012E014: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    skip_7:
    // 0x8012E018: b           L_8012E104
    // 0x8012E01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8012E104;
    // 0x8012E01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012E020: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
L_8012E024:
    // 0x8012E024: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8012E028: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012E02C: lw          $a0, 0x2C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2C);
    // 0x8012E030: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x8012E034: jal         0x8013A334
    // 0x8012E038: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x8012E038: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_0:
    // 0x8012E03C: lw          $t5, 0x30($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X30);
    // 0x8012E040: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8012E044: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012E048: lw          $a0, 0x2C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X2C);
    // 0x8012E04C: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x8012E050: jal         0x8013A334
    // 0x8012E054: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_1;
    // 0x8012E054: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_1:
    // 0x8012E058: lw          $t6, 0x3C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X3C);
    // 0x8012E05C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8012E060: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012E064: lw          $a0, 0x2C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X2C);
    // 0x8012E068: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8012E06C: jal         0x8013A334
    // 0x8012E070: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x8012E070: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_2:
    // 0x8012E074: lw          $t7, 0x48($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X48);
    // 0x8012E078: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8012E07C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012E080: lw          $a0, 0x2C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X2C);
    // 0x8012E084: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    // 0x8012E088: jal         0x8013A334
    // 0x8012E08C: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_3;
    // 0x8012E08C: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_3:
    // 0x8012E090: lw          $t8, 0x18($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X18);
    // 0x8012E094: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8012E098: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012E09C: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x8012E0A0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8012E0A4: jal         0x8013A334
    // 0x8012E0A8: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_4;
    // 0x8012E0A8: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_4:
    // 0x8012E0AC: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8012E0B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8012E0B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012E0B8: lw          $a0, 0x2C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X2C);
    // 0x8012E0BC: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x8012E0C0: jal         0x8013A334
    // 0x8012E0C4: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_5;
    // 0x8012E0C4: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_5:
    // 0x8012E0C8: lhu         $t0, 0xC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC);
    // 0x8012E0CC: slti        $at, $t0, 0x17
    ctx->r1 = SIGNED(ctx->r8) < 0X17 ? 1 : 0;
    // 0x8012E0D0: bnel        $at, $zero, L_8012E0F8
    if (ctx->r1 != 0) {
        // 0x8012E0D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8012E0F8;
    }
    goto skip_8;
    // 0x8012E0D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_8:
    // 0x8012E0D8: lw          $t1, 0x60($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X60);
    // 0x8012E0DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8012E0E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012E0E4: lw          $a0, 0x2C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X2C);
    // 0x8012E0E8: addiu       $a3, $zero, 0x21
    ctx->r7 = ADD32(0, 0X21);
    // 0x8012E0EC: jal         0x8013A334
    // 0x8012E0F0: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_6;
    // 0x8012E0F0: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_6:
    // 0x8012E0F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8012E0F8:
    // 0x8012E0F8: jal         0x801DB868
    // 0x8012E0FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801DB868)(rdram, ctx);
        goto after_7;
    // 0x8012E0FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
L_8012E100:
    // 0x8012E100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8012E104:
    // 0x8012E104: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8012E108: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8012E10C: jr          $ra
    // 0x8012E110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8012E110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012e114(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012e114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E114: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012E118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012E11C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8012E120: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8012E124: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8012E128: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8012E12C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8012E130: jal         0x8012E774
    // 0x8012E134: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012E774)(rdram, ctx);
        goto after_0;
    // 0x8012E134: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8012E138: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012E13C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012E140: lhu         $t7, 0xEF0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XEF0);
    // 0x8012E144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E148: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8012E14C: bnel        $t8, $zero, L_8012E168
    if (ctx->r24 != 0) {
        // 0x8012E150: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8012E168;
    }
    goto skip_0;
    // 0x8012E150: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8012E154: jal         0x801C4A5C
    // 0x8012E158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_1;
    // 0x8012E158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8012E15C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012E160: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012E164: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8012E168:
    // 0x8012E168: lbu         $t9, 0xF5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF5);
    // 0x8012E16C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8012E170: swc1        $f0, 0x238($v1)
    MEM_W(0X238, ctx->r3) = ctx->f0.u32l;
    // 0x8012E174: swc1        $f0, 0x23C($v1)
    MEM_W(0X23C, ctx->r3) = ctx->f0.u32l;
    // 0x8012E178: beq         $t9, $zero, L_8012E248
    if (ctx->r25 == 0) {
        // 0x8012E17C: swc1        $f0, 0x240($v1)
        MEM_W(0X240, ctx->r3) = ctx->f0.u32l;
            goto L_8012E248;
    }
    // 0x8012E17C: swc1        $f0, 0x240($v1)
    MEM_W(0X240, ctx->r3) = ctx->f0.u32l;
    // 0x8012E180: jal         0x8012DF38
    // 0x8012E184: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8012DF38)(rdram, ctx);
        goto after_2;
    // 0x8012E184: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8012E188: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8012E18C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012E190: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012E194: lbu         $t1, 0x22($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X22);
    // 0x8012E198: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8012E19C: beq         $t1, $zero, L_8012E234
    if (ctx->r9 == 0) {
        // 0x8012E1A0: nop
    
            goto L_8012E234;
    }
    // 0x8012E1A0: nop

    // 0x8012E1A4: lbu         $v0, 0x74($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X74);
    // 0x8012E1A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8012E1AC: beql        $v0, $zero, L_8012E1C0
    if (ctx->r2 == 0) {
        // 0x8012E1B0: lw          $t3, 0x18($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X18);
            goto L_8012E1C0;
    }
    goto skip_1;
    // 0x8012E1B0: lw          $t3, 0x18($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X18);
    skip_1:
    // 0x8012E1B4: bne         $v0, $at, L_8012E234
    if (ctx->r2 != ctx->r1) {
        // 0x8012E1B8: nop
    
            goto L_8012E234;
    }
    // 0x8012E1B8: nop

    // 0x8012E1BC: lw          $t3, 0x18($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X18);
L_8012E1C0:
    // 0x8012E1C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8012E1C4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8012E1C8: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8012E1CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8012E1D0: lwc1        $f4, 0xA4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XA4);
    // 0x8012E1D4: lwc1        $f6, 0x98($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X98);
    // 0x8012E1D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012E1DC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012E1E0: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8012E1E4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012E1E8: swc1        $f18, 0x238($v1)
    MEM_W(0X238, ctx->r3) = ctx->f18.u32l;
    // 0x8012E1EC: lw          $t4, 0x18($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X18);
    // 0x8012E1F0: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x8012E1F4: lwc1        $f4, 0xA8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XA8);
    // 0x8012E1F8: lwc1        $f6, 0x9C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x8012E1FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012E200: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012E204: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8012E208: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012E20C: swc1        $f18, 0x23C($v1)
    MEM_W(0X23C, ctx->r3) = ctx->f18.u32l;
    // 0x8012E210: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
    // 0x8012E214: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x8012E218: lwc1        $f4, 0xAC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x8012E21C: lwc1        $f6, 0xA0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XA0);
    // 0x8012E220: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012E224: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012E228: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8012E22C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8012E230: swc1        $f18, 0x240($v1)
    MEM_W(0X240, ctx->r3) = ctx->f18.u32l;
L_8012E234:
    // 0x8012E234: jal         0x8013C608
    // 0x8012E238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8013C608)(rdram, ctx);
        goto after_3;
    // 0x8012E238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8012E23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E240: jal         0x801DE7EC
    // 0x8012E244: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x801DE7EC)(rdram, ctx);
        goto after_4;
    // 0x8012E244: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_4:
L_8012E248:
    // 0x8012E248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012E24C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8012E250: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8012E254: jr          $ra
    // 0x8012E258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8012E258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012e25c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012e25c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E25C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012E260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012E264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8012E268: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012E26C: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8012E270: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8012E274: lbu         $t7, 0x74($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X74);
    // 0x8012E278: beql        $t7, $at, L_8012E310
    if (ctx->r15 == ctx->r1) {
        // 0x8012E27C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_0;
    // 0x8012E27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8012E280: jal         0x80126944
    // 0x8012E284: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8012E284: nop

    after_0:
    // 0x8012E288: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012E28C: bne         $v0, $at, L_8012E30C
    if (ctx->r2 != ctx->r1) {
        // 0x8012E290: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8012E30C;
    }
    // 0x8012E290: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012E294: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012E298: lbu         $v0, 0x1031($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1031);
    // 0x8012E29C: blez        $v0, L_8012E30C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8012E2A0: slti        $at, $v0, 0xE
        ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
            goto L_8012E30C;
    }
    // 0x8012E2A0: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x8012E2A4: beql        $at, $zero, L_8012E310
    if (ctx->r1 == 0) {
        // 0x8012E2A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_1;
    // 0x8012E2A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8012E2AC: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x8012E2B0: beql        $v0, $zero, L_8012E310
    if (ctx->r2 == 0) {
        // 0x8012E2B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_2;
    // 0x8012E2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8012E2B8: lw          $t8, 0xE0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE0);
    // 0x8012E2BC: beql        $t8, $zero, L_8012E310
    if (ctx->r24 == 0) {
        // 0x8012E2C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_3;
    // 0x8012E2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8012E2C4: lbu         $t9, 0x63($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X63);
    // 0x8012E2C8: beql        $t9, $zero, L_8012E310
    if (ctx->r25 == 0) {
        // 0x8012E2CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_4;
    // 0x8012E2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8012E2D0: lw          $v0, 0xEC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XEC);
    // 0x8012E2D4: beql        $v0, $zero, L_8012E310
    if (ctx->r2 == 0) {
        // 0x8012E2D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_5;
    // 0x8012E2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8012E2DC: lw          $t0, 0xF0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XF0);
    // 0x8012E2E0: beql        $t0, $zero, L_8012E310
    if (ctx->r8 == 0) {
        // 0x8012E2E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_6;
    // 0x8012E2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8012E2E8: lbu         $t1, 0x63($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X63);
    // 0x8012E2EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8012E2F0: beql        $t1, $zero, L_8012E310
    if (ctx->r9 == 0) {
        // 0x8012E2F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8012E310;
    }
    goto skip_7;
    // 0x8012E2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8012E2F8: jal         0x80223ED4
    // 0x8012E2FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80223ED4)(rdram, ctx);
        goto after_1;
    // 0x8012E2FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8012E300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8012E304: jal         0x801DBEE4
    // 0x8012E308: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801DBEE4)(rdram, ctx);
        goto after_2;
    // 0x8012E308: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_8012E30C:
    // 0x8012E30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012E310:
    // 0x8012E310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012E314: jr          $ra
    // 0x8012E318: nop

    return;
    // 0x8012E318: nop

;}
RECOMP_FUNC void M7_FUN_8012e31c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E31C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8012E320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012E324: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8012E328: lw          $t2, 0x5C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X5C);
    // 0x8012E32C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8012E330: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x8012E334: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8012E338: jal         0x80126944
    // 0x8012E33C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8012E33C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8012E340: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8012E344: bne         $v0, $v1, L_8012E364
    if (ctx->r2 != ctx->r3) {
        // 0x8012E348: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_8012E364;
    }
    // 0x8012E348: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8012E34C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012E350: lbu         $v0, -0x33DF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33DF);
    // 0x8012E354: blez        $v0, L_8012E440
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8012E358: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8012E440;
    }
    // 0x8012E358: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8012E35C: beql        $at, $zero, L_8012E444
    if (ctx->r1 == 0) {
        // 0x8012E360: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E444;
    }
    goto skip_0;
    // 0x8012E360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8012E364:
    // 0x8012E364: lbu         $v0, 0x9C($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X9C);
    // 0x8012E368: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8012E36C: beql        $v1, $v0, L_8012E380
    if (ctx->r3 == ctx->r2) {
        // 0x8012E370: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_8012E380;
    }
    goto skip_1;
    // 0x8012E370: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x8012E374: bnel        $v0, $at, L_8012E444
    if (ctx->r2 != ctx->r1) {
        // 0x8012E378: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E444;
    }
    goto skip_2;
    // 0x8012E378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8012E37C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_8012E380:
    // 0x8012E380: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // 0x8012E384: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8012E388: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8012E38C: bne         $v1, $v0, L_8012E3B4
    if (ctx->r3 != ctx->r2) {
        // 0x8012E390: lbu         $t1, 0x4B($t8)
        ctx->r9 = MEM_BU(ctx->r24, 0X4B);
            goto L_8012E3B4;
    }
    // 0x8012E390: lbu         $t1, 0x4B($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X4B);
    // 0x8012E394: addiu       $t1, $t1, -0x19
    ctx->r9 = ADD32(ctx->r9, -0X19);
    // 0x8012E398: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x8012E39C: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8012E3A0: bgtz        $t1, L_8012E3D4
    if (SIGNED(ctx->r9) > 0) {
        // 0x8012E3A4: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8012E3D4;
    }
    // 0x8012E3A4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8012E3A8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8012E3AC: b           L_8012E3D4
    // 0x8012E3B0: sb          $t9, 0x9C($t2)
    MEM_B(0X9C, ctx->r10) = ctx->r25;
        goto L_8012E3D4;
    // 0x8012E3B0: sb          $t9, 0x9C($t2)
    MEM_B(0X9C, ctx->r10) = ctx->r25;
L_8012E3B4:
    // 0x8012E3B4: addiu       $t1, $t1, 0x19
    ctx->r9 = ADD32(ctx->r9, 0X19);
    // 0x8012E3B8: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x8012E3BC: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8012E3C0: slti        $at, $t1, 0xFF
    ctx->r1 = SIGNED(ctx->r9) < 0XFF ? 1 : 0;
    // 0x8012E3C4: bnel        $at, $zero, L_8012E3D8
    if (ctx->r1 != 0) {
        // 0x8012E3C8: lhu         $a2, 0xC($t2)
        ctx->r6 = MEM_HU(ctx->r10, 0XC);
            goto L_8012E3D8;
    }
    goto skip_3;
    // 0x8012E3C8: lhu         $a2, 0xC($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0XC);
    skip_3:
    // 0x8012E3CC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8012E3D0: sb          $zero, 0x9C($t2)
    MEM_B(0X9C, ctx->r10) = 0;
L_8012E3D4:
    // 0x8012E3D4: lhu         $a2, 0xC($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0XC);
L_8012E3D8:
    // 0x8012E3D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8012E3DC: addiu       $a3, $a3, -0x4528
    ctx->r7 = ADD32(ctx->r7, -0X4528);
    // 0x8012E3E0: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8012E3E4: bne         $at, $zero, L_8012E440
    if (ctx->r1 != 0) {
        // 0x8012E3E8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8012E440;
    }
    // 0x8012E3E8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8012E3EC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8012E3F0:
    // 0x8012E3F0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8012E3F4: addu        $t4, $s0, $v1
    ctx->r12 = ADD32(ctx->r16, ctx->r3);
    // 0x8012E3F8: bgezl       $t3, L_8012E40C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8012E3FC: lw          $t5, 0x0($t4)
        ctx->r13 = MEM_W(ctx->r12, 0X0);
            goto L_8012E40C;
    }
    goto skip_4;
    // 0x8012E3FC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    skip_4:
    // 0x8012E400: b           L_8012E430
    // 0x8012E404: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
        goto L_8012E430;
    // 0x8012E404: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x8012E408: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
L_8012E40C:
    // 0x8012E40C: or          $t8, $a3, $t0
    ctx->r24 = ctx->r7 | ctx->r8;
    // 0x8012E410: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x8012E414: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x8012E418: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
    // 0x8012E41C: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
    // 0x8012E420: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8012E424: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8012E428: lhu         $a2, 0xC($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0XC);
    // 0x8012E42C: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
L_8012E430:
    // 0x8012E430: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8012E434: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8012E438: bne         $at, $zero, L_8012E3F0
    if (ctx->r1 != 0) {
        // 0x8012E43C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8012E3F0;
    }
    // 0x8012E43C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8012E440:
    // 0x8012E440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8012E444:
    // 0x8012E444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8012E448: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8012E44C: jr          $ra
    // 0x8012E450: nop

    return;
    // 0x8012E450: nop

;}
