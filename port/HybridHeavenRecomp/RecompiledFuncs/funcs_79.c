#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801ce4d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE4D4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801CE4D8: lbu         $t6, 0x8F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X8F);
    // 0x801CE4DC: lbu         $t7, 0x93($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X93);
    // 0x801CE4E0: lbu         $t8, 0x97($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X97);
    // 0x801CE4E4: lbu         $t9, 0x9B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X9B);
    // 0x801CE4E8: lbu         $t0, 0x9F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X9F);
    // 0x801CE4EC: lbu         $t1, 0xA3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XA3);
    // 0x801CE4F0: lwc1        $f12, 0xBC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801CE4F4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801CE4F8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801CE4FC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801CE500: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801CE504: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801CE508: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801CE50C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801CE510: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801CE514: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x801CE518: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x801CE51C: lbu         $t1, 0xC3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XC3);
    // 0x801CE520: lhu         $t0, 0xBA($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XBA);
    // 0x801CE524: lbu         $t9, 0xA7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XA7);
    // 0x801CE528: lbu         $t8, 0xB7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XB7);
    // 0x801CE52C: lbu         $t7, 0xB3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XB3);
    // 0x801CE530: lbu         $t6, 0xAB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAB);
    // 0x801CE534: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801CE538: lbu         $t2, 0xA7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XA7);
    // 0x801CE53C: lbu         $t3, 0xAB($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XAB);
    // 0x801CE540: lbu         $t4, 0xAF($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XAF);
    // 0x801CE544: lbu         $t5, 0xA3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XA3);
    // 0x801CE548: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801CE54C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801CE550: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801CE554: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801CE558: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801CE55C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x801CE560: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x801CE564: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x801CE568: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x801CE56C: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x801CE570: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x801CE574: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x801CE578: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x801CE57C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x801CE580: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x801CE584: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801CE588: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801CE58C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x801CE590: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x801CE594: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x801CE598: jal         0x801CE1C8
    // 0x801CE59C: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CE1C8)(rdram, ctx);
        goto after_0;
    // 0x801CE59C: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801CE5A0: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x801CE5A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801CE5A8: jr          $ra
    // 0x801CE5AC: nop

    return;
    // 0x801CE5AC: nop

;}
RECOMP_FUNC void M8_FUN_801ce5b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE5B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CE5B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CE5B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801CE5BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801CE5C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CE5C4: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801CE5C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CE5CC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801CE5D0: blez        $t6, L_801CE600
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CE5D4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801CE600;
    }
    // 0x801CE5D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CE5D8: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_801CE5DC:
    // 0x801CE5DC: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801CE5E0: jal         0x80006088
    // 0x801CE5E4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x801CE5E4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x801CE5E8: lbu         $t9, 0x94($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X94);
    // 0x801CE5EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CE5F0: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801CE5F4: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801CE5F8: bnel        $at, $zero, L_801CE5DC
    if (ctx->r1 != 0) {
        // 0x801CE5FC: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801CE5DC;
    }
    goto skip_0;
    // 0x801CE5FC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_0:
L_801CE600:
    // 0x801CE600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CE604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CE608: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE60C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801CE610: jr          $ra
    // 0x801CE614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801CE614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801ce618(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801ce618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE61C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CE624: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CE628: jal         0x8012C6B4
    // 0x801CE62C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801CE62C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_0:
    // 0x801CE630: addiu       $t6, $v0, -0x32
    ctx->r14 = ADD32(ctx->r2, -0X32);
    // 0x801CE634: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CE638: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801CE63C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CE640: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CE644: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CE648: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801CE64C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE650: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801CE654: lwc1        $f18, 0x6C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x801CE658: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801CE65C: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x801CE660: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801CE664: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x801CE668: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CE66C: jal         0x8012C6B4
    // 0x801CE670: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801CE670: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    after_1:
    // 0x801CE674: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801CE678: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE67C: ldc1        $f16, 0x3570($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X3570);
    // 0x801CE680: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x801CE684: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801CE688: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE68C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801CE690: lwc1        $f6, 0x70($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X70);
    // 0x801CE694: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x801CE698: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801CE69C: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801CE6A0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801CE6A4: jal         0x8012C6B4
    // 0x801CE6A8: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801CE6A8: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    after_2:
    // 0x801CE6AC: addiu       $t1, $v0, -0x32
    ctx->r9 = ADD32(ctx->r2, -0X32);
    // 0x801CE6B0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801CE6B4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801CE6B8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CE6BC: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801CE6C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CE6C4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x801CE6C8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE6CC: lwc1        $f18, 0x74($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X74);
    // 0x801CE6D0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801CE6D4: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x801CE6D8: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x801CE6DC: add.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f10.d + ctx->f16.d;
    // 0x801CE6E0: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801CE6E4: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
    // 0x801CE6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE6EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CE6F0: jr          $ra
    // 0x801CE6F4: nop

    return;
    // 0x801CE6F4: nop

;}
RECOMP_FUNC void M8_FUN_801ce6f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE6FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE700: jal         0x801CE618
    // 0x801CE704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CE618)(rdram, ctx);
        goto after_0;
    // 0x801CE704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CE708: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE70C: lui         $at, 0x4032
    ctx->r1 = S32(0X4032 << 16);
    // 0x801CE710: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CE714: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801CE718: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CE71C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801CE720: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801CE724: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801CE728: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x801CE72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CE734: jr          $ra
    // 0x801CE738: nop

    return;
    // 0x801CE738: nop

;}
RECOMP_FUNC void M8_FUN_801ce73c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE73C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CE748: jal         0x800058DC
    // 0x801CE74C: lw          $a1, 0x8C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CE74C: lw          $a1, 0x8C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8C);
    after_0:
    // 0x801CE750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CE758: jr          $ra
    // 0x801CE75C: nop

    return;
    // 0x801CE75C: nop

;}
RECOMP_FUNC void M8_FUN_801ce760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CE764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE768: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CE76C: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801CE770: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CE774: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801CE778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CE77C: jal         0x801CE0E8
    // 0x801CE780: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CE780: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x801CE784: bne         $v0, $zero, L_801CE798
    if (ctx->r2 != 0) {
        // 0x801CE788: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801CE798;
    }
    // 0x801CE788: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CE78C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CE790: jal         0x800058DC
    // 0x801CE794: addiu       $a1, $a1, -0x1858
    ctx->r5 = ADD32(ctx->r5, -0X1858);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CE794: addiu       $a1, $a1, -0x1858
    ctx->r5 = ADD32(ctx->r5, -0X1858);
    after_1:
L_801CE798:
    // 0x801CE798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE79C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CE7A0: jr          $ra
    // 0x801CE7A4: nop

    return;
    // 0x801CE7A4: nop

;}
RECOMP_FUNC void M8_FUN_801ce7a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE7A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CE7AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CE7B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CE7B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CE7B8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801CE7BC: lbu         $v0, 0x97($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X97);
    // 0x801CE7C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CE7C4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CE7C8: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x801CE7CC: beq         $at, $zero, L_801CE7E0
    if (ctx->r1 == 0) {
        // 0x801CE7D0: lhu         $v1, 0x3E($t8)
        ctx->r3 = MEM_HU(ctx->r24, 0X3E);
            goto L_801CE7E0;
    }
    // 0x801CE7D0: lhu         $v1, 0x3E($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X3E);
    // 0x801CE7D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801CE7D8: bne         $v0, $at, L_801CE824
    if (ctx->r2 != ctx->r1) {
        // 0x801CE7DC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_801CE824;
    }
    // 0x801CE7DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801CE7E0:
    // 0x801CE7E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CE7E4: jal         0x8012D7A8
    // 0x801CE7E8: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x801CE7E8: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_0:
    // 0x801CE7EC: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x801CE7F0: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x801CE7F4: beql        $t9, $zero, L_801CE808
    if (ctx->r25 == 0) {
        // 0x801CE7F8: lw          $t0, 0x30($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X30);
            goto L_801CE808;
    }
    goto skip_0;
    // 0x801CE7F8: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x801CE7FC: b           L_801CE824
    // 0x801CE800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_801CE824;
    // 0x801CE800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801CE804: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
L_801CE808:
    // 0x801CE808: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x801CE80C: beq         $t1, $zero, L_801CE81C
    if (ctx->r9 == 0) {
        // 0x801CE810: nop
    
            goto L_801CE81C;
    }
    // 0x801CE810: nop

    // 0x801CE814: b           L_801CE824
    // 0x801CE818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_801CE824;
    // 0x801CE818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801CE81C:
    // 0x801CE81C: b           L_801CE824
    // 0x801CE820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_801CE824;
    // 0x801CE820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_801CE824:
    // 0x801CE824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CE828: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CE82C: jal         0x801CD878
    // 0x801CE830: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_1;
    // 0x801CE830: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x801CE834: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x801CE838: lhu         $t2, 0x90($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X90);
    // 0x801CE83C: lhu         $a2, 0x24($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X24);
    // 0x801CE840: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x801CE844: slt         $v1, $t2, $v0
    ctx->r3 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CE848: beq         $v1, $zero, L_801CE858
    if (ctx->r3 == 0) {
        // 0x801CE84C: sh          $t3, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r11;
            goto L_801CE858;
    }
    // 0x801CE84C: sh          $t3, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r11;
    // 0x801CE850: bnel        $a2, $zero, L_801CE86C
    if (ctx->r6 != 0) {
        // 0x801CE854: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CE86C;
    }
    goto skip_1;
    // 0x801CE854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_801CE858:
    // 0x801CE858: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x801CE85C: lhu         $t5, 0x4C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4C);
    // 0x801CE860: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801CE864: beq         $t6, $zero, L_801CE884
    if (ctx->r14 == 0) {
        // 0x801CE868: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CE884;
    }
    // 0x801CE868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801CE86C:
    // 0x801CE86C: jal         0x801CE5B0
    // 0x801CE870: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_2;
    // 0x801CE870: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x801CE874: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CE878: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CE87C: jal         0x800058DC
    // 0x801CE880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CE880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_801CE884:
    // 0x801CE884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CE88C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CE890: jr          $ra
    // 0x801CE894: nop

    return;
    // 0x801CE894: nop

;}
RECOMP_FUNC void M8_FUN_801ce898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE89C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE8A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CE8A4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x801CE8A8: lhu         $t6, 0x4C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4C);
    // 0x801CE8AC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801CE8B0: jal         0x80005700
    // 0x801CE8B4: sh          $t7, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r15;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801CE8B4: sh          $t7, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r15;
    after_0:
    // 0x801CE8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CE8C0: jr          $ra
    // 0x801CE8C4: nop

    return;
    // 0x801CE8C4: nop

;}
RECOMP_FUNC void M8_FUN_801ce8c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE8C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CE8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE8D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CE8D4: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x801CE8D8: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    // 0x801CE8DC: jal         0x801CE0E8
    // 0x801CE8E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CE8E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CE8E4: bne         $v0, $zero, L_801CE9CC
    if (ctx->r2 != 0) {
        // 0x801CE8E8: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_801CE9CC;
    }
    // 0x801CE8E8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801CE8EC: lbu         $a0, 0x94($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X94);
    // 0x801CE8F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CE8F4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801CE8F8: blez        $a0, L_801CE9BC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801CE8FC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801CE9BC;
    }
    // 0x801CE8FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801CE900:
    // 0x801CE900: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x801CE904: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801CE908: mflo        $t7
    ctx->r15 = lo;
    // 0x801CE90C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801CE910: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801CE914: bne         $a0, $zero, L_801CE920
    if (ctx->r4 != 0) {
        // 0x801CE918: nop
    
            goto L_801CE920;
    }
    // 0x801CE918: nop

    // 0x801CE91C: break       7
    do_break(2149378332);
L_801CE920:
    // 0x801CE920: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CE924: bne         $a0, $at, L_801CE938
    if (ctx->r4 != ctx->r1) {
        // 0x801CE928: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801CE938;
    }
    // 0x801CE928: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CE92C: bne         $v1, $at, L_801CE938
    if (ctx->r3 != ctx->r1) {
        // 0x801CE930: nop
    
            goto L_801CE938;
    }
    // 0x801CE930: nop

    // 0x801CE934: break       6
    do_break(2149378356);
L_801CE938:
    // 0x801CE938: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x801CE93C: lbu         $t8, 0x94($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X94);
    // 0x801CE940: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801CE944: div         $zero, $v1, $t8
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r24)));
    // 0x801CE948: mflo        $t9
    ctx->r25 = lo;
    // 0x801CE94C: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x801CE950: lbu         $t0, 0x94($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X94);
    // 0x801CE954: bne         $t8, $zero, L_801CE960
    if (ctx->r24 != 0) {
        // 0x801CE958: nop
    
            goto L_801CE960;
    }
    // 0x801CE958: nop

    // 0x801CE95C: break       7
    do_break(2149378396);
L_801CE960:
    // 0x801CE960: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CE964: bne         $t8, $at, L_801CE978
    if (ctx->r24 != ctx->r1) {
        // 0x801CE968: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801CE978;
    }
    // 0x801CE968: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CE96C: bne         $v1, $at, L_801CE978
    if (ctx->r3 != ctx->r1) {
        // 0x801CE970: nop
    
            goto L_801CE978;
    }
    // 0x801CE970: nop

    // 0x801CE974: break       6
    do_break(2149378420);
L_801CE978:
    // 0x801CE978: div         $zero, $v1, $t0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r8)));
    // 0x801CE97C: mflo        $t1
    ctx->r9 = lo;
    // 0x801CE980: sh          $t1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r9;
    // 0x801CE984: bne         $t0, $zero, L_801CE990
    if (ctx->r8 != 0) {
        // 0x801CE988: nop
    
            goto L_801CE990;
    }
    // 0x801CE988: nop

    // 0x801CE98C: break       7
    do_break(2149378444);
L_801CE990:
    // 0x801CE990: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CE994: bne         $t0, $at, L_801CE9A8
    if (ctx->r8 != ctx->r1) {
        // 0x801CE998: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801CE9A8;
    }
    // 0x801CE998: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CE99C: bne         $v1, $at, L_801CE9A8
    if (ctx->r3 != ctx->r1) {
        // 0x801CE9A0: nop
    
            goto L_801CE9A8;
    }
    // 0x801CE9A0: nop

    // 0x801CE9A4: break       6
    do_break(2149378468);
L_801CE9A8:
    // 0x801CE9A8: lbu         $a0, 0x94($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X94);
    // 0x801CE9AC: addiu       $v1, $v1, 0x2000
    ctx->r3 = ADD32(ctx->r3, 0X2000);
    // 0x801CE9B0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801CE9B4: bne         $at, $zero, L_801CE900
    if (ctx->r1 != 0) {
        // 0x801CE9B8: nop
    
            goto L_801CE900;
    }
    // 0x801CE9B8: nop

L_801CE9BC:
    // 0x801CE9BC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CE9C0: addiu       $a1, $a1, -0x1624
    ctx->r5 = ADD32(ctx->r5, -0X1624);
    // 0x801CE9C4: jal         0x800058DC
    // 0x801CE9C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CE9C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
L_801CE9CC:
    // 0x801CE9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE9D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CE9D4: jr          $ra
    // 0x801CE9D8: nop

    return;
    // 0x801CE9D8: nop

;}
RECOMP_FUNC void M8_FUN_801ce9dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE9DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE9E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CE9E8: jal         0x801CD878
    // 0x801CE9EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801CE9EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CE9F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801CE9F4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE9F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CE9FC: lbu         $a0, 0x94($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X94);
    // 0x801CEA00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEA04: blezl       $a0, L_801CEAA4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801CEA08: lhu         $v0, 0x92($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X92);
            goto L_801CEAA4;
    }
    goto skip_0;
    // 0x801CEA08: lhu         $v0, 0x92($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X92);
    skip_0:
    // 0x801CEA0C: ldc1        $f2, 0x3578($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X3578);
    // 0x801CEA10: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x801CEA14: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801CEA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801CEA1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CEA20: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_801CEA24:
    // 0x801CEA24: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x801CEA28: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CEA2C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CEA30: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801CEA34: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801CEA38: lh          $t9, 0x10($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X10);
    // 0x801CEA3C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801CEA40: nop

    // 0x801CEA44: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801CEA48: bgez        $a0, L_801CEA58
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801CEA4C: sra         $t0, $a0, 1
        ctx->r8 = S32(SIGNED(ctx->r4) >> 1);
            goto L_801CEA58;
    }
    // 0x801CEA4C: sra         $t0, $a0, 1
    ctx->r8 = S32(SIGNED(ctx->r4) >> 1);
    // 0x801CEA50: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x801CEA54: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_801CEA58:
    // 0x801CEA58: subu        $t1, $a1, $t0
    ctx->r9 = SUB32(ctx->r5, ctx->r8);
    // 0x801CEA5C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801CEA60: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801CEA64: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801CEA68: sub.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d - ctx->f2.d;
    // 0x801CEA6C: mul.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x801CEA70: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x801CEA74: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x801CEA78: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x801CEA7C: nop

    // 0x801CEA80: sh          $t3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r11;
    // 0x801CEA84: lh          $t4, 0x10($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X10);
    // 0x801CEA88: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x801CEA8C: sh          $t5, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r13;
    // 0x801CEA90: lbu         $a0, 0x94($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X94);
    // 0x801CEA94: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801CEA98: bnel        $at, $zero, L_801CEA24
    if (ctx->r1 != 0) {
        // 0x801CEA9C: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_801CEA24;
    }
    goto skip_1;
    // 0x801CEA9C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    skip_1:
    // 0x801CEAA0: lhu         $v0, 0x92($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X92);
L_801CEAA4:
    // 0x801CEAA4: lhu         $t6, 0x90($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X90);
    // 0x801CEAA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801CEAAC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801CEAB0: slt         $v1, $t6, $v0
    ctx->r3 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CEAB4: bne         $v1, $zero, L_801CEACC
    if (ctx->r3 != 0) {
        // 0x801CEAB8: sh          $t7, 0x92($a2)
        MEM_H(0X92, ctx->r6) = ctx->r15;
            goto L_801CEACC;
    }
    // 0x801CEAB8: sh          $t7, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r15;
    // 0x801CEABC: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x801CEAC0: lhu         $t9, 0x4C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4C);
    // 0x801CEAC4: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801CEAC8: beq         $t0, $zero, L_801CEAE8
    if (ctx->r8 == 0) {
        // 0x801CEACC: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_801CEAE8;
    }
L_801CEACC:
    // 0x801CEACC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801CEAD0: jal         0x801CE5B0
    // 0x801CEAD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801CEAD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x801CEAD8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEADC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CEAE0: jal         0x800058DC
    // 0x801CEAE4: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CEAE4: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
L_801CEAE8:
    // 0x801CEAE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CEAEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CEAF0: jr          $ra
    // 0x801CEAF4: nop

    return;
    // 0x801CEAF4: nop

;}
RECOMP_FUNC void M8_FUN_801ceaf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEAF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CEAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CEB00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CEB04: sb          $zero, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = 0;
    // 0x801CEB08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CEB0C: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801CEB10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CEB14: jal         0x801CE0E8
    // 0x801CEB18: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CEB18: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    after_0:
    // 0x801CEB1C: bne         $v0, $zero, L_801CEB54
    if (ctx->r2 != 0) {
        // 0x801CEB20: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801CEB54;
    }
    // 0x801CEB20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CEB24: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x801CEB28: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801CEB2C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEB30: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801CEB34: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CEB38: addiu       $a1, $a1, -0x149C
    ctx->r5 = ADD32(ctx->r5, -0X149C);
    // 0x801CEB3C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801CEB40: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801CEB44: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CEB48: lh          $t3, 0x12($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X12);
    // 0x801CEB4C: jal         0x800058DC
    // 0x801CEB50: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CEB50: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    after_1:
L_801CEB54:
    // 0x801CEB54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CEB58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CEB5C: jr          $ra
    // 0x801CEB60: nop

    return;
    // 0x801CEB60: nop

;}
RECOMP_FUNC void M8_FUN_801ceb64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEB64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CEB68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CEB6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CEB70: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CEB74: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801CEB78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CEB7C: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801CEB80: jal         0x8012D7A8
    // 0x801CEB84: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x801CEB84: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801CEB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CEB8C: jal         0x801CD878
    // 0x801CEB90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_1;
    // 0x801CEB90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801CEB94: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801CEB98: lbu         $a0, 0x48($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X48);
    // 0x801CEB9C: lbu         $a1, 0x49($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X49);
    // 0x801CEBA0: lbu         $a2, 0x4A($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X4A);
    // 0x801CEBA4: jal         0x801CD994
    // 0x801CEBA8: lbu         $a3, 0x4B($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X4B);
    LOOKUP_FUNC(0x801CD994)(rdram, ctx);
        goto after_2;
    // 0x801CEBA8: lbu         $a3, 0x4B($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X4B);
    after_2:
    // 0x801CEBAC: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x801CEBB0: lhu         $t8, 0x90($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X90);
    // 0x801CEBB4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801CEBB8: slt         $v1, $t8, $v0
    ctx->r3 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CEBBC: bne         $v1, $zero, L_801CEBD8
    if (ctx->r3 != 0) {
        // 0x801CEBC0: sh          $t9, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r25;
            goto L_801CEBD8;
    }
    // 0x801CEBC0: sh          $t9, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r25;
    // 0x801CEBC4: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x801CEBC8: lhu         $t1, 0x4C($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4C);
    // 0x801CEBCC: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x801CEBD0: beql        $t2, $zero, L_801CEC00
    if (ctx->r10 == 0) {
        // 0x801CEBD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CEC00;
    }
    goto skip_0;
    // 0x801CEBD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_801CEBD8:
    // 0x801CEBD8: jal         0x801CBD70
    // 0x801CEBDC: nop

    LOOKUP_FUNC(0x801CBD70)(rdram, ctx);
        goto after_3;
    // 0x801CEBDC: nop

    after_3:
    // 0x801CEBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CEBE4: jal         0x801CE5B0
    // 0x801CEBE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_4;
    // 0x801CEBE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x801CEBEC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEBF0: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CEBF4: jal         0x800058DC
    // 0x801CEBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801CEBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801CEBFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CEC00:
    // 0x801CEC00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CEC04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CEC08: jr          $ra
    // 0x801CEC0C: nop

    return;
    // 0x801CEC0C: nop

