#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801c8e84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8E84: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x801C8E88: sw          $s3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r19;
    // 0x801C8E8C: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801C8E90: addiu       $s3, $s3, -0x4410
    ctx->r19 = ADD32(ctx->r19, -0X4410);
    // 0x801C8E94: lw          $t6, 0xDC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XDC);
    // 0x801C8E98: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x801C8E9C: sw          $s2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r18;
    // 0x801C8EA0: sw          $s1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r17;
    // 0x801C8EA4: sw          $s0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r16;
    // 0x801C8EA8: sdc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X70, ctx->r29);
    // 0x801C8EAC: sdc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X68, ctx->r29);
    // 0x801C8EB0: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x801C8EB4: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x801C8EB8: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x801C8EBC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x801C8EC0: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x801C8EC4: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    // 0x801C8EC8: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C8ECC: lw          $s2, 0x5C($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X5C);
    // 0x801C8ED0: addiu       $t8, $t8, 0xC88
    ctx->r24 = ADD32(ctx->r24, 0XC88);
    // 0x801C8ED4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801C8ED8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801C8EDC: addiu       $t7, $sp, 0xD0
    ctx->r15 = ADD32(ctx->r29, 0XD0);
    // 0x801C8EE0: lwc1        $f20, 0x24($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X24);
    // 0x801C8EE4: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x801C8EE8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x801C8EEC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x801C8EF0: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801C8EF4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C8EF8: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x801C8EFC: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x801C8F00: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x801C8F04: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x801C8F08: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801C8F0C: sw          $t0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r8;
    // 0x801C8F10: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
    // 0x801C8F14: lw          $t1, 0xE0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XE0);
    // 0x801C8F18: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C8F1C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C8F20: lw          $s0, 0x2C($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X2C);
    // 0x801C8F24: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x801C8F28: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x801C8F2C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C8F30: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C8F34: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801C8F38: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801C8F3C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801C8F40: sub.d       $f8, $f2, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f26.d); 
    ctx->f8.d = ctx->f2.d - ctx->f26.d;
    // 0x801C8F44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801C8F48: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801C8F4C: add.d       $f6, $f2, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f30.d); 
    ctx->f6.d = ctx->f2.d + ctx->f30.d;
    // 0x801C8F50: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C8F54: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801C8F58: jal         0x801C5A1C
    // 0x801C8F5C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_0;
    // 0x801C8F5C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801C8F60: bne         $v0, $zero, L_801C906C
    if (ctx->r2 != 0) {
        // 0x801C8F64: swc1        $f20, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
            goto L_801C906C;
    }
    // 0x801C8F64: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    // 0x801C8F68: lw          $t2, 0xE0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XE0);
    // 0x801C8F6C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C8F70: jal         0x8001EAD0
    // 0x801C8F74: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801C8F74: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x801C8F78: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801C8F7C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C8F80: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C8F84: jal         0x8001EB64
    // 0x801C8F88: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801C8F88: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_2:
    // 0x801C8F8C: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801C8F90: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801C8F94: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C8F98: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801C8F9C: jal         0x8001EAD0
    // 0x801C8FA0: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801C8FA0: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x801C8FA4: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801C8FA8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801C8FAC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C8FB0: jal         0x8001EB64
    // 0x801C8FB4: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x801C8FB4: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_4:
    // 0x801C8FB8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C8FBC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C8FC0: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801C8FC4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C8FC8: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801C8FCC: lw          $s0, 0x2C($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X2C);
    // 0x801C8FD0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C8FD4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C8FD8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C8FDC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C8FE0: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x801C8FE4: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801C8FE8: add.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d + ctx->f16.d;
    // 0x801C8FEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C8FF0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801C8FF4: add.d       $f8, $f2, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f30.d); 
    ctx->f8.d = ctx->f2.d + ctx->f30.d;
    // 0x801C8FF8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801C8FFC: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801C9000: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801C9004: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801C9008: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801C900C: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x801C9010: add.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f8.d + ctx->f18.d;
    // 0x801C9014: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C9018: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C901C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C9020: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C9024: sub.d       $f8, $f2, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f26.d); 
    ctx->f8.d = ctx->f2.d - ctx->f26.d;
    // 0x801C9028: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801C902C: add.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d + ctx->f16.d;
    // 0x801C9030: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C9034: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801C9038: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C903C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801C9040: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C9044: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801C9048: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C904C: nop

    // 0x801C9050: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801C9054: add.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f8.d + ctx->f18.d;
    // 0x801C9058: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C905C: jal         0x801C5A1C
    // 0x801C9060: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_5;
    // 0x801C9060: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x801C9064: beql        $v0, $zero, L_801CB6EC
    if (ctx->r2 == 0) {
        // 0x801C9068: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_801CB6EC;
    }
    goto skip_0;
    // 0x801C9068: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_0:
L_801C906C:
    // 0x801C906C: lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X4);
    // 0x801C9070: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C9074: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801C9078: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801C907C: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x801C9080: beq         $v0, $at, L_801C9094
    if (ctx->r2 == ctx->r1) {
        // 0x801C9084: lwc1        $f20, 0xEC($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0XEC);
            goto L_801C9094;
    }
    // 0x801C9084: lwc1        $f20, 0xEC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x801C9088: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x801C908C: bnel        $v0, $at, L_801C90A4
    if (ctx->r2 != ctx->r1) {
        // 0x801C9090: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_801C90A4;
    }
    goto skip_1;
    // 0x801C9090: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    skip_1:
L_801C9094:
    // 0x801C9094: lbu         $t1, 0x35B($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X35B);
    // 0x801C9098: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x801C909C: beq         $at, $zero, L_801C90BC
    if (ctx->r1 == 0) {
        // 0x801C90A0: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_801C90BC;
    }
    // 0x801C90A0: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
L_801C90A4:
    // 0x801C90A4: bnel        $v0, $at, L_801CB6EC
    if (ctx->r2 != ctx->r1) {
        // 0x801C90A8: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_801CB6EC;
    }
    goto skip_2;
    // 0x801C90A8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_2:
    // 0x801C90AC: lbu         $t2, 0x35B($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X35B);
    // 0x801C90B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C90B4: bnel        $t2, $at, L_801CB6EC
    if (ctx->r10 != ctx->r1) {
        // 0x801C90B8: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_801CB6EC;
    }
    goto skip_3;
    // 0x801C90B8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_3:
L_801C90BC:
    // 0x801C90BC: jal         0x8012C6B4
    // 0x801C90C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801C90C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x801C90C4: sb          $v0, 0xEB($sp)
    MEM_B(0XEB, ctx->r29) = ctx->r2;
    // 0x801C90C8: addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
    // 0x801C90CC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801C90D0: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C90D4: ori         $at, $at, 0x18
    ctx->r1 = ctx->r1 | 0X18;
    // 0x801C90D8: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x801C90DC: bne         $at, $zero, L_801C9184
    if (ctx->r1 != 0) {
        // 0x801C90E0: lui         $at, 0x190
        ctx->r1 = S32(0X190 << 16);
            goto L_801C9184;
    }
    // 0x801C90E0: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x801C90E4: ori         $at, $at, 0x4D
    ctx->r1 = ctx->r1 | 0X4D;
    // 0x801C90E8: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x801C90EC: bne         $at, $zero, L_801C911C
    if (ctx->r1 != 0) {
        // 0x801C90F0: lui         $at, 0xFE6F
        ctx->r1 = S32(0XFE6F << 16);
            goto L_801C911C;
    }
    // 0x801C90F0: lui         $at, 0xFE6F
    ctx->r1 = S32(0XFE6F << 16);
    // 0x801C90F4: ori         $at, $at, 0xFF96
    ctx->r1 = ctx->r1 | 0XFF96;
    // 0x801C90F8: addu        $t3, $v1, $at
    ctx->r11 = ADD32(ctx->r3, ctx->r1);
    // 0x801C90FC: sltiu       $at, $t3, 0x9
    ctx->r1 = ctx->r11 < 0X9 ? 1 : 0;
    // 0x801C9100: beq         $at, $zero, L_801CB644
    if (ctx->r1 == 0) {
        // 0x801C9104: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_801CB644;
    }
    // 0x801C9104: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801C9108: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C910C: addu        $at, $at, $t3
    gpr jr_addend_801C9114 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801C9110: lw          $t3, 0x3024($at)
    ctx->r11 = ADD32(ctx->r1, 0X3024);
    // 0x801C9114: jr          $t3
    // 0x801C9118: nop

    switch (jr_addend_801C9114 >> 2) {
        case 0: goto L_801CB09C; break;
        case 1: goto L_801CB09C; break;
        case 2: goto L_801CB644; break;
        case 3: goto L_801CB09C; break;
        case 4: goto L_801CB09C; break;
        case 5: goto L_801CB09C; break;
        case 6: goto L_801CB09C; break;
        case 7: goto L_801CB09C; break;
        case 8: goto L_801CB09C; break;
        default: switch_error(__func__, 0x801C9114, 0x801E3024);
    }
    // 0x801C9118: nop

L_801C911C:
    // 0x801C911C: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C9120: ori         $at, $at, 0x59
    ctx->r1 = ctx->r1 | 0X59;
    // 0x801C9124: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x801C9128: bne         $at, $zero, L_801C9158
    if (ctx->r1 != 0) {
        // 0x801C912C: lui         $at, 0xFE6F
        ctx->r1 = S32(0XFE6F << 16);
            goto L_801C9158;
    }
    // 0x801C912C: lui         $at, 0xFE6F
    ctx->r1 = S32(0XFE6F << 16);
    // 0x801C9130: ori         $at, $at, 0xFFBB
    ctx->r1 = ctx->r1 | 0XFFBB;
    // 0x801C9134: addu        $t4, $v1, $at
    ctx->r12 = ADD32(ctx->r3, ctx->r1);
    // 0x801C9138: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x801C913C: beq         $at, $zero, L_801CB644
    if (ctx->r1 == 0) {
        // 0x801C9140: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_801CB644;
    }
    // 0x801C9140: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801C9144: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9148: addu        $at, $at, $t4
    gpr jr_addend_801C9150 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801C914C: lw          $t4, 0x3048($at)
    ctx->r12 = ADD32(ctx->r1, 0X3048);
    // 0x801C9150: jr          $t4
    // 0x801C9154: nop

    switch (jr_addend_801C9150 >> 2) {
        case 0: goto L_801CB09C; break;
        case 1: goto L_801CB09C; break;
        case 2: goto L_801CB09C; break;
        case 3: goto L_801CB09C; break;
        case 4: goto L_801CB09C; break;
        case 5: goto L_801CB09C; break;
        case 6: goto L_801CB09C; break;
        case 7: goto L_801CB09C; break;
        default: switch_error(__func__, 0x801C9150, 0x801E3048);
    }
    // 0x801C9154: nop

L_801C9158:
    // 0x801C9158: lui         $at, 0xFE97
    ctx->r1 = S32(0XFE97 << 16);
    // 0x801C915C: ori         $at, $at, 0xFFC9
    ctx->r1 = ctx->r1 | 0XFFC9;
    // 0x801C9160: addu        $t5, $v1, $at
    ctx->r13 = ADD32(ctx->r3, ctx->r1);
    // 0x801C9164: sltiu       $at, $t5, 0x22
    ctx->r1 = ctx->r13 < 0X22 ? 1 : 0;
    // 0x801C9168: beq         $at, $zero, L_801CB644
    if (ctx->r1 == 0) {
        // 0x801C916C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_801CB644;
    }
    // 0x801C916C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801C9170: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9174: addu        $at, $at, $t5
    gpr jr_addend_801C917C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801C9178: lw          $t5, 0x3068($at)
    ctx->r13 = ADD32(ctx->r1, 0X3068);
    // 0x801C917C: jr          $t5
    // 0x801C9180: nop

    switch (jr_addend_801C917C >> 2) {
        case 0: goto L_801CADB4; break;
        case 1: goto L_801CADB4; break;
        case 2: goto L_801CB644; break;
        case 3: goto L_801CB644; break;
        case 4: goto L_801CB644; break;
        case 5: goto L_801CB644; break;
        case 6: goto L_801CB644; break;
        case 7: goto L_801C92F0; break;
        case 8: goto L_801C9518; break;
        case 9: goto L_801C9AEC; break;
        case 10: goto L_801CB644; break;
        case 11: goto L_801CB644; break;
        case 12: goto L_801CB644; break;
        case 13: goto L_801CB644; break;
        case 14: goto L_801CB644; break;
        case 15: goto L_801CB644; break;
        case 16: goto L_801CB644; break;
        case 17: goto L_801CB644; break;
        case 18: goto L_801CB644; break;
        case 19: goto L_801CB644; break;
        case 20: goto L_801CB644; break;
        case 21: goto L_801CAE60; break;
        case 22: goto L_801CB370; break;
        case 23: goto L_801C9AEC; break;
        case 24: goto L_801CB644; break;
        case 25: goto L_801CB370; break;
        case 26: goto L_801CB370; break;
        case 27: goto L_801CB370; break;
        case 28: goto L_801CB644; break;
        case 29: goto L_801CB644; break;
        case 30: goto L_801CB644; break;
        case 31: goto L_801CB644; break;
        case 32: goto L_801CB644; break;
        case 33: goto L_801CB644; break;
        default: switch_error(__func__, 0x801C917C, 0x801E3068);
    }
    // 0x801C9180: nop

L_801C9184:
    // 0x801C9184: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C9188: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x801C918C: beq         $v1, $at, L_801C91B4
    if (ctx->r3 == ctx->r1) {
        // 0x801C9190: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C91B4;
    }
    // 0x801C9190: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C9194: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801C9198: beq         $v1, $at, L_801CABE4
    if (ctx->r3 == ctx->r1) {
        // 0x801C919C: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801CABE4;
    }
    // 0x801C919C: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C91A0: ori         $at, $at, 0x17
    ctx->r1 = ctx->r1 | 0X17;
    // 0x801C91A4: beq         $v1, $at, L_801CADB4
    if (ctx->r3 == ctx->r1) {
        // 0x801C91A8: nop
    
            goto L_801CADB4;
    }
    // 0x801C91A8: nop

    // 0x801C91AC: b           L_801CB648
    // 0x801C91B0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
        goto L_801CB648;
    // 0x801C91B0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
L_801C91B4:
    // 0x801C91B4: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x801C91B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C91BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C91C0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C91C4: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801C91C8: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x801C91CC: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x801C91D0: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x801C91D4: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801C91D8: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C91DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C91E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C91E4: nop

    // 0x801C91E8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C91EC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C91F0: nop

    // 0x801C91F4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C91F8: beql        $t7, $zero, L_801C9248
    if (ctx->r15 == 0) {
        // 0x801C91FC: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_801C9248;
    }
    goto skip_4;
    // 0x801C91FC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x801C9200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C9204: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C9208: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C920C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C9210: nop

    // 0x801C9214: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C9218: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C921C: nop

    // 0x801C9220: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C9224: bne         $t7, $zero, L_801C923C
    if (ctx->r15 != 0) {
        // 0x801C9228: nop
    
            goto L_801C923C;
    }
    // 0x801C9228: nop

    // 0x801C922C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x801C9230: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9234: b           L_801C9254
    // 0x801C9238: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801C9254;
    // 0x801C9238: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801C923C:
    // 0x801C923C: b           L_801C9254
    // 0x801C9240: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801C9254;
    // 0x801C9240: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C9244: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_801C9248:
    // 0x801C9248: nop

    // 0x801C924C: bltz        $t7, L_801C923C
    if (SIGNED(ctx->r15) < 0) {
        // 0x801C9250: nop
    
            goto L_801C923C;
    }
    // 0x801C9250: nop

L_801C9254:
    // 0x801C9254: lhu         $t9, 0x4($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X4);
    // 0x801C9258: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C925C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801C9260: bne         $t8, $t9, L_801CB6E8
    if (ctx->r24 != ctx->r25) {
        // 0x801C9264: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_801CB6E8;
    }
    // 0x801C9264: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C9268: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801C926C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C9270: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C9274: lw          $s0, 0x2C($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X2C);
    // 0x801C9278: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C927C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9280: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C9284: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C9288: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801C928C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C9290: lwc1        $f4, 0x30F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X30F0);
    // 0x801C9294: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C9298: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801C929C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801C92A0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C92A4: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801C92A8: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x801C92AC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x801C92B0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x801C92B4: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x801C92B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C92BC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801C92C0: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801C92C4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801C92C8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801C92CC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x801C92D0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801C92D4: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801C92D8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801C92DC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801C92E0: jal         0x801E02DC
    // 0x801C92E4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_7;
    // 0x801C92E4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x801C92E8: b           L_801CB6EC
    // 0x801C92EC: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
        goto L_801CB6EC;
    // 0x801C92EC: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801C92F0:
    // 0x801C92F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C92F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C92F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C92FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9300: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801C9304: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801C9308: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C930C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C9310: nop

    // 0x801C9314: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C9318: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C931C: nop

    // 0x801C9320: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C9324: beql        $t0, $zero, L_801C9374
    if (ctx->r8 == 0) {
        // 0x801C9328: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_801C9374;
    }
    goto skip_5;
    // 0x801C9328: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_5:
    // 0x801C932C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C9330: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C9334: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C9338: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C933C: nop

    // 0x801C9340: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C9344: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C9348: nop

    // 0x801C934C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C9350: bne         $t0, $zero, L_801C9368
    if (ctx->r8 != 0) {
        // 0x801C9354: nop
    
            goto L_801C9368;
    }
    // 0x801C9354: nop

    // 0x801C9358: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x801C935C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9360: b           L_801C9380
    // 0x801C9364: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801C9380;
    // 0x801C9364: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801C9368:
    // 0x801C9368: b           L_801C9380
    // 0x801C936C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801C9380;
    // 0x801C936C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801C9370: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_801C9374:
    // 0x801C9374: nop

    // 0x801C9378: bltz        $t0, L_801C9368
    if (SIGNED(ctx->r8) < 0) {
        // 0x801C937C: nop
    
            goto L_801C9368;
    }
    // 0x801C937C: nop

L_801C9380:
    // 0x801C9380: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C9384: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x801C9388: beq         $t1, $v1, L_801C9428
    if (ctx->r9 == ctx->r3) {
        // 0x801C938C: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_801C9428;
    }
    // 0x801C938C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801C9390: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C9394: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9398: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C939C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801C93A0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801C93A4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C93A8: nop

    // 0x801C93AC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C93B0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C93B4: nop

    // 0x801C93B8: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C93BC: beql        $t3, $zero, L_801C940C
    if (ctx->r11 == 0) {
        // 0x801C93C0: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_801C940C;
    }
    goto skip_6;
    // 0x801C93C0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x801C93C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C93C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C93CC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C93D0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C93D4: nop

    // 0x801C93D8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C93DC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C93E0: nop

    // 0x801C93E4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C93E8: bne         $t3, $zero, L_801C9400
    if (ctx->r11 != 0) {
        // 0x801C93EC: nop
    
            goto L_801C9400;
    }
    // 0x801C93EC: nop

    // 0x801C93F0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x801C93F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C93F8: b           L_801C9418
    // 0x801C93FC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801C9418;
    // 0x801C93FC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801C9400:
    // 0x801C9400: b           L_801C9418
    // 0x801C9404: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801C9418;
    // 0x801C9404: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801C9408: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_801C940C:
    // 0x801C940C: nop

    // 0x801C9410: bltz        $t3, L_801C9400
    if (SIGNED(ctx->r11) < 0) {
        // 0x801C9414: nop
    
            goto L_801C9400;
    }
    // 0x801C9414: nop

L_801C9418:
    // 0x801C9418: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801C941C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801C9420: bnel        $t4, $v1, L_801CB6EC
    if (ctx->r12 != ctx->r3) {
        // 0x801C9424: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_801CB6EC;
    }
    goto skip_7;
    // 0x801C9424: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_7:
L_801C9428:
    // 0x801C9428: lw          $t5, 0xE0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XE0);
    // 0x801C942C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C9430: jal         0x8001EAD0
    // 0x801C9434: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x801C9434: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_8:
    // 0x801C9438: lw          $t7, 0xE0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XE0);
    // 0x801C943C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801C9440: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C9444: jal         0x8001EB64
    // 0x801C9448: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x801C9448: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_9:
    // 0x801C944C: lw          $t9, 0xE0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9450: cvt.d.s     $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.d = CVT_D_S(ctx->f20.fl);
    // 0x801C9454: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C9458: lw          $s0, 0x2C($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X2C);
    // 0x801C945C: add.d       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f2.d + ctx->f2.d;
    // 0x801C9460: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C9464: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C9468: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801C946C: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x801C9470: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C9474: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C9478: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801C947C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C9480: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C9484: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801C9488: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801C948C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9490: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x801C9494: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801C9498: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801C949C: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x801C94A0: add.d       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f16.d + ctx->f16.d;
    // 0x801C94A4: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801C94A8: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801C94AC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C94B0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801C94B4: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C94B8: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x801C94BC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801C94C0: lwc1        $f4, 0x30F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X30F4);
    // 0x801C94C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C94C8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801C94CC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C94D0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801C94D4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801C94D8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801C94DC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801C94E0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801C94E4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801C94E8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801C94EC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C94F0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801C94F4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801C94F8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801C94FC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801C9500: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801C9504: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801C9508: jal         0x801E02DC
    // 0x801C950C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_10;
    // 0x801C950C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x801C9510: b           L_801CB6EC
    // 0x801C9514: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
        goto L_801CB6EC;
    // 0x801C9514: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801C9518:
    // 0x801C9518: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801C951C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C9520: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C9524: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9528: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801C952C: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801C9530: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C9534: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C9538: nop

    // 0x801C953C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C9540: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C9544: nop

    // 0x801C9548: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C954C: beql        $t9, $zero, L_801C959C
    if (ctx->r25 == 0) {
        // 0x801C9550: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_801C959C;
    }
    goto skip_8;
    // 0x801C9550: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_8:
    // 0x801C9554: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C9558: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C955C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C9560: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C9564: nop

    // 0x801C9568: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C956C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C9570: nop

    // 0x801C9574: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C9578: bne         $t9, $zero, L_801C9590
    if (ctx->r25 != 0) {
        // 0x801C957C: nop
    
            goto L_801C9590;
    }
    // 0x801C957C: nop

    // 0x801C9580: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801C9584: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9588: b           L_801C95A8
    // 0x801C958C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801C95A8;
    // 0x801C958C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801C9590:
    // 0x801C9590: b           L_801C95A8
    // 0x801C9594: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801C95A8;
    // 0x801C9594: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C9598: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_801C959C:
    // 0x801C959C: nop

    // 0x801C95A0: bltz        $t9, L_801C9590
    if (SIGNED(ctx->r25) < 0) {
        // 0x801C95A4: nop
    
            goto L_801C9590;
    }
    // 0x801C95A4: nop

L_801C95A8:
    // 0x801C95A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C95AC: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801C95B0: beq         $t0, $v1, L_801C9654
    if (ctx->r8 == ctx->r3) {
        // 0x801C95B4: lui         $at, 0x4190
        ctx->r1 = S32(0X4190 << 16);
            goto L_801C9654;
    }
    // 0x801C95B4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801C95B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C95BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C95C0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C95C4: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801C95C8: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    // 0x801C95CC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801C95D0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801C95D4: nop

    // 0x801C95D8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C95DC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801C95E0: nop

    // 0x801C95E4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801C95E8: beql        $t2, $zero, L_801C9638
    if (ctx->r10 == 0) {
        // 0x801C95EC: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_801C9638;
    }
    goto skip_9;
    // 0x801C95EC: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_9:
    // 0x801C95F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C95F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C95F8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C95FC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801C9600: nop

    // 0x801C9604: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C9608: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801C960C: nop

    // 0x801C9610: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801C9614: bne         $t2, $zero, L_801C962C
    if (ctx->r10 != 0) {
        // 0x801C9618: nop
    
            goto L_801C962C;
    }
    // 0x801C9618: nop

    // 0x801C961C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801C9620: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9624: b           L_801C9644
    // 0x801C9628: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_801C9644;
    // 0x801C9628: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_801C962C:
    // 0x801C962C: b           L_801C9644
    // 0x801C9630: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_801C9644;
    // 0x801C9630: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801C9634: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_801C9638:
    // 0x801C9638: nop

    // 0x801C963C: bltz        $t2, L_801C962C
    if (SIGNED(ctx->r10) < 0) {
        // 0x801C9640: nop
    
            goto L_801C962C;
    }
    // 0x801C9640: nop

L_801C9644:
    // 0x801C9644: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801C9648: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x801C964C: bnel        $t3, $v1, L_801C9808
    if (ctx->r11 != ctx->r3) {
        // 0x801C9650: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_801C9808;
    }
    goto skip_10;
    // 0x801C9650: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    skip_10:
L_801C9654:
    // 0x801C9654: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9658: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C965C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    // 0x801C9660: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    // 0x801C9664: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x801C9668: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C966C: jal         0x8001EAD0
    // 0x801C9670: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_11;
    // 0x801C9670: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_11:
    // 0x801C9674: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9678: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801C967C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C9680: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801C9684: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x801C9688: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C968C: jal         0x8001EB64
    // 0x801C9690: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_12;
    // 0x801C9690: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_12:
    // 0x801C9694: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C9698: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C969C: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801C96A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C96A4: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801C96A8: lw          $s0, 0x2C($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X2C);
    // 0x801C96AC: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801C96B0: lbu         $t9, 0xEB($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XEB);
    // 0x801C96B4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C96B8: addiu       $t1, $sp, 0xD0
    ctx->r9 = ADD32(ctx->r29, 0XD0);
    // 0x801C96BC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x801C96C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C96C4: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
    // 0x801C96C8: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801C96CC: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801C96D0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C96D4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C96D8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C96DC: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801C96E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C96E4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C96E8: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801C96EC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801C96F0: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801C96F4: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x801C96F8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C96FC: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x801C9700: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801C9704: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801C9708: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801C970C: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C9710: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801C9714: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801C9718: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C971C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801C9720: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801C9724: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C9728: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x801C972C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801C9730: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801C9734: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801C9738: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x801C973C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x801C9740: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801C9744: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801C9748: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801C974C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801C9750: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801C9754: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C9758: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801C975C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x801C9760: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C9764: jal         0x801E02DC
    // 0x801C9768: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_13;
    // 0x801C9768: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x801C976C: lw          $t1, 0xE0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9770: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C9774: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C9778: lw          $s0, 0x2C($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X2C);
    // 0x801C977C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C9780: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9784: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C9788: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C978C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801C9790: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C9794: lwc1        $f10, 0x30F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X30F8);
    // 0x801C9798: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801C979C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801C97A0: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x801C97A4: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x801C97A8: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x801C97AC: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C97B0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801C97B4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C97B8: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x801C97BC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C97C0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x801C97C4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x801C97C8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801C97CC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C97D0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x801C97D4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801C97D8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801C97DC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801C97E0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801C97E4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C97E8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801C97EC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801C97F0: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801C97F4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801C97F8: jal         0x801E02DC
    // 0x801C97FC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_14;
    // 0x801C97FC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x801C9800: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801C9804: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
L_801C9808:
    // 0x801C9808: lwc1        $f0, 0xEC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x801C980C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C9810: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C9814: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C9818: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C981C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9820: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C9824: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801C9828: nop

    // 0x801C982C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C9830: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801C9834: nop

    // 0x801C9838: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801C983C: beql        $t1, $zero, L_801C988C
    if (ctx->r9 == 0) {
        // 0x801C9840: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_801C988C;
    }
    goto skip_11;
    // 0x801C9840: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_11:
    // 0x801C9844: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C9848: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C984C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C9850: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801C9854: nop

    // 0x801C9858: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C985C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801C9860: nop

    // 0x801C9864: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801C9868: bne         $t1, $zero, L_801C9880
    if (ctx->r9 != 0) {
        // 0x801C986C: nop
    
            goto L_801C9880;
    }
    // 0x801C986C: nop

    // 0x801C9870: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801C9874: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9878: b           L_801C9898
    // 0x801C987C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801C9898;
    // 0x801C987C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801C9880:
    // 0x801C9880: b           L_801C9898
    // 0x801C9884: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801C9898;
    // 0x801C9884: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801C9888: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_801C988C:
    // 0x801C988C: nop

    // 0x801C9890: bltz        $t1, L_801C9880
    if (SIGNED(ctx->r9) < 0) {
        // 0x801C9894: nop
    
            goto L_801C9880;
    }
    // 0x801C9894: nop

L_801C9898:
    // 0x801C9898: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C989C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801C98A0: beq         $t2, $v1, L_801C9940
    if (ctx->r10 == ctx->r3) {
        // 0x801C98A4: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_801C9940;
    }
    // 0x801C98A4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801C98A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C98AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C98B0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C98B4: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C98B8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C98BC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C98C0: nop

    // 0x801C98C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C98C8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C98CC: nop

    // 0x801C98D0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C98D4: beql        $t4, $zero, L_801C9924
    if (ctx->r12 == 0) {
        // 0x801C98D8: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801C9924;
    }
    goto skip_12;
    // 0x801C98D8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_12:
    // 0x801C98DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C98E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C98E4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C98E8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C98EC: nop

    // 0x801C98F0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C98F4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C98F8: nop

    // 0x801C98FC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C9900: bne         $t4, $zero, L_801C9918
    if (ctx->r12 != 0) {
        // 0x801C9904: nop
    
            goto L_801C9918;
    }
    // 0x801C9904: nop

    // 0x801C9908: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801C990C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9910: b           L_801C9930
    // 0x801C9914: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801C9930;
    // 0x801C9914: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801C9918:
    // 0x801C9918: b           L_801C9930
    // 0x801C991C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801C9930;
    // 0x801C991C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C9920: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801C9924:
    // 0x801C9924: nop

    // 0x801C9928: bltz        $t4, L_801C9918
    if (SIGNED(ctx->r12) < 0) {
        // 0x801C992C: nop
    
            goto L_801C9918;
    }
    // 0x801C992C: nop

L_801C9930:
    // 0x801C9930: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C9934: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x801C9938: bnel        $t5, $v1, L_801CB6EC
    if (ctx->r13 != ctx->r3) {
        // 0x801C993C: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_801CB6EC;
    }
    goto skip_13;
    // 0x801C993C: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_13:
L_801C9940:
    // 0x801C9940: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9944: lbu         $t8, 0xEB($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XEB);
    // 0x801C9948: addiu       $t0, $sp, 0xD0
    ctx->r8 = ADD32(ctx->r29, 0XD0);
    // 0x801C994C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C9950: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801C9954: addu        $s2, $t9, $t0
    ctx->r18 = ADD32(ctx->r25, ctx->r8);
    // 0x801C9958: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801C995C: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x801C9960: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9964: jal         0x8001EAD0
    // 0x801C9968: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_15;
    // 0x801C9968: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_15:
    // 0x801C996C: lw          $t1, 0xE0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9970: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801C9974: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C9978: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x801C997C: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x801C9980: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9984: jal         0x8001EB64
    // 0x801C9988: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_16;
    // 0x801C9988: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_16:
    // 0x801C998C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C9990: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C9994: lw          $t3, 0xE0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9998: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C999C: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x801C99A0: lw          $s0, 0x2C($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X2C);
    // 0x801C99A4: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801C99A8: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801C99AC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C99B0: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C99B4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801C99B8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C99BC: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801C99C0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C99C4: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801C99C8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C99CC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801C99D0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C99D4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801C99D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C99DC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C99E0: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801C99E4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801C99E8: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801C99EC: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801C99F0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801C99F4: addiu       $t0, $zero, 0x96
    ctx->r8 = ADD32(0, 0X96);
    // 0x801C99F8: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x801C99FC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x801C9A00: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801C9A04: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x801C9A08: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C9A0C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801C9A10: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801C9A14: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801C9A18: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C9A1C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x801C9A20: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801C9A24: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801C9A28: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801C9A2C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801C9A30: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801C9A34: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801C9A38: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801C9A3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C9A40: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801C9A44: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C9A48: jal         0x801E02DC
    // 0x801C9A4C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_17;
    // 0x801C9A4C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x801C9A50: lw          $t3, 0xE0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9A54: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C9A58: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C9A5C: lw          $s0, 0x2C($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X2C);
    // 0x801C9A60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C9A64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9A68: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C9A6C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C9A70: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801C9A74: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C9A78: lwc1        $f8, 0x30FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X30FC);
    // 0x801C9A7C: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C9A80: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801C9A84: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x801C9A88: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x801C9A8C: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x801C9A90: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C9A94: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801C9A98: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801C9A9C: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x801C9AA0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801C9AA4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x801C9AA8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801C9AAC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x801C9AB0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801C9AB4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801C9AB8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801C9ABC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x801C9AC0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801C9AC4: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801C9AC8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C9ACC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801C9AD0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801C9AD4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801C9AD8: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801C9ADC: jal         0x801E02DC
    // 0x801C9AE0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_18;
    // 0x801C9AE0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x801C9AE4: b           L_801CB6EC
    // 0x801C9AE8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
        goto L_801CB6EC;
    // 0x801C9AE8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801C9AEC:
    // 0x801C9AEC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801C9AF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C9AF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9AF8: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801C9AFC: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801C9B00: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801C9B04: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C9B08: nop

    // 0x801C9B0C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C9B10: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C9B14: nop

    // 0x801C9B18: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C9B1C: beq         $t3, $zero, L_801C9B68
    if (ctx->r11 == 0) {
        // 0x801C9B20: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801C9B68;
    }
    // 0x801C9B20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9B24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C9B28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9B2C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C9B30: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C9B34: nop

    // 0x801C9B38: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C9B3C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C9B40: nop

    // 0x801C9B44: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C9B48: bne         $t3, $zero, L_801C9B60
    if (ctx->r11 != 0) {
        // 0x801C9B4C: nop
    
            goto L_801C9B60;
    }
    // 0x801C9B4C: nop

    // 0x801C9B50: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801C9B54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9B58: b           L_801C9B78
    // 0x801C9B5C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801C9B78;
    // 0x801C9B5C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801C9B60:
    // 0x801C9B60: b           L_801C9B78
    // 0x801C9B64: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801C9B78;
    // 0x801C9B64: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_801C9B68:
    // 0x801C9B68: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801C9B6C: nop

    // 0x801C9B70: bltz        $t3, L_801C9B60
    if (SIGNED(ctx->r11) < 0) {
        // 0x801C9B74: nop
    
            goto L_801C9B60;
    }
    // 0x801C9B74: nop

L_801C9B78:
    // 0x801C9B78: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801C9B7C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801C9B80: beq         $t4, $v1, L_801C9C24
    if (ctx->r12 == ctx->r3) {
        // 0x801C9B84: lui         $at, 0x4188
        ctx->r1 = S32(0X4188 << 16);
            goto L_801C9C24;
    }
    // 0x801C9B84: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x801C9B88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C9B8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C9B90: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9B94: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x801C9B98: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    // 0x801C9B9C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C9BA0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C9BA4: nop

    // 0x801C9BA8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C9BAC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C9BB0: nop

    // 0x801C9BB4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C9BB8: beql        $t6, $zero, L_801C9C08
    if (ctx->r14 == 0) {
        // 0x801C9BBC: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_801C9C08;
    }
    goto skip_14;
    // 0x801C9BBC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_14:
    // 0x801C9BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C9BC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C9BC8: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801C9BCC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C9BD0: nop

    // 0x801C9BD4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C9BD8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C9BDC: nop

    // 0x801C9BE0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C9BE4: bne         $t6, $zero, L_801C9BFC
    if (ctx->r14 != 0) {
        // 0x801C9BE8: nop
    
            goto L_801C9BFC;
    }
    // 0x801C9BE8: nop

    // 0x801C9BEC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801C9BF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9BF4: b           L_801C9C14
    // 0x801C9BF8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801C9C14;
    // 0x801C9BF8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801C9BFC:
    // 0x801C9BFC: b           L_801C9C14
    // 0x801C9C00: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801C9C14;
    // 0x801C9C00: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C9C04: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_801C9C08:
    // 0x801C9C08: nop

    // 0x801C9C0C: bltz        $t6, L_801C9BFC
    if (SIGNED(ctx->r14) < 0) {
        // 0x801C9C10: nop
    
            goto L_801C9BFC;
    }
    // 0x801C9C10: nop

L_801C9C14:
    // 0x801C9C14: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C9C18: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801C9C1C: bne         $t7, $v1, L_801C9D98
    if (ctx->r15 != ctx->r3) {
        // 0x801C9C20: nop
    
            goto L_801C9D98;
    }
    // 0x801C9C20: nop

L_801C9C24:
    // 0x801C9C24: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9C28: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C9C2C: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801C9C30: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
    // 0x801C9C34: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9C38: jal         0x8001EAD0
    // 0x801C9C3C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_19;
    // 0x801C9C3C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_19:
    // 0x801C9C40: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9C44: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C9C48: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C9C4C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801C9C50: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
    // 0x801C9C54: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9C58: jal         0x8001EB64
    // 0x801C9C5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_20;
    // 0x801C9C5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_20:
    // 0x801C9C60: lw          $t2, 0xE0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9C64: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801C9C68: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C9C6C: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    // 0x801C9C70: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    // 0x801C9C74: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
    // 0x801C9C78: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9C7C: jal         0x8001EAD0
    // 0x801C9C80: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_21;
    // 0x801C9C80: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_21:
    // 0x801C9C84: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9C88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801C9C8C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C9C90: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    // 0x801C9C94: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
    // 0x801C9C98: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9C9C: jal         0x8001EB64
    // 0x801C9CA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_22;
    // 0x801C9CA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_22:
    // 0x801C9CA4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C9CA8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C9CAC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C9CB0: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9CB4: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801C9CB8: lbu         $t7, 0xEB($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XEB);
    // 0x801C9CBC: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801C9CC0: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x801C9CC4: addiu       $t9, $sp, 0xD0
    ctx->r25 = ADD32(ctx->r29, 0XD0);
    // 0x801C9CC8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801C9CCC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C9CD0: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x801C9CD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9CD8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C9CDC: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801C9CE0: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801C9CE4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C9CE8: ldc1        $f28, 0x3100($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X3100);
    // 0x801C9CEC: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801C9CF0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801C9CF4: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801C9CF8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C9CFC: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801C9D00: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801C9D04: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x801C9D08: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x801C9D0C: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801C9D10: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C9D14: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801C9D18: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x801C9D1C: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801C9D20: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801C9D24: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x801C9D28: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C9D2C: mul.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f28.d);
    // 0x801C9D30: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801C9D34: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C9D38: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801C9D3C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C9D40: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801C9D44: mul.d       $f6, $f10, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f28.d);
    // 0x801C9D48: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801C9D4C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801C9D50: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801C9D54: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801C9D58: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801C9D5C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801C9D60: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801C9D64: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801C9D68: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801C9D6C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C9D70: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801C9D74: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801C9D78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C9D7C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801C9D80: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801C9D84: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C9D88: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x801C9D8C: jal         0x801E02DC
    // 0x801C9D90: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_23;
    // 0x801C9D90: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x801C9D94: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
L_801C9D98:
    // 0x801C9D98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9D9C: ldc1        $f28, 0x3108($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X3108);
    // 0x801C9DA0: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801C9DA4: lwc1        $f0, 0xEC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x801C9DA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C9DAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C9DB0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C9DB4: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C9DB8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9DBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C9DC0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C9DC4: nop

    // 0x801C9DC8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C9DCC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C9DD0: nop

    // 0x801C9DD4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C9DD8: beql        $t0, $zero, L_801C9E28
    if (ctx->r8 == 0) {
        // 0x801C9DDC: mfc1        $t0, $f8
        ctx->r8 = (int32_t)ctx->f8.u32l;
            goto L_801C9E28;
    }
    goto skip_15;
    // 0x801C9DDC: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    skip_15:
    // 0x801C9DE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C9DE4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C9DE8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C9DEC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C9DF0: nop

    // 0x801C9DF4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C9DF8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C9DFC: nop

    // 0x801C9E00: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C9E04: bne         $t0, $zero, L_801C9E1C
    if (ctx->r8 != 0) {
        // 0x801C9E08: nop
    
            goto L_801C9E1C;
    }
    // 0x801C9E08: nop

    // 0x801C9E0C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x801C9E10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9E14: b           L_801C9E34
    // 0x801C9E18: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801C9E34;
    // 0x801C9E18: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801C9E1C:
    // 0x801C9E1C: b           L_801C9E34
    // 0x801C9E20: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801C9E34;
    // 0x801C9E20: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801C9E24: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
L_801C9E28:
    // 0x801C9E28: nop

    // 0x801C9E2C: bltz        $t0, L_801C9E1C
    if (SIGNED(ctx->r8) < 0) {
        // 0x801C9E30: nop
    
            goto L_801C9E1C;
    }
    // 0x801C9E30: nop

L_801C9E34:
    // 0x801C9E34: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C9E38: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x801C9E3C: beq         $t1, $v1, L_801C9EDC
    if (ctx->r9 == ctx->r3) {
        // 0x801C9E40: lui         $at, 0x4190
        ctx->r1 = S32(0X4190 << 16);
            goto L_801C9EDC;
    }
    // 0x801C9E40: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801C9E44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C9E48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9E4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9E50: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C9E54: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801C9E58: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C9E5C: nop

    // 0x801C9E60: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C9E64: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C9E68: nop

    // 0x801C9E6C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C9E70: beql        $t3, $zero, L_801C9EC0
    if (ctx->r11 == 0) {
        // 0x801C9E74: mfc1        $t3, $f6
        ctx->r11 = (int32_t)ctx->f6.u32l;
            goto L_801C9EC0;
    }
    goto skip_16;
    // 0x801C9E74: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    skip_16:
    // 0x801C9E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C9E7C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9E80: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801C9E84: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C9E88: nop

    // 0x801C9E8C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C9E90: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C9E94: nop

    // 0x801C9E98: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C9E9C: bne         $t3, $zero, L_801C9EB4
    if (ctx->r11 != 0) {
        // 0x801C9EA0: nop
    
            goto L_801C9EB4;
    }
    // 0x801C9EA0: nop

    // 0x801C9EA4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801C9EA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9EAC: b           L_801C9ECC
    // 0x801C9EB0: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801C9ECC;
    // 0x801C9EB0: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801C9EB4:
    // 0x801C9EB4: b           L_801C9ECC
    // 0x801C9EB8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801C9ECC;
    // 0x801C9EB8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801C9EBC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
L_801C9EC0:
    // 0x801C9EC0: nop

    // 0x801C9EC4: bltz        $t3, L_801C9EB4
    if (SIGNED(ctx->r11) < 0) {
        // 0x801C9EC8: nop
    
            goto L_801C9EB4;
    }
    // 0x801C9EC8: nop

L_801C9ECC:
    // 0x801C9ECC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801C9ED0: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801C9ED4: bnel        $t4, $v1, L_801CA0DC
    if (ctx->r12 != ctx->r3) {
        // 0x801C9ED8: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_801CA0DC;
    }
    goto skip_17;
    // 0x801C9ED8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_17:
L_801C9EDC:
    // 0x801C9EDC: lw          $t5, 0xE0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9EE0: lbu         $t7, 0xEB($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XEB);
    // 0x801C9EE4: addiu       $t9, $sp, 0xD0
    ctx->r25 = ADD32(ctx->r29, 0XD0);
    // 0x801C9EE8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C9EEC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801C9EF0: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x801C9EF4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    // 0x801C9EF8: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x801C9EFC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9F00: jal         0x8001EAD0
    // 0x801C9F04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_24;
    // 0x801C9F04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_24:
    // 0x801C9F08: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9F0C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C9F10: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C9F14: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801C9F18: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x801C9F1C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9F20: jal         0x8001EB64
    // 0x801C9F24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_25;
    // 0x801C9F24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_25:
    // 0x801C9F28: lw          $t2, 0xE0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9F2C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801C9F30: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C9F34: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    // 0x801C9F38: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x801C9F3C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9F40: jal         0x8001EAD0
    // 0x801C9F44: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_26;
    // 0x801C9F44: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_26:
    // 0x801C9F48: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9F4C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801C9F50: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C9F54: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    // 0x801C9F58: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x801C9F5C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C9F60: jal         0x8001EB64
    // 0x801C9F64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_27;
    // 0x801C9F64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_27:
    // 0x801C9F68: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801C9F6C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C9F70: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C9F74: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801C9F78: cvt.d.s     $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f8.d = CVT_D_S(ctx->f24.fl);
    // 0x801C9F7C: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C9F80: mul.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801C9F84: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x801C9F88: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801C9F8C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801C9F90: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C9F94: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801C9F98: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801C9F9C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C9FA0: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801C9FA4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801C9FA8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C9FAC: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801C9FB0: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x801C9FB4: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801C9FB8: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801C9FBC: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x801C9FC0: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801C9FC4: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801C9FC8: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x801C9FCC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x801C9FD0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801C9FD4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C9FD8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801C9FDC: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801C9FE0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801C9FE4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801C9FE8: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x801C9FEC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C9FF0: mul.d       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f30.d);
    // 0x801C9FF4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801C9FF8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801C9FFC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801CA000: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801CA004: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CA008: mul.d       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f30.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f30.d);
    // 0x801CA00C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CA010: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CA014: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CA018: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801CA01C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801CA020: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801CA024: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801CA028: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CA02C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CA030: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801CA034: jal         0x801E02DC
    // 0x801CA038: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_28;
    // 0x801CA038: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_28:
    // 0x801CA03C: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA040: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CA044: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801CA048: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x801CA04C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801CA050: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CA054: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CA058: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CA05C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CA060: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801CA064: lwc1        $f10, 0x3110($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3110);
    // 0x801CA068: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801CA06C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CA070: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x801CA074: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x801CA078: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x801CA07C: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CA080: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801CA084: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CA088: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x801CA08C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CA090: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x801CA094: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801CA098: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801CA09C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801CA0A0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CA0A4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801CA0A8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CA0AC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CA0B0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801CA0B4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CA0B8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CA0BC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CA0C0: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CA0C4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CA0C8: jal         0x801E02DC
    // 0x801CA0CC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_29;
    // 0x801CA0CC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_29:
    // 0x801CA0D0: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801CA0D4: lwc1        $f0, 0xEC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x801CA0D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_801CA0DC:
    // 0x801CA0DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CA0E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA0E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA0E8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801CA0EC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801CA0F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CA0F4: nop

    // 0x801CA0F8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CA0FC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CA100: nop

    // 0x801CA104: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CA108: beql        $t6, $zero, L_801CA158
    if (ctx->r14 == 0) {
        // 0x801CA10C: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_801CA158;
    }
    goto skip_18;
    // 0x801CA10C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_18:
    // 0x801CA110: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CA114: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA118: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CA11C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CA120: nop

    // 0x801CA124: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CA128: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CA12C: nop

    // 0x801CA130: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CA134: bne         $t6, $zero, L_801CA14C
    if (ctx->r14 != 0) {
        // 0x801CA138: nop
    
            goto L_801CA14C;
    }
    // 0x801CA138: nop

    // 0x801CA13C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801CA140: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA144: b           L_801CA164
    // 0x801CA148: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801CA164;
    // 0x801CA148: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801CA14C:
    // 0x801CA14C: b           L_801CA164
    // 0x801CA150: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801CA164;
    // 0x801CA150: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801CA154: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_801CA158:
    // 0x801CA158: nop

    // 0x801CA15C: bltz        $t6, L_801CA14C
    if (SIGNED(ctx->r14) < 0) {
        // 0x801CA160: nop
    
            goto L_801CA14C;
    }
    // 0x801CA160: nop

L_801CA164:
    // 0x801CA164: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801CA168: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801CA16C: beq         $t7, $v1, L_801CA20C
    if (ctx->r15 == ctx->r3) {
        // 0x801CA170: lui         $at, 0x4198
        ctx->r1 = S32(0X4198 << 16);
            goto L_801CA20C;
    }
    // 0x801CA170: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x801CA174: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CA178: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA17C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA180: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CA184: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CA188: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA18C: nop

    // 0x801CA190: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CA194: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CA198: nop

    // 0x801CA19C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CA1A0: beql        $t9, $zero, L_801CA1F0
    if (ctx->r25 == 0) {
        // 0x801CA1A4: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_801CA1F0;
    }
    goto skip_19;
    // 0x801CA1A4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_19:
    // 0x801CA1A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CA1AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA1B0: sub.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801CA1B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA1B8: nop

    // 0x801CA1BC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CA1C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CA1C4: nop

    // 0x801CA1C8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CA1CC: bne         $t9, $zero, L_801CA1E4
    if (ctx->r25 != 0) {
        // 0x801CA1D0: nop
    
            goto L_801CA1E4;
    }
    // 0x801CA1D0: nop

    // 0x801CA1D4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x801CA1D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA1DC: b           L_801CA1FC
    // 0x801CA1E0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CA1FC;
    // 0x801CA1E0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CA1E4:
    // 0x801CA1E4: b           L_801CA1FC
    // 0x801CA1E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CA1FC;
    // 0x801CA1E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CA1EC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_801CA1F0:
    // 0x801CA1F0: nop

    // 0x801CA1F4: bltz        $t9, L_801CA1E4
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CA1F8: nop
    
            goto L_801CA1E4;
    }
    // 0x801CA1F8: nop

L_801CA1FC:
    // 0x801CA1FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CA200: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801CA204: bnel        $t0, $v1, L_801CA378
    if (ctx->r8 != ctx->r3) {
        // 0x801CA208: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_801CA378;
    }
    goto skip_20;
    // 0x801CA208: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_20:
L_801CA20C:
    // 0x801CA20C: lw          $t1, 0xE0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA210: lbu         $t3, 0xEB($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XEB);
    // 0x801CA214: addiu       $t5, $sp, 0xD0
    ctx->r13 = ADD32(ctx->r29, 0XD0);
    // 0x801CA218: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CA21C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801CA220: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x801CA224: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x801CA228: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x801CA22C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA230: jal         0x8001EAD0
    // 0x801CA234: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_30;
    // 0x801CA234: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_30:
    // 0x801CA238: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA23C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801CA240: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801CA244: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801CA248: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x801CA24C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA250: jal         0x8001EB64
    // 0x801CA254: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_31;
    // 0x801CA254: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_31:
    // 0x801CA258: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA25C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801CA260: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CA264: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801CA268: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x801CA26C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA270: jal         0x8001EAD0
    // 0x801CA274: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_32;
    // 0x801CA274: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_32:
    // 0x801CA278: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA27C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801CA280: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801CA284: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801CA288: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x801CA28C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA290: jal         0x8001EB64
    // 0x801CA294: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_33;
    // 0x801CA294: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_33:
    // 0x801CA298: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CA29C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801CA2A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801CA2A4: lw          $t2, 0xE0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA2A8: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801CA2AC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CA2B0: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801CA2B4: lw          $s0, 0x2C($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X2C);
    // 0x801CA2B8: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CA2BC: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801CA2C0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CA2C4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801CA2C8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CA2CC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801CA2D0: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801CA2D4: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801CA2D8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CA2DC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CA2E0: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801CA2E4: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801CA2E8: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801CA2EC: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x801CA2F0: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801CA2F4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CA2F8: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x801CA2FC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801CA300: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801CA304: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CA308: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801CA30C: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801CA310: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801CA314: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801CA318: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x801CA31C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801CA320: mul.d       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f28.d);
    // 0x801CA324: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801CA328: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801CA32C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801CA330: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801CA334: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801CA338: mul.d       $f6, $f8, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f28.d);
    // 0x801CA33C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CA340: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CA344: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CA348: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801CA34C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801CA350: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801CA354: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801CA358: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CA35C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CA360: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801CA364: jal         0x801E02DC
    // 0x801CA368: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_34;
    // 0x801CA368: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_34:
    // 0x801CA36C: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801CA370: lwc1        $f0, 0xEC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x801CA374: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_801CA378:
    // 0x801CA378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CA37C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801CA380: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA384: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801CA388: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801CA38C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CA390: nop

    // 0x801CA394: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CA398: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CA39C: nop

    // 0x801CA3A0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801CA3A4: beql        $t3, $zero, L_801CA3F4
    if (ctx->r11 == 0) {
        // 0x801CA3A8: mfc1        $t3, $f10
        ctx->r11 = (int32_t)ctx->f10.u32l;
            goto L_801CA3F4;
    }
    goto skip_21;
    // 0x801CA3A8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    skip_21:
    // 0x801CA3AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CA3B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801CA3B4: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801CA3B8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CA3BC: nop

    // 0x801CA3C0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CA3C4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CA3C8: nop

    // 0x801CA3CC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801CA3D0: bne         $t3, $zero, L_801CA3E8
    if (ctx->r11 != 0) {
        // 0x801CA3D4: nop
    
            goto L_801CA3E8;
    }
    // 0x801CA3D4: nop

    // 0x801CA3D8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x801CA3DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA3E0: b           L_801CA400
    // 0x801CA3E4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801CA400;
    // 0x801CA3E4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801CA3E8:
    // 0x801CA3E8: b           L_801CA400
    // 0x801CA3EC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801CA400;
    // 0x801CA3EC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801CA3F0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
L_801CA3F4:
    // 0x801CA3F4: nop

    // 0x801CA3F8: bltz        $t3, L_801CA3E8
    if (SIGNED(ctx->r11) < 0) {
        // 0x801CA3FC: nop
    
            goto L_801CA3E8;
    }
    // 0x801CA3FC: nop

L_801CA400:
    // 0x801CA400: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801CA404: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801CA408: beq         $t4, $v1, L_801CA4A8
    if (ctx->r12 == ctx->r3) {
        // 0x801CA40C: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_801CA4A8;
    }
    // 0x801CA40C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801CA410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CA414: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA418: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA41C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801CA420: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801CA424: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CA428: nop

    // 0x801CA42C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CA430: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CA434: nop

    // 0x801CA438: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CA43C: beql        $t6, $zero, L_801CA48C
    if (ctx->r14 == 0) {
        // 0x801CA440: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_801CA48C;
    }
    goto skip_22;
    // 0x801CA440: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_22:
    // 0x801CA444: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CA448: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA44C: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801CA450: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CA454: nop

    // 0x801CA458: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CA45C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CA460: nop

    // 0x801CA464: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CA468: bne         $t6, $zero, L_801CA480
    if (ctx->r14 != 0) {
        // 0x801CA46C: nop
    
            goto L_801CA480;
    }
    // 0x801CA46C: nop

    // 0x801CA470: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801CA474: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA478: b           L_801CA498
    // 0x801CA47C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801CA498;
    // 0x801CA47C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801CA480:
    // 0x801CA480: b           L_801CA498
    // 0x801CA484: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801CA498;
    // 0x801CA484: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801CA488: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_801CA48C:
    // 0x801CA48C: nop

    // 0x801CA490: bltz        $t6, L_801CA480
    if (SIGNED(ctx->r14) < 0) {
        // 0x801CA494: nop
    
            goto L_801CA480;
    }
    // 0x801CA494: nop

L_801CA498:
    // 0x801CA498: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801CA49C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801CA4A0: bnel        $t7, $v1, L_801CA614
    if (ctx->r15 != ctx->r3) {
        // 0x801CA4A4: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_801CA614;
    }
    goto skip_23;
    // 0x801CA4A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    skip_23:
L_801CA4A8:
    // 0x801CA4A8: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA4AC: lbu         $t0, 0xEB($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XEB);
    // 0x801CA4B0: addiu       $t2, $sp, 0xD0
    ctx->r10 = ADD32(ctx->r29, 0XD0);
    // 0x801CA4B4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CA4B8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x801CA4BC: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x801CA4C0: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801CA4C4: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x801CA4C8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA4CC: jal         0x8001EAD0
    // 0x801CA4D0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_35;
    // 0x801CA4D0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_35:
    // 0x801CA4D4: lw          $t3, 0xE0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA4D8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801CA4DC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801CA4E0: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    // 0x801CA4E4: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x801CA4E8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA4EC: jal         0x8001EB64
    // 0x801CA4F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_36;
    // 0x801CA4F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_36:
    // 0x801CA4F4: lw          $t5, 0xE0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA4F8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801CA4FC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801CA500: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    // 0x801CA504: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x801CA508: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA50C: jal         0x8001EAD0
    // 0x801CA510: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_37;
    // 0x801CA510: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_37:
    // 0x801CA514: lw          $t7, 0xE0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA518: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801CA51C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CA520: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    // 0x801CA524: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x801CA528: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA52C: jal         0x8001EB64
    // 0x801CA530: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_38;
    // 0x801CA530: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_38:
    // 0x801CA534: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CA538: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801CA53C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801CA540: lw          $t9, 0xE0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA544: cvt.d.s     $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.d = CVT_D_S(ctx->f24.fl);
    // 0x801CA548: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CA54C: mul.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801CA550: lw          $s0, 0x2C($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X2C);
    // 0x801CA554: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801CA558: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CA55C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CA560: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CA564: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CA568: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801CA56C: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801CA570: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x801CA574: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CA578: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801CA57C: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x801CA580: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801CA584: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801CA588: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x801CA58C: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801CA590: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CA594: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x801CA598: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801CA59C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801CA5A0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801CA5A4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801CA5A8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801CA5AC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801CA5B0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801CA5B4: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801CA5B8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CA5BC: mul.d       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f28.d);
    // 0x801CA5C0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801CA5C4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801CA5C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801CA5CC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801CA5D0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801CA5D4: mul.d       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f28.d);
    // 0x801CA5D8: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CA5DC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CA5E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CA5E4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801CA5E8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801CA5EC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801CA5F0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801CA5F4: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CA5F8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CA5FC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x801CA600: jal         0x801E02DC
    // 0x801CA604: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_39;
    // 0x801CA604: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_39:
    // 0x801CA608: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801CA60C: lwc1        $f0, 0xEC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x801CA610: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
L_801CA614:
    // 0x801CA614: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CA618: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CA61C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA620: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801CA624: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CA628: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CA62C: nop

    // 0x801CA630: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CA634: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CA638: nop

    // 0x801CA63C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801CA640: beql        $t0, $zero, L_801CA690
    if (ctx->r8 == 0) {
        // 0x801CA644: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_801CA690;
    }
    goto skip_24;
    // 0x801CA644: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_24:
    // 0x801CA648: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CA64C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CA650: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801CA654: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CA658: nop

    // 0x801CA65C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CA660: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CA664: nop

    // 0x801CA668: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801CA66C: bne         $t0, $zero, L_801CA684
    if (ctx->r8 != 0) {
        // 0x801CA670: nop
    
            goto L_801CA684;
    }
    // 0x801CA670: nop

    // 0x801CA674: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801CA678: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA67C: b           L_801CA69C
    // 0x801CA680: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801CA69C;
    // 0x801CA680: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801CA684:
    // 0x801CA684: b           L_801CA69C
    // 0x801CA688: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801CA69C;
    // 0x801CA688: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801CA68C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_801CA690:
    // 0x801CA690: nop

    // 0x801CA694: bltz        $t0, L_801CA684
    if (SIGNED(ctx->r8) < 0) {
        // 0x801CA698: nop
    
            goto L_801CA684;
    }
    // 0x801CA698: nop

L_801CA69C:
    // 0x801CA69C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA6A0: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x801CA6A4: beq         $t1, $v1, L_801CA744
    if (ctx->r9 == ctx->r3) {
        // 0x801CA6A8: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_801CA744;
    }
    // 0x801CA6A8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801CA6AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CA6B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801CA6B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA6B8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801CA6BC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801CA6C0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CA6C4: nop

    // 0x801CA6C8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CA6CC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CA6D0: nop

    // 0x801CA6D4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801CA6D8: beql        $t3, $zero, L_801CA728
    if (ctx->r11 == 0) {
        // 0x801CA6DC: mfc1        $t3, $f10
        ctx->r11 = (int32_t)ctx->f10.u32l;
            goto L_801CA728;
    }
    goto skip_25;
    // 0x801CA6DC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    skip_25:
    // 0x801CA6E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CA6E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801CA6E8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CA6EC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CA6F0: nop

    // 0x801CA6F4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CA6F8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CA6FC: nop

    // 0x801CA700: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801CA704: bne         $t3, $zero, L_801CA71C
    if (ctx->r11 != 0) {
        // 0x801CA708: nop
    
            goto L_801CA71C;
    }
    // 0x801CA708: nop

    // 0x801CA70C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x801CA710: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA714: b           L_801CA734
    // 0x801CA718: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801CA734;
    // 0x801CA718: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801CA71C:
    // 0x801CA71C: b           L_801CA734
    // 0x801CA720: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801CA734;
    // 0x801CA720: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801CA724: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
L_801CA728:
    // 0x801CA728: nop

    // 0x801CA72C: bltz        $t3, L_801CA71C
    if (SIGNED(ctx->r11) < 0) {
        // 0x801CA730: nop
    
            goto L_801CA71C;
    }
    // 0x801CA730: nop

L_801CA734:
    // 0x801CA734: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801CA738: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801CA73C: bnel        $t4, $v1, L_801CA94C
    if (ctx->r12 != ctx->r3) {
        // 0x801CA740: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_801CA94C;
    }
    goto skip_26;
    // 0x801CA740: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    skip_26:
L_801CA744:
    // 0x801CA744: lw          $t5, 0xE0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA748: lbu         $t7, 0xEB($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XEB);
    // 0x801CA74C: addiu       $t9, $sp, 0xD0
    ctx->r25 = ADD32(ctx->r29, 0XD0);
    // 0x801CA750: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801CA754: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801CA758: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x801CA75C: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    // 0x801CA760: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x801CA764: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA768: jal         0x8001EAD0
    // 0x801CA76C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_40;
    // 0x801CA76C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_40:
    // 0x801CA770: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA774: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801CA778: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801CA77C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801CA780: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x801CA784: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA788: jal         0x8001EB64
    // 0x801CA78C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_41;
    // 0x801CA78C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_41:
    // 0x801CA790: lw          $t2, 0xE0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA794: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801CA798: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801CA79C: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    // 0x801CA7A0: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x801CA7A4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA7A8: jal         0x8001EAD0
    // 0x801CA7AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_42;
    // 0x801CA7AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_42:
    // 0x801CA7B0: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA7B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801CA7B8: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801CA7BC: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    // 0x801CA7C0: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x801CA7C4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CA7C8: jal         0x8001EB64
    // 0x801CA7CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_43;
    // 0x801CA7CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_43:
    // 0x801CA7D0: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801CA7D4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801CA7D8: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA7DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CA7E0: cvt.d.s     $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f4.d = CVT_D_S(ctx->f24.fl);
    // 0x801CA7E4: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x801CA7E8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801CA7EC: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CA7F0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CA7F4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CA7F8: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801CA7FC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801CA800: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801CA804: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CA808: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801CA80C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CA810: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801CA814: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801CA818: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801CA81C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CA820: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801CA824: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801CA828: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CA82C: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801CA830: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CA834: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801CA838: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x801CA83C: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x801CA840: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x801CA844: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801CA848: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801CA84C: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801CA850: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801CA854: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CA858: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801CA85C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CA860: mul.d       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f30.d);
    // 0x801CA864: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801CA868: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CA86C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801CA870: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801CA874: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CA878: mul.d       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f30.d);
    // 0x801CA87C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CA880: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CA884: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CA888: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801CA88C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801CA890: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801CA894: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801CA898: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CA89C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CA8A0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801CA8A4: jal         0x801E02DC
    // 0x801CA8A8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_44;
    // 0x801CA8A8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_44:
    // 0x801CA8AC: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CA8B0: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CA8B4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801CA8B8: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x801CA8BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801CA8C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CA8C4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CA8C8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CA8CC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CA8D0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CA8D4: lwc1        $f8, 0x3114($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3114);
    // 0x801CA8D8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801CA8DC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CA8E0: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x801CA8E4: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x801CA8E8: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x801CA8EC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CA8F0: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801CA8F4: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CA8F8: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x801CA8FC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CA900: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x801CA904: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801CA908: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801CA90C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801CA910: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CA914: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801CA918: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CA91C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CA920: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801CA924: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CA928: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CA92C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CA930: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CA934: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CA938: jal         0x801E02DC
    // 0x801CA93C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_45;
    // 0x801CA93C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_45:
    // 0x801CA940: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801CA944: lwc1        $f0, 0xEC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x801CA948: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
L_801CA94C:
    // 0x801CA94C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CA950: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA954: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA958: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CA95C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801CA960: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CA964: nop

    // 0x801CA968: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CA96C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CA970: nop

    // 0x801CA974: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CA978: beql        $t6, $zero, L_801CA9C8
    if (ctx->r14 == 0) {
        // 0x801CA97C: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_801CA9C8;
    }
    goto skip_27;
    // 0x801CA97C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_27:
    // 0x801CA980: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CA984: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA988: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CA98C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CA990: nop

    // 0x801CA994: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CA998: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CA99C: nop

    // 0x801CA9A0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CA9A4: bne         $t6, $zero, L_801CA9BC
    if (ctx->r14 != 0) {
        // 0x801CA9A8: nop
    
            goto L_801CA9BC;
    }
    // 0x801CA9A8: nop

    // 0x801CA9AC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801CA9B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA9B4: b           L_801CA9D4
    // 0x801CA9B8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801CA9D4;
    // 0x801CA9B8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801CA9BC:
    // 0x801CA9BC: b           L_801CA9D4
    // 0x801CA9C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801CA9D4;
    // 0x801CA9C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801CA9C4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_801CA9C8:
    // 0x801CA9C8: nop

    // 0x801CA9CC: bltz        $t6, L_801CA9BC
    if (SIGNED(ctx->r14) < 0) {
        // 0x801CA9D0: nop
    
            goto L_801CA9BC;
    }
    // 0x801CA9D0: nop

L_801CA9D4:
    // 0x801CA9D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801CA9D8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801CA9DC: beq         $t7, $v1, L_801CAA7C
    if (ctx->r15 == ctx->r3) {
        // 0x801CA9E0: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_801CAA7C;
    }
    // 0x801CA9E0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801CA9E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CA9E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA9EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA9F0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801CA9F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CA9F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA9FC: nop

    // 0x801CAA00: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CAA04: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CAA08: nop

    // 0x801CAA0C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CAA10: beql        $t9, $zero, L_801CAA60
    if (ctx->r25 == 0) {
        // 0x801CAA14: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_801CAA60;
    }
    goto skip_28;
    // 0x801CAA14: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_28:
    // 0x801CAA18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CAA1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CAA20: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801CAA24: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CAA28: nop

    // 0x801CAA2C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CAA30: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CAA34: nop

    // 0x801CAA38: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CAA3C: bne         $t9, $zero, L_801CAA54
    if (ctx->r25 != 0) {
        // 0x801CAA40: nop
    
            goto L_801CAA54;
    }
    // 0x801CAA40: nop

    // 0x801CAA44: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x801CAA48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CAA4C: b           L_801CAA6C
    // 0x801CAA50: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CAA6C;
    // 0x801CAA50: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CAA54:
    // 0x801CAA54: b           L_801CAA6C
    // 0x801CAA58: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CAA6C;
    // 0x801CAA58: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CAA5C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_801CAA60:
    // 0x801CAA60: nop

    // 0x801CAA64: bltz        $t9, L_801CAA54
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CAA68: nop
    
            goto L_801CAA54;
    }
    // 0x801CAA68: nop

L_801CAA6C:
    // 0x801CAA6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CAA70: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801CAA74: bnel        $t0, $v1, L_801CB6EC
    if (ctx->r8 != ctx->r3) {
        // 0x801CAA78: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_801CB6EC;
    }
    goto skip_29;
    // 0x801CAA78: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_29:
L_801CAA7C:
    // 0x801CAA7C: lw          $t1, 0xE0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAA80: lbu         $t3, 0xEB($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XEB);
    // 0x801CAA84: addiu       $t5, $sp, 0xD0
    ctx->r13 = ADD32(ctx->r29, 0XD0);
    // 0x801CAA88: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CAA8C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801CAA90: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x801CAA94: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x801CAA98: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x801CAA9C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAAA0: jal         0x8001EAD0
    // 0x801CAAA4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_46;
    // 0x801CAAA4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_46:
    // 0x801CAAA8: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAAAC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801CAAB0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801CAAB4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801CAAB8: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x801CAABC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAAC0: jal         0x8001EB64
    // 0x801CAAC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_47;
    // 0x801CAAC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_47:
    // 0x801CAAC8: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAACC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801CAAD0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CAAD4: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801CAAD8: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x801CAADC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAAE0: jal         0x8001EAD0
    // 0x801CAAE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_48;
    // 0x801CAAE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_48:
    // 0x801CAAE8: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAAEC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801CAAF0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801CAAF4: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801CAAF8: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x801CAAFC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAB00: jal         0x8001EB64
    // 0x801CAB04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_49;
    // 0x801CAB04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_49:
    // 0x801CAB08: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CAB0C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801CAB10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801CAB14: lw          $t2, 0xE0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAB18: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801CAB1C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CAB20: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801CAB24: lw          $s0, 0x2C($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X2C);
    // 0x801CAB28: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CAB2C: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801CAB30: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CAB34: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801CAB38: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CAB3C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801CAB40: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801CAB44: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801CAB48: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CAB4C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CAB50: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801CAB54: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801CAB58: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801CAB5C: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x801CAB60: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801CAB64: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CAB68: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x801CAB6C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801CAB70: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801CAB74: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801CAB78: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801CAB7C: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x801CAB80: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801CAB84: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801CAB88: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x801CAB8C: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801CAB90: mul.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f28.d);
    // 0x801CAB94: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801CAB98: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801CAB9C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801CABA0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801CABA4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801CABA8: mul.d       $f6, $f10, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f28.d);
    // 0x801CABAC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CABB0: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CABB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CABB8: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801CABBC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CABC0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801CABC4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801CABC8: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CABCC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CABD0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801CABD4: jal         0x801E02DC
    // 0x801CABD8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_50;
    // 0x801CABD8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_50:
    // 0x801CABDC: b           L_801CB6EC
    // 0x801CABE0: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
        goto L_801CB6EC;
    // 0x801CABE0: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801CABE4:
    // 0x801CABE4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801CABE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CABEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801CABF0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CABF4: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801CABF8: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x801CABFC: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x801CAC00: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x801CAC04: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x801CAC08: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801CAC0C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CAC10: nop

    // 0x801CAC14: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CAC18: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CAC1C: nop

    // 0x801CAC20: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801CAC24: beql        $t3, $zero, L_801CAC74
    if (ctx->r11 == 0) {
        // 0x801CAC28: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_801CAC74;
    }
    goto skip_30;
    // 0x801CAC28: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_30:
    // 0x801CAC2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CAC30: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801CAC34: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801CAC38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CAC3C: nop

    // 0x801CAC40: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CAC44: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CAC48: nop

    // 0x801CAC4C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801CAC50: bne         $t3, $zero, L_801CAC68
    if (ctx->r11 != 0) {
        // 0x801CAC54: nop
    
            goto L_801CAC68;
    }
    // 0x801CAC54: nop

    // 0x801CAC58: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x801CAC5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CAC60: b           L_801CAC80
    // 0x801CAC64: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801CAC80;
    // 0x801CAC64: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801CAC68:
    // 0x801CAC68: b           L_801CAC80
    // 0x801CAC6C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801CAC80;
    // 0x801CAC6C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801CAC70: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_801CAC74:
    // 0x801CAC74: nop

    // 0x801CAC78: bltz        $t3, L_801CAC68
    if (SIGNED(ctx->r11) < 0) {
        // 0x801CAC7C: nop
    
            goto L_801CAC68;
    }
    // 0x801CAC7C: nop

L_801CAC80:
    // 0x801CAC80: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801CAC84: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801CAC88: beq         $t4, $v1, L_801CAD28
    if (ctx->r12 == ctx->r3) {
        // 0x801CAC8C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_801CAD28;
    }
    // 0x801CAC8C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CAC90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CAC94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CAC98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CAC9C: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801CACA0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801CACA4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CACA8: nop

    // 0x801CACAC: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CACB0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CACB4: nop

    // 0x801CACB8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CACBC: beql        $t6, $zero, L_801CAD0C
    if (ctx->r14 == 0) {
        // 0x801CACC0: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_801CAD0C;
    }
    goto skip_31;
    // 0x801CACC0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_31:
    // 0x801CACC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CACC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CACCC: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801CACD0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CACD4: nop

    // 0x801CACD8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CACDC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CACE0: nop

    // 0x801CACE4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801CACE8: bne         $t6, $zero, L_801CAD00
    if (ctx->r14 != 0) {
        // 0x801CACEC: nop
    
            goto L_801CAD00;
    }
    // 0x801CACEC: nop

    // 0x801CACF0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801CACF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CACF8: b           L_801CAD18
    // 0x801CACFC: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801CAD18;
    // 0x801CACFC: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801CAD00:
    // 0x801CAD00: b           L_801CAD18
    // 0x801CAD04: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801CAD18;
    // 0x801CAD04: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801CAD08: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_801CAD0C:
    // 0x801CAD0C: nop

    // 0x801CAD10: bltz        $t6, L_801CAD00
    if (SIGNED(ctx->r14) < 0) {
        // 0x801CAD14: nop
    
            goto L_801CAD00;
    }
    // 0x801CAD14: nop

L_801CAD18:
    // 0x801CAD18: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801CAD1C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801CAD20: bne         $t7, $v1, L_801CADB4
    if (ctx->r15 != ctx->r3) {
        // 0x801CAD24: nop
    
            goto L_801CADB4;
    }
    // 0x801CAD24: nop

L_801CAD28:
    // 0x801CAD28: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAD2C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CAD30: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CAD34: lw          $s0, 0x2C($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X2C);
    // 0x801CAD38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CAD3C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CAD40: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CAD44: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CAD48: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CAD4C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801CAD50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CAD54: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x801CAD58: lwc1        $f8, 0x3118($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3118);
    // 0x801CAD5C: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CAD60: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CAD64: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CAD68: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x801CAD6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801CAD70: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CAD74: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x801CAD78: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x801CAD7C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x801CAD80: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801CAD84: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801CAD88: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801CAD8C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CAD90: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CAD94: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801CAD98: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801CAD9C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801CADA0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CADA4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CADA8: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CADAC: jal         0x801E02DC
    // 0x801CADB0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_51;
    // 0x801CADB0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_51:
L_801CADB4:
    // 0x801CADB4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CADB8: jal         0x8012C6B4
    // 0x801CADBC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_52;
    // 0x801CADBC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_52:
    // 0x801CADC0: bne         $v0, $zero, L_801CB6E8
    if (ctx->r2 != 0) {
        // 0x801CADC4: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_801CB6E8;
    }
    // 0x801CADC4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CADC8: lw          $t7, 0xE0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XE0);
    // 0x801CADCC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801CADD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CADD4: lw          $s0, 0x2C($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X2C);
    // 0x801CADD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CADDC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CADE0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CADE4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CADE8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CADEC: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801CADF0: lwc1        $f4, 0x311C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X311C);
    // 0x801CADF4: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801CADF8: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x801CADFC: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x801CAE00: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x801CAE04: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801CAE08: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CAE0C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CAE10: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x801CAE14: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801CAE18: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x801CAE1C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x801CAE20: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801CAE24: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801CAE28: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801CAE2C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801CAE30: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801CAE34: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801CAE38: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801CAE3C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CAE40: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CAE44: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CAE48: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CAE4C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CAE50: jal         0x801E02DC
    // 0x801CAE54: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_53;
    // 0x801CAE54: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_53:
    // 0x801CAE58: b           L_801CB6EC
    // 0x801CAE5C: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
        goto L_801CB6EC;
    // 0x801CAE5C: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801CAE60:
    // 0x801CAE60: lbu         $t6, 0xEB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XEB);
    // 0x801CAE64: addiu       $t8, $sp, 0xD0
    ctx->r24 = ADD32(ctx->r29, 0XD0);
    // 0x801CAE68: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CAE6C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801CAE70: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x801CAE74: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801CAE78:
    // 0x801CAE78: jal         0x8012C6B4
    // 0x801CAE7C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_54;
    // 0x801CAE7C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_54:
    // 0x801CAE80: lw          $t9, 0xE0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAE84: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x801CAE88: addiu       $t3, $v1, -0x400
    ctx->r11 = ADD32(ctx->r3, -0X400);
    // 0x801CAE8C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801CAE90: sll         $s0, $t3, 16
    ctx->r16 = S32(ctx->r11 << 16);
    // 0x801CAE94: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801CAE98: lh          $t1, 0x12($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X12);
    // 0x801CAE9C: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    // 0x801CAEA0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAEA4: jal         0x8001EAD0
    // 0x801CAEA8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_55;
    // 0x801CAEA8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_55:
    // 0x801CAEAC: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAEB0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801CAEB4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801CAEB8: lh          $t6, 0x12($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X12);
    // 0x801CAEBC: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    // 0x801CAEC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAEC4: jal         0x8001EB64
    // 0x801CAEC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_56;
    // 0x801CAEC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_56:
    // 0x801CAECC: lw          $t7, 0xE0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAED0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801CAED4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CAED8: lh          $t9, 0x12($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X12);
    // 0x801CAEDC: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x801CAEE0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAEE4: jal         0x8001EAD0
    // 0x801CAEE8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_57;
    // 0x801CAEE8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_57:
    // 0x801CAEEC: lw          $t0, 0xE0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAEF0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801CAEF4: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801CAEF8: lh          $t1, 0x12($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X12);
    // 0x801CAEFC: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    // 0x801CAF00: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CAF04: jal         0x8001EB64
    // 0x801CAF08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_58;
    // 0x801CAF08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_58:
    // 0x801CAF0C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CAF10: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801CAF14: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801CAF18: lw          $t3, 0xE0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XE0);
    // 0x801CAF1C: cvt.d.s     $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.d = CVT_D_S(ctx->f24.fl);
    // 0x801CAF20: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CAF24: mul.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801CAF28: lw          $s0, 0x2C($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X2C);
    // 0x801CAF2C: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801CAF30: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801CAF34: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CAF38: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CAF3C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CAF40: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801CAF44: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801CAF48: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x801CAF4C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CAF50: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801CAF54: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801CAF58: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801CAF5C: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801CAF60: addiu       $t0, $zero, 0x96
    ctx->r8 = ADD32(0, 0X96);
    // 0x801CAF64: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801CAF68: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CAF6C: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x801CAF70: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801CAF74: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801CAF78: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801CAF7C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x801CAF80: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x801CAF84: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801CAF88: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801CAF8C: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801CAF90: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801CAF94: mul.d       $f6, $f10, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f30.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f30.d);
    // 0x801CAF98: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801CAF9C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x801CAFA0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801CAFA4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801CAFA8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801CAFAC: mul.d       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f30.d);
    // 0x801CAFB0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CAFB4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CAFB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CAFBC: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801CAFC0: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x801CAFC4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801CAFC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801CAFCC: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CAFD0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CAFD4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801CAFD8: jal         0x801E02DC
    // 0x801CAFDC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_59;
    // 0x801CAFDC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_59:
    // 0x801CAFE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801CAFE4: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801CAFE8: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x801CAFEC: bne         $at, $zero, L_801CAE78
    if (ctx->r1 != 0) {
        // 0x801CAFF0: nop
    
            goto L_801CAE78;
    }
    // 0x801CAFF0: nop

    // 0x801CAFF4: jal         0x8012C6B4
    // 0x801CAFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_60;
    // 0x801CAFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_60:
    // 0x801CAFFC: bne         $v0, $zero, L_801CB6E8
    if (ctx->r2 != 0) {
        // 0x801CB000: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_801CB6E8;
    }
    // 0x801CB000: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CB004: lw          $t3, 0xE0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB008: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801CB00C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CB010: lw          $s0, 0x2C($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X2C);
    // 0x801CB014: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB018: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CB01C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CB020: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CB024: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CB028: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CB02C: lwc1        $f8, 0x3120($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3120);
    // 0x801CB030: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x801CB034: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x801CB038: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x801CB03C: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x801CB040: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CB044: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CB048: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801CB04C: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x801CB050: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801CB054: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801CB058: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801CB05C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x801CB060: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801CB064: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801CB068: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801CB06C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x801CB070: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801CB074: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x801CB078: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CB07C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CB080: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CB084: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CB088: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CB08C: jal         0x801E02DC
    // 0x801CB090: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_61;
    // 0x801CB090: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_61:
    // 0x801CB094: b           L_801CB6EC
    // 0x801CB098: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
        goto L_801CB6EC;
    // 0x801CB098: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801CB09C:
    // 0x801CB09C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801CB0A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CB0A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CB0A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CB0AC: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801CB0B0: lhu         $t1, 0x4($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X4);
    // 0x801CB0B4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CB0B8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CB0BC: nop

    // 0x801CB0C0: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CB0C4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CB0C8: nop

    // 0x801CB0CC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CB0D0: beql        $t4, $zero, L_801CB120
    if (ctx->r12 == 0) {
        // 0x801CB0D4: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_801CB120;
    }
    goto skip_32;
    // 0x801CB0D4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_32:
    // 0x801CB0D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CB0DC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CB0E0: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801CB0E4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CB0E8: nop

    // 0x801CB0EC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CB0F0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CB0F4: nop

    // 0x801CB0F8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CB0FC: bne         $t4, $zero, L_801CB114
    if (ctx->r12 != 0) {
        // 0x801CB100: nop
    
            goto L_801CB114;
    }
    // 0x801CB100: nop

    // 0x801CB104: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801CB108: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CB10C: b           L_801CB12C
    // 0x801CB110: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801CB12C;
    // 0x801CB110: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801CB114:
    // 0x801CB114: b           L_801CB12C
    // 0x801CB118: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801CB12C;
    // 0x801CB118: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CB11C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_801CB120:
    // 0x801CB120: nop

    // 0x801CB124: bltz        $t4, L_801CB114
    if (SIGNED(ctx->r12) < 0) {
        // 0x801CB128: nop
    
            goto L_801CB114;
    }
    // 0x801CB128: nop

L_801CB12C:
    // 0x801CB12C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x801CB130: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801CB134: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CB138: beql        $at, $zero, L_801CB6EC
    if (ctx->r1 == 0) {
        // 0x801CB13C: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_801CB6EC;
    }
    goto skip_33;
    // 0x801CB13C: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_33:
    // 0x801CB140: jal         0x8012C6B4
    // 0x801CB144: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_62;
    // 0x801CB144: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_62:
    // 0x801CB148: bne         $v0, $zero, L_801CB1E4
    if (ctx->r2 != 0) {
        // 0x801CB14C: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_801CB1E4;
    }
    // 0x801CB14C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CB150: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB154: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801CB158: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CB15C: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x801CB160: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CB164: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB168: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CB16C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CB170: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CB174: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CB178: lwc1        $f8, 0x3124($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3124);
    // 0x801CB17C: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x801CB180: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x801CB184: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x801CB188: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x801CB18C: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CB190: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CB194: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CB198: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x801CB19C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801CB1A0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CB1A4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x801CB1A8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x801CB1AC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801CB1B0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801CB1B4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CB1B8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801CB1BC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CB1C0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CB1C4: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x801CB1C8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CB1CC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CB1D0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CB1D4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CB1D8: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CB1DC: jal         0x801E02DC
    // 0x801CB1E0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_63;
    // 0x801CB1E0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_63:
L_801CB1E4:
    // 0x801CB1E4: lbu         $t5, 0xEB($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XEB);
    // 0x801CB1E8: addiu       $t7, $sp, 0xD0
    ctx->r15 = ADD32(ctx->r29, 0XD0);
    // 0x801CB1EC: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CB1F0: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x801CB1F4: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x801CB1F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801CB1FC:
    // 0x801CB1FC: jal         0x8012C6B4
    // 0x801CB200: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_64;
    // 0x801CB200: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_64:
    // 0x801CB204: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB208: sll         $t3, $v0, 8
    ctx->r11 = S32(ctx->r2 << 8);
    // 0x801CB20C: sll         $s0, $t3, 16
    ctx->r16 = S32(ctx->r11 << 16);
    // 0x801CB210: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CB214: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801CB218: lh          $t0, 0x12($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X12);
    // 0x801CB21C: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    // 0x801CB220: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB224: jal         0x8001EAD0
    // 0x801CB228: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_65;
    // 0x801CB228: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_65:
    // 0x801CB22C: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB230: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801CB234: lw          $t1, 0x2C($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X2C);
    // 0x801CB238: lh          $t5, 0x12($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X12);
    // 0x801CB23C: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    // 0x801CB240: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB244: jal         0x8001EB64
    // 0x801CB248: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_66;
    // 0x801CB248: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_66:
    // 0x801CB24C: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB250: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801CB254: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801CB258: lh          $t8, 0x12($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X12);
    // 0x801CB25C: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x801CB260: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB264: jal         0x8001EAD0
    // 0x801CB268: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_67;
    // 0x801CB268: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_67:
    // 0x801CB26C: lw          $t9, 0xE0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB270: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801CB274: lw          $t2, 0x2C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X2C);
    // 0x801CB278: lh          $t0, 0x12($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X12);
    // 0x801CB27C: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    // 0x801CB280: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB284: jal         0x8001EB64
    // 0x801CB288: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_68;
    // 0x801CB288: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_68:
    // 0x801CB28C: lw          $t3, 0xE0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB290: cvt.d.s     $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.d = CVT_D_S(ctx->f24.fl);
    // 0x801CB294: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CB298: mul.d       $f6, $f10, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f28.d);
    // 0x801CB29C: lw          $s0, 0x2C($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X2C);
    // 0x801CB2A0: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801CB2A4: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801CB2A8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CB2AC: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801CB2B0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CB2B4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801CB2B8: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801CB2BC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801CB2C0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CB2C4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CB2C8: cvt.d.s     $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.d = CVT_D_S(ctx->f22.fl);
    // 0x801CB2CC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801CB2D0: mul.d       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f28.d);
    // 0x801CB2D4: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x801CB2D8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801CB2DC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CB2E0: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x801CB2E4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801CB2E8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801CB2EC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801CB2F0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801CB2F4: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801CB2F8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801CB2FC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801CB300: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801CB304: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801CB308: mul.d       $f6, $f10, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f30.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f30.d);
    // 0x801CB30C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801CB310: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801CB314: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801CB318: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801CB31C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801CB320: mul.d       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f30.d);
    // 0x801CB324: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CB328: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CB32C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CB330: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CB334: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x801CB338: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801CB33C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801CB340: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CB344: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CB348: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x801CB34C: jal         0x801E02DC
    // 0x801CB350: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_69;
    // 0x801CB350: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_69:
    // 0x801CB354: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801CB358: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801CB35C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x801CB360: bne         $at, $zero, L_801CB1FC
    if (ctx->r1 != 0) {
        // 0x801CB364: nop
    
            goto L_801CB1FC;
    }
    // 0x801CB364: nop

    // 0x801CB368: b           L_801CB6EC
    // 0x801CB36C: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
        goto L_801CB6EC;
    // 0x801CB36C: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801CB370:
    // 0x801CB370: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801CB374: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CB378: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CB37C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CB380: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801CB384: lhu         $t3, 0x4($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X4);
    // 0x801CB388: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CB38C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CB390: nop

    // 0x801CB394: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CB398: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CB39C: nop

    // 0x801CB3A0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CB3A4: beql        $t1, $zero, L_801CB3F4
    if (ctx->r9 == 0) {
        // 0x801CB3A8: mfc1        $t1, $f6
        ctx->r9 = (int32_t)ctx->f6.u32l;
            goto L_801CB3F4;
    }
    goto skip_34;
    // 0x801CB3A8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    skip_34:
    // 0x801CB3AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CB3B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CB3B4: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801CB3B8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CB3BC: nop

    // 0x801CB3C0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CB3C4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CB3C8: nop

    // 0x801CB3CC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CB3D0: bne         $t1, $zero, L_801CB3E8
    if (ctx->r9 != 0) {
        // 0x801CB3D4: nop
    
            goto L_801CB3E8;
    }
    // 0x801CB3D4: nop

    // 0x801CB3D8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x801CB3DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CB3E0: b           L_801CB400
    // 0x801CB3E4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801CB400;
    // 0x801CB3E4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801CB3E8:
    // 0x801CB3E8: b           L_801CB400
    // 0x801CB3EC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801CB400;
    // 0x801CB3EC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801CB3F0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
L_801CB3F4:
    // 0x801CB3F4: nop

    // 0x801CB3F8: bltz        $t1, L_801CB3E8
    if (SIGNED(ctx->r9) < 0) {
        // 0x801CB3FC: nop
    
            goto L_801CB3E8;
    }
    // 0x801CB3FC: nop

L_801CB400:
    // 0x801CB400: andi        $t5, $t1, 0xFFFF
    ctx->r13 = ctx->r9 & 0XFFFF;
    // 0x801CB404: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801CB408: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CB40C: beq         $at, $zero, L_801CB644
    if (ctx->r1 == 0) {
        // 0x801CB410: nop
    
            goto L_801CB644;
    }
    // 0x801CB410: nop

    // 0x801CB414: jal         0x8012C6B4
    // 0x801CB418: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_70;
    // 0x801CB418: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_70:
    // 0x801CB41C: bne         $v0, $zero, L_801CB4B8
    if (ctx->r2 != 0) {
        // 0x801CB420: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_801CB4B8;
    }
    // 0x801CB420: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CB424: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB428: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CB42C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CB430: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x801CB434: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CB438: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB43C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CB440: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CB444: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CB448: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801CB44C: lwc1        $f8, 0x3128($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3128);
    // 0x801CB450: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x801CB454: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x801CB458: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x801CB45C: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x801CB460: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CB464: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CB468: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CB46C: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x801CB470: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801CB474: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CB478: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x801CB47C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x801CB480: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x801CB484: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801CB488: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801CB48C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801CB490: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CB494: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CB498: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801CB49C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CB4A0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CB4A4: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CB4A8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CB4AC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CB4B0: jal         0x801E02DC
    // 0x801CB4B4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_71;
    // 0x801CB4B4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_71:
L_801CB4B8:
    // 0x801CB4B8: lbu         $t5, 0xEB($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XEB);
    // 0x801CB4BC: addiu       $t7, $sp, 0xD0
    ctx->r15 = ADD32(ctx->r29, 0XD0);
    // 0x801CB4C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB4C4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x801CB4C8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CB4CC: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x801CB4D0: ldc1        $f28, 0x3130($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X3130);
    // 0x801CB4D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801CB4D8:
    // 0x801CB4D8: jal         0x8012C6B4
    // 0x801CB4DC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_72;
    // 0x801CB4DC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_72:
    // 0x801CB4E0: lw          $t8, 0xE0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB4E4: sll         $t4, $v0, 8
    ctx->r12 = S32(ctx->r2 << 8);
    // 0x801CB4E8: sll         $s0, $t4, 16
    ctx->r16 = S32(ctx->r12 << 16);
    // 0x801CB4EC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CB4F0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801CB4F4: lh          $t2, 0x12($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X12);
    // 0x801CB4F8: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x801CB4FC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB500: jal         0x8001EAD0
    // 0x801CB504: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_73;
    // 0x801CB504: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_73:
    // 0x801CB508: lw          $t1, 0xE0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB50C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801CB510: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801CB514: lh          $t5, 0x12($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X12);
    // 0x801CB518: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    // 0x801CB51C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB520: jal         0x8001EB64
    // 0x801CB524: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_74;
    // 0x801CB524: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_74:
    // 0x801CB528: lw          $t6, 0xE0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB52C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801CB530: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801CB534: lh          $t8, 0x12($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X12);
    // 0x801CB538: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x801CB53C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB540: jal         0x8001EAD0
    // 0x801CB544: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_75;
    // 0x801CB544: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_75:
    // 0x801CB548: lw          $t9, 0xE0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB54C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801CB550: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801CB554: lh          $t2, 0x12($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X12);
    // 0x801CB558: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    // 0x801CB55C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801CB560: jal         0x8001EB64
    // 0x801CB564: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_76;
    // 0x801CB564: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_76:
    // 0x801CB568: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB56C: lwc1        $f30, 0x4($s2)
    ctx->f30.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801CB570: cvt.d.s     $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f16.d = CVT_D_S(ctx->f22.fl);
    // 0x801CB574: lw          $s0, 0x2C($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X2C);
    // 0x801CB578: add.d       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f16.d + ctx->f16.d;
    // 0x801CB57C: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801CB580: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CB584: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CB588: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CB58C: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x801CB590: cvt.d.s     $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.d = CVT_D_S(ctx->f24.fl);
    // 0x801CB594: add.d       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f18.d + ctx->f10.d;
    // 0x801CB598: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CB59C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CB5A0: add.d       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f2.d + ctx->f2.d;
    // 0x801CB5A4: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CB5A8: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801CB5AC: cvt.s.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f10.fl = CVT_S_D(ctx->f10.d);
    // 0x801CB5B0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801CB5B4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801CB5B8: add.s       $f14, $f30, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f30.fl + ctx->f6.fl;
    // 0x801CB5BC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801CB5C0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801CB5C4: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801CB5C8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801CB5CC: mul.d       $f10, $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f28.d);
    // 0x801CB5D0: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x801CB5D4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CB5D8: add.d       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f18.d + ctx->f8.d;
    // 0x801CB5DC: mul.d       $f6, $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f28.d);
    // 0x801CB5E0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801CB5E4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CB5E8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801CB5EC: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x801CB5F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801CB5F4: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x801CB5F8: cvt.s.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f10.fl = CVT_S_D(ctx->f10.d);
    // 0x801CB5FC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801CB600: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801CB604: cvt.s.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f6.fl = CVT_S_D(ctx->f6.d);
    // 0x801CB608: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801CB60C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801CB610: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801CB614: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801CB618: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801CB61C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801CB620: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801CB624: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801CB628: jal         0x801E02DC
    // 0x801CB62C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_77;
    // 0x801CB62C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_77:
    // 0x801CB630: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801CB634: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801CB638: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x801CB63C: bne         $at, $zero, L_801CB4D8
    if (ctx->r1 != 0) {
        // 0x801CB640: nop
    
            goto L_801CB4D8;
    }
    // 0x801CB640: nop

L_801CB644:
    // 0x801CB644: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
L_801CB648:
    // 0x801CB648: jal         0x8012C6B4
    // 0x801CB64C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_78;
    // 0x801CB64C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_78:
    // 0x801CB650: bne         $v0, $zero, L_801CB6E8
    if (ctx->r2 != 0) {
        // 0x801CB654: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_801CB6E8;
    }
    // 0x801CB654: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CB658: lw          $t4, 0xE0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XE0);
    // 0x801CB65C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CB660: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CB664: lw          $s0, 0x2C($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X2C);
    // 0x801CB668: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB66C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x801CB670: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CB674: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CB678: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801CB67C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801CB680: lwc1        $f8, 0x3138($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3138);
    // 0x801CB684: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801CB688: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x801CB68C: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x801CB690: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x801CB694: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801CB698: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801CB69C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CB6A0: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x801CB6A4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801CB6A8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801CB6AC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801CB6B0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801CB6B4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801CB6B8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801CB6BC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801CB6C0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801CB6C4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801CB6C8: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x801CB6CC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CB6D0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CB6D4: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801CB6D8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801CB6DC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801CB6E0: jal         0x801E02DC
    // 0x801CB6E4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801E02DC)(rdram, ctx);
        goto after_79;
    // 0x801CB6E4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_79:
L_801CB6E8:
    // 0x801CB6E8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_801CB6EC:
    // 0x801CB6EC: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x801CB6F0: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x801CB6F4: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x801CB6F8: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x801CB6FC: ldc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X68);
    // 0x801CB700: ldc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X70);
    // 0x801CB704: lw          $s0, 0x7C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X7C);
    // 0x801CB708: lw          $s1, 0x80($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X80);
    // 0x801CB70C: lw          $s2, 0x84($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X84);
    // 0x801CB710: lw          $s3, 0x88($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X88);
    // 0x801CB714: jr          $ra
    // 0x801CB718: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x801CB718: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cb71c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cb71c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CB720: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CB724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CB728: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x801CB72C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801CB730: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x801CB734: sb          $v0, 0x98($a0)
    MEM_B(0X98, ctx->r4) = ctx->r2;
    // 0x801CB738: sh          $v0, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r2;
    // 0x801CB73C: sb          $zero, 0x99($a0)
    MEM_B(0X99, ctx->r4) = 0;
    // 0x801CB740: lw          $t6, 0xDC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XDC);
    // 0x801CB744: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801CB748: beql        $t7, $zero, L_801CB858
    if (ctx->r15 == 0) {
        // 0x801CB74C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CB858;
    }
    goto skip_0;
    // 0x801CB74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CB750: lbu         $t8, 0xF5($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF5);
    // 0x801CB754: beql        $t8, $zero, L_801CB858
    if (ctx->r24 == 0) {
        // 0x801CB758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CB858;
    }
    goto skip_1;
    // 0x801CB758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801CB75C: lbu         $t9, 0xEF5($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XEF5);
    // 0x801CB760: bnel        $t9, $zero, L_801CB858
    if (ctx->r25 != 0) {
        // 0x801CB764: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CB858;
    }
    goto skip_2;
    // 0x801CB764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801CB768: lw          $t0, 0xEF8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XEF8);
    // 0x801CB76C: beql        $t0, $zero, L_801CB858
    if (ctx->r8 == 0) {
        // 0x801CB770: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CB858;
    }
    goto skip_3;
    // 0x801CB770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x801CB774: lhu         $t1, 0xEF0($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XEF0);
    // 0x801CB778: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x801CB77C: beql        $t2, $zero, L_801CB858
    if (ctx->r10 == 0) {
        // 0x801CB780: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CB858;
    }
    goto skip_4;
    // 0x801CB780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x801CB784: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x801CB788: lw          $t3, 0xE0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XE0);
    // 0x801CB78C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801CB790: lh          $t4, 0xA($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XA);
    // 0x801CB794: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801CB798: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801CB79C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x801CB7A0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801CB7A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801CB7A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801CB7AC: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x801CB7B0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801CB7B4: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x801CB7B8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801CB7BC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801CB7C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CB7C4: div.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f16.d);
    // 0x801CB7C8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801CB7CC: sub.d       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f6.d - ctx->f4.d;
    // 0x801CB7D0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801CB7D4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CB7D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CB7DC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801CB7E0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801CB7E4: div.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f16.d);
    // 0x801CB7E8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CB7EC: sub.d       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f10.d - ctx->f8.d;
    // 0x801CB7F0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CB7F4: mul.d       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x801CB7F8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801CB7FC: div.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x801CB800: sub.d       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f6.d - ctx->f18.d;
    // 0x801CB804: mul.d       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f14.d, ctx->f14.d);
    // 0x801CB808: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x801CB80C: mul.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x801CB810: add.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f6.d + ctx->f8.d;
    // 0x801CB814: jal         0x8002FC20
    // 0x801CB818: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801CB818: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x801CB81C: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x801CB820: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CB824: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CB828: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801CB82C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB830: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x801CB834: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CB838: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CB83C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB840: bc1f        L_801CB854
    if (!c1cs) {
        // 0x801CB844: addiu       $a1, $a1, -0x479C
        ctx->r5 = ADD32(ctx->r5, -0X479C);
            goto L_801CB854;
    }
    // 0x801CB844: addiu       $a1, $a1, -0x479C
    ctx->r5 = ADD32(ctx->r5, -0X479C);
    // 0x801CB848: sb          $t7, 0x98($a0)
    MEM_B(0X98, ctx->r4) = ctx->r15;
    // 0x801CB84C: jal         0x800058DC
    // 0x801CB850: sh          $zero, 0x405C($at)
    MEM_H(0X405C, ctx->r1) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CB850: sh          $zero, 0x405C($at)
    MEM_H(0X405C, ctx->r1) = 0;
    after_1:
L_801CB854:
    // 0x801CB854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CB858:
    // 0x801CB858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CB85C: jr          $ra
    // 0x801CB860: nop

    return;
    // 0x801CB860: nop

;}
RECOMP_FUNC void M8_FUN_801cb864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB864: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x801CB868: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x801CB86C: sw          $fp, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r30;
    // 0x801CB870: sw          $s7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r23;
    // 0x801CB874: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x801CB878: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x801CB87C: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x801CB880: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x801CB884: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x801CB888: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x801CB88C: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x801CB890: sdc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X78, ctx->r29);
    // 0x801CB894: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x801CB898: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x801CB89C: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x801CB8A0: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x801CB8A4: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x801CB8A8: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x801CB8AC: lbu         $a2, 0x98($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X98);
    // 0x801CB8B0: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x801CB8B4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801CB8B8: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x801CB8BC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801CB8C0: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x801CB8C4: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x801CB8C8: lui         $s7, 0x801E
    ctx->r23 = S32(0X801E << 16);
    // 0x801CB8CC: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801CB8D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801CB8D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CB8D8: addiu       $s7, $s7, 0x405C
    ctx->r23 = ADD32(ctx->r23, 0X405C);
    // 0x801CB8DC: addiu       $s5, $s5, -0x4410
    ctx->r21 = ADD32(ctx->r21, -0X4410);
    // 0x801CB8E0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x801CB8E4: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x801CB8E8: sra         $a1, $v1, 12
    ctx->r5 = S32(SIGNED(ctx->r3) >> 12);
    // 0x801CB8EC: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
L_801CB8F0:
    // 0x801CB8F0: andi        $s3, $a1, 0xFF
    ctx->r19 = ctx->r5 & 0XFF;
    // 0x801CB8F4: beq         $s3, $zero, L_801CBB84
    if (ctx->r19 == 0) {
        // 0x801CB8F8: andi        $s4, $s4, 0xFFF
        ctx->r20 = ctx->r20 & 0XFFF;
            goto L_801CBB84;
    }
    // 0x801CB8F8: andi        $s4, $s4, 0xFFF
    ctx->r20 = ctx->r20 & 0XFFF;
    // 0x801CB8FC: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x801CB900: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x801CB904: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x801CB908: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801CB90C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801CB910: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x801CB914: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CB918: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x801CB91C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x801CB920: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801CB924: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801CB928: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801CB92C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801CB930: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x801CB934: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x801CB938: cvt.s.d     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f24.fl = CVT_S_D(ctx->f10.d);
    // 0x801CB93C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801CB940: nop

    // 0x801CB944: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801CB948: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801CB94C: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x801CB950: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801CB954: cvt.s.d     $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f26.fl = CVT_S_D(ctx->f8.d);
    // 0x801CB958: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801CB95C: nop

    // 0x801CB960: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801CB964: div.d       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x801CB968: cvt.s.d     $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f28.fl = CVT_S_D(ctx->f6.d);
    // 0x801CB96C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801CB970: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x801CB974: cvt.s.d     $f30, $f18
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f30.fl = CVT_S_D(ctx->f18.d);
    // 0x801CB978: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801CB97C: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x801CB980: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x801CB984: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x801CB988: nop

    // 0x801CB98C: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801CB990: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x801CB994: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CB998: beq         $fp, $s3, L_801CBC28
    if (ctx->r30 == ctx->r19) {
        // 0x801CB99C: swc1        $f8, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
            goto L_801CBC28;
    }
    // 0x801CB99C: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801CB9A0: bne         $s3, $at, L_801CB9D8
    if (ctx->r19 != ctx->r1) {
        // 0x801CB9A4: nop
    
            goto L_801CB9D8;
    }
    // 0x801CB9A4: nop

    // 0x801CB9A8: lhu         $v0, 0x9C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X9C);
    // 0x801CB9AC: addiu       $t4, $a2, 0x1
    ctx->r12 = ADD32(ctx->r6, 0X1);
    // 0x801CB9B0: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x801CB9B4: bnel        $at, $zero, L_801CB9D0
    if (ctx->r1 != 0) {
        // 0x801CB9B8: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_801CB9D0;
    }
    goto skip_0;
    // 0x801CB9B8: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x801CB9BC: sb          $t4, 0x98($s1)
    MEM_B(0X98, ctx->r17) = ctx->r12;
    // 0x801CB9C0: sh          $zero, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = 0;
    // 0x801CB9C4: b           L_801CBC28
    // 0x801CB9C8: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
        goto L_801CBC28;
    // 0x801CB9C8: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    // 0x801CB9CC: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
L_801CB9D0:
    // 0x801CB9D0: b           L_801CBC28
    // 0x801CB9D4: sh          $t5, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r13;
        goto L_801CBC28;
    // 0x801CB9D4: sh          $t5, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r13;
L_801CB9D8:
    // 0x801CB9D8: bne         $s6, $s2, L_801CBAA4
    if (ctx->r22 != ctx->r18) {
        // 0x801CB9DC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801CBAA4;
    }
    // 0x801CB9DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CB9E0: lbu         $t6, 0x99($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X99);
    // 0x801CB9E4: bne         $t6, $zero, L_801CBAC0
    if (ctx->r14 != 0) {
        // 0x801CB9E8: nop
    
            goto L_801CBAC0;
    }
    // 0x801CB9E8: nop

    // 0x801CB9EC: lw          $t7, 0xE8($s5)
    ctx->r15 = MEM_W(ctx->r21, 0XE8);
    // 0x801CB9F0: lw          $s0, 0x2C($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X2C);
    // 0x801CB9F4: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x801CB9F8: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x801CB9FC: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x801CBA00: sub.s       $f0, $f10, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x801CBA04: sub.s       $f2, $f18, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f26.fl;
    // 0x801CBA08: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CBA0C: sub.s       $f14, $f4, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x801CBA10: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801CBA14: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801CBA18: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CBA1C: jal         0x8002FC20
    // 0x801CBA20: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801CBA20: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_0:
    // 0x801CBA24: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x801CBA28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CBA2C: bgez        $s4, L_801CBA40
    if (SIGNED(ctx->r20) >= 0) {
        // 0x801CBA30: cvt.s.w     $f22, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CBA40;
    }
    // 0x801CBA30: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CBA34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CBA38: nop

    // 0x801CBA3C: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
L_801CBA40:
    // 0x801CBA40: div.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801CBA44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBA48: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801CBA4C: swc1        $f8, 0x4060($at)
    MEM_W(0X4060, ctx->r1) = ctx->f8.u32l;
    // 0x801CBA50: lw          $t8, 0xE8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0XE8);
    // 0x801CBA54: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801CBA58: lw          $s0, 0x2C($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X2C);
    // 0x801CBA5C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x801CBA60: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801CBA64: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x801CBA68: sub.s       $f2, $f10, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x801CBA6C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801CBA70: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801CBA74: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801CBA78: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CBA7C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801CBA80: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801CBA84: jal         0x8002FC20
    // 0x801CBA88: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801CBA88: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x801CBA8C: div.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801CBA90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBA94: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CBA98: swc1        $f8, 0x4064($at)
    MEM_W(0X4064, ctx->r1) = ctx->f8.u32l;
    // 0x801CBA9C: b           L_801CBAC0
    // 0x801CBAA0: sb          $t9, 0x99($s1)
    MEM_B(0X99, ctx->r17) = ctx->r25;
        goto L_801CBAC0;
    // 0x801CBAA0: sb          $t9, 0x99($s1)
    MEM_B(0X99, ctx->r17) = ctx->r25;
L_801CBAA4:
    // 0x801CBAA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CBAA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBAAC: swc1        $f10, 0x4064($at)
    MEM_W(0X4064, ctx->r1) = ctx->f10.u32l;
    // 0x801CBAB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CBAB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CBAB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBABC: swc1        $f18, 0x4060($at)
    MEM_W(0X4060, ctx->r1) = ctx->f18.u32l;
L_801CBAC0:
    // 0x801CBAC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBAC4: lwc1        $f4, 0x4060($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4060);
    // 0x801CBAC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBACC: lwc1        $f6, 0x4064($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4064);
    // 0x801CBAD0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801CBAD4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801CBAD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CBADC: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801CBAE0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801CBAE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801CBAE8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CBAEC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801CBAF0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801CBAF4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801CBAF8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x801CBAFC: addiu       $a0, $a0, 0x2FA4
    ctx->r4 = ADD32(ctx->r4, 0X2FA4);
    // 0x801CBB00: addiu       $a1, $zero, 0x37C
    ctx->r5 = ADD32(0, 0X37C);
    // 0x801CBB04: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801CBB08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CBB0C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x801CBB10: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x801CBB14: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x801CBB18: swc1        $f28, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f28.u32l;
    // 0x801CBB1C: swc1        $f30, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f30.u32l;
    // 0x801CBB20: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801CBB24: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801CBB28: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801CBB2C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801CBB30: jal         0x8011AAF4
    // 0x801CBB34: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_2;
    // 0x801CBB34: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801CBB38: bnel        $v0, $zero, L_801CBC2C
    if (ctx->r2 != 0) {
        // 0x801CBB3C: lw          $ra, 0xA4($sp)
        ctx->r31 = MEM_W(ctx->r29, 0XA4);
            goto L_801CBC2C;
    }
    goto skip_1;
    // 0x801CBB3C: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    skip_1:
    // 0x801CBB40: lbu         $t2, 0x98($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X98);
    // 0x801CBB44: sb          $zero, 0x99($s1)
    MEM_B(0X99, ctx->r17) = 0;
    // 0x801CBB48: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801CBB4C: sb          $t3, 0x98($s1)
    MEM_B(0X98, ctx->r17) = ctx->r11;
    // 0x801CBB50: bne         $s6, $s2, L_801CBC28
    if (ctx->r22 != ctx->r18) {
        // 0x801CBB54: sh          $zero, 0x0($s7)
        MEM_H(0X0, ctx->r23) = 0;
            goto L_801CBC28;
    }
    // 0x801CBB54: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    // 0x801CBB58: lbu         $a2, 0x98($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X98);
    // 0x801CBB5C: lw          $t5, 0x38($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X38);
    // 0x801CBB60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CBB64: sll         $t4, $a2, 5
    ctx->r12 = S32(ctx->r6 << 5);
    // 0x801CBB68: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x801CBB6C: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x801CBB70: sra         $a1, $v1, 12
    ctx->r5 = S32(SIGNED(ctx->r3) >> 12);
    // 0x801CBB74: bnel        $a1, $at, L_801CBC2C
    if (ctx->r5 != ctx->r1) {
        // 0x801CBB78: lw          $ra, 0xA4($sp)
        ctx->r31 = MEM_W(ctx->r29, 0XA4);
            goto L_801CBC2C;
    }
    goto skip_2;
    // 0x801CBB78: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    skip_2:
    // 0x801CBB7C: b           L_801CB8F0
    // 0x801CBB80: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
        goto L_801CB8F0;
    // 0x801CBB80: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
L_801CBB84:
    // 0x801CBB84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CBB88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CBB8C: lw          $t7, 0xE8($s5)
    ctx->r15 = MEM_W(ctx->r21, 0XE8);
    // 0x801CBB90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CBB94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CBB98: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801CBB9C: lw          $s0, 0x2C($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X2C);
    // 0x801CBBA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CBBA4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801CBBA8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x801CBBAC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CBBB0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801CBBB4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801CBBB8: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x801CBBBC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CBBC0: addiu       $a0, $a0, 0x2FE8
    ctx->r4 = ADD32(ctx->r4, 0X2FE8);
    // 0x801CBBC4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801CBBC8: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x801CBBCC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801CBBD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CBBD4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801CBBD8: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x801CBBDC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801CBBE0: addiu       $a1, $zero, 0x388
    ctx->r5 = ADD32(0, 0X388);
    // 0x801CBBE4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801CBBE8: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801CBBEC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801CBBF0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801CBBF4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801CBBF8: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x801CBBFC: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801CBC00: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801CBC04: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801CBC08: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x801CBC0C: jal         0x8011AAF4
    // 0x801CBC10: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_3;
    // 0x801CBC10: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x801CBC14: bne         $v0, $zero, L_801CBC28
    if (ctx->r2 != 0) {
        // 0x801CBC18: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801CBC28;
    }
    // 0x801CBC18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CBC1C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBC20: jal         0x800058DC
    // 0x801CBC24: addiu       $a1, $a1, -0x48E4
    ctx->r5 = ADD32(ctx->r5, -0X48E4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CBC24: addiu       $a1, $a1, -0x48E4
    ctx->r5 = ADD32(ctx->r5, -0X48E4);
    after_4:
L_801CBC28:
    // 0x801CBC28: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
L_801CBC2C:
    // 0x801CBC2C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x801CBC30: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x801CBC34: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x801CBC38: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x801CBC3C: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x801CBC40: ldc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X78);
    // 0x801CBC44: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x801CBC48: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x801CBC4C: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x801CBC50: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x801CBC54: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x801CBC58: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x801CBC5C: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x801CBC60: lw          $s7, 0x9C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X9C);
    // 0x801CBC64: lw          $fp, 0xA0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XA0);
    // 0x801CBC68: jr          $ra
    // 0x801CBC6C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x801CBC6C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cbc70(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cbc70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBC70: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CBC74: addiu       $v0, $v0, 0xCA0
    ctx->r2 = ADD32(ctx->r2, 0XCA0);
    // 0x801CBC78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CBC7C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CBC80: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CBC84: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x801CBC88: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x801CBC8C: sb          $a1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r5;
    // 0x801CBC90: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x801CBC94: sb          $a2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r6;
    // 0x801CBC98: jr          $ra
    // 0x801CBC9C: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    return;
    // 0x801CBC9C: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cbca0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cbca0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBCA0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CBCA4: addiu       $v0, $v0, 0xCA0
    ctx->r2 = ADD32(ctx->r2, 0XCA0);
    // 0x801CBCA8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CBCAC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CBCB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CBCB4: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // 0x801CBCB8: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x801CBCBC: sb          $a1, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r5;
    // 0x801CBCC0: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x801CBCC4: sb          $a2, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r6;
    // 0x801CBCC8: jr          $ra
    // 0x801CBCCC: sb          $a2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r6;
    return;
    // 0x801CBCCC: sb          $a2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r6;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cbcd0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cbcd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBCD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CBCD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CBCD8: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801CBCDC: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x801CBCE0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CBCE4: addiu       $v0, $v0, 0xCA0
    ctx->r2 = ADD32(ctx->r2, 0XCA0);
    // 0x801CBCE8: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x801CBCEC: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801CBCF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CBCF4: sb          $a0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r4;
    // 0x801CBCF8: jr          $ra
    // 0x801CBCFC: sb          $a2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r6;
    return;
    // 0x801CBCFC: sb          $a2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r6;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cbd00(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cbd00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CBD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CBD08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CBD0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CBD10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801CBD14: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801CBD18: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801CBD1C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801CBD20: jal         0x801CBC70
    // 0x801CBD24: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801CBC70)(rdram, ctx);
        goto after_0;
    // 0x801CBD24: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x801CBD28: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    // 0x801CBD2C: lbu         $a1, 0x2B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2B);
    // 0x801CBD30: jal         0x801CBCA0
    // 0x801CBD34: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    LOOKUP_FUNC(0x801CBCA0)(rdram, ctx);
        goto after_1;
    // 0x801CBD34: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    after_1:
    // 0x801CBD38: lb          $a0, 0x33($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X33);
    // 0x801CBD3C: lb          $a1, 0x37($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X37);
    // 0x801CBD40: jal         0x801CBCD0
    // 0x801CBD44: lb          $a2, 0x3B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X3B);
    LOOKUP_FUNC(0x801CBCD0)(rdram, ctx);
        goto after_2;
    // 0x801CBD44: lb          $a2, 0x3B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X3B);
    after_2:
    // 0x801CBD48: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CBD4C: addiu       $v0, $v0, 0xCA0
    ctx->r2 = ADD32(ctx->r2, 0XCA0);
    // 0x801CBD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CBD54: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // 0x801CBD58: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x801CBD5C: sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
    // 0x801CBD60: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x801CBD64: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x801CBD68: jr          $ra
    // 0x801CBD6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801CBD6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cbd70(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cbd70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBD70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CBD74: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801CBD78: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CBD7C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CBD80: addiu       $t8, $zero, -0x7F
    ctx->r24 = ADD32(0, -0X7F);
    // 0x801CBD84: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801CBD88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CBD8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CBD90: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801CBD94: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CBD98: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x801CBD9C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801CBDA0: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x801CBDA4: jal         0x801CBD00
    // 0x801CBDA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CBD00)(rdram, ctx);
        goto after_0;
    // 0x801CBDA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801CBDAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801CBDB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CBDB4: jr          $ra
    // 0x801CBDB8: nop

    return;
    // 0x801CBDB8: nop

;}
RECOMP_FUNC void M8_FUN_801cbdbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBDBC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CBDC0: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801CBDC4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x801CBDC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801CBDCC: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x801CBDD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CBDD4: blez        $t6, L_801CBDFC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CBDD8: nop
    
            goto L_801CBDFC;
    }
    // 0x801CBDD8: nop

    // 0x801CBDDC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_801CBDE0:
    // 0x801CBDE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CBDE4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801CBDE8: sh          $a2, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r6;
    // 0x801CBDEC: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x801CBDF0: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CBDF4: bnel        $at, $zero, L_801CBDE0
    if (ctx->r1 != 0) {
        // 0x801CBDF8: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_801CBDE0;
    }
    goto skip_0;
    // 0x801CBDF8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_801CBDFC:
    // 0x801CBDFC: jr          $ra
    // 0x801CBE00: nop

    return;
    // 0x801CBE00: nop

;}
RECOMP_FUNC void M8_FUN_801cbe04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBE04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CBE08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CBE0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CBE10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CBE14: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x801CBE18: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x801CBE1C: jal         0x80116E80
    // 0x801CBE20: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x801CBE20: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x801CBE24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CBE28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801CBE2C: jal         0x801CBDBC
    // 0x801CBE30: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x801CBDBC)(rdram, ctx);
        goto after_1;
    // 0x801CBE30: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x801CBE34: jal         0x801479A8
    // 0x801CBE38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801479A8)(rdram, ctx);
        goto after_2;
    // 0x801CBE38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801CBE3C: jal         0x801CBD70
    // 0x801CBE40: nop

    LOOKUP_FUNC(0x801CBD70)(rdram, ctx);
        goto after_3;
    // 0x801CBE40: nop

    after_3:
    // 0x801CBE44: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801CBE48: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CBE4C: addiu       $t8, $t8, 0xCB8
    ctx->r24 = ADD32(ctx->r24, 0XCB8);
    // 0x801CBE50: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801CBE54: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801CBE58: addiu       $t1, $t1, -0x4898
    ctx->r9 = ADD32(ctx->r9, -0X4898);
    // 0x801CBE5C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801CBE60: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x801CBE64: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBE68: lhu         $t3, 0xC($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XC);
    // 0x801CBE6C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801CBE70: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x801CBE74: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x801CBE78: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801CBE7C: sw          $t1, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r9;
    // 0x801CBE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CBE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CBE88: jr          $ra
    // 0x801CBE8C: nop

    return;
    // 0x801CBE8C: nop

;}
RECOMP_FUNC void M8_FUN_801cbe90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBE90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CBE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CBE98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CBE9C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801CBEA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CBEA4: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // 0x801CBEA8: jal         0x801CBDBC
    // 0x801CBEAC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801CBDBC)(rdram, ctx);
        goto after_0;
    // 0x801CBEAC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801CBEB0: jal         0x801170DC
    // 0x801CBEB4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_1;
    // 0x801CBEB4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_1:
    // 0x801CBEB8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801CBEBC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801CBEC0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CBEC4: sw          $zero, 0x34($t9)
    MEM_W(0X34, ctx->r25) = 0;
    // 0x801CBEC8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBECC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801CBED0: lhu         $t2, 0xC($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XC);
    // 0x801CBED4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801CBED8: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x801CBEDC: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x801CBEE0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801CBEE4: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x801CBEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CBEEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CBEF0: jr          $ra
    // 0x801CBEF4: nop

    return;
    // 0x801CBEF4: nop

;}
RECOMP_FUNC void M8_FUN_801cbef8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBEF8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CBEFC: addiu       $v0, $v0, 0x4080
    ctx->r2 = ADD32(ctx->r2, 0X4080);
    // 0x801CBF00: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cbf04(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cbf04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBF04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CBF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CBF0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CBF10: sh          $zero, 0x4C($t6)
    MEM_H(0X4C, ctx->r14) = 0;
    // 0x801CBF14: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801CBF18: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801CBF1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CBF20: sh          $zero, 0x4E($t7)
    MEM_H(0X4E, ctx->r15) = 0;
    // 0x801CBF24: lbu         $t8, -0x33DB($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X33DB);
    // 0x801CBF28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801CBF2C: bnel        $t8, $at, L_801CC06C
    if (ctx->r24 != ctx->r1) {
        // 0x801CBF30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CC06C;
    }
    goto skip_0;
    // 0x801CBF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CBF34: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801CBF38: lbu         $t9, 0x30($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X30);
    // 0x801CBF3C: addiu       $t0, $t9, -0x10
    ctx->r8 = ADD32(ctx->r25, -0X10);
    // 0x801CBF40: sltiu       $at, $t0, 0x11
    ctx->r1 = ctx->r8 < 0X11 ? 1 : 0;
    // 0x801CBF44: beq         $at, $zero, L_801CBFBC
    if (ctx->r1 == 0) {
        // 0x801CBF48: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_801CBFBC;
    }
    // 0x801CBF48: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801CBF4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBF50: addu        $at, $at, $t0
    gpr jr_addend_801CBF58 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801CBF54: lw          $t0, 0x3200($at)
    ctx->r8 = ADD32(ctx->r1, 0X3200);
    // 0x801CBF58: jr          $t0
    // 0x801CBF5C: nop

    switch (jr_addend_801CBF58 >> 2) {
        case 0: goto L_801CBF60; break;
        case 1: goto L_801CBF80; break;
        case 2: goto L_801CBFA0; break;
        case 3: goto L_801CBFBC; break;
        case 4: goto L_801CBFBC; break;
        case 5: goto L_801CBFBC; break;
        case 6: goto L_801CBFBC; break;
        case 7: goto L_801CBFBC; break;
        case 8: goto L_801CBFBC; break;
        case 9: goto L_801CBFBC; break;
        case 10: goto L_801CBFBC; break;
        case 11: goto L_801CBFBC; break;
        case 12: goto L_801CBFBC; break;
        case 13: goto L_801CBFBC; break;
        case 14: goto L_801CBF60; break;
        case 15: goto L_801CBF80; break;
        case 16: goto L_801CBFA0; break;
        default: switch_error(__func__, 0x801CBF58, 0x801E3200);
    }
    // 0x801CBF5C: nop

