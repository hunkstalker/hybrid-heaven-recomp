#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M55_FUN_8037b4e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B4E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037B4E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037B4EC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8037B4F0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8037B4F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037B4F8: lw          $s1, 0x5C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X5C);
    // 0x8037B4FC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037B500: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037B504: lhu         $t6, 0x22($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X22);
    // 0x8037B508: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037B50C: addiu       $t8, $t8, -0x75BC
    ctx->r24 = ADD32(ctx->r24, -0X75BC);
    // 0x8037B510: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8037B514: beq         $t7, $zero, L_8037B554
    if (ctx->r15 == 0) {
        // 0x8037B518: addiu       $t2, $t2, -0x75C8
        ctx->r10 = ADD32(ctx->r10, -0X75C8);
            goto L_8037B554;
    }
    // 0x8037B518: addiu       $t2, $t2, -0x75C8
    ctx->r10 = ADD32(ctx->r10, -0X75C8);
    // 0x8037B51C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8037B520: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8037B524: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8037B528: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8037B52C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8037B530: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037B534: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8037B538: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037B53C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8037B540: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8037B544: jal         0x80011140
    // 0x8037B548: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x8037B548: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x8037B54C: b           L_8037B588
    // 0x8037B550: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
        goto L_8037B588;
    // 0x8037B550: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
L_8037B554:
    // 0x8037B554: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8037B558: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8037B55C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037B560: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8037B564: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x8037B568: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037B56C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8037B570: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037B574: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8037B578: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8037B57C: jal         0x80011140
    // 0x8037B580: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x8037B580: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_1:
    // 0x8037B584: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
L_8037B588:
    // 0x8037B588: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037B58C: ori         $at, $at, 0x17
    ctx->r1 = ctx->r1 | 0X17;
    // 0x8037B590: bne         $t6, $at, L_8037B5E8
    if (ctx->r14 != ctx->r1) {
        // 0x8037B594: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8037B5E8;
    }
    // 0x8037B594: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8037B598: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8037B59C: addiu       $t3, $zero, 0x5A
    ctx->r11 = ADD32(0, 0X5A);
    // 0x8037B5A0: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x8037B5A4: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8037B5A8: ori         $t0, $t8, 0x20
    ctx->r8 = ctx->r24 | 0X20;
    // 0x8037B5AC: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x8037B5B0: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x8037B5B4: ori         $t2, $t0, 0x80
    ctx->r10 = ctx->r8 | 0X80;
    // 0x8037B5B8: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x8037B5BC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8037B5C0: sh          $t3, 0x6BF8($at)
    MEM_H(0X6BF8, ctx->r1) = ctx->r11;
    // 0x8037B5C4: lhu         $t4, 0xEF0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XEF0);
    // 0x8037B5C8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8037B5CC: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x8037B5D0: ori         $t6, $t4, 0x2000
    ctx->r14 = ctx->r12 | 0X2000;
    // 0x8037B5D4: sh          $t6, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r14;
    // 0x8037B5D8: andi        $t7, $t6, 0xEFFF
    ctx->r15 = ctx->r14 & 0XEFFF;
    // 0x8037B5DC: sh          $t7, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r15;
    // 0x8037B5E0: jal         0x800058DC
    // 0x8037B5E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8037B5E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8037B5E8:
    // 0x8037B5E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037B5EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8037B5F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8037B5F4: jr          $ra
    // 0x8037B5F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037B5F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037b5fc(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037b5fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B5FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037B600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037B604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037B608: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8037B60C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8037B610: jal         0x80010550
    // 0x8037B614: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037B614: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8037B618: beq         $v0, $zero, L_8037B63C
    if (ctx->r2 == 0) {
        // 0x8037B61C: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8037B63C;
    }
    // 0x8037B61C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037B620: sb          $zero, -0x56C4($at)
    MEM_B(-0X56C4, ctx->r1) = 0;
    // 0x8037B624: jal         0x80020744
    // 0x8037B628: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x8037B628: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x8037B62C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037B630: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x8037B634: jal         0x800058DC
    // 0x8037B638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8037B638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8037B63C:
    // 0x8037B63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037B640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037B644: jr          $ra
    // 0x8037B648: nop

    return;
    // 0x8037B648: nop

;}
RECOMP_FUNC void M55_FUN_8037b64c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B64C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8037B650: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037B654: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x8037B658: sb          $zero, -0x56C4($at)
    MEM_B(-0X56C4, ctx->r1) = 0;
    // 0x8037B65C: lhu         $t6, 0x4($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037b660(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037b660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B660: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8037B664: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8037B668: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037B66C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8037B670: beq         $t6, $at, L_8037B728
    if (ctx->r14 == ctx->r1) {
        // 0x8037B674: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8037B728;
    }
    // 0x8037B674: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037B678: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8037B67C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8037B680: lw          $t8, 0xE8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XE8);
    // 0x8037B684: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037B688: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037B68C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8037B690: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8037B694: lw          $t9, 0xE0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XE0);
    // 0x8037B698: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8037B69C: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8037B6A0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037B6A4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8037B6A8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8037B6AC: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8037B6B0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8037B6B4: addiu       $a0, $a0, -0x69A4
    ctx->r4 = ADD32(ctx->r4, -0X69A4);
    // 0x8037B6B8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8037B6BC: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8037B6C0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8037B6C4: addiu       $a1, $zero, 0x36E
    ctx->r5 = ADD32(0, 0X36E);
    // 0x8037B6C8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8037B6CC: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8037B6D0: lwc1        $f10, 0x40($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X40);
    // 0x8037B6D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037B6D8: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037B6DC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037B6E0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8037B6E4: lwc1        $f4, 0x44($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X44);
    // 0x8037B6E8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037B6EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8037B6F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037B6F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037B6F8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8037B6FC: lwc1        $f10, 0x48($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X48);
    // 0x8037B700: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037B704: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8037B708: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8037B70C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037B710: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8037B714: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8037B718: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8037B71C: jal         0x8011AAF4
    // 0x8037B720: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x8037B720: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8037B724: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
L_8037B728:
    // 0x8037B728: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8037B72C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8037B730: jal         0x801DFE50
    // 0x8037B734: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DFE50)(rdram, ctx);
        goto after_1;
    // 0x8037B734: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_1:
    // 0x8037B738: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037B73C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8037B740: jal         0x800058DC
    // 0x8037B744: addiu       $a1, $a1, -0x48A8
    ctx->r5 = ADD32(ctx->r5, -0X48A8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8037B744: addiu       $a1, $a1, -0x48A8
    ctx->r5 = ADD32(ctx->r5, -0X48A8);
    after_2:
    // 0x8037B748: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8037B74C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8037B750: jr          $ra
    // 0x8037B754: nop

    return;
    // 0x8037B754: nop

;}
RECOMP_FUNC void M55_FUN_8037b758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B758: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8037B75C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8037B760: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8037B764: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8037B768: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037B76C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8037B770: jal         0x80010550
    // 0x8037B774: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037B774: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8037B778: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8037B77C: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x8037B780: lhu         $t6, 0x4($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X4);
    // 0x8037B784: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8037B788: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037B78C: beq         $t6, $at, L_8037B838
    if (ctx->r14 == ctx->r1) {
        // 0x8037B790: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8037B838;
    }
    // 0x8037B790: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8037B794: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8037B798: lw          $t8, 0xE8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XE8);
    // 0x8037B79C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037B7A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8037B7A4: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8037B7A8: lw          $t9, 0xE0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XE0);
    // 0x8037B7AC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8037B7B0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8037B7B4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037B7B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8037B7BC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8037B7C0: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8037B7C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8037B7C8: addiu       $a0, $a0, -0x6960
    ctx->r4 = ADD32(ctx->r4, -0X6960);
    // 0x8037B7CC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8037B7D0: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8037B7D4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8037B7D8: addiu       $a1, $zero, 0x381
    ctx->r5 = ADD32(0, 0X381);
    // 0x8037B7DC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8037B7E0: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8037B7E4: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8037B7E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8037B7EC: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037B7F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037B7F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037B7F8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8037B7FC: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8037B800: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037B804: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8037B808: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037B80C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037B810: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8037B814: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8037B818: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037B81C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8037B820: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8037B824: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037B828: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8037B82C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8037B830: jal         0x8011AAF4
    // 0x8037B834: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x8037B834: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
L_8037B838:
    // 0x8037B838: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037B83C: sb          $zero, -0x56C4($at)
    MEM_B(-0X56C4, ctx->r1) = 0;
    // 0x8037B840: jal         0x80020744
    // 0x8037B844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x8037B844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x8037B848: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037B84C: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x8037B850: jal         0x800058DC
    // 0x8037B854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8037B854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8037B858: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8037B85C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8037B860: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8037B864: jr          $ra
    // 0x8037B868: nop

    return;
    // 0x8037B868: nop

;}
RECOMP_FUNC void M55_FUN_8037b86c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B86C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8037B870: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037b874(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037b874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B874: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8037B878: lhu         $t6, 0x4($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X4);
    // 0x8037B87C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8037B880: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8037B884: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8037B888: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8037B88C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037B890: beq         $t6, $at, L_8037B94C
    if (ctx->r14 == ctx->r1) {
        // 0x8037B894: lw          $t0, 0x5C($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X5C);
            goto L_8037B94C;
    }
    // 0x8037B894: lw          $t0, 0x5C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X5C);
    // 0x8037B898: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8037B89C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8037B8A0: lw          $t8, 0xE8($t1)
    ctx->r24 = MEM_W(ctx->r9, 0XE8);
    // 0x8037B8A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037B8A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037B8AC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8037B8B0: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8037B8B4: lw          $t9, 0xE0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XE0);
    // 0x8037B8B8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8037B8BC: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8037B8C0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037B8C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8037B8C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8037B8CC: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8037B8D0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8037B8D4: addiu       $a0, $a0, -0x6918
    ctx->r4 = ADD32(ctx->r4, -0X6918);
    // 0x8037B8D8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8037B8DC: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8037B8E0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8037B8E4: addiu       $a1, $zero, 0x39C
    ctx->r5 = ADD32(0, 0X39C);
    // 0x8037B8E8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8037B8EC: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8037B8F0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8037B8F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8037B8F8: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037B8FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037B900: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037B904: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8037B908: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8037B90C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037B910: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8037B914: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037B918: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037B91C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8037B920: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8037B924: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037B928: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8037B92C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8037B930: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037B934: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8037B938: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8037B93C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8037B940: jal         0x8011AAF4
    // 0x8037B944: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x8037B944: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8037B948: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
L_8037B94C:
    // 0x8037B94C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037B950: addiu       $a0, $a0, -0x56C4
    ctx->r4 = ADD32(ctx->r4, -0X56C4);
    // 0x8037B954: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8037B958: slti        $v1, $v0, 0x15
    ctx->r3 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8037B95C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8037B960: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8037B964: beq         $v1, $zero, L_8037B9D0
    if (ctx->r3 == 0) {
        // 0x8037B968: sb          $t4, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r12;
            goto L_8037B9D0;
    }
    // 0x8037B968: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x8037B96C: addiu       $v0, $t0, 0x1C
    ctx->r2 = ADD32(ctx->r8, 0X1C);
    // 0x8037B970: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8037B974: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x8037B978: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x8037B97C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8037B980: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8037B984: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037B988: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8037B98C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037B990: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037B994: jal         0x8013A28C
    // 0x8037B998: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_1;
    // 0x8037B998: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8037B99C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8037B9A0: jal         0x800023EC
    // 0x8037B9A4: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_2;
    // 0x8037B9A4: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    after_2:
    // 0x8037B9A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8037B9AC: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    // 0x8037B9B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8037B9B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8037B9B8: jal         0x8012FE50
    // 0x8037B9BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_3;
    // 0x8037B9BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8037B9C0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037B9C4: addiu       $a1, $a1, -0x461C
    ctx->r5 = ADD32(ctx->r5, -0X461C);
    // 0x8037B9C8: jal         0x800058DC
    // 0x8037B9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8037B9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8037B9D0:
    // 0x8037B9D0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8037B9D4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8037B9D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8037B9DC: jr          $ra
    // 0x8037B9E0: nop

    return;
    // 0x8037B9E0: nop

;}
RECOMP_FUNC void M55_FUN_8037b9e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B9E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037B9E8: jr          $ra
    // 0x8037B9EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8037B9EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037b9f0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037b9f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B9F0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8037B9F4: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037b9f8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037b9f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B9F8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8037B9FC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037BA00: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8037BA04: beq         $t7, $zero, L_8037BAD8
    if (ctx->r15 == 0) {
        // 0x8037BA08: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8037BAD8;
    }
    // 0x8037BA08: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037BA0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8037BA10: jal         0x801E4F60
    // 0x8037BA14: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801E4F60)(rdram, ctx);
        goto after_0;
    // 0x8037BA14: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x8037BA18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8037BA1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8037BA20: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8037BA24: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x8037BA28: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8037BA2C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037BA30: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8037BA34: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8037BA38: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8037BA3C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8037BA40: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8037BA44: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037BA48: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8037BA4C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8037BA50: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8037BA54: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8037BA58: addiu       $a0, $a0, -0x68D0
    ctx->r4 = ADD32(ctx->r4, -0X68D0);
    // 0x8037BA5C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8037BA60: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8037BA64: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8037BA68: addiu       $a1, $zero, 0x3BC
    ctx->r5 = ADD32(0, 0X3BC);
    // 0x8037BA6C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8037BA70: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8037BA74: lwc1        $f10, 0x40($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X40);
    // 0x8037BA78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037BA7C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037BA80: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8037BA84: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8037BA88: lwc1        $f4, 0x44($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X44);
    // 0x8037BA8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8037BA90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037BA94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037BA98: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8037BA9C: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8037BAA0: lwc1        $f10, 0x48($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X48);
    // 0x8037BAA4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8037BAA8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8037BAAC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8037BAB0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8037BAB4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8037BAB8: jal         0x8011AAF4
    // 0x8037BABC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x8037BABC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8037BAC0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037BAC4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8037BAC8: jal         0x800058DC
    // 0x8037BACC: addiu       $a1, $a1, -0x49B4
    ctx->r5 = ADD32(ctx->r5, -0X49B4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8037BACC: addiu       $a1, $a1, -0x49B4
    ctx->r5 = ADD32(ctx->r5, -0X49B4);
    after_2:
    // 0x8037BAD0: b           L_8037BADC
    // 0x8037BAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037BADC;
    // 0x8037BAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037BAD8:
    // 0x8037BAD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037BADC:
    // 0x8037BADC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8037BAE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8037BAE4: jr          $ra
    // 0x8037BAE8: nop

    return;
    // 0x8037BAE8: nop

;}
RECOMP_FUNC void M55_FUN_8037baec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BAEC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8037BAF0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x8037BAF4: lhu         $v1, 0xEF0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XEF0);
    // 0x8037BAF8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037BAFC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8037BB00: andi        $t6, $v1, 0x1050
    ctx->r14 = ctx->r3 & 0X1050;
    // 0x8037BB04: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8037BB08: beq         $t6, $zero, L_8037BB18
    if (ctx->r14 == 0) {
            // 0x8037BB0C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8037BB18)(rdram, ctx);
    return;
    }
    // 0x8037BB0C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037BB10: jr          $ra
    // 0x8037BB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8037BB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037bb18(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037bb18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BB18: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037BB1C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8037BB20: addiu       $a1, $a1, -0x56D0
    ctx->r5 = ADD32(ctx->r5, -0X56D0);
    // 0x8037BB24: ori         $t7, $v1, 0x1000
    ctx->r15 = ctx->r3 | 0X1000;
    // 0x8037BB28: sh          $t7, 0xEF0($a0)
    MEM_H(0XEF0, ctx->r4) = ctx->r15;
    // 0x8037BB2C: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x8037BB30: swc1        $f14, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8037BB34: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BB38: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x8037BB3C: sh          $a3, -0x7598($at)
    MEM_H(-0X7598, ctx->r1) = ctx->r7;
    // 0x8037BB40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037BB44: jr          $ra
    // 0x8037BB48: nop

    return;
    // 0x8037BB48: nop

;}
RECOMP_FUNC void M55_FUN_8037bb4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BB4C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8037BB50: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8037BB54: lhu         $v0, 0xEF0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XEF0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037bb58(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037bb58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037BB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037BB60: andi        $t6, $v0, 0x1050
    ctx->r14 = ctx->r2 & 0X1050;
    // 0x8037BB64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037BB68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037BB6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8037BB70: beq         $t6, $zero, L_8037BB80
    if (ctx->r14 == 0) {
        // 0x8037BB74: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8037BB80;
    }
    // 0x8037BB74: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8037BB78: b           L_8037BBD4
    // 0x8037BB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037BBD4;
    // 0x8037BB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037BB80:
    // 0x8037BB80: ori         $t7, $v0, 0x1000
    ctx->r15 = ctx->r2 | 0X1000;
    // 0x8037BB84: sh          $t7, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r15;
    // 0x8037BB88: jal         0x8001EAD0
    // 0x8037BB8C: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8037BB8C: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_0:
    // 0x8037BB90: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8037BB94: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8037BB98: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037BB9C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8037BBA0: addiu       $v0, $v0, -0x56D0
    ctx->r2 = ADD32(ctx->r2, -0X56D0);
    // 0x8037BBA4: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x8037BBA8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8037BBAC: jal         0x8001EB64
    // 0x8037BBB0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8037BBB0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    after_1:
    // 0x8037BBB4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8037BBB8: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x8037BBBC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BBC0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8037BBC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037BBC8: swc1        $f16, -0x56C8($at)
    MEM_W(-0X56C8, ctx->r1) = ctx->f16.u32l;
    // 0x8037BBCC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BBD0: sh          $t8, -0x7598($at)
    MEM_H(-0X7598, ctx->r1) = ctx->r24;
L_8037BBD4:
    // 0x8037BBD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037BBD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037BBDC: jr          $ra
    // 0x8037BBE0: nop

    return;
    // 0x8037BBE0: nop

;}
RECOMP_FUNC void M55_FUN_8037bbe4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BBE4: nop

    // 0x8037BBE8: nop

    // 0x8037BBEC: nop

;}
RECOMP_FUNC void M55_FUN_8037bbf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BBF0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8037BBF4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8037BBF8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8037BBFC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8037BC00: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8037BC04: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8037BC08: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8037BC0C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8037BC10: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8037BC14: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8037BC18: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8037BC1C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8037BC20: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8037BC24: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8037BC28: beq         $a2, $zero, L_8037BD0C
    if (ctx->r6 == 0) {
        // 0x8037BC2C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8037BD0C;
    }
    // 0x8037BC2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037BC30: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037BC34: lbu         $t6, -0x7574($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7574);
    // 0x8037BC38: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x8037BC3C: subu        $t7, $t7, $zero
    ctx->r15 = SUB32(ctx->r15, 0);
    // 0x8037BC40: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x8037BC44: beq         $at, $zero, L_8037BD04
    if (ctx->r1 == 0) {
        // 0x8037BC48: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8037BD04;
    }
    // 0x8037BC48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8037BC4C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037BC50: addiu       $t8, $t8, -0x7574
    ctx->r24 = ADD32(ctx->r24, -0X7574);
    // 0x8037BC54: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8037BC58: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8037BC5C: lui         $s4, 0x8039
    ctx->r20 = S32(0X8039 << 16);
    // 0x8037BC60: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8037BC64: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8037BC68: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8037BC6C: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x8037BC70: addiu       $s4, $s4, -0x7574
    ctx->r20 = ADD32(ctx->r20, -0X7574);
    // 0x8037BC74: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8037BC78: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x8037BC7C: lhu         $t9, 0x4($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X4);
L_8037BC80:
    // 0x8037BC80: bnel        $t9, $v0, L_8037BCE4
    if (ctx->r25 != ctx->r2) {
        // 0x8037BC84: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8037BCE4;
    }
    goto skip_0;
    // 0x8037BC84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8037BC88: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8037BC8C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037BC90: sub.s       $f0, $f22, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x8037BC94: sub.s       $f2, $f24, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x8037BC98: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8037BC9C: nop

    // 0x8037BCA0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8037BCA4: jal         0x8002FC20
    // 0x8037BCA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8037BCA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8037BCAC: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8037BCB0: c.lt.d      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.d < ctx->f20.d;
    // 0x8037BCB4: nop

    // 0x8037BCB8: bc1fl       L_8037BCE4
    if (!c1cs) {
        // 0x8037BCBC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8037BCE4;
    }
    goto skip_1;
    // 0x8037BCBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8037BCC0: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037BCC4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BCC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037BCCC: swc1        $f18, -0x56C0($at)
    MEM_W(-0X56C0, ctx->r1) = ctx->f18.u32l;
    // 0x8037BCD0: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8037BCD4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BCD8: b           L_8037BDE4
    // 0x8037BCDC: swc1        $f4, -0x56B8($at)
    MEM_W(-0X56B8, ctx->r1) = ctx->f4.u32l;
        goto L_8037BDE4;
    // 0x8037BCDC: swc1        $f4, -0x56B8($at)
    MEM_W(-0X56B8, ctx->r1) = ctx->f4.u32l;
    // 0x8037BCE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037BCE4:
    // 0x8037BCE4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037BCE8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037BCEC: mflo        $t0
    ctx->r8 = lo;
    // 0x8037BCF0: addu        $s1, $s4, $t0
    ctx->r17 = ADD32(ctx->r20, ctx->r8);
    // 0x8037BCF4: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8037BCF8: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x8037BCFC: bnel        $at, $zero, L_8037BC80
    if (ctx->r1 != 0) {
        // 0x8037BD00: lhu         $t9, 0x4($s2)
        ctx->r25 = MEM_HU(ctx->r18, 0X4);
            goto L_8037BC80;
    }
    goto skip_2;
    // 0x8037BD00: lhu         $t9, 0x4($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X4);
    skip_2:
L_8037BD04:
    // 0x8037BD04: b           L_8037BDE4
    // 0x8037BD08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037BDE4;
    // 0x8037BD08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037BD0C:
    // 0x8037BD0C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037BD10: lbu         $t1, -0x74E4($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X74E4);
    // 0x8037BD14: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8037BD18: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x8037BD1C: slti        $at, $t1, 0xFF
    ctx->r1 = SIGNED(ctx->r9) < 0XFF ? 1 : 0;
    // 0x8037BD20: beq         $at, $zero, L_8037BDE0
    if (ctx->r1 == 0) {
        // 0x8037BD24: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8037BDE0;
    }
    // 0x8037BD24: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8037BD28: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037BD2C: addiu       $t3, $t3, -0x74E4
    ctx->r11 = ADD32(ctx->r11, -0X74E4);
    // 0x8037BD30: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8037BD34: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
    // 0x8037BD38: lui         $s4, 0x8039
    ctx->r20 = S32(0X8039 << 16);
    // 0x8037BD3C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8037BD40: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8037BD44: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8037BD48: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x8037BD4C: addiu       $s4, $s4, -0x74E4
    ctx->r20 = ADD32(ctx->r20, -0X74E4);
    // 0x8037BD50: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8037BD54: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x8037BD58: lhu         $t4, 0x4($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X4);
L_8037BD5C:
    // 0x8037BD5C: bnel        $t4, $v0, L_8037BDC0
    if (ctx->r12 != ctx->r2) {
        // 0x8037BD60: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8037BDC0;
    }
    goto skip_3;
    // 0x8037BD60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x8037BD64: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8037BD68: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037BD6C: sub.s       $f0, $f22, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x8037BD70: sub.s       $f2, $f24, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x8037BD74: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8037BD78: nop

    // 0x8037BD7C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8037BD80: jal         0x8002FC20
    // 0x8037BD84: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x8037BD84: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x8037BD88: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8037BD8C: c.lt.d      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.d < ctx->f20.d;
    // 0x8037BD90: nop

    // 0x8037BD94: bc1fl       L_8037BDC0
    if (!c1cs) {
        // 0x8037BD98: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8037BDC0;
    }
    goto skip_4;
    // 0x8037BD98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x8037BD9C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037BDA0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BDA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037BDA8: swc1        $f4, -0x56C0($at)
    MEM_W(-0X56C0, ctx->r1) = ctx->f4.u32l;
    // 0x8037BDAC: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8037BDB0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BDB4: b           L_8037BDE4
    // 0x8037BDB8: swc1        $f6, -0x56B8($at)
    MEM_W(-0X56B8, ctx->r1) = ctx->f6.u32l;
        goto L_8037BDE4;
    // 0x8037BDB8: swc1        $f6, -0x56B8($at)
    MEM_W(-0X56B8, ctx->r1) = ctx->f6.u32l;
    // 0x8037BDBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037BDC0:
    // 0x8037BDC0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037BDC4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037BDC8: mflo        $t5
    ctx->r13 = lo;
    // 0x8037BDCC: addu        $s1, $s4, $t5
    ctx->r17 = ADD32(ctx->r20, ctx->r13);
    // 0x8037BDD0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8037BDD4: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x8037BDD8: bnel        $at, $zero, L_8037BD5C
    if (ctx->r1 != 0) {
        // 0x8037BDDC: lhu         $t4, 0x4($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X4);
            goto L_8037BD5C;
    }
    goto skip_5;
    // 0x8037BDDC: lhu         $t4, 0x4($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X4);
    skip_5:
L_8037BDE0:
    // 0x8037BDE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037BDE4:
    // 0x8037BDE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8037BDE8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8037BDEC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8037BDF0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8037BDF4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8037BDF8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8037BDFC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8037BE00: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8037BE04: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8037BE08: jr          $ra
    // 0x8037BE0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8037BE0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037be10(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037be10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BE10: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8037BE14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037BE18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037BE1C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8037BE20: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8037BE24: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8037BE28: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8037BE2C: lh          $t7, 0x232($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X232);
    // 0x8037BE30: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x8037BE34: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x8037BE38: addiu       $t8, $zero, 0x2800
    ctx->r24 = ADD32(0, 0X2800);
    // 0x8037BE3C: subu        $t1, $t8, $t7
    ctx->r9 = SUB32(ctx->r24, ctx->r15);
    // 0x8037BE40: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x8037BE44: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
    // 0x8037BE48: sh          $t2, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r10;
    // 0x8037BE4C: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8037BE50: lh          $t5, 0x8($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X8);
    // 0x8037BE54: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8037BE58: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8037BE5C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8037BE60: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8037BE64: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8037BE68: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8037BE6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037BE70: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8037BE74: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8037BE78: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8037BE7C: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8037BE80: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8037BE84: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x8037BE88: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8037BE8C: jal         0x8001EF38
    // 0x8037BE90: swc1        $f14, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8037BE90: swc1        $f14, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8037BE94: lw          $a1, 0xE0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XE0);
    // 0x8037BE98: lh          $t6, 0x76($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X76);
    // 0x8037BE9C: lw          $t2, 0xEF8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XEF8);
    // 0x8037BEA0: lw          $t0, 0x2C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X2C);
    // 0x8037BEA4: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8037BEA8: lh          $t1, 0x12($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X12);
    // 0x8037BEAC: sb          $zero, 0x230($s0)
    MEM_B(0X230, ctx->r16) = 0;
    // 0x8037BEB0: subu        $v1, $t9, $t1
    ctx->r3 = SUB32(ctx->r25, ctx->r9);
    // 0x8037BEB4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8037BEB8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8037BEBC: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8037BEC0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8037BEC4: bne         $t2, $zero, L_8037BEFC
    if (ctx->r10 != 0) {
        // 0x8037BEC8: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8037BEFC;
    }
    // 0x8037BEC8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8037BECC: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8037BED0: sb          $zero, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = 0;
    // 0x8037BED4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8037BED8: sh          $zero, 0x18($t3)
    MEM_H(0X18, ctx->r11) = 0;
    // 0x8037BEDC: lhu         $t4, 0xEF0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XEF0);
    // 0x8037BEE0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037BEE4: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x8037BEE8: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x8037BEEC: jal         0x800058DC
    // 0x8037BEF0: sh          $t5, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8037BEF0: sh          $t5, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r13;
    after_1:
    // 0x8037BEF4: b           L_8037C8E8
    // 0x8037BEF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8037C8E8;
    // 0x8037BEF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037BEFC:
    // 0x8037BEFC: lbu         $t6, 0xEF5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037BF00: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8037BF04: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x8037BF08: mflo        $t8
    ctx->r24 = lo;
    // 0x8037BF0C: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8037BF10: beq         $at, $zero, L_8037C8E4
    if (ctx->r1 == 0) {
        // 0x8037BF14: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8037C8E4;
    }
    // 0x8037BF14: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8037BF18: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BF1C: addu        $at, $at, $t8
    gpr jr_addend_8037BF24 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8037BF20: lw          $t8, -0x676C($at)
    ctx->r24 = ADD32(ctx->r1, -0X676C);
    // 0x8037BF24: jr          $t8
    // 0x8037BF28: nop

    switch (jr_addend_8037BF24 >> 2) {
        case 0: goto L_8037BF2C; break;
        case 1: goto L_8037BF48; break;
        case 2: goto L_8037C8E4; break;
        case 3: goto L_8037C4FC; break;
        case 4: goto L_8037C564; break;
        default: switch_error(__func__, 0x8037BF24, 0x80389894);
    }
    // 0x8037BF28: nop

L_8037BF2C:
    // 0x8037BF2C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037BF30: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8037BF34: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8037BF38: jal         0x8037C8F8
    // 0x8037BF3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8037C8F8)(rdram, ctx);
        goto after_2;
    // 0x8037BF3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8037BF40: b           L_8037C8E8
    // 0x8037BF44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8037C8E8;
    // 0x8037BF44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037BF48:
    // 0x8037BF48: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
    // 0x8037BF4C: jal         0x8001EAD0
    // 0x8037BF50: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x8037BF50: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_3:
    // 0x8037BF54: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x8037BF58: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8037BF5C: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x8037BF60: jal         0x8001EB64
    // 0x8037BF64: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x8037BF64: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_4:
    // 0x8037BF68: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x8037BF6C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8037BF70: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8037BF74: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x8037BF78: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BF7C: ldc1        $f4, -0x6758($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6758);
    // 0x8037BF80: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037BF84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8037BF88: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037BF8C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8037BF90: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8037BF94: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8037BF98: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037BF9C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8037BFA0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8037BFA4: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8037BFA8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037BFAC: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8037BFB0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8037BFB4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8037BFB8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8037BFBC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8037BFC0: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8037BFC4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8037BFC8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8037BFCC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8037BFD0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8037BFD4: jal         0x801C5A1C
    // 0x8037BFD8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_5;
    // 0x8037BFD8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8037BFDC: beq         $v0, $zero, L_8037C470
    if (ctx->r2 == 0) {
        // 0x8037BFE0: lw          $t5, 0x90($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X90);
            goto L_8037C470;
    }
    // 0x8037BFE0: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x8037BFE4: lbu         $v0, 0xEF5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037BFE8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8037BFEC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8037BFF0: beql        $v1, $v0, L_8037C004
    if (ctx->r3 == ctx->r2) {
        // 0x8037BFF4: lwc1        $f0, 0xEEC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XEEC);
            goto L_8037C004;
    }
    goto skip_0;
    // 0x8037BFF4: lwc1        $f0, 0xEEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEEC);
    skip_0:
    // 0x8037BFF8: bnel        $v0, $at, L_8037C0C8
    if (ctx->r2 != ctx->r1) {
        // 0x8037BFFC: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8037C0C8;
    }
    goto skip_1;
    // 0x8037BFFC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_1:
    // 0x8037C000: lwc1        $f0, 0xEEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEEC);
L_8037C004:
    // 0x8037C004: lwc1        $f14, 0xEE4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEE4);
    // 0x8037C008: lwc1        $f6, 0xEE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEE8);
    // 0x8037C00C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x8037C010: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x8037C014: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x8037C018: jal         0x8001EF38
    // 0x8037C01C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_6;
    // 0x8037C01C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8037C020: addiu       $t4, $v0, 0x1800
    ctx->r12 = ADD32(ctx->r2, 0X1800);
    // 0x8037C024: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x8037C028: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C02C: sh          $t5, -0x56B4($at)
    MEM_H(-0X56B4, ctx->r1) = ctx->r13;
    // 0x8037C030: lw          $a1, 0xE0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C034: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C038: lw          $t6, 0x2C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C);
    // 0x8037C03C: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8037C040: swc1        $f8, -0x56BC($at)
    MEM_W(-0X56BC, ctx->r1) = ctx->f8.u32l;
    // 0x8037C044: lbu         $a2, 0xEF5($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037C048: lw          $v1, 0x2C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2C);
    // 0x8037C04C: addiu       $a2, $a2, -0xA
    ctx->r6 = ADD32(ctx->r6, -0XA);
    // 0x8037C050: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8037C054: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037C058: jal         0x8037BBF0
    // 0x8037C05C: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(0x8037BBF0)(rdram, ctx);
        goto after_7;
    // 0x8037C05C: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    after_7:
    // 0x8037C060: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C064: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037C068: lh          $t8, -0x56B4($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X56B4);
    // 0x8037C06C: lwc1        $f12, -0x56C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X56C0);
    // 0x8037C070: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C074: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037C078: lw          $a2, -0x56B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X56B8);
    // 0x8037C07C: lwc1        $f14, -0x56BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X56BC);
    // 0x8037C080: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8037C084: jal         0x801F11C0
    // 0x8037C088: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801F11C0)(rdram, ctx);
        goto after_8;
    // 0x8037C088: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_8:
    // 0x8037C08C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8037C090: sb          $t7, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r15;
    // 0x8037C094: jal         0x801E4F60
    // 0x8037C098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801E4F60)(rdram, ctx);
        goto after_9;
    // 0x8037C098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8037C09C: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x8037C0A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037C0A4: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8037C0A8: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x8037C0AC: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x8037C0B0: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8037C0B4: and         $t9, $t0, $at
    ctx->r25 = ctx->r8 & ctx->r1;
    // 0x8037C0B8: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    // 0x8037C0BC: b           L_8037C8E4
    // 0x8037C0C0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
        goto L_8037C8E4;
    // 0x8037C0C0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8037C0C4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8037C0C8:
    // 0x8037C0C8: bne         $v0, $at, L_8037C148
    if (ctx->r2 != ctx->r1) {
        // 0x8037C0CC: lui         $t1, 0x8021
        ctx->r9 = S32(0X8021 << 16);
            goto L_8037C148;
    }
    // 0x8037C0CC: lui         $t1, 0x8021
    ctx->r9 = S32(0X8021 << 16);
    // 0x8037C0D0: addiu       $t1, $t1, 0x6B90
    ctx->r9 = ADD32(ctx->r9, 0X6B90);
    // 0x8037C0D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8037C0D8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8037C0DC: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8037C0E0: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x8037C0E4: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x8037C0E8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037C0EC: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C0F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037C0F4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8037C0F8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037C0FC: jal         0x80011140
    // 0x8037C100: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_10;
    // 0x8037C100: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_10:
    // 0x8037C104: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C108: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8037C10C: lh          $t5, -0x56B4($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X56B4);
    // 0x8037C110: lwc1        $f12, -0x56C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X56C0);
    // 0x8037C114: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C118: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037C11C: lw          $a2, -0x56B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X56B8);
    // 0x8037C120: lwc1        $f14, -0x56BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X56BC);
    // 0x8037C124: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8037C128: jal         0x801F11C0
    // 0x8037C12C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x801F11C0)(rdram, ctx);
        goto after_11;
    // 0x8037C12C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_11:
    // 0x8037C130: beql        $v0, $zero, L_8037C8E8
    if (ctx->r2 == 0) {
        // 0x8037C134: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8037C8E8;
    }
    goto skip_2;
    // 0x8037C134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8037C138: lbu         $t6, 0xEF5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037C13C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8037C140: b           L_8037C8E4
    // 0x8037C144: sb          $t8, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r24;
        goto L_8037C8E4;
    // 0x8037C144: sb          $t8, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r24;
L_8037C148:
    // 0x8037C148: lbu         $v0, 0x35A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35A);
    // 0x8037C14C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8037C150: beq         $v0, $at, L_8037C170
    if (ctx->r2 == ctx->r1) {
        // 0x8037C154: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8037C170;
    }
    // 0x8037C154: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8037C158: beq         $v0, $at, L_8037C38C
    if (ctx->r2 == ctx->r1) {
        // 0x8037C15C: lw          $a0, 0x90($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X90);
            goto L_8037C38C;
    }
    // 0x8037C15C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037C160: beq         $v0, $v1, L_8037C3A8
    if (ctx->r2 == ctx->r3) {
        // 0x8037C164: lw          $a0, 0x90($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X90);
            goto L_8037C3A8;
    }
    // 0x8037C164: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037C168: b           L_8037C45C
    // 0x8037C16C: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
        goto L_8037C45C;
    // 0x8037C16C: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
L_8037C170:
    // 0x8037C170: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C174: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x8037C178: jal         0x8001EAD0
    // 0x8037C17C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x8037C17C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_12:
    // 0x8037C180: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C184: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8037C188: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x8037C18C: jal         0x8001EB64
    // 0x8037C190: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_13;
    // 0x8037C190: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_13:
    // 0x8037C194: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C198: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8037C19C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8037C1A0: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8037C1A4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C1A8: ldc1        $f6, -0x6750($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6750);
    // 0x8037C1AC: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037C1B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8037C1B4: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037C1B8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8037C1BC: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8037C1C0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8037C1C4: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037C1C8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8037C1CC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8037C1D0: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8037C1D4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037C1D8: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8037C1DC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8037C1E0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8037C1E4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8037C1E8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8037C1EC: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x8037C1F0: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8037C1F4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8037C1F8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8037C1FC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8037C200: jal         0x801C5A1C
    // 0x8037C204: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_14;
    // 0x8037C204: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x8037C208: lbu         $t3, 0x35A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X35A);
    // 0x8037C20C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8037C210: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8037C214: bne         $t3, $at, L_8037C380
    if (ctx->r11 != ctx->r1) {
        // 0x8037C218: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_8037C380;
    }
    // 0x8037C218: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8037C21C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8037C220: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037C224: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037C228: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8037C22C: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8037C230: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x8037C234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C238: bc1fl       L_8037C340
    if (!c1cs) {
        // 0x8037C23C: sw          $zero, 0x54($t4)
        MEM_W(0X54, ctx->r12) = 0;
            goto L_8037C340;
    }
    goto skip_3;
    // 0x8037C23C: sw          $zero, 0x54($t4)
    MEM_W(0X54, ctx->r12) = 0;
    skip_3:
    // 0x8037C240: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C244: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8037C248: jal         0x8001EAD0
    // 0x8037C24C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_15;
    // 0x8037C24C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_15:
    // 0x8037C250: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C254: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8037C258: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x8037C25C: jal         0x8001EB64
    // 0x8037C260: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_16;
    // 0x8037C260: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_16:
    // 0x8037C264: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C268: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8037C26C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8037C270: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x8037C274: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C278: ldc1        $f8, -0x6748($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6748);
    // 0x8037C27C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037C280: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8037C284: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037C288: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8037C28C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8037C290: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x8037C294: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037C298: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8037C29C: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x8037C2A0: mul.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8037C2A4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037C2A8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8037C2AC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8037C2B0: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8037C2B4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8037C2B8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8037C2BC: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8037C2C0: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8037C2C4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8037C2C8: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x8037C2CC: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8037C2D0: jal         0x801C5A1C
    // 0x8037C2D4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_17;
    // 0x8037C2D4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_17:
    // 0x8037C2D8: lbu         $t0, 0x35A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X35A);
    // 0x8037C2DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8037C2E0: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8037C2E4: bne         $t0, $at, L_8037C334
    if (ctx->r8 != ctx->r1) {
        // 0x8037C2E8: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8037C334;
    }
    // 0x8037C2E8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8037C2EC: sw          $zero, 0x54($t9)
    MEM_W(0X54, ctx->r25) = 0;
    // 0x8037C2F0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037C2F4: jal         0x801C4A5C
    // 0x8037C2F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_18;
    // 0x8037C2F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8037C2FC: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C300: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037C304: ori         $at, $at, 0x1F
    ctx->r1 = ctx->r1 | 0X1F;
    // 0x8037C308: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8037C30C: bne         $t2, $at, L_8037C324
    if (ctx->r10 != ctx->r1) {
        // 0x8037C310: nop
    
            goto L_8037C324;
    }
    // 0x8037C310: nop

    // 0x8037C314: jal         0x801BF1A0
    // 0x8037C318: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_19;
    // 0x8037C318: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_19:
    // 0x8037C31C: b           L_8037C480
    // 0x8037C320: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C480;
    // 0x8037C320: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C324:
    // 0x8037C324: jal         0x801BF1A0
    // 0x8037C328: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_20;
    // 0x8037C328: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_20:
    // 0x8037C32C: b           L_8037C480
    // 0x8037C330: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C480;
    // 0x8037C330: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C334:
    // 0x8037C334: b           L_8037C47C
    // 0x8037C338: sb          $t3, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r11;
        goto L_8037C47C;
    // 0x8037C338: sb          $t3, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r11;
    // 0x8037C33C: sw          $zero, 0x54($t4)
    MEM_W(0X54, ctx->r12) = 0;
L_8037C340:
    // 0x8037C340: jal         0x801C4A5C
    // 0x8037C344: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_21;
    // 0x8037C344: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_21:
    // 0x8037C348: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C34C: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037C350: ori         $at, $at, 0x1F
    ctx->r1 = ctx->r1 | 0X1F;
    // 0x8037C354: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x8037C358: bne         $t6, $at, L_8037C370
    if (ctx->r14 != ctx->r1) {
        // 0x8037C35C: nop
    
            goto L_8037C370;
    }
    // 0x8037C35C: nop

    // 0x8037C360: jal         0x801BF1A0
    // 0x8037C364: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_22;
    // 0x8037C364: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_22:
    // 0x8037C368: b           L_8037C480
    // 0x8037C36C: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C480;
    // 0x8037C36C: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C370:
    // 0x8037C370: jal         0x801BF1A0
    // 0x8037C374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_23;
    // 0x8037C374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_23:
    // 0x8037C378: b           L_8037C480
    // 0x8037C37C: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C480;
    // 0x8037C37C: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C380:
    // 0x8037C380: sb          $t8, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r24;
    // 0x8037C384: b           L_8037C480
    // 0x8037C388: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C480;
    // 0x8037C388: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C38C:
    // 0x8037C38C: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    // 0x8037C390: jal         0x801C4A5C
    // 0x8037C394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_24;
    // 0x8037C394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x8037C398: jal         0x801BF1A0
    // 0x8037C39C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_25;
    // 0x8037C39C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_25:
    // 0x8037C3A0: b           L_8037C480
    // 0x8037C3A4: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C480;
    // 0x8037C3A4: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C3A8:
    // 0x8037C3A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037C3AC: sw          $t7, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r15;
    // 0x8037C3B0: jal         0x801C4A5C
    // 0x8037C3B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_26;
    // 0x8037C3B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x8037C3B8: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C3BC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037C3C0: ori         $at, $at, 0x1F
    ctx->r1 = ctx->r1 | 0X1F;
    // 0x8037C3C4: lw          $t9, 0x1C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X1C);
    // 0x8037C3C8: bne         $t9, $at, L_8037C3E0
    if (ctx->r25 != ctx->r1) {
        // 0x8037C3CC: nop
    
            goto L_8037C3E0;
    }
    // 0x8037C3CC: nop

    // 0x8037C3D0: jal         0x801BF1A0
    // 0x8037C3D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_27;
    // 0x8037C3D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_27:
    // 0x8037C3D8: b           L_8037C3EC
    // 0x8037C3DC: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
        goto L_8037C3EC;
    // 0x8037C3DC: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
L_8037C3E0:
    // 0x8037C3E0: jal         0x801BF1A0
    // 0x8037C3E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_28;
    // 0x8037C3E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_28:
    // 0x8037C3E8: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
