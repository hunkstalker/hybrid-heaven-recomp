#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M55_FUN_80386968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386968: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8038696C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80386970: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80386974: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80386978: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8038697C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80386980: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80386984: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x80386988: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8038698C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80386990: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386994: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80386998: bnel        $t7, $zero, L_80386A6C
    if (ctx->r15 != 0) {
        // 0x8038699C: lw          $t8, 0x7C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X7C);
            goto L_80386A6C;
    }
    goto skip_0;
    // 0x8038699C: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    skip_0:
    // 0x803869A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803869A4: lwc1        $f12, 0x94($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X94);
    // 0x803869A8: lwc1        $f14, 0x98($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X98);
    // 0x803869AC: lw          $a2, 0x9C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X9C);
    // 0x803869B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x803869B4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x803869B8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x803869BC: jal         0x80380F94
    // 0x803869C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_0;
    // 0x803869C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x803869C4: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803869C8: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803869CC: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x803869D0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x803869D4: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x803869D8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x803869DC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x803869E0: jal         0x80380F94
    // 0x803869E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_1;
    // 0x803869E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x803869E8: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803869EC: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803869F0: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x803869F4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x803869F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x803869FC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386A00: lwc1        $f8, -0x62D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X62D0);
    // 0x80386A04: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80386A08: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80386A0C: addiu       $t1, $zero, 0xF3
    ctx->r9 = ADD32(0, 0XF3);
    // 0x80386A10: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80386A14: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80386A18: addiu       $t4, $zero, 0x66
    ctx->r12 = ADD32(0, 0X66);
    // 0x80386A1C: addiu       $t5, $zero, 0xF0
    ctx->r13 = ADD32(0, 0XF0);
    // 0x80386A20: addiu       $t6, $zero, -0x4
    ctx->r14 = ADD32(0, -0X4);
    // 0x80386A24: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80386A28: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80386A2C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80386A30: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80386A34: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80386A38: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80386A3C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80386A40: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80386A44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80386A48: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80386A4C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80386A50: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80386A54: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80386A58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80386A5C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80386A60: jal         0x80129FB8
    // 0x80386A64: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_2;
    // 0x80386A64: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80386A68: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
L_80386A6C:
    // 0x80386A6C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80386A70: bgez        $t8, L_80386A84
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80386A74: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_80386A84;
    }
    // 0x80386A74: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80386A78: beq         $t9, $zero, L_80386A84
    if (ctx->r25 == 0) {
        // 0x80386A7C: nop
    
            goto L_80386A84;
    }
    // 0x80386A7C: nop

    // 0x80386A80: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80386A84:
    // 0x80386A84: bnel        $t9, $zero, L_80386BE4
    if (ctx->r25 != 0) {
        // 0x80386A88: lw          $t5, 0x7C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X7C);
            goto L_80386BE4;
    }
    goto skip_1;
    // 0x80386A88: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    skip_1:
    // 0x80386A8C: jal         0x8012C6B4
    // 0x80386A90: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80386A90: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_3:
    // 0x80386A94: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80386A98: jal         0x8012C6B4
    // 0x80386A9C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80386A9C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_4:
    // 0x80386AA0: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80386AA4: jal         0x8012C6B4
    // 0x80386AA8: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80386AA8: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_5:
    // 0x80386AAC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80386AB0: jal         0x8012C6B4
    // 0x80386AB4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80386AB4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_6:
    // 0x80386AB8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80386ABC: jal         0x8012C6B4
    // 0x80386AC0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80386AC0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_7:
    // 0x80386AC4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80386AC8: jal         0x8012C6B4
    // 0x80386ACC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80386ACC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_8:
    // 0x80386AD0: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80386AD4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80386AD8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80386ADC: addiu       $t1, $t0, -0x320
    ctx->r9 = ADD32(ctx->r8, -0X320);
    // 0x80386AE0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80386AE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80386AE8: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80386AEC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80386AF0: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80386AF4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80386AF8: lwc1        $f10, 0x98($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80386AFC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386B00: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x80386B04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80386B08: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80386B0C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386B10: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80386B14: addiu       $t4, $t3, -0x320
    ctx->r12 = ADD32(ctx->r11, -0X320);
    // 0x80386B18: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80386B1C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80386B20: addiu       $t3, $zero, -0x4
    ctx->r11 = ADD32(0, -0X4);
    // 0x80386B24: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80386B28: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80386B2C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80386B30: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80386B34: addiu       $t1, $t0, 0x3C
    ctx->r9 = ADD32(ctx->r8, 0X3C);
    // 0x80386B38: addiu       $t7, $t6, 0xC8
    ctx->r15 = ADD32(ctx->r14, 0XC8);
    // 0x80386B3C: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80386B40: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80386B44: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80386B48: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80386B4C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80386B50: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80386B54: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x80386B58: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80386B5C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80386B60: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80386B64: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80386B68: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80386B6C: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x80386B70: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80386B74: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80386B78: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80386B7C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80386B80: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80386B84: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80386B88: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80386B8C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80386B90: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x80386B94: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80386B98: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80386B9C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80386BA0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80386BA4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80386BA8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80386BAC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80386BB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80386BB4: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x80386BB8: ldc1        $f8, -0x62C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X62C8);
    // 0x80386BBC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386BC0: div.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80386BC4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80386BC8: ldc1        $f16, -0x62C0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X62C0);
    // 0x80386BCC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80386BD0: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x80386BD4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80386BD8: jal         0x80129FB8
    // 0x80386BDC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_9;
    // 0x80386BDC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80386BE0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
L_80386BE4:
    // 0x80386BE4: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80386BE8: bnel        $at, $zero, L_80386BFC
    if (ctx->r1 != 0) {
        // 0x80386BEC: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80386BFC;
    }
    goto skip_2;
    // 0x80386BEC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x80386BF0: jal         0x80005700
    // 0x80386BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_10;
    // 0x80386BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80386BF8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80386BFC:
    // 0x80386BFC: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80386C00: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80386C04: jr          $ra
    // 0x80386C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80386C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80386c0c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80386c0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386C0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80386C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80386C14: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80386C18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80386C1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80386C20: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80386C24: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386C28: lh          $a0, 0xA0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XA0);
    // 0x80386C2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80386C30: jal         0x8001EB64
    // 0x80386C34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x80386C34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80386C38: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80386C3C: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80386C40: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80386C44: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x80386C48: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80386C4C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80386C50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80386C54: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80386C58: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80386C5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80386C60: lwc1        $f18, 0x98($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X98);
    // 0x80386C64: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386C68: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80386C6C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80386C70: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80386C74: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80386C78: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80386C7C: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80386C80: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80386C84: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80386C88: lh          $a0, 0xA0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0XA0);
    // 0x80386C8C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80386C90: jal         0x8001EAD0
    // 0x80386C94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80386C94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80386C98: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80386C9C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80386CA0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80386CA4: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80386CA8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80386CAC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80386CB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80386CB4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80386CB8: lwc1        $f6, 0x9C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X9C);
    // 0x80386CBC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80386CC0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80386CC4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80386CC8: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80386CCC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80386CD0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80386CD4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80386CD8: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x80386CDC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80386CE0: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80386CE4: beql        $at, $zero, L_80386D08
    if (ctx->r1 == 0) {
        // 0x80386CE8: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_80386D08;
    }
    goto skip_0;
    // 0x80386CE8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    skip_0:
    // 0x80386CEC: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80386CF0: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80386CF4: lbu         $t5, 0x4B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386CF8: addiu       $t6, $t5, 0x3C
    ctx->r14 = ADD32(ctx->r13, 0X3C);
    // 0x80386CFC: b           L_80386D44
    // 0x80386D00: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
        goto L_80386D44;
    // 0x80386D00: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
    // 0x80386D04: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
L_80386D08:
    // 0x80386D08: beql        $at, $zero, L_80386D48
    if (ctx->r1 == 0) {
        // 0x80386D0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80386D48;
    }
    goto skip_1;
    // 0x80386D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80386D10: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386D14: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80386D18: lbu         $t7, 0x4B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386D1C: addiu       $t9, $t7, -0x18
    ctx->r25 = ADD32(ctx->r15, -0X18);
    // 0x80386D20: sb          $t9, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r25;
    // 0x80386D24: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80386D28: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80386D2C: lbu         $t2, 0x4B($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X4B);
    // 0x80386D30: slti        $at, $t2, 0x18
    ctx->r1 = SIGNED(ctx->r10) < 0X18 ? 1 : 0;
    // 0x80386D34: beql        $at, $zero, L_80386D48
    if (ctx->r1 == 0) {
        // 0x80386D38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80386D48;
    }
    goto skip_2;
    // 0x80386D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80386D3C: jal         0x80005700
    // 0x80386D40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80386D40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_80386D44:
    // 0x80386D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80386D48:
    // 0x80386D48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80386D4C: jr          $ra
    // 0x80386D50: nop

    return;
    // 0x80386D50: nop

