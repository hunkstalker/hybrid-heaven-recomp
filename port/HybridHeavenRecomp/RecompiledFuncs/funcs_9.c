#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80023b48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023B48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023B4C: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023B58: lbu         $t6, 0x7D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7D);
    // 0x80023B5C: beql        $t6, $zero, L_80023B78
    if (ctx->r14 == 0) {
        // 0x80023B60: lhu         $t7, 0x9A($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X9A);
            goto L_80023B78;
    }
    goto skip_0;
    // 0x80023B60: lhu         $t7, 0x9A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X9A);
    skip_0:
    // 0x80023B64: jal         0x80025694
    // 0x80023B68: nop

    LOOKUP_FUNC(0x80025694)(rdram, ctx);
        goto after_0;
    // 0x80023B68: nop

    after_0:
    // 0x80023B6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023B70: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023B74: lhu         $t7, 0x9A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X9A);
L_80023B78:
    // 0x80023B78: beql        $t7, $zero, L_80023B94
    if (ctx->r15 == 0) {
        // 0x80023B7C: lbu         $t8, 0x6($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X6);
            goto L_80023B94;
    }
    goto skip_1;
    // 0x80023B7C: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    skip_1:
    // 0x80023B80: jal         0x80025150
    // 0x80023B84: nop

    LOOKUP_FUNC(0x80025150)(rdram, ctx);
        goto after_1;
    // 0x80023B84: nop

    after_1:
    // 0x80023B88: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023B8C: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023B90: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
L_80023B94:
    // 0x80023B94: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80023B98: beql        $t9, $zero, L_80023BB4
    if (ctx->r25 == 0) {
        // 0x80023B9C: lhu         $t0, 0x4C($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X4C);
            goto L_80023BB4;
    }
    goto skip_2;
    // 0x80023B9C: lhu         $t0, 0x4C($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4C);
    skip_2:
    // 0x80023BA0: jal         0x80023BF4
    // 0x80023BA4: nop

    LOOKUP_FUNC(0x80023BF4)(rdram, ctx);
        goto after_2;
    // 0x80023BA4: nop

    after_2:
    // 0x80023BA8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023BAC: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023BB0: lhu         $t0, 0x4C($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4C);
L_80023BB4:
    // 0x80023BB4: beql        $t0, $zero, L_80023BD0
    if (ctx->r8 == 0) {
        // 0x80023BB8: lbu         $t1, 0x6($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X6);
            goto L_80023BD0;
    }
    goto skip_3;
    // 0x80023BB8: lbu         $t1, 0x6($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X6);
    skip_3:
    // 0x80023BBC: jal         0x80024358
    // 0x80023BC0: nop

    LOOKUP_FUNC(0x80024358)(rdram, ctx);
        goto after_3;
    // 0x80023BC0: nop

    after_3:
    // 0x80023BC4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023BC8: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023BCC: lbu         $t1, 0x6($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X6);
L_80023BD0:
    // 0x80023BD0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80023BD4: beql        $t2, $zero, L_80023BE8
    if (ctx->r10 == 0) {
        // 0x80023BD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80023BE8;
    }
    goto skip_4;
    // 0x80023BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80023BDC: jal         0x80023D04
    // 0x80023BE0: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_4;
    // 0x80023BE0: nop

    after_4:
    // 0x80023BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BE8:
    // 0x80023BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023BEC: jr          $ra
    // 0x80023BF0: nop

    return;
    // 0x80023BF0: nop

;}
RECOMP_FUNC void FUN_80023bf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023BF4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80023BF8: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80023BFC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80023C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023C08: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x80023C0C: andi        $t7, $t6, 0xFD
    ctx->r15 = ctx->r14 & 0XFD;
    // 0x80023C10: sb          $t7, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r15;
    // 0x80023C14: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80023C18: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80023C1C: addiu       $t6, $t6, 0x7FD8
    ctx->r14 = ADD32(ctx->r14, 0X7FD8);
    // 0x80023C20: lh          $t8, 0xA8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA8);
    // 0x80023C24: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x80023C28: lhu         $t1, 0x38($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X38);
    // 0x80023C2C: lh          $t3, 0x36($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X36);
    // 0x80023C30: lh          $t4, 0xC6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XC6);
    // 0x80023C34: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80023C38: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80023C3C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80023C40: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80023C44: bgez        $v0, L_80023C54
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80023C48: slti        $at, $v0, 0x4801
        ctx->r1 = SIGNED(ctx->r2) < 0X4801 ? 1 : 0;
            goto L_80023C54;
    }
    // 0x80023C48: slti        $at, $v0, 0x4801
    ctx->r1 = SIGNED(ctx->r2) < 0X4801 ? 1 : 0;
    // 0x80023C4C: b           L_80023C60
    // 0x80023C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80023C60;
    // 0x80023C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80023C54:
    // 0x80023C54: bnel        $at, $zero, L_80023C64
    if (ctx->r1 != 0) {
        // 0x80023C58: andi        $a1, $v0, 0xFF
        ctx->r5 = ctx->r2 & 0XFF;
            goto L_80023C64;
    }
    goto skip_0;
    // 0x80023C58: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    skip_0:
    // 0x80023C5C: addiu       $v0, $zero, 0x4800
    ctx->r2 = ADD32(0, 0X4800);
L_80023C60:
    // 0x80023C60: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
L_80023C64:
    // 0x80023C64: sra         $v0, $v0, 8
    ctx->r2 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80023C68: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80023C6C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80023C70: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80023C74: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80023C78: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80023C7C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80023C80: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80023C84: bgez        $a1, L_80023C98
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80023C88: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80023C98;
    }
    // 0x80023C88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80023C8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023C90: nop

    // 0x80023C94: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80023C98:
    // 0x80023C98: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80023C9C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80023CA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80023CA4: lwc1        $f4, 0xB0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x80023CA8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80023CAC: addiu       $t9, $t9, -0x4420
    ctx->r25 = ADD32(ctx->r25, -0X4420);
    // 0x80023CB0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80023CB4: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80023CB8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80023CBC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80023CC0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80023CC4: nop

    // 0x80023CC8: bc1tl       L_80023CF8
    if (c1cs) {
        // 0x80023CCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80023CF8;
    }
    goto skip_1;
    // 0x80023CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80023CD0: swc1        $f0, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->f0.u32l;
    // 0x80023CD4: lbu         $t7, -0x454C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X454C);
    // 0x80023CD8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80023CDC: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80023CE0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80023CE4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80023CE8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80023CEC: jal         0x8002AB10
    // 0x80023CF0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    LOOKUP_FUNC(0x8002AB10)(rdram, ctx);
        goto after_0;
    // 0x80023CF0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80023CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CF8:
    // 0x80023CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023CFC: jr          $ra
    // 0x80023D00: nop

    return;
    // 0x80023D00: nop

;}
RECOMP_FUNC void FUN_80023d04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023D04: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80023D08: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
    // 0x80023D0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80023D10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023D14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80023D18: lbu         $t6, 0x6($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X6);
    // 0x80023D1C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80023D20: andi        $t7, $t6, 0xFE
    ctx->r15 = ctx->r14 & 0XFE;
    // 0x80023D24: sb          $t7, 0x6($t1)
    MEM_B(0X6, ctx->r9) = ctx->r15;
    // 0x80023D28: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80023D2C: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
    // 0x80023D30: lbu         $t8, 0x48($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X48);
    // 0x80023D34: lh          $t9, 0x40($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X40);
    // 0x80023D38: lh          $t3, 0x42($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X42);
    // 0x80023D3C: lhu         $t4, 0x3A($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X3A);
    // 0x80023D40: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80023D44: addu        $t0, $t2, $t3
    ctx->r8 = ADD32(ctx->r10, ctx->r11);
    // 0x80023D48: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023D4C: mflo        $t0
    ctx->r8 = lo;
    // 0x80023D50: slt         $at, $t0, $at
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80023D54: bne         $at, $zero, L_80023D64
    if (ctx->r1 != 0) {
        // 0x80023D58: nop
    
            goto L_80023D64;
    }
    // 0x80023D58: nop

    // 0x80023D5C: b           L_80023D78
    // 0x80023D60: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
        goto L_80023D78;
    // 0x80023D60: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
L_80023D64:
    // 0x80023D64: bgezl       $t0, L_80023D78
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80023D68: sra         $t0, $t0, 8
        ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
            goto L_80023D78;
    }
    goto skip_0;
    // 0x80023D68: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    skip_0:
    // 0x80023D6C: b           L_80023D78
    // 0x80023D70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80023D78;
    // 0x80023D70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80023D74: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
L_80023D78:
    // 0x80023D78: lhu         $t5, 0x4A($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X4A);
    // 0x80023D7C: lh          $v0, 0xAA($t1)
    ctx->r2 = MEM_H(ctx->r9, 0XAA);
    // 0x80023D80: lhu         $s0, 0x4C($t1)
    ctx->r16 = MEM_HU(ctx->r9, 0X4C);
    // 0x80023D84: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023D88: addiu       $t6, $v0, 0x100
    ctx->r14 = ADD32(ctx->r2, 0X100);
    // 0x80023D8C: mflo        $t0
    ctx->r8 = lo;
    // 0x80023D90: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80023D94: beql        $v0, $zero, L_80023DC0
    if (ctx->r2 == 0) {
        // 0x80023D98: lh          $v0, 0xC8($t1)
        ctx->r2 = MEM_H(ctx->r9, 0XC8);
            goto L_80023DC0;
    }
    goto skip_1;
    // 0x80023D98: lh          $v0, 0xC8($t1)
    ctx->r2 = MEM_H(ctx->r9, 0XC8);
    skip_1:
    // 0x80023D9C: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023DA0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80023DA4: mflo        $t0
    ctx->r8 = lo;
    // 0x80023DA8: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80023DAC: slt         $at, $t0, $at
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80023DB0: bnel        $at, $zero, L_80023DC0
    if (ctx->r1 != 0) {
        // 0x80023DB4: lh          $v0, 0xC8($t1)
        ctx->r2 = MEM_H(ctx->r9, 0XC8);
            goto L_80023DC0;
    }
    goto skip_2;
    // 0x80023DB4: lh          $v0, 0xC8($t1)
    ctx->r2 = MEM_H(ctx->r9, 0XC8);
    skip_2:
    // 0x80023DB8: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
    // 0x80023DBC: lh          $v0, 0xC8($t1)
    ctx->r2 = MEM_H(ctx->r9, 0XC8);
L_80023DC0:
    // 0x80023DC0: beql        $v0, $zero, L_80023E18
    if (ctx->r2 == 0) {
        // 0x80023DC4: lbu         $a1, 0xBE($t1)
        ctx->r5 = MEM_BU(ctx->r9, 0XBE);
            goto L_80023E18;
    }
    goto skip_3;
    // 0x80023DC4: lbu         $a1, 0xBE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XBE);
    skip_3:
    // 0x80023DC8: bgez        $v0, L_80023DD8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80023DCC: sra         $v1, $v0, 6
        ctx->r3 = S32(SIGNED(ctx->r2) >> 6);
            goto L_80023DD8;
    }
    // 0x80023DCC: sra         $v1, $v0, 6
    ctx->r3 = S32(SIGNED(ctx->r2) >> 6);
    // 0x80023DD0: addiu       $at, $v0, 0x3F
    ctx->r1 = ADD32(ctx->r2, 0X3F);
    // 0x80023DD4: sra         $v1, $at, 6
    ctx->r3 = S32(SIGNED(ctx->r1) >> 6);
L_80023DD8:
    // 0x80023DD8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80023DDC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80023DE0: slti        $at, $v1, -0xFF
    ctx->r1 = SIGNED(ctx->r3) < -0XFF ? 1 : 0;
    // 0x80023DE4: beq         $at, $zero, L_80023DF4
    if (ctx->r1 == 0) {
        // 0x80023DE8: addiu       $t7, $v1, 0x100
        ctx->r15 = ADD32(ctx->r3, 0X100);
            goto L_80023DF4;
    }
    // 0x80023DE8: addiu       $t7, $v1, 0x100
    ctx->r15 = ADD32(ctx->r3, 0X100);
    // 0x80023DEC: b           L_80023E14
    // 0x80023DF0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80023E14;
    // 0x80023DF0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80023DF4:
    // 0x80023DF4: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023DF8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80023DFC: mflo        $t0
    ctx->r8 = lo;
    // 0x80023E00: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80023E04: slt         $at, $t0, $at
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80023E08: bnel        $at, $zero, L_80023E18
    if (ctx->r1 != 0) {
        // 0x80023E0C: lbu         $a1, 0xBE($t1)
        ctx->r5 = MEM_BU(ctx->r9, 0XBE);
            goto L_80023E18;
    }
    goto skip_4;
    // 0x80023E0C: lbu         $a1, 0xBE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XBE);
    skip_4:
    // 0x80023E10: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
L_80023E14:
    // 0x80023E14: lbu         $a1, 0xBE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XBE);
