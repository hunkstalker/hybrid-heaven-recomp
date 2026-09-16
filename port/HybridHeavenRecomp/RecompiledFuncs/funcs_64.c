#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801eb49c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB49C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EB4A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EB4A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EB4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EB4AC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB4B0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801EB4B4: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    // 0x801EB4B8: jal         0x80005E44
    // 0x801EB4BC: addiu       $a1, $a1, -0x27D0
    ctx->r5 = ADD32(ctx->r5, -0X27D0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801EB4BC: addiu       $a1, $a1, -0x27D0
    ctx->r5 = ADD32(ctx->r5, -0X27D0);
    after_0:
    // 0x801EB4C0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801EB4C4: jal         0x80006214
    // 0x801EB4C8: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801EB4C8: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    after_1:
    // 0x801EB4CC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801EB4D0: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    // 0x801EB4D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EB4D8: addiu       $a2, $zero, 0x260
    ctx->r6 = ADD32(0, 0X260);
    // 0x801EB4DC: jal         0x8012C89C
    // 0x801EB4E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801EB4E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801EB4E4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801EB4E8: addiu       $v1, $v1, -0x27AC
    ctx->r3 = ADD32(ctx->r3, -0X27AC);
    // 0x801EB4EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EB4F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801EB4F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EB4F8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EB4FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EB500: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801EB504: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EB508: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801EB50C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EB510: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801EB514: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EB518: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801EB51C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EB520: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801EB524: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EB528: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801EB52C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801EB530: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801EB534: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EB538: swc1        $f2, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f2.u32l;
    // 0x801EB53C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EB540: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801EB544: addiu       $t7, $t7, -0x5168
    ctx->r15 = ADD32(ctx->r15, -0X5168);
    // 0x801EB548: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801EB54C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EB550: swc1        $f2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f2.u32l;
    // 0x801EB554: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801EB558: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801EB55C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EB560: swc1        $f2, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f2.u32l;
    // 0x801EB564: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EB568: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801EB56C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EB570: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    // 0x801EB574: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EB578: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801EB57C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EB580: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
    // 0x801EB584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EB588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EB58C: jr          $ra
    // 0x801EB590: nop

    return;
    // 0x801EB590: nop

;}
RECOMP_FUNC void M25_FUN_801eb594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB594: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EB598: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EB59C: jr          $ra
    // 0x801EB5A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801EB5A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eb5a4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eb5a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB5A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EB5A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EB5AC: jr          $ra
    // 0x801EB5B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801EB5B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eb5b4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eb5b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB5B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EB5B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EB5BC: jr          $ra
    // 0x801EB5C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801EB5C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eb5c4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eb5c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB5C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EB5C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EB5CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EB5D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EB5D4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB5D8: addiu       $a1, $a1, -0x2270
    ctx->r5 = ADD32(ctx->r5, -0X2270);
    // 0x801EB5DC: jal         0x801C2420
    // 0x801EB5E0: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801EB5E0: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    after_0:
    // 0x801EB5E4: jal         0x8038BA70
    // 0x801EB5E8: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_1;
    // 0x801EB5E8: nop

    after_1:
    // 0x801EB5EC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB5F0: addiu       $a1, $a1, -0x2258
    ctx->r5 = ADD32(ctx->r5, -0X2258);
    // 0x801EB5F4: jal         0x801C2420
    // 0x801EB5F8: addiu       $a0, $zero, 0x261
    ctx->r4 = ADD32(0, 0X261);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_2;
    // 0x801EB5F8: addiu       $a0, $zero, 0x261
    ctx->r4 = ADD32(0, 0X261);
    after_2:
    // 0x801EB5FC: jal         0x8038BA70
    // 0x801EB600: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_3;
    // 0x801EB600: nop

    after_3:
    // 0x801EB604: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB608: addiu       $a1, $a1, -0x2240
    ctx->r5 = ADD32(ctx->r5, -0X2240);
    // 0x801EB60C: jal         0x801C2420
    // 0x801EB610: addiu       $a0, $zero, 0x262
    ctx->r4 = ADD32(0, 0X262);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_4;
    // 0x801EB610: addiu       $a0, $zero, 0x262
    ctx->r4 = ADD32(0, 0X262);
    after_4:
    // 0x801EB614: jal         0x8038BA70
    // 0x801EB618: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_5;
    // 0x801EB618: nop

    after_5:
    // 0x801EB61C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB620: addiu       $a1, $a1, -0x2228
    ctx->r5 = ADD32(ctx->r5, -0X2228);
    // 0x801EB624: jal         0x801C2420
    // 0x801EB628: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_6;
    // 0x801EB628: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_6:
    // 0x801EB62C: jal         0x8038BA70
    // 0x801EB630: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_7;
    // 0x801EB630: nop

    after_7:
    // 0x801EB634: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB638: addiu       $a1, $a1, -0x2210
    ctx->r5 = ADD32(ctx->r5, -0X2210);
    // 0x801EB63C: jal         0x801C2420
    // 0x801EB640: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_8;
    // 0x801EB640: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x801EB644: jal         0x8038BA70
    // 0x801EB648: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_9;
    // 0x801EB648: nop

    after_9:
    // 0x801EB64C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB650: addiu       $a1, $a1, -0x2090
    ctx->r5 = ADD32(ctx->r5, -0X2090);
    // 0x801EB654: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x801EB658: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801EB65C: jal         0x801C2570
    // 0x801EB660: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    LOOKUP_FUNC(0x801C2570)(rdram, ctx);
        goto after_10;
    // 0x801EB660: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    after_10:
    // 0x801EB664: beql        $v0, $zero, L_801EB678
    if (ctx->r2 == 0) {
        // 0x801EB668: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EB678;
    }
    goto skip_0;
    // 0x801EB668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801EB66C: jal         0x8038BA8C
    // 0x801EB670: nop

    LOOKUP_FUNC(0x8038BA8C)(rdram, ctx);
        goto after_11;
    // 0x801EB670: nop

    after_11:
    // 0x801EB674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801EB678:
    // 0x801EB678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EB67C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801EB680: jr          $ra
    // 0x801EB684: nop

    return;
    // 0x801EB684: nop

;}
RECOMP_FUNC void M25_FUN_801eb688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801EB68C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801EB690: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801EB694: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801EB698: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801EB69C: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x801EB6A0: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x801EB6A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801EB6A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801EB6AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801EB6B0: addiu       $s3, $s3, -0x2774
    ctx->r19 = ADD32(ctx->r19, -0X2774);
    // 0x801EB6B4: addiu       $s1, $s1, -0x2734
    ctx->r17 = ADD32(ctx->r17, -0X2734);
    // 0x801EB6B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801EB6BC: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x801EB6C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_801EB6C4:
    // 0x801EB6C4: jal         0x80005E44
    // 0x801EB6C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801EB6C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x801EB6CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801EB6D0: bnel        $s0, $s2, L_801EB6C4
    if (ctx->r16 != ctx->r18) {
        // 0x801EB6D4: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_801EB6C4;
    }
    goto skip_0;
    // 0x801EB6D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x801EB6D8: jal         0x80006214
    // 0x801EB6DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801EB6DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x801EB6E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801EB6E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_801EB6E8:
    // 0x801EB6E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801EB6EC: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x801EB6F0: jal         0x8012C89C
    // 0x801EB6F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801EB6F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801EB6F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801EB6FC: bnel        $s0, $s2, L_801EB6E8
    if (ctx->r16 != ctx->r18) {
        // 0x801EB700: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_801EB6E8;
    }
    goto skip_1;
    // 0x801EB700: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x801EB704: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801EB708: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801EB70C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801EB710: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EB714: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EB718: lui         $at, 0xC24C
    ctx->r1 = S32(0XC24C << 16);
    // 0x801EB71C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801EB720: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EB724: lui         $at, 0x433B
    ctx->r1 = S32(0X433B << 16);
    // 0x801EB728: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801EB72C: lui         $at, 0x43BB
    ctx->r1 = S32(0X43BB << 16);
    // 0x801EB730: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EB734: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EB738: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x801EB73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EB740: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x801EB744: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EB748: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x801EB74C: sub.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x801EB750: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801EB754: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801EB758: swc1        $f2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f2.u32l;
    // 0x801EB75C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EB760: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801EB764: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801EB768: swc1        $f12, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f12.u32l;
    // 0x801EB76C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801EB770: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801EB774: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EB778: sh          $a0, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r4;
    // 0x801EB77C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EB780: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801EB784: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801EB788: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801EB78C: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x801EB790: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EB794: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x801EB798: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801EB79C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801EB7A0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801EB7A4: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    // 0x801EB7A8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EB7AC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801EB7B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801EB7B4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801EB7B8: swc1        $f12, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f12.u32l;
    // 0x801EB7BC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801EB7C0: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801EB7C4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801EB7C8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801EB7CC: sh          $a0, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r4;
    // 0x801EB7D0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EB7D4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801EB7D8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801EB7DC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EB7E0: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801EB7E4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EB7E8: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x801EB7EC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801EB7F0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801EB7F4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801EB7F8: swc1        $f2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f2.u32l;
    // 0x801EB7FC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EB800: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801EB804: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801EB808: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801EB80C: swc1        $f12, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f12.u32l;
    // 0x801EB810: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EB814: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801EB818: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801EB81C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801EB820: sh          $a0, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r4;
    // 0x801EB824: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801EB828: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801EB82C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EB830: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801EB834: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    // 0x801EB838: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EB83C: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x801EB840: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801EB844: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EB848: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EB84C: swc1        $f2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f2.u32l;
    // 0x801EB850: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EB854: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801EB858: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EB85C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801EB860: swc1        $f12, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f12.u32l;
    // 0x801EB864: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EB868: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801EB86C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EB870: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801EB874: sh          $a0, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r4;
    // 0x801EB878: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EB87C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801EB880: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801EB884: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801EB888: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x801EB88C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801EB890: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x801EB894: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801EB898: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801EB89C: swc1        $f2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f2.u32l;
    // 0x801EB8A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EB8A4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801EB8A8: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801EB8AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EB8B0: swc1        $f12, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f12.u32l;
    // 0x801EB8B4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EB8B8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801EB8BC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801EB8C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801EB8C4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801EB8C8: sh          $a0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r4;
    // 0x801EB8CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801EB8D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801EB8D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801EB8D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801EB8DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801EB8E0: jr          $ra
    // 0x801EB8E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801EB8E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eb8e8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eb8e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB8E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EB8EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EB8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EB8F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EB8F8: lui         $a1, 0x53
    ctx->r5 = S32(0X53 << 16);
    // 0x801EB8FC: ori         $a1, $a1, 0xEC60
    ctx->r5 = ctx->r5 | 0XEC60;
    // 0x801EB900: jal         0x801C0B8C
    // 0x801EB904: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EB904: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EB908: beq         $v0, $zero, L_801EB9C0
    if (ctx->r2 == 0) {
        // 0x801EB90C: lui         $a1, 0x8039
        ctx->r5 = S32(0X8039 << 16);
            goto L_801EB9C0;
    }
    // 0x801EB90C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB910: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    // 0x801EB914: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801EB918: lui         $at, 0xC3BB
    ctx->r1 = S32(0XC3BB << 16);
    // 0x801EB91C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801EB920: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EB924: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EB92C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EB930: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x801EB934: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801EB938: swc1        $f12, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f12.u32l;
    // 0x801EB93C: sw          $zero, -0x2BD8($at)
    MEM_W(-0X2BD8, ctx->r1) = 0;
    // 0x801EB940: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801EB944: addiu       $t3, $t3, -0x2BD8
    ctx->r11 = ADD32(ctx->r11, -0X2BD8);
    // 0x801EB948: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x801EB94C: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x801EB950: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801EB954: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801EB958: swc1        $f12, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f12.u32l;
    // 0x801EB95C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x801EB960: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801EB964: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801EB968: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801EB96C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EB970: swc1        $f12, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f12.u32l;
    // 0x801EB974: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801EB978: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801EB97C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801EB980: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EB984: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801EB988: swc1        $f12, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f12.u32l;
    // 0x801EB98C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801EB990: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801EB994: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801EB998: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x801EB99C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801EB9A0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801EB9A4: swc1        $f12, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f12.u32l;
    // 0x801EB9A8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801EB9AC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801EB9B0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EB9B4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EB9B8: b           L_801EBAC8
    // 0x801EB9BC: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
        goto L_801EBAC8;
    // 0x801EB9BC: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