;}
RECOMP_FUNC void M55_FUN_80386d54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386D54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80386D58: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80386D5C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80386D60: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80386D64: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80386D68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80386D6C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80386D70: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80386D74: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386D78: jal         0x8012C6B4
    // 0x80386D7C: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80386D7C: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_0:
    // 0x80386D80: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80386D84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80386D88: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80386D8C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80386D90: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80386D94: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x80386D98: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x80386D9C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80386DA0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80386DA4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80386DA8: jal         0x80380F94
    // 0x80386DAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_1;
    // 0x80386DAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80386DB0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80386DB4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80386DB8: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80386DBC: lbu         $a0, 0x4B($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X4B);
    // 0x80386DC0: slti        $at, $a0, 0xF0
    ctx->r1 = SIGNED(ctx->r4) < 0XF0 ? 1 : 0;
    // 0x80386DC4: beq         $at, $zero, L_80386DD0
    if (ctx->r1 == 0) {
        // 0x80386DC8: addiu       $t0, $a0, 0x4
        ctx->r8 = ADD32(ctx->r4, 0X4);
            goto L_80386DD0;
    }
    // 0x80386DC8: addiu       $t0, $a0, 0x4
    ctx->r8 = ADD32(ctx->r4, 0X4);
    // 0x80386DCC: sb          $t0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r8;
L_80386DD0:
    // 0x80386DD0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80386DD4: slti        $at, $t1, 0x3C
    ctx->r1 = SIGNED(ctx->r9) < 0X3C ? 1 : 0;
    // 0x80386DD8: bnel        $at, $zero, L_80386DEC
    if (ctx->r1 != 0) {
        // 0x80386DDC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80386DEC;
    }
    goto skip_0;
    // 0x80386DDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80386DE0: jal         0x80005700
    // 0x80386DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80386DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80386DE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80386DEC:
    // 0x80386DEC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80386DF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80386DF4: jr          $ra
    // 0x80386DF8: nop

    return;
    // 0x80386DF8: nop

;}
RECOMP_FUNC void M55_FUN_80386dfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80386E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80386E04: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80386E08: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80386E0C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80386E10: beq         $at, $zero, L_80386E5C
    if (ctx->r1 == 0) {
        // 0x80386E14: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_80386E5C;
    }
    // 0x80386E14: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386E18: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80386E1C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386E20: ldc1        $f8, -0x62B8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X62B8);
    // 0x80386E24: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80386E28: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386E2C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386E30: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80386E34: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80386E38: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80386E3C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386E40: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80386E44: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386E48: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80386E4C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386E50: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80386E54: b           L_80386ED0
    // 0x80386E58: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
        goto L_80386ED0;
    // 0x80386E58: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
L_80386E5C:
    // 0x80386E5C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80386E60: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386E64: ldc1        $f6, -0x62B0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X62B0);
    // 0x80386E68: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80386E6C: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386E70: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80386E74: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x80386E78: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80386E7C: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80386E80: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80386E84: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80386E88: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386E8C: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80386E90: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80386E94: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80386E98: swc1        $f0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f0.u32l;
    // 0x80386E9C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80386EA0: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x80386EA4: lbu         $t6, 0x4B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386EA8: addiu       $t7, $t6, -0x6
    ctx->r15 = ADD32(ctx->r14, -0X6);
    // 0x80386EAC: sb          $t7, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r15;
    // 0x80386EB0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386EB4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80386EB8: lbu         $t0, 0x4B($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4B);
    // 0x80386EBC: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x80386EC0: beql        $at, $zero, L_80386ED4
    if (ctx->r1 == 0) {
        // 0x80386EC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80386ED4;
    }
    goto skip_0;
    // 0x80386EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80386EC8: jal         0x80005700
    // 0x80386ECC: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80386ECC: nop

    after_0:
L_80386ED0:
    // 0x80386ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80386ED4:
    // 0x80386ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80386ED8: jr          $ra
    // 0x80386EDC: nop

    return;
    // 0x80386EDC: nop

;}
RECOMP_FUNC void M55_FUN_80386ee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80386EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80386EE8: lhu         $a2, 0x3C($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X3C);
    // 0x80386EEC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386EF0: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x80386EF4: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386EF8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80386EFC: ldc1        $f8, -0x62A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X62A8);
    // 0x80386F00: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386F04: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80386F08: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386F0C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386F10: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80386F14: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80386F18: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80386F1C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386F20: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80386F24: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386F28: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x80386F2C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386F30: ldc1        $f8, -0x62A0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X62A0);
    // 0x80386F34: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80386F38: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80386F3C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386F40: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386F44: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80386F48: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80386F4C: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80386F50: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80386F54: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80386F58: lh          $t1, 0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X12);
    // 0x80386F5C: addiu       $t4, $t1, 0x555
    ctx->r12 = ADD32(ctx->r9, 0X555);
    // 0x80386F60: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x80386F64: beq         $at, $zero, L_80386F84
    if (ctx->r1 == 0) {
        // 0x80386F68: sh          $t5, 0x12($v0)
        MEM_H(0X12, ctx->r2) = ctx->r13;
            goto L_80386F84;
    }
    // 0x80386F68: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    // 0x80386F6C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80386F70: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80386F74: lbu         $t7, 0x4B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386F78: addiu       $t8, $t7, 0x37
    ctx->r24 = ADD32(ctx->r15, 0X37);
    // 0x80386F7C: b           L_80386FC4
    // 0x80386F80: sb          $t8, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r24;
        goto L_80386FC4;
    // 0x80386F80: sb          $t8, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r24;
L_80386F84:
    // 0x80386F84: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80386F88: bnel        $at, $zero, L_80386FC8
    if (ctx->r1 != 0) {
        // 0x80386F8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80386FC8;
    }
    goto skip_0;
    // 0x80386F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80386F90: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386F94: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80386F98: lbu         $t0, 0x4B($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386F9C: addiu       $t1, $t0, -0x10
    ctx->r9 = ADD32(ctx->r8, -0X10);
    // 0x80386FA0: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
    // 0x80386FA4: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80386FA8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80386FAC: lbu         $t4, 0x4B($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X4B);
    // 0x80386FB0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x80386FB4: beql        $at, $zero, L_80386FC8
    if (ctx->r1 == 0) {
        // 0x80386FB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80386FC8;
    }
    goto skip_1;
    // 0x80386FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80386FBC: jal         0x80005700
    // 0x80386FC0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80386FC0: nop

    after_0:
L_80386FC4:
    // 0x80386FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80386FC8:
    // 0x80386FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80386FCC: jr          $ra
    // 0x80386FD0: nop

    return;
    // 0x80386FD0: nop

;}
RECOMP_FUNC void M55_FUN_80386fd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386FD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80386FD8: jr          $ra
    // 0x80386FDC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80386FDC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80386fe0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80386fe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386FE0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80386FE4: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80386FE8: sw          $s5, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r21;
    // 0x80386FEC: sw          $s4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r20;
    // 0x80386FF0: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
    // 0x80386FF4: sw          $s2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r18;
    // 0x80386FF8: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x80386FFC: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
    // 0x80387000: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x80387004: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x80387008: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x8038700C: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x80387010: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80387014: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80387018: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8038701C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80387020: bne         $v0, $zero, L_80387130
    if (ctx->r2 != 0) {
        // 0x80387024: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_80387130;
    }
    // 0x80387024: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80387028: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038702C: lwc1        $f26, -0x6298($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X6298);
    // 0x80387030: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387034: lwc1        $f24, -0x6294($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6294);
    // 0x80387038: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8038703C: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x80387040: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80387044: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80387048: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8038704C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80387050: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80387054: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_80387058:
    // 0x80387058: jal         0x8012C6B4
    // 0x8038705C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x8038705C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x80387060: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80387064: jal         0x8012C6B4
    // 0x80387068: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80387068: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_1:
    // 0x8038706C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80387070: jal         0x8012C6B4
    // 0x80387074: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80387074: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_2:
    // 0x80387078: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8038707C: addiu       $t7, $s2, -0xFA
    ctx->r15 = ADD32(ctx->r18, -0XFA);
    // 0x80387080: addiu       $t8, $v0, -0x12C
    ctx->r24 = ADD32(ctx->r2, -0X12C);
    // 0x80387084: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80387088: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8038708C: lwc1        $f12, 0x94($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X94);
    // 0x80387090: lwc1        $f14, 0x98($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X98);
    // 0x80387094: lw          $a2, 0x9C($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X9C);
    // 0x80387098: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x8038709C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x803870A0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x803870A4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x803870A8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x803870AC: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x803870B0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x803870B4: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x803870B8: addiu       $t5, $zero, -0xC
    ctx->r13 = ADD32(0, -0XC);
    // 0x803870BC: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x803870C0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x803870C4: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x803870C8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x803870CC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x803870D0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x803870D4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x803870D8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x803870DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x803870E0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803870E4: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x803870E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x803870EC: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x803870F0: neg.d       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = -ctx->f8.d;
    // 0x803870F4: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x803870F8: sub.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = ctx->f10.d - ctx->f22.d;
    // 0x803870FC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80387100: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80387104: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80387108: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8038710C: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80387110: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80387114: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80387118: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8038711C: jal         0x80129FB8
    // 0x80387120: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_3;
    // 0x80387120: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80387124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387128: bne         $s0, $s4, L_80387058
    if (ctx->r16 != ctx->r20) {
        // 0x8038712C: nop
    
            goto L_80387058;
    }
    // 0x8038712C: nop