;}
RECOMP_FUNC void M8_FUN_801cec10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEC10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CEC14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801CEC18: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801CEC1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CEC20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801CEC24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CEC28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CEC2C: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x801CEC30: jal         0x801CE0E8
    // 0x801CEC34: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CEC34: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    after_0:
    // 0x801CEC38: bnel        $v0, $zero, L_801CEC90
    if (ctx->r2 != 0) {
        // 0x801CEC3C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801CEC90;
    }
    goto skip_0;
    // 0x801CEC3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801CEC40: lbu         $t6, 0x94($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X94);
    // 0x801CEC44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CEC48: blez        $t6, L_801CEC7C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CEC4C: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801CEC7C;
    }
    // 0x801CEC4C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_801CEC50:
    // 0x801CEC50: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801CEC54: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CEC58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CEC5C: jal         0x801CE618
    // 0x801CEC60: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x801CE618)(rdram, ctx);
        goto after_1;
    // 0x801CEC60: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    after_1:
    // 0x801CEC64: lbu         $t0, 0x94($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X94);
    // 0x801CEC68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CEC6C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CEC70: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801CEC74: bnel        $at, $zero, L_801CEC50
    if (ctx->r1 != 0) {
        // 0x801CEC78: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801CEC50;
    }
    goto skip_1;
    // 0x801CEC78: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_1:
L_801CEC7C:
    // 0x801CEC7C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEC80: addiu       $a1, $a1, -0x135C
    ctx->r5 = ADD32(ctx->r5, -0X135C);
    // 0x801CEC84: jal         0x800058DC
    // 0x801CEC88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CEC88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801CEC8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CEC90:
    // 0x801CEC90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CEC94: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801CEC98: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801CEC9C: jr          $ra
    // 0x801CECA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801CECA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801ceca4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801ceca4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CECA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801CECA8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801CECAC: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801CECB0: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801CECB4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801CECB8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801CECBC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801CECC0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801CECC4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801CECC8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801CECCC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801CECD0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801CECD4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801CECD8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801CECDC: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801CECE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CECE4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801CECE8: blez        $t6, L_801CEE6C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CECEC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801CEE6C;
    }
    // 0x801CECEC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801CECF0: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x801CECF4: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x801CECF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CECFC: ldc1        $f28, 0x3580($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X3580);
    // 0x801CED00: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801CED04: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801CED08: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801CED0C: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801CED10: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x801CED14: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CED18: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801CED1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801CED20: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x801CED24: lhu         $t7, 0x92($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X92);
L_801CED28:
    // 0x801CED28: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x801CED2C: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x801CED30: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x801CED34: div         $zero, $t8, $s4
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r20)));
    // 0x801CED38: mfhi        $t9
    ctx->r25 = hi;
    // 0x801CED3C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801CED40: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801CED44: bne         $s4, $zero, L_801CED50
    if (ctx->r20 != 0) {
        // 0x801CED48: nop
    
            goto L_801CED50;
    }
    // 0x801CED48: nop

    // 0x801CED4C: break       7
    do_break(2149379404);
L_801CED50:
    // 0x801CED50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CED54: bne         $s4, $at, L_801CED68
    if (ctx->r20 != ctx->r1) {
        // 0x801CED58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801CED68;
    }
    // 0x801CED58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CED5C: bne         $t8, $at, L_801CED68
    if (ctx->r24 != ctx->r1) {
        // 0x801CED60: nop
    
            goto L_801CED68;
    }
    // 0x801CED60: nop

    // 0x801CED64: break       6
    do_break(2149379428);
L_801CED68:
    // 0x801CED68: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801CED6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CED70: lw          $s0, 0x30($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X30);
    // 0x801CED74: div.d       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f26.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f26.d);
    // 0x801CED78: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    // 0x801CED7C: cvt.d.s     $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f22.d = CVT_D_S(ctx->f20.fl);
    // 0x801CED80: c.lt.d      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.d < ctx->f28.d;
    // 0x801CED84: nop

    // 0x801CED88: bc1fl       L_801CED9C
    if (!c1cs) {
        // 0x801CED8C: lwc1        $f10, 0x8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
            goto L_801CED9C;
    }
    goto skip_0;
    // 0x801CED8C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x801CED90: jal         0x801CE618
    // 0x801CED94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CE618)(rdram, ctx);
        goto after_0;
    // 0x801CED94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801CED98: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
L_801CED9C:
    // 0x801CED9C: lh          $t3, 0x14($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X14);
    // 0x801CEDA0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CEDA4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801CEDA8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801CEDAC: add.d       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f18.d = ctx->f16.d + ctx->f24.d;
    // 0x801CEDB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CEDB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801CEDB8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801CEDBC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801CEDC0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801CEDC4: lbu         $t4, 0x94($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X94);
    // 0x801CEDC8: bgez        $t4, L_801CEDD8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801CEDCC: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_801CEDD8;
    }
    // 0x801CEDCC: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x801CEDD0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x801CEDD4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_801CEDD8:
    // 0x801CEDD8: subu        $t6, $s3, $t5
    ctx->r14 = SUB32(ctx->r19, ctx->r13);
    // 0x801CEDDC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801CEDE0: nop

    // 0x801CEDE4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x801CEDE8: sub.d       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f18.d = ctx->f16.d - ctx->f24.d;
    // 0x801CEDEC: mul.d       $f4, $f30, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f30.d, ctx->f18.d);
    // 0x801CEDF0: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801CEDF4: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801CEDF8: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x801CEDFC: nop

    // 0x801CEE00: sh          $t8, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r24;
    // 0x801CEE04: lh          $t9, 0x14($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X14);
    // 0x801CEE08: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x801CEE0C: jal         0x801CD5E0
    // 0x801CEE10: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_1;
    // 0x801CEE10: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
    after_1:
    // 0x801CEE14: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CEE18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CEE1C: jal         0x801CD728
    // 0x801CEE20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_2;
    // 0x801CEE20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801CEE24: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801CEE28: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CEE2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CEE30: lwc1        $f16, 0x60($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X60);
    // 0x801CEE34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801CEE38: sub.d       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = ctx->f8.d - ctx->f22.d;
    // 0x801CEE3C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801CEE40: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x801CEE44: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801CEE48: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x801CEE4C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801CEE50: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801CEE54: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801CEE58: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801CEE5C: lbu         $t1, 0x94($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X94);
    // 0x801CEE60: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801CEE64: bnel        $at, $zero, L_801CED28
    if (ctx->r1 != 0) {
        // 0x801CEE68: lhu         $t7, 0x92($s1)
        ctx->r15 = MEM_HU(ctx->r17, 0X92);
            goto L_801CED28;
    }
    goto skip_1;
    // 0x801CEE68: lhu         $t7, 0x92($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X92);
    skip_1:
L_801CEE6C:
    // 0x801CEE6C: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801CEE70: lhu         $t2, 0x90($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X90);
    // 0x801CEE74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CEE78: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x801CEE7C: slt         $v1, $t2, $v0
    ctx->r3 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CEE80: bne         $v1, $zero, L_801CEE9C
    if (ctx->r3 != 0) {
        // 0x801CEE84: sh          $t3, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r11;
            goto L_801CEE9C;
    }
    // 0x801CEE84: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    // 0x801CEE88: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x801CEE8C: lhu         $t5, 0x4C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4C);
    // 0x801CEE90: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801CEE94: beql        $t6, $zero, L_801CEEB8
    if (ctx->r14 == 0) {
        // 0x801CEE98: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801CEEB8;
    }
    goto skip_2;
    // 0x801CEE98: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
L_801CEE9C:
    // 0x801CEE9C: jal         0x801CE5B0
    // 0x801CEEA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801CEEA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x801CEEA4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEEA8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CEEAC: jal         0x800058DC
    // 0x801CEEB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CEEB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801CEEB4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801CEEB8:
    // 0x801CEEB8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801CEEBC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801CEEC0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801CEEC4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801CEEC8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801CEECC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801CEED0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801CEED4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801CEED8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801CEEDC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801CEEE0: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801CEEE4: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801CEEE8: jr          $ra
    // 0x801CEEEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801CEEEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801ceef0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801ceef0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEEF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CEEF4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801CEEF8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801CEEFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CEF00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801CEF04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CEF08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CEF0C: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x801CEF10: jal         0x801CE0E8
    // 0x801CEF14: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CEF14: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    after_0:
    // 0x801CEF18: bnel        $v0, $zero, L_801CEF70
    if (ctx->r2 != 0) {
        // 0x801CEF1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801CEF70;
    }
    goto skip_0;
    // 0x801CEF1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801CEF20: lbu         $t6, 0x94($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X94);
    // 0x801CEF24: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CEF28: blez        $t6, L_801CEF5C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CEF2C: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801CEF5C;
    }
    // 0x801CEF2C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_801CEF30:
    // 0x801CEF30: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801CEF34: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CEF38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CEF3C: jal         0x801CE618
    // 0x801CEF40: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x801CE618)(rdram, ctx);
        goto after_1;
    // 0x801CEF40: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    after_1:
    // 0x801CEF44: lbu         $t0, 0x94($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X94);
    // 0x801CEF48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CEF4C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CEF50: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801CEF54: bnel        $at, $zero, L_801CEF30
    if (ctx->r1 != 0) {
        // 0x801CEF58: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801CEF30;
    }
    goto skip_1;
    // 0x801CEF58: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_1:
L_801CEF5C:
    // 0x801CEF5C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEF60: addiu       $a1, $a1, -0x107C
    ctx->r5 = ADD32(ctx->r5, -0X107C);
    // 0x801CEF64: jal         0x800058DC
    // 0x801CEF68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CEF68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801CEF6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CEF70:
    // 0x801CEF70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CEF74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801CEF78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801CEF7C: jr          $ra
    // 0x801CEF80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801CEF80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cef84(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cef84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEF84: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801CEF88: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801CEF8C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801CEF90: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801CEF94: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801CEF98: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801CEF9C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801CEFA0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801CEFA4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801CEFA8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801CEFAC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801CEFB0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801CEFB4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801CEFB8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801CEFBC: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801CEFC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CEFC4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801CEFC8: blez        $t6, L_801CF14C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CEFCC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801CF14C;
    }
    // 0x801CEFCC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801CEFD0: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x801CEFD4: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x801CEFD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEFDC: ldc1        $f28, 0x3588($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X3588);
    // 0x801CEFE0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801CEFE4: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801CEFE8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801CEFEC: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801CEFF0: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x801CEFF4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CEFF8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801CEFFC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801CF000: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x801CF004: lhu         $t7, 0x92($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X92);
L_801CF008:
    // 0x801CF008: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x801CF00C: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x801CF010: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x801CF014: div         $zero, $t8, $s4
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r20)));
    // 0x801CF018: mfhi        $t9
    ctx->r25 = hi;
    // 0x801CF01C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801CF020: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801CF024: bne         $s4, $zero, L_801CF030
    if (ctx->r20 != 0) {
        // 0x801CF028: nop
    
            goto L_801CF030;
    }
    // 0x801CF028: nop

    // 0x801CF02C: break       7
    do_break(2149380140);
L_801CF030:
    // 0x801CF030: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CF034: bne         $s4, $at, L_801CF048
    if (ctx->r20 != ctx->r1) {
        // 0x801CF038: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801CF048;
    }
    // 0x801CF038: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CF03C: bne         $t8, $at, L_801CF048
    if (ctx->r24 != ctx->r1) {
        // 0x801CF040: nop
    
            goto L_801CF048;
    }
    // 0x801CF040: nop

    // 0x801CF044: break       6
    do_break(2149380164);
L_801CF048:
    // 0x801CF048: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801CF04C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CF050: lw          $s0, 0x30($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X30);
    // 0x801CF054: div.d       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f26.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f26.d);
    // 0x801CF058: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    // 0x801CF05C: cvt.d.s     $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f22.d = CVT_D_S(ctx->f20.fl);
    // 0x801CF060: c.lt.d      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.d < ctx->f28.d;
    // 0x801CF064: nop

    // 0x801CF068: bc1fl       L_801CF07C
    if (!c1cs) {
        // 0x801CF06C: lwc1        $f10, 0x8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
            goto L_801CF07C;
    }
    goto skip_0;
    // 0x801CF06C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x801CF070: jal         0x801CE618
    // 0x801CF074: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CE618)(rdram, ctx);
        goto after_0;
    // 0x801CF074: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801CF078: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
L_801CF07C:
    // 0x801CF07C: lh          $t3, 0x14($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X14);
    // 0x801CF080: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CF084: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801CF088: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801CF08C: add.d       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f18.d = ctx->f16.d + ctx->f24.d;
    // 0x801CF090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CF094: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801CF098: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801CF09C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801CF0A0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801CF0A4: lbu         $t4, 0x94($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X94);
    // 0x801CF0A8: bgez        $t4, L_801CF0B8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801CF0AC: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_801CF0B8;
    }
    // 0x801CF0AC: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x801CF0B0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x801CF0B4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_801CF0B8:
    // 0x801CF0B8: subu        $t6, $s3, $t5
    ctx->r14 = SUB32(ctx->r19, ctx->r13);
    // 0x801CF0BC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801CF0C0: nop

    // 0x801CF0C4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x801CF0C8: sub.d       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f18.d = ctx->f16.d - ctx->f24.d;
    // 0x801CF0CC: mul.d       $f4, $f30, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f30.d, ctx->f18.d);
    // 0x801CF0D0: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801CF0D4: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801CF0D8: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x801CF0DC: nop

    // 0x801CF0E0: sh          $t8, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r24;
    // 0x801CF0E4: lh          $t9, 0x14($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X14);
    // 0x801CF0E8: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x801CF0EC: jal         0x801CD5E0
    // 0x801CF0F0: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_1;
    // 0x801CF0F0: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
    after_1:
    // 0x801CF0F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CF0F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CF0FC: jal         0x801CD728
    // 0x801CF100: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_2;
    // 0x801CF100: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801CF104: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801CF108: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CF10C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CF110: lwc1        $f16, 0x60($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X60);
    // 0x801CF114: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801CF118: sub.d       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = ctx->f8.d - ctx->f22.d;
    // 0x801CF11C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801CF120: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x801CF124: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801CF128: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x801CF12C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801CF130: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801CF134: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801CF138: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801CF13C: lbu         $t1, 0x94($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X94);
    // 0x801CF140: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801CF144: bnel        $at, $zero, L_801CF008
    if (ctx->r1 != 0) {
        // 0x801CF148: lhu         $t7, 0x92($s1)
        ctx->r15 = MEM_HU(ctx->r17, 0X92);
            goto L_801CF008;
    }
    goto skip_1;
    // 0x801CF148: lhu         $t7, 0x92($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X92);
    skip_1:
L_801CF14C:
    // 0x801CF14C: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801CF150: lhu         $t2, 0x90($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X90);
    // 0x801CF154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CF158: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x801CF15C: slt         $v1, $t2, $v0
    ctx->r3 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CF160: bne         $v1, $zero, L_801CF17C
    if (ctx->r3 != 0) {
        // 0x801CF164: sh          $t3, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r11;
            goto L_801CF17C;
    }
    // 0x801CF164: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    // 0x801CF168: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x801CF16C: lhu         $t5, 0x4C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4C);
    // 0x801CF170: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801CF174: beql        $t6, $zero, L_801CF198
    if (ctx->r14 == 0) {
        // 0x801CF178: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801CF198;
    }
    goto skip_2;
    // 0x801CF178: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
L_801CF17C:
    // 0x801CF17C: jal         0x801CE5B0
    // 0x801CF180: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801CF180: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x801CF184: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF188: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CF18C: jal         0x800058DC
    // 0x801CF190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CF190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801CF194: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801CF198:
    // 0x801CF198: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801CF19C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801CF1A0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801CF1A4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801CF1A8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801CF1AC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801CF1B0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801CF1B4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801CF1B8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801CF1BC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801CF1C0: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801CF1C4: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801CF1C8: jr          $ra
    // 0x801CF1CC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801CF1CC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cf1d0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cf1d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF1D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CF1D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF1D8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CF1DC: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x801CF1E0: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    // 0x801CF1E4: jal         0x801CE0E8
    // 0x801CF1E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CF1E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF1EC: bne         $v0, $zero, L_801CF2C4
    if (ctx->r2 != 0) {
        // 0x801CF1F0: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_801CF2C4;
    }
    // 0x801CF1F0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801CF1F4: lbu         $t6, 0x94($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X94);
    // 0x801CF1F8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF1FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CF200: blez        $t6, L_801CF2BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CF204: addiu       $a1, $a1, -0xD2C
        ctx->r5 = ADD32(ctx->r5, -0XD2C);
            goto L_801CF2BC;
    }
    // 0x801CF204: addiu       $a1, $a1, -0xD2C
    ctx->r5 = ADD32(ctx->r5, -0XD2C);
    // 0x801CF208: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF20C: ldc1        $f14, 0x3590($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X3590);
    // 0x801CF210: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801CF214: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801CF218: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801CF21C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801CF220: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801CF224: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801CF228: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801CF22C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_801CF230:
    // 0x801CF230: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801CF234: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CF238: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
    // 0x801CF23C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801CF240: lbu         $t9, 0x94($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X94);
    // 0x801CF244: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801CF248: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801CF24C: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x801CF250: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801CF254: bgez        $t9, L_801CF26C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801CF258: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_801CF26C;
    }
    // 0x801CF258: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x801CF25C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801CF260: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801CF264: nop

    // 0x801CF268: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_801CF26C:
    // 0x801CF26C: div.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x801CF270: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CF274: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CF278: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801CF27C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801CF280: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x801CF284: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x801CF288: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801CF28C: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x801CF290: lwc1        $f4, 0x60($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X60);
    // 0x801CF294: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801CF298: mul.d       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x801CF29C: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x801CF2A0: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801CF2A4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801CF2A8: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801CF2AC: lbu         $t0, 0x94($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X94);
    // 0x801CF2B0: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801CF2B4: bnel        $at, $zero, L_801CF230
    if (ctx->r1 != 0) {
        // 0x801CF2B8: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_801CF230;
    }
    goto skip_0;
    // 0x801CF2B8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_801CF2BC:
    // 0x801CF2BC: jal         0x800058DC
    // 0x801CF2C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CF2C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_801CF2C4:
    // 0x801CF2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CF2C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CF2CC: jr          $ra
    // 0x801CF2D0: nop

    return;
    // 0x801CF2D0: nop

;}
RECOMP_FUNC void M8_FUN_801cf2d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF2D4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801CF2D8: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x801CF2DC: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x801CF2E0: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x801CF2E4: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x801CF2E8: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x801CF2EC: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x801CF2F0: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x801CF2F4: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x801CF2F8: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x801CF2FC: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x801CF300: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x801CF304: lhu         $v1, 0x90($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X90);
    // 0x801CF308: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801CF30C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801CF310: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801CF314: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CF318: bgez        $v1, L_801CF330
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801CF31C: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801CF330;
    }
    // 0x801CF31C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801CF320: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CF324: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CF328: nop

    // 0x801CF32C: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801CF330:
    // 0x801CF330: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF334: ldc1        $f10, 0x3598($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3598);
    // 0x801CF338: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CF33C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801CF340: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801CF344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CF348: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801CF34C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CF350: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CF354: nop

    // 0x801CF358: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x801CF35C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CF360: nop

    // 0x801CF364: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801CF368: beql        $t7, $zero, L_801CF3BC
    if (ctx->r15 == 0) {
        // 0x801CF36C: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_801CF3BC;
    }
    goto skip_0;
    // 0x801CF36C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801CF370: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801CF374: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801CF378: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CF37C: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x801CF380: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CF384: nop

    // 0x801CF388: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x801CF38C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CF390: nop

    // 0x801CF394: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801CF398: bne         $t7, $zero, L_801CF3B0
    if (ctx->r15 != 0) {
        // 0x801CF39C: nop
    
            goto L_801CF3B0;
    }
    // 0x801CF39C: nop

    // 0x801CF3A0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x801CF3A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CF3A8: b           L_801CF3C8
    // 0x801CF3AC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801CF3C8;
    // 0x801CF3AC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801CF3B0:
    // 0x801CF3B0: b           L_801CF3C8
    // 0x801CF3B4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801CF3C8;
    // 0x801CF3B4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801CF3B8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_801CF3BC:
    // 0x801CF3BC: nop

    // 0x801CF3C0: bltz        $t7, L_801CF3B0
    if (SIGNED(ctx->r15) < 0) {
        // 0x801CF3C4: nop
    
            goto L_801CF3B0;
    }
    // 0x801CF3C4: nop

L_801CF3C8:
    // 0x801CF3C8: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x801CF3CC: lbu         $a2, 0x94($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X94);
    // 0x801CF3D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CF3D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801CF3D8: blez        $a2, L_801CF554
    if (SIGNED(ctx->r6) <= 0) {
        // 0x801CF3DC: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CF554;
    }
    // 0x801CF3DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF3E0: lwc1        $f24, 0x35A0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X35A0);
    // 0x801CF3E4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801CF3E8: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801CF3EC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801CF3F0: andi        $s5, $t7, 0xFFFF
    ctx->r21 = ctx->r15 & 0XFFFF;