L_801EB9C0:
    // 0x801EB9C0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB9C4: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    // 0x801EB9C8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801EB9CC: lui         $at, 0x43BB
    ctx->r1 = S32(0X43BB << 16);
    // 0x801EB9D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801EB9D4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801EB9D8: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801EB9DC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EB9E0: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x801EB9E4: nop

    // 0x801EB9E8: bc1f        L_801EBA0C
    if (!c1cs) {
        // 0x801EB9EC: lui         $at, 0xC3BB
        ctx->r1 = S32(0XC3BB << 16);
            goto L_801EBA0C;
    }
    // 0x801EB9EC: lui         $at, 0xC3BB
    ctx->r1 = S32(0XC3BB << 16);
    // 0x801EB9F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801EB9F4: nop

    // 0x801EB9F8: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x801EB9FC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x801EBA00: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801EBA04: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801EBA08: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_801EBA0C:
    // 0x801EBA0C: lui         $at, 0xC3BB
    ctx->r1 = S32(0XC3BB << 16);
    // 0x801EBA10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801EBA14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBA18: lwc1        $f16, -0x37D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X37D0);
    // 0x801EBA1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EBA20: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801EBA24: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801EBA28: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x801EBA2C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_801EBA30:
    // 0x801EBA30: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x801EBA34: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x801EBA38: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801EBA3C: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801EBA40: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBA44: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x801EBA48: nop

    // 0x801EBA4C: bc1fl       L_801EBA70
    if (!c1cs) {
        // 0x801EBA50: add.s       $f6, $f0, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f16.fl;
            goto L_801EBA70;
    }
    goto skip_0;
    // 0x801EBA50: add.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f16.fl;
    skip_0:
    // 0x801EBA54: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x801EBA58: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801EBA5C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x801EBA60: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801EBA64: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801EBA68: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBA6C: add.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f16.fl;
L_801EBA70:
    // 0x801EBA70: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801EBA74: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801EBA78: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x801EBA7C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801EBA80: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801EBA84: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801EBA88: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x801EBA8C: nop

    // 0x801EBA90: bc1fl       L_801EBAB4
    if (!c1cs) {
        // 0x801EBA94: add.s       $f8, $f2, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f16.fl;
            goto L_801EBAB4;
    }
    goto skip_1;
    // 0x801EBA94: add.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f16.fl;
    skip_1:
    // 0x801EBA98: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x801EBA9C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801EBAA0: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x801EBAA4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801EBAA8: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x801EBAAC: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801EBAB0: add.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f16.fl;
L_801EBAB4:
    // 0x801EBAB4: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x801EBAB8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x801EBABC: bne         $a2, $a3, L_801EBA30
    if (ctx->r6 != ctx->r7) {
        // 0x801EBAC0: swc1        $f8, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
            goto L_801EBA30;
    }
    // 0x801EBAC0: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x801EBAC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EBAC8:
    // 0x801EBAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EBACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EBAD0: jr          $ra
    // 0x801EBAD4: nop

    return;
    // 0x801EBAD4: nop

;}
RECOMP_FUNC void M25_FUN_801ebad8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EBAD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EBADC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EBAE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EBAE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EBAE8: lui         $a1, 0x129
    ctx->r5 = S32(0X129 << 16);
    // 0x801EBAEC: ori         $a1, $a1, 0x8BE0
    ctx->r5 = ctx->r5 | 0X8BE0;
    // 0x801EBAF0: jal         0x801C0B8C
    // 0x801EBAF4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EBAF4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EBAF8: beq         $v0, $zero, L_801EBC68
    if (ctx->r2 == 0) {
        // 0x801EBAFC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801EBC68;
    }
    // 0x801EBAFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EBB00: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x801EBB04: addiu       $a3, $a3, -0x2730
    ctx->r7 = ADD32(ctx->r7, -0X2730);
    // 0x801EBB08: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x801EBB0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBB10: lwc1        $f12, -0x37CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X37CC);
    // 0x801EBB14: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EBB18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EBB1C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBB20: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801EBB24: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x801EBB28: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801EBB2C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBB30: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801EBB34: nop

    // 0x801EBB38: bc1f        L_801EBB5C
    if (!c1cs) {
        // 0x801EBB3C: nop
    
            goto L_801EBB5C;
    }
    // 0x801EBB3C: nop

    // 0x801EBB40: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EBB44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EBB48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBB4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EBB50: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x801EBB54: b           L_801EBB70
    // 0x801EBB58: lwc1        $f14, -0x37C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37C8);
        goto L_801EBB70;
    // 0x801EBB58: lwc1        $f14, -0x37C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37C8);
L_801EBB5C:
    // 0x801EBB5C: lwc1        $f14, -0x37C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37C4);
    // 0x801EBB60: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EBB64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EBB68: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x801EBB6C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_801EBB70:
    // 0x801EBB70: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_801EBB74:
    // 0x801EBB74: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801EBB78: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x801EBB7C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801EBB80: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBB84: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801EBB88: nop

    // 0x801EBB8C: bc1fl       L_801EBBA4
    if (!c1cs) {
        // 0x801EBB90: add.s       $f6, $f0, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_801EBBA4;
    }
    goto skip_0;
    // 0x801EBB90: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    skip_0:
    // 0x801EBB94: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x801EBB98: b           L_801EBBA8
    // 0x801EBB9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_801EBBA8;
    // 0x801EBB9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801EBBA0: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
L_801EBBA4:
    // 0x801EBBA4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_801EBBA8:
    // 0x801EBBA8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801EBBAC: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x801EBBB0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801EBBB4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801EBBB8: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801EBBBC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBBC0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801EBBC4: nop

    // 0x801EBBC8: bc1fl       L_801EBBE0
    if (!c1cs) {
        // 0x801EBBCC: add.s       $f8, $f0, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_801EBBE0;
    }
    goto skip_1;
    // 0x801EBBCC: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    skip_1:
    // 0x801EBBD0: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x801EBBD4: b           L_801EBBE4
    // 0x801EBBD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_801EBBE4;
    // 0x801EBBD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801EBBDC: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