L_80023E18:
    // 0x80023E18: beq         $a1, $zero, L_80023E4C
    if (ctx->r5 == 0) {
        // 0x80023E1C: nop
    
            goto L_80023E4C;
    }
    // 0x80023E1C: nop

    // 0x80023E20: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80023E28: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80023E2C: mflo        $t0
    ctx->r8 = lo;
    // 0x80023E30: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80023E34: jal         0x80024114
    // 0x80023E38: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80024114)(rdram, ctx);
        goto after_0;
    // 0x80023E38: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x80023E3C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80023E40: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
    // 0x80023E44: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80023E48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80023E4C:
    // 0x80023E4C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80023E50: addiu       $a3, $a3, -0x4540
    ctx->r7 = ADD32(ctx->r7, -0X4540);
    // 0x80023E54: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x80023E58: beql        $v1, $zero, L_80023EE8
    if (ctx->r3 == 0) {
        // 0x80023E5C: lw          $t3, 0x0($t1)
        ctx->r11 = MEM_W(ctx->r9, 0X0);
            goto L_80023EE8;
    }
    goto skip_5;
    // 0x80023E5C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    skip_5:
    // 0x80023E60: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80023E64: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    // 0x80023E68: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x80023E6C: beq         $v0, $at, L_80023EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80023E70: addiu       $at, $zero, 0x122
        ctx->r1 = ADD32(0, 0X122);
            goto L_80023EE4;
    }
    // 0x80023E70: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x80023E74: beq         $v0, $at, L_80023EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80023E78: addiu       $at, $zero, 0x125
        ctx->r1 = ADD32(0, 0X125);
            goto L_80023EE4;
    }
    // 0x80023E78: addiu       $at, $zero, 0x125
    ctx->r1 = ADD32(0, 0X125);
    // 0x80023E7C: beq         $v0, $at, L_80023EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80023E80: addiu       $at, $zero, 0x12A
        ctx->r1 = ADD32(0, 0X12A);
            goto L_80023EE4;
    }
    // 0x80023E80: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x80023E84: beq         $v0, $at, L_80023EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80023E88: addiu       $at, $zero, 0x213
        ctx->r1 = ADD32(0, 0X213);
            goto L_80023EE4;
    }
    // 0x80023E88: addiu       $at, $zero, 0x213
    ctx->r1 = ADD32(0, 0X213);
    // 0x80023E8C: beq         $v0, $at, L_80023EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80023E90: addiu       $at, $zero, 0x214
        ctx->r1 = ADD32(0, 0X214);
            goto L_80023EE4;
    }
    // 0x80023E90: addiu       $at, $zero, 0x214
    ctx->r1 = ADD32(0, 0X214);
    // 0x80023E94: beql        $v0, $at, L_80023EE8
    if (ctx->r2 == ctx->r1) {
        // 0x80023E98: lw          $t3, 0x0($t1)
        ctx->r11 = MEM_W(ctx->r9, 0X0);
            goto L_80023EE8;
    }
    goto skip_6;
    // 0x80023E98: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    skip_6:
    // 0x80023E9C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023EA0: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
    // 0x80023EA4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80023EA8: sra         $a1, $v1, 8
    ctx->r5 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80023EAC: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80023EB0: subu        $a2, $t2, $t9
    ctx->r6 = SUB32(ctx->r10, ctx->r25);
    // 0x80023EB4: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80023EB8: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80023EBC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80023EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80023EC4: mflo        $t0
    ctx->r8 = lo;
    // 0x80023EC8: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80023ECC: jal         0x80024114
    // 0x80023ED0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80024114)(rdram, ctx);
        goto after_1;
    // 0x80023ED0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_1:
    // 0x80023ED4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80023ED8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80023EDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80023EE0: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
L_80023EE4:
    // 0x80023EE4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_80023EE8:
    // 0x80023EE8: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80023EEC: addiu       $a3, $a3, -0x4544
    ctx->r7 = ADD32(ctx->r7, -0X4544);
    // 0x80023EF0: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x80023EF4: sltiu       $at, $t4, 0x100
    ctx->r1 = ctx->r12 < 0X100 ? 1 : 0;
    // 0x80023EF8: beq         $at, $zero, L_80023F90
    if (ctx->r1 == 0) {
        // 0x80023EFC: nop
    
            goto L_80023F90;
    }
    // 0x80023EFC: nop

    // 0x80023F00: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x80023F04: beq         $v1, $zero, L_80023F4C
    if (ctx->r3 == 0) {
        // 0x80023F08: nop
    
            goto L_80023F4C;
    }
    // 0x80023F08: nop

    // 0x80023F0C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023F10: lhu         $t5, 0x0($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X0);
    // 0x80023F14: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80023F18: sra         $a1, $v1, 8
    ctx->r5 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80023F1C: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80023F20: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
    // 0x80023F24: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80023F28: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80023F2C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80023F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80023F34: mflo        $t0
    ctx->r8 = lo;
    // 0x80023F38: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80023F3C: jal         0x80024114
    // 0x80023F40: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80024114)(rdram, ctx);
        goto after_2;
    // 0x80023F40: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_2:
    // 0x80023F44: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80023F48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80023F4C:
    // 0x80023F4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80023F50: lbu         $a1, -0x4532($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X4532);
    // 0x80023F54: beq         $a1, $zero, L_80023F90
    if (ctx->r5 == 0) {
        // 0x80023F58: nop
    
            goto L_80023F90;
    }
    // 0x80023F58: nop

    // 0x80023F5C: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023F60: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80023F64: lb          $t8, -0x4533($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4533);
    // 0x80023F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80023F6C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80023F70: mflo        $t0
    ctx->r8 = lo;
    // 0x80023F74: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80023F78: bgez        $t8, L_80023F90
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80023F7C: nop
    
            goto L_80023F90;
    }
    // 0x80023F7C: nop

    // 0x80023F80: jal         0x80024114
    // 0x80023F84: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80024114)(rdram, ctx);
        goto after_3;
    // 0x80023F84: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_3:
    // 0x80023F88: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80023F8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80023F90:
    // 0x80023F90: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80023F94: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
    // 0x80023F98: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80023F9C: lbu         $a3, -0x4549($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X4549);
    // 0x80023FA0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80023FA4: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    // 0x80023FA8: beq         $a3, $zero, L_80024008
    if (ctx->r7 == 0) {
        // 0x80023FAC: andi        $a1, $a1, 0x7FFF
        ctx->r5 = ctx->r5 & 0X7FFF;
            goto L_80024008;
    }
    // 0x80023FAC: andi        $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 & 0X7FFF;
    // 0x80023FB0: beq         $a1, $at, L_80024008
    if (ctx->r5 == ctx->r1) {
        // 0x80023FB4: addiu       $at, $zero, 0x300
        ctx->r1 = ADD32(0, 0X300);
            goto L_80024008;
    }
    // 0x80023FB4: addiu       $at, $zero, 0x300
    ctx->r1 = ADD32(0, 0X300);
    // 0x80023FB8: beq         $a1, $at, L_80024008
    if (ctx->r5 == ctx->r1) {
        // 0x80023FBC: nop
    
            goto L_80024008;
    }
    // 0x80023FBC: nop

    // 0x80023FC0: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023FC4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80023FC8: lb          $t2, -0x454A($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X454A);
    // 0x80023FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80023FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80023FD4: mflo        $t0
    ctx->r8 = lo;
    // 0x80023FD8: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80023FDC: bgez        $t2, L_80024008
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80023FE0: nop
    
            goto L_80024008;
    }
    // 0x80023FE0: nop

    // 0x80023FE4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x80023FE8: jal         0x80024114
    // 0x80023FEC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80024114)(rdram, ctx);
        goto after_4;
    // 0x80023FEC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_4:
    // 0x80023FF0: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80023FF4: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
    // 0x80023FF8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80023FFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80024000: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80024004: andi        $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 & 0X7FFF;
L_80024008:
    // 0x80024008: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002400C: addiu       $v1, $v1, -0x4538
    ctx->r3 = ADD32(ctx->r3, -0X4538);
    // 0x80024010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024018:
    // 0x80024018: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x8002401C: bne         $a1, $t9, L_8002407C
    if (ctx->r5 != ctx->r25) {
        // 0x80024020: lui         $t4, 0x800D
        ctx->r12 = S32(0X800D << 16);
            goto L_8002407C;
    }
    // 0x80024020: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80024024: addiu       $t4, $t4, -0x453C
    ctx->r12 = ADD32(ctx->r12, -0X453C);
    // 0x80024028: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8002402C: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80024030: lhu         $a3, 0x2($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X2);
    // 0x80024034: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x80024038: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8002403C: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024040: sra         $t7, $t5, 8
    ctx->r15 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80024044: subu        $a2, $t6, $t7
    ctx->r6 = SUB32(ctx->r14, ctx->r15);
    // 0x80024048: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x8002404C: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80024050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024054: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x80024058: mflo        $t0
    ctx->r8 = lo;
    // 0x8002405C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80024060: jal         0x80024114
    // 0x80024064: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80024114)(rdram, ctx);
        goto after_5;
    // 0x80024064: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_5:
    // 0x80024068: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8002406C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80024070: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80024074: b           L_80024088
    // 0x80024078: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
        goto L_80024088;
    // 0x80024078: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
L_8002407C:
    // 0x8002407C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80024080: bne         $v0, $a0, L_80024018
    if (ctx->r2 != ctx->r4) {
        // 0x80024084: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80024018;
    }
    // 0x80024084: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80024088:
    // 0x80024088: lh          $t8, 0xB4($t1)
    ctx->r24 = MEM_H(ctx->r9, 0XB4);
    // 0x8002408C: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x80024090: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80024094: bne         $a2, $t8, L_800240AC
    if (ctx->r6 != ctx->r24) {
        // 0x80024098: lui         $t3, 0x800D
        ctx->r11 = S32(0X800D << 16);
            goto L_800240AC;
    }
    // 0x80024098: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8002409C: lhu         $t9, 0xB6($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0XB6);
    // 0x800240A0: andi        $t2, $s0, 0xFFFF
    ctx->r10 = ctx->r16 & 0XFFFF;
    // 0x800240A4: beql        $t2, $t9, L_80024104
    if (ctx->r10 == ctx->r25) {
        // 0x800240A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80024104;
    }
    goto skip_7;
    // 0x800240A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_800240AC:
    // 0x800240AC: sh          $t0, 0xB4($t1)
    MEM_H(0XB4, ctx->r9) = ctx->r8;
    // 0x800240B0: lw          $t3, -0x425C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X425C);
    // 0x800240B4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800240B8: sll         $a3, $s0, 2
    ctx->r7 = S32(ctx->r16 << 2);
    // 0x800240BC: sh          $s0, 0xB6($t3)
    MEM_H(0XB6, ctx->r11) = ctx->r16;
    // 0x800240C0: lbu         $t4, -0x454C($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X454C);
    // 0x800240C4: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // 0x800240C8: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    // 0x800240CC: subu        $a3, $a3, $s0
    ctx->r7 = SUB32(ctx->r7, ctx->r16);
    // 0x800240D0: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800240D4: sll         $a3, $a3, 4
    ctx->r7 = S32(ctx->r7 << 4);
    // 0x800240D8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800240DC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800240E0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800240E4: addiu       $t6, $t6, -0x4420
    ctx->r14 = ADD32(ctx->r14, -0X4420);
    // 0x800240E8: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // 0x800240EC: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800240F0: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x800240F4: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    // 0x800240F8: jal         0x80026950
    // 0x800240FC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    LOOKUP_FUNC(0x80026950)(rdram, ctx);
        goto after_6;
    // 0x800240FC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_6:
    // 0x80024100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80024104:
    // 0x80024104: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80024108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002410C: jr          $ra
    // 0x80024110: nop

    return;
    // 0x80024110: nop

;}
RECOMP_FUNC void FUN_80024114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024114: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80024118: lw          $t6, -0x425C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X425C);
    // 0x8002411C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80024120: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80024124: lbu         $t7, 0x49($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X49);
    // 0x80024128: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x8002412C: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80024130: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80024134: bne         $at, $zero, L_80024178
    if (ctx->r1 != 0) {
        // 0x80024138: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80024178;
    }
    // 0x80024138: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002413C: slti        $at, $a0, 0x200
    ctx->r1 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x80024140: beq         $at, $zero, L_8002415C
    if (ctx->r1 == 0) {
        // 0x80024144: nop
    
            goto L_8002415C;
    }
    // 0x80024144: nop

    // 0x80024148: multu       $a1, $a0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002414C: mflo        $a0
    ctx->r4 = lo;
    // 0x80024150: sra         $v0, $a0, 8
    ctx->r2 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80024154: jr          $ra
    // 0x80024158: nop

    return;
    // 0x80024158: nop

L_8002415C:
    // 0x8002415C: bgtz        $a2, L_80024168
    if (SIGNED(ctx->r6) > 0) {
        // 0x80024160: nop
    
            goto L_80024168;
    }
    // 0x80024160: nop

    // 0x80024164: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80024168:
    // 0x80024168: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002416C: mflo        $a0
    ctx->r4 = lo;
    // 0x80024170: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80024174: nop

L_80024178:
    // 0x80024178: jr          $ra
    // 0x8002417C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8002417C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80024180(rdram, ctx);
;}
RECOMP_FUNC void FUN_80024180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024180: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80024184: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80024188: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002418C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024194: sh          $zero, 0x4C($t6)
    MEM_H(0X4C, ctx->r14) = 0;
    // 0x80024198: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002419C: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800241A0: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x800241A4: lhu         $t7, 0x4E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4E);
    // 0x800241A8: beq         $t7, $zero, L_800241EC
    if (ctx->r15 == 0) {
        // 0x800241AC: nop
    
            goto L_800241EC;
    }
    // 0x800241AC: nop

    // 0x800241B0: jal         0x80023D04
    // 0x800241B4: sh          $t8, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r24;
    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_0;
    // 0x800241B4: sh          $t8, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r24;
    after_0:
    // 0x800241B8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800241BC: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x800241C0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800241C4: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x800241C8: sb          $zero, 0x49($t9)
    MEM_B(0X49, ctx->r25) = 0;
    // 0x800241CC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800241D0: sh          $t0, 0x4A($t1)
    MEM_H(0X4A, ctx->r9) = ctx->r8;
    // 0x800241D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800241D8: lhu         $t2, 0x4E($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X4E);
    // 0x800241DC: jal         0x80023D04
    // 0x800241E0: sh          $t2, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r10;
    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_1;
    // 0x800241E0: sh          $t2, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r10;
    after_1:
    // 0x800241E4: b           L_80024200
    // 0x800241E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80024200;
    // 0x800241E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800241EC:
    // 0x800241EC: jal         0x80023D04
    // 0x800241F0: sh          $t3, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_2;
    // 0x800241F0: sh          $t3, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r11;
    after_2:
    // 0x800241F4: jal         0x8002420C
    // 0x800241F8: nop

    LOOKUP_FUNC(0x8002420C)(rdram, ctx);
        goto after_3;
    // 0x800241F8: nop

    after_3:
    // 0x800241FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024200:
    // 0x80024200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024204: jr          $ra
    // 0x80024208: nop

    return;
    // 0x80024208: nop

;}
RECOMP_FUNC void FUN_8002420c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002420C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80024210: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80024214: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002421C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024220: lhu         $t6, 0x54($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X54);
    // 0x80024224: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80024228: beq         $t6, $zero, L_80024260
    if (ctx->r14 == 0) {
        // 0x8002422C: nop
    
            goto L_80024260;
    }
    // 0x8002422C: nop

    // 0x80024230: sb          $t7, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r15;
    // 0x80024234: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024238: lhu         $t8, 0x4A($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X4A);
    // 0x8002423C: lhu         $t9, 0x54($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X54);
    // 0x80024240: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80024244: sh          $t0, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r8;
    // 0x80024248: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002424C: lhu         $t1, 0x50($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X50);
    // 0x80024250: jal         0x80023D04
    // 0x80024254: sh          $t1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r9;
    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_0;
    // 0x80024254: sh          $t1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r9;
    after_0:
    // 0x80024258: b           L_8002426C
    // 0x8002425C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002426C;
    // 0x8002425C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024260:
    // 0x80024260: jal         0x80024278
    // 0x80024264: nop

    LOOKUP_FUNC(0x80024278)(rdram, ctx);
        goto after_1;
    // 0x80024264: nop

    after_1:
    // 0x80024268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002426C:
    // 0x8002426C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024270: jr          $ra
    // 0x80024274: nop

    return;
    // 0x80024274: nop

