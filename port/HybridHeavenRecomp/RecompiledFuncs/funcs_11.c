#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void osViBlack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800295D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800295D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800295D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800295DC: jal         0x80032660
    // 0x800295E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x800295E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800295E4: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x800295E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800295EC: beq         $t6, $zero, L_8002960C
    if (ctx->r14 == 0) {
        // 0x800295F0: nop
    
            goto L_8002960C;
    }
    // 0x800295F0: nop

    // 0x800295F4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x800295F8: lw          $t7, -0x512C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X512C);
    // 0x800295FC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80029600: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80029604: b           L_80029624
    // 0x80029608: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
        goto L_80029624;
    // 0x80029608: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
L_8002960C:
    // 0x8002960C: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80029610: lw          $t0, -0x512C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X512C);
    // 0x80029614: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80029618: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8002961C: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80029620: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
L_80029624:
    // 0x80029624: jal         0x800326D0
    // 0x80029628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x80029628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002962C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029630: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80029638: jr          $ra
    // 0x8002963C: nop

    return;
    // 0x8002963C: nop

;}
RECOMP_FUNC void __osSpRawReadIo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002964C: jal         0x800309E0
    // 0x80029650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800309E0)(rdram, ctx);
        goto after_0;
    // 0x80029650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80029654: beq         $v0, $zero, L_80029664
    if (ctx->r2 == 0) {
        // 0x80029658: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80029664;
    }
    // 0x80029658: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8002965C: b           L_8002967C
    // 0x80029660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8002967C;
    // 0x80029660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029664:
    // 0x80029664: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80029668: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002966C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80029670: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80029674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029678: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_8002967C:
    // 0x8002967C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029684: jr          $ra
    // 0x80029688: nop

    return;
    // 0x80029688: nop

    // 0x8002968C: nop

;}
RECOMP_FUNC void FUN_800296b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800296B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800296B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800296B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800296BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800296C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800296C4: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800296C8: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x800296CC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800296D0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800296D4: beq         $v0, $t7, L_80029700
    if (ctx->r2 == ctx->r15) {
        // 0x800296D8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80029700;
    }
    // 0x800296D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800296DC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800296E0: lbu         $a3, 0x0($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X0);
    // 0x800296E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800296E8: jal         0x8002BCB4
    // 0x800296EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8002BCB4)(rdram, ctx);
        goto after_0;
    // 0x800296EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800296F0: beq         $v0, $zero, L_80029700
    if (ctx->r2 == 0) {
        // 0x800296F4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80029700;
    }
    // 0x800296F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800296F8: b           L_80029774
    // 0x800296FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80029774;
    // 0x800296FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80029700:
    // 0x80029700: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x80029704: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80029708: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8002970C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80029710: lhu         $at, 0x0($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X0);
    // 0x80029714: sh          $at, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r1;
    // 0x80029718: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x8002971C: andi        $v1, $at, 0xFFFF
    ctx->r3 = ctx->r1 & 0XFFFF;
    // 0x80029720: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029724: bnel        $at, $zero, L_80029758
    if (ctx->r1 != 0) {
        // 0x80029728: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80029758;
    }
    goto skip_0;
    // 0x80029728: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8002972C: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x80029730: lbu         $t7, 0x64($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X64);
    // 0x80029734: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80029738: beql        $at, $zero, L_80029758
    if (ctx->r1 == 0) {
        // 0x8002973C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80029758;
    }
    goto skip_1;
    // 0x8002973C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x80029740: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80029744: blez        $v0, L_80029754
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80029748: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80029754;
    }
    // 0x80029748: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8002974C: bne         $at, $zero, L_80029770
    if (ctx->r1 != 0) {
        // 0x80029750: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80029770;
    }
    // 0x80029750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80029754:
    // 0x80029754: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80029758:
    // 0x80029758: bne         $v1, $at, L_80029768
    if (ctx->r3 != ctx->r1) {
        // 0x8002975C: nop
    
            goto L_80029768;
    }
    // 0x8002975C: nop

    // 0x80029760: b           L_80029770
    // 0x80029764: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80029770;
    // 0x80029764: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80029768:
    // 0x80029768: b           L_80029770
    // 0x8002976C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80029770;
    // 0x8002976C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80029770:
    // 0x80029770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80029774:
    // 0x80029774: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029778: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002977C: jr          $ra
    // 0x80029780: nop

    return;
    // 0x80029780: nop

;}
RECOMP_FUNC void FUN_80029d30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D30: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80029D34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029D38: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80029D3C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80029D40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029D44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80029D48: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80029D4C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80029D50: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80029D54:
    // 0x80029D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029D58: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x80029D5C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80029D60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029D64: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80029D68: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80029D6C: beq         $a0, $t3, L_80029DD4
    if (ctx->r4 == ctx->r11) {
        // 0x80029D70: nop
    
            goto L_80029DD4;
    }
    // 0x80029D70: nop

L_80029D74:
    // 0x80029D74: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80029D78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029D7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80029D80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80029D84: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80029D88: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80029D8C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80029D90: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80029D94: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80029D98: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80029D9C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80029DA0: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80029DA4: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80029DA8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80029DAC: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80029DB0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80029DB4: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80029DB8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80029DBC: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80029DC0: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80029DC4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80029DC8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80029DCC: bne         $a0, $t3, L_80029D74
    if (ctx->r4 != ctx->r11) {
        // 0x80029DD0: nop
    
            goto L_80029D74;
    }
    // 0x80029DD0: nop

L_80029DD4:
    // 0x80029DD4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80029DD8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80029DDC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80029DE0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80029DE4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80029DE8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80029DEC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80029DF0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80029DF4: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80029DF8: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80029DFC: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80029E00: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80029E04: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80029E08: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80029E0C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80029E10: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80029E14: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80029E18: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80029E1C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80029E20: bne         $a2, $t4, L_80029D54
    if (ctx->r6 != ctx->r12) {
        // 0x80029E24: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80029D54;
    }
    // 0x80029E24: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80029E28: jr          $ra
    // 0x80029E2C: nop

    return;
    // 0x80029E2C: nop

;}
RECOMP_FUNC void FUN_80029e30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029E30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80029E34: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80029E38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029E3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80029E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80029E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029E48: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80029E4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80029E50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80029E54:
    // 0x80029E54: bnel        $v0, $zero, L_80029E68
    if (ctx->r2 != 0) {
        // 0x80029E58: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80029E68;
    }
    goto skip_0;
    // 0x80029E58: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x80029E5C: b           L_80029E68
    // 0x80029E60: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_80029E68;
    // 0x80029E60: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80029E64: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80029E68:
    // 0x80029E68: bnel        $v0, $a0, L_80029E7C
    if (ctx->r2 != ctx->r4) {
        // 0x80029E6C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_80029E7C;
    }
    goto skip_1;
    // 0x80029E6C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x80029E70: b           L_80029E7C
    // 0x80029E74: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_80029E7C;
    // 0x80029E74: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80029E78: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_80029E7C:
    // 0x80029E7C: bnel        $v0, $a1, L_80029E90
    if (ctx->r2 != ctx->r5) {
        // 0x80029E80: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_80029E90;
    }
    goto skip_2;
    // 0x80029E80: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x80029E84: b           L_80029E90
    // 0x80029E88: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_80029E90;
    // 0x80029E88: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80029E8C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_80029E90:
    // 0x80029E90: bnel        $v0, $a2, L_80029EA4
    if (ctx->r2 != ctx->r6) {
        // 0x80029E94: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_80029EA4;
    }
    goto skip_3;
    // 0x80029E94: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x80029E98: b           L_80029EA4
    // 0x80029E9C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_80029EA4;
    // 0x80029E9C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80029EA0: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_80029EA4:
    // 0x80029EA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029EA8: bne         $v0, $a3, L_80029E54
    if (ctx->r2 != ctx->r7) {
        // 0x80029EAC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80029E54;
    }
    // 0x80029EAC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80029EB0: jr          $ra
    // 0x80029EB4: nop

    return;
    // 0x80029EB4: nop

;}
RECOMP_FUNC void FUN_80029eb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029EB8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80029EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029EC0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80029EC4: jal         0x80029E30
    // 0x80029EC8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80029E30)(rdram, ctx);
        goto after_0;
    // 0x80029EC8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80029ECC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80029ED0: jal         0x80029D30
    // 0x80029ED4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_1;
    // 0x80029ED4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80029ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029EDC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80029EE0: jr          $ra
    // 0x80029EE4: nop

    return;
    // 0x80029EE4: nop

;}
RECOMP_FUNC void FUN_80029ee8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029EE8: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80029EEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029EF0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80029EF4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80029EF8: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80029EFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029F00: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80029F04: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80029F08: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80029F0C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80029F10:
    // 0x80029F10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029F14: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80029F18:
    // 0x80029F18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80029F1C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80029F20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029F24: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80029F28: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80029F2C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x80029F30: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80029F34: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80029F38: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80029F3C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80029F40: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80029F44: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x80029F48: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80029F4C: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x80029F50: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80029F54: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x80029F58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80029F5C: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x80029F60: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x80029F64: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80029F68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80029F6C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80029F70: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80029F74: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80029F78: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80029F7C: swc1        $f8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f8.u32l;
    // 0x80029F80: bne         $a0, $t3, L_80029F18
    if (ctx->r4 != ctx->r11) {
        // 0x80029F84: swc1        $f18, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
            goto L_80029F18;
    }
    // 0x80029F84: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x80029F88: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80029F8C: bne         $a2, $t4, L_80029F10
    if (ctx->r6 != ctx->r12) {
        // 0x80029F90: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80029F10;
    }
    // 0x80029F90: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80029F94: jr          $ra
    // 0x80029F98: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80029F98: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80029F9C: nop

;}
RECOMP_FUNC void osViSetMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029FA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80029FA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029FA8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80029FAC: jal         0x80032660
    // 0x80029FB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x80029FB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80029FB4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80029FB8: lw          $t7, -0x512C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X512C);
    // 0x80029FBC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029FC0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80029FC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80029FC8: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x80029FCC: lw          $t9, -0x512C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X512C);
    // 0x80029FD0: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80029FD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80029FD8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80029FDC: lw          $t0, -0x512C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X512C);
    // 0x80029FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80029FE4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80029FE8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80029FEC: jal         0x800326D0
    // 0x80029FF0: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x80029FF0: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    after_1:
    // 0x80029FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029FF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002A000: jr          $ra
    // 0x8002A004: nop

    return;
    // 0x8002A004: nop

    // 0x8002A008: nop

    // 0x8002A00C: nop

;}
RECOMP_FUNC void FUN_8002a010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A010: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002A014: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002A018: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002A01C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002A020: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8002A024: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8002A028: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8002A02C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8002A030: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8002A034: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8002A038: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8002A03C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8002A040: jal         0x80029E30
    // 0x8002A044: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80029E30)(rdram, ctx);
        goto after_0;
    // 0x8002A044: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8002A048: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A04C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A050: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A054: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002A058: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002A05C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8002A060: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8002A064: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8002A068: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8002A06C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002A070: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002A074: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002A078: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A07C: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002A080: jal         0x8002FC20
    // 0x8002A084: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x8002A084: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8002A088: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8002A08C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002A090: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A094: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8002A098: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8002A09C: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8002A0A0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002A0A4: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8002A0A8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8002A0AC: nop

    // 0x8002A0B0: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8002A0B4: nop

    // 0x8002A0B8: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8002A0BC: nop

    // 0x8002A0C0: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8002A0C4: nop

    // 0x8002A0C8: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8002A0CC: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8002A0D0: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8002A0D4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002A0D8: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8002A0DC: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8002A0E0: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8002A0E4: nop

    // 0x8002A0E8: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8002A0EC: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8002A0F0: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8002A0F4: nop

    // 0x8002A0F8: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8002A0FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002A100: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x8002A104: jal         0x8002FC20
    // 0x8002A108: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x8002A108: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x8002A10C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002A110: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002A114: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A118: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002A11C: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8002A120: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8002A124: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x8002A128: nop

    // 0x8002A12C: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x8002A130: nop

    // 0x8002A134: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x8002A138: nop

    // 0x8002A13C: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x8002A140: nop

    // 0x8002A144: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x8002A148: nop

    // 0x8002A14C: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x8002A150: nop

    // 0x8002A154: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x8002A158: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8002A15C: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x8002A160: nop

    // 0x8002A164: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x8002A168: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x8002A16C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8002A170: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002A174: nop

    // 0x8002A178: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8002A17C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x8002A180: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8002A184: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8002A188: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002A18C: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x8002A190: jal         0x8002FC20
    // 0x8002A194: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x8002A194: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x8002A198: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002A19C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002A1A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002A1A4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8002A1A8: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002A1AC: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8002A1B0: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8002A1B4: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002A1B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A1BC: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x8002A1C0: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8002A1C4: nop

    // 0x8002A1C8: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8002A1CC: nop

    // 0x8002A1D0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002A1D4: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8002A1D8: swc1        $f26, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f26.u32l;
    // 0x8002A1DC: swc1        $f28, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f28.u32l;
    // 0x8002A1E0: swc1        $f30, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f30.u32l;
    // 0x8002A1E4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A1E8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002A1EC: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8002A1F0: nop

    // 0x8002A1F4: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8002A1F8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8002A1FC: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    // 0x8002A200: swc1        $f12, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f12.u32l;
    // 0x8002A204: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002A208: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x8002A20C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A210: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x8002A214: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x8002A218: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002A21C: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x8002A220: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x8002A224: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A228: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002A22C: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8002A230: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8002A234: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002A238: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8002A23C: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x8002A240: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002A244: swc1        $f22, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f22.u32l;
    // 0x8002A248: swc1        $f24, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f24.u32l;
    // 0x8002A24C: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8002A250: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002A254: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8002A258: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A25C: nop

    // 0x8002A260: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8002A264: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8002A268: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8002A26C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A270: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8002A274: nop

    // 0x8002A278: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8002A27C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002A280: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8002A284: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8002A288: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A28C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002A290: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002A294: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8002A298: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x8002A29C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x8002A2A0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A2A4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8002A2A8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8002A2AC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8002A2B0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8002A2B4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8002A2B8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8002A2BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8002A2C0: jr          $ra
    // 0x8002A2C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8002A2C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002a2c8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002a2c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A2C8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002A2CC: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8002A2D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002A2D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002A2D8: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8002A2DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002A2E0: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8002A2E4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8002A2E8: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002A2EC: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002A2F0: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8002A2F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002A2F8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8002A2FC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8002A300: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8002A304: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8002A308: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8002A30C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8002A310: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8002A314: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8002A318: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8002A31C: jal         0x8002A010
    // 0x8002A320: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8002A010)(rdram, ctx);
        goto after_0;
    // 0x8002A320: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8002A324: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8002A328: jal         0x80029D30
    // 0x8002A32C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_1;
    // 0x8002A32C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x8002A330: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A334: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8002A338: jr          $ra
    // 0x8002A33C: nop

    return;
    // 0x8002A33C: nop

    // 0x8002A340: nop

    // 0x8002A344: nop

    // 0x8002A348: nop

    // 0x8002A34C: nop

;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A684: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A688: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A68C: lbu         $s0, 0x23($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X23);
    // 0x8002A690: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A694: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8002A698: blez        $s0, L_8002A6A8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8002A69C: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_8002A6A8;
    }
    // 0x8002A69C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8002A6A0: b           L_8002A6AC
    // 0x8002A6A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002A6AC;
    // 0x8002A6A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002A6A8:
    // 0x8002A6A8: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
