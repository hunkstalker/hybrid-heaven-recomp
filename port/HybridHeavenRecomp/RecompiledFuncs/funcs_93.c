#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_80216558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80216558: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8021655C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80216560: lw          $a1, 0x2C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X2C);
    // 0x80216564: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80216568: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8021656C: lwc1        $f14, 0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80216570: jal         0x8014BC78
    // 0x80216574: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    LOOKUP_FUNC(0x8014BC78)(rdram, ctx);
        goto after_0;
    // 0x80216574: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    after_0:
    // 0x80216578: beq         $v0, $zero, L_802167A0
    if (ctx->r2 == 0) {
        // 0x8021657C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_802167A0;
    }
    // 0x8021657C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80216580: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80216584: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80216588: sh          $v1, 0x244($v0)
    MEM_H(0X244, ctx->r2) = ctx->r3;
    // 0x8021658C: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80216590: jal         0x8014B3F0
    // 0x80216594: sh          $v1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8014B3F0)(rdram, ctx);
        goto after_1;
    // 0x80216594: sh          $v1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r3;
    after_1:
    // 0x80216598: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x8021659C: beq         $t7, $zero, L_80216998
    if (ctx->r15 == 0) {
        // 0x802165A0: sb          $v0, 0x39($sp)
        MEM_B(0X39, ctx->r29) = ctx->r2;
            goto L_80216998;
    }
    // 0x802165A0: sb          $v0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r2;
    // 0x802165A4: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    // 0x802165A8: jal         0x8014B4A0
    // 0x802165AC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_2;
    // 0x802165AC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x802165B0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x802165B4: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x802165B8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x802165BC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x802165C0: lw          $a1, 0x2C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X2C);
    // 0x802165C4: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x802165C8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x802165CC: nop

    // 0x802165D0: bc1fl       L_802165FC
    if (!c1cs) {
        // 0x802165D4: sub.s       $f18, $f0, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_802165FC;
    }
    goto skip_0;
    // 0x802165D4: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    skip_0:
    // 0x802165D8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x802165DC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x802165E0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x802165E4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x802165E8: nop

    // 0x802165EC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x802165F0: b           L_80216610
    // 0x802165F4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80216610;
    // 0x802165F4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x802165F8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
L_802165FC:
    // 0x802165FC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80216600: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80216604: nop

    // 0x80216608: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8021660C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80216610:
    // 0x80216610: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80216614: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80216618: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8021661C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80216620: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80216624: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80216628: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8021662C: nop

    // 0x80216630: bc1fl       L_8021699C
    if (!c1cs) {
        // 0x80216634: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021699C;
    }
    goto skip_1;
    // 0x80216634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80216638: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8021663C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80216640: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80216644: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80216648: jal         0x8001EF38
    // 0x8021664C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x8021664C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x80216650: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80216654: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x80216658: addiu       $t2, $zero, 0x1800
    ctx->r10 = ADD32(0, 0X1800);
    // 0x8021665C: subu        $t0, $t2, $v0
    ctx->r8 = SUB32(ctx->r10, ctx->r2);
    // 0x80216660: lw          $a1, 0x2C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X2C);
    // 0x80216664: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80216668: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8021666C: lh          $t4, 0x12($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X12);
    // 0x80216670: andi        $t0, $t0, 0x1FFF
    ctx->r8 = ctx->r8 & 0X1FFF;
    // 0x80216674: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80216678: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x8021667C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80216680: sh          $t5, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r13;
    // 0x80216684: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    // 0x80216688: jal         0x8014C068
    // 0x8021668C: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    LOOKUP_FUNC(0x8014C068)(rdram, ctx);
        goto after_4;
    // 0x8021668C: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    after_4:
    // 0x80216690: beq         $v0, $zero, L_80216768
    if (ctx->r2 == 0) {
        // 0x80216694: lh          $t0, 0x3E($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X3E);
            goto L_80216768;
    }
    // 0x80216694: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x80216698: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    // 0x8021669C: jal         0x8014C0A8
    // 0x802166A0: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8014C0A8)(rdram, ctx);
        goto after_5;
    // 0x802166A0: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    after_5:
    // 0x802166A4: bne         $v0, $zero, L_80216998
    if (ctx->r2 != 0) {
        // 0x802166A8: lh          $t0, 0x3E($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X3E);
            goto L_80216998;
    }
    // 0x802166A8: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x802166AC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802166B0: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x802166B4: lw          $a1, 0x2C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X2C);
    // 0x802166B8: lh          $t7, 0x12($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X12);
    // 0x802166BC: subu        $v1, $t7, $t0
    ctx->r3 = SUB32(ctx->r15, ctx->r8);
    // 0x802166C0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802166C4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802166C8: andi        $a2, $v1, 0x1000
    ctx->r6 = ctx->r3 & 0X1000;
    // 0x802166CC: beq         $a2, $zero, L_802166E0
    if (ctx->r6 == 0) {
        // 0x802166D0: andi        $v0, $v1, 0x1FFF
        ctx->r2 = ctx->r3 & 0X1FFF;
            goto L_802166E0;
    }
    // 0x802166D0: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x802166D4: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x802166D8: b           L_802166E4
    // 0x802166DC: addiu       $a0, $v0, -0x2000
    ctx->r4 = ADD32(ctx->r2, -0X2000);
        goto L_802166E4;
    // 0x802166DC: addiu       $a0, $v0, -0x2000
    ctx->r4 = ADD32(ctx->r2, -0X2000);
L_802166E0:
    // 0x802166E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_802166E4:
    // 0x802166E4: bgez        $a0, L_80216718
    if (SIGNED(ctx->r4) >= 0) {
        // 0x802166E8: nop
    
            goto L_80216718;
    }
    // 0x802166E8: nop

    // 0x802166EC: beq         $a2, $zero, L_80216708
    if (ctx->r6 == 0) {
        // 0x802166F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80216708;
    }
    // 0x802166F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x802166F4: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
    // 0x802166F8: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x802166FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80216700: b           L_80216730
    // 0x80216704: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80216730;
    // 0x80216704: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80216708:
    // 0x80216708: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8021670C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80216710: b           L_80216730
    // 0x80216714: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80216730;
    // 0x80216714: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80216718:
    // 0x80216718: beq         $a2, $zero, L_80216728
    if (ctx->r6 == 0) {
        // 0x8021671C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80216728;
    }
    // 0x8021671C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80216720: b           L_80216728
    // 0x80216724: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_80216728;
    // 0x80216724: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_80216728:
    // 0x80216728: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8021672C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80216730:
    // 0x80216730: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    // 0x80216734: beql        $at, $zero, L_8021699C
    if (ctx->r1 == 0) {
        // 0x80216738: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021699C;
    }
    goto skip_2;
    // 0x80216738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8021673C: sh          $t0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r8;
    // 0x80216740: jal         0x8014C1F0
    // 0x80216744: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    LOOKUP_FUNC(0x8014C1F0)(rdram, ctx);
        goto after_6;
    // 0x80216744: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    after_6:
    // 0x80216748: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8021674C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80216750: bne         $t8, $at, L_80216760
    if (ctx->r24 != ctx->r1) {
        // 0x80216754: nop
    
            goto L_80216760;
    }
    // 0x80216754: nop

    // 0x80216758: b           L_8021699C
    // 0x8021675C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8021699C;
    // 0x8021675C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80216760:
    // 0x80216760: b           L_8021699C
    // 0x80216764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8021699C;
    // 0x80216764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80216768:
    // 0x80216768: lbu         $a0, 0x39($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X39);
    // 0x8021676C: jal         0x8013D4A0
    // 0x80216770: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_7;
    // 0x80216770: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    after_7:
    // 0x80216774: slti        $at, $v0, 0x63
    ctx->r1 = SIGNED(ctx->r2) < 0X63 ? 1 : 0;
    // 0x80216778: beq         $at, $zero, L_80216798
    if (ctx->r1 == 0) {
        // 0x8021677C: lh          $t0, 0x3E($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X3E);
            goto L_80216798;
    }
    // 0x8021677C: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x80216780: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80216784: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x80216788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8021678C: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x80216790: b           L_8021699C
    // 0x80216794: sh          $t0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r8;
        goto L_8021699C;
    // 0x80216794: sh          $t0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r8;
L_80216798:
    // 0x80216798: b           L_8021699C
    // 0x8021679C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8021699C;
    // 0x8021679C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802167A0:
    // 0x802167A0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x802167A4: lw          $t2, -0x4330($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4330);
    // 0x802167A8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x802167AC: lw          $a1, 0x2C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X2C);
    // 0x802167B0: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x802167B4: lwc1        $f14, 0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X8);
    // 0x802167B8: jal         0x8014BC78
    // 0x802167BC: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    LOOKUP_FUNC(0x8014BC78)(rdram, ctx);
        goto after_8;
    // 0x802167BC: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    after_8:
    // 0x802167C0: beq         $v0, $zero, L_80216998
    if (ctx->r2 == 0) {
        // 0x802167C4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80216998;
    }
    // 0x802167C4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x802167C8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802167CC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x802167D0: sh          $v1, 0x244($v0)
    MEM_H(0X244, ctx->r2) = ctx->r3;
    // 0x802167D4: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x802167D8: jal         0x8014B3F0
    // 0x802167DC: sh          $v1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8014B3F0)(rdram, ctx);
        goto after_9;
    // 0x802167DC: sh          $v1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r3;
    after_9:
    // 0x802167E0: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x802167E4: beql        $t4, $zero, L_8021699C
    if (ctx->r12 == 0) {
        // 0x802167E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021699C;
    }
    goto skip_3;
    // 0x802167E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x802167EC: jal         0x8014C068
    // 0x802167F0: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    LOOKUP_FUNC(0x8014C068)(rdram, ctx);
        goto after_10;
    // 0x802167F0: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    after_10:
    // 0x802167F4: beql        $v0, $zero, L_8021699C
    if (ctx->r2 == 0) {
        // 0x802167F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021699C;
    }
    goto skip_4;
    // 0x802167F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x802167FC: jal         0x8014C1F0
    // 0x80216800: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    LOOKUP_FUNC(0x8014C1F0)(rdram, ctx);
        goto after_11;
    // 0x80216800: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    after_11:
    // 0x80216804: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x80216808: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021680C: bnel        $t5, $at, L_8021699C
    if (ctx->r13 != ctx->r1) {
        // 0x80216810: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021699C;
    }
    goto skip_5;
    // 0x80216810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80216814: jal         0x8014C0A8
    // 0x80216818: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    LOOKUP_FUNC(0x8014C0A8)(rdram, ctx);
        goto after_12;
    // 0x80216818: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    after_12:
    // 0x8021681C: bne         $v0, $zero, L_80216998
    if (ctx->r2 != 0) {
        // 0x80216820: lhu         $a0, 0x56($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0X56);
            goto L_80216998;
    }
    // 0x80216820: lhu         $a0, 0x56($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X56);
    // 0x80216824: jal         0x8014B4A0
    // 0x80216828: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_13;
    // 0x80216828: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_13:
    // 0x8021682C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80216830: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x80216834: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80216838: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8021683C: lw          $a1, 0x2C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X2C);
    // 0x80216840: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80216844: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80216848: nop

    // 0x8021684C: bc1fl       L_80216878
    if (!c1cs) {
        // 0x80216850: sub.s       $f6, $f0, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80216878;
    }
    goto skip_6;
    // 0x80216850: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    skip_6:
    // 0x80216854: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80216858: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8021685C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80216860: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80216864: nop

    // 0x80216868: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8021686C: b           L_8021688C
    // 0x80216870: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8021688C;
    // 0x80216870: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80216874: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
L_80216878:
    // 0x80216878: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8021687C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80216880: nop

    // 0x80216884: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80216888: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8021688C:
    // 0x8021688C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80216890: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80216894: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80216898: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x8021689C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x802168A0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x802168A4: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x802168A8: nop

    // 0x802168AC: bc1fl       L_8021699C
    if (!c1cs) {
        // 0x802168B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021699C;
    }
    goto skip_7;
    // 0x802168B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x802168B4: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x802168B8: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x802168BC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x802168C0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x802168C4: jal         0x8001EF38
    // 0x802168C8: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_14;
    // 0x802168C8: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_14:
    // 0x802168CC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x802168D0: lw          $t1, -0x4330($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4330);
    // 0x802168D4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x802168D8: addiu       $t9, $zero, 0x1800
    ctx->r25 = ADD32(0, 0X1800);
    // 0x802168DC: lw          $a1, 0x2C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X2C);
    // 0x802168E0: subu        $v1, $t9, $v0
    ctx->r3 = SUB32(ctx->r25, ctx->r2);
    // 0x802168E4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802168E8: lh          $t2, 0x12($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X12);
    // 0x802168EC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802168F0: andi        $t7, $v1, 0x1FFF
    ctx->r15 = ctx->r3 & 0X1FFF;
    // 0x802168F4: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x802168F8: sh          $t3, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r11;
    // 0x802168FC: lw          $t4, -0x4330($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4330);
    // 0x80216900: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x80216904: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80216908: lw          $a1, 0x2C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X2C);
    // 0x8021690C: lh          $t5, 0x12($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X12);
    // 0x80216910: subu        $a2, $t5, $t7
    ctx->r6 = SUB32(ctx->r13, ctx->r15);
    // 0x80216914: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80216918: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8021691C: andi        $a3, $a2, 0x1000
    ctx->r7 = ctx->r6 & 0X1000;
    // 0x80216920: beq         $a3, $zero, L_80216934
    if (ctx->r7 == 0) {
        // 0x80216924: andi        $v0, $a2, 0x1FFF
        ctx->r2 = ctx->r6 & 0X1FFF;
            goto L_80216934;
    }
    // 0x80216924: andi        $v0, $a2, 0x1FFF
    ctx->r2 = ctx->r6 & 0X1FFF;
    // 0x80216928: andi        $v0, $a2, 0x1FFF
    ctx->r2 = ctx->r6 & 0X1FFF;
    // 0x8021692C: b           L_80216938
    // 0x80216930: addiu       $a0, $v0, -0x2000
    ctx->r4 = ADD32(ctx->r2, -0X2000);
        goto L_80216938;
    // 0x80216930: addiu       $a0, $v0, -0x2000
    ctx->r4 = ADD32(ctx->r2, -0X2000);
L_80216934:
    // 0x80216934: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80216938:
    // 0x80216938: bgez        $a0, L_8021696C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8021693C: nop
    
            goto L_8021696C;
    }
    // 0x8021693C: nop

    // 0x80216940: beq         $a3, $zero, L_8021695C
    if (ctx->r7 == 0) {
        // 0x80216944: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021695C;
    }
    // 0x80216944: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80216948: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
    // 0x8021694C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80216950: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80216954: b           L_80216984
    // 0x80216958: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80216984;
    // 0x80216958: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8021695C:
    // 0x8021695C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80216960: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80216964: b           L_80216984
    // 0x80216968: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80216984;
    // 0x80216968: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8021696C:
    // 0x8021696C: beq         $a3, $zero, L_8021697C
    if (ctx->r7 == 0) {
        // 0x80216970: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021697C;
    }
    // 0x80216970: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80216974: b           L_8021697C
    // 0x80216978: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_8021697C;
    // 0x80216978: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_8021697C:
    // 0x8021697C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80216980: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80216984:
    // 0x80216984: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    // 0x80216988: beq         $at, $zero, L_80216998
    if (ctx->r1 == 0) {
        // 0x8021698C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80216998;
    }
    // 0x8021698C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80216990: b           L_8021699C
    // 0x80216994: sh          $t0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r8;
        goto L_8021699C;
    // 0x80216994: sh          $t0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r8;
L_80216998:
    // 0x80216998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8021699C:
    // 0x8021699C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802169A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x802169A4: jr          $ra
    // 0x802169A8: nop

    return;
    // 0x802169A8: nop

;}
RECOMP_FUNC void M9_FUN_802169ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802169AC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x802169B0: lhu         $v1, 0x92($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X92);
    // 0x802169B4: lh          $t7, 0x7E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X7E);
    // 0x802169B8: lh          $t8, 0x82($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X82);
    // 0x802169BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x802169C0: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x802169C4: lh          $t6, 0x7A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7A);
    // 0x802169C8: lbu         $t2, 0x8F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X8F);
    // 0x802169CC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x802169D0: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x802169D4: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x802169D8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x802169DC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x802169E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x802169E4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x802169E8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x802169EC: ori         $t3, $a2, 0x4
    ctx->r11 = ctx->r6 | 0X4;
    // 0x802169F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802169F4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x802169F8: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x802169FC: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80216A00: sh          $a3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r7;
    // 0x80216A04: sb          $t1, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r9;
    // 0x80216A08: sb          $t0, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r8;
    // 0x80216A0C: sb          $t9, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r25;
    // 0x80216A10: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x80216A14: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x80216A18: sh          $t7, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r15;
    // 0x80216A1C: sh          $t7, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r15;
    // 0x80216A20: sh          $t8, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r24;
    // 0x80216A24: sh          $t8, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r24;
    // 0x80216A28: sh          $t6, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r14;
    // 0x80216A2C: sb          $t2, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r10;
    // 0x80216A30: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80216A34: lhu         $t0, 0x96($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X96);
    // 0x80216A38: addiu       $at, $zero, 0x209
    ctx->r1 = ADD32(0, 0X209);
    // 0x80216A3C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80216A40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80216A44: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80216A48: sh          $t6, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r14;
    // 0x80216A4C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80216A50: lhu         $v0, 0x96($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X96);
    // 0x80216A54: addiu       $a1, $a1, 0x1A84
    ctx->r5 = ADD32(ctx->r5, 0X1A84);
    // 0x80216A58: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80216A5C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80216A60: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80216A64: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
    // 0x80216A68: bne         $v1, $at, L_80216AC8
    if (ctx->r3 != ctx->r1) {
        // 0x80216A6C: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_80216AC8;
    }
    // 0x80216A6C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80216A70: beq         $v0, $zero, L_80216AA8
    if (ctx->r2 == 0) {
        // 0x80216A74: addiu       $t6, $zero, 0x20
        ctx->r14 = ADD32(0, 0X20);
            goto L_80216AA8;
    }
    // 0x80216A74: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80216A78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80216A7C: beq         $v0, $at, L_80216A98
    if (ctx->r2 == ctx->r1) {
        // 0x80216A80: addiu       $t4, $zero, 0x20
        ctx->r12 = ADD32(0, 0X20);
            goto L_80216A98;
    }
    // 0x80216A80: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80216A84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80216A88: beq         $v0, $at, L_80216AB8
    if (ctx->r2 == ctx->r1) {
        // 0x80216A8C: addiu       $t9, $zero, 0x58
        ctx->r25 = ADD32(0, 0X58);
            goto L_80216AB8;
    }
    // 0x80216A8C: addiu       $t9, $zero, 0x58
    ctx->r25 = ADD32(0, 0X58);
    // 0x80216A90: b           L_80216B2C
    // 0x80216A94: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
        goto L_80216B2C;
    // 0x80216A94: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
L_80216A98:
    // 0x80216A98: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80216A9C: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
    // 0x80216AA0: b           L_80216B28
    // 0x80216AA4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
        goto L_80216B28;
    // 0x80216AA4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
L_80216AA8:
    // 0x80216AA8: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80216AAC: sh          $t0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r8;
    // 0x80216AB0: b           L_80216B28
    // 0x80216AB4: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
        goto L_80216B28;
    // 0x80216AB4: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
L_80216AB8:
    // 0x80216AB8: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80216ABC: sh          $t1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r9;
    // 0x80216AC0: b           L_80216B28
    // 0x80216AC4: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
        goto L_80216B28;
    // 0x80216AC4: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
L_80216AC8:
    // 0x80216AC8: addiu       $at, $zero, 0x21C
    ctx->r1 = ADD32(0, 0X21C);
    // 0x80216ACC: bne         $v1, $at, L_80216B10
    if (ctx->r3 != ctx->r1) {
        // 0x80216AD0: lhu         $v0, 0x96($sp)
        ctx->r2 = MEM_HU(ctx->r29, 0X96);
            goto L_80216B10;
    }
    // 0x80216AD0: lhu         $v0, 0x96($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X96);
    // 0x80216AD4: beq         $v0, $zero, L_80216AF0
    if (ctx->r2 == 0) {
        // 0x80216AD8: addiu       $t2, $zero, 0x20
        ctx->r10 = ADD32(0, 0X20);
            goto L_80216AF0;
    }
    // 0x80216AD8: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80216ADC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80216AE0: beq         $v0, $at, L_80216B00
    if (ctx->r2 == ctx->r1) {
        // 0x80216AE4: addiu       $t7, $zero, 0x38
        ctx->r15 = ADD32(0, 0X38);
            goto L_80216B00;
    }
    // 0x80216AE4: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x80216AE8: b           L_80216B2C
    // 0x80216AEC: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
        goto L_80216B2C;
    // 0x80216AEC: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
L_80216AF0:
    // 0x80216AF0: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80216AF4: sh          $t3, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r11;
    // 0x80216AF8: b           L_80216B28
    // 0x80216AFC: sh          $t2, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r10;
        goto L_80216B28;
    // 0x80216AFC: sh          $t2, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r10;
L_80216B00:
    // 0x80216B00: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80216B04: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
    // 0x80216B08: b           L_80216B28
    // 0x80216B0C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
        goto L_80216B28;
    // 0x80216B0C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
L_80216B10:
    // 0x80216B10: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x80216B14: bne         $v1, $at, L_80216B28
    if (ctx->r3 != ctx->r1) {
        // 0x80216B18: addiu       $t4, $zero, 0x10
        ctx->r12 = ADD32(0, 0X10);
            goto L_80216B28;
    }
    // 0x80216B18: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80216B1C: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80216B20: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
    // 0x80216B24: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
L_80216B28:
    // 0x80216B28: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
L_80216B2C:
    // 0x80216B2C: lhu         $t0, 0x8A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X8A);
    // 0x80216B30: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x80216B34: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x80216B38: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80216B3C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80216B40: sh          $t6, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r14;
    // 0x80216B44: jal         0x80146088
    // 0x80216B48: sh          $t0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x80216B48: sh          $t0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r8;
    after_0:
    // 0x80216B4C: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x80216B50: jal         0x80006214
    // 0x80216B54: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80216B54: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80216B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80216B5C: lbu         $v0, 0x2B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2B);
    // 0x80216B60: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80216B64: jr          $ra
    // 0x80216B68: nop

    return;
    // 0x80216B68: nop

;}
RECOMP_FUNC void M10_FUN_8021b150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B150: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021B154: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x8021B158: lbu         $t6, 0x16($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X16);
    // 0x8021B15C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8021B160: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8021B164: bne         $t6, $zero, L_8021B18C
    if (ctx->r14 != 0) {
        // 0x8021B168: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8021B18C;
    }
    // 0x8021B168: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021B16C: lbu         $v0, -0x33DF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33DF);
    // 0x8021B170: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021B174: beq         $v0, $at, L_8021B18C
    if (ctx->r2 == ctx->r1) {
        // 0x8021B178: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8021B18C;
    }
    // 0x8021B178: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8021B17C: beq         $v0, $at, L_8021B18C
    if (ctx->r2 == ctx->r1) {
        // 0x8021B180: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8021B18C;
    }
    // 0x8021B180: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8021B184: bne         $v0, $at, L_8021B1A0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B188: nop
    
            goto L_8021B1A0;
    }
    // 0x8021B188: nop

L_8021B18C:
    // 0x8021B18C: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x8021B190: sltiu       $at, $v0, -0x1
    ctx->r1 = ctx->r2 < -0X1 ? 1 : 0;
    // 0x8021B194: beq         $at, $zero, L_8021B1A0
    if (ctx->r1 == 0) {
        // 0x8021B198: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8021B1A0;
    }
    // 0x8021B198: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8021B19C: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
L_8021B1A0:
    // 0x8021B1A0: jr          $ra
    // 0x8021B1A4: nop

    return;
    // 0x8021B1A4: nop

;}
RECOMP_FUNC void M10_FUN_8021b1a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B1A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021B1AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021B1B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021B1B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021B1B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021B1BC: jal         0x80031190
    // 0x8021B1C0: sb          $zero, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = 0;
    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_0;
    // 0x8021B1C0: sb          $zero, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = 0;
    after_0:
    // 0x8021B1C4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8021B1C8: sw          $v0, 0x758($at)
    MEM_W(0X758, ctx->r1) = ctx->r2;
    // 0x8021B1CC: sw          $v1, 0x75C($at)
    MEM_W(0X75C, ctx->r1) = ctx->r3;
    // 0x8021B1D0: jal         0x80126930
    // 0x8021B1D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80126930)(rdram, ctx);
        goto after_1;
    // 0x8021B1D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8021B1D8: jal         0x80020718
    // 0x8021B1DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x8021B1DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x8021B1E0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021B1E4: addiu       $a1, $a1, -0x4E00
    ctx->r5 = ADD32(ctx->r5, -0X4E00);
    // 0x8021B1E8: jal         0x800058DC
    // 0x8021B1EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021B1EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8021B1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021B1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021B1F8: jr          $ra
    // 0x8021B1FC: nop

    return;
    // 0x8021B1FC: nop

;}
RECOMP_FUNC void M10_FUN_8021b200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021B204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021B208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021B20C: jal         0x800172F4
    // 0x8021B210: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800172F4)(rdram, ctx);
        goto after_0;
    // 0x8021B210: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021B214: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x8021B218: jal         0x80016E40
    // 0x8021B21C: ori         $a0, $a0, 0x6FC0
    ctx->r4 = ctx->r4 | 0X6FC0;
    LOOKUP_FUNC(0x80016E40)(rdram, ctx);
        goto after_1;
    // 0x8021B21C: ori         $a0, $a0, 0x6FC0
    ctx->r4 = ctx->r4 | 0X6FC0;
    after_1:
    // 0x8021B220: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021B224: addiu       $a1, $a1, -0x4DC0
    ctx->r5 = ADD32(ctx->r5, -0X4DC0);
    // 0x8021B228: jal         0x800058DC
    // 0x8021B22C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8021B22C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8021B230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021B234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021B238: jr          $ra
    // 0x8021B23C: nop

    return;
    // 0x8021B23C: nop

;}
RECOMP_FUNC void M10_FUN_8021b240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021B244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021B248: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021B24C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021B250: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x8021B254: jal         0x80126A0C
    // 0x8021B258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x8021B258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8021B25C: beq         $v0, $zero, L_8021B270
    if (ctx->r2 == 0) {
        // 0x8021B260: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021B270;
    }
    // 0x8021B260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021B264: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021B268: jal         0x800058DC
    // 0x8021B26C: addiu       $a1, $a1, -0x4D80
    ctx->r5 = ADD32(ctx->r5, -0X4D80);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8021B26C: addiu       $a1, $a1, -0x4D80
    ctx->r5 = ADD32(ctx->r5, -0X4D80);
    after_1:
L_8021B270:
    // 0x8021B270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021B274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021B278: jr          $ra
    // 0x8021B27C: nop

    return;
    // 0x8021B27C: nop

;}
RECOMP_FUNC void M10_FUN_8021b280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021B284: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021B288: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8021B28C: addiu       $a1, $a1, -0x2284
    ctx->r5 = ADD32(ctx->r5, -0X2284);
    // 0x8021B290: lbu         $v0, 0x16($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X16);
    // 0x8021B294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021B298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021B29C: beq         $v0, $zero, L_8021B30C
    if (ctx->r2 == 0) {
        // 0x8021B2A0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8021B30C;
    }
    // 0x8021B2A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B2A4: bne         $v0, $at, L_8021B2B4
    if (ctx->r2 != ctx->r1) {
        // 0x8021B2A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021B2B4;
    }
    // 0x8021B2A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021B2AC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8021B2B0: sh          $t6, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r14;
L_8021B2B4:
    // 0x8021B2B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021B2B8: bnel        $v1, $at, L_8021B2DC
    if (ctx->r3 != ctx->r1) {
        // 0x8021B2BC: lbu         $t8, 0x22($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X22);
            goto L_8021B2DC;
    }
    goto skip_0;
    // 0x8021B2BC: lbu         $t8, 0x22($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X22);
    skip_0:
    // 0x8021B2C0: jal         0x80152890
    // 0x8021B2C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80152890)(rdram, ctx);
        goto after_0;
    // 0x8021B2C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8021B2C8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8021B2CC: addiu       $a1, $a1, -0x2284
    ctx->r5 = ADD32(ctx->r5, -0X2284);
    // 0x8021B2D0: addiu       $t7, $v0, -0x2
    ctx->r15 = ADD32(ctx->r2, -0X2);
    // 0x8021B2D4: sh          $t7, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r15;
    // 0x8021B2D8: lbu         $t8, 0x22($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X22);
L_8021B2DC:
    // 0x8021B2DC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021B2E0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021B2E4: bne         $t8, $zero, L_8021B304
    if (ctx->r24 != 0) {
        // 0x8021B2E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021B304;
    }
    // 0x8021B2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8021B2EC:
    // 0x8021B2EC: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x8021B2F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8021B2F4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8021B2F8: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x8021B2FC: bne         $at, $zero, L_8021B2EC
    if (ctx->r1 != 0) {
        // 0x8021B300: sb          $zero, 0x784($t9)
        MEM_B(0X784, ctx->r25) = 0;
            goto L_8021B2EC;
    }
    // 0x8021B300: sb          $zero, 0x784($t9)
    MEM_B(0X784, ctx->r25) = 0;
L_8021B304:
    // 0x8021B304: b           L_8021B310
    // 0x8021B308: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8021B310;
    // 0x8021B308: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8021B30C:
    // 0x8021B30C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8021B310:
    // 0x8021B310: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021B314: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    // 0x8021B318: sb          $zero, 0xAE($t0)
    MEM_B(0XAE, ctx->r8) = 0;
    // 0x8021B31C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8021B320: sb          $zero, 0xB2($t1)
    MEM_B(0XB2, ctx->r9) = 0;
    // 0x8021B324: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8021B328: jal         0x8022C7A4
    // 0x8021B32C: sb          $zero, 0x90($t2)
    MEM_B(0X90, ctx->r10) = 0;
    LOOKUP_FUNC(0x8022C7A4)(rdram, ctx);
        goto after_1;
    // 0x8021B32C: sb          $zero, 0x90($t2)
    MEM_B(0X90, ctx->r10) = 0;
    after_1:
    // 0x8021B330: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8021B334: addiu       $a1, $a1, -0x2284
    ctx->r5 = ADD32(ctx->r5, -0X2284);
    // 0x8021B338: lbu         $t3, 0x22($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X22);
    // 0x8021B33C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021B340: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021B344: bne         $t3, $zero, L_8021B360
    if (ctx->r11 != 0) {
        // 0x8021B348: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_8021B360;
    }
    // 0x8021B348: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021B34C: lbu         $t4, 0x16($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X16);
    // 0x8021B350: beql        $t4, $zero, L_8021B364
    if (ctx->r12 == 0) {
        // 0x8021B354: lbu         $t6, 0x47C($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X47C);
            goto L_8021B364;
    }
    goto skip_1;
    // 0x8021B354: lbu         $t6, 0x47C($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X47C);
    skip_1:
    // 0x8021B358: lh          $t5, 0x44C($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X44C);
    // 0x8021B35C: sh          $t5, 0x44E($a2)
    MEM_H(0X44E, ctx->r6) = ctx->r13;
L_8021B360:
    // 0x8021B360: lbu         $t6, 0x47C($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X47C);
L_8021B364:
    // 0x8021B364: lbu         $t4, 0x47D($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X47D);
    // 0x8021B368: addiu       $v1, $v1, -0x225C
    ctx->r3 = ADD32(ctx->r3, -0X225C);
    // 0x8021B36C: andi        $t8, $t6, 0xFF7F
    ctx->r24 = ctx->r14 & 0XFF7F;
    // 0x8021B370: andi        $t0, $t8, 0x9F
    ctx->r8 = ctx->r24 & 0X9F;
    // 0x8021B374: lbu         $t6, 0x47E($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X47E);
    // 0x8021B378: sb          $t8, 0x47C($a2)
    MEM_B(0X47C, ctx->r6) = ctx->r24;
    // 0x8021B37C: andi        $t2, $t0, 0xE1
    ctx->r10 = ctx->r8 & 0XE1;
    // 0x8021B380: andi        $t8, $t4, 0xFF7F
    ctx->r24 = ctx->r12 & 0XFF7F;
    // 0x8021B384: sb          $t0, 0x47C($a2)
    MEM_B(0X47C, ctx->r6) = ctx->r8;
    // 0x8021B388: andi        $t0, $t8, 0x9F
    ctx->r8 = ctx->r24 & 0X9F;
    // 0x8021B38C: andi        $t4, $t6, 0xFFEF
    ctx->r12 = ctx->r14 & 0XFFEF;
    // 0x8021B390: lbu         $t6, 0x484($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X484);
    // 0x8021B394: sb          $t2, 0x47C($a2)
    MEM_B(0X47C, ctx->r6) = ctx->r10;
    // 0x8021B398: andi        $t3, $t2, 0xFE
    ctx->r11 = ctx->r10 & 0XFE;
    // 0x8021B39C: sb          $t8, 0x47D($a2)
    MEM_B(0X47D, ctx->r6) = ctx->r24;
    // 0x8021B3A0: sb          $t0, 0x47D($a2)
    MEM_B(0X47D, ctx->r6) = ctx->r8;
    // 0x8021B3A4: andi        $t2, $t0, 0xE7
    ctx->r10 = ctx->r8 & 0XE7;
    // 0x8021B3A8: lbu         $t0, 0x818($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X818);
    // 0x8021B3AC: sb          $t3, 0x47C($a2)
    MEM_B(0X47C, ctx->r6) = ctx->r11;
    // 0x8021B3B0: andi        $t8, $t6, 0xFF7F
    ctx->r24 = ctx->r14 & 0XFF7F;
    // 0x8021B3B4: sb          $t2, 0x47D($a2)
    MEM_B(0X47D, ctx->r6) = ctx->r10;
    // 0x8021B3B8: andi        $t3, $t2, 0xF8
    ctx->r11 = ctx->r10 & 0XF8;
    // 0x8021B3BC: sb          $t4, 0x47E($a2)
    MEM_B(0X47E, ctx->r6) = ctx->r12;
    // 0x8021B3C0: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x8021B3C4: sb          $t8, 0x484($a2)
    MEM_B(0X484, ctx->r6) = ctx->r24;
    // 0x8021B3C8: andi        $t9, $t8, 0x9F
    ctx->r25 = ctx->r24 & 0X9F;
    // 0x8021B3CC: andi        $t2, $t0, 0xFF7F
    ctx->r10 = ctx->r8 & 0XFF7F;
    // 0x8021B3D0: lbu         $t8, 0x819($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X819);
    // 0x8021B3D4: andi        $t4, $t2, 0x9F
    ctx->r12 = ctx->r10 & 0X9F;
    // 0x8021B3D8: sb          $t2, 0x818($a2)
    MEM_B(0X818, ctx->r6) = ctx->r10;
    // 0x8021B3DC: andi        $t6, $t4, 0xE1
    ctx->r14 = ctx->r12 & 0XE1;
    // 0x8021B3E0: sb          $t4, 0x818($a2)
    MEM_B(0X818, ctx->r6) = ctx->r12;
    // 0x8021B3E4: lbu         $t0, 0x81A($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X81A);
    // 0x8021B3E8: sb          $t6, 0x818($a2)
    MEM_B(0X818, ctx->r6) = ctx->r14;
    // 0x8021B3EC: andi        $t7, $t6, 0xFE
    ctx->r15 = ctx->r14 & 0XFE;
    // 0x8021B3F0: andi        $t2, $t8, 0xFF7F
    ctx->r10 = ctx->r24 & 0XFF7F;
    // 0x8021B3F4: andi        $t4, $t2, 0x9F
    ctx->r12 = ctx->r10 & 0X9F;
    // 0x8021B3F8: sb          $t7, 0x818($a2)
    MEM_B(0X818, ctx->r6) = ctx->r15;
    // 0x8021B3FC: sb          $t2, 0x819($a2)
    MEM_B(0X819, ctx->r6) = ctx->r10;
    // 0x8021B400: andi        $t6, $t4, 0xE7
    ctx->r14 = ctx->r12 & 0XE7;
    // 0x8021B404: sb          $t4, 0x819($a2)
    MEM_B(0X819, ctx->r6) = ctx->r12;
    // 0x8021B408: andi        $t7, $t6, 0xF8
    ctx->r15 = ctx->r14 & 0XF8;
    // 0x8021B40C: andi        $t8, $t0, 0xFFEF
    ctx->r24 = ctx->r8 & 0XFFEF;
    // 0x8021B410: lbu         $t0, 0x820($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X820);
    // 0x8021B414: sb          $t6, 0x819($a2)
    MEM_B(0X819, ctx->r6) = ctx->r14;
    // 0x8021B418: sb          $t7, 0x819($a2)
    MEM_B(0X819, ctx->r6) = ctx->r15;
    // 0x8021B41C: lhu         $t6, 0x30($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X30);
    // 0x8021B420: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    // 0x8021B424: andi        $t2, $t0, 0xFF7F
    ctx->r10 = ctx->r8 & 0XFF7F;
    // 0x8021B428: sb          $t3, 0x47D($a2)
    MEM_B(0X47D, ctx->r6) = ctx->r11;
    // 0x8021B42C: sb          $t5, 0x47E($a2)
    MEM_B(0X47E, ctx->r6) = ctx->r13;
    // 0x8021B430: sb          $t9, 0x484($a2)
    MEM_B(0X484, ctx->r6) = ctx->r25;
    // 0x8021B434: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8021B438: sb          $t8, 0x81A($a2)
    MEM_B(0X81A, ctx->r6) = ctx->r24;
    // 0x8021B43C: andi        $t9, $t8, 0x1F
    ctx->r25 = ctx->r24 & 0X1F;
    // 0x8021B440: sb          $t2, 0x820($a2)
    MEM_B(0X820, ctx->r6) = ctx->r10;
    // 0x8021B444: andi        $t3, $t2, 0x9F
    ctx->r11 = ctx->r10 & 0X9F;
    // 0x8021B448: addiu       $t5, $t6, 0x80
    ctx->r13 = ADD32(ctx->r14, 0X80);
    // 0x8021B44C: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8021B450: sb          $t9, 0x81A($a2)
    MEM_B(0X81A, ctx->r6) = ctx->r25;
    // 0x8021B454: sb          $t3, 0x820($a2)
    MEM_B(0X820, ctx->r6) = ctx->r11;
    // 0x8021B458: sb          $t5, 0x479($a2)
    MEM_B(0X479, ctx->r6) = ctx->r13;
    // 0x8021B45C: sb          $zero, 0x1032($a2)
    MEM_B(0X1032, ctx->r6) = 0;
    // 0x8021B460: beq         $at, $zero, L_8021B4CC
    if (ctx->r1 == 0) {
        // 0x8021B464: sb          $t6, 0x815($a2)
        MEM_B(0X815, ctx->r6) = ctx->r14;
            goto L_8021B4CC;
    }
    // 0x8021B464: sb          $t6, 0x815($a2)
    MEM_B(0X815, ctx->r6) = ctx->r14;
    // 0x8021B468: jal         0x80151BC4
    // 0x8021B46C: nop

    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_2;
    // 0x8021B46C: nop

    after_2:
    // 0x8021B470: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021B474: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8021B478: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021B47C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021B480: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021B484: addiu       $a1, $a1, -0x2284
    ctx->r5 = ADD32(ctx->r5, -0X2284);
    // 0x8021B488: beq         $v0, $at, L_8021B4CC
    if (ctx->r2 == ctx->r1) {
        // 0x8021B48C: addiu       $v1, $v1, -0x225C
        ctx->r3 = ADD32(ctx->r3, -0X225C);
            goto L_8021B4CC;
    }
    // 0x8021B48C: addiu       $v1, $v1, -0x225C
    ctx->r3 = ADD32(ctx->r3, -0X225C);
    // 0x8021B490: lbu         $v0, 0x16($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X16);
    // 0x8021B494: beql        $v0, $zero, L_8021B4B4
    if (ctx->r2 == 0) {
        // 0x8021B498: lhu         $t9, 0x2C($a2)
        ctx->r25 = MEM_HU(ctx->r6, 0X2C);
            goto L_8021B4B4;
    }
    goto skip_2;
    // 0x8021B498: lhu         $t9, 0x2C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2C);
    skip_2:
    // 0x8021B49C: beq         $v0, $zero, L_8021B4CC
    if (ctx->r2 == 0) {
        // 0x8021B4A0: nop
    
            goto L_8021B4CC;
    }
    // 0x8021B4A0: nop

    // 0x8021B4A4: lbu         $t8, 0x17($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X17);
    // 0x8021B4A8: beq         $t8, $zero, L_8021B4CC
    if (ctx->r24 == 0) {
        // 0x8021B4AC: nop
    
            goto L_8021B4CC;
    }
    // 0x8021B4AC: nop

    // 0x8021B4B0: lhu         $t9, 0x2C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2C);
L_8021B4B4:
    // 0x8021B4B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021B4B8: beq         $t9, $at, L_8021B4CC
    if (ctx->r25 == ctx->r1) {
        // 0x8021B4BC: nop
    
            goto L_8021B4CC;
    }
    // 0x8021B4BC: nop

    // 0x8021B4C0: lhu         $t0, 0x4($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4);
    // 0x8021B4C4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8021B4C8: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
L_8021B4CC:
    // 0x8021B4CC: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8021B4D0: addiu       $v1, $v1, 0x730
    ctx->r3 = ADD32(ctx->r3, 0X730);
    // 0x8021B4D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8021B4D8:
    // 0x8021B4D8: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8021B4DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8021B4E0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8021B4E4: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8021B4E8: bne         $at, $zero, L_8021B4D8
    if (ctx->r1 != 0) {
        // 0x8021B4EC: sb          $zero, 0x0($t2)
        MEM_B(0X0, ctx->r10) = 0;
            goto L_8021B4D8;
    }
    // 0x8021B4EC: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x8021B4F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8021B4F4:
    // 0x8021B4F4: addu        $t3, $v1, $v0
    ctx->r11 = ADD32(ctx->r3, ctx->r2);
    // 0x8021B4F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8021B4FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8021B500: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8021B504: bne         $at, $zero, L_8021B4F4
    if (ctx->r1 != 0) {
        // 0x8021B508: sb          $zero, 0x14($t3)
        MEM_B(0X14, ctx->r11) = 0;
            goto L_8021B4F4;
    }
    // 0x8021B508: sb          $zero, 0x14($t3)
    MEM_B(0X14, ctx->r11) = 0;
    // 0x8021B50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8021B510:
    // 0x8021B510: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x8021B514: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8021B518: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8021B51C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8021B520: bne         $at, $zero, L_8021B510
    if (ctx->r1 != 0) {
        // 0x8021B524: sb          $zero, 0x1A($t4)
        MEM_B(0X1A, ctx->r12) = 0;
            goto L_8021B510;
    }
    // 0x8021B524: sb          $zero, 0x1A($t4)
    MEM_B(0X1A, ctx->r12) = 0;
    // 0x8021B528: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021B52C: sb          $zero, 0x22($v1)
    MEM_B(0X22, ctx->r3) = 0;
    // 0x8021B530: sb          $zero, 0x21($v1)
    MEM_B(0X21, ctx->r3) = 0;
    // 0x8021B534: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
    // 0x8021B538: addiu       $a1, $a1, -0x4AA0
    ctx->r5 = ADD32(ctx->r5, -0X4AA0);
    // 0x8021B53C: jal         0x800058DC
    // 0x8021B540: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021B540: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8021B544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021B548: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021B54C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021B550: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8021B554: sb          $t7, 0x1031($a2)
    MEM_B(0X1031, ctx->r6) = ctx->r15;
    // 0x8021B558: jr          $ra
    // 0x8021B55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8021B55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021b560(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021b560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021B564: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021B568: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021B56C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8021B570: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8021B574: lbu         $v0, 0x90($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X90);
    // 0x8021B578: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021B57C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8021B580: bne         $v0, $zero, L_8021B5D4
    if (ctx->r2 != 0) {
        // 0x8021B584: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8021B5D4;
    }
    // 0x8021B584: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B588: lhu         $v1, 0x2C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2C);
    // 0x8021B58C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021B590: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021B594: beq         $v1, $at, L_8021B5A8
    if (ctx->r3 == ctx->r1) {
        // 0x8021B598: addiu       $a1, $zero, 0x111
        ctx->r5 = ADD32(0, 0X111);
            goto L_8021B5A8;
    }
    // 0x8021B598: addiu       $a1, $zero, 0x111
    ctx->r5 = ADD32(0, 0X111);
    // 0x8021B59C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021B5A0: bne         $v1, $at, L_8021B5BC
    if (ctx->r3 != ctx->r1) {
        // 0x8021B5A4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8021B5BC;
    }
    // 0x8021B5A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8021B5A8:
    // 0x8021B5A8: jal         0x80126A0C
    // 0x8021B5AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x8021B5AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8021B5B0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8021B5B4: b           L_8021B77C
    // 0x8021B5B8: sb          $v0, 0x90($t7)
    MEM_B(0X90, ctx->r15) = ctx->r2;
        goto L_8021B77C;
    // 0x8021B5B8: sb          $v0, 0x90($t7)
    MEM_B(0X90, ctx->r15) = ctx->r2;
L_8021B5BC:
    // 0x8021B5BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021B5C0: jal         0x80126A0C
    // 0x8021B5C4: addiu       $a1, $zero, 0x10F
    ctx->r5 = ADD32(0, 0X10F);
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_1;
    // 0x8021B5C4: addiu       $a1, $zero, 0x10F
    ctx->r5 = ADD32(0, 0X10F);
    after_1:
    // 0x8021B5C8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8021B5CC: b           L_8021B77C
    // 0x8021B5D0: sb          $v0, 0x90($t8)
    MEM_B(0X90, ctx->r24) = ctx->r2;
        goto L_8021B77C;
    // 0x8021B5D0: sb          $v0, 0x90($t8)
    MEM_B(0X90, ctx->r24) = ctx->r2;
L_8021B5D4:
    // 0x8021B5D4: bne         $v0, $at, L_8021B638
    if (ctx->r2 != ctx->r1) {
        // 0x8021B5D8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021B638;
    }
    // 0x8021B5D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021B5DC: jal         0x80236C9C
    // 0x8021B5E0: nop

    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_2;
    // 0x8021B5E0: nop

    after_2:
    // 0x8021B5E4: bne         $v0, $zero, L_8021B608
    if (ctx->r2 != 0) {
        // 0x8021B5E8: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_8021B608;
    }
    // 0x8021B5E8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021B5EC: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8021B5F0: lhu         $v1, 0x2C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2C);
    // 0x8021B5F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021B5F8: beq         $v1, $at, L_8021B608
    if (ctx->r3 == ctx->r1) {
        // 0x8021B5FC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8021B608;
    }
    // 0x8021B5FC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021B600: bne         $v1, $at, L_8021B62C
    if (ctx->r3 != ctx->r1) {
        // 0x8021B604: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8021B62C;
    }
    // 0x8021B604: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_8021B608:
    // 0x8021B608: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021B60C: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    // 0x8021B610: jal         0x80126A0C
    // 0x8021B614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_3;
    // 0x8021B614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8021B618: beq         $v0, $zero, L_8021B77C
    if (ctx->r2 == 0) {
        // 0x8021B61C: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_8021B77C;
    }
    // 0x8021B61C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8021B620: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8021B624: b           L_8021B77C
    // 0x8021B628: sb          $t9, 0x90($t0)
    MEM_B(0X90, ctx->r8) = ctx->r25;
        goto L_8021B77C;
    // 0x8021B628: sb          $t9, 0x90($t0)
    MEM_B(0X90, ctx->r8) = ctx->r25;
L_8021B62C:
    // 0x8021B62C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8021B630: b           L_8021B77C
    // 0x8021B634: sb          $t1, 0x90($t2)
    MEM_B(0X90, ctx->r10) = ctx->r9;
        goto L_8021B77C;
    // 0x8021B634: sb          $t1, 0x90($t2)
    MEM_B(0X90, ctx->r10) = ctx->r9;