L_801CF3F4:
    // 0x801CF3F4: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CF3F8: lhu         $t8, 0x92($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X92);
    // 0x801CF3FC: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x801CF400: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x801CF404: mflo        $t9
    ctx->r25 = lo;
    // 0x801CF408: subu        $s1, $t8, $t9
    ctx->r17 = SUB32(ctx->r24, ctx->r25);
    // 0x801CF40C: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x801CF410: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x801CF414: bltzl       $s1, L_801CF430
    if (SIGNED(ctx->r17) < 0) {
        // 0x801CF418: lw          $t3, 0x0($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X0);
            goto L_801CF430;
    }
    goto skip_1;
    // 0x801CF418: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    skip_1:
    // 0x801CF41C: lhu         $v1, 0x90($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X90);
    // 0x801CF420: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x801CF424: beql        $at, $zero, L_801CF43C
    if (ctx->r1 == 0) {
        // 0x801CF428: mtc1        $s1, $f4
        ctx->f4.u32l = ctx->r17;
            goto L_801CF43C;
    }
    goto skip_2;
    // 0x801CF428: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    skip_2:
    // 0x801CF42C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
L_801CF430:
    // 0x801CF430: b           L_801CF538
    // 0x801CF434: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
        goto L_801CF538;
    // 0x801CF434: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
    // 0x801CF438: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
L_801CF43C:
    // 0x801CF43C: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x801CF440: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CF444: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CF448: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801CF44C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801CF450: bgez        $v1, L_801CF464
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801CF454: add.d       $f10, $f6, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f6.d + ctx->f22.d;
            goto L_801CF464;
    }
    // 0x801CF454: add.d       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f6.d + ctx->f22.d;
    // 0x801CF458: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CF45C: nop

    // 0x801CF460: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801CF464:
    // 0x801CF464: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801CF468: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x801CF46C: add.d       $f6, $f8, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f6.d = ctx->f8.d + ctx->f22.d;
    // 0x801CF470: addu        $v0, $s4, $t4
    ctx->r2 = ADD32(ctx->r20, ctx->r12);
    // 0x801CF474: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801CF478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801CF47C: div.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x801CF480: sb          $s6, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r22;
    // 0x801CF484: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801CF488: lw          $s0, 0x30($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X30);
    // 0x801CF48C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801CF490: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    // 0x801CF494: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CF498: jal         0x801CD5E0
    // 0x801CF49C: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_0;
    // 0x801CF49C: nop

    after_0:
    // 0x801CF4A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CF4A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801CF4A8: jal         0x801CD728
    // 0x801CF4AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_1;
    // 0x801CF4AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801CF4B0: lwc1        $f4, 0x60($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X60);
    // 0x801CF4B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801CF4B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801CF4BC: mul.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801CF4C0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801CF4C4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801CF4C8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801CF4CC: lhu         $t7, 0x90($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X90);
    // 0x801CF4D0: bnel        $s1, $t7, L_801CF53C
    if (ctx->r17 != ctx->r15) {
        // 0x801CF4D4: lbu         $a2, 0x94($s2)
        ctx->r6 = MEM_BU(ctx->r18, 0X94);
            goto L_801CF53C;
    }
    goto skip_3;
    // 0x801CF4D4: lbu         $a2, 0x94($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X94);
    skip_3:
    // 0x801CF4D8: lwc1        $f18, 0x74($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X74);
    // 0x801CF4DC: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x801CF4E0: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x801CF4E4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801CF4E8: lbu         $v0, 0x78($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X78);
    // 0x801CF4EC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801CF4F0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801CF4F4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x801CF4F8: lbu         $v1, 0x79($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X79);
    // 0x801CF4FC: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x801CF500: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x801CF504: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801CF508: lbu         $t0, 0x7A($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X7A);
    // 0x801CF50C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801CF510: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x801CF514: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x801CF518: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801CF51C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CF520: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801CF524: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801CF528: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x801CF52C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801CF530: jal         0x801CE330
    // 0x801CF534: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_2;
    // 0x801CF534: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
L_801CF538:
    // 0x801CF538: lbu         $a2, 0x94($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X94);
L_801CF53C:
    // 0x801CF53C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801CF540: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801CF544: slt         $at, $s3, $a2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801CF548: bne         $at, $zero, L_801CF3F4
    if (ctx->r1 != 0) {
        // 0x801CF54C: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_801CF3F4;
    }
    // 0x801CF54C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x801CF550: lhu         $v1, 0x90($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X90);
L_801CF554:
    // 0x801CF554: lhu         $t3, 0x8C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X8C);
    // 0x801CF558: lhu         $v0, 0x92($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X92);
    // 0x801CF55C: multu       $a2, $t3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CF560: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801CF564: sh          $t6, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r14;
    // 0x801CF568: mflo        $t4
    ctx->r12 = lo;
    // 0x801CF56C: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x801CF570: slt         $a0, $t5, $v0
    ctx->r4 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CF574: beql        $a0, $zero, L_801CF594
    if (ctx->r4 == 0) {
        // 0x801CF578: lw          $t9, 0xC($s2)
        ctx->r25 = MEM_W(ctx->r18, 0XC);
            goto L_801CF594;
    }
    goto skip_4;
    // 0x801CF578: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    skip_4:
    // 0x801CF57C: lhu         $t7, 0x4C($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X4C);
    // 0x801CF580: lhu         $t8, 0x4E($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X4E);
    // 0x801CF584: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CF588: beql        $at, $zero, L_801CF5A4
    if (ctx->r1 == 0) {
        // 0x801CF58C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801CF5A4;
    }
    goto skip_5;
    // 0x801CF58C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_5:
    // 0x801CF590: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
L_801CF594:
    // 0x801CF594: lhu         $t1, 0x4C($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4C);
    // 0x801CF598: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x801CF59C: beq         $t2, $zero, L_801CF5BC
    if (ctx->r10 == 0) {
        // 0x801CF5A0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801CF5BC;
    }
    // 0x801CF5A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_801CF5A4:
    // 0x801CF5A4: jal         0x801CE5B0
    // 0x801CF5A8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801CF5A8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x801CF5AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF5B0: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CF5B4: jal         0x800058DC
    // 0x801CF5B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CF5B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_801CF5BC:
    // 0x801CF5BC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x801CF5C0: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x801CF5C4: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x801CF5C8: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x801CF5CC: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x801CF5D0: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x801CF5D4: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x801CF5D8: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x801CF5DC: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x801CF5E0: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x801CF5E4: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x801CF5E8: jr          $ra
    // 0x801CF5EC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801CF5EC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cf5f0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cf5f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF5F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801CF5F4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x801CF5F8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801CF5FC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801CF600: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x801CF604: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x801CF608: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801CF60C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801CF610: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801CF614: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801CF618: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801CF61C: sb          $zero, 0x45($sp)
    MEM_B(0X45, ctx->r29) = 0;
    // 0x801CF620: jal         0x801CE0E8
    // 0x801CF624: addiu       $a1, $sp, 0x45
    ctx->r5 = ADD32(ctx->r29, 0X45);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CF624: addiu       $a1, $sp, 0x45
    ctx->r5 = ADD32(ctx->r29, 0X45);
    after_0:
    // 0x801CF628: bnel        $v0, $zero, L_801CF734
    if (ctx->r2 != 0) {
        // 0x801CF62C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801CF734;
    }
    goto skip_0;
    // 0x801CF62C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801CF630: jal         0x8012C6B4
    // 0x801CF634: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801CF634: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_1:
    // 0x801CF638: lbu         $v1, 0x94($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X94);
    // 0x801CF63C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x801CF640: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x801CF644: blez        $v1, L_801CF720
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801CF648: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801CF720;
    }
    // 0x801CF648: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801CF64C: lui         $at, 0x401A
    ctx->r1 = S32(0X401A << 16);
    // 0x801CF650: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801CF654: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801CF658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CF65C: sll         $t6, $v0, 13
    ctx->r14 = S32(ctx->r2 << 13);
L_801CF660:
    // 0x801CF660: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x801CF664: mflo        $t7
    ctx->r15 = lo;
    // 0x801CF668: addu        $s2, $t7, $s3
    ctx->r18 = ADD32(ctx->r15, ctx->r19);
    // 0x801CF66C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x801CF670: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801CF674: andi        $s2, $s2, 0x1FFF
    ctx->r18 = ctx->r18 & 0X1FFF;
    // 0x801CF678: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x801CF67C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x801CF680: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x801CF684: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CF688: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801CF68C: bne         $v1, $zero, L_801CF698
    if (ctx->r3 != 0) {
        // 0x801CF690: nop
    
            goto L_801CF698;
    }
    // 0x801CF690: nop

    // 0x801CF694: break       7
    do_break(2149381780);
L_801CF698:
    // 0x801CF698: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CF69C: bne         $v1, $at, L_801CF6B0
    if (ctx->r3 != ctx->r1) {
        // 0x801CF6A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801CF6B0;
    }
    // 0x801CF6A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CF6A4: bne         $t6, $at, L_801CF6B0
    if (ctx->r14 != ctx->r1) {
        // 0x801CF6A8: nop
    
            goto L_801CF6B0;
    }
    // 0x801CF6A8: nop

    // 0x801CF6AC: break       6
    do_break(2149381804);
L_801CF6B0:
    // 0x801CF6B0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801CF6B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801CF6B8: jal         0x8001EB64
    // 0x801CF6BC: lw          $s0, 0x30($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X30);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801CF6BC: lw          $s0, 0x30($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X30);
    after_2:
    // 0x801CF6C0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801CF6C4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801CF6C8: mul.d       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f8.d);
    // 0x801CF6CC: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801CF6D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801CF6D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801CF6D8: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801CF6DC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801CF6E0: jal         0x8001EAD0
    // 0x801CF6E4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801CF6E4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x801CF6E8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801CF6EC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801CF6F0: mul.d       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f6.d);
    // 0x801CF6F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801CF6F8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801CF6FC: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801CF700: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801CF704: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801CF708: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801CF70C: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x801CF710: lbu         $v1, 0x94($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X94);
    // 0x801CF714: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801CF718: bnel        $at, $zero, L_801CF660
    if (ctx->r1 != 0) {
        // 0x801CF71C: sll         $t6, $v0, 13
        ctx->r14 = S32(ctx->r2 << 13);
            goto L_801CF660;
    }
    goto skip_1;
    // 0x801CF71C: sll         $t6, $v0, 13
    ctx->r14 = S32(ctx->r2 << 13);
    skip_1:
L_801CF720:
    // 0x801CF720: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF724: addiu       $a1, $a1, -0x8A8
    ctx->r5 = ADD32(ctx->r5, -0X8A8);
    // 0x801CF728: jal         0x800058DC
    // 0x801CF72C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CF72C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x801CF730: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801CF734:
    // 0x801CF734: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801CF738: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801CF73C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801CF740: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x801CF744: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x801CF748: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x801CF74C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x801CF750: jr          $ra
    // 0x801CF754: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801CF754: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cf758(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cf758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF758: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CF75C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CF760: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CF764: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CF768: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801CF76C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CF770: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CF774: lhu         $t9, 0x3E($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X3E);
    // 0x801CF778: jal         0x8012D7A8
    // 0x801CF77C: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x801CF77C: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    after_0:
    // 0x801CF780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CF784: jal         0x801CD878
    // 0x801CF788: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_1;
    // 0x801CF788: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801CF78C: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x801CF790: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x801CF794: beql        $t1, $zero, L_801CF7A8
    if (ctx->r9 == 0) {
        // 0x801CF798: lw          $t2, 0x30($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X30);
            goto L_801CF7A8;
    }
    goto skip_0;
    // 0x801CF798: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x801CF79C: b           L_801CF7C0
    // 0x801CF7A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801CF7C0;
    // 0x801CF7A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801CF7A4: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
L_801CF7A8:
    // 0x801CF7A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CF7AC: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x801CF7B0: beq         $t3, $zero, L_801CF7C0
    if (ctx->r11 == 0) {
        // 0x801CF7B4: nop
    
            goto L_801CF7C0;
    }
    // 0x801CF7B4: nop

    // 0x801CF7B8: b           L_801CF7C0
    // 0x801CF7BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801CF7C0;
    // 0x801CF7BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801CF7C0:
    // 0x801CF7C0: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x801CF7C4: lhu         $t4, 0x90($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X90);
    // 0x801CF7C8: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x801CF7CC: slt         $a0, $t4, $v0
    ctx->r4 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CF7D0: beq         $a0, $zero, L_801CF7E0
    if (ctx->r4 == 0) {
        // 0x801CF7D4: sh          $t5, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r13;
            goto L_801CF7E0;
    }
    // 0x801CF7D4: sh          $t5, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r13;
    // 0x801CF7D8: bnel        $v1, $zero, L_801CF7F8
    if (ctx->r3 != 0) {
        // 0x801CF7DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CF7F8;
    }
    goto skip_1;
    // 0x801CF7DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_801CF7E0:
    // 0x801CF7E0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x801CF7E4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801CF7E8: lhu         $t8, 0x4C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4C);
    // 0x801CF7EC: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x801CF7F0: beq         $t9, $zero, L_801CF810
    if (ctx->r25 == 0) {
        // 0x801CF7F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CF810;
    }
    // 0x801CF7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801CF7F8:
    // 0x801CF7F8: jal         0x801CE5B0
    // 0x801CF7FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_2;
    // 0x801CF7FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x801CF800: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF804: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CF808: jal         0x800058DC
    // 0x801CF80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CF80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_801CF810:
    // 0x801CF810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CF814: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CF818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CF81C: jr          $ra
    // 0x801CF820: nop

    return;
    // 0x801CF820: nop

;}
RECOMP_FUNC void M8_FUN_801cf824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF824: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CF828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF82C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CF830: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
    // 0x801CF834: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    // 0x801CF838: jal         0x801CE0E8
    // 0x801CF83C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CF83C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF840: bne         $v0, $zero, L_801CF884
    if (ctx->r2 != 0) {
        // 0x801CF844: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_801CF884;
    }
    // 0x801CF844: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801CF848: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801CF84C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CF850: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x801CF854: blez        $t6, L_801CF87C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CF858: lui         $a1, 0x801D
        ctx->r5 = S32(0X801D << 16);
            goto L_801CF87C;
    }
    // 0x801CF858: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF85C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_801CF860:
    // 0x801CF860: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801CF864: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801CF868: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
    // 0x801CF86C: lbu         $t8, 0x94($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X94);
    // 0x801CF870: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CF874: bnel        $at, $zero, L_801CF860
    if (ctx->r1 != 0) {
        // 0x801CF878: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_801CF860;
    }
    goto skip_0;
    // 0x801CF878: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_0:
L_801CF87C:
    // 0x801CF87C: jal         0x800058DC
    // 0x801CF880: addiu       $a1, $a1, -0x76C
    ctx->r5 = ADD32(ctx->r5, -0X76C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CF880: addiu       $a1, $a1, -0x76C
    ctx->r5 = ADD32(ctx->r5, -0X76C);
    after_1:
L_801CF884:
    // 0x801CF884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CF888: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CF88C: jr          $ra
    // 0x801CF890: nop

    return;
    // 0x801CF890: nop

;}
RECOMP_FUNC void M8_FUN_801cf894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF894: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801CF898: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CF89C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x801CF8A0: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x801CF8A4: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x801CF8A8: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x801CF8AC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801CF8B0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801CF8B4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801CF8B8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801CF8BC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801CF8C0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801CF8C4: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    // 0x801CF8C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CF8CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801CF8D0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x801CF8D4: beq         $at, $zero, L_801CF914
    if (ctx->r1 == 0) {
        // 0x801CF8D8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801CF914;
    }
    // 0x801CF8D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801CF8DC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801CF8E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801CF8E4: bgez        $v0, L_801CF8FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801CF8E8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CF8FC;
    }
    // 0x801CF8E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CF8EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CF8F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CF8F4: nop

    // 0x801CF8F8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CF8FC:
    // 0x801CF8FC: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801CF900: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801CF904: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801CF908: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801CF90C: b           L_801CF958
    // 0x801CF910: cvt.s.d     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f22.fl = CVT_S_D(ctx->f18.d);
        goto L_801CF958;
    // 0x801CF910: cvt.s.d     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f22.fl = CVT_S_D(ctx->f18.d);
L_801CF914:
    // 0x801CF914: lhu         $v0, 0x90($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X90);
    // 0x801CF918: addiu       $t6, $v0, -0x5
    ctx->r14 = ADD32(ctx->r2, -0X5);
    // 0x801CF91C: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801CF920: bne         $at, $zero, L_801CF94C
    if (ctx->r1 != 0) {
        // 0x801CF924: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_801CF94C;
    }
    // 0x801CF924: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x801CF928: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801CF92C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801CF930: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CF934: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CF938: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CF93C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801CF940: div.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x801CF944: b           L_801CF958
    // 0x801CF948: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
        goto L_801CF958;
    // 0x801CF948: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
L_801CF94C:
    // 0x801CF94C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CF950: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801CF954: nop

L_801CF958:
    // 0x801CF958: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801CF95C: lbu         $a0, 0x78($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X78);
    // 0x801CF960: lbu         $a1, 0x79($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X79);
    // 0x801CF964: jal         0x801CD924
    // 0x801CF968: lbu         $a2, 0x7A($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X7A);
    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_0;
    // 0x801CF968: lbu         $a2, 0x7A($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X7A);
    after_0:
    // 0x801CF96C: lbu         $a0, 0x94($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X94);
    // 0x801CF970: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801CF974: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CF978: blez        $a0, L_801CFC20
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801CF97C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801CFC20;
    }
    // 0x801CF97C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801CF980: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801CF984: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801CF988: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801CF98C: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801CF990: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801CF994: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801CF998: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801CF99C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801CF9A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801CF9A4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x801CF9A8: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_801CF9AC:
    // 0x801CF9AC: multu       $v1, $s3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CF9B0: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801CF9B4: mflo        $a1
    ctx->r5 = lo;
    // 0x801CF9B8: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801CF9BC: bnel        $at, $zero, L_801CFC10
    if (ctx->r1 != 0) {
        // 0x801CF9C0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801CFC10;
    }
    goto skip_0;
    // 0x801CF9C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x801CF9C4: lhu         $t8, 0x90($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X90);
    // 0x801CF9C8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x801CF9CC: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x801CF9D0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801CF9D4: addu        $v1, $s4, $t3
    ctx->r3 = ADD32(ctx->r20, ctx->r11);
    // 0x801CF9D8: bgez        $t8, L_801CF9F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801CF9DC: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_801CF9F4;
    }
    // 0x801CF9DC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801CF9E0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CF9E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CF9E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CF9EC: nop

    // 0x801CF9F0: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_801CF9F4:
    // 0x801CF9F4: bgez        $a0, L_801CFA10
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801CF9F8: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_801CFA10;
    }
    // 0x801CF9F8: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x801CF9FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFA00: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801CFA04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801CFA08: nop

    // 0x801CFA0C: add.d       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f10.d + ctx->f16.d;
L_801CFA10:
    // 0x801CFA10: mul.d       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x801CFA14: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801CFA18: nop

    // 0x801CFA1C: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x801CFA20: bgez        $v0, L_801CFA3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801CFA24: sub.d       $f8, $f4, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
            goto L_801CFA3C;
    }
    // 0x801CFA24: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x801CFA28: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFA2C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CFA30: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CFA34: nop

    // 0x801CFA38: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_801CFA3C:
    // 0x801CFA3C: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x801CFA40: nop

    // 0x801CFA44: bc1fl       L_801CFA68
    if (!c1cs) {
        // 0x801CFA48: lw          $t4, 0x0($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X0);
            goto L_801CFA68;
    }
    goto skip_1;
    // 0x801CFA48: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801CFA4C: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x801CFA50: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x801CFA54: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801CFA58: lbu         $t2, 0x22($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X22);
    // 0x801CFA5C: beql        $t2, $zero, L_801CFC10
    if (ctx->r10 == 0) {
        // 0x801CFA60: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801CFC10;
    }
    goto skip_2;
    // 0x801CFA60: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x801CFA64: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
L_801CFA68:
    // 0x801CFA68: sb          $s5, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r21;
    // 0x801CFA6C: lbu         $a0, 0x94($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X94);
    // 0x801CFA70: lhu         $t5, 0x92($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X92);
    // 0x801CFA74: multu       $a0, $s3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CFA78: subu        $t6, $t5, $a1
    ctx->r14 = SUB32(ctx->r13, ctx->r5);
    // 0x801CFA7C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x801CFA80: nop

    // 0x801CFA84: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801CFA88: mflo        $t7
    ctx->r15 = lo;
    // 0x801CFA8C: nop

    // 0x801CFA90: nop

    // 0x801CFA94: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x801CFA98: mfhi        $v0
    ctx->r2 = hi;
    // 0x801CFA9C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801CFAA0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801CFAA4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801CFAA8: bne         $t7, $zero, L_801CFAB4
    if (ctx->r15 != 0) {
        // 0x801CFAAC: nop
    
            goto L_801CFAB4;
    }
    // 0x801CFAAC: nop

    // 0x801CFAB0: break       7
    do_break(2149382832);
L_801CFAB4:
    // 0x801CFAB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CFAB8: bne         $t7, $at, L_801CFACC
    if (ctx->r15 != ctx->r1) {
        // 0x801CFABC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801CFACC;
    }
    // 0x801CFABC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CFAC0: bne         $t6, $at, L_801CFACC
    if (ctx->r14 != ctx->r1) {
        // 0x801CFAC4: nop
    
            goto L_801CFACC;
    }
    // 0x801CFAC4: nop

    // 0x801CFAC8: break       6
    do_break(2149382856);