L_8002A6AC:
    // 0x8002A6AC: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8002A6B0: beq         $at, $zero, L_8002A6DC
    if (ctx->r1 == 0) {
        // 0x8002A6B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8002A6DC;
    }
    // 0x8002A6B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002A6B8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8002A6BC: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x8002A6C0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8002A6C4:
    // 0x8002A6C4: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A6C8: beql        $t2, $t7, L_8002A6E0
    if (ctx->r10 == ctx->r15) {
        // 0x8002A6CC: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_8002A6E0;
    }
    goto skip_0;
    // 0x8002A6CC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    skip_0:
    // 0x8002A6D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A6D4: bne         $v1, $t3, L_8002A6C4
    if (ctx->r3 != ctx->r11) {
        // 0x8002A6D8: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8002A6C4;
    }
    // 0x8002A6D8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8002A6DC:
    // 0x8002A6DC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
L_8002A6E0:
    // 0x8002A6E0: bne         $v1, $t3, L_8002A6F8
    if (ctx->r3 != ctx->r11) {
        // 0x8002A6E4: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8002A6F8;
    }
    // 0x8002A6E4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8002A6E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002A6EC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8002A6F0: b           L_8002A7B4
    // 0x8002A6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002A7B4;
    // 0x8002A6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A6F8:
    // 0x8002A6F8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8002A6FC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8002A700: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002A704: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8002A708: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x8002A70C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A710: bne         $at, $zero, L_8002A774
    if (ctx->r1 != 0) {
        // 0x8002A714: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8002A774;
    }
    // 0x8002A714: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8002A718: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8002A71C: beq         $at, $zero, L_8002A774
    if (ctx->r1 == 0) {
        // 0x8002A720: sll         $t4, $v1, 1
        ctx->r12 = S32(ctx->r3 << 1);
            goto L_8002A774;
    }
    // 0x8002A720: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x8002A724: addu        $v0, $a1, $t4
    ctx->r2 = ADD32(ctx->r5, ctx->r12);
    // 0x8002A728: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
L_8002A72C:
    // 0x8002A72C: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x8002A730: addu        $t1, $a1, $t6
    ctx->r9 = ADD32(ctx->r5, ctx->r14);
    // 0x8002A734: bnel        $t2, $t5, L_8002A758
    if (ctx->r10 != ctx->r13) {
        // 0x8002A738: lw          $t9, 0x0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X0);
            goto L_8002A758;
    }
    goto skip_1;
    // 0x8002A738: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x8002A73C: sb          $s0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r16;
    // 0x8002A740: sb          $v1, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r3;
    // 0x8002A744: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8002A748: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8002A74C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002A750: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8002A754: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
L_8002A758:
    // 0x8002A758: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A75C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002A760: slt         $at, $t9, $s1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002A764: beq         $at, $zero, L_8002A774
    if (ctx->r1 == 0) {
        // 0x8002A768: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_8002A774;
    }
    // 0x8002A768: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8002A76C: bnel        $at, $zero, L_8002A72C
    if (ctx->r1 != 0) {
        // 0x8002A770: lhu         $t5, 0x0($v0)
        ctx->r13 = MEM_HU(ctx->r2, 0X0);
            goto L_8002A72C;
    }
    goto skip_2;
    // 0x8002A770: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    skip_2:
L_8002A774:
    // 0x8002A774: bne         $v1, $t3, L_8002A798
    if (ctx->r3 != ctx->r11) {
        // 0x8002A778: sw          $a0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r4;
            goto L_8002A798;
    }
    // 0x8002A778: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    // 0x8002A77C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8002A780: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8002A784: slt         $at, $t4, $s1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002A788: beql        $at, $zero, L_8002A79C
    if (ctx->r1 == 0) {
        // 0x8002A78C: sll         $t7, $t0, 1
        ctx->r15 = S32(ctx->r8 << 1);
            goto L_8002A79C;
    }
    goto skip_3;
    // 0x8002A78C: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    skip_3:
    // 0x8002A790: b           L_8002A7B0
    // 0x8002A794: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
        goto L_8002A7B0;
    // 0x8002A794: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
L_8002A798:
    // 0x8002A798: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
L_8002A79C:
    // 0x8002A79C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8002A7A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002A7A4: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8002A7A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002A7AC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8002A7B0:
    // 0x8002A7B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A7B4:
    // 0x8002A7B4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A7B8: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A7BC: jr          $ra
    // 0x8002A7C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A7C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8002A7C4: nop

    // 0x8002A7C8: nop

    // 0x8002A7CC: nop

;}
RECOMP_FUNC void FUN_8002aa40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AA40: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8002AA44: lbu         $t7, -0x403F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X403F);
    // 0x8002AA48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AA4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8002AA50: addiu       $t6, $t6, -0x3E30
    ctx->r14 = ADD32(ctx->r14, -0X3E30);
    // 0x8002AA54: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
    // 0x8002AA58: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8002AA5C: blez        $t7, L_8002AB00
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8002AA60: sw          $zero, 0x8($sp)
        MEM_W(0X8, ctx->r29) = 0;
            goto L_8002AB00;
    }
    // 0x8002AA60: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8002AA64:
    // 0x8002AA64: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8002AA68: addiu       $t8, $sp, 0xC
    ctx->r24 = ADD32(ctx->r29, 0XC);
    // 0x8002AA6C: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8002AA70: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8002AA74: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8002AA78: lwl         $t1, 0x4($t9)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r25, 0X4);
    // 0x8002AA7C: lwr         $t1, 0x7($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X7);
    // 0x8002AA80: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8002AA84: lbu         $t2, 0xE($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XE);
    // 0x8002AA88: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x8002AA8C: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8002AA90: sb          $t4, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r12;
    // 0x8002AA94: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x8002AA98: bne         $t5, $zero, L_8002AAD4
    if (ctx->r13 != 0) {
        // 0x8002AA9C: nop
    
            goto L_8002AAD4;
    }
    // 0x8002AA9C: nop

    // 0x8002AAA0: lbu         $t6, 0x11($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X11);
    // 0x8002AAA4: lbu         $t0, 0x10($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X10);
    // 0x8002AAA8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002AAAC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8002AAB0: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x8002AAB4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002AAB8: lbu         $t9, 0x12($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X12);
    // 0x8002AABC: sb          $t9, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r25;
    // 0x8002AAC0: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8002AAC4: lbu         $t1, 0x7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7);
    // 0x8002AAC8: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x8002AACC: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x8002AAD0: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_8002AAD4:
    // 0x8002AAD4: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8002AAD8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8002AADC: lbu         $t9, -0x403F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X403F);
    // 0x8002AAE0: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8002AAE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002AAE8: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002AAEC: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x8002AAF0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8002AAF4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8002AAF8: bne         $at, $zero, L_8002AA64
    if (ctx->r1 != 0) {
        // 0x8002AAFC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8002AA64;
    }
    // 0x8002AAFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8002AB00:
    // 0x8002AB00: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x8002AB04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AB08: jr          $ra
    // 0x8002AB0C: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    return;
    // 0x8002AB0C: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002ab10(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002ab10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AB14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AB18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002AB1C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002AB20: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x8002AB24: beql        $t6, $zero, L_8002AB88
    if (ctx->r14 == 0) {
        // 0x8002AB28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002AB88;
    }
    goto skip_0;
    // 0x8002AB28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002AB2C: jal         0x8002C6A0
    // 0x8002AB30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_0;
    // 0x8002AB30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002AB34: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AB38: beq         $v0, $zero, L_8002AB84
    if (ctx->r2 == 0) {
        // 0x8002AB3C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002AB84;
    }
    // 0x8002AB3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002AB40: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8002AB44: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002AB48: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8002AB4C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8002AB50: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x8002AB54: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8002AB58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002AB5C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002AB60: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002AB64: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002AB68: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002AB6C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8002AB70: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x8002AB74: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x8002AB78: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002AB7C: jalr        $t9
    // 0x8002AB80: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002AB80: nop

    after_1:
L_8002AB84:
    // 0x8002AB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002AB88:
    // 0x8002AB88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AB8C: jr          $ra
    // 0x8002AB90: nop

    return;
    // 0x8002AB90: nop

    // 0x8002AB94: nop

    // 0x8002AB98: nop

    // 0x8002AB9C: nop

;}
RECOMP_FUNC void FUN_8002aba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ABA0: mfc0        $t0, EntryHi
    ctx->r8 = cop0_register_read(ctx, 10);
    // 0x8002ABA4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8002ABA8: addiu       $at, $zero, -0x2000
    ctx->r1 = ADD32(0, -0X2000);
    // 0x8002ABAC: and         $t2, $a0, $at
    ctx->r10 = ctx->r4 & ctx->r1;
    // 0x8002ABB0: or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // 0x8002ABB4: mtc0        $t1, EntryHi
    cop0_register_write(ctx, 10, ctx->r9);    // 0x8002ABB8: nop

    // 0x8002ABBC: nop

    // 0x8002ABC0: nop

    // 0x8002ABC4: tlbp

    // 0x8002ABC8: nop

    // 0x8002ABCC: nop

    // 0x8002ABD0: mfc0        $t3, Index
    ctx->r11 = cop0_register_read(ctx, 0);
    // 0x8002ABD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002ABD8: and         $t3, $t3, $at
    ctx->r11 = ctx->r11 & ctx->r1;
    // 0x8002ABDC: bne         $t3, $zero, L_8002AC48
    if (ctx->r11 != 0) {
        // 0x8002ABE0: nop
    
            goto L_8002AC48;
    }
    // 0x8002ABE0: nop

    // 0x8002ABE4: tlbr

    // 0x8002ABE8: nop

    // 0x8002ABEC: nop

    // 0x8002ABF0: nop

    // 0x8002ABF4: mfc0        $t3, PageMask
    ctx->r11 = cop0_register_read(ctx, 5);
    // 0x8002ABF8: addi        $t3, $t3, 0x2000
    ctx->r11 = ADD32(ctx->r11, 0X2000);
    // 0x8002ABFC: srl         $t3, $t3, 1
    ctx->r11 = S32(U32(ctx->r11) >> 1);
    // 0x8002AC00: and         $t4, $t3, $a0
    ctx->r12 = ctx->r11 & ctx->r4;
    // 0x8002AC04: bne         $t4, $zero, L_8002AC18
    if (ctx->r12 != 0) {
        // 0x8002AC08: addi        $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_8002AC18;
    }
    // 0x8002AC08: addi        $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8002AC0C: mfc0        $v0, EntryLo0
    ctx->r2 = cop0_register_read(ctx, 2);
    // 0x8002AC10: b           L_8002AC1C
    // 0x8002AC14: nop

        goto L_8002AC1C;
    // 0x8002AC14: nop

L_8002AC18:
    // 0x8002AC18: mfc0        $v0, EntryLo1
    ctx->r2 = cop0_register_read(ctx, 3);
L_8002AC1C:
    // 0x8002AC1C: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x8002AC20: beq         $t5, $zero, L_8002AC48
    if (ctx->r13 == 0) {
        // 0x8002AC24: nop
    
            goto L_8002AC48;
    }
    // 0x8002AC24: nop

    // 0x8002AC28: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x8002AC2C: ori         $at, $at, 0xFFC0
    ctx->r1 = ctx->r1 | 0XFFC0;
    // 0x8002AC30: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8002AC34: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x8002AC38: and         $t5, $a0, $t3
    ctx->r13 = ctx->r4 & ctx->r11;
    // 0x8002AC3C: add         $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x8002AC40: b           L_8002AC4C
    // 0x8002AC44: nop

        goto L_8002AC4C;
    // 0x8002AC44: nop

L_8002AC48:
    // 0x8002AC48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002AC4C:
    // 0x8002AC4C: mtc0        $t0, EntryHi
    cop0_register_write(ctx, 10, ctx->r8);    // 0x8002AC50: jr          $ra
    // 0x8002AC54: nop

    return;
    // 0x8002AC54: nop

    // 0x8002AC58: nop

    // 0x8002AC5C: nop

