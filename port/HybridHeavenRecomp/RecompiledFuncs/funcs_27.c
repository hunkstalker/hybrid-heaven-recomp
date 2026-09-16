#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8013a7d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A7D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013A7D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013A7DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013A7E0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8013A7E4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8013A7E8: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8013A7EC: lhu         $t6, -0x6B88($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B88);
    // 0x8013A7F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8013A7F4: and         $a2, $t0, $at
    ctx->r6 = ctx->r8 & ctx->r1;
    // 0x8013A7F8: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x8013A7FC: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x8013A800: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8013A804: beq         $t7, $zero, L_8013A89C
    if (ctx->r15 == 0) {
        // 0x8013A808: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_8013A89C;
    }
    // 0x8013A808: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8013A80C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8013A810: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8013A814: addiu       $a0, $a0, 0x36EC
    ctx->r4 = ADD32(ctx->r4, 0X36EC);
    // 0x8013A818: addiu       $v0, $v0, 0x36B0
    ctx->r2 = ADD32(ctx->r2, 0X36B0);
    // 0x8013A81C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8013A820: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
L_8013A824:
    // 0x8013A824: beq         $v1, $t8, L_8013A83C
    if (ctx->r3 == ctx->r24) {
        // 0x8013A828: nop
    
            goto L_8013A83C;
    }
    // 0x8013A828: nop

    // 0x8013A82C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8013A830: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8013A834: bnel        $at, $zero, L_8013A824
    if (ctx->r1 != 0) {
        // 0x8013A838: lhu         $t8, 0x0($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X0);
            goto L_8013A824;
    }
    goto skip_0;
    // 0x8013A838: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    skip_0:
L_8013A83C:
    // 0x8013A83C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8013A840: addiu       $t9, $t9, 0x36E6
    ctx->r25 = ADD32(ctx->r25, 0X36E6);
    // 0x8013A844: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8013A848: bne         $at, $zero, L_8013A85C
    if (ctx->r1 != 0) {
        // 0x8013A84C: addiu       $v0, $v0, 0x6
        ctx->r2 = ADD32(ctx->r2, 0X6);
            goto L_8013A85C;
    }
    // 0x8013A84C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8013A850: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8013A854: b           L_8013A85C
    // 0x8013A858: addiu       $v0, $v0, 0x36B0
    ctx->r2 = ADD32(ctx->r2, 0X36B0);
        goto L_8013A85C;
    // 0x8013A858: addiu       $v0, $v0, 0x36B0
    ctx->r2 = ADD32(ctx->r2, 0X36B0);
L_8013A85C:
    // 0x8013A85C: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x8013A860: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8013A864: sll         $a1, $t3, 16
    ctx->r5 = S32(ctx->r11 << 16);
    // 0x8013A868: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x8013A86C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013A870: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013A874: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013A878: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013A87C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013A880: jal         0x8013A28C
    // 0x8013A884: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_0;
    // 0x8013A884: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013A888: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8013A88C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8013A890: and         $a2, $t0, $at
    ctx->r6 = ctx->r8 & ctx->r1;
    // 0x8013A894: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x8013A898: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
L_8013A89C:
    // 0x8013A89C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8013A8A0: addiu       $v0, $a0, 0x36B0
    ctx->r2 = ADD32(ctx->r4, 0X36B0);
    // 0x8013A8A4: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8013A8A8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8013A8AC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8013A8B0: beq         $a2, $t7, L_8013A8C8
    if (ctx->r6 == ctx->r15) {
        // 0x8013A8B4: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_8013A8C8;
    }
    // 0x8013A8B4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8013A8B8: lhu         $t8, 0x6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6);
L_8013A8BC:
    // 0x8013A8BC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8013A8C0: bnel        $v1, $t8, L_8013A8BC
    if (ctx->r3 != ctx->r24) {
        // 0x8013A8C4: lhu         $t8, 0x6($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X6);
            goto L_8013A8BC;
    }
    goto skip_1;
    // 0x8013A8C4: lhu         $t8, 0x6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6);
    skip_1:
L_8013A8C8:
    // 0x8013A8C8: lhu         $t2, 0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2);
    // 0x8013A8CC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013A8D0: addiu       $a3, $a3, -0x20AC
    ctx->r7 = ADD32(ctx->r7, -0X20AC);
    // 0x8013A8D4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8013A8D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8013A8DC: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8013A8E0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8013A8E4: jal         0x8001DFFC
    // 0x8013A8E8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_1;
    // 0x8013A8E8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_1:
    // 0x8013A8EC: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x8013A8F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8013A8F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013A8F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013A8FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8013A900: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013A904: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8013A908: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8013A90C: addiu       $a3, $a3, -0x2098
    ctx->r7 = ADD32(ctx->r7, -0X2098);
    // 0x8013A910: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8013A914: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8013A918: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    // 0x8013A91C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8013A920: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8013A924: nop

    // 0x8013A928: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8013A92C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8013A930: nop

    // 0x8013A934: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8013A938: beq         $t4, $zero, L_8013A984
    if (ctx->r12 == 0) {
        // 0x8013A93C: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8013A984;
    }
    // 0x8013A93C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8013A940: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013A944: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013A948: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8013A94C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8013A950: nop

    // 0x8013A954: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8013A958: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8013A95C: nop

    // 0x8013A960: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8013A964: bne         $t4, $zero, L_8013A97C
    if (ctx->r12 != 0) {
        // 0x8013A968: nop
    
            goto L_8013A97C;
    }
    // 0x8013A968: nop

    // 0x8013A96C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8013A970: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A974: b           L_8013A994
    // 0x8013A978: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8013A994;
    // 0x8013A978: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8013A97C:
    // 0x8013A97C: b           L_8013A994
    // 0x8013A980: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8013A994;
    // 0x8013A980: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8013A984:
    // 0x8013A984: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8013A988: nop

    // 0x8013A98C: bltz        $t4, L_8013A97C
    if (SIGNED(ctx->r12) < 0) {
        // 0x8013A990: nop
    
            goto L_8013A97C;
    }
    // 0x8013A990: nop

L_8013A994:
    // 0x8013A994: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8013A998: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8013A99C: jal         0x8001DFFC
    // 0x8013A9A0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_2;
    // 0x8013A9A0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_2:
    // 0x8013A9A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013A9A8: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // 0x8013A9AC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8013A9B0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8013A9B4: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x8013A9B8: beq         $t6, $zero, L_8013AA1C
    if (ctx->r14 == 0) {
        // 0x8013A9BC: andi        $t7, $v0, 0x400
        ctx->r15 = ctx->r2 & 0X400;
            goto L_8013AA1C;
    }
    // 0x8013A9BC: andi        $t7, $v0, 0x400
    ctx->r15 = ctx->r2 & 0X400;
    // 0x8013A9C0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8013A9C4: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8013A9C8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8013A9CC: andi        $t7, $t0, 0xFFFF
    ctx->r15 = ctx->r8 & 0XFFFF;
    // 0x8013A9D0: beq         $t7, $zero, L_8013A9E4
    if (ctx->r15 == 0) {
        // 0x8013A9D4: or          $t4, $t9, $t3
        ctx->r12 = ctx->r25 | ctx->r11;
            goto L_8013A9E4;
    }
    // 0x8013A9D4: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x8013A9D8: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x8013A9DC: b           L_8013A9E8
    // 0x8013A9E0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_8013A9E8;
    // 0x8013A9E0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8013A9E4:
    // 0x8013A9E4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_8013A9E8:
    // 0x8013A9E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8013A9EC: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8013A9F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013A9F4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8013A9F8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013A9FC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013AA00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013AA04: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013AA08: jal         0x8013A2E0
    // 0x8013AA0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_3;
    // 0x8013AA0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x8013AA10: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AA14: b           L_8013AA7C
    // 0x8013AA18: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
        goto L_8013AA7C;
    // 0x8013AA18: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
L_8013AA1C:
    // 0x8013AA1C: beql        $t7, $zero, L_8013AA80
    if (ctx->r15 == 0) {
        // 0x8013AA20: andi        $t7, $v0, 0x10
        ctx->r15 = ctx->r2 & 0X10;
            goto L_8013AA80;
    }
    goto skip_2;
    // 0x8013AA20: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    skip_2:
    // 0x8013AA24: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8013AA28: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x8013AA2C: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x8013AA30: andi        $t8, $t0, 0xFFFF
    ctx->r24 = ctx->r8 & 0XFFFF;
    // 0x8013AA34: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x8013AA38: beq         $at, $zero, L_8013AA48
    if (ctx->r1 == 0) {
        // 0x8013AA3C: addiu       $t3, $t0, 0x1
        ctx->r11 = ADD32(ctx->r8, 0X1);
            goto L_8013AA48;
    }
    // 0x8013AA3C: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x8013AA40: b           L_8013AA4C
    // 0x8013AA44: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_8013AA4C;
    // 0x8013AA44: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_8013AA48:
    // 0x8013AA48: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_8013AA4C:
    // 0x8013AA4C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8013AA50: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8013AA54: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013AA58: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8013AA5C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013AA60: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013AA64: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013AA68: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013AA6C: jal         0x8013A2E0
    // 0x8013AA70: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_4;
    // 0x8013AA70: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_4:
    // 0x8013AA74: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AA78: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
L_8013AA7C:
    // 0x8013AA7C: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
L_8013AA80:
    // 0x8013AA80: beql        $t7, $zero, L_8013AAB8
    if (ctx->r15 == 0) {
        // 0x8013AA84: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_8013AAB8;
    }
    goto skip_3;
    // 0x8013AA84: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    skip_3:
    // 0x8013AA88: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
    // 0x8013AA8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013AA90: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8013AA94: xori        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 ^ 0X2;
    // 0x8013AA98: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x8013AA9C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8013AAA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013AAA4: jal         0x8000F2B8
    // 0x8013AAA8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_5;
    // 0x8013AAA8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_5:
    // 0x8013AAAC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AAB0: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // 0x8013AAB4: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
L_8013AAB8:
    // 0x8013AAB8: beql        $t4, $zero, L_8013AAF0
    if (ctx->r12 == 0) {
        // 0x8013AABC: andi        $t8, $v0, 0x8000
        ctx->r24 = ctx->r2 & 0X8000;
            goto L_8013AAF0;
    }
    goto skip_4;
    // 0x8013AABC: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    skip_4:
    // 0x8013AAC0: lhu         $t5, 0x6($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6);
    // 0x8013AAC4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8013AAC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8013AACC: xori        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 ^ 0X10;
    // 0x8013AAD0: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x8013AAD4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8013AAD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013AADC: jal         0x8000F2B8
    // 0x8013AAE0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_6;
    // 0x8013AAE0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_6:
    // 0x8013AAE4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AAE8: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // 0x8013AAEC: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
L_8013AAF0:
    // 0x8013AAF0: beql        $t8, $zero, L_8013AB20
    if (ctx->r24 == 0) {
        // 0x8013AAF4: lhu         $t5, 0x6($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X6);
            goto L_8013AB20;
    }
    goto skip_5;
    // 0x8013AAF4: lhu         $t5, 0x6($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6);
    skip_5:
    // 0x8013AAF8: lhu         $t9, 0x6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6);
    // 0x8013AAFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013AB00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8013AB04: xori        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 ^ 0X1;
    // 0x8013AB08: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x8013AB0C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8013AB10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013AB14: jal         0x8000F2B8
    // 0x8013AB18: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_7;
    // 0x8013AB18: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_7:
    // 0x8013AB1C: lhu         $t5, 0x6($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6);
L_8013AB20:
    // 0x8013AB20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013AB24: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8013AB28: beq         $t6, $zero, L_8013ABA4
    if (ctx->r14 == 0) {
        // 0x8013AB2C: nop
    
            goto L_8013ABA4;
    }
    // 0x8013AB2C: nop

    // 0x8013AB30: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8013AB34: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AB38: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8013AB3C: lhu         $t9, 0x60($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X60);
    // 0x8013AB40: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x8013AB44: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // 0x8013AB48: andi        $t3, $v0, 0x200
    ctx->r11 = ctx->r2 & 0X200;
    // 0x8013AB4C: beq         $t3, $zero, L_8013AB70
    if (ctx->r11 == 0) {
        // 0x8013AB50: andi        $t5, $v0, 0x100
        ctx->r13 = ctx->r2 & 0X100;
            goto L_8013AB70;
    }
    // 0x8013AB50: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x8013AB54: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x8013AB58: beq         $v0, $zero, L_8013AB68
    if (ctx->r2 == 0) {
        // 0x8013AB5C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_8013AB68;
    }
    // 0x8013AB5C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8013AB60: b           L_8013AB84
    // 0x8013AB64: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
        goto L_8013AB84;
    // 0x8013AB64: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
L_8013AB68:
    // 0x8013AB68: b           L_8013AB84
    // 0x8013AB6C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
        goto L_8013AB84;
    // 0x8013AB6C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_8013AB70:
    // 0x8013AB70: beql        $t5, $zero, L_8013AB88
    if (ctx->r13 == 0) {
        // 0x8013AB74: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_8013AB88;
    }
    goto skip_6;
    // 0x8013AB74: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x8013AB78: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x8013AB7C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013AB80: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
L_8013AB84:
    // 0x8013AB84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_8013AB88:
    // 0x8013AB88: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8013AB8C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013AB90: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013AB94: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013AB98: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013AB9C: jal         0x8013A2E0
    // 0x8013ABA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_8;
    // 0x8013ABA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_8:
L_8013ABA4:
    // 0x8013ABA4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013ABA8: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // 0x8013ABAC: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8013ABB0: beq         $t3, $zero, L_8013AC1C
    if (ctx->r11 == 0) {
        // 0x8013ABB4: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_8013AC1C;
    }
    // 0x8013ABB4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8013ABB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013ABBC: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8013ABC0: lui         $at, 0x3F90
    ctx->r1 = S32(0X3F90 << 16);
    // 0x8013ABC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8013ABC8: nop

    // 0x8013ABCC: bc1fl       L_8013ABF0
    if (!c1cs) {
        // 0x8013ABD0: lw          $t5, 0x0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X0);
            goto L_8013ABF0;
    }
    goto skip_7;
    // 0x8013ABD0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    skip_7:
    // 0x8013ABD4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8013ABD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8013ABDC: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x8013ABE0: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x8013ABE4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8013ABE8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8013ABEC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
L_8013ABF0:
    // 0x8013ABF0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013ABF4: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8013ABF8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013ABFC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013AC00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013AC04: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013AC08: jal         0x8013A2E0
    // 0x8013AC0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_9;
    // 0x8013AC0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_9:
    // 0x8013AC10: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AC14: b           L_8013ACA0
    // 0x8013AC18: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
        goto L_8013ACA0;
    // 0x8013AC18: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
L_8013AC1C:
    // 0x8013AC1C: beql        $t6, $zero, L_8013ACA4
    if (ctx->r14 == 0) {
        // 0x8013AC20: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8013ACA4;
    }
    goto skip_8;
    // 0x8013AC20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_8:
    // 0x8013AC24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013AC28: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8013AC2C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8013AC30: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8013AC34: nop

    // 0x8013AC38: bc1fl       L_8013AC50
    if (!c1cs) {
        // 0x8013AC3C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8013AC50;
    }
    goto skip_9;
    // 0x8013AC3C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_9:
    // 0x8013AC40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013AC44: b           L_8013AC74
    // 0x8013AC48: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_8013AC74;
    // 0x8013AC48: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8013AC4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8013AC50:
    // 0x8013AC50: lui         $at, 0x3F90
    ctx->r1 = S32(0X3F90 << 16);
    // 0x8013AC54: bc1fl       L_8013AC78
    if (!c1cs) {
        // 0x8013AC58: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_8013AC78;
    }
    goto skip_10;
    // 0x8013AC58: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x8013AC5C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8013AC60: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8013AC64: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8013AC68: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8013AC6C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8013AC70: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_8013AC74:
    // 0x8013AC74: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_8013AC78:
    // 0x8013AC78: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013AC7C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8013AC80: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013AC84: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013AC88: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013AC8C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013AC90: jal         0x8013A2E0
    // 0x8013AC94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_10;
    // 0x8013AC94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_10:
    // 0x8013AC98: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AC9C: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
L_8013ACA0:
    // 0x8013ACA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8013ACA4:
    // 0x8013ACA4: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x8013ACA8: beq         $t9, $zero, L_8013AD10
    if (ctx->r25 == 0) {
        // 0x8013ACAC: andi        $t5, $v0, 0x4
        ctx->r13 = ctx->r2 & 0X4;
            goto L_8013AD10;
    }
    // 0x8013ACAC: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x8013ACB0: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8013ACB4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8013ACB8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8013ACBC: nop

    // 0x8013ACC0: bc1fl       L_8013ACE4
    if (!c1cs) {
        // 0x8013ACC4: lw          $t4, 0x0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X0);
            goto L_8013ACE4;
    }
    goto skip_11;
    // 0x8013ACC4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    skip_11:
    // 0x8013ACC8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8013ACCC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8013ACD0: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8013ACD4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8013ACD8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8013ACDC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8013ACE0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
L_8013ACE4:
    // 0x8013ACE4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013ACE8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8013ACEC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013ACF0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013ACF4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013ACF8: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013ACFC: jal         0x8013A2E0
    // 0x8013AD00: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_11;
    // 0x8013AD00: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_11:
    // 0x8013AD04: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AD08: b           L_8013AD88
    // 0x8013AD0C: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
        goto L_8013AD88;
    // 0x8013AD0C: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
L_8013AD10:
    // 0x8013AD10: beql        $t5, $zero, L_8013AD8C
    if (ctx->r13 == 0) {
        // 0x8013AD14: andi        $t8, $v0, 0x2000
        ctx->r24 = ctx->r2 & 0X2000;
            goto L_8013AD8C;
    }
    goto skip_12;
    // 0x8013AD14: andi        $t8, $v0, 0x2000
    ctx->r24 = ctx->r2 & 0X2000;
    skip_12:
    // 0x8013AD18: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8013AD1C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8013AD20: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8013AD24: nop

    // 0x8013AD28: bc1fl       L_8013AD40
    if (!c1cs) {
        // 0x8013AD2C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8013AD40;
    }
    goto skip_13;
    // 0x8013AD2C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_13:
    // 0x8013AD30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013AD34: b           L_8013AD5C
    // 0x8013AD38: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_8013AD5C;
    // 0x8013AD38: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8013AD3C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8013AD40:
    // 0x8013AD40: nop

    // 0x8013AD44: bc1fl       L_8013AD60
    if (!c1cs) {
        // 0x8013AD48: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_8013AD60;
    }
    goto skip_14;
    // 0x8013AD48: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_14:
    // 0x8013AD4C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8013AD50: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8013AD54: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8013AD58: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8013AD5C:
    // 0x8013AD5C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_8013AD60:
    // 0x8013AD60: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013AD64: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8013AD68: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013AD6C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013AD70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013AD74: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013AD78: jal         0x8013A2E0
    // 0x8013AD7C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_12;
    // 0x8013AD7C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_12:
    // 0x8013AD80: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8013AD84: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
L_8013AD88:
    // 0x8013AD88: andi        $t8, $v0, 0x2000
    ctx->r24 = ctx->r2 & 0X2000;
L_8013AD8C:
    // 0x8013AD8C: beq         $t8, $zero, L_8013ADC0
    if (ctx->r24 == 0) {
        // 0x8013AD90: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8013ADC0;
    }
    // 0x8013AD90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013AD94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013AD98: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8013AD9C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8013ADA0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8013ADA4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8013ADA8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013ADAC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013ADB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013ADB4: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8013ADB8: jal         0x8013A2E0
    // 0x8013ADBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A2E0)(rdram, ctx);
        goto after_13;
    // 0x8013ADBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_13:
L_8013ADC0:
    // 0x8013ADC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013ADC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013ADC8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013ADCC: jr          $ra
    // 0x8013ADD0: nop

    return;
    // 0x8013ADD0: nop

;}
RECOMP_FUNC void M7_FUN_8013add4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013ADD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013ADD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013ADDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013ADE0: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x8013ADE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8013ADE8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8013ADEC: jal         0x80010550
    // 0x8013ADF0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8013ADF0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8013ADF4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8013ADF8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013ADFC: jal         0x8013A7D4
    // 0x8013AE00: addiu       $a1, $a2, 0x1C
    ctx->r5 = ADD32(ctx->r6, 0X1C);
    LOOKUP_FUNC(0x8013A7D4)(rdram, ctx);
        goto after_1;
    // 0x8013AE00: addiu       $a1, $a2, 0x1C
    ctx->r5 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x8013AE04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013AE08: jal         0x8013A5E8
    // 0x8013AE0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013A5E8)(rdram, ctx);
        goto after_2;
    // 0x8013AE0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8013AE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013AE14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013AE18: jr          $ra
    // 0x8013AE1C: nop

    return;
    // 0x8013AE1C: nop