L_80387130:
    // 0x80387130: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80387134: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387138: ldc1        $f16, -0x6290($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X6290);
    // 0x8038713C: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80387140: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387144: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80387148: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8038714C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80387150: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80387154: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80387158: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8038715C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80387160: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80387164: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80387168: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8038716C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80387170: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    // 0x80387174: lw          $t1, 0x4($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X4);
    // 0x80387178: ldc1        $f10, -0x6288($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6288);
    // 0x8038717C: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x80387180: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80387184: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80387188: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8038718C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80387190: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
    // 0x80387194: lw          $t2, 0x4($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X4);
    // 0x80387198: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x8038719C: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x803871A0: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x803871A4: lw          $t3, 0x4($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X4);
    // 0x803871A8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x803871AC: swc1        $f0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f0.u32l;
    // 0x803871B0: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x803871B4: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x803871B8: lbu         $t6, 0x4B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4B);
    // 0x803871BC: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x803871C0: sb          $t7, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r15;
    // 0x803871C4: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x803871C8: lw          $t1, 0x4($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X4);
    // 0x803871CC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803871D0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x803871D4: lbu         $t0, 0x4B($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4B);
    // 0x803871D8: sb          $t0, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r8;
    // 0x803871DC: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x803871E0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x803871E4: lbu         $t5, 0x4B($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4B);
    // 0x803871E8: slti        $at, $t5, 0x11
    ctx->r1 = SIGNED(ctx->r13) < 0X11 ? 1 : 0;
    // 0x803871EC: beql        $at, $zero, L_80387200
    if (ctx->r1 == 0) {
        // 0x803871F0: lw          $ra, 0x84($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X84);
            goto L_80387200;
    }
    goto skip_0;
    // 0x803871F0: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x803871F4: jal         0x80005700
    // 0x803871F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x803871F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x803871FC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
L_80387200:
    // 0x80387200: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80387204: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80387208: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x8038720C: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x80387210: lw          $s0, 0x6C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X6C);
    // 0x80387214: lw          $s1, 0x70($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X70);
    // 0x80387218: lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X74);
    // 0x8038721C: lw          $s3, 0x78($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X78);
    // 0x80387220: lw          $s4, 0x7C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X7C);
    // 0x80387224: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80387228: jr          $ra
    // 0x8038722C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8038722C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80387230(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80387230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387230: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80387234: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80387238: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8038723C: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80387240: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80387244: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80387248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038724C: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80387250: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80387254: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80387258: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8038725C: bgez        $t7, L_80387270
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80387260: andi        $t8, $t7, 0x1
        ctx->r24 = ctx->r15 & 0X1;
            goto L_80387270;
    }
    // 0x80387260: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80387264: beq         $t8, $zero, L_80387270
    if (ctx->r24 == 0) {
        // 0x80387268: nop
    
            goto L_80387270;
    }
    // 0x80387268: nop

    // 0x8038726C: addiu       $t8, $t8, -0x2
    ctx->r24 = ADD32(ctx->r24, -0X2);
L_80387270:
    // 0x80387270: bnel        $t8, $zero, L_803873C4
    if (ctx->r24 != 0) {
        // 0x80387274: lw          $t3, 0x84($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X84);
            goto L_803873C4;
    }
    goto skip_0;
    // 0x80387274: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x80387278: jal         0x8012C6B4
    // 0x8038727C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x8038727C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_0:
    // 0x80387280: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80387284: jal         0x8012C6B4
    // 0x80387288: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80387288: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_1:
    // 0x8038728C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80387290: jal         0x8012C6B4
    // 0x80387294: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80387294: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_2:
    // 0x80387298: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8038729C: jal         0x8012C6B4
    // 0x803872A0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x803872A0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_3:
    // 0x803872A4: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x803872A8: jal         0x8012C6B4
    // 0x803872AC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x803872AC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_4:
    // 0x803872B0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x803872B4: jal         0x8012C6B4
    // 0x803872B8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x803872B8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_5:
    // 0x803872BC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x803872C0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x803872C4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x803872C8: addiu       $t0, $t9, -0x1F4
    ctx->r8 = ADD32(ctx->r25, -0X1F4);
    // 0x803872CC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x803872D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803872D4: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x803872D8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x803872DC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x803872E0: addiu       $t2, $t1, -0x1F4
    ctx->r10 = ADD32(ctx->r9, -0X1F4);
    // 0x803872E4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x803872E8: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803872EC: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x803872F0: addiu       $t4, $t3, -0x1F4
    ctx->r12 = ADD32(ctx->r11, -0X1F4);
    // 0x803872F4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803872F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x803872FC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80387300: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80387304: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80387308: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8038730C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80387310: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x80387314: addiu       $t1, $zero, -0x4
    ctx->r9 = ADD32(0, -0X4);
    // 0x80387318: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x8038731C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80387320: addiu       $t8, $zero, 0x94
    ctx->r24 = ADD32(0, 0X94);
    // 0x80387324: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80387328: addiu       $t7, $t6, 0x8E
    ctx->r15 = ADD32(ctx->r14, 0X8E);
    // 0x8038732C: div.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80387330: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80387334: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80387338: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8038733C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80387340: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80387344: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80387348: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8038734C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80387350: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80387354: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80387358: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8038735C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80387360: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80387364: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80387368: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8038736C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80387370: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80387374: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80387378: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8038737C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80387380: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80387384: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80387388: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8038738C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80387390: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80387394: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80387398: ldc1        $f8, -0x6280($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6280);
    // 0x8038739C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803873A0: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x803873A4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x803873A8: ldc1        $f18, -0x6278($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6278);
    // 0x803873AC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x803873B0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x803873B4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x803873B8: jal         0x80129FB8
    // 0x803873BC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_6;
    // 0x803873BC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x803873C0: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
L_803873C4:
    // 0x803873C4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x803873C8: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x803873CC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803873D0: bgez        $t3, L_803873E4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x803873D4: andi        $t4, $t3, 0x3
        ctx->r12 = ctx->r11 & 0X3;
            goto L_803873E4;
    }
    // 0x803873D4: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x803873D8: beq         $t4, $zero, L_803873E4
    if (ctx->r12 == 0) {
        // 0x803873DC: nop
    
            goto L_803873E4;
    }
    // 0x803873DC: nop

    // 0x803873E0: addiu       $t4, $t4, -0x4
    ctx->r12 = ADD32(ctx->r12, -0X4);
L_803873E4:
    // 0x803873E4: bnel        $t4, $zero, L_80387534
    if (ctx->r12 != 0) {
        // 0x803873E8: lw          $t9, 0x84($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X84);
            goto L_80387534;
    }
    goto skip_1;
    // 0x803873E8: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    skip_1:
    // 0x803873EC: jal         0x8012C6B4
    // 0x803873F0: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x803873F0: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    after_7:
    // 0x803873F4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x803873F8: jal         0x8012C6B4
    // 0x803873FC: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x803873FC: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    after_8:
    // 0x80387400: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80387404: jal         0x8012C6B4
    // 0x80387408: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x80387408: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    after_9:
    // 0x8038740C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80387410: jal         0x8012C6B4
    // 0x80387414: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x80387414: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_10:
    // 0x80387418: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8038741C: jal         0x8012C6B4
    // 0x80387420: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80387420: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_11:
    // 0x80387424: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80387428: jal         0x8012C6B4
    // 0x8038742C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x8038742C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_12:
    // 0x80387430: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80387434: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80387438: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8038743C: addiu       $t6, $t5, -0x190
    ctx->r14 = ADD32(ctx->r13, -0X190);
    // 0x80387440: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80387444: addiu       $t8, $t7, -0x190
    ctx->r24 = ADD32(ctx->r15, -0X190);
    // 0x80387448: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8038744C: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80387450: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80387454: addiu       $t0, $t9, -0x190
    ctx->r8 = ADD32(ctx->r25, -0X190);
    // 0x80387458: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038745C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80387460: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80387464: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80387468: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8038746C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80387470: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80387474: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80387478: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8038747C: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x80387480: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x80387484: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80387488: addiu       $t4, $zero, 0x94
    ctx->r12 = ADD32(0, 0X94);
    // 0x8038748C: addiu       $t3, $t2, 0x8E
    ctx->r11 = ADD32(ctx->r10, 0X8E);
    // 0x80387490: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80387494: div.d       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80387498: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x8038749C: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x803874A0: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803874A4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x803874A8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x803874AC: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x803874B0: lwc1        $f8, -0x6270($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6270);
    // 0x803874B4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803874B8: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x803874BC: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x803874C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x803874C4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803874C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x803874CC: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x803874D0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x803874D4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x803874D8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x803874DC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x803874E0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x803874E4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x803874E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x803874EC: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x803874F0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x803874F4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x803874F8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x803874FC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80387500: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80387504: ldc1        $f4, -0x6268($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6268);
    // 0x80387508: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038750C: cvt.d.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.d = CVT_D_W(ctx->f18.u32l);
    // 0x80387510: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80387514: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80387518: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8038751C: ldc1        $f10, -0x6260($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6260);
    // 0x80387520: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80387524: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80387528: jal         0x80129FB8
    // 0x8038752C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_13;
    // 0x8038752C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x80387530: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