;}
RECOMP_FUNC void osCreatePiManager(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AC60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002AC64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002AC68: lui         $s0, 0x8005
    ctx->r16 = S32(0X8005 << 16);
    // 0x8002AC6C: addiu       $s0, $s0, -0x54F0
    ctx->r16 = ADD32(ctx->r16, -0X54F0);
    // 0x8002AC70: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8002AC74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002AC78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002AC7C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002AC80: bne         $t6, $zero, L_8002ADBC
    if (ctx->r14 != 0) {
        // 0x8002AC84: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8002ADBC;
    }
    // 0x8002AC84: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002AC88: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002AC8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8002AC90: jal         0x80030610
    // 0x8002AC94: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_0;
    // 0x8002AC94: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8002AC98: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002AC9C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8002ACA0: addiu       $a1, $a1, -0x2B38
    ctx->r5 = ADD32(ctx->r5, -0X2B38);
    // 0x8002ACA4: addiu       $a0, $a0, -0x2B50
    ctx->r4 = ADD32(ctx->r4, -0X2B50);
    // 0x8002ACA8: jal         0x80030610
    // 0x8002ACAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_1;
    // 0x8002ACAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8002ACB0: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8002ACB4: lw          $t7, -0x54C0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X54C0);
    // 0x8002ACB8: bne         $t7, $zero, L_8002ACC8
    if (ctx->r15 != 0) {
        // 0x8002ACBC: nop
    
            goto L_8002ACC8;
    }
    // 0x8002ACBC: nop

    // 0x8002ACC0: jal         0x8002ADD0
    // 0x8002ACC4: nop

    LOOKUP_FUNC(0x8002ADD0)(rdram, ctx);
        goto after_2;
    // 0x8002ACC4: nop

    after_2:
L_8002ACC8:
    // 0x8002ACC8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8002ACCC: lui         $a2, 0x2222
    ctx->r6 = S32(0X2222 << 16);
    // 0x8002ACD0: ori         $a2, $a2, 0x2222
    ctx->r6 = ctx->r6 | 0X2222;
    // 0x8002ACD4: addiu       $a1, $a1, -0x2B50
    ctx->r5 = ADD32(ctx->r5, -0X2B50);
    // 0x8002ACD8: jal         0x8002FB60
    // 0x8002ACDC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_3;
    // 0x8002ACDC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x8002ACE0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002ACE4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8002ACE8: jal         0x80030C40
    // 0x8002ACEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80030C40)(rdram, ctx);
        goto after_4;
    // 0x8002ACEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8002ACF0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8002ACF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002ACF8: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002ACFC: beq         $at, $zero, L_8002AD0C
    if (ctx->r1 == 0) {
        // 0x8002AD00: or          $a1, $t9, $zero
        ctx->r5 = ctx->r25 | 0;
            goto L_8002AD0C;
    }
    // 0x8002AD00: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002AD04: jal         0x80030B60
    // 0x8002AD08: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80030B60)(rdram, ctx);
        goto after_5;
    // 0x8002AD08: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_5:
L_8002AD0C:
    // 0x8002AD0C: jal         0x80032660
    // 0x8002AD10: nop

    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_6;
    // 0x8002AD10: nop

    after_6:
    // 0x8002AD14: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8002AD18: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002AD1C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002AD20: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8002AD24: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8002AD28: lui         $t4, 0x8003
    ctx->r12 = S32(0X8003 << 16);
    // 0x8002AD2C: lui         $t5, 0x8003
    ctx->r13 = S32(0X8003 << 16);
    // 0x8002AD30: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8002AD34: addiu       $a0, $a0, -0x3D00
    ctx->r4 = ADD32(ctx->r4, -0X3D00);
    // 0x8002AD38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002AD3C: addiu       $t2, $t2, -0x2B50
    ctx->r10 = ADD32(ctx->r10, -0X2B50);
    // 0x8002AD40: addiu       $t3, $t3, -0x2B28
    ctx->r11 = ADD32(ctx->r11, -0X2B28);
    // 0x8002AD44: addiu       $t4, $t4, -0x4D50
    ctx->r12 = ADD32(ctx->r12, -0X4D50);
    // 0x8002AD48: addiu       $t5, $t5, 0xE10
    ctx->r13 = ADD32(ctx->r13, 0XE10);
    // 0x8002AD4C: addiu       $t6, $t6, -0x2B50
    ctx->r14 = ADD32(ctx->r14, -0X2B50);
    // 0x8002AD50: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002AD54: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8002AD58: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8002AD5C: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x8002AD60: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x8002AD64: sw          $t3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r11;
    // 0x8002AD68: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
    // 0x8002AD6C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
    // 0x8002AD70: addiu       $a2, $a2, -0x5160
    ctx->r6 = ADD32(ctx->r6, -0X5160);
    // 0x8002AD74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002AD78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002AD7C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002AD80: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x8002AD84: jal         0x80028260
    // 0x8002AD88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_7;
    // 0x8002AD88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_7:
    // 0x8002AD8C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002AD90: jal         0x80034C90
    // 0x8002AD94: addiu       $a0, $a0, -0x3D00
    ctx->r4 = ADD32(ctx->r4, -0X3D00);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_8;
    // 0x8002AD94: addiu       $a0, $a0, -0x3D00
    ctx->r4 = ADD32(ctx->r4, -0X3D00);
    after_8:
    // 0x8002AD98: jal         0x800326D0
    // 0x8002AD9C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_9;
    // 0x8002AD9C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x8002ADA0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002ADA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002ADA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002ADAC: beql        $t8, $at, L_8002ADC0
    if (ctx->r24 == ctx->r1) {
        // 0x8002ADB0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8002ADC0;
    }
    goto skip_0;
    // 0x8002ADB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8002ADB4: jal         0x80030B60
    // 0x8002ADB8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    LOOKUP_FUNC(0x80030B60)(rdram, ctx);
        goto after_10;
    // 0x8002ADB8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_10:
L_8002ADBC:
    // 0x8002ADBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002ADC0:
    // 0x8002ADC0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002ADC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002ADC8: jr          $ra
    // 0x8002ADCC: nop

    return;
    // 0x8002ADCC: nop

;}
RECOMP_FUNC void FUN_8002add0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ADD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002ADD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ADD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002ADDC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002ADE0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002ADE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8002ADE8: sw          $t6, -0x54C0($at)
    MEM_W(-0X54C0, ctx->r1) = ctx->r14;
    // 0x8002ADEC: addiu       $a1, $a1, -0x2B30
    ctx->r5 = ADD32(ctx->r5, -0X2B30);
    // 0x8002ADF0: addiu       $a0, $a0, -0x2B28
    ctx->r4 = ADD32(ctx->r4, -0X2B28);
    // 0x8002ADF4: jal         0x80030610
    // 0x8002ADF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_0;
    // 0x8002ADF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8002ADFC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002AE00: addiu       $a0, $a0, -0x2B28
    ctx->r4 = ADD32(ctx->r4, -0X2B28);
    // 0x8002AE04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002AE08: jal         0x80026300
    // 0x8002AE0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_1;
    // 0x8002AE0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8002AE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AE18: jr          $ra
    // 0x8002AE1C: nop

    return;
    // 0x8002AE1C: nop

;}
RECOMP_FUNC void FUN_8002ae20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AE20: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8002AE24: lw          $t6, -0x54C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54C0);
    // 0x8002AE28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002AE2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AE30: bne         $t6, $zero, L_8002AE40
    if (ctx->r14 != 0) {
        // 0x8002AE34: nop
    
            goto L_8002AE40;
    }
    // 0x8002AE34: nop

    // 0x8002AE38: jal         0x8002ADD0
    // 0x8002AE3C: nop

    LOOKUP_FUNC(0x8002ADD0)(rdram, ctx);
        goto after_0;
    // 0x8002AE3C: nop

    after_0:
L_8002AE40:
    // 0x8002AE40: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002AE44: addiu       $a0, $a0, -0x2B28
    ctx->r4 = ADD32(ctx->r4, -0X2B28);
    // 0x8002AE48: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8002AE4C: jal         0x800266B0
    // 0x8002AE50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_1;
    // 0x8002AE50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8002AE54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AE58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002AE5C: jr          $ra
    // 0x8002AE60: nop

    return;
    // 0x8002AE60: nop

;}
RECOMP_FUNC void FUN_8002ae64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AE64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AE6C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002AE70: addiu       $a0, $a0, -0x2B28
    ctx->r4 = ADD32(ctx->r4, -0X2B28);
    // 0x8002AE74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002AE78: jal         0x80026300
    // 0x8002AE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_0;
    // 0x8002AE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AE88: jr          $ra
    // 0x8002AE8C: nop

    return;
    // 0x8002AE8C: nop

    // 0x8002AE90: nop

    // 0x8002AE94: nop

    // 0x8002AE98: nop

    // 0x8002AE9C: nop

;}
RECOMP_FUNC void __osDevMgrMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AEA0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002AEA4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002AEA8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002AEAC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002AEB0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002AEB4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002AEB8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002AEBC: lui         $s3, 0x500
    ctx->r19 = S32(0X500 << 16);
    // 0x8002AEC0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8002AEC4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002AEC8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002AECC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002AED0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002AED4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8002AED8: ori         $s3, $s3, 0x510
    ctx->r19 = ctx->r19 | 0X510;
    // 0x8002AEDC: addiu       $s5, $zero, 0x24
    ctx->r21 = ADD32(0, 0X24);
    // 0x8002AEE0: addiu       $s6, $sp, 0x70
    ctx->r22 = ADD32(ctx->r29, 0X70);
    // 0x8002AEE4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8002AEE8: addiu       $fp, $zero, 0x1D
    ctx->r30 = ADD32(0, 0X1D);
L_8002AEEC:
    // 0x8002AEEC: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
L_8002AEF0:
    // 0x8002AEF0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8002AEF4: jal         0x800266B0
    // 0x8002AEF8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_0;
    // 0x8002AEF8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x8002AEFC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8002AF00: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8002AF04: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x8002AF08: beql        $a0, $zero, L_8002B110
    if (ctx->r4 == 0) {
        // 0x8002AF0C: lhu         $t1, 0x0($t0)
        ctx->r9 = MEM_HU(ctx->r8, 0X0);
            goto L_8002B110;
    }
    goto skip_0;
    // 0x8002AF0C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    skip_0:
    // 0x8002AF10: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x8002AF14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002AF18: bnel        $t7, $at, L_8002B110
    if (ctx->r15 != ctx->r1) {
        // 0x8002AF1C: lhu         $t1, 0x0($t0)
        ctx->r9 = MEM_HU(ctx->r8, 0X0);
            goto L_8002B110;
    }
    goto skip_1;
    // 0x8002AF1C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    skip_1:
    // 0x8002AF20: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8002AF24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AF28: addiu       $s0, $a0, 0x14
    ctx->r16 = ADD32(ctx->r4, 0X14);
    // 0x8002AF2C: beq         $v0, $zero, L_8002AF3C
    if (ctx->r2 == 0) {
        // 0x8002AF30: addiu       $a1, $sp, 0x6C
        ctx->r5 = ADD32(ctx->r29, 0X6C);
            goto L_8002AF3C;
    }
    // 0x8002AF30: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8002AF34: bnel        $v0, $at, L_8002B110
    if (ctx->r2 != ctx->r1) {
        // 0x8002AF38: lhu         $t1, 0x0($t0)
        ctx->r9 = MEM_HU(ctx->r8, 0X0);
            goto L_8002B110;
    }
    goto skip_2;
    // 0x8002AF38: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    skip_2:
L_8002AF3C:
    // 0x8002AF3C: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
    // 0x8002AF40: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x8002AF44: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8002AF48: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002AF4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002AF50: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x8002AF54: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002AF58: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8002AF5C: mflo        $t9
    ctx->r25 = lo;
    // 0x8002AF60: addu        $s1, $s0, $t9
    ctx->r17 = ADD32(ctx->r16, ctx->r25);
    // 0x8002AF64: beq         $v0, $at, L_8002AF80
    if (ctx->r2 == ctx->r1) {
        // 0x8002AF68: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_8002AF80;
    }
    // 0x8002AF68: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8002AF6C: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x8002AF70: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x8002AF74: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8002AF78: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x8002AF7C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
L_8002AF80:
    // 0x8002AF80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002AF84: bne         $v0, $at, L_8002AFA4
    if (ctx->r2 != ctx->r1) {
        // 0x8002AF88: lw          $t4, 0x74($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X74);
            goto L_8002AFA4;
    }
    // 0x8002AF88: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8002AF8C: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x8002AF90: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x8002AF94: bne         $t6, $zero, L_8002AFA4
    if (ctx->r14 != 0) {
        // 0x8002AF98: nop
    
            goto L_8002AFA4;
    }
    // 0x8002AF98: nop

    // 0x8002AF9C: b           L_8002AFA4
    // 0x8002AFA0: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
        goto L_8002AFA4;
    // 0x8002AFA0: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_8002AFA4:
    // 0x8002AFA4: jal         0x800266B0
    // 0x8002AFA8: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_1;
    // 0x8002AFA8: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    after_1:
    // 0x8002AFAC: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8002AFB0: jal         0x80031B60
    // 0x8002AFB4: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    LOOKUP_FUNC(0x80031B60)(rdram, ctx);
        goto after_2;
    // 0x8002AFB4: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    after_2:
    // 0x8002AFB8: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8002AFBC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8002AFC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002AFC4: or          $t8, $a2, $at
    ctx->r24 = ctx->r6 | ctx->r1;
    // 0x8002AFC8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002AFCC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002AFD0: jal         0x80034400
    // 0x8002AFD4: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    LOOKUP_FUNC(0x80034400)(rdram, ctx);
        goto after_3;
    // 0x8002AFD4: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    after_3:
L_8002AFD8:
    // 0x8002AFD8: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x8002AFDC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8002AFE0: jal         0x800266B0
    // 0x8002AFE4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_4;
    // 0x8002AFE4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_4:
    // 0x8002AFE8: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8002AFEC: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x8002AFF0: addiu       $s0, $a0, 0x14
    ctx->r16 = ADD32(ctx->r4, 0X14);
    // 0x8002AFF4: lhu         $t0, 0x6($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6);
    // 0x8002AFF8: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002AFFC: mflo        $t1
    ctx->r9 = lo;
    // 0x8002B000: addu        $s1, $s0, $t1
    ctx->r17 = ADD32(ctx->r16, ctx->r9);
    // 0x8002B004: lw          $t2, 0x18($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X18);
    // 0x8002B008: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8002B00C: bnel        $fp, $t2, L_8002B0AC
    if (ctx->r30 != ctx->r10) {
        // 0x8002B010: lw          $a1, 0x74($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X74);
            goto L_8002B0AC;
    }
    goto skip_3;
    // 0x8002B010: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    skip_3:
    // 0x8002B014: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8002B018: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8002B01C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002B020: or          $t3, $a2, $at
    ctx->r11 = ctx->r6 | ctx->r1;
    // 0x8002B024: jal         0x80034400
    // 0x8002B028: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    LOOKUP_FUNC(0x80034400)(rdram, ctx);
        goto after_5;
    // 0x8002B028: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_5:
    // 0x8002B02C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8002B030: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002B034: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8002B038: jal         0x80034400
    // 0x8002B03C: lw          $a0, 0x14($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X14);
    LOOKUP_FUNC(0x80034400)(rdram, ctx);
        goto after_6;
    // 0x8002B03C: lw          $a0, 0x14($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X14);
    after_6:
    // 0x8002B040: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8002B044: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8002B048: ori         $a1, $a1, 0x508
    ctx->r5 = ctx->r5 | 0X508;
    // 0x8002B04C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8002B050: jal         0x80030C60
    // 0x8002B054: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    LOOKUP_FUNC(0x80030C60)(rdram, ctx);
        goto after_7;
    // 0x8002B054: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    after_7:
    // 0x8002B058: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8002B05C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8002B060: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002B064: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8002B068: bgezl       $t7, L_8002B08C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8002B06C: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8002B08C;
    }
    goto skip_4;
    // 0x8002B06C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    skip_4:
    // 0x8002B070: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8002B074: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8002B078: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x8002B07C: or          $t9, $a2, $at
    ctx->r25 = ctx->r6 | ctx->r1;
    // 0x8002B080: jal         0x80034400
    // 0x8002B084: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(0x80034400)(rdram, ctx);
        goto after_8;
    // 0x8002B084: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x8002B088: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_8002B08C:
    // 0x8002B08C: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x8002B090: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8002B094: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x8002B098: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8002B09C: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x8002B0A0: jal         0x80031620
    // 0x8002B0A4: ori         $a0, $a0, 0xC01
    ctx->r4 = ctx->r4 | 0XC01;
    LOOKUP_FUNC(0x80031620)(rdram, ctx);
        goto after_9;
    // 0x8002B0A4: ori         $a0, $a0, 0xC01
    ctx->r4 = ctx->r4 | 0XC01;
    after_9:
    // 0x8002B0A8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
L_8002B0AC:
    // 0x8002B0AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B0B0: jal         0x80026300
    // 0x8002B0B4: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_10;
    // 0x8002B0B4: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    after_10:
    // 0x8002B0B8: bne         $s2, $s7, L_8002B0D8
    if (ctx->r18 != ctx->r23) {
        // 0x8002B0BC: lw          $t4, 0x74($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X74);
            goto L_8002B0D8;
    }
    // 0x8002B0BC: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8002B0C0: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x8002B0C4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8002B0C8: bnel        $t6, $zero, L_8002B0DC
    if (ctx->r14 != 0) {
        // 0x8002B0CC: lw          $a0, 0x10($s4)
        ctx->r4 = MEM_W(ctx->r20, 0X10);
            goto L_8002B0DC;
    }
    goto skip_5;
    // 0x8002B0CC: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    skip_5:
    // 0x8002B0D0: b           L_8002AFD8
    // 0x8002B0D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8002AFD8;
    // 0x8002B0D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8002B0D8:
    // 0x8002B0D8: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
L_8002B0DC:
    // 0x8002B0DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002B0E0: jal         0x80026300
    // 0x8002B0E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_11;
    // 0x8002B0E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8002B0E8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8002B0EC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8002B0F0: lhu         $t9, 0x1A($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1A);
    // 0x8002B0F4: bnel        $s7, $t9, L_8002AEF0
    if (ctx->r23 != ctx->r25) {
        // 0x8002B0F8: lw          $a0, 0x8($s4)
        ctx->r4 = MEM_W(ctx->r20, 0X8);
            goto L_8002AEF0;
    }
    goto skip_6;
    // 0x8002B0F8: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    skip_6:
    // 0x8002B0FC: jal         0x80033CD0
    // 0x8002B100: nop

    LOOKUP_FUNC(0x80033CD0)(rdram, ctx);
        goto after_12;
    // 0x8002B100: nop

    after_12:
    // 0x8002B104: b           L_8002AEF0
    // 0x8002B108: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
        goto L_8002AEF0;
    // 0x8002B108: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8002B10C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