L_801CBF60:
    // 0x801CBF60: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801CBF64: sb          $a0, 0x34($v1)
    MEM_B(0X34, ctx->r3) = ctx->r4;
    // 0x801CBF68: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801CBF6C: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801CBF70: sb          $t1, 0x35($t2)
    MEM_B(0X35, ctx->r10) = ctx->r9;
    // 0x801CBF74: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801CBF78: b           L_801CBFD4
    // 0x801CBF7C: sb          $zero, 0x36($t3)
    MEM_B(0X36, ctx->r11) = 0;
        goto L_801CBFD4;
    // 0x801CBF7C: sb          $zero, 0x36($t3)
    MEM_B(0X36, ctx->r11) = 0;
L_801CBF80:
    // 0x801CBF80: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
    // 0x801CBF84: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801CBF88: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CBF8C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801CBF90: sb          $t4, 0x35($t5)
    MEM_B(0X35, ctx->r13) = ctx->r12;
    // 0x801CBF94: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801CBF98: b           L_801CBFD4
    // 0x801CBF9C: sb          $a0, 0x36($t6)
    MEM_B(0X36, ctx->r14) = ctx->r4;
        goto L_801CBFD4;
    // 0x801CBF9C: sb          $a0, 0x36($t6)
    MEM_B(0X36, ctx->r14) = ctx->r4;
L_801CBFA0:
    // 0x801CBFA0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801CBFA4: sb          $a0, 0x34($v1)
    MEM_B(0X34, ctx->r3) = ctx->r4;
    // 0x801CBFA8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801CBFAC: sb          $a0, 0x35($t7)
    MEM_B(0X35, ctx->r15) = ctx->r4;
    // 0x801CBFB0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801CBFB4: b           L_801CBFD4
    // 0x801CBFB8: sb          $zero, 0x36($t8)
    MEM_B(0X36, ctx->r24) = 0;
        goto L_801CBFD4;
    // 0x801CBFB8: sb          $zero, 0x36($t8)
    MEM_B(0X36, ctx->r24) = 0;
L_801CBFBC:
    // 0x801CBFBC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801CBFC0: sb          $a0, 0x34($v1)
    MEM_B(0X34, ctx->r3) = ctx->r4;
    // 0x801CBFC4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801CBFC8: sb          $a0, 0x35($t9)
    MEM_B(0X35, ctx->r25) = ctx->r4;
    // 0x801CBFCC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801CBFD0: sb          $a0, 0x36($t0)
    MEM_B(0X36, ctx->r8) = ctx->r4;
L_801CBFD4:
    // 0x801CBFD4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801CBFD8: lbu         $t1, 0x30($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X30);
    // 0x801CBFDC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801CBFE0: sltiu       $at, $t2, 0x20
    ctx->r1 = ctx->r10 < 0X20 ? 1 : 0;
    // 0x801CBFE4: beq         $at, $zero, L_801CC058
    if (ctx->r1 == 0) {
        // 0x801CBFE8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_801CC058;
    }
    // 0x801CBFE8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801CBFEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CBFF0: addu        $at, $at, $t2
    gpr jr_addend_801CBFF8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801CBFF4: lw          $t2, 0x3244($at)
    ctx->r10 = ADD32(ctx->r1, 0X3244);
    // 0x801CBFF8: jr          $t2
    // 0x801CBFFC: nop

    switch (jr_addend_801CBFF8 >> 2) {
        case 0: goto L_801CC058; break;
        case 1: goto L_801CC058; break;
        case 2: goto L_801CC058; break;
        case 3: goto L_801CC058; break;
        case 4: goto L_801CC038; break;
        case 5: goto L_801CC038; break;
        case 6: goto L_801CC038; break;
        case 7: goto L_801CC038; break;
        case 8: goto L_801CC058; break;
        case 9: goto L_801CC058; break;
        case 10: goto L_801CC058; break;
        case 11: goto L_801CC058; break;
        case 12: goto L_801CC058; break;
        case 13: goto L_801CC058; break;
        case 14: goto L_801CC058; break;
        case 15: goto L_801CC000; break;
        case 16: goto L_801CC000; break;
        case 17: goto L_801CC000; break;
        case 18: goto L_801CC058; break;
        case 19: goto L_801CC058; break;
        case 20: goto L_801CC058; break;
        case 21: goto L_801CC058; break;
        case 22: goto L_801CC058; break;
        case 23: goto L_801CC058; break;
        case 24: goto L_801CC058; break;
        case 25: goto L_801CC058; break;
        case 26: goto L_801CC058; break;
        case 27: goto L_801CC058; break;
        case 28: goto L_801CC058; break;
        case 29: goto L_801CC018; break;
        case 30: goto L_801CC018; break;
        case 31: goto L_801CC018; break;
        default: switch_error(__func__, 0x801CBFF8, 0x801E3244);
    }
    // 0x801CBFFC: nop

L_801CC000:
    // 0x801CC000: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC004: addiu       $a1, $a1, -0x3910
    ctx->r5 = ADD32(ctx->r5, -0X3910);
    // 0x801CC008: jal         0x800058DC
    // 0x801CC00C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CC00C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x801CC010: b           L_801CC06C
    // 0x801CC014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CC06C;
    // 0x801CC014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC018:
    // 0x801CC018: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801CC01C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC020: sh          $t3, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r11;
    // 0x801CC024: addiu       $a1, $a1, -0x37D0
    ctx->r5 = ADD32(ctx->r5, -0X37D0);
    // 0x801CC028: jal         0x800058DC
    // 0x801CC02C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC02C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x801CC030: b           L_801CC06C
    // 0x801CC034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CC06C;
    // 0x801CC034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC038:
    // 0x801CC038: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801CC03C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC040: sh          $t4, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r12;
    // 0x801CC044: addiu       $a1, $a1, -0x3DA0
    ctx->r5 = ADD32(ctx->r5, -0X3DA0);
    // 0x801CC048: jal         0x800058DC
    // 0x801CC04C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CC04C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x801CC050: b           L_801CC06C
    // 0x801CC054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CC06C;
    // 0x801CC054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC058:
    // 0x801CC058: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC05C: addiu       $a1, $a1, -0x3F88
    ctx->r5 = ADD32(ctx->r5, -0X3F88);
    // 0x801CC060: jal         0x800058DC
    // 0x801CC064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CC064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x801CC068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC06C:
    // 0x801CC06C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC070: jr          $ra
    // 0x801CC074: nop

    return;
    // 0x801CC074: nop

;}
RECOMP_FUNC void M8_FUN_801cc078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC078: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801CC07C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CC080: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x801CC084: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801CC088: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x801CC08C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CC090: lw          $t8, 0x4080($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4080);
    // 0x801CC094: lw          $t7, 0x5C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X5C);
    // 0x801CC098: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x801CC09C: lbu         $v0, 0x30($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X30);
    // 0x801CC0A0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801CC0A4: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x801CC0A8: beq         $at, $zero, L_801CC0DC
    if (ctx->r1 == 0) {
        // 0x801CC0AC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801CC0DC;
    }
    // 0x801CC0AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801CC0B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC0B4: addu        $at, $at, $t9
    gpr jr_addend_801CC0BC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801CC0B8: lw          $t9, 0x32C4($at)
    ctx->r25 = ADD32(ctx->r1, 0X32C4);
    // 0x801CC0BC: jr          $t9
    // 0x801CC0C0: nop

    switch (jr_addend_801CC0BC >> 2) {
        case 0: goto L_801CC0DC; break;
        case 1: goto L_801CC0DC; break;
        case 2: goto L_801CC0DC; break;
        case 3: goto L_801CC0DC; break;
        case 4: goto L_801CC0DC; break;
        case 5: goto L_801CC0DC; break;
        case 6: goto L_801CC0DC; break;
        case 7: goto L_801CC0DC; break;
        case 8: goto L_801CC0C4; break;
        case 9: goto L_801CC0C4; break;
        case 10: goto L_801CC0C4; break;
        case 11: goto L_801CC0C4; break;
        default: switch_error(__func__, 0x801CC0BC, 0x801E32C4);
    }
    // 0x801CC0C0: nop

L_801CC0C4:
    // 0x801CC0C4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CC0C8: addiu       $t1, $zero, 0xC0
    ctx->r9 = ADD32(0, 0XC0);
    // 0x801CC0CC: sb          $t1, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r9;
    // 0x801CC0D0: sb          $t0, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r8;
    // 0x801CC0D4: b           L_801CC0F0
    // 0x801CC0D8: sb          $zero, 0x59($sp)
    MEM_B(0X59, ctx->r29) = 0;
        goto L_801CC0F0;
    // 0x801CC0D8: sb          $zero, 0x59($sp)
    MEM_B(0X59, ctx->r29) = 0;
L_801CC0DC:
    // 0x801CC0DC: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x801CC0E0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801CC0E4: sb          $t3, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r11;
    // 0x801CC0E8: sb          $t2, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r10;
    // 0x801CC0EC: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
L_801CC0F0:
    // 0x801CC0F0: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801CC0F4: sltiu       $at, $t4, 0xC
    ctx->r1 = ctx->r12 < 0XC ? 1 : 0;
    // 0x801CC0F8: beq         $at, $zero, L_801CC12C
    if (ctx->r1 == 0) {
        // 0x801CC0FC: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_801CC12C;
    }
    // 0x801CC0FC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801CC100: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC104: addu        $at, $at, $t4
    gpr jr_addend_801CC10C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801CC108: lw          $t4, 0x32F4($at)
    ctx->r12 = ADD32(ctx->r1, 0X32F4);
    // 0x801CC10C: jr          $t4
    // 0x801CC110: nop

    switch (jr_addend_801CC10C >> 2) {
        case 0: goto L_801CC12C; break;
        case 1: goto L_801CC114; break;
        case 2: goto L_801CC11C; break;
        case 3: goto L_801CC124; break;
        case 4: goto L_801CC12C; break;
        case 5: goto L_801CC12C; break;
        case 6: goto L_801CC12C; break;
        case 7: goto L_801CC12C; break;
        case 8: goto L_801CC12C; break;
        case 9: goto L_801CC114; break;
        case 10: goto L_801CC11C; break;
        case 11: goto L_801CC124; break;
        default: switch_error(__func__, 0x801CC10C, 0x801E32F4);
    }
    // 0x801CC110: nop

L_801CC114:
    // 0x801CC114: b           L_801CC130
    // 0x801CC118: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_801CC130;
    // 0x801CC118: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_801CC11C:
    // 0x801CC11C: b           L_801CC130
    // 0x801CC120: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
        goto L_801CC130;
    // 0x801CC120: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_801CC124:
    // 0x801CC124: b           L_801CC130
    // 0x801CC128: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
        goto L_801CC130;
    // 0x801CC128: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_801CC12C:
    // 0x801CC12C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_801CC130:
    // 0x801CC130: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801CC134: jal         0x80006214
    // 0x801CC138: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CC138: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    after_0:
    // 0x801CC13C: jal         0x80126944
    // 0x801CC140: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x801CC140: nop

    after_1:
    // 0x801CC144: bne         $v0, $zero, L_801CC168
    if (ctx->r2 != 0) {
        // 0x801CC148: lhu         $v1, 0x5E($sp)
        ctx->r3 = MEM_HU(ctx->r29, 0X5E);
            goto L_801CC168;
    }
    // 0x801CC148: lhu         $v1, 0x5E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X5E);
    // 0x801CC14C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801CC150: lhu         $t5, -0x3520($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X3520);
    // 0x801CC154: andi        $t6, $t5, 0x100
    ctx->r14 = ctx->r13 & 0X100;
    // 0x801CC158: beql        $t6, $zero, L_801CC16C
    if (ctx->r14 == 0) {
        // 0x801CC15C: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_801CC16C;
    }
    goto skip_0;
    // 0x801CC15C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_0:
    // 0x801CC160: b           L_801CC16C
    // 0x801CC164: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
        goto L_801CC16C;
    // 0x801CC164: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
L_801CC168:
    // 0x801CC168: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_801CC16C:
    // 0x801CC16C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801CC170: addiu       $a1, $a1, -0x2578
    ctx->r5 = ADD32(ctx->r5, -0X2578);
    // 0x801CC174: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x801CC178: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x801CC17C: jal         0x8013A334
    // 0x801CC180: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x801CC180: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    after_2:
    // 0x801CC184: jal         0x80006214
    // 0x801CC188: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801CC188: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_3:
    // 0x801CC18C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC190: lhu         $v1, 0x5E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X5E);
    // 0x801CC194: lwc1        $f6, 0x3324($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3324);
    // 0x801CC198: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801CC19C: lbu         $t1, 0x5B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5B);
    // 0x801CC1A0: lbu         $t2, 0x5A($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X5A);
    // 0x801CC1A4: lbu         $t3, 0x59($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X59);
    // 0x801CC1A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CC1AC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CC1B0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CC1B4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CC1B8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801CC1BC: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x801CC1C0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x801CC1C4: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801CC1C8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x801CC1CC: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x801CC1D0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801CC1D4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801CC1D8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CC1DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CC1E0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x801CC1E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CC1E8: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x801CC1EC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x801CC1F0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x801CC1F4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801CC1F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801CC1FC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801CC200: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801CC204: jal         0x801CE330
    // 0x801CC208: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_4;
    // 0x801CC208: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_4:
    // 0x801CC20C: beq         $v0, $zero, L_801CC234
    if (ctx->r2 == 0) {
        // 0x801CC210: lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
            goto L_801CC234;
    }
    // 0x801CC210: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CC214: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CC218: lw          $t8, 0x4080($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4080);
    // 0x801CC21C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CC220: addiu       $a0, $zero, 0x10C
    ctx->r4 = ADD32(0, 0X10C);
    // 0x801CC224: jal         0x80020718
    // 0x801CC228: sh          $t7, 0x4C($t8)
    MEM_H(0X4C, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_5;
    // 0x801CC228: sh          $t7, 0x4C($t8)
    MEM_H(0X4C, ctx->r24) = ctx->r15;
    after_5:
    // 0x801CC22C: b           L_801CC240
    // 0x801CC230: nop

        goto L_801CC240;
    // 0x801CC230: nop

L_801CC234:
    // 0x801CC234: lw          $t0, 0x4080($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4080);
    // 0x801CC238: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801CC23C: sh          $t9, 0x4C($t0)
    MEM_H(0X4C, ctx->r8) = ctx->r25;
L_801CC240:
    // 0x801CC240: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC244: addiu       $a1, $a1, -0x3DA0
    ctx->r5 = ADD32(ctx->r5, -0X3DA0);
    // 0x801CC248: jal         0x800058DC
    // 0x801CC24C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801CC24C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_6:
    // 0x801CC250: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801CC254: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801CC258: jr          $ra
    // 0x801CC25C: nop

    return;
    // 0x801CC25C: nop

;}
RECOMP_FUNC void M8_FUN_801cc260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC260: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x801CC264: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801CC268: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x801CC26C: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x801CC270: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x801CC274: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CC278: addiu       $a1, $a1, 0x4080
    ctx->r5 = ADD32(ctx->r5, 0X4080);
    // 0x801CC27C: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801CC280: lw          $t8, 0x5C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5C);
    // 0x801CC284: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801CC288: lw          $t5, 0x2C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X2C);
    // 0x801CC28C: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
    // 0x801CC290: lhu         $t9, 0x4C($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4C);
    // 0x801CC294: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x801CC298: bnel        $at, $zero, L_801CC654
    if (ctx->r1 != 0) {
        // 0x801CC29C: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_801CC654;
    }
    goto skip_0;
    // 0x801CC29C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x801CC2A0: sh          $zero, 0x4E($v1)
    MEM_H(0X4E, ctx->r3) = 0;
    // 0x801CC2A4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801CC2A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CC2AC: lhu         $a0, 0xD7E($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XD7E);
    // 0x801CC2B0: lbu         $v0, 0x30($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X30);
    // 0x801CC2B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x801CC2B8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801CC2BC: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x801CC2C0: beq         $at, $zero, L_801CC344
    if (ctx->r1 == 0) {
        // 0x801CC2C4: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_801CC344;
    }
    // 0x801CC2C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801CC2C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801CC2CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC2D0: addu        $at, $at, $t7
    gpr jr_addend_801CC2D8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801CC2D4: lw          $t7, 0x3328($at)
    ctx->r15 = ADD32(ctx->r1, 0X3328);
    // 0x801CC2D8: jr          $t7
    // 0x801CC2DC: nop

    switch (jr_addend_801CC2D8 >> 2) {
        case 0: goto L_801CC344; break;
        case 1: goto L_801CC344; break;
        case 2: goto L_801CC344; break;
        case 3: goto L_801CC344; break;
        case 4: goto L_801CC310; break;
        case 5: goto L_801CC310; break;
        case 6: goto L_801CC310; break;
        case 7: goto L_801CC310; break;
        case 8: goto L_801CC2E0; break;
        case 9: goto L_801CC2E0; break;
        case 10: goto L_801CC2E0; break;
        case 11: goto L_801CC2E0; break;
        default: switch_error(__func__, 0x801CC2D8, 0x801E3328);
    }
    // 0x801CC2DC: nop

L_801CC2E0:
    // 0x801CC2E0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CC2E4: addiu       $t9, $zero, 0xE0
    ctx->r25 = ADD32(0, 0XE0);
    // 0x801CC2E8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801CC2EC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CC2F0: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x801CC2F4: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x801CC2F8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x801CC2FC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x801CC300: sh          $t8, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r24;
    // 0x801CC304: sh          $t9, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r25;
    // 0x801CC308: b           L_801CC370
    // 0x801CC30C: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
        goto L_801CC370;
    // 0x801CC30C: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
L_801CC310:
    // 0x801CC310: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CC314: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    // 0x801CC318: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801CC31C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CC320: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CC324: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CC328: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x801CC32C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x801CC330: sh          $t6, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r14;
    // 0x801CC334: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // 0x801CC338: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
    // 0x801CC33C: b           L_801CC370
    // 0x801CC340: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
        goto L_801CC370;
    // 0x801CC340: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_801CC344:
    // 0x801CC344: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x801CC348: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CC34C: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x801CC350: addiu       $v1, $zero, 0x50
    ctx->r3 = ADD32(0, 0X50);
    // 0x801CC354: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801CC358: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CC35C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801CC360: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801CC364: sh          $zero, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = 0;
    // 0x801CC368: sh          $t7, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r15;
    // 0x801CC36C: sh          $t8, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r24;
L_801CC370:
    // 0x801CC370: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801CC374: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x801CC378: beq         $at, $zero, L_801CC3B8
    if (ctx->r1 == 0) {
        // 0x801CC37C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801CC3B8;
    }
    // 0x801CC37C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801CC380: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC384: addu        $at, $at, $t9
    gpr jr_addend_801CC38C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801CC388: lw          $t9, 0x3358($at)
    ctx->r25 = ADD32(ctx->r1, 0X3358);
    // 0x801CC38C: jr          $t9
    // 0x801CC390: nop

    switch (jr_addend_801CC38C >> 2) {
        case 0: goto L_801CC394; break;
        case 1: goto L_801CC3A0; break;
        case 2: goto L_801CC3AC; break;
        case 3: goto L_801CC3B8; break;
        case 4: goto L_801CC394; break;
        case 5: goto L_801CC3A0; break;
        case 6: goto L_801CC3AC; break;
        case 7: goto L_801CC3B8; break;
        case 8: goto L_801CC394; break;
        case 9: goto L_801CC3A0; break;
        case 10: goto L_801CC3AC; break;
        case 11: goto L_801CC3B8; break;
        default: switch_error(__func__, 0x801CC38C, 0x801E3358);
    }
    // 0x801CC390: nop

L_801CC394:
    // 0x801CC394: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801CC398: b           L_801CC3CC
    // 0x801CC39C: sh          $t6, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r14;
        goto L_801CC3CC;
    // 0x801CC39C: sh          $t6, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r14;
L_801CC3A0:
    // 0x801CC3A0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801CC3A4: b           L_801CC3CC
    // 0x801CC3A8: sh          $t7, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r15;
        goto L_801CC3CC;
    // 0x801CC3A8: sh          $t7, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r15;
L_801CC3AC:
    // 0x801CC3AC: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x801CC3B0: b           L_801CC3CC
    // 0x801CC3B4: sh          $t8, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r24;
        goto L_801CC3CC;
    // 0x801CC3B4: sh          $t8, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r24;
L_801CC3B8:
    // 0x801CC3B8: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x801CC3BC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801CC3C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CC3C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CC3C8: sh          $t9, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r25;
L_801CC3CC:
    // 0x801CC3CC: sh          $v1, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r3;
    // 0x801CC3D0: sh          $a0, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r4;
    // 0x801CC3D4: sh          $t0, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r8;
    // 0x801CC3D8: sh          $t1, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r9;
    // 0x801CC3DC: sh          $t2, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r10;
    // 0x801CC3E0: sh          $t3, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r11;
    // 0x801CC3E4: sh          $t4, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r12;
    // 0x801CC3E8: jal         0x80126944
    // 0x801CC3EC: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801CC3EC: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    after_0:
    // 0x801CC3F0: lhu         $v1, 0xB0($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XB0);
    // 0x801CC3F4: lhu         $t0, 0xAE($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XAE);
    // 0x801CC3F8: lhu         $t1, 0xAC($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XAC);
    // 0x801CC3FC: lhu         $t2, 0xAA($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XAA);
    // 0x801CC400: lhu         $t3, 0xA8($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XA8);
    // 0x801CC404: lhu         $t4, 0xA6($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XA6);
    // 0x801CC408: bne         $v0, $zero, L_801CC438
    if (ctx->r2 != 0) {
        // 0x801CC40C: lw          $t5, 0xC4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XC4);
            goto L_801CC438;
    }
    // 0x801CC40C: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x801CC410: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801CC414: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // 0x801CC418: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC41C: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x801CC420: beq         $t7, $zero, L_801CC438
    if (ctx->r15 == 0) {
        // 0x801CC424: nop
    
            goto L_801CC438;
    }
    // 0x801CC424: nop

    // 0x801CC428: lwc1        $f0, 0x3388($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3388);
    // 0x801CC42C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC430: b           L_801CC448
    // 0x801CC434: lwc1        $f2, 0x338C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X338C);
        goto L_801CC448;
    // 0x801CC434: lwc1        $f2, 0x338C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X338C);
L_801CC438:
    // 0x801CC438: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC43C: lwc1        $f2, 0x3390($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X3390);
    // 0x801CC440: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC444: lwc1        $f0, 0x3394($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3394);
L_801CC448:
    // 0x801CC448: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x801CC44C: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x801CC450: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x801CC454: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC458: lwc1        $f6, 0x3398($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3398);
    // 0x801CC45C: lhu         $t6, 0xB2($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XB2);
    // 0x801CC460: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CC464: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CC468: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CC46C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x801CC470: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x801CC474: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x801CC478: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CC47C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x801CC480: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801CC484: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x801CC488: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x801CC48C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x801CC490: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CC494: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CC498: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x801CC49C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801CC4A0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801CC4A4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CC4A8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801CC4AC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801CC4B0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801CC4B4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801CC4B8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801CC4BC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801CC4C0: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x801CC4C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801CC4C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801CC4CC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x801CC4D0: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x801CC4D4: jal         0x801CE1C8
    // 0x801CC4D8: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CE1C8)(rdram, ctx);
        goto after_1;
    // 0x801CC4D8: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801CC4DC: jal         0x80020718
    // 0x801CC4E0: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x801CC4E0: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    after_2:
    // 0x801CC4E4: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x801CC4E8: jal         0x80006214
    // 0x801CC4EC: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801CC4EC: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    after_3:
    // 0x801CC4F0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801CC4F4: addiu       $a1, $a1, -0x2578
    ctx->r5 = ADD32(ctx->r5, -0X2578);
    // 0x801CC4F8: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x801CC4FC: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801CC500: jal         0x8013A334
    // 0x801CC504: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_4;
    // 0x801CC504: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    after_4:
    // 0x801CC508: jal         0x80006214
    // 0x801CC50C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801CC50C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_5:
    // 0x801CC510: lhu         $v1, 0xB2($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XB2);
    // 0x801CC514: lbu         $t0, 0xA5($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XA5);
    // 0x801CC518: lbu         $t1, 0xA3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XA3);
    // 0x801CC51C: lbu         $t2, 0xA1($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XA1);
    // 0x801CC520: lbu         $t3, 0x9F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X9F);
    // 0x801CC524: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CC528: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CC52C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC530: lwc1        $f16, 0x339C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X339C);
    // 0x801CC534: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801CC538: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801CC53C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801CC540: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x801CC544: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CC548: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CC54C: addiu       $t9, $v1, -0x14
    ctx->r25 = ADD32(ctx->r3, -0X14);
    // 0x801CC550: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x801CC554: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CC558: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CC55C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801CC560: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x801CC564: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801CC568: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x801CC56C: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    // 0x801CC570: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CC574: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x801CC578: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801CC57C: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x801CC580: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801CC584: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x801CC588: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801CC58C: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x801CC590: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801CC594: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x801CC598: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801CC59C: jal         0x801CE330
    // 0x801CC5A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_6;
    // 0x801CC5A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x801CC5A4: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801CC5A8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CC5AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801CC5B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CC5B4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801CC5B8: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x801CC5BC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801CC5C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC5C4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CC5C8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CC5CC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801CC5D0: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x801CC5D4: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x801CC5D8: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x801CC5DC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x801CC5E0: lwc1        $f18, 0x33A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X33A0);
    // 0x801CC5E4: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801CC5E8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CC5EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CC5F0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x801CC5F4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801CC5F8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CC5FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CC600: addiu       $t7, $v1, -0xA
    ctx->r15 = ADD32(ctx->r3, -0XA);
    // 0x801CC604: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801CC608: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801CC60C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801CC610: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x801CC614: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x801CC618: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801CC61C: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x801CC620: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CC624: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801CC628: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801CC62C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801CC630: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801CC634: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x801CC638: jal         0x801CE330
    // 0x801CC63C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_7;
    // 0x801CC63C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x801CC640: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC644: addiu       $a1, $a1, -0x39A0
    ctx->r5 = ADD32(ctx->r5, -0X39A0);
    // 0x801CC648: jal         0x800058DC
    // 0x801CC64C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801CC64C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_8:
    // 0x801CC650: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_801CC654:
    // 0x801CC654: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x801CC658: jr          $ra
    // 0x801CC65C: nop

    return;
    // 0x801CC65C: nop

;}
RECOMP_FUNC void M8_FUN_801cc660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CC664: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CC668: lw          $v0, 0x4080($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4080);
    // 0x801CC66C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CC674: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CC678: lhu         $t7, 0x4E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4E);
    // 0x801CC67C: lhu         $t6, 0x4C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4C);
    // 0x801CC680: ori         $at, $zero, 0x8002
    ctx->r1 = 0 | 0X8002;
    // 0x801CC684: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x801CC688: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CC68C: bnel        $at, $zero, L_801CC6E4
    if (ctx->r1 != 0) {
        // 0x801CC690: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CC6E4;
    }
    goto skip_0;
    // 0x801CC690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CC694: jal         0x80126944
    // 0x801CC698: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801CC698: nop

    after_0:
    // 0x801CC69C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CC6A0: beq         $v0, $at, L_801CC6D0
    if (ctx->r2 == ctx->r1) {
        // 0x801CC6A4: nop
    
            goto L_801CC6D0;
    }
    // 0x801CC6A4: nop

    // 0x801CC6A8: jal         0x80126E88
    // 0x801CC6AC: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x801CC6AC: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    after_1:
    // 0x801CC6B0: jal         0x80126E88
    // 0x801CC6B4: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_2;
    // 0x801CC6B4: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    after_2:
    // 0x801CC6B8: jal         0x80126E88
    // 0x801CC6BC: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_3;
    // 0x801CC6BC: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    after_3:
    // 0x801CC6C0: jal         0x80126E88
    // 0x801CC6C4: addiu       $a0, $zero, 0x1AD
    ctx->r4 = ADD32(0, 0X1AD);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_4;
    // 0x801CC6C4: addiu       $a0, $zero, 0x1AD
    ctx->r4 = ADD32(0, 0X1AD);
    after_4:
    // 0x801CC6C8: jal         0x80126E88
    // 0x801CC6CC: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_5;
    // 0x801CC6CC: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    after_5:
L_801CC6D0:
    // 0x801CC6D0: jal         0x80005700
    // 0x801CC6D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_6;
    // 0x801CC6D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x801CC6D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC6DC: sw          $zero, 0x4080($at)
    MEM_W(0X4080, ctx->r1) = 0;
    // 0x801CC6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC6E4:
    // 0x801CC6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC6E8: jr          $ra
    // 0x801CC6EC: nop

    return;
    // 0x801CC6EC: nop

;}
RECOMP_FUNC void M8_FUN_801cc6f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC6F0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801CC6F4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CC6F8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x801CC6FC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x801CC700: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x801CC704: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC708: jal         0x80006214
    // 0x801CC70C: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CC70C: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    after_0:
    // 0x801CC710: jal         0x80126944
    // 0x801CC714: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x801CC714: nop

    after_1:
    // 0x801CC718: bne         $v0, $zero, L_801CC73C
    if (ctx->r2 != 0) {
        // 0x801CC71C: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_801CC73C;
    }
    // 0x801CC71C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x801CC720: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801CC724: lhu         $t8, -0x3520($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X3520);
    // 0x801CC728: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x801CC72C: beql        $t9, $zero, L_801CC740
    if (ctx->r25 == 0) {
        // 0x801CC730: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_801CC740;
    }
    goto skip_0;
    // 0x801CC730: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_0:
    // 0x801CC734: b           L_801CC740
    // 0x801CC738: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
        goto L_801CC740;
    // 0x801CC738: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