L_8021B638:
    // 0x8021B638: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021B63C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8021B640: lw          $t3, 0xDC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XDC);
    // 0x8021B644: lbu         $t4, 0x63($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X63);
    // 0x8021B648: beql        $t4, $zero, L_8021B780
    if (ctx->r12 == 0) {
        // 0x8021B64C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021B780;
    }
    goto skip_0;
    // 0x8021B64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8021B650: lw          $t5, 0xEC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEC);
    // 0x8021B654: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021B658: lbu         $t6, 0x63($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X63);
    // 0x8021B65C: beql        $t6, $zero, L_8021B780
    if (ctx->r14 == 0) {
        // 0x8021B660: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021B780;
    }
    goto skip_1;
    // 0x8021B660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8021B664: bne         $v1, $at, L_8021B77C
    if (ctx->r3 != ctx->r1) {
        // 0x8021B668: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8021B77C;
    }
    // 0x8021B668: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021B66C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8021B670: jal         0x80005670
    // 0x8021B674: addiu       $a1, $a1, -0x36DC
    ctx->r5 = ADD32(ctx->r5, -0X36DC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_4;
    // 0x8021B674: addiu       $a1, $a1, -0x36DC
    ctx->r5 = ADD32(ctx->r5, -0X36DC);
    after_4:
    // 0x8021B678: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8021B67C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021B680: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021B684: sw          $v0, 0x9C($t7)
    MEM_W(0X9C, ctx->r15) = ctx->r2;
    // 0x8021B688: lhu         $v1, 0x2C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2C);
    // 0x8021B68C: beq         $v1, $at, L_8021B69C
    if (ctx->r3 == ctx->r1) {
        // 0x8021B690: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8021B69C;
    }
    // 0x8021B690: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021B694: bne         $v1, $at, L_8021B6D4
    if (ctx->r3 != ctx->r1) {
        // 0x8021B698: nop
    
            goto L_8021B6D4;
    }
    // 0x8021B698: nop

L_8021B69C:
    // 0x8021B69C: jal         0x8022C7A4
    // 0x8021B6A0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022C7A4)(rdram, ctx);
        goto after_5;
    // 0x8021B6A0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_5:
    // 0x8021B6A4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021B6A8: jal         0x80244410
    // 0x8021B6AC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x80244410)(rdram, ctx);
        goto after_6;
    // 0x8021B6AC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_6:
    // 0x8021B6B0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021B6B4: jal         0x80244410
    // 0x8021B6B8: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x80244410)(rdram, ctx);
        goto after_7;
    // 0x8021B6B8: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_7:
    // 0x8021B6BC: jal         0x80232FEC
    // 0x8021B6C0: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    LOOKUP_FUNC(0x80232FEC)(rdram, ctx);
        goto after_8;
    // 0x8021B6C0: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    after_8:
    // 0x8021B6C4: jal         0x80232FEC
    // 0x8021B6C8: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    LOOKUP_FUNC(0x80232FEC)(rdram, ctx);
        goto after_9;
    // 0x8021B6C8: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    after_9:
    // 0x8021B6CC: b           L_8021B6F4
    // 0x8021B6D0: nop

        goto L_8021B6F4;
    // 0x8021B6D0: nop

L_8021B6D4:
    // 0x8021B6D4: jal         0x80232FEC
    // 0x8021B6D8: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    LOOKUP_FUNC(0x80232FEC)(rdram, ctx);
        goto after_10;
    // 0x8021B6D8: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    after_10:
    // 0x8021B6DC: jal         0x8022CABC
    // 0x8021B6E0: nop

    LOOKUP_FUNC(0x8022CABC)(rdram, ctx);
        goto after_11;
    // 0x8021B6E0: nop

    after_11:
    // 0x8021B6E4: jal         0x8022CAFC
    // 0x8021B6E8: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    LOOKUP_FUNC(0x8022CAFC)(rdram, ctx);
        goto after_12;
    // 0x8021B6E8: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    after_12:
    // 0x8021B6EC: jal         0x80232820
    // 0x8021B6F0: nop

    LOOKUP_FUNC(0x80232820)(rdram, ctx);
        goto after_13;
    // 0x8021B6F0: nop

    after_13:
L_8021B6F4:
    // 0x8021B6F4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021B6F8: jal         0x8022D954
    // 0x8021B6FC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022D954)(rdram, ctx);
        goto after_14;
    // 0x8021B6FC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_14:
    // 0x8021B700: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021B704: sh          $v0, 0x4A2($s0)
    MEM_H(0X4A2, ctx->r16) = ctx->r2;
    // 0x8021B708: jal         0x8022D954
    // 0x8021B70C: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022D954)(rdram, ctx);
        goto after_15;
    // 0x8021B70C: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_15:
    // 0x8021B710: lbu         $v1, 0x1034($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1034);
    // 0x8021B714: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B718: sh          $v0, 0x83E($s0)
    MEM_H(0X83E, ctx->r16) = ctx->r2;
    // 0x8021B71C: bnel        $v1, $at, L_8021B730
    if (ctx->r3 != ctx->r1) {
        // 0x8021B720: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8021B730;
    }
    goto skip_2;
    // 0x8021B720: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_2:
    // 0x8021B724: lh          $t8, 0x7EC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X7EC);
    // 0x8021B728: sh          $t8, 0x7EE($s0)
    MEM_H(0X7EE, ctx->r16) = ctx->r24;
    // 0x8021B72C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8021B730:
    // 0x8021B730: beql        $v1, $at, L_8021B750
    if (ctx->r3 == ctx->r1) {
        // 0x8021B734: lh          $t9, 0x450($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X450);
            goto L_8021B750;
    }
    goto skip_3;
    // 0x8021B734: lh          $t9, 0x450($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X450);
    skip_3:
    // 0x8021B738: jal         0x80151BC4
    // 0x8021B73C: nop

    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_16;
    // 0x8021B73C: nop

    after_16:
    // 0x8021B740: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021B744: bnel        $v0, $at, L_8021B758
    if (ctx->r2 != ctx->r1) {
        // 0x8021B748: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_8021B758;
    }
    goto skip_4;
    // 0x8021B748: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    skip_4:
    // 0x8021B74C: lh          $t9, 0x450($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X450);
L_8021B750:
    // 0x8021B750: sh          $t9, 0x452($s0)
    MEM_H(0X452, ctx->r16) = ctx->r25;
    // 0x8021B754: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_8021B758:
    // 0x8021B758: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8021B75C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021B760: sb          $zero, 0x90($t0)
    MEM_B(0X90, ctx->r8) = 0;
    // 0x8021B764: sb          $zero, -0x3D9C($at)
    MEM_B(-0X3D9C, ctx->r1) = 0;
    // 0x8021B768: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021B76C: jal         0x800058DC
    // 0x8021B770: addiu       $a1, $a1, -0x4790
    ctx->r5 = ADD32(ctx->r5, -0X4790);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x8021B770: addiu       $a1, $a1, -0x4790
    ctx->r5 = ADD32(ctx->r5, -0X4790);
    after_17:
    // 0x8021B774: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8021B778: sb          $t1, 0x1031($s0)
    MEM_B(0X1031, ctx->r16) = ctx->r9;
L_8021B77C:
    // 0x8021B77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021B780:
    // 0x8021B780: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021B784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021B788: jr          $ra
    // 0x8021B78C: nop

    return;
    // 0x8021B78C: nop

;}
RECOMP_FUNC void M10_FUN_8021b790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B790: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021B794: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021B798: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021B79C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8021B7A0: lw          $v0, 0x448($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X448);
    // 0x8021B7A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021B7A8: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
    // 0x8021B7AC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8021B7B0: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x8021B7B4: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8021B7B8: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8021B7BC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8021B7C0: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8021B7C4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8021B7C8: swc1        $f8, 0xB84($s0)
    MEM_W(0XB84, ctx->r16) = ctx->f8.u32l;
    // 0x8021B7CC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8021B7D0: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x8021B7D4: lwc1        $f0, 0xB84($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XB84);
    // 0x8021B7D8: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x8021B7DC: lwc1        $f16, 0x8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8021B7E0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8021B7E4: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8021B7E8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8021B7EC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8021B7F0: swc1        $f18, 0xB88($s0)
    MEM_W(0XB88, ctx->r16) = ctx->f18.u32l;
    // 0x8021B7F4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8021B7F8: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8021B7FC: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x8021B800: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8021B804: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8021B808: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8021B80C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8021B810: swc1        $f8, 0xB8C($s0)
    MEM_W(0XB8C, ctx->r16) = ctx->f8.u32l;
    // 0x8021B814: lwc1        $f2, 0xB8C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8C);
    // 0x8021B818: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8021B81C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8021B820: swc1        $f18, 0xB90($s0)
    MEM_W(0XB90, ctx->r16) = ctx->f18.u32l;
    // 0x8021B824: jal         0x8002FC20
    // 0x8021B828: lwc1        $f12, 0xB90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB90);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8021B828: lwc1        $f12, 0xB90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB90);
    after_0:
    // 0x8021B82C: lwc1        $f2, 0xB88($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB88);
    // 0x8021B830: lwc1        $f4, 0xB90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB90);
    // 0x8021B834: swc1        $f0, 0xB94($s0)
    MEM_W(0XB94, ctx->r16) = ctx->f0.u32l;
    // 0x8021B838: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8021B83C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8021B840: swc1        $f8, 0xB90($s0)
    MEM_W(0XB90, ctx->r16) = ctx->f8.u32l;
    // 0x8021B844: jal         0x8002FC20
    // 0x8021B848: lwc1        $f12, 0xB90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB90);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x8021B848: lwc1        $f12, 0xB90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB90);
    after_1:
    // 0x8021B84C: swc1        $f0, 0xB90($s0)
    MEM_W(0XB90, ctx->r16) = ctx->f0.u32l;
    // 0x8021B850: lwc1        $f12, 0xB84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB84);
    // 0x8021B854: jal         0x8001EF38
    // 0x8021B858: lwc1        $f14, 0xB8C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XB8C);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8021B858: lwc1        $f14, 0xB8C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XB8C);
    after_2:
    // 0x8021B85C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021B860: sh          $v0, 0xB98($s0)
    MEM_H(0XB98, ctx->r16) = ctx->r2;
    // 0x8021B864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021B868: jr          $ra
    // 0x8021B86C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8021B86C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021b870(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021b870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B870: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021B874: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021B878: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021b87c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021b87c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021B87C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021B880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021B884: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021B888: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021B88C: bne         $v1, $zero, L_8021B8C4
    if (ctx->r3 != 0) {
        // 0x8021B890: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8021B8C4;
    }
    // 0x8021B890: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021B894: addiu       $a1, $zero, 0x1AA
    ctx->r5 = ADD32(0, 0X1AA);
    // 0x8021B898: jal         0x80126A0C
    // 0x8021B89C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x8021B89C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8021B8A0: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021B8A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B8A8: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B8AC: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021B8AC: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021B8B0: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8021B8B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8021B8B8: andi        $v1, $t7, 0xFF
    ctx->r3 = ctx->r15 & 0XFF;
    // 0x8021B8BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021B8C0: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_8021B8C4:
    // 0x8021B8C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B8C8: bne         $v0, $at, L_8021B900
    if (ctx->r2 != ctx->r1) {
        // 0x8021B8CC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021B900;
    }
    // 0x8021B8CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021B8D0: addiu       $a1, $zero, 0x1AB
    ctx->r5 = ADD32(0, 0X1AB);
    // 0x8021B8D4: jal         0x80126A0C
    // 0x8021B8D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_1;
    // 0x8021B8D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8021B8DC: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021B8E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B8E4: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B8E8: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021B8E8: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021B8EC: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x8021B8F0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8021B8F4: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
    // 0x8021B8F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021B8FC: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_8021B900:
    // 0x8021B900: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021B904: bne         $v0, $at, L_8021B93C
    if (ctx->r2 != ctx->r1) {
        // 0x8021B908: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021B93C;
    }
    // 0x8021B908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021B90C: addiu       $a1, $zero, 0x1AC
    ctx->r5 = ADD32(0, 0X1AC);
    // 0x8021B910: jal         0x80126A0C
    // 0x8021B914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_2;
    // 0x8021B914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8021B918: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021B91C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B920: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B924: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021B924: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021B928: lbu         $t0, 0x0($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X0);
    // 0x8021B92C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8021B930: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x8021B934: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021B938: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
L_8021B93C:
    // 0x8021B93C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021B940: bne         $v0, $at, L_8021B978
    if (ctx->r2 != ctx->r1) {
        // 0x8021B944: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021B978;
    }
    // 0x8021B944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021B948: addiu       $a1, $zero, 0x1AD
    ctx->r5 = ADD32(0, 0X1AD);
    // 0x8021B94C: jal         0x80126A0C
    // 0x8021B950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_3;
    // 0x8021B950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8021B954: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021B958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B95C: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B960: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021B960: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021B964: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x8021B968: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8021B96C: andi        $v1, $t3, 0xFF
    ctx->r3 = ctx->r11 & 0XFF;
    // 0x8021B970: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021B974: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
L_8021B978:
    // 0x8021B978: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021B97C: bne         $v0, $at, L_8021B9B4
    if (ctx->r2 != ctx->r1) {
        // 0x8021B980: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021B9B4;
    }
    // 0x8021B980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021B984: addiu       $a1, $zero, 0x1AF
    ctx->r5 = ADD32(0, 0X1AF);
    // 0x8021B988: jal         0x80126A0C
    // 0x8021B98C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_4;
    // 0x8021B98C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8021B990: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021B994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B998: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B99C: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021B99C: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021B9A0: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x8021B9A4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8021B9A8: andi        $v1, $t5, 0xFF
    ctx->r3 = ctx->r13 & 0XFF;
    // 0x8021B9AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021B9B0: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
L_8021B9B4:
    // 0x8021B9B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021B9B8: bne         $v0, $at, L_8021B9F0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B9BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021B9F0;
    }
    // 0x8021B9BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021B9C0: addiu       $a1, $zero, 0x1B0
    ctx->r5 = ADD32(0, 0X1B0);
    // 0x8021B9C4: jal         0x80126A0C
    // 0x8021B9C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_5;
    // 0x8021B9C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8021B9CC: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021B9D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021B9D4: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021B9D8: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021B9D8: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021B9DC: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8021B9E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8021B9E4: andi        $v1, $t7, 0xFF
    ctx->r3 = ctx->r15 & 0XFF;
    // 0x8021B9E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021B9EC: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_8021B9F0:
    // 0x8021B9F0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8021B9F4: bne         $v0, $at, L_8021BA2C
    if (ctx->r2 != ctx->r1) {
        // 0x8021B9F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BA2C;
    }
    // 0x8021B9F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021B9FC: addiu       $a1, $zero, 0x1B1
    ctx->r5 = ADD32(0, 0X1B1);
    // 0x8021BA00: jal         0x80126A0C
    // 0x8021BA04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_6;
    // 0x8021BA04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8021BA08: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BA0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BA10: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BA14: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BA14: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BA18: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BA1C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8021BA20: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
    // 0x8021BA24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BA28: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_8021BA2C:
    // 0x8021BA2C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8021BA30: bne         $v0, $at, L_8021BA68
    if (ctx->r2 != ctx->r1) {
        // 0x8021BA34: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BA68;
    }
    // 0x8021BA34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BA38: addiu       $a1, $zero, 0x1B2
    ctx->r5 = ADD32(0, 0X1B2);
    // 0x8021BA3C: jal         0x80126A0C
    // 0x8021BA40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_7;
    // 0x8021BA40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8021BA44: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BA48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BA4C: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BA50: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BA50: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BA54: lbu         $t0, 0x0($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BA58: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8021BA5C: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x8021BA60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BA64: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
L_8021BA68:
    // 0x8021BA68: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8021BA6C: bne         $v0, $at, L_8021BAA4
    if (ctx->r2 != ctx->r1) {
        // 0x8021BA70: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BAA4;
    }
    // 0x8021BA70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BA74: addiu       $a1, $zero, 0x1B3
    ctx->r5 = ADD32(0, 0X1B3);
    // 0x8021BA78: jal         0x80126A0C
    // 0x8021BA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_8;
    // 0x8021BA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8021BA80: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BA84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BA88: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BA8C: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BA8C: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BA90: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BA94: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8021BA98: andi        $v1, $t3, 0xFF
    ctx->r3 = ctx->r11 & 0XFF;
    // 0x8021BA9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BAA0: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
L_8021BAA4:
    // 0x8021BAA4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8021BAA8: bne         $v0, $at, L_8021BAE0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BAAC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BAE0;
    }
    // 0x8021BAAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BAB0: addiu       $a1, $zero, 0x1B4
    ctx->r5 = ADD32(0, 0X1B4);
    // 0x8021BAB4: jal         0x80126A0C
    // 0x8021BAB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_9;
    // 0x8021BAB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8021BABC: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BAC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BAC4: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BAC8: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BAC8: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BACC: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BAD0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8021BAD4: andi        $v1, $t5, 0xFF
    ctx->r3 = ctx->r13 & 0XFF;
    // 0x8021BAD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BADC: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
L_8021BAE0:
    // 0x8021BAE0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021BAE4: bne         $v0, $at, L_8021BB1C
    if (ctx->r2 != ctx->r1) {
        // 0x8021BAE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BB1C;
    }
    // 0x8021BAE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BAEC: addiu       $a1, $zero, 0x1B5
    ctx->r5 = ADD32(0, 0X1B5);
    // 0x8021BAF0: jal         0x80126A0C
    // 0x8021BAF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_10;
    // 0x8021BAF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8021BAF8: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BAFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BB00: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BB04: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BB04: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BB08: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BB0C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8021BB10: andi        $v1, $t7, 0xFF
    ctx->r3 = ctx->r15 & 0XFF;
    // 0x8021BB14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BB18: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_8021BB1C:
    // 0x8021BB1C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021BB20: bne         $v0, $at, L_8021BB58
    if (ctx->r2 != ctx->r1) {
        // 0x8021BB24: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BB58;
    }
    // 0x8021BB24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BB28: addiu       $a1, $zero, 0x1B6
    ctx->r5 = ADD32(0, 0X1B6);
    // 0x8021BB2C: jal         0x80126A0C
    // 0x8021BB30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_11;
    // 0x8021BB30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8021BB34: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BB38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BB3C: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BB40: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BB40: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BB44: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BB48: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8021BB4C: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
    // 0x8021BB50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BB54: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_8021BB58:
    // 0x8021BB58: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8021BB5C: bne         $v0, $at, L_8021BB94
    if (ctx->r2 != ctx->r1) {
        // 0x8021BB60: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BB94;
    }
    // 0x8021BB60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BB64: addiu       $a1, $zero, 0x1B7
    ctx->r5 = ADD32(0, 0X1B7);
    // 0x8021BB68: jal         0x80126A0C
    // 0x8021BB6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_12;
    // 0x8021BB6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x8021BB70: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BB74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BB78: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BB7C: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BB7C: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BB80: lbu         $t0, 0x0($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BB84: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8021BB88: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x8021BB8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BB90: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
L_8021BB94:
    // 0x8021BB94: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8021BB98: bne         $v0, $at, L_8021BBD0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BB9C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BBD0;
    }
    // 0x8021BB9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BBA0: addiu       $a1, $zero, 0x1B8
    ctx->r5 = ADD32(0, 0X1B8);
    // 0x8021BBA4: jal         0x80126A0C
    // 0x8021BBA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_13;
    // 0x8021BBA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x8021BBAC: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BBB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021BBB4: bne         $v0, $at, L_8021BCF0
    if (ctx->r2 != ctx->r1) {
        // 0x8021BBB8: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BBB8: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BBBC: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BBC0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8021BBC4: andi        $v1, $t3, 0xFF
    ctx->r3 = ctx->r11 & 0XFF;
    // 0x8021BBC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BBCC: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
L_8021BBD0:
    // 0x8021BBD0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8021BBD4: bne         $v0, $at, L_8021BC08
    if (ctx->r2 != ctx->r1) {
        // 0x8021BBD8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BC08;
    }
    // 0x8021BBD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BBDC: addiu       $a1, $zero, 0x125
    ctx->r5 = ADD32(0, 0X125);
    // 0x8021BBE0: jal         0x80126A0C
    // 0x8021BBE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_14;
    // 0x8021BBE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x8021BBE8: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BBEC: beq         $v0, $zero, L_8021BCF0
    if (ctx->r2 == 0) {
        // 0x8021BBF0: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BBF0: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BBF4: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BBF8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8021BBFC: andi        $v1, $t5, 0xFF
    ctx->r3 = ctx->r13 & 0XFF;
    // 0x8021BC00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BC04: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
L_8021BC08:
    // 0x8021BC08: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021BC0C: bne         $v0, $at, L_8021BC40
    if (ctx->r2 != ctx->r1) {
        // 0x8021BC10: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021BC40;
    }
    // 0x8021BC10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BC14: addiu       $a1, $zero, 0x127
    ctx->r5 = ADD32(0, 0X127);
    // 0x8021BC18: jal         0x80126A0C
    // 0x8021BC1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_15;
    // 0x8021BC1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x8021BC20: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BC24: beq         $v0, $zero, L_8021BCF0
    if (ctx->r2 == 0) {
        // 0x8021BC28: addiu       $a3, $a3, -0x3D9C
        ctx->r7 = ADD32(ctx->r7, -0X3D9C);
            goto L_8021BCF0;
    }
    // 0x8021BC28: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BC2C: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BC30: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8021BC34: andi        $v1, $t7, 0xFF
    ctx->r3 = ctx->r15 & 0XFF;
    // 0x8021BC38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8021BC3C: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_8021BC40:
    // 0x8021BC40: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8021BC44: bne         $v0, $at, L_8021BCCC
    if (ctx->r2 != ctx->r1) {
        // 0x8021BC48: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_8021BCCC;
    }
    // 0x8021BC48: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021BC4C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021BC50: lhu         $v0, 0x2C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2C);
    // 0x8021BC54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021BC58: beq         $v0, $at, L_8021BC70
    if (ctx->r2 == ctx->r1) {
        // 0x8021BC5C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8021BC70;
    }
    // 0x8021BC5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021BC60: beq         $v0, $at, L_8021BC70
    if (ctx->r2 == ctx->r1) {
        // 0x8021BC64: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021BC70;
    }
    // 0x8021BC64: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021BC68: bnel        $v0, $at, L_8021BCC8
    if (ctx->r2 != ctx->r1) {
        // 0x8021BC6C: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_8021BCC8;
    }
    goto skip_0;
    // 0x8021BC6C: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    skip_0:
L_8021BC70:
    // 0x8021BC70: lw          $t8, 0x188($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X188);
    // 0x8021BC74: bnel        $t8, $zero, L_8021BCF4
    if (ctx->r24 != 0) {
        // 0x8021BC78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021BCF4;
    }
    goto skip_1;
    // 0x8021BC78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8021BC7C: lbu         $t9, 0x181($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X181);
    // 0x8021BC80: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8021BC84: bnel        $t9, $zero, L_8021BCF4
    if (ctx->r25 != 0) {
        // 0x8021BC88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021BCF4;
    }
    goto skip_2;
    // 0x8021BC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8021BC8C: lw          $t0, -0x2A80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2A80);
    // 0x8021BC90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8021BC94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8021BC98: sltiu       $at, $t0, 0x2001
    ctx->r1 = ctx->r8 < 0X2001 ? 1 : 0;
    // 0x8021BC9C: bnel        $at, $zero, L_8021BCB0
    if (ctx->r1 != 0) {
        // 0x8021BCA0: sb          $t2, 0x181($a2)
        MEM_B(0X181, ctx->r6) = ctx->r10;
            goto L_8021BCB0;
    }
    goto skip_3;
    // 0x8021BCA0: sb          $t2, 0x181($a2)
    MEM_B(0X181, ctx->r6) = ctx->r10;
    skip_3:
    // 0x8021BCA4: b           L_8021BCF0
    // 0x8021BCA8: sb          $t1, 0x181($a2)
    MEM_B(0X181, ctx->r6) = ctx->r9;
        goto L_8021BCF0;
    // 0x8021BCA8: sb          $t1, 0x181($a2)
    MEM_B(0X181, ctx->r6) = ctx->r9;
    // 0x8021BCAC: sb          $t2, 0x181($a2)
    MEM_B(0X181, ctx->r6) = ctx->r10;
L_8021BCB0:
    // 0x8021BCB0: jal         0x8022AF94
    // 0x8021BCB4: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    LOOKUP_FUNC(0x8022AF94)(rdram, ctx);
        goto after_16;
    // 0x8021BCB4: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    after_16:
    // 0x8021BCB8: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8021BCBC: addiu       $a3, $a3, -0x3D9C
    ctx->r7 = ADD32(ctx->r7, -0X3D9C);
    // 0x8021BCC0: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8021BCC4: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_8021BCC8:
    // 0x8021BCC8: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
L_8021BCCC:
    // 0x8021BCCC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021BCD0: addiu       $a1, $a1, -0x4300
    ctx->r5 = ADD32(ctx->r5, -0X4300);
    // 0x8021BCD4: jal         0x800058DC
    // 0x8021BCD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x8021BCD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_17:
    // 0x8021BCDC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021BCE0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021BCE4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8021BCE8: jal         0x8021B790
    // 0x8021BCEC: sb          $t4, 0x1031($a2)
    MEM_B(0X1031, ctx->r6) = ctx->r12;
    LOOKUP_FUNC(0x8021B790)(rdram, ctx);
        goto after_18;
    // 0x8021BCEC: sb          $t4, 0x1031($a2)
    MEM_B(0X1031, ctx->r6) = ctx->r12;
    after_18:
L_8021BCF0:
    // 0x8021BCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021BCF4:
    // 0x8021BCF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021BCF8: jr          $ra
    // 0x8021BCFC: nop

    return;
    // 0x8021BCFC: nop

;}
RECOMP_FUNC void M10_FUN_8021bd00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021BD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021BD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021BD08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021BD0C: jal         0x8021B790
    // 0x8021BD10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8021B790)(rdram, ctx);
        goto after_0;
    // 0x8021BD10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021BD14: jal         0x80031190
    // 0x8021BD18: nop

    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_1;
    // 0x8021BD18: nop

    after_1:
    // 0x8021BD1C: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8021BD20: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8021BD24: lw          $t7, 0x75C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X75C);
    // 0x8021BD28: lw          $t6, 0x758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X758);
    // 0x8021BD2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8021BD30: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x8021BD34: subu        $a0, $v0, $t6
    ctx->r4 = SUB32(ctx->r2, ctx->r14);
    // 0x8021BD38: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x8021BD3C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8021BD40: jal         0x80026F58
    // 0x8021BD44: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_2;
    // 0x8021BD44: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    after_2:
    // 0x8021BD48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8021BD4C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8021BD50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8021BD54: jal         0x80026E58
    // 0x8021BD58: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_3;
    // 0x8021BD58: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_3:
    // 0x8021BD5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8021BD60: jal         0x80034C24
    // 0x8021BD64: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_4;
    // 0x8021BD64: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x8021BD68: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8021BD6C: ldc1        $f4, -0x16B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X16B8);
    // 0x8021BD70: jal         0x80034AB8
    // 0x8021BD74: div.d       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f4.d);
    LOOKUP_FUNC(0x80034AB8)(rdram, ctx);
        goto after_5;
    // 0x8021BD74: div.d       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f4.d);
    after_5:
    // 0x8021BD78: bne         $v0, $zero, L_8021BD84
    if (ctx->r2 != 0) {
        // 0x8021BD7C: sltiu       $at, $v1, 0x1F
        ctx->r1 = ctx->r3 < 0X1F ? 1 : 0;
            goto L_8021BD84;
    }
    // 0x8021BD7C: sltiu       $at, $v1, 0x1F
    ctx->r1 = ctx->r3 < 0X1F ? 1 : 0;
    // 0x8021BD80: bne         $at, $zero, L_8021BDD0
    if (ctx->r1 != 0) {
        // 0x8021BD84: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8021BDD0;
    }
L_8021BD84:
    // 0x8021BD84: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021BD88: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021BD8C: lbu         $t8, 0x181($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X181);
    // 0x8021BD90: bnel        $t8, $zero, L_8021BDD4
    if (ctx->r24 != 0) {
        // 0x8021BD94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021BDD4;
    }
    goto skip_0;
    // 0x8021BD94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021BD98: lbu         $t9, 0x182($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X182);
    // 0x8021BD9C: bnel        $t9, $zero, L_8021BDD4
    if (ctx->r25 != 0) {
        // 0x8021BDA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021BDD4;
    }
    goto skip_1;
    // 0x8021BDA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8021BDA4: jal         0x80151BC4
    // 0x8021BDA8: nop

    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_6;
    // 0x8021BDA8: nop

    after_6:
    // 0x8021BDAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021BDB0: beq         $v0, $at, L_8021BDC0
    if (ctx->r2 == ctx->r1) {
        // 0x8021BDB4: nop
    
            goto L_8021BDC0;
    }
    // 0x8021BDB4: nop

    // 0x8021BDB8: jal         0x802332D8
    // 0x8021BDBC: nop

    LOOKUP_FUNC(0x802332D8)(rdram, ctx);
        goto after_7;
    // 0x8021BDBC: nop

    after_7:
L_8021BDC0:
    // 0x8021BDC0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021BDC4: addiu       $a1, $a1, -0x4220
    ctx->r5 = ADD32(ctx->r5, -0X4220);
    // 0x8021BDC8: jal         0x800058DC
    // 0x8021BDCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8021BDCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
L_8021BDD0:
    // 0x8021BDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021BDD4:
    // 0x8021BDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021BDD8: jr          $ra
    // 0x8021BDDC: nop

    return;
    // 0x8021BDDC: nop

;}
RECOMP_FUNC void M10_FUN_8021bde0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021BDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021BDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021BDE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021BDEC: jal         0x8021B790
    // 0x8021BDF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8021B790)(rdram, ctx);
        goto after_0;
    // 0x8021BDF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021BDF4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021BDF8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021BDFC: lbu         $t6, 0x299($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X299);
    // 0x8021BE00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021BE04: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8021BE08: beq         $t6, $zero, L_8021BE20
    if (ctx->r14 == 0) {
        // 0x8021BE0C: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_8021BE20;
    }
    // 0x8021BE0C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021BE10: sb          $zero, 0x90($a0)
    MEM_B(0X90, ctx->r4) = 0;
    // 0x8021BE14: sb          $t7, 0x1031($v0)
    MEM_B(0X1031, ctx->r2) = ctx->r15;
    // 0x8021BE18: jal         0x800058DC
    // 0x8021BE1C: addiu       $a1, $a1, -0x41D0
    ctx->r5 = ADD32(ctx->r5, -0X41D0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8021BE1C: addiu       $a1, $a1, -0x41D0
    ctx->r5 = ADD32(ctx->r5, -0X41D0);
    after_1:
L_8021BE20:
    // 0x8021BE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021BE24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021BE28: jr          $ra
    // 0x8021BE2C: nop

    return;
    // 0x8021BE2C: nop

;}
RECOMP_FUNC void M10_FUN_8021be30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021BE30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021BE34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021BE38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021BE3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8021BE40: lw          $t6, 0x9C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C);
    // 0x8021BE44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021BE48: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021BE4C: lbu         $t7, 0x90($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X90);
    // 0x8021BE50: beql        $t7, $zero, L_8021BF64
    if (ctx->r15 == 0) {
        // 0x8021BE54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021BF64;
    }
    goto skip_0;
    // 0x8021BE54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8021BE58: lhu         $v1, -0x43E4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X43E4);
    // 0x8021BE5C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021BE60: beq         $v1, $at, L_8021BE98
    if (ctx->r3 == ctx->r1) {
        // 0x8021BE64: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8021BE98;
    }
    // 0x8021BE64: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021BE68: beq         $v1, $at, L_8021BE98
    if (ctx->r3 == ctx->r1) {
        // 0x8021BE6C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8021BE98;
    }
    // 0x8021BE6C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BE70: jal         0x80229524
    // 0x8021BE74: lw          $a0, -0x4324($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4324);
    LOOKUP_FUNC(0x80229524)(rdram, ctx);
        goto after_0;
    // 0x8021BE74: lw          $a0, -0x4324($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4324);
    after_0:
    // 0x8021BE78: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021BE7C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021BE80: lhu         $t8, 0x2C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2C);
    // 0x8021BE84: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021BE88: bne         $t8, $at, L_8021BE98
    if (ctx->r24 != ctx->r1) {
        // 0x8021BE8C: nop
    
            goto L_8021BE98;
    }
    // 0x8021BE8C: nop

    // 0x8021BE90: jal         0x80229524
    // 0x8021BE94: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
    LOOKUP_FUNC(0x80229524)(rdram, ctx);
        goto after_1;
    // 0x8021BE94: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
    after_1:
L_8021BE98:
    // 0x8021BE98: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021BE9C: addiu       $a1, $a1, -0x68FC
    ctx->r5 = ADD32(ctx->r5, -0X68FC);
    // 0x8021BEA0: jal         0x80005670
    // 0x8021BEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x8021BEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8021BEA8: sb          $zero, 0xA8($v0)
    MEM_B(0XA8, ctx->r2) = 0;
    // 0x8021BEAC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021BEB0: lhu         $v1, -0x43E4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X43E4);
    // 0x8021BEB4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021BEB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021BEBC: beq         $v1, $at, L_8021BED0
    if (ctx->r3 == ctx->r1) {
        // 0x8021BEC0: lui         $a1, 0x8039
        ctx->r5 = S32(0X8039 << 16);
            goto L_8021BED0;
    }
    // 0x8021BEC0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021BEC4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021BEC8: bne         $v1, $at, L_8021BEE0
    if (ctx->r3 != ctx->r1) {
        // 0x8021BECC: nop
    
            goto L_8021BEE0;
    }
    // 0x8021BECC: nop

L_8021BED0:
    // 0x8021BED0: jal         0x80005670
    // 0x8021BED4: addiu       $a1, $a1, -0x68FC
    ctx->r5 = ADD32(ctx->r5, -0X68FC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x8021BED4: addiu       $a1, $a1, -0x68FC
    ctx->r5 = ADD32(ctx->r5, -0X68FC);
    after_3:
    // 0x8021BED8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8021BEDC: sb          $t9, 0xA8($v0)
    MEM_B(0XA8, ctx->r2) = ctx->r25;
L_8021BEE0:
    // 0x8021BEE0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021BEE4: addiu       $a1, $a1, -0x694C
    ctx->r5 = ADD32(ctx->r5, -0X694C);
    // 0x8021BEE8: jal         0x80005670
    // 0x8021BEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_4;
    // 0x8021BEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8021BEF0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021BEF4: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
    // 0x8021BEF8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021BEFC: sw          $t0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r8;
    // 0x8021BF00: addiu       $a1, $a1, -0x694C
    ctx->r5 = ADD32(ctx->r5, -0X694C);
    // 0x8021BF04: jal         0x80005670
    // 0x8021BF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x8021BF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8021BF0C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8021BF10: addiu       $t1, $t1, -0x3C28
    ctx->r9 = ADD32(ctx->r9, -0X3C28);
    // 0x8021BF14: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021BF18: sw          $t1, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r9;
    // 0x8021BF1C: addiu       $a1, $a1, -0x68E8
    ctx->r5 = ADD32(ctx->r5, -0X68E8);
    // 0x8021BF20: jal         0x80005670
    // 0x8021BF24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x8021BF24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8021BF28: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021BF2C: sb          $zero, 0xA8($v0)
    MEM_B(0XA8, ctx->r2) = 0;
    // 0x8021BF30: addiu       $a1, $a1, -0x68E8
    ctx->r5 = ADD32(ctx->r5, -0X68E8);
    // 0x8021BF34: jal         0x80005670
    // 0x8021BF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_7;
    // 0x8021BF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8021BF3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8021BF40: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021BF44: sb          $t2, 0xA8($v0)
    MEM_B(0XA8, ctx->r2) = ctx->r10;
    // 0x8021BF48: addiu       $a1, $a1, -0x408C
    ctx->r5 = ADD32(ctx->r5, -0X408C);
    // 0x8021BF4C: jal         0x800058DC
    // 0x8021BF50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8021BF50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8021BF54: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8021BF58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021BF5C: sb          $t3, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r11;
    // 0x8021BF60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021BF64:
    // 0x8021BF64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021BF68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021BF6C: jr          $ra
    // 0x8021BF70: nop

    return;
    // 0x8021BF70: nop

;}
RECOMP_FUNC void M10_FUN_8021bf74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021BF74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021BF78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021BF7C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021BF80: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8021BF84: lbu         $t6, 0x1031($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1031);
    // 0x8021BF88: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021BF8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021BF90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8021BF94: bne         $t6, $at, L_8021BFA4
    if (ctx->r14 != ctx->r1) {
        // 0x8021BF98: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8021BFA4;
    }
    // 0x8021BF98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8021BF9C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8021BFA0: sb          $t7, 0x1031($s0)
    MEM_B(0X1031, ctx->r16) = ctx->r15;
L_8021BFA4:
    // 0x8021BFA4: jal         0x8021B790
    // 0x8021BFA8: nop

    LOOKUP_FUNC(0x8021B790)(rdram, ctx);
        goto after_0;
    // 0x8021BFA8: nop

    after_0:
    // 0x8021BFAC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BFB0: jal         0x8022C010
    // 0x8021BFB4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022C010)(rdram, ctx);
        goto after_1;
    // 0x8021BFB4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_1:
    // 0x8021BFB8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BFBC: jal         0x8022C010
    // 0x8021BFC0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022C010)(rdram, ctx);
        goto after_2;
    // 0x8021BFC0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_2:
    // 0x8021BFC4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BFC8: jal         0x8022F850
    // 0x8021BFCC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022F850)(rdram, ctx);
        goto after_3;
    // 0x8021BFCC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_3:
    // 0x8021BFD0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BFD4: jal         0x8022F850
    // 0x8021BFD8: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022F850)(rdram, ctx);
        goto after_4;
    // 0x8021BFD8: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_4:
    // 0x8021BFDC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BFE0: jal         0x8022FC38
    // 0x8021BFE4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022FC38)(rdram, ctx);
        goto after_5;
    // 0x8021BFE4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_5:
    // 0x8021BFE8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BFEC: jal         0x8022FC38
    // 0x8021BFF0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022FC38)(rdram, ctx);
        goto after_6;
    // 0x8021BFF0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_6:
    // 0x8021BFF4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021BFF8: jal         0x8022F99C
    // 0x8021BFFC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022F99C)(rdram, ctx);
        goto after_7;
    // 0x8021BFFC: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_7:
    // 0x8021C000: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C004: jal         0x8022F99C
    // 0x8021C008: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022F99C)(rdram, ctx);
        goto after_8;
    // 0x8021C008: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_8:
    // 0x8021C00C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C010: jal         0x8022D9EC
    // 0x8021C014: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022D9EC)(rdram, ctx);
        goto after_9;
    // 0x8021C014: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_9:
    // 0x8021C018: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C01C: jal         0x8022D9EC
    // 0x8021C020: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022D9EC)(rdram, ctx);
        goto after_10;
    // 0x8021C020: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_10:
    // 0x8021C024: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C028: jal         0x8022BD28
    // 0x8021C02C: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022BD28)(rdram, ctx);
        goto after_11;
    // 0x8021C02C: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_11:
    // 0x8021C030: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C034: jal         0x8022BD28
    // 0x8021C038: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022BD28)(rdram, ctx);
        goto after_12;
    // 0x8021C038: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_12:
    // 0x8021C03C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C040: jal         0x8022BECC
    // 0x8021C044: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022BECC)(rdram, ctx);
        goto after_13;
    // 0x8021C044: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_13:
    // 0x8021C048: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C04C: jal         0x8022BECC
    // 0x8021C050: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022BECC)(rdram, ctx);
        goto after_14;
    // 0x8021C050: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_14:
    // 0x8021C054: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C058: jal         0x8022FFFC
    // 0x8021C05C: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x8022FFFC)(rdram, ctx);
        goto after_15;
    // 0x8021C05C: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_15:
    // 0x8021C060: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C064: jal         0x8022FFFC
    // 0x8021C068: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x8022FFFC)(rdram, ctx);
        goto after_16;
    // 0x8021C068: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_16:
    // 0x8021C06C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C070: jal         0x802300F0
    // 0x8021C074: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    LOOKUP_FUNC(0x802300F0)(rdram, ctx);
        goto after_17;
    // 0x8021C074: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    after_17:
    // 0x8021C078: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C07C: jal         0x802300F0
    // 0x8021C080: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    LOOKUP_FUNC(0x802300F0)(rdram, ctx);
        goto after_18;
    // 0x8021C080: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    after_18:
    // 0x8021C084: lh          $v0, 0x44E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X44E);
    // 0x8021C088: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8021C08C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8021C090: blez        $v0, L_8021C0A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8021C094: nop
    
            goto L_8021C0A4;
    }
    // 0x8021C094: nop

    // 0x8021C098: lh          $t8, 0x7EA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X7EA);
    // 0x8021C09C: bgtzl       $t8, L_8021C0F0
    if (SIGNED(ctx->r24) > 0) {
        // 0x8021C0A0: lbu         $t5, 0x1031($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X1031);
            goto L_8021C0F0;
    }
    goto skip_0;
    // 0x8021C0A0: lbu         $t5, 0x1031($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1031);
    skip_0:
L_8021C0A4:
    // 0x8021C0A4: bgtz        $v0, L_8021C0C0
    if (SIGNED(ctx->r2) > 0) {
        // 0x8021C0A8: addiu       $t1, $zero, 0x5
        ctx->r9 = ADD32(0, 0X5);
            goto L_8021C0C0;
    }
    // 0x8021C0A8: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8021C0AC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8021C0B0: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8021C0B4: sb          $t9, 0x744($s0)
    MEM_B(0X744, ctx->r16) = ctx->r25;
    // 0x8021C0B8: b           L_8021C0CC
    // 0x8021C0BC: sh          $t0, 0x4EA($s0)
    MEM_H(0X4EA, ctx->r16) = ctx->r8;
        goto L_8021C0CC;
    // 0x8021C0BC: sh          $t0, 0x4EA($s0)
    MEM_H(0X4EA, ctx->r16) = ctx->r8;
L_8021C0C0:
    // 0x8021C0C0: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8021C0C4: sb          $t1, 0xAE0($s0)
    MEM_B(0XAE0, ctx->r16) = ctx->r9;
    // 0x8021C0C8: sh          $t2, 0x886($s0)
    MEM_H(0X886, ctx->r16) = ctx->r10;
L_8021C0CC:
    // 0x8021C0CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021C0D0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C0D4: addiu       $a1, $a1, -0x33D0
    ctx->r5 = ADD32(ctx->r5, -0X33D0);
    // 0x8021C0D8: sb          $t3, 0xAE($a0)
    MEM_B(0XAE, ctx->r4) = ctx->r11;
    // 0x8021C0DC: jal         0x800058DC
    // 0x8021C0E0: sb          $t4, 0x1031($s0)
    MEM_B(0X1031, ctx->r16) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_19;
    // 0x8021C0E0: sb          $t4, 0x1031($s0)
    MEM_B(0X1031, ctx->r16) = ctx->r12;
    after_19:
    // 0x8021C0E4: b           L_8021C188
    // 0x8021C0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021C188;
    // 0x8021C0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021C0EC: lbu         $t5, 0x1031($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1031);
L_8021C0F0:
    // 0x8021C0F0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8021C0F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021C0F8: bne         $t5, $at, L_8021C114
    if (ctx->r13 != ctx->r1) {
        // 0x8021C0FC: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_8021C114;
    }
    // 0x8021C0FC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8021C100: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C104: jal         0x800058DC
    // 0x8021C108: addiu       $a1, $a1, -0x3E68
    ctx->r5 = ADD32(ctx->r5, -0X3E68);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_20;
    // 0x8021C108: addiu       $a1, $a1, -0x3E68
    ctx->r5 = ADD32(ctx->r5, -0X3E68);
    after_20:
    // 0x8021C10C: b           L_8021C188
    // 0x8021C110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021C188;
    // 0x8021C110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021C114:
    // 0x8021C114: lhu         $t6, -0x6B88($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B88);
    // 0x8021C118: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x8021C11C: beql        $t7, $zero, L_8021C188
    if (ctx->r15 == 0) {
        // 0x8021C120: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021C188;
    }
    goto skip_1;
    // 0x8021C120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8021C124: lhu         $v0, 0x2C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2C);
    // 0x8021C128: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021C12C: beq         $v0, $at, L_8021C184
    if (ctx->r2 == ctx->r1) {
        // 0x8021C130: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8021C184;
    }
    // 0x8021C130: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021C134: beq         $v0, $at, L_8021C184
    if (ctx->r2 == ctx->r1) {
        // 0x8021C138: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021C184;
    }
    // 0x8021C138: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021C13C: beql        $v0, $at, L_8021C188
    if (ctx->r2 == ctx->r1) {
        // 0x8021C140: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021C188;
    }
    goto skip_2;
    // 0x8021C140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8021C144: jal         0x80236C9C
    // 0x8021C148: nop

    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_21;
    // 0x8021C148: nop

    after_21:
    // 0x8021C14C: bne         $v0, $zero, L_8021C184
    if (ctx->r2 != 0) {
        // 0x8021C150: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8021C184;
    }
    // 0x8021C150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021C154: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021C158: jal         0x80005670
    // 0x8021C15C: addiu       $a1, $a1, -0x6518
    ctx->r5 = ADD32(ctx->r5, -0X6518);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_22;
    // 0x8021C15C: addiu       $a1, $a1, -0x6518
    ctx->r5 = ADD32(ctx->r5, -0X6518);
    after_22:
    // 0x8021C160: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8021C164: sb          $zero, 0x94($v0)
    MEM_B(0X94, ctx->r2) = 0;
    // 0x8021C168: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8021C16C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C170: sw          $t8, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r24;
    // 0x8021C174: sb          $t9, 0x1031($s0)
    MEM_B(0X1031, ctx->r16) = ctx->r25;
    // 0x8021C178: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021C17C: jal         0x800058DC
    // 0x8021C180: addiu       $a1, $a1, -0x2748
    ctx->r5 = ADD32(ctx->r5, -0X2748);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_23;
    // 0x8021C180: addiu       $a1, $a1, -0x2748
    ctx->r5 = ADD32(ctx->r5, -0X2748);
    after_23:
L_8021C184:
    // 0x8021C184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021C188:
    // 0x8021C188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021C18C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021C190: jr          $ra
    // 0x8021C194: nop

    return;
    // 0x8021C194: nop

;}
RECOMP_FUNC void M10_FUN_8021c198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021C198: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C19C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C1A0: lbu         $v0, 0x1030($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1030);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021c1a4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021c1a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021C1A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8021C1A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021C1AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8021C1B0: bne         $v0, $zero, L_8021C1C4
    if (ctx->r2 != 0) {
        // 0x8021C1B4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_8021C1C4;
    }
    // 0x8021C1B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8021C1B8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C1BC: b           L_8021C1CC
    // 0x8021C1C0: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_8021C1CC;
    // 0x8021C1C0: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_8021C1C4:
    // 0x8021C1C4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021C1C8: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_8021C1CC:
    // 0x8021C1CC: bne         $v0, $zero, L_8021C1E0
    if (ctx->r2 != 0) {
        // 0x8021C1D0: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_8021C1E0;
    }
    // 0x8021C1D0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021C1D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021C1D8: b           L_8021C1E4
    // 0x8021C1DC: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
        goto L_8021C1E4;
    // 0x8021C1DC: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_8021C1E0:
    // 0x8021C1E0: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_8021C1E4:
    // 0x8021C1E4: lb          $t8, 0x47D($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X47D);
    // 0x8021C1E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8021C1EC: sb          $t6, 0x1032($a2)
    MEM_B(0X1032, ctx->r6) = ctx->r14;
    // 0x8021C1F0: bgezl       $t8, L_8021C3FC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8021C1F4: lbu         $t5, 0x1031($a2)
        ctx->r13 = MEM_BU(ctx->r6, 0X1031);
            goto L_8021C3FC;
    }
    goto skip_0;
    // 0x8021C1F4: lbu         $t5, 0x1031($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1031);
    skip_0:
    // 0x8021C1F8: lb          $t0, 0x819($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X819);
    // 0x8021C1FC: bgezl       $t0, L_8021C3FC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8021C200: lbu         $t5, 0x1031($a2)
        ctx->r13 = MEM_BU(ctx->r6, 0X1031);
            goto L_8021C3FC;
    }
    goto skip_1;
    // 0x8021C200: lbu         $t5, 0x1031($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1031);
    skip_1:
    // 0x8021C204: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x8021C208: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8021C20C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8021C210: sll         $t2, $t1, 11
    ctx->r10 = S32(ctx->r9 << 11);
    // 0x8021C214: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x8021C218: sb          $t3, 0x98($t4)
    MEM_B(0X98, ctx->r12) = ctx->r11;
    // 0x8021C21C: lw          $t5, 0x2D4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2D4);
    // 0x8021C220: addiu       $t6, $t6, 0x42A0
    ctx->r14 = ADD32(ctx->r14, 0X42A0);
    // 0x8021C224: bnel        $t5, $zero, L_8021C234
    if (ctx->r13 != 0) {
        // 0x8021C228: lw          $t7, 0x2D4($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X2D4);
            goto L_8021C234;
    }
    goto skip_2;
    // 0x8021C228: lw          $t7, 0x2D4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2D4);
    skip_2:
    // 0x8021C22C: sw          $t6, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r14;
    // 0x8021C230: lw          $t7, 0x2D4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2D4);
L_8021C234:
    // 0x8021C234: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8021C238: addiu       $t8, $t8, 0x42A0
    ctx->r24 = ADD32(ctx->r24, 0X42A0);
    // 0x8021C23C: bnel        $t7, $zero, L_8021C24C
    if (ctx->r15 != 0) {
        // 0x8021C240: lbu         $t9, 0x2D8($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X2D8);
            goto L_8021C24C;
    }
    goto skip_3;
    // 0x8021C240: lbu         $t9, 0x2D8($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D8);
    skip_3:
    // 0x8021C244: sw          $t8, 0x2D4($a1)
    MEM_W(0X2D4, ctx->r5) = ctx->r24;
    // 0x8021C248: lbu         $t9, 0x2D8($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D8);
L_8021C24C:
    // 0x8021C24C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021C250: bnel        $t9, $at, L_8021C288
    if (ctx->r25 != ctx->r1) {
        // 0x8021C254: lbu         $t3, 0x818($a2)
        ctx->r11 = MEM_BU(ctx->r6, 0X818);
            goto L_8021C288;
    }
    goto skip_4;
    // 0x8021C254: lbu         $t3, 0x818($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X818);
    skip_4:
    // 0x8021C258: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8021C25C: jal         0x8037C50C
    // 0x8021C260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8037C50C)(rdram, ctx);
        goto after_0;
    // 0x8021C260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021C264: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8021C268: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021C26C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C270: lbu         $t0, 0x2D8($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2D8);
    // 0x8021C274: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8021C278: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C27C: sb          $t1, 0x2D8($a1)
    MEM_B(0X2D8, ctx->r5) = ctx->r9;
    // 0x8021C280: sb          $t0, 0x2D9($a1)
    MEM_B(0X2D9, ctx->r5) = ctx->r8;
    // 0x8021C284: lbu         $t3, 0x818($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X818);
L_8021C288:
    // 0x8021C288: lbu         $t7, 0x47C($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X47C);
    // 0x8021C28C: lbu         $t0, 0x819($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X819);
    // 0x8021C290: ori         $v0, $t3, 0x1
    ctx->r2 = ctx->r11 | 0X1;
    // 0x8021C294: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8021C298: lbu         $t7, 0x47D($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X47D);
    // 0x8021C29C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8021C2A0: andi        $t2, $t0, 0xFF7F
    ctx->r10 = ctx->r8 & 0XFF7F;
    // 0x8021C2A4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8021C2A8: sb          $v0, 0x818($a2)
    MEM_B(0X818, ctx->r6) = ctx->r2;
    // 0x8021C2AC: ori         $t0, $v0, 0x80
    ctx->r8 = ctx->r2 | 0X80;
    // 0x8021C2B0: sb          $t2, 0x819($a2)
    MEM_B(0X819, ctx->r6) = ctx->r10;
    // 0x8021C2B4: sb          $t0, 0x818($a2)
    MEM_B(0X818, ctx->r6) = ctx->r8;
    // 0x8021C2B8: lw          $t1, 0x818($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X818);
    // 0x8021C2BC: sb          $t9, 0x47C($a2)
    MEM_B(0X47C, ctx->r6) = ctx->r25;
    // 0x8021C2C0: andi        $t6, $t7, 0xFF7F
    ctx->r14 = ctx->r15 & 0XFF7F;
    // 0x8021C2C4: lbu         $t7, 0x47C($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X47C);
    // 0x8021C2C8: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x8021C2CC: sll         $t5, $t3, 7
    ctx->r13 = S32(ctx->r11 << 7);
    // 0x8021C2D0: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x8021C2D4: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8021C2D8: sll         $t4, $t2, 7
    ctx->r12 = S32(ctx->r10 << 7);
    // 0x8021C2DC: andi        $t5, $t7, 0xFF7F
    ctx->r13 = ctx->r15 & 0XFF7F;
    // 0x8021C2E0: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x8021C2E4: sb          $t8, 0x47D($a2)
    MEM_B(0X47D, ctx->r6) = ctx->r24;
    // 0x8021C2E8: sb          $t6, 0x47C($a2)
    MEM_B(0X47C, ctx->r6) = ctx->r14;
    // 0x8021C2EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8021C2F0: sb          $t9, 0x2DB($a1)
    MEM_B(0X2DB, ctx->r5) = ctx->r25;
    // 0x8021C2F4: sb          $t9, 0x2DB($a0)
    MEM_B(0X2DB, ctx->r4) = ctx->r25;
    // 0x8021C2F8: sb          $zero, 0x2DE($a1)
    MEM_B(0X2DE, ctx->r5) = 0;
    // 0x8021C2FC: sb          $zero, 0x2DE($a0)
    MEM_B(0X2DE, ctx->r4) = 0;
    // 0x8021C300: sb          $zero, 0x2E8($a1)
    MEM_B(0X2E8, ctx->r5) = 0;
    // 0x8021C304: sb          $zero, 0x2E8($a0)
    MEM_B(0X2E8, ctx->r4) = 0;
    // 0x8021C308: sb          $zero, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = 0;
    // 0x8021C30C: sb          $zero, 0x2F8($a0)
    MEM_B(0X2F8, ctx->r4) = 0;
    // 0x8021C310: sh          $zero, 0x9A($a1)
    MEM_H(0X9A, ctx->r5) = 0;
    // 0x8021C314: sh          $zero, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = 0;
    // 0x8021C318: sb          $zero, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = 0;
    // 0x8021C31C: sb          $zero, 0x2F0($a0)
    MEM_B(0X2F0, ctx->r4) = 0;
    // 0x8021C320: sb          $zero, 0x2DD($a1)
    MEM_B(0X2DD, ctx->r5) = 0;
    // 0x8021C324: sb          $zero, 0x2DD($a0)
    MEM_B(0X2DD, ctx->r4) = 0;
    // 0x8021C328: sb          $zero, 0x304($a1)
    MEM_B(0X304, ctx->r5) = 0;
    // 0x8021C32C: sb          $zero, 0x304($a0)
    MEM_B(0X304, ctx->r4) = 0;
    // 0x8021C330: sb          $zero, 0x2FA($a1)
    MEM_B(0X2FA, ctx->r5) = 0;
    // 0x8021C334: sb          $zero, 0x2FA($a0)
    MEM_B(0X2FA, ctx->r4) = 0;
    // 0x8021C338: sb          $zero, 0x375($a1)
    MEM_B(0X375, ctx->r5) = 0;
    // 0x8021C33C: sb          $zero, 0x375($a0)
    MEM_B(0X375, ctx->r4) = 0;
    // 0x8021C340: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021C344: jal         0x802321FC
    // 0x8021C348: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x802321FC)(rdram, ctx);
        goto after_1;
    // 0x8021C348: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8021C34C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021C350: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8021C354: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8021C358:
    // 0x8021C358: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x8021C35C: addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
    // 0x8021C360: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8021C364: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8021C368: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8021C36C: sb          $zero, 0x2E0($v0)
    MEM_B(0X2E0, ctx->r2) = 0;
    // 0x8021C370: bne         $at, $zero, L_8021C358
    if (ctx->r1 != 0) {
        // 0x8021C374: sb          $zero, 0x2E0($t0)
        MEM_B(0X2E0, ctx->r8) = 0;
            goto L_8021C358;
    }
    // 0x8021C374: sb          $zero, 0x2E0($t0)
    MEM_B(0X2E0, ctx->r8) = 0;
    // 0x8021C378: jal         0x80231CEC
    // 0x8021C37C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80231CEC)(rdram, ctx);
        goto after_2;
    // 0x8021C37C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8021C380: jal         0x80231B28
    // 0x8021C384: nop

    LOOKUP_FUNC(0x80231B28)(rdram, ctx);
        goto after_3;
    // 0x8021C384: nop

    after_3:
    // 0x8021C388: jal         0x8022C0A0
    // 0x8021C38C: nop

    LOOKUP_FUNC(0x8022C0A0)(rdram, ctx);
        goto after_4;
    // 0x8021C38C: nop

    after_4:
    // 0x8021C390: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8021C394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8021C398: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C39C: sb          $zero, 0xB3($a3)
    MEM_B(0XB3, ctx->r7) = 0;
    // 0x8021C3A0: sw          $zero, 0x9C($a3)
    MEM_W(0X9C, ctx->r7) = 0;
    // 0x8021C3A4: sb          $zero, 0x95($a3)
    MEM_B(0X95, ctx->r7) = 0;
    // 0x8021C3A8: lbu         $t1, 0x2D8($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2D8);
    // 0x8021C3AC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8021C3B0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C3B4: bne         $t1, $at, L_8021C3DC
    if (ctx->r9 != ctx->r1) {
        // 0x8021C3B8: addiu       $t4, $zero, 0x7
        ctx->r12 = ADD32(0, 0X7);
            goto L_8021C3DC;
    }
    // 0x8021C3B8: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8021C3BC: lbu         $t2, 0x2D9($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2D9);
    // 0x8021C3C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8021C3C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8021C3C8: slti        $at, $t2, 0x1E
    ctx->r1 = SIGNED(ctx->r10) < 0X1E ? 1 : 0;
    // 0x8021C3CC: bne         $at, $zero, L_8021C3DC
    if (ctx->r1 != 0) {
        // 0x8021C3D0: nop
    
            goto L_8021C3DC;
    }
    // 0x8021C3D0: nop

    // 0x8021C3D4: sb          $t3, 0x2DA($a0)
    MEM_B(0X2DA, ctx->r4) = ctx->r11;
    // 0x8021C3D8: sb          $t7, 0x2FA($a0)
    MEM_B(0X2FA, ctx->r4) = ctx->r15;