;}
RECOMP_FUNC void M7_FUN_8013ae20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AE20: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8013AE24: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013AE28: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8013AE2C: addiu       $t6, $t6, -0x4334
    ctx->r14 = ADD32(ctx->r14, -0X4334);
    // 0x8013AE30: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013AE34: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x8013AE38: addiu       $t0, $sp, 0xBC
    ctx->r8 = ADD32(ctx->r29, 0XBC);
    // 0x8013AE3C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8013AE40: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013AE44: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013AE48: addiu       $t9, $t9, -0x431C
    ctx->r25 = ADD32(ctx->r25, -0X431C);
    // 0x8013AE4C: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8013AE50: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013AE54: addiu       $t1, $sp, 0xA4
    ctx->r9 = ADD32(ctx->r29, 0XA4);
    // 0x8013AE58: addiu       $t2, $sp, 0x8C
    ctx->r10 = ADD32(ctx->r29, 0X8C);
    // 0x8013AE5C: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x8013AE60: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013AE64: addiu       $t3, $sp, 0x74
    ctx->r11 = ADD32(ctx->r29, 0X74);
    // 0x8013AE68: addiu       $t4, $sp, 0x5C
    ctx->r12 = ADD32(ctx->r29, 0X5C);
    // 0x8013AE6C: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
    // 0x8013AE70: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8013AE74: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x8013AE78: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8013AE7C: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x8013AE80: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8013AE84: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013AE88: addiu       $t8, $t8, -0x4304
    ctx->r24 = ADD32(ctx->r24, -0X4304);
    // 0x8013AE8C: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x8013AE90: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8013AE94: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013AE98: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8013AE9C: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8013AEA0: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8013AEA4: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x8013AEA8: sw          $t7, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r15;
    // 0x8013AEAC: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x8013AEB0: sw          $t6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r14;
    // 0x8013AEB4: lw          $t7, 0x10($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X10);
    // 0x8013AEB8: sw          $t7, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r15;
    // 0x8013AEBC: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x8013AEC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8013AEC4: addiu       $t7, $t7, -0x42EC
    ctx->r15 = ADD32(ctx->r15, -0X42EC);
    // 0x8013AEC8: sw          $t6, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r14;
    // 0x8013AECC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8013AED0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8013AED4: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8013AED8: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8013AEDC: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x8013AEE0: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x8013AEE4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8013AEE8: sw          $t9, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r25;
    // 0x8013AEEC: lw          $t6, 0x10($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X10);
    // 0x8013AEF0: sw          $t6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r14;
    // 0x8013AEF4: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8013AEF8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013AEFC: addiu       $t6, $t6, -0x42D4
    ctx->r14 = ADD32(ctx->r14, -0X42D4);
    // 0x8013AF00: sw          $t9, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r25;
    // 0x8013AF04: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013AF08: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8013AF0C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013AF10: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8013AF14: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013AF18: sw          $t9, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r25;
    // 0x8013AF1C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013AF20: sw          $t8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r24;
    // 0x8013AF24: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8013AF28: sw          $t9, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r25;
    // 0x8013AF2C: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8013AF30: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013AF34: addiu       $t9, $t9, -0x42BC
    ctx->r25 = ADD32(ctx->r25, -0X42BC);
    // 0x8013AF38: sw          $t8, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r24;
    // 0x8013AF3C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013AF40: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8013AF44: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013AF48: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8013AF4C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013AF50: sw          $t8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r24;
    // 0x8013AF54: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013AF58: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x8013AF5C: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8013AF60: sw          $t8, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r24;
    // 0x8013AF64: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8013AF68: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8013AF6C: sw          $t7, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r15;
    // 0x8013AF70: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8013AF74: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8013AF78: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8013AF7C: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8013AF80: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x8013AF84: sw          $t7, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r15;
    // 0x8013AF88: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x8013AF8C: sw          $t6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r14;
    // 0x8013AF90: lw          $t7, 0x10($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X10);
    // 0x8013AF94: sw          $t7, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r15;
    // 0x8013AF98: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x8013AF9C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013AFA0: addiu       $t9, $t9, -0x42A4
    ctx->r25 = ADD32(ctx->r25, -0X42A4);
    // 0x8013AFA4: sw          $t6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r14;
    // 0x8013AFA8: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8013AFAC: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8013AFB0: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8013AFB4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8013AFB8: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x8013AFBC: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x8013AFC0: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8013AFC4: sw          $t6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r14;
    // 0x8013AFC8: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x8013AFCC: lw          $t7, 0x10($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X10);
    // 0x8013AFD0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013AFD4: addiu       $t9, $t9, -0x428C
    ctx->r25 = ADD32(ctx->r25, -0X428C);
    // 0x8013AFD8: sw          $t6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r14;
    // 0x8013AFDC: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8013AFE0: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8013AFE4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8013AFE8: addiu       $t8, $sp, 0x14
    ctx->r24 = ADD32(ctx->r29, 0X14);
    // 0x8013AFEC: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8013AFF0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8013AFF4: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x8013AFF8: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x8013AFFC: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8013B000: sw          $t6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r14;
    // 0x8013B004: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x8013B008: lw          $t7, 0x10($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X10);
    // 0x8013B00C: sw          $t6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r14;
    // 0x8013B010: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8013B014: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x8013B018: bnel        $v0, $at, L_8013B02C
    if (ctx->r2 != ctx->r1) {
        // 0x8013B01C: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_8013B02C;
    }
    goto skip_0;
    // 0x8013B01C: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    skip_0:
    // 0x8013B020: b           L_8013B0AC
    // 0x8013B024: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8013B0AC;
    // 0x8013B024: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8013B028: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
L_8013B02C:
    // 0x8013B02C: bnel        $v0, $at, L_8013B040
    if (ctx->r2 != ctx->r1) {
        // 0x8013B030: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_8013B040;
    }
    goto skip_1;
    // 0x8013B030: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    skip_1:
    // 0x8013B034: b           L_8013B0AC
    // 0x8013B038: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8013B0AC;
    // 0x8013B038: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8013B03C: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
L_8013B040:
    // 0x8013B040: bnel        $v0, $at, L_8013B054
    if (ctx->r2 != ctx->r1) {
        // 0x8013B044: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_8013B054;
    }
    goto skip_2;
    // 0x8013B044: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    skip_2:
    // 0x8013B048: b           L_8013B0AC
    // 0x8013B04C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8013B0AC;
    // 0x8013B04C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8013B050: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
L_8013B054:
    // 0x8013B054: bnel        $v0, $at, L_8013B068
    if (ctx->r2 != ctx->r1) {
        // 0x8013B058: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_8013B068;
    }
    goto skip_3;
    // 0x8013B058: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    skip_3:
    // 0x8013B05C: b           L_8013B0AC
    // 0x8013B060: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_8013B0AC;
    // 0x8013B060: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8013B064: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
L_8013B068:
    // 0x8013B068: bnel        $v0, $at, L_8013B07C
    if (ctx->r2 != ctx->r1) {
        // 0x8013B06C: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_8013B07C;
    }
    goto skip_4;
    // 0x8013B06C: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    skip_4:
    // 0x8013B070: b           L_8013B0AC
    // 0x8013B074: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_8013B0AC;
    // 0x8013B074: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8013B078: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
L_8013B07C:
    // 0x8013B07C: bnel        $v0, $at, L_8013B090
    if (ctx->r2 != ctx->r1) {
        // 0x8013B080: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_8013B090;
    }
    goto skip_5;
    // 0x8013B080: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    skip_5:
    // 0x8013B084: b           L_8013B0AC
    // 0x8013B088: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_8013B0AC;
    // 0x8013B088: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8013B08C: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
L_8013B090:
    // 0x8013B090: bnel        $v0, $at, L_8013B0A4
    if (ctx->r2 != ctx->r1) {
        // 0x8013B094: addiu       $at, $zero, 0x4057
        ctx->r1 = ADD32(0, 0X4057);
            goto L_8013B0A4;
    }
    goto skip_6;
    // 0x8013B094: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
    skip_6:
    // 0x8013B098: b           L_8013B0AC
    // 0x8013B09C: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
        goto L_8013B0AC;
    // 0x8013B09C: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x8013B0A0: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
L_8013B0A4:
    // 0x8013B0A4: bne         $v0, $at, L_8013B124
    if (ctx->r2 != ctx->r1) {
        // 0x8013B0A8: addiu       $v0, $sp, 0x14
        ctx->r2 = ADD32(ctx->r29, 0X14);
            goto L_8013B124;
    }
    // 0x8013B0A8: addiu       $v0, $sp, 0x14
    ctx->r2 = ADD32(ctx->r29, 0X14);
L_8013B0AC:
    // 0x8013B0AC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8013B0B0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8013B0B4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8013B0B8: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x8013B0BC: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x8013B0C0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8013B0C4: addiu       $a3, $a3, 0x1CF0
    ctx->r7 = ADD32(ctx->r7, 0X1CF0);
    // 0x8013B0C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8013B0CC: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8013B0D0: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x8013B0D4: lhu         $t7, 0x2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X2);
    // 0x8013B0D8: lw          $v1, 0x4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4);
    // 0x8013B0DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8013B0E0: lw          $t7, 0x24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X24);
    // 0x8013B0E4: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8013B0E8: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8013B0EC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8013B0F0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x8013B0F4: lhu         $t9, 0x4($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X4);
    // 0x8013B0F8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8013B0FC: addu        $t6, $a3, $t7
    ctx->r14 = ADD32(ctx->r7, ctx->r15);
    // 0x8013B100: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013B104: lhu         $t9, 0x6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6);
    // 0x8013B108: lw          $v1, 0x4($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X4);
    // 0x8013B10C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8013B110: lw          $t9, 0x30($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X30);
    // 0x8013B114: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x8013B118: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013B11C: lw          $t7, 0x2C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X2C);
    // 0x8013B120: sw          $t8, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r24;
L_8013B124:
    // 0x8013B124: jr          $ra
    // 0x8013B128: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8013B128: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013b12c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013b12c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B12C: nop

;}
RECOMP_FUNC void M7_FUN_8013b130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013B134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013B138: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8013B13C: addiu       $a0, $a0, -0x1500
    ctx->r4 = ADD32(ctx->r4, -0X1500);
    // 0x8013B140: jal         0x800279F0
    // 0x8013B144: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x8013B144: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x8013B148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013B14C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013B150: jr          $ra
    // 0x8013B154: nop

    return;
    // 0x8013B154: nop

;}
RECOMP_FUNC void M7_FUN_8013b158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B158: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013B15C: addiu       $v0, $v0, -0x1500
    ctx->r2 = ADD32(ctx->r2, -0X1500);
    // 0x8013B160: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013B164: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
L_8013B168:
    // 0x8013B168: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8013B16C: bnel        $t7, $zero, L_8013B180
    if (ctx->r15 != 0) {
        // 0x8013B170: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8013B180;
    }
    goto skip_0;
    // 0x8013B170: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8013B174: jr          $ra
    // 0x8013B178: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013B178: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013B17C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8013B180:
    // 0x8013B180: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8013B184: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8013B188: bnel        $at, $zero, L_8013B168
    if (ctx->r1 != 0) {
        // 0x8013B18C: addu        $t6, $v0, $v1
        ctx->r14 = ADD32(ctx->r2, ctx->r3);
            goto L_8013B168;
    }
    goto skip_1;
    // 0x8013B18C: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    skip_1:
    // 0x8013B190: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8013B194: jr          $ra
    // 0x8013B198: nop

    return;
    // 0x8013B198: nop

;}
RECOMP_FUNC void M7_FUN_8013b19c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B19C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8013B1A0: addiu       $a3, $a3, -0x2BA0
    ctx->r7 = ADD32(ctx->r7, -0X2BA0);
    // 0x8013B1A4: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x8013B1A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013B1AC: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x8013B1B0: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8013B1B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013B1B8: beq         $a2, $t6, L_8013B1FC
    if (ctx->r6 == ctx->r14) {
        // 0x8013B1BC: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_8013B1FC;
    }
    // 0x8013B1BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8013B1C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8013B1C4: addiu       $t7, $t7, -0x2BA0
    ctx->r15 = ADD32(ctx->r15, -0X2BA0);
    // 0x8013B1C8: lhu         $a1, 0x4($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X4);
    // 0x8013B1CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8013B1D0:
    // 0x8013B1D0: bnel        $v0, $a1, L_8013B1E4
    if (ctx->r2 != ctx->r5) {
        // 0x8013B1D4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8013B1E4;
    }
    goto skip_0;
    // 0x8013B1D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8013B1D8: jr          $ra
    // 0x8013B1DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013B1DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013B1E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8013B1E4:
    // 0x8013B1E4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8013B1E8: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x8013B1EC: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8013B1F0: lhu         $a1, 0x4($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X4);
    // 0x8013B1F4: bne         $a2, $a1, L_8013B1D0
    if (ctx->r6 != ctx->r5) {
        // 0x8013B1F8: nop
    
            goto L_8013B1D0;
    }
    // 0x8013B1F8: nop

L_8013B1FC:
    // 0x8013B1FC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8013B200: jr          $ra
    // 0x8013B204: nop

    return;
    // 0x8013B204: nop

;}
RECOMP_FUNC void M7_FUN_8013b208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013B20C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013B210: lbu         $v0, 0x60($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X60);
    // 0x8013B214: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8013B218: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8013B21C: beq         $at, $zero, L_8013B254
    if (ctx->r1 == 0) {
        // 0x8013B220: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8013B254;
    }
    // 0x8013B220: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013B224: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8013B228: sb          $zero, -0x1500($at)
    MEM_B(-0X1500, ctx->r1) = 0;
    // 0x8013B22C: lbu         $t6, 0x60($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X60);
    // 0x8013B230: addiu       $t8, $t8, -0x2680
    ctx->r24 = ADD32(ctx->r24, -0X2680);
    // 0x8013B234: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8013B238: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8013B23C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8013B240: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8013B244: jal         0x800279F0
    // 0x8013B248: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x8013B248: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8013B24C: b           L_8013B258
    // 0x8013B250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013B258;
    // 0x8013B250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013B254:
    // 0x8013B254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013B258:
    // 0x8013B258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013B25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013B260: jr          $ra
    // 0x8013B264: nop

    return;
    // 0x8013B264: nop

;}
RECOMP_FUNC void M7_FUN_8013b268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B268: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013B26C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013B270: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8013B274: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8013B278: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8013B27C: jal         0x8013B158
    // 0x8013B280: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013B158)(rdram, ctx);
        goto after_0;
    // 0x8013B280: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013B284: sb          $v0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r2;
    // 0x8013B288: jal         0x8013B19C
    // 0x8013B28C: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    LOOKUP_FUNC(0x8013B19C)(rdram, ctx);
        goto after_1;
    // 0x8013B28C: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    after_1:
    // 0x8013B290: lbu         $t6, 0x22($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X22);
    // 0x8013B294: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8013B298: sb          $v0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r2;
    // 0x8013B29C: beq         $v1, $t6, L_8013B2AC
    if (ctx->r3 == ctx->r14) {
        // 0x8013B2A0: nop
    
            goto L_8013B2AC;
    }
    // 0x8013B2A0: nop

    // 0x8013B2A4: bnel        $v1, $v0, L_8013B2B8
    if (ctx->r3 != ctx->r2) {
        // 0x8013B2A8: lbu         $v0, 0x3B($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X3B);
            goto L_8013B2B8;
    }
    goto skip_0;
    // 0x8013B2A8: lbu         $v0, 0x3B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X3B);
    skip_0:
L_8013B2AC:
    // 0x8013B2AC: b           L_8013B560
    // 0x8013B2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013B560;
    // 0x8013B2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013B2B4: lbu         $v0, 0x3B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X3B);
L_8013B2B8:
    // 0x8013B2B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013B2BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013B2C0: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x8013B2C4: beq         $v1, $at, L_8013B2D4
    if (ctx->r3 == ctx->r1) {
        // 0x8013B2C8: lui         $a1, 0x8014
        ctx->r5 = S32(0X8014 << 16);
            goto L_8013B2D4;
    }
    // 0x8013B2C8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013B2CC: bne         $v1, $zero, L_8013B2E8
    if (ctx->r3 != 0) {
        // 0x8013B2D0: andi        $t7, $v0, 0x80
        ctx->r15 = ctx->r2 & 0X80;
            goto L_8013B2E8;
    }
    // 0x8013B2D0: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