L_8037C3EC:
    // 0x8037C3EC: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8037C3F0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037C3F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037C3F8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8037C3FC: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8037C400: nop

    // 0x8037C404: bc1fl       L_8037C480
    if (!c1cs) {
        // 0x8037C408: lbu         $t8, 0x87($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X87);
            goto L_8037C480;
    }
    goto skip_4;
    // 0x8037C408: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
    skip_4:
    // 0x8037C40C: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C410: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8037C414: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8037C418: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x8037C41C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037C420: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037C424: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037C428: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037C42C: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x8037C430: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8037C434: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x8037C438: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037C43C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8037C440: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8037C444: jal         0x801C5A1C
    // 0x8037C448: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_29;
    // 0x8037C448: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_29:
    // 0x8037C44C: beq         $v0, $zero, L_8037C47C
    if (ctx->r2 == 0) {
        // 0x8037C450: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8037C47C;
    }
    // 0x8037C450: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8037C454: b           L_8037C47C
    // 0x8037C458: sb          $t2, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r10;
        goto L_8037C47C;
    // 0x8037C458: sb          $t2, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r10;
L_8037C45C:
    // 0x8037C45C: sw          $zero, 0x54($t3)
    MEM_W(0X54, ctx->r11) = 0;
    // 0x8037C460: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8037C464: sb          $t4, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r12;
    // 0x8037C468: b           L_8037C480
    // 0x8037C46C: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C480;
    // 0x8037C46C: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C470:
    // 0x8037C470: sw          $zero, 0x54($t5)
    MEM_W(0X54, ctx->r13) = 0;
    // 0x8037C474: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8037C478: sb          $t6, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r14;
L_8037C47C:
    // 0x8037C47C: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
L_8037C480:
    // 0x8037C480: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8037C484: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8037C488: beq         $t8, $at, L_8037C4E0
    if (ctx->r24 == ctx->r1) {
        // 0x8037C48C: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_8037C4E0;
    }
    // 0x8037C48C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8037C490: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8037C494: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037C498: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8037C49C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037C4A0: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8037C4A4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8037C4A8: bc1fl       L_8037C4BC
    if (!c1cs) {
        // 0x8037C4AC: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_8037C4BC;
    }
    goto skip_5;
    // 0x8037C4AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_5:
    // 0x8037C4B0: b           L_8037C4E0
    // 0x8037C4B4: sb          $t7, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r15;
        goto L_8037C4E0;
    // 0x8037C4B4: sb          $t7, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r15;
    // 0x8037C4B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_8037C4BC:
    // 0x8037C4BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037C4C0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8037C4C4: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8037C4C8: nop

    // 0x8037C4CC: bc1fl       L_8037C4E0
    if (!c1cs) {
        // 0x8037C4D0: sb          $zero, 0x87($sp)
        MEM_B(0X87, ctx->r29) = 0;
            goto L_8037C4E0;
    }
    goto skip_6;
    // 0x8037C4D0: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
    skip_6:
    // 0x8037C4D4: b           L_8037C4E0
    // 0x8037C4D8: sb          $t0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r8;
        goto L_8037C4E0;
    // 0x8037C4D8: sb          $t0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r8;
    // 0x8037C4DC: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
L_8037C4E0:
    // 0x8037C4E0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037C4E4: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8037C4E8: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C4EC: jal         0x801EBCC4
    // 0x8037C4F0: lbu         $a3, 0x87($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X87);
    LOOKUP_FUNC(0x801EBCC4)(rdram, ctx);
        goto after_30;
    // 0x8037C4F0: lbu         $a3, 0x87($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X87);
    after_30:
    // 0x8037C4F4: b           L_8037C8E8
    // 0x8037C4F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8037C8E8;
    // 0x8037C4F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037C4FC:
    // 0x8037C4FC: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C500: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037C504: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037C508: sh          $zero, 0x18($t9)
    MEM_H(0X18, ctx->r25) = 0;
    // 0x8037C50C: lhu         $t1, 0xEF0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XEF0);
    // 0x8037C510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C514: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x8037C518: sh          $t2, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r10;
    // 0x8037C51C: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x8037C520: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x8037C524: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x8037C528: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8037C52C: sw          $t4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r12;
    // 0x8037C530: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8037C534: lw          $t5, 0xEFC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEFC);
    // 0x8037C538: jal         0x801C4A5C
    // 0x8037C53C: sw          $t5, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r13;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_31;
    // 0x8037C53C: sw          $t5, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r13;
    after_31:
    // 0x8037C540: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C544: sh          $zero, -0x7590($at)
    MEM_H(-0X7590, ctx->r1) = 0;
    // 0x8037C548: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8037C54C: sb          $zero, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = 0;
    // 0x8037C550: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x8037C554: jal         0x800058DC
    // 0x8037C558: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_32;
    // 0x8037C558: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_32:
    // 0x8037C55C: b           L_8037C8E8
    // 0x8037C560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8037C8E8;
    // 0x8037C560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037C564:
    // 0x8037C564: lw          $t6, 0x2C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C);
    // 0x8037C568: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    // 0x8037C56C: jal         0x8001EAD0
    // 0x8037C570: sh          $v1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_33;
    // 0x8037C570: sh          $v1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r3;
    after_33:
    // 0x8037C574: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C578: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8037C57C: lw          $t7, 0x2C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X2C);
    // 0x8037C580: jal         0x8001EB64
    // 0x8037C584: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_34;
    // 0x8037C584: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_34:
    // 0x8037C588: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C58C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8037C590: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x8037C594: jal         0x8001EAD0
    // 0x8037C598: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_35;
    // 0x8037C598: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_35:
    // 0x8037C59C: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C5A0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8037C5A4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8037C5A8: jal         0x8001EB64
    // 0x8037C5AC: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_36;
    // 0x8037C5AC: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_36:
    // 0x8037C5B0: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C5B4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8037C5B8: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8037C5BC: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x8037C5C0: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8037C5C4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8037C5C8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037C5CC: add.d       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f18.d + ctx->f18.d;
    // 0x8037C5D0: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037C5D4: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x8037C5D8: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037C5DC: sub.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d - ctx->f4.d;
    // 0x8037C5E0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8037C5E4: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8037C5E8: sdc1        $f4, 0x28($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X28, ctx->r29);
    // 0x8037C5EC: add.d       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f4.d + ctx->f4.d;
    // 0x8037C5F0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8037C5F4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8037C5F8: sub.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d - ctx->f6.d;
    // 0x8037C5FC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8037C600: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8037C604: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037C608: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037C60C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8037C610: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8037C614: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8037C618: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8037C61C: add.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f8.d + ctx->f2.d;
    // 0x8037C620: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037C624: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037C628: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8037C62C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8037C630: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x8037C634: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037C638: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037C63C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8037C640: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8037C644: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8037C648: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8037C64C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8037C650: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x8037C654: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8037C658: jal         0x801C5A1C
    // 0x8037C65C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_37;
    // 0x8037C65C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_37:
    // 0x8037C660: beql        $v0, $zero, L_8037C8D4
    if (ctx->r2 == 0) {
        // 0x8037C664: lw          $a0, 0x90($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X90);
            goto L_8037C8D4;
    }
    goto skip_7;
    // 0x8037C664: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    skip_7:
    // 0x8037C668: lbu         $v0, 0x35A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35A);
    // 0x8037C66C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8037C670: beq         $v0, $at, L_8037C694
    if (ctx->r2 == ctx->r1) {
        // 0x8037C674: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8037C694;
    }
    // 0x8037C674: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8037C678: beq         $v0, $at, L_8037C6B4
    if (ctx->r2 == ctx->r1) {
        // 0x8037C67C: lw          $a0, 0x90($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X90);
            goto L_8037C6B4;
    }
    // 0x8037C67C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037C680: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8037C684: beq         $v0, $at, L_8037C6D0
    if (ctx->r2 == ctx->r1) {
        // 0x8037C688: lw          $t4, 0x90($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X90);
            goto L_8037C6D0;
    }
    // 0x8037C688: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8037C68C: b           L_8037C804
    // 0x8037C690: nop

        goto L_8037C804;
    // 0x8037C690: nop

L_8037C694:
    // 0x8037C694: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8037C698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C69C: jal         0x801C4A5C
    // 0x8037C6A0: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_38;
    // 0x8037C6A0: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    after_38:
    // 0x8037C6A4: jal         0x801BF1A0
    // 0x8037C6A8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_39;
    // 0x8037C6A8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_39:
    // 0x8037C6AC: b           L_8037C830
    // 0x8037C6B0: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C830;
    // 0x8037C6B0: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
L_8037C6B4:
    // 0x8037C6B4: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    // 0x8037C6B8: jal         0x801C4A5C
    // 0x8037C6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_40;
    // 0x8037C6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x8037C6C0: jal         0x801BF1A0
    // 0x8037C6C4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_41;
    // 0x8037C6C4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_41:
    // 0x8037C6C8: b           L_8037C830
    // 0x8037C6CC: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
        goto L_8037C830;
    // 0x8037C6CC: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
L_8037C6D0:
    // 0x8037C6D0: sw          $zero, 0x54($t4)
    MEM_W(0X54, ctx->r12) = 0;
    // 0x8037C6D4: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C6D8: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037C6DC: ori         $at, $at, 0x30
    ctx->r1 = ctx->r1 | 0X30;
    // 0x8037C6E0: lw          $v0, 0x1C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X1C);
    // 0x8037C6E4: bnel        $v0, $at, L_8037C7F0
    if (ctx->r2 != ctx->r1) {
        // 0x8037C6E8: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_8037C7F0;
    }
    goto skip_8;
    // 0x8037C6E8: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    skip_8:
    // 0x8037C6EC: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C6F0: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x8037C6F4: jal         0x8001EAD0
    // 0x8037C6F8: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_42;
    // 0x8037C6F8: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_42:
    // 0x8037C6FC: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C700: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8037C704: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x8037C708: jal         0x8001EB64
    // 0x8037C70C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_43;
    // 0x8037C70C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_43:
    // 0x8037C710: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C714: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8037C718: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x8037C71C: jal         0x8001EAD0
    // 0x8037C720: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_44;
    // 0x8037C720: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_44:
    // 0x8037C724: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C728: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8037C72C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8037C730: jal         0x8001EB64
    // 0x8037C734: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_45;
    // 0x8037C734: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_45:
    // 0x8037C738: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C73C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8037C740: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8037C744: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x8037C748: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8037C74C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8037C750: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037C754: add.d       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f18.d + ctx->f18.d;
    // 0x8037C758: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037C75C: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x8037C760: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037C764: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x8037C768: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8037C76C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8037C770: sdc1        $f6, 0x28($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X28, ctx->r29);
    // 0x8037C774: add.d       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f6.d + ctx->f6.d;
    // 0x8037C778: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8037C77C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8037C780: sub.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f16.d - ctx->f10.d;
    // 0x8037C784: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8037C788: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8037C78C: add.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f10.d + ctx->f2.d;
    // 0x8037C790: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037C794: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037C798: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x8037C79C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8037C7A0: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8037C7A4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x8037C7A8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8037C7AC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8037C7B0: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8037C7B4: add.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f6.d + ctx->f16.d;
    // 0x8037C7B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8037C7BC: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8037C7C0: jal         0x801C5A1C
    // 0x8037C7C4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_46;
    // 0x8037C7C4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_46:
    // 0x8037C7C8: beql        $v0, $zero, L_8037C830
    if (ctx->r2 == 0) {
        // 0x8037C7CC: lbu         $t7, 0x87($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X87);
            goto L_8037C830;
    }
    goto skip_9;
    // 0x8037C7CC: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
    skip_9:
    // 0x8037C7D0: lbu         $t5, 0x35A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X35A);
    // 0x8037C7D4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8037C7D8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8037C7DC: bnel        $t5, $at, L_8037C830
    if (ctx->r13 != ctx->r1) {
        // 0x8037C7E0: lbu         $t7, 0x87($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X87);
            goto L_8037C830;
    }
    goto skip_10;
    // 0x8037C7E0: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
    skip_10:
    // 0x8037C7E4: b           L_8037C82C
    // 0x8037C7E8: sb          $t6, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r14;
        goto L_8037C82C;
    // 0x8037C7E8: sb          $t6, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r14;
    // 0x8037C7EC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
L_8037C7F0:
    // 0x8037C7F0: ori         $at, $at, 0x19
    ctx->r1 = ctx->r1 | 0X19;
    // 0x8037C7F4: bne         $v0, $at, L_8037C82C
    if (ctx->r2 != ctx->r1) {
        // 0x8037C7F8: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_8037C82C;
    }
    // 0x8037C7F8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8037C7FC: b           L_8037C82C
    // 0x8037C800: sb          $t8, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r24;
        goto L_8037C82C;
    // 0x8037C800: sb          $t8, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r24;
L_8037C804:
    // 0x8037C804: jal         0x801C89D8
    // 0x8037C808: nop

    LOOKUP_FUNC(0x801C89D8)(rdram, ctx);
        goto after_47;
    // 0x8037C808: nop

    after_47:
    // 0x8037C80C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C810: sh          $zero, -0x7590($at)
    MEM_H(-0X7590, ctx->r1) = 0;
    // 0x8037C814: sb          $zero, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = 0;
    // 0x8037C818: sw          $zero, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = 0;
    // 0x8037C81C: jal         0x801BF1A0
    // 0x8037C820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_48;
    // 0x8037C820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_48:
    // 0x8037C824: b           L_8037C8E8
    // 0x8037C828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8037C8E8;
    // 0x8037C828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037C82C:
    // 0x8037C82C: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
L_8037C830:
    // 0x8037C830: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8037C834: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8037C838: beql        $t7, $at, L_8037C8D4
    if (ctx->r15 == ctx->r1) {
        // 0x8037C83C: lw          $a0, 0x90($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X90);
            goto L_8037C8D4;
    }
    goto skip_11;
    // 0x8037C83C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    skip_11:
    // 0x8037C840: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8037C844: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8037C848: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8037C84C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8037C850: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8037C854: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037C858: lh          $v0, 0x72($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X72);
    // 0x8037C85C: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x8037C860: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8037C864: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8037C868: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8037C86C: nop

    // 0x8037C870: bc1fl       L_8037C8D4
    if (!c1cs) {
        // 0x8037C874: lw          $a0, 0x90($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X90);
            goto L_8037C8D4;
    }
    goto skip_12;
    // 0x8037C874: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    skip_12:
    // 0x8037C878: bne         $at, $zero, L_8037C890
    if (ctx->r1 != 0) {
        // 0x8037C87C: slti        $at, $v0, 0xC00
        ctx->r1 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
            goto L_8037C890;
    }
    // 0x8037C87C: slti        $at, $v0, 0xC00
    ctx->r1 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
    // 0x8037C880: beql        $at, $zero, L_8037C894
    if (ctx->r1 == 0) {
        // 0x8037C884: slti        $at, $v0, 0xC00
        ctx->r1 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
            goto L_8037C894;
    }
    goto skip_13;
    // 0x8037C884: slti        $at, $v0, 0xC00
    ctx->r1 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
    skip_13:
    // 0x8037C888: b           L_8037C8D0
    // 0x8037C88C: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
        goto L_8037C8D0;
    // 0x8037C88C: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
L_8037C890:
    // 0x8037C890: slti        $at, $v0, 0xC00
    ctx->r1 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
L_8037C894:
    // 0x8037C894: bne         $at, $zero, L_8037C8AC
    if (ctx->r1 != 0) {
        // 0x8037C898: slti        $at, $v0, 0x1400
        ctx->r1 = SIGNED(ctx->r2) < 0X1400 ? 1 : 0;
            goto L_8037C8AC;
    }
    // 0x8037C898: slti        $at, $v0, 0x1400
    ctx->r1 = SIGNED(ctx->r2) < 0X1400 ? 1 : 0;
    // 0x8037C89C: beq         $at, $zero, L_8037C8AC
    if (ctx->r1 == 0) {
        // 0x8037C8A0: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8037C8AC;
    }
    // 0x8037C8A0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8037C8A4: b           L_8037C8D0
    // 0x8037C8A8: sb          $t0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r8;
        goto L_8037C8D0;
    // 0x8037C8A8: sb          $t0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r8;
L_8037C8AC:
    // 0x8037C8AC: slti        $at, $v0, 0x1400
    ctx->r1 = SIGNED(ctx->r2) < 0X1400 ? 1 : 0;
    // 0x8037C8B0: bne         $at, $zero, L_8037C8CC
    if (ctx->r1 != 0) {
        // 0x8037C8B4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8037C8CC;
    }
    // 0x8037C8B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8037C8B8: slti        $at, $v0, 0x1C00
    ctx->r1 = SIGNED(ctx->r2) < 0X1C00 ? 1 : 0;
    // 0x8037C8BC: beql        $at, $zero, L_8037C8D0
    if (ctx->r1 == 0) {
        // 0x8037C8C0: sb          $t9, 0x87($sp)
        MEM_B(0X87, ctx->r29) = ctx->r25;
            goto L_8037C8D0;
    }
    goto skip_14;
    // 0x8037C8C0: sb          $t9, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r25;
    skip_14:
    // 0x8037C8C4: b           L_8037C8D0
    // 0x8037C8C8: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
        goto L_8037C8D0;
    // 0x8037C8C8: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
L_8037C8CC:
    // 0x8037C8CC: sb          $t9, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r25;
L_8037C8D0:
    // 0x8037C8D0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
L_8037C8D4:
    // 0x8037C8D4: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8037C8D8: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8037C8DC: jal         0x801ED2D4
    // 0x8037C8E0: lbu         $a3, 0x87($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X87);
    LOOKUP_FUNC(0x801ED2D4)(rdram, ctx);
        goto after_49;
    // 0x8037C8E0: lbu         $a3, 0x87($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X87);
    after_49:
L_8037C8E4:
    // 0x8037C8E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037C8E8:
    // 0x8037C8E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037C8EC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x8037C8F0: jr          $ra
    // 0x8037C8F4: nop

    return;
    // 0x8037C8F4: nop

;}
RECOMP_FUNC void M55_FUN_8037c8f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C8F8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8037C8FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8037C900: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8037C904: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8037C908: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C90C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037C910: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8037C914: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8037C918: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8037C91C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8037C920: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8037C924: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8037C928: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8037C92C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037C930: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8037C934: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8037C938: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8037C93C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8037C940: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037C944: jal         0x80010550
    // 0x8037C948: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037C948: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8037C94C: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C950: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8037C954: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8037C958: swc1        $f10, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f10.u32l;
    // 0x8037C95C: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C960: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8037C964: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8037C968: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x8037C96C: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C970: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8037C974: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8037C978: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x8037C97C: lbu         $v1, 0xEF5($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037C980: sltiu       $at, $v1, 0x9
    ctx->r1 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x8037C984: beq         $at, $zero, L_8037CFB4
    if (ctx->r1 == 0) {
        // 0x8037C988: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_8037CFB4;
    }
    // 0x8037C988: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8037C98C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C990: addu        $at, $at, $t3
    gpr jr_addend_8037C998 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8037C994: lw          $t3, -0x6740($at)
    ctx->r11 = ADD32(ctx->r1, -0X6740);
    // 0x8037C998: jr          $t3
    // 0x8037C99C: nop

    switch (jr_addend_8037C998 >> 2) {
        case 0: goto L_8037C9A0; break;
        case 1: goto L_8037CBC8; break;
        case 2: goto L_8037CC00; break;
        case 3: goto L_8037CC70; break;
        case 4: goto L_8037CCC8; break;
        case 5: goto L_8037CD18; break;
        case 6: goto L_8037CDC8; break;
        case 7: goto L_8037CEF0; break;
        case 8: goto L_8037CF1C; break;
        default: switch_error(__func__, 0x8037C998, 0x803898C0);
    }
    // 0x8037C99C: nop