L_8002B110:
    // 0x8002B110: addiu       $t2, $t1, -0xA
    ctx->r10 = ADD32(ctx->r9, -0XA);
    // 0x8002B114: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x8002B118: beq         $at, $zero, L_8002B238
    if (ctx->r1 == 0) {
        // 0x8002B11C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8002B238;
    }
    // 0x8002B11C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002B120: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002B124: addu        $at, $at, $t2
    gpr jr_addend_8002B12C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8002B128: lw          $t2, -0x2CB0($at)
    ctx->r10 = ADD32(ctx->r1, -0X2CB0);
    // 0x8002B12C: jr          $t2
    // 0x8002B130: nop

    switch (jr_addend_8002B12C >> 2) {
        case 0: goto L_8002B21C; break;
        case 1: goto L_8002B134; break;
        case 2: goto L_8002B168; break;
        case 3: goto L_8002B238; break;
        case 4: goto L_8002B238; break;
        case 5: goto L_8002B19C; break;
        case 6: goto L_8002B1DC; break;
        default: switch_error(__func__, 0x8002B12C, 0x8004D350);
    }
    // 0x8002B130: nop

L_8002B134:
    // 0x8002B134: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x8002B138: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8002B13C: jal         0x800266B0
    // 0x8002B140: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_13;
    // 0x8002B140: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_13:
    // 0x8002B144: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8002B148: lw          $t9, 0x14($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X14);
    // 0x8002B14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002B150: lw          $a1, 0xC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC);
    // 0x8002B154: lw          $a2, 0x8($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X8);
    // 0x8002B158: jalr        $t9
    // 0x8002B15C: lw          $a3, 0x10($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X10);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x8002B15C: lw          $a3, 0x10($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X10);
    after_14:
    // 0x8002B160: b           L_8002B23C
    // 0x8002B164: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8002B23C;
    // 0x8002B164: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B168:
    // 0x8002B168: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x8002B16C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8002B170: jal         0x800266B0
    // 0x8002B174: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_15;
    // 0x8002B174: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_15:
    // 0x8002B178: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8002B17C: lw          $t9, 0x14($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X14);
    // 0x8002B180: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8002B184: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    // 0x8002B188: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x8002B18C: jalr        $t9
    // 0x8002B190: lw          $a3, 0x10($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X10);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_16;
    // 0x8002B190: lw          $a3, 0x10($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X10);
    after_16:
    // 0x8002B194: b           L_8002B23C
    // 0x8002B198: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8002B23C;
    // 0x8002B198: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B19C:
    // 0x8002B19C: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x8002B1A0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8002B1A4: jal         0x800266B0
    // 0x8002B1A8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_17;
    // 0x8002B1A8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_17:
    // 0x8002B1AC: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8002B1B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002B1B4: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x8002B1B8: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x8002B1BC: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    // 0x8002B1C0: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x8002B1C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002B1C8: lw          $t9, 0x18($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X18);
    // 0x8002B1CC: jalr        $t9
    // 0x8002B1D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_18;
    // 0x8002B1D0: nop

    after_18:
    // 0x8002B1D4: b           L_8002B23C
    // 0x8002B1D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8002B23C;
    // 0x8002B1D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B1DC:
    // 0x8002B1DC: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x8002B1E0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8002B1E4: jal         0x800266B0
    // 0x8002B1E8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_19;
    // 0x8002B1E8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_19:
    // 0x8002B1EC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8002B1F0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8002B1F4: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8002B1F8: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x8002B1FC: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    // 0x8002B200: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x8002B204: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002B208: lw          $t9, 0x18($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X18);
    // 0x8002B20C: jalr        $t9
    // 0x8002B210: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_20;
    // 0x8002B210: nop

    after_20:
    // 0x8002B214: b           L_8002B23C
    // 0x8002B218: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8002B23C;
    // 0x8002B218: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B21C:
    // 0x8002B21C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8002B220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B224: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8002B228: jal         0x80026300
    // 0x8002B22C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_21;
    // 0x8002B22C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    after_21:
    // 0x8002B230: b           L_8002B23C
    // 0x8002B234: nop

        goto L_8002B23C;
    // 0x8002B234: nop

L_8002B238:
    // 0x8002B238: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_8002B23C:
    // 0x8002B23C: bne         $s0, $zero, L_8002AEEC
    if (ctx->r16 != 0) {
        // 0x8002B240: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_8002AEEC;
    }
    // 0x8002B240: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8002B244: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x8002B248: jal         0x800266B0
    // 0x8002B24C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_22;
    // 0x8002B24C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_22:
    // 0x8002B250: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8002B254: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B258: jal         0x80026300
    // 0x8002B25C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_23;
    // 0x8002B25C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    after_23:
    // 0x8002B260: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x8002B264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002B268: jal         0x80026300
    // 0x8002B26C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_24;
    // 0x8002B26C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x8002B270: b           L_8002AEF0
    // 0x8002B274: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
        goto L_8002AEF0;
    // 0x8002B274: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8002B278: nop

    // 0x8002B27C: nop

    // 0x8002B280: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002B284: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002B288: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002B28C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002B290: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B294: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002B298: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002B29C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002B2A0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B2A4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002B2A8: jr          $ra
    // 0x8002B2AC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8002B2AC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void FUN_8002b380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002B38C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002B390: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x8002B394: beql        $t6, $zero, L_8002B3F8
    if (ctx->r14 == 0) {
        // 0x8002B398: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002B3F8;
    }
    goto skip_0;
    // 0x8002B398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002B39C: jal         0x8002C6A0
    // 0x8002B3A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_0;
    // 0x8002B3A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002B3A4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B3A8: beq         $v0, $zero, L_8002B3F4
    if (ctx->r2 == 0) {
        // 0x8002B3AC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002B3F4;
    }
    // 0x8002B3AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002B3B0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8002B3B4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002B3B8: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8002B3BC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8002B3C0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x8002B3C4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8002B3C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002B3CC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002B3D0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002B3D4: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x8002B3D8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002B3DC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x8002B3E0: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x8002B3E4: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x8002B3E8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002B3EC: jalr        $t9
    // 0x8002B3F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002B3F0: nop

    after_1:
L_8002B3F4:
    // 0x8002B3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002B3F8:
    // 0x8002B3F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B3FC: jr          $ra
    // 0x8002B400: nop

    return;
    // 0x8002B400: nop

    // 0x8002B404: nop

    // 0x8002B408: nop

    // 0x8002B40C: nop

;}
RECOMP_FUNC void FUN_8002b410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B410: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002B414: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002B418: blez        $a1, L_8002B474
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002B41C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8002B474;
    }
    // 0x8002B41C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B420: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x8002B424: beq         $a3, $zero, L_8002B448
    if (ctx->r7 == 0) {
        // 0x8002B428: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8002B448;
    }
    // 0x8002B428: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8002B42C:
    // 0x8002B42C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8002B430: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002B434: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B438: bne         $a0, $a2, L_8002B42C
    if (ctx->r4 != ctx->r6) {
        // 0x8002B43C: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_8002B42C;
    }
    // 0x8002B43C: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8002B440: beql        $a2, $a1, L_8002B478
    if (ctx->r6 == ctx->r5) {
        // 0x8002B444: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8002B478;
    }
    goto skip_0;
    // 0x8002B444: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
L_8002B448:
    // 0x8002B448: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8002B44C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8002B450: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8002B454: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8002B458: lbu         $t0, 0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3);
    // 0x8002B45C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8002B460: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8002B464: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x8002B468: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002B46C: bne         $a2, $a1, L_8002B448
    if (ctx->r6 != ctx->r5) {
        // 0x8002B470: addu        $v1, $v1, $t0
        ctx->r3 = ADD32(ctx->r3, ctx->r8);
            goto L_8002B448;
    }
    // 0x8002B470: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_8002B474:
    // 0x8002B474: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8002B478:
    // 0x8002B478: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x8002B47C: jr          $ra
    // 0x8002B480: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8002B480: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B484: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8002B488: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8002B48C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8002B490: addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
    // 0x8002B494: addiu       $t1, $a3, 0x2
    ctx->r9 = ADD32(ctx->r7, 0X2);
    // 0x8002B498: addu        $t8, $zero, $v0
    ctx->r24 = ADD32(0, ctx->r2);
    // 0x8002B49C: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002B4A0: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x8002B4A4: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8002B4A8: addiu       $t2, $a3, 0x4
    ctx->r10 = ADD32(ctx->r7, 0X4);
    // 0x8002B4AC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B4B0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8002B4B4: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8002B4B8: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8002B4BC: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x8002B4C0: addiu       $t3, $a3, 0x6
    ctx->r11 = ADD32(ctx->r7, 0X6);
    // 0x8002B4C4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8002B4C8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002B4CC: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x8002B4D0: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8002B4D4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8002B4D8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B4DC: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_8002B4E0:
    // 0x8002B4E0: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x8002B4E4: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8002B4E8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8002B4EC: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8002B4F0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8002B4F4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002B4F8: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x8002B4FC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8002B500: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002B504: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B508: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8002B50C: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8002B510: lhu         $v0, -0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, -0X8);
    // 0x8002B514: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x8002B518: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x8002B51C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8002B520: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002B524: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x8002B528: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8002B52C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B530: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8002B534: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8002B538: lhu         $v0, -0x8($t2)
    ctx->r2 = MEM_HU(ctx->r10, -0X8);
    // 0x8002B53C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8002B540: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002B544: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x8002B548: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8002B54C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B550: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8002B554: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8002B558: lhu         $v0, -0x8($t3)
    ctx->r2 = MEM_HU(ctx->r11, -0X8);
    // 0x8002B55C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8002B560: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002B564: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x8002B568: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8002B56C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B570: bne         $v1, $a0, L_8002B4E0
    if (ctx->r3 != ctx->r4) {
        // 0x8002B574: sh          $t6, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r14;
            goto L_8002B4E0;
    }
    // 0x8002B574: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8002B578: jr          $ra
    // 0x8002B57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002B57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void FUN_8002bf90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BF90: mfc0        $v0, Count
    ctx->r2 = cop0_register_read(ctx, 9);
    // 0x8002BF94: jr          $ra
    // 0x8002BF98: nop

    return;
    // 0x8002BF98: nop

    // 0x8002BF9C: nop

;}
RECOMP_FUNC void FUN_8002c1d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C1D0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002C1D4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002C1D8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002C1DC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002C1E0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002C1E4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002C1E8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002C1EC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002C1F0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002C1F4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002C1F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002C1FC: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x8002C200: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8002C204: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8002C208: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x8002C20C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8002C210: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x8002C214: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x8002C218: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x8002C21C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x8002C220: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x8002C224: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x8002C228: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8002C22C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8002C230: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x8002C234: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x8002C238: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002C23C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C244: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002C248: jal         0x80034A10
    // 0x8002C24C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_0;
    // 0x8002C24C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x8002C250: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8002C254: jal         0x8002CFB0
    // 0x8002C258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8002CFB0)(rdram, ctx);
        goto after_1;
    // 0x8002C258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8002C25C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C260: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x8002C264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C268: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x8002C26C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002C270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C274: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8002C278: jal         0x80034A10
    // 0x8002C27C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_2;
    // 0x8002C27C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8002C280: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002C284: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x8002C288: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x8002C28C: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x8002C290: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8002C294: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002C298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C29C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C2A0: jal         0x80034A10
    // 0x8002C2A4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_3;
    // 0x8002C2A4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x8002C2A8: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x8002C2AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002C2B0: jal         0x8002CF08
    // 0x8002C2B4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    LOOKUP_FUNC(0x8002CF08)(rdram, ctx);
        goto after_4;
    // 0x8002C2B4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_4:
    // 0x8002C2B8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8002C2BC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002C2C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C2C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C2C8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8002C2CC: jal         0x80034A10
    // 0x8002C2D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_5;
    // 0x8002C2D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8002C2D4: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x8002C2D8: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x8002C2DC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8002C2E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002C2E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C2E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C2EC: jal         0x80034A10
    // 0x8002C2F0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_6;
    // 0x8002C2F0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x8002C2F4: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x8002C2F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002C2FC: jal         0x8002CF5C
    // 0x8002C300: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    LOOKUP_FUNC(0x8002CF5C)(rdram, ctx);
        goto after_7;
    // 0x8002C300: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_7:
    // 0x8002C304: lbu         $t7, 0x1C($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1C);
    // 0x8002C308: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002C30C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x8002C310: beq         $t7, $zero, L_8002C32C
    if (ctx->r15 == 0) {
        // 0x8002C314: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8002C32C;
    }
    // 0x8002C314: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8002C318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C31C: jal         0x80034E40
    // 0x8002C320: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80034E40)(rdram, ctx);
        goto after_8;
    // 0x8002C320: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x8002C324: b           L_8002C33C
    // 0x8002C328: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
        goto L_8002C33C;
    // 0x8002C328: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_8002C32C:
    // 0x8002C32C: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x8002C330: jal         0x8002D000
    // 0x8002C334: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    LOOKUP_FUNC(0x8002D000)(rdram, ctx);
        goto after_9;
    // 0x8002C334: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    after_9:
    // 0x8002C338: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_8002C33C:
    // 0x8002C33C: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x8002C340: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x8002C344: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x8002C348: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x8002C34C: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x8002C350: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x8002C354: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x8002C358: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002C35C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C364: jal         0x80034A10
    // 0x8002C368: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_10;
    // 0x8002C368: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x8002C36C: lw          $t9, 0x4($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X4);
    // 0x8002C370: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002C374: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002C378: blez        $t9, L_8002C438
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002C37C: addiu       $a1, $s6, 0x4
        ctx->r5 = ADD32(ctx->r22, 0X4);
            goto L_8002C438;
    }
    // 0x8002C37C: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x8002C380: addiu       $s1, $v0, 0x8C
    ctx->r17 = ADD32(ctx->r2, 0X8C);
    // 0x8002C384: addiu       $s2, $v0, 0x58
    ctx->r18 = ADD32(ctx->r2, 0X58);
    // 0x8002C388: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x8002C38C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