L_8013B2D4:
    // 0x8013B2D4: addiu       $a1, $a1, -0x4720
    ctx->r5 = ADD32(ctx->r5, -0X4720);
    // 0x8013B2D8: jal         0x800058DC
    // 0x8013B2DC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8013B2DC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8013B2E0: b           L_8013B318
    // 0x8013B2E4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8013B318;
    // 0x8013B2E4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8013B2E8:
    // 0x8013B2E8: beq         $t7, $zero, L_8013B308
    if (ctx->r15 == 0) {
        // 0x8013B2EC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8013B308;
    }
    // 0x8013B2EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013B2F0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8013B2F4: addiu       $a1, $a1, -0x41F8
    ctx->r5 = ADD32(ctx->r5, -0X41F8);
    // 0x8013B2F8: jal         0x80005670
    // 0x8013B2FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x8013B2FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8013B300: b           L_8013B318
    // 0x8013B304: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8013B318;
    // 0x8013B304: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8013B308:
    // 0x8013B308: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8013B30C: jal         0x80005670
    // 0x8013B310: addiu       $a1, $a1, -0x420C
    ctx->r5 = ADD32(ctx->r5, -0X420C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_4;
    // 0x8013B310: addiu       $a1, $a1, -0x420C
    ctx->r5 = ADD32(ctx->r5, -0X420C);
    after_4:
    // 0x8013B314: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8013B318:
    // 0x8013B318: beq         $v1, $zero, L_8013B55C
    if (ctx->r3 == 0) {
        // 0x8013B31C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8013B55C;
    }
    // 0x8013B31C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013B320: lhu         $t0, 0x36($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X36);
    // 0x8013B324: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x8013B328: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013B32C: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x8013B330: sh          $t8, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r24;
    // 0x8013B334: lbu         $t9, 0x22($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X22);
    // 0x8013B338: lbu         $t1, 0x22($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X22);
    // 0x8013B33C: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x8013B340: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8013B344: sb          $a1, -0x1500($at)
    MEM_B(-0X1500, ctx->r1) = ctx->r5;
    // 0x8013B348: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8013B34C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8013B350: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013B354: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8013B358: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8013B35C: addiu       $t6, $t6, -0x2BA0
    ctx->r14 = ADD32(ctx->r14, -0X2BA0);
    // 0x8013B360: addiu       $t3, $t3, -0x2680
    ctx->r11 = ADD32(ctx->r11, -0X2680);
    // 0x8013B364: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8013B368: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8013B36C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8013B370: lbu         $t7, 0x10($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10);
    // 0x8013B374: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8013B378: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8013B37C: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x8013B380: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x8013B384: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8013B388: addiu       $t3, $t3, -0x2F74
    ctx->r11 = ADD32(ctx->r11, -0X2F74);
    // 0x8013B38C: sh          $t0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r8;
    // 0x8013B390: sh          $t7, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r15;
    // 0x8013B394: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013B398: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x8013B39C: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x8013B3A0: sb          $t2, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r10;
    // 0x8013B3A4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8013B3A8: lhu         $t6, 0x1C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1C);
    // 0x8013B3AC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8013B3B0: sw          $t5, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r13;
    // 0x8013B3B4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8013B3B8: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x8013B3BC: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8013B3C0: sb          $zero, 0x9D($a0)
    MEM_B(0X9D, ctx->r4) = 0;
    // 0x8013B3C4: sb          $zero, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = 0;
    // 0x8013B3C8: sh          $a1, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r5;
    // 0x8013B3CC: sh          $a1, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = ctx->r5;
    // 0x8013B3D0: sb          $a3, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r7;
    // 0x8013B3D4: sh          $t6, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r14;
    // 0x8013B3D8: sw          $t5, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r13;
    // 0x8013B3DC: sw          $a0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r4;
    // 0x8013B3E0: lbu         $t7, 0x22($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X22);
    // 0x8013B3E4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013B3E8: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8013B3EC: sb          $t7, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r15;
    // 0x8013B3F0: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x8013B3F4: sb          $zero, 0x63($v1)
    MEM_B(0X63, ctx->r3) = 0;
    // 0x8013B3F8: beq         $a3, $zero, L_8013B45C
    if (ctx->r7 == 0) {
        // 0x8013B3FC: sb          $t8, 0x61($v1)
        MEM_B(0X61, ctx->r3) = ctx->r24;
            goto L_8013B45C;
    }
    // 0x8013B3FC: sb          $t8, 0x61($v1)
    MEM_B(0X61, ctx->r3) = ctx->r24;
    // 0x8013B400: lhu         $v0, 0x2C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2C);
    // 0x8013B404: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013B408: beq         $v0, $at, L_8013B450
    if (ctx->r2 == ctx->r1) {
        // 0x8013B40C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8013B450;
    }
    // 0x8013B40C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013B410: beq         $v0, $at, L_8013B450
    if (ctx->r2 == ctx->r1) {
        // 0x8013B414: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8013B450;
    }
    // 0x8013B414: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013B418: beq         $v0, $at, L_8013B450
    if (ctx->r2 == ctx->r1) {
        // 0x8013B41C: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8013B450;
    }
    // 0x8013B41C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8013B420: beq         $v0, $at, L_8013B450
    if (ctx->r2 == ctx->r1) {
        // 0x8013B424: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8013B450;
    }
    // 0x8013B424: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013B428: bne         $v0, $at, L_8013B45C
    if (ctx->r2 != ctx->r1) {
        // 0x8013B42C: nop
    
            goto L_8013B45C;
    }
    // 0x8013B42C: nop

    // 0x8013B430: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8013B434: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8013B438: jal         0x80126944
    // 0x8013B43C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_5;
    // 0x8013B43C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x8013B440: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013B444: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8013B448: beq         $v0, $zero, L_8013B45C
    if (ctx->r2 == 0) {
        // 0x8013B44C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8013B45C;
    }
    // 0x8013B44C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8013B450:
    // 0x8013B450: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x8013B454: ori         $t1, $t9, 0x3E0
    ctx->r9 = ctx->r25 | 0X3E0;
    // 0x8013B458: sw          $t1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r9;
L_8013B45C:
    // 0x8013B45C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013B460: sltiu       $at, $a2, 0x5
    ctx->r1 = ctx->r6 < 0X5 ? 1 : 0;
    // 0x8013B464: beq         $at, $zero, L_8013B50C
    if (ctx->r1 == 0) {
        // 0x8013B468: addiu       $a1, $a1, -0x4410
        ctx->r5 = ADD32(ctx->r5, -0X4410);
            goto L_8013B50C;
    }
    // 0x8013B468: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8013B46C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8013B470: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013B474: addu        $at, $at, $t2
    gpr jr_addend_8013B47C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8013B478: lw          $t2, -0x1ED0($at)
    ctx->r10 = ADD32(ctx->r1, -0X1ED0);
    // 0x8013B47C: jr          $t2
    // 0x8013B480: nop

    switch (jr_addend_8013B47C >> 2) {
        case 0: goto L_8013B484; break;
        case 1: goto L_8013B4E4; break;
        case 2: goto L_8013B4AC; break;
        case 3: goto L_8013B4E4; break;
        case 4: goto L_8013B50C; break;
        default: switch_error(__func__, 0x8013B47C, 0x8018E130);
    }
    // 0x8013B480: nop

L_8013B484:
    // 0x8013B484: sw          $v1, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->r3;
    // 0x8013B488: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013B48C: sw          $a0, -0x3FCC($at)
    MEM_W(-0X3FCC, ctx->r1) = ctx->r4;
    // 0x8013B490: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
    // 0x8013B494: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8013B498: addiu       $t3, $t3, -0x4374
    ctx->r11 = ADD32(ctx->r11, -0X4374);
    // 0x8013B49C: ori         $t5, $t4, 0x3E0
    ctx->r13 = ctx->r12 | 0X3E0;
    // 0x8013B4A0: sw          $t3, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r11;
    // 0x8013B4A4: b           L_8013B524
    // 0x8013B4A8: sw          $t5, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r13;
        goto L_8013B524;
    // 0x8013B4A8: sw          $t5, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r13;
L_8013B4AC:
    // 0x8013B4AC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8013B4B0: sw          $v1, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->r3;
    // 0x8013B4B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013B4B8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013B4BC: sw          $a0, -0x3FCC($at)
    MEM_W(-0X3FCC, ctx->r1) = ctx->r4;
    // 0x8013B4C0: addiu       $t6, $t6, -0x4374
    ctx->r14 = ADD32(ctx->r14, -0X4374);
    // 0x8013B4C4: sw          $t6, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r14;
    // 0x8013B4C8: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x8013B4CC: ori         $t8, $t7, 0x3E0
    ctx->r24 = ctx->r15 | 0X3E0;
    // 0x8013B4D0: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x8013B4D4: lw          $t9, 0x54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X54);
    // 0x8013B4D8: ori         $t1, $t9, 0x1E1
    ctx->r9 = ctx->r25 | 0X1E1;
    // 0x8013B4DC: b           L_8013B524
    // 0x8013B4E0: sw          $t1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r9;
        goto L_8013B524;
    // 0x8013B4E0: sw          $t1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r9;
L_8013B4E4:
    // 0x8013B4E4: sw          $v1, 0xEC($a1)
    MEM_W(0XEC, ctx->r5) = ctx->r3;
    // 0x8013B4E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013B4EC: sw          $a0, -0x3FC8($at)
    MEM_W(-0X3FC8, ctx->r1) = ctx->r4;
    // 0x8013B4F0: lw          $t3, 0x54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X54);
    // 0x8013B4F4: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8013B4F8: addiu       $t2, $t2, -0x4354
    ctx->r10 = ADD32(ctx->r10, -0X4354);
    // 0x8013B4FC: ori         $t4, $t3, 0x1E1
    ctx->r12 = ctx->r11 | 0X1E1;
    // 0x8013B500: sw          $t2, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r10;
    // 0x8013B504: b           L_8013B524
    // 0x8013B508: sw          $t4, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r12;
        goto L_8013B524;
    // 0x8013B508: sw          $t4, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r12;
L_8013B50C:
    // 0x8013B50C: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x8013B510: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8013B514: addiu       $t5, $t5, -0x6B8C
    ctx->r13 = ADD32(ctx->r13, -0X6B8C);
    // 0x8013B518: ori         $t7, $t6, 0x1E1
    ctx->r15 = ctx->r14 | 0X1E1;
    // 0x8013B51C: sw          $t5, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r13;
    // 0x8013B520: sw          $t7, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r15;
L_8013B524:
    // 0x8013B524: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013B528: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8013B52C: addiu       $t8, $zero, 0x12
    ctx->r24 = ADD32(0, 0X12);
    // 0x8013B530: sb          $v0, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r2;
    // 0x8013B534: sb          $t8, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r24;
    // 0x8013B538: beq         $a0, $zero, L_8013B548
    if (ctx->r4 == 0) {
        // 0x8013B53C: sb          $v0, 0x4E($v1)
        MEM_B(0X4E, ctx->r3) = ctx->r2;
            goto L_8013B548;
    }
    // 0x8013B53C: sb          $v0, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r2;
    // 0x8013B540: b           L_8013B554
    // 0x8013B544: sw          $a0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r4;
        goto L_8013B554;
    // 0x8013B544: sw          $a0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r4;
L_8013B548:
    // 0x8013B548: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013B54C: addiu       $t9, $t9, -0x4328
    ctx->r25 = ADD32(ctx->r25, -0X4328);
    // 0x8013B550: sw          $t9, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r25;
L_8013B554:
    // 0x8013B554: lhu         $t1, 0x46($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X46);
    // 0x8013B558: sh          $t1, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r9;
L_8013B55C:
    // 0x8013B55C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013B560:
    // 0x8013B560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013B564: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013B568: jr          $ra
    // 0x8013B56C: nop

    return;
    // 0x8013B56C: nop

;}
RECOMP_FUNC void M7_FUN_8013b570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B570: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013B574: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8013B578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013B57C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013B580: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8013B584: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8013B588: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x8013B58C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8013B590: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013B594: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8013B598: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013B59C: jal         0x8013B268
    // 0x8013B5A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8013B268)(rdram, ctx);
        goto after_0;
    // 0x8013B5A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013B5A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013B5A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013B5AC: jr          $ra
    // 0x8013B5B0: nop

    return;
    // 0x8013B5B0: nop

;}
RECOMP_FUNC void M7_FUN_8013b5b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B5B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8013B5B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013B5BC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8013B5C0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8013B5C4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8013B5C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013B5CC: lhu         $a1, 0x56($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X56);
    // 0x8013B5D0: lhu         $t0, 0x1A($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1A);
    // 0x8013B5D4: lhu         $t7, 0x56($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X56);
    // 0x8013B5D8: slti        $at, $t0, 0x24
    ctx->r1 = SIGNED(ctx->r8) < 0X24 ? 1 : 0;
    // 0x8013B5DC: beq         $at, $zero, L_8013B6CC
    if (ctx->r1 == 0) {
        // 0x8013B5E0: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_8013B6CC;
    }
    // 0x8013B5E0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8013B5E4: slti        $at, $a1, 0x7
    ctx->r1 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x8013B5E8: bnel        $at, $zero, L_8013B5FC
    if (ctx->r1 != 0) {
        // 0x8013B5EC: addiu       $at, $zero, 0x22
        ctx->r1 = ADD32(0, 0X22);
            goto L_8013B5FC;
    }
    goto skip_0;
    // 0x8013B5EC: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    skip_0:
    // 0x8013B5F0: b           L_8013B790
    // 0x8013B5F4: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
        goto L_8013B790;
    // 0x8013B5F4: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x8013B5F8: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
L_8013B5FC:
    // 0x8013B5FC: bne         $a2, $at, L_8013B628
    if (ctx->r6 != ctx->r1) {
        // 0x8013B600: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_8013B628;
    }
    // 0x8013B600: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8013B604: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013B608: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8013B60C: jal         0x801DFE00
    // 0x8013B610: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801DFE00)(rdram, ctx);
        goto after_0;
    // 0x8013B610: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    after_0:
    // 0x8013B614: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8013B618: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8013B61C: beq         $v0, $zero, L_8013B628
    if (ctx->r2 == 0) {
        // 0x8013B620: lhu         $t0, 0x4A($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X4A);
            goto L_8013B628;
    }
    // 0x8013B620: lhu         $t0, 0x4A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4A);
    // 0x8013B624: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
L_8013B628:
    // 0x8013B628: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013B62C: beq         $a1, $at, L_8013B63C
    if (ctx->r5 == ctx->r1) {
        // 0x8013B630: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8013B63C;
    }
    // 0x8013B630: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013B634: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013B638: bne         $a1, $at, L_8013B64C
    if (ctx->r5 != ctx->r1) {
        // 0x8013B63C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8013B64C;
    }
L_8013B63C:
    // 0x8013B63C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013B640: sh          $t7, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r15;
    // 0x8013B644: b           L_8013B660
    // 0x8013B648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8013B660;
    // 0x8013B648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8013B64C:
    // 0x8013B64C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013B650: bne         $a1, $at, L_8013B660
    if (ctx->r5 != ctx->r1) {
        // 0x8013B654: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8013B660;
    }
    // 0x8013B654: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8013B658: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
    // 0x8013B65C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8013B660:
    // 0x8013B660: lhu         $t9, -0x2DB0($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2DB0);
    // 0x8013B664: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8013B668: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x8013B66C: beq         $t9, $zero, L_8013B6AC
    if (ctx->r25 == 0) {
        // 0x8013B670: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_8013B6AC;
    }
    // 0x8013B670: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013B674: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8013B678: addu        $t1, $t1, $a3
    ctx->r9 = ADD32(ctx->r9, ctx->r7);
    // 0x8013B67C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8013B680: addiu       $t2, $t2, -0x2DB0
    ctx->r10 = ADD32(ctx->r10, -0X2DB0);
    // 0x8013B684: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8013B688: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8013B68C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
L_8013B690:
    // 0x8013B690: beql        $a2, $v1, L_8013B6B0
    if (ctx->r6 == ctx->r3) {
        // 0x8013B694: sll         $t3, $a3, 2
        ctx->r11 = S32(ctx->r7 << 2);
            goto L_8013B6B0;
    }
    goto skip_1;
    // 0x8013B694: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    skip_1:
    // 0x8013B698: lhu         $v1, 0xA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA);
    // 0x8013B69C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8013B6A0: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8013B6A4: bne         $v1, $zero, L_8013B690
    if (ctx->r3 != 0) {
        // 0x8013B6A8: nop
    
            goto L_8013B690;
    }
    // 0x8013B6A8: nop

L_8013B6AC:
    // 0x8013B6AC: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
L_8013B6B0:
    // 0x8013B6B0: addu        $t3, $t3, $a3
    ctx->r11 = ADD32(ctx->r11, ctx->r7);
    // 0x8013B6B4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8013B6B8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8013B6BC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8013B6C0: lhu         $t6, -0x2DAE($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2DAE);
    // 0x8013B6C4: b           L_8013B790
    // 0x8013B6C8: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
        goto L_8013B790;
    // 0x8013B6C8: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
L_8013B6CC:
    // 0x8013B6CC: bne         $t7, $zero, L_8013B6DC
    if (ctx->r15 != 0) {
        // 0x8013B6D0: addiu       $at, $zero, 0x26
        ctx->r1 = ADD32(0, 0X26);
            goto L_8013B6DC;
    }
    // 0x8013B6D0: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x8013B6D4: b           L_8013B790
    // 0x8013B6D8: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
        goto L_8013B790;
    // 0x8013B6D8: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
L_8013B6DC:
    // 0x8013B6DC: beq         $a2, $at, L_8013B700
    if (ctx->r6 == ctx->r1) {
        // 0x8013B6E0: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_8013B700;
    }
    // 0x8013B6E0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8013B6E4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8013B6E8: beq         $a2, $at, L_8013B700
    if (ctx->r6 == ctx->r1) {
        // 0x8013B6EC: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_8013B700;
    }
    // 0x8013B6EC: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8013B6F0: beq         $a2, $at, L_8013B700
    if (ctx->r6 == ctx->r1) {
        // 0x8013B6F4: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_8013B700;
    }
    // 0x8013B6F4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8013B6F8: bne         $a2, $at, L_8013B720
    if (ctx->r6 != ctx->r1) {
        // 0x8013B6FC: nop
    
            goto L_8013B720;
    }
    // 0x8013B6FC: nop

L_8013B700:
    // 0x8013B700: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8013B704: jal         0x801DFE00
    // 0x8013B708: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801DFE00)(rdram, ctx);
        goto after_1;
    // 0x8013B708: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    after_1:
    // 0x8013B70C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8013B710: beq         $v0, $zero, L_8013B720
    if (ctx->r2 == 0) {
        // 0x8013B714: lhu         $t0, 0x4A($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X4A);
            goto L_8013B720;
    }
    // 0x8013B714: lhu         $t0, 0x4A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4A);
    // 0x8013B718: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8013B71C: andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
L_8013B720:
    // 0x8013B720: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013B724: lhu         $t8, -0x2C48($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2C48);
    // 0x8013B728: lhu         $t3, 0x56($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X56);
    // 0x8013B72C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013B730: beq         $t8, $zero, L_8013B774
    if (ctx->r24 == 0) {
        // 0x8013B734: sll         $t4, $t3, 1
        ctx->r12 = S32(ctx->r11 << 1);
            goto L_8013B774;
    }
    // 0x8013B734: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8013B738: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x8013B73C: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x8013B740: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013B744: addiu       $t1, $t1, -0x2C48
    ctx->r9 = ADD32(ctx->r9, -0X2C48);
    // 0x8013B748: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8013B74C: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8013B750: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8013B754: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_8013B758:
    // 0x8013B758: beql        $a2, $v1, L_8013B778
    if (ctx->r6 == ctx->r3) {
        // 0x8013B75C: sll         $t2, $a3, 3
        ctx->r10 = S32(ctx->r7 << 3);
            goto L_8013B778;
    }
    goto skip_2;
    // 0x8013B75C: sll         $t2, $a3, 3
    ctx->r10 = S32(ctx->r7 << 3);
    skip_2:
    // 0x8013B760: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
    // 0x8013B764: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8013B768: addiu       $v0, $v0, 0xE
    ctx->r2 = ADD32(ctx->r2, 0XE);
    // 0x8013B76C: bne         $v1, $zero, L_8013B758
    if (ctx->r3 != 0) {
        // 0x8013B770: nop
    
            goto L_8013B758;
    }
    // 0x8013B770: nop

L_8013B774:
    // 0x8013B774: sll         $t2, $a3, 3
    ctx->r10 = S32(ctx->r7 << 3);
L_8013B778:
    // 0x8013B778: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x8013B77C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8013B780: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8013B784: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8013B788: lhu         $t6, -0x2C48($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2C48);
    // 0x8013B78C: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
L_8013B790:
    // 0x8013B790: lhu         $t7, 0x48($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X48);
    // 0x8013B794: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8013B798: beql        $t7, $zero, L_8013B7F8
    if (ctx->r15 == 0) {
        // 0x8013B79C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013B7F8;
    }
    goto skip_3;
    // 0x8013B79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8013B7A0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x8013B7A4: addiu       $t1, $sp, 0x34
    ctx->r9 = ADD32(ctx->r29, 0X34);
    // 0x8013B7A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8013B7AC: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8013B7B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013B7B4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8013B7B8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8013B7BC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8013B7C0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8013B7C4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8013B7C8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8013B7CC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x8013B7D0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8013B7D4: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x8013B7D8: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x8013B7DC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8013B7E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013B7E4: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8013B7E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8013B7EC: jal         0x801DC9C4
    // 0x8013B7F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_2;
    // 0x8013B7F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_2:
    // 0x8013B7F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013B7F8:
    // 0x8013B7F8: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x8013B7FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8013B800: jr          $ra
    // 0x8013B804: nop

    return;
    // 0x8013B804: nop

;}
RECOMP_FUNC void M7_FUN_8013b808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013B80C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013B810: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8013B814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013B818: jal         0x8013C7F8
    // 0x8013B81C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013C7F8)(rdram, ctx);
        goto after_0;
    // 0x8013B81C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8013B820: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013B824: jal         0x8013B5B4
    // 0x8013B828: lhu         $a1, 0x22($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X22);
    LOOKUP_FUNC(0x8013B5B4)(rdram, ctx);
        goto after_1;
    // 0x8013B828: lhu         $a1, 0x22($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X22);
    after_1:
    // 0x8013B82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013B830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013B834: jr          $ra
    // 0x8013B838: nop

    return;
    // 0x8013B838: nop

;}
RECOMP_FUNC void M7_FUN_8013b83c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B83C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8013B840: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8013B844: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8013B848: lw          $v0, 0x38($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X38);
    // 0x8013B84C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013B850: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8013B854: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8013B858: addiu       $t8, $t8, -0x2578
    ctx->r24 = ADD32(ctx->r24, -0X2578);
    // 0x8013B85C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8013B860: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8013B864: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8013B868: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8013B86C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013B870: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8013B874: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8013B878: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8013B87C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8013B880: swc1        $f16, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f16.u32l;
    // 0x8013B884: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x8013B888: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8013B88C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8013B890: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8013B894: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013B898: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8013B89C: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8013B8A0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8013B8A4: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x8013B8A8: lh          $t5, 0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA);
    // 0x8013B8AC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8013B8B0: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8013B8B4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8013B8B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013B8BC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8013B8C0: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8013B8C4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8013B8C8: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x8013B8CC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8013B8D0: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x8013B8D4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8013B8D8: jr          $ra
    // 0x8013B8DC: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
    return;
    // 0x8013B8DC: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013b8e0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013b8e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B8E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013B8E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013B8E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013B8EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013B8F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8013B8F4: lhu         $t6, 0x70($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X70);
    // 0x8013B8F8: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x8013B8FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013B900: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x8013B904: jal         0x8013B19C
    // 0x8013B908: lhu         $a0, 0x36($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X36);
    LOOKUP_FUNC(0x8013B19C)(rdram, ctx);
        goto after_0;
    // 0x8013B908: lhu         $a0, 0x36($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X36);
    after_0:
    // 0x8013B90C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013B910: addiu       $t8, $t8, -0x2BA0
    ctx->r24 = ADD32(ctx->r24, -0X2BA0);
    // 0x8013B914: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x8013B918: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8013B91C: jal         0x801394CC
    // 0x8013B920: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x801394CC)(rdram, ctx);
        goto after_1;
    // 0x8013B920: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_1:
    // 0x8013B924: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8013B928: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013B92C: lbu         $v0, 0x11($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X11);
    // 0x8013B930: beq         $v0, $zero, L_8013B960
    if (ctx->r2 == 0) {
        // 0x8013B934: nop
    
            goto L_8013B960;
    }
    // 0x8013B934: nop

    // 0x8013B938: beq         $v0, $at, L_8013B950
    if (ctx->r2 == ctx->r1) {
        // 0x8013B93C: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8013B950;
    }
    // 0x8013B93C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013B940: bnel        $v0, $t0, L_8013B964
    if (ctx->r2 != ctx->r8) {
        // 0x8013B944: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_8013B964;
    }
    goto skip_0;
    // 0x8013B944: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8013B948: jal         0x80139528
    // 0x8013B94C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    LOOKUP_FUNC(0x80139528)(rdram, ctx);
        goto after_2;
    // 0x8013B94C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_2:
L_8013B950:
    // 0x8013B950: jal         0x80139528
    // 0x8013B954: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80139528)(rdram, ctx);
        goto after_3;
    // 0x8013B954: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x8013B958: b           L_8013B964
    // 0x8013B95C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
        goto L_8013B964;
    // 0x8013B95C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_8013B960:
    // 0x8013B960: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_8013B964:
    // 0x8013B964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B968: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013B96C: lhu         $a3, 0x26($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X26);
    // 0x8013B970: jal         0x80139894
    // 0x8013B974: lw          $a2, 0x18($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X18);
    LOOKUP_FUNC(0x80139894)(rdram, ctx);
        goto after_4;
    // 0x8013B974: lw          $a2, 0x18($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X18);
    after_4:
    // 0x8013B978: beq         $v0, $zero, L_8013B990
    if (ctx->r2 == 0) {
        // 0x8013B97C: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8013B990;
    }
    // 0x8013B97C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013B980: jal         0x80005700
    // 0x8013B984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_5;
    // 0x8013B984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8013B988: b           L_8013BCC8
    // 0x8013B98C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013BCC8;
    // 0x8013B98C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013B990:
    // 0x8013B990: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8013B994: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x8013B998: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013B99C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8013B9A0: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013B9A4: bne         $v0, $zero, L_8013B9D8
    if (ctx->r2 != 0) {
        // 0x8013B9A8: lw          $v1, 0x2C($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X2C);
            goto L_8013B9D8;
    }
    // 0x8013B9A8: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x8013B9AC: lwc1        $f4, 0x198($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X198);
    // 0x8013B9B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013B9B4: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8013B9B8: lwc1        $f6, 0x19C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X19C);
    // 0x8013B9BC: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8013B9C0: lwc1        $f8, 0x1A0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X1A0);
    // 0x8013B9C4: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8013B9C8: lh          $t5, 0x32($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X32);
    // 0x8013B9CC: sh          $t5, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r13;
    // 0x8013B9D0: b           L_8013BA90
    // 0x8013B9D4: sb          $t6, 0xF5($a3)
    MEM_B(0XF5, ctx->r7) = ctx->r14;
        goto L_8013BA90;
    // 0x8013B9D4: sb          $t6, 0xF5($a3)
    MEM_B(0XF5, ctx->r7) = ctx->r14;