L_801EBBE0:
    // 0x801EBBE0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_801EBBE4:
    // 0x801EBBE4: bnel        $v1, $a1, L_801EBB74
    if (ctx->r3 != ctx->r5) {
        // 0x801EBBE8: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_801EBB74;
    }
    goto skip_2;
    // 0x801EBBE8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x801EBBEC: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x801EBBF0: bnel        $at, $zero, L_801EBD6C
    if (ctx->r1 != 0) {
        // 0x801EBBF4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801EBD6C;
    }
    goto skip_3;
    // 0x801EBBF4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_3:
    // 0x801EBBF8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x801EBBFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801EBC00: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801EBC04: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801EBC08: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x801EBC0C: swc1        $f2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f2.u32l;
    // 0x801EBC10: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801EBC14: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x801EBC18: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EBC1C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EBC20: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
    // 0x801EBC24: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801EBC28: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x801EBC2C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801EBC30: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801EBC34: swc1        $f2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f2.u32l;
    // 0x801EBC38: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x801EBC3C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801EBC40: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EBC44: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x801EBC48: swc1        $f2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f2.u32l;
    // 0x801EBC4C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801EBC50: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x801EBC54: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801EBC58: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EBC5C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EBC60: b           L_801EBD6C
    // 0x801EBC64: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
        goto L_801EBD6C;
    // 0x801EBC64: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
L_801EBC68:
    // 0x801EBC68: lui         $at, 0xC3BB
    ctx->r1 = S32(0XC3BB << 16);
    // 0x801EBC6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EBC70: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBC74: lwc1        $f14, -0x37C0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37C0);
    // 0x801EBC78: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBC7C: lwc1        $f12, -0x37BC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X37BC);
    // 0x801EBC80: lui         $at, 0x433B
    ctx->r1 = S32(0X433B << 16);
    // 0x801EBC84: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801EBC88: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801EBC8C: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801EBC90: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x801EBC94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EBC98: addiu       $a3, $a3, -0x2730
    ctx->r7 = ADD32(ctx->r7, -0X2730);
    // 0x801EBC9C: addiu       $t1, $t1, -0x2BD8
    ctx->r9 = ADD32(ctx->r9, -0X2BD8);
    // 0x801EBCA0: addiu       $t3, $t3, -0x2BC4
    ctx->r11 = ADD32(ctx->r11, -0X2BC4);
    // 0x801EBCA4: addiu       $v1, $v1, -0x2BD8
    ctx->r3 = ADD32(ctx->r3, -0X2BD8);
    // 0x801EBCA8: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x801EBCAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_801EBCB0:
    // 0x801EBCB0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x801EBCB4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801EBCB8: bne         $a0, $zero, L_801EBD08
    if (ctx->r4 != 0) {
        // 0x801EBCBC: addu        $a1, $t9, $a2
        ctx->r5 = ADD32(ctx->r25, ctx->r6);
            goto L_801EBD08;
    }
    // 0x801EBCBC: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    // 0x801EBCC0: beql        $v1, $t1, L_801EBD04
    if (ctx->r3 == ctx->r9) {
        // 0x801EBCC4: sw          $t0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r8;
            goto L_801EBD04;
    }
    goto skip_4;
    // 0x801EBCC4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    skip_4:
    // 0x801EBCC8: lw          $t4, -0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, -0X4);
    // 0x801EBCCC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801EBCD0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801EBCD4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EBCD8: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x801EBCDC: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801EBCE0: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801EBCE4: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x801EBCE8: nop

    // 0x801EBCEC: bc1fl       L_801EBD0C
    if (!c1cs) {
        // 0x801EBCF0: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_801EBD0C;
    }
    goto skip_5;
    // 0x801EBCF0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_5:
    // 0x801EBCF4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801EBCF8: b           L_801EBD08
    // 0x801EBCFC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_801EBD08;
    // 0x801EBCFC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x801EBD00: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_801EBD04:
    // 0x801EBD04: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_801EBD08:
    // 0x801EBD08: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_801EBD0C:
    // 0x801EBD0C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801EBD10: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801EBD14: bne         $t0, $a0, L_801EBD38
    if (ctx->r8 != ctx->r4) {
        // 0x801EBD18: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_801EBD38;
    }
    // 0x801EBD18: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBD1C: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x801EBD20: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801EBD24: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801EBD28: addu        $t4, $t9, $a2
    ctx->r12 = ADD32(ctx->r25, ctx->r6);
    // 0x801EBD2C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801EBD30: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801EBD34: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_801EBD38:
    // 0x801EBD38: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x801EBD3C: nop

    // 0x801EBD40: bc1f        L_801EBD60
    if (!c1cs) {
        // 0x801EBD44: nop
    
            goto L_801EBD60;
    }
    // 0x801EBD44: nop

    // 0x801EBD48: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x801EBD4C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x801EBD50: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x801EBD54: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801EBD58: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801EBD5C: sh          $t2, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r10;
L_801EBD60:
    // 0x801EBD60: bne         $v1, $t3, L_801EBCB0
    if (ctx->r3 != ctx->r11) {
        // 0x801EBD64: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_801EBCB0;
    }
    // 0x801EBD64: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801EBD68: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EBD6C:
    // 0x801EBD6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EBD70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EBD74: jr          $ra
    // 0x801EBD78: nop

    return;
    // 0x801EBD78: nop

;}
RECOMP_FUNC void M25_FUN_801ebd7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EBD7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EBD80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EBD84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EBD88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EBD8C: lui         $a1, 0x71E
    ctx->r5 = S32(0X71E << 16);
    // 0x801EBD90: ori         $a1, $a1, 0x275A
    ctx->r5 = ctx->r5 | 0X275A;
    // 0x801EBD94: jal         0x801C0B8C
    // 0x801EBD98: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EBD98: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EBD9C: beq         $v0, $zero, L_801EBE54
    if (ctx->r2 == 0) {
        // 0x801EBDA0: lui         $a0, 0x8039
        ctx->r4 = S32(0X8039 << 16);
            goto L_801EBE54;
    }
    // 0x801EBDA0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801EBDA4: addiu       $a0, $a0, -0x2730
    ctx->r4 = ADD32(ctx->r4, -0X2730);
    // 0x801EBDA8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801EBDAC: lui         $at, 0xC3BB
    ctx->r1 = S32(0XC3BB << 16);
    // 0x801EBDB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801EBDB4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EBDB8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBDBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EBDC0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EBDC4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x801EBDC8: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801EBDCC: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801EBDD0: sw          $zero, -0x2BD8($at)
    MEM_W(-0X2BD8, ctx->r1) = 0;
    // 0x801EBDD4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801EBDD8: addiu       $t3, $t3, -0x2BD8
    ctx->r11 = ADD32(ctx->r11, -0X2BD8);
    // 0x801EBDDC: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x801EBDE0: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x801EBDE4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801EBDE8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801EBDEC: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
    // 0x801EBDF0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x801EBDF4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801EBDF8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801EBDFC: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801EBE00: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EBE04: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801EBE08: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801EBE0C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801EBE10: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801EBE14: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EBE18: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801EBE1C: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x801EBE20: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x801EBE24: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801EBE28: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x801EBE2C: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x801EBE30: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801EBE34: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801EBE38: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801EBE3C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801EBE40: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801EBE44: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EBE48: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EBE4C: b           L_801EBE58
    // 0x801EBE50: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
        goto L_801EBE58;
    // 0x801EBE50: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
L_801EBE54:
    // 0x801EBE54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EBE58:
    // 0x801EBE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EBE5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EBE60: jr          $ra
    // 0x801EBE64: nop

    return;
    // 0x801EBE64: nop

;}
RECOMP_FUNC void M25_FUN_801ebe68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EBE68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EBE6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EBE70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EBE74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EBE78: lui         $a1, 0x739
    ctx->r5 = S32(0X739 << 16);
    // 0x801EBE7C: ori         $a1, $a1, 0x9E9A
    ctx->r5 = ctx->r5 | 0X9E9A;
    // 0x801EBE80: jal         0x801C0B8C
    // 0x801EBE84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EBE84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EBE88: beq         $v0, $zero, L_801EC000
    if (ctx->r2 == 0) {
        // 0x801EBE8C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EC000;
    }
    // 0x801EBE8C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EBE90: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x801EBE94: addiu       $a3, $a3, -0x2730
    ctx->r7 = ADD32(ctx->r7, -0X2730);
    // 0x801EBE98: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x801EBE9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBEA0: lwc1        $f12, -0x37B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X37B8);
    // 0x801EBEA4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EBEA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EBEAC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBEB0: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801EBEB4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x801EBEB8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801EBEBC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBEC0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801EBEC4: nop

    // 0x801EBEC8: bc1f        L_801EBEEC
    if (!c1cs) {
        // 0x801EBECC: nop
    
            goto L_801EBEEC;
    }
    // 0x801EBECC: nop

    // 0x801EBED0: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EBED4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EBED8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EBEDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EBEE0: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x801EBEE4: b           L_801EBF00
    // 0x801EBEE8: lwc1        $f14, -0x37B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37B4);
        goto L_801EBF00;
    // 0x801EBEE8: lwc1        $f14, -0x37B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37B4);
L_801EBEEC:
    // 0x801EBEEC: lwc1        $f14, -0x37B0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37B0);
    // 0x801EBEF0: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EBEF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EBEF8: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x801EBEFC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_801EBF00:
    // 0x801EBF00: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_801EBF04:
    // 0x801EBF04: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801EBF08: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x801EBF0C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801EBF10: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBF14: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801EBF18: nop

    // 0x801EBF1C: bc1fl       L_801EBF34
    if (!c1cs) {
        // 0x801EBF20: add.s       $f6, $f0, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_801EBF34;
    }
    goto skip_0;
    // 0x801EBF20: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    skip_0:
    // 0x801EBF24: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x801EBF28: b           L_801EBF38
    // 0x801EBF2C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_801EBF38;
    // 0x801EBF2C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801EBF30: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