;}
RECOMP_FUNC void FUN_80024278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024278: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002427C: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80024280: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80024284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002428C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80024290: sb          $t6, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r14;
    // 0x80024294: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024298: lhu         $t8, 0x52($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X52);
    // 0x8002429C: beql        $t8, $zero, L_800242BC
    if (ctx->r24 == 0) {
        // 0x800242A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800242BC;
    }
    goto skip_0;
    // 0x800242A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800242A4: sh          $zero, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = 0;
    // 0x800242A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800242AC: lhu         $t9, 0x52($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X52);
    // 0x800242B0: jal         0x80023D04
    // 0x800242B4: sh          $t9, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_0;
    // 0x800242B4: sh          $t9, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r25;
    after_0:
    // 0x800242B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800242BC:
    // 0x800242BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800242C0: jr          $ra
    // 0x800242C4: nop

    return;
    // 0x800242C4: nop

;}
RECOMP_FUNC void FUN_800242c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800242C8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800242CC: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x800242D0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800242D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800242D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800242DC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800242E0: sb          $t6, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r14;
    // 0x800242E4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800242E8: sh          $zero, 0x4A($t8)
    MEM_H(0X4A, ctx->r24) = 0;
    // 0x800242EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800242F0: lhu         $t9, 0x56($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X56);
    // 0x800242F4: jal         0x80023D04
    // 0x800242F8: sh          $t9, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_0;
    // 0x800242F8: sh          $t9, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r25;
    after_0:
    // 0x800242FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024304: jr          $ra
    // 0x80024308: nop

    return;
    // 0x80024308: nop

;}
RECOMP_FUNC void FUN_8002430c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002430C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80024310: addiu       $v0, $v0, -0x425C
    ctx->r2 = ADD32(ctx->r2, -0X425C);
    // 0x80024314: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80024318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002431C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024320: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80024324: sb          $v1, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r3;
    // 0x80024328: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002432C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80024330: sb          $t7, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r15;
    // 0x80024334: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80024338: sh          $zero, 0x4A($t9)
    MEM_H(0X4A, ctx->r25) = 0;
    // 0x8002433C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80024340: jal         0x80023D04
    // 0x80024344: sh          $v1, 0x4C($t0)
    MEM_H(0X4C, ctx->r8) = ctx->r3;
    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_0;
    // 0x80024344: sh          $v1, 0x4C($t0)
    MEM_H(0X4C, ctx->r8) = ctx->r3;
    after_0:
    // 0x80024348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002434C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024350: jr          $ra
    // 0x80024354: nop

    return;
    // 0x80024354: nop

;}
RECOMP_FUNC void FUN_80024358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024358: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002435C: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80024360: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80024364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002436C: lhu         $t6, 0x4C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4C);
    // 0x80024370: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80024374: sh          $t7, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r15;
    // 0x80024378: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8002437C: lhu         $v1, 0xB6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB6);
    // 0x80024380: beq         $v1, $zero, L_80024394
    if (ctx->r3 == 0) {
        // 0x80024384: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80024394;
    }
    // 0x80024384: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80024388: sh          $t8, 0xB6($v0)
    MEM_H(0XB6, ctx->r2) = ctx->r24;
    // 0x8002438C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80024390: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
L_80024394:
    // 0x80024394: lhu         $t9, 0x4C($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4C);
    // 0x80024398: bnel        $t9, $zero, L_800243DC
    if (ctx->r25 != 0) {
        // 0x8002439C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800243DC;
    }
    goto skip_0;
    // 0x8002439C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800243A0: lbu         $v1, 0x49($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X49);
    // 0x800243A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800243A8: beq         $v1, $zero, L_800243C0
    if (ctx->r3 == 0) {
        // 0x800243AC: nop
    
            goto L_800243C0;
    }
    // 0x800243AC: nop

    // 0x800243B0: beq         $v1, $at, L_800243D0
    if (ctx->r3 == ctx->r1) {
        // 0x800243B4: nop
    
            goto L_800243D0;
    }
    // 0x800243B4: nop

    // 0x800243B8: b           L_800243DC
    // 0x800243BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800243DC;
    // 0x800243BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800243C0:
    // 0x800243C0: jal         0x8002420C
    // 0x800243C4: nop

    LOOKUP_FUNC(0x8002420C)(rdram, ctx);
        goto after_0;
    // 0x800243C4: nop

    after_0:
    // 0x800243C8: b           L_800243DC
    // 0x800243CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800243DC;
    // 0x800243CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800243D0:
    // 0x800243D0: jal         0x80024278
    // 0x800243D4: nop

    LOOKUP_FUNC(0x80024278)(rdram, ctx);
        goto after_1;
    // 0x800243D4: nop

    after_1:
    // 0x800243D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800243DC:
    // 0x800243DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800243E0: jr          $ra
    // 0x800243E4: nop

    return;
    // 0x800243E4: nop

    // 0x800243E8: nop

    // 0x800243EC: nop

;}
RECOMP_FUNC void FUN_800243f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800243F0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800243F4: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x800243F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800243FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80024400: addiu       $v0, $v0, -0x425C
    ctx->r2 = ADD32(ctx->r2, -0X425C);
    // 0x80024404: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80024408: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002440C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80024410: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x80024414: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80024418: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8002441C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80024420: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80024424: jr          $ra
    // 0x80024428: sb          $zero, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = 0;
    return;
    // 0x80024428: sb          $zero, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002442c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002442c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002442C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024430: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80024434: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80024438: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002443C: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80024440: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80024444: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80024448: sb          $t7, 0x1D($t8)
    MEM_B(0X1D, ctx->r24) = ctx->r15;
    // 0x8002444C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80024450: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80024454: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80024458: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8002445C: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x80024460: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x80024464: sb          $t2, 0x1C($t3)
    MEM_B(0X1C, ctx->r11) = ctx->r10;
    // 0x80024468: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8002446C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80024470: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80024474: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80024478: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x8002447C: lhu         $t9, 0x18($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X18);
    // 0x80024480: lbu         $t0, 0x1D($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1D);
    // 0x80024484: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80024488: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002448C: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x80024490: div         $zero, $v1, $t0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r8)));
    // 0x80024494: mflo        $t1
    ctx->r9 = lo;
    // 0x80024498: sh          $t1, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r9;
    // 0x8002449C: bne         $t0, $zero, L_800244A8
    if (ctx->r8 != 0) {
        // 0x800244A0: nop
    
            goto L_800244A8;
    }
    // 0x800244A0: nop

    // 0x800244A4: break       7
    do_break(2147632292);
L_800244A8:
    // 0x800244A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800244AC: bne         $t0, $at, L_800244C0
    if (ctx->r8 != ctx->r1) {
        // 0x800244B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800244C0;
    }
    // 0x800244B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800244B4: bne         $v1, $at, L_800244C0
    if (ctx->r3 != ctx->r1) {
        // 0x800244B8: nop
    
            goto L_800244C0;
    }
    // 0x800244B8: nop

    // 0x800244BC: break       6
    do_break(2147632316);
L_800244C0:
    // 0x800244C0: jr          $ra
    // 0x800244C4: nop

    return;
    // 0x800244C4: nop

;}
RECOMP_FUNC void FUN_800244c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800244C8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800244CC: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x800244D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800244D4: lbu         $t6, 0x1D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1D);
    // 0x800244D8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800244DC: sb          $t7, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r15;
    // 0x800244E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800244E4: lbu         $t8, 0x1D($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1D);
    // 0x800244E8: beql        $t8, $zero, L_80024530
    if (ctx->r24 == 0) {
        // 0x800244EC: lbu         $t0, 0x1C($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X1C);
            goto L_80024530;
    }
    goto skip_0;
    // 0x800244EC: lbu         $t0, 0x1C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1C);
    skip_0:
    // 0x800244F0: lhu         $v1, 0x18($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X18);
    // 0x800244F4: lh          $t9, 0x1E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1E);
    // 0x800244F8: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x800244FC: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80024500: beql        $at, $zero, L_80024514
    if (ctx->r1 == 0) {
        // 0x80024504: ori         $at, $zero, 0xFF01
        ctx->r1 = 0 | 0XFF01;
            goto L_80024514;
    }
    goto skip_1;
    // 0x80024504: ori         $at, $zero, 0xFF01
    ctx->r1 = 0 | 0XFF01;
    skip_1:
    // 0x80024508: b           L_80024524
    // 0x8002450C: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
        goto L_80024524;
    // 0x8002450C: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x80024510: ori         $at, $zero, 0xFF01
    ctx->r1 = 0 | 0XFF01;
L_80024514:
    // 0x80024514: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80024518: bne         $at, $zero, L_80024524
    if (ctx->r1 != 0) {
        // 0x8002451C: nop
    
            goto L_80024524;
    }
    // 0x8002451C: nop

    // 0x80024520: ori         $v1, $zero, 0xFF00
    ctx->r3 = 0 | 0XFF00;
L_80024524:
    // 0x80024524: jr          $ra
    // 0x80024528: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    return;
    // 0x80024528: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    // 0x8002452C: lbu         $t0, 0x1C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1C);
L_80024530:
    // 0x80024530: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80024534: sh          $t1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r9;
    // 0x80024538: jr          $ra
    // 0x8002453C: nop

    return;
    // 0x8002453C: nop

;}
RECOMP_FUNC void FUN_80024540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024540: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024544: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80024548: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8002454C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024554: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024558: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x8002455C: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80024560: beq         $v0, $zero, L_800245A0
    if (ctx->r2 == 0) {
        // 0x80024564: srl         $v0, $v0, 8
        ctx->r2 = S32(U32(ctx->r2) >> 8);
            goto L_800245A0;
    }
    // 0x80024564: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x80024568: sltiu       $at, $v0, 0xA00
    ctx->r1 = ctx->r2 < 0XA00 ? 1 : 0;
    // 0x8002456C: beql        $at, $zero, L_80024580
    if (ctx->r1 == 0) {
        // 0x80024570: sltiu       $at, $v0, 0x7501
        ctx->r1 = ctx->r2 < 0X7501 ? 1 : 0;
            goto L_80024580;
    }
    goto skip_0;
    // 0x80024570: sltiu       $at, $v0, 0x7501
    ctx->r1 = ctx->r2 < 0X7501 ? 1 : 0;
    skip_0:
    // 0x80024574: b           L_8002458C
    // 0x80024578: addiu       $v0, $zero, 0xA00
    ctx->r2 = ADD32(0, 0XA00);
        goto L_8002458C;
    // 0x80024578: addiu       $v0, $zero, 0xA00
    ctx->r2 = ADD32(0, 0XA00);
    // 0x8002457C: sltiu       $at, $v0, 0x7501
    ctx->r1 = ctx->r2 < 0X7501 ? 1 : 0;
L_80024580:
    // 0x80024580: bnel        $at, $zero, L_80024590
    if (ctx->r1 != 0) {
        // 0x80024584: sb          $zero, 0x5B($v1)
        MEM_B(0X5B, ctx->r3) = 0;
            goto L_80024590;
    }
    goto skip_1;
    // 0x80024584: sb          $zero, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = 0;
    skip_1:
    // 0x80024588: addiu       $v0, $zero, 0x7500
    ctx->r2 = ADD32(0, 0X7500);
L_8002458C:
    // 0x8002458C: sb          $zero, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = 0;
L_80024590:
    // 0x80024590: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80024594: ori         $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 | 0X8000;
    // 0x80024598: sh          $t6, 0x58($t7)
    MEM_H(0X58, ctx->r15) = ctx->r14;
    // 0x8002459C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_800245A0:
    // 0x800245A0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800245A4: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x800245A8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800245AC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800245B0: sb          $t9, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r25;
    // 0x800245B4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800245B8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800245BC: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800245C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800245C4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800245C8: lbu         $a1, 0xC($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XC);
    // 0x800245CC: addiu       $a0, $a0, -0x776C
    ctx->r4 = ADD32(ctx->r4, -0X776C);
    // 0x800245D0: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800245D4: beq         $at, $zero, L_800245FC
    if (ctx->r1 == 0) {
        // 0x800245D8: sll         $t2, $a1, 2
        ctx->r10 = S32(ctx->r5 << 2);
            goto L_800245FC;
    }
    // 0x800245D8: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x800245DC: lbu         $t3, 0xD($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XD);
    // 0x800245E0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800245E4: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x800245E8: lw          $a0, -0x7D60($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D60);
    // 0x800245EC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800245F0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800245F4: b           L_800245FC
    // 0x800245F8: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
        goto L_800245FC;
    // 0x800245F8: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
L_800245FC:
    // 0x800245FC: jal         0x80024614
    // 0x80024600: nop

    LOOKUP_FUNC(0x80024614)(rdram, ctx);
        goto after_0;
    // 0x80024600: nop

    after_0:
    // 0x80024604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002460C: jr          $ra
    // 0x80024610: nop

    return;
    // 0x80024610: nop