L_8013B9D8:
    // 0x8013B9D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013B9DC: bne         $v0, $at, L_8013BA24
    if (ctx->r2 != ctx->r1) {
        // 0x8013B9E0: lui         $a3, 0x801C
        ctx->r7 = S32(0X801C << 16);
            goto L_8013BA24;
    }
    // 0x8013B9E0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013B9E4: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013B9E8: lhu         $t7, 0x2C($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X2C);
    // 0x8013B9EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013B9F0: bnel        $t7, $at, L_8013BA28
    if (ctx->r15 != ctx->r1) {
        // 0x8013B9F4: lbu         $v1, 0x61($s1)
        ctx->r3 = MEM_BU(ctx->r17, 0X61);
            goto L_8013BA28;
    }
    goto skip_1;
    // 0x8013B9F4: lbu         $v1, 0x61($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X61);
    skip_1:
    // 0x8013B9F8: lwc1        $f10, 0x111C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X111C);
    // 0x8013B9FC: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8013BA00: lwc1        $f16, 0x1120($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X1120);
    // 0x8013BA04: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8013BA08: lwc1        $f18, 0x1124($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X1124);
    // 0x8013BA0C: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
    // 0x8013BA10: lwc1        $f4, 0x1128($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X1128);
    // 0x8013BA14: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8013BA18: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8013BA1C: b           L_8013BA90
    // 0x8013BA20: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
        goto L_8013BA90;
    // 0x8013BA20: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
L_8013BA24:
    // 0x8013BA24: lbu         $v1, 0x61($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X61);
L_8013BA28:
    // 0x8013BA28: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013BA2C: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013BA30: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x8013BA34: bne         $t0, $v1, L_8013BA60
    if (ctx->r8 != ctx->r3) {
        // 0x8013BA38: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8013BA60;
    }
    // 0x8013BA38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013BA3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BA40: jal         0x8012636C
    // 0x8013BA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_6;
    // 0x8013BA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8013BA48: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013BA4C: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013BA50: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013BA54: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x8013BA58: b           L_8013BA84
    // 0x8013BA5C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
        goto L_8013BA84;
    // 0x8013BA5C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_8013BA60:
    // 0x8013BA60: bne         $v1, $at, L_8013BA84
    if (ctx->r3 != ctx->r1) {
        // 0x8013BA64: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013BA84;
    }
    // 0x8013BA64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BA68: jal         0x8013B83C
    // 0x8013BA6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013B83C)(rdram, ctx);
        goto after_7;
    // 0x8013BA6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8013BA70: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013BA74: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013BA78: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013BA7C: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x8013BA80: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_8013BA84:
    // 0x8013BA84: bne         $t0, $v0, L_8013BA90
    if (ctx->r8 != ctx->r2) {
        // 0x8013BA88: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8013BA90;
    }
    // 0x8013BA88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013BA8C: sb          $t2, 0xF5($a3)
    MEM_B(0XF5, ctx->r7) = ctx->r10;
L_8013BA90:
    // 0x8013BA90: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8013BA94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BA98: lw          $v0, 0x14($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X14);
    // 0x8013BA9C: beql        $v0, $zero, L_8013BACC
    if (ctx->r2 == 0) {
        // 0x8013BAA0: lhu         $v0, 0xE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XE);
            goto L_8013BACC;
    }
    goto skip_2;
    // 0x8013BAA0: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
    skip_2:
    // 0x8013BAA4: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x8013BAA8: jal         0x8012D844
    // 0x8013BAAC: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_8;
    // 0x8013BAAC: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    after_8:
    // 0x8013BAB0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013BAB4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013BAB8: sh          $t4, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r12;
    // 0x8013BABC: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013BAC0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013BAC4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8013BAC8: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
L_8013BACC:
    // 0x8013BACC: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x8013BAD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BAD4: bnel        $v0, $at, L_8013BB10
    if (ctx->r2 != ctx->r1) {
        // 0x8013BAD8: addiu       $at, $zero, 0x141
        ctx->r1 = ADD32(0, 0X141);
            goto L_8013BB10;
    }
    goto skip_3;
    // 0x8013BAD8: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
    skip_3:
    // 0x8013BADC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013BAE0: addiu       $v0, $v0, -0x2DBC
    ctx->r2 = ADD32(ctx->r2, -0X2DBC);
    // 0x8013BAE4: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x8013BAE8: jal         0x8012D844
    // 0x8013BAEC: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_9;
    // 0x8013BAEC: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    after_9:
    // 0x8013BAF0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8013BAF4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013BAF8: sh          $t5, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r13;
    // 0x8013BAFC: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013BB00: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013BB04: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8013BB08: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
    // 0x8013BB0C: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
L_8013BB10:
    // 0x8013BB10: beq         $v0, $at, L_8013BB20
    if (ctx->r2 == ctx->r1) {
        // 0x8013BB14: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013BB20;
    }
    // 0x8013BB14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BB18: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x8013BB1C: bne         $v0, $at, L_8013BB4C
    if (ctx->r2 != ctx->r1) {
        // 0x8013BB20: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8013BB4C;
    }
L_8013BB20:
    // 0x8013BB20: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013BB24: addiu       $v0, $v0, -0x2E2C
    ctx->r2 = ADD32(ctx->r2, -0X2E2C);
    // 0x8013BB28: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x8013BB2C: jal         0x8012D894
    // 0x8013BB30: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_10;
    // 0x8013BB30: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    after_10:
    // 0x8013BB34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013BB38: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013BB3C: sh          $t6, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r14;
    // 0x8013BB40: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013BB44: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013BB48: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_8013BB4C:
    // 0x8013BB4C: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x8013BB50: beql        $v0, $zero, L_8013BB64
    if (ctx->r2 == 0) {
        // 0x8013BB54: lw          $t7, 0xDC($a3)
        ctx->r15 = MEM_W(ctx->r7, 0XDC);
            goto L_8013BB64;
    }
    goto skip_4;
    // 0x8013BB54: lw          $t7, 0xDC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XDC);
    skip_4:
    // 0x8013BB58: bne         $t0, $v0, L_8013BB78
    if (ctx->r8 != ctx->r2) {
        // 0x8013BB5C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8013BB78;
    }
    // 0x8013BB5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013BB60: lw          $t7, 0xDC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XDC);
L_8013BB64:
    // 0x8013BB64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013BB68: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x8013BB6C: sb          $t9, 0x230($a3)
    MEM_B(0X230, ctx->r7) = ctx->r25;
    // 0x8013BB70: b           L_8013BBB0
    // 0x8013BB74: sw          $t8, 0xE0($a3)
    MEM_W(0XE0, ctx->r7) = ctx->r24;
        goto L_8013BBB0;
    // 0x8013BB74: sw          $t8, 0xE0($a3)
    MEM_W(0XE0, ctx->r7) = ctx->r24;
L_8013BB78:
    // 0x8013BB78: beq         $v0, $at, L_8013BB8C
    if (ctx->r2 == ctx->r1) {
        // 0x8013BB7C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8013BB8C;
    }
    // 0x8013BB7C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013BB80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013BB84: bnel        $v0, $at, L_8013BBB4
    if (ctx->r2 != ctx->r1) {
        // 0x8013BB88: lhu         $t5, 0xC($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0XC);
            goto L_8013BBB4;
    }
    goto skip_5;
    // 0x8013BB88: lhu         $t5, 0xC($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XC);
    skip_5:
L_8013BB8C:
    // 0x8013BB8C: lw          $t2, 0xEC($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XEC);
    // 0x8013BB90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BB94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013BB98: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x8013BB9C: sb          $t4, 0x231($a3)
    MEM_B(0X231, ctx->r7) = ctx->r12;
    // 0x8013BBA0: jal         0x8012B1E4
    // 0x8013BBA4: sw          $t3, 0xF0($a3)
    MEM_W(0XF0, ctx->r7) = ctx->r11;
    LOOKUP_FUNC(0x8012B1E4)(rdram, ctx);
        goto after_11;
    // 0x8013BBA4: sw          $t3, 0xF0($a3)
    MEM_W(0XF0, ctx->r7) = ctx->r11;
    after_11:
    // 0x8013BBA8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013BBAC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_8013BBB0:
    // 0x8013BBB0: lhu         $t5, 0xC($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XC);
L_8013BBB4:
    // 0x8013BBB4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8013BBB8: addiu       $a1, $a1, -0x2440
    ctx->r5 = ADD32(ctx->r5, -0X2440);
    // 0x8013BBBC: blez        $t5, L_8013BC3C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8013BBC0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8013BC3C;
    }
    // 0x8013BBC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013BBC4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
L_8013BBC8:
    // 0x8013BBC8: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x8013BBCC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8013BBD0: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x8013BBD4: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8013BBD8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8013BBDC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8013BBE0: sh          $t9, 0x6C($t3)
    MEM_H(0X6C, ctx->r11) = ctx->r25;
    // 0x8013BBE4: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x8013BBE8: beql        $v0, $zero, L_8013BBFC
    if (ctx->r2 == 0) {
        // 0x8013BBEC: lw          $t4, 0x0($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X0);
            goto L_8013BBFC;
    }
    goto skip_6;
    // 0x8013BBEC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    skip_6:
    // 0x8013BBF0: bnel        $t0, $v0, L_8013BC14
    if (ctx->r8 != ctx->r2) {
        // 0x8013BBF4: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_8013BC14;
    }
    goto skip_7;
    // 0x8013BBF4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_7:
    // 0x8013BBF8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
L_8013BBFC:
    // 0x8013BBFC: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x8013BC00: lhu         $t5, 0x6C($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X6C);
    // 0x8013BC04: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x8013BC08: b           L_8013BC24
    // 0x8013BC0C: sh          $t6, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = ctx->r14;
        goto L_8013BC24;
    // 0x8013BC0C: sh          $t6, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = ctx->r14;
    // 0x8013BC10: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_8013BC14:
    // 0x8013BC14: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8013BC18: lhu         $t8, 0x6C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6C);
    // 0x8013BC1C: ori         $t2, $t8, 0x4
    ctx->r10 = ctx->r24 | 0X4;
    // 0x8013BC20: sh          $t2, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = ctx->r10;
L_8013BC24:
    // 0x8013BC24: lhu         $t9, 0xC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC);
    // 0x8013BC28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8013BC2C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013BC30: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8013BC34: bnel        $at, $zero, L_8013BBC8
    if (ctx->r1 != 0) {
        // 0x8013BC38: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8013BBC8;
    }
    goto skip_8;
    // 0x8013BC38: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    skip_8:
L_8013BC3C:
    // 0x8013BC3C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013BC40: sh          $zero, 0x70($s1)
    MEM_H(0X70, ctx->r17) = 0;
    // 0x8013BC44: sb          $t3, 0x63($s1)
    MEM_B(0X63, ctx->r17) = ctx->r11;
    // 0x8013BC48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BC4C: jal         0x800058DC
    // 0x8013BC50: lw          $a1, 0x64($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x8013BC50: lw          $a1, 0x64($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X64);
    after_12:
    // 0x8013BC54: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013BC58: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013BC5C: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
    // 0x8013BC60: lhu         $v0, 0x2C($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2C);
    // 0x8013BC64: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013BC68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BC6C: beq         $v0, $at, L_8013BC98
    if (ctx->r2 == ctx->r1) {
        // 0x8013BC70: lui         $a1, 0x801E
        ctx->r5 = S32(0X801E << 16);
            goto L_8013BC98;
    }
    // 0x8013BC70: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8013BC74: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013BC78: beq         $v0, $at, L_8013BC98
    if (ctx->r2 == ctx->r1) {
        // 0x8013BC7C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8013BC98;
    }
    // 0x8013BC7C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013BC80: beq         $v0, $at, L_8013BC98
    if (ctx->r2 == ctx->r1) {
        // 0x8013BC84: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8013BC98;
    }
    // 0x8013BC84: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8013BC88: beq         $v0, $at, L_8013BC98
    if (ctx->r2 == ctx->r1) {
        // 0x8013BC8C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8013BC98;
    }
    // 0x8013BC8C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013BC90: bnel        $v0, $at, L_8013BCA8
    if (ctx->r2 != ctx->r1) {
        // 0x8013BC94: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013BCA8;
    }
    goto skip_9;
    // 0x8013BC94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_9:
L_8013BC98:
    // 0x8013BC98: jal         0x80005670
    // 0x8013BC9C: addiu       $a1, $a1, 0x1460
    ctx->r5 = ADD32(ctx->r5, 0X1460);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_13;
    // 0x8013BC9C: addiu       $a1, $a1, 0x1460
    ctx->r5 = ADD32(ctx->r5, 0X1460);
    after_13:
    // 0x8013BCA0: sw          $v0, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r2;
    // 0x8013BCA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8013BCA8:
    // 0x8013BCA8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8013BCAC: jal         0x8013C7F8
    // 0x8013BCB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8013C7F8)(rdram, ctx);
        goto after_14;
    // 0x8013BCB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x8013BCB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013BCB8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8013BCBC: jal         0x8013C6FC
    // 0x8013BCC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013C6FC)(rdram, ctx);
        goto after_15;
    // 0x8013BCC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x8013BCC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013BCC8:
    // 0x8013BCC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8013BCCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013BCD0: jr          $ra
    // 0x8013BCD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8013BCD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013bcd8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013bcd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BCD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013BCDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013BCE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013BCE4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8013BCE8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8013BCEC: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8013BCF0: lhu         $t7, 0x18($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18);
    // 0x8013BCF4: sb          $t6, 0x9D($v0)
    MEM_B(0X9D, ctx->r2) = ctx->r14;
    // 0x8013BCF8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013BCFC: andi        $t8, $t7, 0x3000
    ctx->r24 = ctx->r15 & 0X3000;
    // 0x8013BD00: bne         $t8, $at, L_8013BD40
    if (ctx->r24 != ctx->r1) {
        // 0x8013BD04: lui         $a1, 0x8014
        ctx->r5 = S32(0X8014 << 16);
            goto L_8013BD40;
    }
    // 0x8013BD04: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013BD08: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013BD0C: lw          $t9, 0xDC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XDC);
    // 0x8013BD10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013BD14: addiu       $t1, $zero, 0xE7F
    ctx->r9 = ADD32(0, 0XE7F);
    // 0x8013BD18: bne         $a0, $t9, L_8013BD30
    if (ctx->r4 != ctx->r25) {
        // 0x8013BD1C: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_8013BD30;
    }
    // 0x8013BD1C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8013BD20: sb          $zero, 0x3F($a0)
    MEM_B(0X3F, ctx->r4) = 0;
    // 0x8013BD24: sb          $t0, 0x4F($a0)
    MEM_B(0X4F, ctx->r4) = ctx->r8;
    // 0x8013BD28: sw          $t1, 0xEFC($v0)
    MEM_W(0XEFC, ctx->r2) = ctx->r9;
    // 0x8013BD2C: sw          $t1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r9;
L_8013BD30:
    // 0x8013BD30: jal         0x800058DC
    // 0x8013BD34: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8013BD34: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    after_0:
    // 0x8013BD38: b           L_8013BD4C
    // 0x8013BD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013BD4C;
    // 0x8013BD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013BD40:
    // 0x8013BD40: jal         0x800058DC
    // 0x8013BD44: addiu       $a1, $a1, -0x522C
    ctx->r5 = ADD32(ctx->r5, -0X522C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8013BD44: addiu       $a1, $a1, -0x522C
    ctx->r5 = ADD32(ctx->r5, -0X522C);
    after_1:
    // 0x8013BD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013BD4C:
    // 0x8013BD4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013BD50: jr          $ra
    // 0x8013BD54: nop

    return;
    // 0x8013BD54: nop

;}
RECOMP_FUNC void M7_FUN_8013bd58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BD58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013BD5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013BD60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013BD64: jal         0x8013B208
    // 0x8013BD68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013B208)(rdram, ctx);
        goto after_0;
    // 0x8013BD68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8013BD6C: jal         0x80005700
    // 0x8013BD70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x8013BD70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013BD74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013BD78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013BD7C: jr          $ra
    // 0x8013BD80: nop

    return;
    // 0x8013BD80: nop

;}
RECOMP_FUNC void M7_FUN_8013bd84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BD84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013BD88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013BD8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013BD90: jal         0x8013B19C
    // 0x8013BD94: lhu         $a0, 0x36($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X36);
    LOOKUP_FUNC(0x8013B19C)(rdram, ctx);
        goto after_0;
    // 0x8013BD94: lhu         $a0, 0x36($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X36);
    after_0:
    // 0x8013BD98: sll         $t6, $v0, 5
    ctx->r14 = S32(ctx->r2 << 5);
    // 0x8013BD9C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8013BDA0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8013BDA4: lw          $t7, -0x2B88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B88);
    // 0x8013BDA8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013BDAC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013BDB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013BDB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8013BDB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013BDBC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8013BDC0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013BDC4: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8013BDC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013BDCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013BDD0: jr          $ra
    // 0x8013BDD4: nop

    return;
    // 0x8013BDD4: nop

;}
RECOMP_FUNC void M7_FUN_8013bdd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BDD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013BDDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013BDE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013BDE4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8013BDE8: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8013BDEC: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8013BDF0: sb          $v0, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = ctx->r2;
    // 0x8013BDF4: sb          $t6, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = ctx->r14;
    // 0x8013BDF8: sb          $v0, 0x4E($a0)
    MEM_B(0X4E, ctx->r4) = ctx->r2;
    // 0x8013BDFC: lhu         $a1, 0x36($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X36);
    // 0x8013BE00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013BE04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013BE08: jal         0x8013B570
    // 0x8013BE0C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x8013BE0C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x8013BE10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013BE14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013BE18: jr          $ra
    // 0x8013BE1C: nop

    return;
    // 0x8013BE1C: nop

;}
RECOMP_FUNC void M7_FUN_8013be20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BE20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013BE24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013BE28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013BE2C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8013BE30: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8013BE34: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8013BE38: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013BE3C: sb          $v1, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = ctx->r3;
    // 0x8013BE40: sb          $t6, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = ctx->r14;
    // 0x8013BE44: sb          $v1, 0x4E($a0)
    MEM_B(0X4E, ctx->r4) = ctx->r3;
    // 0x8013BE48: sb          $t7, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r15;
    // 0x8013BE4C: sb          $t8, 0x4F($a0)
    MEM_B(0X4F, ctx->r4) = ctx->r24;
    // 0x8013BE50: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013BE54: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // 0x8013BE58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013BE5C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013BE60: beq         $v0, $at, L_8013BE70
    if (ctx->r2 == ctx->r1) {
        // 0x8013BE64: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8013BE70;
    }
    // 0x8013BE64: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013BE68: bnel        $v0, $at, L_8013BE7C
    if (ctx->r2 != ctx->r1) {
        // 0x8013BE6C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8013BE7C;
    }
    goto skip_0;
    // 0x8013BE6C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
L_8013BE70:
    // 0x8013BE70: b           L_8013BE7C
    // 0x8013BE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013BE7C;
    // 0x8013BE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013BE78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8013BE7C:
    // 0x8013BE7C: lhu         $a1, 0x36($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X36);
    // 0x8013BE80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013BE84: jal         0x8013B570
    // 0x8013BE88: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x8013BE88: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    after_0:
    // 0x8013BE8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013BE90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013BE94: jr          $ra
    // 0x8013BE98: nop

    return;
    // 0x8013BE98: nop

;}
RECOMP_FUNC void M7_FUN_8013be9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BE9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013BEA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013BEA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013BEA8: lw          $t0, 0x54($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X54);
    // 0x8013BEAC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8013BEB0: addiu       $t6, $zero, 0x3E0
    ctx->r14 = ADD32(0, 0X3E0);
    // 0x8013BEB4: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x8013BEB8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8013BEBC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013BEC0: ori         $t1, $t0, 0xE1
    ctx->r9 = ctx->r8 | 0XE1;
    // 0x8013BEC4: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
    // 0x8013BEC8: sb          $v0, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = ctx->r2;
    // 0x8013BECC: sb          $t7, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = ctx->r15;
    // 0x8013BED0: sb          $v0, 0x4E($a0)
    MEM_B(0X4E, ctx->r4) = ctx->r2;
    // 0x8013BED4: sb          $t8, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r24;
    // 0x8013BED8: sb          $t9, 0x4F($a0)
    MEM_B(0X4F, ctx->r4) = ctx->r25;
    // 0x8013BEDC: sw          $t1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r9;
    // 0x8013BEE0: lhu         $a1, 0x36($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X36);
    // 0x8013BEE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013BEE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013BEEC: jal         0x8013B570
    // 0x8013BEF0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x8013BEF0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x8013BEF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013BEF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013BEFC: jr          $ra
    // 0x8013BF00: nop

    return;
    // 0x8013BF00: nop

;}
RECOMP_FUNC void M7_FUN_8013bf04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BF04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013BF08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013BF0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013BF10: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8013BF14: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8013BF18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013BF1C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013BF20: sb          $t6, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = ctx->r14;
    // 0x8013BF24: sb          $t7, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r15;
    // 0x8013BF28: sb          $t8, 0x4F($a0)
    MEM_B(0X4F, ctx->r4) = ctx->r24;
    // 0x8013BF2C: addiu       $t9, $t9, -0x40AC
    ctx->r25 = ADD32(ctx->r25, -0X40AC);
    // 0x8013BF30: lhu         $a1, 0x36($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X36);
    // 0x8013BF34: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013BF38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013BF3C: jal         0x8013B570
    // 0x8013BF40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x8013BF40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8013BF44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013BF48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013BF4C: jr          $ra
    // 0x8013BF50: nop

    return;
    // 0x8013BF50: nop