L_8021C3DC:
    // 0x8021C3DC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C3E0: sb          $t4, 0x1031($a2)
    MEM_B(0X1031, ctx->r6) = ctx->r12;
    // 0x8021C3E4: addiu       $a1, $a1, -0x3B40
    ctx->r5 = ADD32(ctx->r5, -0X3B40);
    // 0x8021C3E8: jal         0x800058DC
    // 0x8021C3EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8021C3EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x8021C3F0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C3F4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C3F8: lbu         $t5, 0x1031($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1031);
L_8021C3FC:
    // 0x8021C3FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021C400: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8021C404: bne         $t5, $at, L_8021C420
    if (ctx->r13 != ctx->r1) {
        // 0x8021C408: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_8021C420;
    }
    // 0x8021C408: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8021C40C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C410: jal         0x800058DC
    // 0x8021C414: addiu       $a1, $a1, -0x408C
    ctx->r5 = ADD32(ctx->r5, -0X408C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8021C414: addiu       $a1, $a1, -0x408C
    ctx->r5 = ADD32(ctx->r5, -0X408C);
    after_6:
    // 0x8021C418: b           L_8021C4B4
    // 0x8021C41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021C4B4;
    // 0x8021C41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021C420:
    // 0x8021C420: lhu         $t6, -0x6B88($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B88);
    // 0x8021C424: andi        $t8, $t6, 0x1000
    ctx->r24 = ctx->r14 & 0X1000;
    // 0x8021C428: beql        $t8, $zero, L_8021C4B4
    if (ctx->r24 == 0) {
        // 0x8021C42C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021C4B4;
    }
    goto skip_5;
    // 0x8021C42C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8021C430: jal         0x80236788
    // 0x8021C434: nop

    LOOKUP_FUNC(0x80236788)(rdram, ctx);
        goto after_7;
    // 0x8021C434: nop

    after_7:
    // 0x8021C438: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C43C: beq         $v0, $zero, L_8021C4B0
    if (ctx->r2 == 0) {
        // 0x8021C440: addiu       $a2, $a2, -0x4410
        ctx->r6 = ADD32(ctx->r6, -0X4410);
            goto L_8021C4B0;
    }
    // 0x8021C440: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C444: lhu         $v0, 0x2C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2C);
    // 0x8021C448: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021C44C: beq         $v0, $at, L_8021C4B0
    if (ctx->r2 == ctx->r1) {
        // 0x8021C450: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8021C4B0;
    }
    // 0x8021C450: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021C454: beq         $v0, $at, L_8021C4B0
    if (ctx->r2 == ctx->r1) {
        // 0x8021C458: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021C4B0;
    }
    // 0x8021C458: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021C45C: beql        $v0, $at, L_8021C4B4
    if (ctx->r2 == ctx->r1) {
        // 0x8021C460: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021C4B4;
    }
    goto skip_6;
    // 0x8021C460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8021C464: jal         0x80236C9C
    // 0x8021C468: nop

    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_8;
    // 0x8021C468: nop

    after_8:
    // 0x8021C46C: bne         $v0, $zero, L_8021C4B0
    if (ctx->r2 != 0) {
        // 0x8021C470: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8021C4B0;
    }
    // 0x8021C470: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8021C474: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021C478: jal         0x80005670
    // 0x8021C47C: addiu       $a1, $a1, -0x6518
    ctx->r5 = ADD32(ctx->r5, -0X6518);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_9;
    // 0x8021C47C: addiu       $a1, $a1, -0x6518
    ctx->r5 = ADD32(ctx->r5, -0X6518);
    after_9:
    // 0x8021C480: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8021C484: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C488: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8021C48C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C490: sb          $t0, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r8;
    // 0x8021C494: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8021C498: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C49C: sw          $t9, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r25;
    // 0x8021C4A0: sb          $t1, 0x1031($a2)
    MEM_B(0X1031, ctx->r6) = ctx->r9;
    // 0x8021C4A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8021C4A8: jal         0x800058DC
    // 0x8021C4AC: addiu       $a1, $a1, -0x2748
    ctx->r5 = ADD32(ctx->r5, -0X2748);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x8021C4AC: addiu       $a1, $a1, -0x2748
    ctx->r5 = ADD32(ctx->r5, -0X2748);
    after_10:
L_8021C4B0:
    // 0x8021C4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021C4B4:
    // 0x8021C4B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8021C4B8: jr          $ra
    // 0x8021C4BC: nop

    return;
    // 0x8021C4BC: nop

;}
RECOMP_FUNC void M10_FUN_8021c4c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021C4C0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C4C4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C4C8: lbu         $v0, 0x1030($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1030);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021c4cc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021c4cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021C4CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8021C4D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8021C4D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021C4D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021C4DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8021C4E0: bne         $v0, $zero, L_8021C4F4
    if (ctx->r2 != 0) {
        // 0x8021C4E4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8021C4F4;
    }
    // 0x8021C4E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8021C4E8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021C4EC: b           L_8021C4FC
    // 0x8021C4F0: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
        goto L_8021C4FC;
    // 0x8021C4F0: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
L_8021C4F4:
    // 0x8021C4F4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021C4F8: addiu       $s0, $s0, -0x3C28
    ctx->r16 = ADD32(ctx->r16, -0X3C28);
L_8021C4FC:
    // 0x8021C4FC: bne         $v0, $zero, L_8021C514
    if (ctx->r2 != 0) {
        // 0x8021C500: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8021C514;
    }
    // 0x8021C500: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8021C504: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8021C508: addiu       $t6, $t6, -0x3C28
    ctx->r14 = ADD32(ctx->r14, -0X3C28);
    // 0x8021C50C: b           L_8021C51C
    // 0x8021C510: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_8021C51C;
    // 0x8021C510: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8021C514:
    // 0x8021C514: addiu       $t7, $t7, -0x3FC4
    ctx->r15 = ADD32(ctx->r15, -0X3FC4);
    // 0x8021C518: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8021C51C:
    // 0x8021C51C: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
    // 0x8021C520: jal         0x8021B790
    // 0x8021C524: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8021B790)(rdram, ctx);
        goto after_0;
    // 0x8021C524: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021C528: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C52C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C530: lbu         $t8, 0x47C($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X47C);
    // 0x8021C534: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8021C538: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8021C53C: bnel        $t9, $zero, L_8021C6E8
    if (ctx->r25 != 0) {
        // 0x8021C540: lbu         $v1, 0x2D8($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
            goto L_8021C6E8;
    }
    goto skip_0;
    // 0x8021C540: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    skip_0:
    // 0x8021C544: lbu         $t0, 0x818($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X818);
    // 0x8021C548: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8021C54C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8021C550: bnel        $t1, $zero, L_8021C6E8
    if (ctx->r9 != 0) {
        // 0x8021C554: lbu         $v1, 0x2D8($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
            goto L_8021C6E8;
    }
    goto skip_1;
    // 0x8021C554: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    skip_1:
    // 0x8021C558: sb          $zero, 0xAD0($a2)
    MEM_B(0XAD0, ctx->r6) = 0;
    // 0x8021C55C: sb          $zero, 0xAC6($a2)
    MEM_B(0XAC6, ctx->r6) = 0;
    // 0x8021C560: sb          $zero, 0x734($a2)
    MEM_B(0X734, ctx->r6) = 0;
    // 0x8021C564: sb          $zero, 0x72A($a2)
    MEM_B(0X72A, ctx->r6) = 0;
    // 0x8021C568: lw          $t5, 0x9C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X9C);
    // 0x8021C56C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8021C570: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8021C574: beq         $t5, $zero, L_8021C5D0
    if (ctx->r13 == 0) {
        // 0x8021C578: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8021C5D0;
    }
    // 0x8021C578: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021C57C: jal         0x8022F558
    // 0x8021C580: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8022F558)(rdram, ctx);
        goto after_1;
    // 0x8021C580: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8021C584: lbu         $v0, 0x2FD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2FD);
    // 0x8021C588: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C58C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C590: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x8021C594: beq         $at, $zero, L_8021C5A0
    if (ctx->r1 == 0) {
        // 0x8021C598: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8021C5A0;
    }
    // 0x8021C598: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8021C59C: sb          $t6, 0x2FD($s0)
    MEM_B(0X2FD, ctx->r16) = ctx->r14;
L_8021C5A0:
    // 0x8021C5A0: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    // 0x8021C5A4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8021C5A8: beq         $v1, $at, L_8021C5B8
    if (ctx->r3 == ctx->r1) {
        // 0x8021C5AC: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8021C5B8;
    }
    // 0x8021C5AC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8021C5B0: bnel        $v1, $at, L_8021C5F4
    if (ctx->r3 != ctx->r1) {
        // 0x8021C5B4: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8021C5F4;
    }
    goto skip_2;
    // 0x8021C5B4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    skip_2:
L_8021C5B8:
    // 0x8021C5B8: jal         0x80379054
    // 0x8021C5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80379054)(rdram, ctx);
        goto after_2;
    // 0x8021C5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8021C5C0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C5C4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C5C8: b           L_8021C5F0
    // 0x8021C5CC: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
        goto L_8021C5F0;
    // 0x8021C5CC: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
L_8021C5D0:
    // 0x8021C5D0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021C5D4: sh          $zero, 0x312($v0)
    MEM_H(0X312, ctx->r2) = 0;
    // 0x8021C5D8: sb          $t7, 0x2DB($v0)
    MEM_B(0X2DB, ctx->r2) = ctx->r15;
    // 0x8021C5DC: jal         0x80005670
    // 0x8021C5E0: addiu       $a1, $a1, -0x6938
    ctx->r5 = ADD32(ctx->r5, -0X6938);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x8021C5E0: addiu       $a1, $a1, -0x6938
    ctx->r5 = ADD32(ctx->r5, -0X6938);
    after_3:
    // 0x8021C5E4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C5E8: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C5EC: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
L_8021C5F0:
    // 0x8021C5F0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_8021C5F4:
    // 0x8021C5F4: bne         $at, $zero, L_8021C624
    if (ctx->r1 != 0) {
        // 0x8021C5F8: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8021C624;
    }
    // 0x8021C5F8: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8021C5FC: beql        $at, $zero, L_8021C628
    if (ctx->r1 == 0) {
        // 0x8021C600: lw          $t0, 0x448($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X448);
            goto L_8021C628;
    }
    goto skip_3;
    // 0x8021C600: lw          $t0, 0x448($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X448);
    skip_3:
    // 0x8021C604: lbu         $t8, 0x2DA($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2DA);
    // 0x8021C608: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8021C60C: bnel        $t8, $zero, L_8021C628
    if (ctx->r24 != 0) {
        // 0x8021C610: lw          $t0, 0x448($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X448);
            goto L_8021C628;
    }
    goto skip_4;
    // 0x8021C610: lw          $t0, 0x448($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X448);
    skip_4:
    // 0x8021C614: jal         0x80378B48
    // 0x8021C618: sh          $zero, 0x312($t9)
    MEM_H(0X312, ctx->r25) = 0;
    LOOKUP_FUNC(0x80378B48)(rdram, ctx);
        goto after_4;
    // 0x8021C618: sh          $zero, 0x312($t9)
    MEM_H(0X312, ctx->r25) = 0;
    after_4:
    // 0x8021C61C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C620: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
L_8021C624:
    // 0x8021C624: lw          $t0, 0x448($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X448);
L_8021C628:
    // 0x8021C628: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8021C62C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8021C630: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8021C634: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C638: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x8021C63C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8021C640: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8021C644: swc1        $f4, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f4.u32l;
    // 0x8021C648: lw          $t4, 0x448($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X448);
    // 0x8021C64C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8021C650: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x8021C654: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8021C658: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8021C65C: swc1        $f6, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f6.u32l;
    // 0x8021C660: lw          $t8, 0x448($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X448);
    // 0x8021C664: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8021C668: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x8021C66C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8021C670: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8021C674: swc1        $f8, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->f8.u32l;
    // 0x8021C678: lw          $t2, 0x448($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X448);
    // 0x8021C67C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8021C680: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x8021C684: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8021C688: lh          $t6, 0x12($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X12);
    // 0x8021C68C: sh          $t6, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r14;
    // 0x8021C690: lbu         $t7, 0x2D8($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2D8);
    // 0x8021C694: bne         $t7, $at, L_8021C6C8
    if (ctx->r15 != ctx->r1) {
        // 0x8021C698: nop
    
            goto L_8021C6C8;
    }
    // 0x8021C698: nop

    // 0x8021C69C: lbu         $t8, 0x375($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X375);
    // 0x8021C6A0: blez        $t8, L_8021C6C8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8021C6A4: nop
    
            goto L_8021C6C8;
    }
    // 0x8021C6A4: nop

    // 0x8021C6A8: jal         0x8037F410
    // 0x8021C6AC: nop

    LOOKUP_FUNC(0x8037F410)(rdram, ctx);
        goto after_5;
    // 0x8021C6AC: nop

    after_5:
    // 0x8021C6B0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021C6B4: addiu       $a1, $a1, -0x36D8
    ctx->r5 = ADD32(ctx->r5, -0X36D8);
    // 0x8021C6B8: jal         0x800058DC
    // 0x8021C6BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8021C6BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x8021C6C0: b           L_8021C918
    // 0x8021C6C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021C918;
    // 0x8021C6C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021C6C8:
    // 0x8021C6C8: jal         0x800058DC
    // 0x8021C6CC: addiu       $a1, $a1, -0x36CC
    ctx->r5 = ADD32(ctx->r5, -0X36CC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x8021C6CC: addiu       $a1, $a1, -0x36CC
    ctx->r5 = ADD32(ctx->r5, -0X36CC);
    after_7:
    // 0x8021C6D0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C6D4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C6D8: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8021C6DC: b           L_8021C914
    // 0x8021C6E0: sb          $t9, 0x1031($a2)
    MEM_B(0X1031, ctx->r6) = ctx->r25;
        goto L_8021C914;
    // 0x8021C6E0: sb          $t9, 0x1031($a2)
    MEM_B(0X1031, ctx->r6) = ctx->r25;
    // 0x8021C6E4: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
L_8021C6E8:
    // 0x8021C6E8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8021C6EC: bne         $at, $zero, L_8021C70C
    if (ctx->r1 != 0) {
        // 0x8021C6F0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8021C70C;
    }
    // 0x8021C6F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8021C6F4: beq         $v1, $at, L_8021C70C
    if (ctx->r3 == ctx->r1) {
        // 0x8021C6F8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8021C70C;
    }
    // 0x8021C6F8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8021C6FC: beq         $v1, $at, L_8021C70C
    if (ctx->r3 == ctx->r1) {
        // 0x8021C700: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8021C70C;
    }
    // 0x8021C700: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021C704: bnel        $v1, $at, L_8021C734
    if (ctx->r3 != ctx->r1) {
        // 0x8021C708: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8021C734;
    }
    goto skip_5;
    // 0x8021C708: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_5:
L_8021C70C:
    // 0x8021C70C: jal         0x8022B66C
    // 0x8021C710: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8022B66C)(rdram, ctx);
        goto after_8;
    // 0x8021C710: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x8021C714: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8021C718: jal         0x8022BBB0
    // 0x8021C71C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8022BBB0)(rdram, ctx);
        goto after_9;
    // 0x8021C71C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_9:
    // 0x8021C720: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C724: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C728: b           L_8021C7B0
    // 0x8021C72C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
        goto L_8021C7B0;
    // 0x8021C72C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8021C730: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8021C734:
    // 0x8021C734: beq         $v1, $at, L_8021C74C
    if (ctx->r3 == ctx->r1) {
        // 0x8021C738: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_8021C74C;
    }
    // 0x8021C738: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8021C73C: bne         $at, $zero, L_8021C764
    if (ctx->r1 != 0) {
        // 0x8021C740: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8021C764;
    }
    // 0x8021C740: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8021C744: beql        $at, $zero, L_8021C768
    if (ctx->r1 == 0) {
        // 0x8021C748: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8021C768;
    }
    goto skip_6;
    // 0x8021C748: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_6:
L_8021C74C:
    // 0x8021C74C: jal         0x8022BA44
    // 0x8021C750: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8022BA44)(rdram, ctx);
        goto after_10;
    // 0x8021C750: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x8021C754: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C758: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C75C: b           L_8021C7B0
    // 0x8021C760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8021C7B0;
    // 0x8021C760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8021C764:
    // 0x8021C764: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8021C768:
    // 0x8021C768: beq         $v1, $at, L_8021C778
    if (ctx->r3 == ctx->r1) {
        // 0x8021C76C: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8021C778;
    }
    // 0x8021C76C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8021C770: bnel        $v1, $at, L_8021C794
    if (ctx->r3 != ctx->r1) {
        // 0x8021C774: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021C794;
    }
    goto skip_7;
    // 0x8021C774: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    skip_7:
L_8021C778:
    // 0x8021C778: jal         0x8022BB28
    // 0x8021C77C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8022BB28)(rdram, ctx);
        goto after_11;
    // 0x8021C77C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x8021C780: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C784: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C788: b           L_8021C7B0
    // 0x8021C78C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8021C7B0;
    // 0x8021C78C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8021C790: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
L_8021C794:
    // 0x8021C794: bne         $v1, $at, L_8021C7B0
    if (ctx->r3 != ctx->r1) {
        // 0x8021C798: nop
    
            goto L_8021C7B0;
    }
    // 0x8021C798: nop

    // 0x8021C79C: jal         0x8022C1B4
    // 0x8021C7A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8022C1B4)(rdram, ctx);
        goto after_12;
    // 0x8021C7A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x8021C7A4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C7A8: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C7AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8021C7B0:
    // 0x8021C7B0: beq         $a1, $zero, L_8021C914
    if (ctx->r5 == 0) {
        // 0x8021C7B4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8021C914;
    }
    // 0x8021C7B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8021C7B8: lbu         $t0, 0xB3($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XB3);
    // 0x8021C7BC: sw          $a1, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r5;
    // 0x8021C7C0: bnel        $t0, $zero, L_8021C7E8
    if (ctx->r8 != 0) {
        // 0x8021C7C4: lbu         $t1, 0x1030($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X1030);
            goto L_8021C7E8;
    }
    goto skip_8;
    // 0x8021C7C4: lbu         $t1, 0x1030($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1030);
    skip_8:
    // 0x8021C7C8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021C7CC: jal         0x80005670
    // 0x8021C7D0: addiu       $a1, $a1, -0x6938
    ctx->r5 = ADD32(ctx->r5, -0X6938);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_13;
    // 0x8021C7D0: addiu       $a1, $a1, -0x6938
    ctx->r5 = ADD32(ctx->r5, -0X6938);
    after_13:
    // 0x8021C7D4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C7D8: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C7DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8021C7E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8021C7E4: lbu         $t1, 0x1030($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1030);
L_8021C7E8:
    // 0x8021C7E8: beql        $t1, $zero, L_8021C824
    if (ctx->r9 == 0) {
        // 0x8021C7EC: lbu         $v1, 0x2D8($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
            goto L_8021C824;
    }
    goto skip_9;
    // 0x8021C7EC: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    skip_9:
    // 0x8021C7F0: lbu         $t2, 0xB3($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XB3);
    // 0x8021C7F4: bnel        $t2, $zero, L_8021C824
    if (ctx->r10 != 0) {
        // 0x8021C7F8: lbu         $v1, 0x2D8($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
            goto L_8021C824;
    }
    goto skip_10;
    // 0x8021C7F8: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    skip_10:
    // 0x8021C7FC: lbu         $t3, 0x2D8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2D8);
    // 0x8021C800: slti        $at, $t3, 0x9
    ctx->r1 = SIGNED(ctx->r11) < 0X9 ? 1 : 0;
    // 0x8021C804: beql        $at, $zero, L_8021C824
    if (ctx->r1 == 0) {
        // 0x8021C808: lbu         $v1, 0x2D8($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
            goto L_8021C824;
    }
    goto skip_11;
    // 0x8021C808: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    skip_11:
    // 0x8021C80C: jal         0x80378764
    // 0x8021C810: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80378764)(rdram, ctx);
        goto after_14;
    // 0x8021C810: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_14:
    // 0x8021C814: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8021C818: sb          $v0, 0x96($a1)
    MEM_B(0X96, ctx->r5) = ctx->r2;
    // 0x8021C81C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8021C820: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
L_8021C824:
    // 0x8021C824: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x8021C828: bne         $at, $zero, L_8021C838
    if (ctx->r1 != 0) {
        // 0x8021C82C: slti        $at, $v1, 0xB
        ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
            goto L_8021C838;
    }
    // 0x8021C82C: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x8021C830: bnel        $at, $zero, L_8021C84C
    if (ctx->r1 != 0) {
        // 0x8021C834: slti        $at, $v1, 0xB
        ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
            goto L_8021C84C;
    }
    goto skip_12;
    // 0x8021C834: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    skip_12:
L_8021C838:
    // 0x8021C838: lbu         $t4, 0xB3($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XB3);
    // 0x8021C83C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8021C840: sb          $t5, 0xB3($a0)
    MEM_B(0XB3, ctx->r4) = ctx->r13;
    // 0x8021C844: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    // 0x8021C848: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
L_8021C84C:
    // 0x8021C84C: bne         $at, $zero, L_8021C85C
    if (ctx->r1 != 0) {
        // 0x8021C850: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021C85C;
    }
    // 0x8021C850: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021C854: bnel        $v1, $at, L_8021C918
    if (ctx->r3 != ctx->r1) {
        // 0x8021C858: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021C918;
    }
    goto skip_13;
    // 0x8021C858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
L_8021C85C:
    // 0x8021C85C: jal         0x8022F680
    // 0x8021C860: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8022F680)(rdram, ctx);
        goto after_15;
    // 0x8021C860: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x8021C864: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8021C868: jal         0x8022F680
    // 0x8021C86C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8022F680)(rdram, ctx);
        goto after_16;
    // 0x8021C86C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x8021C870: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021C874: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021C878: lbu         $t6, 0x1030($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1030);
    // 0x8021C87C: bne         $t6, $zero, L_8021C894
    if (ctx->r14 != 0) {
        // 0x8021C880: nop
    
            goto L_8021C894;
    }
    // 0x8021C880: nop

    // 0x8021C884: jal         0x8037797C
    // 0x8021C888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037797C)(rdram, ctx);
        goto after_17;
    // 0x8021C888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8021C88C: b           L_8021C8B8
    // 0x8021C890: sb          $v0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r2;
        goto L_8021C8B8;
    // 0x8021C890: sb          $v0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r2;
L_8021C894:
    // 0x8021C894: jal         0x8037797C
    // 0x8021C898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037797C)(rdram, ctx);
        goto after_18;
    // 0x8021C898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8021C89C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8021C8A0: lhu         $t8, 0x9A($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X9A);
    // 0x8021C8A4: beql        $t8, $zero, L_8021C8BC
    if (ctx->r24 == 0) {
        // 0x8021C8A8: lbu         $t9, 0x23($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X23);
            goto L_8021C8BC;
    }
    goto skip_14;
    // 0x8021C8A8: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    skip_14:
    // 0x8021C8AC: jal         0x80378020
    // 0x8021C8B0: nop

    LOOKUP_FUNC(0x80378020)(rdram, ctx);
        goto after_19;
    // 0x8021C8B0: nop

    after_19:
    // 0x8021C8B4: sb          $v0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r2;
L_8021C8B8:
    // 0x8021C8B8: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
L_8021C8BC:
    // 0x8021C8BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8021C8C0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021C8C4: beq         $t9, $zero, L_8021C8DC
    if (ctx->r25 == 0) {
        // 0x8021C8C8: nop
    
            goto L_8021C8DC;
    }
    // 0x8021C8C8: nop

    // 0x8021C8CC: jal         0x80005670
    // 0x8021C8D0: addiu       $a1, $a1, -0x6960
    ctx->r5 = ADD32(ctx->r5, -0X6960);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_20;
    // 0x8021C8D0: addiu       $a1, $a1, -0x6960
    ctx->r5 = ADD32(ctx->r5, -0X6960);
    after_20:
    // 0x8021C8D4: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x8021C8D8: sb          $t0, 0xAC($v0)
    MEM_B(0XAC, ctx->r2) = ctx->r8;
L_8021C8DC:
    // 0x8021C8DC: jal         0x8022F424
    // 0x8021C8E0: nop

    LOOKUP_FUNC(0x8022F424)(rdram, ctx);
        goto after_21;
    // 0x8021C8E0: nop

    after_21:
    // 0x8021C8E4: jal         0x80378B48
    // 0x8021C8E8: nop

    LOOKUP_FUNC(0x80378B48)(rdram, ctx);
        goto after_22;
    // 0x8021C8E8: nop

    after_22:
    // 0x8021C8EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8021C8F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8021C8F4:
    // 0x8021C8F4: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8021C8F8: addu        $t2, $s0, $v1
    ctx->r10 = ADD32(ctx->r16, ctx->r3);
    // 0x8021C8FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8021C900: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8021C904: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8021C908: sb          $zero, 0x2E0($v0)
    MEM_B(0X2E0, ctx->r2) = 0;
    // 0x8021C90C: bne         $at, $zero, L_8021C8F4
    if (ctx->r1 != 0) {
        // 0x8021C910: sb          $zero, 0x2E0($t2)
        MEM_B(0X2E0, ctx->r10) = 0;
            goto L_8021C8F4;
    }
    // 0x8021C910: sb          $zero, 0x2E0($t2)
    MEM_B(0X2E0, ctx->r10) = 0;
L_8021C914:
    // 0x8021C914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021C918:
    // 0x8021C918: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021C91C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8021C920: jr          $ra
    // 0x8021C924: nop

    return;
    // 0x8021C924: nop

;}
RECOMP_FUNC void M10_FUN_8021c928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021C928: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8021C92C: jr          $ra
    // 0x8021C930: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8021C930: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021c934(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021c934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021C934: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021C938: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021C93C: lbu         $t6, 0x1030($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1030);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021c940(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021c940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021C940: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8021C944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021C948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021C94C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021C950: bne         $t6, $zero, L_8021C964
    if (ctx->r14 != 0) {
        // 0x8021C954: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_8021C964;
    }
    // 0x8021C954: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8021C958: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021C95C: b           L_8021C96C
    // 0x8021C960: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
        goto L_8021C96C;
    // 0x8021C960: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_8021C964:
    // 0x8021C964: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021C968: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_8021C96C:
    // 0x8021C96C: sb          $zero, 0x1032($v1)
    MEM_B(0X1032, ctx->r3) = 0;
    // 0x8021C970: lbu         $t7, 0x2D8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2D8);
    // 0x8021C974: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8021C978: bnel        $a0, $t7, L_8021CA34
    if (ctx->r4 != ctx->r15) {
        // 0x8021C97C: lhu         $v0, 0x2C($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X2C);
            goto L_8021CA34;
    }
    goto skip_0;
    // 0x8021C97C: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    skip_0:
    // 0x8021C980: jal         0x8037C530
    // 0x8021C984: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8037C530)(rdram, ctx);
        goto after_0;
    // 0x8021C984: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021C988: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8021C98C: jal         0x80379904
    // 0x8021C990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80379904)(rdram, ctx);
        goto after_1;
    // 0x8021C990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8021C994: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8021C998: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021C99C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8021C9A0: lbu         $t8, 0x2D9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2D9);
    // 0x8021C9A4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021C9A8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8021C9AC: bne         $t8, $at, L_8021CA18
    if (ctx->r24 != ctx->r1) {
        // 0x8021C9B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021CA18;
    }
    // 0x8021C9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021C9B4: lbu         $t9, 0x2DA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2DA);
    // 0x8021C9B8: beq         $t9, $zero, L_8021CA18
    if (ctx->r25 == 0) {
        // 0x8021C9BC: nop
    
            goto L_8021CA18;
    }
    // 0x8021C9BC: nop

    // 0x8021C9C0: jal         0x802322E8
    // 0x8021C9C4: nop

    LOOKUP_FUNC(0x802322E8)(rdram, ctx);
        goto after_2;
    // 0x8021C9C4: nop

    after_2:
    // 0x8021C9C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8021C9CC: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x8021C9D0: lhu         $v0, 0x9A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X9A);
    // 0x8021C9D4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8021C9D8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021C9DC: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8021C9E0: beq         $at, $zero, L_8021C9F0
    if (ctx->r1 == 0) {
        // 0x8021C9E4: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_8021C9F0;
    }
    // 0x8021C9E4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021C9E8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x8021C9EC: sh          $t0, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r8;