;}
RECOMP_FUNC void FUN_80024614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024614: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80024618: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x8002461C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024628: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x8002462C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80024630: lbu         $t9, 0xD($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XD);
    // 0x80024634: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80024638: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002463C: lw          $t8, 0x6A98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A98);
    // 0x80024640: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80024644: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80024648: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8002464C: addiu       $t2, $t2, -0x7E02
    ctx->r10 = ADD32(ctx->r10, -0X7E02);
    // 0x80024650: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    // 0x80024654: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80024658: lw          $t0, 0xC($t4)
    ctx->r8 = MEM_W(ctx->r12, 0XC);
    // 0x8002465C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80024660: lw          $t5, 0x8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X8);
    // 0x80024664: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x80024668: lb          $t6, -0x5($a0)
    ctx->r14 = MEM_B(ctx->r4, -0X5);
    // 0x8002466C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80024670: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80024674: sh          $t7, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = ctx->r15;
    // 0x80024678: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002467C: lb          $t3, -0x4($a0)
    ctx->r11 = MEM_B(ctx->r4, -0X4);
    // 0x80024680: lh          $t9, 0x2C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2C);
    // 0x80024684: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80024688: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8002468C: sh          $t5, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r13;
    // 0x80024690: lb          $t6, -0x3($a0)
    ctx->r14 = MEM_B(ctx->r4, -0X3);
    // 0x80024694: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80024698: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002469C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800246A0: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x800246A4: lhu         $t9, 0x0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X0);
    // 0x800246A8: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x800246AC: sh          $t9, 0x4E($t4)
    MEM_H(0X4E, ctx->r12) = ctx->r25;
    // 0x800246B0: lbu         $a1, -0x2($a0)
    ctx->r5 = MEM_BU(ctx->r4, -0X2);
    // 0x800246B4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800246B8: andi        $t5, $a1, 0xF0
    ctx->r13 = ctx->r5 & 0XF0;
    // 0x800246BC: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800246C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800246C4: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800246C8: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x800246CC: lhu         $t3, -0x7E86($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X7E86);
    // 0x800246D0: andi        $t4, $a1, 0xF
    ctx->r12 = ctx->r5 & 0XF;
    // 0x800246D4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800246D8: sh          $t3, 0x50($t9)
    MEM_H(0X50, ctx->r25) = ctx->r11;
    // 0x800246DC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800246E0: sh          $t5, 0x54($t6)
    MEM_H(0X54, ctx->r14) = ctx->r13;
    // 0x800246E4: lbu         $a2, -0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, -0X1);
    // 0x800246E8: bne         $a2, $zero, L_800246FC
    if (ctx->r6 != 0) {
        // 0x800246EC: sll         $t8, $a2, 1
        ctx->r24 = S32(ctx->r6 << 1);
            goto L_800246FC;
    }
    // 0x800246EC: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800246F0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800246F4: b           L_80024714
    // 0x800246F8: sh          $zero, 0x52($t7)
    MEM_H(0X52, ctx->r15) = 0;
        goto L_80024714;
    // 0x800246F8: sh          $zero, 0x52($t7)
    MEM_H(0X52, ctx->r15) = 0;
L_800246FC:
    // 0x800246FC: negu        $t3, $t8
    ctx->r11 = SUB32(0, ctx->r24);
    // 0x80024700: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x80024704: lhu         $t4, 0x0($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X0);
    // 0x80024708: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002470C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80024710: sh          $t5, 0x52($t6)
    MEM_H(0X52, ctx->r14) = ctx->r13;
L_80024714:
    // 0x80024714: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x80024718: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x8002471C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80024720: sll         $t3, $t8, 3
    ctx->r11 = S32(ctx->r24 << 3);
    // 0x80024724: negu        $t9, $t3
    ctx->r25 = SUB32(0, ctx->r11);
    // 0x80024728: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x8002472C: lhu         $t4, -0x7E06($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X7E06);
    // 0x80024730: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80024734: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024738: sh          $t4, 0x56($t5)
    MEM_H(0X56, ctx->r13) = ctx->r12;
    // 0x8002473C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024740: lhu         $t6, 0x58($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X58);
    // 0x80024744: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80024748: beq         $at, $zero, L_80024764
    if (ctx->r1 == 0) {
        // 0x8002474C: nop
    
            goto L_80024764;
    }
    // 0x8002474C: nop

    // 0x80024750: lb          $t7, 0x0($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X0);
    // 0x80024754: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80024758: sh          $t8, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r24;
    // 0x8002475C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80024760: sb          $zero, 0x5B($t3)
    MEM_B(0X5B, ctx->r11) = 0;
L_80024764:
    // 0x80024764: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024768: jal         0x80022A84
    // 0x8002476C: lbu         $a0, -0x454C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454C);
    LOOKUP_FUNC(0x80022A84)(rdram, ctx);
        goto after_0;
    // 0x8002476C: lbu         $a0, -0x454C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454C);
    after_0:
    // 0x80024770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024778: jr          $ra
    // 0x8002477C: nop

    return;
    // 0x8002477C: nop

;}
RECOMP_FUNC void FUN_80024780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024780: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80024784: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80024788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002478C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024790: lbu         $t6, 0x25($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X25);
    // 0x80024794: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80024798: addiu       $t9, $t9, -0x7764
    ctx->r25 = ADD32(ctx->r25, -0X7764);
    // 0x8002479C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800247A0: addiu       $t8, $t7, -0x240
    ctx->r24 = ADD32(ctx->r15, -0X240);
    // 0x800247A4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800247A8: lb          $t0, 0x0($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X0);
    // 0x800247AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800247B0: jal         0x80024614
    // 0x800247B4: sb          $t0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r8;
    LOOKUP_FUNC(0x80024614)(rdram, ctx);
        goto after_0;
    // 0x800247B4: sb          $t0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r8;
    after_0:
    // 0x800247B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800247BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800247C0: jr          $ra
    // 0x800247C4: nop

    return;
    // 0x800247C4: nop

;}
RECOMP_FUNC void FUN_800247c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800247C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800247CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800247D0: jal         0x80024820
    // 0x800247D4: nop

    LOOKUP_FUNC(0x80024820)(rdram, ctx);
        goto after_0;
    // 0x800247D4: nop

    after_0:
    // 0x800247D8: jal         0x80024540
    // 0x800247DC: nop

    LOOKUP_FUNC(0x80024540)(rdram, ctx);
        goto after_1;
    // 0x800247DC: nop

    after_1:
    // 0x800247E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800247E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800247E8: jr          $ra
    // 0x800247EC: nop

    return;
    // 0x800247EC: nop

;}
RECOMP_FUNC void FUN_800247f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800247F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800247F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800247F8: jal         0x80024820
    // 0x800247FC: nop

    LOOKUP_FUNC(0x80024820)(rdram, ctx);
        goto after_0;
    // 0x800247FC: nop

    after_0:
    // 0x80024800: jal         0x80024540
    // 0x80024804: nop

    LOOKUP_FUNC(0x80024540)(rdram, ctx);
        goto after_1;
    // 0x80024804: nop

    after_1:
    // 0x80024808: jal         0x80024CF8
    // 0x8002480C: nop

    LOOKUP_FUNC(0x80024CF8)(rdram, ctx);
        goto after_2;
    // 0x8002480C: nop

    after_2:
    // 0x80024810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024818: jr          $ra
    // 0x8002481C: nop

    return;
    // 0x8002481C: nop

;}
RECOMP_FUNC void FUN_80024820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024820: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80024824: addiu       $a2, $a2, -0x4260
    ctx->r6 = ADD32(ctx->r6, -0X4260);
    // 0x80024828: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8002482C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80024830: addiu       $a3, $a3, -0x425C
    ctx->r7 = ADD32(ctx->r7, -0X425C);
    // 0x80024834: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80024838: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8002483C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80024840: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80024844: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80024848: sll         $t0, $v0, 8
    ctx->r8 = S32(ctx->r2 << 8);
    // 0x8002484C: srl         $t7, $a1, 24
    ctx->r15 = S32(U32(ctx->r5) >> 24);
    // 0x80024850: beq         $t7, $zero, L_8002486C
    if (ctx->r15 == 0) {
        // 0x80024854: srl         $t8, $a1, 24
        ctx->r24 = S32(U32(ctx->r5) >> 24);
            goto L_8002486C;
    }
    // 0x80024854: srl         $t8, $a1, 24
    ctx->r24 = S32(U32(ctx->r5) >> 24);
    // 0x80024858: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002485C: mflo        $t9
    ctx->r25 = lo;
    // 0x80024860: sh          $t9, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r25;
    // 0x80024864: b           L_80024874
    // 0x80024868: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
        goto L_80024874;
    // 0x80024868: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
L_8002486C:
    // 0x8002486C: sh          $t0, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r8;
    // 0x80024870: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
L_80024874:
    // 0x80024874: jr          $ra
    // 0x80024878: sb          $zero, 0x47($t1)
    MEM_B(0X47, ctx->r9) = 0;
    return;
    // 0x80024878: sb          $zero, 0x47($t1)
    MEM_B(0X47, ctx->r9) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002487c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002487c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002487C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024880: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80024884: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80024888: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002488C: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80024890: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80024894: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80024898: sb          $t7, 0x47($t8)
    MEM_B(0X47, ctx->r24) = ctx->r15;
    // 0x8002489C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800248A0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800248A4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800248A8: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800248AC: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800248B0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800248B4: sb          $t2, 0x46($t3)
    MEM_B(0X46, ctx->r11) = ctx->r10;
    // 0x800248B8: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800248BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800248C0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800248C4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800248C8: lbu         $t6, 0x46($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X46);
    // 0x800248CC: lhu         $t9, 0x3A($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X3A);
    // 0x800248D0: lbu         $t0, 0x47($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X47);
    // 0x800248D4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800248D8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800248DC: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x800248E0: div         $zero, $v1, $t0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r8)));
    // 0x800248E4: mflo        $t1
    ctx->r9 = lo;
    // 0x800248E8: sh          $t1, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r9;
    // 0x800248EC: bne         $t0, $zero, L_800248F8
    if (ctx->r8 != 0) {
        // 0x800248F0: nop
    
            goto L_800248F8;
    }
    // 0x800248F0: nop

    // 0x800248F4: break       7
    do_break(2147633396);
L_800248F8:
    // 0x800248F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800248FC: bne         $t0, $at, L_80024910
    if (ctx->r8 != ctx->r1) {
        // 0x80024900: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024910;
    }
    // 0x80024900: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024904: bne         $v1, $at, L_80024910
    if (ctx->r3 != ctx->r1) {
        // 0x80024908: nop
    
            goto L_80024910;
    }
    // 0x80024908: nop

    // 0x8002490C: break       6
    do_break(2147633420);
L_80024910:
    // 0x80024910: jr          $ra
    // 0x80024914: nop

    return;
    // 0x80024914: nop

;}
RECOMP_FUNC void FUN_80024918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024918: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002491C: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80024920: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024924: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x80024928: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8002492C: sb          $t7, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r15;
    // 0x80024930: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024934: lbu         $t8, 0x47($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X47);
    // 0x80024938: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002493C: sb          $t9, 0x47($v0)
    MEM_B(0X47, ctx->r2) = ctx->r25;
    // 0x80024940: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024944: lbu         $t0, 0x47($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X47);
    // 0x80024948: beql        $t0, $zero, L_80024988
    if (ctx->r8 == 0) {
        // 0x8002494C: lbu         $t2, 0x46($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X46);
            goto L_80024988;
    }
    goto skip_0;
    // 0x8002494C: lbu         $t2, 0x46($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X46);
    skip_0:
    // 0x80024950: lhu         $v1, 0x3A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X3A);
    // 0x80024954: lh          $t1, 0x44($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X44);
    // 0x80024958: ori         $at, $zero, 0xFF01
    ctx->r1 = 0 | 0XFF01;
    // 0x8002495C: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80024960: bgez        $v1, L_80024970
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80024964: slt         $at, $v1, $at
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
            goto L_80024970;
    }
    // 0x80024964: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80024968: b           L_8002497C
    // 0x8002496C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8002497C;
    // 0x8002496C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80024970:
    // 0x80024970: bne         $at, $zero, L_8002497C
    if (ctx->r1 != 0) {
        // 0x80024974: nop
    
            goto L_8002497C;
    }
    // 0x80024974: nop

    // 0x80024978: ori         $v1, $zero, 0xFF00
    ctx->r3 = 0 | 0XFF00;
L_8002497C:
    // 0x8002497C: jr          $ra
    // 0x80024980: sh          $v1, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r3;
    return;
    // 0x80024980: sh          $v1, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r3;
    // 0x80024984: lbu         $t2, 0x46($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X46);
L_80024988:
    // 0x80024988: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8002498C: sh          $t3, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r11;
    // 0x80024990: jr          $ra
    // 0x80024994: nop

    return;
    // 0x80024994: nop

;}
RECOMP_FUNC void FUN_80024998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024998: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8002499C: addiu       $a2, $a2, -0x4260
    ctx->r6 = ADD32(ctx->r6, -0X4260);
    // 0x800249A0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800249A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800249A8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800249AC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800249B0: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x800249B4: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800249B8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800249BC: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x800249C0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800249C4: lhu         $t0, -0x7E02($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X7E02);
    // 0x800249C8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x800249CC: sh          $t0, 0x4E($t1)
    MEM_H(0X4E, ctx->r9) = ctx->r8;
    // 0x800249D0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x800249D4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800249D8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800249DC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800249E0: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800249E4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800249E8: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800249EC: andi        $t5, $v1, 0xF0
    ctx->r13 = ctx->r3 & 0XF0;
    // 0x800249F0: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800249F4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800249F8: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800249FC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80024A00: lhu         $t9, -0x7E86($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X7E86);
    // 0x80024A04: andi        $t1, $v1, 0xF
    ctx->r9 = ctx->r3 & 0XF;
    // 0x80024A08: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80024A0C: sh          $t9, 0x50($t0)
    MEM_H(0X50, ctx->r8) = ctx->r25;
    // 0x80024A10: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80024A14: jr          $ra
    // 0x80024A18: sh          $t2, 0x54($t3)
    MEM_H(0X54, ctx->r11) = ctx->r10;
    return;
    // 0x80024A18: sh          $t2, 0x54($t3)
    MEM_H(0X54, ctx->r11) = ctx->r10;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80024a1c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80024a1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A1C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024A20: addiu       $a0, $a0, -0x4260
    ctx->r4 = ADD32(ctx->r4, -0X4260);
    // 0x80024A24: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80024A28: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024A2C: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x80024A30: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80024A34: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80024A38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80024A3C: bne         $v0, $zero, L_80024A80
    if (ctx->r2 != 0) {
        // 0x80024A40: sll         $t1, $v0, 1
        ctx->r9 = S32(ctx->r2 << 1);
            goto L_80024A80;
    }
    // 0x80024A40: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x80024A44: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024A48: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x80024A4C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80024A50: sh          $zero, 0x52($t7)
    MEM_H(0X52, ctx->r15) = 0;
    // 0x80024A54: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80024A58: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
    // 0x80024A5C: bne         $t8, $zero, L_80024AD4
    if (ctx->r24 != 0) {
        // 0x80024A60: nop
    
            goto L_80024AD4;
    }
    // 0x80024A60: nop

    // 0x80024A64: lbu         $t9, 0x49($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X49);
    // 0x80024A68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80024A6C: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
    // 0x80024A70: bne         $t9, $at, L_80024AD4
    if (ctx->r25 != ctx->r1) {
        // 0x80024A74: nop
    
            goto L_80024AD4;
    }
    // 0x80024A74: nop

    // 0x80024A78: jr          $ra
    // 0x80024A7C: sh          $t0, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r8;
    return;
    // 0x80024A7C: sh          $t0, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r8;