L_8002C390:
    // 0x8002C390: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002C394: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x8002C398: jal         0x800268C0
    // 0x8002C39C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_11;
    // 0x8002C39C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8002C3A0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8002C3A4: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x8002C3A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002C3AC: jal         0x8002CDD4
    // 0x8002C3B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x8002CDD4)(rdram, ctx);
        goto after_12;
    // 0x8002C3B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x8002C3B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002C3B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C3BC: jal         0x8002F010
    // 0x8002C3C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8002F010)(rdram, ctx);
        goto after_13;
    // 0x8002C3C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x8002C3C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002C3C8: jal         0x8002CE7C
    // 0x8002C3CC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    LOOKUP_FUNC(0x8002CE7C)(rdram, ctx);
        goto after_14;
    // 0x8002C3CC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x8002C3D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002C3D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C3D8: jal         0x8002EB40
    // 0x8002C3DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8002EB40)(rdram, ctx);
        goto after_15;
    // 0x8002C3DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x8002C3E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002C3E4: jal         0x8002CD2C
    // 0x8002C3E8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    LOOKUP_FUNC(0x8002CD2C)(rdram, ctx);
        goto after_16;
    // 0x8002C3E8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x8002C3EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002C3F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C3F4: jal         0x8002E3C8
    // 0x8002C3F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    LOOKUP_FUNC(0x8002E3C8)(rdram, ctx);
        goto after_17;
    // 0x8002C3F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_17:
    // 0x8002C3FC: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x8002C400: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8002C404: jal         0x8002DDB0
    // 0x8002C408: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8002DDB0)(rdram, ctx);
        goto after_18;
    // 0x8002C408: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x8002C40C: addiu       $t0, $s5, 0x8C
    ctx->r8 = ADD32(ctx->r21, 0X8C);
    // 0x8002C410: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x8002C414: lw          $t1, 0x4($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X4);
    // 0x8002C418: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002C41C: addiu       $s0, $s0, 0xDC
    ctx->r16 = ADD32(ctx->r16, 0XDC);
    // 0x8002C420: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C424: addiu       $s1, $s1, 0xDC
    ctx->r17 = ADD32(ctx->r17, 0XDC);
    // 0x8002C428: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
    // 0x8002C42C: bne         $at, $zero, L_8002C390
    if (ctx->r1 != 0) {
        // 0x8002C430: addiu       $s3, $s3, 0xDC
        ctx->r19 = ADD32(ctx->r19, 0XDC);
            goto L_8002C390;
    }
    // 0x8002C430: addiu       $s3, $s3, 0xDC
    ctx->r19 = ADD32(ctx->r19, 0XDC);
    // 0x8002C434: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8002C438:
    // 0x8002C438: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C43C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C440: jal         0x8003089C
    // 0x8002C444: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    LOOKUP_FUNC(0x8003089C)(rdram, ctx);
        goto after_19;
    // 0x8002C444: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    after_19:
    // 0x8002C448: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x8002C44C: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x8002C450: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002C454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C45C: jal         0x80034A10
    // 0x8002C460: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_20;
    // 0x8002C460: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x8002C464: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x8002C468: lw          $t3, 0x8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8);
    // 0x8002C46C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002C470: blezl       $t3, L_8002C4A0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8002C474: sw          $s7, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r23;
            goto L_8002C4A0;
    }
    goto skip_0;
    // 0x8002C474: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    skip_0:
    // 0x8002C478: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
L_8002C47C:
    // 0x8002C47C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002C480: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8002C484: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x8002C488: lw          $t5, 0x8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8);
    // 0x8002C48C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8002C490: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002C494: bnel        $at, $zero, L_8002C47C
    if (ctx->r1 != 0) {
        // 0x8002C498: lw          $t4, 0x2C($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X2C);
            goto L_8002C47C;
    }
    goto skip_1;
    // 0x8002C498: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
    skip_1:
    // 0x8002C49C: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
L_8002C4A0:
    // 0x8002C4A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002C4A4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002C4A8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C4AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002C4B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002C4B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002C4B8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C4BC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002C4C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002C4C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002C4C8: jr          $ra
    // 0x8002C4CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8002C4CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002c4d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002c4d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C4D0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002C4D4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8002C4D8: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x8002C4DC: lw          $s2, -0x6710($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X6710);
    // 0x8002C4E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002C4E4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8002C4E8: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8002C4EC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8002C4F0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8002C4F4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8002C4F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002C4FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002C500: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8002C504: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8002C508: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002C50C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002C510: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8002C514: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8002C518: bne         $t6, $zero, L_8002C52C
    if (ctx->r14 != 0) {
        // 0x8002C51C: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_8002C52C;
    }
    // 0x8002C51C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8002C520: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8002C524: b           L_8002C674
    // 0x8002C528: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8002C674;
    // 0x8002C528: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8002C52C:
    // 0x8002C52C: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x8002C530: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C534: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002C538: jal         0x8002C7F4
    // 0x8002C53C: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x8002C7F4)(rdram, ctx);
        goto after_0;
    // 0x8002C53C: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    after_0:
    // 0x8002C540: lw          $t8, 0x20($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X20);
    // 0x8002C544: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8002C548: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
    // 0x8002C54C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8002C550: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002C554: beql        $at, $zero, L_8002C5BC
    if (ctx->r1 == 0) {
        // 0x8002C558: lw          $t8, 0x1C($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X1C);
            goto L_8002C5BC;
    }
    goto skip_0;
    // 0x8002C558: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    skip_0:
    // 0x8002C55C: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
L_8002C560:
    // 0x8002C560: and         $t1, $t0, $s1
    ctx->r9 = ctx->r8 & ctx->r17;
    // 0x8002C564: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x8002C568: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8002C56C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002C570: jalr        $t9
    // 0x8002C574: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002C574: nop

    after_1:
    // 0x8002C578: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002C57C: jal         0x8002C780
    // 0x8002C580: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8002C780)(rdram, ctx);
        goto after_2;
    // 0x8002C580: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8002C584: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8002C588: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002C58C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C590: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8002C594: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8002C598: jal         0x8002C7F4
    // 0x8002C59C: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    LOOKUP_FUNC(0x8002C7F4)(rdram, ctx);
        goto after_3;
    // 0x8002C59C: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    after_3:
    // 0x8002C5A0: lw          $t6, 0x20($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X20);
    // 0x8002C5A4: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8002C5A8: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8002C5AC: slt         $at, $t7, $s3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002C5B0: bnel        $at, $zero, L_8002C560
    if (ctx->r1 != 0) {
        // 0x8002C5B4: lw          $t0, 0x1C($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X1C);
            goto L_8002C560;
    }
    goto skip_1;
    // 0x8002C5B4: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    skip_1:
    // 0x8002C5B8: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
L_8002C5BC:
    // 0x8002C5BC: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
    // 0x8002C5C0: addiu       $s7, $sp, 0x62
    ctx->r23 = ADD32(ctx->r29, 0X62);
    // 0x8002C5C4: and         $t0, $t8, $s1
    ctx->r8 = ctx->r24 & ctx->r17;
    // 0x8002C5C8: blez        $s3, L_8002C654
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8002C5CC: sw          $t0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r8;
            goto L_8002C654;
    }
    // 0x8002C5CC: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x8002C5D0: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_8002C5D4:
    // 0x8002C5D4: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x8002C5D8: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8002C5DC: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002C5E0: beq         $at, $zero, L_8002C5F0
    if (ctx->r1 == 0) {
        // 0x8002C5E4: nop
    
            goto L_8002C5F0;
    }
    // 0x8002C5E4: nop

    // 0x8002C5E8: b           L_8002C5F0
    // 0x8002C5EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8002C5F0;
    // 0x8002C5EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002C5F0:
    // 0x8002C5F0: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x8002C5F4: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x8002C5F8: lw          $s1, 0x38($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X38);
    // 0x8002C5FC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8002C600: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002C604: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8002C608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002C60C: jalr        $t9
    // 0x8002C610: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8002C610: nop

    after_4:
    // 0x8002C614: lw          $a3, 0x20($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X20);
    // 0x8002C618: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x8002C61C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C620: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8002C624: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002C628: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8002C62C: jalr        $t9
    // 0x8002C630: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8002C630: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8002C634: lw          $t5, 0x20($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X20);
    // 0x8002C638: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x8002C63C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8002C640: addu        $t3, $t5, $s0
    ctx->r11 = ADD32(ctx->r13, ctx->r16);
    // 0x8002C644: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002C648: addu        $s5, $s5, $t4
    ctx->r21 = ADD32(ctx->r21, ctx->r12);
    // 0x8002C64C: bgtz        $s3, L_8002C5D4
    if (SIGNED(ctx->r19) > 0) {
        // 0x8002C650: sw          $t3, 0x20($s2)
        MEM_W(0X20, ctx->r18) = ctx->r11;
            goto L_8002C5D4;
    }
    // 0x8002C650: sw          $t3, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r11;
L_8002C654:
    // 0x8002C654: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8002C658: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8002C65C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002C660: subu        $t7, $s4, $t6
    ctx->r15 = SUB32(ctx->r20, ctx->r14);
    // 0x8002C664: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8002C668: jal         0x8002C6E8
    // 0x8002C66C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    LOOKUP_FUNC(0x8002C6E8)(rdram, ctx);
        goto after_6;
    // 0x8002C66C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    after_6:
    // 0x8002C670: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8002C674:
    // 0x8002C674: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C678: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C67C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002C680: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8002C684: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8002C688: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C68C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8002C690: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8002C694: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8002C698: jr          $ra
    // 0x8002C69C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002C69C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002c6a0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002c6a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C6A0: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8002C6A4: lw          $v0, -0x6710($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6710);
    // 0x8002C6A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C6AC: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8002C6B0: beq         $a0, $zero, L_8002C6C8
    if (ctx->r4 == 0) {
        // 0x8002C6B4: nop
    
            goto L_8002C6C8;
    }
    // 0x8002C6B4: nop

    // 0x8002C6B8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002C6BC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8002C6C0: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x8002C6C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8002C6C8:
    // 0x8002C6C8: jr          $ra
    // 0x8002C6CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002C6CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002c6d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002c6d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C6D0: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8002C6D4: lw          $v0, -0x6710($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6710);
    // 0x8002C6D8: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8002C6DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8002C6E0: jr          $ra
    // 0x8002C6E4: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    return;
    // 0x8002C6E4: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002c6e8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002c6e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C6E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002C6EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002C6F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002C6F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002C6F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002C6FC: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x8002C700: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002C704: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x8002C708: beql        $s0, $zero, L_8002C734
    if (ctx->r16 == 0) {
        // 0x8002C70C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8002C734;
    }
    goto skip_0;
    // 0x8002C70C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8002C710:
    // 0x8002C710: jal         0x80026890
    // 0x8002C714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80026890)(rdram, ctx);
        goto after_0;
    // 0x8002C714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8002C718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C71C: jal         0x800268C0
    // 0x8002C720: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_1;
    // 0x8002C720: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8002C724: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x8002C728: bne         $s0, $zero, L_8002C710
    if (ctx->r16 != 0) {
        // 0x8002C72C: nop
    
            goto L_8002C710;
    }
    // 0x8002C72C: nop

    // 0x8002C730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002C734:
    // 0x8002C734: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002C738: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C73C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002C740: jr          $ra
    // 0x8002C744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002C744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002c748(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002c748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C758: jal         0x80026890
    // 0x8002C75C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80026890)(rdram, ctx);
        goto after_0;
    // 0x8002C75C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8002C760: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8002C764: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C768: jal         0x800268C0
    // 0x8002C76C: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_1;
    // 0x8002C76C: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x8002C770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C778: jr          $ra
    // 0x8002C77C: nop

    return;
    // 0x8002C77C: nop

;}
RECOMP_FUNC void FUN_8002c780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C780: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8002C784: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8002C788: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002C78C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8002C790: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002C794: ldc1        $f4, -0x2C90($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C90);
    // 0x8002C798: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002C79C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C7A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002C7A4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002C7A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C7AC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C7B0: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x8002C7B4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8002C7B8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8002C7BC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002C7C0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8002C7C4: jr          $ra
    // 0x8002C7C8: nop

    return;
    // 0x8002C7C8: nop

;}
RECOMP_FUNC void FUN_8002c7cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C7CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C7D4: jal         0x8002C780
    // 0x8002C7D8: nop

    LOOKUP_FUNC(0x8002C780)(rdram, ctx);
        goto after_0;
    // 0x8002C7D8: nop

    after_0:
    // 0x8002C7DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C7E0: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8002C7E4: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8002C7E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002C7EC: jr          $ra
    // 0x8002C7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002c7f4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002c7f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C7F4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8002C7F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8002C7FC: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x8002C800: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8002C804: beql        $v1, $zero, L_8002C844
    if (ctx->r3 == 0) {
        // 0x8002C808: lw          $t9, 0x0($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X0);
            goto L_8002C844;
    }
    goto skip_0;
    // 0x8002C808: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8002C80C: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8002C810: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
L_8002C814:
    // 0x8002C814: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x8002C818: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002C81C: beql        $at, $zero, L_8002C838
    if (ctx->r1 == 0) {
        // 0x8002C820: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_8002C838;
    }
    goto skip_1;
    // 0x8002C820: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8002C824: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8002C828: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8002C82C: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8002C830: subu        $v0, $t8, $a2
    ctx->r2 = SUB32(ctx->r24, ctx->r6);
    // 0x8002C834: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_8002C838:
    // 0x8002C838: bnel        $v1, $zero, L_8002C814
    if (ctx->r3 != 0) {
        // 0x8002C83C: lw          $t6, 0x10($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X10);
            goto L_8002C814;
    }
    goto skip_2;
    // 0x8002C83C: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    skip_2:
    // 0x8002C840: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
L_8002C844:
    // 0x8002C844: jr          $ra
    // 0x8002C848: lw          $v0, 0x10($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X10);
    return;
    // 0x8002C848: lw          $v0, 0x10($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X10);
    // 0x8002C84C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002c850(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002c850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C850: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8002C854: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x8002C858: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002C85C: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x8002C860: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8002C864: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002C868: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002C86C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x8002C870: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x8002C874: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x8002C878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C87C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_8002C880:
    // 0x8002C880: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002C884: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x8002C888: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002C88C: bne         $at, $zero, L_8002C880
    if (ctx->r1 != 0) {
        // 0x8002C890: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_8002C880;
    }
    // 0x8002C890: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x8002C894: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8002C898: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x8002C89C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8002C8A0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002C8A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002C8A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002C8AC: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8002C8B0: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x8002C8B4: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x8002C8B8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002C8BC: beq         $at, $zero, L_8002C8E8
    if (ctx->r1 == 0) {
        // 0x8002C8C0: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8002C8E8;
    }
    // 0x8002C8C0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8002C8C4:
    // 0x8002C8C4: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8002C8C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002C8CC: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8002C8D0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002C8D4: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x8002C8D8: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x8002C8DC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8002C8E0: bne         $at, $zero, L_8002C8C4
    if (ctx->r1 != 0) {
        // 0x8002C8E4: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_8002C8C4;
    }
    // 0x8002C8E4: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_8002C8E8:
    // 0x8002C8E8: jr          $ra
    // 0x8002C8EC: nop

    return;
    // 0x8002C8EC: nop