L_80387534:
    // 0x80387534: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80387538: bnel        $at, $zero, L_8038754C
    if (ctx->r1 != 0) {
        // 0x8038753C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_8038754C;
    }
    goto skip_2;
    // 0x8038753C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x80387540: jal         0x80005700
    // 0x80387544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_14;
    // 0x80387544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80387548: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8038754C:
    // 0x8038754C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80387550: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80387554: jr          $ra
    // 0x80387558: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80387558: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8038755c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8038755c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038755C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80387560: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80387564: sw          $s3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r19;
    // 0x80387568: sw          $s2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r18;
    // 0x8038756C: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    // 0x80387570: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x80387574: sdc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X68, ctx->r29);
    // 0x80387578: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x8038757C: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x80387580: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x80387584: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x80387588: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8038758C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80387590: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80387594: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80387598: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x8038759C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x803875A0: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x803875A4: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x803875A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x803875AC: bnel        $t7, $zero, L_80387694
    if (ctx->r15 != 0) {
        // 0x803875B0: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_80387694;
    }
    goto skip_0;
    // 0x803875B0: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    skip_0:
    // 0x803875B4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x803875B8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803875BC: lwc1        $f26, -0x6258($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X6258);
    // 0x803875C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x803875C4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x803875C8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x803875CC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803875D0: addiu       $s3, $zero, 0x22A2
    ctx->r19 = ADD32(0, 0X22A2);
    // 0x803875D4: sll         $s1, $s0, 16
    ctx->r17 = S32(ctx->r16 << 16);
L_803875D8:
    // 0x803875D8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x803875DC: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x803875E0: jal         0x8001EAD0
    // 0x803875E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x803875E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x803875E8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x803875EC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x803875F0: jal         0x8001EB64
    // 0x803875F4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x803875F4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x803875F8: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x803875FC: lwc1        $f4, 0x98($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80387600: mul.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x80387604: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80387608: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x8038760C: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x80387610: mul.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f20.d);
    // 0x80387614: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80387618: add.s       $f14, $f4, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x8038761C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80387620: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80387624: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80387628: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x8038762C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80387630: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80387634: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x80387638: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8038763C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80387640: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
    // 0x80387644: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80387648: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8038764C: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80387650: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80387654: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80387658: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8038765C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80387660: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80387664: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80387668: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8038766C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80387670: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80387674: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x80387678: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x8038767C: jal         0x80129FB8
    // 0x80387680: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_2;
    // 0x80387680: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_2:
    // 0x80387684: addiu       $s0, $s0, 0x2AA
    ctx->r16 = ADD32(ctx->r16, 0X2AA);
    // 0x80387688: bnel        $s0, $s3, L_803875D8
    if (ctx->r16 != ctx->r19) {
        // 0x8038768C: sll         $s1, $s0, 16
        ctx->r17 = S32(ctx->r16 << 16);
            goto L_803875D8;
    }
    goto skip_1;
    // 0x8038768C: sll         $s1, $s0, 16
    ctx->r17 = S32(ctx->r16 << 16);
    skip_1:
    // 0x80387690: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_80387694:
    // 0x80387694: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80387698: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8038769C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x803876A0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x803876A4: bne         $at, $zero, L_80387734
    if (ctx->r1 != 0) {
        // 0x803876A8: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_80387734;
    }
    // 0x803876A8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x803876AC: lwc1        $f6, 0x98($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X98);
    // 0x803876B0: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x803876B4: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x803876B8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803876BC: lwc1        $f8, -0x6254($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6254);
    // 0x803876C0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803876C4: lwc1        $f10, -0x6250($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6250);
    // 0x803876C8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x803876CC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x803876D0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x803876D4: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x803876D8: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x803876DC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x803876E0: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x803876E4: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
    // 0x803876E8: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x803876EC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x803876F0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x803876F4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x803876F8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x803876FC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80387700: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80387704: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80387708: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8038770C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80387710: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80387714: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80387718: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8038771C: add.s       $f14, $f6, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x80387720: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80387724: jal         0x80129FB8
    // 0x80387728: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_3;
    // 0x80387728: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8038772C: jal         0x80005700
    // 0x80387730: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x80387730: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_80387734:
    // 0x80387734: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x80387738: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8038773C: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80387740: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x80387744: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x80387748: ldc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X68);
    // 0x8038774C: lw          $s0, 0x74($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X74);
    // 0x80387750: lw          $s1, 0x78($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X78);
    // 0x80387754: lw          $s2, 0x7C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X7C);
    // 0x80387758: lw          $s3, 0x80($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X80);
    // 0x8038775C: jr          $ra
    // 0x80387760: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80387760: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80387764(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80387764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80387768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038776C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80387770: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387774: ldc1        $f0, -0x6248($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6248);
    // 0x80387778: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8038777C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80387780: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80387784: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x80387788: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8038778C: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80387790: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80387794: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80387798: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8038779C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x803877A0: add.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d + ctx->f0.d;
    // 0x803877A4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x803877A8: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x803877AC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x803877B0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x803877B4: lbu         $t9, 0x4B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4B);
    // 0x803877B8: addiu       $t0, $t9, -0x10
    ctx->r8 = ADD32(ctx->r25, -0X10);
    // 0x803877BC: sb          $t0, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r8;
    // 0x803877C0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x803877C4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x803877C8: lbu         $t3, 0x4B($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X4B);
    // 0x803877CC: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x803877D0: beql        $at, $zero, L_803877E4
    if (ctx->r1 == 0) {
        // 0x803877D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803877E4;
    }
    goto skip_0;
    // 0x803877D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803877D8: jal         0x80005700
    // 0x803877DC: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803877DC: nop

    after_0:
    // 0x803877E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803877E4:
    // 0x803877E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803877E8: jr          $ra
    // 0x803877EC: nop

    return;
    // 0x803877EC: nop

;}
RECOMP_FUNC void M55_FUN_803877f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803877F0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x803877F4: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x803877F8: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x803877FC: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80387800: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80387804: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80387808: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x8038780C: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x80387810: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80387814: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80387818: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8038781C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80387820: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80387824: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80387828: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8038782C: bne         $v0, $zero, L_803879A0
    if (ctx->r2 != 0) {
        // 0x80387830: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_803879A0;
    }
    // 0x80387830: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80387834: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387838: lwc1        $f24, -0x6240($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6240);
    // 0x8038783C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387840: lwc1        $f22, -0x623C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X623C);
    // 0x80387844: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80387848: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8038784C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80387850: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_80387854:
    // 0x80387854: jal         0x8012C6B4
    // 0x80387858: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80387858: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x8038785C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80387860: jal         0x8012C6B4
    // 0x80387864: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80387864: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x80387868: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8038786C: jal         0x8012C6B4
    // 0x80387870: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80387870: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_2:
    // 0x80387874: addiu       $t7, $s1, -0x64
    ctx->r15 = ADD32(ctx->r17, -0X64);
    // 0x80387878: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8038787C: addiu       $t9, $v0, -0x64
    ctx->r25 = ADD32(ctx->r2, -0X64);
    // 0x80387880: addiu       $t8, $s2, -0x32
    ctx->r24 = ADD32(ctx->r18, -0X32);
    // 0x80387884: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80387888: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8038788C: lwc1        $f12, 0x94($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X94);
    // 0x80387890: lwc1        $f14, 0x98($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X98);
    // 0x80387894: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80387898: lw          $a2, 0x9C($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X9C);
    // 0x8038789C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x803878A0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x803878A4: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x803878A8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x803878AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x803878B0: addiu       $t4, $zero, 0xDC
    ctx->r12 = ADD32(0, 0XDC);
    // 0x803878B4: addiu       $t5, $zero, -0xE
    ctx->r13 = ADD32(0, -0XE);
    // 0x803878B8: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x803878BC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x803878C0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x803878C4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x803878C8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x803878CC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x803878D0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x803878D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x803878D8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803878DC: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x803878E0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x803878E4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x803878E8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x803878EC: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x803878F0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x803878F4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x803878F8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x803878FC: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80387900: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80387904: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80387908: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8038790C: neg.d       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = -ctx->f16.d;
    // 0x80387910: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80387914: jal         0x80129FB8
    // 0x80387918: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_3;
    // 0x80387918: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8038791C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387920: bne         $s0, $s4, L_80387854
    if (ctx->r16 != ctx->r20) {
        // 0x80387924: nop
    
            goto L_80387854;
    }
    // 0x80387924: nop

    // 0x80387928: lwc1        $f12, 0x94($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X94);
    // 0x8038792C: lwc1        $f14, 0x98($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X98);
    // 0x80387930: lw          $a2, 0x9C($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X9C);
    // 0x80387934: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80387938: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038793C: lwc1        $f6, -0x6238($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6238);
    // 0x80387940: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80387944: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80387948: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8038794C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80387950: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80387954: addiu       $t2, $zero, -0x4
    ctx->r10 = ADD32(0, -0X4);
    // 0x80387958: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8038795C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80387960: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80387964: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80387968: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8038796C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80387970: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80387974: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80387978: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8038797C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80387980: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80387984: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80387988: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8038798C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80387990: jal         0x80129FB8
    // 0x80387994: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_4;
    // 0x80387994: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80387998: jal         0x80005700
    // 0x8038799C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_5;
    // 0x8038799C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