L_8037C9A0:
    // 0x8037C9A0: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8037C9A4: lui         $t4, 0x168
    ctx->r12 = S32(0X168 << 16);
    // 0x8037C9A8: ori         $a1, $t4, 0x3E
    ctx->r5 = ctx->r12 | 0X3E;
    // 0x8037C9AC: addiu       $t5, $zero, 0x1100
    ctx->r13 = ADD32(0, 0X1100);
    // 0x8037C9B0: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x8037C9B4: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x8037C9B8: sh          $t5, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r13;
    // 0x8037C9BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037C9C0: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x8037C9C4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8037C9C8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037C9CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037C9D0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037C9D4: jal         0x8013A28C
    // 0x8037C9D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_1;
    // 0x8037C9D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8037C9DC: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x8037C9E0: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8037C9E4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8037C9E8: sw          $t9, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r25;
    // 0x8037C9EC: ori         $t1, $t9, 0x40
    ctx->r9 = ctx->r25 | 0X40;
    // 0x8037C9F0: sw          $t1, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r9;
    // 0x8037C9F4: lw          $v0, 0xEF8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEF8);
    // 0x8037C9F8: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x8037C9FC: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x8037CA00: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8037CA04: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8037CA08: swc1        $f6, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->f6.u32l;
    // 0x8037CA0C: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x8037CA10: lwc1        $f10, 0x198($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X198);
    // 0x8037CA14: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8037CA18: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8037CA1C: swc1        $f8, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->f8.u32l;
    // 0x8037CA20: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8037CA24: lwc1        $f4, 0x1A0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x8037CA28: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037CA2C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037CA30: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8037CA34: jal         0x8001EF38
    // 0x8037CA38: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8037CA38: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x8037CA3C: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CA40: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8037CA44: sh          $v0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r2;
    // 0x8037CA48: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CA4C: lwc1        $f8, 0x198($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X198);
    // 0x8037CA50: lwc1        $f18, 0x1A0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x8037CA54: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8037CA58: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037CA5C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037CA60: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8037CA64: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8037CA68: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8037CA6C: nop

    // 0x8037CA70: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8037CA74: jal         0x8002FC20
    // 0x8037CA78: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x8037CA78: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_3:
    // 0x8037CA7C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037CA80: swc1        $f0, -0x758C($at)
    MEM_W(-0X758C, ctx->r1) = ctx->f0.u32l;
    // 0x8037CA84: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CA88: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8037CA8C: jal         0x8001EAD0
    // 0x8037CA90: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8037CA90: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_4:
    // 0x8037CA94: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037CA98: lwc1        $f10, -0x758C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X758C);
    // 0x8037CA9C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8037CAA0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8037CAA4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8037CAA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037CAAC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8037CAB0: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8037CAB4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8037CAB8: swc1        $f10, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f10.u32l;
    // 0x8037CABC: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CAC0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8037CAC4: jal         0x8001EB64
    // 0x8037CAC8: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x8037CAC8: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_5:
    // 0x8037CACC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037CAD0: lwc1        $f18, -0x758C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X758C);
    // 0x8037CAD4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8037CAD8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037CADC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8037CAE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037CAE4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8037CAE8: sw          $t4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r12;
    // 0x8037CAEC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8037CAF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037CAF4: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8037CAF8: swc1        $f4, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f4.u32l;
    // 0x8037CAFC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8037CB00: swc1        $f18, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f18.u32l;
    // 0x8037CB04: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8037CB08: jal         0x80010550
    // 0x8037CB0C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_6;
    // 0x8037CB0C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_6:
    // 0x8037CB10: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CB14: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8037CB18: jal         0x8001EAD0
    // 0x8037CB1C: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x8037CB1C: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_7:
    // 0x8037CB20: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8037CB24: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037CB28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037CB2C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8037CB30: lwc1        $f18, 0x198($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X198);
    // 0x8037CB34: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8037CB38: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CB3C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8037CB40: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x8037CB44: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8037CB48: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8037CB4C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8037CB50: jal         0x8001EB64
    // 0x8037CB54: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x8037CB54: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_8:
    // 0x8037CB58: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8037CB5C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8037CB60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037CB64: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8037CB68: lwc1        $f6, 0x1A0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x8037CB6C: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8037CB70: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CB74: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8037CB78: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8037CB7C: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8037CB80: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8037CB84: sub.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d - ctx->f10.d;
    // 0x8037CB88: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8037CB8C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8037CB90: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8037CB94: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8037CB98: sub.s       $f14, $f16, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8037CB9C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8037CBA0: jal         0x8002FC20
    // 0x8037CBA4: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_9;
    // 0x8037CBA4: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_9:
    // 0x8037CBA8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037CBAC: swc1        $f0, -0x758C($at)
    MEM_W(-0X758C, ctx->r1) = ctx->f0.u32l;
    // 0x8037CBB0: lbu         $t0, 0xEF5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037CBB4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037CBB8: addiu       $a0, $a0, -0x7590
    ctx->r4 = ADD32(ctx->r4, -0X7590);
    // 0x8037CBBC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8037CBC0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8037CBC4: sb          $t1, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r9;
L_8037CBC8:
    // 0x8037CBC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037CBCC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037CBD0: addiu       $a0, $a0, -0x7590
    ctx->r4 = ADD32(ctx->r4, -0X7590);
    // 0x8037CBD4: swc1        $f4, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f4.u32l;
    // 0x8037CBD8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8037CBDC: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8037CBE0: bne         $at, $zero, L_8037CBF8
    if (ctx->r1 != 0) {
        // 0x8037CBE4: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8037CBF8;
    }
    // 0x8037CBE4: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8037CBE8: lbu         $t2, 0xEF5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037CBEC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8037CBF0: b           L_8037CFB4
    // 0x8037CBF4: sb          $t3, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r11;
        goto L_8037CFB4;
    // 0x8037CBF4: sb          $t3, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r11;
L_8037CBF8:
    // 0x8037CBF8: b           L_8037CFB4
    // 0x8037CBFC: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
        goto L_8037CFB4;
    // 0x8037CBFC: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
L_8037CC00:
    // 0x8037CC00: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8037CC04: addiu       $t5, $t5, -0x7454
    ctx->r13 = ADD32(ctx->r13, -0X7454);
    // 0x8037CC08: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8037CC0C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8037CC10: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8037CC14: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x8037CC18: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037CC1C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037CC20: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x8037CC24: jal         0x8013A28C
    // 0x8037CC28: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_10;
    // 0x8037CC28: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_10:
    // 0x8037CC2C: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x8037CC30: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8037CC34: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8037CC38: sw          $t9, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r25;
    // 0x8037CC3C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8037CC40: jal         0x80010550
    // 0x8037CC44: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_11;
    // 0x8037CC44: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x8037CC48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037CC4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037CC50: swc1        $f6, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f6.u32l;
    // 0x8037CC54: swc1        $f8, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f8.u32l;
    // 0x8037CC58: lbu         $t1, 0xEF5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037CC5C: lw          $t0, 0xEF8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XEF8);
    // 0x8037CC60: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8037CC64: sb          $t2, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r10;
    // 0x8037CC68: b           L_8037CFB4
    // 0x8037CC6C: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
        goto L_8037CFB4;
    // 0x8037CC6C: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
L_8037CC70:
    // 0x8037CC70: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8037CC74: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8037CC78: bne         $t3, $zero, L_8037CC88
    if (ctx->r11 != 0) {
        // 0x8037CC7C: nop
    
            goto L_8037CC88;
    }
    // 0x8037CC7C: nop

    // 0x8037CC80: b           L_8037CFB4
    // 0x8037CC84: sb          $t4, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r12;
        goto L_8037CFB4;
    // 0x8037CC84: sb          $t4, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r12;
L_8037CC88:
    // 0x8037CC88: beq         $v0, $zero, L_8037CFB4
    if (ctx->r2 == 0) {
        // 0x8037CC8C: lui         $t5, 0x8039
        ctx->r13 = S32(0X8039 << 16);
            goto L_8037CFB4;
    }
    // 0x8037CC8C: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8037CC90: addiu       $t5, $t5, -0x7454
    ctx->r13 = ADD32(ctx->r13, -0X7454);
    // 0x8037CC94: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8037CC98: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8037CC9C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8037CCA0: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x8037CCA4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037CCA8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037CCAC: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x8037CCB0: jal         0x8013A28C
    // 0x8037CCB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_12;
    // 0x8037CCB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_12:
    // 0x8037CCB8: lbu         $t8, 0xEF5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037CCBC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8037CCC0: b           L_8037CFB4
    // 0x8037CCC4: sb          $t9, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r25;
        goto L_8037CFB4;
    // 0x8037CCC4: sb          $t9, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r25;
L_8037CCC8:
    // 0x8037CCC8: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8037CCCC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8037CCD0: bne         $t0, $zero, L_8037CCE0
    if (ctx->r8 != 0) {
        // 0x8037CCD4: nop
    
            goto L_8037CCE0;
    }
    // 0x8037CCD4: nop

    // 0x8037CCD8: b           L_8037CFB4
    // 0x8037CCDC: sb          $t1, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r9;
        goto L_8037CFB4;
    // 0x8037CCDC: sb          $t1, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r9;
L_8037CCE0:
    // 0x8037CCE0: beq         $v0, $zero, L_8037CFB4
    if (ctx->r2 == 0) {
        // 0x8037CCE4: lui         $t2, 0x8039
        ctx->r10 = S32(0X8039 << 16);
            goto L_8037CFB4;
    }
    // 0x8037CCE4: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037CCE8: addiu       $t2, $t2, -0x7448
    ctx->r10 = ADD32(ctx->r10, -0X7448);
    // 0x8037CCEC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8037CCF0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8037CCF4: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8037CCF8: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x8037CCFC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037CD00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037CD04: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x8037CD08: jal         0x8013A28C
    // 0x8037CD0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_13;
    // 0x8037CD0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_13:
    // 0x8037CD10: b           L_8037CFB8
    // 0x8037CD14: lhu         $t9, 0xEF0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XEF0);
        goto L_8037CFB8;
    // 0x8037CD14: lhu         $t9, 0xEF0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XEF0);
L_8037CD18:
    // 0x8037CD18: lw          $t5, 0xEF8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEF8);
    // 0x8037CD1C: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CD20: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x8037CD24: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x8037CD28: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8037CD2C: lh          $a1, 0x12($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X12);
    // 0x8037CD30: lh          $a2, 0x12($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X12);
    // 0x8037CD34: subu        $v0, $a2, $a1
    ctx->r2 = SUB32(ctx->r6, ctx->r5);
    // 0x8037CD38: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8037CD3C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8037CD40: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x8037CD44: beq         $t9, $zero, L_8037CD60
    if (ctx->r25 == 0) {
        // 0x8037CD48: andi        $a0, $v0, 0x1FFF
        ctx->r4 = ctx->r2 & 0X1FFF;
            goto L_8037CD60;
    }
    // 0x8037CD48: andi        $a0, $v0, 0x1FFF
    ctx->r4 = ctx->r2 & 0X1FFF;
    // 0x8037CD4C: andi        $a0, $v0, 0x1FFF
    ctx->r4 = ctx->r2 & 0X1FFF;
    // 0x8037CD50: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x8037CD54: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037CD58: b           L_8037CD68
    // 0x8037CD5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8037CD68;
    // 0x8037CD5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8037CD60:
    // 0x8037CD60: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037CD64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8037CD68:
    // 0x8037CD68: bgez        $a0, L_8037CD78
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8037CD6C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8037CD78;
    }
    // 0x8037CD6C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037CD70: b           L_8037CD78
    // 0x8037CD74: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_8037CD78;
    // 0x8037CD74: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_8037CD78:
    // 0x8037CD78: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8037CD7C: bnel        $at, $zero, L_8037CDB8
    if (ctx->r1 != 0) {
        // 0x8037CD80: sh          $a2, 0x12($v1)
        MEM_H(0X12, ctx->r3) = ctx->r6;
            goto L_8037CDB8;
    }
    goto skip_0;
    // 0x8037CD80: sh          $a2, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r6;
    skip_0:
    // 0x8037CD84: blez        $a0, L_8037CD98
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8037CD88: addiu       $t1, $a1, -0x40
        ctx->r9 = ADD32(ctx->r5, -0X40);
            goto L_8037CD98;
    }
    // 0x8037CD88: addiu       $t1, $a1, -0x40
    ctx->r9 = ADD32(ctx->r5, -0X40);
    // 0x8037CD8C: addiu       $t0, $a1, 0x40
    ctx->r8 = ADD32(ctx->r5, 0X40);
    // 0x8037CD90: b           L_8037CD9C
    // 0x8037CD94: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
        goto L_8037CD9C;
    // 0x8037CD94: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
L_8037CD98:
    // 0x8037CD98: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
L_8037CD9C:
    // 0x8037CD9C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CDA0: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8037CDA4: lh          $t3, 0x12($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X12);
    // 0x8037CDA8: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x8037CDAC: b           L_8037CFB4
    // 0x8037CDB0: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
        goto L_8037CFB4;
    // 0x8037CDB0: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
    // 0x8037CDB4: sh          $a2, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r6;
L_8037CDB8:
    // 0x8037CDB8: lbu         $t5, 0xEF5($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037CDBC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8037CDC0: b           L_8037CFB4
    // 0x8037CDC4: sb          $t6, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r14;
        goto L_8037CFB4;
    // 0x8037CDC4: sb          $t6, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r14;
L_8037CDC8:
    // 0x8037CDC8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8037CDCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037CDD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037CDD4: lui         $t7, 0x168
    ctx->r15 = S32(0X168 << 16);
    // 0x8037CDD8: ori         $a1, $t7, 0x3E
    ctx->r5 = ctx->r15 | 0X3E;
    // 0x8037CDDC: addiu       $t8, $zero, 0x1100
    ctx->r24 = ADD32(0, 0X1100);
    // 0x8037CDE0: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x8037CDE4: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x8037CDE8: sh          $t8, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r24;
    // 0x8037CDEC: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x8037CDF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037CDF4: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x8037CDF8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8037CDFC: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037CE00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037CE04: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037CE08: jal         0x8013A28C
    // 0x8037CE0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_14;
    // 0x8037CE0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_14:
    // 0x8037CE10: lw          $t1, 0x2C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X2C);
    // 0x8037CE14: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8037CE18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8037CE1C: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8037CE20: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    // 0x8037CE24: lw          $t3, 0xEF8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XEF8);
    // 0x8037CE28: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CE2C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8037CE30: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x8037CE34: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8037CE38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037CE3C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8037CE40: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037CE44: lh          $t6, 0x12($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X12);
    // 0x8037CE48: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x8037CE4C: swc1        $f18, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f18.u32l;
    // 0x8037CE50: swc1        $f4, -0x758C($at)
    MEM_W(-0X758C, ctx->r1) = ctx->f4.u32l;
    // 0x8037CE54: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CE58: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8037CE5C: jal         0x8001EAD0
    // 0x8037CE60: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_15;
    // 0x8037CE60: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_15:
    // 0x8037CE64: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037CE68: lwc1        $f6, -0x758C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X758C);
    // 0x8037CE6C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8037CE70: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8037CE74: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8037CE78: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8037CE7C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8037CE80: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8037CE84: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8037CE88: swc1        $f6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f6.u32l;
    // 0x8037CE8C: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x8037CE90: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8037CE94: jal         0x8001EB64
    // 0x8037CE98: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_16;
    // 0x8037CE98: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_16:
    // 0x8037CE9C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037CEA0: lwc1        $f8, -0x758C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X758C);
    // 0x8037CEA4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8037CEA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8037CEAC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8037CEB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037CEB4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8037CEB8: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x8037CEBC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8037CEC0: swc1        $f8, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f8.u32l;
    // 0x8037CEC4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8037CEC8: jal         0x80010550
    // 0x8037CECC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_17;
    // 0x8037CECC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_17:
    // 0x8037CED0: lbu         $t3, 0xEF5($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XEF5);
    // 0x8037CED4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037CED8: addiu       $a0, $a0, -0x7590
    ctx->r4 = ADD32(ctx->r4, -0X7590);
    // 0x8037CEDC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8037CEE0: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8037CEE4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8037CEE8: b           L_8037CFB4
    // 0x8037CEEC: sb          $t4, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r12;
        goto L_8037CFB4;
    // 0x8037CEEC: sb          $t4, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r12;
L_8037CEF0:
    // 0x8037CEF0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037CEF4: addiu       $a0, $a0, -0x7590
    ctx->r4 = ADD32(ctx->r4, -0X7590);
    // 0x8037CEF8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8037CEFC: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8037CF00: slti        $at, $v0, 0x3B
    ctx->r1 = SIGNED(ctx->r2) < 0X3B ? 1 : 0;
    // 0x8037CF04: bne         $at, $zero, L_8037CF14
    if (ctx->r1 != 0) {
        // 0x8037CF08: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8037CF14;
    }
    // 0x8037CF08: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8037CF0C: b           L_8037CFB4
    // 0x8037CF10: sb          $t5, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r13;
        goto L_8037CFB4;
    // 0x8037CF10: sb          $t5, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r13;
L_8037CF14:
    // 0x8037CF14: b           L_8037CFB4
    // 0x8037CF18: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
        goto L_8037CFB4;
    // 0x8037CF18: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
L_8037CF1C:
    // 0x8037CF1C: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x8037CF20: addiu       $t6, $t6, 0x6B90
    ctx->r14 = ADD32(ctx->r14, 0X6B90);
    // 0x8037CF24: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8037CF28: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8037CF2C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8037CF30: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8037CF34: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x8037CF38: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037CF3C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8037CF40: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037CF44: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8037CF48: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8037CF4C: jal         0x80011140
    // 0x8037CF50: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_18;
    // 0x8037CF50: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_18:
    // 0x8037CF54: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8037CF58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037CF5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037CF60: sh          $zero, 0x18($t1)
    MEM_H(0X18, ctx->r9) = 0;
    // 0x8037CF64: lhu         $t2, 0xEF0($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XEF0);
    // 0x8037CF68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037CF6C: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x8037CF70: sh          $t3, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r11;
    // 0x8037CF74: lw          $t4, 0x2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2C);
    // 0x8037CF78: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x8037CF7C: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x8037CF80: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x8037CF84: sw          $t5, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r13;
    // 0x8037CF88: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x8037CF8C: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    // 0x8037CF90: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x8037CF94: lw          $t8, 0xEFC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XEFC);
    // 0x8037CF98: jal         0x801C4A5C
    // 0x8037CF9C: sw          $t8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r24;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_19;
    // 0x8037CF9C: sw          $t8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r24;
    after_19:
    // 0x8037CFA0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037CFA4: addiu       $a0, $a0, -0x7590
    ctx->r4 = ADD32(ctx->r4, -0X7590);
    // 0x8037CFA8: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8037CFAC: sb          $zero, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = 0;
    // 0x8037CFB0: sw          $zero, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = 0;
L_8037CFB4:
    // 0x8037CFB4: lhu         $t9, 0xEF0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XEF0);
L_8037CFB8:
    // 0x8037CFB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037CFBC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8037CFC0: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x8037CFC4: bnel        $t0, $zero, L_8037CFD8
    if (ctx->r8 != 0) {
        // 0x8037CFC8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8037CFD8;
    }
    goto skip_1;
    // 0x8037CFC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8037CFCC: jal         0x800058DC
    // 0x8037CFD0: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_20;
    // 0x8037CFD0: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    after_20:
    // 0x8037CFD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037CFD8:
    // 0x8037CFD8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8037CFDC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8037CFE0: jr          $ra
    // 0x8037CFE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8037CFE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037cfe8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037cfe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CFE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037CFEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037CFF0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8037CFF4: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8037CFF8: lw          $v0, 0xDC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XDC);
    // 0x8037CFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037D000: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037D004: beql        $v0, $zero, L_8037D0EC
    if (ctx->r2 == 0) {
        // 0x8037D008: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037D0EC;
    }
    goto skip_0;
    // 0x8037D008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037D00C: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x8037D010: beql        $t6, $zero, L_8037D0EC
    if (ctx->r14 == 0) {
        // 0x8037D014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037D0EC;
    }
    goto skip_1;
    // 0x8037D014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8037D018: lbu         $t7, 0xF5($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XF5);
    // 0x8037D01C: beql        $t7, $zero, L_8037D0EC
    if (ctx->r15 == 0) {
        // 0x8037D020: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037D0EC;
    }
    goto skip_2;
    // 0x8037D020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8037D024: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8037D028: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037D02C: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x8037D030: lw          $t8, 0x1C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C);
    // 0x8037D034: beql        $t8, $at, L_8037D050
    if (ctx->r24 == ctx->r1) {
        // 0x8037D038: lui         $at, 0x4214
        ctx->r1 = S32(0X4214 << 16);
            goto L_8037D050;
    }
    goto skip_3;
    // 0x8037D038: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
    skip_3:
    // 0x8037D03C: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x8037D040: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037D044: ori         $at, $at, 0x17
    ctx->r1 = ctx->r1 | 0X17;
    // 0x8037D048: bne         $t9, $at, L_8037D0E8
    if (ctx->r25 != ctx->r1) {
        // 0x8037D04C: lui         $at, 0x4214
        ctx->r1 = S32(0X4214 << 16);
            goto L_8037D0E8;
    }
    // 0x8037D04C: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
L_8037D050:
    // 0x8037D050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037D054: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D058: lwc1        $f6, -0x671C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X671C);
    // 0x8037D05C: lui         $at, 0x439A
    ctx->r1 = S32(0X439A << 16);
    // 0x8037D060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037D064: lw          $t0, 0xE0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XE0);
    // 0x8037D068: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8037D06C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8037D070: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8037D074: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x8037D078: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8037D07C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8037D080: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037D084: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8037D088: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8037D08C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8037D090: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8037D094: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8037D098: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8037D09C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8037D0A0: jal         0x8002FC20
    // 0x8037D0A4: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8037D0A4: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x8037D0A8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8037D0AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8037D0B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037D0B4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8037D0B8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8037D0BC: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8037D0C0: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8037D0C4: bc1fl       L_8037D0EC
    if (!c1cs) {
        // 0x8037D0C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037D0EC;
    }
    goto skip_4;
    // 0x8037D0C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8037D0CC: lhu         $t1, 0xEF0($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XEF0);
    // 0x8037D0D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037D0D4: ori         $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 | 0X4000;
    // 0x8037D0D8: jal         0x801BF1A0
    // 0x8037D0DC: sh          $t2, 0xEF0($a1)
    MEM_H(0XEF0, ctx->r5) = ctx->r10;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_1;
    // 0x8037D0DC: sh          $t2, 0xEF0($a1)
    MEM_H(0XEF0, ctx->r5) = ctx->r10;
    after_1:
    // 0x8037D0E0: jal         0x80005700
    // 0x8037D0E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x8037D0E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_8037D0E8:
    // 0x8037D0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037D0EC:
    // 0x8037D0EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037D0F0: jr          $ra
    // 0x8037D0F4: nop

    return;
    // 0x8037D0F4: nop