L_80024A80:
    // 0x80024A80: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80024A84: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x80024A88: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80024A8C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80024A90: lhu         $t3, -0x7E02($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X7E02);
    // 0x80024A94: lhu         $a0, 0x52($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X52);
    // 0x80024A98: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80024A9C: sh          $t4, 0x52($v1)
    MEM_H(0X52, ctx->r3) = ctx->r12;
    // 0x80024AA0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80024AA4: lbu         $t5, 0x22($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X22);
    // 0x80024AA8: bne         $t5, $zero, L_80024AD4
    if (ctx->r13 != 0) {
        // 0x80024AAC: nop
    
            goto L_80024AD4;
    }
    // 0x80024AAC: nop

    // 0x80024AB0: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    // 0x80024AB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80024AB8: bne         $t6, $at, L_80024AD4
    if (ctx->r14 != ctx->r1) {
        // 0x80024ABC: nop
    
            goto L_80024AD4;
    }
    // 0x80024ABC: nop

    // 0x80024AC0: lhu         $t7, 0x52($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X52);
    // 0x80024AC4: bne         $a0, $zero, L_80024AD4
    if (ctx->r4 != 0) {
        // 0x80024AC8: sh          $t7, 0x4C($v1)
        MEM_H(0X4C, ctx->r3) = ctx->r15;
            goto L_80024AD4;
    }
    // 0x80024AC8: sh          $t7, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r15;
    // 0x80024ACC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80024AD0: sh          $zero, 0x4A($t8)
    MEM_H(0X4A, ctx->r24) = 0;
L_80024AD4:
    // 0x80024AD4: jr          $ra
    // 0x80024AD8: nop

    return;
    // 0x80024AD8: nop

;}
RECOMP_FUNC void FUN_80024adc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024ADC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024AE0: addiu       $a0, $a0, -0x4260
    ctx->r4 = ADD32(ctx->r4, -0X4260);
    // 0x80024AE4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80024AE8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80024AEC: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80024AF0: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80024AF4: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80024AF8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80024AFC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80024B00: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x80024B04: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80024B08: lhu         $t1, -0x7E06($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X7E06);
    // 0x80024B0C: sh          $t1, 0x56($t2)
    MEM_H(0X56, ctx->r10) = ctx->r9;
    // 0x80024B10: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80024B14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024B18: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80024B1C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80024B20: lbu         $t5, 0x22($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X22);
    // 0x80024B24: bne         $t5, $zero, L_80024B44
    if (ctx->r13 != 0) {
        // 0x80024B28: nop
    
            goto L_80024B44;
    }
    // 0x80024B28: nop

    // 0x80024B2C: lbu         $t6, 0x49($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49);
    // 0x80024B30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024B34: bne         $t6, $at, L_80024B44
    if (ctx->r14 != ctx->r1) {
        // 0x80024B38: nop
    
            goto L_80024B44;
    }
    // 0x80024B38: nop

    // 0x80024B3C: lhu         $t7, 0x56($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X56);
    // 0x80024B40: sh          $t7, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r15;
L_80024B44:
    // 0x80024B44: jr          $ra
    // 0x80024B48: nop

    return;
    // 0x80024B48: nop

;}
RECOMP_FUNC void FUN_80024b4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024B4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80024B50: lw          $t6, -0x425C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X425C);
    // 0x80024B54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024B5C: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x80024B60: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80024B64: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80024B68: beq         $t7, $zero, L_80024B94
    if (ctx->r15 == 0) {
        // 0x80024B6C: lui         $t1, 0x800D
        ctx->r9 = S32(0X800D << 16);
            goto L_80024B94;
    }
    // 0x80024B6C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80024B70: lbu         $t8, -0x454C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X454C);
    // 0x80024B74: addiu       $t1, $t1, -0x4420
    ctx->r9 = ADD32(ctx->r9, -0X4420);
    // 0x80024B78: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80024B7C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80024B80: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80024B84: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80024B88: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x80024B8C: jal         0x80030770
    // 0x80024B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80030770)(rdram, ctx);
        goto after_0;
    // 0x80024B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_80024B94:
    // 0x80024B94: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80024B98: addiu       $t0, $t0, -0x4260
    ctx->r8 = ADD32(ctx->r8, -0X4260);
    // 0x80024B9C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80024BA0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80024BA4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024BA8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80024BAC: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80024BB0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80024BB4: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80024BB8: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x80024BBC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80024BC0: bne         $t3, $zero, L_80024BD4
    if (ctx->r11 != 0) {
        // 0x80024BC4: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_80024BD4;
    }
    // 0x80024BC4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80024BC8: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80024BCC: lw          $t5, 0x79CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X79CC);
    // 0x80024BD0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_80024BD4:
    // 0x80024BD4: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80024BD8: lw          $a1, -0x41F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X41F8);
    // 0x80024BDC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80024BE0: jal         0x80028EE0
    // 0x80024BE4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80028EE0)(rdram, ctx);
        goto after_1;
    // 0x80024BE4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80024BE8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80024BEC: addiu       $t0, $t0, -0x4260
    ctx->r8 = ADD32(ctx->r8, -0X4260);
    // 0x80024BF0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80024BF4: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80024BF8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024BFC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80024C00: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80024C04: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80024C08: sll         $t7, $v1, 7
    ctx->r15 = S32(ctx->r3 << 7);
    // 0x80024C0C: bne         $t7, $zero, L_80024C20
    if (ctx->r15 != 0) {
        // 0x80024C10: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80024C20;
    }
    // 0x80024C10: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80024C14: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80024C18: lw          $t9, 0x79D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79D0);
    // 0x80024C1C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_80024C20:
    // 0x80024C20: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80024C24: lw          $a1, -0x41F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X41F8);
    // 0x80024C28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80024C2C: jal         0x80028EE0
    // 0x80024C30: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80028EE0)(rdram, ctx);
        goto after_2;
    // 0x80024C30: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80024C34: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80024C38: lw          $t1, -0x425C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X425C);
    // 0x80024C3C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80024C40: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80024C44: lbu         $a2, 0x10($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X10);
    // 0x80024C48: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80024C4C: beql        $a2, $zero, L_80024C78
    if (ctx->r6 == 0) {
        // 0x80024C50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80024C78;
    }
    goto skip_0;
    // 0x80024C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80024C54: lbu         $t2, -0x454C($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X454C);
    // 0x80024C58: addiu       $t4, $t4, -0x4420
    ctx->r12 = ADD32(ctx->r12, -0X4420);
    // 0x80024C5C: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80024C60: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80024C64: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80024C68: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80024C6C: jal         0x80030770
    // 0x80024C70: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    LOOKUP_FUNC(0x80030770)(rdram, ctx);
        goto after_3;
    // 0x80024C70: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80024C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024C78:
    // 0x80024C78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80024C7C: jr          $ra
    // 0x80024C80: nop

    return;
    // 0x80024C80: nop

;}
RECOMP_FUNC void FUN_80024c84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024C84: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024C88: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80024C8C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80024C90: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80024C94: addiu       $t8, $t8, -0x4258
    ctx->r24 = ADD32(ctx->r24, -0X4258);
    // 0x80024C98: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80024C9C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80024CA0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80024CA4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80024CA8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80024CAC: beq         $v0, $zero, L_80024CF0
    if (ctx->r2 == 0) {
        // 0x80024CB0: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_80024CF0;
    }
    // 0x80024CB0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80024CB4: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x80024CB8: lbu         $a2, -0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, -0X1);
    // 0x80024CBC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80024CC0: beq         $a2, $zero, L_80024CF0
    if (ctx->r6 == 0) {
        // 0x80024CC4: nop
    
            goto L_80024CF0;
    }
    // 0x80024CC4: nop

    // 0x80024CC8: beq         $a0, $zero, L_80024CE4
    if (ctx->r4 == 0) {
        // 0x80024CCC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80024CE4;
    }
    // 0x80024CCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80024CD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80024CD4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80024CD8: addiu       $t9, $v0, 0xF0
    ctx->r25 = ADD32(ctx->r2, 0XF0);
    // 0x80024CDC: jr          $ra
    // 0x80024CE0: sb          $t9, -0x4251($at)
    MEM_B(-0X4251, ctx->r1) = ctx->r25;
    return;
    // 0x80024CE0: sb          $t9, -0x4251($at)
    MEM_B(-0X4251, ctx->r1) = ctx->r25;
L_80024CE4:
    // 0x80024CE4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80024CE8: sb          $a2, -0x4251($at)
    MEM_B(-0X4251, ctx->r1) = ctx->r6;
    // 0x80024CEC: sb          $zero, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = 0;
L_80024CF0:
    // 0x80024CF0: jr          $ra
    // 0x80024CF4: nop

    return;
    // 0x80024CF4: nop

;}
RECOMP_FUNC void FUN_80024cf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024CF8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024CFC: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x80024D00: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80024D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024D0C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80024D10: addiu       $a2, $a2, -0x4260
    ctx->r6 = ADD32(ctx->r6, -0X4260);
    // 0x80024D14: sb          $zero, 0x5B($t6)
    MEM_B(0X5B, ctx->r14) = 0;
    // 0x80024D18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80024D1C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80024D20: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024D24: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80024D28: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80024D2C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80024D30: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x80024D34: sh          $t8, 0x58($t9)
    MEM_H(0X58, ctx->r25) = ctx->r24;
    // 0x80024D38: jal         0x80022A84
    // 0x80024D3C: lbu         $a0, -0x454C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454C);
    LOOKUP_FUNC(0x80022A84)(rdram, ctx);
        goto after_0;
    // 0x80024D3C: lbu         $a0, -0x454C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454C);
    after_0:
    // 0x80024D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024D48: jr          $ra
    // 0x80024D4C: nop

    return;
    // 0x80024D4C: nop

;}
RECOMP_FUNC void FUN_80024d50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024D50: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024D54: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80024D58: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80024D5C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024D60: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80024D64: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80024D68: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80024D6C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80024D70: sb          $t7, 0x5B($t8)
    MEM_B(0X5B, ctx->r24) = ctx->r15;
    // 0x80024D74: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80024D78: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80024D7C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80024D80: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80024D84: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x80024D88: sb          $t2, 0x5A($t3)
    MEM_B(0X5A, ctx->r11) = ctx->r10;
    // 0x80024D8C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80024D90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80024D94: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80024D98: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80024D9C: lhu         $v1, 0x58($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X58);
    // 0x80024DA0: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80024DA4: beql        $at, $zero, L_80024DC0
    if (ctx->r1 == 0) {
        // 0x80024DA8: lbu         $t8, 0x5A($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X5A);
            goto L_80024DC0;
    }
    goto skip_0;
    // 0x80024DA8: lbu         $t8, 0x5A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5A);
    skip_0:
    // 0x80024DAC: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x80024DB0: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x80024DB4: bne         $t7, $zero, L_80024E04
    if (ctx->r15 != 0) {
        // 0x80024DB8: nop
    
            goto L_80024E04;
    }
    // 0x80024DB8: nop

    // 0x80024DBC: lbu         $t8, 0x5A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5A);
L_80024DC0:
    // 0x80024DC0: andi        $t1, $v1, 0x7FFF
    ctx->r9 = ctx->r3 & 0X7FFF;
    // 0x80024DC4: lbu         $t2, 0x5B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5B);
    // 0x80024DC8: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80024DCC: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80024DD0: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    // 0x80024DD4: div         $zero, $a0, $t2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r10)));
    // 0x80024DD8: mflo        $t3
    ctx->r11 = lo;
    // 0x80024DDC: sh          $t3, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r11;
    // 0x80024DE0: bne         $t2, $zero, L_80024DEC
    if (ctx->r10 != 0) {
        // 0x80024DE4: nop
    
            goto L_80024DEC;
    }
    // 0x80024DE4: nop

    // 0x80024DE8: break       7
    do_break(2147634664);
L_80024DEC:
    // 0x80024DEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024DF0: bne         $t2, $at, L_80024E04
    if (ctx->r10 != ctx->r1) {
        // 0x80024DF4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024E04;
    }
    // 0x80024DF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024DF8: bne         $a0, $at, L_80024E04
    if (ctx->r4 != ctx->r1) {
        // 0x80024DFC: nop
    
            goto L_80024E04;
    }
    // 0x80024DFC: nop

    // 0x80024E00: break       6
    do_break(2147634688);
L_80024E04:
    // 0x80024E04: jr          $ra
    // 0x80024E08: nop

    return;
    // 0x80024E08: nop

;}
RECOMP_FUNC void FUN_80024e0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024E0C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80024E10: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x80024E14: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80024E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024E20: lbu         $t6, 0x5B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5B);
    // 0x80024E24: lhu         $a1, 0x58($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X58);
    // 0x80024E28: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80024E2C: sb          $t7, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r15;
    // 0x80024E30: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80024E34: andi        $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 & 0X8000;
    // 0x80024E38: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80024E3C: lbu         $t8, 0x5B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5B);
    // 0x80024E40: beql        $t8, $zero, L_80024E84
    if (ctx->r24 == 0) {
        // 0x80024E44: lbu         $t0, 0x5A($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X5A);
            goto L_80024E84;
    }
    goto skip_0;
    // 0x80024E44: lbu         $t0, 0x5A($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5A);
    skip_0:
    // 0x80024E48: lhu         $v1, 0x58($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X58);
    // 0x80024E4C: lh          $t9, 0x5C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X5C);
    // 0x80024E50: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80024E54: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x80024E58: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80024E5C: bgez        $v1, L_80024E6C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80024E60: slt         $at, $v1, $at
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
            goto L_80024E6C;
    }
    // 0x80024E60: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80024E64: b           L_80024E78
    // 0x80024E68: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80024E78;
    // 0x80024E68: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80024E6C:
    // 0x80024E6C: bne         $at, $zero, L_80024E78
    if (ctx->r1 != 0) {
        // 0x80024E70: nop
    
            goto L_80024E78;
    }
    // 0x80024E70: nop

    // 0x80024E74: addiu       $v1, $zero, 0x7F00
    ctx->r3 = ADD32(0, 0X7F00);
L_80024E78:
    // 0x80024E78: b           L_80024E8C
    // 0x80024E7C: sh          $v1, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r3;
        goto L_80024E8C;
    // 0x80024E7C: sh          $v1, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r3;
    // 0x80024E80: lbu         $t0, 0x5A($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5A);
L_80024E84:
    // 0x80024E84: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80024E88: sh          $t1, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r9;