L_801EBF34:
    // 0x801EBF34: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_801EBF38:
    // 0x801EBF38: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801EBF3C: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x801EBF40: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801EBF44: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801EBF48: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801EBF4C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EBF50: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801EBF54: nop

    // 0x801EBF58: bc1fl       L_801EBF70
    if (!c1cs) {
        // 0x801EBF5C: add.s       $f8, $f0, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_801EBF70;
    }
    goto skip_1;
    // 0x801EBF5C: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    skip_1:
    // 0x801EBF60: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x801EBF64: b           L_801EBF74
    // 0x801EBF68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_801EBF74;
    // 0x801EBF68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801EBF6C: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
L_801EBF70:
    // 0x801EBF70: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_801EBF74:
    // 0x801EBF74: bnel        $v1, $a1, L_801EBF04
    if (ctx->r3 != ctx->r5) {
        // 0x801EBF78: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_801EBF04;
    }
    goto skip_2;
    // 0x801EBF78: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x801EBF7C: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x801EBF80: bne         $at, $zero, L_801EBFF8
    if (ctx->r1 != 0) {
        // 0x801EBF84: nop
    
            goto L_801EBFF8;
    }
    // 0x801EBF84: nop

    // 0x801EBF88: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x801EBF8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801EBF90: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801EBF94: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801EBF98: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x801EBF9C: swc1        $f2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f2.u32l;
    // 0x801EBFA0: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801EBFA4: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x801EBFA8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801EBFAC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EBFB0: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
    // 0x801EBFB4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801EBFB8: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x801EBFBC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801EBFC0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801EBFC4: swc1        $f2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f2.u32l;
    // 0x801EBFC8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x801EBFCC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801EBFD0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EBFD4: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x801EBFD8: swc1        $f2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f2.u32l;
    // 0x801EBFDC: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801EBFE0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x801EBFE4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801EBFE8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801EBFEC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801EBFF0: b           L_801EC118
    // 0x801EBFF4: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
        goto L_801EC118;
    // 0x801EBFF4: swc1        $f2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f2.u32l;
L_801EBFF8:
    // 0x801EBFF8: b           L_801EC118
    // 0x801EBFFC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EC118;
    // 0x801EBFFC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EC000:
    // 0x801EC000: lui         $a1, 0x71E
    ctx->r5 = S32(0X71E << 16);
    // 0x801EC004: jal         0x801C0B8C
    // 0x801EC008: ori         $a1, $a1, 0x275A
    ctx->r5 = ctx->r5 | 0X275A;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801EC008: ori         $a1, $a1, 0x275A
    ctx->r5 = ctx->r5 | 0X275A;
    after_1:
    // 0x801EC00C: beq         $v0, $zero, L_801EC114
    if (ctx->r2 == 0) {
        // 0x801EC010: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801EC114;
    }
    // 0x801EC010: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EC014: lui         $at, 0xC3BB
    ctx->r1 = S32(0XC3BB << 16);
    // 0x801EC018: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EC01C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC020: lwc1        $f14, -0x37AC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X37AC);
    // 0x801EC024: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC028: lwc1        $f12, -0x37A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X37A8);
    // 0x801EC02C: lui         $at, 0x433B
    ctx->r1 = S32(0X433B << 16);
    // 0x801EC030: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801EC034: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801EC038: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801EC03C: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x801EC040: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801EC044: addiu       $a3, $a3, -0x2730
    ctx->r7 = ADD32(ctx->r7, -0X2730);
    // 0x801EC048: addiu       $t1, $t1, -0x2BD8
    ctx->r9 = ADD32(ctx->r9, -0X2BD8);
    // 0x801EC04C: addiu       $t3, $t3, -0x2BC4
    ctx->r11 = ADD32(ctx->r11, -0X2BC4);
    // 0x801EC050: addiu       $v1, $v1, -0x2BD8
    ctx->r3 = ADD32(ctx->r3, -0X2BD8);
    // 0x801EC054: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x801EC058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_801EC05C:
    // 0x801EC05C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x801EC060: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801EC064: bne         $a0, $zero, L_801EC0B4
    if (ctx->r4 != 0) {
        // 0x801EC068: addu        $a1, $t9, $a2
        ctx->r5 = ADD32(ctx->r25, ctx->r6);
            goto L_801EC0B4;
    }
    // 0x801EC068: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    // 0x801EC06C: beql        $v1, $t1, L_801EC0B0
    if (ctx->r3 == ctx->r9) {
        // 0x801EC070: sw          $t0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r8;
            goto L_801EC0B0;
    }
    goto skip_3;
    // 0x801EC070: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    skip_3:
    // 0x801EC074: lw          $t4, -0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, -0X4);
    // 0x801EC078: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801EC07C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801EC080: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801EC084: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x801EC088: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801EC08C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801EC090: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x801EC094: nop

    // 0x801EC098: bc1fl       L_801EC0B8
    if (!c1cs) {
        // 0x801EC09C: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_801EC0B8;
    }
    goto skip_4;
    // 0x801EC09C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_4:
    // 0x801EC0A0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801EC0A4: b           L_801EC0B4
    // 0x801EC0A8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_801EC0B4;
    // 0x801EC0A8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x801EC0AC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_801EC0B0:
    // 0x801EC0B0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_801EC0B4:
    // 0x801EC0B4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_801EC0B8:
    // 0x801EC0B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801EC0BC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801EC0C0: bne         $t0, $a0, L_801EC0E4
    if (ctx->r8 != ctx->r4) {
        // 0x801EC0C4: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_801EC0E4;
    }
    // 0x801EC0C4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801EC0C8: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x801EC0CC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801EC0D0: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801EC0D4: addu        $t4, $t9, $a2
    ctx->r12 = ADD32(ctx->r25, ctx->r6);
    // 0x801EC0D8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801EC0DC: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801EC0E0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_801EC0E4:
    // 0x801EC0E4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x801EC0E8: nop

    // 0x801EC0EC: bc1f        L_801EC10C
    if (!c1cs) {
        // 0x801EC0F0: nop
    
            goto L_801EC10C;
    }
    // 0x801EC0F0: nop

    // 0x801EC0F4: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x801EC0F8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x801EC0FC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x801EC100: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801EC104: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801EC108: sh          $t2, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r10;
L_801EC10C:
    // 0x801EC10C: bne         $v1, $t3, L_801EC05C
    if (ctx->r3 != ctx->r11) {
        // 0x801EC110: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_801EC05C;
    }
    // 0x801EC110: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_801EC114:
    // 0x801EC114: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EC118:
    // 0x801EC118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EC11C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EC120: jr          $ra
    // 0x801EC124: nop

    return;
    // 0x801EC124: nop

;}
RECOMP_FUNC void M25_FUN_801ec128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC128: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC12C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC130: jr          $ra
    // 0x801EC134: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x801EC134: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec138(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC138: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801EC13C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EC140: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801EC144: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801EC148: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801EC14C: jal         0x801BF628
    // 0x801EC150: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801EC150: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801EC154: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801EC158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EC15C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801EC160: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801EC164: bne         $at, $zero, L_801EC174
    if (ctx->r1 != 0) {
        // 0x801EC168: nop
    
            goto L_801EC174;
    }
    // 0x801EC168: nop

    // 0x801EC16C: b           L_801EC174
    // 0x801EC170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801EC174;
    // 0x801EC170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EC174:
    // 0x801EC174: jr          $ra
    // 0x801EC178: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801EC178: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec17c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec17c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC17C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801EC180: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801EC184: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801EC188: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801EC18C: lui         $a1, 0x503
    ctx->r5 = S32(0X503 << 16);
    // 0x801EC190: ori         $a1, $a1, 0x84BA
    ctx->r5 = ctx->r5 | 0X84BA;
    // 0x801EC194: jal         0x801C0B8C
    // 0x801EC198: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EC198: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EC19C: beq         $v0, $zero, L_801EC1F0
    if (ctx->r2 == 0) {
        // 0x801EC1A0: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801EC1F0;
    }
    // 0x801EC1A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC1A4: lwc1        $f12, -0x37A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X37A4);
    // 0x801EC1A8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801EC1AC: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801EC1B0: addiu       $t9, $t9, -0x7100
    ctx->r25 = ADD32(ctx->r25, -0X7100);
    // 0x801EC1B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801EC1B8: addiu       $t6, $zero, 0xB0
    ctx->r14 = ADD32(0, 0XB0);
    // 0x801EC1BC: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x801EC1C0: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801EC1C4: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x801EC1C8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801EC1CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801EC1D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801EC1D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801EC1D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801EC1DC: lui         $a2, 0xC0C0
    ctx->r6 = S32(0XC0C0 << 16);
    // 0x801EC1E0: jal         0x801C2C90
    // 0x801EC1E4: addiu       $a3, $zero, 0xB0
    ctx->r7 = ADD32(0, 0XB0);
    LOOKUP_FUNC(0x801C2C90)(rdram, ctx);
        goto after_1;
    // 0x801EC1E4: addiu       $a3, $zero, 0xB0
    ctx->r7 = ADD32(0, 0XB0);
    after_1:
    // 0x801EC1E8: b           L_801EC1F4
    // 0x801EC1EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801EC1F4;
    // 0x801EC1EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EC1F0:
    // 0x801EC1F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EC1F4:
    // 0x801EC1F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801EC1F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801EC1FC: jr          $ra
    // 0x801EC200: nop

    return;
    // 0x801EC200: nop