;}
RECOMP_FUNC void FUN_8002c8f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C8F0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002C8F4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8002C8F8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8002C8FC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8002C900: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8002C904: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8002C908: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002C90C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8002C910: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8002C914: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8002C918: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8002C91C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8002C920: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8002C924: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8002C928: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8002C92C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8002C930: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8002C934: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8002C938: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8002C93C: addiu       $a2, $a2, -0x2B70
    ctx->r6 = ADD32(ctx->r6, -0X2B70);
    // 0x8002C940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C944: jal         0x80030480
    // 0x8002C948: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80030480)(rdram, ctx);
        goto after_0;
    // 0x8002C948: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x8002C94C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8002C950: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002C954: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002C958: addiu       $t6, $t6, -0x2EB0
    ctx->r14 = ADD32(ctx->r14, -0X2EB0);
    // 0x8002C95C: addiu       $t7, $t7, -0x2B58
    ctx->r15 = ADD32(ctx->r15, -0X2B58);
    // 0x8002C960: sw          $t6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r14;
    // 0x8002C964: sw          $t7, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r15;
    // 0x8002C968: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x8002C96C: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x8002C970: addiu       $s3, $s3, -0x5338
    ctx->r19 = ADD32(ctx->r19, -0X5338);
    // 0x8002C974: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002C978: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x8002C97C: beq         $at, $zero, L_8002C9DC
    if (ctx->r1 == 0) {
        // 0x8002C980: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8002C9DC;
    }
    // 0x8002C980: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002C984: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002C988: addu        $at, $at, $t9
    gpr jr_addend_8002C990 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002C98C: lw          $t9, -0x2C80($at)
    ctx->r25 = ADD32(ctx->r1, -0X2C80);
    // 0x8002C990: jr          $t9
    // 0x8002C994: nop

    switch (jr_addend_8002C990 >> 2) {
        case 0: goto L_8002C998; break;
        case 1: goto L_8002C9A4; break;
        case 2: goto L_8002C9BC; break;
        case 3: goto L_8002C9C8; break;
        case 4: goto L_8002C9B0; break;
        case 5: goto L_8002C9D4; break;
        default: switch_error(__func__, 0x8002C990, 0x8004D380);
    }
    // 0x8002C994: nop

L_8002C998:
    // 0x8002C998: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x8002C99C: b           L_8002C9DC
    // 0x8002C9A0: addiu       $s3, $s3, -0x54A0
    ctx->r19 = ADD32(ctx->r19, -0X54A0);
        goto L_8002C9DC;
    // 0x8002C9A0: addiu       $s3, $s3, -0x54A0
    ctx->r19 = ADD32(ctx->r19, -0X54A0);
L_8002C9A4:
    // 0x8002C9A4: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x8002C9A8: b           L_8002C9DC
    // 0x8002C9AC: addiu       $s3, $s3, -0x5438
    ctx->r19 = ADD32(ctx->r19, -0X5438);
        goto L_8002C9DC;
    // 0x8002C9AC: addiu       $s3, $s3, -0x5438
    ctx->r19 = ADD32(ctx->r19, -0X5438);
L_8002C9B0:
    // 0x8002C9B0: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x8002C9B4: b           L_8002C9DC
    // 0x8002C9B8: addiu       $s3, $s3, -0x53B0
    ctx->r19 = ADD32(ctx->r19, -0X53B0);
        goto L_8002C9DC;
    // 0x8002C9B8: addiu       $s3, $s3, -0x53B0
    ctx->r19 = ADD32(ctx->r19, -0X53B0);
L_8002C9BC:
    // 0x8002C9BC: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x8002C9C0: b           L_8002C9DC
    // 0x8002C9C4: addiu       $s3, $s3, -0x5388
    ctx->r19 = ADD32(ctx->r19, -0X5388);
        goto L_8002C9DC;
    // 0x8002C9C4: addiu       $s3, $s3, -0x5388
    ctx->r19 = ADD32(ctx->r19, -0X5388);
L_8002C9C8:
    // 0x8002C9C8: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x8002C9CC: b           L_8002C9DC
    // 0x8002C9D0: addiu       $s3, $s3, -0x5360
    ctx->r19 = ADD32(ctx->r19, -0X5360);
        goto L_8002C9DC;
    // 0x8002C9D0: addiu       $s3, $s3, -0x5360
    ctx->r19 = ADD32(ctx->r19, -0X5360);
L_8002C9D4:
    // 0x8002C9D4: b           L_8002C9DC
    // 0x8002C9D8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
        goto L_8002C9DC;
    // 0x8002C9D8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
L_8002C9DC:
    // 0x8002C9DC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8002C9E0: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x8002C9E4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8002C9E8: sb          $t0, 0x24($s5)
    MEM_B(0X24, ctx->r21) = ctx->r8;
    // 0x8002C9EC: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x8002C9F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C9F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C9F8: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x8002C9FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002CA00: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002CA04: jal         0x80034A10
    // 0x8002CA08: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_1;
    // 0x8002CA08: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    after_1:
    // 0x8002CA0C: sw          $v0, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r2;
    // 0x8002CA10: lw          $a3, 0x1C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X1C);
    // 0x8002CA14: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8002CA18: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002CA1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CA20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CA24: jal         0x80034A10
    // 0x8002CA28: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_2;
    // 0x8002CA28: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x8002CA2C: lw          $t4, 0x1C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1C);
    // 0x8002CA30: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x8002CA34: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x8002CA38: beq         $t4, $zero, L_8002CA6C
    if (ctx->r12 == 0) {
        // 0x8002CA3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002CA6C;
    }
    // 0x8002CA3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002CA40: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
L_8002CA44:
    // 0x8002CA44: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8002CA48: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002CA4C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8002CA50: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x8002CA54: lw          $t9, 0x1C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1C);
    // 0x8002CA58: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8002CA5C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8002CA60: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x8002CA64: bnel        $at, $zero, L_8002CA44
    if (ctx->r1 != 0) {
        // 0x8002CA68: lw          $t5, 0x14($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X14);
            goto L_8002CA44;
    }
    goto skip_0;
    // 0x8002CA68: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
    skip_0:
L_8002CA6C:
    // 0x8002CA6C: lbu         $t0, 0x24($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X24);
    // 0x8002CA70: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002CA74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002CA78: blez        $t0, L_8002CCEC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002CA7C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_8002CCEC;
    }
    // 0x8002CA7C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8002CA80: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8002CA84: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8002CA88: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002CA8C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002CA90: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8002CA94: ldc1        $f20, -0x2C68($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X2C68);
    // 0x8002CA98: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
L_8002CA9C:
    // 0x8002CA9C: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CAA0: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8002CAA4: lw          $t1, 0x20($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X20);
    // 0x8002CAA8: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8002CAAC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002CAB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CAB4: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x8002CAB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002CABC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8002CAC0: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x8002CAC4: mflo        $t2
    ctx->r10 = lo;
    // 0x8002CAC8: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x8002CACC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8002CAD0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002CAD4: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x8002CAD8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002CADC: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8002CAE0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8002CAE4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8002CAE8: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x8002CAEC: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x8002CAF0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002CAF4: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x8002CAF8: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x8002CAFC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002CB00: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x8002CB04: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x8002CB08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002CB0C: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x8002CB10: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8002CB14: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8002CB18: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x8002CB1C: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x8002CB20: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8002CB24: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8002CB28: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x8002CB2C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8002CB30: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8002CB34: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x8002CB38: beq         $v0, $zero, L_8002CC3C
    if (ctx->r2 == 0) {
        // 0x8002CB3C: addiu       $s1, $t0, 0x2
        ctx->r17 = ADD32(ctx->r8, 0X2);
            goto L_8002CC3C;
    }
    // 0x8002CB3C: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x8002CB40: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002CB44: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8002CB48: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8002CB4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CB50: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x8002CB54: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8002CB58: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x8002CB5C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8002CB60: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x8002CB64: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8002CB68: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8002CB6C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8002CB70: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8002CB74: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8002CB78: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8002CB7C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8002CB80: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8002CB84: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8002CB88: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8002CB8C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002CB90: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8002CB94: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8002CB98: bgez        $t0, L_8002CBB0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8002CB9C: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_8002CBB0;
    }
    // 0x8002CB9C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8002CBA0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002CBA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002CBA8: nop

    // 0x8002CBAC: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_8002CBB0:
    // 0x8002CBB0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8002CBB4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CBB8: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x8002CBBC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8002CBC0: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x8002CBC4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8002CBC8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002CBCC: addiu       $t5, $zero, 0x34
    ctx->r13 = ADD32(0, 0X34);
    // 0x8002CBD0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x8002CBD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CBDC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002CBE0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002CBE4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8002CBE8: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x8002CBEC: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8002CBF0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8002CBF4: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8002CBF8: jal         0x80034A10
    // 0x8002CBFC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_3;
    // 0x8002CBFC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x8002CC00: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8002CC04: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8002CC08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002CC0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CC10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CC14: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002CC18: jal         0x80034A10
    // 0x8002CC1C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_4;
    // 0x8002CC1C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x8002CC20: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8002CC24: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x8002CC28: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8002CC2C: swc1        $f26, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f26.u32l;
    // 0x8002CC30: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8002CC34: b           L_8002CC48
    // 0x8002CC38: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
        goto L_8002CC48;
    // 0x8002CC38: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
L_8002CC3C:
    // 0x8002CC3C: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x8002CC40: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8002CC44: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_8002CC48:
    // 0x8002CC48: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8002CC4C: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x8002CC50: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8002CC54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CC58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CC5C: beq         $t3, $zero, L_8002CCC4
    if (ctx->r11 == 0) {
        // 0x8002CC60: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_8002CCC4;
    }
    // 0x8002CC60: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002CC64: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x8002CC68: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002CC6C: jal         0x80034A10
    // 0x8002CC70: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_5;
    // 0x8002CC70: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_5:
    // 0x8002CC74: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8002CC78: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8002CC7C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002CC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CC84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CC88: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002CC8C: jal         0x80034A10
    // 0x8002CC90: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_6;
    // 0x8002CC90: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
    // 0x8002CC94: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x8002CC98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CC9C: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x8002CCA0: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x8002CCA4: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x8002CCA8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8002CCAC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8002CCB0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8002CCB4: jal         0x8002C850
    // 0x8002CCB8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    LOOKUP_FUNC(0x8002C850)(rdram, ctx);
        goto after_7;
    // 0x8002CCB8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x8002CCBC: b           L_8002CCD8
    // 0x8002CCC0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
        goto L_8002CCD8;
    // 0x8002CCC0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_8002CCC4:
    // 0x8002CCC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CCC8: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x8002CCCC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8002CCD0: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8002CCD4: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_8002CCD8:
    // 0x8002CCD8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002CCDC: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x8002CCE0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002CCE4: bne         $at, $zero, L_8002CA9C
    if (ctx->r1 != 0) {
        // 0x8002CCE8: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_8002CA9C;
    }
    // 0x8002CCE8: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_8002CCEC:
    // 0x8002CCEC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8002CCF0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002CCF4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8002CCF8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8002CCFC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8002CD00: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8002CD04: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8002CD08: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8002CD0C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8002CD10: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8002CD14: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8002CD18: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8002CD1C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8002CD20: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8002CD24: jr          $ra
    // 0x8002CD28: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002CD28: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002cd2c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002cd2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CD2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CD30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002CD34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002CD38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002CD3C: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8002CD40: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002CD44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002CD48: addiu       $a2, $a2, -0x1C38
    ctx->r6 = ADD32(ctx->r6, -0X1C38);
    // 0x8002CD4C: addiu       $a1, $a1, -0x2140
    ctx->r5 = ADD32(ctx->r5, -0X2140);
    // 0x8002CD50: jal         0x80030480
    // 0x8002CD54: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80030480)(rdram, ctx);
        goto after_0;
    // 0x8002CD54: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x8002CD58: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8002CD5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002CD60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CD64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CD68: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CD6C: jal         0x80034A10
    // 0x8002CD70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_1;
    // 0x8002CD70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8002CD74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002CD78: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8002CD7C: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x8002CD80: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8002CD84: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
    // 0x8002CD88: sh          $v1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r3;
    // 0x8002CD8C: sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    // 0x8002CD90: sh          $v1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r3;
    // 0x8002CD94: sh          $v1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r3;
    // 0x8002CD98: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x8002CD9C: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x8002CDA0: sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    // 0x8002CDA4: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x8002CDA8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8002CDAC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x8002CDB0: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8002CDB4: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8002CDB8: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x8002CDBC: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x8002CDC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002CDC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002CDCC: jr          $ra
    // 0x8002CDD0: nop

    return;
    // 0x8002CDD0: nop

;}
RECOMP_FUNC void FUN_8002cdd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CDD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CDD8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002CDDC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002CDE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002CDE4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002CDE8: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002CDEC: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8002CDF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002CDF4: addiu       $a1, $a1, -0x944
    ctx->r5 = ADD32(ctx->r5, -0X944);
    // 0x8002CDF8: addiu       $a2, $a2, -0xFF0
    ctx->r6 = ADD32(ctx->r6, -0XFF0);
    // 0x8002CDFC: jal         0x80030480
    // 0x8002CE00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80030480)(rdram, ctx);
        goto after_0;
    // 0x8002CE00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8002CE04: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8002CE08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002CE0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CE10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CE14: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002CE18: jal         0x80034A10
    // 0x8002CE1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_1;
    // 0x8002CE1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8002CE20: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8002CE24: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8002CE28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002CE2C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002CE30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CE34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CE38: jal         0x80034A10
    // 0x8002CE3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_2;
    // 0x8002CE3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8002CE40: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8002CE44: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CE48: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8002CE4C: jalr        $t9
    // 0x8002CE50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8002CE50: nop

    after_3:
    // 0x8002CE54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002CE58: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8002CE5C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8002CE60: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x8002CE64: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x8002CE68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002CE6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002CE70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002CE74: jr          $ra
    // 0x8002CE78: nop

    return;
    // 0x8002CE78: nop

;}
RECOMP_FUNC void FUN_8002ce7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CE7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CE80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002CE84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002CE88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002CE8C: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8002CE90: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002CE94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002CE98: addiu       $a2, $a2, -0x14C0
    ctx->r6 = ADD32(ctx->r6, -0X14C0);
    // 0x8002CE9C: addiu       $a1, $a1, -0x13D4
    ctx->r5 = ADD32(ctx->r5, -0X13D4);
    // 0x8002CEA0: jal         0x80030480
    // 0x8002CEA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80030480)(rdram, ctx);
        goto after_0;
    // 0x8002CEA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8002CEA8: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8002CEAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002CEB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CEB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CEB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CEBC: jal         0x80034A10
    // 0x8002CEC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80034A10)(rdram, ctx);
        goto after_1;
    // 0x8002CEC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8002CEC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002CEC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CECC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002CED0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002CED4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8002CED8: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x8002CEDC: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8002CEE0: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8002CEE4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8002CEE8: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x8002CEEC: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8002CEF0: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8002CEF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002CEF8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002CEFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002CF00: jr          $ra
    // 0x8002CF04: nop

    return;
    // 0x8002CF04: nop

;}
RECOMP_FUNC void FUN_8002cf08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CF08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CF0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002CF10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002CF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CF18: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002CF1C: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8002CF20: addiu       $a1, $a1, -0x2220
    ctx->r5 = ADD32(ctx->r5, -0X2220);
    // 0x8002CF24: addiu       $a2, $a2, -0x2250
    ctx->r6 = ADD32(ctx->r6, -0X2250);
    // 0x8002CF28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002CF2C: jal         0x80030480
    // 0x8002CF30: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80030480)(rdram, ctx);
        goto after_0;
    // 0x8002CF30: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x8002CF34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002CF38: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8002CF3C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002CF40: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8002CF44: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CF48: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8002CF4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CF50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CF54: jr          $ra
    // 0x8002CF58: nop

    return;
    // 0x8002CF58: nop