L_8021C9F0:
    // 0x8021C9F0: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8021C9F4: sh          $t1, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r9;
    // 0x8021C9F8: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x8021C9FC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CA00: sb          $t2, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r10;
    // 0x8021CA04: addiu       $a1, $a1, -0x3218
    ctx->r5 = ADD32(ctx->r5, -0X3218);
    // 0x8021CA08: jal         0x800058DC
    // 0x8021CA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021CA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8021CA10: b           L_8021CC20
    // 0x8021CA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021CC20;
    // 0x8021CA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021CA18:
    // 0x8021CA18: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CA1C: sb          $t3, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r11;
    // 0x8021CA20: jal         0x800058DC
    // 0x8021CA24: addiu       $a1, $a1, -0x408C
    ctx->r5 = ADD32(ctx->r5, -0X408C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8021CA24: addiu       $a1, $a1, -0x408C
    ctx->r5 = ADD32(ctx->r5, -0X408C);
    after_4:
    // 0x8021CA28: b           L_8021CC20
    // 0x8021CA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021CC20;
    // 0x8021CA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021CA30: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
L_8021CA34:
    // 0x8021CA34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021CA38: beql        $v0, $at, L_8021CB68
    if (ctx->r2 == ctx->r1) {
        // 0x8021CA3C: lh          $t1, 0x7EA($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X7EA);
            goto L_8021CB68;
    }
    goto skip_1;
    // 0x8021CA3C: lh          $t1, 0x7EA($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X7EA);
    skip_1:
    // 0x8021CA40: beq         $a0, $v0, L_8021CB64
    if (ctx->r4 == ctx->r2) {
        // 0x8021CA44: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021CB64;
    }
    // 0x8021CA44: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021CA48: beql        $v0, $at, L_8021CB68
    if (ctx->r2 == ctx->r1) {
        // 0x8021CA4C: lh          $t1, 0x7EA($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X7EA);
            goto L_8021CB68;
    }
    goto skip_2;
    // 0x8021CA4C: lh          $t1, 0x7EA($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X7EA);
    skip_2:
    // 0x8021CA50: lh          $t4, 0x7EA($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X7EA);
    // 0x8021CA54: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8021CA58: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8021CA5C: bgtz        $t4, L_8021CA80
    if (SIGNED(ctx->r12) > 0) {
        // 0x8021CA60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021CA80;
    }
    // 0x8021CA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021CA64: sb          $t5, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r13;
    // 0x8021CA68: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CA6C: sh          $t6, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r14;
    // 0x8021CA70: jal         0x800058DC
    // 0x8021CA74: addiu       $a1, $a1, -0x3184
    ctx->r5 = ADD32(ctx->r5, -0X3184);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8021CA74: addiu       $a1, $a1, -0x3184
    ctx->r5 = ADD32(ctx->r5, -0X3184);
    after_5:
    // 0x8021CA78: b           L_8021CC20
    // 0x8021CA7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021CC20;
    // 0x8021CA7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021CA80:
    // 0x8021CA80: lh          $t7, 0x44E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X44E);
    // 0x8021CA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021CA88: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CA8C: bgtz        $t7, L_8021CB18
    if (SIGNED(ctx->r15) > 0) {
        // 0x8021CA90: nop
    
            goto L_8021CB18;
    }
    // 0x8021CA90: nop

    // 0x8021CA94: jal         0x80146B04
    // 0x8021CA98: nop

    LOOKUP_FUNC(0x80146B04)(rdram, ctx);
        goto after_6;
    // 0x8021CA98: nop

    after_6:
    // 0x8021CA9C: jal         0x802329F8
    // 0x8021CAA0: nop

    LOOKUP_FUNC(0x802329F8)(rdram, ctx);
        goto after_7;
    // 0x8021CAA0: nop

    after_7:
    // 0x8021CAA4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8021CAA8: addiu       $v0, $v0, -0x2284
    ctx->r2 = ADD32(ctx->r2, -0X2284);
    // 0x8021CAAC: lbu         $t9, 0x16($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X16);
    // 0x8021CAB0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021CAB4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021CAB8: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8021CABC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021CAC0: bne         $t9, $at, L_8021CAEC
    if (ctx->r25 != ctx->r1) {
        // 0x8021CAC4: sb          $t8, 0x1031($v1)
        MEM_B(0X1031, ctx->r3) = ctx->r24;
            goto L_8021CAEC;
    }
    // 0x8021CAC4: sb          $t8, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r24;
    // 0x8021CAC8: lbu         $t0, 0x17($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X17);
    // 0x8021CACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021CAD0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CAD4: beq         $t0, $zero, L_8021CAEC
    if (ctx->r8 == 0) {
        // 0x8021CAD8: nop
    
            goto L_8021CAEC;
    }
    // 0x8021CAD8: nop

    // 0x8021CADC: jal         0x800058DC
    // 0x8021CAE0: addiu       $a1, $a1, -0x28D4
    ctx->r5 = ADD32(ctx->r5, -0X28D4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8021CAE0: addiu       $a1, $a1, -0x28D4
    ctx->r5 = ADD32(ctx->r5, -0X28D4);
    after_8:
    // 0x8021CAE4: b           L_8021CC20
    // 0x8021CAE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021CC20;
    // 0x8021CAE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021CAEC:
    // 0x8021CAEC: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x8021CAF0: addiu       $a1, $a1, 0x76D0
    ctx->r5 = ADD32(ctx->r5, 0X76D0);
    // 0x8021CAF4: jal         0x80005670
    // 0x8021CAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_9;
    // 0x8021CAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8021CAFC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CB00: sw          $v0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r2;
    // 0x8021CB04: addiu       $a1, $a1, -0x2FCC
    ctx->r5 = ADD32(ctx->r5, -0X2FCC);
    // 0x8021CB08: jal         0x800058DC
    // 0x8021CB0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x8021CB0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8021CB10: b           L_8021CC20
    // 0x8021CB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021CC20;
    // 0x8021CB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021CB18:
    // 0x8021CB18: jal         0x800058DC
    // 0x8021CB1C: addiu       $a1, $a1, -0x3264
    ctx->r5 = ADD32(ctx->r5, -0X3264);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x8021CB1C: addiu       $a1, $a1, -0x3264
    ctx->r5 = ADD32(ctx->r5, -0X3264);
    after_11:
    // 0x8021CB20: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021CB24: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021CB28: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8021CB2C: sb          $t1, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r9;
    // 0x8021CB30: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    // 0x8021CB34: sb          $zero, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = 0;
    // 0x8021CB38: lbu         $t2, 0x818($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X818);
    // 0x8021CB3C: lbu         $t8, 0x47C($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X47C);
    // 0x8021CB40: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x8021CB44: sb          $t3, 0x818($v1)
    MEM_B(0X818, ctx->r3) = ctx->r11;
    // 0x8021CB48: lw          $t4, 0x818($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X818);
    // 0x8021CB4C: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x8021CB50: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8021CB54: sll         $t7, $t5, 7
    ctx->r15 = S32(ctx->r13 << 7);
    // 0x8021CB58: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8021CB5C: b           L_8021CC1C
    // 0x8021CB60: sb          $t0, 0x47C($v1)
    MEM_B(0X47C, ctx->r3) = ctx->r8;
        goto L_8021CC1C;
    // 0x8021CB60: sb          $t0, 0x47C($v1)
    MEM_B(0X47C, ctx->r3) = ctx->r8;
L_8021CB64:
    // 0x8021CB64: lh          $t1, 0x7EA($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X7EA);
L_8021CB68:
    // 0x8021CB68: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021CB6C: blez        $t1, L_8021CB88
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8021CB70: nop
    
            goto L_8021CB88;
    }
    // 0x8021CB70: nop

    // 0x8021CB74: lh          $t2, 0x44E($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X44E);
    // 0x8021CB78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021CB7C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CB80: bgtz        $t2, L_8021CBD4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8021CB84: nop
    
            goto L_8021CBD4;
    }
    // 0x8021CB84: nop

L_8021CB88:
    // 0x8021CB88: bne         $v0, $at, L_8021CBB0
    if (ctx->r2 != ctx->r1) {
        // 0x8021CB8C: addiu       $t4, $zero, 0xC
        ctx->r12 = ADD32(0, 0XC);
            goto L_8021CBB0;
    }
    // 0x8021CB8C: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8021CB90: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8021CB94: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CB98: sh          $t3, 0xA4($s0)
    MEM_H(0XA4, ctx->r16) = ctx->r11;
    // 0x8021CB9C: addiu       $a1, $a1, -0x2E58
    ctx->r5 = ADD32(ctx->r5, -0X2E58);
    // 0x8021CBA0: jal         0x800058DC
    // 0x8021CBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x8021CBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8021CBA8: b           L_8021CC20
    // 0x8021CBAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021CC20;
    // 0x8021CBAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021CBB0:
    // 0x8021CBB0: sb          $t4, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r12;
    // 0x8021CBB4: jal         0x800208C4
    // 0x8021CBB8: addiu       $a0, $zero, 0x6C7
    ctx->r4 = ADD32(0, 0X6C7);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_13;
    // 0x8021CBB8: addiu       $a0, $zero, 0x6C7
    ctx->r4 = ADD32(0, 0X6C7);
    after_13:
    // 0x8021CBBC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CBC0: addiu       $a1, $a1, -0x2FC0
    ctx->r5 = ADD32(ctx->r5, -0X2FC0);
    // 0x8021CBC4: jal         0x800058DC
    // 0x8021CBC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x8021CBC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8021CBCC: b           L_8021CC20
    // 0x8021CBD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021CC20;
    // 0x8021CBD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021CBD4:
    // 0x8021CBD4: jal         0x800058DC
    // 0x8021CBD8: addiu       $a1, $a1, -0x3264
    ctx->r5 = ADD32(ctx->r5, -0X3264);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x8021CBD8: addiu       $a1, $a1, -0x3264
    ctx->r5 = ADD32(ctx->r5, -0X3264);
    after_15:
    // 0x8021CBDC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021CBE0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021CBE4: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8021CBE8: sb          $t5, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r13;
    // 0x8021CBEC: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    // 0x8021CBF0: sb          $zero, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = 0;
    // 0x8021CBF4: lbu         $t6, 0x818($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X818);
    // 0x8021CBF8: lbu         $t2, 0x47C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X47C);
    // 0x8021CBFC: andi        $t8, $t6, 0xFF7F
    ctx->r24 = ctx->r14 & 0XFF7F;
    // 0x8021CC00: sb          $t8, 0x818($v1)
    MEM_B(0X818, ctx->r3) = ctx->r24;
    // 0x8021CC04: lw          $t7, 0x818($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X818);
    // 0x8021CC08: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x8021CC0C: srl         $t9, $t7, 31
    ctx->r25 = S32(U32(ctx->r15) >> 31);
    // 0x8021CC10: sll         $t1, $t9, 7
    ctx->r9 = S32(ctx->r25 << 7);
    // 0x8021CC14: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8021CC18: sb          $t4, 0x47C($v1)
    MEM_B(0X47C, ctx->r3) = ctx->r12;
L_8021CC1C:
    // 0x8021CC1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021CC20:
    // 0x8021CC20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021CC24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8021CC28: jr          $ra
    // 0x8021CC2C: nop

    return;
    // 0x8021CC2C: nop

;}
RECOMP_FUNC void M10_FUN_8021cc30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CC30: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021CC34: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021CC38: lhu         $v1, 0x2C($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021cc3c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021cc3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CC3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021CC40: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021CC44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021CC48: beq         $v1, $at, L_8021CD78
    if (ctx->r3 == ctx->r1) {
        // 0x8021CC4C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8021CD78;
    }
    // 0x8021CC4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021CC50: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021CC54: beql        $v1, $at, L_8021CD7C
    if (ctx->r3 == ctx->r1) {
        // 0x8021CC58: addiu       $t0, $zero, 0xC
        ctx->r8 = ADD32(0, 0XC);
            goto L_8021CD7C;
    }
    goto skip_0;
    // 0x8021CC58: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    skip_0:
    // 0x8021CC5C: lh          $t6, 0x44E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X44E);
    // 0x8021CC60: bgtzl       $t6, L_8021CCEC
    if (SIGNED(ctx->r14) > 0) {
        // 0x8021CC64: lh          $t0, 0x7EA($v0)
        ctx->r8 = MEM_H(ctx->r2, 0X7EA);
            goto L_8021CCEC;
    }
    goto skip_1;
    // 0x8021CC64: lh          $t0, 0x7EA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X7EA);
    skip_1:
    // 0x8021CC68: jal         0x80146B04
    // 0x8021CC6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80146B04)(rdram, ctx);
        goto after_0;
    // 0x8021CC6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8021CC70: jal         0x802329F8
    // 0x8021CC74: nop

    LOOKUP_FUNC(0x802329F8)(rdram, ctx);
        goto after_1;
    // 0x8021CC74: nop

    after_1:
    // 0x8021CC78: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021CC7C: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x8021CC80: lbu         $t8, 0x16($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X16);
    // 0x8021CC84: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021CC88: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021CC8C: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8021CC90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021CC94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021CC98: bne         $t8, $at, L_8021CCC0
    if (ctx->r24 != ctx->r1) {
        // 0x8021CC9C: sb          $t7, 0x1031($v0)
        MEM_B(0X1031, ctx->r2) = ctx->r15;
            goto L_8021CCC0;
    }
    // 0x8021CC9C: sb          $t7, 0x1031($v0)
    MEM_B(0X1031, ctx->r2) = ctx->r15;
    // 0x8021CCA0: lbu         $t9, 0x17($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X17);
    // 0x8021CCA4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CCA8: beq         $t9, $zero, L_8021CCC0
    if (ctx->r25 == 0) {
        // 0x8021CCAC: nop
    
            goto L_8021CCC0;
    }
    // 0x8021CCAC: nop

    // 0x8021CCB0: jal         0x800058DC
    // 0x8021CCB4: addiu       $a1, $a1, -0x28D4
    ctx->r5 = ADD32(ctx->r5, -0X28D4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8021CCB4: addiu       $a1, $a1, -0x28D4
    ctx->r5 = ADD32(ctx->r5, -0X28D4);
    after_2:
    // 0x8021CCB8: b           L_8021CD90
    // 0x8021CCBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021CD90;
    // 0x8021CCBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021CCC0:
    // 0x8021CCC0: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x8021CCC4: addiu       $a1, $a1, 0x76D0
    ctx->r5 = ADD32(ctx->r5, 0X76D0);
    // 0x8021CCC8: jal         0x80005670
    // 0x8021CCCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x8021CCCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x8021CCD0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CCD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021CCD8: jal         0x800058DC
    // 0x8021CCDC: addiu       $a1, $a1, -0x2FCC
    ctx->r5 = ADD32(ctx->r5, -0X2FCC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8021CCDC: addiu       $a1, $a1, -0x2FCC
    ctx->r5 = ADD32(ctx->r5, -0X2FCC);
    after_4:
    // 0x8021CCE0: b           L_8021CD90
    // 0x8021CCE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021CD90;
    // 0x8021CCE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021CCE8: lh          $t0, 0x7EA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X7EA);
L_8021CCEC:
    // 0x8021CCEC: bgtzl       $t0, L_8021CD90
    if (SIGNED(ctx->r8) > 0) {
        // 0x8021CCF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CD90;
    }
    goto skip_2;
    // 0x8021CCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8021CCF4: lw          $t1, 0x448($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X448);
    // 0x8021CCF8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CCFC: addiu       $a1, $a1, -0x3184
    ctx->r5 = ADD32(ctx->r5, -0X3184);
    // 0x8021CD00: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8021CD04: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x8021CD08: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8021CD0C: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8021CD10: swc1        $f4, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f4.u32l;
    // 0x8021CD14: lw          $t5, 0x448($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X448);
    // 0x8021CD18: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8021CD1C: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8021CD20: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8021CD24: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8021CD28: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8021CD2C: swc1        $f6, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f6.u32l;
    // 0x8021CD30: lw          $t9, 0x448($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X448);
    // 0x8021CD34: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8021CD38: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8021CD3C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x8021CD40: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8021CD44: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8021CD48: swc1        $f8, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->f8.u32l;
    // 0x8021CD4C: lw          $t3, 0x448($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X448);
    // 0x8021CD50: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8021CD54: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x8021CD58: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8021CD5C: lh          $t7, 0x12($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X12);
    // 0x8021CD60: sh          $t8, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r24;
    // 0x8021CD64: sh          $t7, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r15;
    // 0x8021CD68: jal         0x800058DC
    // 0x8021CD6C: sb          $t9, 0x1031($v0)
    MEM_B(0X1031, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8021CD6C: sb          $t9, 0x1031($v0)
    MEM_B(0X1031, ctx->r2) = ctx->r25;
    after_5:
    // 0x8021CD70: b           L_8021CD90
    // 0x8021CD74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021CD90;
    // 0x8021CD74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021CD78:
    // 0x8021CD78: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
L_8021CD7C:
    // 0x8021CD7C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CD80: sb          $t0, 0x1031($v0)
    MEM_B(0X1031, ctx->r2) = ctx->r8;
    // 0x8021CD84: jal         0x800058DC
    // 0x8021CD88: addiu       $a1, $a1, -0x2FC0
    ctx->r5 = ADD32(ctx->r5, -0X2FC0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8021CD88: addiu       $a1, $a1, -0x2FC0
    ctx->r5 = ADD32(ctx->r5, -0X2FC0);
    after_6:
    // 0x8021CD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021CD90:
    // 0x8021CD90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021CD94: jr          $ra
    // 0x8021CD98: nop

    return;
    // 0x8021CD98: nop

;}
RECOMP_FUNC void M10_FUN_8021cd9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CD9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021CDA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021CDA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021CDA8: lh          $t6, 0xB0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XB0);
    // 0x8021CDAC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CDB0: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8021CDB4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8021CDB8: sh          $t7, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r15;
    // 0x8021CDBC: lh          $t8, 0xB0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XB0);
    // 0x8021CDC0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021CDC4: addiu       $a1, $a1, -0x408C
    ctx->r5 = ADD32(ctx->r5, -0X408C);
    // 0x8021CDC8: bgezl       $t8, L_8021CDDC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8021CDCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CDDC;
    }
    goto skip_0;
    // 0x8021CDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021CDD0: jal         0x800058DC
    // 0x8021CDD4: sb          $t9, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8021CDD4: sb          $t9, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r25;
    after_0:
    // 0x8021CDD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021CDDC:
    // 0x8021CDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021CDE0: jr          $ra
    // 0x8021CDE4: nop

    return;
    // 0x8021CDE4: nop

;}
RECOMP_FUNC void M10_FUN_8021cde8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CDE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021CDEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021CDF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021CDF4: lbu         $t6, 0xAE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAE);
    // 0x8021CDF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8021CDFC: beql        $t6, $zero, L_8021CE70
    if (ctx->r14 == 0) {
        // 0x8021CE00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CE70;
    }
    goto skip_0;
    // 0x8021CE00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021CE04: lbu         $t7, 0xAF($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAF);
    // 0x8021CE08: bnel        $t7, $zero, L_8021CE70
    if (ctx->r15 != 0) {
        // 0x8021CE0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CE70;
    }
    goto skip_1;
    // 0x8021CE0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8021CE10: lbu         $t8, 0x9B($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9B);
    // 0x8021CE14: bnel        $t8, $zero, L_8021CE70
    if (ctx->r24 != 0) {
        // 0x8021CE18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CE70;
    }
    goto skip_2;
    // 0x8021CE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8021CE1C: lh          $t9, 0xB0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XB0);
    // 0x8021CE20: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8021CE24: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8021CE28: sh          $t0, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r8;
    // 0x8021CE2C: lh          $t1, 0xB0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XB0);
    // 0x8021CE30: bgezl       $t1, L_8021CE70
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8021CE34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CE70;
    }
    goto skip_3;
    // 0x8021CE34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8021CE38: sh          $t2, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r10;
    // 0x8021CE3C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8021CE40: jal         0x80020744
    // 0x8021CE44: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x8021CE44: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8021CE48: jal         0x80126E88
    // 0x8021CE4C: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x8021CE4C: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_1:
    // 0x8021CE50: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x8021CE54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021CE58: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CE5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021CE60: sb          $t3, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r11;
    // 0x8021CE64: jal         0x800058DC
    // 0x8021CE68: addiu       $a1, $a1, -0x2D9C
    ctx->r5 = ADD32(ctx->r5, -0X2D9C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8021CE68: addiu       $a1, $a1, -0x2D9C
    ctx->r5 = ADD32(ctx->r5, -0X2D9C);
    after_2:
    // 0x8021CE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021CE70:
    // 0x8021CE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021CE74: jr          $ra
    // 0x8021CE78: nop

    return;
    // 0x8021CE78: nop

;}
RECOMP_FUNC void M10_FUN_8021ce7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CE7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021CE80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021CE84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021CE88: lbu         $t6, 0xAE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAE);
    // 0x8021CE8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8021CE90: beql        $t6, $zero, L_8021CEE8
    if (ctx->r14 == 0) {
        // 0x8021CE94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CEE8;
    }
    goto skip_0;
    // 0x8021CE94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021CE98: lbu         $t7, 0xAF($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAF);
    // 0x8021CE9C: bnel        $t7, $zero, L_8021CEE8
    if (ctx->r15 != 0) {
        // 0x8021CEA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CEE8;
    }
    goto skip_1;
    // 0x8021CEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8021CEA4: lbu         $t8, 0x9B($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9B);
    // 0x8021CEA8: bnel        $t8, $zero, L_8021CEE8
    if (ctx->r24 != 0) {
        // 0x8021CEAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CEE8;
    }
    goto skip_2;
    // 0x8021CEAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8021CEB0: lh          $t9, 0xB0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XB0);
    // 0x8021CEB4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8021CEB8: sh          $t0, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r8;
    // 0x8021CEBC: lh          $t1, 0xB0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XB0);
    // 0x8021CEC0: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    // 0x8021CEC4: bgezl       $t1, L_8021CEE8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8021CEC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021CEE8;
    }
    goto skip_3;
    // 0x8021CEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8021CECC: jal         0x80126E88
    // 0x8021CED0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x8021CED0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8021CED4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021CEDC: jal         0x800058DC
    // 0x8021CEE0: addiu       $a1, $a1, -0x310C
    ctx->r5 = ADD32(ctx->r5, -0X310C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8021CEE0: addiu       $a1, $a1, -0x310C
    ctx->r5 = ADD32(ctx->r5, -0X310C);
    after_1:
    // 0x8021CEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021CEE8:
    // 0x8021CEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021CEEC: jr          $ra
    // 0x8021CEF0: nop

    return;
    // 0x8021CEF0: nop

;}
RECOMP_FUNC void M10_FUN_8021cef4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CEF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021CEF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021CEFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021CF00: addiu       $a1, $zero, 0x129
    ctx->r5 = ADD32(0, 0X129);
    // 0x8021CF04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021CF08: jal         0x80126A0C
    // 0x8021CF0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x8021CF0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8021CF10: beq         $v0, $zero, L_8021CF40
    if (ctx->r2 == 0) {
        // 0x8021CF14: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021CF40;
    }
    // 0x8021CF14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021CF18: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021CF1C: addiu       $a1, $a1, -0x6500
    ctx->r5 = ADD32(ctx->r5, -0X6500);
    // 0x8021CF20: jal         0x80005670
    // 0x8021CF24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8021CF24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8021CF28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021CF2C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021CF30: addiu       $a1, $a1, -0x30B0
    ctx->r5 = ADD32(ctx->r5, -0X30B0);
    // 0x8021CF34: sw          $v0, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r2;
    // 0x8021CF38: jal         0x800058DC
    // 0x8021CF3C: sb          $zero, 0xB3($a0)
    MEM_B(0XB3, ctx->r4) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8021CF3C: sb          $zero, 0xB3($a0)
    MEM_B(0XB3, ctx->r4) = 0;
    after_2:
L_8021CF40:
    // 0x8021CF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021CF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021CF48: jr          $ra
    // 0x8021CF4C: nop

    return;
    // 0x8021CF4C: nop