L_801CFACC:
    // 0x801CFACC: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CFAD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CFAD4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801CFAD8: bgez        $a0, L_801CFAEC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801CFADC: add.d       $f10, $f6, $f24
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f6.d + ctx->f24.d;
            goto L_801CFAEC;
    }
    // 0x801CFADC: add.d       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f6.d + ctx->f24.d;
    // 0x801CFAE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CFAE4: nop

    // 0x801CFAE8: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_801CFAEC:
    // 0x801CFAEC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801CFAF0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801CFAF4: mul.d       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f20.d);
    // 0x801CFAF8: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801CFAFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801CFB00: add.d       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = ctx->f6.d + ctx->f24.d;
    // 0x801CFB04: div.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x801CFB08: bne         $v0, $zero, L_801CFBAC
    if (ctx->r2 != 0) {
        // 0x801CFB0C: cvt.s.d     $f22, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
            goto L_801CFBAC;
    }
    // 0x801CFB0C: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
    // 0x801CFB10: lwc1        $f16, 0x70($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X70);
    // 0x801CFB14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFB18: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x801CFB1C: lhu         $t9, 0x90($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X90);
    // 0x801CFB20: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801CFB24: bgez        $t9, L_801CFB3C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801CFB28: cvt.d.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
            goto L_801CFB3C;
    }
    // 0x801CFB28: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x801CFB2C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CFB30: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CFB34: nop

    // 0x801CFB38: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
L_801CFB3C:
    // 0x801CFB3C: lbu         $t0, 0x94($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X94);
    // 0x801CFB40: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFB44: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801CFB48: bgez        $t0, L_801CFB60
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801CFB4C: cvt.d.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
            goto L_801CFB60;
    }
    // 0x801CFB4C: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x801CFB50: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801CFB54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801CFB58: nop

    // 0x801CFB5C: add.d       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f4.d + ctx->f16.d;
L_801CFB60:
    // 0x801CFB60: mul.d       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801CFB64: lhu         $t1, 0x92($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X92);
    // 0x801CFB68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFB6C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801CFB70: nop

    // 0x801CFB74: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x801CFB78: bgez        $t1, L_801CFB90
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801CFB7C: sub.d       $f10, $f6, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
            goto L_801CFB90;
    }
    // 0x801CFB7C: sub.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
    // 0x801CFB80: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801CFB84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801CFB88: nop

    // 0x801CFB8C: add.d       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f16.d + ctx->f4.d;
L_801CFB90:
    // 0x801CFB90: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x801CFB94: nop

    // 0x801CFB98: bc1fl       L_801CFBEC
    if (!c1cs) {
        // 0x801CFB9C: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_801CFBEC;
    }
    goto skip_3;
    // 0x801CFB9C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_3:
    // 0x801CFBA0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801CFBA4: b           L_801CFBE8
    // 0x801CFBA8: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
        goto L_801CFBE8;
    // 0x801CFBA8: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
L_801CFBAC:
    // 0x801CFBAC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801CFBB0: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x801CFBB4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFBB8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801CFBBC: bgez        $a0, L_801CFBD4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801CFBC0: cvt.d.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
            goto L_801CFBD4;
    }
    // 0x801CFBC0: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x801CFBC4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801CFBC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801CFBCC: nop

    // 0x801CFBD0: add.d       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f4.d + ctx->f10.d;
L_801CFBD4:
    // 0x801CFBD4: mul.d       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801CFBD8: div.d       $f6, $f26, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = DIV_D(ctx->f26.d, ctx->f16.d);
    // 0x801CFBDC: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x801CFBE0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801CFBE4: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_801CFBE8:
    // 0x801CFBE8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_801CFBEC:
    // 0x801CFBEC: jal         0x801CD5E0
    // 0x801CFBF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_1;
    // 0x801CFBF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CFBF4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801CFBF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CFBFC: jal         0x801CD728
    // 0x801CFC00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_2;
    // 0x801CFC00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801CFC04: lbu         $a0, 0x94($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X94);
    // 0x801CFC08: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801CFC0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_801CFC10:
    // 0x801CFC10: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801CFC14: slt         $at, $s2, $a2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801CFC18: bne         $at, $zero, L_801CF9AC
    if (ctx->r1 != 0) {
        // 0x801CFC1C: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_801CF9AC;
    }
    // 0x801CFC1C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_801CFC20:
    // 0x801CFC20: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801CFC24: lhu         $t3, 0x90($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X90);
    // 0x801CFC28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CFC2C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x801CFC30: slt         $v1, $v0, $t3
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801CFC34: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801CFC38: bne         $v1, $zero, L_801CFC54
    if (ctx->r3 != 0) {
        // 0x801CFC3C: sh          $t4, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r12;
            goto L_801CFC54;
    }
    // 0x801CFC3C: sh          $t4, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r12;
    // 0x801CFC40: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x801CFC44: lhu         $t6, 0x4C($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4C);
    // 0x801CFC48: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x801CFC4C: beql        $t7, $zero, L_801CFC70
    if (ctx->r15 == 0) {
        // 0x801CFC50: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801CFC70;
    }
    goto skip_4;
    // 0x801CFC50: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_4:
L_801CFC54:
    // 0x801CFC54: jal         0x801CE5B0
    // 0x801CFC58: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801CFC58: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x801CFC5C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFC60: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CFC64: jal         0x800058DC
    // 0x801CFC68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CFC68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801CFC6C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801CFC70:
    // 0x801CFC70: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801CFC74: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801CFC78: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801CFC7C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801CFC80: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801CFC84: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801CFC88: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x801CFC8C: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x801CFC90: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x801CFC94: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x801CFC98: jr          $ra
    // 0x801CFC9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801CFC9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cfca0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cfca0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFCA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CFCA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CFCA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CFCAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CFCB0: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x801CFCB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CFCB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CFCBC: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801CFCC0: jal         0x801CE0E8
    // 0x801CFCC4: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CFCC4: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    after_0:
    // 0x801CFCC8: bne         $v0, $zero, L_801CFD30
    if (ctx->r2 != 0) {
        // 0x801CFCCC: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_801CFD30;
    }
    // 0x801CFCCC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801CFCD0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CFCD4: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x801CFCD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFCDC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801CFCE0: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x801CFCE4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801CFCE8: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801CFCEC: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x801CFCF0: ldc1        $f8, 0x35A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X35A8);
    // 0x801CFCF4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801CFCF8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801CFCFC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801CFD00: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x801CFD04: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801CFD08: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801CFD0C: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801CFD10: lbu         $a2, 0x7A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X7A);
    // 0x801CFD14: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x801CFD18: jal         0x801CD924
    // 0x801CFD1C: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_1;
    // 0x801CFD1C: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    after_1:
    // 0x801CFD20: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFD24: addiu       $a1, $a1, -0x2BC
    ctx->r5 = ADD32(ctx->r5, -0X2BC);
    // 0x801CFD28: jal         0x800058DC
    // 0x801CFD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CFD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_801CFD30:
    // 0x801CFD30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CFD34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CFD38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CFD3C: jr          $ra
    // 0x801CFD40: nop

    return;
    // 0x801CFD40: nop

;}
RECOMP_FUNC void M8_FUN_801cfd44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CFD48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CFD4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CFD50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CFD54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CFD58: jal         0x801CD878
    // 0x801CFD5C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801CFD5C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x801CFD60: lbu         $t6, 0x94($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X94);
    // 0x801CFD64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CFD68: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801CFD6C: blezl       $t6, L_801CFE20
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CFD70: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_801CFE20;
    }
    goto skip_0;
    // 0x801CFD70: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801CFD74: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801CFD78: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801CFD7C: nop

    // 0x801CFD80: lhu         $t0, 0x92($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X92);
L_801CFD84:
    // 0x801CFD84: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801CFD88: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801CFD8C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CFD90: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801CFD94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CFD98: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x801CFD9C: bgez        $t0, L_801CFDB0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801CFDA0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CFDB0;
    }
    // 0x801CFDA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CFDA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CFDA8: nop

    // 0x801CFDAC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CFDB0:
    // 0x801CFDB0: lhu         $t1, 0x90($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X90);
    // 0x801CFDB4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801CFDB8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFDBC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x801CFDC0: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x801CFDC4: bgez        $t1, L_801CFDDC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801CFDC8: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_801CFDDC;
    }
    // 0x801CFDC8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801CFDCC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801CFDD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CFDD4: nop

    // 0x801CFDD8: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_801CFDDC:
    // 0x801CFDDC: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x801CFDE0: lwc1        $f18, 0x60($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801CFDE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801CFDE8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CFDEC: div.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x801CFDF0: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801CFDF4: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x801CFDF8: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x801CFDFC: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x801CFE00: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801CFE04: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x801CFE08: lbu         $t2, 0x94($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X94);
    // 0x801CFE0C: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801CFE10: bnel        $at, $zero, L_801CFD84
    if (ctx->r1 != 0) {
        // 0x801CFE14: lhu         $t0, 0x92($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X92);
            goto L_801CFD84;
    }
    goto skip_1;
    // 0x801CFE14: lhu         $t0, 0x92($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X92);
    skip_1:
    // 0x801CFE18: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801CFE1C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_801CFE20:
    // 0x801CFE20: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    // 0x801CFE24: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x801CFE28: lbu         $t3, 0x4B($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4B);
    // 0x801CFE2C: lbu         $a2, 0x7A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X7A);
    // 0x801CFE30: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801CFE34: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x801CFE38: bgez        $t3, L_801CFE50
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801CFE3C: cvt.d.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
            goto L_801CFE50;
    }
    // 0x801CFE3C: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x801CFE40: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801CFE44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801CFE48: nop

    // 0x801CFE4C: add.d       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f6.d + ctx->f18.d;
L_801CFE50:
    // 0x801CFE50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFE54: ldc1        $f10, 0x35B0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X35B0);
    // 0x801CFE58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801CFE5C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801CFE60: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801CFE64: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CFE68: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801CFE6C: nop

    // 0x801CFE70: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x801CFE74: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801CFE78: nop

    // 0x801CFE7C: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801CFE80: beql        $a3, $zero, L_801CFED4
    if (ctx->r7 == 0) {
        // 0x801CFE84: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801CFED4;
    }
    goto skip_2;
    // 0x801CFE84: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x801CFE88: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801CFE8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801CFE90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801CFE94: sub.d       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f8.d - ctx->f4.d;
    // 0x801CFE98: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801CFE9C: nop

    // 0x801CFEA0: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x801CFEA4: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801CFEA8: nop

    // 0x801CFEAC: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801CFEB0: bne         $a3, $zero, L_801CFEC8
    if (ctx->r7 != 0) {
        // 0x801CFEB4: nop
    
            goto L_801CFEC8;
    }
    // 0x801CFEB4: nop

    // 0x801CFEB8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801CFEBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CFEC0: b           L_801CFEE0
    // 0x801CFEC4: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801CFEE0;
    // 0x801CFEC4: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801CFEC8:
    // 0x801CFEC8: b           L_801CFEE0
    // 0x801CFECC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801CFEE0;
    // 0x801CFECC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801CFED0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801CFED4:
    // 0x801CFED4: nop

    // 0x801CFED8: bltz        $a3, L_801CFEC8
    if (SIGNED(ctx->r7) < 0) {
        // 0x801CFEDC: nop
    
            goto L_801CFEC8;
    }
    // 0x801CFEDC: nop

L_801CFEE0:
    // 0x801CFEE0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CFEE4: jal         0x801CD994
    // 0x801CFEE8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CD994)(rdram, ctx);
        goto after_1;
    // 0x801CFEE8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801CFEEC: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x801CFEF0: lhu         $t5, 0x90($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X90);
    // 0x801CFEF4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801CFEF8: slt         $v1, $t5, $v0
    ctx->r3 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CFEFC: bne         $v1, $zero, L_801CFF18
    if (ctx->r3 != 0) {
        // 0x801CFF00: sh          $t6, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r14;
            goto L_801CFF18;
    }
    // 0x801CFF00: sh          $t6, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r14;
    // 0x801CFF04: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x801CFF08: lhu         $t8, 0x4C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4C);
    // 0x801CFF0C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x801CFF10: beql        $t9, $zero, L_801CFF40
    if (ctx->r25 == 0) {
        // 0x801CFF14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CFF40;
    }
    goto skip_3;
    // 0x801CFF14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_801CFF18:
    // 0x801CFF18: jal         0x801CBD70
    // 0x801CFF1C: nop

    LOOKUP_FUNC(0x801CBD70)(rdram, ctx);
        goto after_2;
    // 0x801CFF1C: nop

    after_2:
    // 0x801CFF20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CFF24: jal         0x801CE5B0
    // 0x801CFF28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801CFF28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x801CFF2C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFF30: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801CFF34: jal         0x800058DC
    // 0x801CFF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CFF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801CFF3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CFF40:
    // 0x801CFF40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CFF44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CFF48: jr          $ra
    // 0x801CFF4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801CFF4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801cff50(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801cff50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFF50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CFF54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CFF58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CFF5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CFF60: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x801CFF64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CFF68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CFF6C: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801CFF70: jal         0x801CE0E8
    // 0x801CFF74: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801CFF74: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    after_0:
    // 0x801CFF78: bne         $v0, $zero, L_801CFFE0
    if (ctx->r2 != 0) {
        // 0x801CFF7C: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_801CFFE0;
    }
    // 0x801CFF7C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801CFF80: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CFF84: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x801CFF88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFF8C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801CFF90: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x801CFF94: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801CFF98: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801CFF9C: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x801CFFA0: ldc1        $f8, 0x35B8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X35B8);
    // 0x801CFFA4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801CFFA8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801CFFAC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801CFFB0: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x801CFFB4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801CFFB8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801CFFBC: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801CFFC0: lbu         $a2, 0x7A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X7A);
    // 0x801CFFC4: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x801CFFC8: jal         0x801CD924
    // 0x801CFFCC: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_1;
    // 0x801CFFCC: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    after_1:
    // 0x801CFFD0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFFD4: addiu       $a1, $a1, -0xC
    ctx->r5 = ADD32(ctx->r5, -0XC);
    // 0x801CFFD8: jal         0x800058DC
    // 0x801CFFDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CFFDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_801CFFE0:
    // 0x801CFFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CFFE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CFFE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CFFEC: jr          $ra
    // 0x801CFFF0: nop

    return;
    // 0x801CFFF0: nop

;}
RECOMP_FUNC void M8_FUN_801cfff4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFFF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CFFF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CFFFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801D0000: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801D0004: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x801D0008: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D000C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D0010: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801D0014: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D0018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D001C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801D0020: bgez        $t6, L_801D0038
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D0024: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D0038;
    }
    // 0x801D0024: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D0028: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D002C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D0030: nop

    // 0x801D0034: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801D0038:
    // 0x801D0038: lhu         $t7, 0x90($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X90);
    // 0x801D003C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D0040: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D0044: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801D0048: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x801D004C: bgez        $t7, L_801D0064
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D0050: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_801D0064;
    }
    // 0x801D0050: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801D0054: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D0058: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D005C: nop

    // 0x801D0060: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_801D0064:
    // 0x801D0064: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x801D0068: lbu         $t8, 0x94($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X94);
    // 0x801D006C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801D0070: div.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x801D0074: blez        $t8, L_801D00B8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801D0078: cvt.s.d     $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
            goto L_801D00B8;
    }
    // 0x801D0078: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x801D007C: lwc1        $f18, 0x60($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X60);
L_801D0080:
    // 0x801D0080: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801D0084: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x801D0088: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801D008C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D0090: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D0094: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D0098: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801D009C: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801D00A0: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801D00A4: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801D00A8: lbu         $t2, 0x94($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X94);
    // 0x801D00AC: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801D00B0: bnel        $at, $zero, L_801D0080
    if (ctx->r1 != 0) {
        // 0x801D00B4: lwc1        $f18, 0x60($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X60);
            goto L_801D0080;
    }
    goto skip_0;
    // 0x801D00B4: lwc1        $f18, 0x60($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X60);
    skip_0:
L_801D00B8:
    // 0x801D00B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D00BC: ldc1        $f4, 0x35C0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X35C0);
    // 0x801D00C0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801D00C4: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    // 0x801D00C8: mul.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x801D00CC: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x801D00D0: lbu         $a2, 0x7A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X7A);
    // 0x801D00D4: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x801D00D8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801D00DC: jal         0x801CD924
    // 0x801D00E0: nop

    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_0;
    // 0x801D00E0: nop

    after_0:
    // 0x801D00E4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x801D00E8: lhu         $v1, 0x4C($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4C);
    // 0x801D00EC: andi        $t3, $v1, 0x8000
    ctx->r11 = ctx->r3 & 0X8000;
    // 0x801D00F0: beq         $t3, $zero, L_801D0114
    if (ctx->r11 == 0) {
        // 0x801D00F4: addiu       $t4, $v1, 0x1
        ctx->r12 = ADD32(ctx->r3, 0X1);
            goto L_801D0114;
    }
    // 0x801D00F4: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x801D00F8: jal         0x801CBD70
    // 0x801D00FC: sh          $t4, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r12;
    LOOKUP_FUNC(0x801CBD70)(rdram, ctx);
        goto after_1;
    // 0x801D00FC: sh          $t4, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r12;
    after_1:
    // 0x801D0100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D0104: jal         0x801CE5B0
    // 0x801D0108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_2;
    // 0x801D0108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x801D010C: b           L_801D0154
    // 0x801D0110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D0154;
    // 0x801D0110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D0114:
    // 0x801D0114: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x801D0118: lhu         $t5, 0x90($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X90);
    // 0x801D011C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801D0120: slt         $v1, $t5, $v0
    ctx->r3 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D0124: beq         $v1, $zero, L_801D0150
    if (ctx->r3 == 0) {
        // 0x801D0128: sh          $t6, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r14;
            goto L_801D0150;
    }
    // 0x801D0128: sh          $t6, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r14;
    // 0x801D012C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x801D0130: sh          $zero, 0x92($s0)
    MEM_H(0X92, ctx->r16) = 0;
    // 0x801D0134: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0138: lhu         $t7, 0x4C($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4C);
    // 0x801D013C: addiu       $a1, $a1, 0x164
    ctx->r5 = ADD32(ctx->r5, 0X164);
    // 0x801D0140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D0144: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801D0148: jal         0x800058DC
    // 0x801D014C: sh          $t8, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D014C: sh          $t8, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r24;
    after_3:
L_801D0150:
    // 0x801D0150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D0154:
    // 0x801D0154: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801D0158: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801D015C: jr          $ra
    // 0x801D0160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801D0160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d0164(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d0164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D016C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D0170: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D0174: lhu         $t7, 0x4C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4C);
    // 0x801D0178: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x801D017C: beql        $t8, $zero, L_801D01A4
    if (ctx->r24 == 0) {
        // 0x801D0180: lhu         $v0, 0x92($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X92);
            goto L_801D01A4;
    }
    goto skip_0;
    // 0x801D0180: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    skip_0:
    // 0x801D0184: jal         0x801CBD70
    // 0x801D0188: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CBD70)(rdram, ctx);
        goto after_0;
    // 0x801D0188: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D018C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D0190: jal         0x801CE5B0
    // 0x801D0194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D0194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x801D0198: b           L_801D01D0
    // 0x801D019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D01D0;
    // 0x801D019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D01A0: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
L_801D01A4:
    // 0x801D01A4: lhu         $t9, 0x90($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X90);
    // 0x801D01A8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D01AC: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x801D01B0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801D01B4: slt         $v1, $t0, $v0
    ctx->r3 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D01B8: beq         $v1, $zero, L_801D01CC
    if (ctx->r3 == 0) {
        // 0x801D01BC: sh          $t1, 0x92($a0)
        MEM_H(0X92, ctx->r4) = ctx->r9;
            goto L_801D01CC;
    }
    // 0x801D01BC: sh          $t1, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r9;
    // 0x801D01C0: sh          $zero, 0x92($a0)
    MEM_H(0X92, ctx->r4) = 0;
    // 0x801D01C4: jal         0x800058DC
    // 0x801D01C8: addiu       $a1, $a1, 0x1DC
    ctx->r5 = ADD32(ctx->r5, 0X1DC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D01C8: addiu       $a1, $a1, 0x1DC
    ctx->r5 = ADD32(ctx->r5, 0X1DC);
    after_2:
L_801D01CC:
    // 0x801D01CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D01D0:
    // 0x801D01D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D01D4: jr          $ra
    // 0x801D01D8: nop

    return;
    // 0x801D01D8: nop

;}
RECOMP_FUNC void M8_FUN_801d01dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D01DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D01E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D01E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801D01E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801D01EC: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x801D01F0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D01F4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D01F8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801D01FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D0200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D0204: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801D0208: bgez        $t6, L_801D0220
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D020C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D0220;
    }
    // 0x801D020C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D0210: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D0214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D0218: nop

    // 0x801D021C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801D0220:
    // 0x801D0220: lhu         $t7, 0x90($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X90);
    // 0x801D0224: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D0228: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D022C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801D0230: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x801D0234: bgez        $t7, L_801D024C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D0238: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_801D024C;
    }
    // 0x801D0238: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801D023C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D0240: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D0244: nop

    // 0x801D0248: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_801D024C:
    // 0x801D024C: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x801D0250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D0254: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801D0258: div.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x801D025C: sub.d       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f0.d - ctx->f10.d;
    // 0x801D0260: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x801D0264: jal         0x801CD878
    // 0x801D0268: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D0268: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x801D026C: lbu         $t8, 0x94($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X94);
    // 0x801D0270: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801D0274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D0278: blezl       $t8, L_801D02C4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801D027C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_801D02C4;
    }
    goto skip_0;
    // 0x801D027C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801D0280: lwc1        $f8, 0x60($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X60);