L_803879A0:
    // 0x803879A0: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x803879A4: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x803879A8: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x803879AC: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x803879B0: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x803879B4: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x803879B8: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x803879BC: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x803879C0: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x803879C4: jr          $ra
    // 0x803879C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x803879C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803879cc(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803879cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803879CC: nop

;}
RECOMP_FUNC void M55_FUN_803879d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803879D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x803879D4: lhu         $t6, -0x23C0($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X23C0);
    // 0x803879D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x803879DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x803879E0: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803879E4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x803879E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x803879EC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x803879F0: mflo        $v1
    ctx->r3 = lo;
    // 0x803879F4: nop

    // 0x803879F8: nop

    // 0x803879FC: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80387A00: mflo        $v1
    ctx->r3 = lo;
    // 0x80387A04: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80387A08: beq         $at, $zero, L_80387A18
    if (ctx->r1 == 0) {
            // 0x80387A0C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    LOOKUP_FUNC(0x80387A18)(rdram, ctx);
    return;
    }
    // 0x80387A0C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x80387A10: jr          $ra
    // 0x80387A14: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80387A14: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80387a18(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80387a18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387A18: jr          $ra
    // 0x80387A1C: nop

    return;
    // 0x80387A1C: nop

;}
RECOMP_FUNC void M55_FUN_80387a20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80387A24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80387A28: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80387A2C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80387A30: sltiu       $at, $t6, 0x12
    ctx->r1 = ctx->r14 < 0X12 ? 1 : 0;
    // 0x80387A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80387A38: beq         $at, $zero, L_80387DCC
    if (ctx->r1 == 0) {
        // 0x80387A3C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80387DCC;
    }
    // 0x80387A3C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80387A40: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80387A44: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387A48: addu        $at, $at, $t6
    gpr jr_addend_80387A50 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80387A4C: lw          $t6, -0x6168($at)
    ctx->r14 = ADD32(ctx->r1, -0X6168);
    // 0x80387A50: jr          $t6
    // 0x80387A54: nop

    switch (jr_addend_80387A50 >> 2) {
        case 0: goto L_80387A58; break;
        case 1: goto L_80387AB8; break;
        case 2: goto L_80387B18; break;
        case 3: goto L_80387B78; break;
        case 4: goto L_80387DCC; break;
        case 5: goto L_80387DCC; break;
        case 6: goto L_80387DCC; break;
        case 7: goto L_80387DCC; break;
        case 8: goto L_80387B9C; break;
        case 9: goto L_80387BFC; break;
        case 10: goto L_80387C5C; break;
        case 11: goto L_80387CBC; break;
        case 12: goto L_80387DCC; break;
        case 13: goto L_80387DCC; break;
        case 14: goto L_80387DCC; break;
        case 15: goto L_80387CE0; break;
        case 16: goto L_80387D30; break;
        case 17: goto L_80387D80; break;
        default: switch_error(__func__, 0x80387A50, 0x80389E98);
    }
    // 0x80387A54: nop

L_80387A58:
    // 0x80387A58: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80387A5C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80387A60: jal         0x803879D0
    // 0x80387A64: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x803879D0)(rdram, ctx);
        goto after_0;
    // 0x80387A64: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80387A68: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387A6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387A70: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387A74: jal         0x80005670
    // 0x80387A78: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x80387A78: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_1:
    // 0x80387A7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387A80: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387A84: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x80387A88: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x80387A8C: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x80387A90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80387A94: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x80387A98: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80387A9C: beql        $at, $zero, L_80387AB0
    if (ctx->r1 == 0) {
        // 0x80387AA0: sh          $v1, 0x90($v0)
        MEM_H(0X90, ctx->r2) = ctx->r3;
            goto L_80387AB0;
    }
    goto skip_0;
    // 0x80387AA0: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    skip_0:
    // 0x80387AA4: b           L_80387AB0
    // 0x80387AA8: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
        goto L_80387AB0;
    // 0x80387AA8: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
    // 0x80387AAC: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
L_80387AB0:
    // 0x80387AB0: b           L_80387DCC
    // 0x80387AB4: sh          $t9, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r25;
        goto L_80387DCC;
    // 0x80387AB4: sh          $t9, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r25;
L_80387AB8:
    // 0x80387AB8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80387ABC: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x80387AC0: jal         0x803879D0
    // 0x80387AC4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x803879D0)(rdram, ctx);
        goto after_2;
    // 0x80387AC4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80387AC8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387AD0: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387AD4: jal         0x80005670
    // 0x80387AD8: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x80387AD8: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_3:
    // 0x80387ADC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387AE0: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387AE4: lhu         $t0, 0x0($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X0);
    // 0x80387AE8: lhu         $t1, 0x2($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X2);
    // 0x80387AEC: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x80387AF0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80387AF4: subu        $v1, $t0, $t1
    ctx->r3 = SUB32(ctx->r8, ctx->r9);
    // 0x80387AF8: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80387AFC: beql        $at, $zero, L_80387B10
    if (ctx->r1 == 0) {
        // 0x80387B00: sh          $v1, 0x90($v0)
        MEM_H(0X90, ctx->r2) = ctx->r3;
            goto L_80387B10;
    }
    goto skip_1;
    // 0x80387B00: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    skip_1:
    // 0x80387B04: b           L_80387B10
    // 0x80387B08: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
        goto L_80387B10;
    // 0x80387B08: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
    // 0x80387B0C: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
L_80387B10:
    // 0x80387B10: b           L_80387DCC
    // 0x80387B14: sh          $t2, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r10;
        goto L_80387DCC;
    // 0x80387B14: sh          $t2, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r10;
L_80387B18:
    // 0x80387B18: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80387B1C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x80387B20: jal         0x803879D0
    // 0x80387B24: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x803879D0)(rdram, ctx);
        goto after_4;
    // 0x80387B24: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x80387B28: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387B2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387B30: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387B34: jal         0x80005670
    // 0x80387B38: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x80387B38: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_5:
    // 0x80387B3C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387B40: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387B44: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x80387B48: lhu         $t4, 0x2($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2);
    // 0x80387B4C: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x80387B50: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80387B54: subu        $v1, $t3, $t4
    ctx->r3 = SUB32(ctx->r11, ctx->r12);
    // 0x80387B58: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80387B5C: beql        $at, $zero, L_80387B70
    if (ctx->r1 == 0) {
        // 0x80387B60: sh          $v1, 0x90($v0)
        MEM_H(0X90, ctx->r2) = ctx->r3;
            goto L_80387B70;
    }
    goto skip_2;
    // 0x80387B60: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    skip_2:
    // 0x80387B64: b           L_80387B70
    // 0x80387B68: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
        goto L_80387B70;
    // 0x80387B68: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
    // 0x80387B6C: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
L_80387B70:
    // 0x80387B70: b           L_80387DCC
    // 0x80387B74: sh          $t5, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r13;
        goto L_80387DCC;
    // 0x80387B74: sh          $t5, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r13;
L_80387B78:
    // 0x80387B78: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387B7C: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387B80: jal         0x80005670
    // 0x80387B84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x80387B84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80387B88: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80387B8C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80387B90: sh          $t6, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r14;
    // 0x80387B94: b           L_80387DCC
    // 0x80387B98: sh          $t7, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r15;
        goto L_80387DCC;
    // 0x80387B98: sh          $t7, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r15;
L_80387B9C:
    // 0x80387B9C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80387BA0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80387BA4: jal         0x803879D0
    // 0x80387BA8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x803879D0)(rdram, ctx);
        goto after_7;
    // 0x80387BA8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_7:
    // 0x80387BAC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387BB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387BB4: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387BB8: jal         0x80005670
    // 0x80387BBC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_8;
    // 0x80387BBC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_8:
    // 0x80387BC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387BC4: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387BC8: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x80387BCC: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x80387BD0: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x80387BD4: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80387BD8: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x80387BDC: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80387BE0: beql        $at, $zero, L_80387BF4
    if (ctx->r1 == 0) {
        // 0x80387BE4: sh          $v1, 0x90($v0)
        MEM_H(0X90, ctx->r2) = ctx->r3;
            goto L_80387BF4;
    }
    goto skip_3;
    // 0x80387BE4: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    skip_3:
    // 0x80387BE8: b           L_80387BF4
    // 0x80387BEC: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
        goto L_80387BF4;
    // 0x80387BEC: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
    // 0x80387BF0: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