;}
RECOMP_FUNC void FUN_8002cf5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CF5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CF60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002CF64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002CF68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CF6C: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002CF70: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8002CF74: addiu       $a1, $a1, -0x2FD0
    ctx->r5 = ADD32(ctx->r5, -0X2FD0);
    // 0x8002CF78: addiu       $a2, $a2, -0x3000
    ctx->r6 = ADD32(ctx->r6, -0X3000);
    // 0x8002CF7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002CF80: jal         0x80030480
    // 0x8002CF84: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80030480)(rdram, ctx);
        goto after_0;
    // 0x8002CF84: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x8002CF88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002CF8C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8002CF90: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002CF94: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8002CF98: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CF9C: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8002CFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CFA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CFA8: jr          $ra
    // 0x8002CFAC: nop

    return;
    // 0x8002CFAC: nop

;}
RECOMP_FUNC void FUN_8002cfb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CFB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CFB8: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8002CFBC: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002CFC0: addiu       $a2, $a2, 0x89C
    ctx->r6 = ADD32(ctx->r6, 0X89C);
    // 0x8002CFC4: addiu       $a1, $a1, 0x810
    ctx->r5 = ADD32(ctx->r5, 0X810);
    // 0x8002CFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002CFCC: jal         0x80030480
    // 0x8002CFD0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80030480)(rdram, ctx);
        goto after_0;
    // 0x8002CFD0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x8002CFD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002CFD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002CFDC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8002CFE0: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8002CFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CFEC: jr          $ra
    // 0x8002CFF0: nop

    return;
    // 0x8002CFF0: nop

    // 0x8002CFF4: nop

    // 0x8002CFF8: nop

    // 0x8002CFFC: nop

;}
RECOMP_FUNC void FUN_8002d000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D000: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002D004: bne         $a1, $at, L_8002D028
    if (ctx->r5 != ctx->r1) {
        // 0x8002D008: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_8002D028;
    }
    // 0x8002D008: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8002D00C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8002D010: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002D014: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8002D018: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x8002D01C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8002D020: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8002D024: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_8002D028:
    // 0x8002D028: jr          $ra
    // 0x8002D02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002D02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002d030(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002d030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D030: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002D034: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8002D038: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002D03C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002D040: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002D044: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002D048: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002D04C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002D050: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002D054: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002D058: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002D05C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002D060: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8002D064: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8002D068: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8002D06C: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x8002D070: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x8002D074: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x8002D078: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8002D07C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8002D080: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8002D084: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8002D088: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8002D08C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8002D090: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8002D094: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x8002D098: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8002D09C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002D0A0: blez        $t8, L_8002D11C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8002D0A4: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_8002D11C;
    }
    // 0x8002D0A4: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x8002D0A8: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x8002D0AC: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x8002D0B0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8002D0B4: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_8002D0B8:
    // 0x8002D0B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D0BC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8002D0C0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8002D0C4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8002D0C8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002D0CC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8002D0D0: jalr        $t9
    // 0x8002D0D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002D0D4: nop

    after_0:
    // 0x8002D0D8: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x8002D0DC: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x8002D0E0: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x8002D0E4: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x8002D0E8: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x8002D0EC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8002D0F0: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8002D0F4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x8002D0F8: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x8002D0FC: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8002D100: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x8002D104: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x8002D108: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002D10C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002D110: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002D114: bne         $at, $zero, L_8002D0B8
    if (ctx->r1 != 0) {
        // 0x8002D118: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_8002D0B8;
    }
    // 0x8002D118: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_8002D11C:
    // 0x8002D11C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002D120: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8002D124: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D128: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002D12C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002D130: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002D134: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002D138: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002D13C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002D140: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D144: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002D148: jr          $ra
    // 0x8002D14C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8002D14C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002d150(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002d150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D150: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8002D154: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002D158: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002D15C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002D160: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002D164: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002D168: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002D16C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002D170: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002D174: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002D178: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002D17C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002D180: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8002D184: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8002D188: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8002D18C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8002D190: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002D194: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8002D198: jalr        $t9
    // 0x8002D19C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002D19C: nop

    after_0:
    // 0x8002D1A0: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x8002D1A4: lui         $t8, 0xC00
    ctx->r24 = S32(0XC00 << 16);
    // 0x8002D1A8: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x8002D1AC: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x8002D1B0: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8002D1B4: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x8002D1B8: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x8002D1BC: ori         $t2, $t2, 0x6C0
    ctx->r10 = ctx->r10 | 0X6C0;
    // 0x8002D1C0: ori         $t8, $t8, 0xDA83
    ctx->r24 = ctx->r24 | 0XDA83;
    // 0x8002D1C4: ori         $t4, $t4, 0x6C0
    ctx->r12 = ctx->r12 | 0X6C0;
    // 0x8002D1C8: ori         $t3, $t3, 0x5A82
    ctx->r11 = ctx->r11 | 0X5A82;
    // 0x8002D1CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002D1D0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002D1D4: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8002D1D8: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x8002D1DC: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x8002D1E0: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x8002D1E4: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x8002D1E8: addiu       $t5, $v0, 0x18
    ctx->r13 = ADD32(ctx->r2, 0X18);
    // 0x8002D1EC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002D1F0: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x8002D1F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002D1F8: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x8002D1FC: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8002D200: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002D204: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x8002D208: jal         0x8002DABC
    // 0x8002D20C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    LOOKUP_FUNC(0x8002DABC)(rdram, ctx);
        goto after_1;
    // 0x8002D20C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x8002D210: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x8002D214: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8002D218: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x8002D21C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002D220: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8002D224: lbu         $t9, 0x24($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X24);
    // 0x8002D228: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8002D22C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002D230: blezl       $t9, L_8002D410
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002D234: lw          $v1, 0x1C($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X1C);
            goto L_8002D410;
    }
    goto skip_0;
    // 0x8002D234: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    skip_0:
    // 0x8002D238: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
L_8002D23C:
    // 0x8002D23C: lw          $t7, 0x20($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X20);
    // 0x8002D240: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x8002D244: addu        $t8, $t8, $s7
    ctx->r24 = ADD32(ctx->r24, ctx->r23);
    // 0x8002D248: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002D24C: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8002D250: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8002D254: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x8002D258: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002D25C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8002D260: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8002D264: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8002D268: addu        $s4, $v0, $t4
    ctx->r20 = ADD32(ctx->r2, ctx->r12);
    // 0x8002D26C: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8002D270: bne         $s4, $v1, L_8002D298
    if (ctx->r20 != ctx->r3) {
        // 0x8002D274: addu        $fp, $v0, $t9
        ctx->r30 = ADD32(ctx->r2, ctx->r25);
            goto L_8002D298;
    }
    // 0x8002D274: addu        $fp, $v0, $t9
    ctx->r30 = ADD32(ctx->r2, ctx->r25);
    // 0x8002D278: or          $t7, $s2, $zero
    ctx->r15 = ctx->r18 | 0;
    // 0x8002D27C: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x8002D280: sll         $s5, $t7, 16
    ctx->r21 = S32(ctx->r15 << 16);
    // 0x8002D284: sra         $t2, $s5, 16
    ctx->r10 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8002D288: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8002D28C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8002D290: b           L_8002D2B0
    // 0x8002D294: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
        goto L_8002D2B0;
    // 0x8002D294: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
L_8002D298:
    // 0x8002D298: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002D29C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002D2A0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8002D2A4: jal         0x8002D924
    // 0x8002D2A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8002D924)(rdram, ctx);
        goto after_2;
    // 0x8002D2A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x8002D2AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002D2B0:
    // 0x8002D2B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002D2B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002D2B8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002D2BC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8002D2C0: jal         0x8002D704
    // 0x8002D2C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8002D704)(rdram, ctx);
        goto after_3;
    // 0x8002D2C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x8002D2C8: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8002D2CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002D2D0: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x8002D2D4: beq         $a0, $zero, L_8002D328
    if (ctx->r4 == 0) {
        // 0x8002D2D8: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_8002D328;
    }
    // 0x8002D2D8: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8002D2DC: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x8002D2E0: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x8002D2E4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8002D2E8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8002D2EC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8002D2F0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002D2F4: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x8002D2F8: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8002D2FC: bnel        $t2, $zero, L_8002D32C
    if (ctx->r10 != 0) {
        // 0x8002D300: lh          $v1, 0xA($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XA);
            goto L_8002D32C;
    }
    goto skip_1;
    // 0x8002D300: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    skip_1:
    // 0x8002D304: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x8002D308: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002D30C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8002D310: bne         $t3, $zero, L_8002D328
    if (ctx->r11 != 0) {
        // 0x8002D314: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_8002D328;
    }
    // 0x8002D314: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002D318: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8002D31C: jal         0x8002DABC
    // 0x8002D320: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8002DABC)(rdram, ctx);
        goto after_4;
    // 0x8002D320: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x8002D324: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002D328:
    // 0x8002D328: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
L_8002D32C:
    // 0x8002D32C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002D330: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x8002D334: beq         $v1, $zero, L_8002D374
    if (ctx->r3 == 0) {
        // 0x8002D338: andi        $t5, $v1, 0xFFFF
        ctx->r13 = ctx->r3 & 0XFFFF;
            goto L_8002D374;
    }
    // 0x8002D338: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x8002D33C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8002D340: andi        $t8, $s5, 0xFFFF
    ctx->r24 = ctx->r21 & 0XFFFF;
    // 0x8002D344: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x8002D348: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8002D34C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002D350: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8002D354: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002D358: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002D35C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002D360: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002D364: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002D368: jal         0x8002DABC
    // 0x8002D36C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    LOOKUP_FUNC(0x8002DABC)(rdram, ctx);
        goto after_5;
    // 0x8002D36C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x8002D370: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002D374:
    // 0x8002D374: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8002D378: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002D37C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002D380: beql        $a0, $zero, L_8002D398
    if (ctx->r4 == 0) {
        // 0x8002D384: lw          $t3, 0x24($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X24);
            goto L_8002D398;
    }
    goto skip_2;
    // 0x8002D384: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    skip_2:
    // 0x8002D388: jal         0x8002DC50
    // 0x8002D38C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8002DC50)(rdram, ctx);
        goto after_6;
    // 0x8002D38C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x8002D390: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002D394: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
L_8002D398:
    // 0x8002D398: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002D39C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8002D3A0: bne         $t3, $zero, L_8002D3B8
    if (ctx->r11 != 0) {
        // 0x8002D3A4: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_8002D3B8;
    }
    // 0x8002D3A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002D3A8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8002D3AC: jal         0x8002DABC
    // 0x8002D3B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8002DABC)(rdram, ctx);
        goto after_7;
    // 0x8002D3B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x8002D3B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002D3B8:
    // 0x8002D3B8: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x8002D3BC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002D3C0: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x8002D3C4: beq         $v1, $zero, L_8002D3F0
    if (ctx->r3 == 0) {
        // 0x8002D3C8: sra         $s7, $t4, 16
        ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
            goto L_8002D3F0;
    }
    // 0x8002D3C8: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8002D3CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002D3D0: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x8002D3D4: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x8002D3D8: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8002D3DC: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x8002D3E0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8002D3E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002D3E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002D3EC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002D3F0:
    // 0x8002D3F0: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x8002D3F4: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8002D3F8: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x8002D3FC: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002D400: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002D404: bne         $at, $zero, L_8002D23C
    if (ctx->r1 != 0) {
        // 0x8002D408: addu        $v1, $v0, $t3
        ctx->r3 = ADD32(ctx->r2, ctx->r11);
            goto L_8002D23C;
    }
    // 0x8002D408: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x8002D40C: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
L_8002D410:
    // 0x8002D410: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x8002D414: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002D418: lw          $t3, 0x14($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X14);
    // 0x8002D41C: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x8002D420: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8002D424: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x8002D428: sltu        $at, $t4, $t8
    ctx->r1 = ctx->r12 < ctx->r24 ? 1 : 0;
    // 0x8002D42C: beq         $at, $zero, L_8002D43C
    if (ctx->r1 == 0) {
        // 0x8002D430: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_8002D43C;
    }
    // 0x8002D430: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x8002D434: subu        $t5, $t8, $t2
    ctx->r13 = SUB32(ctx->r24, ctx->r10);
    // 0x8002D438: sw          $t5, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r13;
L_8002D43C:
    // 0x8002D43C: lui         $t6, 0xA00
    ctx->r14 = S32(0XA00 << 16);
    // 0x8002D440: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x8002D444: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002D448: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002D44C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8002D450: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x8002D454: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8002D458: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8002D45C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8002D460: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002D464: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002D468: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D46C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002D470: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002D474: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002D478: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D47C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002D480: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002D484: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002D488: jr          $ra
    // 0x8002D48C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8002D48C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002d490(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002d490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D490: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D494: bne         $a1, $at, L_8002D4A0
    if (ctx->r5 != ctx->r1) {
        // 0x8002D498: nop
    
            goto L_8002D4A0;
    }
    // 0x8002D498: nop

    // 0x8002D49C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_8002D4A0:
    // 0x8002D4A0: jr          $ra
    // 0x8002D4A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002D4A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002d4a8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002d4a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D4A8: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x8002D4AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D4B0: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x8002D4B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D4B8: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x8002D4BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002D4C0: beq         $at, $zero, L_8002D6F0
    if (ctx->r1 == 0) {
        // 0x8002D4C4: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_8002D6F0;
    }
    // 0x8002D4C4: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8002D4C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002D4CC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002D4D0: addu        $at, $at, $t6
    gpr jr_addend_8002D4D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002D4D4: lw          $t6, -0x2C60($at)
    ctx->r14 = ADD32(ctx->r1, -0X2C60);
    // 0x8002D4D8: jr          $t6
    // 0x8002D4DC: nop

    switch (jr_addend_8002D4D8 >> 2) {
        case 0: goto L_8002D4E0; break;
        case 1: goto L_8002D514; break;
        case 2: goto L_8002D574; break;
        case 3: goto L_8002D548; break;
        case 4: goto L_8002D5A0; break;
        case 5: goto L_8002D5CC; break;
        case 6: goto L_8002D634; break;
        case 7: goto L_8002D6AC; break;
        default: switch_error(__func__, 0x8002D4D8, 0x8004D3A0);
    }
    // 0x8002D4DC: nop