L_801D0284:
    // 0x801D0284: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801D0288: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x801D028C: mul.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801D0290: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D0294: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801D0298: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801D029C: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801D02A0: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x801D02A4: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801D02A8: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x801D02AC: lbu         $t2, 0x94($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X94);
    // 0x801D02B0: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801D02B4: bnel        $at, $zero, L_801D0284
    if (ctx->r1 != 0) {
        // 0x801D02B8: lwc1        $f8, 0x60($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X60);
            goto L_801D0284;
    }
    goto skip_1;
    // 0x801D02B8: lwc1        $f8, 0x60($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X60);
    skip_1:
    // 0x801D02BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801D02C0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_801D02C4:
    // 0x801D02C4: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    // 0x801D02C8: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x801D02CC: lbu         $t3, 0x4B($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4B);
    // 0x801D02D0: lbu         $a2, 0x7A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X7A);
    // 0x801D02D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D02D8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801D02DC: bgez        $t3, L_801D02F4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801D02E0: cvt.d.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D02F4;
    }
    // 0x801D02E0: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D02E4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D02E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D02EC: nop

    // 0x801D02F0: add.d       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f16.d + ctx->f6.d;
L_801D02F4:
    // 0x801D02F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D02F8: ldc1        $f10, 0x35C8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X35C8);
    // 0x801D02FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801D0300: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D0304: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x801D0308: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D030C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801D0310: nop

    // 0x801D0314: cvt.w.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_D(ctx->f18.d);
    // 0x801D0318: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801D031C: nop

    // 0x801D0320: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801D0324: beql        $a3, $zero, L_801D0378
    if (ctx->r7 == 0) {
        // 0x801D0328: mfc1        $a3, $f8
        ctx->r7 = (int32_t)ctx->f8.u32l;
            goto L_801D0378;
    }
    goto skip_2;
    // 0x801D0328: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x801D032C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D0330: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D0334: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801D0338: sub.d       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f18.d - ctx->f8.d;
    // 0x801D033C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801D0340: nop

    // 0x801D0344: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x801D0348: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801D034C: nop

    // 0x801D0350: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801D0354: bne         $a3, $zero, L_801D036C
    if (ctx->r7 != 0) {
        // 0x801D0358: nop
    
            goto L_801D036C;
    }
    // 0x801D0358: nop

    // 0x801D035C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801D0360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D0364: b           L_801D0384
    // 0x801D0368: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801D0384;
    // 0x801D0368: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801D036C:
    // 0x801D036C: b           L_801D0384
    // 0x801D0370: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801D0384;
    // 0x801D0370: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801D0374: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
L_801D0378:
    // 0x801D0378: nop

    // 0x801D037C: bltz        $a3, L_801D036C
    if (SIGNED(ctx->r7) < 0) {
        // 0x801D0380: nop
    
            goto L_801D036C;
    }
    // 0x801D0380: nop

L_801D0384:
    // 0x801D0384: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D0388: jal         0x801CD994
    // 0x801D038C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CD994)(rdram, ctx);
        goto after_1;
    // 0x801D038C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801D0390: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x801D0394: lhu         $t5, 0x90($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X90);
    // 0x801D0398: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801D039C: slt         $v1, $t5, $v0
    ctx->r3 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D03A0: bne         $v1, $zero, L_801D03BC
    if (ctx->r3 != 0) {
        // 0x801D03A4: sh          $t6, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r14;
            goto L_801D03BC;
    }
    // 0x801D03A4: sh          $t6, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r14;
    // 0x801D03A8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x801D03AC: lhu         $t8, 0x4C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4C);
    // 0x801D03B0: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x801D03B4: beql        $t9, $zero, L_801D03E4
    if (ctx->r25 == 0) {
        // 0x801D03B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D03E4;
    }
    goto skip_3;
    // 0x801D03B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_801D03BC:
    // 0x801D03BC: jal         0x801CBD70
    // 0x801D03C0: nop

    LOOKUP_FUNC(0x801CBD70)(rdram, ctx);
        goto after_2;
    // 0x801D03C0: nop

    after_2:
    // 0x801D03C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D03C8: jal         0x801CE5B0
    // 0x801D03CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801D03CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x801D03D0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D03D4: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D03D8: jal         0x800058DC
    // 0x801D03DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D03DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801D03E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D03E4:
    // 0x801D03E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801D03E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801D03EC: jr          $ra
    // 0x801D03F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801D03F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d03f4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d03f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D03F4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801D03F8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801D03FC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801D0400: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D0404: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801D0408: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801D040C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801D0410: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801D0414: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801D0418: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801D041C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D0420: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D0424: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D0428: sb          $zero, 0x75($sp)
    MEM_B(0X75, ctx->r29) = 0;
    // 0x801D042C: jal         0x801CE0E8
    // 0x801D0430: addiu       $a1, $sp, 0x75
    ctx->r5 = ADD32(ctx->r29, 0X75);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D0430: addiu       $a1, $sp, 0x75
    ctx->r5 = ADD32(ctx->r29, 0X75);
    after_0:
    // 0x801D0434: bnel        $v0, $zero, L_801D0568
    if (ctx->r2 != 0) {
        // 0x801D0438: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801D0568;
    }
    goto skip_0;
    // 0x801D0438: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x801D043C: lbu         $t6, 0x94($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X94);
    // 0x801D0440: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D0444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D0448: blez        $t6, L_801D0554
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D044C: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_801D0554;
    }
    // 0x801D044C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D0450: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D0454: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D0458: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D045C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D0460: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D0464: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
L_801D0468:
    // 0x801D0468: div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // 0x801D046C: mfhi        $t7
    ctx->r15 = hi;
    // 0x801D0470: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x801D0474: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x801D0478: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801D047C: bne         $s3, $zero, L_801D0488
    if (ctx->r19 != 0) {
        // 0x801D0480: nop
    
            goto L_801D0488;
    }
    // 0x801D0480: nop

    // 0x801D0484: break       7
    do_break(2149385348);
L_801D0488:
    // 0x801D0488: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D048C: bne         $s3, $at, L_801D04A0
    if (ctx->r19 != ctx->r1) {
        // 0x801D0490: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D04A0;
    }
    // 0x801D0490: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D0494: bne         $v0, $at, L_801D04A0
    if (ctx->r2 != ctx->r1) {
        // 0x801D0498: nop
    
            goto L_801D04A0;
    }
    // 0x801D0498: nop

    // 0x801D049C: break       6
    do_break(2149385372);
L_801D04A0:
    // 0x801D04A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D04A4: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x801D04A8: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x801D04AC: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x801D04B0: c.lt.d      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.d < ctx->f22.d;
    // 0x801D04B4: nop

    // 0x801D04B8: bc1fl       L_801D04D0
    if (!c1cs) {
        // 0x801D04BC: sub.d       $f20, $f0, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f20.d = ctx->f0.d - ctx->f22.d;
            goto L_801D04D0;
    }
    goto skip_1;
    // 0x801D04BC: sub.d       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f20.d = ctx->f0.d - ctx->f22.d;
    skip_1:
    // 0x801D04C0: sub.d       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f20.d = ctx->f0.d - ctx->f22.d;
    // 0x801D04C4: b           L_801D04D0
    // 0x801D04C8: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
        goto L_801D04D0;
    // 0x801D04C8: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
    // 0x801D04CC: sub.d       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f20.d = ctx->f0.d - ctx->f22.d;
L_801D04D0:
    // 0x801D04D0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801D04D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D04D8: lw          $s0, 0x30($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X30);
    // 0x801D04DC: jal         0x801CE6F8
    // 0x801D04E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CE6F8)(rdram, ctx);
        goto after_1;
    // 0x801D04E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801D04E4: div.d       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = DIV_D(ctx->f20.d, ctx->f22.d);
    // 0x801D04E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D04EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D04F0: cvt.s.d     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f24.fl = CVT_S_D(ctx->f8.d);
    // 0x801D04F4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801D04F8: jal         0x801CD5E0
    // 0x801D04FC: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_2;
    // 0x801D04FC: nop

    after_2:
    // 0x801D0500: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801D0504: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D0508: jal         0x801CD728
    // 0x801D050C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_3;
    // 0x801D050C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x801D0510: cvt.d.s     $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f18.d = CVT_D_S(ctx->f24.fl);
    // 0x801D0514: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D0518: sub.d       $f4, $f26, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f26.d - ctx->f18.d;
    // 0x801D051C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D0520: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D0524: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D0528: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801D052C: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x801D0530: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D0534: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x801D0538: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D053C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D0540: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801D0544: lbu         $t3, 0x94($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X94);
    // 0x801D0548: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801D054C: bne         $at, $zero, L_801D0468
    if (ctx->r1 != 0) {
        // 0x801D0550: nop
    
            goto L_801D0468;
    }
    // 0x801D0550: nop

L_801D0554:
    // 0x801D0554: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0558: addiu       $a1, $a1, 0x594
    ctx->r5 = ADD32(ctx->r5, 0X594);
    // 0x801D055C: jal         0x800058DC
    // 0x801D0560: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D0560: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x801D0564: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D0568:
    // 0x801D0568: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D056C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D0570: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D0574: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801D0578: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801D057C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801D0580: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801D0584: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801D0588: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801D058C: jr          $ra
    // 0x801D0590: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801D0590: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d0594(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d0594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0594: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801D0598: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801D059C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801D05A0: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801D05A4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801D05A8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801D05AC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801D05B0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801D05B4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801D05B8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801D05BC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801D05C0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D05C4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D05C8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D05CC: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801D05D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D05D4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D05D8: blez        $t6, L_801D0788
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D05DC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_801D0788;
    }
    // 0x801D05DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801D05E0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D05E4: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x801D05E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801D05EC: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801D05F0: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x801D05F4: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D05F8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D05FC: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D0600: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x801D0604: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801D0608: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D060C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D0610: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D0614: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x801D0618: lhu         $t7, 0x92($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X92);
L_801D061C:
    // 0x801D061C: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x801D0620: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x801D0624: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x801D0628: div         $zero, $t8, $s4
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r20)));
    // 0x801D062C: mfhi        $v0
    ctx->r2 = hi;
    // 0x801D0630: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x801D0634: bne         $s4, $zero, L_801D0640
    if (ctx->r20 != 0) {
        // 0x801D0638: nop
    
            goto L_801D0640;
    }
    // 0x801D0638: nop

    // 0x801D063C: break       7
    do_break(2149385788);
L_801D0640:
    // 0x801D0640: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D0644: bne         $s4, $at, L_801D0658
    if (ctx->r20 != ctx->r1) {
        // 0x801D0648: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D0658;
    }
    // 0x801D0648: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D064C: bne         $t8, $at, L_801D0658
    if (ctx->r24 != ctx->r1) {
        // 0x801D0650: nop
    
            goto L_801D0658;
    }
    // 0x801D0650: nop

    // 0x801D0654: break       6
    do_break(2149385812);
L_801D0658:
    // 0x801D0658: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D065C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D0660: bgez        $v0, L_801D0674
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801D0664: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D0674;
    }
    // 0x801D0664: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D0668: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D066C: nop

    // 0x801D0670: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801D0674:
    // 0x801D0674: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x801D0678: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D067C: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    // 0x801D0680: nop

    // 0x801D0684: bc1fl       L_801D069C
    if (!c1cs) {
        // 0x801D0688: sub.d       $f22, $f0, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f22.d = ctx->f0.d - ctx->f20.d;
            goto L_801D069C;
    }
    goto skip_0;
    // 0x801D0688: sub.d       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f22.d = ctx->f0.d - ctx->f20.d;
    skip_0:
    // 0x801D068C: sub.d       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f22.d = ctx->f0.d - ctx->f20.d;
    // 0x801D0690: b           L_801D069C
    // 0x801D0694: neg.d       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.d); 
    ctx->f22.d = -ctx->f22.d;
        goto L_801D069C;
    // 0x801D0694: neg.d       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.d); 
    ctx->f22.d = -ctx->f22.d;
    // 0x801D0698: sub.d       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f22.d = ctx->f0.d - ctx->f20.d;
L_801D069C:
    // 0x801D069C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D06A0: bne         $v0, $zero, L_801D06B0
    if (ctx->r2 != 0) {
        // 0x801D06A4: lw          $s0, 0x30($t1)
        ctx->r16 = MEM_W(ctx->r9, 0X30);
            goto L_801D06B0;
    }
    // 0x801D06A4: lw          $s0, 0x30($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X30);
    // 0x801D06A8: jal         0x801CE6F8
    // 0x801D06AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CE6F8)(rdram, ctx);
        goto after_0;
    // 0x801D06AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
L_801D06B0:
    // 0x801D06B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D06B4: lwc1        $f16, 0x35D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X35D0);
    // 0x801D06B8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D06BC: lh          $t2, 0x14($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X14);
    // 0x801D06C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D06C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801D06C8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801D06CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D06D0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801D06D4: lbu         $t3, 0x94($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X94);
    // 0x801D06D8: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D06DC: bgez        $t3, L_801D06EC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801D06E0: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_801D06EC;
    }
    // 0x801D06E0: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x801D06E4: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x801D06E8: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_801D06EC:
    // 0x801D06EC: subu        $t5, $s2, $t4
    ctx->r13 = SUB32(ctx->r18, ctx->r12);
    // 0x801D06F0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801D06F4: nop

    // 0x801D06F8: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D06FC: sub.d       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f16.d = ctx->f10.d - ctx->f28.d;
    // 0x801D0700: div.d       $f10, $f22, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f22.d, ctx->f20.d);
    // 0x801D0704: mul.d       $f18, $f26, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f26.d, ctx->f16.d);
    // 0x801D0708: add.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d + ctx->f18.d;
    // 0x801D070C: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x801D0710: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801D0714: nop

    // 0x801D0718: sh          $t7, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r15;
    // 0x801D071C: lh          $t8, 0x14($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X14);
    // 0x801D0720: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x801D0724: sh          $t9, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r25;
    // 0x801D0728: cvt.s.d     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f24.fl = CVT_S_D(ctx->f10.d);
    // 0x801D072C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801D0730: jal         0x801CD5E0
    // 0x801D0734: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_1;
    // 0x801D0734: nop

    after_1:
    // 0x801D0738: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801D073C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D0740: jal         0x801CD728
    // 0x801D0744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_2;
    // 0x801D0744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801D0748: cvt.d.s     $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f18.d = CVT_D_S(ctx->f24.fl);
    // 0x801D074C: lwc1        $f16, 0x60($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X60);
    // 0x801D0750: sub.d       $f4, $f30, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f30.d - ctx->f18.d;
    // 0x801D0754: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801D0758: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801D075C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D0760: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x801D0764: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x801D0768: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801D076C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D0770: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D0774: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801D0778: lbu         $t0, 0x94($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X94);
    // 0x801D077C: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D0780: bnel        $at, $zero, L_801D061C
    if (ctx->r1 != 0) {
        // 0x801D0784: lhu         $t7, 0x92($s1)
        ctx->r15 = MEM_HU(ctx->r17, 0X92);
            goto L_801D061C;
    }
    goto skip_1;
    // 0x801D0784: lhu         $t7, 0x92($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X92);
    skip_1:
L_801D0788:
    // 0x801D0788: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801D078C: lhu         $t1, 0x90($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X90);
    // 0x801D0790: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D0794: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801D0798: slt         $v1, $t1, $v0
    ctx->r3 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D079C: bne         $v1, $zero, L_801D07B8
    if (ctx->r3 != 0) {
        // 0x801D07A0: sh          $t2, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r10;
            goto L_801D07B8;
    }
    // 0x801D07A0: sh          $t2, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r10;
    // 0x801D07A4: lw          $t3, 0xC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC);
    // 0x801D07A8: lhu         $t4, 0x4C($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4C);
    // 0x801D07AC: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x801D07B0: beql        $t5, $zero, L_801D07D4
    if (ctx->r13 == 0) {
        // 0x801D07B4: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801D07D4;
    }
    goto skip_2;
    // 0x801D07B4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
L_801D07B8:
    // 0x801D07B8: jal         0x801CE5B0
    // 0x801D07BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801D07BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x801D07C0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D07C4: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D07C8: jal         0x800058DC
    // 0x801D07CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D07CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801D07D0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801D07D4:
    // 0x801D07D4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D07D8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D07DC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D07E0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801D07E4: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801D07E8: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801D07EC: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801D07F0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801D07F4: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801D07F8: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801D07FC: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801D0800: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801D0804: jr          $ra
    // 0x801D0808: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801D0808: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d080c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d080c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D080C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801D0810: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D0814: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801D0818: lh          $s0, -0x41DE($s0)
    ctx->r16 = MEM_H(ctx->r16, -0X41DE);
    // 0x801D081C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801D0820: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801D0824: addiu       $s0, $s0, -0x800
    ctx->r16 = ADD32(ctx->r16, -0X800);
    // 0x801D0828: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801D082C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801D0830: andi        $s0, $s0, 0x1FFF
    ctx->r16 = ctx->r16 & 0X1FFF;
    // 0x801D0834: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801D0838: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801D083C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801D0840: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801D0844: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801D0848: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D084C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D0850: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D0854: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D0858: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D085C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D0860: jal         0x8001EB64
    // 0x801D0864: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D0864: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x801D0868: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801D086C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801D0870: jal         0x8001EAD0
    // 0x801D0874: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D0874: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801D0878: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801D087C: sb          $zero, 0x53($sp)
    MEM_B(0X53, ctx->r29) = 0;
    // 0x801D0880: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801D0884: jal         0x801CE0E8
    // 0x801D0888: addiu       $a1, $sp, 0x53
    ctx->r5 = ADD32(ctx->r29, 0X53);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_2;
    // 0x801D0888: addiu       $a1, $sp, 0x53
    ctx->r5 = ADD32(ctx->r29, 0X53);
    after_2:
    // 0x801D088C: bnel        $v0, $zero, L_801D09D0
    if (ctx->r2 != 0) {
        // 0x801D0890: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801D09D0;
    }
    goto skip_0;
    // 0x801D0890: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801D0894: lbu         $v0, 0x94($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X94);
    // 0x801D0898: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801D089C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D08A0: blez        $v0, L_801D09BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801D08A4: addiu       $t9, $zero, 0x2000
        ctx->r25 = ADD32(0, 0X2000);
            goto L_801D09BC;
    }
    // 0x801D08A4: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
L_801D08A8:
    // 0x801D08A8: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x801D08AC: mflo        $a0
    ctx->r4 = lo;
    // 0x801D08B0: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x801D08B4: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x801D08B8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D08BC: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801D08C0: bne         $v0, $zero, L_801D08CC
    if (ctx->r2 != 0) {
        // 0x801D08C4: nop
    
            goto L_801D08CC;
    }
    // 0x801D08C4: nop

    // 0x801D08C8: break       7
    do_break(2149386440);
L_801D08CC:
    // 0x801D08CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D08D0: bne         $v0, $at, L_801D08E4
    if (ctx->r2 != ctx->r1) {
        // 0x801D08D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D08E4;
    }
    // 0x801D08D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D08D8: bne         $t9, $at, L_801D08E4
    if (ctx->r25 != ctx->r1) {
        // 0x801D08DC: nop
    
            goto L_801D08E4;
    }
    // 0x801D08DC: nop

    // 0x801D08E0: break       6
    do_break(2149386464);
L_801D08E4:
    // 0x801D08E4: bgez        $a0, L_801D08F0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801D08E8: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_801D08F0;
    }
    // 0x801D08E8: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x801D08EC: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
L_801D08F0:
    // 0x801D08F0: sra         $a0, $at, 1
    ctx->r4 = S32(SIGNED(ctx->r1) >> 1);
    // 0x801D08F4: jal         0x8012C6B4
    // 0x801D08F8: nop

    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D08F8: nop

    after_3:
    // 0x801D08FC: lbu         $t1, 0x94($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X94);
    // 0x801D0900: sll         $t0, $s1, 13
    ctx->r8 = S32(ctx->r17 << 13);
    // 0x801D0904: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x801D0908: mflo        $t2
    ctx->r10 = lo;
    // 0x801D090C: addu        $s2, $v0, $t2
    ctx->r18 = ADD32(ctx->r2, ctx->r10);
    // 0x801D0910: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x801D0914: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801D0918: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801D091C: bne         $t1, $zero, L_801D0928
    if (ctx->r9 != 0) {
        // 0x801D0920: nop
    
            goto L_801D0928;
    }
    // 0x801D0920: nop

    // 0x801D0924: break       7
    do_break(2149386532);
L_801D0928:
    // 0x801D0928: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D092C: bne         $t1, $at, L_801D0940
    if (ctx->r9 != ctx->r1) {
        // 0x801D0930: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D0940;
    }
    // 0x801D0930: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D0934: bne         $t0, $at, L_801D0940
    if (ctx->r8 != ctx->r1) {
        // 0x801D0938: nop
    
            goto L_801D0940;
    }
    // 0x801D0938: nop

    // 0x801D093C: break       6
    do_break(2149386556);
L_801D0940:
    // 0x801D0940: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D0944: jal         0x8001EB64
    // 0x801D0948: nop

    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x801D0948: nop

    after_4:
    // 0x801D094C: lwc1        $f6, 0x88($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X88);
    // 0x801D0950: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D0954: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D0958: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D095C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801D0960: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D0964: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x801D0968: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801D096C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x801D0970: lwc1        $f6, 0x88($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X88);
    // 0x801D0974: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D0978: nop

    // 0x801D097C: mul.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x801D0980: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801D0984: jal         0x8001EAD0
    // 0x801D0988: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x801D0988: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x801D098C: lwc1        $f6, 0x88($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X88);
    // 0x801D0990: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D0994: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801D0998: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D099C: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801D09A0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x801D09A4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801D09A8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801D09AC: lbu         $v0, 0x94($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X94);
    // 0x801D09B0: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D09B4: bnel        $at, $zero, L_801D08A8
    if (ctx->r1 != 0) {
        // 0x801D09B8: addiu       $t9, $zero, 0x2000
        ctx->r25 = ADD32(0, 0X2000);
            goto L_801D08A8;
    }
    goto skip_1;
    // 0x801D09B8: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    skip_1:
L_801D09BC:
    // 0x801D09BC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D09C0: addiu       $a1, $a1, -0x1858
    ctx->r5 = ADD32(ctx->r5, -0X1858);
    // 0x801D09C4: jal         0x800058DC
    // 0x801D09C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D09C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x801D09CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801D09D0:
    // 0x801D09D0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D09D4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D09D8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D09DC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D09E0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D09E4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D09E8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801D09EC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801D09F0: jr          $ra
    // 0x801D09F4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801D09F4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d09f8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d09f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D09F8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801D09FC: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801D0A00: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801D0A04: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801D0A08: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801D0A0C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801D0A10: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801D0A14: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801D0A18: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801D0A1C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801D0A20: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801D0A24: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D0A28: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D0A2C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D0A30: sb          $zero, 0x7F($sp)
    MEM_B(0X7F, ctx->r29) = 0;
    // 0x801D0A34: jal         0x801CE0E8
    // 0x801D0A38: addiu       $a1, $sp, 0x7F
    ctx->r5 = ADD32(ctx->r29, 0X7F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D0A38: addiu       $a1, $sp, 0x7F
    ctx->r5 = ADD32(ctx->r29, 0X7F);
    after_0:
    // 0x801D0A3C: bnel        $v0, $zero, L_801D0BEC
    if (ctx->r2 != 0) {
        // 0x801D0A40: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801D0BEC;
    }
    goto skip_0;
    // 0x801D0A40: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801D0A44: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x801D0A48: lwc1        $f20, 0x7C($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x801D0A4C: lwc1        $f22, 0x80($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X80);
    // 0x801D0A50: lwc1        $f24, 0xA0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0XA0);
    // 0x801D0A54: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801D0A58: nop

    // 0x801D0A5C: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x801D0A60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D0A64: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x801D0A68: jal         0x8002FC20
    // 0x801D0A6C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801D0A6C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x801D0A70: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801D0A74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D0A78: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801D0A7C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801D0A80: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x801D0A84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0A88: bc1fl       L_801D0A98
    if (!c1cs) {
        // 0x801D0A8C: lbu         $t6, 0x94($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X94);
            goto L_801D0A98;
    }
    goto skip_1;
    // 0x801D0A8C: lbu         $t6, 0x94($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X94);
    skip_1:
    // 0x801D0A90: lwc1        $f2, 0x35D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X35D4);
    // 0x801D0A94: lbu         $t6, 0x94($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X94);
L_801D0A98:
    // 0x801D0A98: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x801D0A9C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D0AA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0AA4: div.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f2.fl);
    // 0x801D0AA8: blez        $t6, L_801D0BD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D0AAC: div.s       $f24, $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f2.fl);
            goto L_801D0BD8;
    }
    // 0x801D0AAC: div.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f2.fl);
    // 0x801D0AB0: ldc1        $f28, 0x35D8($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X35D8);
    // 0x801D0AB4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D0AB8: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801D0ABC: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801D0AC0: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D0AC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0AC8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D0ACC: ldc1        $f22, 0x35E0($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X35E0);
    // 0x801D0AD0: sdc1        $f6, 0x58($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X58, ctx->r29);
    // 0x801D0AD4: sdc1        $f4, 0x60($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X60, ctx->r29);
    // 0x801D0AD8: cvt.d.s     $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f30.d = CVT_D_S(ctx->f20.fl);
    // 0x801D0ADC: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_801D0AE0:
    // 0x801D0AE0: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x801D0AE4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D0AE8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801D0AEC: jal         0x8012C6B4
    // 0x801D0AF0: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801D0AF0: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    after_2:
    // 0x801D0AF4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D0AF8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D0AFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D0B00: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D0B04: div.d       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f26.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f26.d);
    // 0x801D0B08: add.d       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f28.d); 
    ctx->f4.d = ctx->f18.d + ctx->f28.d;
    // 0x801D0B0C: jal         0x8012C6B4
    // 0x801D0B10: cvt.s.d     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f24.fl = CVT_S_D(ctx->f4.d);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D0B10: cvt.s.d     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f24.fl = CVT_S_D(ctx->f4.d);
    after_3:
    // 0x801D0B14: addiu       $t0, $v0, -0x64
    ctx->r8 = ADD32(ctx->r2, -0X64);
    // 0x801D0B18: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801D0B1C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D0B20: cvt.d.s     $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f20.d = CVT_D_S(ctx->f24.fl);
    // 0x801D0B24: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D0B28: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D0B2C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D0B30: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D0B34: div.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f22.d);
    // 0x801D0B38: add.d       $f6, $f30, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f30.d + ctx->f4.d;
    // 0x801D0B3C: mul.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x801D0B40: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D0B44: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D0B48: jal         0x8012C6B4
    // 0x801D0B4C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D0B4C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x801D0B50: addiu       $t1, $v0, -0x64
    ctx->r9 = ADD32(ctx->r2, -0X64);
    // 0x801D0B54: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801D0B58: ldc1        $f4, 0x60($sp)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r29, 0X60);
    // 0x801D0B5C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D0B60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D0B64: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D0B68: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D0B6C: div.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f22.d);
    // 0x801D0B70: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D0B74: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x801D0B78: mul.d       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f20.d);
    // 0x801D0B7C: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x801D0B80: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x801D0B84: jal         0x8012C6B4
    // 0x801D0B88: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D0B88: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x801D0B8C: addiu       $t2, $v0, -0x64
    ctx->r10 = ADD32(ctx->r2, -0X64);
    // 0x801D0B90: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x801D0B94: ldc1        $f18, 0x58($sp)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r29, 0X58);
    // 0x801D0B98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D0B9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D0BA0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D0BA4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D0BA8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D0BAC: div.d       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f22.d);
    // 0x801D0BB0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D0BB4: add.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f18.d + ctx->f4.d;
    // 0x801D0BB8: mul.d       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f20.d);
    // 0x801D0BBC: add.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f6.d + ctx->f8.d;
    // 0x801D0BC0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D0BC4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x801D0BC8: lbu         $t3, 0x94($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X94);
    // 0x801D0BCC: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801D0BD0: bnel        $at, $zero, L_801D0AE0
    if (ctx->r1 != 0) {
        // 0x801D0BD4: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_801D0AE0;
    }
    goto skip_2;
    // 0x801D0BD4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    skip_2:
L_801D0BD8:
    // 0x801D0BD8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0BDC: addiu       $a1, $a1, 0xC1C
    ctx->r5 = ADD32(ctx->r5, 0XC1C);
    // 0x801D0BE0: jal         0x800058DC
    // 0x801D0BE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D0BE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x801D0BE8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801D0BEC:
    // 0x801D0BEC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D0BF0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D0BF4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D0BF8: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801D0BFC: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801D0C00: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801D0C04: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801D0C08: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801D0C0C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801D0C10: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801D0C14: jr          $ra
    // 0x801D0C18: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801D0C18: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d0c1c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d0c1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0C1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801D0C20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D0C24: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D0C28: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D0C2C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x801D0C30: lwc1        $f18, 0x6C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x801D0C34: lwc1        $f20, 0x70($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X70);
    // 0x801D0C38: lwc1        $f22, 0x74($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801D0C3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801D0C40: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801D0C44: jal         0x801CD878
    // 0x801D0C48: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D0C48: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801D0C4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801D0C50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801D0C54: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801D0C58: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801D0C5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801D0C60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0C64: blezl       $t6, L_801D0D90
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D0C68: lhu         $v0, 0x92($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X92);
            goto L_801D0D90;
    }
    goto skip_0;
    // 0x801D0C68: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    skip_0:
    // 0x801D0C6C: ldc1        $f2, 0x35E8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X35E8);
    // 0x801D0C70: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D0C74: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D0C78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D0C7C: nop

    // 0x801D0C80: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_801D0C84:
    // 0x801D0C84: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801D0C88: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D0C8C: lhu         $t0, 0x92($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X92);
    // 0x801D0C90: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D0C94: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D0C98: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D0C9C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D0CA0: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D0CA4: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x801D0CA8: bgez        $t0, L_801D0CC0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D0CAC: cvt.d.s     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
            goto L_801D0CC0;
    }
    // 0x801D0CAC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D0CB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D0CB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D0CB8: nop

    // 0x801D0CBC: add.d       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f10.d + ctx->f4.d;
L_801D0CC0:
    // 0x801D0CC0: add.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f10.d + ctx->f0.d;
    // 0x801D0CC4: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D0CC8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D0CCC: div.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801D0CD0: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x801D0CD4: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801D0CD8: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x801D0CDC: sub.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f20.fl;
    // 0x801D0CE0: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801D0CE4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D0CE8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D0CEC: lhu         $t1, 0x92($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X92);
    // 0x801D0CF0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801D0CF4: bgez        $t1, L_801D0D0C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801D0CF8: cvt.d.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
            goto L_801D0D0C;
    }
    // 0x801D0CF8: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D0CFC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D0D00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D0D04: nop

    // 0x801D0D08: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
L_801D0D0C:
    // 0x801D0D0C: add.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f4.d + ctx->f0.d;
    // 0x801D0D10: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D0D14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D0D18: div.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x801D0D1C: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x801D0D20: mul.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801D0D24: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x801D0D28: sub.s       $f10, $f16, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x801D0D2C: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801D0D30: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D0D34: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801D0D38: lhu         $t2, 0x92($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X92);
    // 0x801D0D3C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x801D0D40: bgez        $t2, L_801D0D58
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801D0D44: cvt.d.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
            goto L_801D0D58;
    }
    // 0x801D0D44: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D0D48: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801D0D4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D0D50: nop

    // 0x801D0D54: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
L_801D0D58:
    // 0x801D0D58: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x801D0D5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D0D60: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D0D64: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x801D0D68: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D0D6C: mul.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801D0D70: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801D0D74: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D0D78: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801D0D7C: lbu         $t3, 0x94($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X94);
    // 0x801D0D80: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801D0D84: bnel        $at, $zero, L_801D0C84
    if (ctx->r1 != 0) {
        // 0x801D0D88: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_801D0C84;
    }
    goto skip_1;
    // 0x801D0D88: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_1:
    // 0x801D0D8C: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
L_801D0D90:
    // 0x801D0D90: lhu         $t4, 0x90($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X90);
    // 0x801D0D94: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x801D0D98: slt         $v1, $t4, $v0
    ctx->r3 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D0D9C: bne         $v1, $zero, L_801D0DB8
    if (ctx->r3 != 0) {
        // 0x801D0DA0: sh          $t5, 0x92($a0)
        MEM_H(0X92, ctx->r4) = ctx->r13;
            goto L_801D0DB8;
    }
    // 0x801D0DA0: sh          $t5, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r13;
    // 0x801D0DA4: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D0DA8: lhu         $t7, 0x4C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4C);
    // 0x801D0DAC: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x801D0DB0: beql        $t8, $zero, L_801D0DD4
    if (ctx->r24 == 0) {
        // 0x801D0DB4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D0DD4;
    }
    goto skip_2;
    // 0x801D0DB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_801D0DB8:
    // 0x801D0DB8: jal         0x801CE5B0
    // 0x801D0DBC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D0DBC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D0DC0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0DC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801D0DC8: jal         0x800058DC
    // 0x801D0DCC: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D0DCC: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D0DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D0DD4:
    // 0x801D0DD4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D0DD8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D0DDC: jr          $ra
    // 0x801D0DE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801D0DE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d0de4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d0de4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0DE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D0DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0DEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D0DF0: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801D0DF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D0DF8: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D0DFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D0E00: jal         0x801CE0E8
    // 0x801D0E04: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D0E04: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x801D0E08: bne         $v0, $zero, L_801D0E1C
    if (ctx->r2 != 0) {
        // 0x801D0E0C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D0E1C;
    }
    // 0x801D0E0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D0E10: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0E14: jal         0x800058DC
    // 0x801D0E18: addiu       $a1, $a1, 0xE2C
    ctx->r5 = ADD32(ctx->r5, 0XE2C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D0E18: addiu       $a1, $a1, 0xE2C
    ctx->r5 = ADD32(ctx->r5, 0XE2C);
    after_1:
L_801D0E1C:
    // 0x801D0E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D0E20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D0E24: jr          $ra
    // 0x801D0E28: nop

    return;
    // 0x801D0E28: nop

;}
RECOMP_FUNC void M8_FUN_801d0e2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0E34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D0E38: jal         0x801CD878
    // 0x801D0E3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D0E3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D0E40: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801D0E44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801D0E48: lhu         $v0, 0x92($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X92);
    // 0x801D0E4C: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x801D0E50: bne         $at, $zero, L_801D0F00
    if (ctx->r1 != 0) {
        // 0x801D0E54: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801D0F00;
    }
    // 0x801D0E54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801D0E58: lbu         $t6, 0x94($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X94);
    // 0x801D0E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801D0E60: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801D0E64: blezl       $t6, L_801D0F04
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D0E68: lhu         $t3, 0x90($a2)
        ctx->r11 = MEM_HU(ctx->r6, 0X90);
            goto L_801D0F04;
    }
    goto skip_0;
    // 0x801D0E68: lhu         $t3, 0x90($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X90);
    skip_0:
    // 0x801D0E6C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801D0E70: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D0E74: nop

    // 0x801D0E78: lhu         $v1, 0x90($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X90);
L_801D0E7C:
    // 0x801D0E7C: lhu         $t0, 0x92($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X92);
    // 0x801D0E80: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801D0E84: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x801D0E88: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801D0E8C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D0E90: cvt.d.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.d = CVT_D_W(ctx->f18.u32l);
    // 0x801D0E94: subu        $t1, $v1, $t0
    ctx->r9 = SUB32(ctx->r3, ctx->r8);
    // 0x801D0E98: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x801D0E9C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D0EA0: bgez        $v1, L_801D0EBC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801D0EA4: cvt.d.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
            goto L_801D0EBC;
    }
    // 0x801D0EA4: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x801D0EA8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D0EAC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D0EB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D0EB4: nop

    // 0x801D0EB8: add.d       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f10.d + ctx->f16.d;
L_801D0EBC:
    // 0x801D0EBC: sub.d       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f10.d - ctx->f2.d;
    // 0x801D0EC0: lwc1        $f8, 0x60($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X60);
    // 0x801D0EC4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801D0EC8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801D0ECC: div.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f18.d);
    // 0x801D0ED0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801D0ED4: mul.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x801D0ED8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801D0EDC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801D0EE0: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801D0EE4: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801D0EE8: lbu         $t2, 0x94($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X94);
    // 0x801D0EEC: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801D0EF0: bnel        $at, $zero, L_801D0E7C
    if (ctx->r1 != 0) {
        // 0x801D0EF4: lhu         $v1, 0x90($a2)
        ctx->r3 = MEM_HU(ctx->r6, 0X90);
            goto L_801D0E7C;
    }
    goto skip_1;
    // 0x801D0EF4: lhu         $v1, 0x90($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X90);
    skip_1:
    // 0x801D0EF8: lhu         $v0, 0x92($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X92);
    // 0x801D0EFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801D0F00:
    // 0x801D0F00: lhu         $t3, 0x90($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X90);
L_801D0F04:
    // 0x801D0F04: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x801D0F08: sh          $t4, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r12;
    // 0x801D0F0C: slt         $a0, $t3, $v1
    ctx->r4 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D0F10: bnel        $a0, $zero, L_801D0F2C
    if (ctx->r4 != 0) {
        // 0x801D0F14: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801D0F2C;
    }
    goto skip_2;
    // 0x801D0F14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_2:
    // 0x801D0F18: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    // 0x801D0F1C: lhu         $t6, 0x4C($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4C);
    // 0x801D0F20: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x801D0F24: beq         $t7, $zero, L_801D0F44
    if (ctx->r15 == 0) {
        // 0x801D0F28: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801D0F44;
    }
    // 0x801D0F28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_801D0F2C:
    // 0x801D0F2C: jal         0x801CE5B0
    // 0x801D0F30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D0F30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x801D0F34: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0F38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D0F3C: jal         0x800058DC
    // 0x801D0F40: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D0F40: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
L_801D0F44:
    // 0x801D0F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D0F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0F4C: jr          $ra
    // 0x801D0F50: nop

    return;
    // 0x801D0F50: nop

;}
RECOMP_FUNC void M8_FUN_801d0f54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0F54: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801D0F58: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801D0F5C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801D0F60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801D0F64: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801D0F68: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D0F6C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801D0F70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801D0F74: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D0F78: sb          $zero, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = 0;
    // 0x801D0F7C: jal         0x801CE0E8
    // 0x801D0F80: addiu       $a1, $sp, 0x3B
    ctx->r5 = ADD32(ctx->r29, 0X3B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D0F80: addiu       $a1, $sp, 0x3B
    ctx->r5 = ADD32(ctx->r29, 0X3B);
    after_0:
    // 0x801D0F84: bnel        $v0, $zero, L_801D1064
    if (ctx->r2 != 0) {
        // 0x801D0F88: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801D1064;
    }
    goto skip_0;
    // 0x801D0F88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801D0F8C: lbu         $t6, 0x94($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X94);
    // 0x801D0F90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D0F94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0F98: blez        $t6, L_801D1050
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D0F9C: nop
    
            goto L_801D1050;
    }
    // 0x801D0F9C: nop

    // 0x801D0FA0: ldc1        $f20, 0x35F0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X35F0);
    // 0x801D0FA4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_801D0FA8:
    // 0x801D0FA8: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801D0FAC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D0FB0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D0FB4: jal         0x8012C6B4
    // 0x801D0FB8: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D0FB8: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    after_1:
    // 0x801D0FBC: addiu       $t0, $v0, -0x64
    ctx->r8 = ADD32(ctx->r2, -0X64);
    // 0x801D0FC0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D0FC4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D0FC8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D0FCC: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D0FD0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D0FD4: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x801D0FD8: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x801D0FDC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D0FE0: jal         0x8012C6B4
    // 0x801D0FE4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801D0FE4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x801D0FE8: addiu       $t1, $v0, -0x64
    ctx->r9 = ADD32(ctx->r2, -0X64);
    // 0x801D0FEC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801D0FF0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D0FF4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D0FF8: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D0FFC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D1000: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x801D1004: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x801D1008: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801D100C: jal         0x8012C6B4
    // 0x801D1010: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D1010: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x801D1014: addiu       $t2, $v0, -0x64
    ctx->r10 = ADD32(ctx->r2, -0X64);
    // 0x801D1018: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x801D101C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D1020: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D1024: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x801D1028: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D102C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x801D1030: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x801D1034: add.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f16.d + ctx->f4.d;
    // 0x801D1038: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801D103C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801D1040: lbu         $t3, 0x94($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X94);
    // 0x801D1044: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801D1048: bnel        $at, $zero, L_801D0FA8
    if (ctx->r1 != 0) {
        // 0x801D104C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_801D0FA8;
    }
    goto skip_1;
    // 0x801D104C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    skip_1:
L_801D1050:
    // 0x801D1050: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1054: addiu       $a1, $a1, 0x1080
    ctx->r5 = ADD32(ctx->r5, 0X1080);
    // 0x801D1058: jal         0x800058DC
    // 0x801D105C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D105C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x801D1060: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801D1064:
    // 0x801D1064: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D1068: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801D106C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801D1070: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x801D1074: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x801D1078: jr          $ra
    // 0x801D107C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801D107C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d1080(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d1080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801D1084: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801D1088: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D108C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D1090: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D1094: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x801D1098: lwc1        $f20, 0x70($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X70);
    // 0x801D109C: lwc1        $f22, 0x74($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X74);
    // 0x801D10A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801D10A4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801D10A8: jal         0x801CD878
    // 0x801D10AC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D10AC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801D10B0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x801D10B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x801D10B8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801D10BC: lbu         $t6, 0x94($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X94);
    // 0x801D10C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801D10C4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801D10C8: blezl       $t6, L_801D1244
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D10CC: lhu         $v0, 0x92($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X92);
            goto L_801D1244;
    }
    goto skip_0;
    // 0x801D10CC: lhu         $v0, 0x92($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X92);
    skip_0:
    // 0x801D10D0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801D10D4: lui         $at, 0x400C
    ctx->r1 = S32(0X400C << 16);
    // 0x801D10D8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D10DC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D10E0: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x801D10E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D10E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801D10EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801D10F0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_801D10F4:
    // 0x801D10F4: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801D10F8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D10FC: lhu         $t0, 0x92($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X92);
    // 0x801D1100: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D1104: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D1108: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D110C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D1110: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D1114: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801D1118: bgez        $t0, L_801D1130
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D111C: cvt.d.s     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
            goto L_801D1130;
    }
    // 0x801D111C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D1120: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D1124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D1128: nop

    // 0x801D112C: add.d       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f10.d + ctx->f4.d;
L_801D1130:
    // 0x801D1130: add.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d + ctx->f14.d;
    // 0x801D1134: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D1138: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D113C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801D1140: div.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801D1144: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801D1148: sub.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x801D114C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D1150: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D1154: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x801D1158: lhu         $t1, 0x92($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X92);
    // 0x801D115C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801D1160: bgez        $t1, L_801D1178
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801D1164: cvt.d.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
            goto L_801D1178;
    }
    // 0x801D1164: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D1168: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801D116C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D1170: nop

    // 0x801D1174: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