L_801CC73C:
    // 0x801CC73C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_801CC740:
    // 0x801CC740: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801CC744: addiu       $a1, $a1, -0x2578
    ctx->r5 = ADD32(ctx->r5, -0X2578);
    // 0x801CC748: jal         0x8013A334
    // 0x801CC74C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x801CC74C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_2:
    // 0x801CC750: jal         0x80006214
    // 0x801CC754: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801CC754: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x801CC758: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801CC75C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CC760: lw          $v1, 0x4080($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4080);
    // 0x801CC764: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CC768: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801CC76C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801CC770: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801CC774: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801CC778: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801CC77C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801CC780: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801CC784: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801CC788: lbu         $t4, 0x34($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X34);
    // 0x801CC78C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC790: lwc1        $f6, 0x33A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X33A4);
    // 0x801CC794: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801CC798: lbu         $t5, 0x35($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X35);
    // 0x801CC79C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x801CC7A0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CC7A4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x801CC7A8: lbu         $t6, 0x36($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X36);
    // 0x801CC7AC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x801CC7B0: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x801CC7B4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x801CC7B8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x801CC7BC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x801CC7C0: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801CC7C4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x801CC7C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CC7CC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x801CC7D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x801CC7D4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801CC7D8: jal         0x801CE3F8
    // 0x801CC7DC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801CE3F8)(rdram, ctx);
        goto after_4;
    // 0x801CC7DC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_4:
    // 0x801CC7E0: beq         $v0, $zero, L_801CC804
    if (ctx->r2 == 0) {
        // 0x801CC7E4: lui         $t4, 0x801E
        ctx->r12 = S32(0X801E << 16);
            goto L_801CC804;
    }
    // 0x801CC7E4: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801CC7E8: jal         0x80020718
    // 0x801CC7EC: addiu       $a0, $zero, 0x10C
    ctx->r4 = ADD32(0, 0X10C);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_5;
    // 0x801CC7EC: addiu       $a0, $zero, 0x10C
    ctx->r4 = ADD32(0, 0X10C);
    after_5:
    // 0x801CC7F0: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801CC7F4: lw          $t2, 0x4080($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4080);
    // 0x801CC7F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CC7FC: b           L_801CC810
    // 0x801CC800: sh          $t1, 0x4C($t2)
    MEM_H(0X4C, ctx->r10) = ctx->r9;
        goto L_801CC810;
    // 0x801CC800: sh          $t1, 0x4C($t2)
    MEM_H(0X4C, ctx->r10) = ctx->r9;
L_801CC804:
    // 0x801CC804: lw          $t4, 0x4080($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4080);
    // 0x801CC808: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801CC80C: sh          $t3, 0x4C($t4)
    MEM_H(0X4C, ctx->r12) = ctx->r11;
L_801CC810:
    // 0x801CC810: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC814: addiu       $a1, $a1, -0x37D0
    ctx->r5 = ADD32(ctx->r5, -0X37D0);
    // 0x801CC818: jal         0x800058DC
    // 0x801CC81C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801CC81C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_6:
    // 0x801CC820: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801CC824: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801CC828: jr          $ra
    // 0x801CC82C: nop

    return;
    // 0x801CC82C: nop

;}
RECOMP_FUNC void M8_FUN_801cc830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC830: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801CC834: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801CC838: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801CC83C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801CC840: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x801CC844: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801CC848: addiu       $t3, $t3, 0x4080
    ctx->r11 = ADD32(ctx->r11, 0X4080);
    // 0x801CC84C: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x801CC850: lw          $t7, 0x5C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X5C);
    // 0x801CC854: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801CC858: lw          $t2, 0x2C($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X2C);
    // 0x801CC85C: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x801CC860: lhu         $t8, 0x4C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X4C);
    // 0x801CC864: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CC868: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x801CC86C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x801CC870: bne         $at, $zero, L_801CC99C
    if (ctx->r1 != 0) {
        // 0x801CC874: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_801CC99C;
    }
    // 0x801CC874: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CC878: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
    // 0x801CC87C: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x801CC880: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801CC884: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x801CC888: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x801CC88C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801CC890: lbu         $v1, 0x34($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X34);
    // 0x801CC894: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC898: lwc1        $f6, 0x33A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X33A8);
    // 0x801CC89C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801CC8A0: lbu         $t0, 0x35($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X35);
    // 0x801CC8A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CC8A8: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x801CC8AC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801CC8B0: lbu         $t1, 0x36($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X36);
    // 0x801CC8B4: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x801CC8B8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801CC8BC: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x801CC8C0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x801CC8C4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CC8C8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801CC8CC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801CC8D0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801CC8D4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CC8D8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801CC8DC: jal         0x801CE330
    // 0x801CC8E0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_0;
    // 0x801CC8E0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_0:
    // 0x801CC8E4: jal         0x80006214
    // 0x801CC8E8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CC8E8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_1:
    // 0x801CC8EC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801CC8F0: addiu       $a1, $a1, -0x2578
    ctx->r5 = ADD32(ctx->r5, -0X2578);
    // 0x801CC8F4: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x801CC8F8: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x801CC8FC: jal         0x8013A334
    // 0x801CC900: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x801CC900: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    after_2:
    // 0x801CC904: jal         0x80006214
    // 0x801CC908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801CC908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801CC90C: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801CC910: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CC914: lw          $v0, 0x4080($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4080);
    // 0x801CC918: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801CC91C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC920: lbu         $v1, 0x34($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X34);
    // 0x801CC924: lwc1        $f10, 0x33AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X33AC);
    // 0x801CC928: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CC92C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801CC930: lbu         $t0, 0x35($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X35);
    // 0x801CC934: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801CC938: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x801CC93C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801CC940: lbu         $t1, 0x36($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X36);
    // 0x801CC944: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x801CC948: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x801CC94C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x801CC950: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x801CC954: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CC958: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801CC95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CC960: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801CC964: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x801CC968: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x801CC96C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801CC970: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x801CC974: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CC978: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801CC97C: jal         0x801CE330
    // 0x801CC980: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_4;
    // 0x801CC980: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_4:
    // 0x801CC984: jal         0x80020718
    // 0x801CC988: addiu       $a0, $zero, 0x10A
    ctx->r4 = ADD32(0, 0X10A);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_5;
    // 0x801CC988: addiu       $a0, $zero, 0x10A
    ctx->r4 = ADD32(0, 0X10A);
    after_5:
    // 0x801CC98C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC990: addiu       $a1, $a1, -0x39A0
    ctx->r5 = ADD32(ctx->r5, -0X39A0);
    // 0x801CC994: jal         0x800058DC
    // 0x801CC998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801CC998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_801CC99C:
    // 0x801CC99C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801CC9A0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801CC9A4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801CC9A8: jr          $ra
    // 0x801CC9AC: nop

    return;
    // 0x801CC9AC: nop

;}
RECOMP_FUNC void M8_FUN_801cc9b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC9B0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801CC9B4: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cc9b8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cc9b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC9B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC9C0: bne         $a0, $t6, L_801CC9D4
    if (ctx->r4 != ctx->r14) {
        // 0x801CC9C4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801CC9D4;
    }
    // 0x801CC9C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC9C8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CC9CC: b           L_801CC9DC
    // 0x801CC9D0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_801CC9DC;
    // 0x801CC9D0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_801CC9D4:
    // 0x801CC9D4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CC9D8: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_801CC9DC:
    // 0x801CC9DC: lbu         $t7, 0x2D9($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2D9);
    // 0x801CC9E0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CC9E4: addiu       $a1, $a1, 0xCE8
    ctx->r5 = ADD32(ctx->r5, 0XCE8);
    // 0x801CC9E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC9EC: jal         0x80005670
    // 0x801CC9F0: sb          $t7, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801CC9F0: sb          $t7, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r15;
    after_0:
    // 0x801CC9F4: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x801CC9F8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CC9FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCA00: addiu       $v1, $v1, 0x4080
    ctx->r3 = ADD32(ctx->r3, 0X4080);
    // 0x801CCA04: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801CCA08: sb          $t8, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r24;
    // 0x801CCA0C: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x801CCA10: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x801CCA14: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x801CCA18: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x801CCA1C: jal         0x801CBE04
    // 0x801CCA20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x801CBE04)(rdram, ctx);
        goto after_1;
    // 0x801CCA20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801CCA24: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CCA28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCA2C: jal         0x800058DC
    // 0x801CCA30: addiu       $a1, $a1, -0x35BC
    ctx->r5 = ADD32(ctx->r5, -0X35BC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CCA30: addiu       $a1, $a1, -0x35BC
    ctx->r5 = ADD32(ctx->r5, -0X35BC);
    after_2:
    // 0x801CCA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CCA38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CCA3C: jr          $ra
    // 0x801CCA40: nop

    return;
    // 0x801CCA40: nop

;}
RECOMP_FUNC void M8_FUN_801cca44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCA44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CCA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCA4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CCA50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CCA54: lw          $a3, 0x5C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X5C);
    // 0x801CCA58: jal         0x80126944
    // 0x801CCA5C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801CCA5C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801CCA60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CCA64: beq         $v0, $t0, L_801CCBA8
    if (ctx->r2 == ctx->r8) {
        // 0x801CCA68: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCBA8;
    }
    // 0x801CCA68: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCA6C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CCA70: lbu         $v0, 0xD98($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD98);
    // 0x801CCA74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCA78: addiu       $a1, $zero, 0x1AA
    ctx->r5 = ADD32(0, 0X1AA);
    // 0x801CCA7C: bne         $v0, $zero, L_801CCAB0
    if (ctx->r2 != 0) {
        // 0x801CCA80: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801CCAB0;
    }
    // 0x801CCA80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCA84: jal         0x80126A0C
    // 0x801CCA88: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_1;
    // 0x801CCA88: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x801CCA8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CCA90: bne         $v0, $t0, L_801CCD48
    if (ctx->r2 != ctx->r8) {
        // 0x801CCA94: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCD48;
    }
    // 0x801CCA94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCA98: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CCA9C: lbu         $v1, 0xD98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XD98);
    // 0x801CCAA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CCAA8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x801CCAAC: sb          $v0, 0xD98($at)
    MEM_B(0XD98, ctx->r1) = ctx->r2;
L_801CCAB0:
    // 0x801CCAB0: bne         $t0, $v0, L_801CCAEC
    if (ctx->r8 != ctx->r2) {
        // 0x801CCAB4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801CCAEC;
    }
    // 0x801CCAB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCAB8: addiu       $a1, $zero, 0x1AB
    ctx->r5 = ADD32(0, 0X1AB);
    // 0x801CCABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCAC0: jal         0x80126A0C
    // 0x801CCAC4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_2;
    // 0x801CCAC4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CCAC8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CCACC: bne         $v0, $t0, L_801CCD48
    if (ctx->r2 != ctx->r8) {
        // 0x801CCAD0: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCD48;
    }
    // 0x801CCAD0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCAD4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CCAD8: lbu         $v1, 0xD98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XD98);
    // 0x801CCADC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CCAE4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x801CCAE8: sb          $v0, 0xD98($at)
    MEM_B(0XD98, ctx->r1) = ctx->r2;
L_801CCAEC:
    // 0x801CCAEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CCAF0: bne         $v0, $at, L_801CCB2C
    if (ctx->r2 != ctx->r1) {
        // 0x801CCAF4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801CCB2C;
    }
    // 0x801CCAF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCAF8: addiu       $a1, $zero, 0x1AC
    ctx->r5 = ADD32(0, 0X1AC);
    // 0x801CCAFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCB00: jal         0x80126A0C
    // 0x801CCB04: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_3;
    // 0x801CCB04: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_3:
    // 0x801CCB08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CCB0C: bne         $v0, $t0, L_801CCD48
    if (ctx->r2 != ctx->r8) {
        // 0x801CCB10: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCD48;
    }
    // 0x801CCB10: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCB14: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CCB18: lbu         $v1, 0xD98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XD98);
    // 0x801CCB1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CCB24: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x801CCB28: sb          $v0, 0xD98($at)
    MEM_B(0XD98, ctx->r1) = ctx->r2;
L_801CCB2C:
    // 0x801CCB2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801CCB30: bne         $v0, $at, L_801CCB6C
    if (ctx->r2 != ctx->r1) {
        // 0x801CCB34: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801CCB6C;
    }
    // 0x801CCB34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCB38: addiu       $a1, $zero, 0x1AD
    ctx->r5 = ADD32(0, 0X1AD);
    // 0x801CCB3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCB40: jal         0x80126A0C
    // 0x801CCB44: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_4;
    // 0x801CCB44: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_4:
    // 0x801CCB48: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CCB4C: bne         $v0, $t0, L_801CCD48
    if (ctx->r2 != ctx->r8) {
        // 0x801CCB50: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCD48;
    }
    // 0x801CCB50: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCB54: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CCB58: lbu         $v1, 0xD98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XD98);
    // 0x801CCB5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CCB64: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x801CCB68: sb          $v0, 0xD98($at)
    MEM_B(0XD98, ctx->r1) = ctx->r2;
L_801CCB6C:
    // 0x801CCB6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801CCB70: bne         $v0, $at, L_801CCBA8
    if (ctx->r2 != ctx->r1) {
        // 0x801CCB74: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801CCBA8;
    }
    // 0x801CCB74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCB78: addiu       $a1, $zero, 0x1AF
    ctx->r5 = ADD32(0, 0X1AF);
    // 0x801CCB7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCB80: jal         0x80126A0C
    // 0x801CCB84: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_5;
    // 0x801CCB84: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_5:
    // 0x801CCB88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CCB8C: bne         $v0, $t0, L_801CCD48
    if (ctx->r2 != ctx->r8) {
        // 0x801CCB90: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCD48;
    }
    // 0x801CCB90: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCB94: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CCB98: lbu         $v1, 0xD98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XD98);
    // 0x801CCB9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCBA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CCBA4: sb          $v1, 0xD98($at)
    MEM_B(0XD98, ctx->r1) = ctx->r3;
L_801CCBA8:
    // 0x801CCBA8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CCBAC: lw          $t7, 0x4080($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4080);
    // 0x801CCBB0: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CCBB4: lhu         $t8, 0x4C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4C);
    // 0x801CCBB8: beql        $t8, $zero, L_801CCD4C
    if (ctx->r24 == 0) {
        // 0x801CCBBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CCD4C;
    }
    goto skip_0;
    // 0x801CCBBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CCBC0: lw          $t1, 0x1C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X1C);
    // 0x801CCBC4: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x801CCBC8: lw          $t2, 0x1C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X1C);
    // 0x801CCBCC: sw          $t1, 0x88($a3)
    MEM_W(0X88, ctx->r7) = ctx->r9;
    // 0x801CCBD0: lw          $t1, 0x24($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X24);
    // 0x801CCBD4: addiu       $a2, $a2, 0x4070
    ctx->r6 = ADD32(ctx->r6, 0X4070);
    // 0x801CCBD8: sw          $t9, 0x8C($a3)
    MEM_W(0X8C, ctx->r7) = ctx->r25;
    // 0x801CCBDC: sw          $t1, 0x90($a3)
    MEM_W(0X90, ctx->r7) = ctx->r9;
    // 0x801CCBE0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x801CCBE4: lhu         $t3, 0x22($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X22);
    // 0x801CCBE8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCBEC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x801CCBF0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801CCBF4: sh          $t4, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r12;
    // 0x801CCBF8: jal         0x80126944
    // 0x801CCBFC: sb          $zero, 0xD98($at)
    MEM_B(0XD98, ctx->r1) = 0;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_6;
    // 0x801CCBFC: sb          $zero, 0xD98($at)
    MEM_B(0XD98, ctx->r1) = 0;
    after_6:
    // 0x801CCC00: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CCC04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CCC08: addiu       $a2, $a2, 0x4070
    ctx->r6 = ADD32(ctx->r6, 0X4070);
    // 0x801CCC0C: bne         $v0, $t0, L_801CCC20
    if (ctx->r2 != ctx->r8) {
        // 0x801CCC10: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCC20;
    }
    // 0x801CCC10: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCC14: lhu         $t5, 0x4($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X4);
    // 0x801CCC18: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x801CCC1C: sh          $t6, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r14;
L_801CCC20:
    // 0x801CCC20: lhu         $t7, 0x20($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X20);
    // 0x801CCC24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CCC28: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801CCC2C: sh          $t7, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r15;
    // 0x801CCC30: lw          $t8, 0x1C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1C);
    // 0x801CCC34: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x801CCC38: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x801CCC3C: jal         0x80011198
    // 0x801CCC40: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_7;
    // 0x801CCC40: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    after_7:
    // 0x801CCC44: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCC48: lhu         $t9, 0x22($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X22);
    // 0x801CCC4C: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x801CCC50: beq         $t1, $zero, L_801CCC6C
    if (ctx->r9 == 0) {
        // 0x801CCC54: nop
    
            goto L_801CCC6C;
    }
    // 0x801CCC54: nop

    // 0x801CCC58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CCC5C: addiu       $a1, $a3, 0x22
    ctx->r5 = ADD32(ctx->r7, 0X22);
    // 0x801CCC60: jal         0x800113D0
    // 0x801CCC64: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_8;
    // 0x801CCC64: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_8:
    // 0x801CCC68: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_801CCC6C:
    // 0x801CCC6C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801CCC70: lw          $t2, 0x4080($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4080);
    // 0x801CCC74: lbu         $t3, 0x30($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X30);
    // 0x801CCC78: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x801CCC7C: sltiu       $at, $t4, 0x20
    ctx->r1 = ctx->r12 < 0X20 ? 1 : 0;
    // 0x801CCC80: beq         $at, $zero, L_801CCCAC
    if (ctx->r1 == 0) {
        // 0x801CCC84: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_801CCCAC;
    }
    // 0x801CCC84: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801CCC88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCC8C: addu        $at, $at, $t4
    gpr jr_addend_801CCC94 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801CCC90: lw          $t4, 0x33B0($at)
    ctx->r12 = ADD32(ctx->r1, 0X33B0);
    // 0x801CCC94: jr          $t4
    // 0x801CCC98: nop

    switch (jr_addend_801CCC94 >> 2) {
        case 0: goto L_801CCCAC; break;
        case 1: goto L_801CCCAC; break;
        case 2: goto L_801CCCAC; break;
        case 3: goto L_801CCCAC; break;
        case 4: goto L_801CCCBC; break;
        case 5: goto L_801CCCBC; break;
        case 6: goto L_801CCCBC; break;
        case 7: goto L_801CCCBC; break;
        case 8: goto L_801CCCAC; break;
        case 9: goto L_801CCCAC; break;
        case 10: goto L_801CCCAC; break;
        case 11: goto L_801CCCAC; break;
        case 12: goto L_801CCCAC; break;
        case 13: goto L_801CCCAC; break;
        case 14: goto L_801CCCAC; break;
        case 15: goto L_801CCC9C; break;
        case 16: goto L_801CCC9C; break;
        case 17: goto L_801CCC9C; break;
        case 18: goto L_801CCCAC; break;
        case 19: goto L_801CCCAC; break;
        case 20: goto L_801CCCAC; break;
        case 21: goto L_801CCCAC; break;
        case 22: goto L_801CCCAC; break;
        case 23: goto L_801CCCAC; break;
        case 24: goto L_801CCCAC; break;
        case 25: goto L_801CCCAC; break;
        case 26: goto L_801CCCAC; break;
        case 27: goto L_801CCCAC; break;
        case 28: goto L_801CCCAC; break;
        case 29: goto L_801CCC9C; break;
        case 30: goto L_801CCC9C; break;
        case 31: goto L_801CCC9C; break;
        default: switch_error(__func__, 0x801CCC94, 0x801E33B0);
    }
    // 0x801CCC98: nop

L_801CCC9C:
    // 0x801CCC9C: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801CCCA0: addiu       $t5, $t5, 0xD68
    ctx->r13 = ADD32(ctx->r13, 0XD68);
    // 0x801CCCA4: b           L_801CCCC8
    // 0x801CCCA8: sw          $t5, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r13;
        goto L_801CCCC8;
    // 0x801CCCA8: sw          $t5, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r13;
L_801CCCAC:
    // 0x801CCCAC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CCCB0: addiu       $t6, $t6, 0xD88
    ctx->r14 = ADD32(ctx->r14, 0XD88);
    // 0x801CCCB4: b           L_801CCCC8
    // 0x801CCCB8: sw          $t6, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r14;
        goto L_801CCCC8;
    // 0x801CCCB8: sw          $t6, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r14;
L_801CCCBC:
    // 0x801CCCBC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CCCC0: addiu       $t7, $t7, 0xD68
    ctx->r15 = ADD32(ctx->r15, 0XD68);
    // 0x801CCCC4: sw          $t7, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r15;
L_801CCCC8:
    // 0x801CCCC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801CCCCC: sh          $v0, 0x82($a3)
    MEM_H(0X82, ctx->r7) = ctx->r2;
    // 0x801CCCD0: sh          $v0, 0x80($a3)
    MEM_H(0X80, ctx->r7) = ctx->r2;
    // 0x801CCCD4: jal         0x80126944
    // 0x801CCCD8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_9;
    // 0x801CCCD8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_9:
    // 0x801CCCDC: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CCCE0: addiu       $a2, $a2, 0x4070
    ctx->r6 = ADD32(ctx->r6, 0X4070);
    // 0x801CCCE4: bne         $v0, $zero, L_801CCD38
    if (ctx->r2 != 0) {
        // 0x801CCCE8: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_801CCD38;
    }
    // 0x801CCCE8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCCEC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CCCF0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801CCCF4: lbu         $t8, 0x47D($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X47D);
    // 0x801CCCF8: lhu         $t2, 0xEF0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XEF0);
    // 0x801CCCFC: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x801CCD00: andi        $t9, $t8, 0xFF9F
    ctx->r25 = ctx->r24 & 0XFF9F;
    // 0x801CCD04: ori         $t1, $t9, 0x40
    ctx->r9 = ctx->r25 | 0X40;
    // 0x801CCD08: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x801CCD0C: beq         $t3, $zero, L_801CCD38
    if (ctx->r11 == 0) {
        // 0x801CCD10: sb          $t1, 0x47D($v0)
        MEM_B(0X47D, ctx->r2) = ctx->r9;
            goto L_801CCD38;
    }
    // 0x801CCD10: sb          $t1, 0x47D($v0)
    MEM_B(0X47D, ctx->r2) = ctx->r9;
    // 0x801CCD14: lbu         $t4, -0x2ABC($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2ABC);
    // 0x801CCD18: addiu       $t5, $zero, 0x82
    ctx->r13 = ADD32(0, 0X82);
    // 0x801CCD1C: addiu       $t6, $zero, 0x41
    ctx->r14 = ADD32(0, 0X41);
    // 0x801CCD20: beql        $t4, $zero, L_801CCD34
    if (ctx->r12 == 0) {
        // 0x801CCD24: sh          $t6, 0x82($a3)
        MEM_H(0X82, ctx->r7) = ctx->r14;
            goto L_801CCD34;
    }
    goto skip_1;
    // 0x801CCD24: sh          $t6, 0x82($a3)
    MEM_H(0X82, ctx->r7) = ctx->r14;
    skip_1:
    // 0x801CCD28: b           L_801CCD34
    // 0x801CCD2C: sh          $t5, 0x82($a3)
    MEM_H(0X82, ctx->r7) = ctx->r13;
        goto L_801CCD34;
    // 0x801CCD2C: sh          $t5, 0x82($a3)
    MEM_H(0X82, ctx->r7) = ctx->r13;
    // 0x801CCD30: sh          $t6, 0x82($a3)
    MEM_H(0X82, ctx->r7) = ctx->r14;
L_801CCD34:
    // 0x801CCD34: sw          $a2, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r6;
L_801CCD38:
    // 0x801CCD38: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CCD3C: addiu       $a1, $a1, -0x32A8
    ctx->r5 = ADD32(ctx->r5, -0X32A8);
    // 0x801CCD40: jal         0x800058DC
    // 0x801CCD44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801CCD44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
L_801CCD48:
    // 0x801CCD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CCD4C:
    // 0x801CCD4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CCD50: jr          $ra
    // 0x801CCD54: nop

    return;
    // 0x801CCD54: nop

;}
RECOMP_FUNC void M8_FUN_801ccd58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCD58: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801CCD5C: lbu         $t6, -0x33DB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801ccd60(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801ccd60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCD60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CCD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCD68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CCD6C: bne         $t6, $at, L_801CCDD4
    if (ctx->r14 != ctx->r1) {
        // 0x801CCD70: lw          $v0, 0x5C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X5C);
            goto L_801CCDD4;
    }
    // 0x801CCD70: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801CCD74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCD78: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801CCD7C: jal         0x801DB6B8
    // 0x801CCD80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801DB6B8)(rdram, ctx);
        goto after_0;
    // 0x801CCD80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CCD84: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801CCD88: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CCD8C: addiu       $t7, $t7, 0x4070
    ctx->r15 = ADD32(ctx->r15, 0X4070);
    // 0x801CCD90: lw          $t8, 0x7C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X7C);
    // 0x801CCD94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CCD98: bnel        $t7, $t8, L_801CCDD8
    if (ctx->r15 != ctx->r24) {
        // 0x801CCD9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CCDD8;
    }
    goto skip_0;
    // 0x801CCD9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CCDA0: lhu         $t9, 0x80($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X80);
    // 0x801CCDA4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CCDA8: bnel        $t9, $zero, L_801CCDD8
    if (ctx->r25 != 0) {
        // 0x801CCDAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CCDD8;
    }
    goto skip_1;
    // 0x801CCDAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801CCDB0: lw          $v0, 0x4080($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4080);
    // 0x801CCDB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CCDB8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CCDBC: lhu         $t0, 0x4C($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4C);
    // 0x801CCDC0: addiu       $a1, $a1, -0x321C
    ctx->r5 = ADD32(ctx->r5, -0X321C);
    // 0x801CCDC4: ori         $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 | 0X8000;
    // 0x801CCDC8: sh          $t1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r9;
    // 0x801CCDCC: jal         0x800058DC
    // 0x801CCDD0: sb          $zero, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CCDD0: sb          $zero, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = 0;
    after_1:
L_801CCDD4:
    // 0x801CCDD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CCDD8:
    // 0x801CCDD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CCDDC: jr          $ra
    // 0x801CCDE0: nop

    return;
    // 0x801CCDE0: nop

;}
RECOMP_FUNC void M8_FUN_801ccde4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCDE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CCDE8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CCDEC: lw          $t6, 0x4080($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4080);
    // 0x801CCDF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CCDF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CCDF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CCDFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CCE00: bne         $t6, $zero, L_801CCF74
    if (ctx->r14 != 0) {
        // 0x801CCE04: lw          $t0, 0x5C($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X5C);
            goto L_801CCF74;
    }
    // 0x801CCE04: lw          $t0, 0x5C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X5C);
    // 0x801CCE08: jal         0x80126944
    // 0x801CCE0C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801CCE0C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x801CCE10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CCE14: bne         $v0, $at, L_801CCEEC
    if (ctx->r2 != ctx->r1) {
        // 0x801CCE18: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_801CCEEC;
    }
    // 0x801CCE18: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801CCE1C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CCE20: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801CCE24: lw          $t7, 0xDC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XDC);
    // 0x801CCE28: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CCE2C: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
    // 0x801CCE30: bne         $s0, $t7, L_801CCE44
    if (ctx->r16 != ctx->r15) {
        // 0x801CCE34: nop
    
            goto L_801CCE44;
    }
    // 0x801CCE34: nop

    // 0x801CCE38: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CCE3C: b           L_801CCE44
    // 0x801CCE40: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_801CCE44;
    // 0x801CCE40: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_801CCE44:
    // 0x801CCE44: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x801CCE48: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
    // 0x801CCE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CCE50: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x801CCE54: lbu         $t3, 0x31($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X31);
    // 0x801CCE58: lbu         $t5, 0x30($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X30);
    // 0x801CCE5C: sw          $t2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r10;
    // 0x801CCE60: andi        $t9, $t3, 0xFFF8
    ctx->r25 = ctx->r11 & 0XFFF8;
    // 0x801CCE64: andi        $t7, $t5, 0xFF7F
    ctx->r15 = ctx->r13 & 0XFF7F;
    // 0x801CCE68: sb          $t9, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r25;
    // 0x801CCE6C: sb          $t7, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r15;
    // 0x801CCE70: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x801CCE74: andi        $t1, $t9, 0x7F
    ctx->r9 = ctx->r25 & 0X7F;
    // 0x801CCE78: sb          $t8, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r24;
    // 0x801CCE7C: sb          $t1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r9;
    // 0x801CCE80: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801CCE84: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801CCE88: jal         0x801CBE90
    // 0x801CCE8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CBE90)(rdram, ctx);
        goto after_1;
    // 0x801CCE8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801CCE90: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801CCE94: lw          $t3, 0x88($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X88);
    // 0x801CCE98: addiu       $v1, $t0, 0x1C
    ctx->r3 = ADD32(ctx->r8, 0X1C);
    // 0x801CCE9C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801CCEA0: lw          $t2, 0x8C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8C);
    // 0x801CCEA4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801CCEA8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x801CCEAC: lw          $t3, 0x90($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X90);
    // 0x801CCEB0: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x801CCEB4: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x801CCEB8: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801CCEBC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CCEC0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CCEC4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CCEC8: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x801CCECC: jal         0x8013A28C
    // 0x801CCED0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CCED0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CCED4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x801CCED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CCEDC: jal         0x800058DC
    // 0x801CCEE0: lw          $a1, 0x324($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X324);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CCEE0: lw          $a1, 0x324($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X324);
    after_3:
    // 0x801CCEE4: b           L_801CCF78
    // 0x801CCEE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801CCF78;
    // 0x801CCEE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CCEEC:
    // 0x801CCEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CCEF0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CCEF4: jal         0x801CBE90
    // 0x801CCEF8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801CBE90)(rdram, ctx);
        goto after_4;
    // 0x801CCEF8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_4:
    // 0x801CCEFC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801CCF00: lw          $t7, 0x88($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X88);
    // 0x801CCF04: addiu       $v1, $t0, 0x1C
    ctx->r3 = ADD32(ctx->r8, 0X1C);
    // 0x801CCF08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801CCF0C: lw          $t6, 0x8C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8C);
    // 0x801CCF10: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801CCF14: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801CCF18: lw          $t7, 0x90($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X90);
    // 0x801CCF1C: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x801CCF20: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801CCF24: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801CCF28: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CCF2C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CCF30: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CCF34: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x801CCF38: jal         0x8013A28C
    // 0x801CCF3C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_5;
    // 0x801CCF3C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_5:
    // 0x801CCF40: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x801CCF44: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CCF48: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801CCF4C: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x801CCF50: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x801CCF54: lhu         $t3, 0xEF0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XEF0);
    // 0x801CCF58: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x801CCF5C: jal         0x8001F6FC
    // 0x801CCF60: sh          $t4, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r12;
    LOOKUP_FUNC(0x8001F6FC)(rdram, ctx);
        goto after_6;
    // 0x801CCF60: sh          $t4, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r12;
    after_6:
    // 0x801CCF64: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CCF68: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801CCF6C: jal         0x800058DC
    // 0x801CCF70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801CCF70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_801CCF74:
    // 0x801CCF74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CCF78:
    // 0x801CCF78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CCF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CCF80: jr          $ra
    // 0x801CCF84: nop

    return;
    // 0x801CCF84: nop