L_80387BF4:
    // 0x80387BF4: b           L_80387DCC
    // 0x80387BF8: sh          $t0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r8;
        goto L_80387DCC;
    // 0x80387BF8: sh          $t0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r8;
L_80387BFC:
    // 0x80387BFC: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80387C00: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x80387C04: jal         0x803879D0
    // 0x80387C08: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x803879D0)(rdram, ctx);
        goto after_9;
    // 0x80387C08: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_9:
    // 0x80387C0C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387C10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387C14: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387C18: jal         0x80005670
    // 0x80387C1C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_10;
    // 0x80387C1C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_10:
    // 0x80387C20: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387C24: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387C28: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    // 0x80387C2C: lhu         $t2, 0x2($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X2);
    // 0x80387C30: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x80387C34: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80387C38: subu        $v1, $t1, $t2
    ctx->r3 = SUB32(ctx->r9, ctx->r10);
    // 0x80387C3C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80387C40: beql        $at, $zero, L_80387C54
    if (ctx->r1 == 0) {
        // 0x80387C44: sh          $v1, 0x90($v0)
        MEM_H(0X90, ctx->r2) = ctx->r3;
            goto L_80387C54;
    }
    goto skip_4;
    // 0x80387C44: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    skip_4:
    // 0x80387C48: b           L_80387C54
    // 0x80387C4C: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
        goto L_80387C54;
    // 0x80387C4C: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
    // 0x80387C50: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
L_80387C54:
    // 0x80387C54: b           L_80387DCC
    // 0x80387C58: sh          $t3, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r11;
        goto L_80387DCC;
    // 0x80387C58: sh          $t3, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r11;
L_80387C5C:
    // 0x80387C5C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80387C60: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x80387C64: jal         0x803879D0
    // 0x80387C68: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x803879D0)(rdram, ctx);
        goto after_11;
    // 0x80387C68: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_11:
    // 0x80387C6C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387C70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387C74: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387C78: jal         0x80005670
    // 0x80387C7C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_12;
    // 0x80387C7C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_12:
    // 0x80387C80: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387C84: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387C88: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x80387C8C: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    // 0x80387C90: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x80387C94: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x80387C98: subu        $v1, $t4, $t5
    ctx->r3 = SUB32(ctx->r12, ctx->r13);
    // 0x80387C9C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80387CA0: beql        $at, $zero, L_80387CB4
    if (ctx->r1 == 0) {
        // 0x80387CA4: sh          $v1, 0x90($v0)
        MEM_H(0X90, ctx->r2) = ctx->r3;
            goto L_80387CB4;
    }
    goto skip_5;
    // 0x80387CA4: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    skip_5:
    // 0x80387CA8: b           L_80387CB4
    // 0x80387CAC: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
        goto L_80387CB4;
    // 0x80387CAC: sh          $a2, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r6;
    // 0x80387CB0: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
L_80387CB4:
    // 0x80387CB4: b           L_80387DCC
    // 0x80387CB8: sh          $t6, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r14;
        goto L_80387DCC;
    // 0x80387CB8: sh          $t6, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r14;
L_80387CBC:
    // 0x80387CBC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387CC0: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387CC4: jal         0x80005670
    // 0x80387CC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_13;
    // 0x80387CC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_13:
    // 0x80387CCC: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x80387CD0: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80387CD4: sh          $t7, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r15;
    // 0x80387CD8: b           L_80387DCC
    // 0x80387CDC: sh          $t8, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r24;
        goto L_80387DCC;
    // 0x80387CDC: sh          $t8, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r24;
L_80387CE0:
    // 0x80387CE0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387CE4: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387CE8: jal         0x80005670
    // 0x80387CEC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_14;
    // 0x80387CEC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_14:
    // 0x80387CF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80387CF4: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x80387CF8: sh          $zero, 0x90($v0)
    MEM_H(0X90, ctx->r2) = 0;
    // 0x80387CFC: sb          $t0, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r8;
    // 0x80387D00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80387D04: jal         0x8022B640
    // 0x80387D08: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_15;
    // 0x80387D08: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_15:
    // 0x80387D0C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80387D10: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387D14: addiu       $t3, $v0, 0x10
    ctx->r11 = ADD32(ctx->r2, 0X10);
    // 0x80387D18: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387D1C: sh          $t3, 0x9A($v1)
    MEM_H(0X9A, ctx->r3) = ctx->r11;
    // 0x80387D20: lhu         $t2, 0x40($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X40);
    // 0x80387D24: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80387D28: b           L_80387DCC
    // 0x80387D2C: sh          $t4, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r12;
        goto L_80387DCC;
    // 0x80387D2C: sh          $t4, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r12;
L_80387D30:
    // 0x80387D30: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387D34: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387D38: jal         0x80005670
    // 0x80387D3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_16;
    // 0x80387D3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_16:
    // 0x80387D40: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80387D44: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x80387D48: sh          $zero, 0x90($v0)
    MEM_H(0X90, ctx->r2) = 0;
    // 0x80387D4C: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x80387D50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80387D54: jal         0x8022B640
    // 0x80387D58: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_17;
    // 0x80387D58: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_17:
    // 0x80387D5C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80387D60: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387D64: addiu       $t9, $v0, 0x10
    ctx->r25 = ADD32(ctx->r2, 0X10);
    // 0x80387D68: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387D6C: sh          $t9, 0x9A($v1)
    MEM_H(0X9A, ctx->r3) = ctx->r25;
    // 0x80387D70: lhu         $t8, 0x42($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X42);
    // 0x80387D74: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80387D78: b           L_80387DCC
    // 0x80387D7C: sh          $t0, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r8;
        goto L_80387DCC;
    // 0x80387D7C: sh          $t0, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r8;
L_80387D80:
    // 0x80387D80: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387D84: addiu       $a1, $a1, -0x7100
    ctx->r5 = ADD32(ctx->r5, -0X7100);
    // 0x80387D88: jal         0x80005670
    // 0x80387D8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_18;
    // 0x80387D8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_18:
    // 0x80387D90: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80387D94: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x80387D98: sh          $zero, 0x90($v0)
    MEM_H(0X90, ctx->r2) = 0;
    // 0x80387D9C: sb          $t2, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r10;
    // 0x80387DA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80387DA4: jal         0x8022B640
    // 0x80387DA8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_19;
    // 0x80387DA8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_19:
    // 0x80387DAC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80387DB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80387DB4: addiu       $t5, $v0, 0x10
    ctx->r13 = ADD32(ctx->r2, 0X10);
    // 0x80387DB8: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x80387DBC: sh          $t5, 0x9A($v1)
    MEM_H(0X9A, ctx->r3) = ctx->r13;
    // 0x80387DC0: lhu         $t4, 0x46($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X46);
    // 0x80387DC4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80387DC8: sh          $t6, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r14;
L_80387DCC:
    // 0x80387DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80387DD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80387DD4: jr          $ra
    // 0x80387DD8: nop

    return;
    // 0x80387DD8: nop

;}
RECOMP_FUNC void M55_FUN_80387ddc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387DDC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80387DE0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80387DE4: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80387DE8: lh          $t6, 0x66($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X66);
    // 0x80387DEC: lh          $t7, 0x6A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6A);
    // 0x80387DF0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80387DF4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80387DF8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80387DFC: lw          $v0, 0x2594($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2594);
    // 0x80387E00: sh          $t8, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r24;
    // 0x80387E04: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x80387E08: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x80387E0C: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x80387E10: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80387E14: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80387E18: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x80387E1C: addiu       $t3, $zero, 0x30
    ctx->r11 = ADD32(0, 0X30);
    // 0x80387E20: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x80387E24: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80387E28: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x80387E2C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80387E30: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80387E34: addiu       $t9, $zero, 0x66
    ctx->r25 = ADD32(0, 0X66);
    // 0x80387E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80387E3C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80387E40: sh          $t1, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r9;
    // 0x80387E44: sh          $t0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r8;
    // 0x80387E48: sh          $t3, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r11;
    // 0x80387E4C: sh          $t2, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r10;
    // 0x80387E50: sb          $t5, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r13;
    // 0x80387E54: sb          $t4, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r12;
    // 0x80387E58: sb          $t6, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r14;
    // 0x80387E5C: sb          $t7, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r15;
    // 0x80387E60: sb          $zero, 0x32($sp)
    MEM_B(0X32, ctx->r29) = 0;
    // 0x80387E64: sb          $zero, 0x31($sp)
    MEM_B(0X31, ctx->r29) = 0;
    // 0x80387E68: sb          $zero, 0x30($sp)
    MEM_B(0X30, ctx->r29) = 0;
    // 0x80387E6C: sb          $t8, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r24;
    // 0x80387E70: sh          $t9, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r25;
    // 0x80387E74: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x80387E78: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80387E7C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80387E80: andi        $t3, $a3, 0xFFFF
    ctx->r11 = ctx->r7 & 0XFFFF;
    // 0x80387E84: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80387E88: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80387E8C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80387E90: sh          $t1, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r9;
    // 0x80387E94: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80387E98: addiu       $a1, $a1, -0x70EC
    ctx->r5 = ADD32(ctx->r5, -0X70EC);
    // 0x80387E9C: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x80387EA0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80387EA4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80387EA8: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x80387EAC: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // 0x80387EB0: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80387EB4: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80387EB8: jal         0x80146088
    // 0x80387EBC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x80387EBC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_0:
    // 0x80387EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80387EC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80387EC8: jr          $ra
    // 0x80387ECC: nop

    return;
    // 0x80387ECC: nop