;}
RECOMP_FUNC void M7_FUN_8013bf54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BF54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013BF58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013BF5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013BF60: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013BF64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013BF68: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013BF6C: sb          $zero, 0x3F($a0)
    MEM_B(0X3F, ctx->r4) = 0;
    // 0x8013BF70: sb          $t6, 0x4F($a0)
    MEM_B(0X4F, ctx->r4) = ctx->r14;
    // 0x8013BF74: addiu       $t7, $zero, 0xE7F
    ctx->r15 = ADD32(0, 0XE7F);
    // 0x8013BF78: sw          $t7, 0xEFC($v0)
    MEM_W(0XEFC, ctx->r2) = ctx->r15;
    // 0x8013BF7C: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x8013BF80: sw          $t7, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r15;
    // 0x8013BF84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013BF88: ori         $t0, $t9, 0x3E0
    ctx->r8 = ctx->r25 | 0X3E0;
    // 0x8013BF8C: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x8013BF90: jal         0x801C4A5C
    // 0x8013BF94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_0;
    // 0x8013BF94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013BF98: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8013BF9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013BFA0: jal         0x800058DC
    // 0x8013BFA4: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8013BFA4: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    after_1:
    // 0x8013BFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013BFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013BFB0: jr          $ra
    // 0x8013BFB4: nop

    return;
    // 0x8013BFB4: nop

;}
RECOMP_FUNC void M7_FUN_8013bfb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BFB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013BFBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013BFC0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013BFC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013BFC8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8013BFCC: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x8013BFD0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8013BFD4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8013BFD8: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x8013BFDC: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x8013BFE0: lhu         $v0, 0x9E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X9E);
    // 0x8013BFE4: beq         $v0, $zero, L_8013C010
    if (ctx->r2 == 0) {
        // 0x8013BFE8: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8013C010;
    }
    // 0x8013BFE8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8013BFEC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8013BFF0: bne         $t9, $zero, L_8013C0BC
    if (ctx->r25 != 0) {
        // 0x8013BFF4: sh          $t8, 0x9E($s0)
        MEM_H(0X9E, ctx->r16) = ctx->r24;
            goto L_8013C0BC;
    }
    // 0x8013BFF4: sh          $t8, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r24;
    // 0x8013BFF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013BFFC: lhu         $a1, 0x0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X0);
    // 0x8013C000: jal         0x8012D844
    // 0x8013C004: lhu         $a2, 0x4($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X4);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x8013C004: lhu         $a2, 0x4($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X4);
    after_0:
    // 0x8013C008: b           L_8013C0C0
    // 0x8013C00C: lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X2A);
        goto L_8013C0C0;
    // 0x8013C00C: lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X2A);
L_8013C010:
    // 0x8013C010: lhu         $t0, -0x43E0($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X43E0);
    // 0x8013C014: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8013C018: bnel        $t1, $zero, L_8013C174
    if (ctx->r9 != 0) {
        // 0x8013C01C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C174;
    }
    goto skip_0;
    // 0x8013C01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013C020: jal         0x8012C6B4
    // 0x8013C024: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x8013C024: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    after_1:
    // 0x8013C028: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8013C02C: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x8013C030: slti        $at, $v0, 0x119
    ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
    // 0x8013C034: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x8013C038: beql        $t2, $zero, L_8013C074
    if (ctx->r10 == 0) {
        // 0x8013C03C: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_8013C074;
    }
    goto skip_1;
    // 0x8013C03C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    skip_1:
    // 0x8013C040: bne         $at, $zero, L_8013C070
    if (ctx->r1 != 0) {
        // 0x8013C044: slti        $at, $v0, 0x12D
        ctx->r1 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
            goto L_8013C070;
    }
    // 0x8013C044: slti        $at, $v0, 0x12D
    ctx->r1 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x8013C048: beq         $at, $zero, L_8013C070
    if (ctx->r1 == 0) {
        // 0x8013C04C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8013C070;
    }
    // 0x8013C04C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013C050: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x8013C054: jal         0x8012D844
    // 0x8013C058: lhu         $a2, 0x6($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X6);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x8013C058: lhu         $a2, 0x6($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X6);
    after_2:
    // 0x8013C05C: jal         0x8012C6B4
    // 0x8013C060: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x8013C060: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x8013C064: addiu       $t3, $v0, 0x5
    ctx->r11 = ADD32(ctx->r2, 0X5);
    // 0x8013C068: sh          $t3, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r11;
    // 0x8013C06C: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
L_8013C070:
    // 0x8013C070: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
L_8013C074:
    // 0x8013C074: beq         $v0, $zero, L_8013C0BC
    if (ctx->r2 == 0) {
        // 0x8013C078: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8013C0BC;
    }
    // 0x8013C078: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013C07C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8013C080: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8013C084: mflo        $v1
    ctx->r3 = lo;
    // 0x8013C088: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8013C08C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8013C090: beq         $at, $zero, L_8013C0BC
    if (ctx->r1 == 0) {
        // 0x8013C094: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8013C0BC;
    }
    // 0x8013C094: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013C098: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x8013C09C: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x8013C0A0: lhu         $a2, 0x8($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X8);
    // 0x8013C0A4: jal         0x8012D844
    // 0x8013C0A8: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x8013C0A8: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    after_4:
    // 0x8013C0AC: jal         0x8012C6B4
    // 0x8013C0B0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x8013C0B0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x8013C0B4: addiu       $t6, $v0, 0x5
    ctx->r14 = ADD32(ctx->r2, 0X5);
    // 0x8013C0B8: sh          $t6, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r14;
L_8013C0BC:
    // 0x8013C0BC: lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X2A);
L_8013C0C0:
    // 0x8013C0C0: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
    // 0x8013C0C4: beq         $v0, $at, L_8013C0D4
    if (ctx->r2 == ctx->r1) {
        // 0x8013C0C8: addiu       $at, $zero, 0x142
        ctx->r1 = ADD32(0, 0X142);
            goto L_8013C0D4;
    }
    // 0x8013C0C8: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x8013C0CC: bnel        $v0, $at, L_8013C174
    if (ctx->r2 != ctx->r1) {
        // 0x8013C0D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C174;
    }
    goto skip_2;
    // 0x8013C0D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_8013C0D4:
    // 0x8013C0D4: lhu         $v0, 0xA0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA0);
    // 0x8013C0D8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8013C0DC: beq         $v0, $zero, L_8013C110
    if (ctx->r2 == 0) {
        // 0x8013C0E0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8013C110;
    }
    // 0x8013C0E0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8013C0E4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8013C0E8: bne         $t8, $zero, L_8013C170
    if (ctx->r24 != 0) {
        // 0x8013C0EC: sh          $t7, 0xA0($s0)
        MEM_H(0XA0, ctx->r16) = ctx->r15;
            goto L_8013C170;
    }
    // 0x8013C0EC: sh          $t7, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r15;
    // 0x8013C0F0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013C0F4: addiu       $v0, $v0, -0x2E2C
    ctx->r2 = ADD32(ctx->r2, -0X2E2C);
    // 0x8013C0F8: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x8013C0FC: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x8013C100: jal         0x8012D894
    // 0x8013C104: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_6;
    // 0x8013C104: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x8013C108: b           L_8013C174
    // 0x8013C10C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013C174;
    // 0x8013C10C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013C110:
    // 0x8013C110: lhu         $t9, -0x43E0($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X43E0);
    // 0x8013C114: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8013C118: beql        $t0, $zero, L_8013C174
    if (ctx->r8 == 0) {
        // 0x8013C11C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C174;
    }
    goto skip_3;
    // 0x8013C11C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8013C120: jal         0x8012C6B4
    // 0x8013C124: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x8013C124: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    after_7:
    // 0x8013C128: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x8013C12C: beq         $at, $zero, L_8013C170
    if (ctx->r1 == 0) {
        // 0x8013C130: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8013C170;
    }
    // 0x8013C130: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8013C134: lhu         $a0, -0x2E2A($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2E2A);
    // 0x8013C138: jal         0x8012C6B4
    // 0x8013C13C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x8013C13C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_8:
    // 0x8013C140: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x8013C144: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8013C148: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8013C14C: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8013C150: lhu         $a2, -0x2E24($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X2E24);
    // 0x8013C154: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013C158: jal         0x8012D894
    // 0x8013C15C: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_9;
    // 0x8013C15C: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    after_9:
    // 0x8013C160: jal         0x8012C6B4
    // 0x8013C164: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x8013C164: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_10:
    // 0x8013C168: addiu       $t3, $v0, 0x5
    ctx->r11 = ADD32(ctx->r2, 0X5);
    // 0x8013C16C: sh          $t3, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r11;
L_8013C170:
    // 0x8013C170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013C174:
    // 0x8013C174: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8013C178: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013C17C: jr          $ra
    // 0x8013C180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013C180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013c184(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013c184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C184: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013C188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C18C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013C190: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x8013C194: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8013C198: lhu         $v0, 0x9E($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X9E);
    // 0x8013C19C: beq         $v0, $zero, L_8013C1C8
    if (ctx->r2 == 0) {
        // 0x8013C1A0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8013C1C8;
    }
    // 0x8013C1A0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8013C1A4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8013C1A8: bne         $t8, $zero, L_8013C234
    if (ctx->r24 != 0) {
        // 0x8013C1AC: sh          $t7, 0x9E($v1)
        MEM_H(0X9E, ctx->r3) = ctx->r15;
            goto L_8013C234;
    }
    // 0x8013C1AC: sh          $t7, 0x9E($v1)
    MEM_H(0X9E, ctx->r3) = ctx->r15;
    // 0x8013C1B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013C1B4: lhu         $a1, 0x0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X0);
    // 0x8013C1B8: jal         0x8012D844
    // 0x8013C1BC: lhu         $a2, 0x4($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X4);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x8013C1BC: lhu         $a2, 0x4($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X4);
    after_0:
    // 0x8013C1C0: b           L_8013C238
    // 0x8013C1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013C238;
    // 0x8013C1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013C1C8:
    // 0x8013C1C8: lhu         $t9, 0x2($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X2);
    // 0x8013C1CC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8013C1D0: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x8013C1D4: beql        $t0, $zero, L_8013C238
    if (ctx->r8 == 0) {
        // 0x8013C1D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013C238;
    }
    goto skip_0;
    // 0x8013C1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013C1DC: lhu         $t1, -0x43E0($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X43E0);
    // 0x8013C1E0: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    // 0x8013C1E4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8013C1E8: beql        $t2, $zero, L_8013C238
    if (ctx->r10 == 0) {
        // 0x8013C1EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013C238;
    }
    goto skip_1;
    // 0x8013C1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013C1F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8013C1F4: jal         0x8012C6B4
    // 0x8013C1F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x8013C1F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x8013C1FC: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8013C200: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C204: beq         $at, $zero, L_8013C234
    if (ctx->r1 == 0) {
        // 0x8013C208: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_8013C234;
    }
    // 0x8013C208: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8013C20C: lhu         $a1, 0x0($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X0);
    // 0x8013C210: lhu         $a2, 0x6($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X6);
    // 0x8013C214: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8013C218: jal         0x8012D844
    // 0x8013C21C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x8013C21C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8013C220: jal         0x8012C6B4
    // 0x8013C224: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x8013C224: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x8013C228: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C22C: addiu       $t3, $v0, 0x5
    ctx->r11 = ADD32(ctx->r2, 0X5);
    // 0x8013C230: sh          $t3, 0x9E($v1)
    MEM_H(0X9E, ctx->r3) = ctx->r11;
L_8013C234:
    // 0x8013C234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013C238:
    // 0x8013C238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013C23C: jr          $ra
    // 0x8013C240: nop

    return;
    // 0x8013C240: nop