;}
RECOMP_FUNC void M8_FUN_801ccf88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CCF8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CCF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCF94: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CCF98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801CCF9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801CCFA0: jal         0x80005670
    // 0x801CCFA4: addiu       $a1, $a1, 0xCFC
    ctx->r5 = ADD32(ctx->r5, 0XCFC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801CCFA4: addiu       $a1, $a1, 0xCFC
    ctx->r5 = ADD32(ctx->r5, 0XCFC);
    after_0:
    // 0x801CCFA8: beq         $v0, $zero, L_801CCFDC
    if (ctx->r2 == 0) {
        // 0x801CCFAC: lwc1        $f4, 0x1C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_801CCFDC;
    }
    // 0x801CCFAC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801CCFB0: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x801CCFB4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801CCFB8: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x801CCFBC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CCFC0: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x801CCFC4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CCFC8: swc1        $f10, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f10.u32l;
    // 0x801CCFCC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801CCFD0: swc1        $f16, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f16.u32l;
    // 0x801CCFD4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801CCFD8: swc1        $f18, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f18.u32l;
L_801CCFDC:
    // 0x801CCFDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CCFE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CCFE4: jr          $ra
    // 0x801CCFE8: nop

    return;
    // 0x801CCFE8: nop

;}
RECOMP_FUNC void M8_FUN_801ccfec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCFEC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x801CCFF0: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x801CCFF4: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x801CCFF8: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x801CCFFC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x801CD000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CD004: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x801CD008: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x801CD00C: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x801CD010: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x801CD014: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x801CD018: lwc1        $f12, 0x7C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x801CD01C: jal         0x8001EF38
    // 0x801CD020: lwc1        $f14, 0x84($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X84);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801CD020: lwc1        $f14, 0x84($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801CD024: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD028: lwc1        $f0, 0x3430($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3430);
    // 0x801CD02C: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x801CD030: sh          $v0, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r2;
    // 0x801CD034: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
    // 0x801CD038: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801CD03C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CD040: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CD044: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801CD048: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801CD04C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CD050: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CD054: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CD058: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x801CD05C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x801CD060: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801CD064: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801CD068: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x801CD06C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x801CD070: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x801CD074: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x801CD078: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x801CD07C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801CD080: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801CD084: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801CD088: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801CD08C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801CD090: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801CD094: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801CD098: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x801CD09C: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x801CD0A0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x801CD0A4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x801CD0A8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CD0AC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CD0B0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x801CD0B4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801CD0B8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801CD0BC: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x801CD0C0: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x801CD0C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CD0C8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x801CD0CC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801CD0D0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801CD0D4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801CD0D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801CD0DC: jal         0x801CE1C8
    // 0x801CD0E0: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801CE1C8)(rdram, ctx);
        goto after_1;
    // 0x801CD0E0: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x801CD0E4: beq         $v0, $zero, L_801CD0F4
    if (ctx->r2 == 0) {
        // 0x801CD0E8: lui         $at, 0x3E20
        ctx->r1 = S32(0X3E20 << 16);
            goto L_801CD0F4;
    }
    // 0x801CD0E8: lui         $at, 0x3E20
    ctx->r1 = S32(0X3E20 << 16);
    // 0x801CD0EC: lh          $t7, 0x82($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X82);
    // 0x801CD0F0: sh          $t7, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r15;
L_801CD0F4:
    // 0x801CD0F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801CD0F8: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801CD0FC: lh          $t4, 0x82($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X82);
    // 0x801CD100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801CD104: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CD108: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CD10C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CD110: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801CD114: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801CD118: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801CD11C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CD120: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801CD124: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801CD128: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x801CD12C: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x801CD130: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x801CD134: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801CD138: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801CD13C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801CD140: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801CD144: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801CD148: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801CD14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CD150: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x801CD154: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x801CD158: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x801CD15C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CD160: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CD164: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801CD168: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801CD16C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x801CD170: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CD174: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CD178: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x801CD17C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x801CD180: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801CD184: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801CD188: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801CD18C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801CD190: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x801CD194: jal         0x801CE1C8
    // 0x801CD198: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CE1C8)(rdram, ctx);
        goto after_2;
    // 0x801CD198: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801CD19C: beq         $v0, $zero, L_801CD1AC
    if (ctx->r2 == 0) {
        // 0x801CD1A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CD1AC;
    }
    // 0x801CD1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CD1A4: lh          $t8, 0x82($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X82);
    // 0x801CD1A8: sh          $t8, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r24;
L_801CD1AC:
    // 0x801CD1AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CD1B0: jal         0x800058DC
    // 0x801CD1B4: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CD1B4: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    after_3:
    // 0x801CD1B8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x801CD1BC: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x801CD1C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x801CD1C4: jr          $ra
    // 0x801CD1C8: nop

    return;
    // 0x801CD1C8: nop

;}
RECOMP_FUNC void M8_FUN_801cd1cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD1CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CD1D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD1D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CD1D8: lhu         $t7, 0x4E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4E);
    // 0x801CD1DC: lhu         $t6, 0x4C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4C);
    // 0x801CD1E0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CD1E4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801CD1E8: bnel        $at, $zero, L_801CD1FC
    if (ctx->r1 != 0) {
        // 0x801CD1EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CD1FC;
    }
    goto skip_0;
    // 0x801CD1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CD1F0: jal         0x800058DC
    // 0x801CD1F4: addiu       $a1, $a1, -0x2DF8
    ctx->r5 = ADD32(ctx->r5, -0X2DF8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CD1F4: addiu       $a1, $a1, -0x2DF8
    ctx->r5 = ADD32(ctx->r5, -0X2DF8);
    after_0:
    // 0x801CD1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CD1FC:
    // 0x801CD1FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CD200: jr          $ra
    // 0x801CD204: nop

    return;
    // 0x801CD204: nop

;}
RECOMP_FUNC void M8_FUN_801cd208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CD20C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD210: jal         0x80005700
    // 0x801CD214: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801CD214: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CD218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD21C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CD220: jr          $ra
    // 0x801CD224: nop

    return;
    // 0x801CD224: nop

;}
RECOMP_FUNC void M8_FUN_801cd228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD228: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CD22C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD230: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801CD234: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CD238: addiu       $a1, $a1, 0xD10
    ctx->r5 = ADD32(ctx->r5, 0XD10);
    // 0x801CD23C: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801CD240: jal         0x80005670
    // 0x801CD244: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801CD244: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801CD248: beq         $v0, $zero, L_801CD278
    if (ctx->r2 == 0) {
        // 0x801CD24C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_801CD278;
    }
    // 0x801CD24C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD250: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801CD254: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CD258: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x801CD25C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801CD260: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x801CD264: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801CD268: sb          $t7, 0x78($v0)
    MEM_B(0X78, ctx->r2) = ctx->r15;
    // 0x801CD26C: sb          $zero, 0x7A($v0)
    MEM_B(0X7A, ctx->r2) = 0;
    // 0x801CD270: sb          $zero, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = 0;
    // 0x801CD274: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
L_801CD278:
    // 0x801CD278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD27C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CD280: jr          $ra
    // 0x801CD284: nop

    return;
    // 0x801CD284: nop

;}
RECOMP_FUNC void M8_FUN_801cd288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD288: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801CD28C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801CD290: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801CD294: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801CD298: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x801CD29C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CD2A0: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x801CD2A4: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x801CD2A8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x801CD2AC: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x801CD2B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801CD2B4: jal         0x8012C6B4
    // 0x801CD2B8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801CD2B8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801CD2BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD2C0: lwc1        $f16, 0x3434($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3434);
    // 0x801CD2C4: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801CD2C8: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x801CD2CC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CD2D0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CD2D4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CD2D8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CD2DC: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x801CD2E0: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801CD2E4: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801CD2E8: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x801CD2EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CD2F0: sb          $v1, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r3;
    // 0x801CD2F4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x801CD2F8: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x801CD2FC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801CD300: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801CD304: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801CD308: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801CD30C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801CD310: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801CD314: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801CD318: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x801CD31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CD320: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801CD324: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x801CD328: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x801CD32C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CD330: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801CD334: jal         0x801CE330
    // 0x801CD338: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_1;
    // 0x801CD338: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801CD33C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD340: lwc1        $f4, 0x3438($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3438);
    // 0x801CD344: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801CD348: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801CD34C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CD350: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801CD354: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801CD358: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x801CD35C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x801CD360: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801CD364: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801CD368: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x801CD36C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CD370: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x801CD374: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x801CD378: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x801CD37C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801CD380: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CD384: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801CD388: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CD38C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801CD390: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801CD394: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801CD398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CD39C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x801CD3A0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x801CD3A4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x801CD3A8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CD3AC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x801CD3B0: jal         0x801CE330
    // 0x801CD3B4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_2;
    // 0x801CD3B4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801CD3B8: addiu       $v1, $s0, 0x7B
    ctx->r3 = ADD32(ctx->r16, 0X7B);
    // 0x801CD3BC: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x801CD3C0: lbu         $t6, 0x5F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5F);
    // 0x801CD3C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CD3C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CD3CC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801CD3D0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801CD3D4: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x801CD3D8: bne         $at, $zero, L_801CD3E8
    if (ctx->r1 != 0) {
        // 0x801CD3DC: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_801CD3E8;
    }
    // 0x801CD3DC: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x801CD3E0: jal         0x800058DC
    // 0x801CD3E4: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CD3E4: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    after_3:
L_801CD3E8:
    // 0x801CD3E8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801CD3EC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801CD3F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801CD3F4: jr          $ra
    // 0x801CD3F8: nop

    return;
    // 0x801CD3F8: nop

;}
RECOMP_FUNC void M8_FUN_801cd3fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD3FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CD400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD404: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CD408: jal         0x80005670
    // 0x801CD40C: addiu       $a1, $a1, 0xD24
    ctx->r5 = ADD32(ctx->r5, 0XD24);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801CD40C: addiu       $a1, $a1, 0xD24
    ctx->r5 = ADD32(ctx->r5, 0XD24);
    after_0:
    // 0x801CD410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CD418: jr          $ra
    // 0x801CD41C: nop

    return;
    // 0x801CD41C: nop

;}
RECOMP_FUNC void M8_FUN_801cd420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD420: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801CD424: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CD428: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x801CD42C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801CD430: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x801CD434: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CD438: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801CD43C: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801CD440: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801CD444: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x801CD448: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CD44C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x801CD450: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801CD454: jal         0x8012C6B4
    // 0x801CD458: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801CD458: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801CD45C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD460: lwc1        $f16, 0x343C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X343C);
    // 0x801CD464: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801CD468: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CD46C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CD470: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801CD474: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801CD478: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x801CD47C: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x801CD480: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x801CD484: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801CD488: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x801CD48C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CD490: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x801CD494: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801CD498: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801CD49C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801CD4A0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801CD4A4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801CD4A8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x801CD4AC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801CD4B0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801CD4B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801CD4B8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x801CD4BC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x801CD4C0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x801CD4C4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x801CD4C8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CD4CC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801CD4D0: jal         0x801CE330
    // 0x801CD4D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_1;
    // 0x801CD4D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801CD4D8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CD4DC: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    // 0x801CD4E0: jal         0x800058DC
    // 0x801CD4E4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CD4E4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_2:
    // 0x801CD4E8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801CD4EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801CD4F0: jr          $ra
    // 0x801CD4F4: nop

    return;
    // 0x801CD4F4: nop

;}
RECOMP_FUNC void M8_FUN_801cd4f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD4F8: nop

    // 0x801CD4FC: nop

;}
RECOMP_FUNC void M8_FUN_801cd500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD500: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CD504: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801CD508: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801CD50C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CD510: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801CD514: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801CD518: bgez        $a0, L_801CD530
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801CD51C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CD530;
    }
    // 0x801CD51C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CD520: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CD524: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CD528: nop

    // 0x801CD52C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CD530:
    // 0x801CD530: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x801CD534: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801CD538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CD53C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CD540: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801CD544: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801CD548: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x801CD54C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CD550: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801CD554: nop

    // 0x801CD558: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CD55C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801CD560: nop

    // 0x801CD564: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801CD568: beql        $v0, $zero, L_801CD5C8
    if (ctx->r2 == 0) {
        // 0x801CD56C: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_801CD5C8;
    }
    goto skip_0;
    // 0x801CD56C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x801CD570: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CD574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CD578: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801CD57C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801CD580: nop

    // 0x801CD584: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CD588: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801CD58C: nop

    // 0x801CD590: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801CD594: bnel        $v0, $zero, L_801CD5B8
    if (ctx->r2 != 0) {
        // 0x801CD598: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_801CD5B8;
    }
    goto skip_1;
    // 0x801CD598: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x801CD59C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x801CD5A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CD5A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CD5A8: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x801CD5AC: jr          $ra
    // 0x801CD5B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x801CD5B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CD5B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801CD5B8:
    // 0x801CD5B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CD5BC: jr          $ra
    // 0x801CD5C0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x801CD5C0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CD5C4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_801CD5C8:
    // 0x801CD5C8: nop

    // 0x801CD5CC: bltzl       $v0, L_801CD5B8
    if (SIGNED(ctx->r2) < 0) {
        // 0x801CD5D0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_801CD5B8;
    }
    goto skip_2;
    // 0x801CD5D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_2:
    // 0x801CD5D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CD5D8: jr          $ra
    // 0x801CD5DC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x801CD5DC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cd5e0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cd5e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD5E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CD5E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CD5E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CD5EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CD5F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CD5F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801CD5F8: lbu         $a1, 0x7C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7C);
    // 0x801CD5FC: jal         0x801CD500
    // 0x801CD600: lbu         $a0, 0x78($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X78);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_0;
    // 0x801CD600: lbu         $a0, 0x78($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X78);
    after_0:
    // 0x801CD604: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801CD608: sb          $v0, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r2;
    // 0x801CD60C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801CD610: lbu         $a1, 0x7D($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7D);
    // 0x801CD614: jal         0x801CD500
    // 0x801CD618: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_1;
    // 0x801CD618: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    after_1:
    // 0x801CD61C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801CD620: sb          $v0, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r2;
    // 0x801CD624: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801CD628: lbu         $a1, 0x7E($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7E);
    // 0x801CD62C: jal         0x801CD500
    // 0x801CD630: lbu         $a0, 0x7A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7A);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_2;
    // 0x801CD630: lbu         $a0, 0x7A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7A);
    after_2:
    // 0x801CD634: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801CD638: sb          $v0, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r2;
    // 0x801CD63C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801CD640: lbu         $a1, 0x7F($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7F);
    // 0x801CD644: jal         0x801CD500
    // 0x801CD648: lbu         $a0, 0x7B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7B);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_3;
    // 0x801CD648: lbu         $a0, 0x7B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7B);
    after_3:
    // 0x801CD64C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801CD650: sb          $v0, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r2;
    // 0x801CD654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CD65C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CD660: jr          $ra
    // 0x801CD664: nop

    return;
    // 0x801CD664: nop

;}
RECOMP_FUNC void M8_FUN_801cd668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD668: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CD66C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CD670: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CD674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CD678: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CD67C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801CD680: lbu         $a1, 0x7C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7C);
    // 0x801CD684: jal         0x801CD500
    // 0x801CD688: lbu         $a0, 0x78($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X78);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_0;
    // 0x801CD688: lbu         $a0, 0x78($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X78);
    after_0:
    // 0x801CD68C: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x801CD690: lbu         $a1, 0x7D($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7D);
    // 0x801CD694: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x801CD698: jal         0x801CD500
    // 0x801CD69C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_1;
    // 0x801CD69C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x801CD6A0: lbu         $a0, 0x7A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7A);
    // 0x801CD6A4: lbu         $a1, 0x7E($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7E);
    // 0x801CD6A8: sb          $v0, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r2;
    // 0x801CD6AC: jal         0x801CD500
    // 0x801CD6B0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_2;
    // 0x801CD6B0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x801CD6B4: lbu         $a0, 0x7B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7B);
    // 0x801CD6B8: lbu         $a1, 0x7F($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7F);
    // 0x801CD6BC: sb          $v0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r2;
    // 0x801CD6C0: jal         0x801CD500
    // 0x801CD6C4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_3;
    // 0x801CD6C4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x801CD6C8: lbu         $t6, 0x94($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X94);
    // 0x801CD6CC: lbu         $a3, 0x26($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X26);
    // 0x801CD6D0: lbu         $t0, 0x25($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X25);
    // 0x801CD6D4: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x801CD6D8: blez        $t6, L_801CD714
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CD6DC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801CD714;
    }
    // 0x801CD6DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CD6E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801CD6E4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
L_801CD6E8:
    // 0x801CD6E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801CD6EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801CD6F0: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x801CD6F4: sb          $t1, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r9;
    // 0x801CD6F8: sb          $a3, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r7;
    // 0x801CD6FC: sb          $t0, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r8;
    // 0x801CD700: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
    // 0x801CD704: lbu         $t8, 0x94($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X94);
    // 0x801CD708: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CD70C: bnel        $at, $zero, L_801CD6E8
    if (ctx->r1 != 0) {
        // 0x801CD710: lw          $t7, 0x0($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X0);
            goto L_801CD6E8;
    }
    goto skip_0;
    // 0x801CD710: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    skip_0:
L_801CD714:
    // 0x801CD714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD718: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CD71C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CD720: jr          $ra
    // 0x801CD724: nop

    return;
    // 0x801CD724: nop

;}
RECOMP_FUNC void M8_FUN_801cd728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CD72C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CD730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CD734: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CD738: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CD73C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801CD740: lbu         $a1, 0x84($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X84);
    // 0x801CD744: jal         0x801CD500
    // 0x801CD748: lbu         $a0, 0x80($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X80);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_0;
    // 0x801CD748: lbu         $a0, 0x80($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X80);
    after_0:
    // 0x801CD74C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801CD750: sb          $v0, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r2;
    // 0x801CD754: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801CD758: lbu         $a1, 0x85($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X85);
    // 0x801CD75C: jal         0x801CD500
    // 0x801CD760: lbu         $a0, 0x81($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X81);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_1;
    // 0x801CD760: lbu         $a0, 0x81($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X81);
    after_1:
    // 0x801CD764: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801CD768: sb          $v0, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r2;
    // 0x801CD76C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801CD770: lbu         $a1, 0x86($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X86);
    // 0x801CD774: jal         0x801CD500
    // 0x801CD778: lbu         $a0, 0x82($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X82);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_2;
    // 0x801CD778: lbu         $a0, 0x82($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X82);
    after_2:
    // 0x801CD77C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801CD780: sb          $v0, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r2;
    // 0x801CD784: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801CD788: lbu         $a1, 0x87($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X87);
    // 0x801CD78C: jal         0x801CD500
    // 0x801CD790: lbu         $a0, 0x83($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X83);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_3;
    // 0x801CD790: lbu         $a0, 0x83($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X83);
    after_3:
    // 0x801CD794: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801CD798: sb          $v0, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r2;
    // 0x801CD79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD7A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CD7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CD7A8: jr          $ra
    // 0x801CD7AC: nop

    return;
    // 0x801CD7AC: nop

;}
RECOMP_FUNC void M8_FUN_801cd7b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD7B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CD7B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CD7B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CD7BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CD7C0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CD7C4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801CD7C8: lbu         $a1, 0x84($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X84);
    // 0x801CD7CC: jal         0x801CD500
    // 0x801CD7D0: lbu         $a0, 0x80($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X80);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_0;
    // 0x801CD7D0: lbu         $a0, 0x80($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X80);
    after_0:
    // 0x801CD7D4: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x801CD7D8: lbu         $a1, 0x85($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X85);
    // 0x801CD7DC: lbu         $a0, 0x81($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X81);
    // 0x801CD7E0: jal         0x801CD500
    // 0x801CD7E4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_1;
    // 0x801CD7E4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x801CD7E8: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x801CD7EC: lbu         $a1, 0x86($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X86);
    // 0x801CD7F0: lbu         $a0, 0x82($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X82);
    // 0x801CD7F4: jal         0x801CD500
    // 0x801CD7F8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_2;
    // 0x801CD7F8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x801CD7FC: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x801CD800: lbu         $a1, 0x87($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X87);
    // 0x801CD804: lbu         $a0, 0x83($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X83);
    // 0x801CD808: jal         0x801CD500
    // 0x801CD80C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_3;
    // 0x801CD80C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x801CD810: lbu         $t6, 0x94($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X94);
    // 0x801CD814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CD818: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801CD81C: blez        $t6, L_801CD864
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CD820: lh          $a1, 0x2A($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X2A);
            goto L_801CD864;
    }
    // 0x801CD820: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x801CD824: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x801CD828: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x801CD82C: lh          $a2, 0x28($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X28);
    // 0x801CD830: lh          $a3, 0x26($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X26);
    // 0x801CD834: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_801CD838:
    // 0x801CD838: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CD83C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801CD840: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801CD844: sb          $a1, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r5;
    // 0x801CD848: sb          $a2, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r6;
    // 0x801CD84C: sb          $a3, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r7;
    // 0x801CD850: sb          $t0, 0x4F($v0)
    MEM_B(0X4F, ctx->r2) = ctx->r8;
    // 0x801CD854: lbu         $t8, 0x94($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X94);
    // 0x801CD858: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CD85C: bnel        $at, $zero, L_801CD838
    if (ctx->r1 != 0) {
        // 0x801CD860: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_801CD838;
    }
    goto skip_0;
    // 0x801CD860: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_801CD864:
    // 0x801CD864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CD86C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CD870: jr          $ra
    // 0x801CD874: nop

    return;
    // 0x801CD874: nop

;}
RECOMP_FUNC void M8_FUN_801cd878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CD87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD880: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CD884: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x801CD888: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801CD88C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801CD890: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CD894: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801CD898: bgez        $t6, L_801CD8B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CD89C: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801CD8B4;
    }
    // 0x801CD89C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801CD8A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CD8A4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CD8A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CD8AC: nop

    // 0x801CD8B0: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801CD8B4:
    // 0x801CD8B4: lhu         $t7, 0x90($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X90);
    // 0x801CD8B8: add.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f6.d + ctx->f0.d;
    // 0x801CD8BC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CD8C0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801CD8C4: bgez        $t7, L_801CD8DC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801CD8C8: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_801CD8DC;
    }
    // 0x801CD8C8: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x801CD8CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801CD8D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801CD8D4: nop

    // 0x801CD8D8: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_801CD8DC:
    // 0x801CD8DC: add.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f18.d + ctx->f0.d;
    // 0x801CD8E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801CD8E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CD8E8: div.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x801CD8EC: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x801CD8F0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801CD8F4: jal         0x801CD668
    // 0x801CD8F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x801CD668)(rdram, ctx);
        goto after_0;
    // 0x801CD8F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x801CD8FC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801CD900: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CD904: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801CD908: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801CD90C: jal         0x801CD7B0
    // 0x801CD910: nop

    LOOKUP_FUNC(0x801CD7B0)(rdram, ctx);
        goto after_1;
    // 0x801CD910: nop

    after_1:
    // 0x801CD914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CD91C: jr          $ra
    // 0x801CD920: nop

    return;
    // 0x801CD920: nop

;}
RECOMP_FUNC void M8_FUN_801cd924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD924: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CD928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD92C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CD930: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CD934: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801CD938: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    // 0x801CD93C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801CD940: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x801CD944: jal         0x801CD500
    // 0x801CD948: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_0;
    // 0x801CD948: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x801CD94C: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x801CD950: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x801CD954: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x801CD958: jal         0x801CD500
    // 0x801CD95C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_1;
    // 0x801CD95C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801CD960: sb          $v0, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r2;
    // 0x801CD964: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x801CD968: lbu         $a1, 0x2B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2B);
    // 0x801CD96C: jal         0x801CD500
    // 0x801CD970: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_2;
    // 0x801CD970: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x801CD974: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x801CD978: lbu         $a1, 0x1E($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1E);
    // 0x801CD97C: jal         0x801CBC70
    // 0x801CD980: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x801CBC70)(rdram, ctx);
        goto after_3;
    // 0x801CD980: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x801CD984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CD98C: jr          $ra
    // 0x801CD990: nop

    return;
    // 0x801CD990: nop

;}
RECOMP_FUNC void M8_FUN_801cd994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CD998: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801CD99C: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x801CD9A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CD9A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CD9A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CD9AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801CD9B0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801CD9B4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801CD9B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801CD9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD9C0: bgez        $t6, L_801CD9D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CD9C4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CD9D8;
    }
    // 0x801CD9C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CD9C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CD9CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CD9D0: nop

    // 0x801CD9D4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CD9D8:
    // 0x801CD9D8: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x801CD9DC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801CD9E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801CD9E4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801CD9E8: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x801CD9EC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801CD9F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801CD9F4: jal         0x801CD924
    // 0x801CD9F8: nop

    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_0;
    // 0x801CD9F8: nop

    after_0:
    // 0x801CD9FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CDA00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDA04: jr          $ra
    // 0x801CDA08: nop

    return;
    // 0x801CDA08: nop

;}
RECOMP_FUNC void M8_FUN_801cda0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDA0C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801CDA10: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801CDA14: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801CDA18: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801CDA1C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801CDA20: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801CDA24: lw          $t7, 0x1CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1CEC);
    // 0x801CDA28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801CDA2C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x801CDA30: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x801CDA34: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801CDA38: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801CDA3C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801CDA40: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801CDA44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801CDA48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801CDA4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CDA50: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x801CDA54: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x801CDA58: lbu         $t1, 0x96($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X96);
    // 0x801CDA5C: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x801CDA60: lui         $s3, 0x801E
    ctx->r19 = S32(0X801E << 16);
    // 0x801CDA64: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801CDA68: andi        $t8, $t1, 0x2
    ctx->r24 = ctx->r9 & 0X2;
    // 0x801CDA6C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CDA70: addiu       $s3, $s3, 0x4890
    ctx->r19 = ADD32(ctx->r19, 0X4890);
    // 0x801CDA74: addiu       $s0, $s0, 0x4090
    ctx->r16 = ADD32(ctx->r16, 0X4090);
    // 0x801CDA78: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x801CDA7C: addiu       $fp, $zero, 0x30F
    ctx->r30 = ADD32(0, 0X30F);
    // 0x801CDA80: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x801CDA84: beq         $t8, $zero, L_801CDA98
    if (ctx->r24 == 0) {
        // 0x801CDA88: lhu         $t0, 0x2($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X2);
            goto L_801CDA98;
    }
    // 0x801CDA88: lhu         $t0, 0x2($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2);
    // 0x801CDA8C: lui         $fp, 0x8
    ctx->r30 = S32(0X8 << 16);
    // 0x801CDA90: b           L_801CDAAC
    // 0x801CDA94: ori         $fp, $fp, 0x30F
    ctx->r30 = ctx->r30 | 0X30F;
        goto L_801CDAAC;
    // 0x801CDA94: ori         $fp, $fp, 0x30F
    ctx->r30 = ctx->r30 | 0X30F;
L_801CDA98:
    // 0x801CDA98: andi        $t9, $t1, 0x1
    ctx->r25 = ctx->r9 & 0X1;
    // 0x801CDA9C: beql        $t9, $zero, L_801CDAB0
    if (ctx->r25 == 0) {
        // 0x801CDAA0: andi        $t2, $t1, 0x4
        ctx->r10 = ctx->r9 & 0X4;
            goto L_801CDAB0;
    }
    goto skip_0;
    // 0x801CDAA0: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    skip_0:
    // 0x801CDAA4: lui         $fp, 0x6
    ctx->r30 = S32(0X6 << 16);
    // 0x801CDAA8: ori         $fp, $fp, 0x30F
    ctx->r30 = ctx->r30 | 0X30F;
L_801CDAAC:
    // 0x801CDAAC: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
L_801CDAB0:
    // 0x801CDAB0: beq         $t2, $zero, L_801CDACC
    if (ctx->r10 == 0) {
        // 0x801CDAB4: lui         $a3, 0x801E
        ctx->r7 = S32(0X801E << 16);
            goto L_801CDACC;
    }
    // 0x801CDAB4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CDAB8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CDABC: addiu       $a3, $a3, 0xE00
    ctx->r7 = ADD32(ctx->r7, 0XE00);
    // 0x801CDAC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CDAC4: b           L_801CDAD8
    // 0x801CDAC8: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801CDAD8;
    // 0x801CDAC8: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801CDACC:
    // 0x801CDACC: addiu       $a3, $a3, 0xDA0
    ctx->r7 = ADD32(ctx->r7, 0XDA0);
    // 0x801CDAD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CDAD4: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801CDAD8:
    // 0x801CDAD8: lbu         $v0, 0x94($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X94);
    // 0x801CDADC: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x801CDAE0: addiu       $s6, $zero, 0x1000
    ctx->r22 = ADD32(0, 0X1000);
    // 0x801CDAE4: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x801CDAE8: bne         $at, $zero, L_801CDAF8
    if (ctx->r1 != 0) {
        // 0x801CDAEC: addiu       $s5, $zero, 0x40
        ctx->r21 = ADD32(0, 0X40);
            goto L_801CDAF8;
    }
    // 0x801CDAEC: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x801CDAF0: sb          $t3, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r11;
    // 0x801CDAF4: andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
L_801CDAF8:
    // 0x801CDAF8: blez        $v0, L_801CDC2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801CDAFC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801CDC2C;
    }
    // 0x801CDAFC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801CDB00: lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // 0x801CDB04: addiu       $s4, $s4, 0x13AC
    ctx->r20 = ADD32(ctx->r20, 0X13AC);
L_801CDB08:
    // 0x801CDB08: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x801CDB0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CDB10: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801CDB14: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x801CDB18: lwc1        $f6, 0x70($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X70);
    // 0x801CDB1C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x801CDB20: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801CDB24: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x801CDB28: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x801CDB2C: sh          $v1, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r3;
    // 0x801CDB30: sh          $t0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r8;
    // 0x801CDB34: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801CDB38: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x801CDB3C: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x801CDB40: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x801CDB44: sw          $fp, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r30;
    // 0x801CDB48: sw          $t4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r12;
    // 0x801CDB4C: lwc1        $f10, 0x60($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X60);
    // 0x801CDB50: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x801CDB54: lwc1        $f16, 0x64($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X64);
    // 0x801CDB58: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x801CDB5C: lwc1        $f18, 0x68($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X68);
    // 0x801CDB60: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    // 0x801CDB64: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x801CDB68: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x801CDB6C: lw          $t5, 0x4($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X4);
    // 0x801CDB70: sw          $t5, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r13;
    // 0x801CDB74: lw          $t6, 0x8($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X8);
    // 0x801CDB78: sw          $t6, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r14;
    // 0x801CDB7C: lw          $t5, 0xC($s4)
    ctx->r13 = MEM_W(ctx->r20, 0XC);
    // 0x801CDB80: sw          $t5, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r13;
    // 0x801CDB84: lbu         $t7, 0x96($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X96);
    // 0x801CDB88: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x801CDB8C: beql        $t8, $zero, L_801CDBA0
    if (ctx->r24 == 0) {
        // 0x801CDB90: sh          $s6, 0x8($s3)
        MEM_H(0X8, ctx->r19) = ctx->r22;
            goto L_801CDBA0;
    }
    goto skip_1;
    // 0x801CDB90: sh          $s6, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r22;
    skip_1:
    // 0x801CDB94: b           L_801CDBA0
    // 0x801CDB98: sh          $s5, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r21;
        goto L_801CDBA0;
    // 0x801CDB98: sh          $s5, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r21;
    // 0x801CDB9C: sh          $s6, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r22;