;}
RECOMP_FUNC void M55_FUN_80387ed0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80387ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80387ED8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80387EDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80387EE0: addiu       $a1, $zero, 0x12F
    ctx->r5 = ADD32(0, 0X12F);
    // 0x80387EE4: jal         0x80126A0C
    // 0x80387EE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x80387EE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80387EEC: beq         $v0, $zero, L_80387F00
    if (ctx->r2 == 0) {
        // 0x80387EF0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80387F00;
    }
    // 0x80387EF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80387EF4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80387EF8: jal         0x800058DC
    // 0x80387EFC: addiu       $a1, $a1, 0x7F10
    ctx->r5 = ADD32(ctx->r5, 0X7F10);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80387EFC: addiu       $a1, $a1, 0x7F10
    ctx->r5 = ADD32(ctx->r5, 0X7F10);
    after_1:
L_80387F00:
    // 0x80387F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80387F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80387F08: jr          $ra
    // 0x80387F0C: nop

    return;
    // 0x80387F0C: nop

;}
RECOMP_FUNC void M55_FUN_80387f10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387F10: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80387F14: lbu         $t6, -0x33DB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80387f18(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80387f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80387F1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80387F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80387F24: bne         $t6, $at, L_80387F38
    if (ctx->r14 != ctx->r1) {
        // 0x80387F28: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80387F38;
    }
    // 0x80387F28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80387F2C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80387F30: jal         0x800058DC
    // 0x80387F34: addiu       $a1, $a1, 0x7F48
    ctx->r5 = ADD32(ctx->r5, 0X7F48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80387F34: addiu       $a1, $a1, 0x7F48
    ctx->r5 = ADD32(ctx->r5, 0X7F48);
    after_0:
L_80387F38:
    // 0x80387F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80387F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80387F40: jr          $ra
    // 0x80387F44: nop

    return;
    // 0x80387F44: nop

;}
RECOMP_FUNC void M55_FUN_80387f48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387F48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80387F4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80387F50: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80387F54: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80387F58: sb          $zero, 0x47($sp)
    MEM_B(0X47, ctx->r29) = 0;
    // 0x80387F5C: lbu         $v1, 0x9C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X9C);
    // 0x80387F60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80387F64: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80387F68: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80387F6C: bne         $v0, $zero, L_80388374
    if (ctx->r2 != 0) {
        // 0x80387F70: sb          $t6, 0x9C($a0)
        MEM_B(0X9C, ctx->r4) = ctx->r14;
            goto L_80388374;
    }
    // 0x80387F70: sb          $t6, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r14;
    // 0x80387F74: jal         0x80116E80
    // 0x80387F78: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x80387F78: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x80387F7C: addiu       $t7, $sp, 0x47
    ctx->r15 = ADD32(ctx->r29, 0X47);
    // 0x80387F80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80387F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80387F88: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80387F8C: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80387F90: jal         0x80387DDC
    // 0x80387F94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_1;
    // 0x80387F94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80387F98: addiu       $t8, $sp, 0x47
    ctx->r24 = ADD32(ctx->r29, 0X47);
    // 0x80387F9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80387FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80387FA4: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80387FA8: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80387FAC: jal         0x80387DDC
    // 0x80387FB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_2;
    // 0x80387FB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80387FB4: addiu       $t9, $sp, 0x47
    ctx->r25 = ADD32(ctx->r29, 0X47);
    // 0x80387FB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80387FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80387FC0: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x80387FC4: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80387FC8: jal         0x80387DDC
    // 0x80387FCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_3;
    // 0x80387FCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80387FD0: addiu       $t0, $sp, 0x47
    ctx->r8 = ADD32(ctx->r29, 0X47);
    // 0x80387FD4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80387FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80387FDC: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80387FE0: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80387FE4: jal         0x80387DDC
    // 0x80387FE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_4;
    // 0x80387FE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80387FEC: addiu       $t1, $sp, 0x47
    ctx->r9 = ADD32(ctx->r29, 0X47);
    // 0x80387FF0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80387FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80387FF8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x80387FFC: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80388000: jal         0x80387DDC
    // 0x80388004: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_5;
    // 0x80388004: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80388008: addiu       $t2, $sp, 0x47
    ctx->r10 = ADD32(ctx->r29, 0X47);
    // 0x8038800C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80388010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80388014: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
    // 0x80388018: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x8038801C: jal         0x80387DDC
    // 0x80388020: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_6;
    // 0x80388020: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80388024: addiu       $t3, $sp, 0x47
    ctx->r11 = ADD32(ctx->r29, 0X47);
    // 0x80388028: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8038802C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80388030: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    // 0x80388034: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80388038: jal         0x80387DDC
    // 0x8038803C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_7;
    // 0x8038803C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80388040: addiu       $t4, $sp, 0x47
    ctx->r12 = ADD32(ctx->r29, 0X47);
    // 0x80388044: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80388048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038804C: addiu       $a1, $zero, 0x9E
    ctx->r5 = ADD32(0, 0X9E);
    // 0x80388050: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80388054: jal         0x80387DDC
    // 0x80388058: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_8;
    // 0x80388058: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8038805C: addiu       $t5, $sp, 0x47
    ctx->r13 = ADD32(ctx->r29, 0X47);
    // 0x80388060: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80388064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80388068: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    // 0x8038806C: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80388070: jal         0x80387DDC
    // 0x80388074: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_9;
    // 0x80388074: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80388078: addiu       $t6, $sp, 0x47
    ctx->r14 = ADD32(ctx->r29, 0X47);
    // 0x8038807C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80388080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80388084: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x80388088: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x8038808C: jal         0x80387DDC
    // 0x80388090: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_10;
    // 0x80388090: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80388094: addiu       $t7, $sp, 0x47
    ctx->r15 = ADD32(ctx->r29, 0X47);
    // 0x80388098: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8038809C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803880A0: addiu       $a1, $zero, 0xCE
    ctx->r5 = ADD32(0, 0XCE);
    // 0x803880A4: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x803880A8: jal         0x80387DDC
    // 0x803880AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_11;
    // 0x803880AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x803880B0: addiu       $t8, $sp, 0x47
    ctx->r24 = ADD32(ctx->r29, 0X47);
    // 0x803880B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x803880B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803880BC: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x803880C0: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x803880C4: jal         0x80387DDC
    // 0x803880C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_12;
    // 0x803880C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x803880CC: addiu       $t9, $sp, 0x47
    ctx->r25 = ADD32(ctx->r29, 0X47);
    // 0x803880D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x803880D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803880D8: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x803880DC: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x803880E0: jal         0x80387DDC
    // 0x803880E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_13;
    // 0x803880E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x803880E8: addiu       $t0, $sp, 0x47
    ctx->r8 = ADD32(ctx->r29, 0X47);
    // 0x803880EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x803880F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803880F4: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    // 0x803880F8: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x803880FC: jal         0x80387DDC
    // 0x80388100: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80387DDC)(rdram, ctx);
        goto after_14;
    // 0x80388100: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x80388104: jal         0x80006214
    // 0x80388108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_15;
    // 0x80388108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8038810C: lbu         $v1, 0x98($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X98);
    // 0x80388110: beq         $v1, $zero, L_80388264
    if (ctx->r3 == 0) {
        // 0x80388114: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_80388264;
    }
    // 0x80388114: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80388118: beq         $v0, $zero, L_80388138
    if (ctx->r2 == 0) {
        // 0x8038811C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80388138;
    }
    // 0x8038811C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80388120: beq         $v0, $at, L_8038819C
    if (ctx->r2 == ctx->r1) {
        // 0x80388124: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8038819C;
    }
    // 0x80388124: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80388128: beq         $v0, $at, L_80388200
    if (ctx->r2 == ctx->r1) {
        // 0x8038812C: nop
    
            goto L_80388200;
    }
    // 0x8038812C: nop

    // 0x80388130: b           L_80388360
    // 0x80388134: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
        goto L_80388360;
    // 0x80388134: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_80388138:
    // 0x80388138: jal         0x8013D5F4
    // 0x8038813C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_16;
    // 0x8038813C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_16:
    // 0x80388140: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80388144: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80388148: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8038814C: addiu       $a3, $a3, -0x6230
    ctx->r7 = ADD32(ctx->r7, -0X6230);
    // 0x80388150: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80388154: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80388158: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x8038815C: jal         0x8001B204
    // 0x80388160: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_17;
    // 0x80388160: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_17:
    // 0x80388164: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80388168: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8038816C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80388170: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80388174: lhu         $t4, 0x9A($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X9A);
    // 0x80388178: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8038817C: addiu       $a3, $a3, -0x6228
    ctx->r7 = ADD32(ctx->r7, -0X6228);
    // 0x80388180: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80388184: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80388188: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    // 0x8038818C: jal         0x8001B204
    // 0x80388190: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_18;
    // 0x80388190: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_18:
    // 0x80388194: b           L_80388360
    // 0x80388198: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
        goto L_80388360;
    // 0x80388198: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_8038819C:
    // 0x8038819C: jal         0x8013D5F4
    // 0x803881A0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_19;
    // 0x803881A0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_19:
    // 0x803881A4: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803881A8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x803881AC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x803881B0: addiu       $a3, $a3, -0x6208
    ctx->r7 = ADD32(ctx->r7, -0X6208);
    // 0x803881B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x803881B8: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x803881BC: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x803881C0: jal         0x8001B204
    // 0x803881C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_20;
    // 0x803881C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_20:
    // 0x803881C8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x803881CC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x803881D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x803881D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803881D8: lhu         $t8, 0x9A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X9A);
    // 0x803881DC: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803881E0: addiu       $a3, $a3, -0x6200
    ctx->r7 = ADD32(ctx->r7, -0X6200);
    // 0x803881E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x803881E8: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x803881EC: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    // 0x803881F0: jal         0x8001B204
    // 0x803881F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_21;
    // 0x803881F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_21:
    // 0x803881F8: b           L_80388360
    // 0x803881FC: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
        goto L_80388360;
    // 0x803881FC: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_80388200:
    // 0x80388200: jal         0x8013D5F4
    // 0x80388204: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_22;
    // 0x80388204: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_22:
    // 0x80388208: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8038820C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80388210: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80388214: addiu       $a3, $a3, -0x61E0
    ctx->r7 = ADD32(ctx->r7, -0X61E0);
    // 0x80388218: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8038821C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80388220: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x80388224: jal         0x8001B204
    // 0x80388228: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_23;
    // 0x80388228: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_23:
    // 0x8038822C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80388230: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80388234: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80388238: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8038823C: lhu         $t2, 0x9A($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X9A);
    // 0x80388240: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80388244: addiu       $a3, $a3, -0x61D8
    ctx->r7 = ADD32(ctx->r7, -0X61D8);
    // 0x80388248: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8038824C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80388250: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    // 0x80388254: jal         0x8001B204
    // 0x80388258: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_24;
    // 0x80388258: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_24:
    // 0x8038825C: b           L_80388360
    // 0x80388260: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
        goto L_80388360;
    // 0x80388260: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_80388264:
    // 0x80388264: jal         0x8013D5F4
    // 0x80388268: lbu         $a0, 0x93($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X93);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_25;
    // 0x80388268: lbu         $a0, 0x93($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X93);
    after_25:
    // 0x8038826C: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80388270: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80388274: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80388278: addiu       $a3, $a3, -0x61BC
    ctx->r7 = ADD32(ctx->r7, -0X61BC);
    // 0x8038827C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80388280: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80388284: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x80388288: jal         0x8001B204
    // 0x8038828C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_26;
    // 0x8038828C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_26:
    // 0x80388290: lhu         $v1, 0x92($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X92);
    // 0x80388294: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80388298: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8038829C: beq         $v1, $at, L_803882B0
    if (ctx->r3 == ctx->r1) {
        // 0x803882A0: addiu       $a1, $zero, 0x3A
        ctx->r5 = ADD32(0, 0X3A);
            goto L_803882B0;
    }
    // 0x803882A0: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x803882A4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x803882A8: bne         $v1, $at, L_803882DC
    if (ctx->r3 != ctx->r1) {
        // 0x803882AC: addiu       $a2, $zero, 0x4B
        ctx->r6 = ADD32(0, 0X4B);
            goto L_803882DC;
    }
    // 0x803882AC: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
L_803882B0:
    // 0x803882B0: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803882B4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x803882B8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x803882BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x803882C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x803882C4: addiu       $a3, $a3, -0x61B4
    ctx->r7 = ADD32(ctx->r7, -0X61B4);
    // 0x803882C8: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    // 0x803882CC: jal         0x8001B204
    // 0x803882D0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_27;
    // 0x803882D0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_27:
    // 0x803882D4: b           L_8038830C
    // 0x803882D8: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
        goto L_8038830C;
    // 0x803882D8: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
L_803882DC:
    // 0x803882DC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x803882E0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x803882E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x803882E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803882EC: lhu         $t8, 0x90($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X90);
    // 0x803882F0: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803882F4: addiu       $a3, $a3, -0x6190
    ctx->r7 = ADD32(ctx->r7, -0X6190);
    // 0x803882F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x803882FC: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80388300: jal         0x8001B204
    // 0x80388304: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_28;
    // 0x80388304: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_28:
    // 0x80388308: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
L_8038830C:
    // 0x8038830C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80388310: beql        $v0, $zero, L_80388360
    if (ctx->r2 == 0) {
        // 0x80388314: addiu       $t3, $zero, 0x3C
        ctx->r11 = ADD32(0, 0X3C);
            goto L_80388360;
    }
    goto skip_0;
    // 0x80388314: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    skip_0:
    // 0x80388318: bne         $v0, $at, L_80388334
    if (ctx->r2 != ctx->r1) {
        // 0x8038831C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80388334;
    }
    // 0x8038831C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80388320: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80388324: addiu       $v0, $v0, -0x23C0
    ctx->r2 = ADD32(ctx->r2, -0X23C0);
    // 0x80388328: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8038832C: b           L_8038835C
    // 0x80388330: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
        goto L_8038835C;
    // 0x80388330: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_80388334:
    // 0x80388334: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80388338: addiu       $v0, $v0, -0x23C0
    ctx->r2 = ADD32(ctx->r2, -0X23C0);
    // 0x8038833C: lhu         $t0, 0x2($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2);
    // 0x80388340: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80388344: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80388348: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8038834C: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80388350: beq         $at, $zero, L_8038835C
    if (ctx->r1 == 0) {
        // 0x80388354: sh          $t1, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r9;
            goto L_8038835C;
    }
    // 0x80388354: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x80388358: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
L_8038835C:
    // 0x8038835C: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_80388360:
    // 0x80388360: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80388364: sw          $t3, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r11;
    // 0x80388368: addiu       $a1, $a1, -0x7C78
    ctx->r5 = ADD32(ctx->r5, -0X7C78);
    // 0x8038836C: jal         0x800058DC
    // 0x80388370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_29;
    // 0x80388370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_80388374:
    // 0x80388374: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80388378: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8038837C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80388380: jr          $ra
    // 0x80388384: nop

    return;
    // 0x80388384: nop

;}
RECOMP_FUNC void M55_FUN_80388388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80388388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8038838C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80388390: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80388394: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80388398: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8038839C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803883A0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x803883A4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x803883A8: bltz        $v0, L_803883BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x803883AC: sw          $t6, 0xB0($a0)
        MEM_W(0XB0, ctx->r4) = ctx->r14;
            goto L_803883BC;
    }
    // 0x803883AC: sw          $t6, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r14;
    // 0x803883B0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x803883B4: lbu         $t7, -0x33DB($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X33DB);
    // 0x803883B8: bne         $t7, $zero, L_80388430
    if (ctx->r15 != 0) {
        // 0x803883BC: lui         $a3, 0x8039
        ctx->r7 = S32(0X8039 << 16);
            goto L_80388430;
    }