;}
RECOMP_FUNC void M25_FUN_801ec204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC204: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC208: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC20C: jr          $ra
    // 0x801EC210: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801EC210: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec214(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC214: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC218: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC21C: jr          $ra
    // 0x801EC220: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801EC220: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec224(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC224: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC228: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC22C: jr          $ra
    // 0x801EC230: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801EC230: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec234(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EC238: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EC23C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EC240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EC244: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC248: addiu       $a1, $a1, 0xA48
    ctx->r5 = ADD32(ctx->r5, 0XA48);
    // 0x801EC24C: jal         0x801C2420
    // 0x801EC250: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801EC250: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_0:
    // 0x801EC254: jal         0x801CC318
    // 0x801EC258: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_1;
    // 0x801EC258: nop

    after_1:
    // 0x801EC25C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC260: addiu       $a1, $a1, -0x4E9C
    ctx->r5 = ADD32(ctx->r5, -0X4E9C);
    // 0x801EC264: jal         0x801CC458
    // 0x801EC268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_2;
    // 0x801EC268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801EC26C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC270: addiu       $a1, $a1, 0xA60
    ctx->r5 = ADD32(ctx->r5, 0XA60);
    // 0x801EC274: jal         0x801C2420
    // 0x801EC278: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_3;
    // 0x801EC278: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    after_3:
    // 0x801EC27C: jal         0x801CC318
    // 0x801EC280: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_4;
    // 0x801EC280: nop

    after_4:
    // 0x801EC284: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC288: addiu       $a1, $a1, -0x4F7C
    ctx->r5 = ADD32(ctx->r5, -0X4F7C);
    // 0x801EC28C: jal         0x801CC458
    // 0x801EC290: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_5;
    // 0x801EC290: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x801EC294: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC298: addiu       $a1, $a1, -0x4F78
    ctx->r5 = ADD32(ctx->r5, -0X4F78);
    // 0x801EC29C: jal         0x801CC4C0
    // 0x801EC2A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CC4C0)(rdram, ctx);
        goto after_6;
    // 0x801EC2A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x801EC2A4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC2A8: addiu       $a1, $a1, 0xA78
    ctx->r5 = ADD32(ctx->r5, 0XA78);
    // 0x801EC2AC: jal         0x801C2420
    // 0x801EC2B0: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_7;
    // 0x801EC2B0: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    after_7:
    // 0x801EC2B4: jal         0x801CC318
    // 0x801EC2B8: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_8;
    // 0x801EC2B8: nop

    after_8:
    // 0x801EC2BC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC2C0: addiu       $a1, $a1, -0x5134
    ctx->r5 = ADD32(ctx->r5, -0X5134);
    // 0x801EC2C4: jal         0x801CC458
    // 0x801EC2C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_9;
    // 0x801EC2C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x801EC2CC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC2D0: addiu       $a1, $a1, 0xA90
    ctx->r5 = ADD32(ctx->r5, 0XA90);
    // 0x801EC2D4: jal         0x801C2420
    // 0x801EC2D8: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_10;
    // 0x801EC2D8: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_10:
    // 0x801EC2DC: jal         0x801CC318
    // 0x801EC2E0: nop

    LOOKUP_FUNC(0x801CC318)(rdram, ctx);
        goto after_11;
    // 0x801EC2E0: nop

    after_11:
    // 0x801EC2E4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC2E8: addiu       $a1, $a1, -0x50E8
    ctx->r5 = ADD32(ctx->r5, -0X50E8);
    // 0x801EC2EC: jal         0x801CC458
    // 0x801EC2F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_12;
    // 0x801EC2F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x801EC2F4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC2F8: addiu       $a1, $a1, -0x5028
    ctx->r5 = ADD32(ctx->r5, -0X5028);
    // 0x801EC2FC: jal         0x801CC458
    // 0x801EC300: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801CC458)(rdram, ctx);
        goto after_13;
    // 0x801EC300: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_13:
    // 0x801EC304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EC308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EC30C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801EC310: jr          $ra
    // 0x801EC314: nop

    return;
    // 0x801EC314: nop

;}
RECOMP_FUNC void M25_FUN_801ec318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EC31C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EC320: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EC324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EC328: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC32C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801EC330: lw          $a0, -0x54EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54EC);
    // 0x801EC334: jal         0x80005670
    // 0x801EC338: addiu       $a1, $a1, -0x4EB0
    ctx->r5 = ADD32(ctx->r5, -0X4EB0);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801EC338: addiu       $a1, $a1, -0x4EB0
    ctx->r5 = ADD32(ctx->r5, -0X4EB0);
    after_0:
    // 0x801EC33C: jal         0x801D11AC
    // 0x801EC340: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D11AC)(rdram, ctx);
        goto after_1;
    // 0x801EC340: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801EC344: jal         0x801D11B8
    // 0x801EC348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D11B8)(rdram, ctx);
        goto after_2;
    // 0x801EC348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801EC34C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801EC350: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801EC354: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC358: addiu       $a1, $a1, -0x4F90
    ctx->r5 = ADD32(ctx->r5, -0X4F90);
    // 0x801EC35C: jal         0x80005670
    // 0x801EC360: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x801EC360: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    after_3:
    // 0x801EC364: jal         0x801CFD28
    // 0x801EC368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CFD28)(rdram, ctx);
        goto after_4;
    // 0x801EC368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x801EC36C: jal         0x801CFD34
    // 0x801EC370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CFD34)(rdram, ctx);
        goto after_5;
    // 0x801EC370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801EC374: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801EC378: lw          $t7, -0x54EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X54EC);
    // 0x801EC37C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC380: addiu       $a1, $a1, -0x5148
    ctx->r5 = ADD32(ctx->r5, -0X5148);
    // 0x801EC384: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EC388: jal         0x80005670
    // 0x801EC38C: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x801EC38C: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_6:
    // 0x801EC390: jal         0x801D048C
    // 0x801EC394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D048C)(rdram, ctx);
        goto after_7;
    // 0x801EC394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x801EC398: jal         0x801D03E0
    // 0x801EC39C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D03E0)(rdram, ctx);
        goto after_8;
    // 0x801EC39C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x801EC3A0: jal         0x801D03EC
    // 0x801EC3A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D03EC)(rdram, ctx);
        goto after_9;
    // 0x801EC3A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x801EC3A8: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801EC3AC: lw          $t9, -0x54EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X54EC);
    // 0x801EC3B0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC3B4: addiu       $a1, $a1, -0x50FC
    ctx->r5 = ADD32(ctx->r5, -0X50FC);
    // 0x801EC3B8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EC3BC: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EC3C0: jal         0x80005670
    // 0x801EC3C4: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_10;
    // 0x801EC3C4: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    after_10:
    // 0x801EC3C8: jal         0x801D0A68
    // 0x801EC3CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0A68)(rdram, ctx);
        goto after_11;
    // 0x801EC3CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x801EC3D0: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801EC3D4: lw          $t2, -0x54EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X54EC);
    // 0x801EC3D8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801EC3DC: addiu       $a1, $a1, -0x503C
    ctx->r5 = ADD32(ctx->r5, -0X503C);
    // 0x801EC3E0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EC3E4: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EC3E8: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EC3EC: jal         0x80005670
    // 0x801EC3F0: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_12;
    // 0x801EC3F0: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    after_12:
    // 0x801EC3F4: jal         0x801CC530
    // 0x801EC3F8: nop

    LOOKUP_FUNC(0x801CC530)(rdram, ctx);
        goto after_13;
    // 0x801EC3F8: nop

    after_13:
    // 0x801EC3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EC400: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC404: sw          $zero, -0x4B40($at)
    MEM_W(-0X4B40, ctx->r1) = 0;
    // 0x801EC408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EC40C: jr          $ra
    // 0x801EC410: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801EC410: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec414(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC414: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EC418: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec41c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec41c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC41C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EC420: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EC424: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EC428: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EC42C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EC430: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EC434: lui         $a2, 0x8020
    ctx->r6 = S32(0X8020 << 16);
    // 0x801EC438: addiu       $a2, $a2, -0x4B40
    ctx->r6 = ADD32(ctx->r6, -0X4B40);
    // 0x801EC43C: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    // 0x801EC440: beql        $a0, $zero, L_801EC5A4
    if (ctx->r4 == 0) {
        // 0x801EC444: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801EC5A4;
    }
    goto skip_0;
    // 0x801EC444: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801EC448: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801EC44C: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EC450: beql        $v0, $zero, L_801EC478
    if (ctx->r2 == 0) {
        // 0x801EC454: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_801EC478;
    }
    goto skip_1;
    // 0x801EC454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x801EC458: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801EC45C: beq         $v0, $at, L_801EC4CC
    if (ctx->r2 == ctx->r1) {
        // 0x801EC460: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801EC4CC;
    }
    // 0x801EC460: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801EC464: beq         $v0, $at, L_801EC514
    if (ctx->r2 == ctx->r1) {
        // 0x801EC468: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EC514;
    }
    // 0x801EC468: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EC46C: b           L_801EC5A4
    // 0x801EC470: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801EC5A4;
    // 0x801EC470: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801EC474: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_801EC478:
    // 0x801EC478: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x801EC47C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801EC480: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801EC484: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EC488: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EC48C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EC490: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EC494: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801EC498: swc1        $f0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f0.u32l;
    // 0x801EC49C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801EC4A0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EC4A4: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EC4A8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EC4AC: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x801EC4B0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801EC4B4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EC4B8: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EC4BC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EC4C0: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x801EC4C4: b           L_801EC5A0
    // 0x801EC4C8: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_801EC5A0;
    // 0x801EC4C8: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_801EC4CC:
    // 0x801EC4CC: lui         $a1, 0x169
    ctx->r5 = S32(0X169 << 16);
    // 0x801EC4D0: ori         $a1, $a1, 0xA220
    ctx->r5 = ctx->r5 | 0XA220;
    // 0x801EC4D4: jal         0x801C0B8C
    // 0x801EC4D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EC4D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EC4DC: beq         $v0, $zero, L_801EC5A0
    if (ctx->r2 == 0) {
        // 0x801EC4E0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801EC5A0;
    }
    // 0x801EC4E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EC4E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EC4E8: lui         $a1, 0x168
    ctx->r5 = S32(0X168 << 16);
    // 0x801EC4EC: ori         $a1, $a1, 0x1C
    ctx->r5 = ctx->r5 | 0X1C;
    // 0x801EC4F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EC4F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EC4F8: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EC4FC: jal         0x801CC470
    // 0x801EC500: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EC500: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801EC504: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801EC508: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC50C: b           L_801EC5A0
    // 0x801EC510: sw          $t2, -0x4B40($at)
    MEM_W(-0X4B40, ctx->r1) = ctx->r10;
        goto L_801EC5A0;
    // 0x801EC510: sw          $t2, -0x4B40($at)
    MEM_W(-0X4B40, ctx->r1) = ctx->r10;