L_801D1178:
    // 0x801D1178: add.d       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f8.d + ctx->f14.d;
    // 0x801D117C: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D1180: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D1184: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801D1188: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801D118C: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801D1190: sub.s       $f8, $f12, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f22.fl;
    // 0x801D1194: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801D1198: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D119C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801D11A0: lhu         $t2, 0x92($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X92);
    // 0x801D11A4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801D11A8: bgez        $t2, L_801D11C0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801D11AC: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D11C0;
    }
    // 0x801D11AC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D11B0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D11B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D11B8: nop

    // 0x801D11BC: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D11C0:
    // 0x801D11C0: add.d       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = ctx->f6.d + ctx->f14.d;
    // 0x801D11C4: lh          $t3, 0x14($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X14);
    // 0x801D11C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D11CC: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x801D11D0: div.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x801D11D4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D11D8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801D11DC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D11E0: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x801D11E4: bgez        $a0, L_801D11F8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801D11E8: andi        $t4, $a0, 0x7
        ctx->r12 = ctx->r4 & 0X7;
            goto L_801D11F8;
    }
    // 0x801D11E8: andi        $t4, $a0, 0x7
    ctx->r12 = ctx->r4 & 0X7;
    // 0x801D11EC: beq         $t4, $zero, L_801D11F8
    if (ctx->r12 == 0) {
        // 0x801D11F0: nop
    
            goto L_801D11F8;
    }
    // 0x801D11F0: nop

    // 0x801D11F4: addiu       $t4, $t4, -0x8
    ctx->r12 = ADD32(ctx->r12, -0X8);
L_801D11F8:
    // 0x801D11F8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x801D11FC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801D1200: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D1204: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x801D1208: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D120C: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x801D1210: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801D1214: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801D1218: nop

    // 0x801D121C: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x801D1220: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
    // 0x801D1224: lh          $t0, 0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X14);
    // 0x801D1228: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x801D122C: sh          $t1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r9;
    // 0x801D1230: lbu         $t2, 0x94($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X94);
    // 0x801D1234: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801D1238: bnel        $at, $zero, L_801D10F4
    if (ctx->r1 != 0) {
        // 0x801D123C: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_801D10F4;
    }
    goto skip_1;
    // 0x801D123C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_1:
    // 0x801D1240: lhu         $v0, 0x92($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X92);
L_801D1244:
    // 0x801D1244: lhu         $t4, 0x90($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X90);
    // 0x801D1248: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801D124C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x801D1250: slt         $v1, $t4, $v0
    ctx->r3 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D1254: bne         $v1, $zero, L_801D1270
    if (ctx->r3 != 0) {
        // 0x801D1258: sh          $t5, 0x92($a2)
        MEM_H(0X92, ctx->r6) = ctx->r13;
            goto L_801D1270;
    }
    // 0x801D1258: sh          $t5, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r13;
    // 0x801D125C: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x801D1260: lhu         $t7, 0x4C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4C);
    // 0x801D1264: andi        $t3, $t7, 0x8000
    ctx->r11 = ctx->r15 & 0X8000;
    // 0x801D1268: beql        $t3, $zero, L_801D128C
    if (ctx->r11 == 0) {
        // 0x801D126C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801D128C;
    }
    goto skip_2;
    // 0x801D126C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
L_801D1270:
    // 0x801D1270: jal         0x801CE5B0
    // 0x801D1274: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D1274: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_1:
    // 0x801D1278: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D127C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801D1280: jal         0x800058DC
    // 0x801D1284: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D1284: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D1288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801D128C:
    // 0x801D128C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D1290: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D1294: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D1298: jr          $ra
    // 0x801D129C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801D129C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d12a0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d12a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D12A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D12A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D12A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D12AC: sb          $zero, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = 0;
    // 0x801D12B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D12B4: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D12B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D12BC: jal         0x801CE0E8
    // 0x801D12C0: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D12C0: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    after_0:
    // 0x801D12C4: bne         $v0, $zero, L_801D12EC
    if (ctx->r2 != 0) {
        // 0x801D12C8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D12EC;
    }
    // 0x801D12C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D12CC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D12D0: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x801D12D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D12D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D12DC: addiu       $a1, $a1, 0x12FC
    ctx->r5 = ADD32(ctx->r5, 0X12FC);
    // 0x801D12E0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D12E4: jal         0x800058DC
    // 0x801D12E8: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D12E8: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    after_1:
L_801D12EC:
    // 0x801D12EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D12F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D12F4: jr          $ra
    // 0x801D12F8: nop

    return;
    // 0x801D12F8: nop

;}
RECOMP_FUNC void M8_FUN_801d12fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D12FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D1300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D1304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D1308: jal         0x801CD878
    // 0x801D130C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D130C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D1310: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D1314: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801D1318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801D131C: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801D1320: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1324: blezl       $t6, L_801D137C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D1328: lhu         $v0, 0x92($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X92);
            goto L_801D137C;
    }
    goto skip_0;
    // 0x801D1328: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    skip_0:
    // 0x801D132C: ldc1        $f2, 0x35F8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X35F8);
    // 0x801D1330: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_801D1334:
    // 0x801D1334: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801D1338: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D133C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D1340: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D1344: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D1348: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801D134C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D1350: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801D1354: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D1358: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x801D135C: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801D1360: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801D1364: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801D1368: lbu         $t0, 0x94($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X94);
    // 0x801D136C: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D1370: bnel        $at, $zero, L_801D1334
    if (ctx->r1 != 0) {
        // 0x801D1374: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_801D1334;
    }
    goto skip_1;
    // 0x801D1374: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_1:
    // 0x801D1378: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
L_801D137C:
    // 0x801D137C: lhu         $t1, 0x90($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X90);
    // 0x801D1380: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801D1384: slt         $v1, $t1, $v0
    ctx->r3 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D1388: bne         $v1, $zero, L_801D13A4
    if (ctx->r3 != 0) {
        // 0x801D138C: sh          $t2, 0x92($a0)
        MEM_H(0X92, ctx->r4) = ctx->r10;
            goto L_801D13A4;
    }
    // 0x801D138C: sh          $t2, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r10;
    // 0x801D1390: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x801D1394: lhu         $t4, 0x4C($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4C);
    // 0x801D1398: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x801D139C: beql        $t5, $zero, L_801D13C0
    if (ctx->r13 == 0) {
        // 0x801D13A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D13C0;
    }
    goto skip_2;
    // 0x801D13A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_801D13A4:
    // 0x801D13A4: jal         0x801CE5B0
    // 0x801D13A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D13A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D13AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D13B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D13B4: jal         0x800058DC
    // 0x801D13B8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D13B8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D13BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D13C0:
    // 0x801D13C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D13C4: jr          $ra
    // 0x801D13C8: nop

    return;
    // 0x801D13C8: nop

;}
RECOMP_FUNC void M8_FUN_801d13cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D13CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D13D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D13D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D13D8: sb          $zero, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = 0;
    // 0x801D13DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D13E0: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D13E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D13E8: jal         0x801CE0E8
    // 0x801D13EC: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D13EC: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    after_0:
    // 0x801D13F0: bne         $v0, $zero, L_801D1418
    if (ctx->r2 != 0) {
        // 0x801D13F4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D1418;
    }
    // 0x801D13F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D13F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D13FC: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x801D1400: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1404: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D1408: addiu       $a1, $a1, 0x1428
    ctx->r5 = ADD32(ctx->r5, 0X1428);
    // 0x801D140C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D1410: jal         0x800058DC
    // 0x801D1414: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D1414: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    after_1:
L_801D1418:
    // 0x801D1418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D141C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D1420: jr          $ra
    // 0x801D1424: nop

    return;
    // 0x801D1424: nop

;}
RECOMP_FUNC void M8_FUN_801d1428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D142C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D1430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D1434: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x801D1438: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D143C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801D1440: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801D1444: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D1448: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801D144C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D1450: bgez        $t6, L_801D146C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D1454: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D146C;
    }
    // 0x801D1454: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D1458: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D145C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D1460: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D1464: nop

    // 0x801D1468: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D146C:
    // 0x801D146C: lhu         $t7, 0x90($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X90);
    // 0x801D1470: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x801D1474: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D1478: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801D147C: bgez        $t7, L_801D1494
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D1480: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_801D1494;
    }
    // 0x801D1480: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x801D1484: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D1488: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D148C: nop

    // 0x801D1490: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_801D1494:
    // 0x801D1494: add.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f18.d + ctx->f2.d;
    // 0x801D1498: lbu         $a0, 0x7B($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X7B);
    // 0x801D149C: lbu         $a1, 0x7F($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7F);
    // 0x801D14A0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801D14A4: div.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x801D14A8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801D14AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801D14B0: jal         0x801CD500
    // 0x801D14B4: nop

    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_0;
    // 0x801D14B4: nop

    after_0:
    // 0x801D14B8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801D14BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801D14C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D14C4: lbu         $t8, 0x94($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X94);
    // 0x801D14C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D14CC: blezl       $t8, L_801D1540
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801D14D0: lhu         $v0, 0x92($a3)
        ctx->r2 = MEM_HU(ctx->r7, 0X92);
            goto L_801D1540;
    }
    goto skip_0;
    // 0x801D14D0: lhu         $v0, 0x92($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X92);
    skip_0:
    // 0x801D14D4: ldc1        $f2, 0x3600($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X3600);
    // 0x801D14D8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
L_801D14DC:
    // 0x801D14DC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x801D14E0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D14E4: lbu         $t2, 0x7C($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X7C);
    // 0x801D14E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801D14EC: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801D14F0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801D14F4: lwc1        $f16, 0x20($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801D14F8: sb          $t2, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r10;
    // 0x801D14FC: lbu         $t3, 0x7D($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X7D);
    // 0x801D1500: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D1504: mul.d       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801D1508: sb          $t3, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r11;
    // 0x801D150C: lbu         $t4, 0x7E($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X7E);
    // 0x801D1510: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
    // 0x801D1514: sb          $t4, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r12;
    // 0x801D1518: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x801D151C: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x801D1520: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801D1524: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801D1528: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x801D152C: lbu         $t5, 0x94($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X94);
    // 0x801D1530: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801D1534: bnel        $at, $zero, L_801D14DC
    if (ctx->r1 != 0) {
        // 0x801D1538: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_801D14DC;
    }
    goto skip_1;
    // 0x801D1538: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    skip_1:
    // 0x801D153C: lhu         $v0, 0x92($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X92);
L_801D1540:
    // 0x801D1540: lhu         $t6, 0x90($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X90);
    // 0x801D1544: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801D1548: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801D154C: slt         $v1, $t6, $v0
    ctx->r3 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D1550: bne         $v1, $zero, L_801D156C
    if (ctx->r3 != 0) {
        // 0x801D1554: sh          $t7, 0x92($a3)
        MEM_H(0X92, ctx->r7) = ctx->r15;
            goto L_801D156C;
    }
    // 0x801D1554: sh          $t7, 0x92($a3)
    MEM_H(0X92, ctx->r7) = ctx->r15;
    // 0x801D1558: lw          $t8, 0xC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XC);
    // 0x801D155C: lhu         $t9, 0x4C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4C);
    // 0x801D1560: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801D1564: beql        $t0, $zero, L_801D1588
    if (ctx->r8 == 0) {
        // 0x801D1568: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D1588;
    }
    goto skip_2;
    // 0x801D1568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_801D156C:
    // 0x801D156C: jal         0x801CE5B0
    // 0x801D1570: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D1570: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x801D1574: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1578: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D157C: jal         0x800058DC
    // 0x801D1580: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D1580: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D1584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D1588:
    // 0x801D1588: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D158C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D1590: jr          $ra
    // 0x801D1594: nop

    return;
    // 0x801D1594: nop

;}
RECOMP_FUNC void M8_FUN_801d1598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1598: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801D159C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D15A0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801D15A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801D15A8: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D15AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801D15B0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D15B4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D15B8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D15BC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D15C0: sb          $zero, 0x43($sp)
    MEM_B(0X43, ctx->r29) = 0;
    // 0x801D15C4: jal         0x801CE0E8
    // 0x801D15C8: addiu       $a1, $sp, 0x43
    ctx->r5 = ADD32(ctx->r29, 0X43);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D15C8: addiu       $a1, $sp, 0x43
    ctx->r5 = ADD32(ctx->r29, 0X43);
    after_0:
    // 0x801D15CC: bnel        $v0, $zero, L_801D169C
    if (ctx->r2 != 0) {
        // 0x801D15D0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801D169C;
    }
    goto skip_0;
    // 0x801D15D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801D15D4: lbu         $t6, 0x94($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X94);
    // 0x801D15D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D15DC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D15E0: blez        $t6, L_801D1688
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D15E4: nop
    
            goto L_801D1688;
    }
    // 0x801D15E4: nop

    // 0x801D15E8: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D15EC: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D15F0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D15F4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D15F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D15FC: nop

    // 0x801D1600: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_801D1604:
    // 0x801D1604: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x801D1608: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D160C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D1610: jal         0x8012C6B4
    // 0x801D1614: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D1614: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    after_1:
    // 0x801D1618: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D161C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D1620: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D1624: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D1628: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D162C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D1630: sub.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = ctx->f16.d - ctx->f20.d;
    // 0x801D1634: div.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f22.d);
    // 0x801D1638: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x801D163C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D1640: jal         0x8012C6B4
    // 0x801D1644: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801D1644: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x801D1648: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801D164C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D1650: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D1654: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D1658: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D165C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D1660: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D1664: sub.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = ctx->f8.d - ctx->f20.d;
    // 0x801D1668: div.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f22.d);
    // 0x801D166C: add.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f18.d + ctx->f16.d;
    // 0x801D1670: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D1674: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x801D1678: lbu         $t0, 0x94($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X94);
    // 0x801D167C: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D1680: bnel        $at, $zero, L_801D1604
    if (ctx->r1 != 0) {
        // 0x801D1684: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_801D1604;
    }
    goto skip_1;
    // 0x801D1684: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    skip_1:
L_801D1688:
    // 0x801D1688: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D168C: addiu       $a1, $a1, -0x1858
    ctx->r5 = ADD32(ctx->r5, -0X1858);
    // 0x801D1690: jal         0x800058DC
    // 0x801D1694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D1694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x801D1698: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801D169C:
    // 0x801D169C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D16A0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D16A4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D16A8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D16AC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D16B0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D16B4: jr          $ra
    // 0x801D16B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801D16B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d16bc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d16bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D16BC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801D16C0: lh          $t6, -0x41DE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X41DE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d16c4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d16c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D16C4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801D16C8: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x801D16CC: addiu       $t7, $zero, 0x2800
    ctx->r15 = ADD32(0, 0X2800);
    // 0x801D16D0: subu        $s0, $t7, $t6
    ctx->r16 = SUB32(ctx->r15, ctx->r14);
    // 0x801D16D4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801D16D8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801D16DC: andi        $s0, $s0, 0x1FFF
    ctx->r16 = ctx->r16 & 0X1FFF;
    // 0x801D16E0: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x801D16E4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801D16E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801D16EC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801D16F0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D16F4: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x801D16F8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801D16FC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801D1700: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x801D1704: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801D1708: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801D170C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D1710: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D1714: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D1718: jal         0x8001EB64
    // 0x801D171C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D171C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x801D1720: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801D1724: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x801D1728: jal         0x8001EAD0
    // 0x801D172C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D172C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801D1730: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x801D1734: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    // 0x801D1738: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D173C: jal         0x801CE0E8
    // 0x801D1740: addiu       $a1, $sp, 0x5B
    ctx->r5 = ADD32(ctx->r29, 0X5B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_2;
    // 0x801D1740: addiu       $a1, $sp, 0x5B
    ctx->r5 = ADD32(ctx->r29, 0X5B);
    after_2:
    // 0x801D1744: bnel        $v0, $zero, L_801D1890
    if (ctx->r2 != 0) {
        // 0x801D1748: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801D1890;
    }
    goto skip_0;
    // 0x801D1748: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x801D174C: lbu         $t8, 0x94($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X94);
    // 0x801D1750: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D1754: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D1758: blez        $t8, L_801D187C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801D175C: nop
    
            goto L_801D187C;
    }
    // 0x801D175C: nop

    // 0x801D1760: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D1764: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801D1768: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D176C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D1770: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D1774: nop

L_801D1778:
    // 0x801D1778: jal         0x8012C6B4
    // 0x801D177C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D177C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_3:
    // 0x801D1780: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D1784: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x801D1788: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x801D178C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D1790: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D1794: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801D1798: lw          $s0, 0x30($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X30);
    // 0x801D179C: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x801D17A0: jal         0x8012C6B4
    // 0x801D17A4: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D17A4: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    after_4:
    // 0x801D17A8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801D17AC: mul.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x801D17B0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801D17B4: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801D17B8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D17BC: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x801D17C0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D17C4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801D17C8: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x801D17CC: add.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f18.d + ctx->f8.d;
    // 0x801D17D0: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x801D17D4: jal         0x8012C6B4
    // 0x801D17D8: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D17D8: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x801D17DC: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801D17E0: mul.s       $f6, $f28, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x801D17E4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801D17E8: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x801D17EC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D17F0: div.d       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x801D17F4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D17F8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801D17FC: add.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f10.d + ctx->f4.d;
    // 0x801D1800: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x801D1804: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D1808: jal         0x8012C6B4
    // 0x801D180C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801D180C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_6:
    // 0x801D1810: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801D1814: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D1818: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801D181C: cvt.d.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.d = CVT_D_W(ctx->f18.u32l);
    // 0x801D1820: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D1824: div.d       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x801D1828: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801D182C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D1830: jal         0x8012C6B4
    // 0x801D1834: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x801D1834: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_7:
    // 0x801D1838: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801D183C: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D1840: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D1844: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D1848: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D184C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x801D1850: add.d       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f8.d + ctx->f24.d;
    // 0x801D1854: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x801D1858: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x801D185C: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x801D1860: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D1864: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D1868: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801D186C: lbu         $t2, 0x94($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X94);
    // 0x801D1870: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801D1874: bne         $at, $zero, L_801D1778
    if (ctx->r1 != 0) {
        // 0x801D1878: nop
    
            goto L_801D1778;
    }
    // 0x801D1878: nop

L_801D187C:
    // 0x801D187C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1880: addiu       $a1, $a1, -0x1858
    ctx->r5 = ADD32(ctx->r5, -0X1858);
    // 0x801D1884: jal         0x800058DC
    // 0x801D1888: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801D1888: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x801D188C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D1890:
    // 0x801D1890: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D1894: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D1898: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D189C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801D18A0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801D18A4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x801D18A8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x801D18AC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x801D18B0: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x801D18B4: jr          $ra
    // 0x801D18B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801D18B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d18bc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d18bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D18BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D18C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D18C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D18C8: sb          $zero, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = 0;
    // 0x801D18CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D18D0: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D18D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D18D8: jal         0x801CE0E8
    // 0x801D18DC: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D18DC: addiu       $a1, $sp, 0x1B
    ctx->r5 = ADD32(ctx->r29, 0X1B);
    after_0:
    // 0x801D18E0: bne         $v0, $zero, L_801D1908
    if (ctx->r2 != 0) {
        // 0x801D18E4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D1908;
    }
    // 0x801D18E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D18E8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D18EC: lh          $t9, 0x98($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X98);
    // 0x801D18F0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D18F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D18F8: addiu       $a1, $a1, 0x1918
    ctx->r5 = ADD32(ctx->r5, 0X1918);
    // 0x801D18FC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D1900: jal         0x800058DC
    // 0x801D1904: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D1904: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    after_1:
L_801D1908:
    // 0x801D1908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D190C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D1910: jr          $ra
    // 0x801D1914: nop

    return;
    // 0x801D1914: nop

;}
RECOMP_FUNC void M8_FUN_801d1918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1918: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D191C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D1920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D1924: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x801D1928: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D192C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801D1930: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801D1934: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D1938: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801D193C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D1940: bgez        $t6, L_801D195C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D1944: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D195C;
    }
    // 0x801D1944: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D1948: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D194C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D1950: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D1954: nop

    // 0x801D1958: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D195C:
    // 0x801D195C: lhu         $t7, 0x90($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X90);
    // 0x801D1960: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x801D1964: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D1968: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801D196C: bgez        $t7, L_801D1984
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D1970: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_801D1984;
    }
    // 0x801D1970: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x801D1974: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D1978: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D197C: nop

    // 0x801D1980: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_801D1984:
    // 0x801D1984: add.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f18.d + ctx->f2.d;
    // 0x801D1988: lbu         $a0, 0x7B($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X7B);
    // 0x801D198C: lbu         $a1, 0x7F($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7F);
    // 0x801D1990: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801D1994: div.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x801D1998: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801D199C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801D19A0: jal         0x801CD500
    // 0x801D19A4: nop

    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_0;
    // 0x801D19A4: nop

    after_0:
    // 0x801D19A8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801D19AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801D19B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D19B4: lbu         $t8, 0x94($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X94);
    // 0x801D19B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D19BC: blezl       $t8, L_801D1A30
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801D19C0: lhu         $v0, 0x92($a3)
        ctx->r2 = MEM_HU(ctx->r7, 0X92);
            goto L_801D1A30;
    }
    goto skip_0;
    // 0x801D19C0: lhu         $v0, 0x92($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X92);
    skip_0:
    // 0x801D19C4: ldc1        $f2, 0x3608($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X3608);
    // 0x801D19C8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
L_801D19CC:
    // 0x801D19CC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x801D19D0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D19D4: lbu         $t2, 0x7C($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X7C);
    // 0x801D19D8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801D19DC: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801D19E0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801D19E4: lwc1        $f16, 0x20($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801D19E8: sb          $t2, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r10;
    // 0x801D19EC: lbu         $t3, 0x7D($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X7D);
    // 0x801D19F0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D19F4: mul.d       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801D19F8: sb          $t3, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r11;
    // 0x801D19FC: lbu         $t4, 0x7E($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X7E);
    // 0x801D1A00: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
    // 0x801D1A04: sb          $t4, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r12;
    // 0x801D1A08: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x801D1A0C: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x801D1A10: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801D1A14: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801D1A18: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x801D1A1C: lbu         $t5, 0x94($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X94);
    // 0x801D1A20: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801D1A24: bnel        $at, $zero, L_801D19CC
    if (ctx->r1 != 0) {
        // 0x801D1A28: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_801D19CC;
    }
    goto skip_1;
    // 0x801D1A28: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    skip_1:
    // 0x801D1A2C: lhu         $v0, 0x92($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X92);