;}
RECOMP_FUNC void M7_FUN_8013c244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C244: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013c248(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013c248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C248: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8013C24C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013C250: addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    // 0x8013C254: addiu       $t6, $t6, -0x240C
    ctx->r14 = ADD32(ctx->r14, -0X240C);
    // 0x8013C258: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x8013C25C: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x8013C260: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
L_8013C264:
    // 0x8013C264: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013C268: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013C26C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013C270: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8013C274: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8013C278: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8013C27C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013C280: bne         $t6, $t0, L_8013C264
    if (ctx->r14 != ctx->r8) {
        // 0x8013C284: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8013C264;
    }
    // 0x8013C284: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013C288: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013C28C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8013C290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013C294: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8013C298: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013C29C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8013C2A0: lhu         $a1, -0x40C2($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X40C2);
    // 0x8013C2A4: bne         $a1, $at, L_8013C2DC
    if (ctx->r5 != ctx->r1) {
        // 0x8013C2A8: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_8013C2DC;
    }
    // 0x8013C2A8: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8013C2AC: beq         $v1, $at, L_8013C2CC
    if (ctx->r3 == ctx->r1) {
        // 0x8013C2B0: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_8013C2CC;
    }
    // 0x8013C2B0: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x8013C2B4: beq         $v1, $at, L_8013C2CC
    if (ctx->r3 == ctx->r1) {
        // 0x8013C2B8: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_8013C2CC;
    }
    // 0x8013C2B8: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8013C2BC: beq         $v1, $at, L_8013C2CC
    if (ctx->r3 == ctx->r1) {
        // 0x8013C2C0: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_8013C2CC;
    }
    // 0x8013C2C0: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8013C2C4: bne         $v1, $at, L_8013C2D4
    if (ctx->r3 != ctx->r1) {
        // 0x8013C2C8: nop
    
            goto L_8013C2D4;
    }
    // 0x8013C2C8: nop

L_8013C2CC:
    // 0x8013C2CC: b           L_8013C3C4
    // 0x8013C2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013C3C4;
    // 0x8013C2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013C2D4:
    // 0x8013C2D4: b           L_8013C3C4
    // 0x8013C2D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013C3C4;
    // 0x8013C2D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013C2DC:
    // 0x8013C2DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013C2E0: bne         $a1, $at, L_8013C308
    if (ctx->r5 != ctx->r1) {
        // 0x8013C2E4: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_8013C308;
    }
    // 0x8013C2E4: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x8013C2E8: beq         $v1, $at, L_8013C2F8
    if (ctx->r3 == ctx->r1) {
        // 0x8013C2EC: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_8013C2F8;
    }
    // 0x8013C2EC: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x8013C2F0: bne         $v1, $at, L_8013C300
    if (ctx->r3 != ctx->r1) {
        // 0x8013C2F4: nop
    
            goto L_8013C300;
    }
    // 0x8013C2F4: nop

L_8013C2F8:
    // 0x8013C2F8: b           L_8013C3C4
    // 0x8013C2FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013C3C4;
    // 0x8013C2FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013C300:
    // 0x8013C300: b           L_8013C3C4
    // 0x8013C304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013C3C4;
    // 0x8013C304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013C308:
    // 0x8013C308: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8013C30C: bne         $a1, $at, L_8013C334
    if (ctx->r5 != ctx->r1) {
        // 0x8013C310: addiu       $at, $zero, 0x33
        ctx->r1 = ADD32(0, 0X33);
            goto L_8013C334;
    }
    // 0x8013C310: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8013C314: beq         $v1, $at, L_8013C324
    if (ctx->r3 == ctx->r1) {
        // 0x8013C318: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_8013C324;
    }
    // 0x8013C318: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8013C31C: bne         $v1, $at, L_8013C32C
    if (ctx->r3 != ctx->r1) {
        // 0x8013C320: nop
    
            goto L_8013C32C;
    }
    // 0x8013C320: nop

L_8013C324:
    // 0x8013C324: b           L_8013C3C4
    // 0x8013C328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013C3C4;
    // 0x8013C328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013C32C:
    // 0x8013C32C: b           L_8013C3C4
    // 0x8013C330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013C3C4;
    // 0x8013C330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013C334:
    // 0x8013C334: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C338: bne         $a1, $at, L_8013C364
    if (ctx->r5 != ctx->r1) {
        // 0x8013C33C: lhu         $t1, 0x14($sp)
        ctx->r9 = MEM_HU(ctx->r29, 0X14);
            goto L_8013C364;
    }
    // 0x8013C33C: lhu         $t1, 0x14($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X14);
    // 0x8013C340: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
    // 0x8013C344: beq         $v1, $at, L_8013C354
    if (ctx->r3 == ctx->r1) {
        // 0x8013C348: addiu       $at, $zero, 0x142
        ctx->r1 = ADD32(0, 0X142);
            goto L_8013C354;
    }
    // 0x8013C348: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x8013C34C: bne         $v1, $at, L_8013C35C
    if (ctx->r3 != ctx->r1) {
        // 0x8013C350: nop
    
            goto L_8013C35C;
    }
    // 0x8013C350: nop

L_8013C354:
    // 0x8013C354: b           L_8013C3C4
    // 0x8013C358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013C3C4;
    // 0x8013C358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013C35C:
    // 0x8013C35C: b           L_8013C3C4
    // 0x8013C360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013C3C4;
    // 0x8013C360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013C364:
    // 0x8013C364: beq         $t1, $zero, L_8013C390
    if (ctx->r9 == 0) {
        // 0x8013C368: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013C390;
    }
    // 0x8013C368: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013C36C: addiu       $a0, $sp, 0x14
    ctx->r4 = ADD32(ctx->r29, 0X14);
    // 0x8013C370: lhu         $a2, 0x0($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X0);
L_8013C374:
    // 0x8013C374: beql        $a1, $a2, L_8013C394
    if (ctx->r5 == ctx->r6) {
        // 0x8013C378: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_8013C394;
    }
    goto skip_0;
    // 0x8013C378: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    skip_0:
    // 0x8013C37C: lhu         $a2, 0x4($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X4);
    // 0x8013C380: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013C384: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8013C388: bne         $a2, $zero, L_8013C374
    if (ctx->r6 != 0) {
        // 0x8013C38C: nop
    
            goto L_8013C374;
    }
    // 0x8013C38C: nop

L_8013C390:
    // 0x8013C390: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
L_8013C394:
    // 0x8013C394: addu        $a0, $a3, $t3
    ctx->r4 = ADD32(ctx->r7, ctx->r11);
    // 0x8013C398: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x8013C39C: bnel        $t4, $zero, L_8013C3B0
    if (ctx->r12 != 0) {
        // 0x8013C3A0: lhu         $t5, 0x2($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X2);
            goto L_8013C3B0;
    }
    goto skip_1;
    // 0x8013C3A0: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    skip_1:
    // 0x8013C3A4: b           L_8013C3C4
    // 0x8013C3A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013C3C4;
    // 0x8013C3A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013C3AC: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
L_8013C3B0:
    // 0x8013C3B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013C3B4: beq         $v1, $t5, L_8013C3C4
    if (ctx->r3 == ctx->r13) {
        // 0x8013C3B8: nop
    
            goto L_8013C3C4;
    }
    // 0x8013C3B8: nop

    // 0x8013C3BC: b           L_8013C3C4
    // 0x8013C3C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013C3C4;
    // 0x8013C3C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013C3C4:
    // 0x8013C3C4: jr          $ra
    // 0x8013C3C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8013C3C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013c3cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013c3cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C3CC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013C3D0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013C3D4: lhu         $t6, 0x350($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X350);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013c3d8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013c3d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C3D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013C3DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C3E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013C3E4: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x8013C3E8: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x8013C3EC: sltiu       $at, $t7, 0x51
    ctx->r1 = ctx->r15 < 0X51 ? 1 : 0;
    // 0x8013C3F0: beq         $at, $zero, L_8013C434
    if (ctx->r1 == 0) {
        // 0x8013C3F4: lhu         $a3, 0xE($a2)
        ctx->r7 = MEM_HU(ctx->r6, 0XE);
            goto L_8013C434;
    }
    // 0x8013C3F4: lhu         $a3, 0xE($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0XE);
    // 0x8013C3F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8013C3FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013C400: addu        $at, $at, $t7
    gpr jr_addend_8013C408 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8013C404: lw          $t7, -0x1EBC($at)
    ctx->r15 = ADD32(ctx->r1, -0X1EBC);
    // 0x8013C408: jr          $t7
    // 0x8013C40C: nop

    switch (jr_addend_8013C408 >> 2) {
        case 0: goto L_8013C410; break;
        case 1: goto L_8013C434; break;
        case 2: goto L_8013C434; break;
        case 3: goto L_8013C434; break;
        case 4: goto L_8013C434; break;
        case 5: goto L_8013C434; break;
        case 6: goto L_8013C434; break;
        case 7: goto L_8013C434; break;
        case 8: goto L_8013C434; break;
        case 9: goto L_8013C434; break;
        case 10: goto L_8013C434; break;
        case 11: goto L_8013C434; break;
        case 12: goto L_8013C434; break;
        case 13: goto L_8013C434; break;
        case 14: goto L_8013C434; break;
        case 15: goto L_8013C434; break;
        case 16: goto L_8013C434; break;
        case 17: goto L_8013C434; break;
        case 18: goto L_8013C434; break;
        case 19: goto L_8013C434; break;
        case 20: goto L_8013C434; break;
        case 21: goto L_8013C434; break;
        case 22: goto L_8013C434; break;
        case 23: goto L_8013C434; break;
        case 24: goto L_8013C434; break;
        case 25: goto L_8013C434; break;
        case 26: goto L_8013C434; break;
        case 27: goto L_8013C434; break;
        case 28: goto L_8013C434; break;
        case 29: goto L_8013C434; break;
        case 30: goto L_8013C434; break;
        case 31: goto L_8013C434; break;
        case 32: goto L_8013C418; break;
        case 33: goto L_8013C434; break;
        case 34: goto L_8013C434; break;
        case 35: goto L_8013C434; break;
        case 36: goto L_8013C434; break;
        case 37: goto L_8013C434; break;
        case 38: goto L_8013C434; break;
        case 39: goto L_8013C434; break;
        case 40: goto L_8013C434; break;
        case 41: goto L_8013C434; break;
        case 42: goto L_8013C434; break;
        case 43: goto L_8013C434; break;
        case 44: goto L_8013C434; break;
        case 45: goto L_8013C434; break;
        case 46: goto L_8013C434; break;
        case 47: goto L_8013C434; break;
        case 48: goto L_8013C418; break;
        case 49: goto L_8013C434; break;
        case 50: goto L_8013C434; break;
        case 51: goto L_8013C434; break;
        case 52: goto L_8013C434; break;
        case 53: goto L_8013C434; break;
        case 54: goto L_8013C434; break;
        case 55: goto L_8013C434; break;
        case 56: goto L_8013C434; break;
        case 57: goto L_8013C434; break;
        case 58: goto L_8013C434; break;
        case 59: goto L_8013C434; break;
        case 60: goto L_8013C434; break;
        case 61: goto L_8013C434; break;
        case 62: goto L_8013C434; break;
        case 63: goto L_8013C434; break;
        case 64: goto L_8013C418; break;
        case 65: goto L_8013C434; break;
        case 66: goto L_8013C434; break;
        case 67: goto L_8013C434; break;
        case 68: goto L_8013C434; break;
        case 69: goto L_8013C434; break;
        case 70: goto L_8013C434; break;
        case 71: goto L_8013C434; break;
        case 72: goto L_8013C434; break;
        case 73: goto L_8013C434; break;
        case 74: goto L_8013C434; break;
        case 75: goto L_8013C434; break;
        case 76: goto L_8013C434; break;
        case 77: goto L_8013C434; break;
        case 78: goto L_8013C434; break;
        case 79: goto L_8013C434; break;
        case 80: goto L_8013C434; break;
        default: switch_error(__func__, 0x8013C408, 0x8018E144);
    }
    // 0x8013C40C: nop

L_8013C410:
    // 0x8013C410: b           L_8013C438
    // 0x8013C414: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_8013C438;
    // 0x8013C414: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8013C418:
    // 0x8013C418: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x8013C41C: bne         $a3, $at, L_8013C42C
    if (ctx->r7 != ctx->r1) {
        // 0x8013C420: nop
    
            goto L_8013C42C;
    }
    // 0x8013C420: nop

    // 0x8013C424: b           L_8013C438
    // 0x8013C428: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_8013C438;
    // 0x8013C428: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8013C42C:
    // 0x8013C42C: b           L_8013C438
    // 0x8013C430: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8013C438;
    // 0x8013C430: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8013C434:
    // 0x8013C434: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8013C438:
    // 0x8013C438: lhu         $t8, 0x34E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X34E);
    // 0x8013C43C: beql        $t8, $zero, L_8013C470
    if (ctx->r24 == 0) {
        // 0x8013C440: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8013C470;
    }
    goto skip_0;
    // 0x8013C440: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_0:
    // 0x8013C444: sb          $v1, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r3;
    // 0x8013C448: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013C44C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8013C450: jal         0x8013C244
    // 0x8013C454: sh          $a3, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013C244)(rdram, ctx);
        goto after_0;
    // 0x8013C454: sh          $a3, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013C458: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
    // 0x8013C45C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013C460: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C464: bne         $v0, $zero, L_8013C480
    if (ctx->r2 != 0) {
        // 0x8013C468: lhu         $a3, 0x1A($sp)
        ctx->r7 = MEM_HU(ctx->r29, 0X1A);
            goto L_8013C480;
    }
    // 0x8013C468: lhu         $a3, 0x1A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X1A);
    // 0x8013C46C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8013C470:
    // 0x8013C470: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8013C474: sh          $t9, 0xA0($a2)
    MEM_H(0XA0, ctx->r6) = ctx->r25;
    // 0x8013C478: b           L_8013C4A8
    // 0x8013C47C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_8013C4A8;
    // 0x8013C47C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8013C480:
    // 0x8013C480: lhu         $t0, 0xA0($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0XA0);
    // 0x8013C484: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8013C488: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8013C48C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8013C490: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8013C494: beq         $t2, $zero, L_8013C4A4
    if (ctx->r10 == 0) {
        // 0x8013C498: sh          $t1, 0xA0($a2)
        MEM_H(0XA0, ctx->r6) = ctx->r9;
            goto L_8013C4A4;
    }
    // 0x8013C498: sh          $t1, 0xA0($a2)
    MEM_H(0XA0, ctx->r6) = ctx->r9;
    // 0x8013C49C: b           L_8013C51C
    // 0x8013C4A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8013C51C;
    // 0x8013C4A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013C4A4:
    // 0x8013C4A4: sh          $t3, 0xA0($a2)
    MEM_H(0XA0, ctx->r6) = ctx->r11;
L_8013C4A8:
    // 0x8013C4A8: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
    // 0x8013C4AC: beq         $v0, $at, L_8013C4C0
    if (ctx->r2 == ctx->r1) {
        // 0x8013C4B0: sll         $t4, $v1, 1
        ctx->r12 = S32(ctx->r3 << 1);
            goto L_8013C4C0;
    }
    // 0x8013C4B0: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x8013C4B4: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x8013C4B8: bne         $v0, $at, L_8013C4E4
    if (ctx->r2 != ctx->r1) {
        // 0x8013C4BC: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_8013C4E4;
    }
    // 0x8013C4BC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_8013C4C0:
    // 0x8013C4C0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013C4C4: addiu       $v0, $v0, -0x2E2C
    ctx->r2 = ADD32(ctx->r2, -0X2E2C);
    // 0x8013C4C8: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8013C4CC: lhu         $a2, 0x0($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X0);
    // 0x8013C4D0: sb          $v1, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r3;
    // 0x8013C4D4: jal         0x8012D894
    // 0x8013C4D8: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_1;
    // 0x8013C4D8: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    after_1:
    // 0x8013C4DC: b           L_8013C518
    // 0x8013C4E0: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
        goto L_8013C518;
    // 0x8013C4E0: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
L_8013C4E4:
    // 0x8013C4E4: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x8013C4E8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8013C4EC: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8013C4F0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8013C4F4: bne         $t8, $zero, L_8013C504
    if (ctx->r24 != 0) {
        // 0x8013C4F8: addu        $t1, $t9, $t0
        ctx->r9 = ADD32(ctx->r25, ctx->r8);
            goto L_8013C504;
    }
    // 0x8013C4F8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8013C4FC: b           L_8013C51C
    // 0x8013C500: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8013C51C;
    // 0x8013C500: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013C504:
    // 0x8013C504: lhu         $a1, 0x0($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X0);
    // 0x8013C508: lhu         $a2, 0x0($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X0);
    // 0x8013C50C: jal         0x8012D844
    // 0x8013C510: sb          $v1, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x8013C510: sb          $v1, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r3;
    after_2:
    // 0x8013C514: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
L_8013C518:
    // 0x8013C518: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013C51C:
    // 0x8013C51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013C524: jr          $ra
    // 0x8013C528: nop

    return;
    // 0x8013C528: nop

;}
RECOMP_FUNC void M7_FUN_8013c52c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C52C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013C530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013C538: jal         0x80126944
    // 0x8013C53C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8013C53C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8013C540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013C544: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C548: beq         $v0, $at, L_8013C558
    if (ctx->r2 == ctx->r1) {
        // 0x8013C54C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8013C558;
    }
    // 0x8013C54C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013C550: b           L_8013C5E4
    // 0x8013C554: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8013C5E4;
    // 0x8013C554: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8013C558:
    // 0x8013C558: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013C55C: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // 0x8013C560: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013C564: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
    // 0x8013C568: bne         $a0, $t6, L_8013C57C
    if (ctx->r4 != ctx->r14) {
        // 0x8013C56C: nop
    
            goto L_8013C57C;
    }
    // 0x8013C56C: nop

    // 0x8013C570: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013C574: b           L_8013C57C
    // 0x8013C578: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_8013C57C;
    // 0x8013C578: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8013C57C:
    // 0x8013C57C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8013C580: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013C584: ldc1        $f8, -0x1D78($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1D78);
    // 0x8013C588: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8013C58C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8013C590: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013C594: cvt.d.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_W(ctx->f4.u32l);
    // 0x8013C598: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8013C59C: nop

    // 0x8013C5A0: cvt.d.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.d = CVT_D_W(ctx->f6.u32l);
    // 0x8013C5A4: mul.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f8.d);
    // 0x8013C5A8: c.lt.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d < ctx->f2.d;
    // 0x8013C5AC: nop

    // 0x8013C5B0: bc1f        L_8013C5C0
    if (!c1cs) {
        // 0x8013C5B4: nop
    
            goto L_8013C5C0;
    }
    // 0x8013C5B4: nop

    // 0x8013C5B8: b           L_8013C5E4
    // 0x8013C5BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8013C5E4;
    // 0x8013C5BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8013C5C0:
    // 0x8013C5C0: ldc1        $f16, -0x1D70($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X1D70);
    // 0x8013C5C4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8013C5C8: mul.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x8013C5CC: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x8013C5D0: nop

    // 0x8013C5D4: bc1f        L_8013C5E4
    if (!c1cs) {
        // 0x8013C5D8: nop
    
            goto L_8013C5E4;
    }
    // 0x8013C5D8: nop

    // 0x8013C5DC: b           L_8013C5E4
    // 0x8013C5E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8013C5E4;
    // 0x8013C5E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8013C5E4:
    // 0x8013C5E4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8013C5E8: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x8013C5EC: lhu         $a2, 0x0($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X0);
    // 0x8013C5F0: jal         0x8012D844
    // 0x8013C5F4: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x8013C5F4: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    after_1:
    // 0x8013C5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C5FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013C600: jr          $ra
    // 0x8013C604: nop

    return;
    // 0x8013C604: nop

;}
RECOMP_FUNC void M7_FUN_8013c608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C608: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013C60C: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013c610(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013c610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013C614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C618: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x8013C61C: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8013C620: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8013C624: bne         $t7, $zero, L_8013C6EC
    if (ctx->r15 != 0) {
        // 0x8013C628: lhu         $a2, 0xE($v1)
        ctx->r6 = MEM_HU(ctx->r3, 0XE);
            goto L_8013C6EC;
    }
    // 0x8013C628: lhu         $a2, 0xE($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XE);
    // 0x8013C62C: beq         $a2, $zero, L_8013C6EC
    if (ctx->r6 == 0) {
        // 0x8013C630: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_8013C6EC;
    }
    // 0x8013C630: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x8013C634: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8013C638: sh          $a2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r6;
    // 0x8013C63C: jal         0x8013B19C
    // 0x8013C640: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013B19C)(rdram, ctx);
        goto after_0;
    // 0x8013C640: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013C644: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8013C648: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013C64C: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x8013C650: beq         $v0, $at, L_8013C6EC
    if (ctx->r2 == ctx->r1) {
        // 0x8013C654: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8013C6EC;
    }
    // 0x8013C654: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8013C658: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x8013C65C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8013C660: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8013C664: lw          $a1, -0x2B8C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2B8C);
    // 0x8013C668: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x8013C66C: beql        $a1, $zero, L_8013C6F0
    if (ctx->r5 == 0) {
        // 0x8013C670: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013C6F0;
    }
    goto skip_0;
    // 0x8013C670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013C674: bnel        $a2, $at, L_8013C690
    if (ctx->r6 != ctx->r1) {
        // 0x8013C678: lbu         $v0, 0x9D($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X9D);
            goto L_8013C690;
    }
    goto skip_1;
    // 0x8013C678: lbu         $v0, 0x9D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9D);
    skip_1:
    // 0x8013C67C: jal         0x8013C52C
    // 0x8013C680: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8013C52C)(rdram, ctx);
        goto after_1;
    // 0x8013C680: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8013C684: b           L_8013C6F0
    // 0x8013C688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013C6F0;
    // 0x8013C688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C68C: lbu         $v0, 0x9D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9D);
L_8013C690:
    // 0x8013C690: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C694: bnel        $v0, $at, L_8013C6B0
    if (ctx->r2 != ctx->r1) {
        // 0x8013C698: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8013C6B0;
    }
    goto skip_2;
    // 0x8013C698: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_2:
    // 0x8013C69C: jal         0x8013BFB8
    // 0x8013C6A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8013BFB8)(rdram, ctx);
        goto after_2;
    // 0x8013C6A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8013C6A4: b           L_8013C6F0
    // 0x8013C6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013C6F0;
    // 0x8013C6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C6AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8013C6B0:
    // 0x8013C6B0: bne         $v0, $at, L_8013C6C8
    if (ctx->r2 != ctx->r1) {
        // 0x8013C6B4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8013C6C8;
    }
    // 0x8013C6B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8013C6B8: jal         0x8013C184
    // 0x8013C6BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8013C184)(rdram, ctx);
        goto after_3;
    // 0x8013C6BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8013C6C0: b           L_8013C6F0
    // 0x8013C6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013C6F0;
    // 0x8013C6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013C6C8:
    // 0x8013C6C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013C6CC: jal         0x8013C3CC
    // 0x8013C6D0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013C3CC)(rdram, ctx);
        goto after_4;
    // 0x8013C6D0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_4:
    // 0x8013C6D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C6D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C6DC: bne         $v0, $at, L_8013C6EC
    if (ctx->r2 != ctx->r1) {
        // 0x8013C6E0: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8013C6EC;
    }
    // 0x8013C6E0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8013C6E4: jal         0x8013C184
    // 0x8013C6E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8013C184)(rdram, ctx);
        goto after_5;
    // 0x8013C6E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
L_8013C6EC:
    // 0x8013C6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013C6F0:
    // 0x8013C6F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013C6F4: jr          $ra
    // 0x8013C6F8: nop

    return;
    // 0x8013C6F8: nop

;}
RECOMP_FUNC void M7_FUN_8013c6fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C6FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013C700: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013C704: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8013C708: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8013C70C: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8013C710: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013C714: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8013C718: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8013C71C: slti        $at, $t6, 0x18
    ctx->r1 = SIGNED(ctx->r14) < 0X18 ? 1 : 0;
    // 0x8013C720: bnel        $at, $zero, L_8013C7EC
    if (ctx->r1 != 0) {
        // 0x8013C724: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C7EC;
    }
    goto skip_0;
    // 0x8013C724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013C728: beq         $a2, $zero, L_8013C788
    if (ctx->r6 == 0) {
        // 0x8013C72C: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_8013C788;
    }
    // 0x8013C72C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8013C730: addiu       $t7, $t7, -0x23E0
    ctx->r15 = ADD32(ctx->r15, -0X23E0);
    // 0x8013C734: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013C738: addiu       $v1, $sp, 0x2C
    ctx->r3 = ADD32(ctx->r29, 0X2C);
    // 0x8013C73C: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x8013C740: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8013C744: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013C748: lui         $t0, 0x191
    ctx->r8 = S32(0X191 << 16);
    // 0x8013C74C: ori         $t0, $t0, 0xB3
    ctx->r8 = ctx->r8 | 0XB3;
    // 0x8013C750: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8013C754: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013C758: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8013C75C: lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X36);
    // 0x8013C760: beq         $v0, $at, L_8013C780
    if (ctx->r2 == ctx->r1) {
        // 0x8013C764: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_8013C780;
    }
    // 0x8013C764: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x8013C768: beq         $v0, $at, L_8013C780
    if (ctx->r2 == ctx->r1) {
        // 0x8013C76C: addiu       $at, $zero, 0xFB
        ctx->r1 = ADD32(0, 0XFB);
            goto L_8013C780;
    }
    // 0x8013C76C: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x8013C770: beq         $v0, $at, L_8013C780
    if (ctx->r2 == ctx->r1) {
        // 0x8013C774: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_8013C780;
    }
    // 0x8013C774: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8013C778: bnel        $v0, $at, L_8013C7C0
    if (ctx->r2 != ctx->r1) {
        // 0x8013C77C: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8013C7C0;
    }
    goto skip_1;
    // 0x8013C77C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_8013C780:
    // 0x8013C780: b           L_8013C7BC
    // 0x8013C784: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_8013C7BC;
    // 0x8013C784: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_8013C788:
    // 0x8013C788: jal         0x8013B19C
    // 0x8013C78C: lhu         $a0, 0x36($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X36);
    LOOKUP_FUNC(0x8013B19C)(rdram, ctx);
        goto after_0;
    // 0x8013C78C: lhu         $a0, 0x36($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X36);
    after_0:
    // 0x8013C790: sll         $t1, $v0, 5
    ctx->r9 = S32(ctx->r2 << 5);
    // 0x8013C794: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8013C798: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8013C79C: lw          $t2, -0x2B88($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B88);
    // 0x8013C7A0: addiu       $v1, $sp, 0x2C
    ctx->r3 = ADD32(ctx->r29, 0X2C);
    // 0x8013C7A4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8013C7A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8013C7AC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8013C7B0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8013C7B4: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8013C7B8: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
L_8013C7BC:
    // 0x8013C7BC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8013C7C0:
    // 0x8013C7C0: lui         $t7, 0xE0
    ctx->r15 = S32(0XE0 << 16);
    // 0x8013C7C4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8013C7C8: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8013C7CC: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8013C7D0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013C7D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013C7D8: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x8013C7DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8013C7E0: jal         0x8013A1B4
    // 0x8013C7E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_1;
    // 0x8013C7E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8013C7E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013C7EC:
    // 0x8013C7EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013C7F0: jr          $ra
    // 0x8013C7F4: nop

    return;
    // 0x8013C7F4: nop

;}
RECOMP_FUNC void M7_FUN_8013c7f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C7F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013C7FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013C800: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8013C804: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8013C808: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8013C80C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013C810: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8013C814: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x8013C818: bnel        $at, $zero, L_8013C8D4
    if (ctx->r1 != 0) {
        // 0x8013C81C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C8D4;
    }
    goto skip_0;
    // 0x8013C81C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013C820: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8013C824: lw          $t8, 0x4C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4C);
    // 0x8013C828: bltzl       $t8, L_8013C8D4
    if (SIGNED(ctx->r24) < 0) {
        // 0x8013C82C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C8D4;
    }
    goto skip_1;
    // 0x8013C82C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013C830: lhu         $a0, 0x36($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X36);
    // 0x8013C834: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8013C838: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8013C83C: beql        $t9, $at, L_8013C8D4
    if (ctx->r25 == ctx->r1) {
        // 0x8013C840: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C8D4;
    }
    goto skip_2;
    // 0x8013C840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013C844: beq         $a2, $zero, L_8013C870
    if (ctx->r6 == 0) {
        // 0x8013C848: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8013C870;
    }
    // 0x8013C848: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8013C84C: addiu       $t0, $t0, -0x23D4
    ctx->r8 = ADD32(ctx->r8, -0X23D4);
    // 0x8013C850: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8013C854: addiu       $v1, $sp, 0x2C
    ctx->r3 = ADD32(ctx->r29, 0X2C);
    // 0x8013C858: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8013C85C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8013C860: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8013C864: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8013C868: b           L_8013C8A4
    // 0x8013C86C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
        goto L_8013C8A4;
    // 0x8013C86C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
L_8013C870:
    // 0x8013C870: jal         0x8013B19C
    // 0x8013C874: nop

    LOOKUP_FUNC(0x8013B19C)(rdram, ctx);
        goto after_0;
    // 0x8013C874: nop

    after_0:
    // 0x8013C878: sll         $t3, $v0, 5
    ctx->r11 = S32(ctx->r2 << 5);
    // 0x8013C87C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8013C880: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8013C884: lw          $t4, -0x2B88($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B88);
    // 0x8013C888: addiu       $v1, $sp, 0x2C
    ctx->r3 = ADD32(ctx->r29, 0X2C);
    // 0x8013C88C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8013C890: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013C894: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8013C898: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8013C89C: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x8013C8A0: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
L_8013C8A4:
    // 0x8013C8A4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8013C8A8: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x8013C8AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8013C8B0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8013C8B4: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8013C8B8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013C8BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013C8C0: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x8013C8C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013C8C8: jal         0x8013A1B4
    // 0x8013C8CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_1;
    // 0x8013C8CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8013C8D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013C8D4:
    // 0x8013C8D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013C8D8: jr          $ra
    // 0x8013C8DC: nop

    return;
    // 0x8013C8DC: nop

;}
RECOMP_FUNC void M7_FUN_8013c8e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C8E0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013C8E4: jr          $ra
    // 0x8013C8E8: lhu         $v0, -0x2324($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2324);
    return;
    // 0x8013C8E8: lhu         $v0, -0x2324($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2324);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013c8ec(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013c8ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C8EC: nop