L_801EC514:
    // 0x801EC514: lui         $a1, 0x1A9
    ctx->r5 = S32(0X1A9 << 16);
    // 0x801EC518: jal         0x801C0B8C
    // 0x801EC51C: ori         $a1, $a1, 0xB860
    ctx->r5 = ctx->r5 | 0XB860;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801EC51C: ori         $a1, $a1, 0xB860
    ctx->r5 = ctx->r5 | 0XB860;
    after_2:
    // 0x801EC520: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EC524: beq         $v0, $zero, L_801EC5A0
    if (ctx->r2 == 0) {
        // 0x801EC528: addiu       $v1, $v1, -0x54EC
        ctx->r3 = ADD32(ctx->r3, -0X54EC);
            goto L_801EC5A0;
    }
    // 0x801EC528: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EC52C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801EC530: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC534: lwc1        $f8, -0x37A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X37A0);
    // 0x801EC538: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EC53C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801EC540: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EC544: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EC548: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC54C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801EC550: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EC554: addiu       $t5, $zero, 0x1800
    ctx->r13 = ADD32(0, 0X1800);
    // 0x801EC558: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    // 0x801EC55C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801EC560: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EC564: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EC568: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EC56C: swc1        $f10, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f10.u32l;
    // 0x801EC570: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801EC574: lwc1        $f16, -0x379C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X379C);
    // 0x801EC578: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EC57C: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EC580: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EC584: swc1        $f16, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f16.u32l;
    // 0x801EC588: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EC58C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EC590: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EC594: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EC598: b           L_801EC5A4
    // 0x801EC59C: sh          $t5, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r13;
        goto L_801EC5A4;
    // 0x801EC59C: sh          $t5, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r13;
L_801EC5A0:
    // 0x801EC5A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EC5A4:
    // 0x801EC5A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EC5A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EC5AC: jr          $ra
    // 0x801EC5B0: nop

    return;
    // 0x801EC5B0: nop

;}
RECOMP_FUNC void M25_FUN_801ec5b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC5B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EC5B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EC5BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EC5C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EC5C4: lui         $a1, 0x242
    ctx->r5 = S32(0X242 << 16);
    // 0x801EC5C8: ori         $a1, $a1, 0x4EE0
    ctx->r5 = ctx->r5 | 0X4EE0;
    // 0x801EC5CC: jal         0x801C0B8C
    // 0x801EC5D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EC5D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EC5D4: beq         $v0, $zero, L_801EC654
    if (ctx->r2 == 0) {
        // 0x801EC5D8: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801EC654;
    }
    // 0x801EC5D8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EC5DC: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EC5E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EC5E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC5E8: lwc1        $f4, -0x3798($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3798);
    // 0x801EC5EC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EC5F0: lui         $at, 0x4178
    ctx->r1 = S32(0X4178 << 16);
    // 0x801EC5F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EC5F8: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EC5FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC600: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EC604: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EC608: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801EC60C: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801EC610: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801EC614: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EC618: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EC61C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EC620: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801EC624: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EC628: lwc1        $f8, -0x3794($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3794);
    // 0x801EC62C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EC630: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EC634: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EC638: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801EC63C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EC640: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EC644: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EC648: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EC64C: b           L_801EC658
    // 0x801EC650: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
        goto L_801EC658;
    // 0x801EC650: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
L_801EC654:
    // 0x801EC654: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EC658:
    // 0x801EC658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EC65C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EC660: jr          $ra
    // 0x801EC664: nop

    return;
    // 0x801EC664: nop

;}
RECOMP_FUNC void M25_FUN_801ec668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC668: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EC66C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801EC670: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801EC674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EC678: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EC67C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EC680: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EC684: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801EC688: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EC68C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EC690: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x801EC694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EC698: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EC69C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EC6A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EC6A4: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801EC6A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EC6AC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801EC6B0: nop

    // 0x801EC6B4: bc1f        L_801EC6D4
    if (!c1cs) {
        // 0x801EC6B8: nop
    
            goto L_801EC6D4;
    }
    // 0x801EC6B8: nop

    // 0x801EC6BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EC6C0: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EC6C4: jal         0x801CC470
    // 0x801EC6C8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801EC6C8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801EC6CC: b           L_801EC6D4
    // 0x801EC6D0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EC6D4;
    // 0x801EC6D0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EC6D4:
    // 0x801EC6D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EC6D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EC6DC: jr          $ra
    // 0x801EC6E0: nop

    return;
    // 0x801EC6E0: nop

;}
RECOMP_FUNC void M25_FUN_801ec6e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC6E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EC6E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EC6EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EC6F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EC6F4: lui         $a1, 0x2A5
    ctx->r5 = S32(0X2A5 << 16);
    // 0x801EC6F8: ori         $a1, $a1, 0x7D80
    ctx->r5 = ctx->r5 | 0X7D80;
    // 0x801EC6FC: jal         0x801C0B8C
    // 0x801EC700: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EC700: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EC704: beq         $v0, $zero, L_801EC7A4
    if (ctx->r2 == 0) {
        // 0x801EC708: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EC7A4;
    }
    // 0x801EC708: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EC70C: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EC710: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EC714: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x801EC718: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EC71C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EC720: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EC724: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC728: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EC72C: lui         $a1, 0x168
    ctx->r5 = S32(0X168 << 16);
    // 0x801EC730: ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    // 0x801EC734: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EC738: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801EC73C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EC740: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801EC744: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EC748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EC74C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EC750: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EC754: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EC758: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EC75C: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801EC760: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801EC764: lwc1        $f8, -0x3790($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3790);
    // 0x801EC768: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EC76C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EC770: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EC774: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EC778: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EC77C: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801EC780: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801EC784: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EC788: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EC78C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EC790: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801EC794: jal         0x801CC470
    // 0x801EC798: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EC798: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EC79C: b           L_801EC7A8
    // 0x801EC7A0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801EC7A8;
    // 0x801EC7A0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EC7A4:
    // 0x801EC7A4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EC7A8:
    // 0x801EC7A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EC7AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EC7B0: jr          $ra
    // 0x801EC7B4: nop

    return;
    // 0x801EC7B4: nop

;}
RECOMP_FUNC void M25_FUN_801ec7b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC7B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC7BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC7C0: jr          $ra
    // 0x801EC7C4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801EC7C4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec7c8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec7c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC7C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC7CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC7D0: jr          $ra
    // 0x801EC7D4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801EC7D4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec7d8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec7d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC7D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC7DC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC7E0: jr          $ra
    // 0x801EC7E4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801EC7E4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec7e8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec7e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC7E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EC7EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EC7F0: jr          $ra
    // 0x801EC7F4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x801EC7F4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ec7f8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ec7f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC7F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EC7FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EC800: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EC804: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EC808: lui         $a1, 0x40D
    ctx->r5 = S32(0X40D << 16);
    // 0x801EC80C: ori         $a1, $a1, 0x9900
    ctx->r5 = ctx->r5 | 0X9900;
    // 0x801EC810: jal         0x801C0B8C
    // 0x801EC814: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EC814: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EC818: beq         $v0, $zero, L_801EC8B8
    if (ctx->r2 == 0) {
        // 0x801EC81C: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EC8B8;
    }
    // 0x801EC81C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EC820: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EC824: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EC828: lui         $at, 0xC298
    ctx->r1 = S32(0XC298 << 16);
    // 0x801EC82C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EC830: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EC834: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EC838: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC83C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EC840: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EC844: ori         $a1, $a1, 0x1B
    ctx->r5 = ctx->r5 | 0X1B;
    // 0x801EC848: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EC84C: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801EC850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EC854: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801EC858: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EC85C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EC860: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EC864: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EC868: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EC86C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EC870: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801EC874: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801EC878: lwc1        $f8, -0x378C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X378C);
    // 0x801EC87C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EC880: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EC884: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EC888: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EC88C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EC890: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801EC894: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801EC898: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EC89C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EC8A0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EC8A4: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801EC8A8: jal         0x801CC470
    // 0x801EC8AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EC8AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EC8B0: b           L_801EC8BC
    // 0x801EC8B4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801EC8BC;
    // 0x801EC8B4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801EC8B8:
    // 0x801EC8B8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801EC8BC:
    // 0x801EC8BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EC8C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EC8C4: jr          $ra
    // 0x801EC8C8: nop

    return;
    // 0x801EC8C8: nop