L_801D1A30:
    // 0x801D1A30: lhu         $t6, 0x90($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X90);
    // 0x801D1A34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801D1A38: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801D1A3C: slt         $v1, $t6, $v0
    ctx->r3 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D1A40: bne         $v1, $zero, L_801D1A5C
    if (ctx->r3 != 0) {
        // 0x801D1A44: sh          $t7, 0x92($a3)
        MEM_H(0X92, ctx->r7) = ctx->r15;
            goto L_801D1A5C;
    }
    // 0x801D1A44: sh          $t7, 0x92($a3)
    MEM_H(0X92, ctx->r7) = ctx->r15;
    // 0x801D1A48: lw          $t8, 0xC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XC);
    // 0x801D1A4C: lhu         $t9, 0x4C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4C);
    // 0x801D1A50: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801D1A54: beql        $t0, $zero, L_801D1A78
    if (ctx->r8 == 0) {
        // 0x801D1A58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D1A78;
    }
    goto skip_2;
    // 0x801D1A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_801D1A5C:
    // 0x801D1A5C: jal         0x801CE5B0
    // 0x801D1A60: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D1A60: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x801D1A64: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1A68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D1A6C: jal         0x800058DC
    // 0x801D1A70: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D1A70: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D1A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D1A78:
    // 0x801D1A78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D1A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D1A80: jr          $ra
    // 0x801D1A84: nop

    return;
    // 0x801D1A84: nop

;}
RECOMP_FUNC void M8_FUN_801d1a88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1A88: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801D1A8C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D1A90: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D1A94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801D1A98: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801D1A9C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801D1AA0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D1AA4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D1AA8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D1AAC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D1AB0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D1AB4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D1AB8: jal         0x8001EB64
    // 0x801D1ABC: lh          $a0, 0x98($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X98);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D1ABC: lh          $a0, 0x98($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X98);
    after_0:
    // 0x801D1AC0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801D1AC4: jal         0x8001EAD0
    // 0x801D1AC8: lh          $a0, 0x98($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X98);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D1AC8: lh          $a0, 0x98($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X98);
    after_1:
    // 0x801D1ACC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801D1AD0: sb          $zero, 0x53($sp)
    MEM_B(0X53, ctx->r29) = 0;
    // 0x801D1AD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D1AD8: jal         0x801CE0E8
    // 0x801D1ADC: addiu       $a1, $sp, 0x53
    ctx->r5 = ADD32(ctx->r29, 0X53);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_2;
    // 0x801D1ADC: addiu       $a1, $sp, 0x53
    ctx->r5 = ADD32(ctx->r29, 0X53);
    after_2:
    // 0x801D1AE0: bnel        $v0, $zero, L_801D1C1C
    if (ctx->r2 != 0) {
        // 0x801D1AE4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801D1C1C;
    }
    goto skip_0;
    // 0x801D1AE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801D1AE8: jal         0x8012C6B4
    // 0x801D1AEC: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D1AEC: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_3:
    // 0x801D1AF0: lbu         $v1, 0x94($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X94);
    // 0x801D1AF4: sll         $s4, $v0, 16
    ctx->r20 = S32(ctx->r2 << 16);
    // 0x801D1AF8: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x801D1AFC: blez        $v1, L_801D1C08
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801D1B00: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801D1C08;
    }
    // 0x801D1B00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D1B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D1B08: sll         $s2, $v0, 13
    ctx->r18 = S32(ctx->r2 << 13);
L_801D1B0C:
    // 0x801D1B0C: div         $zero, $s2, $v1
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r3)));
    // 0x801D1B10: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x801D1B14: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x801D1B18: mflo        $t9
    ctx->r25 = lo;
    // 0x801D1B1C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D1B20: addu        $a0, $t9, $s4
    ctx->r4 = ADD32(ctx->r25, ctx->r20);
    // 0x801D1B24: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D1B28: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D1B2C: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801D1B30: bne         $v1, $zero, L_801D1B3C
    if (ctx->r3 != 0) {
        // 0x801D1B34: nop
    
            goto L_801D1B3C;
    }
    // 0x801D1B34: nop

    // 0x801D1B38: break       7
    do_break(2149391160);
L_801D1B3C:
    // 0x801D1B3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D1B40: bne         $v1, $at, L_801D1B54
    if (ctx->r3 != ctx->r1) {
        // 0x801D1B44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D1B54;
    }
    // 0x801D1B44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D1B48: bne         $s2, $at, L_801D1B54
    if (ctx->r18 != ctx->r1) {
        // 0x801D1B4C: nop
    
            goto L_801D1B54;
    }
    // 0x801D1B4C: nop

    // 0x801D1B50: break       6
    do_break(2149391184);
L_801D1B54:
    // 0x801D1B54: jal         0x8001EB64
    // 0x801D1B58: nop

    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x801D1B58: nop

    after_4:
    // 0x801D1B5C: lwc1        $f6, 0x88($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X88);
    // 0x801D1B60: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D1B64: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D1B68: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D1B6C: nop

    // 0x801D1B70: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x801D1B74: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801D1B78: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x801D1B7C: lwc1        $f6, 0x88($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X88);
    // 0x801D1B80: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D1B84: nop

    // 0x801D1B88: mul.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x801D1B8C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801D1B90: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x801D1B94: lbu         $t0, 0x94($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X94);
    // 0x801D1B98: div         $zero, $s2, $t0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r8)));
    // 0x801D1B9C: mflo        $t1
    ctx->r9 = lo;
    // 0x801D1BA0: addu        $a0, $t1, $s4
    ctx->r4 = ADD32(ctx->r9, ctx->r20);
    // 0x801D1BA4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D1BA8: bne         $t0, $zero, L_801D1BB4
    if (ctx->r8 != 0) {
        // 0x801D1BAC: nop
    
            goto L_801D1BB4;
    }
    // 0x801D1BAC: nop

    // 0x801D1BB0: break       7
    do_break(2149391280);
L_801D1BB4:
    // 0x801D1BB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D1BB8: bne         $t0, $at, L_801D1BCC
    if (ctx->r8 != ctx->r1) {
        // 0x801D1BBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D1BCC;
    }
    // 0x801D1BBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D1BC0: bne         $s2, $at, L_801D1BCC
    if (ctx->r18 != ctx->r1) {
        // 0x801D1BC4: nop
    
            goto L_801D1BCC;
    }
    // 0x801D1BC4: nop

    // 0x801D1BC8: break       6
    do_break(2149391304);
L_801D1BCC:
    // 0x801D1BCC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D1BD0: jal         0x8001EAD0
    // 0x801D1BD4: nop

    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x801D1BD4: nop

    after_5:
    // 0x801D1BD8: lwc1        $f6, 0x88($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X88);
    // 0x801D1BDC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D1BE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D1BE4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D1BE8: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D1BEC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801D1BF0: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801D1BF4: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801D1BF8: lbu         $v1, 0x94($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X94);
    // 0x801D1BFC: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D1C00: bnel        $at, $zero, L_801D1B0C
    if (ctx->r1 != 0) {
        // 0x801D1C04: sll         $s2, $v0, 13
        ctx->r18 = S32(ctx->r2 << 13);
            goto L_801D1B0C;
    }
    goto skip_1;
    // 0x801D1C04: sll         $s2, $v0, 13
    ctx->r18 = S32(ctx->r2 << 13);
    skip_1:
L_801D1C08:
    // 0x801D1C08: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1C0C: addiu       $a1, $a1, -0x1858
    ctx->r5 = ADD32(ctx->r5, -0X1858);
    // 0x801D1C10: jal         0x800058DC
    // 0x801D1C14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D1C14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x801D1C18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801D1C1C:
    // 0x801D1C1C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D1C20: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D1C24: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D1C28: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D1C2C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D1C30: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D1C34: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801D1C38: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801D1C3C: jr          $ra
    // 0x801D1C40: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801D1C40: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d1c44(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d1c44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1C44: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801D1C48: lh          $t6, -0x41DE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X41DE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d1c4c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d1c4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1C4C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801D1C50: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D1C54: addiu       $t7, $zero, 0x2800
    ctx->r15 = ADD32(0, 0X2800);
    // 0x801D1C58: subu        $s0, $t7, $t6
    ctx->r16 = SUB32(ctx->r15, ctx->r14);
    // 0x801D1C5C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801D1C60: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801D1C64: andi        $s0, $s0, 0x1FFF
    ctx->r16 = ctx->r16 & 0X1FFF;
    // 0x801D1C68: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801D1C6C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801D1C70: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801D1C74: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801D1C78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801D1C7C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801D1C80: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801D1C84: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D1C88: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D1C8C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D1C90: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D1C94: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D1C98: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D1C9C: jal         0x8001EB64
    // 0x801D1CA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D1CA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x801D1CA4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801D1CA8: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x801D1CAC: jal         0x8001EAD0
    // 0x801D1CB0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D1CB0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801D1CB4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x801D1CB8: sb          $zero, 0x63($sp)
    MEM_B(0X63, ctx->r29) = 0;
    // 0x801D1CBC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801D1CC0: jal         0x801CDF5C
    // 0x801D1CC4: addiu       $a1, $sp, 0x63
    ctx->r5 = ADD32(ctx->r29, 0X63);
    LOOKUP_FUNC(0x801CDF5C)(rdram, ctx);
        goto after_2;
    // 0x801D1CC4: addiu       $a1, $sp, 0x63
    ctx->r5 = ADD32(ctx->r29, 0X63);
    after_2:
    // 0x801D1CC8: beq         $v0, $zero, L_801D1CE4
    if (ctx->r2 == 0) {
        // 0x801D1CCC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801D1CE4;
    }
    // 0x801D1CCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801D1CD0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1CD4: jal         0x800058DC
    // 0x801D1CD8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D1CD8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_3:
    // 0x801D1CDC: b           L_801D1E3C
    // 0x801D1CE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801D1E3C;
    // 0x801D1CE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801D1CE4:
    // 0x801D1CE4: jal         0x8012C6B4
    // 0x801D1CE8: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D1CE8: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_4:
    // 0x801D1CEC: lbu         $t8, 0x94($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X94);
    // 0x801D1CF0: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x801D1CF4: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x801D1CF8: blez        $t8, L_801D1E28
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801D1CFC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801D1E28;
    }
    // 0x801D1CFC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D1D00: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801D1D04: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801D1D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D1D0C: cvt.d.s     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f20.d = CVT_D_S(ctx->f4.fl);
    // 0x801D1D10: cvt.d.s     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f22.d = CVT_D_S(ctx->f6.fl);
    // 0x801D1D14: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
L_801D1D18:
    // 0x801D1D18: addu        $v0, $s5, $t9
    ctx->r2 = ADD32(ctx->r21, ctx->r25);
    // 0x801D1D1C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801D1D20: sll         $s2, $a1, 13
    ctx->r18 = S32(ctx->r5 << 13);
    // 0x801D1D24: lw          $t0, 0x24($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X24);
    // 0x801D1D28: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801D1D2C: sw          $t1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r9;
    // 0x801D1D30: lbu         $t3, 0x94($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X94);
    // 0x801D1D34: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D1D38: div         $zero, $s2, $t3
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r11)));
    // 0x801D1D3C: mflo        $t4
    ctx->r12 = lo;
    // 0x801D1D40: addu        $a0, $t4, $s3
    ctx->r4 = ADD32(ctx->r12, ctx->r19);
    // 0x801D1D44: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D1D48: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D1D4C: lw          $s0, 0x30($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X30);
    // 0x801D1D50: bne         $t3, $zero, L_801D1D5C
    if (ctx->r11 != 0) {
        // 0x801D1D54: nop
    
            goto L_801D1D5C;
    }
    // 0x801D1D54: nop

    // 0x801D1D58: break       7
    do_break(2149391704);
L_801D1D5C:
    // 0x801D1D5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D1D60: bne         $t3, $at, L_801D1D74
    if (ctx->r11 != ctx->r1) {
        // 0x801D1D64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D1D74;
    }
    // 0x801D1D64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D1D68: bne         $s2, $at, L_801D1D74
    if (ctx->r18 != ctx->r1) {
        // 0x801D1D6C: nop
    
            goto L_801D1D74;
    }
    // 0x801D1D6C: nop

    // 0x801D1D70: break       6
    do_break(2149391728);
L_801D1D74:
    // 0x801D1D74: jal         0x8001EB64
    // 0x801D1D78: nop

    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x801D1D78: nop

    after_5:
    // 0x801D1D7C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x801D1D80: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D1D84: mul.d       $f16, $f2, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f20.d);
    // 0x801D1D88: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D1D8C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D1D90: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D1D94: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801D1D98: mul.d       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f22.d);
    // 0x801D1D9C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D1DA0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D1DA4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801D1DA8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D1DAC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x801D1DB0: lbu         $t5, 0x94($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X94);
    // 0x801D1DB4: div         $zero, $s2, $t5
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r13)));
    // 0x801D1DB8: mflo        $t7
    ctx->r15 = lo;
    // 0x801D1DBC: addu        $a0, $t7, $s3
    ctx->r4 = ADD32(ctx->r15, ctx->r19);
    // 0x801D1DC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D1DC4: bne         $t5, $zero, L_801D1DD0
    if (ctx->r13 != 0) {
        // 0x801D1DC8: nop
    
            goto L_801D1DD0;
    }
    // 0x801D1DC8: nop

    // 0x801D1DCC: break       7
    do_break(2149391820);
L_801D1DD0:
    // 0x801D1DD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D1DD4: bne         $t5, $at, L_801D1DE8
    if (ctx->r13 != ctx->r1) {
        // 0x801D1DD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D1DE8;
    }
    // 0x801D1DD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D1DDC: bne         $s2, $at, L_801D1DE8
    if (ctx->r18 != ctx->r1) {
        // 0x801D1DE0: nop
    
            goto L_801D1DE8;
    }
    // 0x801D1DE0: nop

    // 0x801D1DE4: break       6
    do_break(2149391844);
L_801D1DE8:
    // 0x801D1DE8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D1DEC: jal         0x8001EAD0
    // 0x801D1DF0: nop

    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x801D1DF0: nop

    after_6:
    // 0x801D1DF4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D1DF8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D1DFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D1E00: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D1E04: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D1E08: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801D1E0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801D1E10: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801D1E14: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x801D1E18: lbu         $t6, 0x94($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X94);
    // 0x801D1E1C: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801D1E20: bnel        $at, $zero, L_801D1D18
    if (ctx->r1 != 0) {
        // 0x801D1E24: sll         $t9, $s1, 2
        ctx->r25 = S32(ctx->r17 << 2);
            goto L_801D1D18;
    }
    goto skip_0;
    // 0x801D1E24: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    skip_0:
L_801D1E28:
    // 0x801D1E28: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1E2C: addiu       $a1, $a1, -0x1858
    ctx->r5 = ADD32(ctx->r5, -0X1858);
    // 0x801D1E30: jal         0x800058DC
    // 0x801D1E34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801D1E34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x801D1E38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801D1E3C:
    // 0x801D1E3C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D1E40: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D1E44: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D1E48: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D1E4C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D1E50: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D1E54: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801D1E58: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801D1E5C: jr          $ra
    // 0x801D1E60: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801D1E60: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d1e64(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d1e64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1E64: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801D1E68: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801D1E6C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801D1E70: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801D1E74: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801D1E78: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801D1E7C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801D1E80: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801D1E84: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801D1E88: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801D1E8C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801D1E90: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D1E94: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D1E98: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D1E9C: sb          $zero, 0x7F($sp)
    MEM_B(0X7F, ctx->r29) = 0;
    // 0x801D1EA0: jal         0x801CE0E8
    // 0x801D1EA4: addiu       $a1, $sp, 0x7F
    ctx->r5 = ADD32(ctx->r29, 0X7F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D1EA4: addiu       $a1, $sp, 0x7F
    ctx->r5 = ADD32(ctx->r29, 0X7F);
    after_0:
    // 0x801D1EA8: bnel        $v0, $zero, L_801D2058
    if (ctx->r2 != 0) {
        // 0x801D1EAC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801D2058;
    }
    goto skip_0;
    // 0x801D1EAC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801D1EB0: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x801D1EB4: lwc1        $f20, 0x7C($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x801D1EB8: lwc1        $f22, 0x80($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X80);
    // 0x801D1EBC: lwc1        $f24, 0xA0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0XA0);
    // 0x801D1EC0: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801D1EC4: nop

    // 0x801D1EC8: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x801D1ECC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D1ED0: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x801D1ED4: jal         0x8002FC20
    // 0x801D1ED8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801D1ED8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x801D1EDC: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801D1EE0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D1EE4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801D1EE8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801D1EEC: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x801D1EF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1EF4: bc1fl       L_801D1F04
    if (!c1cs) {
        // 0x801D1EF8: lbu         $t6, 0x94($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X94);
            goto L_801D1F04;
    }
    goto skip_1;
    // 0x801D1EF8: lbu         $t6, 0x94($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X94);
    skip_1:
    // 0x801D1EFC: lwc1        $f2, 0x3610($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X3610);
    // 0x801D1F00: lbu         $t6, 0x94($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X94);
L_801D1F04:
    // 0x801D1F04: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x801D1F08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D1F0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1F10: div.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f2.fl);
    // 0x801D1F14: blez        $t6, L_801D2044
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D1F18: div.s       $f24, $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f2.fl);
            goto L_801D2044;
    }
    // 0x801D1F18: div.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f2.fl);
    // 0x801D1F1C: ldc1        $f28, 0x3618($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X3618);
    // 0x801D1F20: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D1F24: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801D1F28: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801D1F2C: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D1F30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1F34: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D1F38: ldc1        $f22, 0x3620($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X3620);
    // 0x801D1F3C: sdc1        $f6, 0x58($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X58, ctx->r29);
    // 0x801D1F40: sdc1        $f4, 0x60($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X60, ctx->r29);
    // 0x801D1F44: cvt.d.s     $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f30.d = CVT_D_S(ctx->f20.fl);
    // 0x801D1F48: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_801D1F4C:
    // 0x801D1F4C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x801D1F50: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D1F54: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801D1F58: jal         0x8012C6B4
    // 0x801D1F5C: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801D1F5C: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    after_2:
    // 0x801D1F60: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D1F64: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D1F68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D1F6C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D1F70: div.d       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f26.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f26.d);
    // 0x801D1F74: add.d       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f28.d); 
    ctx->f4.d = ctx->f18.d + ctx->f28.d;
    // 0x801D1F78: jal         0x8012C6B4
    // 0x801D1F7C: cvt.s.d     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f24.fl = CVT_S_D(ctx->f4.d);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D1F7C: cvt.s.d     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f24.fl = CVT_S_D(ctx->f4.d);
    after_3:
    // 0x801D1F80: addiu       $t0, $v0, -0x64
    ctx->r8 = ADD32(ctx->r2, -0X64);
    // 0x801D1F84: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801D1F88: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D1F8C: cvt.d.s     $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f20.d = CVT_D_S(ctx->f24.fl);
    // 0x801D1F90: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D1F94: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D1F98: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D1F9C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D1FA0: div.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f22.d);
    // 0x801D1FA4: add.d       $f6, $f30, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f30.d + ctx->f4.d;
    // 0x801D1FA8: mul.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x801D1FAC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D1FB0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D1FB4: jal         0x8012C6B4
    // 0x801D1FB8: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D1FB8: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x801D1FBC: addiu       $t1, $v0, -0x64
    ctx->r9 = ADD32(ctx->r2, -0X64);
    // 0x801D1FC0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801D1FC4: ldc1        $f4, 0x60($sp)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r29, 0X60);
    // 0x801D1FC8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D1FCC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D1FD0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D1FD4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D1FD8: div.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f22.d);
    // 0x801D1FDC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D1FE0: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x801D1FE4: mul.d       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f20.d);
    // 0x801D1FE8: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x801D1FEC: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x801D1FF0: jal         0x8012C6B4
    // 0x801D1FF4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D1FF4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x801D1FF8: addiu       $t2, $v0, -0x64
    ctx->r10 = ADD32(ctx->r2, -0X64);
    // 0x801D1FFC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x801D2000: ldc1        $f18, 0x58($sp)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r29, 0X58);
    // 0x801D2004: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D2008: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D200C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D2010: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D2014: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D2018: div.d       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f22.d);
    // 0x801D201C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D2020: add.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f18.d + ctx->f4.d;
    // 0x801D2024: mul.d       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f20.d);
    // 0x801D2028: add.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f6.d + ctx->f8.d;
    // 0x801D202C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D2030: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x801D2034: lbu         $t3, 0x94($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X94);
    // 0x801D2038: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801D203C: bnel        $at, $zero, L_801D1F4C
    if (ctx->r1 != 0) {
        // 0x801D2040: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_801D1F4C;
    }
    goto skip_2;
    // 0x801D2040: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    skip_2:
L_801D2044:
    // 0x801D2044: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2048: addiu       $a1, $a1, 0xC1C
    ctx->r5 = ADD32(ctx->r5, 0XC1C);
    // 0x801D204C: jal         0x800058DC
    // 0x801D2050: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D2050: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x801D2054: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801D2058:
    // 0x801D2058: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D205C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D2060: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D2064: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801D2068: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801D206C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801D2070: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801D2074: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801D2078: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801D207C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801D2080: jr          $ra
    // 0x801D2084: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801D2084: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d2088(rdram, ctx);
;}