;}
RECOMP_FUNC void M55_FUN_8037d0f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D0F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037D0FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037d100(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037d100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D100: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8037D104: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D108: lwc1        $f4, -0x6718($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6718);
    // 0x8037D10C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D110: lwc1        $f6, -0x6714($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6714);
    // 0x8037D114: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D118: lwc1        $f8, -0x6710($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6710);
    // 0x8037D11C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D120: lwc1        $f10, -0x670C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X670C);
    // 0x8037D124: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D128: lwc1        $f16, -0x6708($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6708);
    // 0x8037D12C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D130: lwc1        $f18, -0x6704($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6704);
    // 0x8037D134: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8037D138: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8037D13C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8037D140: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037D144: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037D148: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8037D14C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037D150: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8037D154: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037D158: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037D15C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8037D160: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8037D164: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8037D168: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8037D16C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037D170: addiu       $a0, $a0, -0x67AC
    ctx->r4 = ADD32(ctx->r4, -0X67AC);
    // 0x8037D174: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x8037D178: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8037D17C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037D180: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8037D184: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8037D188: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8037D18C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8037D190: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8037D194: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8037D198: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8037D19C: jal         0x8011AAF4
    // 0x8037D1A0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x8037D1A0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8037D1A4: bnel        $v0, $zero, L_8037D1D0
    if (ctx->r2 != 0) {
        // 0x8037D1A8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8037D1D0;
    }
    goto skip_0;
    // 0x8037D1A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x8037D1AC: jal         0x80020718
    // 0x8037D1B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x8037D1B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8037D1B4: jal         0x801FBB30
    // 0x8037D1B8: nop

    LOOKUP_FUNC(0x801FBB30)(rdram, ctx);
        goto after_2;
    // 0x8037D1B8: nop

    after_2:
    // 0x8037D1BC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037D1C0: addiu       $a1, $a1, -0x2E24
    ctx->r5 = ADD32(ctx->r5, -0X2E24);
    // 0x8037D1C4: jal         0x800058DC
    // 0x8037D1C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8037D1C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x8037D1CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8037D1D0:
    // 0x8037D1D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8037D1D4: jr          $ra
    // 0x8037D1D8: nop

    return;
    // 0x8037D1D8: nop

;}
RECOMP_FUNC void M55_FUN_8037d1dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D1DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037D1E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037D1E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037D1E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037D1EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037D1F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037D1F4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8037D1F8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8037D1FC: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8037D200: ori         $t7, $t6, 0xE0
    ctx->r15 = ctx->r14 | 0XE0;
    // 0x8037D204: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8037D208: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x8037D20C: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x8037D210: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037D214: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8037D218: lw          $s1, 0x5C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X5C);
    // 0x8037D21C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D220: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x8037D224: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x8037D228: lwc1        $f6, -0x6700($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6700);
    // 0x8037D22C: lui         $at, 0x439A
    ctx->r1 = S32(0X439A << 16);
    // 0x8037D230: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8037D234: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037D238: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037D23C: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x8037D240: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x8037D244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037D248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8037D24C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8037D250: lui         $t6, 0x168
    ctx->r14 = S32(0X168 << 16);
    // 0x8037D254: ori         $a1, $t6, 0x15
    ctx->r5 = ctx->r14 | 0X15;
    // 0x8037D258: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x8037D25C: lw          $t4, 0xDC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XDC);
    // 0x8037D260: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8037D264: swc1        $f10, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f10.u32l;
    // 0x8037D268: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
    // 0x8037D26C: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8037D270: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8037D274: lw          $t5, 0xDC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XDC);
    // 0x8037D278: swc1        $f0, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f0.u32l;
    // 0x8037D27C: sw          $a1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r5;
    // 0x8037D280: sh          $zero, 0x20($s1)
    MEM_H(0X20, ctx->r17) = 0;
    // 0x8037D284: sh          $zero, 0x22($s1)
    MEM_H(0X22, ctx->r17) = 0;
    // 0x8037D288: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
    // 0x8037D28C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037D290: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x8037D294: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037D298: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037D29C: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x8037D2A0: jal         0x8013A28C
    // 0x8037D2A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_0;
    // 0x8037D2A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8037D2A8: lhu         $t9, 0xEF0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XEF0);
    // 0x8037D2AC: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x8037D2B0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8037D2B4: andi        $t0, $t9, 0xFEFF
    ctx->r8 = ctx->r25 & 0XFEFF;
    // 0x8037D2B8: sh          $t0, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r8;
    // 0x8037D2BC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8037D2C0: addiu       $t4, $zero, 0x181
    ctx->r12 = ADD32(0, 0X181);
    // 0x8037D2C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037D2C8: sh          $t1, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r9;
    // 0x8037D2CC: sw          $t4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->r12;
    // 0x8037D2D0: jal         0x801C4A5C
    // 0x8037D2D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_1;
    // 0x8037D2D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8037D2D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037D2DC: jal         0x80010550
    // 0x8037D2E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x8037D2E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8037D2E4: lw          $t5, 0xE8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE8);
    // 0x8037D2E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037D2EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8037D2F0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8037D2F4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037D2F8: addiu       $a1, $a1, -0x2CE0
    ctx->r5 = ADD32(ctx->r5, -0X2CE0);
    // 0x8037D2FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037D300: jal         0x800058DC
    // 0x8037D304: swc1        $f18, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f18.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8037D304: swc1        $f18, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f18.u32l;
    after_3:
    // 0x8037D308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037D30C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037D310: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8037D314: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8037D318: jr          $ra
    // 0x8037D31C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037D31C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037d320(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037d320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D320: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8037D324: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037d328(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037d328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D328: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037D32C: lw          $t7, 0xE8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XE8);
    // 0x8037D330: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037D334: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037D338: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037D33C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037D340: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037D344: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8037D348: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8037D34C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8037D350: swc1        $f4, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f4.u32l;
    // 0x8037D354: lw          $t0, 0xE0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE0);
    // 0x8037D358: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8037D35C: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x8037D360: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037D364: jal         0x80010550
    // 0x8037D368: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037D368: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8037D36C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8037D370: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8037D374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8037D378: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8037D37C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037D380: jal         0x801E95D4
    // 0x8037D384: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x801E95D4)(rdram, ctx);
        goto after_1;
    // 0x8037D384: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x8037D388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037D38C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037D390: jr          $ra
    // 0x8037D394: nop

    return;
    // 0x8037D394: nop

;}
RECOMP_FUNC void M55_FUN_8037d398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D398: nop

    // 0x8037D39C: nop

;}
RECOMP_FUNC void M55_FUN_8037d3a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D3A0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8037D3A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8037D3A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037D3AC: beq         $t6, $zero, L_8037D410
    if (ctx->r14 == 0) {
        // 0x8037D3B0: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8037D410;
    }
    // 0x8037D3B0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8037D3B4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8037D3B8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8037D3BC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8037D3C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8037D3C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037D3C8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8037D3CC: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_8037D3D0:
    // 0x8037D3D0: bne         $at, $zero, L_8037D3F0
    if (ctx->r1 != 0) {
        // 0x8037D3D4: slti        $at, $v1, 0x81
        ctx->r1 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
            goto L_8037D3F0;
    }
    // 0x8037D3D4: slti        $at, $v1, 0x81
    ctx->r1 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
    // 0x8037D3D8: beql        $at, $zero, L_8037D3F4
    if (ctx->r1 == 0) {
        // 0x8037D3DC: cvt.d.s     $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
            goto L_8037D3F4;
    }
    goto skip_0;
    // 0x8037D3DC: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    skip_0:
    // 0x8037D3E0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8037D3E4: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x8037D3E8: b           L_8037D400
    // 0x8037D3EC: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
        goto L_8037D400;
    // 0x8037D3EC: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_8037D3F0:
    // 0x8037D3F0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
L_8037D3F4:
    // 0x8037D3F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037D3F8: add.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d + ctx->f12.d;
    // 0x8037D3FC: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8037D400:
    // 0x8037D400: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8037D404: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037D408: bnel        $v1, $zero, L_8037D3D0
    if (ctx->r3 != 0) {
        // 0x8037D40C: slti        $at, $v1, 0x20
        ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
            goto L_8037D3D0;
    }
    goto skip_1;
    // 0x8037D40C: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    skip_1:
L_8037D410:
    // 0x8037D410: jr          $ra
    // 0x8037D414: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8037D414: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037d418(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037d418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037D41C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8037D420: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037D424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037D428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037D42C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8037D430: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8037D434: jal         0x8037D3A0
    // 0x8037D438: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8037D3A0)(rdram, ctx);
        goto after_0;
    // 0x8037D438: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8037D43C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8037D440: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037D444: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8037D448: addiu       $t0, $zero, 0xF5
    ctx->r8 = ADD32(0, 0XF5);
    // 0x8037D44C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8037D450: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8037D454: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8037D458: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8037D45C: addiu       $t2, $zero, 0xA1
    ctx->r10 = ADD32(0, 0XA1);
    // 0x8037D460: addiu       $t3, $zero, 0xB8
    ctx->r11 = ADD32(0, 0XB8);
    // 0x8037D464: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8037D468: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8037D46C: nop

    // 0x8037D470: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8037D474: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8037D478: subu        $a0, $t0, $t9
    ctx->r4 = SUB32(ctx->r8, ctx->r25);
    // 0x8037D47C: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x8037D480: beq         $v0, $zero, L_8037D4A0
    if (ctx->r2 == 0) {
        // 0x8037D484: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8037D4A0;
    }
    // 0x8037D484: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8037D488: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_8037D48C:
    // 0x8037D48C: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x8037D490: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8037D494: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8037D498: bnel        $v0, $zero, L_8037D48C
    if (ctx->r2 != 0) {
        // 0x8037D49C: sb          $v0, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r2;
            goto L_8037D48C;
    }
    goto skip_0;
    // 0x8037D49C: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    skip_0:
L_8037D4A0:
    // 0x8037D4A0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8037D4A4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8037D4A8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8037D4AC: mfhi        $t1
    ctx->r9 = hi;
    // 0x8037D4B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8037D4B4: bne         $t1, $at, L_8037D4D4
    if (ctx->r9 != ctx->r1) {
        // 0x8037D4B8: nop
    
            goto L_8037D4D4;
    }
    // 0x8037D4B8: nop

    // 0x8037D4BC: addiu       $v1, $v0, -0x5
    ctx->r3 = ADD32(ctx->r2, -0X5);
    // 0x8037D4C0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8037D4C4: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8037D4C8: sb          $t3, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r11;
    // 0x8037D4CC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8037D4D0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8037D4D4:
    // 0x8037D4D4: blez        $v1, L_8037D4F4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8037D4D8: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_8037D4F4;
    }
    // 0x8037D4D8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_8037D4DC:
    // 0x8037D4DC: addiu       $v1, $v1, -0xA
    ctx->r3 = ADD32(ctx->r3, -0XA);
    // 0x8037D4E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8037D4E4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8037D4E8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8037D4EC: bgtz        $v1, L_8037D4DC
    if (SIGNED(ctx->r3) > 0) {
        // 0x8037D4F0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8037D4DC;
    }
    // 0x8037D4F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8037D4F4:
    // 0x8037D4F4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8037D4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037D4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037D500: jr          $ra
    // 0x8037D504: nop

    return;
    // 0x8037D504: nop

;}
RECOMP_FUNC void M55_FUN_8037d508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D508: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037D50C: addiu       $v1, $v1, -0x73A0
    ctx->r3 = ADD32(ctx->r3, -0X73A0);
    // 0x8037D510: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037d514(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037d514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037D518: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037D51C: bne         $t6, $zero, L_8037D584
    if (ctx->r14 != 0) {
        // 0x8037D520: lui         $t7, 0x8039
        ctx->r15 = S32(0X8039 << 16);
            goto L_8037D584;
    }
    // 0x8037D520: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037D524: addiu       $t7, $t7, -0x739C
    ctx->r15 = ADD32(ctx->r15, -0X739C);
    // 0x8037D528: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037D52C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8037D530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037D534: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8037D538: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8037D53C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037D540: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8037D544: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8037D548: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037D54C: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8037D550: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8037D554: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8037D558: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037D55C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8037D560: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8037D564: jal         0x8012C4D0
    // 0x8037D568: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x8037D568: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x8037D56C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037D570: addiu       $v1, $v1, -0x73A0
    ctx->r3 = ADD32(ctx->r3, -0X73A0);
    // 0x8037D574: beq         $v0, $zero, L_8037D584
    if (ctx->r2 == 0) {
        // 0x8037D578: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8037D584;
    }
    // 0x8037D578: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8037D57C: b           L_8037D588
    // 0x8037D580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037D588;
    // 0x8037D580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037D584:
    // 0x8037D584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037D588:
    // 0x8037D588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037D58C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037D590: jr          $ra
    // 0x8037D594: nop

    return;
    // 0x8037D594: nop

;}
RECOMP_FUNC void M55_FUN_8037d598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D598: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D59C: lw          $t6, -0x73A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73A0);
    // 0x8037D5A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D5A4: bne         $t6, $zero, L_8037D5B4
    if (ctx->r14 != 0) {
            // 0x8037D5A8: nop

    LOOKUP_FUNC(0x8037D5B4)(rdram, ctx);
    return;
    }
    // 0x8037D5A8: nop

    // 0x8037D5AC: jr          $ra
    // 0x8037D5B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037D5B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037d5b4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037d5b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D5B4: jr          $ra
    // 0x8037D5B8: nop

    return;
    // 0x8037D5B8: nop

;}
RECOMP_FUNC void M55_FUN_8037d5bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D5BC: jr          $ra
    // 0x8037D5C0: nop

    return;
    // 0x8037D5C0: nop

;}
RECOMP_FUNC void M55_FUN_8037d5c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D5C4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8037D5C8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8037D5CC: sll         $s7, $a3, 16
    ctx->r23 = S32(ctx->r7 << 16);
    // 0x8037D5D0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8037D5D4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8037D5D8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8037D5DC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8037D5E0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8037D5E4: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8037D5E8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8037D5EC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8037D5F0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8037D5F4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8037D5F8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8037D5FC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8037D600: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8037D604: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x8037D608: sb          $zero, 0x76($sp)
    MEM_B(0X76, ctx->r29) = 0;
    // 0x8037D60C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8037D610: jal         0x80006214
    // 0x8037D614: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8037D614: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    after_0:
    // 0x8037D618: lhu         $a2, 0x82($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X82);
    // 0x8037D61C: sb          $v0, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r2;
    // 0x8037D620: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037D624: lbu         $s3, 0x97($sp)
    ctx->r19 = MEM_BU(ctx->r29, 0X97);
    // 0x8037D628: addiu       $s6, $sp, 0x76
    ctx->r22 = ADD32(ctx->r29, 0X76);
    // 0x8037D62C: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8037D630: lh          $s4, 0x8A($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X8A);
L_8037D634:
    // 0x8037D634: div         $zero, $a2, $s5
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r21)));
    // 0x8037D638: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8037D63C: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x8037D640: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x8037D644: bne         $s5, $zero, L_8037D650
    if (ctx->r21 != 0) {
        // 0x8037D648: nop
    
            goto L_8037D650;
    }
    // 0x8037D648: nop

    // 0x8037D64C: break       7
    do_break(2151142988);
L_8037D650:
    // 0x8037D650: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037D654: bne         $s5, $at, L_8037D668
    if (ctx->r21 != ctx->r1) {
        // 0x8037D658: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037D668;
    }
    // 0x8037D658: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037D65C: bne         $s1, $at, L_8037D668
    if (ctx->r17 != ctx->r1) {
        // 0x8037D660: nop
    
            goto L_8037D668;
    }
    // 0x8037D660: nop

    // 0x8037D664: break       6
    do_break(2151143012);
L_8037D668:
    // 0x8037D668: mfhi        $t7
    ctx->r15 = hi;
    // 0x8037D66C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8037D670: bne         $s3, $zero, L_8037D6E8
    if (ctx->r19 != 0) {
        // 0x8037D674: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8037D6E8;
    }
    // 0x8037D674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037D678: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8037D67C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8037D680: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8037D684: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8037D688: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8037D68C: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8037D690: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8037D694: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8037D698: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8037D69C: subu        $a3, $s7, $t8
    ctx->r7 = SUB32(ctx->r23, ctx->r24);
    // 0x8037D6A0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8037D6A4: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8037D6A8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8037D6AC: addiu       $t4, $zero, 0x21D
    ctx->r12 = ADD32(0, 0X21D);
    // 0x8037D6B0: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8037D6B4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8037D6B8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8037D6BC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8037D6C0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8037D6C4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8037D6C8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8037D6CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037D6D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037D6D4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8037D6D8: jal         0x80146208
    // 0x8037D6DC: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8037D6DC: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    after_1:
    // 0x8037D6E0: b           L_8037D74C
    // 0x8037D6E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8037D74C;
    // 0x8037D6E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8037D6E8:
    // 0x8037D6E8: bne         $s3, $at, L_8037D748
    if (ctx->r19 != ctx->r1) {
        // 0x8037D6EC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8037D748;
    }
    // 0x8037D6EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037D6F0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8037D6F4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8037D6F8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037D6FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037D700: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8037D704: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8037D708: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8037D70C: subu        $a3, $s7, $t6
    ctx->r7 = SUB32(ctx->r23, ctx->r14);
    // 0x8037D710: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8037D714: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8037D718: addiu       $t2, $zero, 0x21D
    ctx->r10 = ADD32(0, 0X21D);
    // 0x8037D71C: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8037D720: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8037D724: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8037D728: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8037D72C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8037D730: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8037D734: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8037D738: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037D73C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8037D740: jal         0x80146208
    // 0x8037D744: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x8037D744: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    after_2:
L_8037D748:
    // 0x8037D748: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8037D74C:
    // 0x8037D74C: lbu         $a1, 0x8F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X8F);
    // 0x8037D750: jal         0x80145348
    // 0x8037D754: lbu         $a2, 0x93($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X93);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_3;
    // 0x8037D754: lbu         $a2, 0x93($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X93);
    after_3:
    // 0x8037D758: div         $zero, $s1, $s5
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r21)));
    // 0x8037D75C: bne         $s5, $zero, L_8037D768
    if (ctx->r21 != 0) {
        // 0x8037D760: nop
    
            goto L_8037D768;
    }
    // 0x8037D760: nop

    // 0x8037D764: break       7
    do_break(2151143268);
L_8037D768:
    // 0x8037D768: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037D76C: bne         $s5, $at, L_8037D780
    if (ctx->r21 != ctx->r1) {
        // 0x8037D770: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037D780;
    }
    // 0x8037D770: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037D774: bne         $s1, $at, L_8037D780
    if (ctx->r17 != ctx->r1) {
        // 0x8037D778: nop
    
            goto L_8037D780;
    }
    // 0x8037D778: nop

    // 0x8037D77C: break       6
    do_break(2151143292);
L_8037D780:
    // 0x8037D780: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037D784: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037D788: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8037D78C: mflo        $a2
    ctx->r6 = lo;
    // 0x8037D790: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8037D794: bne         $at, $zero, L_8037D634
    if (ctx->r1 != 0) {
        // 0x8037D798: nop
    
            goto L_8037D634;
    }
    // 0x8037D798: nop

    // 0x8037D79C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037D7A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D7A4: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8037D7A8: addiu       $v1, $sp, 0x6F
    ctx->r3 = ADD32(ctx->r29, 0X6F);
L_8037D7AC:
    // 0x8037D7AC: negu        $t4, $v0
    ctx->r12 = SUB32(0, ctx->r2);
    // 0x8037D7B0: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8037D7B4: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8037D7B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037D7BC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037D7C0: bne         $t6, $zero, L_8037D7F0
    if (ctx->r14 != 0) {
        // 0x8037D7C4: slti        $at, $s0, 0x3
        ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
            goto L_8037D7F0;
    }
    // 0x8037D7C4: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8037D7C8: bne         $fp, $zero, L_8037D7F0
    if (ctx->r30 != 0) {
        // 0x8037D7CC: lbu         $t7, 0x72($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X72);
            goto L_8037D7F0;
    }
    // 0x8037D7CC: lbu         $t7, 0x72($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X72);
    // 0x8037D7D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8037D7D4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8037D7D8: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8037D7DC: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8037D7E0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8037D7E4: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8037D7E8: b           L_8037D7F4
    // 0x8037D7EC: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
        goto L_8037D7F4;
    // 0x8037D7EC: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
L_8037D7F0:
    // 0x8037D7F0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_8037D7F4:
    // 0x8037D7F4: bne         $at, $zero, L_8037D7AC
    if (ctx->r1 != 0) {
        // 0x8037D7F8: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8037D7AC;
    }
    // 0x8037D7F8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037D7FC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8037D800: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8037D804: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8037D808: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8037D80C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8037D810: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8037D814: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8037D818: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8037D81C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8037D820: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8037D824: jr          $ra
    // 0x8037D828: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8037D828: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037d82c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037d82c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D82C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8037D830: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037D834: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8037D838: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8037D83C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8037D840: addiu       $t7, $t7, -0x7388
    ctx->r15 = ADD32(ctx->r15, -0X7388);
    // 0x8037D844: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037D848: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8037D84C: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x8037D850: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8037D854: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8037D858: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8037D85C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8037D860: addiu       $t1, $zero, 0x45
    ctx->r9 = ADD32(0, 0X45);
    // 0x8037D864: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8037D868: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8037D86C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8037D870: addiu       $t2, $zero, 0x17
    ctx->r10 = ADD32(0, 0X17);
    // 0x8037D874: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8037D878: lhu         $a2, 0x0($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X0);
    // 0x8037D87C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037D880: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8037D884: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8037D888: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8037D88C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8037D890: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8037D894: jal         0x8037D5C4
    // 0x8037D898: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    LOOKUP_FUNC(0x8037D5C4)(rdram, ctx);
        goto after_0;
    // 0x8037D898: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_0:
    // 0x8037D89C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8037D8A0: addiu       $t5, $zero, 0x55
    ctx->r13 = ADD32(0, 0X55);
    // 0x8037D8A4: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x8037D8A8: lhu         $a2, 0x0($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X0);
    // 0x8037D8AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037D8B0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8037D8B4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8037D8B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037D8BC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8037D8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037D8C4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8037D8C8: jal         0x8037D5C4
    // 0x8037D8CC: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    LOOKUP_FUNC(0x8037D5C4)(rdram, ctx);
        goto after_1;
    // 0x8037D8CC: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_1:
    // 0x8037D8D0: addiu       $t8, $zero, 0x55
    ctx->r24 = ADD32(0, 0X55);
    // 0x8037D8D4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8037D8D8: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8037D8DC: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x8037D8E0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8037D8E4: addiu       $t3, $zero, 0x21D
    ctx->r11 = ADD32(0, 0X21D);
    // 0x8037D8E8: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x8037D8EC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8037D8F0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8037D8F4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8037D8F8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8037D8FC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8037D900: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8037D904: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037D908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037D90C: addiu       $a1, $sp, 0x53
    ctx->r5 = ADD32(ctx->r29, 0X53);
    // 0x8037D910: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037D914: addiu       $a3, $zero, 0x62
    ctx->r7 = ADD32(0, 0X62);
    // 0x8037D918: jal         0x80146208
    // 0x8037D91C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x8037D91C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x8037D920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037D924: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8037D928: jal         0x80145348
    // 0x8037D92C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_3;
    // 0x8037D92C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8037D930: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8037D934: addiu       $t6, $zero, 0x55
    ctx->r14 = ADD32(0, 0X55);
    // 0x8037D938: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x8037D93C: lhu         $a2, 0x0($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X0);
    // 0x8037D940: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8037D944: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8037D948: sb          $t9, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r25;
    // 0x8037D94C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8037D950: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8037D954: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037D958: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037D95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037D960: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8037D964: jal         0x8037D5C4
    // 0x8037D968: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    LOOKUP_FUNC(0x8037D5C4)(rdram, ctx);
        goto after_4;
    // 0x8037D968: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_4:
    // 0x8037D96C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8037D970: lbu         $t1, 0x57($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X57);
    // 0x8037D974: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8037D978: lhu         $a2, 0x0($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X0);
    // 0x8037D97C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8037D980: addiu       $t3, $t2, 0x45
    ctx->r11 = ADD32(ctx->r10, 0X45);
    // 0x8037D984: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8037D988: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8037D98C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037D990: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8037D994: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037D998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037D99C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8037D9A0: jal         0x8037D5C4
    // 0x8037D9A4: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    LOOKUP_FUNC(0x8037D5C4)(rdram, ctx);
        goto after_5;
    // 0x8037D9A4: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_5:
    // 0x8037D9A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8037D9AC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8037D9B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8037D9B4: jr          $ra
    // 0x8037D9B8: nop

    return;
    // 0x8037D9B8: nop