;}
RECOMP_FUNC void M25_FUN_801ec8cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC8CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EC8D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EC8D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EC8D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EC8DC: lui         $a1, 0x44A
    ctx->r5 = S32(0X44A << 16);
    // 0x801EC8E0: ori         $a1, $a1, 0xA200
    ctx->r5 = ctx->r5 | 0XA200;
    // 0x801EC8E4: jal         0x801C0B8C
    // 0x801EC8E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EC8E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EC8EC: beq         $v0, $zero, L_801EC98C
    if (ctx->r2 == 0) {
        // 0x801EC8F0: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EC98C;
    }
    // 0x801EC8F0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EC8F4: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EC8F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EC8FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC900: lwc1        $f4, -0x3788($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3788);
    // 0x801EC904: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EC908: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EC90C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EC910: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EC914: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EC918: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x801EC91C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EC920: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801EC924: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EC928: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801EC92C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EC930: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EC934: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EC938: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EC93C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EC940: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EC944: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801EC948: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801EC94C: lwc1        $f8, -0x3784($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3784);
    // 0x801EC950: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EC954: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EC958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EC95C: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EC960: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EC964: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801EC968: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801EC96C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EC970: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EC974: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EC978: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801EC97C: jal         0x801CC470
    // 0x801EC980: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EC980: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EC984: b           L_801EC990
    // 0x801EC988: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801EC990;
    // 0x801EC988: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801EC98C:
    // 0x801EC98C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801EC990:
    // 0x801EC990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EC994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EC998: jr          $ra
    // 0x801EC99C: nop

    return;
    // 0x801EC99C: nop

;}
RECOMP_FUNC void M25_FUN_801ec9a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EC9A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EC9A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EC9A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EC9AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EC9B0: lui         $a1, 0x473
    ctx->r5 = S32(0X473 << 16);
    // 0x801EC9B4: ori         $a1, $a1, 0x52AA
    ctx->r5 = ctx->r5 | 0X52AA;
    // 0x801EC9B8: jal         0x801C0B8C
    // 0x801EC9BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EC9BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EC9C0: beq         $v0, $zero, L_801EC9F0
    if (ctx->r2 == 0) {
        // 0x801EC9C4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801EC9F0;
    }
    // 0x801EC9C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EC9C8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801EC9CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EC9D0: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EC9D4: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x801EC9D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EC9DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EC9E0: jal         0x801CC470
    // 0x801EC9E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EC9E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801EC9E8: b           L_801EC9F4
    // 0x801EC9EC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801EC9F4;
    // 0x801EC9EC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801EC9F0:
    // 0x801EC9F0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801EC9F4:
    // 0x801EC9F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EC9F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EC9FC: jr          $ra
    // 0x801ECA00: nop

    return;
    // 0x801ECA00: nop

;}
RECOMP_FUNC void M25_FUN_801eca04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECA04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ECA08: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ECA0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ECA10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ECA14: lui         $a1, 0x503
    ctx->r5 = S32(0X503 << 16);
    // 0x801ECA18: ori         $a1, $a1, 0x84BA
    ctx->r5 = ctx->r5 | 0X84BA;
    // 0x801ECA1C: jal         0x801C0B8C
    // 0x801ECA20: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECA20: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ECA24: beq         $v0, $zero, L_801ECA54
    if (ctx->r2 == 0) {
        // 0x801ECA28: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801ECA54;
    }
    // 0x801ECA28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801ECA2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ECA30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ECA34: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801ECA38: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x801ECA3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ECA40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801ECA44: jal         0x801CC470
    // 0x801ECA48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ECA48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801ECA4C: b           L_801ECA58
    // 0x801ECA50: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801ECA58;
    // 0x801ECA50: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801ECA54:
    // 0x801ECA54: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801ECA58:
    // 0x801ECA58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ECA5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ECA60: jr          $ra
    // 0x801ECA64: nop

    return;
    // 0x801ECA64: nop

;}
RECOMP_FUNC void M25_FUN_801eca68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECA68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ECA6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ECA70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ECA74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ECA78: lui         $a1, 0x508
    ctx->r5 = S32(0X508 << 16);
    // 0x801ECA7C: ori         $a1, $a1, 0x189A
    ctx->r5 = ctx->r5 | 0X189A;
    // 0x801ECA80: jal         0x801C0B8C
    // 0x801ECA84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECA84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ECA88: beq         $v0, $zero, L_801ECAB8
    if (ctx->r2 == 0) {
        // 0x801ECA8C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801ECAB8;
    }
    // 0x801ECA8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801ECA90: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801ECA94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ECA98: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801ECA9C: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    // 0x801ECAA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ECAA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801ECAA8: jal         0x801CC470
    // 0x801ECAAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ECAAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801ECAB0: b           L_801ECABC
    // 0x801ECAB4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_801ECABC;
    // 0x801ECAB4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801ECAB8:
    // 0x801ECAB8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801ECABC:
    // 0x801ECABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ECAC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ECAC4: jr          $ra
    // 0x801ECAC8: nop

    return;
    // 0x801ECAC8: nop

;}
RECOMP_FUNC void M25_FUN_801ecacc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECACC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ECAD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ECAD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ECAD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ECADC: lui         $a1, 0x545
    ctx->r5 = S32(0X545 << 16);
    // 0x801ECAE0: ori         $a1, $a1, 0x219A
    ctx->r5 = ctx->r5 | 0X219A;
    // 0x801ECAE4: jal         0x801C0B8C
    // 0x801ECAE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECAE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ECAEC: beq         $v0, $zero, L_801ECB8C
    if (ctx->r2 == 0) {
        // 0x801ECAF0: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801ECB8C;
    }
    // 0x801ECAF0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801ECAF4: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801ECAF8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ECAFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ECB00: lwc1        $f4, -0x3780($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3780);
    // 0x801ECB04: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ECB08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ECB0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ECB10: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801ECB14: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ECB18: ori         $a1, $a1, 0x11
    ctx->r5 = ctx->r5 | 0X11;
    // 0x801ECB1C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801ECB20: addiu       $t8, $zero, 0x1BED
    ctx->r24 = ADD32(0, 0X1BED);
    // 0x801ECB24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801ECB28: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801ECB2C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801ECB30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ECB34: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801ECB38: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801ECB3C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801ECB40: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801ECB44: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801ECB48: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801ECB4C: lwc1        $f8, -0x377C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X377C);
    // 0x801ECB50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ECB54: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801ECB58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ECB5C: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801ECB60: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801ECB64: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801ECB68: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801ECB6C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801ECB70: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801ECB74: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801ECB78: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801ECB7C: jal         0x801CC470
    // 0x801ECB80: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ECB80: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ECB84: b           L_801ECB90
    // 0x801ECB88: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_801ECB90;
    // 0x801ECB88: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801ECB8C:
    // 0x801ECB8C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801ECB90:
    // 0x801ECB90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ECB94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ECB98: jr          $ra
    // 0x801ECB9C: nop

    return;
    // 0x801ECB9C: nop

;}
RECOMP_FUNC void M25_FUN_801ecba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECBA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ECBA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ECBA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ECBAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ECBB0: lui         $a1, 0x582
    ctx->r5 = S32(0X582 << 16);
    // 0x801ECBB4: ori         $a1, $a1, 0x2A9A
    ctx->r5 = ctx->r5 | 0X2A9A;
    // 0x801ECBB8: jal         0x801C0B8C
    // 0x801ECBBC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECBBC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ECBC0: beq         $v0, $zero, L_801ECC64
    if (ctx->r2 == 0) {
        // 0x801ECBC4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801ECC64;
    }
    // 0x801ECBC4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801ECBC8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801ECBCC: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801ECBD0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ECBD4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ECBD8: lwc1        $f4, -0x3778($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3778);
    // 0x801ECBDC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ECBE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ECBE4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ECBE8: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801ECBEC: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ECBF0: ori         $a1, $a1, 0x11
    ctx->r5 = ctx->r5 | 0X11;
    // 0x801ECBF4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801ECBF8: addiu       $t8, $zero, 0x1A6D
    ctx->r24 = ADD32(0, 0X1A6D);
    // 0x801ECBFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801ECC00: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801ECC04: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801ECC08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ECC0C: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801ECC10: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801ECC14: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801ECC18: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801ECC1C: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801ECC20: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801ECC24: lwc1        $f8, -0x3774($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3774);
    // 0x801ECC28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ECC2C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801ECC30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ECC34: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801ECC38: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801ECC3C: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801ECC40: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801ECC44: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801ECC48: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801ECC4C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801ECC50: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
    // 0x801ECC54: jal         0x801CC470
    // 0x801ECC58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ECC58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ECC5C: b           L_801ECC84
    // 0x801ECC60: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801ECC84;
    // 0x801ECC60: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801ECC64:
    // 0x801ECC64: lui         $a1, 0x563
    ctx->r5 = S32(0X563 << 16);
    // 0x801ECC68: jal         0x801C0B8C
    // 0x801ECC6C: ori         $a1, $a1, 0xA61A
    ctx->r5 = ctx->r5 | 0XA61A;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801ECC6C: ori         $a1, $a1, 0xA61A
    ctx->r5 = ctx->r5 | 0XA61A;
    after_2:
    // 0x801ECC70: beql        $v0, $zero, L_801ECC84
    if (ctx->r2 == 0) {
        // 0x801ECC74: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_801ECC84;
    }
    goto skip_0;
    // 0x801ECC74: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    skip_0:
    // 0x801ECC78: jal         0x801D1AF8
    // 0x801ECC7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D1AF8)(rdram, ctx);
        goto after_3;
    // 0x801ECC7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x801ECC80: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801ECC84:
    // 0x801ECC84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ECC88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ECC8C: jr          $ra
    // 0x801ECC90: nop

    return;
    // 0x801ECC90: nop