L_80024E8C:
    // 0x80024E8C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80024E90: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024E94: lhu         $t2, 0x58($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X58);
    // 0x80024E98: or          $t3, $t2, $a1
    ctx->r11 = ctx->r10 | ctx->r5;
    // 0x80024E9C: sh          $t3, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r11;
    // 0x80024EA0: jal         0x80022A84
    // 0x80024EA4: lbu         $a0, -0x454C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454C);
    LOOKUP_FUNC(0x80022A84)(rdram, ctx);
        goto after_0;
    // 0x80024EA4: lbu         $a0, -0x454C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454C);
    after_0:
    // 0x80024EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024EAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024EB0: jr          $ra
    // 0x80024EB4: nop

    return;
    // 0x80024EB4: nop

;}
RECOMP_FUNC void FUN_80024eb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024EB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80024EBC: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x80024EC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80024EC4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80024EC8: lw          $t9, -0x425C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X425C);
    // 0x80024ECC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80024ED0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80024ED4: sh          $t8, 0x2E($t9)
    MEM_H(0X2E, ctx->r25) = ctx->r24;
    // 0x80024ED8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80024EDC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80024EE0: jr          $ra
    // 0x80024EE4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x80024EE4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80024ee8(rdram, ctx);
;}
RECOMP_FUNC void FUN_80024ee8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024EE8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80024EEC: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x80024EF0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80024EF4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80024EF8: lw          $t9, -0x425C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X425C);
    // 0x80024EFC: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80024F00: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80024F04: sh          $t8, 0x30($t9)
    MEM_H(0X30, ctx->r25) = ctx->r24;
    // 0x80024F08: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80024F0C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80024F10: jr          $ra
    // 0x80024F14: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x80024F14: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80024f18(rdram, ctx);
;}
RECOMP_FUNC void FUN_80024f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024F18: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80024F1C: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80024F20: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80024F24: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80024F28: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x80024F2C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80024F30: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80024F34: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80024F38: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80024F3C: beq         $at, $zero, L_80024F58
    if (ctx->r1 == 0) {
        // 0x80024F40: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80024F58;
    }
    // 0x80024F40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024F44: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80024F48: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x80024F4C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80024F50: b           L_80024F6C
    // 0x80024F54: sb          $v0, 0x93($t7)
    MEM_B(0X93, ctx->r15) = ctx->r2;
        goto L_80024F6C;
    // 0x80024F54: sb          $v0, 0x93($t7)
    MEM_B(0X93, ctx->r15) = ctx->r2;
L_80024F58:
    // 0x80024F58: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80024F5C: addiu       $t9, $a0, -0x64
    ctx->r25 = ADD32(ctx->r4, -0X64);
    // 0x80024F60: sb          $zero, 0x93($t8)
    MEM_B(0X93, ctx->r24) = 0;
    // 0x80024F64: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80024F68: sb          $t9, 0x9E($t0)
    MEM_B(0X9E, ctx->r8) = ctx->r25;
L_80024F6C:
    // 0x80024F6C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80024F70: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80024F74: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80024F78: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80024F7C: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80024F80: beq         $at, $zero, L_80024FC0
    if (ctx->r1 == 0) {
        // 0x80024F84: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80024FC0;
    }
    // 0x80024F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024F88: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x80024F8C: beq         $at, $zero, L_80024FAC
    if (ctx->r1 == 0) {
        // 0x80024F90: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_80024FAC;
    }
    // 0x80024F90: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80024F94: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80024F98: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80024F9C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80024FA0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80024FA4: b           L_80025008
    // 0x80024FA8: sb          $t2, 0x99($t3)
    MEM_B(0X99, ctx->r11) = ctx->r10;
        goto L_80025008;
    // 0x80024FA8: sb          $t2, 0x99($t3)
    MEM_B(0X99, ctx->r11) = ctx->r10;
L_80024FAC:
    // 0x80024FAC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80024FB0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80024FB4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80024FB8: b           L_80025008
    // 0x80024FBC: sb          $t4, 0x99($t5)
    MEM_B(0X99, ctx->r13) = ctx->r12;
        goto L_80025008;
    // 0x80024FBC: sb          $t4, 0x99($t5)
    MEM_B(0X99, ctx->r13) = ctx->r12;
L_80024FC0:
    // 0x80024FC0: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x80024FC4: beq         $at, $zero, L_80024FE0
    if (ctx->r1 == 0) {
        // 0x80024FC8: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80024FE0;
    }
    // 0x80024FC8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80024FCC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80024FD0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80024FD4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80024FD8: b           L_80025008
    // 0x80024FDC: sb          $t6, 0x99($t7)
    MEM_B(0X99, ctx->r15) = ctx->r14;
        goto L_80025008;
    // 0x80024FDC: sb          $t6, 0x99($t7)
    MEM_B(0X99, ctx->r15) = ctx->r14;
L_80024FE0:
    // 0x80024FE0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80024FE4: bnel        $a0, $at, L_80025000
    if (ctx->r4 != ctx->r1) {
        // 0x80024FE8: lw          $t1, 0x0($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X0);
            goto L_80025000;
    }
    goto skip_0;
    // 0x80024FE8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x80024FEC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80024FF0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80024FF4: b           L_80025008
    // 0x80024FF8: sb          $t8, 0x99($t9)
    MEM_B(0X99, ctx->r25) = ctx->r24;
        goto L_80025008;
    // 0x80024FF8: sb          $t8, 0x99($t9)
    MEM_B(0X99, ctx->r25) = ctx->r24;
    // 0x80024FFC: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
L_80025000:
    // 0x80025000: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80025004: sb          $t0, 0x99($t1)
    MEM_B(0X99, ctx->r9) = ctx->r8;
L_80025008:
    // 0x80025008: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8002500C: sb          $v0, 0x95($t2)
    MEM_B(0X95, ctx->r10) = ctx->r2;
    // 0x80025010: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80025014: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025018: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8002501C: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80025020: sh          $t5, 0x9A($t6)
    MEM_H(0X9A, ctx->r14) = ctx->r13;
    // 0x80025024: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80025028: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8002502C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80025030: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025034: lbu         $a0, 0x9E($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X9E);
    // 0x80025038: beq         $a0, $zero, L_80025074
    if (ctx->r4 == 0) {
        // 0x8002503C: nop
    
            goto L_80025074;
    }
    // 0x8002503C: nop

    // 0x80025040: lhu         $t9, 0x9A($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X9A);
    // 0x80025044: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x80025048: mflo        $t0
    ctx->r8 = lo;
    // 0x8002504C: sh          $t0, 0xA0($v1)
    MEM_H(0XA0, ctx->r3) = ctx->r8;
    // 0x80025050: bne         $a0, $zero, L_8002505C
    if (ctx->r4 != 0) {
        // 0x80025054: nop
    
            goto L_8002505C;
    }
    // 0x80025054: nop

    // 0x80025058: break       7
    do_break(2147635288);
L_8002505C:
    // 0x8002505C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80025060: bne         $a0, $at, L_80025074
    if (ctx->r4 != ctx->r1) {
        // 0x80025064: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80025074;
    }
    // 0x80025064: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80025068: bne         $t9, $at, L_80025074
    if (ctx->r25 != ctx->r1) {
        // 0x8002506C: nop
    
            goto L_80025074;
    }
    // 0x8002506C: nop

    // 0x80025070: break       6
    do_break(2147635312);
L_80025074:
    // 0x80025074: jr          $ra
    // 0x80025078: nop

    return;
    // 0x80025078: nop

;}
RECOMP_FUNC void FUN_8002507c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002507C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80025080: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80025084: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025088: lbu         $t6, 0x93($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X93);
    // 0x8002508C: sb          $t6, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r14;
    // 0x80025090: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025094: lbu         $t7, 0x9E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X9E);
    // 0x80025098: sb          $t7, 0x9F($v0)
    MEM_B(0X9F, ctx->r2) = ctx->r15;
    // 0x8002509C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800250A0: lbu         $t8, 0x9E($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9E);
    // 0x800250A4: bnel        $t8, $zero, L_800250BC
    if (ctx->r24 != 0) {
        // 0x800250A8: sh          $zero, 0x9C($v0)
        MEM_H(0X9C, ctx->r2) = 0;
            goto L_800250BC;
    }
    goto skip_0;
    // 0x800250A8: sh          $zero, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = 0;
    skip_0:
    // 0x800250AC: lhu         $t9, 0x9A($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X9A);
    // 0x800250B0: b           L_800250BC
    // 0x800250B4: sh          $t9, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r25;
        goto L_800250BC;
    // 0x800250B4: sh          $t9, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r25;
    // 0x800250B8: sh          $zero, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = 0;
L_800250BC:
    // 0x800250BC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800250C0: sh          $zero, 0x96($t0)
    MEM_H(0X96, ctx->r8) = 0;
    // 0x800250C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800250C8: lhu         $t1, 0x96($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X96);
    // 0x800250CC: jr          $ra
    // 0x800250D0: sb          $t1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r9;
    return;
    // 0x800250D0: sb          $t1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800250d4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800250d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800250D4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800250D8: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x800250DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800250E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800250E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800250E8: lbu         $v1, 0x94($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X94);
    // 0x800250EC: beq         $v1, $zero, L_800250FC
    if (ctx->r3 == 0) {
        // 0x800250F0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_800250FC;
    }
    // 0x800250F0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x800250F4: b           L_80025140
    // 0x800250F8: sb          $t6, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r14;
        goto L_80025140;
    // 0x800250F8: sb          $t6, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r14;
L_800250FC:
    // 0x800250FC: lbu         $v1, 0x9F($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X9F);
    // 0x80025100: beq         $v1, $zero, L_80025138
    if (ctx->r3 == 0) {
        // 0x80025104: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80025138;
    }
    // 0x80025104: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80025108: sb          $t7, 0x9F($v0)
    MEM_B(0X9F, ctx->r2) = ctx->r15;
    // 0x8002510C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025110: lbu         $t8, 0x9F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9F);
    // 0x80025114: beql        $t8, $zero, L_80025134
    if (ctx->r24 == 0) {
        // 0x80025118: lhu         $t2, 0x9A($v0)
        ctx->r10 = MEM_HU(ctx->r2, 0X9A);
            goto L_80025134;
    }
    goto skip_0;
    // 0x80025118: lhu         $t2, 0x9A($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X9A);
    skip_0:
    // 0x8002511C: lhu         $t9, 0x9C($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X9C);
    // 0x80025120: lhu         $t0, 0xA0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XA0);
    // 0x80025124: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80025128: b           L_80025138
    // 0x8002512C: sh          $t1, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r9;
        goto L_80025138;
    // 0x8002512C: sh          $t1, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r9;
    // 0x80025130: lhu         $t2, 0x9A($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X9A);
L_80025134:
    // 0x80025134: sh          $t2, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r10;
L_80025138:
    // 0x80025138: jal         0x80025150
    // 0x8002513C: nop

    LOOKUP_FUNC(0x80025150)(rdram, ctx);
        goto after_0;
    // 0x8002513C: nop

    after_0:
L_80025140:
    // 0x80025140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025148: jr          $ra
    // 0x8002514C: nop

    return;
    // 0x8002514C: nop

;}
RECOMP_FUNC void FUN_80025150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025150: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80025154: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x80025158: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002515C: lbu         $t6, 0x94($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X94);
    // 0x80025160: bne         $t6, $zero, L_80025278
    if (ctx->r14 != 0) {
        // 0x80025164: nop
    
            goto L_80025278;
    }
    // 0x80025164: nop

    // 0x80025168: lhu         $t7, 0x96($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X96);
    // 0x8002516C: lbu         $t8, 0x95($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X95);
    // 0x80025170: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80025174: sh          $t9, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r25;
    // 0x80025178: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002517C: lhu         $v1, 0x96($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X96);
    // 0x80025180: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80025184: bne         $at, $zero, L_80025278
    if (ctx->r1 != 0) {
        // 0x80025188: andi        $t0, $v1, 0xFF
        ctx->r8 = ctx->r3 & 0XFF;
            goto L_80025278;
    }
    // 0x80025188: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x8002518C: sh          $t0, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r8;
    // 0x80025190: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80025194: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80025198: lbu         $t1, 0x6($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X6);
    // 0x8002519C: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800251A0: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
    // 0x800251A4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800251A8: lbu         $t3, 0x98($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X98);
    // 0x800251AC: lbu         $t4, 0x99($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X99);
    // 0x800251B0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800251B4: sb          $t5, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r13;
    // 0x800251B8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800251BC: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800251C0: andi        $t7, $t6, 0x3F
    ctx->r15 = ctx->r14 & 0X3F;
    // 0x800251C4: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
    // 0x800251C8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800251CC: lhu         $a0, 0x9C($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X9C);
    // 0x800251D0: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800251D4: beq         $at, $zero, L_80025214
    if (ctx->r1 == 0) {
        // 0x800251D8: sra         $t5, $a0, 8
        ctx->r13 = S32(SIGNED(ctx->r4) >> 8);
            goto L_80025214;
    }
    // 0x800251D8: sra         $t5, $a0, 8
    ctx->r13 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800251DC: sra         $t8, $a0, 7
    ctx->r24 = S32(SIGNED(ctx->r4) >> 7);
    // 0x800251E0: sh          $t8, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r24;
    // 0x800251E4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800251E8: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x800251EC: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x800251F0: lh          $t2, 0x36($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X36);
    // 0x800251F4: andi        $t0, $t9, 0x1F
    ctx->r8 = ctx->r25 & 0X1F;
    // 0x800251F8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800251FC: lbu         $t1, -0x7E00($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X7E00);
    // 0x80025200: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025204: mflo        $t3
    ctx->r11 = lo;
    // 0x80025208: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x8002520C: b           L_80025258
    // 0x80025210: sh          $t4, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r12;
        goto L_80025258;
    // 0x80025210: sh          $t4, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r12;
L_80025214:
    // 0x80025214: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x80025218: sh          $t6, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r14;
    // 0x8002521C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80025220: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80025224: lh          $t7, 0x36($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X36);
    // 0x80025228: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x8002522C: sh          $t8, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r24;
    // 0x80025230: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80025234: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x80025238: lh          $t2, 0x36($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X36);
    // 0x8002523C: andi        $t0, $t9, 0x1F
    ctx->r8 = ctx->r25 & 0X1F;
    // 0x80025240: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80025244: lbu         $t1, -0x7E00($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X7E00);
    // 0x80025248: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002524C: mflo        $t3
    ctx->r11 = lo;
    // 0x80025250: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80025254: sh          $t4, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r12;
L_80025258:
    // 0x80025258: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002525C: lbu         $t5, 0x98($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X98);
    // 0x80025260: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x80025264: bne         $at, $zero, L_80025278
    if (ctx->r1 != 0) {
        // 0x80025268: nop
    
            goto L_80025278;
    }
    // 0x80025268: nop

    // 0x8002526C: lh          $t6, 0x36($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X36);
    // 0x80025270: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80025274: sh          $t7, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r15;