L_8002D4E0:
    // 0x8002D4E0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8002D4E4: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x8002D4E8: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8002D4EC: bgez        $v1, L_8002D4FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D4F0: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D4FC;
    }
    // 0x8002D4F0: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D4F4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D4F8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8002D4FC:
    // 0x8002D4FC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8002D500: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8002D504: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002D508: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8002D50C: b           L_8002D6F0
    // 0x8002D510: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_8002D6F0;
    // 0x8002D510: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8002D514:
    // 0x8002D514: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8002D518: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8002D51C: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x8002D520: bgez        $v1, L_8002D530
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D524: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D530;
    }
    // 0x8002D524: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D528: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D52C: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_8002D530:
    // 0x8002D530: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002D534: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D538: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002D53C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x8002D540: b           L_8002D6F0
    // 0x8002D544: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_8002D6F0;
    // 0x8002D544: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_8002D548:
    // 0x8002D548: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8002D54C: bgez        $v1, L_8002D55C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D550: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D55C;
    }
    // 0x8002D550: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D554: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D558: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8002D55C:
    // 0x8002D55C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8002D560: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x8002D564: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002D568: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x8002D56C: b           L_8002D6F0
    // 0x8002D570: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_8002D6F0;
    // 0x8002D570: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_8002D574:
    // 0x8002D574: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x8002D578: bgez        $v1, L_8002D588
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D57C: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D588;
    }
    // 0x8002D57C: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D580: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D584: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_8002D588:
    // 0x8002D588: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002D58C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8002D590: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002D594: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x8002D598: b           L_8002D6F0
    // 0x8002D59C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_8002D6F0;
    // 0x8002D59C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_8002D5A0:
    // 0x8002D5A0: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x8002D5A4: bgez        $v1, L_8002D5B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D5A8: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D5B4;
    }
    // 0x8002D5A8: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D5AC: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D5B0: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8002D5B4:
    // 0x8002D5B4: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8002D5B8: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8002D5BC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002D5C0: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D5C4: b           L_8002D6F0
    // 0x8002D5C8: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_8002D6F0;
    // 0x8002D5C8: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_8002D5CC:
    // 0x8002D5CC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8002D5D0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8002D5D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002D5D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D5DC: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8002D5E0: lw          $t2, -0x6710($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6710);
    // 0x8002D5E4: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x8002D5E8: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x8002D5EC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002D5F0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8002D5F4: nop

    // 0x8002D5F8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8002D5FC: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8002D600: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8002D604: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x8002D608: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002D60C: bgez        $v1, L_8002D61C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D610: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D61C;
    }
    // 0x8002D610: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D614: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D618: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8002D61C:
    // 0x8002D61C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8002D620: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8002D624: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002D628: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8002D62C: b           L_8002D6F0
    // 0x8002D630: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_8002D6F0;
    // 0x8002D630: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_8002D634:
    // 0x8002D634: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x8002D638: bgez        $v1, L_8002D648
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D63C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D648;
    }
    // 0x8002D63C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D640: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D644: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8002D648:
    // 0x8002D648: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8002D64C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8002D650: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002D654: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x8002D658: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8002D65C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002D660: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8002D664: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8002D668: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x8002D66C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002D670: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D674: bgez        $t6, L_8002D68C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8002D678: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_8002D68C;
    }
    // 0x8002D678: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x8002D67C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002D680: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002D684: nop

    // 0x8002D688: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_8002D68C:
    // 0x8002D68C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002D690: ldc1        $f10, -0x2C40($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2C40);
    // 0x8002D694: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002D698: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8002D69C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8002D6A0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8002D6A4: b           L_8002D6F0
    // 0x8002D6A8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_8002D6F0;
    // 0x8002D6A8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_8002D6AC:
    // 0x8002D6AC: bgez        $v1, L_8002D6BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D6B0: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D6BC;
    }
    // 0x8002D6B0: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D6B4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D6B8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8002D6BC:
    // 0x8002D6BC: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x8002D6C0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8002D6C4: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8002D6C8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002D6CC: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x8002D6D0: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x8002D6D4: beql        $a1, $zero, L_8002D6F4
    if (ctx->r5 == 0) {
        // 0x8002D6D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002D6F4;
    }
    goto skip_0;
    // 0x8002D6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002D6DC: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x8002D6E0: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8002D6E4: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x8002D6E8: jal         0x8002C850
    // 0x8002D6EC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    LOOKUP_FUNC(0x8002C850)(rdram, ctx);
        goto after_0;
    // 0x8002D6EC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    after_0:
L_8002D6F0:
    // 0x8002D6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002D6F4:
    // 0x8002D6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D6F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002D6FC: jr          $ra
    // 0x8002D700: nop

    return;
    // 0x8002D700: nop

;}
RECOMP_FUNC void FUN_8002d704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D704: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002D708: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002D70C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002D710: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002D714: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002D718: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8002D71C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8002D720: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8002D724: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8002D728: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8002D72C: beq         $t6, $zero, L_8002D8DC
    if (ctx->r14 == 0) {
        // 0x8002D730: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_8002D8DC;
    }
    // 0x8002D730: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8002D734: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8002D738: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8002D73C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002D740: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8002D744: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8002D748: jal         0x8002DD00
    // 0x8002D74C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8002DD00)(rdram, ctx);
        goto after_0;
    // 0x8002D74C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_0:
    // 0x8002D750: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002D754: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002D758: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002D75C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8002D760: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002D764: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002D768: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D76C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002D770: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8002D774: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x8002D778: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002D77C: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002D780: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002D784: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8002D788: nop

    // 0x8002D78C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002D790: nop

    // 0x8002D794: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D798: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002D79C: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x8002D7A0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002D7A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D7A8: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x8002D7AC: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x8002D7B0: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8002D7B4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8002D7B8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8002D7BC: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8002D7C0: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D7C4: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8002D7C8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8002D7CC: nop

    // 0x8002D7D0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8002D7D4: nop

    // 0x8002D7D8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002D7DC: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8002D7E0: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8002D7E4: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x8002D7E8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8002D7EC: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8002D7F0: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8002D7F4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8002D7F8: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8002D7FC: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8002D800: addu        $s1, $t3, $t2
    ctx->r17 = ADD32(ctx->r11, ctx->r10);
    // 0x8002D804: andi        $v1, $s1, 0x7
    ctx->r3 = ctx->r17 & 0X7;
    // 0x8002D808: sra         $t4, $v1, 1
    ctx->r12 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8002D80C: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x8002D810: subu        $a1, $s1, $t1
    ctx->r5 = SUB32(ctx->r17, ctx->r9);
    // 0x8002D814: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8002D818: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x8002D81C: addu        $a3, $t0, $t4
    ctx->r7 = ADD32(ctx->r8, ctx->r12);
    // 0x8002D820: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8002D824: jal         0x8002D924
    // 0x8002D828: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8002D924)(rdram, ctx);
        goto after_1;
    // 0x8002D828: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x8002D82C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002D830: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002D834: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x8002D838: addiu       $t6, $t1, 0x280
    ctx->r14 = ADD32(ctx->r9, 0X280);
    // 0x8002D83C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8002D840: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002D844: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002D848: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8002D84C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8002D850: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002D854: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x8002D858: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8002D85C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002D860: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002D864: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002D868: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002D86C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8002D870: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8002D874: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x8002D878: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002D87C: addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
    // 0x8002D880: lw          $t2, 0x24($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X24);
    // 0x8002D884: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002D888: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x8002D88C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8002D890: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002D894: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8002D898: nop

    // 0x8002D89C: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x8002D8A0: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x8002D8A4: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8002D8A8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8002D8AC: jal         0x80028A10
    // 0x8002D8B0: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_2;
    // 0x8002D8B0: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    after_2:
    // 0x8002D8B4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002D8B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8002D8BC: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x8002D8C0: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8002D8C4: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
    // 0x8002D8C8: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x8002D8CC: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x8002D8D0: subu        $t7, $t6, $s2
    ctx->r15 = SUB32(ctx->r14, ctx->r18);
    // 0x8002D8D4: b           L_8002D908
    // 0x8002D8D8: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
        goto L_8002D908;
    // 0x8002D8D8: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
L_8002D8DC:
    // 0x8002D8DC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8002D8E0: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8002D8E4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8002D8E8: negu        $t4, $t9
    ctx->r12 = SUB32(0, ctx->r25);
    // 0x8002D8EC: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8002D8F0: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8002D8F4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8002D8F8: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    // 0x8002D8FC: jal         0x8002D924
    // 0x8002D900: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8002D924)(rdram, ctx);
        goto after_3;
    // 0x8002D900: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x8002D904: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8002D908:
    // 0x8002D908: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D90C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8002D910: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002D914: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002D918: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002D91C: jr          $ra
    // 0x8002D920: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002D920: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002d924(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002d924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D924: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8002D928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D92C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D930: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8002D934: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8002D938: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8002D93C: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8002D940: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8002D944: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8002D948: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8002D94C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8002D950: beq         $at, $zero, L_8002D95C
    if (ctx->r1 == 0) {
        // 0x8002D954: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_8002D95C;
    }
    // 0x8002D954: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x8002D958: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8002D95C:
    // 0x8002D95C: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8002D960: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x8002D964: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x8002D968: beq         $at, $zero, L_8002DA48
    if (ctx->r1 == 0) {
        // 0x8002D96C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8002DA48;
    }
    // 0x8002D96C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002D970: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8002D974: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8002D978: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x8002D97C: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8002D980: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002D984: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002D988: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8002D98C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8002D990: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002D994: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x8002D998: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8002D99C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8002D9A0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8002D9A4: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8002D9A8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8002D9AC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8002D9B0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8002D9B4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8002D9B8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8002D9BC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8002D9C0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002D9C4: jal         0x80028A10
    // 0x8002D9C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_0;
    // 0x8002D9C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8002D9CC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002D9D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002D9D4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8002D9D8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002D9DC: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x8002D9E0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8002D9E4: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    // 0x8002D9E8: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8002D9EC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002D9F0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8002D9F4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8002D9F8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8002D9FC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002DA00: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8002DA04: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x8002DA08: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002DA0C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8002DA10: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002DA14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002DA18: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x8002DA1C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8002DA20: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8002DA24: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002DA28: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x8002DA2C: jal         0x80028A10
    // 0x8002DA30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_1;
    // 0x8002DA30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8002DA34: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DA38: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DA3C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8002DA40: b           L_8002DA98
    // 0x8002DA44: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_8002DA98;
    // 0x8002DA44: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_8002DA48:
    // 0x8002DA48: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8002DA4C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8002DA50: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002DA54: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x8002DA58: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002DA5C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002DA60: addiu       $s0, $t6, 0x8
    ctx->r16 = ADD32(ctx->r14, 0X8);
    // 0x8002DA64: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002DA68: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x8002DA6C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8002DA70: sw          $a3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r7;
    // 0x8002DA74: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8002DA78: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8002DA7C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8002DA80: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002DA84: jal         0x80028A10
    // 0x8002DA88: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_2;
    // 0x8002DA88: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8002DA8C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8002DA90: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002DA94: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8002DA98:
    // 0x8002DA98: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002DA9C: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8002DAA0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8002DAA4: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8002DAA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DAAC: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8002DAB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DAB4: jr          $ra
    // 0x8002DAB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8002DAB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002dabc(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002dabc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DABC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8002DAC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002DAC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002DAC8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8002DACC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8002DAD0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8002DAD4: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8002DAD8: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8002DADC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8002DAE0: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8002DAE4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8002DAE8: beq         $at, $zero, L_8002DAF4
    if (ctx->r1 == 0) {
        // 0x8002DAEC: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_8002DAF4;
    }
    // 0x8002DAEC: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x8002DAF0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8002DAF4:
    // 0x8002DAF4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8002DAF8: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x8002DAFC: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x8002DB00: beq         $at, $zero, L_8002DBF4
    if (ctx->r1 == 0) {
        // 0x8002DB04: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8002DBF4;
    }
    // 0x8002DB04: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002DB08: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8002DB0C: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x8002DB10: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x8002DB14: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002DB18: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8002DB1C: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8002DB20: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8002DB24: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x8002DB28: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002DB2C: or          $t3, $t8, $t9
    ctx->r11 = ctx->r24 | ctx->r25;
    // 0x8002DB30: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8002DB34: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8002DB38: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8002DB3C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8002DB40: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8002DB44: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8002DB48: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8002DB4C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8002DB50: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8002DB54: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8002DB58: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002DB5C: jal         0x80028A10
    // 0x8002DB60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_0;
    // 0x8002DB60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8002DB64: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002DB68: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002DB6C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8002DB70: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002DB74: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002DB78: lui         $t5, 0x800
    ctx->r13 = S32(0X800 << 16);
    // 0x8002DB7C: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x8002DB80: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8002DB84: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8002DB88: subu        $t3, $a3, $t0
    ctx->r11 = SUB32(ctx->r7, ctx->r8);
    // 0x8002DB8C: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8002DB90: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x8002DB94: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8002DB98: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002DB9C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002DBA0: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002DBA4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002DBA8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8002DBAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002DBB0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8002DBB4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8002DBB8: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8002DBBC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002DBC0: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x8002DBC4: jal         0x80028A10
    // 0x8002DBC8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_1;
    // 0x8002DBC8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8002DBCC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DBD0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DBD4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002DBD8: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8002DBDC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8002DBE0: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x8002DBE4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8002DBE8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8002DBEC: b           L_8002DC3C
    // 0x8002DBF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8002DC3C;
    // 0x8002DBF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002DBF4:
    // 0x8002DBF4: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8002DBF8: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x8002DBFC: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x8002DC00: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8002DC04: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8002DC08: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x8002DC0C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002DC10: sll         $t3, $t8, 16
    ctx->r11 = S32(ctx->r24 << 16);
    // 0x8002DC14: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8002DC18: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8002DC1C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8002DC20: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002DC24: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8002DC28: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002DC2C: jal         0x80028A10
    // 0x8002DC30: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_2;
    // 0x8002DC30: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8002DC34: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8002DC38: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8002DC3C:
    // 0x8002DC3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DC40: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002DC44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DC48: jr          $ra
    // 0x8002DC4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8002DC4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002dc50(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002dc50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002DC54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002DC58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002DC5C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8002DC60: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8002DC64: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8002DC68: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8002DC6C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002DC70: lui         $t1, 0xB00
    ctx->r9 = S32(0XB00 << 16);
    // 0x8002DC74: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8002DC78: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8002DC7C: ori         $t1, $t1, 0x20
    ctx->r9 = ctx->r9 | 0X20;
    // 0x8002DC80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002DC84: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8002DC88: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8002DC8C: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x8002DC90: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002DC94: jal         0x80028A10
    // 0x8002DC98: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_0;
    // 0x8002DC98: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8002DC9C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DCA0: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x8002DCA4: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x8002DCA8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8002DCAC: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x8002DCB0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8002DCB4: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x8002DCB8: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8002DCBC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8002DCC0: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8002DCC4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8002DCC8: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8002DCCC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8002DCD0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002DCD4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8002DCD8: jal         0x80028A10
    // 0x8002DCDC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_1;
    // 0x8002DCDC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002DCE0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8002DCE4: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8002DCE8: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x8002DCEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DCF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DCF4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DCF8: jr          $ra
    // 0x8002DCFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002DCFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002dd00(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002dd00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DD00: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8002DD04: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002DD08: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002DD0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002DD10: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002DD14: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002DD18: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DD1C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002DD20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DD24: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8002DD28: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8002DD2C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002DD30: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8002DD34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002DD38: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8002DD3C: nop

    // 0x8002DD40: bc1fl       L_8002DD68
    if (!c1cs) {
        // 0x8002DD44: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_8002DD68;
    }
    goto skip_0;
    // 0x8002DD44: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_0:
    // 0x8002DD48: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002DD4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002DD50: nop

    // 0x8002DD54: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x8002DD58: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8002DD5C: b           L_8002DD6C
    // 0x8002DD60: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_8002DD6C;
    // 0x8002DD60: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8002DD64: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
L_8002DD68:
    // 0x8002DD68: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_8002DD6C:
    // 0x8002DD6C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002DD70: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002DD74: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002DD78: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8002DD7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002DD80: bc1fl       L_8002DD90
    if (!c1cs) {
        // 0x8002DD84: cvt.d.s     $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
            goto L_8002DD90;
    }
    goto skip_1;
    // 0x8002DD84: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    skip_1:
    // 0x8002DD88: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8002DD8C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
L_8002DD90:
    // 0x8002DD90: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8002DD94: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x8002DD98: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x8002DD9C: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8002DDA0: jr          $ra
    // 0x8002DDA4: nop

    return;
    // 0x8002DDA4: nop

    // 0x8002DDA8: nop

    // 0x8002DDAC: nop

;}