;}
RECOMP_FUNC void M55_FUN_8037d9bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D9BC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8037D9C0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D9C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8037D9C8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8037D9CC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8037D9D0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8037D9D4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8037D9D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8037D9DC: addiu       $t6, $t6, -0x7378
    ctx->r14 = ADD32(ctx->r14, -0X7378);
    // 0x8037D9E0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8037D9E4: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
    // 0x8037D9E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8037D9EC: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8037D9F0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8037D9F4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8037D9F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037D9FC: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x8037DA00: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8037DA04: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037DA08: sw          $t8, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r24;
    // 0x8037DA0C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8037DA10: sw          $t7, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r15;
L_8037DA14:
    // 0x8037DA14: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8037DA18: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x8037DA1C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8037DA20: sll         $t2, $s1, 4
    ctx->r10 = S32(ctx->r17 << 4);
    // 0x8037DA24: addiu       $t3, $t2, 0x86
    ctx->r11 = ADD32(ctx->r10, 0X86);
    // 0x8037DA28: lhu         $a2, 0x0($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X0);
    // 0x8037DA2C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8037DA30: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037DA34: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037DA38: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8037DA3C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037DA40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037DA44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8037DA48: jal         0x8037D5C4
    // 0x8037DA4C: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    LOOKUP_FUNC(0x8037D5C4)(rdram, ctx);
        goto after_0;
    // 0x8037DA4C: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    after_0:
    // 0x8037DA50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037DA54: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037DA58: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8037DA5C: bne         $at, $zero, L_8037DA14
    if (ctx->r1 != 0) {
        // 0x8037DA60: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_8037DA14;
    }
    // 0x8037DA60: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8037DA64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8037DA68: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8037DA6C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8037DA70: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8037DA74: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8037DA78: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8037DA7C: jr          $ra
    // 0x8037DA80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8037DA80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037da84(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037da84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DA84: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8037DA88: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037DA8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8037DA90: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8037DA94: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8037DA98: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8037DA9C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8037DAA0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8037DAA4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8037DAA8: addiu       $t6, $t6, -0x7368
    ctx->r14 = ADD32(ctx->r14, -0X7368);
    // 0x8037DAAC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8037DAB0: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
    // 0x8037DAB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8037DAB8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8037DABC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8037DAC0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037DAC4: addiu       $t1, $t1, -0x7350
    ctx->r9 = ADD32(ctx->r9, -0X7350);
    // 0x8037DAC8: sw          $t7, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r15;
    // 0x8037DACC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8037DAD0: addiu       $t0, $sp, 0x5C
    ctx->r8 = ADD32(ctx->r29, 0X5C);
    // 0x8037DAD4: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8037DAD8: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x8037DADC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8037DAE0: addiu       $t5, $t5, -0x7340
    ctx->r13 = ADD32(ctx->r13, -0X7340);
    // 0x8037DAE4: addiu       $t4, $sp, 0x4C
    ctx->r12 = ADD32(ctx->r29, 0X4C);
    // 0x8037DAE8: sw          $t7, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r15;
    // 0x8037DAEC: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8037DAF0: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
    // 0x8037DAF4: addiu       $v0, $sp, 0x74
    ctx->r2 = ADD32(ctx->r29, 0X74);
    // 0x8037DAF8: sw          $t8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r24;
    // 0x8037DAFC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8037DB00: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037DB04: addiu       $t8, $t8, -0x7330
    ctx->r24 = ADD32(ctx->r24, -0X7330);
    // 0x8037DB08: sw          $t7, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r15;
    // 0x8037DB0C: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x8037DB10: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8037DB14: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8037DB18: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8037DB1C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8037DB20: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8037DB24: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8037DB28: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8037DB2C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8037DB30: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8037DB34: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8037DB38: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8037DB3C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8037DB40: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8037DB44: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8037DB48: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8037DB4C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8037DB50: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x8037DB54: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x8037DB58: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8037DB5C: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
    // 0x8037DB60: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8037DB64: sw          $t9, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r25;
    // 0x8037DB68: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8037DB6C: jal         0x80006214
    // 0x8037DB70: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8037DB70: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_0:
    // 0x8037DB74: sb          $v0, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r2;
    // 0x8037DB78: lb          $t1, 0x91($s2)
    ctx->r9 = MEM_B(ctx->r18, 0X91);
    // 0x8037DB7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037DB80: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8037DB84: addu        $s1, $sp, $t2
    ctx->r17 = ADD32(ctx->r29, ctx->r10);
    // 0x8037DB88: lw          $s1, 0x4C($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4C);