;}
RECOMP_FUNC void M25_FUN_801ecc94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECC94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801ECC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ECC9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801ECCA0: jal         0x801D1B04
    // 0x801ECCA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801D1B04)(rdram, ctx);
        goto after_0;
    // 0x801ECCA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801ECCA8: bne         $v0, $zero, L_801ECCB8
    if (ctx->r2 != 0) {
        // 0x801ECCAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801ECCB8;
    }
    // 0x801ECCAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801ECCB0: b           L_801ECCBC
    // 0x801ECCB4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_801ECCBC;
    // 0x801ECCB4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801ECCB8:
    // 0x801ECCB8: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801ECCBC:
    // 0x801ECCBC: jr          $ra
    // 0x801ECCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801ECCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eccc4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eccc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECCC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801ECCC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801ECCCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ECCD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801ECCD4: lui         $a1, 0x75F
    ctx->r5 = S32(0X75F << 16);
    // 0x801ECCD8: ori         $a1, $a1, 0xC43A
    ctx->r5 = ctx->r5 | 0XC43A;
    // 0x801ECCDC: jal         0x801C0B8C
    // 0x801ECCE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECCE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ECCE4: beql        $v0, $zero, L_801ECCF8
    if (ctx->r2 == 0) {
        // 0x801ECCE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801ECCF8;
    }
    goto skip_0;
    // 0x801ECCE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801ECCEC: jal         0x801CC528
    // 0x801ECCF0: nop

    LOOKUP_FUNC(0x801CC528)(rdram, ctx);
        goto after_1;
    // 0x801ECCF0: nop

    after_1:
    // 0x801ECCF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801ECCF8:
    // 0x801ECCF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801ECCFC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x801ECD00: jr          $ra
    // 0x801ECD04: nop

    return;
    // 0x801ECD04: nop

;}
RECOMP_FUNC void M25_FUN_801ecd08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECD0C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECD10: jr          $ra
    // 0x801ECD14: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x801ECD14: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecd18(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecd18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECD1C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECD20: jr          $ra
    // 0x801ECD24: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801ECD24: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecd28(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecd28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECD2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECD30: jr          $ra
    // 0x801ECD34: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    return;
    // 0x801ECD34: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecd38(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecd38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECD3C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECD40: jr          $ra
    // 0x801ECD44: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    return;
    // 0x801ECD44: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecd48(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecd48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECD4C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECD50: jr          $ra
    // 0x801ECD54: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    return;
    // 0x801ECD54: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecd58(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecd58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECD5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECD60: jr          $ra
    // 0x801ECD64: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x801ECD64: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecd68(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecd68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECD6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECD70: jr          $ra
    // 0x801ECD74: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x801ECD74: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecd78(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecd78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECD78: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801ECD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ECD80: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801ECD84: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801ECD88: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801ECD8C: jal         0x801BF628
    // 0x801ECD90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801ECD90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801ECD94: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801ECD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801ECD9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801ECDA0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801ECDA4: bne         $at, $zero, L_801ECDB4
    if (ctx->r1 != 0) {
        // 0x801ECDA8: nop
    
            goto L_801ECDB4;
    }
    // 0x801ECDA8: nop

    // 0x801ECDAC: b           L_801ECDB4
    // 0x801ECDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801ECDB4;
    // 0x801ECDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801ECDB4:
    // 0x801ECDB4: jr          $ra
    // 0x801ECDB8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801ECDB8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecdbc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecdbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECDBC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801ECDC0: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecdc4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecdc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECDC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ECDC8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801ECDCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ECDD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ECDD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ECDD8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ECDDC: lui         $a1, 0x129
    ctx->r5 = S32(0X129 << 16);
    // 0x801ECDE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801ECDE4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ECDE8: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ECDEC: beql        $t9, $zero, L_801ECEB0
    if (ctx->r25 == 0) {
        // 0x801ECDF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801ECEB0;
    }
    goto skip_0;
    // 0x801ECDF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801ECDF4: jal         0x801C0B8C
    // 0x801ECDF8: ori         $a1, $a1, 0x8BE0
    ctx->r5 = ctx->r5 | 0X8BE0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECDF8: ori         $a1, $a1, 0x8BE0
    ctx->r5 = ctx->r5 | 0X8BE0;
    after_0:
    // 0x801ECDFC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801ECE00: beq         $v0, $zero, L_801ECE10
    if (ctx->r2 == 0) {
        // 0x801ECE04: addiu       $v1, $v1, -0x54EC
        ctx->r3 = ADD32(ctx->r3, -0X54EC);
            goto L_801ECE10;
    }
    // 0x801ECE04: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801ECE08: b           L_801ECEB0
    // 0x801ECE0C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801ECEB0;
    // 0x801ECE0C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801ECE10:
    // 0x801ECE10: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801ECE14: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x801ECE18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ECE1C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801ECE20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ECE24: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x801ECE28: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ECE2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ECE30: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801ECE34: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801ECE38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ECE3C: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ECE40: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801ECE44: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x801ECE48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ECE4C: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x801ECE50: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801ECE54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ECE58: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801ECE5C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801ECE60: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x801ECE64: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ECE68: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801ECE6C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801ECE70: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801ECE74: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801ECE78: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801ECE7C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ECE80: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801ECE84: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801ECE88: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
    // 0x801ECE8C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801ECE90: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ECE94: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ECE98: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ECE9C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ECEA0: sh          $t5, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r13;
    // 0x801ECEA4: jal         0x801CC470
    // 0x801ECEA8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ECEA8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ECEAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801ECEB0:
    // 0x801ECEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ECEB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ECEB8: jr          $ra
    // 0x801ECEBC: nop

    return;
    // 0x801ECEBC: nop

;}
RECOMP_FUNC void M25_FUN_801ecec0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECEC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ECEC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801ECEC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ECECC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ECED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ECED4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ECED8: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ECEDC: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x801ECEE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ECEE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ECEE8: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801ECEEC: jal         0x801CC470
    // 0x801ECEF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801ECEF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801ECEF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ECEF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ECEFC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801ECF00: jr          $ra
    // 0x801ECF04: nop

    return;
    // 0x801ECF04: nop

;}
RECOMP_FUNC void M25_FUN_801ecf08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECF08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801ECF0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801ECF10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ECF14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801ECF18: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
    // 0x801ECF1C: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    // 0x801ECF20: jal         0x801C0B8C
    // 0x801ECF24: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECF24: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ECF28: beq         $v0, $zero, L_801ECFB4
    if (ctx->r2 == 0) {
        // 0x801ECF2C: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801ECFB4;
    }
    // 0x801ECF2C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801ECF30: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801ECF34: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801ECF38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ECF3C: lwc1        $f4, -0x3770($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3770);
    // 0x801ECF40: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ECF44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ECF48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ECF4C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ECF50: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801ECF54: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ECF58: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ECF5C: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801ECF60: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801ECF64: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ECF68: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x801ECF6C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ECF70: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801ECF74: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801ECF78: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801ECF7C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801ECF80: lwc1        $f8, -0x376C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X376C);
    // 0x801ECF84: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ECF88: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ECF8C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ECF90: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ECF94: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801ECF98: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801ECF9C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ECFA0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801ECFA4: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801ECFA8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801ECFAC: b           L_801ECFB8
    // 0x801ECFB0: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
        goto L_801ECFB8;
    // 0x801ECFB0: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
L_801ECFB4:
    // 0x801ECFB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801ECFB8:
    // 0x801ECFB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801ECFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801ECFC0: jr          $ra
    // 0x801ECFC4: nop

    return;
    // 0x801ECFC4: nop

;}
RECOMP_FUNC void M25_FUN_801ecfc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECFC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ECFCC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ECFD0: jr          $ra
    // 0x801ECFD4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801ECFD4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ecfd8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ecfd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ECFD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ECFDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ECFE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ECFE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ECFE8: lui         $a1, 0x16C
    ctx->r5 = S32(0X16C << 16);
    // 0x801ECFEC: ori         $a1, $a1, 0xAF60
    ctx->r5 = ctx->r5 | 0XAF60;
    // 0x801ECFF0: jal         0x801C0B8C
    // 0x801ECFF4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ECFF4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ECFF8: beq         $v0, $zero, L_801ED024
    if (ctx->r2 == 0) {
        // 0x801ECFFC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801ED024;
    }
    // 0x801ECFFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED000: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801ED004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ED008: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ED00C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED010: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801ED014: jal         0x801CC470
    // 0x801ED018: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED018: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801ED01C: b           L_801ED028
    // 0x801ED020: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801ED028;
    // 0x801ED020: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801ED024:
    // 0x801ED024: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801ED028:
    // 0x801ED028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED02C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED030: jr          $ra
    // 0x801ED034: nop

    return;
    // 0x801ED034: nop

;}