;}
RECOMP_FUNC void M7_FUN_8013c8f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C8F0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8013C8F4: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8013C8F8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013C8FC: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8013C900: beq         $at, $zero, L_8013C9BC
    if (ctx->r1 == 0) {
        // 0x8013C904: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8013C9BC;
    }
    // 0x8013C904: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8013C908: lh          $v1, 0x6($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X6);
    // 0x8013C90C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8013C910: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013C914: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8013C918: mflo        $v1
    ctx->r3 = lo;
    // 0x8013C91C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8013C920: beq         $t0, $v1, L_8013C954
    if (ctx->r8 == ctx->r3) {
        // 0x8013C924: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8013C954;
    }
    // 0x8013C924: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8013C928: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8013C92C: beq         $a3, $t1, L_8013C970
    if (ctx->r7 == ctx->r9) {
        // 0x8013C930: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_8013C970;
    }
    // 0x8013C930: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8013C934: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013C938: beq         $a3, $at, L_8013C988
    if (ctx->r7 == ctx->r1) {
        // 0x8013C93C: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_8013C988;
    }
    // 0x8013C93C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013C940: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013C944: beq         $a3, $at, L_8013C9A4
    if (ctx->r7 == ctx->r1) {
        // 0x8013C948: sll         $t9, $a1, 3
        ctx->r25 = S32(ctx->r5 << 3);
            goto L_8013C9A4;
    }
    // 0x8013C948: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8013C94C: b           L_8013CA30
    // 0x8013C950: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
        goto L_8013CA30;
    // 0x8013C950: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
L_8013C954:
    // 0x8013C954: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013C958: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013C95C: addiu       $t8, $t8, -0x211C
    ctx->r24 = ADD32(ctx->r24, -0X211C);
    // 0x8013C960: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013C964: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8013C968: b           L_8013CA30
    // 0x8013C96C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
        goto L_8013CA30;
    // 0x8013C96C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
L_8013C970:
    // 0x8013C970: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x8013C974: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8013C978: addiu       $t5, $t5, -0x2114
    ctx->r13 = ADD32(ctx->r13, -0X2114);
    // 0x8013C97C: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8013C980: b           L_8013CA30
    // 0x8013C984: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_8013CA30;
    // 0x8013C984: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_8013C988:
    // 0x8013C988: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8013C98C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8013C990: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013C994: addiu       $t8, $t8, -0x2108
    ctx->r24 = ADD32(ctx->r24, -0X2108);
    // 0x8013C998: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013C99C: b           L_8013CA30
    // 0x8013C9A0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
        goto L_8013CA30;
    // 0x8013C9A0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_8013C9A4:
    // 0x8013C9A4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8013C9A8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8013C9AC: addiu       $t5, $t5, -0x20FC
    ctx->r13 = ADD32(ctx->r13, -0X20FC);
    // 0x8013C9B0: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8013C9B4: b           L_8013CA30
    // 0x8013C9B8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_8013CA30;
    // 0x8013C9B8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_8013C9BC:
    // 0x8013C9BC: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8013C9C0: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8013C9C4: addiu       $v0, $a0, -0x44C
    ctx->r2 = ADD32(ctx->r4, -0X44C);
    // 0x8013C9C8: bne         $v0, $a3, L_8013C9E8
    if (ctx->r2 != ctx->r7) {
        // 0x8013C9CC: sll         $a1, $a2, 3
        ctx->r5 = S32(ctx->r6 << 3);
            goto L_8013C9E8;
    }
    // 0x8013C9CC: sll         $a1, $a2, 3
    ctx->r5 = S32(ctx->r6 << 3);
    // 0x8013C9D0: sll         $a1, $a2, 3
    ctx->r5 = S32(ctx->r6 << 3);
    // 0x8013C9D4: subu        $a1, $a1, $a2
    ctx->r5 = SUB32(ctx->r5, ctx->r6);
    // 0x8013C9D8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8013C9DC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8013C9E0: b           L_8013C9F8
    // 0x8013C9E4: lbu         $v1, -0x20FA($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X20FA);
        goto L_8013C9F8;
    // 0x8013C9E4: lbu         $v1, -0x20FA($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X20FA);
L_8013C9E8:
    // 0x8013C9E8: subu        $a1, $a1, $a2
    ctx->r5 = SUB32(ctx->r5, ctx->r6);
    // 0x8013C9EC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8013C9F0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8013C9F4: lbu         $v1, -0x20E2($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X20E2);
L_8013C9F8:
    // 0x8013C9F8: bne         $v0, $a3, L_8013CA1C
    if (ctx->r2 != ctx->r7) {
        // 0x8013C9FC: addiu       $t8, $a1, -0xD
        ctx->r24 = ADD32(ctx->r5, -0XD);
            goto L_8013CA1C;
    }
    // 0x8013C9FC: addiu       $t8, $a1, -0xD
    ctx->r24 = ADD32(ctx->r5, -0XD);
    // 0x8013CA00: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8013CA04: addiu       $t7, $t7, -0x20EC
    ctx->r15 = ADD32(ctx->r15, -0X20EC);
    // 0x8013CA08: addiu       $t6, $a1, -0xD
    ctx->r14 = ADD32(ctx->r5, -0XD);
    // 0x8013CA0C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8013CA10: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8013CA14: b           L_8013CA30
    // 0x8013CA18: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_8013CA30;
    // 0x8013CA18: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8013CA1C:
    // 0x8013CA1C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013CA20: addiu       $t9, $t9, -0x20D4
    ctx->r25 = ADD32(ctx->r25, -0X20D4);
    // 0x8013CA24: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8013CA28: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8013CA2C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8013CA30:
    // 0x8013CA30: lh          $t4, 0x2BC($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2BC);
    // 0x8013CA34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013CA38: bgezl       $t4, L_8013CA9C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8013CA3C: lh          $t4, 0x2BE($a0)
        ctx->r12 = MEM_H(ctx->r4, 0X2BE);
            goto L_8013CA9C;
    }
    goto skip_0;
    // 0x8013CA3C: lh          $t4, 0x2BE($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2BE);
    skip_0:
    // 0x8013CA40: blez        $v1, L_8013CBCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8013CA44: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8013CBCC;
    }
    // 0x8013CA44: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8013CA48: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8013CA4C: addiu       $t2, $t2, 0x42A0
    ctx->r10 = ADD32(ctx->r10, 0X42A0);
    // 0x8013CA50: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x8013CA54: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
L_8013CA58:
    // 0x8013CA58: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8013CA5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013CA60: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013CA64: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013CA68: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8013CA6C: mflo        $t7
    ctx->r15 = lo;
    // 0x8013CA70: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8013CA74: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x8013CA78: bne         $t9, $zero, L_8013CA88
    if (ctx->r25 != 0) {
        // 0x8013CA7C: nop
    
            goto L_8013CA88;
    }
    // 0x8013CA7C: nop

    // 0x8013CA80: b           L_8013CC08
    // 0x8013CA84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CC08;
    // 0x8013CA84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CA88:
    // 0x8013CA88: bnel        $at, $zero, L_8013CA58
    if (ctx->r1 != 0) {
        // 0x8013CA8C: addu        $t5, $a1, $v0
        ctx->r13 = ADD32(ctx->r5, ctx->r2);
            goto L_8013CA58;
    }
    goto skip_1;
    // 0x8013CA8C: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
    skip_1:
    // 0x8013CA90: b           L_8013CBD0
    // 0x8013CA94: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
        goto L_8013CBD0;
    // 0x8013CA94: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8013CA98: lh          $t4, 0x2BE($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2BE);
L_8013CA9C:
    // 0x8013CA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013CAA0: bgezl       $t4, L_8013CB08
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8013CAA4: lh          $t4, 0x2C0($a0)
        ctx->r12 = MEM_H(ctx->r4, 0X2C0);
            goto L_8013CB08;
    }
    goto skip_2;
    // 0x8013CAA4: lh          $t4, 0x2C0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2C0);
    skip_2:
    // 0x8013CAA8: blez        $v1, L_8013CBCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8013CAAC: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8013CBCC;
    }
    // 0x8013CAAC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8013CAB0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8013CAB4: addiu       $t2, $t2, 0x42A0
    ctx->r10 = ADD32(ctx->r10, 0X42A0);
    // 0x8013CAB8: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x8013CABC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013CAC0: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
L_8013CAC4:
    // 0x8013CAC4: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8013CAC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013CACC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013CAD0: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013CAD4: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8013CAD8: mflo        $t7
    ctx->r15 = lo;
    // 0x8013CADC: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8013CAE0: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x8013CAE4: bne         $t0, $t9, L_8013CAF4
    if (ctx->r8 != ctx->r25) {
        // 0x8013CAE8: nop
    
            goto L_8013CAF4;
    }
    // 0x8013CAE8: nop

    // 0x8013CAEC: b           L_8013CC08
    // 0x8013CAF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CC08;
    // 0x8013CAF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CAF4:
    // 0x8013CAF4: bnel        $at, $zero, L_8013CAC4
    if (ctx->r1 != 0) {
        // 0x8013CAF8: addu        $t5, $a1, $v0
        ctx->r13 = ADD32(ctx->r5, ctx->r2);
            goto L_8013CAC4;
    }
    goto skip_3;
    // 0x8013CAF8: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
    skip_3:
    // 0x8013CAFC: b           L_8013CBD0
    // 0x8013CB00: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
        goto L_8013CBD0;
    // 0x8013CB00: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8013CB04: lh          $t4, 0x2C0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2C0);
L_8013CB08:
    // 0x8013CB08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013CB0C: bgezl       $t4, L_8013CB70
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8013CB10: lh          $t4, 0x2C2($a0)
        ctx->r12 = MEM_H(ctx->r4, 0X2C2);
            goto L_8013CB70;
    }
    goto skip_4;
    // 0x8013CB10: lh          $t4, 0x2C2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2C2);
    skip_4:
    // 0x8013CB14: blez        $v1, L_8013CBCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8013CB18: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8013CBCC;
    }
    // 0x8013CB18: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8013CB1C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8013CB20: addiu       $t2, $t2, 0x42A0
    ctx->r10 = ADD32(ctx->r10, 0X42A0);
    // 0x8013CB24: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x8013CB28: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
L_8013CB2C:
    // 0x8013CB2C: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8013CB30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013CB34: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013CB38: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013CB3C: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8013CB40: mflo        $t7
    ctx->r15 = lo;
    // 0x8013CB44: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8013CB48: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x8013CB4C: bne         $t0, $t9, L_8013CB5C
    if (ctx->r8 != ctx->r25) {
        // 0x8013CB50: nop
    
            goto L_8013CB5C;
    }
    // 0x8013CB50: nop

    // 0x8013CB54: b           L_8013CC08
    // 0x8013CB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CC08;
    // 0x8013CB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CB5C:
    // 0x8013CB5C: bnel        $at, $zero, L_8013CB2C
    if (ctx->r1 != 0) {
        // 0x8013CB60: addu        $t5, $a1, $v0
        ctx->r13 = ADD32(ctx->r5, ctx->r2);
            goto L_8013CB2C;
    }
    goto skip_5;
    // 0x8013CB60: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
    skip_5:
    // 0x8013CB64: b           L_8013CBD0
    // 0x8013CB68: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
        goto L_8013CBD0;
    // 0x8013CB68: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8013CB6C: lh          $t4, 0x2C2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2C2);
L_8013CB70:
    // 0x8013CB70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013CB74: bgezl       $t4, L_8013CBD0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8013CB78: slti        $at, $a2, 0x2
        ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
            goto L_8013CBD0;
    }
    goto skip_6;
    // 0x8013CB78: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    skip_6:
    // 0x8013CB7C: blez        $v1, L_8013CBCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8013CB80: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8013CBCC;
    }
    // 0x8013CB80: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8013CB84: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8013CB88: addiu       $t2, $t2, 0x42A0
    ctx->r10 = ADD32(ctx->r10, 0X42A0);
    // 0x8013CB8C: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x8013CB90: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
L_8013CB94:
    // 0x8013CB94: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8013CB98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8013CB9C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013CBA0: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013CBA4: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8013CBA8: mflo        $t7
    ctx->r15 = lo;
    // 0x8013CBAC: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8013CBB0: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x8013CBB4: bne         $t1, $t9, L_8013CBC4
    if (ctx->r9 != ctx->r25) {
        // 0x8013CBB8: nop
    
            goto L_8013CBC4;
    }
    // 0x8013CBB8: nop

    // 0x8013CBBC: b           L_8013CC08
    // 0x8013CBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CC08;
    // 0x8013CBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CBC4:
    // 0x8013CBC4: bnel        $at, $zero, L_8013CB94
    if (ctx->r1 != 0) {
        // 0x8013CBC8: addu        $t5, $a1, $v0
        ctx->r13 = ADD32(ctx->r5, ctx->r2);
            goto L_8013CB94;
    }
    goto skip_7;
    // 0x8013CBC8: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
    skip_7:
L_8013CBCC:
    // 0x8013CBCC: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
L_8013CBD0:
    // 0x8013CBD0: beq         $at, $zero, L_8013CBE0
    if (ctx->r1 == 0) {
        // 0x8013CBD4: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8013CBE0;
    }
    // 0x8013CBD4: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8013CBD8: b           L_8013CC08
    // 0x8013CBDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CC08;
    // 0x8013CBDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013CBE0:
    // 0x8013CBE0: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x8013CBE4: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x8013CBE8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8013CBEC: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x8013CBF0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8013CBF4: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8013CBF8: bne         $at, $zero, L_8013CC08
    if (ctx->r1 != 0) {
        // 0x8013CBFC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013CC08;
    }
    // 0x8013CBFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013CC00: b           L_8013CC08
    // 0x8013CC04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CC08;
    // 0x8013CC04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013CC08:
    // 0x8013CC08: jr          $ra
    // 0x8013CC0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8013CC0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013cc10(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013cc10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013CC10: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013CC14: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x8013CC18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013CC1C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013CC20: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x8013CC24: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013CC28: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013CC2C: bne         $a0, $t7, L_8013CC54
    if (ctx->r4 != ctx->r15) {
        // 0x8013CC30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013CC54;
    }
    // 0x8013CC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013CC34: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8013CC38: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013CC3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8013CC40: addiu       $t3, $t3, -0x20EC
    ctx->r11 = ADD32(ctx->r11, -0X20EC);
    // 0x8013CC44: mflo        $t8
    ctx->r24 = lo;
    // 0x8013CC48: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8013CC4C: b           L_8013CC70
    // 0x8013CC50: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
        goto L_8013CC70;
    // 0x8013CC50: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
L_8013CC54:
    // 0x8013CC54: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8013CC58: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013CC5C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013CC60: addiu       $t6, $t6, -0x20D4
    ctx->r14 = ADD32(ctx->r14, -0X20D4);
    // 0x8013CC64: mflo        $t4
    ctx->r12 = lo;
    // 0x8013CC68: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8013CC6C: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
L_8013CC70:
    // 0x8013CC70: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8013CC74: bne         $at, $zero, L_8013CCF8
    if (ctx->r1 != 0) {
        // 0x8013CC78: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
        LOOKUP_FUNC(0x8013CCF8)(rdram, ctx);
        return;
    }
    // 0x8013CC78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013CC7C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013CC80: addiu       $t1, $t1, -0x2250
    ctx->r9 = ADD32(ctx->r9, -0X2250);
    // 0x8013CC84: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8013CC88: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013CC8C: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8013CC90: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8013CC94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8013CC98: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013CC9C: addu        $a3, $t1, $t9
    ctx->r7 = ADD32(ctx->r9, ctx->r25);
    // 0x8013CCA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013CCA4: mflo        $t7
    ctx->r15 = lo;
    // 0x8013CCA8: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8013CCAC: lbu         $a1, 0x0($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X0);
    // 0x8013CCB0: addu        $t3, $v1, $a2
    ctx->r11 = ADD32(ctx->r3, ctx->r6);
L_8013CCB4:
    // 0x8013CCB4: addu        $t5, $a3, $a2
    ctx->r13 = ADD32(ctx->r7, ctx->r6);
    // 0x8013CCB8: lbu         $t6, 0x1($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1);
    // 0x8013CCBC: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8013CCC0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8013CCC4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013CCC8: bne         $t4, $t6, L_8013CCD8
    if (ctx->r12 != ctx->r14) {
        // 0x8013CCCC: slti        $at, $a2, 0x5
        ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
            goto L_8013CCD8;
    }
    // 0x8013CCCC: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8013CCD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013CCD4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8013CCD8:
    // 0x8013CCD8: bnel        $at, $zero, L_8013CCB4
    if (ctx->r1 != 0) {
        // 0x8013CCDC: addu        $t3, $v1, $a2
        ctx->r11 = ADD32(ctx->r3, ctx->r6);
            goto L_8013CCB4;
    }
    goto skip_0;
    // 0x8013CCDC: addu        $t3, $v1, $a2
    ctx->r11 = ADD32(ctx->r3, ctx->r6);
    skip_0:
    // 0x8013CCE0: bne         $t2, $v0, L_8013CCF0
    if (ctx->r10 != ctx->r2) {
            // 0x8013CCE4: slti        $at, $a0, 0x2C
    ctx->r1 = SIGNED(ctx->r4) < 0X2C ? 1 : 0;
    LOOKUP_FUNC(0x8013CCF0)(rdram, ctx);
    return;
    }
    // 0x8013CCE4: slti        $at, $a0, 0x2C
    ctx->r1 = SIGNED(ctx->r4) < 0X2C ? 1 : 0;
    // 0x8013CCE8: jr          $ra
    // 0x8013CCEC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8013CCEC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013ccf0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013ccf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8013CC88:
    // 0x8013CCF0: bne         $at, $zero, L_8013CC88
    if (ctx->r1 != 0) {
        // 0x8013CCF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
        LOOKUP_FUNC(0x8013CC88)(rdram, ctx);
        return;
    }
    // 0x8013CCF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013CCF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013CCFC: jr          $ra
    // 0x8013CD00: nop

    return;
    // 0x8013CD00: nop

;}
RECOMP_FUNC void M7_FUN_8013cd04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013CD04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013CD08: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013CD0C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013CD10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013CD14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8013CD18: addiu       $t6, $v0, 0x7E8
    ctx->r14 = ADD32(ctx->r2, 0X7E8);
    // 0x8013CD1C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013CD20: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013CD24: bne         $a0, $t6, L_8013CD38
    if (ctx->r4 != ctx->r14) {
        // 0x8013CD28: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8013CD38;
    }
    // 0x8013CD28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013CD2C: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8013CD30: beq         $at, $zero, L_8013CD3C
    if (ctx->r1 == 0) {
        // 0x8013CD34: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8013CD3C;
    }
    // 0x8013CD34: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8013CD38:
    // 0x8013CD38: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8013CD3C:
    // 0x8013CD3C: addiu       $t7, $v0, 0x44C
    ctx->r15 = ADD32(ctx->r2, 0X44C);
    // 0x8013CD40: bne         $a0, $t7, L_8013CD64
    if (ctx->r4 != ctx->r15) {
        // 0x8013CD44: andi        $t4, $a2, 0xFF
        ctx->r12 = ctx->r6 & 0XFF;
            goto L_8013CD64;
    }
    // 0x8013CD44: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x8013CD48: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8013CD4C: subu        $t8, $t8, $a3
    ctx->r24 = SUB32(ctx->r24, ctx->r7);
    // 0x8013CD50: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8013CD54: addiu       $t0, $t0, -0x20EC
    ctx->r8 = ADD32(ctx->r8, -0X20EC);
    // 0x8013CD58: addiu       $t9, $t8, -0xE
    ctx->r25 = ADD32(ctx->r24, -0XE);
    // 0x8013CD5C: b           L_8013CD7C
    // 0x8013CD60: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
        goto L_8013CD7C;
    // 0x8013CD60: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
L_8013CD64:
    // 0x8013CD64: sll         $t1, $a3, 3
    ctx->r9 = S32(ctx->r7 << 3);
    // 0x8013CD68: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x8013CD6C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8013CD70: addiu       $t3, $t3, -0x20D4
    ctx->r11 = ADD32(ctx->r11, -0X20D4);
    // 0x8013CD74: addiu       $t2, $t1, -0xE
    ctx->r10 = ADD32(ctx->r9, -0XE);
    // 0x8013CD78: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
L_8013CD7C:
    // 0x8013CD7C: sb          $zero, 0x375($a0)
    MEM_B(0X375, ctx->r4) = 0;
    // 0x8013CD80: bne         $t4, $zero, L_8013CFFC
    if (ctx->r12 != 0) {
        // 0x8013CD84: sb          $a2, 0x377($a0)
        MEM_B(0X377, ctx->r4) = ctx->r6;
            goto L_8013CFFC;
    }
    // 0x8013CD84: sb          $a2, 0x377($a0)
    MEM_B(0X377, ctx->r4) = ctx->r6;
    // 0x8013CD88: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x8013CD8C: beq         $at, $zero, L_8013CF48
    if (ctx->r1 == 0) {
        // 0x8013CD90: addiu       $a2, $a3, -0x2
        ctx->r6 = ADD32(ctx->r7, -0X2);
            goto L_8013CF48;
    }
    // 0x8013CD90: addiu       $a2, $a3, -0x2
    ctx->r6 = ADD32(ctx->r7, -0X2);
    // 0x8013CD94: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x8013CD98: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8013CD9C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8013CDA0: bne         $v0, $at, L_8013CE04
    if (ctx->r2 != ctx->r1) {
        // 0x8013CDA4: sll         $t6, $a1, 3
        ctx->r14 = S32(ctx->r5 << 3);
            goto L_8013CE04;
    }
    // 0x8013CDA4: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8013CDA8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8013CDAC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013CDB0: addiu       $t8, $t8, -0x20FC
    ctx->r24 = ADD32(ctx->r24, -0X20FC);
    // 0x8013CDB4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013CDB8: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x8013CDBC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013CDC0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8013CDC4: addiu       $t1, $t1, -0x20FC
    ctx->r9 = ADD32(ctx->r9, -0X20FC);
    // 0x8013CDC8: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8013CDCC: sb          $t5, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r13;
    // 0x8013CDD0: sw          $t9, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r25;
    // 0x8013CDD4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8013CDD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CDDC:
    // 0x8013CDDC: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8013CDE0: addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // 0x8013CDE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013CDE8: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8013CDEC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8013CDF0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8013CDF4: bne         $at, $zero, L_8013CDDC
    if (ctx->r1 != 0) {
        // 0x8013CDF8: sb          $t3, 0x378($t4)
        MEM_B(0X378, ctx->r12) = ctx->r11;
            goto L_8013CDDC;
    }
    // 0x8013CDF8: sb          $t3, 0x378($t4)
    MEM_B(0X378, ctx->r12) = ctx->r11;
    // 0x8013CDFC: b           L_8013CFD0
    // 0x8013CE00: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
        goto L_8013CFD0;
    // 0x8013CE00: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