L_8037DB8C:
    // 0x8037DB8C: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8037DB90: addu        $v0, $s3, $t3
    ctx->r2 = ADD32(ctx->r19, ctx->r11);
    // 0x8037DB94: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8037DB98: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x8037DB9C: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x8037DBA0: addiu       $t5, $t4, 0x23
    ctx->r13 = ADD32(ctx->r12, 0X23);
    // 0x8037DBA4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8037DBA8: lb          $t6, 0x91($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X91);
    // 0x8037DBAC: addiu       $a3, $a3, 0x1B
    ctx->r7 = ADD32(ctx->r7, 0X1B);
    // 0x8037DBB0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8037DBB4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8037DBB8: addu        $v1, $s4, $t7
    ctx->r3 = ADD32(ctx->r20, ctx->r15);
    // 0x8037DBBC: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8037DBC0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8037DBC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037DBC8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8037DBCC: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8037DBD0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037DBD4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8037DBD8: jal         0x8037D5C4
    // 0x8037DBDC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8037D5C4)(rdram, ctx);
        goto after_1;
    // 0x8037DBDC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_1:
    // 0x8037DBE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037DBE4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037DBE8: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8037DBEC: bne         $at, $zero, L_8037DB8C
    if (ctx->r1 != 0) {
        // 0x8037DBF0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8037DB8C;
    }
    // 0x8037DBF0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8037DBF4: lbu         $t0, 0x72($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X72);
    // 0x8037DBF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8037DBFC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037DC00: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8037DC04: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x8037DC08: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8037DC0C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8037DC10: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8037DC14: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8037DC18: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8037DC1C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8037DC20: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8037DC24: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x8037DC28: jr          $ra
    // 0x8037DC2C: sw          $t3, -0x565C($at)
    MEM_W(-0X565C, ctx->r1) = ctx->r11;
    return;
    // 0x8037DC2C: sw          $t3, -0x565C($at)
    MEM_W(-0X565C, ctx->r1) = ctx->r11;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037dc30(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037dc30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DC30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8037DC34: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8037DC38: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8037DC3C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8037DC40: jal         0x80006214
    // 0x8037DC44: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8037DC44: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8037DC48: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    // 0x8037DC4C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8037DC50: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8037DC54: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037DC58: addiu       $t0, $zero, 0x21E
    ctx->r8 = ADD32(0, 0X21E);
    // 0x8037DC5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8037DC60: sb          $v0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r2;
    // 0x8037DC64: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8037DC68: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8037DC6C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037DC70: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037DC74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037DC78: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8037DC7C: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x8037DC80: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037DC84: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x8037DC88: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037DC8C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037DC90: jal         0x80146208
    // 0x8037DC94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8037DC94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8037DC98: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8037DC9C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8037DCA0: jal         0x80145348
    // 0x8037DCA4: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x8037DCA4: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_2:
    // 0x8037DCA8: lbu         $t2, 0x3E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3E);
    // 0x8037DCAC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8037DCB0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8037DCB4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8037DCB8: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8037DCBC: lw          $v0, -0x2578($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2578);
    // 0x8037DCC0: jr          $ra
    // 0x8037DCC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8037DCC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037dcc8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037dcc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DCC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8037DCCC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8037DCD0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8037DCD4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8037DCD8: jal         0x80006214
    // 0x8037DCDC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8037DCDC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8037DCE0: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    // 0x8037DCE4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8037DCE8: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8037DCEC: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8037DCF0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037DCF4: addiu       $t0, $zero, 0x21E
    ctx->r8 = ADD32(0, 0X21E);
    // 0x8037DCF8: sb          $v0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r2;
    // 0x8037DCFC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8037DD00: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037DD04: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037DD08: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037DD0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037DD10: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037DD14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037DD18: lb          $t1, 0x97($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X97);
    // 0x8037DD1C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037DD20: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x8037DD24: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8037DD28: lbu         $t2, -0x7400($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X7400);
    // 0x8037DD2C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037DD30: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x8037DD34: jal         0x80146208
    // 0x8037DD38: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8037DD38: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_1:
    // 0x8037DD3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8037DD40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037DD44: jal         0x80145348
    // 0x8037DD48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x8037DD48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8037DD4C: lbu         $t3, 0x3E($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3E);
    // 0x8037DD50: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8037DD54: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8037DD58: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8037DD5C: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x8037DD60: lw          $v0, -0x2578($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2578);
    // 0x8037DD64: jr          $ra
    // 0x8037DD68: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8037DD68: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037dd6c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037dd6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DD6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037DD70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037DD74: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037DD78: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037DD7C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8037DD80: sb          $zero, 0x22($sp)
    MEM_B(0X22, ctx->r29) = 0;
    // 0x8037DD84: lw          $t6, 0x30($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X30);
    // 0x8037DD88: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8037DD8C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8037DD90: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x8037DD94: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8037DD98: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8037DD9C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8037DDA0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037DDA4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8037DDA8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8037DDAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037DDB0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8037DDB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037DDB8: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8037DDBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037DDC0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8037DDC4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8037DDC8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x8037DDCC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8037DDD0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8037DDD4: bc1fl       L_8037DDE8
    if (!c1cs) {
        // 0x8037DDD8: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8037DDE8;
    }
    goto skip_0;
    // 0x8037DDD8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8037DDDC: b           L_8037DDE8
    // 0x8037DDE0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8037DDE8;
    // 0x8037DDE0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8037DDE4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8037DDE8:
    // 0x8037DDE8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8037DDEC: nop

    // 0x8037DDF0: bc1fl       L_8037DE48
    if (!c1cs) {
        // 0x8037DDF4: add.s       $f10, $f16, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f12.fl;
            goto L_8037DE48;
    }
    goto skip_1;
    // 0x8037DDF4: add.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f12.fl;
    skip_1:
    // 0x8037DDF8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8037DDFC: nop

    // 0x8037DE00: bc1fl       L_8037DE14
    if (!c1cs) {
        // 0x8037DE04: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8037DE14;
    }
    goto skip_2;
    // 0x8037DE04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_2:
    // 0x8037DE08: b           L_8037DE14
    // 0x8037DE0C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8037DE14;
    // 0x8037DE0C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8037DE10: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8037DE14:
    // 0x8037DE14: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8037DE18: nop

    // 0x8037DE1C: bc1fl       L_8037DE48
    if (!c1cs) {
        // 0x8037DE20: add.s       $f10, $f16, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f12.fl;
            goto L_8037DE48;
    }
    goto skip_3;
    // 0x8037DE20: add.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f12.fl;
    skip_3:
    // 0x8037DE24: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8037DE28: nop

    // 0x8037DE2C: bc1fl       L_8037DE40
    if (!c1cs) {
        // 0x8037DE30: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8037DE40;
    }
    goto skip_4;
    // 0x8037DE30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_4:
    // 0x8037DE34: b           L_8037DE40
    // 0x8037DE38: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8037DE40;
    // 0x8037DE38: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8037DE3C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8037DE40:
    // 0x8037DE40: div.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8037DE44: add.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f12.fl;
L_8037DE48:
    // 0x8037DE48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8037DE4C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8037DE50: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8037DE54: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8037DE58: jal         0x80006088
    // 0x8037DE5C: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x8037DE5C: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x8037DE60: jal         0x80006088
    // 0x8037DE64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_1;
    // 0x8037DE64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8037DE68: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8037DE6C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8037DE70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8037DE74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037DE78: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8037DE7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8037DE80: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8037DE84: bc1fl       L_8037DE98
    if (!c1cs) {
        // 0x8037DE88: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8037DE98;
    }
    goto skip_5;
    // 0x8037DE88: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_5:
    // 0x8037DE8C: b           L_8037DE98
    // 0x8037DE90: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_8037DE98;
    // 0x8037DE90: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x8037DE94: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8037DE98:
    // 0x8037DE98: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8037DE9C: nop

    // 0x8037DEA0: bc1f        L_8037DEC0
    if (!c1cs) {
        // 0x8037DEA4: nop
    
            goto L_8037DEC0;
    }
    // 0x8037DEA4: nop

    // 0x8037DEA8: jal         0x8037DC30
    // 0x8037DEAC: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8037DC30)(rdram, ctx);
        goto after_2;
    // 0x8037DEAC: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    after_2:
    // 0x8037DEB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8037DEB4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8037DEB8: jal         0x8037DCC8
    // 0x8037DEBC: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8037DCC8)(rdram, ctx);
        goto after_3;
    // 0x8037DEBC: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    after_3:
L_8037DEC0:
    // 0x8037DEC0: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037DEC4: lw          $t9, -0x563C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X563C);
    // 0x8037DEC8: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x8037DECC: beql        $a0, $zero, L_8037DEE8
    if (ctx->r4 == 0) {
        // 0x8037DED0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8037DEE8;
    }
    goto skip_6;
    // 0x8037DED0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_6:
    // 0x8037DED4: jal         0x80147174
    // 0x8037DED8: nop

    LOOKUP_FUNC(0x80147174)(rdram, ctx);
        goto after_4;
    // 0x8037DED8: nop

    after_4:
    // 0x8037DEDC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8037DEE0: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x8037DEE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8037DEE8:
    // 0x8037DEE8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8037DEEC: jal         0x8037DC30
    // 0x8037DEF0: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8037DC30)(rdram, ctx);
        goto after_5;
    // 0x8037DEF0: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    after_5:
    // 0x8037DEF4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037DEF8: sw          $v0, -0x5650($at)
    MEM_W(-0X5650, ctx->r1) = ctx->r2;
    // 0x8037DEFC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8037DF00: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8037DF04: jal         0x8037DCC8
    // 0x8037DF08: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8037DCC8)(rdram, ctx);
        goto after_6;
    // 0x8037DF08: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    after_6:
    // 0x8037DF0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037DF10: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037DF14: sw          $v0, -0x564C($at)
    MEM_W(-0X564C, ctx->r1) = ctx->r2;
    // 0x8037DF18: lbu         $v0, 0x22($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X22);
    // 0x8037DF1C: jr          $ra
    // 0x8037DF20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037DF20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037df24(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037df24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DF24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037DF28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037DF2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037DF30: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8037DF34: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8037DF38: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8037DF3C: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x8037DF40: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8037DF44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037DF48: lw          $s0, -0x5650($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5650);
    // 0x8037DF4C: lw          $s1, -0x564C($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X564C);
    // 0x8037DF50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8037DF54:
    // 0x8037DF54: lb          $t6, 0x97($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X97);
    // 0x8037DF58: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8037DF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037DF60: bne         $s2, $t6, L_8037DF8C
    if (ctx->r18 != ctx->r14) {
        // 0x8037DF64: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8037DF8C;
    }
    // 0x8037DF64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037DF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037DF6C: jal         0x80145310
    // 0x8037DF70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x8037DF70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8037DF74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037DF78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037DF7C: jal         0x80145310
    // 0x8037DF80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x8037DF80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8037DF84: b           L_8037DFA8
    // 0x8037DF88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8037DFA8;
    // 0x8037DF88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8037DF8C:
    // 0x8037DF8C: jal         0x80145310
    // 0x8037DF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_2;
    // 0x8037DF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8037DF94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037DF98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037DF9C: jal         0x80145310
    // 0x8037DFA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_3;
    // 0x8037DFA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8037DFA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8037DFA8:
    // 0x8037DFA8: sll         $s2, $s2, 24
    ctx->r18 = S32(ctx->r18 << 24);
    // 0x8037DFAC: sra         $s2, $s2, 24
    ctx->r18 = S32(SIGNED(ctx->r18) >> 24);
    // 0x8037DFB0: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8037DFB4: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x8037DFB8: bne         $at, $zero, L_8037DF54
    if (ctx->r1 != 0) {
        // 0x8037DFBC: lw          $s1, 0x10($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X10);
            goto L_8037DF54;
    }
    // 0x8037DFBC: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x8037DFC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037DFC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037DFC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037DFCC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8037DFD0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8037DFD4: jr          $ra
    // 0x8037DFD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037DFD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037dfdc(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037dfdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DFDC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8037DFE0: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8037DFE4: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8037DFE8: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8037DFEC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8037DFF0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8037DFF4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8037DFF8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8037DFFC: lui         $s2, 0x8039
    ctx->r18 = S32(0X8039 << 16);
    // 0x8037E000: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x8037E004: lui         $s4, 0x8039
    ctx->r20 = S32(0X8039 << 16);
    // 0x8037E008: lui         $s6, 0x8039
    ctx->r22 = S32(0X8039 << 16);
    // 0x8037E00C: lui         $s7, 0x8039
    ctx->r23 = S32(0X8039 << 16);
    // 0x8037E010: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8037E014: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8037E018: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8037E01C: lw          $s2, -0x5648($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X5648);
    // 0x8037E020: lw          $s3, -0x5644($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X5644);
    // 0x8037E024: addiu       $s7, $s7, -0x6628
    ctx->r23 = ADD32(ctx->r23, -0X6628);
    // 0x8037E028: addiu       $s6, $s6, -0x6630
    ctx->r22 = ADD32(ctx->r22, -0X6630);
    // 0x8037E02C: addiu       $s4, $s4, -0x73FC
    ctx->r20 = ADD32(ctx->r20, -0X73FC);
    // 0x8037E030: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8037E034:
    // 0x8037E034: lb          $t6, 0x97($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X97);
    // 0x8037E038: lw          $s1, 0x30($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X30);
    // 0x8037E03C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037E040: bne         $s0, $t6, L_8037E094
    if (ctx->r16 != ctx->r14) {
        // 0x8037E044: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8037E094;
    }
    // 0x8037E044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037E048: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037E04C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8037E050: jal         0x80145310
    // 0x8037E054: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x8037E054: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_0:
    // 0x8037E058: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8037E05C: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x8037E060: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8037E064: lh          $a2, 0x2($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X2);
    // 0x8037E068: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x8037E06C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8037E070: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037E074: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8037E078: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037E07C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x8037E080: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8037E084: jal         0x8001B204
    // 0x8037E088: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8037E088: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x8037E08C: b           L_8037E0D4
    // 0x8037E090: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8037E0D4;
    // 0x8037E090: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037E094:
    // 0x8037E094: jal         0x80145310
    // 0x8037E098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_2;
    // 0x8037E098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8037E09C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8037E0A0: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x8037E0A4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8037E0A8: lh          $a2, 0x2($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X2);
    // 0x8037E0AC: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x8037E0B0: addiu       $t1, $zero, 0x82
    ctx->r9 = ADD32(0, 0X82);
    // 0x8037E0B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8037E0B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8037E0BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037E0C0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x8037E0C4: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8037E0C8: jal         0x8001B204
    // 0x8037E0CC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x8037E0CC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_3:
    // 0x8037E0D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037E0D4:
    // 0x8037E0D4: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x8037E0D8: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8037E0DC: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8037E0E0: lw          $s2, 0x10($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X10);
    // 0x8037E0E4: bne         $at, $zero, L_8037E034
    if (ctx->r1 != 0) {
        // 0x8037E0E8: lw          $s3, 0x10($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X10);
            goto L_8037E034;
    }
    // 0x8037E0E8: lw          $s3, 0x10($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X10);
    // 0x8037E0EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8037E0F0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8037E0F4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8037E0F8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8037E0FC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8037E100: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8037E104: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8037E108: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8037E10C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8037E110: jr          $ra
    // 0x8037E114: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8037E114: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037e118(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037e118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E118: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8037E11C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037E120: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8037E124: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8037E128: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8037E12C: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8037E130: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8037E134: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8037E138: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8037E13C: jal         0x80006214
    // 0x8037E140: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8037E140: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x8037E144: addiu       $s4, $sp, 0x5E
    ctx->r20 = ADD32(ctx->r29, 0X5E);
    // 0x8037E148: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x8037E14C: addiu       $t7, $zero, 0x60
    ctx->r15 = ADD32(0, 0X60);
    // 0x8037E150: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8037E154: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037E158: addiu       $t0, $zero, 0x20E
    ctx->r8 = ADD32(0, 0X20E);
    // 0x8037E15C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8037E160: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
    // 0x8037E164: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8037E168: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8037E16C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037E170: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037E174: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037E178: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037E17C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037E180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E184: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037E188: addiu       $a3, $zero, 0x70
    ctx->r7 = ADD32(0, 0X70);
    // 0x8037E18C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E190: jal         0x80146208
    // 0x8037E194: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8037E194: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // 0x8037E198: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x8037E19C: addiu       $t3, $zero, 0x60
    ctx->r11 = ADD32(0, 0X60);
    // 0x8037E1A0: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8037E1A4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8037E1A8: addiu       $t6, $zero, 0x21E
    ctx->r14 = ADD32(0, 0X21E);
    // 0x8037E1AC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8037E1B0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8037E1B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8037E1B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8037E1BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8037E1C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E1C4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037E1C8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E1CC: addiu       $a3, $zero, 0x70
    ctx->r7 = ADD32(0, 0X70);
    // 0x8037E1D0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E1D4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037E1D8: jal         0x80146208
    // 0x8037E1DC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x8037E1DC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_2:
    // 0x8037E1E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E1E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037E1E8: jal         0x80145348
    // 0x8037E1EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_3;
    // 0x8037E1EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8037E1F0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8037E1F4: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8037E1F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E1FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8037E200: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8037E204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E208: jal         0x80006214
    // 0x8037E20C: sw          $t0, -0x5664($at)
    MEM_W(-0X5664, ctx->r1) = ctx->r8;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x8037E20C: sw          $t0, -0x5664($at)
    MEM_W(-0X5664, ctx->r1) = ctx->r8;
    after_4:
    // 0x8037E210: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
    // 0x8037E214: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037E218: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037E21C: addiu       $s2, $zero, 0x1E
    ctx->r18 = ADD32(0, 0X1E);
L_8037E220:
    // 0x8037E220: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037E224: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x8037E228: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8037E22C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8037E230: addiu       $t6, $zero, 0x21E
    ctx->r14 = ADD32(0, 0X21E);
    // 0x8037E234: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037E238: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8037E23C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8037E240: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8037E244: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8037E248: mflo        $t1
    ctx->r9 = lo;
    // 0x8037E24C: addiu       $t2, $t1, 0x4B
    ctx->r10 = ADD32(ctx->r9, 0X4B);
    // 0x8037E250: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8037E254: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8037E258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E25C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037E260: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E264: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x8037E268: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E26C: jal         0x80146208
    // 0x8037E270: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x8037E270: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x8037E274: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037E27C: jal         0x80145348
    // 0x8037E280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_6;
    // 0x8037E280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8037E284: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037E288: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037E28C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8037E290: bne         $at, $zero, L_8037E220
    if (ctx->r1 != 0) {
        // 0x8037E294: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8037E220;
    }
    // 0x8037E294: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8037E298: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8037E29C: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x8037E2A0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E2A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8037E2A8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8037E2AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E2B0: jal         0x80006214
    // 0x8037E2B4: sw          $t1, -0x5650($at)
    MEM_W(-0X5650, ctx->r1) = ctx->r9;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_7;
    // 0x8037E2B4: sw          $t1, -0x5650($at)
    MEM_W(-0X5650, ctx->r1) = ctx->r9;
    after_7:
    // 0x8037E2B8: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x8037E2BC: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
    // 0x8037E2C0: addiu       $s3, $s3, -0x7400
    ctx->r19 = ADD32(ctx->r19, -0X7400);
    // 0x8037E2C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037E2C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037E2CC:
    // 0x8037E2CC: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037E2D0: addu        $t8, $s3, $s0
    ctx->r24 = ADD32(ctx->r19, ctx->r16);
    // 0x8037E2D4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8037E2D8: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8037E2DC: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8037E2E0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8037E2E4: addiu       $t7, $zero, 0x21E
    ctx->r15 = ADD32(0, 0X21E);
    // 0x8037E2E8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8037E2EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8037E2F0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8037E2F4: mflo        $t2
    ctx->r10 = lo;
    // 0x8037E2F8: addiu       $t3, $t2, 0x4B
    ctx->r11 = ADD32(ctx->r10, 0X4B);
    // 0x8037E2FC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037E300: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037E304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E308: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037E30C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E310: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x8037E314: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E318: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037E31C: jal         0x80146208
    // 0x8037E320: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x8037E320: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_8:
    // 0x8037E324: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E328: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037E32C: jal         0x80145348
    // 0x8037E330: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_9;
    // 0x8037E330: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8037E334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037E338: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037E33C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8037E340: bne         $at, $zero, L_8037E2CC
    if (ctx->r1 != 0) {
        // 0x8037E344: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8037E2CC;
    }
    // 0x8037E344: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8037E348: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8037E34C: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x8037E350: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E354: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8037E358: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8037E35C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E360: jal         0x8037DF24
    // 0x8037E364: sw          $t3, -0x564C($at)
    MEM_W(-0X564C, ctx->r1) = ctx->r11;
    LOOKUP_FUNC(0x8037DF24)(rdram, ctx);
        goto after_10;
    // 0x8037E364: sw          $t3, -0x564C($at)
    MEM_W(-0X564C, ctx->r1) = ctx->r11;
    after_10:
    // 0x8037E368: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8037E36C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8037E370: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8037E374: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8037E378: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8037E37C: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8037E380: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8037E384: jr          $ra
    // 0x8037E388: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8037E388: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037e38c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037e38c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E38C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8037E390: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8037E394: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8037E398: addiu       $s3, $sp, 0x5E
    ctx->r19 = ADD32(ctx->r29, 0X5E);
    // 0x8037E39C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8037E3A0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037E3A4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8037E3A8: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8037E3AC: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8037E3B0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8037E3B4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037E3B8: addiu       $t0, $zero, 0x21E
    ctx->r8 = ADD32(0, 0X21E);
    // 0x8037E3BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8037E3C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8037E3C4: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8037E3C8: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8037E3CC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8037E3D0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8037E3D4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8037E3D8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037E3DC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037E3E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037E3E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037E3E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8037E3EC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E3F0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037E3F4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E3F8: jal         0x80146208
    // 0x8037E3FC: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_0;
    // 0x8037E3FC: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_0:
    // 0x8037E400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E404: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8037E408: jal         0x80145348
    // 0x8037E40C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_1;
    // 0x8037E40C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_1:
    // 0x8037E410: jal         0x80006214
    // 0x8037E414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x8037E414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8037E418: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8037E41C: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x8037E420: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x8037E424: lui         $s5, 0x8039
    ctx->r21 = S32(0X8039 << 16);
    // 0x8037E428: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E42C: addiu       $s5, $s5, -0x7400
    ctx->r21 = ADD32(ctx->r21, -0X7400);
    // 0x8037E430: sw          $t4, -0x5650($at)
    MEM_W(-0X5650, ctx->r1) = ctx->r12;
    // 0x8037E434: lbu         $t0, 0x3($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X3);
    // 0x8037E438: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8037E43C: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8037E440: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8037E444: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8037E448: addiu       $t9, $zero, 0x21E
    ctx->r25 = ADD32(0, 0X21E);
    // 0x8037E44C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8037E450: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8037E454: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8037E458: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037E45C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8037E460: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037E464: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E46C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8037E470: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E474: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x8037E478: jal         0x80146208
    // 0x8037E47C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x8037E47C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8037E480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037E488: jal         0x80145348
    // 0x8037E48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_4;
    // 0x8037E48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8037E490: jal         0x80006214
    // 0x8037E494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x8037E494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8037E498: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8037E49C: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x8037E4A0: lw          $t3, -0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X4);
    // 0x8037E4A4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E4A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E4AC: jal         0x80006214
    // 0x8037E4B0: sw          $t3, -0x564C($at)
    MEM_W(-0X564C, ctx->r1) = ctx->r11;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x8037E4B0: sw          $t3, -0x564C($at)
    MEM_W(-0X564C, ctx->r1) = ctx->r11;
    after_6:
    // 0x8037E4B4: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x8037E4B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037E4BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037E4C0: addiu       $s2, $zero, 0x16
    ctx->r18 = ADD32(0, 0X16);
L_8037E4C4:
    // 0x8037E4C4: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037E4C8: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8037E4CC: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8037E4D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8037E4D4: addiu       $t9, $zero, 0x21E
    ctx->r25 = ADD32(0, 0X21E);
    // 0x8037E4D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8037E4DC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8037E4E0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8037E4E4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8037E4E8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8037E4EC: mflo        $t4
    ctx->r12 = lo;
    // 0x8037E4F0: addiu       $t5, $t4, 0x4B
    ctx->r13 = ADD32(ctx->r12, 0X4B);
    // 0x8037E4F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8037E4F8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037E4FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E500: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8037E504: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E508: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x8037E50C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E510: jal         0x80146208
    // 0x8037E514: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_7;
    // 0x8037E514: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_7:
    // 0x8037E518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E51C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037E520: jal         0x80145348
    // 0x8037E524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_8;
    // 0x8037E524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8037E528: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037E52C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037E530: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8037E534: bne         $at, $zero, L_8037E4C4
    if (ctx->r1 != 0) {
        // 0x8037E538: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8037E4C4;
    }
    // 0x8037E538: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8037E53C: lbu         $t1, 0x5D($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5D);
    // 0x8037E540: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E548: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8037E54C: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x8037E550: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8037E554: jal         0x80006214
    // 0x8037E558: sw          $t4, -0x5648($at)
    MEM_W(-0X5648, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_9;
    // 0x8037E558: sw          $t4, -0x5648($at)
    MEM_W(-0X5648, ctx->r1) = ctx->r12;
    after_9:
    // 0x8037E55C: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x8037E560: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037E564: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037E568:
    // 0x8037E568: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037E56C: addu        $t1, $s5, $s0
    ctx->r9 = ADD32(ctx->r21, ctx->r16);
    // 0x8037E570: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8037E574: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8037E578: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8037E57C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037E580: addiu       $t0, $zero, 0x21E
    ctx->r8 = ADD32(0, 0X21E);
    // 0x8037E584: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8037E588: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037E58C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037E590: mflo        $t5
    ctx->r13 = lo;
    // 0x8037E594: addiu       $t6, $t5, 0x4B
    ctx->r14 = ADD32(ctx->r13, 0X4B);
    // 0x8037E598: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037E59C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037E5A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E5A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8037E5A8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E5AC: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x8037E5B0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E5B4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037E5B8: jal         0x80146208
    // 0x8037E5BC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_10;
    // 0x8037E5BC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_10:
    // 0x8037E5C0: jal         0x80006214
    // 0x8037E5C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_11;
    // 0x8037E5C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8037E5C8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8037E5CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037E5D0: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x8037E5D4: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x8037E5D8: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037E5DC: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8037E5E0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8037E5E4: bne         $at, $zero, L_8037E568
    if (ctx->r1 != 0) {
        // 0x8037E5E8: sb          $zero, 0x22($t5)
        MEM_B(0X22, ctx->r13) = 0;
            goto L_8037E568;
    }
    // 0x8037E5E8: sb          $zero, 0x22($t5)
    MEM_B(0X22, ctx->r13) = 0;
    // 0x8037E5EC: lbu         $t6, 0x5D($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5D);
    // 0x8037E5F0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E5F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037E5F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8037E5FC: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8037E600: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8037E604: jal         0x8037DFDC
    // 0x8037E608: sw          $t9, -0x5644($at)
    MEM_W(-0X5644, ctx->r1) = ctx->r25;
    LOOKUP_FUNC(0x8037DFDC)(rdram, ctx);
        goto after_12;
    // 0x8037E608: sw          $t9, -0x5644($at)
    MEM_W(-0X5644, ctx->r1) = ctx->r25;
    after_12:
    // 0x8037E60C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8037E610: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8037E614: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8037E618: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8037E61C: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8037E620: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8037E624: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8037E628: jr          $ra
    // 0x8037E62C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8037E62C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037e630(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037e630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E630: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8037E634: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8037E638: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037E63C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8037E640: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8037E644: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8037E648: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8037E64C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8037E650: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8037E654: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8037E658: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8037E65C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8037E660: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037E664: lb          $t7, 0x91($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X91);
    // 0x8037E668: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037E66C: addiu       $a3, $a3, -0x6620
    ctx->r7 = ADD32(ctx->r7, -0X6620);
    // 0x8037E670: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x8037E674: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8037E678: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x8037E67C: jal         0x8001B204
    // 0x8037E680: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x8037E680: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8037E684: addiu       $s6, $sp, 0x6E
    ctx->r22 = ADD32(ctx->r29, 0X6E);
    // 0x8037E688: addiu       $t8, $zero, 0x3F
    ctx->r24 = ADD32(0, 0X3F);
    // 0x8037E68C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8037E690: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8037E694: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8037E698: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8037E69C: addiu       $t3, $zero, 0x209
    ctx->r11 = ADD32(0, 0X209);
    // 0x8037E6A0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8037E6A4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8037E6A8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8037E6AC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8037E6B0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8037E6B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8037E6B8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8037E6BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037E6C0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8037E6C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037E6C8: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x8037E6CC: addiu       $a3, $zero, 0x7E
    ctx->r7 = ADD32(0, 0X7E);
    // 0x8037E6D0: jal         0x80146208
    // 0x8037E6D4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8037E6D4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // 0x8037E6D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037E6DC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8037E6E0: jal         0x80145348
    // 0x8037E6E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x8037E6E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x8037E6E8: jal         0x80006214
    // 0x8037E6EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x8037E6EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x8037E6F0: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8037E6F4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8037E6F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037E6FC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8037E700: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x8037E704: sw          $t8, -0x5640($at)
    MEM_W(-0X5640, ctx->r1) = ctx->r24;
    // 0x8037E708: lb          $t9, 0x91($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X91);
    // 0x8037E70C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037E710: bnel        $t9, $at, L_8037E738
    if (ctx->r25 != ctx->r1) {
        // 0x8037E714: addiu       $t4, $zero, 0x3F
        ctx->r12 = ADD32(0, 0X3F);
            goto L_8037E738;
    }
    goto skip_0;
    // 0x8037E714: addiu       $t4, $zero, 0x3F
    ctx->r12 = ADD32(0, 0X3F);
    skip_0:
    // 0x8037E718: jal         0x80006214
    // 0x8037E71C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x8037E71C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8037E720: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8037E724: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8037E728: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8037E72C: lw          $t3, -0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X4);
    // 0x8037E730: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
    // 0x8037E734: addiu       $t4, $zero, 0x3F
    ctx->r12 = ADD32(0, 0X3F);
L_8037E738:
    // 0x8037E738: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8037E73C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8037E740: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8037E744: addiu       $t8, $zero, 0x209
    ctx->r24 = ADD32(0, 0X209);
    // 0x8037E748: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8037E74C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8037E750: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8037E754: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8037E758: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8037E75C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8037E760: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8037E764: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037E768: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8037E76C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037E770: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    // 0x8037E774: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E778: jal         0x80146208
    // 0x8037E77C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x8037E77C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x8037E780: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037E784: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8037E788: jal         0x80145348
    // 0x8037E78C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_6;
    // 0x8037E78C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x8037E790: lb          $t0, 0x91($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X91);
    // 0x8037E794: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8037E798: bnel        $t0, $at, L_8037E7C0
    if (ctx->r8 != ctx->r1) {
        // 0x8037E79C: addiu       $t5, $zero, 0xA0
        ctx->r13 = ADD32(0, 0XA0);
            goto L_8037E7C0;
    }
    goto skip_1;
    // 0x8037E79C: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    skip_1:
    // 0x8037E7A0: jal         0x80006214
    // 0x8037E7A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_7;
    // 0x8037E7A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x8037E7A8: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8037E7AC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8037E7B0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8037E7B4: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x8037E7B8: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
    // 0x8037E7BC: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
L_8037E7C0:
    // 0x8037E7C0: addiu       $t6, $zero, 0x82
    ctx->r14 = ADD32(0, 0X82);
    // 0x8037E7C4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8037E7C8: addiu       $t8, $zero, 0x66
    ctx->r24 = ADD32(0, 0X66);
    // 0x8037E7CC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8037E7D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8037E7D4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037E7D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8037E7DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037E7E0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8037E7E4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8037E7E8: addiu       $a3, $zero, 0x4B
    ctx->r7 = ADD32(0, 0X4B);
    // 0x8037E7EC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E7F0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037E7F4: jal         0x80146178
    // 0x8037E7F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_8;
    // 0x8037E7F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_8:
    // 0x8037E7FC: lb          $v1, 0x91($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X91);
    // 0x8037E800: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8037E804: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037E808: blez        $v1, L_8037E8DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8037E80C: lui         $s5, 0x8039
        ctx->r21 = S32(0X8039 << 16);
            goto L_8037E8DC;
    }
    // 0x8037E80C: lui         $s5, 0x8039
    ctx->r21 = S32(0X8039 << 16);
    // 0x8037E810: addiu       $s5, $s5, -0x6614
    ctx->r21 = ADD32(ctx->r21, -0X6614);
    // 0x8037E814: addiu       $s4, $zero, 0x1A
    ctx->r20 = ADD32(0, 0X1A);
L_8037E818:
    // 0x8037E818: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8037E81C: lbu         $a1, 0x97($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X97);
    // 0x8037E820: jal         0x8013D268
    // 0x8037E824: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    LOOKUP_FUNC(0x8013D268)(rdram, ctx);
        goto after_9;
    // 0x8037E824: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    after_9:
    // 0x8037E828: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037E82C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8037E830: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037E834: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8037E838: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8037E83C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x8037E840: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8037E844: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037E848: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8037E84C: mflo        $s1
    ctx->r17 = lo;
    // 0x8037E850: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
    // 0x8037E854: addiu       $a2, $s1, 0x13
    ctx->r6 = ADD32(ctx->r17, 0X13);
    // 0x8037E858: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8037E85C: jal         0x8001B204
    // 0x8037E860: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x8037E860: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_10:
    // 0x8037E864: addiu       $t0, $s1, 0x24
    ctx->r8 = ADD32(ctx->r17, 0X24);
    // 0x8037E868: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8037E86C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8037E870: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8037E874: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8037E878: addiu       $t5, $zero, 0x209
    ctx->r13 = ADD32(0, 0X209);
    // 0x8037E87C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8037E880: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8037E884: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8037E888: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8037E88C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8037E890: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8037E894: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8037E898: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8037E89C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037E8A0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8037E8A4: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x8037E8A8: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    // 0x8037E8AC: jal         0x80146208
    // 0x8037E8B0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_11;
    // 0x8037E8B0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_11:
    // 0x8037E8B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037E8B8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8037E8BC: jal         0x80145348
    // 0x8037E8C0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_12;
    // 0x8037E8C0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_12:
    // 0x8037E8C4: lb          $v1, 0x91($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X91);
    // 0x8037E8C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8037E8CC: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8037E8D0: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8037E8D4: bne         $at, $zero, L_8037E818
    if (ctx->r1 != 0) {
        // 0x8037E8D8: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_8037E818;
    }
    // 0x8037E8D8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8037E8DC:
    // 0x8037E8DC: jal         0x80006214
    // 0x8037E8E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_13;
    // 0x8037E8E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x8037E8E4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8037E8E8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8037E8EC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8037E8F0: lw          $t0, -0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X4);
    // 0x8037E8F4: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x8037E8F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8037E8FC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8037E900: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8037E904: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8037E908: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8037E90C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8037E910: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8037E914: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8037E918: jr          $ra
    // 0x8037E91C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8037E91C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037e920(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037e920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E920: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8037E924: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8037E928: addiu       $s4, $sp, 0x6E
    ctx->r20 = ADD32(ctx->r29, 0X6E);
    // 0x8037E92C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8037E930: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8037E934: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8037E938: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x8037E93C: addiu       $t7, $zero, 0x82
    ctx->r15 = ADD32(0, 0X82);
    // 0x8037E940: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8037E944: addiu       $t9, $zero, 0x66
    ctx->r25 = ADD32(0, 0X66);
    // 0x8037E948: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8037E94C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8037E950: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8037E954: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8037E958: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8037E95C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8037E960: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8037E964: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037E968: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037E96C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037E970: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037E974: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037E978: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037E97C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8037E980: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8037E984: jal         0x80146178
    // 0x8037E988: addiu       $a3, $zero, 0x4B
    ctx->r7 = ADD32(0, 0X4B);
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_0;
    // 0x8037E988: addiu       $a3, $zero, 0x4B
    ctx->r7 = ADD32(0, 0X4B);
    after_0:
    // 0x8037E98C: lui         $s6, 0x8039
    ctx->r22 = S32(0X8039 << 16);
    // 0x8037E990: addiu       $s6, $s6, -0x660C
    ctx->r22 = ADD32(ctx->r22, -0X660C);
    // 0x8037E994: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8037E998: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037E99C: addiu       $s5, $zero, 0x1A
    ctx->r21 = ADD32(0, 0X1A);
L_8037E9A0:
    // 0x8037E9A0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8037E9A4: lbu         $a1, 0x97($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X97);
    // 0x8037E9A8: jal         0x8013D268
    // 0x8037E9AC: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    LOOKUP_FUNC(0x8013D268)(rdram, ctx);
        goto after_1;
    // 0x8037E9AC: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    after_1:
    // 0x8037E9B0: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037E9B4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8037E9B8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8037E9BC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8037E9C0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8037E9C4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x8037E9C8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8037E9CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037E9D0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8037E9D4: mflo        $s1
    ctx->r17 = lo;
    // 0x8037E9D8: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
    // 0x8037E9DC: addiu       $a2, $s1, 0x13
    ctx->r6 = ADD32(ctx->r17, 0X13);
    // 0x8037E9E0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8037E9E4: jal         0x8001B204
    // 0x8037E9E8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x8037E9E8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_2:
    // 0x8037E9EC: addiu       $t1, $s1, 0x24
    ctx->r9 = ADD32(ctx->r17, 0X24);
    // 0x8037E9F0: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8037E9F4: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8037E9F8: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8037E9FC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8037EA00: addiu       $t6, $zero, 0x209
    ctx->r14 = ADD32(0, 0X209);
    // 0x8037EA04: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8037EA08: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8037EA0C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8037EA10: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8037EA14: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8037EA18: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8037EA1C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8037EA20: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8037EA24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037EA28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037EA2C: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x8037EA30: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    // 0x8037EA34: jal         0x80146208
    // 0x8037EA38: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x8037EA38: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_3:
    // 0x8037EA3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037EA40: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8037EA44: jal         0x80145348
    // 0x8037EA48: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_4;
    // 0x8037EA48: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_4:
    // 0x8037EA4C: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x8037EA50: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8037EA54: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8037EA58: jal         0x8013D268
    // 0x8037EA5C: lbu         $a1, 0x97($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X97);
    LOOKUP_FUNC(0x8013D268)(rdram, ctx);
        goto after_5;
    // 0x8037EA5C: lbu         $a1, 0x97($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X97);
    after_5:
    // 0x8037EA60: beq         $v0, $zero, L_8037EA78
    if (ctx->r2 == 0) {
        // 0x8037EA64: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8037EA78;
    }
    // 0x8037EA64: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8037EA68: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8037EA6C: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x8037EA70: bne         $at, $zero, L_8037E9A0
    if (ctx->r1 != 0) {
        // 0x8037EA74: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_8037E9A0;
    }
    // 0x8037EA74: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8037EA78:
    // 0x8037EA78: jal         0x80006214
    // 0x8037EA7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x8037EA7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x8037EA80: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8037EA84: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8037EA88: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8037EA8C: lw          $t1, -0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, -0X4);
    // 0x8037EA90: sb          $zero, 0x22($t1)
    MEM_B(0X22, ctx->r9) = 0;
    // 0x8037EA94: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8037EA98: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8037EA9C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8037EAA0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8037EAA4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8037EAA8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8037EAAC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8037EAB0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8037EAB4: jr          $ra
    // 0x8037EAB8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8037EAB8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037eabc(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037eabc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EABC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037EAC0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8037EAC4: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8037EAC8: lw          $s0, -0x5640($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5640);
    // 0x8037EACC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037EAD0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8037EAD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037EAD8: sb          $t6, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r14;
    // 0x8037EADC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037EAE0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8037EAE4: addiu       $t9, $zero, 0x1A
    ctx->r25 = ADD32(0, 0X1A);
    // 0x8037EAE8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8037EAEC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8037EAF0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037EAF4: addiu       $a1, $zero, 0x180
    ctx->r5 = ADD32(0, 0X180);
    // 0x8037EAF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037EAFC: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x8037EB00: jal         0x801453CC
    // 0x8037EB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x8037EB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8037EB08: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8037EB0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EB10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037EB14: lb          $t1, 0x96($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X96);
    // 0x8037EB18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037EB1C: bnel        $t1, $zero, L_8037EB30
    if (ctx->r9 != 0) {
        // 0x8037EB20: lw          $s0, 0x10($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X10);
            goto L_8037EB30;
    }
    goto skip_0;
    // 0x8037EB20: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x8037EB24: jal         0x80145310
    // 0x8037EB28: sb          $zero, 0x22($s0)
    MEM_B(0X22, ctx->r16) = 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x8037EB28: sb          $zero, 0x22($s0)
    MEM_B(0X22, ctx->r16) = 0;
    after_1:
    // 0x8037EB2C: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
L_8037EB30:
    // 0x8037EB30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8037EB34: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8037EB38: sb          $t2, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r10;
    // 0x8037EB3C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8037EB40: addiu       $t5, $zero, 0x1A
    ctx->r13 = ADD32(0, 0X1A);
    // 0x8037EB44: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8037EB48: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037EB4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037EB50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037EB54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037EB58: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x8037EB5C: jal         0x801453CC
    // 0x8037EB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_2;
    // 0x8037EB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8037EB64: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8037EB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EB6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037EB70: lbu         $v0, 0x95($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X95);
    // 0x8037EB74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037EB78: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8037EB7C: bne         $at, $zero, L_8037EB94
    if (ctx->r1 != 0) {
        // 0x8037EB80: nop
    
            goto L_8037EB94;
    }
    // 0x8037EB80: nop

    // 0x8037EB84: lb          $t7, 0x96($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X96);
    // 0x8037EB88: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x8037EB8C: bnel        $t8, $v0, L_8037EBA0
    if (ctx->r24 != ctx->r2) {
        // 0x8037EB90: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8037EBA0;
    }
    goto skip_1;
    // 0x8037EB90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_8037EB94:
    // 0x8037EB94: jal         0x80145310
    // 0x8037EB98: sb          $zero, 0x22($s0)
    MEM_B(0X22, ctx->r16) = 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_3;
    // 0x8037EB98: sb          $zero, 0x22($s0)
    MEM_B(0X22, ctx->r16) = 0;
    after_3:
    // 0x8037EB9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8037EBA0:
    // 0x8037EBA0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8037EBA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8037EBA8: jr          $ra
    // 0x8037EBAC: nop

    return;
    // 0x8037EBAC: nop

;}
RECOMP_FUNC void M55_FUN_8037ebb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EBB0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8037EBB4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8037EBB8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8037EBBC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8037EBC0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8037EBC4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8037EBC8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8037EBCC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8037EBD0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037EBD4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8037EBD8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8037EBDC: lui         $s7, 0x8039
    ctx->r23 = S32(0X8039 << 16);
    // 0x8037EBE0: lui         $fp, 0x8018
    ctx->r30 = S32(0X8018 << 16);
    // 0x8037EBE4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8037EBE8: addiu       $s2, $zero, 0x46
    ctx->r18 = ADD32(0, 0X46);
    // 0x8037EBEC: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8037EBF0: addiu       $fp, $fp, 0x4140
    ctx->r30 = ADD32(ctx->r30, 0X4140);
    // 0x8037EBF4: addiu       $s7, $s7, -0x56A0
    ctx->r23 = ADD32(ctx->r23, -0X56A0);
    // 0x8037EBF8: lbu         $s4, 0x96($a0)
    ctx->r20 = MEM_BU(ctx->r4, 0X96);
    // 0x8037EBFC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8037EC00: addiu       $s5, $sp, 0x60
    ctx->r21 = ADD32(ctx->r29, 0X60);