L_80025278:
    // 0x80025278: jr          $ra
    // 0x8002527C: nop

    return;
    // 0x8002527C: nop

    // 0x80025280: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80025284: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x80025288: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002528C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80025290: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80025294: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80025298: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x8002529C: sb          $v0, 0x9E($t7)
    MEM_B(0X9E, ctx->r15) = ctx->r2;
    // 0x800252A0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800252A4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800252A8: beq         $v0, $zero, L_800252EC
    if (ctx->r2 == 0) {
        // 0x800252AC: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_800252EC;
    }
    // 0x800252AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800252B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800252B4: lhu         $t0, 0x9A($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X9A);
    // 0x800252B8: lbu         $t1, 0x9E($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X9E);
    // 0x800252BC: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x800252C0: mflo        $t2
    ctx->r10 = lo;
    // 0x800252C4: sh          $t2, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = ctx->r10;
    // 0x800252C8: bne         $t1, $zero, L_800252D4
    if (ctx->r9 != 0) {
        // 0x800252CC: nop
    
            goto L_800252D4;
    }
    // 0x800252CC: nop

    // 0x800252D0: break       7
    do_break(2147635920);
L_800252D4:
    // 0x800252D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800252D8: bne         $t1, $at, L_800252EC
    if (ctx->r9 != ctx->r1) {
        // 0x800252DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800252EC;
    }
    // 0x800252DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800252E0: bne         $t0, $at, L_800252EC
    if (ctx->r8 != ctx->r1) {
        // 0x800252E4: nop
    
            goto L_800252EC;
    }
    // 0x800252E4: nop

    // 0x800252E8: break       6
    do_break(2147635944);
L_800252EC:
    // 0x800252EC: jr          $ra
    // 0x800252F0: nop

    return;
    // 0x800252F0: nop

;}
RECOMP_FUNC void FUN_800252f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800252F4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800252F8: addiu       $a0, $a0, -0x4260
    ctx->r4 = ADD32(ctx->r4, -0X4260);
    // 0x800252FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80025300: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80025304: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80025308: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002530C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80025310: sb          $t7, 0x92($t8)
    MEM_B(0X92, ctx->r24) = ctx->r15;
    // 0x80025314: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80025318: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8002531C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80025320: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80025324: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x80025328: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8002532C: sh          $t3, 0x8E($t4)
    MEM_H(0X8E, ctx->r12) = ctx->r11;
    // 0x80025330: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80025334: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025338: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002533C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80025340: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x80025344: lhu         $t7, 0x8E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X8E);
    // 0x80025348: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8002534C: sh          $t0, 0x8E($v0)
    MEM_H(0X8E, ctx->r2) = ctx->r8;
    // 0x80025350: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80025354: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80025358: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8002535C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80025360: sb          $zero, 0x8D($t3)
    MEM_B(0X8D, ctx->r11) = 0;
    // 0x80025364: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025368: lbu         $t4, 0x8D($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8D);
    // 0x8002536C: sh          $t4, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r12;
    // 0x80025370: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025374: lbu         $t5, 0x92($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X92);
    // 0x80025378: bne         $t5, $zero, L_80025384
    if (ctx->r13 != 0) {
        // 0x8002537C: nop
    
            goto L_80025384;
    }
    // 0x8002537C: nop

    // 0x80025380: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
L_80025384:
    // 0x80025384: jr          $ra
    // 0x80025388: nop

    return;
    // 0x80025388: nop

;}
RECOMP_FUNC void FUN_8002538c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002538C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80025390: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80025394: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025398: lhu         $t6, 0x90($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X90);
    // 0x8002539C: lbu         $t7, 0x92($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X92);
    // 0x800253A0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800253A4: sh          $t8, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r24;
    // 0x800253A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800253AC: lhu         $v1, 0x90($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X90);
    // 0x800253B0: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800253B4: bne         $at, $zero, L_80025440
    if (ctx->r1 != 0) {
        // 0x800253B8: andi        $t9, $v1, 0xFF
        ctx->r25 = ctx->r3 & 0XFF;
            goto L_80025440;
    }
    // 0x800253B8: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x800253BC: sh          $t9, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r25;
    // 0x800253C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800253C4: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x800253C8: addiu       $a1, $a1, -0x7DE0
    ctx->r5 = ADD32(ctx->r5, -0X7DE0);
    // 0x800253CC: lbu         $t0, 0x6($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X6);
    // 0x800253D0: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x800253D4: sb          $t1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r9;
    // 0x800253D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800253DC: lbu         $t2, 0x8D($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8D);
    // 0x800253E0: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x800253E4: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800253E8: sh          $t4, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r12;
    // 0x800253EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800253F0: lbu         $t5, 0x8D($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X8D);
    // 0x800253F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800253F8: sb          $t6, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r14;
    // 0x800253FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025400: lbu         $t7, 0x8D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8D);
    // 0x80025404: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x80025408: sb          $t8, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r24;
    // 0x8002540C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025410: lbu         $t0, 0x8D($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X8D);
    // 0x80025414: lhu         $t9, 0x38($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X38);
    // 0x80025418: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8002541C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80025420: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80025424: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80025428: sh          $t4, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r12;
    // 0x8002542C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025430: lhu         $t5, 0x38($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X38);
    // 0x80025434: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x80025438: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8002543C: sh          $t7, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r15;
L_80025440:
    // 0x80025440: jr          $ra
    // 0x80025444: nop

    return;
    // 0x80025444: nop

    // 0x80025448: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002544C: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x80025450: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80025454: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x80025458: jr          $ra
    // 0x8002545C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8002545C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025460(rdram, ctx);
;}
RECOMP_FUNC void FUN_80025460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025460: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80025464: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x80025468: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8002546C: lbu         $t6, 0x7D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X7D);
    // 0x80025470: lhu         $t8, 0x18($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X18);
    // 0x80025474: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x80025478: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8002547C: divu        $zero, $t7, $t8
    lo = S32(U32(ctx->r15) / U32(ctx->r24)); hi = S32(U32(ctx->r15) % U32(ctx->r24));
    // 0x80025480: mflo        $v0
    ctx->r2 = lo;
    // 0x80025484: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
    // 0x80025488: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002548C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80025490: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    // 0x80025494: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x80025498: mflo        $t1
    ctx->r9 = lo;
    // 0x8002549C: sw          $t1, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r9;
    // 0x800254A0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800254A4: bne         $t8, $zero, L_800254B0
    if (ctx->r24 != 0) {
        // 0x800254A8: nop
    
            goto L_800254B0;
    }
    // 0x800254A8: nop

    // 0x800254AC: break       7
    do_break(2147636396);
L_800254B0:
    // 0x800254B0: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x800254B4: bne         $v0, $zero, L_800254C0
    if (ctx->r2 != 0) {
        // 0x800254B8: nop
    
            goto L_800254C0;
    }
    // 0x800254B8: nop

    // 0x800254BC: break       7
    do_break(2147636412);
L_800254C0:
    // 0x800254C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800254C4: bne         $v0, $at, L_800254D8
    if (ctx->r2 != ctx->r1) {
        // 0x800254C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800254D8;
    }
    // 0x800254C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800254CC: bne         $a0, $at, L_800254D8
    if (ctx->r4 != ctx->r1) {
        // 0x800254D0: nop
    
            goto L_800254D8;
    }
    // 0x800254D0: nop

    // 0x800254D4: break       6
    do_break(2147636436);
L_800254D8:
    // 0x800254D8: bne         $a1, $zero, L_800254F8
    if (ctx->r5 != 0) {
        // 0x800254DC: nop
    
            goto L_800254F8;
    }
    // 0x800254DC: nop

    // 0x800254E0: bgez        $a0, L_800254F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800254E4: addiu       $t3, $a1, 0x1
        ctx->r11 = ADD32(ctx->r5, 0X1);
            goto L_800254F4;
    }
    // 0x800254E4: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x800254E8: addiu       $t2, $a1, -0x1
    ctx->r10 = ADD32(ctx->r5, -0X1);
    // 0x800254EC: jr          $ra
    // 0x800254F0: sw          $t2, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r10;
    return;
    // 0x800254F0: sw          $t2, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r10;
L_800254F4:
    // 0x800254F4: sw          $t3, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r11;
L_800254F8:
    // 0x800254F8: jr          $ra
    // 0x800254FC: nop

    return;
    // 0x800254FC: nop

;}
RECOMP_FUNC void FUN_80025500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025500: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80025504: addiu       $a0, $a0, -0x4260
    ctx->r4 = ADD32(ctx->r4, -0X4260);
    // 0x80025508: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8002550C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025514: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80025518: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x8002551C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80025520: xori        $v0, $v0, 0xE4
    ctx->r2 = ctx->r2 ^ 0XE4;
    // 0x80025524: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80025528: beq         $v0, $zero, L_800255EC
    if (ctx->r2 == 0) {
        // 0x8002552C: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_800255EC;
    }
    // 0x8002552C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80025530: lbu         $t7, -0x454C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X454C);
    // 0x80025534: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80025538: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x8002553C: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x80025540: beql        $at, $zero, L_800255D4
    if (ctx->r1 == 0) {
        // 0x80025544: lw          $t3, 0x0($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X0);
            goto L_800255D4;
    }
    goto skip_0;
    // 0x80025544: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80025548: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8002554C: lh          $t8, 0x8A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8A);
    // 0x80025550: bnel        $t8, $zero, L_800255D4
    if (ctx->r24 != 0) {
        // 0x80025554: lw          $t3, 0x0($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X0);
            goto L_800255D4;
    }
    goto skip_1;
    // 0x80025554: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80025558: sb          $zero, 0x8C($v0)
    MEM_B(0X8C, ctx->r2) = 0;
    // 0x8002555C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80025560: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80025564: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80025568: sb          $t0, 0x7C($t1)
    MEM_B(0X7C, ctx->r9) = ctx->r8;
    // 0x8002556C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80025570: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025574: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80025578: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8002557C: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x80025580: sb          $t5, 0x7D($t6)
    MEM_B(0X7D, ctx->r14) = ctx->r13;
    // 0x80025584: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80025588: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8002558C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80025590: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80025594: lbu         $v1, 0x0($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0X0);
    // 0x80025598: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002559C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800255A0: lbu         $t0, 0x25($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X25);
    // 0x800255A4: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    // 0x800255A8: subu        $v1, $v1, $t0
    ctx->r3 = SUB32(ctx->r3, ctx->r8);
    // 0x800255AC: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x800255B0: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800255B4: jal         0x80025460
    // 0x800255B8: sw          $t2, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r10;
    LOOKUP_FUNC(0x80025460)(rdram, ctx);
        goto after_0;
    // 0x800255B8: sw          $t2, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r10;
    after_0:
    // 0x800255BC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800255C0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800255C4: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x800255C8: b           L_800255E4
    // 0x800255CC: addiu       $a0, $a0, -0x4260
    ctx->r4 = ADD32(ctx->r4, -0X4260);
        goto L_800255E4;
    // 0x800255CC: addiu       $a0, $a0, -0x4260
    ctx->r4 = ADD32(ctx->r4, -0X4260);
    // 0x800255D0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
L_800255D4:
    // 0x800255D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800255D8: addiu       $t4, $t3, 0x3
    ctx->r12 = ADD32(ctx->r11, 0X3);
    // 0x800255DC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800255E0: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
L_800255E4:
    // 0x800255E4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800255E8: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
L_800255EC:
    // 0x800255EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800255F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800255F4: jr          $ra
    // 0x800255F8: nop

    return;
    // 0x800255F8: nop

;}
RECOMP_FUNC void FUN_800255fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800255FC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80025600: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80025604: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002560C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025610: lbu         $t6, 0x8C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8C);
    // 0x80025614: bne         $t6, $zero, L_8002567C
    if (ctx->r14 != 0) {
        // 0x80025618: nop
    
            goto L_8002567C;
    }
    // 0x80025618: nop

    // 0x8002561C: lbu         $v1, 0x7C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X7C);
    // 0x80025620: beq         $v1, $zero, L_80025630
    if (ctx->r3 == 0) {
        // 0x80025624: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80025630;
    }
    // 0x80025624: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80025628: b           L_80025684
    // 0x8002562C: sb          $t7, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r15;
        goto L_80025684;
    // 0x8002562C: sb          $t7, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r15;
L_80025630:
    // 0x80025630: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x80025634: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80025638: sb          $t9, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r25;
    // 0x8002563C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025640: lbu         $t0, 0x7D($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X7D);
    // 0x80025644: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80025648: sb          $t1, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r9;
    // 0x8002564C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025650: lbu         $t2, 0x7D($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7D);
    // 0x80025654: beql        $t2, $zero, L_80025674
    if (ctx->r10 == 0) {
        // 0x80025658: lw          $t6, 0x80($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X80);
            goto L_80025674;
    }
    goto skip_0;
    // 0x80025658: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    skip_0:
    // 0x8002565C: lw          $t3, 0x28($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X28);
    // 0x80025660: lw          $t4, 0x84($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X84);
    // 0x80025664: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80025668: b           L_80025684
    // 0x8002566C: sw          $t5, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r13;
        goto L_80025684;
    // 0x8002566C: sw          $t5, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r13;
    // 0x80025670: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
L_80025674:
    // 0x80025674: b           L_80025684
    // 0x80025678: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
        goto L_80025684;
    // 0x80025678: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
L_8002567C:
    // 0x8002567C: jal         0x80025834
    // 0x80025680: nop

    LOOKUP_FUNC(0x80025834)(rdram, ctx);
        goto after_0;
    // 0x80025680: nop

    after_0:
L_80025684:
    // 0x80025684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002568C: jr          $ra
    // 0x80025690: nop

    return;
    // 0x80025690: nop

;}
RECOMP_FUNC void FUN_80025694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025694: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80025698: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x8002569C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800256A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800256A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800256A8: lbu         $t6, 0x8C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8C);
    // 0x800256AC: bne         $t6, $zero, L_800256E4
    if (ctx->r14 != 0) {
        // 0x800256B0: nop
    
            goto L_800256E4;
    }
    // 0x800256B0: nop

    // 0x800256B4: lbu         $t7, 0x7C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X7C);
    // 0x800256B8: bnel        $t7, $zero, L_800256F0
    if (ctx->r15 != 0) {
        // 0x800256BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800256F0;
    }
    goto skip_0;
    // 0x800256BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800256C0: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800256C4: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x800256C8: sb          $t9, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r25;
    // 0x800256CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800256D0: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    // 0x800256D4: lw          $t1, 0x84($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X84);
    // 0x800256D8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800256DC: b           L_800256EC
    // 0x800256E0: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
        goto L_800256EC;
    // 0x800256E0: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