L_8013CE04:
    // 0x8013CE04: slti        $at, $v0, 0x190
    ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x8013CE08: bne         $at, $zero, L_8013CE78
    if (ctx->r1 != 0) {
        // 0x8013CE0C: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8013CE78;
    }
    // 0x8013CE0C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8013CE10: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013CE14: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8013CE18: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8013CE1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013CE20: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8013CE24: addiu       $t8, $t8, -0x2108
    ctx->r24 = ADD32(ctx->r24, -0X2108);
    // 0x8013CE28: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013CE2C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8013CE30: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013CE34: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8013CE38: addiu       $t1, $t1, -0x2108
    ctx->r9 = ADD32(ctx->r9, -0X2108);
    // 0x8013CE3C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8013CE40: sb          $t5, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r13;
    // 0x8013CE44: sw          $t9, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r25;
    // 0x8013CE48: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8013CE4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CE50:
    // 0x8013CE50: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8013CE54: addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // 0x8013CE58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013CE5C: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8013CE60: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8013CE64: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8013CE68: bne         $at, $zero, L_8013CE50
    if (ctx->r1 != 0) {
        // 0x8013CE6C: sb          $t3, 0x378($t4)
        MEM_B(0X378, ctx->r12) = ctx->r11;
            goto L_8013CE50;
    }
    // 0x8013CE6C: sb          $t3, 0x378($t4)
    MEM_B(0X378, ctx->r12) = ctx->r11;
    // 0x8013CE70: b           L_8013CFD0
    // 0x8013CE74: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
        goto L_8013CFD0;
    // 0x8013CE74: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
L_8013CE78:
    // 0x8013CE78: slti        $at, $v0, 0x12C
    ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8013CE7C: bne         $at, $zero, L_8013CEE4
    if (ctx->r1 != 0) {
        // 0x8013CE80: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_8013CEE4;
    }
    // 0x8013CE80: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8013CE84: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013CE88: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8013CE8C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013CE90: addiu       $t8, $t8, -0x2114
    ctx->r24 = ADD32(ctx->r24, -0X2114);
    // 0x8013CE94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013CE98: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8013CE9C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013CEA0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8013CEA4: addiu       $t1, $t1, -0x2114
    ctx->r9 = ADD32(ctx->r9, -0X2114);
    // 0x8013CEA8: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x8013CEAC: sb          $t5, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r13;
    // 0x8013CEB0: sw          $t9, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r25;
    // 0x8013CEB4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8013CEB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CEBC:
    // 0x8013CEBC: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8013CEC0: addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // 0x8013CEC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013CEC8: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8013CECC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8013CED0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8013CED4: bne         $at, $zero, L_8013CEBC
    if (ctx->r1 != 0) {
        // 0x8013CED8: sb          $t3, 0x378($t4)
        MEM_B(0X378, ctx->r12) = ctx->r11;
            goto L_8013CEBC;
    }
    // 0x8013CED8: sb          $t3, 0x378($t4)
    MEM_B(0X378, ctx->r12) = ctx->r11;
    // 0x8013CEDC: b           L_8013CFD0
    // 0x8013CEE0: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
        goto L_8013CFD0;
    // 0x8013CEE0: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
L_8013CEE4:
    // 0x8013CEE4: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8013CEE8: bne         $at, $zero, L_8013CFCC
    if (ctx->r1 != 0) {
        // 0x8013CEEC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8013CFCC;
    }
    // 0x8013CEEC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8013CEF0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013CEF4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013CEF8: addiu       $t8, $t8, -0x211C
    ctx->r24 = ADD32(ctx->r24, -0X211C);
    // 0x8013CEFC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013CF00: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013CF04: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8013CF08: addiu       $t1, $t1, -0x211C
    ctx->r9 = ADD32(ctx->r9, -0X211C);
    // 0x8013CF0C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8013CF10: sb          $t5, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r13;
    // 0x8013CF14: sw          $t9, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r25;
    // 0x8013CF18: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8013CF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CF20:
    // 0x8013CF20: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8013CF24: addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // 0x8013CF28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013CF2C: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8013CF30: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8013CF34: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8013CF38: bne         $at, $zero, L_8013CF20
    if (ctx->r1 != 0) {
        // 0x8013CF3C: sb          $t3, 0x378($t4)
        MEM_B(0X378, ctx->r12) = ctx->r11;
            goto L_8013CF20;
    }
    // 0x8013CF3C: sb          $t3, 0x378($t4)
    MEM_B(0X378, ctx->r12) = ctx->r11;
    // 0x8013CF40: b           L_8013CFD0
    // 0x8013CF44: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
        goto L_8013CFD0;
    // 0x8013CF44: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
L_8013CF48:
    // 0x8013CF48: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x8013CF4C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8013CF50: sw          $t7, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r15;
    // 0x8013CF54: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8013CF58: sb          $t6, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r14;
    // 0x8013CF5C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8013CF60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013CF64: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013CF68: blezl       $t8, L_8013CFA0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8013CF6C: lbu         $a1, 0x376($a0)
        ctx->r5 = MEM_BU(ctx->r4, 0X376);
            goto L_8013CFA0;
    }
    goto skip_0;
    // 0x8013CF6C: lbu         $a1, 0x376($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X376);
    skip_0:
    // 0x8013CF70: lw          $t9, 0x380($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X380);
L_8013CF74:
    // 0x8013CF74: addu        $t2, $a0, $v0
    ctx->r10 = ADD32(ctx->r4, ctx->r2);
    // 0x8013CF78: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8013CF7C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8013CF80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013CF84: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8013CF88: sb          $t1, 0x378($t2)
    MEM_B(0X378, ctx->r10) = ctx->r9;
    // 0x8013CF8C: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8013CF90: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8013CF94: bnel        $at, $zero, L_8013CF74
    if (ctx->r1 != 0) {
        // 0x8013CF98: lw          $t9, 0x380($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X380);
            goto L_8013CF74;
    }
    goto skip_1;
    // 0x8013CF98: lw          $t9, 0x380($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X380);
    skip_1:
    // 0x8013CF9C: lbu         $a1, 0x376($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X376);
L_8013CFA0:
    // 0x8013CFA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013CFA4: jal         0x8013CC10
    // 0x8013CFA8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8013CC10)(rdram, ctx);
        goto after_0;
    // 0x8013CFA8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8013CFAC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013CFB0: beq         $v0, $zero, L_8013CFCC
    if (ctx->r2 == 0) {
        // 0x8013CFB4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8013CFCC;
    }
    // 0x8013CFB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013CFB8: sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // 0x8013CFBC: lbu         $t5, 0x376($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X376);
    // 0x8013CFC0: sb          $v0, 0x37D($a0)
    MEM_B(0X37D, ctx->r4) = ctx->r2;
    // 0x8013CFC4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8013CFC8: sb          $t6, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r14;
L_8013CFCC:
    // 0x8013CFCC: lw          $t7, 0x380($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X380);
L_8013CFD0:
    // 0x8013CFD0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013CFD4: addiu       $t1, $t1, 0x42A0
    ctx->r9 = ADD32(ctx->r9, 0X42A0);
    // 0x8013CFD8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8013CFDC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8013CFE0: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8013CFE4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8013CFE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013CFEC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8013CFF0: sw          $t2, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r10;
    // 0x8013CFF4: b           L_8013D088
    // 0x8013CFF8: sb          $t8, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r24;
        goto L_8013D088;
    // 0x8013CFF8: sb          $t8, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r24;
L_8013CFFC:
    // 0x8013CFFC: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x8013D000: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8013D004: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8013D008: bnel        $v0, $at, L_8013D01C
    if (ctx->r2 != ctx->r1) {
        // 0x8013D00C: slti        $at, $v0, 0x190
        ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
            goto L_8013D01C;
    }
    goto skip_2;
    // 0x8013D00C: slti        $at, $v0, 0x190
    ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    skip_2:
    // 0x8013D010: b           L_8013D058
    // 0x8013D014: sb          $t3, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r11;
        goto L_8013D058;
    // 0x8013D014: sb          $t3, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r11;
    // 0x8013D018: slti        $at, $v0, 0x190
    ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
L_8013D01C:
    // 0x8013D01C: bne         $at, $zero, L_8013D02C
    if (ctx->r1 != 0) {
        // 0x8013D020: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_8013D02C;
    }
    // 0x8013D020: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8013D024: b           L_8013D058
    // 0x8013D028: sb          $t4, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r12;
        goto L_8013D058;
    // 0x8013D028: sb          $t4, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r12;
L_8013D02C:
    // 0x8013D02C: slti        $at, $v0, 0x12C
    ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8013D030: bne         $at, $zero, L_8013D040
    if (ctx->r1 != 0) {
        // 0x8013D034: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_8013D040;
    }
    // 0x8013D034: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8013D038: b           L_8013D058
    // 0x8013D03C: sb          $t5, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r13;
        goto L_8013D058;
    // 0x8013D03C: sb          $t5, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r13;
L_8013D040:
    // 0x8013D040: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8013D044: bne         $at, $zero, L_8013D054
    if (ctx->r1 != 0) {
        // 0x8013D048: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8013D054;
    }
    // 0x8013D048: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013D04C: b           L_8013D058
    // 0x8013D050: sb          $t6, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r14;
        goto L_8013D058;
    // 0x8013D050: sb          $t6, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r14;
L_8013D054:
    // 0x8013D054: sb          $zero, 0x376($a0)
    MEM_B(0X376, ctx->r4) = 0;
L_8013D058:
    // 0x8013D058: lbu         $t7, 0x2D9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2D9);
    // 0x8013D05C: addiu       $v0, $a0, 0x378
    ctx->r2 = ADD32(ctx->r4, 0X378);
    // 0x8013D060: sw          $v0, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r2;
    // 0x8013D064: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8013D068: lbu         $t8, 0x2D9($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2D9);
    // 0x8013D06C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8013D070: addiu       $t0, $t0, 0x42A0
    ctx->r8 = ADD32(ctx->r8, 0X42A0);
    // 0x8013D074: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8013D078: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8013D07C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013D080: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8013D084: sw          $t1, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r9;
L_8013D088:
    // 0x8013D088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013D08C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013D090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013D094: jr          $ra
    // 0x8013D098: nop

    return;
    // 0x8013D098: nop

;}
RECOMP_FUNC void M7_FUN_8013d09c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D09C: lbu         $t6, 0x377($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X377);
    // 0x8013D0A0: bnel        $t6, $zero, L_8013D0F0
    if (ctx->r14 != 0) {
        // 0x8013D0A4: lbu         $t7, 0x375($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X375);
            goto L_8013D0F0;
    }
    goto skip_0;
    // 0x8013D0A4: lbu         $t7, 0x375($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X375);
    skip_0:
    // 0x8013D0A8: lbu         $t7, 0x375($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X375);
    // 0x8013D0AC: lw          $t9, 0x380($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X380);
    // 0x8013D0B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8013D0B4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8013D0B8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8013D0BC: sb          $t8, 0x375($a0)
    MEM_B(0X375, ctx->r4) = ctx->r24;
    // 0x8013D0C0: sw          $t0, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r8;
    // 0x8013D0C4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x8013D0C8: addiu       $t5, $t5, 0x42A0
    ctx->r13 = ADD32(ctx->r13, 0X42A0);
    // 0x8013D0CC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8013D0D0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8013D0D4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8013D0D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8013D0DC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8013D0E0: sw          $t6, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r14;
    // 0x8013D0E4: jr          $ra
    // 0x8013D0E8: sb          $t2, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r10;
    return;
    // 0x8013D0E8: sb          $t2, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r10;
    // 0x8013D0EC: lbu         $t7, 0x375($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X375);
L_8013D0F0:
    // 0x8013D0F0: lw          $t9, 0x380($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X380);
    // 0x8013D0F4: lbu         $t1, 0x2D9($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2D9);
    // 0x8013D0F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8013D0FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8013D100: sb          $t8, 0x375($a0)
    MEM_B(0X375, ctx->r4) = ctx->r24;
    // 0x8013D104: sw          $t0, 0x380($a0)
    MEM_W(0X380, ctx->r4) = ctx->r8;
    // 0x8013D108: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x8013D10C: lbu         $t3, 0x2D9($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X2D9);
    // 0x8013D110: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8013D114: addiu       $t5, $t5, 0x42A0
    ctx->r13 = ADD32(ctx->r13, 0X42A0);
    // 0x8013D118: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8013D11C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8013D120: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8013D124: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8013D128: sw          $t6, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r14;
    // 0x8013D12C: jr          $ra
    // 0x8013D130: nop

    return;
    // 0x8013D130: nop

;}
RECOMP_FUNC void M7_FUN_8013d134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D134: lbu         $t6, 0x375($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X375);
    // 0x8013D138: jr          $ra
    // 0x8013D13C: sb          $t6, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r14;
    return;
    // 0x8013D13C: sb          $t6, 0x376($a0)
    MEM_B(0X376, ctx->r4) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d140(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D140: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013D144: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013D148: slti        $at, $a0, 0xE
    ctx->r1 = SIGNED(ctx->r4) < 0XE ? 1 : 0;
    // 0x8013D14C: beq         $at, $zero, L_8013D160
    if (ctx->r1 == 0) {
            // 0x8013D150: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    LOOKUP_FUNC(0x8013D160)(rdram, ctx);
    return;
    }
    // 0x8013D150: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8013D154: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8013D158: jr          $ra
    // 0x8013D15C: addiu       $v0, $v0, -0x1D04
    ctx->r2 = ADD32(ctx->r2, -0X1D04);
    return;
    // 0x8013D15C: addiu       $v0, $v0, -0x1D04
    ctx->r2 = ADD32(ctx->r2, -0X1D04);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d160(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D160: addiu       $v0, $v0, -0x1D00
    ctx->r2 = ADD32(ctx->r2, -0X1D00);
    // 0x8013D164: jr          $ra
    // 0x8013D168: nop

    return;
    // 0x8013D168: nop

;}
RECOMP_FUNC void M7_FUN_8013d16c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D16C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013D170: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013D174: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x8013D178: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x8013D17C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013D180: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8013D184: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013D188: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013D18C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013D190: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013D194: bne         $a1, $t7, L_8013D1B4
    if (ctx->r5 != ctx->r15) {
        // 0x8013D198: andi        $a2, $a0, 0xFF
        ctx->r6 = ctx->r4 & 0XFF;
            goto L_8013D1B4;
    }
    // 0x8013D198: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8013D19C: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x8013D1A0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8013D1A4: addiu       $t9, $t9, -0x20EC
    ctx->r25 = ADD32(ctx->r25, -0X20EC);
    // 0x8013D1A8: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8013D1AC: b           L_8013D1C8
    // 0x8013D1B0: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
        goto L_8013D1C8;
    // 0x8013D1B0: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
L_8013D1B4:
    // 0x8013D1B4: sll         $t0, $a2, 3
    ctx->r8 = S32(ctx->r6 << 3);
    // 0x8013D1B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8013D1BC: addiu       $t1, $t1, -0x20D4
    ctx->r9 = ADD32(ctx->r9, -0X20D4);
    // 0x8013D1C0: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8013D1C4: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
L_8013D1C8:
    // 0x8013D1C8: lbu         $t2, 0x0($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X0);
    // 0x8013D1CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8013D1D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013D1D4: blez        $t2, L_8013D22C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8013D1D8: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_8013D22C;
    }
    // 0x8013D1D8: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8013D1DC: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x8013D1E0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8013D1E4: addiu       $t4, $t4, -0x14E0
    ctx->r12 = ADD32(ctx->r12, -0X14E0);
    // 0x8013D1E8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8013D1EC: addu        $s3, $t3, $t4
    ctx->r19 = ADD32(ctx->r11, ctx->r12);
    // 0x8013D1F0: sb          $a2, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r6;
    // 0x8013D1F4: addu        $t5, $s0, $s2
    ctx->r13 = ADD32(ctx->r16, ctx->r18);
L_8013D1F8:
    // 0x8013D1F8: jal         0x8013D140
    // 0x8013D1FC: lbu         $a0, 0x1($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X1);
    LOOKUP_FUNC(0x8013D140)(rdram, ctx);
        goto after_0;
    // 0x8013D1FC: lbu         $a0, 0x1($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X1);
    after_0:
    // 0x8013D200: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8013D204: addu        $t7, $s3, $s1
    ctx->r15 = ADD32(ctx->r19, ctx->r17);
    // 0x8013D208: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8013D20C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8013D210: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x8013D214: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8013D218: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8013D21C: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8013D220: bnel        $at, $zero, L_8013D1F8
    if (ctx->r1 != 0) {
        // 0x8013D224: addu        $t5, $s0, $s2
        ctx->r13 = ADD32(ctx->r16, ctx->r18);
            goto L_8013D1F8;
    }
    goto skip_0;
    // 0x8013D224: addu        $t5, $s0, $s2
    ctx->r13 = ADD32(ctx->r16, ctx->r18);
    skip_0:
    // 0x8013D228: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
L_8013D22C:
    // 0x8013D22C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8013D230: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8013D234: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8013D238: addiu       $t0, $t0, -0x14E0
    ctx->r8 = ADD32(ctx->r8, -0X14E0);
    // 0x8013D23C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8013D240: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8013D244: addu        $t1, $v0, $s1
    ctx->r9 = ADD32(ctx->r2, ctx->r17);
    // 0x8013D248: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8013D24C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013D250: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8013D254: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D258: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013D25C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8013D260: jr          $ra
    // 0x8013D264: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8013D264: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d268(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D268: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8013D26C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013D270: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013D274: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8013D278: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013D27C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8013D280: bne         $at, $zero, L_8013D290
    if (ctx->r1 != 0) {
            // 0x8013D284: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8013D290)(rdram, ctx);
    return;
    }
    // 0x8013D284: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013D288: jr          $ra
    // 0x8013D28C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013D28C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d290(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D290: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8013D294: beql        $at, $zero, L_8013D2A8
    if (ctx->r1 == 0) {
        // 0x8013D298: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8013D2A8;
    }
    goto skip_0;
    // 0x8013D298: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x8013D29C: jr          $ra
    // 0x8013D2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013D2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013D2A4: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8013D2A8:
    // 0x8013D2A8: bne         $at, $zero, L_8013D2B8
    if (ctx->r1 != 0) {
            // 0x8013D2AC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    LOOKUP_FUNC(0x8013D2B8)(rdram, ctx);
    return;
    }
    // 0x8013D2AC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8013D2B0: jr          $ra
    // 0x8013D2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013D2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d2b8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d2b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D2B8: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8013D2BC: beq         $at, $zero, L_8013D3A4
    if (ctx->r1 == 0) {
            // 0x8013D2C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x8013D3A4)(rdram, ctx);
    return;
    }
    // 0x8013D2C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8013D2C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013D2C8: beq         $v0, $at, L_8013D2FC
    if (ctx->r2 == ctx->r1) {
            // 0x8013D2CC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    LOOKUP_FUNC(0x8013D2FC)(rdram, ctx);
    return;
    }
    // 0x8013D2CC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013D2D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013D2D4: beq         $v0, $at, L_8013D320
    if (ctx->r2 == ctx->r1) {
            // 0x8013D2D8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    LOOKUP_FUNC(0x8013D320)(rdram, ctx);
    return;
    }
    // 0x8013D2D8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8013D2DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013D2E0: beq         $v0, $at, L_8013D348
    if (ctx->r2 == ctx->r1) {
            // 0x8013D2E4: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    LOOKUP_FUNC(0x8013D348)(rdram, ctx);
    return;
    }
    // 0x8013D2E4: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8013D2E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013D2EC: beq         $v0, $at, L_8013D374
    if (ctx->r2 == ctx->r1) {
            // 0x8013D2F0: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    LOOKUP_FUNC(0x8013D374)(rdram, ctx);
    return;
    }
    // 0x8013D2F0: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x8013D2F4: jr          $ra
    // 0x8013D2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013D2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d2fc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d2fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D2FC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8013D300: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8013D304: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8013D308: lbu         $t8, -0x211B($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X211B);
    // 0x8013D30C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013D310: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8013D314: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8013D318: jr          $ra
    // 0x8013D31C: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    return;
    // 0x8013D31C: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d320(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D320: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x8013D324: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x8013D328: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8013D32C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8013D330: lbu         $t2, -0x2113($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2113);
    // 0x8013D334: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013D338: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8013D33C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8013D340: jr          $ra
    // 0x8013D344: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    return;
    // 0x8013D344: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d348(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013d348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D348: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8013D34C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8013D350: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x8013D354: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013D358: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8013D35C: lbu         $t6, -0x2107($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2107);
    // 0x8013D360: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013D364: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8013D368: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8013D36C: jr          $ra
    // 0x8013D370: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    return;
    // 0x8013D370: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013d374(rdram, ctx);
;}