L_8037EC04:
    // 0x8037EC04: addu        $t6, $s7, $s4
    ctx->r14 = ADD32(ctx->r23, ctx->r20);
    // 0x8037EC08: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x8037EC0C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8037EC10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037EC14: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x8037EC18: beq         $at, $zero, L_8037EC94
    if (ctx->r1 == 0) {
        // 0x8037EC1C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8037EC94;
    }
    // 0x8037EC1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037EC20: bne         $s6, $zero, L_8037EC94
    if (ctx->r22 != 0) {
        // 0x8037EC24: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8037EC94;
    }
    // 0x8037EC24: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8037EC28: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8037EC2C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8037EC30: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8037EC34: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x8037EC38: addu        $s1, $s1, $t9
    ctx->r17 = ADD32(ctx->r17, ctx->r25);
    // 0x8037EC3C: lbu         $s1, 0x3CE3($s1)
    ctx->r17 = MEM_BU(ctx->r17, 0X3CE3);
    // 0x8037EC40: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8037EC44: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8037EC48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8037EC4C: jal         0x8037D418
    // 0x8037EC50: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8037D418)(rdram, ctx);
        goto after_0;
    // 0x8037EC50: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_0:
    // 0x8037EC54: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8037EC58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037EC5C: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x8037EC60: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037EC64: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8037EC68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8037EC6C: addiu       $a3, $a3, -0x6604
    ctx->r7 = ADD32(ctx->r7, -0X6604);
    // 0x8037EC70: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8037EC74: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037EC78: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x8037EC7C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037EC80: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8037EC84: jal         0x8001B204
    // 0x8037EC88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8037EC88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_1:
    // 0x8037EC8C: b           L_8037ECB0
    // 0x8037EC90: addiu       $s2, $s2, 0xD
    ctx->r18 = ADD32(ctx->r18, 0XD);
        goto L_8037ECB0;
    // 0x8037EC90: addiu       $s2, $s2, 0xD
    ctx->r18 = ADD32(ctx->r18, 0XD);
L_8037EC94:
    // 0x8037EC94: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037EC98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037EC9C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8037ECA0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037ECA4: jal         0x8001B204
    // 0x8037ECA8: addiu       $a3, $a3, -0x65F8
    ctx->r7 = ADD32(ctx->r7, -0X65F8);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x8037ECA8: addiu       $a3, $a3, -0x65F8
    ctx->r7 = ADD32(ctx->r7, -0X65F8);
    after_2:
    // 0x8037ECAC: addiu       $s2, $s2, 0xD
    ctx->r18 = ADD32(ctx->r18, 0XD);
L_8037ECB0:
    // 0x8037ECB0: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8037ECB4: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
    // 0x8037ECB8: beq         $at, $zero, L_8037ECD8
    if (ctx->r1 == 0) {
        // 0x8037ECBC: sra         $s2, $s2, 16
        ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
            goto L_8037ECD8;
    }
    // 0x8037ECBC: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8037ECC0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8037ECC4: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x8037ECC8: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8037ECCC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8037ECD0: bne         $at, $zero, L_8037EC04
    if (ctx->r1 != 0) {
        // 0x8037ECD4: andi        $s4, $s4, 0xFF
        ctx->r20 = ctx->r20 & 0XFF;
            goto L_8037EC04;
    }
    // 0x8037ECD4: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
L_8037ECD8:
    // 0x8037ECD8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8037ECDC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8037ECE0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8037ECE4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8037ECE8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8037ECEC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8037ECF0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8037ECF4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8037ECF8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8037ECFC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8037ED00: jr          $ra
    // 0x8037ED04: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8037ED04: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037ed08(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037ed08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037ED08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037ED0C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037ED10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037ED14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037ED18: addiu       $t6, $t6, -0x7328
    ctx->r14 = ADD32(ctx->r14, -0X7328);
    // 0x8037ED1C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8037ED20: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x8037ED24: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037ED28: addiu       $t9, $t9, -0x7324
    ctx->r25 = ADD32(ctx->r25, -0X7324);
    // 0x8037ED2C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8037ED30: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8037ED34: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x8037ED38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037ED3C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8037ED40: lb          $a2, 0x97($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X97);
    // 0x8037ED44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037ED48: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8037ED4C: addu        $t3, $a3, $a2
    ctx->r11 = ADD32(ctx->r7, ctx->r6);
    // 0x8037ED50: addu        $t4, $t0, $a2
    ctx->r12 = ADD32(ctx->r8, ctx->r6);
    // 0x8037ED54: lbu         $a1, 0x0($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X0);
    // 0x8037ED58: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x8037ED5C: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037ED60: addiu       $a3, $a3, -0x56A0
    ctx->r7 = ADD32(ctx->r7, -0X56A0);
    // 0x8037ED64: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8037ED68: beq         $at, $zero, L_8037EDC0
    if (ctx->r1 == 0) {
        // 0x8037ED6C: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_8037EDC0;
    }
    // 0x8037ED6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8037ED70: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8037ED74: addiu       $a0, $a0, 0x3CE0
    ctx->r4 = ADD32(ctx->r4, 0X3CE0);
L_8037ED78:
    // 0x8037ED78: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037ED7C: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x8037ED80: mflo        $t5
    ctx->r13 = lo;
    // 0x8037ED84: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8037ED88: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8037ED8C: beql        $t7, $zero, L_8037EDB0
    if (ctx->r15 == 0) {
        // 0x8037ED90: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037EDB0;
    }
    goto skip_0;
    // 0x8037ED90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8037ED94: sb          $v0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r2;
    // 0x8037ED98: lb          $t9, 0x97($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X97);
    // 0x8037ED9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037EDA0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8037EDA4: addu        $a1, $sp, $t9
    ctx->r5 = ADD32(ctx->r29, ctx->r25);
    // 0x8037EDA8: lbu         $a1, 0x30($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X30);
    // 0x8037EDAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8037EDB0:
    // 0x8037EDB0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8037EDB4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8037EDB8: bne         $at, $zero, L_8037ED78
    if (ctx->r1 != 0) {
        // 0x8037EDBC: nop
    
            goto L_8037ED78;
    }
    // 0x8037EDBC: nop

L_8037EDC0:
    // 0x8037EDC0: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037EDC4: addiu       $a3, $a3, -0x56A0
    ctx->r7 = ADD32(ctx->r7, -0X56A0);
    // 0x8037EDC8: addu        $t2, $a3, $v1
    ctx->r10 = ADD32(ctx->r7, ctx->r3);
    // 0x8037EDCC: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x8037EDD0: sb          $zero, 0x96($s0)
    MEM_B(0X96, ctx->r16) = 0;
    // 0x8037EDD4: sb          $v1, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r3;
    // 0x8037EDD8: jal         0x8037EBB0
    // 0x8037EDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037EBB0)(rdram, ctx);
        goto after_0;
    // 0x8037EDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8037EDE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037EDE4: lbu         $v0, 0x2E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2E);
    // 0x8037EDE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037EDEC: jr          $ra
    // 0x8037EDF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037EDF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037edf4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037edf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EDF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037EDF8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8037EDFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037EE00: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8037EE04: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8037EE08: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8037EE0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8037EE10: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8037EE14: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8037EE18: lui         $s6, 0x8039
    ctx->r22 = S32(0X8039 << 16);
    // 0x8037EE1C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8037EE20: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8037EE24: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037EE28: lw          $s0, -0x5638($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5638);
    // 0x8037EE2C: addiu       $s6, $s6, -0x56B0
    ctx->r22 = ADD32(ctx->r22, -0X56B0);
    // 0x8037EE30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8037EE34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8037EE38: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8037EE3C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_8037EE40:
    // 0x8037EE40: addu        $s1, $s6, $s2
    ctx->r17 = ADD32(ctx->r22, ctx->r18);
    // 0x8037EE44: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x8037EE48: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8037EE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EE50: bne         $s5, $t6, L_8037EE6C
    if (ctx->r21 != ctx->r14) {
        // 0x8037EE54: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8037EE6C;
    }
    // 0x8037EE54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037EE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EE5C: jal         0x80145310
    // 0x8037EE60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x8037EE60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8037EE64: b           L_8037EE78
    // 0x8037EE68: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
        goto L_8037EE78;
    // 0x8037EE68: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
L_8037EE6C:
    // 0x8037EE6C: jal         0x80145310
    // 0x8037EE70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x8037EE70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8037EE74: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
L_8037EE78:
    // 0x8037EE78: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x8037EE7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8037EE80: bne         $s7, $t7, L_8037EEA0
    if (ctx->r23 != ctx->r15) {
        // 0x8037EE84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037EEA0;
    }
    // 0x8037EE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EE8C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8037EE90: jal         0x80145310
    // 0x8037EE94: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_2;
    // 0x8037EE94: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_2:
    // 0x8037EE98: b           L_8037EEAC
    // 0x8037EE9C: lb          $t8, 0x96($s4)
    ctx->r24 = MEM_B(ctx->r20, 0X96);
        goto L_8037EEAC;
    // 0x8037EE9C: lb          $t8, 0x96($s4)
    ctx->r24 = MEM_B(ctx->r20, 0X96);
L_8037EEA0:
    // 0x8037EEA0: jal         0x80145310
    // 0x8037EEA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_3;
    // 0x8037EEA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8037EEA8: lb          $t8, 0x96($s4)
    ctx->r24 = MEM_B(ctx->r20, 0X96);
L_8037EEAC:
    // 0x8037EEAC: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x8037EEB0: addiu       $v1, $zero, 0x6E
    ctx->r3 = ADD32(0, 0X6E);
    // 0x8037EEB4: bne         $s3, $t8, L_8037EEC4
    if (ctx->r19 != ctx->r24) {
        // 0x8037EEB8: nop
    
            goto L_8037EEC4;
    }
    // 0x8037EEB8: nop

    // 0x8037EEBC: b           L_8037EEC4
    // 0x8037EEC0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_8037EEC4;
    // 0x8037EEC0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8037EEC4:
    // 0x8037EEC4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8037EEC8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8037EECC: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8037EED0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8037EED4: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x8037EED8: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8037EEDC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8037EEE0: sb          $v1, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r3;
    // 0x8037EEE4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8037EEE8: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x8037EEEC: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x8037EEF0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8037EEF4: lbu         $t4, 0xB($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XB);
    // 0x8037EEF8: bne         $at, $zero, L_8037EE40
    if (ctx->r1 != 0) {
        // 0x8037EEFC: sb          $t4, 0xB($t5)
        MEM_B(0XB, ctx->r13) = ctx->r12;
            goto L_8037EE40;
    }
    // 0x8037EEFC: sb          $t4, 0xB($t5)
    MEM_B(0XB, ctx->r13) = ctx->r12;
    // 0x8037EF00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8037EF04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037EF08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037EF0C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8037EF10: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8037EF14: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8037EF18: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8037EF1C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8037EF20: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8037EF24: jr          $ra
    // 0x8037EF28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037EF28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037ef2c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037ef2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EF2C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8037EF30: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8037EF34: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8037EF38: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8037EF3C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8037EF40: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8037EF44: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8037EF48: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037EF4C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8037EF50: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8037EF54: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8037EF58: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8037EF5C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8037EF60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037EF64: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8037EF68: addiu       $fp, $zero, 0x14
    ctx->r30 = ADD32(0, 0X14);
L_8037EF6C:
    // 0x8037EF6C: lb          $t6, 0x96($s7)
    ctx->r14 = MEM_B(ctx->r23, 0X96);
    // 0x8037EF70: addiu       $s5, $zero, 0x6E
    ctx->r21 = ADD32(0, 0X6E);
    // 0x8037EF74: addiu       $s6, $zero, 0x6E
    ctx->r22 = ADD32(0, 0X6E);
    // 0x8037EF78: bne         $s1, $t6, L_8037EF88
    if (ctx->r17 != ctx->r14) {
        // 0x8037EF7C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_8037EF88;
    }
    // 0x8037EF7C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8037EF80: b           L_8037EF8C
    // 0x8037EF84: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8037EF8C;
    // 0x8037EF84: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8037EF88:
    // 0x8037EF88: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
L_8037EF8C:
    // 0x8037EF8C: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037EF90: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8037EF94: subu        $t7, $t7, $s4
    ctx->r15 = SUB32(ctx->r15, ctx->r20);
    // 0x8037EF98: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037EF9C: addiu       $t8, $t8, -0x73E8
    ctx->r24 = ADD32(ctx->r24, -0X73E8);
    // 0x8037EFA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8037EFA4: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x8037EFA8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8037EFAC: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037EFB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037EFB4: mflo        $s3
    ctx->r19 = lo;
    // 0x8037EFB8: addiu       $s3, $s3, 0x46
    ctx->r19 = ADD32(ctx->r19, 0X46);
    // 0x8037EFBC: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x8037EFC0: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8037EFC4: sll         $a2, $s3, 16
    ctx->r6 = S32(ctx->r19 << 16);
    // 0x8037EFC8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8037EFCC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037EFD0: addiu       $a3, $a3, -0x65F4
    ctx->r7 = ADD32(ctx->r7, -0X65F4);
    // 0x8037EFD4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x8037EFD8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8037EFDC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037EFE0: jal         0x8001B204
    // 0x8037EFE4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x8037EFE4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x8037EFE8: lb          $t0, 0x96($s7)
    ctx->r8 = MEM_B(ctx->r23, 0X96);
    // 0x8037EFEC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8037EFF0: addiu       $a1, $zero, 0x49C
    ctx->r5 = ADD32(0, 0X49C);
    // 0x8037EFF4: bne         $s1, $t0, L_8037F028
    if (ctx->r17 != ctx->r8) {
        // 0x8037EFF8: sll         $a2, $s3, 16
        ctx->r6 = S32(ctx->r19 << 16);
            goto L_8037F028;
    }
    // 0x8037EFF8: sll         $a2, $s3, 16
    ctx->r6 = S32(ctx->r19 << 16);
    // 0x8037EFFC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037F000: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8037F004: lbu         $v0, -0x56B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56B0);
    // 0x8037F008: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037F00C: bnel        $v0, $at, L_8037F01C
    if (ctx->r2 != ctx->r1) {
        // 0x8037F010: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8037F01C;
    }
    goto skip_0;
    // 0x8037F010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8037F014: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8037F018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8037F01C:
    // 0x8037F01C: bnel        $v0, $at, L_8037F02C
    if (ctx->r2 != ctx->r1) {
        // 0x8037F020: lw          $t1, 0x4($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X4);
            goto L_8037F02C;
    }
    goto skip_1;
    // 0x8037F020: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    skip_1:
    // 0x8037F024: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
L_8037F028:
    // 0x8037F028: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
L_8037F02C:
    // 0x8037F02C: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037F030: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037F034: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037F038: addiu       $a3, $a3, -0x65EC
    ctx->r7 = ADD32(ctx->r7, -0X65EC);
    // 0x8037F03C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8037F040: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x8037F044: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037F048: jal         0x8001B204
    // 0x8037F04C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8037F04C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_1:
    // 0x8037F050: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    // 0x8037F054: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8037F058: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037F05C: sll         $a2, $s3, 16
    ctx->r6 = S32(ctx->r19 << 16);
    // 0x8037F060: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037F064: addiu       $a3, $a3, -0x65E4
    ctx->r7 = ADD32(ctx->r7, -0X65E4);
    // 0x8037F068: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8037F06C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037F070: addiu       $a1, $zero, 0x4E2
    ctx->r5 = ADD32(0, 0X4E2);
    // 0x8037F074: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x8037F078: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037F07C: jal         0x8001B204
    // 0x8037F080: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x8037F080: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_2:
    // 0x8037F084: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8037F088: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x8037F08C: slti        $at, $s4, 0x6
    ctx->r1 = SIGNED(ctx->r20) < 0X6 ? 1 : 0;
    // 0x8037F090: bne         $at, $zero, L_8037EF6C
    if (ctx->r1 != 0) {
        // 0x8037F094: or          $s1, $s4, $zero
        ctx->r17 = ctx->r20 | 0;
            goto L_8037EF6C;
    }
    // 0x8037F094: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x8037F098: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8037F09C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8037F0A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8037F0A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8037F0A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8037F0AC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8037F0B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8037F0B4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8037F0B8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8037F0BC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8037F0C0: jr          $ra
    // 0x8037F0C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8037F0C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f0c8(rdram, ctx);
;}