L_803883BC:
    // 0x803883BC: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803883C0: addiu       $a3, $a3, -0x6170
    ctx->r7 = ADD32(ctx->r7, -0X6170);
    // 0x803883C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x803883C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803883CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803883D0: jal         0x8001B204
    // 0x803883D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x803883D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x803883D8: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803883DC: addiu       $a3, $a3, -0x616C
    ctx->r7 = ADD32(ctx->r7, -0X616C);
    // 0x803883E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x803883E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803883E8: jal         0x8001B204
    // 0x803883EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x803883EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x803883F0: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
    // 0x803883F4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
L_803883F8:
    // 0x803883F8: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x803883FC: jal         0x80006088
    // 0x80388400: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_2;
    // 0x80388400: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_2:
    // 0x80388404: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80388408: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x8038840C: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80388410: bgezl       $s0, L_803883F8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80388414: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_803883F8;
    }
    goto skip_0;
    // 0x80388414: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    skip_0:
    // 0x80388418: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8038841C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80388420: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80388424: addiu       $a1, $a1, -0x7BBC
    ctx->r5 = ADD32(ctx->r5, -0X7BBC);
    // 0x80388428: jal         0x800058DC
    // 0x8038842C: sw          $t0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8038842C: sw          $t0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r8;
    after_3:
L_80388430:
    // 0x80388430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80388434: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80388438: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8038843C: jr          $ra
    // 0x80388440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80388440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80388444(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80388444(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80388444u);
    return;
}
RECOMP_FUNC void M55_FUN_8038871c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8038871Cu);
    return;
}
RECOMP_FUNC void M55_FUN_803899c8(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803899C8u);
    return;
}
RECOMP_FUNC void M55_FUN_803899cc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803899CCu);
    return;
}