L_800256E4:
    // 0x800256E4: jal         0x80025834
    // 0x800256E8: nop

    LOOKUP_FUNC(0x80025834)(rdram, ctx);
        goto after_0;
    // 0x800256E8: nop

    after_0:
L_800256EC:
    // 0x800256EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800256F0:
    // 0x800256F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800256F4: jr          $ra
    // 0x800256F8: nop

    return;
    // 0x800256F8: nop

    // 0x800256FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025700: addiu       $v0, $v0, -0x425C
    ctx->r2 = ADD32(ctx->r2, -0X425C);
    // 0x80025704: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80025708: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002570C: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x80025710: sb          $zero, 0x8C($t6)
    MEM_B(0X8C, ctx->r14) = 0;
    // 0x80025714: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80025718: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002571C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80025720: sb          $t8, 0x88($t9)
    MEM_B(0X88, ctx->r25) = ctx->r24;
    // 0x80025724: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80025728: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002572C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80025730: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80025734: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x80025738: sb          $t3, 0x89($t4)
    MEM_B(0X89, ctx->r12) = ctx->r11;
    // 0x8002573C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80025740: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80025744: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80025748: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002574C: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x80025750: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80025754: sh          $t9, 0x8A($t0)
    MEM_H(0X8A, ctx->r8) = ctx->r25;
    // 0x80025758: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8002575C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80025760: jr          $ra
    // 0x80025764: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    return;
    // 0x80025764: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025768(rdram, ctx);
;}
RECOMP_FUNC void FUN_80025768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025768: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002576C: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80025770: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002577C: lbu         $t6, 0x8C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8C);
    // 0x80025780: bnel        $t6, $zero, L_800257CC
    if (ctx->r14 != 0) {
        // 0x80025784: lw          $t3, 0x28($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X28);
            goto L_800257CC;
    }
    goto skip_0;
    // 0x80025784: lw          $t3, 0x28($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X28);
    skip_0:
    // 0x80025788: lbu         $t7, 0x88($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X88);
    // 0x8002578C: sb          $t7, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r15;
    // 0x80025790: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025794: lbu         $t8, 0x89($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X89);
    // 0x80025798: sb          $t8, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r24;
    // 0x8002579C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800257A0: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x800257A4: sw          $t9, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r25;
    // 0x800257A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800257AC: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    // 0x800257B0: lh          $t1, 0x8A($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8A);
    // 0x800257B4: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800257B8: jal         0x80025460
    // 0x800257BC: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
    LOOKUP_FUNC(0x80025460)(rdram, ctx);
        goto after_0;
    // 0x800257BC: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
    after_0:
    // 0x800257C0: b           L_800257EC
    // 0x800257C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800257EC;
    // 0x800257C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800257C8: lw          $t3, 0x28($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X28);
L_800257CC:
    // 0x800257CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800257D0: sw          $t3, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r11;
    // 0x800257D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800257D8: lw          $t4, 0x84($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X84);
    // 0x800257DC: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
    // 0x800257E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800257E4: sb          $t5, 0x7D($t6)
    MEM_B(0X7D, ctx->r14) = ctx->r13;
    // 0x800257E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800257EC:
    // 0x800257EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800257F0: jr          $ra
    // 0x800257F4: nop

    return;
    // 0x800257F4: nop

;}
RECOMP_FUNC void FUN_800257f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800257F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800257FC: addiu       $v0, $v0, -0x425C
    ctx->r2 = ADD32(ctx->r2, -0X425C);
    // 0x80025800: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80025804: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80025808: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002580C: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x80025810: sb          $t6, 0x8C($t7)
    MEM_B(0X8C, ctx->r15) = ctx->r14;
    // 0x80025814: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80025818: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8002581C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80025820: sh          $t9, 0x8A($t0)
    MEM_H(0X8A, ctx->r8) = ctx->r25;
    // 0x80025824: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80025828: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8002582C: jr          $ra
    // 0x80025830: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    return;
    // 0x80025830: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025834(rdram, ctx);
;}
RECOMP_FUNC void FUN_80025834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025834: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80025838: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x8002583C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80025840: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x80025844: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80025848: sb          $t7, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r15;
    // 0x8002584C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80025850: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x80025854: lw          $t8, 0x80($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X80);
    // 0x80025858: subu        $v1, $t8, $a0
    ctx->r3 = SUB32(ctx->r24, ctx->r4);
    // 0x8002585C: bgez        $v1, L_80025868
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80025860: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80025868;
    }
    // 0x80025860: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80025864: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
L_80025868:
    // 0x80025868: lh          $t9, 0x8A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8A);
    // 0x8002586C: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025870: mflo        $a1
    ctx->r5 = lo;
    // 0x80025874: sra         $a1, $a1, 8
    ctx->r5 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80025878: bne         $a1, $zero, L_80025884
    if (ctx->r5 != 0) {
        // 0x8002587C: nop
    
            goto L_80025884;
    }
    // 0x8002587C: nop

    // 0x80025880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80025884:
    // 0x80025884: bgez        $v1, L_800258C4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80025888: addu        $t1, $a0, $a1
        ctx->r9 = ADD32(ctx->r4, ctx->r5);
            goto L_800258C4;
    }
    // 0x80025888: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x8002588C: subu        $t0, $a0, $a1
    ctx->r8 = SUB32(ctx->r4, ctx->r5);
    // 0x80025890: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    // 0x80025894: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80025898: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x8002589C: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    // 0x800258A0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800258A4: beq         $at, $zero, L_800258F4
    if (ctx->r1 == 0) {
        // 0x800258A8: nop
    
            goto L_800258F4;
    }
    // 0x800258A8: nop

    // 0x800258AC: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x800258B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800258B4: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x800258B8: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    // 0x800258BC: b           L_800258F4
    // 0x800258C0: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
        goto L_800258F4;
    // 0x800258C0: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
L_800258C4:
    // 0x800258C4: sw          $t1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r9;
    // 0x800258C8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800258CC: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    // 0x800258D0: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x800258D4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800258D8: beq         $at, $zero, L_800258F4
    if (ctx->r1 == 0) {
        // 0x800258DC: nop
    
            goto L_800258F4;
    }
    // 0x800258DC: nop

    // 0x800258E0: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x800258E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800258E8: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x800258EC: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    // 0x800258F0: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
L_800258F4:
    // 0x800258F4: bne         $v1, $a0, L_80025900
    if (ctx->r3 != ctx->r4) {
        // 0x800258F8: nop
    
            goto L_80025900;
    }
    // 0x800258F8: nop

    // 0x800258FC: sb          $zero, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = 0;
L_80025900:
    // 0x80025900: jr          $ra
    // 0x80025904: nop

    return;
    // 0x80025904: nop

;}
RECOMP_FUNC void FUN_80025908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025908: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002590C: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80025910: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80025914: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80025918: sb          $zero, 0x5E($t6)
    MEM_B(0X5E, ctx->r14) = 0;
    // 0x8002591C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80025920: lw          $t7, -0x4260($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4260);
    // 0x80025924: sw          $t7, 0x60($t8)
    MEM_W(0X60, ctx->r24) = ctx->r15;
    // 0x80025928: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002592C: sh          $zero, 0x40($t9)
    MEM_H(0X40, ctx->r25) = 0;
    // 0x80025930: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025934: lh          $t0, 0x40($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X40);
    // 0x80025938: jr          $ra
    // 0x8002593C: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    return;
    // 0x8002593C: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025940(rdram, ctx);
;}
RECOMP_FUNC void FUN_80025940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025940: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80025944: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80025948: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8002594C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80025950: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x80025954: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025958: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8002595C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80025960: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80025964: lbu         $t7, 0x5E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5E);
    // 0x80025968: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002596C: beq         $v0, $zero, L_80025984
    if (ctx->r2 == 0) {
        // 0x80025970: sb          $t8, 0x5E($a0)
        MEM_B(0X5E, ctx->r4) = ctx->r24;
            goto L_80025984;
    }
    // 0x80025970: sb          $t8, 0x5E($a0)
    MEM_B(0X5E, ctx->r4) = ctx->r24;
    // 0x80025974: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025978: lbu         $t9, 0x5E($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5E);
    // 0x8002597C: beql        $t9, $v0, L_800259E0
    if (ctx->r25 == ctx->r2) {
        // 0x80025980: sh          $zero, 0x40($a0)
        MEM_H(0X40, ctx->r4) = 0;
            goto L_800259E0;
    }
    goto skip_0;
    // 0x80025980: sh          $zero, 0x40($a0)
    MEM_H(0X40, ctx->r4) = 0;
    skip_0:
L_80025984:
    // 0x80025984: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025988: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8002598C: lh          $t0, 0x40($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X40);
    // 0x80025990: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x80025994: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80025998: sh          $t3, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r11;
    // 0x8002599C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800259A0: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800259A4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800259A8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800259AC: lb          $t8, 0x0($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X0);
    // 0x800259B0: lh          $t6, 0x32($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X32);
    // 0x800259B4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800259B8: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x800259BC: sh          $t1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r9;
    // 0x800259C0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800259C4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800259C8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800259CC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800259D0: lw          $t4, 0x60($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X60);
    // 0x800259D4: jr          $ra
    // 0x800259D8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    return;
    // 0x800259D8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800259DC: sh          $zero, 0x40($a0)
    MEM_H(0X40, ctx->r4) = 0;
L_800259E0:
    // 0x800259E0: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800259E4: lh          $t5, 0x40($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X40);
    // 0x800259E8: sh          $t5, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r13;
    // 0x800259EC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800259F0: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800259F4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800259F8: jr          $ra
    // 0x800259FC: nop

    return;
    // 0x800259FC: nop

;}
RECOMP_FUNC void FUN_80025a00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025A00: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80025A04: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80025A08: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80025A0C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80025A10: sb          $zero, 0x64($t6)
    MEM_B(0X64, ctx->r14) = 0;
    // 0x80025A14: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80025A18: lw          $t7, -0x4260($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4260);
    // 0x80025A1C: sw          $t7, 0x68($t8)
    MEM_W(0X68, ctx->r24) = ctx->r15;
    // 0x80025A20: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80025A24: sh          $zero, 0x42($t9)
    MEM_H(0X42, ctx->r25) = 0;
    // 0x80025A28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80025A2C: lh          $t0, 0x42($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X42);
    // 0x80025A30: jr          $ra
    // 0x80025A34: sh          $t0, 0x34($v0)
    MEM_H(0X34, ctx->r2) = ctx->r8;
    return;
    // 0x80025A34: sh          $t0, 0x34($v0)
    MEM_H(0X34, ctx->r2) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025a38(rdram, ctx);
;}
RECOMP_FUNC void FUN_80025a38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025A38: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80025A3C: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80025A40: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80025A44: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80025A48: addiu       $a2, $a2, -0x425C
    ctx->r6 = ADD32(ctx->r6, -0X425C);
    // 0x80025A4C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025A50: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80025A54: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80025A58: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80025A5C: lbu         $t7, 0x64($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X64);
    // 0x80025A60: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80025A64: beq         $v0, $zero, L_80025A7C
    if (ctx->r2 == 0) {
        // 0x80025A68: sb          $t8, 0x64($a0)
        MEM_B(0X64, ctx->r4) = ctx->r24;
            goto L_80025A7C;
    }
    // 0x80025A68: sb          $t8, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r24;
    // 0x80025A6C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025A70: lbu         $t9, 0x64($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X64);
    // 0x80025A74: beql        $t9, $v0, L_80025AD8
    if (ctx->r25 == ctx->r2) {
        // 0x80025A78: sh          $zero, 0x42($a0)
        MEM_H(0X42, ctx->r4) = 0;
            goto L_80025AD8;
    }
    goto skip_0;
    // 0x80025A78: sh          $zero, 0x42($a0)
    MEM_H(0X42, ctx->r4) = 0;
    skip_0:
L_80025A7C:
    // 0x80025A7C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025A80: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80025A84: lh          $t0, 0x42($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X42);
    // 0x80025A88: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x80025A8C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80025A90: sh          $t3, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r11;
    // 0x80025A94: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80025A98: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025A9C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80025AA0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80025AA4: lb          $t8, 0x0($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X0);
    // 0x80025AA8: lh          $t6, 0x34($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X34);
    // 0x80025AAC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80025AB0: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x80025AB4: sh          $t1, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r9;
    // 0x80025AB8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80025ABC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025AC0: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80025AC4: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80025AC8: lw          $t4, 0x68($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X68);
    // 0x80025ACC: jr          $ra
    // 0x80025AD0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    return;
    // 0x80025AD0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80025AD4: sh          $zero, 0x42($a0)
    MEM_H(0X42, ctx->r4) = 0;
L_80025AD8:
    // 0x80025AD8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80025ADC: lh          $t5, 0x42($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X42);
    // 0x80025AE0: sh          $t5, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r13;
    // 0x80025AE4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80025AE8: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80025AEC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025AF0: jr          $ra
    // 0x80025AF4: nop

    return;
    // 0x80025AF4: nop

;}
RECOMP_FUNC void FUN_80025af8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025AF8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80025AFC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80025B00: lw          $t7, -0x425C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X425C);
    // 0x80025B04: lw          $t6, -0x4260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4260);
    // 0x80025B08: jr          $ra
    // 0x80025B0C: sw          $t6, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->r14;
    return;
    // 0x80025B0C: sw          $t6, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025b10(rdram, ctx);
;}
RECOMP_FUNC void FUN_80025b10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B10: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80025B14: lw          $t6, -0x425C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X425C);
    // 0x80025B18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80025B1C: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x80025B20: jr          $ra
    // 0x80025B24: sw          $t7, -0x4260($at)
    MEM_W(-0X4260, ctx->r1) = ctx->r15;
    return;
    // 0x80025B24: sw          $t7, -0x4260($at)
    MEM_W(-0X4260, ctx->r1) = ctx->r15;
    // 0x80025B28: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025B2C: addiu       $v0, $v0, -0x425C
    ctx->r2 = ADD32(ctx->r2, -0X425C);
    // 0x80025B30: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80025B34: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80025B38: sb          $zero, 0x70($t6)
    MEM_B(0X70, ctx->r14) = 0;
    // 0x80025B3C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80025B40: lw          $t7, -0x4260($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4260);
    // 0x80025B44: jr          $ra
    // 0x80025B48: sw          $t7, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->r15;
    return;
    // 0x80025B48: sw          $t7, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025b4c(rdram, ctx);
;}