L_801CDBA0:
    // 0x801CDBA0: sw          $s0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r16;
    // 0x801CDBA4: sh          $t0, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r8;
    // 0x801CDBA8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801CDBAC: sh          $v1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r3;
    // 0x801CDBB0: jal         0x80146088
    // 0x801CDBB4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x801CDBB4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    after_0:
    // 0x801CDBB8: addu        $s7, $s7, $v0
    ctx->r23 = ADD32(ctx->r23, ctx->r2);
    // 0x801CDBBC: andi        $s7, $s7, 0xFF
    ctx->r23 = ctx->r23 & 0XFF;
    // 0x801CDBC0: lhu         $v1, 0x52($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X52);
    // 0x801CDBC4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x801CDBC8: beq         $s7, $zero, L_801CDC10
    if (ctx->r23 == 0) {
        // 0x801CDBCC: lhu         $t0, 0x50($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X50);
            goto L_801CDC10;
    }
    // 0x801CDBCC: lhu         $t0, 0x50($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X50);
    // 0x801CDBD0: blez        $s2, L_801CDC08
    if (SIGNED(ctx->r18) <= 0) {
        // 0x801CDBD4: nop
    
            goto L_801CDC08;
    }
    // 0x801CDBD4: nop

    // 0x801CDBD8: jal         0x80006214
    // 0x801CDBDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CDBDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CDBE0: blez        $s2, L_801CDC08
    if (SIGNED(ctx->r18) <= 0) {
        // 0x801CDBE4: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_801CDC08;
    }
    // 0x801CDBE4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x801CDBE8: addiu       $s0, $t9, -0x2578
    ctx->r16 = ADD32(ctx->r25, -0X2578);
    // 0x801CDBEC: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x801CDBF0: addu        $s1, $t2, $s0
    ctx->r17 = ADD32(ctx->r10, ctx->r16);
L_801CDBF4:
    // 0x801CDBF4: jal         0x80006088
    // 0x801CDBF8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_2;
    // 0x801CDBF8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x801CDBFC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801CDC00: bne         $s0, $s1, L_801CDBF4
    if (ctx->r16 != ctx->r17) {
        // 0x801CDC04: nop
    
            goto L_801CDBF4;
    }
    // 0x801CDC04: nop

L_801CDC08:
    // 0x801CDC08: b           L_801CDCB4
    // 0x801CDC0C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
        goto L_801CDCB4;
    // 0x801CDC0C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_801CDC10:
    // 0x801CDC10: lbu         $t3, 0x94($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X94);
    // 0x801CDC14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801CDC18: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x801CDC1C: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801CDC20: bne         $at, $zero, L_801CDB08
    if (ctx->r1 != 0) {
        // 0x801CDC24: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_801CDB08;
    }
    // 0x801CDC24: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x801CDC28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_801CDC2C:
    // 0x801CDC2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CDC30: jal         0x80006214
    // 0x801CDC34: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801CDC34: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_3:
    // 0x801CDC38: lbu         $t4, 0x94($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X94);
    // 0x801CDC3C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801CDC40: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x801CDC44: blez        $t4, L_801CDCB0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x801CDC48: addiu       $v1, $v1, -0x2578
        ctx->r3 = ADD32(ctx->r3, -0X2578);
            goto L_801CDCB0;
    }
    // 0x801CDC48: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x801CDC4C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
L_801CDC50:
    // 0x801CDC50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801CDC54: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801CDC58: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801CDC5C: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x801CDC60: lbu         $t6, 0x78($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X78);
    // 0x801CDC64: sb          $t6, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r14;
    // 0x801CDC68: lbu         $t7, 0x79($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X79);
    // 0x801CDC6C: sb          $t7, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r15;
    // 0x801CDC70: lbu         $t8, 0x7A($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X7A);
    // 0x801CDC74: sb          $t8, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r24;
    // 0x801CDC78: lbu         $t2, 0x7B($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X7B);
    // 0x801CDC7C: sb          $t2, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r10;
    // 0x801CDC80: lbu         $t9, 0x80($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X80);
    // 0x801CDC84: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
    // 0x801CDC88: lbu         $t3, 0x81($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X81);
    // 0x801CDC8C: sb          $t3, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r11;
    // 0x801CDC90: lbu         $t4, 0x82($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X82);
    // 0x801CDC94: sb          $t4, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r12;
    // 0x801CDC98: lbu         $t5, 0x83($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X83);
    // 0x801CDC9C: sb          $t5, 0x4F($v0)
    MEM_B(0X4F, ctx->r2) = ctx->r13;
    // 0x801CDCA0: lbu         $t6, 0x94($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X94);
    // 0x801CDCA4: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801CDCA8: bnel        $at, $zero, L_801CDC50
    if (ctx->r1 != 0) {
        // 0x801CDCAC: lw          $t5, 0x0($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X0);
            goto L_801CDC50;
    }
    goto skip_2;
    // 0x801CDCAC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    skip_2:
L_801CDCB0:
    // 0x801CDCB0: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_801CDCB4:
    // 0x801CDCB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801CDCB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CDCBC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801CDCC0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801CDCC4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801CDCC8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801CDCCC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801CDCD0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801CDCD4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x801CDCD8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x801CDCDC: jr          $ra
    // 0x801CDCE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801CDCE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cdce4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cdce4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDCE4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801CDCE8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CDCEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801CDCF0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801CDCF4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801CDCF8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801CDCFC: addiu       $t6, $t6, 0x13BC
    ctx->r14 = ADD32(ctx->r14, 0X13BC);
    // 0x801CDD00: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801CDD04: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x801CDD08: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801CDD0C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801CDD10: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801CDD14: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801CDD18: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CDD1C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x801CDD20: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801CDD24: sw          $t8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r24;
    // 0x801CDD28: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801CDD2C: sw          $t7, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r15;
    // 0x801CDD30: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801CDD34: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x801CDD38: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801CDD3C: sw          $t7, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r15;
    // 0x801CDD40: lbu         $t9, 0x97($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X97);
    // 0x801CDD44: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x801CDD48: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x801CDD4C: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x801CDD50: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x801CDD54: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x801CDD58: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801CDD5C: lw          $t4, 0x1CEC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1CEC);
    // 0x801CDD60: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x801CDD64: lw          $t0, 0x4($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X4);
    // 0x801CDD68: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x801CDD6C: jal         0x801CDA0C
    // 0x801CDD70: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    LOOKUP_FUNC(0x801CDA0C)(rdram, ctx);
        goto after_0;
    // 0x801CDD70: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x801CDD74: beq         $v0, $zero, L_801CDD84
    if (ctx->r2 == 0) {
        // 0x801CDD78: sb          $v0, 0x37($sp)
        MEM_B(0X37, ctx->r29) = ctx->r2;
            goto L_801CDD84;
    }
    // 0x801CDD78: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // 0x801CDD7C: b           L_801CDDE8
    // 0x801CDD80: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_801CDDE8;
    // 0x801CDD80: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_801CDD84:
    // 0x801CDD84: lbu         $t7, 0x97($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X97);
    // 0x801CDD88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801CDD8C: bnel        $t7, $at, L_801CDDE8
    if (ctx->r15 != ctx->r1) {
        // 0x801CDD90: lbu         $v0, 0x37($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X37);
            goto L_801CDDE8;
    }
    goto skip_0;
    // 0x801CDD90: lbu         $v0, 0x37($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X37);
    skip_0:
    // 0x801CDD94: lbu         $t8, 0x94($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X94);
    // 0x801CDD98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CDD9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CDDA0: blezl       $t8, L_801CDDE8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801CDDA4: lbu         $v0, 0x37($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X37);
            goto L_801CDDE8;
    }
    goto skip_1;
    // 0x801CDDA4: lbu         $v0, 0x37($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X37);
    skip_1:
    // 0x801CDDA8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801CDDAC: nop

    // 0x801CDDB0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_801CDDB4:
    // 0x801CDDB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CDDB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801CDDBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CDDC0: addiu       $a1, $zero, 0x371
    ctx->r5 = ADD32(0, 0X371);
    // 0x801CDDC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CDDC8: jal         0x8012D8C8
    // 0x801CDDCC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_1;
    // 0x801CDDCC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_1:
    // 0x801CDDD0: lbu         $t2, 0x94($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X94);
    // 0x801CDDD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CDDD8: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801CDDDC: bnel        $at, $zero, L_801CDDB4
    if (ctx->r1 != 0) {
        // 0x801CDDE0: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_801CDDB4;
    }
    goto skip_2;
    // 0x801CDDE0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_2:
    // 0x801CDDE4: lbu         $v0, 0x37($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X37);
L_801CDDE8:
    // 0x801CDDE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801CDDEC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801CDDF0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801CDDF4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801CDDF8: jr          $ra
    // 0x801CDDFC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801CDDFC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cde00(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cde00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDE00: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801CDE04: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CDE08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CDE0C: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x801CDE10: addiu       $t6, $t6, 0x13E4
    ctx->r14 = ADD32(ctx->r14, 0X13E4);
    // 0x801CDE14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CDE18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CDE1C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801CDE20: addiu       $t1, $t6, 0x24
    ctx->r9 = ADD32(ctx->r14, 0X24);
    // 0x801CDE24: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
L_801CDE28:
    // 0x801CDE28: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801CDE2C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801CDE30: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801CDE34: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801CDE38: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801CDE3C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801CDE40: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801CDE44: bne         $t6, $t1, L_801CDE28
    if (ctx->r14 != ctx->r9) {
        // 0x801CDE48: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801CDE28;
    }
    // 0x801CDE48: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801CDE4C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801CDE50: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CDE54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CDE58: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801CDE5C: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x801CDE60: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x801CDE64: lbu         $v1, 0x97($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X97);
    // 0x801CDE68: addiu       $v1, $v1, -0x6
    ctx->r3 = ADD32(ctx->r3, -0X6);
    // 0x801CDE6C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801CDE70: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x801CDE74: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x801CDE78: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x801CDE7C: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x801CDE80: lhu         $t3, 0x2($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2);
    // 0x801CDE84: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x801CDE88: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801CDE8C: lhu         $t4, 0x4($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4);
    // 0x801CDE90: sh          $a1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r5;
    // 0x801CDE94: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801CDE98: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x801CDE9C: jal         0x801CDA0C
    // 0x801CDEA0: lw          $a2, 0x13D4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X13D4);
    LOOKUP_FUNC(0x801CDA0C)(rdram, ctx);
        goto after_0;
    // 0x801CDEA0: lw          $a2, 0x13D4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X13D4);
    after_0:
    // 0x801CDEA4: beq         $v0, $zero, L_801CDEB4
    if (ctx->r2 == 0) {
        // 0x801CDEA8: andi        $t0, $v0, 0xFF
        ctx->r8 = ctx->r2 & 0XFF;
            goto L_801CDEB4;
    }
    // 0x801CDEA8: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x801CDEAC: b           L_801CDF48
    // 0x801CDEB0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_801CDF48;
    // 0x801CDEB0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_801CDEB4:
    // 0x801CDEB4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801CDEB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CDEBC: lhu         $a2, 0x32($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X32);
    // 0x801CDEC0: lw          $a1, 0x30($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X30);
    // 0x801CDEC4: sb          $t0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r8;
    // 0x801CDEC8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801CDECC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x801CDED0: jal         0x8012CF8C
    // 0x801CDED4: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_1;
    // 0x801CDED4: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    after_1:
    // 0x801CDED8: lbu         $t6, 0x94($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X94);
    // 0x801CDEDC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x801CDEE0: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x801CDEE4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801CDEE8: bne         $at, $zero, L_801CDF44
    if (ctx->r1 != 0) {
        // 0x801CDEEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CDF44;
    }
    // 0x801CDEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CDEF0: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    // 0x801CDEF4: jal         0x80006214
    // 0x801CDEF8: sb          $t0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801CDEF8: sb          $t0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r8;
    after_2:
    // 0x801CDEFC: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
    // 0x801CDF00: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x801CDF04: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x801CDF08: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x801CDF0C: bne         $at, $zero, L_801CDF44
    if (ctx->r1 != 0) {
        // 0x801CDF10: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801CDF44;
    }
    // 0x801CDF10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801CDF14: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801CDF18: addiu       $v0, $v0, -0x2574
    ctx->r2 = ADD32(ctx->r2, -0X2574);
    // 0x801CDF1C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801CDF20:
    // 0x801CDF20: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801CDF24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CDF28: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x801CDF2C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801CDF30: sw          $t7, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r15;
    // 0x801CDF34: lbu         $t3, 0x94($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X94);
    // 0x801CDF38: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801CDF3C: bnel        $at, $zero, L_801CDF20
    if (ctx->r1 != 0) {
        // 0x801CDF40: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801CDF20;
    }
    goto skip_0;
    // 0x801CDF40: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
L_801CDF44:
    // 0x801CDF44: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_801CDF48:
    // 0x801CDF48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CDF4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CDF50: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801CDF54: jr          $ra
    // 0x801CDF58: nop

    return;
    // 0x801CDF58: nop

;}
RECOMP_FUNC void M8_FUN_801cdf5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDF5C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801CDF60: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CDF64: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801CDF68: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x801CDF6C: addiu       $t6, $t6, 0x1410
    ctx->r14 = ADD32(ctx->r14, 0X1410);
    // 0x801CDF70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CDF74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801CDF78: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801CDF7C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801CDF80: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801CDF84: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801CDF88: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801CDF8C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801CDF90: addiu       $t1, $t6, 0x30
    ctx->r9 = ADD32(ctx->r14, 0X30);
    // 0x801CDF94: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
L_801CDF98:
    // 0x801CDF98: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801CDF9C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801CDFA0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801CDFA4: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801CDFA8: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801CDFAC: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801CDFB0: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801CDFB4: bne         $t6, $t1, L_801CDF98
    if (ctx->r14 != ctx->r9) {
        // 0x801CDFB8: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801CDF98;
    }
    // 0x801CDFB8: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801CDFBC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801CDFC0: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CDFC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CDFC8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801CDFCC: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x801CDFD0: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x801CDFD4: lbu         $v1, 0x97($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X97);
    // 0x801CDFD8: addiu       $v1, $v1, -0xD
    ctx->r3 = ADD32(ctx->r3, -0XD);
    // 0x801CDFDC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801CDFE0: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x801CDFE4: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x801CDFE8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x801CDFEC: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x801CDFF0: lhu         $t3, 0x4($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X4);
    // 0x801CDFF4: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x801CDFF8: lhu         $s4, 0x2($v0)
    ctx->r20 = MEM_HU(ctx->r2, 0X2);
    // 0x801CDFFC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801CE000: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x801CE004: lw          $a2, 0x13D4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X13D4);
    // 0x801CE008: jal         0x801CDA0C
    // 0x801CE00C: sh          $a1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CDA0C)(rdram, ctx);
        goto after_0;
    // 0x801CE00C: sh          $a1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CE010: lhu         $a1, 0x56($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X56);
    // 0x801CE014: beq         $v0, $zero, L_801CE024
    if (ctx->r2 == 0) {
        // 0x801CE018: sb          $v0, 0x47($sp)
        MEM_B(0X47, ctx->r29) = ctx->r2;
            goto L_801CE024;
    }
    // 0x801CE018: sb          $v0, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r2;
    // 0x801CE01C: b           L_801CE0C4
    // 0x801CE020: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_801CE0C4;
    // 0x801CE020: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_801CE024:
    // 0x801CE024: lbu         $t5, 0x97($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X97);
    // 0x801CE028: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x801CE02C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801CE030: bne         $t5, $at, L_801CE044
    if (ctx->r13 != ctx->r1) {
        // 0x801CE034: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801CE044;
    }
    // 0x801CE034: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CE038: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801CE03C: b           L_801CE080
    // 0x801CE040: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_801CE080;
    // 0x801CE040: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_801CE044:
    // 0x801CE044: lhu         $t1, 0x90($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X90);
    // 0x801CE048: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801CE04C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CE050: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801CE054: bgez        $t1, L_801CE068
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801CE058: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CE068;
    }
    // 0x801CE058: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CE05C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CE060: nop

    // 0x801CE064: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CE068:
    // 0x801CE068: lui         $at, 0x4038
    ctx->r1 = S32(0X4038 << 16);
    // 0x801CE06C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801CE070: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801CE074: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x801CE078: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801CE07C: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
L_801CE080:
    // 0x801CE080: lbu         $t6, 0x94($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X94);
    // 0x801CE084: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CE088: blezl       $t6, L_801CE0C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CE08C: lbu         $v0, 0x47($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X47);
            goto L_801CE0C4;
    }
    goto skip_0;
    // 0x801CE08C: lbu         $v0, 0x47($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X47);
    skip_0:
    // 0x801CE090: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_801CE094:
    // 0x801CE094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CE098: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801CE09C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x801CE0A0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x801CE0A4: jal         0x8012D8C8
    // 0x801CE0A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_1;
    // 0x801CE0A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_1:
    // 0x801CE0AC: lbu         $t9, 0x94($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X94);
    // 0x801CE0B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CE0B4: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801CE0B8: bnel        $at, $zero, L_801CE094
    if (ctx->r1 != 0) {
        // 0x801CE0BC: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_801CE094;
    }
    goto skip_1;
    // 0x801CE0BC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x801CE0C0: lbu         $v0, 0x47($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X47);
L_801CE0C4:
    // 0x801CE0C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801CE0C8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801CE0CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801CE0D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801CE0D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801CE0D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801CE0DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801CE0E0: jr          $ra
    // 0x801CE0E4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801CE0E4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801ce0e8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801ce0e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE0E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CE0EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CE0F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CE0F4: lbu         $v0, 0x97($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X97);
    // 0x801CE0F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CE0FC: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801CE100: beql        $at, $zero, L_801CE11C
    if (ctx->r1 == 0) {
        // 0x801CE104: slti        $at, $v0, 0xD
        ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
            goto L_801CE11C;
    }
    goto skip_0;
    // 0x801CE104: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    skip_0:
    // 0x801CE108: jal         0x801CDCE4
    // 0x801CE10C: nop

    LOOKUP_FUNC(0x801CDCE4)(rdram, ctx);
        goto after_0;
    // 0x801CE10C: nop

    after_0:
    // 0x801CE110: b           L_801CE140
    // 0x801CE114: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_801CE140;
    // 0x801CE114: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801CE118: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
L_801CE11C:
    // 0x801CE11C: beq         $at, $zero, L_801CE134
    if (ctx->r1 == 0) {
        // 0x801CE120: nop
    
            goto L_801CE134;
    }
    // 0x801CE120: nop

    // 0x801CE124: jal         0x801CDE00
    // 0x801CE128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CDE00)(rdram, ctx);
        goto after_1;
    // 0x801CE128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801CE12C: b           L_801CE140
    // 0x801CE130: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_801CE140;
    // 0x801CE130: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_801CE134:
    // 0x801CE134: jal         0x801CDF5C
    // 0x801CE138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CDF5C)(rdram, ctx);
        goto after_2;
    // 0x801CE138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801CE13C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_801CE140:
    // 0x801CE140: beq         $v0, $zero, L_801CE15C
    if (ctx->r2 == 0) {
        // 0x801CE144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CE15C;
    }
    // 0x801CE144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CE148: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CE14C: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CE150: jal         0x800058DC
    // 0x801CE154: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CE154: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_3:
    // 0x801CE158: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
L_801CE15C:
    // 0x801CE15C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CE164: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CE168: jr          $ra
    // 0x801CE16C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801CE16C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801ce170(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801ce170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE170: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE174: addiu       $v1, $v0, 0x1200
    ctx->r3 = ADD32(ctx->r2, 0X1200);
    // 0x801CE178: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CE17C: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x801CE180: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801CE184: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801CE188: beq         $a2, $t6, L_801CE1BC
    if (ctx->r6 == ctx->r14) {
        // 0x801CE18C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801CE1BC;
    }
    // 0x801CE18C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801CE190: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CE194: addiu       $t7, $t7, 0x1200
    ctx->r15 = ADD32(ctx->r15, 0X1200);
    // 0x801CE198: lbu         $a1, 0x5($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X5);
L_801CE19C:
    // 0x801CE19C: bnel        $v0, $a1, L_801CE1B0
    if (ctx->r2 != ctx->r5) {
        // 0x801CE1A0: lbu         $a1, 0xD($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0XD);
            goto L_801CE1B0;
    }
    goto skip_0;
    // 0x801CE1A0: lbu         $a1, 0xD($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XD);
    skip_0:
    // 0x801CE1A4: jr          $ra
    // 0x801CE1A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801CE1A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801CE1AC: lbu         $a1, 0xD($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XD);
L_801CE1B0:
    // 0x801CE1B0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801CE1B4: bne         $a2, $a1, L_801CE19C
    if (ctx->r6 != ctx->r5) {
        // 0x801CE1B8: nop
    
            goto L_801CE19C;
    }
    // 0x801CE1B8: nop

L_801CE1BC:
    // 0x801CE1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CE1C0: jr          $ra
    // 0x801CE1C4: nop

    return;
    // 0x801CE1C4: nop

;}
RECOMP_FUNC void M8_FUN_801ce1c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE1C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CE1CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE1D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CE1D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CE1D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801CE1DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801CE1E0: jal         0x801CE170
    // 0x801CE1E4: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    LOOKUP_FUNC(0x801CE170)(rdram, ctx);
        goto after_0;
    // 0x801CE1E4: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    after_0:
    // 0x801CE1E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801CE1EC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CE1F0: addiu       $a1, $a1, 0x1398
    ctx->r5 = ADD32(ctx->r5, 0X1398);
    // 0x801CE1F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801CE1F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CE1FC: jal         0x80005670
    // 0x801CE200: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801CE200: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    after_1:
    // 0x801CE204: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801CE208: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801CE20C: beq         $v0, $zero, L_801CE31C
    if (ctx->r2 == 0) {
        // 0x801CE210: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801CE31C;
    }
    // 0x801CE210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801CE214: lhu         $t7, 0x4E($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X4E);
    // 0x801CE218: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801CE21C: sh          $t8, 0x4E($a1)
    MEM_H(0X4E, ctx->r5) = ctx->r24;
    // 0x801CE220: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x801CE224: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x801CE228: sh          $zero, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = 0;
    // 0x801CE22C: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
    // 0x801CE230: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801CE234: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x801CE238: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801CE23C: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
    // 0x801CE240: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801CE244: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x801CE248: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CE24C: swc1        $f10, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f10.u32l;
    // 0x801CE250: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801CE254: swc1        $f16, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f16.u32l;
    // 0x801CE258: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801CE25C: swc1        $f18, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f18.u32l;
    // 0x801CE260: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x801CE264: sb          $t9, 0x78($v0)
    MEM_B(0X78, ctx->r2) = ctx->r25;
    // 0x801CE268: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x801CE26C: sb          $t0, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r8;
    // 0x801CE270: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x801CE274: sb          $t1, 0x7A($v0)
    MEM_B(0X7A, ctx->r2) = ctx->r9;
    // 0x801CE278: lbu         $t2, 0x43($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X43);
    // 0x801CE27C: sb          $t2, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r10;
    // 0x801CE280: lbu         $t3, 0x47($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X47);
    // 0x801CE284: sb          $t3, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r11;
    // 0x801CE288: lbu         $t4, 0x4B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4B);
    // 0x801CE28C: sb          $t4, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r12;
    // 0x801CE290: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x801CE294: sb          $t5, 0x7E($v0)
    MEM_B(0X7E, ctx->r2) = ctx->r13;
    // 0x801CE298: lbu         $t6, 0x53($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X53);
    // 0x801CE29C: sb          $t6, 0x7F($v0)
    MEM_B(0X7F, ctx->r2) = ctx->r14;
    // 0x801CE2A0: lbu         $t7, 0x57($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X57);
    // 0x801CE2A4: sb          $t7, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r15;
    // 0x801CE2A8: lbu         $t8, 0x5B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5B);
    // 0x801CE2AC: sb          $t8, 0x81($v0)
    MEM_B(0X81, ctx->r2) = ctx->r24;
    // 0x801CE2B0: lbu         $t9, 0x5F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X5F);
    // 0x801CE2B4: sb          $t9, 0x82($v0)
    MEM_B(0X82, ctx->r2) = ctx->r25;
    // 0x801CE2B8: lbu         $t0, 0x63($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X63);
    // 0x801CE2BC: sb          $t0, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r8;
    // 0x801CE2C0: lbu         $t1, 0x67($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X67);
    // 0x801CE2C4: sb          $t1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r9;
    // 0x801CE2C8: lbu         $t2, 0x6B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6B);
    // 0x801CE2CC: sb          $t2, 0x85($v0)
    MEM_B(0X85, ctx->r2) = ctx->r10;
    // 0x801CE2D0: lbu         $t3, 0x6F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6F);
    // 0x801CE2D4: sb          $t3, 0x86($v0)
    MEM_B(0X86, ctx->r2) = ctx->r11;
    // 0x801CE2D8: lbu         $t4, 0x73($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X73);
    // 0x801CE2DC: sb          $t4, 0x87($v0)
    MEM_B(0X87, ctx->r2) = ctx->r12;
    // 0x801CE2E0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801CE2E4: sw          $t5, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r13;
    // 0x801CE2E8: lhu         $t6, 0x7A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X7A);
    // 0x801CE2EC: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x801CE2F0: sh          $t6, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r14;
    // 0x801CE2F4: lbu         $t7, 0x77($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X77);
    // 0x801CE2F8: sb          $t7, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r15;
    // 0x801CE2FC: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x801CE300: sb          $t8, 0x95($v0)
    MEM_B(0X95, ctx->r2) = ctx->r24;
    // 0x801CE304: lbu         $t9, 0x8F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X8F);
    // 0x801CE308: sb          $t9, 0x96($v0)
    MEM_B(0X96, ctx->r2) = ctx->r25;
    // 0x801CE30C: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x801CE310: sb          $t0, 0x97($v0)
    MEM_B(0X97, ctx->r2) = ctx->r8;
    // 0x801CE314: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801CE318: swc1        $f4, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f4.u32l;
L_801CE31C:
    // 0x801CE31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CE324: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801CE328: jr          $ra
    // 0x801CE32C: nop

    return;
    // 0x801CE32C: nop

;}
RECOMP_FUNC void M8_FUN_801ce330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE330: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801CE334: lbu         $t6, 0x8F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X8F);
    // 0x801CE338: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801CE33C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801CE340: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801CE344: lbu         $t6, 0xBB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XBB);
    // 0x801CE348: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801CE34C: lbu         $t7, 0x93($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X93);
    // 0x801CE350: lbu         $t8, 0x97($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X97);
    // 0x801CE354: lbu         $t9, 0x9B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X9B);
    // 0x801CE358: lbu         $t0, 0x9F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X9F);
    // 0x801CE35C: lbu         $t1, 0xA3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XA3);
    // 0x801CE360: lbu         $t2, 0xA7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XA7);
    // 0x801CE364: lbu         $t3, 0xAB($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XAB);
    // 0x801CE368: lbu         $t4, 0xAF($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XAF);
    // 0x801CE36C: lhu         $t5, 0xB2($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XB2);
    // 0x801CE370: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CE374: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801CE378: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801CE37C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801CE380: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801CE384: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x801CE388: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801CE38C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801CE390: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x801CE394: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801CE398: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801CE39C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x801CE3A0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x801CE3A4: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x801CE3A8: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x801CE3AC: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x801CE3B0: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x801CE3B4: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x801CE3B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801CE3BC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801CE3C0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801CE3C4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801CE3C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801CE3CC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801CE3D0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801CE3D4: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801CE3D8: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x801CE3DC: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x801CE3E0: jal         0x801CE1C8
    // 0x801CE3E4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CE1C8)(rdram, ctx);
        goto after_0;
    // 0x801CE3E4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801CE3E8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x801CE3EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801CE3F0: jr          $ra
    // 0x801CE3F4: nop

    return;
    // 0x801CE3F4: nop

;}
RECOMP_FUNC void M8_FUN_801ce3f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE3F8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801CE3FC: lbu         $t6, 0x8F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X8F);
    // 0x801CE400: lbu         $t7, 0x93($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X93);
    // 0x801CE404: lbu         $t8, 0x97($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X97);
    // 0x801CE408: lbu         $t9, 0x9B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X9B);
    // 0x801CE40C: lbu         $t0, 0x9B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X9B);
    // 0x801CE410: lbu         $t1, 0x9F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X9F);
    // 0x801CE414: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801CE418: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801CE41C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801CE420: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801CE424: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801CE428: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801CE42C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801CE430: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801CE434: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801CE438: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x801CE43C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x801CE440: lbu         $t1, 0xBB($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XBB);
    // 0x801CE444: lhu         $t0, 0xB2($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XB2);
    // 0x801CE448: lbu         $t9, 0xA3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XA3);
    // 0x801CE44C: lbu         $t8, 0xAF($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAF);
    // 0x801CE450: lbu         $t7, 0xAB($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAB);
    // 0x801CE454: lbu         $t6, 0xA7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XA7);
    // 0x801CE458: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801CE45C: lbu         $t2, 0xA3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XA3);
    // 0x801CE460: lbu         $t3, 0xA7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XA7);
    // 0x801CE464: lbu         $t4, 0xAB($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XAB);
    // 0x801CE468: lbu         $t5, 0x9F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X9F);
    // 0x801CE46C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CE470: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801CE474: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801CE478: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801CE47C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801CE480: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x801CE484: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x801CE488: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x801CE48C: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x801CE490: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x801CE494: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x801CE498: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x801CE49C: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x801CE4A0: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x801CE4A4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x801CE4A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801CE4AC: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801CE4B0: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x801CE4B4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x801CE4B8: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x801CE4BC: jal         0x801CE1C8
    // 0x801CE4C0: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CE1C8)(rdram, ctx);
        goto after_0;
    // 0x801CE4C0: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801CE4C4: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x801CE4C8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801CE4CC: jr          $ra
    // 0x801CE4D0: nop

    return;
    // 0x801CE4D0: nop

;}