;}
RECOMP_FUNC void M10_FUN_8021cf50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CF50: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021CF54: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021CF58: lw          $t8, 0x818($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X818);
    // 0x8021CF5C: lhu         $t6, 0xEF0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XEF0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021cf60(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021cf60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021CF60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8021CF64: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8021CF68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8021CF6C: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x8021CF70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021CF74: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8021CF78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021CF7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8021CF80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8021CF84: bne         $t0, $at, L_8021D020
    if (ctx->r8 != ctx->r1) {
        // 0x8021CF88: sh          $t7, 0xEF0($v1)
        MEM_H(0XEF0, ctx->r3) = ctx->r15;
            goto L_8021D020;
    }
    // 0x8021CF88: sh          $t7, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r15;
    // 0x8021CF8C: lbu         $t1, 0xB3($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XB3);
    // 0x8021CF90: beql        $t1, $zero, L_8021D024
    if (ctx->r9 == 0) {
        // 0x8021CF94: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8021D024;
    }
    goto skip_0;
    // 0x8021CF94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8021CF98: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    // 0x8021CF9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021CFA0: beq         $v0, $at, L_8021CFD8
    if (ctx->r2 == ctx->r1) {
        // 0x8021CFA4: xori        $t2, $v0, 0xA
        ctx->r10 = ctx->r2 ^ 0XA;
            goto L_8021CFD8;
    }
    // 0x8021CFA4: xori        $t2, $v0, 0xA
    ctx->r10 = ctx->r2 ^ 0XA;
    // 0x8021CFA8: sltu        $t2, $zero, $t2
    ctx->r10 = 0 < ctx->r10 ? 1 : 0;
    // 0x8021CFAC: xor         $t3, $v0, $t2
    ctx->r11 = ctx->r2 ^ ctx->r10;
    // 0x8021CFB0: sltu        $t3, $zero, $t3
    ctx->r11 = 0 < ctx->r11 ? 1 : 0;
    // 0x8021CFB4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021CFB8: beq         $t3, $at, L_8021CFD8
    if (ctx->r11 == ctx->r1) {
        // 0x8021CFBC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8021CFD8;
    }
    // 0x8021CFBC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8021CFC0: lwc1        $f12, 0xA0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x8021CFC4: lwc1        $f14, 0xA4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XA4);
    // 0x8021CFC8: lw          $a2, 0xA8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XA8);
    // 0x8021CFCC: lh          $a3, 0xAC($a0)
    ctx->r7 = MEM_H(ctx->r4, 0XAC);
    // 0x8021CFD0: jal         0x80231D84
    // 0x8021CFD4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80231D84)(rdram, ctx);
        goto after_0;
    // 0x8021CFD4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
L_8021CFD8:
    // 0x8021CFD8: jal         0x8037865C
    // 0x8021CFDC: nop

    LOOKUP_FUNC(0x8037865C)(rdram, ctx);
        goto after_1;
    // 0x8021CFDC: nop

    after_1:
    // 0x8021CFE0: jal         0x80232278
    // 0x8021CFE4: nop

    LOOKUP_FUNC(0x80232278)(rdram, ctx);
        goto after_2;
    // 0x8021CFE4: nop

    after_2:
    // 0x8021CFE8: jal         0x802322E8
    // 0x8021CFEC: nop

    LOOKUP_FUNC(0x802322E8)(rdram, ctx);
        goto after_3;
    // 0x8021CFEC: nop

    after_3:
    // 0x8021CFF0: jal         0x80020744
    // 0x8021CFF4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_4;
    // 0x8021CFF4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x8021CFF8: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x8021CFFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021D000: sb          $t5, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r13;
    // 0x8021D004: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8021D008: jal         0x801FA1C4
    // 0x8021D00C: sh          $t6, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r14;
    LOOKUP_FUNC(0x801FA1C4)(rdram, ctx);
        goto after_5;
    // 0x8021D00C: sh          $t6, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r14;
    after_5:
    // 0x8021D010: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D014: addiu       $a1, $a1, -0x2D9C
    ctx->r5 = ADD32(ctx->r5, -0X2D9C);
    // 0x8021D018: jal         0x800058DC
    // 0x8021D01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8021D01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8021D020:
    // 0x8021D020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8021D024:
    // 0x8021D024: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8021D028: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8021D02C: jr          $ra
    // 0x8021D030: nop

    return;
    // 0x8021D030: nop

;}
RECOMP_FUNC void M10_FUN_8021d034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D034: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8021D038: jr          $ra
    // 0x8021D03C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8021D03C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021d040(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021d040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D040: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8021D044: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021d048(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021d048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021D04C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021D050: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8021D054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021D058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021D05C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8021D060: sh          $t7, -0x3520($at)
    MEM_H(-0X3520, ctx->r1) = ctx->r15;
    // 0x8021D064: lbu         $t8, 0xAE($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XAE);
    // 0x8021D068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021D06C: beql        $t8, $zero, L_8021D198
    if (ctx->r24 == 0) {
        // 0x8021D070: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021D198;
    }
    goto skip_0;
    // 0x8021D070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8021D074: lbu         $t9, 0xB2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XB2);
    // 0x8021D078: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021D07C: bnel        $t9, $zero, L_8021D11C
    if (ctx->r25 != 0) {
        // 0x8021D080: lh          $t2, 0xA4($s0)
        ctx->r10 = MEM_H(ctx->r16, 0XA4);
            goto L_8021D11C;
    }
    goto skip_1;
    // 0x8021D080: lh          $t2, 0xA4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA4);
    skip_1:
    // 0x8021D084: jal         0x80005670
    // 0x8021D088: addiu       $a1, $a1, -0x68C0
    ctx->r5 = ADD32(ctx->r5, -0X68C0);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x8021D088: addiu       $a1, $a1, -0x68C0
    ctx->r5 = ADD32(ctx->r5, -0X68C0);
    after_0:
    // 0x8021D08C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021D090: lh          $t0, -0x3C26($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X3C26);
    // 0x8021D094: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021D098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021D09C: bgtz        $t0, L_8021D0D4
    if (SIGNED(ctx->r8) > 0) {
        // 0x8021D0A0: lui         $a1, 0x8039
        ctx->r5 = S32(0X8039 << 16);
            goto L_8021D0D4;
    }
    // 0x8021D0A0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8021D0A4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021D0A8: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x8021D0AC: sb          $zero, 0xA8($v0)
    MEM_B(0XA8, ctx->r2) = 0;
    // 0x8021D0B0: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x8021D0B4: addiu       $t4, $zero, 0x63
    ctx->r12 = ADD32(0, 0X63);
    // 0x8021D0B8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8021D0BC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8021D0C0: slti        $at, $t3, 0x64
    ctx->r1 = SIGNED(ctx->r11) < 0X64 ? 1 : 0;
    // 0x8021D0C4: bne         $at, $zero, L_8021D100
    if (ctx->r1 != 0) {
        // 0x8021D0C8: sb          $t2, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r10;
            goto L_8021D100;
    }
    // 0x8021D0C8: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x8021D0CC: b           L_8021D100
    // 0x8021D0D0: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
        goto L_8021D100;
    // 0x8021D0D0: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_8021D0D4:
    // 0x8021D0D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8021D0D8: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x8021D0DC: sb          $t5, 0xA8($v0)
    MEM_B(0XA8, ctx->r2) = ctx->r13;
    // 0x8021D0E0: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8021D0E4: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x8021D0E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8021D0EC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8021D0F0: slti        $at, $t8, 0x64
    ctx->r1 = SIGNED(ctx->r24) < 0X64 ? 1 : 0;
    // 0x8021D0F4: bne         $at, $zero, L_8021D100
    if (ctx->r1 != 0) {
        // 0x8021D0F8: sb          $t7, 0x1($v1)
        MEM_B(0X1, ctx->r3) = ctx->r15;
            goto L_8021D100;
    }
    // 0x8021D0F8: sb          $t7, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r15;
    // 0x8021D0FC: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
L_8021D100:
    // 0x8021D100: jal         0x80005670
    // 0x8021D104: addiu       $a1, $a1, -0x6460
    ctx->r5 = ADD32(ctx->r5, -0X6460);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8021D104: addiu       $a1, $a1, -0x6460
    ctx->r5 = ADD32(ctx->r5, -0X6460);
    after_1:
    // 0x8021D108: lbu         $t0, 0xB2($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XB2);
    // 0x8021D10C: sh          $zero, 0xA4($s0)
    MEM_H(0XA4, ctx->r16) = 0;
    // 0x8021D110: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8021D114: sb          $t1, 0xB2($s0)
    MEM_B(0XB2, ctx->r16) = ctx->r9;
    // 0x8021D118: lh          $t2, 0xA4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA4);
L_8021D11C:
    // 0x8021D11C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8021D120: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x8021D124: beql        $t3, $zero, L_8021D198
    if (ctx->r11 == 0) {
        // 0x8021D128: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021D198;
    }
    goto skip_2;
    // 0x8021D128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8021D12C: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    // 0x8021D130: jal         0x800023EC
    // 0x8021D134: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_2;
    // 0x8021D134: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    after_2:
    // 0x8021D138: jal         0x80020744
    // 0x8021D13C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x8021D13C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x8021D140: lh          $v0, 0xA4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA4);
    // 0x8021D144: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021D148: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x8021D14C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8021D150: beq         $v0, $zero, L_8021D17C
    if (ctx->r2 == 0) {
        // 0x8021D154: addiu       $t6, $zero, 0xE
        ctx->r14 = ADD32(0, 0XE);
            goto L_8021D17C;
    }
    // 0x8021D154: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8021D158: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021D15C: bnel        $v0, $at, L_8021D178
    if (ctx->r2 != ctx->r1) {
        // 0x8021D160: sb          $zero, 0x1($v1)
        MEM_B(0X1, ctx->r3) = 0;
            goto L_8021D178;
    }
    goto skip_3;
    // 0x8021D160: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    skip_3:
    // 0x8021D164: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x8021D168: lb          $t4, 0xF($v1)
    ctx->r12 = MEM_B(ctx->r3, 0XF);
    // 0x8021D16C: b           L_8021D17C
    // 0x8021D170: sb          $t4, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r12;
        goto L_8021D17C;
    // 0x8021D170: sb          $t4, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r12;
    // 0x8021D174: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
L_8021D178:
    // 0x8021D178: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8021D17C:
    // 0x8021D17C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021D180: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D184: sb          $t6, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r14;
    // 0x8021D188: addiu       $a1, $a1, -0x2E58
    ctx->r5 = ADD32(ctx->r5, -0X2E58);
    // 0x8021D18C: jal         0x800058DC
    // 0x8021D190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8021D190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8021D194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021D198:
    // 0x8021D198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021D19C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021D1A0: jr          $ra
    // 0x8021D1A4: nop

    return;
    // 0x8021D1A4: nop

;}
RECOMP_FUNC void M10_FUN_8021d1a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D1A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8021D1AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8021D1B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8021D1B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8021D1B8: lh          $t6, 0xB0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XB0);
    // 0x8021D1BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021D1C0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8021D1C4: sh          $t7, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r15;
    // 0x8021D1C8: lh          $t8, 0xB0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XB0);
    // 0x8021D1CC: slti        $at, $t8, 0x1F
    ctx->r1 = SIGNED(ctx->r24) < 0X1F ? 1 : 0;
    // 0x8021D1D0: bnel        $at, $zero, L_8021D254
    if (ctx->r1 != 0) {
        // 0x8021D1D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8021D254;
    }
    goto skip_0;
    // 0x8021D1D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8021D1D8: lh          $v0, 0xA4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XA4);
    // 0x8021D1DC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8021D1E0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021D1E4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8021D1E8: bne         $v0, $zero, L_8021D20C
    if (ctx->r2 != 0) {
        // 0x8021D1EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8021D20C;
    }
    // 0x8021D1EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021D1F0: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x8021D1F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8021D1F8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8021D1FC: jal         0x8012FE50
    // 0x8021D200: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x8021D200: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8021D204: b           L_8021D248
    // 0x8021D208: nop

        goto L_8021D248;
    // 0x8021D208: nop

L_8021D20C:
    // 0x8021D20C: bne         $v0, $at, L_8021D234
    if (ctx->r2 != ctx->r1) {
        // 0x8021D210: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8021D234;
    }
    // 0x8021D210: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8021D214: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8021D218: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8021D21C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8021D220: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8021D224: jal         0x8012FE50
    // 0x8021D228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_1;
    // 0x8021D228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8021D22C: b           L_8021D248
    // 0x8021D230: nop

        goto L_8021D248;
    // 0x8021D230: nop

L_8021D234:
    // 0x8021D234: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x8021D238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8021D23C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8021D240: jal         0x8012FE50
    // 0x8021D244: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_2;
    // 0x8021D244: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
L_8021D248:
    // 0x8021D248: jal         0x80005700
    // 0x8021D24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x8021D24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8021D250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8021D254:
    // 0x8021D254: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8021D258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8021D25C: jr          $ra
    // 0x8021D260: nop

    return;
    // 0x8021D260: nop

;}
RECOMP_FUNC void M10_FUN_8021d264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D264: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8021D268: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021D26C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021D270: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8021D274: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8021D278: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8021D27C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8021D280: sb          $t6, 0x1031($v1)
    MEM_B(0X1031, ctx->r3) = ctx->r14;
    // 0x8021D284: lh          $t7, 0xB0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XB0);
    // 0x8021D288: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021D28C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8021D290: sh          $t8, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r24;
    // 0x8021D294: lh          $t9, 0xB0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XB0);
    // 0x8021D298: bgezl       $t9, L_8021D35C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8021D29C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8021D35C;
    }
    goto skip_0;
    // 0x8021D29C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8021D2A0: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    // 0x8021D2A4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021D2A8: beq         $v0, $at, L_8021D2C8
    if (ctx->r2 == ctx->r1) {
        // 0x8021D2AC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8021D2C8;
    }
    // 0x8021D2AC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021D2B0: beq         $v0, $at, L_8021D2C8
    if (ctx->r2 == ctx->r1) {
        // 0x8021D2B4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8021D2C8;
    }
    // 0x8021D2B4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8021D2B8: beq         $v0, $at, L_8021D2C8
    if (ctx->r2 == ctx->r1) {
        // 0x8021D2BC: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021D2C8;
    }
    // 0x8021D2BC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021D2C0: bne         $v0, $at, L_8021D2F8
    if (ctx->r2 != ctx->r1) {
        // 0x8021D2C4: nop
    
            goto L_8021D2F8;
    }
    // 0x8021D2C4: nop

L_8021D2C8:
    // 0x8021D2C8: jal         0x80146B04
    // 0x8021D2CC: nop

    LOOKUP_FUNC(0x80146B04)(rdram, ctx);
        goto after_0;
    // 0x8021D2CC: nop

    after_0:
    // 0x8021D2D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8021D2D4: jal         0x800023EC
    // 0x8021D2D8: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_1;
    // 0x8021D2D8: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    after_1:
    // 0x8021D2DC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D2E0: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    // 0x8021D2E4: addiu       $a1, $a1, -0x2C94
    ctx->r5 = ADD32(ctx->r5, -0X2C94);
    // 0x8021D2E8: jal         0x800058DC
    // 0x8021D2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8021D2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8021D2F0: b           L_8021D35C
    // 0x8021D2F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8021D35C;
    // 0x8021D2F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8021D2F8:
    // 0x8021D2F8: jal         0x801271E4
    // 0x8021D2FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801271E4)(rdram, ctx);
        goto after_3;
    // 0x8021D2FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8021D300: jal         0x80005700
    // 0x8021D304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x8021D304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8021D308: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x8021D30C: addiu       $t0, $t0, -0x3D98
    ctx->r8 = ADD32(ctx->r8, -0X3D98);
    // 0x8021D310: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8021D314: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8021D318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021D31C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8021D320: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8021D324: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021D328: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8021D32C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8021D330: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8021D334: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8021D338: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8021D33C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8021D340: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8021D344: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8021D348: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8021D34C: jal         0x8012C4D0
    // 0x8021D350: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_5;
    // 0x8021D350: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_5:
    // 0x8021D354: sh          $zero, 0xB0($v0)
    MEM_H(0XB0, ctx->r2) = 0;
    // 0x8021D358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8021D35C:
    // 0x8021D35C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8021D360: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8021D364: jr          $ra
    // 0x8021D368: nop

    return;
    // 0x8021D368: nop

;}
RECOMP_FUNC void M10_FUN_8021d36c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D36C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8021D370: addiu       $v0, $v0, -0x2284
    ctx->r2 = ADD32(ctx->r2, -0X2284);
    // 0x8021D374: lbu         $v1, 0x16($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021d378(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021d378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021D37C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021D380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8021D384: bne         $v1, $zero, L_8021D480
    if (ctx->r3 != 0) {
        // 0x8021D388: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8021D480;
    }
    // 0x8021D388: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8021D38C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8021D390: lw          $t6, -0x4324($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4324);
    // 0x8021D394: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8021D398: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D39C: lhu         $v0, 0x36($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X36);
    // 0x8021D3A0: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x8021D3A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8021D3A8: bne         $v0, $at, L_8021D3C0
    if (ctx->r2 != ctx->r1) {
        // 0x8021D3AC: addiu       $a3, $zero, 0x4
        ctx->r7 = ADD32(0, 0X4);
            goto L_8021D3C0;
    }
    // 0x8021D3AC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8021D3B0: jal         0x8012FE50
    // 0x8021D3B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x8021D3B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8021D3B8: b           L_8021D524
    // 0x8021D3BC: nop

        goto L_8021D524;
    // 0x8021D3BC: nop

L_8021D3C0:
    // 0x8021D3C0: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x8021D3C4: bne         $v0, $at, L_8021D3E8
    if (ctx->r2 != ctx->r1) {
        // 0x8021D3C8: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8021D3E8;
    }
    // 0x8021D3C8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D3CC: addiu       $a1, $zero, 0x103
    ctx->r5 = ADD32(0, 0X103);
    // 0x8021D3D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8021D3D4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8021D3D8: jal         0x8012FE50
    // 0x8021D3DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_1;
    // 0x8021D3DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8021D3E0: b           L_8021D524
    // 0x8021D3E4: nop

        goto L_8021D524;
    // 0x8021D3E4: nop

L_8021D3E8:
    // 0x8021D3E8: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x8021D3EC: bne         $v0, $at, L_8021D410
    if (ctx->r2 != ctx->r1) {
        // 0x8021D3F0: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8021D410;
    }
    // 0x8021D3F0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D3F4: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
    // 0x8021D3F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8021D3FC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8021D400: jal         0x8012FE50
    // 0x8021D404: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_2;
    // 0x8021D404: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8021D408: b           L_8021D524
    // 0x8021D40C: nop

        goto L_8021D524;
    // 0x8021D40C: nop

L_8021D410:
    // 0x8021D410: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    // 0x8021D414: bne         $v0, $at, L_8021D438
    if (ctx->r2 != ctx->r1) {
        // 0x8021D418: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8021D438;
    }
    // 0x8021D418: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D41C: addiu       $a1, $zero, 0xF7
    ctx->r5 = ADD32(0, 0XF7);
    // 0x8021D420: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8021D424: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8021D428: jal         0x8012FE50
    // 0x8021D42C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_3;
    // 0x8021D42C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8021D430: b           L_8021D524
    // 0x8021D434: nop

        goto L_8021D524;
    // 0x8021D434: nop

L_8021D438:
    // 0x8021D438: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x8021D43C: bne         $v0, $at, L_8021D464
    if (ctx->r2 != ctx->r1) {
        // 0x8021D440: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8021D464;
    }
    // 0x8021D440: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8021D444: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D448: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    // 0x8021D44C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8021D450: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8021D454: jal         0x8012FE50
    // 0x8021D458: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_4;
    // 0x8021D458: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8021D45C: b           L_8021D524
    // 0x8021D460: nop

        goto L_8021D524;
    // 0x8021D460: nop

L_8021D464:
    // 0x8021D464: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x8021D468: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8021D46C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8021D470: jal         0x8012FE50
    // 0x8021D474: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_5;
    // 0x8021D474: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8021D478: b           L_8021D524
    // 0x8021D47C: nop

        goto L_8021D524;
    // 0x8021D47C: nop

L_8021D480:
    // 0x8021D480: lbu         $t7, 0x22($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X22);
    // 0x8021D484: lhu         $t0, 0x14($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X14);
    // 0x8021D488: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8021D48C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8021D490: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8021D494: beq         $at, $zero, L_8021D4CC
    if (ctx->r1 == 0) {
        // 0x8021D498: sb          $t8, 0x22($v0)
        MEM_B(0X22, ctx->r2) = ctx->r24;
            goto L_8021D4CC;
    }
    // 0x8021D498: sb          $t8, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r24;
    // 0x8021D49C: jal         0x80152F7C
    // 0x8021D4A0: nop

    LOOKUP_FUNC(0x80152F7C)(rdram, ctx);
        goto after_6;
    // 0x8021D4A0: nop

    after_6:
    // 0x8021D4A4: jal         0x80153008
    // 0x8021D4A8: nop

    LOOKUP_FUNC(0x80153008)(rdram, ctx);
        goto after_7;
    // 0x8021D4A8: nop

    after_7:
    // 0x8021D4AC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D4B0: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8021D4B4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8021D4B8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8021D4BC: jal         0x8012FE50
    // 0x8021D4C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_8;
    // 0x8021D4C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x8021D4C4: b           L_8021D524
    // 0x8021D4C8: nop

        goto L_8021D524;
    // 0x8021D4C8: nop

L_8021D4CC:
    // 0x8021D4CC: lbu         $t1, 0x17($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X17);
    // 0x8021D4D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021D4D4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D4D8: beq         $t1, $zero, L_8021D514
    if (ctx->r9 == 0) {
        // 0x8021D4DC: addiu       $a1, $zero, 0xC3
        ctx->r5 = ADD32(0, 0XC3);
            goto L_8021D514;
    }
    // 0x8021D4DC: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x8021D4E0: bnel        $v1, $at, L_8021D518
    if (ctx->r3 != ctx->r1) {
        // 0x8021D4E4: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8021D518;
    }
    goto skip_0;
    // 0x8021D4E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_0:
    // 0x8021D4E8: lhu         $t2, 0x12($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X12);
    // 0x8021D4EC: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x8021D4F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8021D4F4: bne         $t2, $at, L_8021D514
    if (ctx->r10 != ctx->r1) {
        // 0x8021D4F8: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8021D514;
    }
    // 0x8021D4F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8021D4FC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8021D500: addiu       $a1, $zero, 0xC2
    ctx->r5 = ADD32(0, 0XC2);
    // 0x8021D504: jal         0x8012FE50
    // 0x8021D508: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_9;
    // 0x8021D508: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x8021D50C: b           L_8021D524
    // 0x8021D510: nop

        goto L_8021D524;
    // 0x8021D510: nop

L_8021D514:
    // 0x8021D514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8021D518:
    // 0x8021D518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8021D51C: jal         0x8012FE50
    // 0x8021D520: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_10;
    // 0x8021D520: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
L_8021D524:
    // 0x8021D524: jal         0x80005700
    // 0x8021D528: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_11;
    // 0x8021D528: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x8021D52C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021D530: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021D534: jr          $ra
    // 0x8021D538: nop

    return;
    // 0x8021D538: nop

;}
RECOMP_FUNC void M10_FUN_8021d53c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D53C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021D540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021D544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021D548: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021D54C: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x8021D550: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8021D554: slti        $v1, $v0, 0x6
    ctx->r3 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8021D558: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8021D55C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8021D560: beq         $v1, $zero, L_8021D614
    if (ctx->r3 == 0) {
        // 0x8021D564: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_8021D614;
    }
    // 0x8021D564: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x8021D568: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8021D56C: jal         0x80126E88
    // 0x8021D570: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x8021D570: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021D574: jal         0x80126E88
    // 0x8021D578: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x8021D578: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_1:
    // 0x8021D57C: jal         0x80126E88
    // 0x8021D580: addiu       $a0, $zero, 0x129
    ctx->r4 = ADD32(0, 0X129);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_2;
    // 0x8021D580: addiu       $a0, $zero, 0x129
    ctx->r4 = ADD32(0, 0X129);
    after_2:
    // 0x8021D584: jal         0x80126E88
    // 0x8021D588: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_3;
    // 0x8021D588: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    after_3:
    // 0x8021D58C: jal         0x80126E88
    // 0x8021D590: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_4;
    // 0x8021D590: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_4:
    // 0x8021D594: jal         0x80126E88
    // 0x8021D598: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_5;
    // 0x8021D598: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    after_5:
    // 0x8021D59C: jal         0x80126E88
    // 0x8021D5A0: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_6;
    // 0x8021D5A0: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    after_6:
    // 0x8021D5A4: jal         0x80126E88
    // 0x8021D5A8: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_7;
    // 0x8021D5A8: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    after_7:
    // 0x8021D5AC: jal         0x80126E88
    // 0x8021D5B0: addiu       $a0, $zero, 0x1AD
    ctx->r4 = ADD32(0, 0X1AD);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_8;
    // 0x8021D5B0: addiu       $a0, $zero, 0x1AD
    ctx->r4 = ADD32(0, 0X1AD);
    after_8:
    // 0x8021D5B4: jal         0x80126E88
    // 0x8021D5B8: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_9;
    // 0x8021D5B8: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    after_9:
    // 0x8021D5BC: jal         0x80126E88
    // 0x8021D5C0: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_10;
    // 0x8021D5C0: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    after_10:
    // 0x8021D5C4: jal         0x80126E88
    // 0x8021D5C8: addiu       $a0, $zero, 0x1B1
    ctx->r4 = ADD32(0, 0X1B1);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_11;
    // 0x8021D5C8: addiu       $a0, $zero, 0x1B1
    ctx->r4 = ADD32(0, 0X1B1);
    after_11:
    // 0x8021D5CC: jal         0x80126E88
    // 0x8021D5D0: addiu       $a0, $zero, 0x1B2
    ctx->r4 = ADD32(0, 0X1B2);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_12;
    // 0x8021D5D0: addiu       $a0, $zero, 0x1B2
    ctx->r4 = ADD32(0, 0X1B2);
    after_12:
    // 0x8021D5D4: jal         0x80126E88
    // 0x8021D5D8: addiu       $a0, $zero, 0x1B3
    ctx->r4 = ADD32(0, 0X1B3);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_13;
    // 0x8021D5D8: addiu       $a0, $zero, 0x1B3
    ctx->r4 = ADD32(0, 0X1B3);
    after_13:
    // 0x8021D5DC: jal         0x80126E88
    // 0x8021D5E0: addiu       $a0, $zero, 0x1B4
    ctx->r4 = ADD32(0, 0X1B4);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_14;
    // 0x8021D5E0: addiu       $a0, $zero, 0x1B4
    ctx->r4 = ADD32(0, 0X1B4);
    after_14:
    // 0x8021D5E4: jal         0x80126E88
    // 0x8021D5E8: addiu       $a0, $zero, 0x1B5
    ctx->r4 = ADD32(0, 0X1B5);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_15;
    // 0x8021D5E8: addiu       $a0, $zero, 0x1B5
    ctx->r4 = ADD32(0, 0X1B5);
    after_15:
    // 0x8021D5EC: jal         0x80126E88
    // 0x8021D5F0: addiu       $a0, $zero, 0x1B6
    ctx->r4 = ADD32(0, 0X1B6);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_16;
    // 0x8021D5F0: addiu       $a0, $zero, 0x1B6
    ctx->r4 = ADD32(0, 0X1B6);
    after_16:
    // 0x8021D5F4: jal         0x80126E88
    // 0x8021D5F8: addiu       $a0, $zero, 0x1B7
    ctx->r4 = ADD32(0, 0X1B7);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_17;
    // 0x8021D5F8: addiu       $a0, $zero, 0x1B7
    ctx->r4 = ADD32(0, 0X1B7);
    after_17:
    // 0x8021D5FC: jal         0x80126E88
    // 0x8021D600: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_18;
    // 0x8021D600: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_18:
    // 0x8021D604: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D608: addiu       $a1, $a1, -0x29DC
    ctx->r5 = ADD32(ctx->r5, -0X29DC);
    // 0x8021D60C: jal         0x800058DC
    // 0x8021D610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_19;
    // 0x8021D610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_19:
L_8021D614:
    // 0x8021D614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021D618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021D61C: jr          $ra
    // 0x8021D620: nop

    return;
    // 0x8021D620: nop

;}
RECOMP_FUNC void M10_FUN_8021d624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021D628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021D62C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021D630: jal         0x800172F4
    // 0x8021D634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800172F4)(rdram, ctx);
        goto after_0;
    // 0x8021D634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021D638: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8021D63C: jal         0x80016E40
    // 0x8021D640: ori         $a0, $a0, 0xA000
    ctx->r4 = ctx->r4 | 0XA000;
    LOOKUP_FUNC(0x80016E40)(rdram, ctx);
        goto after_1;
    // 0x8021D640: ori         $a0, $a0, 0xA000
    ctx->r4 = ctx->r4 | 0XA000;
    after_1:
    // 0x8021D644: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D648: addiu       $a1, $a1, -0x299C
    ctx->r5 = ADD32(ctx->r5, -0X299C);
    // 0x8021D64C: jal         0x800058DC
    // 0x8021D650: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8021D650: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8021D654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021D658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021D65C: jr          $ra
    // 0x8021D660: nop

    return;
    // 0x8021D660: nop

;}
RECOMP_FUNC void M10_FUN_8021d664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021D668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021D66C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021D670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021D674: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x8021D678: jal         0x80126A0C
    // 0x8021D67C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x8021D67C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8021D680: beq         $v0, $zero, L_8021D694
    if (ctx->r2 == 0) {
        // 0x8021D684: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8021D694;
    }
    // 0x8021D684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021D688: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D68C: jal         0x800058DC
    // 0x8021D690: addiu       $a1, $a1, -0x295C
    ctx->r5 = ADD32(ctx->r5, -0X295C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8021D690: addiu       $a1, $a1, -0x295C
    ctx->r5 = ADD32(ctx->r5, -0X295C);
    after_1:
L_8021D694:
    // 0x8021D694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021D698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021D69C: jr          $ra
    // 0x8021D6A0: nop

    return;
    // 0x8021D6A0: nop

;}
RECOMP_FUNC void M10_FUN_8021d6a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D6A4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021D6A8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021D6AC: lw          $t6, 0x188($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X188);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021d6b0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021d6b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D6B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021D6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021D6B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021D6BC: bne         $t6, $zero, L_8021D71C
    if (ctx->r14 != 0) {
        // 0x8021D6C0: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8021D71C;
    }
    // 0x8021D6C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021D6C4: lbu         $t7, 0x181($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X181);
    // 0x8021D6C8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8021D6CC: bnel        $t7, $zero, L_8021D720
    if (ctx->r15 != 0) {
        // 0x8021D6D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021D720;
    }
    goto skip_0;
    // 0x8021D6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021D6D4: lw          $t8, -0x2A80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A80);
    // 0x8021D6D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8021D6DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8021D6E0: sltiu       $at, $t8, 0x2001
    ctx->r1 = ctx->r24 < 0X2001 ? 1 : 0;
    // 0x8021D6E4: bne         $at, $zero, L_8021D6F4
    if (ctx->r1 != 0) {
        // 0x8021D6E8: nop
    
            goto L_8021D6F4;
    }
    // 0x8021D6E8: nop

    // 0x8021D6EC: b           L_8021D71C
    // 0x8021D6F0: sb          $t9, 0x181($v0)
    MEM_B(0X181, ctx->r2) = ctx->r25;
        goto L_8021D71C;
    // 0x8021D6F0: sb          $t9, 0x181($v0)
    MEM_B(0X181, ctx->r2) = ctx->r25;
L_8021D6F4:
    // 0x8021D6F4: jal         0x801269C0
    // 0x8021D6F8: sb          $t0, 0x181($v0)
    MEM_B(0X181, ctx->r2) = ctx->r8;
    LOOKUP_FUNC(0x801269C0)(rdram, ctx);
        goto after_0;
    // 0x8021D6F8: sb          $t0, 0x181($v0)
    MEM_B(0X181, ctx->r2) = ctx->r8;
    after_0:
    // 0x8021D6FC: jal         0x80126930
    // 0x8021D700: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80126930)(rdram, ctx);
        goto after_1;
    // 0x8021D700: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8021D704: jal         0x80146B04
    // 0x8021D708: nop

    LOOKUP_FUNC(0x80146B04)(rdram, ctx);
        goto after_2;
    // 0x8021D708: nop

    after_2:
    // 0x8021D70C: jal         0x801F3B5C
    // 0x8021D710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_3;
    // 0x8021D710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8021D714: jal         0x80005700
    // 0x8021D718: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x8021D718: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
L_8021D71C:
    // 0x8021D71C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021D720:
    // 0x8021D720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021D724: jr          $ra
    // 0x8021D728: nop

    return;
    // 0x8021D728: nop

;}
RECOMP_FUNC void M10_FUN_8021d72c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D72C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021D730: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8021D734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021D738: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8021D73C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021D740: jal         0x80005670
    // 0x8021D744: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x8021D744: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    after_0:
    // 0x8021D748: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D74C: addiu       $a1, $a1, -0x2898
    ctx->r5 = ADD32(ctx->r5, -0X2898);
    // 0x8021D750: jal         0x800058DC
    // 0x8021D754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8021D754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8021D758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021D75C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021D760: jr          $ra
    // 0x8021D764: nop

    return;
    // 0x8021D764: nop

;}
RECOMP_FUNC void M10_FUN_8021d768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D768: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8021D76C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8021D770: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8021D774: jal         0x80142570
    // 0x8021D778: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x8021D778: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021D77C: jal         0x8013EA94
    // 0x8021D780: nop

    LOOKUP_FUNC(0x8013EA94)(rdram, ctx);
        goto after_1;
    // 0x8021D780: nop

    after_1:
    // 0x8021D784: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8021D788: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x8021D78C: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x8021D790: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8021D794: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8021D798: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8021D79C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021D7A0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8021D7A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8021D7A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8021D7AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8021D7B0: addiu       $a1, $a1, -0x1720
    ctx->r5 = ADD32(ctx->r5, -0X1720);
    // 0x8021D7B4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8021D7B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8021D7BC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8021D7C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8021D7C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8021D7C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8021D7CC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8021D7D0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8021D7D4: jal         0x8001A804
    // 0x8021D7D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x8021D7D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x8021D7DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8021D7E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021D7E4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D7E8: sb          $t1, -0x4410($at)
    MEM_B(-0X4410, ctx->r1) = ctx->r9;
    // 0x8021D7EC: addiu       $a1, $a1, -0x27F8
    ctx->r5 = ADD32(ctx->r5, -0X27F8);
    // 0x8021D7F0: jal         0x800058DC
    // 0x8021D7F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021D7F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x8021D7F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8021D7FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8021D800: jr          $ra
    // 0x8021D804: nop

    return;
    // 0x8021D804: nop

;}
RECOMP_FUNC void M10_FUN_8021d808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8021D80C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021D810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8021D814: jal         0x8013EB2C
    // 0x8021D818: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013EB2C)(rdram, ctx);
        goto after_0;
    // 0x8021D818: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021D81C: beql        $v0, $zero, L_8021D840
    if (ctx->r2 == 0) {
        // 0x8021D820: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021D840;
    }
    goto skip_0;
    // 0x8021D820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021D824: jal         0x80142570
    // 0x8021D828: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x8021D828: nop

    after_1:
    // 0x8021D82C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021D830: addiu       $a1, $a1, -0x27B4
    ctx->r5 = ADD32(ctx->r5, -0X27B4);
    // 0x8021D834: jal         0x800058DC
    // 0x8021D838: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8021D838: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8021D83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021D840:
    // 0x8021D840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8021D844: jr          $ra
    // 0x8021D848: nop

    return;
    // 0x8021D848: nop

;}
RECOMP_FUNC void M10_FUN_8021d84c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D84C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021D850: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8021D854: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021D858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8021D85C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8021D860: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x8021D864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8021D868:
    // 0x8021D868: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8021D86C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8021D870: sltiu       $at, $v0, 0x28
    ctx->r1 = ctx->r2 < 0X28 ? 1 : 0;
    // 0x8021D874: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8021D878: bne         $at, $zero, L_8021D868
    if (ctx->r1 != 0) {
        // 0x8021D87C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8021D868;
    }
    // 0x8021D87C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8021D880: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8021D884: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x8021D888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8021D88C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8021D890: jal         0x8012FE50
    // 0x8021D894: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x8021D894: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8021D898: jal         0x80020744
    // 0x8021D89C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x8021D89C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8021D8A0: jal         0x80005700
    // 0x8021D8A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x8021D8A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8021D8A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021D8AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021D8B0: jr          $ra
    // 0x8021D8B4: nop

    return;
    // 0x8021D8B4: nop

;}
RECOMP_FUNC void M10_FUN_8021d8b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D8B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8021D8BC: jr          $ra
    // 0x8021D8C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8021D8C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021d8c4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021d8c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D8C4: nop

    // 0x8021D8C8: nop

    // 0x8021D8CC: nop

;}
RECOMP_FUNC void M10_FUN_8021d8d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D8D0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8021D8D4: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021d8d8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021d8d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021D8D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8021D8DC: lw          $t6, 0xDC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XDC);
    // 0x8021D8E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021D8E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021D8E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8021D8EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021D8F0: bne         $a0, $t6, L_8021D904
    if (ctx->r4 != ctx->r14) {
        // 0x8021D8F4: lw          $v1, 0x5C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X5C);
            goto L_8021D904;
    }
    // 0x8021D8F4: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x8021D8F8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021D8FC: b           L_8021D90C
    // 0x8021D900: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_8021D90C;
    // 0x8021D900: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8021D904:
    // 0x8021D904: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021D908: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_8021D90C:
    // 0x8021D90C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8021D910: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8021D914: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8021D918: sb          $t7, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r15;
    // 0x8021D91C: lbu         $t0, 0x74($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X74);
    // 0x8021D920: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x8021D924: beq         $at, $zero, L_8021D970
    if (ctx->r1 == 0) {
        // 0x8021D928: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8021D970;
    }
    // 0x8021D928: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8021D92C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8021D930: addu        $at, $at, $t0
    gpr jr_addend_8021D938 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8021D934: lw          $t0, -0x15F4($at)
    ctx->r8 = ADD32(ctx->r1, -0X15F4);
    // 0x8021D938: jr          $t0
    // 0x8021D93C: nop

    switch (jr_addend_8021D938 >> 2) {
        case 0: goto L_8021D940; break;
        case 1: goto L_8021D958; break;
        case 2: goto L_8021D940; break;
        case 3: goto L_8021D958; break;
        case 4: goto L_8021D970; break;
        default: switch_error(__func__, 0x8021D938, 0x8023EA0C);
    }
    // 0x8021D93C: nop

L_8021D940:
    // 0x8021D940: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8021D944: sw          $s0, 0xDC($a3)
    MEM_W(0XDC, ctx->r7) = ctx->r16;
    // 0x8021D948: sw          $v1, 0x444($a3)
    MEM_W(0X444, ctx->r7) = ctx->r3;
    // 0x8021D94C: addiu       $t1, $t1, -0x4374
    ctx->r9 = ADD32(ctx->r9, -0X4374);
    // 0x8021D950: b           L_8021D984
    // 0x8021D954: sw          $t1, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r9;
        goto L_8021D984;
    // 0x8021D954: sw          $t1, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r9;
L_8021D958:
    // 0x8021D958: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8021D95C: sw          $s0, 0xEC($a3)
    MEM_W(0XEC, ctx->r7) = ctx->r16;
    // 0x8021D960: sw          $v1, 0x448($a3)
    MEM_W(0X448, ctx->r7) = ctx->r3;
    // 0x8021D964: addiu       $t2, $t2, -0x4354
    ctx->r10 = ADD32(ctx->r10, -0X4354);
    // 0x8021D968: b           L_8021D984
    // 0x8021D96C: sw          $t2, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r10;
        goto L_8021D984;
    // 0x8021D96C: sw          $t2, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r10;
L_8021D970:
    // 0x8021D970: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8021D974: sw          $s0, 0xEC($a3)
    MEM_W(0XEC, ctx->r7) = ctx->r16;
    // 0x8021D978: sw          $v1, 0x448($a3)
    MEM_W(0X448, ctx->r7) = ctx->r3;
    // 0x8021D97C: addiu       $t3, $t3, -0x6B8C
    ctx->r11 = ADD32(ctx->r11, -0X6B8C);
    // 0x8021D980: sw          $t3, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r11;
L_8021D984:
    // 0x8021D984: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x8021D988: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8021D98C: ori         $t5, $t4, 0x60
    ctx->r13 = ctx->r12 | 0X60;
    // 0x8021D990: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x8021D994: and         $t8, $t5, $at
    ctx->r24 = ctx->r13 & ctx->r1;
    // 0x8021D998: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x8021D99C: lbu         $t7, 0x1031($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1031);
    // 0x8021D9A0: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8021D9A4: bnel        $at, $zero, L_8021DC5C
    if (ctx->r1 != 0) {
        // 0x8021D9A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021DC5C;
    }
    goto skip_0;
    // 0x8021D9A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8021D9AC: lbu         $t9, 0x74($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X74);
    // 0x8021D9B0: addiu       $t1, $zero, 0x1E1
    ctx->r9 = ADD32(0, 0X1E1);
    // 0x8021D9B4: bnel        $t9, $zero, L_8021D9F0
    if (ctx->r25 != 0) {
        // 0x8021D9B8: sw          $t1, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r9;
            goto L_8021D9F0;
    }
    goto skip_1;
    // 0x8021D9B8: sw          $t1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r9;
    skip_1:
    // 0x8021D9BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8021D9C0: jal         0x80374254
    // 0x8021D9C4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80374254)(rdram, ctx);
        goto after_0;
    // 0x8021D9C4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8021D9C8: addiu       $t0, $zero, 0x1F
    ctx->r8 = ADD32(0, 0X1F);
    // 0x8021D9CC: sw          $t0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r8;
    // 0x8021D9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021D9D4: jal         0x801C4A5C
    // 0x8021D9D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_1;
    // 0x8021D9D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8021D9DC: jal         0x80225410
    // 0x8021D9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80225410)(rdram, ctx);
        goto after_2;
    // 0x8021D9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8021D9E4: b           L_8021DA18
    // 0x8021D9E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_8021DA18;
    // 0x8021D9E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8021D9EC: sw          $t1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r9;
L_8021D9F0:
    // 0x8021D9F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8021D9F4: lbu         $t2, 0x74($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X74);
    // 0x8021D9F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021D9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021DA00: bnel        $t2, $at, L_8021DA1C
    if (ctx->r10 != ctx->r1) {
        // 0x8021DA04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021DA1C;
    }
    goto skip_2;
    // 0x8021DA04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8021DA08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8021DA0C: jal         0x80225410
    // 0x8021DA10: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80225410)(rdram, ctx);
        goto after_3;
    // 0x8021DA10: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x8021DA14: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8021DA18:
    // 0x8021DA18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8021DA1C:
    // 0x8021DA1C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8021DA20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8021DA24: jal         0x8013AE20
    // 0x8021DA28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8013AE20)(rdram, ctx);
        goto after_4;
    // 0x8021DA28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_4:
    // 0x8021DA2C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8021DA30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8021DA34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8021DA38: lbu         $t3, 0x30($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X30);
    // 0x8021DA3C: lbu         $t8, 0x31($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X31);
    // 0x8021DA40: sh          $zero, 0x32E($v0)
    MEM_H(0X32E, ctx->r2) = 0;
    // 0x8021DA44: andi        $t5, $t3, 0xFF9F
    ctx->r13 = ctx->r11 & 0XFF9F;
    // 0x8021DA48: lbu         $t3, 0x32($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X32);
    // 0x8021DA4C: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x8021DA50: andi        $t6, $t5, 0xFE
    ctx->r14 = ctx->r13 & 0XFE;
    // 0x8021DA54: sb          $t5, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r13;
    // 0x8021DA58: andi        $t1, $t9, 0xE7
    ctx->r9 = ctx->r25 & 0XE7;
    // 0x8021DA5C: sb          $t9, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r25;
    // 0x8021DA60: andi        $t5, $t3, 0xFFEF
    ctx->r13 = ctx->r11 & 0XFFEF;
    // 0x8021DA64: lbu         $t9, 0x33($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X33);
    // 0x8021DA68: andi        $t8, $t5, 0xF3
    ctx->r24 = ctx->r13 & 0XF3;
    // 0x8021DA6C: sb          $t5, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r13;
    // 0x8021DA70: lbu         $t5, 0x38($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X38);
    // 0x8021DA74: andi        $t2, $t1, 0xF8
    ctx->r10 = ctx->r9 & 0XF8;
    // 0x8021DA78: sb          $t1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r9;
    // 0x8021DA7C: andi        $t1, $t9, 0xFFE7
    ctx->r9 = ctx->r25 & 0XFFE7;
    // 0x8021DA80: andi        $t7, $t8, 0xFC
    ctx->r15 = ctx->r24 & 0XFC;
    // 0x8021DA84: sb          $t8, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r24;
    // 0x8021DA88: andi        $t8, $t5, 0xFF7F
    ctx->r24 = ctx->r13 & 0XFF7F;
    // 0x8021DA8C: andi        $t3, $t1, 0xBF
    ctx->r11 = ctx->r9 & 0XBF;
    // 0x8021DA90: andi        $t9, $t8, 0x9F
    ctx->r25 = ctx->r24 & 0X9F;
    // 0x8021DA94: sb          $t1, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r9;
    // 0x8021DA98: andi        $t1, $t9, 0xEF
    ctx->r9 = ctx->r25 & 0XEF;
    // 0x8021DA9C: sb          $t8, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r24;
    // 0x8021DAA0: sb          $t2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r10;
    // 0x8021DAA4: sb          $t9, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r25;
    // 0x8021DAA8: andi        $t2, $t1, 0xF3
    ctx->r10 = ctx->r9 & 0XF3;
    // 0x8021DAAC: sb          $t1, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r9;
    // 0x8021DAB0: andi        $t4, $t3, 0xDF
    ctx->r12 = ctx->r11 & 0XDF;
    // 0x8021DAB4: sb          $t3, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r11;
    // 0x8021DAB8: sb          $t2, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r10;
    // 0x8021DABC: lhu         $t3, 0x38($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X38);
    // 0x8021DAC0: sb          $t4, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r12;
    // 0x8021DAC4: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x8021DAC8: andi        $t4, $t3, 0xFC7F
    ctx->r12 = ctx->r11 & 0XFC7F;
    // 0x8021DACC: sb          $t7, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r15;
    // 0x8021DAD0: sh          $t4, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r12;
    // 0x8021DAD4: sh          $zero, 0x330($v0)
    MEM_H(0X330, ctx->r2) = 0;
    // 0x8021DAD8: sh          $zero, 0x312($v0)
    MEM_H(0X312, ctx->r2) = 0;
    // 0x8021DADC: sb          $zero, 0x328($v0)
    MEM_B(0X328, ctx->r2) = 0;
    // 0x8021DAE0: sb          $zero, 0x329($v0)
    MEM_B(0X329, ctx->r2) = 0;
    // 0x8021DAE4: sb          $zero, 0x2FA($v0)
    MEM_B(0X2FA, ctx->r2) = 0;
    // 0x8021DAE8: sb          $zero, 0x374($v0)
    MEM_B(0X374, ctx->r2) = 0;
    // 0x8021DAEC: sb          $zero, 0x390($v0)
    MEM_B(0X390, ctx->r2) = 0;
    // 0x8021DAF0: swc1        $f0, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->f0.u32l;
    // 0x8021DAF4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8021DAF8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8021DAFC: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8021DB00: sb          $zero, 0x9C($t5)
    MEM_B(0X9C, ctx->r13) = 0;
    // 0x8021DB04: sb          $zero, 0x393($v0)
    MEM_B(0X393, ctx->r2) = 0;
    // 0x8021DB08: sb          $zero, 0x396($v0)
    MEM_B(0X396, ctx->r2) = 0;
    // 0x8021DB0C: sh          $zero, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = 0;
    // 0x8021DB10: lhu         $t6, 0x2C($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X2C);
    // 0x8021DB14: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021DB18: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8021DB1C: beql        $t6, $at, L_8021DB80
    if (ctx->r14 == ctx->r1) {
        // 0x8021DB20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021DB80;
    }
    goto skip_3;
    // 0x8021DB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8021DB24: lbu         $t7, 0x74($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X74);
    // 0x8021DB28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021DB2C: bnel        $t7, $at, L_8021DB80
    if (ctx->r15 != ctx->r1) {
        // 0x8021DB30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021DB80;
    }
    goto skip_4;
    // 0x8021DB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8021DB34: lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X36);
    // 0x8021DB38: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x8021DB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021DB40: bne         $v1, $at, L_8021DB64
    if (ctx->r3 != ctx->r1) {
        // 0x8021DB44: addiu       $a1, $zero, 0x506
        ctx->r5 = ADD32(0, 0X506);
            goto L_8021DB64;
    }
    // 0x8021DB44: addiu       $a1, $zero, 0x506
    ctx->r5 = ADD32(0, 0X506);
    // 0x8021DB48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8021DB4C: jal         0x80226710
    // 0x8021DB50: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80226710)(rdram, ctx);
        goto after_5;
    // 0x8021DB50: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_5:
    // 0x8021DB54: jal         0x80226780
    // 0x8021DB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80226780)(rdram, ctx);
        goto after_6;
    // 0x8021DB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8021DB5C: b           L_8021DB7C
    // 0x8021DB60: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_8021DB7C;
    // 0x8021DB60: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8021DB64:
    // 0x8021DB64: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x8021DB68: bne         $v1, $at, L_8021DB7C
    if (ctx->r3 != ctx->r1) {
        // 0x8021DB6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021DB7C;
    }
    // 0x8021DB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021DB70: jal         0x803704DC
    // 0x8021DB74: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x803704DC)(rdram, ctx);
        goto after_7;
    // 0x8021DB74: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // 0x8021DB78: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8021DB7C:
    // 0x8021DB7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8021DB80:
    // 0x8021DB80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8021DB84: jal         0x8037573C
    // 0x8021DB88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8037573C)(rdram, ctx);
        goto after_8;
    // 0x8021DB88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_8:
    // 0x8021DB8C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8021DB90: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8021DB94: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x8021DB98: addiu       $at, $zero, 0x8D
    ctx->r1 = ADD32(0, 0X8D);
    // 0x8021DB9C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8021DBA0: bne         $t9, $at, L_8021DBAC
    if (ctx->r25 != ctx->r1) {
        // 0x8021DBA4: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8021DBAC;
    }
    // 0x8021DBA4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8021DBA8: sb          $t0, 0x1034($a3)
    MEM_B(0X1034, ctx->r7) = ctx->r8;
L_8021DBAC:
    // 0x8021DBAC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8021DBB0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8021DBB4: jal         0x80011198
    // 0x8021DBB8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_9;
    // 0x8021DBB8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_9:
    // 0x8021DBBC: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8021DBC0: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8021DBC4: lbu         $v1, 0x1034($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X1034);
    // 0x8021DBC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021DBCC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8021DBD0: bnel        $v1, $at, L_8021DBE4
    if (ctx->r3 != ctx->r1) {
        // 0x8021DBD4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8021DBE4;
    }
    goto skip_5;
    // 0x8021DBD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_5:
    // 0x8021DBD8: lw          $t1, 0xDC($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XDC);
    // 0x8021DBDC: beq         $s0, $t1, L_8021DBF8
    if (ctx->r16 == ctx->r9) {
        // 0x8021DBE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8021DBF8;
    }
    // 0x8021DBE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8021DBE4:
    // 0x8021DBE4: bne         $v1, $at, L_8021DC30
    if (ctx->r3 != ctx->r1) {
        // 0x8021DBE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021DC30;
    }
    // 0x8021DBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021DBEC: lw          $t2, 0xEC($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XEC);
    // 0x8021DBF0: bnel        $s0, $t2, L_8021DC34
    if (ctx->r16 != ctx->r10) {
        // 0x8021DBF4: lbu         $t9, 0x30($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X30);
            goto L_8021DC34;
    }
    goto skip_6;
    // 0x8021DBF4: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    skip_6:
L_8021DBF8:
    // 0x8021DBF8: lbu         $t3, 0x30($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X30);
    // 0x8021DBFC: lbu         $t8, 0x33($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X33);
    // 0x8021DC00: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021DC04: andi        $t4, $t3, 0xFFE1
    ctx->r12 = ctx->r11 & 0XFFE1;
    // 0x8021DC08: ori         $t5, $t4, 0x6
    ctx->r13 = ctx->r12 | 0X6;
    // 0x8021DC0C: ori         $t7, $t8, 0x80
    ctx->r15 = ctx->r24 | 0X80;
    // 0x8021DC10: sb          $t5, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r13;
    // 0x8021DC14: sb          $t7, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r15;
    // 0x8021DC18: sb          $zero, 0x1034($a3)
    MEM_B(0X1034, ctx->r7) = 0;
    // 0x8021DC1C: addiu       $a1, $a1, -0x2394
    ctx->r5 = ADD32(ctx->r5, -0X2394);
    // 0x8021DC20: jal         0x800058DC
    // 0x8021DC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x8021DC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8021DC28: b           L_8021DC5C
    // 0x8021DC2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021DC5C;
    // 0x8021DC2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021DC30:
    // 0x8021DC30: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
L_8021DC34:
    // 0x8021DC34: lbu         $t1, 0x33($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X33);
    // 0x8021DC38: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021DC3C: andi        $t0, $t9, 0xFFE1
    ctx->r8 = ctx->r25 & 0XFFE1;
    // 0x8021DC40: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x8021DC44: sh          $zero, 0x312($v0)
    MEM_H(0X312, ctx->r2) = 0;
    // 0x8021DC48: sb          $t0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r8;
    // 0x8021DC4C: sb          $t2, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r10;
    // 0x8021DC50: jal         0x800058DC
    // 0x8021DC54: addiu       $a1, $a1, -0x1BEC
    ctx->r5 = ADD32(ctx->r5, -0X1BEC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x8021DC54: addiu       $a1, $a1, -0x1BEC
    ctx->r5 = ADD32(ctx->r5, -0X1BEC);
    after_11:
    // 0x8021DC58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021DC5C:
    // 0x8021DC5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021DC60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8021DC64: jr          $ra
    // 0x8021DC68: nop

    return;
    // 0x8021DC68: nop

;}
